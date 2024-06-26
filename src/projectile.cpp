//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_game.hpp"
#include "my_thing.hpp"
#include <algorithm>

Projectile_::Projectile_(Levelp level, ThingId thing_id, ThingId victim_id, ProjectileInfo info)
    : id(thing_id), victim_id(victim_id), info(info)
{
  TRACE_AND_INDENT();
  auto t = level->thing_find(id);
  if (unlikely(! t)) {
    ERR("no projectile");
    return;
  }

  //
  // Can be either a staff or the projectile itself being fired
  //
  std::string name;
  if (t->is_projectile()) {
    name = t->tp()->name();
  } else {
    name = t->gfx_targeted_projectile();
    if (name.empty()) {
      t->err("no projectile name");
      return;
    }
  }

  if (g_opt_ascii) {
    //
    // Just use the ascii char in the animation for the projectile.
    //
    return;
  }

  //
  // Some things like darts are very simply animated.
  //
  auto proj_tp = tp_find(name);
  if (proj_tp && tile_find(name)) {
    auto anim_tiles = &proj_tp->tiles;
    for (int frame = 0; frame < max_frames; frame++) {
      auto tile = tile_n(anim_tiles, frame);
      tiles.push_back(tile);
    }
    return;
  }

  //
  // Find all projectile animation tiles. Names look like this:
  //
  // "projectile_green.{frame}.1",
  // "projectile_green.{frame}.2",
  // "projectile_green.{frame}.3",
  // "projectile_green.{frame}.4",
  // "projectile_green.{frame}.5",
  // "projectile_green.{frame}.6",
  // "projectile_green.{frame}.7",
  // "projectile_green.{frame}.8",
  // "projectile_green.{frame}.9",
  // "projectile_green.{frame}.10",
  // "projectile_green.{frame}.11",
  // "projectile_green.{frame}.12",
  // "projectile_green.{frame}.13",
  // "projectile_green.{frame}.14",
  // "projectile_green.{frame}.15",
  // "projectile_green.{frame}.16",
  //
  // Use the preferred name if set.
  //
  if (proj_tp) {
    if (! proj_tp->gfx_targeted_projectile().empty()) {
      name = proj_tp->gfx_targeted_projectile();
    }
  }

  for (int frame = 0; frame < max_frames; frame++) {
    tiles.push_back(tile_find_mand(name + "." + std::to_string(frame + 1)));
  }
}

void Level::new_projectile(ThingId id, ThingId victim_id, ProjectileInfo info, uint32_t dur)
{
  TRACE_AND_INDENT();
  if (id.ok()) {
    auto t = thing_find(id);
    if (t) {
      if (t->has_projectile) {
        return;
      }
      t->has_projectile = true;
      IF_DEBUG { t->log("New projectile"); }
    }
  }

  uint32_t now  = time_game_ms();
  info.ts_start = now;

  info.ts_stop = now + dur;
  new_projectiles.push_back(Projectile(this, id, victim_id, info));
}

void Level::display_projectiles(point tl, point br)
{
  TRACE_NO_INDENT();

  if (0) {
    CON("- particles:");
    for (auto p : all_projectiles) {
      CON("all int p %d,%d to @%d,%d", p.info.map_start.x, p.info.map_start.y, p.info.map_stop.x, p.info.map_stop.y);
    }
    for (auto p : new_projectiles) {
      CON("new int p %d,%d to @%d,%d", p.info.map_start.x, p.info.map_start.y, p.info.map_stop.x, p.info.map_stop.y);
    }
  }

  all_projectiles.insert(std::end(all_projectiles), std::begin(new_projectiles), std::end(new_projectiles));
  new_projectiles.clear();

  if (all_projectiles.empty()) {
    return;
  }

  if (g_opt_ascii) {
    display_ascii_projectiles(tl, br);
  } else {
    display_pixelart_projectiles(tl, br);
  }
}

bool Thing::projectile_anim_exists(void)
{
  TRACE_AND_INDENT();
  return has_projectile;
}

void Thing::delete_projectile(void)
{
  TRACE_AND_INDENT();
  auto e = std::remove_if(level->all_projectiles.begin(), level->all_projectiles.end(), [ =, this ](Projectile &p) {
    if (p.id == id) {
      log("Remove projectile");
      return true;
    }
    return false;
  });

  level->all_projectiles.erase(e, level->all_projectiles.end());

  has_projectile = false;
}
