//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_game.hpp"
#include "my_monst.hpp"
#include "my_thing.hpp"

void Game::place_player(void)
{
  //
  // Place the player if we do not have one.
  //
  if (! level) {
    ERR("No level for player");
    return;
  }

  DBG("Place player");

  for (auto x = MAP_BORDER_ROCK; x < MAP_WIDTH - MAP_BORDER_ROCK; x++) {
    for (auto y = MAP_BORDER_ROCK; y < MAP_HEIGHT - MAP_BORDER_ROCK; y++) {

      //
      // Place the player at the ascend exit
      //
      if (! level->is_ascend_dungeon(x, y)) {
        continue;
      }

      CarryOptions carry_options;
      carry_options.is_able_to_be_equipped = true;

      auto t = level->thing_new("player1", point(x, y));
      if (! t) {
        DIE("Failed to create player");
      }

      FOR_ALL_BODYPART(e)
      {
        auto b = level->thing_new(tp_random_bodypart(e), point(x, y));
        t->bodypart_add(b, e);
      }

      if (0) {
        auto k = level->thing_new("key", point(x, y));
        t->carry(k, carry_options);
      }
      if (1) {
        auto w = level->thing_new("sword_rusty", point(x, y));
        t->carry(w, carry_options);
      }
      if (1) {
        auto w = level->thing_new("dagger", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("potion_health", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("potion_invisibility", point(x, y));
        t->carry(w, carry_options);
      }
      {
        //
        // Darts
        //
        for (auto d = 0; d < 2; d++) {
          auto w = level->thing_new("dart", point(x, y));
          t->carry(w, carry_options);
        }
        if (0) {
          auto w = level->thing_new("dart_metal", point(x, y));
          t->carry(w, carry_options);
        }
        if (0) {
          auto w = level->thing_new("dart_poison", point(x, y));
          t->carry(w, carry_options);
        }
      }
      if (1) {
        auto w = level->thing_new("pottedmeat", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("horseshoe", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("armor_lather", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("sword_plutonium", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("staff_descent", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("gauntlets_lion", point(x, y - 2));
        t->carry(w, carry_options);
        t->enchant_without_stone(w);
        t->enchant_without_stone(w);
      }
      if (0) {
        auto w = level->thing_new("potion_health", point(x, y - 2));
        w->enchant_randomly();
      }
      if (0) {
        auto w = level->thing_new("buff_undead_protection", point(x, y));
        t->buff_add(w);
      }
      if (0) {
        auto w = level->thing_new("debuff_necrotized", point(x, y));
        t->debuff_add(w);
      }
      // level->thing_new("zorb_wizard", point(x - 4, y));
      if (0) {
        level->thing_new("zorb_necro", point(x + 2, y));
        level->thing_new("zorb_pirate", point(x + 2, y + 1));
        level->thing_new("fire", point(x + 1, y - 1));
        level->thing_new("fire", point(x + 1, y + 1));
        level->thing_new("small_fire", point(x + 3, y + 3));
      }

      if (0) {
        level->thing_new("portal", point(x, y + 4));
        level->thing_new("portal", point(x - 2, y + 7));
        level->thing_new("potion_health", point(x - 2, y + 9));
        level->thing_new("potion_health", point(x - 2, y));
      }

      if (0) {
        auto w = level->thing_new("skill_primal_rage1", point(x, y));
        t->skill_add(w);
      }
      if (0) {
        auto w = level->thing_new("skill_devoted_thrust1", point(x, y));
        t->skill_add(w);
      }
      if (0) {
        auto w = level->thing_new("skill_double_strike1", point(x, y));
        t->skill_add(w);
      }

      if (0) {
        level->thing_new("wall_dungeon.1", point(x - 2, y + 2));
        level->thing_new("wall_dungeon.1", point(x - 1, y + 2));
        level->thing_new("wall_dungeon.1", point(x, y + 2));
        level->thing_new("wall_dungeon.1", point(x + 1, y + 2));
        level->thing_new("wall_dungeon.1", point(x + 2, y + 2));
        level->thing_new("trap_pressure_plate_gas", point(x - 2, y));
        level->thing_new("rat_large", point(x + 1, y + 3));
        level->thing_new("trap_monster", point(x - 2, y));
      }
      if (0) {
        level->thing_new("lava_ant", point(x - 2, y));
        level->thing_new("dogman", point(x + 1, y + 3));
        level->thing_new("wet_grass1", point(x + 1, y));
        level->thing_new("wet_grass2", point(x + 2, y));
        level->thing_new("wet_grass4", point(x + 3, y));
        level->thing_new("wet_grass1", point(x + 1, y + 2));
        level->thing_new("wet_grass2", point(x + 2, y + 2));
        level->thing_new("wet_grass4", point(x + 3, y + 2));
        level->thing_new("dry_grass", point(x + 1, y + 1));
        level->thing_new("dry_grass", point(x + 2, y + 1));
        level->thing_new("dry_grass", point(x + 3, y + 1));
      }

      if (0) {
        level->thing_new("gold6", point(x + 1, y));
        auto w = level->thing_new("skill_gold_to_health", point(x, y));
        t->skill_add(w);
      }
      if (0) {
        auto w = level->thing_new("amulet_endurance", point(x, y - 2));
        t->carry(w, carry_options);
      }
      if (0) {
        level->thing_new("portable_hole", point(x - 3, y));
        auto w = level->thing_new("amulet_teleport_attack", point(x, y - 2));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("staff_lightning", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("staff_fire", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("staff_cold", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("staff_energy", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("staff_descent", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("pike", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("scythe", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("double_shovel", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("shovel", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto r1 = level->thing_new("ring_is_immune_to_negation", point(x, y));
        t->carry(r1, carry_options);
        auto r2 = level->thing_new("ring_is_immune_to_poison", point(x, y));
        t->carry(r2, carry_options);
      }
      if (0) {
        auto r1 = level->thing_new("ring_shield", point(x, y));
        t->carry(r1, carry_options);
      }
      if (0) {
        auto r1 = level->thing_new("shield_eagle", point(x, y));
        t->carry(r1, carry_options);
      }
      if (0) {
        auto r2 = level->thing_new("ring_is_immune_to_poison", point(x, y));
        t->carry(r2, carry_options);
      }
      if (0) {
        auto r3 = level->thing_new("ring_is_immune_to_fire", point(x, y));
        t->carry(r3, carry_options);
        auto r4 = level->thing_new("ring_is_immune_to_cold", point(x, y));
        t->carry(r4, carry_options);
      }
      if (0) {
        auto w = level->thing_new("very_broadsword", point(x + 3, y));
        w->enchant_randomly();
        // t->carry(w,carry_options);
        // t->enchant_without_stone(w);
      }
      if (0) {
        auto w = level->thing_new("sword_draining", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("axe", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("staff_energy", point(x, y));
        t->carry(w, carry_options);
      }
      if (1) {
        auto w = level->thing_new("torch", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("wooden_cross", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("boots_fluffy", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("cloak_stone", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("cloak_fire", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("cloak_protection", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("torch", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto b = level->thing_new("bag_small", point(x, y));
        t->carry(b, carry_options);
      }
      if (0) {
        level->thing_new("bag_large", point(x + 1, y));
      }
      if (0) {
        auto b = level->thing_new("enchantstone", point(x, y));
        t->carry(b, carry_options);
      }
      if (0) {
        auto b = level->thing_new("enchantstone", point(x, y));
        t->carry(b, carry_options);
      }
      if (1) {
        {
          for (auto sk = 0; sk < 1; sk++) {
            auto b = level->thing_new("skillstone", point(x, y));
            t->carry(b, carry_options);
          }
        }
      }
      if (0) {
        auto b = level->thing_new("thunderstone", point(x, y));
        t->carry(b, carry_options);
      }
      if (0) {
        auto b = level->thing_new("chest1", point(x, y));
        auto w = level->thing_new("wooden_cross", point(x, y));
        b->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("staff_energy", point(x, y));
        t->carry(w, carry_options);
        t->enchant_without_stone(w);
      }
      if (0) {
        auto w = level->thing_new("map_treasure", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("map_beast", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto w = level->thing_new("staff_negation", point(x, y));
        t->carry(w, carry_options);
      }
      if (0) {
        auto d = level->thing_new("dogman", point(x + 2, y));
        d->wake("");
      }
      if (0) {
        level->thing_new("scorpion_death", point(x + 2, y + 1));
        level->thing_new("yeti", point(x + 2, y + 1));
        level->thing_new("mantisman", point(x + 2, y + 1));
        level->thing_new("iceman", point(x + 2, y + 1));
        level->thing_new("molekin", point(x + 2, y + 1));
        level->thing_new("gnome_rock", point(x + 2, y + 1));
        level->thing_new("bloodbug", point(x + 2, y + 1));
        level->thing_new("death_hornet", point(x + 2, y + 1));
        level->thing_new("bear_undead", point(x + 2, y + 1));
        level->thing_new("meatfairy", point(x + 2, y + 1));
        level->thing_new("bearowl", point(x + 2, y + 1));
        level->thing_new("carcas_creeper", point(x + 2, y + 1));
        level->thing_new("centipede", point(x - 2, y + 1));
        level->thing_new("demon_fire", point(x + 4, y));
        level->thing_new("ogre", point(x + 4, y));
        level->thing_new("troll_stone", point(x + 2, y));
        level->thing_new("troll_fire", point(x + 2, y + 2));
        level->thing_new("ettin", point(x + 2, y));
        level->thing_new("cthulite", point(x + 2, y));
        level->thing_new("cyclops", point(x + 2, y));
        level->thing_new("gargoyle_baby", point(x + 2, y + 2));
        level->thing_new("mimic_sleeping", point(x - 2, y + 2));
        level->thing_new("chest1", point(x + 2, y + 2));
        level->thing_new("chest2", point(x + 3, y + 2));
        level->thing_new("scorpion_colossal", point(x + 3, y + 2));
        level->thing_new("cthulite", point(x + 3, y + 2));
        level->thing_new("blinkcat", point(x + 2, y + 1));
        level->thing_new("gnome_thief", point(x + 2, y + 1));
        level->thing_new("gnome_rock", point(x + 2, y + 1));
        level->thing_new("gnome_knight", point(x + 2, y + 1));
        level->thing_new("goat_battle", point(x + 2, y + 1));
        level->thing_new("goat_demon", point(x + 2, y + 1));
        level->thing_new("gnome_dwarf", point(x + 2, y + 1));
        level->thing_new("rat_large", point(x + 1, y + 3));
        level->thing_new("dogman", point(x + 1, y + 3));
        level->thing_new("golem_cement", point(x + 4, y + 2));
        level->thing_new("amulet_healing", point(x + 1, y - 3));
        level->thing_new("amulet_peeking", point(x + 2, y - 3));
        level->thing_new("amulet_endurance", point(x, y - 3));
        level->thing_new("shield_eagle", point(x, y - 2));
        level->thing_new("zorb_priest", point(x + 1, y + 3));
        level->thing_new("mummy_necro", point(x + 1, y));
        level->thing_new("reaper", point(x + 3, y));
        level->thing_new("tentacleye", point(x + 1, y + 1));
        level->thing_new("tentacleye", point(x + 1, y + 2));
        level->thing_new("zorb_eldster", point(x + 1, y + 3));
        level->thing_new("flameskull", point(x + 1, y + 4));
        level->thing_new("tentacleye", point(x + 1, y + 1));
        level->thing_new("tentacleye", point(x + 2, y + 2));
        level->thing_new("pyrolizard", point(x + 2, y + 3));
        level->thing_new("cleaner", point(x + 3, y + 1));
        level->thing_new("zorb_eldster", point(x + 3, y + 2));
        level->thing_new("snake_dreadfire", point(x + 3, y + 3));
        level->thing_new("zorb_eldster", point(x + 3, y + 4));
        // auto w = level->thing_new("staff_lightning", point(x, y));
        // auto w = level->thing_new("staff_descent", point(x, y));
        auto w1 = level->thing_new("staff_cold", point(x, y));
        t->carry(w1, carry_options);
        auto w2 = level->thing_new("staff_fire", point(x, y));
        t->carry(w2, carry_options);
        // t->enchant_without_stone(w);
      }
      if (0) {
        auto w = level->thing_new("rock", point(x, y));
        t->carry(w, carry_options);
        t->enchant_without_stone(w);
      }
      if (0) {
        auto w = level->thing_new("staff_fire", point(x, y));
        t->carry(w, carry_options);
        t->enchant_without_stone(w);
      }
      if (0) {
        auto w = level->thing_new("staff_descent", point(x, y));
        t->carry(w, carry_options);
        t->enchant_without_stone(w);
      }
      if (0) {
        level->thing_new("spider_bone", point(x + 2, y + 3));
        level->thing_new("crab_sewer", point(x + 3, y + 3));
        level->thing_new("sheep", point(x + 1, y + 3));
        level->thing_new("goat_battle", point(x + 2, y + 1));
        level->thing_new("moresquito", point(x + 2, y + 3));
        level->thing_new("fleshbee", point(x + 1, y + 3));
        level->thing_new("narhornet", point(x + 0, y + 3));
        level->thing_new("spider_para", point(x + 2, y + 4));
        level->thing_new("spider_brown", point(x + 2, y + 4));
        level->thing_new("spider_flux", point(x - 2, y - 3));
        level->thing_new("leech_giant", point(x + 2, y));
        level->thing_new("water", point(x + 1, y));
        level->thing_new("water", point(x + 2, y));
        level->thing_new("water", point(x + 3, y));
        level->thing_new("water", point(x + 4, y));

        level->thing_new("water", point(x + 1, y + 1));
        level->thing_new("water", point(x + 2, y + 1));
        level->thing_new("water", point(x + 3, y + 1));
        level->thing_new("water", point(x + 4, y + 1));

        level->thing_new("water", point(x + 1, y + 2));
        level->thing_new("water", point(x + 2, y + 2));
        level->thing_new("water", point(x + 3, y + 2));
        level->thing_new("water", point(x + 4, y + 2));

        level->thing_new("water", point(x + 1, y + 3));
        level->thing_new("water", point(x + 2, y + 3));
        level->thing_new("water", point(x + 3, y + 3));
        level->thing_new("water", point(x + 4, y + 3));

        level->thing_new("water", point(x + 1, y + 4));
        level->thing_new("water", point(x + 2, y + 4));
        level->thing_new("water", point(x + 3, y + 4));
        level->thing_new("water", point(x + 4, y + 4));

        level->thing_new("water", point(x + 1, y + 5));
        level->thing_new("water", point(x + 2, y + 5));
        level->thing_new("water", point(x + 3, y + 5));
        level->thing_new("water", point(x + 4, y + 5));

        // level->thing_new("electric_eel", point(x + 3, y + 2));
        level->thing_new("eel", point(x + 3, y + 4));
        // level->thing_new("teletoad", point(x + 3, y + 3));
        // level->thing_new("kraken", point(x + 2, y + 2));

        // level->thing_new("cleaner", point(x + 2, y - 2));
      }

      if (0) {
        level->thing_new("door_metal", point(x + 2, y));
        // d->dead("killed");
      }
      // level->thing_new("golem_flesh", point(x + 1, y + 3));
      IF_DEBUG2
      {
        if (0) {
          level->thing_new("lava", point(x + 1, y));
          level->thing_new("lava", point(x + 2, y));
          level->thing_new("lava", point(x + 3, y));
        }
        if (0) {
          level->thing_new("coffin_mob", point(x + 2, y + 1));
        }
        if (0) {
          level->thing_new("barrel", point(x + 2, y + 1));
          level->thing_new("rat_giant", point(x + 3, y + 1));
        }
        if (0) {
          level->thing_new("staff_energy", point(x, y + 1));
        }
        // level->thing_new("gargoyle_moving", point(x + 2, y - 5));
        // level->thing_new("rat_giant", point(x - 1, y));
        // level->thing_new("rat_giant", point(x + 1, y));
        // level->thing_new("rat_giant", point(x, y - 1));
        // level->thing_new("rock1", point(x + 1, y));
        // level->thing_new("rock1", point(x + 3, y));
        // level->thing_new("gargoyle_static", point(x + 2, y - 2));
        // level->thing_new("frog", point(x + 3, y - 1));
        // level->thing_new("fire", point(x + 1, y - 1));
        // level->thing_new("enchantstone", point(x + 1, y - 1));
        // level->thing_new("skillstone", point(x + 1, y - 1));
        // level->thing_new("horseshoe", point(x, y));
        // level->thing_new("four_leaf_clover", point(x, y));
        // level->thing_new("medal_of_valor", point(x, y));
        // level->thing_new("wooden_cross", point(x, y));
        // level->thing_new("armor_lather", point(x, y));
        // level->thing_new("boots_fluffy", point(x, y - 2));
        // level->thing_new("boots_silence", point(x, y - 2));
        // level->thing_new("boots_teleport", point(x, y - 2));
        // level->thing_new("mummy_necro", point(x + 5, y + 1));
        // level->thing_new("shield_woodon", point(x, y - 2));
        // level->thing_new("fire", point(x, y - 2));
        // level->thing_new("frog", point(x, y - 2));
        // level->thing_new("cleaner", point(x + 1, y + 3));
        // level->thing_new("thunderstone", point(x, y - 2));
        // level->thing_new("zorb_eldster", point(x + 5, y));
        // level->thing_new("key", point(x + 5, y));
        // level->thing_new("key_pair", point(x - 1, y - 2));
        // level->thing_new("key_golden", point(x - 1, y + 2));
        // level->thing_new("key_penta", point(x, y + 12));
        // level->thing_new("snake_viper", point(x, y + 2));
        // level->thing_new("zorb_pack", point(x + 2, y));
        // level->thing_new("mummy_pack", point(x + 2, y + 12));
        // level->thing_new("barrel", point(x - 2, y));
        // level->thing_new("floor_red_blood1", point(x + 2, y + 1));
        // level->thing_new("teleport", point(x + 2, y + 2));
        // level->thing_new("scorpion", point(x + 2, y + 2));
        level->assign_leaders_and_followers();
      }
      // level->thing_new("sentry_orb_energy", point(x - 3, y));
      if (0) {
        level->thing_new("portable_hole", point(x - 3, y));
        level->thing_new("cleaner", point(x, y));
        level->thing_new("gargoyle_static", point(x, y + 1));
      }
      if (0) {
        level->thing_new("foliage", point(x, y + 1));
        level->thing_new("mummy", point(x - 1, y + 1));
      }
      // level->thing_new("pyrolizard", point(x - 2, y + 1));
      // level->thing_new("vampire_rose", point(x - 2, y + 1));
      // level->thing_new("blob", point(x - 2, y + 1));
      if (0) {
        auto d = level->thing_new("belcher", point(x - 3, y + 1));
        d->wake("");
      }
      // level->thing_new("cleaner", point(x - 3, y + 2));
      if (0) {
        auto d = level->thing_new("bat_lesser", point(x + 2, y + 2));
        d->wake("");
        d->is_burnt = true;
        d->dead("x");
      }
      if (0) {
        level->thing_new("lava", point(x + 2, y + 1));
        level->thing_new("block_of_ice", point(x + 2, y + 1));
      }
      // level->thing_new("vampire_rose_stem", point(x, y + 1));
      // level->thing_new("fire", point(x - 4, y + 5));
      // level->thing_new("foliage", point(x - 4, y + 5));
      // level->thing_new("foliage", point(x, y + 5));
      // level->player->on_fire_set("");
      // level->thing_new("block_of_ice", point(x, y + 1));
      // level->thing_new("block_of_ice", point(x, y + 2));
      if (0) {
        level->thing_new("vampire_rose_stem1", point(x - 1, y + 2));
        level->thing_new("vampire_rose_stem2", point(x + 1, y + 2));
        level->thing_new("vampire_rose_stem1", point(x - 1, y + 1));
        level->thing_new("vampire_rose_stem2", point(x + 1, y + 1));
        level->thing_new("vampire_rose_stem1", point(x, y + 1));
        level->thing_new("vampire_rose_stem2", point(x - 1, y + 3));
        level->thing_new("vampire_rose_stem1", point(x + 1, y + 3));
        level->thing_new("vampire_rose_stem2", point(x, y + 3));
        level->thing_new("vampire_rose_stem1", point(x - 1, y + 4));
        level->thing_new("vampire_rose_stem2", point(x + 1, y + 4));
        level->thing_new("vampire_rose_stem1", point(x, y + 4));
      }
      if (0) {
        level->thing_new("slime_parent", point(x, y + 4));
        level->thing_new("slime_baby", point(x, y + 4));
      }
      if (0) {
        auto d = level->thing_new("dogman", point(x + 1, y + 2));
        d->dead("x");
      }

      // level->thing_new("staff_descent", point(x + 5, y + 2));
      // level->thing_new("fire", point(x + 5, y + 2));
      // level->thing_new("spiderweb", point(x, y));
      // level->thing_new("spider_onyx_widow", point(x + 2, y));
      // level->thing_new("spider_giant", point(x + 2, y));
      if (0) {
        level->thing_new("bat_lesser", point(x + 2, y + 1));
      }
      // level->thing_new("golem_flesh", point(x, y + 3));
      // level->thing_new("lava", point(x, y + 5));
      // level->thing_new("lava", point(x, y + 6));
      // level->thing_new("lava", point(x, y + 7));
      // level->thing_new("lava", point(x + 1, y + 5));
      // level->thing_new("lava", point(x + 1, y + 6));
      // level->thing_new("lava", point(x + 1, y + 7));
      // level->thing_new("lava", point(x + 1, y + 7));
      //
      if (0) {
        auto m = level->thing_new("coffin_mob", point(x, y + 4));
        m->frozen_set();
      }
      // level->thing_new("flameskull", point(x, y + 4));

      if (0) {
        auto m = level->thing_new("slime_parent", point(x, y + 4));
        m->frozen_set();
      }
      // level->thing_new("slime_baby", point(x, y + 2));
      //
      // Zoom the map to the player
      //
      level->scroll_map_to_player();

      DBG("INF: Placed player");

      goto done;
    }
  }

done:
  level->ts_fade_in_begin = time_ms_cached();
  level->ts_redraw_bg     = 1; // Force redraw

  auto player = level->player;
  if (player) {
    level->request_player_light_update = true;

    if (0) {
      level->thing_new("water", point(player->curr_at.x, player->curr_at.y));
      level->thing_new("water", point(player->curr_at.x + 1, player->curr_at.y));
      level->thing_new("water", point(player->curr_at.x + 1, player->curr_at.y + 1));
      level->thing_new("water", point(player->curr_at.x + 2, player->curr_at.y + 1));
      // level->thing_new("block_of_ice", point(player->curr_at.x, player->curr_at.y));
      // player->frozen_set();
      // level->thing_new("lava", point(player->curr_at.x, player->curr_at.y));
    }

    if (0) {
      IF_DEBUG2
      {
        player->health_max_incr(200);
        // player->health_decr(90);
      }
    }

    game->player_is_ready_for_messages = true;

    player->log("Placed");
  }
}
