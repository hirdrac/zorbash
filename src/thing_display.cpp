/*
 * Copyright goblinhack@gmail.com
 * See the README file for license info.
 */

#include "my_game.h"
#include "my_thing.h"

ThingDisplayOrder thing_display_order[MAP_WIDTH][MAP_HEIGHT][MAP_DEPTH];

void Thing::attach (void)
{_
    detach();

    auto root = &thing_display_order[(int)at.x][(int)at.y][depth];
    auto key = ThingDisplaySortKey(depth, br.y, this);
    auto result = root->insert(std::make_pair(key, this));
    if (result.second == false) {
        die("thing attach failed");
    }

    is_attached = true;
    last_attached = at;
//log("attached at %d %d %d", (int)last_attached.x, (int)last_attached.y, 
//depth);
}

void Thing::detach (void)
{_
    if (!is_attached) {
        return;
    }
    is_attached = false;
//log("detach from %d %d %d", (int)last_attached.x, (int)last_attached.y, 
//depth);
    auto root = &thing_display_order[(int)last_attached.x]
                                    [(int)last_attached.y][depth];
    auto key = ThingDisplaySortKey(depth, br.y, this);
    auto result = root->find(key);
    if (result == root->end()) {
        die("cannot detach");
    }

    root->erase(key);
}

void Thing::blit_wall_cladding (fpoint &tl, fpoint &br)
{  
    double dw = game.config.one_pixel_gl_width;
    double dh = game.config.one_pixel_gl_height;

    int x = (int) at.x;
    int y = (int) at.y;

    if (unlikely(x <= 0) || 
        unlikely(y <= 0) || 
        unlikely(x >= MAP_WIDTH - 1) || 
        unlikely(y >= MAP_HEIGHT - 1)) {
        return;
    }

    if (!game.state.map.is_wall[x][y - 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit_fat_outline(tp, top_tile, tl2, br2);
    }

    if (!game.state.map.is_wall[x][y + 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit_fat_outline(tp, bot_tile, tl2, br2);
    }

    if (!game.state.map.is_wall[x - 1][y]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x -= dw;
        br2.x -= dw;
        tile_blit_fat_outline(tp, left_tile, tl2, br2);
    }

    if (!game.state.map.is_wall[x + 1][y]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        tile_blit_fat_outline(tp, right_tile, tl2, br2);
    }

    /*
     * X---
     * |...
     * |...
     */
    if (!game.state.map.is_wall[x - 1][y - 1] &&
        !game.state.map.is_wall[x - 1][y] &&
        !game.state.map.is_wall[x][y - 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x -= dw;
        br2.x -= dw;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit_fat_outline(tp, tl_tile, tl2, br2);
    }

    /*
     * ---X
     * ...|
     * ...|
     */
    if (!game.state.map.is_wall[x + 1][y - 1] &&
        !game.state.map.is_wall[x + 1][y] &&
        !game.state.map.is_wall[x][y - 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit_fat_outline(tp, tr_tile, tl2, br2);
    }

    /*
     *  .|
     *  .|
     *  .X--
     *  ....
     */
    if (!game.state.map.is_wall[x + 1][y - 1] &&
        game.state.map.is_wall[x + 1][y] &&
        game.state.map.is_wall[x][y - 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit_fat_outline(tp, tr_tile, tl2, br2);
    }

    /*
     *    |.
     *    |.
     *  --X.
     *  ....
     */
    if (!game.state.map.is_wall[x - 1][y - 1] &&
        game.state.map.is_wall[x - 1][y] &&
        game.state.map.is_wall[x][y - 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit_fat_outline(tp, tl_tile, tl2, br2);
    }

    dw = 0.00;
    dh = 0.00;

    /*
     * |...
     * |...
     * X---
     */
    if (!game.state.map.is_wall[x - 1][y + 1] &&
        !game.state.map.is_wall[x - 1][y] &&
        !game.state.map.is_wall[x][y + 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x -= dw;
        br2.x -= dw;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit_fat_outline(tp, bl_tile, tl2, br2);
    }

    /*
     * ...|
     * ...|
     * ---X
     */
    if (!game.state.map.is_wall[x + 1][y + 1] &&
        !game.state.map.is_wall[x + 1][y] &&
        !game.state.map.is_wall[x][y + 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit_fat_outline(tp, br_tile, tl2, br2);
    }

    /*
     * .....
     * .X---
     * .|
     * .|
     */
    if (!game.state.map.is_wall[x + 1][y + 1] &&
        game.state.map.is_wall[x + 1][y] &&
        game.state.map.is_wall[x][y + 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit_fat_outline(tp, br_tile, tl2, br2);
    }

    /*
     * ....
     * --X.
     *   |.
     *   |.
     */
    if (!game.state.map.is_wall[x - 1][y + 1] &&
        game.state.map.is_wall[x - 1][y] &&
        game.state.map.is_wall[x][y + 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit_fat_outline(tp, bl_tile, tl2, br2);
    }
}

void Thing::blit_rock_cladding (fpoint &tl, fpoint &br)
{  
    double dw = game.config.one_pixel_gl_width;
    double dh = game.config.one_pixel_gl_height;

    int x = (int) at.x;
    int y = (int) at.y;

    if (unlikely(x <= 0) || 
        unlikely(y <= 0) || 
        unlikely(x >= MAP_WIDTH - 1) || 
        unlikely(y >= MAP_HEIGHT - 1)) {
        return;
    }

    if (!game.state.map.is_rock[x][y - 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit_fat_outline(tp, top_tile, tl2, br2);
    }

    if (!game.state.map.is_rock[x][y + 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit_fat_outline(tp, bot_tile, tl2, br2);
    }

    if (!game.state.map.is_rock[x - 1][y]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x -= dw;
        br2.x -= dw;
        tile_blit_fat_outline(tp, left_tile, tl2, br2);
    }

    if (!game.state.map.is_rock[x + 1][y]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        tile_blit_fat_outline(tp, right_tile, tl2, br2);
    }

    /*
     * X---
     * |...
     * |...
     */
    if (!game.state.map.is_rock[x - 1][y - 1] &&
        !game.state.map.is_rock[x - 1][y] &&
        !game.state.map.is_rock[x][y - 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x -= dw;
        br2.x -= dw;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit_fat_outline(tp, tl_tile, tl2, br2);
    }

    /*
     * ---X
     * ...|
     * ...|
     */
    if (!game.state.map.is_rock[x + 1][y - 1] &&
        !game.state.map.is_rock[x + 1][y] &&
        !game.state.map.is_rock[x][y - 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit_fat_outline(tp, tr_tile, tl2, br2);
    }

    /*
     *  .|
     *  .|
     *  .X--
     *  ....
     */
    if (!game.state.map.is_rock[x + 1][y - 1] &&
        game.state.map.is_rock[x + 1][y] &&
        game.state.map.is_rock[x][y - 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit_fat_outline(tp, tr_tile, tl2, br2);
    }

    /*
     *    |.
     *    |.
     *  --X.
     *  ....
     */
    if (!game.state.map.is_rock[x - 1][y - 1] &&
        game.state.map.is_rock[x - 1][y] &&
        game.state.map.is_rock[x][y - 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        tl2.y -= dh;
        br2.y -= dh;
        tile_blit_fat_outline(tp, tl_tile, tl2, br2);
    }

    dw = 0.00;
    dh = 0.00;

    /*
     * |...
     * |...
     * X---
     */
    if (!game.state.map.is_rock[x - 1][y + 1] &&
        !game.state.map.is_rock[x - 1][y] &&
        !game.state.map.is_rock[x][y + 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x -= dw;
        br2.x -= dw;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit_fat_outline(tp, bl_tile, tl2, br2);
    }

    /*
     * ...|
     * ...|
     * ---X
     */
    if (!game.state.map.is_rock[x + 1][y + 1] &&
        !game.state.map.is_rock[x + 1][y] &&
        !game.state.map.is_rock[x][y + 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit_fat_outline(tp, br_tile, tl2, br2);
    }

    /*
     * .....
     * .X---
     * .|
     * .|
     */
    if (!game.state.map.is_rock[x + 1][y + 1] &&
        game.state.map.is_rock[x + 1][y] &&
        game.state.map.is_rock[x][y + 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit_fat_outline(tp, br_tile, tl2, br2);
    }

    /*
     * ....
     * --X.
     *   |.
     *   |.
     */
    if (!game.state.map.is_rock[x - 1][y + 1] &&
        game.state.map.is_rock[x - 1][y] &&
        game.state.map.is_rock[x][y + 1]) {
        fpoint tl2 = tl;
        fpoint br2 = br;
        tl2.x += dw;
        br2.x += dw;
        //tl2.y += dh;
        //br2.y += dh;
        tile_blit_fat_outline(tp, bl_tile, tl2, br2);
    }
}

void Thing::blit_player_owned_shadow (const Tpp &tp, const Tilep &tile, 
                                      const fpoint &tl, const fpoint &br)
{
    double x1;
    double x2;
    double y1;
    double y2;

    if (!tile) {
        return;
    }

    x1 = tile->x1;
    x2 = tile->x2;
    y1 = tile->y1;
    y2 = tile->y2;

    fpoint shadow_tl = tl;
    fpoint shadow_tr(br.x, tl.y);
    fpoint shadow_bl(tl.x, br.y); 
    fpoint shadow_br = br;

    double dx = 1.0;
    double dy = 1.0;

    color c = BLACK;
    c.a = 100;
    glcolor(c);

    shadow_tl.x += 0.05 * dx;
    shadow_tr.x += 0.05 * dx;
    shadow_tl.y += 0.01 * dy;
    shadow_tr.y += 0.01 * dy;

    ::blit(tile->gl_surface_binding, x1, y2, x2, y1, 
           shadow_bl, shadow_br, shadow_tl, shadow_tr);

    glcolor(WHITE);
}

/*
 * Blits a whole tile. Y co-ords are inverted.
 */
void Thing::blit_non_player_owned_shadow (const Tpp &tp, const Tilep &tile, 
                                          const fpoint &tl, const fpoint &br)
{
    double x1;
    double x2;
    double y1;
    double y2;

    if (!tile) {
        return;
    }

    x1 = tile->x1;
    x2 = tile->x2;
    y1 = tile->y1;
    y2 = tile->y2;

    fpoint shadow_bl(tl.x, br.y); 
    fpoint shadow_br = br;
    fpoint shadow_tl = shadow_bl;
    fpoint shadow_tr = shadow_br;

    double dx = 1.0;
    double dy = 1.0;
    if (game.state.player) {
        if (owner_thing_id == game.state.player->id) {
            // use default shadow for carried items
        } else if (this != game.state.player) {
            fpoint d = this->interpolated_at - game.state.player->interpolated_at;
            const double D = 5.0;
            dx = d.x / D;
            dy = d.y / D;
        }
    } else {
        // use default shadow
    }

    double n = 0.1;
    if (dy < 0) {
        dy = std::min(-n, dy);
    } else {
        dy = std::max(n, dy);
    }

    double m = 0.5;
    if (dx < 0) {
        dx = std::max(-m, dx);
    } else {
        dx = std::min(m, dx);
    }
    if (dy < 0) {
        dy = std::max(-m, dy);
    } else {
        dy = std::min(m, dy);
    }

    color c = BLACK;
    c.a = 100;
    glcolor(c);

    shadow_tl.x += 0.40 * dx;
    shadow_tr.x += 0.40 * dx;
    shadow_tl.y += 0.40 * dy;
    shadow_tr.y += 0.40 * dy;

    if (shadow_tl.x > shadow_tr.x) {
        std::swap(shadow_tl, shadow_tr);
    }

    double height = get_bounce() / 2.0;
    shadow_tl.x -= height;
    shadow_tr.x -= height;
    shadow_bl.x -= height;
    shadow_br.x -= height;
    shadow_tl.y -= height;
    shadow_tr.y -= height;
    shadow_bl.y -= height;
    shadow_br.y -= height;

    ::blit(tile->gl_surface_binding, x1, y2, x2, y1, 
           shadow_bl, shadow_br, shadow_tl, shadow_tr);

    c.a = 50;
    glcolor(c);

    fpoint faded_shadow_tl;
    fpoint faded_shadow_tr;

    faded_shadow_tl.x = shadow_tl.x + 0.07 * dx;
    faded_shadow_tr.x = shadow_tr.x + 0.07 * dx;
    faded_shadow_tl.y = shadow_tl.y + 0.02 * dy;
    faded_shadow_tr.y = shadow_tr.y + 0.02 * dy;
    ::blit(tile->gl_surface_binding, x1, y2, x2, y1, 
           shadow_bl, shadow_br, faded_shadow_tl, faded_shadow_tr);

    faded_shadow_tl.x = shadow_tl.x + 0.03 * dx;
    faded_shadow_tr.x = shadow_tr.x + 0.03 * dx;
    faded_shadow_tl.y = shadow_tl.y + 0.01 * dy;
    faded_shadow_tr.y = shadow_tr.y + 0.01 * dy;
    ::blit(tile->gl_surface_binding, x1, y2, x2, y1, 
           shadow_bl, shadow_br, faded_shadow_tl, faded_shadow_tr);

    glcolor(WHITE);
}

void Thing::blit_shadow (const Tpp &tp, const Tilep &tile, 
                         const fpoint &tl, const fpoint &br)
{
    if (tp_is_player(tp) || (owner_thing_id == game.state.player->id)) {
        blit_player_owned_shadow(tp, tile, tl, br);
    } else {
        blit_non_player_owned_shadow(tp, tile, tl, br);
    }
}

void Thing::blit (double offset_x, double offset_y, int x, int y)
{
    if (unlikely(is_hidden)) {
        return;
    }

    Tilep tile;
    if (current_tileinfo) {
        tile = current_tileinfo->tile;
    } else {
        tile = current_tile;
    }

    fpoint blit_tl(tl.x - offset_x, tl.y - offset_y);
    fpoint blit_br(br.x - offset_x, br.y - offset_y);

    fpoint tile_tl(0, 0);
    fpoint tile_br(1, 1);

    if (tp_is_monst(tp) || tp_is_player(tp)) {
        if (game.state.map.is_deep_water[(int)at.x][(int)at.y]) {
            const auto water_depth = 0.5;
            tile_tl = fpoint(0, 0);
            tile_br = fpoint(1, 1.0 - water_depth);
            blit_tl.y += (blit_br.y - blit_tl.y) * water_depth;
        } else if (game.state.map.is_water[(int)at.x][(int)at.y]) {
            const auto water_depth = 0.1;
            tile_tl = fpoint(0, 0);
            tile_br = fpoint(1, 1.0 - water_depth);
            blit_tl.y += (blit_br.y - blit_tl.y) * water_depth;
        }
    }

#if 0
    if ((mouse_x > blit_tl.x * game.config.video_pix_width) && (mouse_x < blit_br.x * game.config.video_pix_width) &&
        (mouse_y > blit_tl.y * game.config.video_pix_height) && (mouse_y < blit_br.y * game.config.video_pix_height)) {
        if (tp_is_wall(tp)) {
//            con("over");
//            extern Thingp debug_thing;
//            debug_thing = this;
        }
    }
#endif

    if (unlikely(tp_is_small_shadow_caster(tp))) {
        blit_shadow(tp, tile, blit_tl, blit_br);
    }

    if (tp_is_outlined(tp)) {
        if (game.state.map.is_water[(int)at.x][(int)at.y]) {
            tile_blit_section(tp, tile, tile_tl, tile_br, blit_tl, blit_br);
        } else {
            tile_blit_fat_outline(tp, tile, blit_tl, blit_br);
        }
    } else {
        if (game.state.map.is_water[(int)at.x][(int)at.y]) {
            tile_blit_section(tp, tile, tile_tl, tile_br, blit_tl, blit_br);
        } else {
            tile_blit_fat(tp, tile, blit_tl, blit_br);
        }
    }

    //if (!tp) { // top_tile) {
    if (top_tile) {
        if (tp_is_wall(tp)) {
            blit_wall_cladding(blit_tl, blit_br);
        }
        if (tp_is_rock(tp)) {
            blit_rock_cladding(blit_tl, blit_br);
        }
    }
}

void Thing::blit_upside_down (double offset_x, double offset_y, int x, int y)
{
    if (unlikely(is_hidden)) {
        return;
    }

    Tilep tile;
    if (current_tileinfo) {
        tile = current_tileinfo->tile;
    } else {
        tile = current_tile;
    }

    fpoint blit_tl(tl.x - offset_x, tl.y - offset_y);
    fpoint blit_br(br.x - offset_x, br.y - offset_y);
    auto diff = blit_br.y - blit_tl.y;

    std::swap(blit_tl.y, blit_br.y);

    if (tile_get_height(tile) != TILE_HEIGHT) {
        if (tp_is_blitted_as_sitting_on_the_ground(tp)) {
            blit_br.y += diff;
            blit_tl.y += diff;
        } else {
            blit_br.y += game.config.tile_gl_height;
            blit_tl.y += game.config.tile_gl_height;
        }
    } else {
        blit_br.y += diff;
        blit_tl.y += diff;
    }

    if (tp_is_outlined(tp)) {
        tile_blit_fat_outline(tp, tile, blit_tl, blit_br);
    } else {
        tile_blit_fat(tp, tile, blit_tl, blit_br);
    }

    if (top_tile) {
        if (tp_is_wall(tp)) {
            blit_wall_cladding(blit_tl, blit_br);
        }
        if (tp_is_rock(tp)) {
            blit_rock_cladding(blit_tl, blit_br);
        }
    }
}
