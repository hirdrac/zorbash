//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_game.hpp"
#include "my_thing.hpp"

void Level::create(point3d world_at, point grid_at, int difficulty_depth, int dungeon_walk_order_level_no)
{
  TRACE_NO_INDENT();

  DBG("Create level");
  pcg_random_allowed++;

  if (difficulty_depth > DUNGEONS_MAX_DIFFICULTY_LEVEL) {
    difficulty_depth = DUNGEONS_MAX_DIFFICULTY_LEVEL;
  }

  uint32_t seedval;

  if (dungeon_walk_order_level_no <= 1) {
    seedval = game->seed + 1; // +1 is a temporary hack
  } else {
    seedval = (world_at.z * DUNGEONS_GRID_CHUNK_HEIGHT * DUNGEONS_GRID_CHUNK_WIDTH)
            + (world_at.y * DUNGEONS_GRID_CHUNK_HEIGHT) + world_at.x
            + (dungeon_walk_order_level_no * (123 * DUNGEONS_GRID_CHUNK_HEIGHT * DUNGEONS_GRID_CHUNK_WIDTH))
            + (difficulty_depth * 121121);
  }

  game->seed = seedval;

  pcg_srand(seedval);

  is_starting = true;
  clear();

  this->seed                        = seedval;
  this->difficulty_depth            = difficulty_depth;
  this->dungeon_walk_order_level_no = dungeon_walk_order_level_no;
  this->world_at                    = world_at;
  this->grid_at                     = grid_at;

  IF_DEBUG2
  {
    log("-");
    log("Creating, seed %u", seedval);
    log("| | | | | | | | | | | | | | | | | | | | | | | | | | |");
    log("v v v v v v v v v v v v v v v v v v v v v v v v v v v");
  }

  //
  // Must set the level pointer so for e.g. spiders can spawn webs when born
  //
  game->level_being_created = this;

  if (player) {
    TOPCON("A new dungeon level is coming into being...");
  }

  bool ret;
  switch (biome) {
    case BIOME_DUNGEON : ret = create_biome_dungeon(world_at, seed); break;
    case BIOME_FLOODED : ret = create_biome_flooded(world_at, seed); break;
    case BIOME_SWAMP : ret = create_biome_swamp(world_at, seed); break;
    case BIOME_SEWER : ret = create_biome_sewer(world_at, seed); break;
    case BIOME_CHASMS : ret = create_biome_chasms(world_at, seed); break;
    case BIOME_ICE : ret = create_biome_ice(world_at, seed); break;
    case BIOME_LAVA : ret = create_biome_lava(world_at, seed); break;
    default :
      DIE("No biome set for level create");
      ret = create_biome_dungeon(world_at, seed);
      break;
  }

  if (! monst_count) {
    if (g_opt_biome_chasms || g_opt_biome_ice || g_opt_biome_lava || g_opt_biome_swamp || g_opt_biome_flooded) {
      //
      // Ignore for testing
      //
    } else {
      if (biome != BIOME_SEWER) {
        err("No monsters placed on level, difficulty_depth %d", difficulty_depth);
      }
    }
  }

  game->level_being_created = nullptr;

  IF_DEBUG2
  {
    log("^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^");
    log("| | | | | | | | | | | | | | | | | | | | | | | | | | |");
    log("Created, seed %u", seed);
    log("-");
  }

  if (! ret) {
    err("Failed to create level");
  }

  update_map();

  game->started = true;
  is_starting   = false;

  ts_fade_in_begin = time_ms_cached();

  things_gc_force();

  if (! cursor && player) {
    cursor = cursor_thing_new(player->curr_at);
    if (cursor) {
      cursor->hide("level create, cursor hide");
    }
    is_map_mini_valid = true;
  }

  created();

  pcg_random_allowed--;
}

void Level::created(void)
{
  TRACE_NO_INDENT();

  assign_leaders_and_followers();
}

void Level::place_the_grid(void)
{
  TRACE_NO_INDENT();

  for (auto x = 0; x < MAP_WIDTH; x++) {
    for (auto y = 0; y < MAP_HEIGHT; y++) {
      (void) thing_new("the_grid", point(x, y));
      if (g_errored) {
        DIE("Could not create level");
        return;
      }
    }
  }
}

int Level::total_monst_hp_level(void)
{
  int hp = 0;
  TRACE_NO_INDENT();
  FOR_ALL_INTERESTING_THINGS_ON_LEVEL(this, t)
  {
    if (t->is_monst()) {
      hp += t->health_max();
    }

    if (t->is_mob()) {
      hp += t->health_max() * t->minion_limit();
    }
  }
  TRACE_NO_INDENT();
  FOR_ALL_INTERESTING_THINGS_ON_LEVEL_END(this)
  return hp;
}

int Level::total_monst_dmg_level(void)
{
  int damage = 0;
  TRACE_NO_INDENT();
  FOR_ALL_INTERESTING_THINGS_ON_LEVEL(this, t)
  {
    if (t->is_mob() || t->is_monst()) {
      damage += t->dmg_melee_dice().max_roll();
      damage += t->dmg_poison_dice().max_roll();
      damage += t->dmg_drown_dice().max_roll();
      damage += t->dmg_bite_dice().max_roll();
      damage += t->dmg_claw_dice().max_roll();
      damage += t->dmg_cold_dice().max_roll();
      damage += t->dmg_fire_dice().max_roll();
      damage += t->dmg_heat_dice().max_roll();
      damage += t->dmg_crush_dice().max_roll();
      damage += t->dmg_impact_dice().max_roll();
      damage += t->dmg_missile_dice().max_roll();
      damage += t->dmg_lightning_dice().max_roll();
      damage += t->dmg_energy_dice().max_roll();
      damage += t->dmg_negation_dice().max_roll();
      damage += t->dmg_acid_dice().max_roll();
      damage += t->dmg_water_dice().max_roll();
      damage += t->dmg_digest_dice().max_roll();
      damage += t->dmg_digest_dice().max_roll();
      damage += t->dmg_nat_att_dice().max_roll();
    }
  }
  TRACE_NO_INDENT();
  FOR_ALL_INTERESTING_THINGS_ON_LEVEL_END(this)
  return damage;
}

int Level::total_loot_level(void)
{
  int value = 0;
  TRACE_NO_INDENT();
  FOR_ALL_INTERESTING_THINGS_ON_LEVEL(this, t)
  {
    if (t->is_treasure() || t->is_weapon() || t->is_staff()) {
      value += t->gold_value();
    }
  }
  TRACE_NO_INDENT();
  FOR_ALL_INTERESTING_THINGS_ON_LEVEL_END(this)
  return value;
}

int Level::total_food_level(void)
{
  int value = 0;
  TRACE_NO_INDENT();
  FOR_ALL_INTERESTING_THINGS_ON_LEVEL(this, t)
  {
    if (t->is_food()) {
      value += t->nutrition_get();
    }
  }
  TRACE_NO_INDENT();
  FOR_ALL_INTERESTING_THINGS_ON_LEVEL_END(this)
  return value;
}
