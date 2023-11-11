//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_PY_LEVEL_HPP_
#define _MY_PY_LEVEL_HPP_
#include <Python.h>

// begin sort marker1 {
PyObject *chance_d1000_level_is_steal_item_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_add_(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_ai_detect_secret_doors_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_ai_resent_count_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_ai_wanderer_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_attack_no_msg_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_attack_undead_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_dmg_num_of_attacks_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_dmg_rcv_doubled_from_cold_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_flood_fill_gas_get_all_grid_things(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_flood_fill_get_all_grid_things(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_flood_fill_get_all_things(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_get_all(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_hunger_clock_tick_freq_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_hunger_is_insatiable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_amplify_footsteps_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_be_resurrected_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_break_out_of_ice_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_dampen_footsteps_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_freeze_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_melt_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_able_to_spawn_things_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_acid_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_air_breather_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_alive_monst_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_alive_on_end_of_anim_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_always_hit_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_amulet_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_aquatic_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_armor_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_ascend_dungeon_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_ascend_sewer_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_asleep_initially_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_attackable_by_monst_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_attackable_by_player_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_auto_collect_item_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_auto_equipped_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_auto_throw_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_bag_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_bag_item_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_bag_item_container_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_bag_item_not_stackable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_barrel_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_basalt_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_biome_dungeon_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_biome_swamp_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_bleeder_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_block_of_crystal_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_block_of_ice_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_bloodied_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_bones_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_boots_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_brazier_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_bridge_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_brittle_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_buff_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_burnable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_carnivorous_plant_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_carrying_an_item_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_carrying_treasure_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_chasm_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_cloak_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_cold_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_collectable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_collected_as_gold_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_collected_as_keys_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_combustible_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_corpse_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_corpse_on_death_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_corpse_with_bones_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_corridor_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_critical_to_level_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_crushable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_crystalline_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_cursor_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_cursor_can_hover_over_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_cursor_can_hover_over_needs_confirm_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_cursor_path_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_cursor_path_blocker_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_cursor_path_hazard_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dagger_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dead_on_end_of_anim_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dead_on_falling_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dead_on_shove_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_debuff_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_debug_path_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_debug_type_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_deep_water_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_descend_dungeon_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_descend_sewer_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_described_when_hovering_over_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_destroyed_on_hit_or_miss_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_destroyed_on_hitting_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_bl_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_br_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_down_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_left_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_none_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_right_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dirt_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_tl_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_tr_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_dir_up_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_door_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_droppable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_eater_of_food_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_eater_of_green_blood_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_eater_of_magical_items_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_eater_of_meat_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_eater_of_potions_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_eater_of_red_blood_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_eater_of_slime_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_eater_of_treasure_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_enchantable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_enchantstone_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_engulfer_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_ethereal_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_ethereal_mob_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_exit_finder_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_explorer_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_explosion_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_fearless_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_fire_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_flat_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_floating_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_floor_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_floor_deco_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_flying_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_foliage_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_food_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_fungus_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_fungus_edible_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_fungus_healing_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_fungus_poison_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_fungus_withered_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_gas_blocker_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_gas_explosion_blocker_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_gauntlet_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_gelatinous_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_glass_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_gold_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_grass_dry_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_grass_wet_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_green_blood_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_green_blooded_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_green_splatter_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_hard_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_hazard_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_heavy_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_helmet_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_hittable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_humanoid_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_acid_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_cold_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_holy_damage_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_magic_drain_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_necrosis_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_poison_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_shoot_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_spiderwebs_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_stamina_drain_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_immune_to_water_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_intelligent_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_interesting_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_item_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_item_carrier_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_item_collector_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_item_organic_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_item_targeted_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_key_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_key_special_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_lava_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_lifeless_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_light_blocker_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_light_blocker_for_monst_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_light_blocker_for_monst_for_monst_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_living_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_loggable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_magical_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_meat_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_metal_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_minion_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_mob_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_monst_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_monst_class_A_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_monst_class_B_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_monst_class_C_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_monst_class_D_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_monst_class_E_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_moveable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_msg_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_necrotic_danger_level_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_no_tile_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_obs_destructable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_obs_jumping_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_obs_shoving_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_obs_spell_casting_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_obs_throwing_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_obs_wall_or_door_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_obs_when_dead_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_on_want_to_shoot_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_ooze_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_openable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_organic_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_pack_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_pillar_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_plant_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_player_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_poisonous_danger_level_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_portal_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_potion_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_red_blood_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_red_blooded_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_red_splatter_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_removable_if_out_of_slots_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_ring_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_ripple_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_rock_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_rusty_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_secret_door_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_sewer_wall_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_shallow_water_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_shield_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_shovable_and_sticky_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_shovable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_skill_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_skillstone_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_slime_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_slippery_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_smoke_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_snake_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_soft_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_spectral_blade_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_spell_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_spellbook_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_spell_of_holding_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_spell_of_sanctuary_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_spider_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_spiderweb_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_staff_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_steam_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_sticky_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_stone_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_sword_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_target_radial_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_target_select_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_thief_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_throwable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_tickable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_tireless_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_tmp_thing_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_torch_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_trap_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_treasure_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_treasure_chest_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_treasure_type_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_undead_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_usable_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_used_when_thrown_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_very_combustible_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_very_hard_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_very_heavy_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_visible_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_wall_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_wall_dungeon_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_water_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_weapon_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_is_wooden_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_magic_drain_on_using(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_move_speed_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_shove_strength_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *level_teleport_distance_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_all_followers_get(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *thing_all_minions_get(PyObject *obj, PyObject *args, PyObject *keywds);
// end sort marker1 }

#endif
