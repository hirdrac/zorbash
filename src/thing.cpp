/*
 * Copyright (C) 2018 goblinhack@gmail.com
 *
 * See the LICENSE file for license.
 */

#include "my_game.h"
#include "my_thing.h"
#include "my_tile_info.h"

static uint32_t thing_id;

Thingp thing_new (std::string tp_name, fpoint at)
{_
    auto id = ++thing_id;

    auto t = new Thing(); // std::make_shared< class Thing >();
    auto tp = t->tp = tp_find(tp_name);
    if (!t->tp) {
        DIE("thing [%s] not found", tp_name.c_str());
    }

    t->id = id;
    auto p = std::make_pair(t->id, t);
    auto result = game.state.map.all_things.insert(p);
    if (result.second == false) {
        DIE("thing insert [%d] failed", id);
    }

    point new_at((int)at.x, (int)at.y);
    if ((new_at.x >= MAP_WIDTH) || (new_at.y >= MAP_HEIGHT)) {
        DIE("new thing is oob at %d, %d", new_at.x, new_at.y);
    }
    auto depth = t->depth = tp_z_depth(tp);
    auto n = &game.state.map.things[new_at.x][new_at.y][depth];
    result = n->insert(p);
    if (result.second == false) {
        DIE("thing insert into map [%d] failed", id);
    }

    t->at             = at;

    if (tp_is_animated_walk_flip(tp)) {
        t->dir            = THING_DIR_RIGHT;
    } else {
        t->dir            = THING_DIR_NONE;
    }

    t->is_dead        = false;
    t->is_hidden        = false;
    t->is_sleeping    = false;
    t->is_moving      = false;
    t->has_ever_moved = false;
    t->is_open        = false;

    auto tiles = tp_get_left_tiles(tp);
    auto tinfo = tile_info_random(tiles);
    if (tinfo) {
        t->left_tile = tinfo->tile;
    }

    tiles = tp_get_right_tiles(tp);
    tinfo = tile_info_random(tiles);
    if (tinfo) {
        t->right_tile = tinfo->tile;
    }

    tiles = tp_get_top_tiles(tp);
    tinfo = tile_info_random(tiles);
    if (tinfo) {
        t->top_tile = tinfo->tile;
    }

    tiles = tp_get_bot_tiles(tp);
    tinfo = tile_info_random(tiles);
    if (tinfo) {
        t->bot_tile = tinfo->tile;
    }

    tiles = tp_get_tl_tiles(tp);
    tinfo = tile_info_random(tiles);
    if (tinfo) {
        t->tl_tile = tinfo->tile;
    }

    tiles = tp_get_tr_tiles(tp);
    tinfo = tile_info_random(tiles);
    if (tinfo) {
        t->tr_tile = tinfo->tile;
    }

    tiles = tp_get_br_tiles(tp);
    tinfo = tile_info_random(tiles);
    if (tinfo) {
        t->br_tile = tinfo->tile;
    }

    tiles = tp_get_bl_tiles(tp);
    tinfo = tile_info_random(tiles);
    if (tinfo) {
        t->bl_tile = tinfo->tile;
    }

    tiles = tp_get_tiles(tp);
    if (tp->is_animated) {
        tinfo = tile_info_first(tiles);
    } else {
        tinfo = tile_info_random(tiles);
    }
    if (tinfo) {
        t->current_tileinfo = tinfo;
        t->current_tile = tinfo->tile;
    }

    if (tp_is_player(tp)) {
        if (game.state.player && (game.state.player != t)) {
            DIE("player exists in multiple places on map, %f, %f and %f, %f",
                game.state.player->at.x,
                game.state.player->at.y,
                t->at.x,
                t->at.y);
        }
        game.state.player = t;

        color col = WHITE;
        col.a = 50;
        t->light = light_new(MAX_LIGHT_RAYS, 8, at, LIGHT_QUALITY_HIGH, col);

        t->log("player created");
    }

    if (tp_is_wall(tp)) {
        game.state.map.is_wall[new_at.x][new_at.y] = true;
    }

    //log("created");
    return (t);
}

void Thing::hide (void)
{_
    verify(t);

    is_hidden = true;

    /*
     * Hide the weapon too or it just floats in the air.
     */
    auto weapon_carry_anim = get_weapon_carry_anim();
    if (weapon_carry_anim) {
        weapon_carry_anim->hide();
    }
}

void Thing::visible (void)
{_
    verify(t);

    is_hidden = false;

    /*
     * If this thing has an owner, should the thing stay hidden?
     */
    auto owner = get_owner();
    if (owner) {
        if (this == owner->get_weapon_carry_anim()) {
            if (owner->get_weapon_swing_anim()) {
                /*
                 * Stay hidden until the weapon swing is done.
                 */
                return;
            }
        }
    }

    /*
     * Reveal the weapon again too.
     */
    auto weapon_carry_anim = get_weapon_carry_anim();
    if (weapon_carry_anim) {
        weapon_carry_anim->visible();
    }
}

uint8_t Thing::is_visible (void)
{
    verify(t);

    return (!is_hidden);
}

/*
 * Get rid of all the hooks to other things that this thing has. e.g. the
 * weapons it carries etc.
 */
void Thing::remove_hooks ()
{_
    verify(t);

    /*
     * We are owned by something. i.e. we are a sword.
     */
    Thingp owner = 0;

#ifdef THING_DEBUG
    log("remove hooks");
#endif

    if (owner_thing_id) {
        owner = get_owner();
    }

    if (owner_thing_id && owner) {
#ifdef THING_DEBUG
        log("detach from owner %s", owner->logname().c_str());
#endif

        if (thing_id == owner->weapon_carry_anim_thing_id) {
            unwield("remove hooks");

#ifdef THING_DEBUG
            log("detach from carry anim owner %s", owner->logname().c_str());
#endif

            set_weapon_carry_anim(nullptr);
        }

        if (thing_id == owner->weapon_swing_anim_thing_id) {
#ifdef THING_DEBUG
            log("detach from swing anim owner %s", owner->logname().c_str());
#endif

            set_weapon_swing_anim(nullptr);

            /*
             * End of the swing animation, make the sword visible again.
             */
            auto carrying = owner->get_weapon_carry_anim();
            if (carrying) {
                /*
                 * But only if the owner is visible. They may have reached the
                 * level.
                 */
                if (owner->is_visible()) {
                    carrying->visible();
                }
            }
        }

        set_owner(nullptr);
    }

    /*
     * We own things like a sword. i.e. we are a player.
     */
    if (weapon_carry_anim_thing_id) {
        auto item = get_weapon_carry_anim();
        set_weapon_carry_anim(nullptr);
        verify(item);
        item->set_owner(nullptr);
        item->dead(nullptr, "weapon carry anim owner killed");
    }

    if (weapon_swing_anim_thing_id) {
        auto item = get_weapon_swing_anim();
        set_weapon_swing_anim(nullptr);
        verify(item);
        item->set_owner(nullptr);
        item->dead(nullptr, "weapon swing anim owner killed");
    }

    /*
     * Some things have lots of things they own
     */
    if (owned_count) {
        log("Remove remaining %u owned things", owned_count);

        for (auto i : game.state.map.all_things) {
            Thingp t = i.second;
            auto o = t->get_owner();
            if (o && (o == t)) {
                t->set_owner(nullptr);
            }
        }
    }
}

Thingp Thing::get_owner (void)
{
    if (owner_thing_id) {
        return (thing_find(owner_thing_id));
    } else {
        return (nullptr);
    }
}

void Thing::set_owner (Thingp owner)
{
    if (owner) {
        verify(owner);
    }

    auto old_owner = get_owner();
    if (old_owner) {
        if (old_owner == owner) {
            return;
        }

        if (owner) {
            log("set-owner change %s->%s", old_owner->logname().c_str(), 
                owner->logname().c_str());
        } else {
            log("set-owner remove owner %s", old_owner->logname().c_str());
        }
    } else {
        if (owner) {
            log("set-owner %s", owner->logname().c_str());
        }
    }

    if (owner) {
        owner_thing_id = owner->id;

        owner->owned_count++;
    } else {
        owner_thing_id = 0;

        if (old_owner) {
            old_owner->owned_count--;
        }
    }
}

void Thing::pop (void)
{_
    auto t = this;

    /*
     * Pop from all things
     */
    {
        auto a = &game.state.map.all_things;
        auto iter = a->find(t->id);
        if (iter == a->end()) {
            t->die("thing not found to destroy from all things");
        }
        a->erase(t->id);
    }
_
    /*
     * Pop from the map
     */
    point old_at((int)at.x, (int)at.y);
    {
        auto o = &game.state.map.things[old_at.x][old_at.y][t->depth];
        auto iter = o->find(t->id);
        if (iter == o->end()) {
            t->die("thing not found to destroy");
        }
_    
        auto value = (*o)[t->id];
        o->erase(iter);
_
        if (tp_is_wall(tp)) {
            game.state.map.is_wall[old_at.x][old_at.y] = false;
        }
_
        if (tp_is_player(tp)) {
            if (game.state.player != value) {
                game.state.player = nullptr;
            }
        }
    }
}

void Thing::move_to (fpoint to)
{_
    auto t = this;
    auto tp = t->tp;

    t->last_move_ms = time_get_time_ms_cached();
    t->end_move_ms = t->last_move_ms + ONESEC / 10;
    t->has_ever_moved = true;

    if (!t->has_ever_moved) {
        t->last_at = to;
    } else {
        t->last_at = t->at;
    }
_
    point old_at((int)t->at.x, (int)t->at.y);
    point new_at((int)to.x, (int)to.y);

    /*
     * Keep track of where this thing is on the grid
     */
    if (old_at != new_at) {
        /*
         * Pop
         */
        auto o = &game.state.map.things[old_at.x][old_at.y][t->depth];
        auto iter = o->find(t->id);
        if (iter == o->end()) {
            die("not found on map move");
        }

        auto value = (*o)[t->id];
        o->erase(iter);

        /*
         * Add back
         */
        auto n = &game.state.map.things[new_at.x][new_at.y][t->depth];
        n->insert(std::make_pair(t->id, value));

        if (tp_is_wall(tp)) {
            game.state.map.is_wall[old_at.x][old_at.y] = false;
            game.state.map.is_wall[new_at.x][new_at.y] = true;
        }
    }
_
    /*
     * Moves are immediate, but we render the move in steps, hence keep
     * track of when we moved.
     */
    t->at = to;
    t->last_move_ms = time_get_time_ms_cached();
    t->end_move_ms = t->last_move_ms + ONESEC / 10;
_
    /*
     * Light source follows the thing.
     */
    if (t->light) {
        t->light->move_to(at);
        t->light->calculate();
    }
}

void Thing::move_delta (fpoint delta)
{_
    auto t = this;

    /*
     * If not moving and this is the first move then break out of the
     * idle animation.
     */
    if (t->is_dir_none()) {
        t->next_frame_ms = time_get_time_ms_cached();
    }

    if (delta.x > 0) {
        t->set_dir_left();
        t->is_moving = true;
        t->has_ever_moved = true;
    }

    if (delta.x < 0) {
        t->set_dir_right();
        t->is_moving = true;
        t->has_ever_moved = true;
    }

    if (delta.y > 0) {
        t->set_dir_up();
        t->is_moving = true;
        t->has_ever_moved = true;
    }

    if (delta.y < 0) {
        t->set_dir_down();
        t->is_moving = true;
        t->has_ever_moved = true;
    }

    t->move_to(t->at + delta);
}

/*
 * Find an existing thing.
 */
Thingp thing_find (uint32_t id)
{_
    auto result = game.state.map.all_things.find(id);
    if (result == game.state.map.all_things.end()) {
        return (0);
    }

    return (result->second);
}

std::string Thing::logname (void)
{_
    auto t = this;

    /*
     * Return constant strings from a small pool.
     */
    static char tmp[10][MAXSTR];
    static int loop;

    if (loop >= 10) {
        loop = 0;
    }

    snprintf(tmp[loop], sizeof(tmp[loop]) - 1, "%u(%s) at (%g,%g)",
             t->id, t->tp->short_name.c_str(), t->at.x, t->at.y);

    return (tmp[loop++]);
}

void Thing::dead (Thingp killer, const char * , ...)
{_
    ERR("thing dead TBD");
}

void Thing::set_dir_none (void)
{_
    auto t = this;

    if (tp_is_animated_no_dir(t->tp)) {
        return;
    }

    if (t->dir != THING_DIR_NONE) {
        t->dir = THING_DIR_NONE;
    }
}

uint8_t Thing::is_dir_none (void)
{_
    auto t = this;

    return (t->dir == THING_DIR_NONE);
}

void Thing::set_dir_down (void)
{_
    auto t = this;

    if (tp_is_animated_no_dir(t->tp)) {
        return;
    }

    if (t->dir != THING_DIR_DOWN) {
        t->dir = THING_DIR_DOWN;
    }
}

uint8_t Thing::is_dir_down (void)
{_
    auto t = this;

    return (t->dir == THING_DIR_DOWN);
}

void Thing::set_dir_up (void)
{_
    auto t = this;

    if (tp_is_animated_no_dir(t->tp)) {
        return;
    }

    if (t->dir != THING_DIR_UP) {
        t->dir = THING_DIR_UP;
    }
}

uint8_t Thing::is_dir_up (void)
{_
    auto t = this;

    return (t->dir == THING_DIR_UP);
}

void Thing::set_dir_left (void)
{_
    auto t = this;

    if (tp_is_animated_no_dir(t->tp)) {
        return;
    }

    if (t->dir != THING_DIR_LEFT) {
        if (t->dir == THING_DIR_RIGHT) {
            if (tp_is_animated_walk_flip(tp)) {
                t->flip_start_ms = time_get_time_ms_cached();
            }
        }
        t->dir = THING_DIR_LEFT;
    }
}

uint8_t Thing::is_dir_left (void)
{_
    auto t = this;

    return (t->dir == THING_DIR_LEFT);
}

void Thing::set_dir_right (void)
{_
    auto t = this;

    if (tp_is_animated_no_dir(t->tp)) {
        return;
    }

    if (t->dir != THING_DIR_RIGHT) {
        if (t->dir == THING_DIR_LEFT) {
            if (tp_is_animated_walk_flip(tp)) {
                t->flip_start_ms = time_get_time_ms_cached();
            }
        }
        t->dir = THING_DIR_RIGHT;
    }
}

uint8_t Thing::is_dir_right (void)
{_
    auto t = this;

    return (t->dir == THING_DIR_RIGHT);
}

void Thing::set_dir_tl (void)
{_
    auto t = this;

    if (tp_is_animated_no_dir(t->tp)) {
        return;
    }

    if (t->dir != THING_DIR_TL) {
        t->dir = THING_DIR_TL;
    }
}

uint8_t Thing::is_dir_tl (void)
{_
    auto t = this;

    return (t->dir == THING_DIR_TL);
}

void Thing::set_dir_bl (void)
{_
    auto t = this;

    if (tp_is_animated_no_dir(t->tp)) {
        return;
    }

    if (t->dir != THING_DIR_BL) {
        t->dir = THING_DIR_BL;
    }
}

uint8_t Thing::is_dir_bl (void)
{_
    auto t = this;

    return (t->dir == THING_DIR_BL);
}

void Thing::set_dir_tr (void)
{_
    auto t = this;

    if (tp_is_animated_no_dir(t->tp)) {
        return;
    }

    if (t->dir != THING_DIR_TR) {
        t->dir = THING_DIR_TR;
    }
}

uint8_t Thing::is_dir_tr (void)
{_
    auto t = this;

    return (t->dir == THING_DIR_TR);
}

void Thing::set_dir_br (void)
{_
    auto t = this;

    if (tp_is_animated_no_dir(t->tp)) {
        return;
    }

    if (t->dir != THING_DIR_BR) {
        t->dir = THING_DIR_BR;
    }
}

uint8_t Thing::is_dir_br (void)
{_
    auto t = this;

    return (t->dir == THING_DIR_BR);
}
