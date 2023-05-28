//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_level.hpp"

//
// Templates can be assigned dynamic IDs - however the levels are more reproducable it
// they have fixed numbers. This list helps to achieve that. It is optional for a template
// to be in this list
//
std::initializer_list< std::string > tps = {
    "", // ID 0 means unused
    "acid1",
    "ai_path1",
    "ai_path2",
    "amulet_endurance",
    "amulet_endurance_carry",
    "amulet_healing",
    "amulet_healing_carry",
    "amulet_peeking",
    "amulet_peeking_carry",
    "amulet_teleport_attack",
    "amulet_teleport_attack_carry",
    "apple1",
    "apple2",
    "apple_cider",
    "applepie",
    "armor_fish_scale",
    "armor_fish_scale_carry",
    "armor_lather",
    "armor_lather_carry",
    "armor_lathered",
    "armor_lathered_carry",
    "armor_leather",
    "armor_leather_carry",
    "armor_lime_scale",
    "armor_lime_scale_carry",
    "ascend_dungeon",
    "spider_bone",
    "ascend_sewer1",
    "ascend_sewer2",
    "ascend_sewer3",
    "ascend_sewer4",
    "attack_green",
    "attack_major_green",
    "attack_major_orange",
    "attack_major_red",
    "attack_orange",
    "attack_punch",
    "attack_red",
    "aubergine",
    "axe",
    "axe_carry",
    "axe_swing",
    "bacon",
    "bag_l",
    "bag_s",
    "baguette",
    "barrel",
    "basalt",
    "bat_greater",
    "bat_lesser",
    "bat_minion",
    "bearowl",
    "bear_undead",
    "bloodbug",
    "beer1",
    "beer2",
    "belcher",
    "blinkcat",
    "block_of_ice",
    "fleshbee",
    "bones.1",
    "bones.2",
    "bones.3",
    "bones.4",
    "bones.5",
    "bones.6",
    "boots_fluffy",
    "boots_fluffy_carry",
    "boots_haste",
    "boots_haste_carry",
    "boots_jumping",
    "boots_jumping_carry",
    "boots_silence",
    "boots_silence_carry",
    "boots_teleport",
    "boots_teleport_carry",
    "boots_teleport_emer",
    "boots_teleport_emer_carry",
    "brazier",
    "bridge_lr",
    "bridge_ud",
    "bridge_x",
    "buff_full",
    "buff_is_immune_to_cold",
    "buff_is_immune_to_fire",
    "buff_is_immune_to_negation",
    "buff_is_immune_to_poison",
    "buff_is_immune_to_teleport_attack",
    "buff_is_immune_to_water",
    "buff_is_invisible",
    "buff_missile_protection",
    "buff_slippery",
    "buff_undead_protection",
    "carcas_creeper",
    "centipede",
    "chasm1",
    "cheesecake",
    "cherry",
    "chest1",
    "chest2",
    "chicken",
    "chocolate_bar",
    "cleaner",
    "cloak_fire",
    "cloak_fire_carry",
    "cloak_protection",
    "cloak_protection_carry",
    "cloak_stone",
    "cloak_stone_carry",
    "coffin_mob",
    "cookie",
    "corridor1",
    "corridor2",
    "crab_sewer",
    "cthulite",
    "cursor",
    "cursor_path",
    "cursor_select",
    "cursor_select_fail",
    "cursor_select_fail_path",
    "cursor_select_path",
    "custardpie",
    "cutlass",
    "cutlass_carry",
    "cutlass_swing",
    "cyclops",
    "dagger",
    "dagger_carry",
    "dagger_swing",
    "dart",
    "dart_metal",
    "dart_poison",
    "death_hornet",
    "debuff_hungry",
    "debuff_necrotized",
    "debuff_poisoned",
    "debuff_starving",
    "debug_path",
    "deep_water",
    "demon_fire",
    "descend_sewer1",
    "descend_sewer2",
    "descend_sewer3",
    "descend_sewer4",
    "descend_sewer5",
    "dirt1",
    "dirt2",
    "dirt3",
    "dogman",
    "door_metal",
    "door_secret",
    "door_wood",
    "double_shovel",
    "double_shovel_carry",
    "double_shovel_swing",
    "dry_grass",
    "dry_grass_dead",
    "dry_grass_trampled",
    "durian",
    "eel",
    "eggs",
    "electric_eel",
    "enchant_stone",
    "ettin",
    "exit1",
    "explosion_cold",
    "explosion_destroy_floor",
    "explosion_fire",
    "explosion_major",
    "fire",
    "fish",
    "flagon_ale",
    "flameskull",
    "floor1",
    "floor_ice1",
    "floor_lava1",
    "floor10",
    "floor11",
    "floor2",
    "floor3",
    "floor4",
    "floor5",
    "floor6",
    "floor7",
    "floor8",
    "floor9",
    "floor_green_blood1",
    "floor_green_blood2",
    "floor_green_blood3",
    "floor_green_blood4",
    "floor_green_blood5",
    "floor_green_blood6",
    "floor_green_blood7",
    "floor_green_blood8",
    "floor_red_blood1",
    "floor_red_blood2",
    "floor_red_blood3",
    "floor_red_blood4",
    "floor_red_blood5",
    "floor_red_blood6",
    "floor_red_blood7",
    "floor_red_blood8",
    "foliage",
    "foliage_large",
    "foliage_sickly",
    "foliage_sickly_large",
    "four_leaf_clover",
    "frog",
    "gargoyle_baby",
    "gargoyle_moving",
    "gargoyle_podium",
    "gargoyle_static",
    "gauntlets_lion",
    "gauntlets_lion_carry",
    "gauntlets_shoving",
    "gauntlets_shoving_carry",
    "gauntlets_war",
    "gauntlets_war_carry",
    "gem_amber",
    "gem_amethyst",
    "gem_aventurine",
    "gem_diamond",
    "gem_emerald",
    "gem_ruby",
    "gem_sapphire",
    "gem_topaz",
    "gherkin",
    "ghost",
    "ghost_explosion",
    "ghost_minion",
    "ghost_mob",
    "ginger",
    "gloat",
    "gnome_all",
    "gnome_dwarf",
    "gnome_knight",
    "gnome_rock",
    "gnome_thief",
    "goat_battle",
    "goat_demon",
    "gold1",
    "gold2",
    "gold3",
    "gold4",
    "gold5",
    "gold6",
    "goldfish",
    "golem_cement",
    "golem_flesh",
    "greenpepper",
    "green_splatter",
    "honey",
    "horseshoe",
    "hotsauce",
    "iceman",
    "key",
    "key_crystal",
    "key_golden",
    "key_pair",
    "key_penta",
    "kraken",
    "kraken_tentacle",
    "laser_energy",
    "lava",
    "lava_ant",
    "leech_giant",
    "lemonpie",
    "magical_effect",
    "mantisman",
    "map_beast",
    "map_treasure",
    "meatfairy",
    "medal_of_valor",
    "melon1",
    "melon2",
    "mimic_awake",
    "mimic_sleeping",
    "mob_explosion",
    "molekin",
    "moresquito",
    "msg",
    "mummy",
    "mummy_necro",
    "mummy_pack",
    "narhornet",
    "ogre",
    "onion",
    "orange_slices",
    "peach",
    "pickled_eggs",
    "pickledeyes",
    "pike",
    "pike_carry",
    "pike_swing",
    "pillar",
    "pineapple",
    "piranha",
    "piranha_giant",
    "piranha_giant_pack",
    "piranha_pack",
    "player1",
    "player2",
    "portable_hole",
    "portal",
    "potato",
    "potion_effect",
    "potion_health",
    "potion_invisibility",
    "pottedmeat",
    "pretzel",
    "projectile_acid",
    "projectile_dart",
    "projectile_dart_metal",
    "projectile_dart_poison",
    "projectile_rock",
    "projectile_web",
    "pyrolizard",
    "rat_giant",
    "rat_large",
    "reaper",
    "redpepper",
    "red_splatter",
    "ring_is_immune_to_cold",
    "ring_is_immune_to_cold_carry",
    "ring_is_immune_to_fire",
    "ring_is_immune_to_fire_carry",
    "ring_is_immune_to_negation",
    "ring_is_immune_to_negation_carry",
    "ring_is_immune_to_poison",
    "ring_is_immune_to_poison_carry",
    "ring_shield",
    "ring_shield_carry",
    "ripple_large1",
    "ripple_large2",
    "ripple_small1",
    "ripple_small2",
    "roastchicken",
    "rock",
    "rock1",
    "rock_ice1",
    "rock_lava1",
    "rock2",
    "salami",
    "salmon",
    "sardines",
    "scorpion",
    "scorpion_colossal",
    "scorpion_death",
    "scythe",
    "scythe_carry",
    "scythe_swing",
    "sentry_orb_energy",
    "sentry_orb_fire",
    "sewer_wall",
    "sheep",
    "shield_eagle",
    "shield_eagle_carry",
    "shield_obsidian",
    "shield_obsidian_carry",
    "shield_tower",
    "shield_tower2",
    "shield_tower2_carry",
    "shield_tower_carry",
    "shield_wooden",
    "shield_wooden_carry",
    "shield_woodon",
    "shield_woodon_carry",
    "shovel",
    "shovel_carry",
    "shovel_swing",
    "sirloin",
    "skeleton",
    "skel_fire",
    "skel_giant",
    "skel_minion",
    "skel_minion_fire",
    "skel_minion_wander",
    "skel_mob",
    "skill_artful_dodging1",
    "skill_artful_dodging2",
    "skill_artful_dodging3",
    "skill_artful_dodging4",
    "skill_artful_dodging5",
    "skill_devoted_thrust1",
    "skill_devoted_thrust2",
    "skill_devoted_thrust3",
    "skill_devoted_thrust4",
    "skill_devoted_thrust5",
    "skill_devoted_thrust_effect",
    "skill_gold_to_health1",
    "skill_gold_to_health2",
    "skill_gold_to_health3",
    "skill_gold_to_health4",
    "skill_gold_to_health5",
    "skill_gold_to_health_effect",
    "skill_secondary_attack1",
    "skill_secondary_attack2",
    "skill_secondary_attack3",
    "skill_secondary_attack4",
    "skill_secondary_attack5",
    "skill_secondary_attack_effect",
    "skill_stone",
    "slime_baby",
    "slime_parent",
    "small_fire",
    "smoke",
    "snake_asp",
    "snake_dreadfire",
    "snake_viper",
    "somekindofmeat",
    "spider_brown",
    "spider_flux",
    "spider_giant",
    "spider_onyx_widow",
    "spider_para",
    "spiderweb",
    "staff_cold",
    "staff_cold_carry",
    "staff_cold_projectile",
    "staff_descent",
    "staff_descent_carry",
    "staff_descent_laser",
    "staff_descent_radial",
    "staff_energy",
    "staff_energy_carry",
    "staff_fire",
    "staff_fire_carry",
    "staff_fire_projectile",
    "staff_lightning",
    "staff_lightning_carry",
    "staff_lightning_laser",
    "staff_lightning_laser_fork",
    "staff_negation",
    "staff_negation_carry",
    "staff_negation_laser",
    "staff_negation_radial",
    "steak",
    "steam",
    "strawberry",
    "sushi1",
    "sushi2",
    "sword",
    "sword_carry",
    "sword_draining",
    "sword_draining_carry",
    "sword_draining_swing",
    "sword_plutonium",
    "sword_plutonium_carry",
    "sword_plutonium_swing",
    "sword_rusty",
    "sword_rusty_carry",
    "sword_rusty_swing",
    "sword_swing",
    "sword_wood",
    "sword_wood_carry",
    "sword_wood_swing",
    "teleport_in",
    "teleport_out",
    "teletoad",
    "tentacleye",
    "the_grid",
    "thunderstone",
    "tomato",
    "torch",
    "trap_monster",
    "trap_pressure_plate_gas",
    "troll_fire",
    "troll_stone",
    "turnip",
    "vampire_rose",
    "vampire_rose_stem1",
    "vampire_rose_stem2",
    "very_broadsword",
    "very_broadsword_carry",
    "very_broadsword_swing",
    "wall_dungeon.1",
    "wall_dungeon.10",
    "wall_dungeon.11",
    "wall_dungeon.12",
    "wall_dungeon.2",
    "wall_dungeon.3",
    "wall_dungeon.4",
    "wall_dungeon.5",
    "wall_dungeon.6",
    "wall_dungeon.7",
    "wall_dungeon.8",
    "wall_dungeon.9",
    "wall_floor1",
    "water",
    "waterlemon",
    "webball",
    "wet_grass1",
    "wet_grass2",
    "wet_grass3",
    "wet_grass4",
    "wet_grass5",
    "wet_grass6",
    "wet_grass_trampled1",
    "wet_grass_trampled2",
    "wet_grass_trampled3",
    "wet_grass_trampled4",
    "wet_grass_trampled5",
    "wet_grass_trampled6",
    "wine",
    "wooden_cross",
    "wooden_cross_carry",
    "yeti",
    "zoblin",
    "zorb_all",
    "zorb_captain",
    "zorb_eldster",
    "zorb_necro",
    "zorb_pack",
    "zorb_pirate",
    "zorb_priest",
    "zorb_single",
    "zorb_soldier",
    "zorb_wizard",
};

static std::map< std::string, int > tp_preferred_id;

//
// Assign template IDs
//
void tp_get_id(const std::string &tp_name, int *id_out)
{
  static const std::vector< std::string > tp_arr(tps);

  static int  id;
  static bool init;

  //
  // Assign static IDs
  //
  if (! init) {
    init = true;
    for (auto t : tp_arr) {
      tp_preferred_id[ t ] = id++;
    }
  }

  //
  // Previously known
  //
  if (tp_preferred_id.find(tp_name) == tp_preferred_id.end()) {
    tp_preferred_id[ tp_name ] = *id_out = ++id;
    CON("*** Thing template not found %s. Please edit thing_template_ids.cpp and add it. ***", tp_name.c_str());
    return;
  }

  *id_out = tp_preferred_id[ tp_name ];
}
