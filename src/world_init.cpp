//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_array_bounds_check.hpp"
#include "my_world.hpp"

void World::clear(void)
{
  TRACE_AND_INDENT();
  LOG("World init: Clear all levels");
  for (auto x = 0; x < LEVELS_ACROSS; ++x) {
    for (auto y = 0; y < LEVELS_DOWN; ++y) {
      for (auto z = 0; z < LEVELS_DEEP; ++z) {
        auto l = get(levels, x, y, z);
        if (l) {
          l->clear();
        }
      }
    }
  }
}

Levelp World::new_level_at(point3d world_at, point grid_at, uint32_t seed, int difficulty_depth,
                           int dungeon_walk_order_level_no)
{
  TRACE_AND_INDENT();

  //
  // Choose the biome for the level
  //
  auto biome = BIOME_DUNGEON;
  switch (difficulty_depth) {
    case 0:
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
    default: biome = BIOME_DUNGEON; break;
    case 2:
    case 3: biome = BIOME_SWAMP; break;
  }

  if (! (world_at.z & 1)) {
    biome = BIOME_SEWER;
  }

  if (g_opt_biome_swamp) {
    biome = BIOME_SWAMP;
  }

  //
  // If the old level exists, remove it
  //
  auto old_level = get(levels, world_at.x, world_at.y, world_at.z);
  delete old_level;

  //
  // Create the new level
  //
  auto new_level = new Level(biome);
  set(levels, world_at.x, world_at.y, world_at.z, new_level);
  new_level->create(world_at, grid_at, seed, difficulty_depth, dungeon_walk_order_level_no);

  return new_level;
}
