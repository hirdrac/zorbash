//
// Copyright Neil McGill, goblinhack@gmail.com
//

#pragma once
#ifndef _MY_PY_TP_HPP_
#define _MY_PY_TP_HPP_
#include <Python.h>

PyObject *if_matches_(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *if_matches_then_dead_(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *place_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *spawn_at_if_possible(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *spawn_at_my_position(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *spawn_at(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *spawn_set_fire_to_things_around_me(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *spawn_things_around_me(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *spawn_gas_poison_around_thing(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *spawn_next_to_or_on_monst_(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *spawn_next_to_(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *spawn_owned_thing_at_my_position(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *spawn_radius_range_(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *spawn_using_items_radius_range_(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *tp_load_(PyObject *obj, PyObject *args, PyObject *keywds);
PyObject *tp_update_(PyObject *obj, PyObject *args, PyObject *keywds);

#define TP_SET_PROTO(__field__) PyObject *__field__(PyObject *obj, PyObject *args, PyObject *keywds);

#define MY_ADD_PYTHON_TP_FUNCTION(__field__)                                                                         \
  {                                                                                                                  \
#__field__, (PyCFunction) __field__, METH_VARARGS | METH_KEYWORDS, "set a " #__field__ " in a thing template"    \
  }

/*
 * The cast of the function is necessary since PyCFunction values
 * only take two PyObject *parameters, and some take three.
 */
#define MY_ADD_PYTHON_FUNCTION(__func__)                                                                             \
  {                                                                                                                  \
#__func__, (PyCFunction) __func__, METH_VARARGS | METH_KEYWORDS, #__func__                                       \
  }
#define MY_ADD_WRAPPED_PYTHON_FUNCTION(__func__)                                                                     \
  {                                                                                                                  \
#__func__, (PyCFunction) __func__##_, METH_VARARGS | METH_KEYWORDS, #__func__                                    \
  }

// begin sort marker1 {
TP_SET_PROTO(aggression_pct)
TP_SET_PROTO(ai_detect_secret_doors)
TP_SET_PROTO(ai_resent_count)
TP_SET_PROTO(ai_wanderer)
TP_SET_PROTO(appearing_chance_d1000)
TP_SET_PROTO(attack_eater)
TP_SET_PROTO(attack_engulf_chance_d1000)
TP_SET_PROTO(attack_humanoid)
TP_SET_PROTO(attack_living)
TP_SET_PROTO(attack_meat)
TP_SET_PROTO(attack_no_msg)
TP_SET_PROTO(attacks_per_round)
TP_SET_PROTO(attack_undead)
TP_SET_PROTO(bl1_tile)
TP_SET_PROTO(bl2_tile)
TP_SET_PROTO(blast_min_radius)
TP_SET_PROTO(blit_bot_off)
TP_SET_PROTO(blit_left_off)
TP_SET_PROTO(blit_right_off)
TP_SET_PROTO(blit_top_off)
TP_SET_PROTO(bot1_tile)
TP_SET_PROTO(bot2_tile)
TP_SET_PROTO(bot3_tile)
TP_SET_PROTO(br1_tile)
TP_SET_PROTO(br2_tile)
TP_SET_PROTO(capacity_height)
TP_SET_PROTO(capacity_width)
TP_SET_PROTO(charge_count)
TP_SET_PROTO(collateral_dmg_pct)
TP_SET_PROTO(collision_check)
TP_SET_PROTO(collision_hit_180)
TP_SET_PROTO(collision_hit_360)
TP_SET_PROTO(collision_hit_adj)
TP_SET_PROTO(collision_hit_priority)
TP_SET_PROTO(collision_hit_two_tiles_ahead)
TP_SET_PROTO(consume_per_bite_amount)
TP_SET_PROTO(crit_chance_d10000)
TP_SET_PROTO(damaged_chance_d10000)
TP_SET_PROTO(distance_avoid)
TP_SET_PROTO(distance_leader_max)
TP_SET_PROTO(distance_minion_vision_shared)
TP_SET_PROTO(distance_mob_max)
TP_SET_PROTO(distance_recruitment_max)
TP_SET_PROTO(distance_throw)
TP_SET_PROTO(distance_vision)
TP_SET_PROTO(dmg_acid_chance_d1000)
TP_SET_PROTO(dmg_acid_dice)
TP_SET_PROTO(dmg_bite_chance_d1000)
TP_SET_PROTO(dmg_bite_dice)
TP_SET_PROTO(dmg_claw_chance_d1000)
TP_SET_PROTO(dmg_claw_dice)
TP_SET_PROTO(dmg_cold_chance_d1000)
TP_SET_PROTO(dmg_cold_dice)
TP_SET_PROTO(dmg_crush_chance_d1000)
TP_SET_PROTO(dmg_crush_dice)
TP_SET_PROTO(dmg_digest_chance_d1000)
TP_SET_PROTO(dmg_digest_dice)
TP_SET_PROTO(dmg_draining_chance_d1000)
TP_SET_PROTO(dmg_draining_dice)
TP_SET_PROTO(dmg_drown_chance_d1000)
TP_SET_PROTO(dmg_drown_dice)
TP_SET_PROTO(dmg_energy_chance_d1000)
TP_SET_PROTO(dmg_energy_dice)
TP_SET_PROTO(dmg_fire_chance_d1000)
TP_SET_PROTO(dmg_fire_dice)
TP_SET_PROTO(dmg_heat_chance_d1000)
TP_SET_PROTO(dmg_heat_dice)
TP_SET_PROTO(dmg_lightning_chance_d1000)
TP_SET_PROTO(dmg_lightning_dice)
TP_SET_PROTO(dmg_melee_chance_d1000)
TP_SET_PROTO(dmg_melee_dice)
TP_SET_PROTO(dmg_missile_chance_d1000)
TP_SET_PROTO(dmg_missile_dice)
TP_SET_PROTO(dmg_nat_att_chance_d1000)
TP_SET_PROTO(dmg_nat_att_dice)
TP_SET_PROTO(dmg_nat_att_type)
TP_SET_PROTO(dmg_necrosis_chance_d1000)
TP_SET_PROTO(dmg_necrosis_dice)
TP_SET_PROTO(dmg_negation_chance_d1000)
TP_SET_PROTO(dmg_negation_dice)
TP_SET_PROTO(dmg_poison_chance_d1000)
TP_SET_PROTO(dmg_poison_dice)
TP_SET_PROTO(dmg_received_doubled_from_acid)
TP_SET_PROTO(dmg_received_doubled_from_cold)
TP_SET_PROTO(dmg_received_doubled_from_fire)
TP_SET_PROTO(dmg_received_doubled_from_necrosis)
TP_SET_PROTO(dmg_received_doubled_from_poison)
TP_SET_PROTO(dmg_received_doubled_from_water)
TP_SET_PROTO(dmg_water_chance_d1000)
TP_SET_PROTO(dmg_water_dice)
TP_SET_PROTO(effect_radius)
TP_SET_PROTO(enchant_max)
TP_SET_PROTO(environ_avoids_acid)
TP_SET_PROTO(environ_avoids_cold)
TP_SET_PROTO(environ_avoids_fire)
TP_SET_PROTO(environ_avoids_necrosis)
TP_SET_PROTO(environ_avoids_poison)
TP_SET_PROTO(environ_avoids_water)
TP_SET_PROTO(equip_carry_anim)
TP_SET_PROTO(gfx_anim_use)
TP_SET_PROTO(gfx_ascii_animated)
TP_SET_PROTO(gfx_ascii_bg_color_spread_alpha)
TP_SET_PROTO(gfx_ascii_bg_color_spread_blue)
TP_SET_PROTO(gfx_ascii_bg_color_spread_green)
TP_SET_PROTO(gfx_ascii_bg_color_spread_hue)
TP_SET_PROTO(gfx_ascii_bg_color_spread_red)
TP_SET_PROTO(gfx_ascii_color_bg_unchanged_by_lights)
TP_SET_PROTO(gfx_ascii_color_fg_unchanged_by_lights)
TP_SET_PROTO(gfx_ascii_color_is_animated)
TP_SET_PROTO(gfx_ascii_fade_with_dist)
TP_SET_PROTO(gfx_ascii_fg_color_spread_alpha)
TP_SET_PROTO(gfx_ascii_fg_color_spread_blue)
TP_SET_PROTO(gfx_ascii_fg_color_spread_green)
TP_SET_PROTO(gfx_ascii_fg_color_spread_hue)
TP_SET_PROTO(gfx_ascii_fg_color_spread_red)
TP_SET_PROTO(gfx_ascii_shown)
TP_SET_PROTO(gfx_ascii_shown_as_gray_in_shadow)
TP_SET_PROTO(gfx_ascii_shown_in_bg)
TP_SET_PROTO(gfx_glows)
TP_SET_PROTO(gfx_on_fire_anim)
TP_SET_PROTO(gfx_pixelart_animated)
TP_SET_PROTO(gfx_pixelart_animated_can_hflip)
TP_SET_PROTO(gfx_pixelart_animated_can_vflip)
TP_SET_PROTO(gfx_pixelart_animated_no_dir)
TP_SET_PROTO(gfx_pixelart_anim_synced_with_owner)
TP_SET_PROTO(gfx_pixelart_attack_anim)
TP_SET_PROTO(gfx_pixelart_bounce_always)
TP_SET_PROTO(gfx_pixelart_bounce_on_move)
TP_SET_PROTO(gfx_pixelart_equip_carry_anim)
TP_SET_PROTO(gfx_pixelart_flickers)
TP_SET_PROTO(gfx_pixelart_health_bar_autohide)
TP_SET_PROTO(gfx_pixelart_health_bar_only_when_awake)
TP_SET_PROTO(gfx_pixelart_health_bar_shown)
TP_SET_PROTO(gfx_pixelart_oversized_and_centered)
TP_SET_PROTO(gfx_pixelart_oversized_and_on_floor)
TP_SET_PROTO(gfx_pixelart_reflection)
TP_SET_PROTO(gfx_pixelart_shadow)
TP_SET_PROTO(gfx_pixelart_shadow_long)
TP_SET_PROTO(gfx_pixelart_shadow_short)
TP_SET_PROTO(gfx_pixelart_shadow_solid)
TP_SET_PROTO(gfx_pixelart_shadow_very_short)
TP_SET_PROTO(gfx_pixelart_show_asleep_anim)
TP_SET_PROTO(gfx_pixelart_show_highlighted)
TP_SET_PROTO(gfx_pixelart_shown_in_bg)
TP_SET_PROTO(gfx_pixelart_show_outlined)
TP_SET_PROTO(gfx_pixelart_show_square_outlined)
TP_SET_PROTO(gfx_pixelart_submergable)
TP_SET_PROTO(gfx_pixelart_wobbles_when_hit)
TP_SET_PROTO(gfx_targetted_laser)
TP_SET_PROTO(gfx_targetted_radial)
TP_SET_PROTO(gfx_water)
TP_SET_PROTO(gold_value_dice)
TP_SET_PROTO(health_initial_dice)
TP_SET_PROTO(hunger_clock_tick_freq)
TP_SET_PROTO(hunger_is_hunger_level_hungry_at_pct)
TP_SET_PROTO(hunger_is_hunger_level_starving_at_pct)
TP_SET_PROTO(hunger_is_insatiable)
TP_SET_PROTO(is_able_to_attack_mobs)
TP_SET_PROTO(is_able_to_attack_owner)
TP_SET_PROTO(is_able_to_be_surprised)
TP_SET_PROTO(is_able_to_break_down_doors)
TP_SET_PROTO(is_able_to_break_out_of_ice)
TP_SET_PROTO(is_able_to_break_out_of_webs)
TP_SET_PROTO(is_able_to_burn)
TP_SET_PROTO(is_able_to_change_levels)
TP_SET_PROTO(is_able_to_collect_keys)
TP_SET_PROTO(is_able_to_enchant_items)
TP_SET_PROTO(is_able_to_fall)
TP_SET_PROTO(is_able_to_follow)
TP_SET_PROTO(is_able_to_freeze)
TP_SET_PROTO(is_able_to_grapple)
TP_SET_PROTO(is_able_to_grapple_chance_d1000)
TP_SET_PROTO(is_able_to_jump)
TP_SET_PROTO(is_able_to_jump_attack)
TP_SET_PROTO(is_able_to_jump_attack_chance_d1000)
TP_SET_PROTO(is_able_to_jump_escape)
TP_SET_PROTO(is_able_to_jump_on_low_hp_chance_d1000)
TP_SET_PROTO(is_able_to_jump_onto)
TP_SET_PROTO(is_able_to_jump_onto_chance_d1000)
TP_SET_PROTO(is_able_to_jump_randomly_chance_d1000)
TP_SET_PROTO(is_able_to_jump_without_tiring)
TP_SET_PROTO(is_able_to_learn_skills)
TP_SET_PROTO(is_able_to_live_out_of_water)
TP_SET_PROTO(is_able_to_lunge)
TP_SET_PROTO(is_able_to_melt)
TP_SET_PROTO(is_able_to_move_diagonally)
TP_SET_PROTO(is_able_to_open_doors)
TP_SET_PROTO(is_able_to_rest)
TP_SET_PROTO(is_able_to_see_in_the_dark)
TP_SET_PROTO(is_able_to_see_invisible)
TP_SET_PROTO(is_able_to_see_through_doors)
TP_SET_PROTO(is_able_to_shove)
TP_SET_PROTO(is_able_to_shove_chance_d1000)
TP_SET_PROTO(is_able_to_sleep)
TP_SET_PROTO(is_able_to_spawn_things)
TP_SET_PROTO(is_able_to_swim)
TP_SET_PROTO(is_able_to_teleport_attack)
TP_SET_PROTO(is_able_to_teleport_attack_chance_d1000)
TP_SET_PROTO(is_able_to_teleport_escape)
TP_SET_PROTO(is_able_to_teleport_without_tiring)
TP_SET_PROTO(is_able_to_tire)
TP_SET_PROTO(is_able_to_use_amulet)
TP_SET_PROTO(is_able_to_use_armor)
TP_SET_PROTO(is_able_to_use_boots)
TP_SET_PROTO(is_able_to_use_cloak)
TP_SET_PROTO(is_able_to_use_gauntlet)
TP_SET_PROTO(is_able_to_use_helmet)
TP_SET_PROTO(is_able_to_use_rings)
TP_SET_PROTO(is_able_to_use_shield)
TP_SET_PROTO(is_able_to_use_staffs)
TP_SET_PROTO(is_able_to_use_weapons)
TP_SET_PROTO(is_able_to_walk_through_walls)
TP_SET_PROTO(is_acid)
TP_SET_PROTO(is_air_breather)
TP_SET_PROTO(is_albe_to_shoot_at)
TP_SET_PROTO(is_albe_to_shoot_at_close_range)
TP_SET_PROTO(is_alive_on_end_of_anim)
TP_SET_PROTO(is_allied_with)
TP_SET_PROTO(is_always_hit)
TP_SET_PROTO(is_always_submerged)
TP_SET_PROTO(is_amulet)
TP_SET_PROTO(is_aquatic)
TP_SET_PROTO(is_armor)
TP_SET_PROTO(is_ascend_dungeon)
TP_SET_PROTO(is_ascend_sewer)
TP_SET_PROTO(is_asleep_initially)
TP_SET_PROTO(is_attackable_by_monst)
TP_SET_PROTO(is_attackable_by_player)
TP_SET_PROTO(is_auto_collect_item)
TP_SET_PROTO(is_auto_equipped)
TP_SET_PROTO(is_auto_throw)
TP_SET_PROTO(is_auto_use)
TP_SET_PROTO(is_bag)
TP_SET_PROTO(is_bag_item)
TP_SET_PROTO(is_bag_item_container)
TP_SET_PROTO(is_bag_item_not_stackable)
TP_SET_PROTO(is_barrel)
TP_SET_PROTO(is_basalt)
TP_SET_PROTO(is_biome_dungeon)
TP_SET_PROTO(is_biome_sewer)
TP_SET_PROTO(is_biome_swamp)
TP_SET_PROTO(is_biome_unused)
TP_SET_PROTO(is_bleeder)
TP_SET_PROTO(is_block_of_ice)
TP_SET_PROTO(is_bones)
TP_SET_PROTO(is_boots)
TP_SET_PROTO(is_brazier)
TP_SET_PROTO(is_bridge)
TP_SET_PROTO(is_brittle)
TP_SET_PROTO(is_buff)
TP_SET_PROTO(is_carnivorous_plant)
TP_SET_PROTO(is_carrier_of_treasure_class_a_d1000)
TP_SET_PROTO(is_carrier_of_treasure_class_b_d1000)
TP_SET_PROTO(is_carrier_of_treasure_class_c_d1000)
TP_SET_PROTO(is_carrier_of_weapon_class_a_d1000)
TP_SET_PROTO(is_carrier_of_weapon_class_b_d1000)
TP_SET_PROTO(is_carrier_of_weapon_class_c_d1000)
TP_SET_PROTO(is_chasm)
TP_SET_PROTO(is_cloak)
TP_SET_PROTO(is_cold)
TP_SET_PROTO(is_collectable)
TP_SET_PROTO(is_collected_as_gold)
TP_SET_PROTO(is_collected_as_keys)
TP_SET_PROTO(is_combustible)
TP_SET_PROTO(is_corpse_on_death)
TP_SET_PROTO(is_corpse_with_bones)
TP_SET_PROTO(is_corridor)
TP_SET_PROTO(is_cowardly)
TP_SET_PROTO(is_critical_to_level)
TP_SET_PROTO(is_crushable)
TP_SET_PROTO(is_crystal)
TP_SET_PROTO(is_cursor)
TP_SET_PROTO(is_cursor_can_hover_over)
TP_SET_PROTO(is_cursor_can_hover_over_x2_click)
TP_SET_PROTO(is_cursor_path)
TP_SET_PROTO(is_cursor_path_blocker)
TP_SET_PROTO(is_cursor_path_hazard)
TP_SET_PROTO(is_dagger)
TP_SET_PROTO(is_dead_on_end_of_anim)
TP_SET_PROTO(is_dead_on_falling)
TP_SET_PROTO(is_dead_on_shove)
TP_SET_PROTO(is_debuff)
TP_SET_PROTO(is_debug_path)
TP_SET_PROTO(is_debug_type)
TP_SET_PROTO(is_deep_water)
TP_SET_PROTO(is_deep_water_swimmer)
TP_SET_PROTO(is_descend_dungeon)
TP_SET_PROTO(is_descend_sewer)
TP_SET_PROTO(is_described_when_hovering_over)
TP_SET_PROTO(is_destroyed_on_hit_or_miss)
TP_SET_PROTO(is_destroyed_on_hitting)
TP_SET_PROTO(is_dirt)
TP_SET_PROTO(is_door)
TP_SET_PROTO(is_droppable)
TP_SET_PROTO(is_dry_grass)
TP_SET_PROTO(is_dry_grass_trampled)
TP_SET_PROTO(is_eater_of_amulets)
TP_SET_PROTO(is_eater_of_armor)
TP_SET_PROTO(is_eater_of_boots)
TP_SET_PROTO(is_eater_of_cloaks)
TP_SET_PROTO(is_eater_of_food)
TP_SET_PROTO(is_eater_of_gauntlets)
TP_SET_PROTO(is_eater_of_green_blood)
TP_SET_PROTO(is_eater_of_helmets)
TP_SET_PROTO(is_eater_of_jelly)
TP_SET_PROTO(is_eater_of_magical_items)
TP_SET_PROTO(is_eater_of_meat)
TP_SET_PROTO(is_eater_of_potions)
TP_SET_PROTO(is_eater_of_red_blood)
TP_SET_PROTO(is_eater_of_rings)
TP_SET_PROTO(is_eater_of_shields)
TP_SET_PROTO(is_eater_of_staffs)
TP_SET_PROTO(is_eater_of_treasure)
TP_SET_PROTO(is_eater_of_weapons)
TP_SET_PROTO(is_enchantable)
TP_SET_PROTO(is_enchantstone)
TP_SET_PROTO(is_engulfer)
TP_SET_PROTO(is_ethereal)
TP_SET_PROTO(is_ethereal_mob)
TP_SET_PROTO(is_exit_finder)
TP_SET_PROTO(is_explorer)
TP_SET_PROTO(is_explosion)
TP_SET_PROTO(is_fearless)
TP_SET_PROTO(is_fire)
TP_SET_PROTO(is_flat)
TP_SET_PROTO(is_floating)
TP_SET_PROTO(is_floor)
TP_SET_PROTO(is_floor_deco)
TP_SET_PROTO(is_flying)
TP_SET_PROTO(is_foliage)
TP_SET_PROTO(is_food)
TP_SET_PROTO(is_gas_blocker)
TP_SET_PROTO(is_gauntlet)
TP_SET_PROTO(is_gelatinous)
TP_SET_PROTO(is_glass)
TP_SET_PROTO(is_gold)
TP_SET_PROTO(is_green_blood)
TP_SET_PROTO(is_green_blooded)
TP_SET_PROTO(is_green_splatter)
TP_SET_PROTO(is_hard)
TP_SET_PROTO(is_hazard)
TP_SET_PROTO(is_healing)
TP_SET_PROTO(is_health_booster)
TP_SET_PROTO(is_heavy)
TP_SET_PROTO(is_helmet)
TP_SET_PROTO(is_hidden)
TP_SET_PROTO(is_hittable)
TP_SET_PROTO(is_humanoid)
TP_SET_PROTO(is_immune_to_acid)
TP_SET_PROTO(is_immune_to_cold)
TP_SET_PROTO(is_immune_to_draining)
TP_SET_PROTO(is_immune_to_electricity)
TP_SET_PROTO(is_immune_to_fire)
TP_SET_PROTO(is_immune_to_necrosis)
TP_SET_PROTO(is_immune_to_negation)
TP_SET_PROTO(is_immune_to_poison)
TP_SET_PROTO(is_immune_to_spiderwebs)
TP_SET_PROTO(is_immune_to_water)
TP_SET_PROTO(is_intelligent)
TP_SET_PROTO(is_interesting)
TP_SET_PROTO(is_internal)
TP_SET_PROTO(is_invisible)
TP_SET_PROTO(is_item)
TP_SET_PROTO(is_item_carrier)
TP_SET_PROTO(is_item_collector)
TP_SET_PROTO(is_item_organic)
TP_SET_PROTO(is_item_targetted)
TP_SET_PROTO(is_jelly)
TP_SET_PROTO(is_key)
TP_SET_PROTO(is_key_special)
TP_SET_PROTO(is_laser)
TP_SET_PROTO(is_lava)
TP_SET_PROTO(is_lifeless)
TP_SET_PROTO(is_light_blocker)
TP_SET_PROTO(is_light_blocker_for_monst)
TP_SET_PROTO(is_lightning)
TP_SET_PROTO(is_limb)
TP_SET_PROTO(is_living)
TP_SET_PROTO(is_loggable)
TP_SET_PROTO(is_magical)
TP_SET_PROTO(is_map_beast)
TP_SET_PROTO(is_map_treasure)
TP_SET_PROTO(is_meat)
TP_SET_PROTO(is_metal)
TP_SET_PROTO(is_minion)
TP_SET_PROTO(is_missile)
TP_SET_PROTO(is_mob)
TP_SET_PROTO(is_mob_challenge_class_a)
TP_SET_PROTO(is_mob_challenge_class_b)
TP_SET_PROTO(is_monst)
TP_SET_PROTO(is_monst_class_a)
TP_SET_PROTO(is_monst_class_b)
TP_SET_PROTO(is_monst_class_c)
TP_SET_PROTO(is_monst_class_d)
TP_SET_PROTO(is_monst_class_e)
TP_SET_PROTO(is_monst_pack)
TP_SET_PROTO(is_moveable)
TP_SET_PROTO(is_msg)
TP_SET_PROTO(is_msg_allowed_hears_something)
TP_SET_PROTO(is_msg_allowed_is_dead)
TP_SET_PROTO(is_msg_allowed_is_seen)
TP_SET_PROTO(is_msg_allowed_is_surprised)
TP_SET_PROTO(is_msg_allowed_is_wounded)
TP_SET_PROTO(is_msg_allowed_senses_danger)
TP_SET_PROTO(is_necrotic_danger_level)
TP_SET_PROTO(is_no_tile)
TP_SET_PROTO(is_obs_destructable)
TP_SET_PROTO(is_obs_for_ai)
TP_SET_PROTO(is_obs_for_jump_landing)
TP_SET_PROTO(is_obs_for_shoving)
TP_SET_PROTO(is_obs_in_the_way_for_firing)
TP_SET_PROTO(is_obs_in_the_way_for_jumping)
TP_SET_PROTO(is_obs_in_the_way_for_throwing)
TP_SET_PROTO(is_obs_wall_or_door)
TP_SET_PROTO(is_obs_when_dead)
TP_SET_PROTO(is_openable)
TP_SET_PROTO(is_organic)
TP_SET_PROTO(is_pillar)
TP_SET_PROTO(is_plant)
TP_SET_PROTO(is_player)
TP_SET_PROTO(is_poisonous_danger_level)
TP_SET_PROTO(is_potion)
TP_SET_PROTO(is_projectile)
TP_SET_PROTO(is_red_blood)
TP_SET_PROTO(is_red_blooded)
TP_SET_PROTO(is_red_splatter)
TP_SET_PROTO(is_removable_if_out_of_slots)
TP_SET_PROTO(is_resurrectable)
TP_SET_PROTO(is_ring)
TP_SET_PROTO(is_ripple)
TP_SET_PROTO(is_rock)
TP_SET_PROTO(is_rusty)
TP_SET_PROTO(is_sand)
TP_SET_PROTO(is_secret_corridor)
TP_SET_PROTO(is_secret_door)
TP_SET_PROTO(is_sewer_wall)
TP_SET_PROTO(is_shallow_water)
TP_SET_PROTO(is_shallow_water_swimmer)
TP_SET_PROTO(is_shield)
TP_SET_PROTO(is_shovable)
TP_SET_PROTO(is_shovable_and_sticky)
TP_SET_PROTO(is_skill)
TP_SET_PROTO(is_skillstone)
TP_SET_PROTO(is_sleeping)
TP_SET_PROTO(is_slippery)
TP_SET_PROTO(is_smoke)
TP_SET_PROTO(is_snake)
TP_SET_PROTO(is_soft)
TP_SET_PROTO(is_spider)
TP_SET_PROTO(is_spiderweb)
TP_SET_PROTO(is_staff)
TP_SET_PROTO(is_steal_item_chance_d1000)
TP_SET_PROTO(is_steam)
TP_SET_PROTO(is_sticky)
TP_SET_PROTO(is_stone)
TP_SET_PROTO(is_swimmer)
TP_SET_PROTO(is_sword)
TP_SET_PROTO(is_target_radial)
TP_SET_PROTO(is_target_select)
TP_SET_PROTO(is_tentacle)
TP_SET_PROTO(is_the_grid)
TP_SET_PROTO(is_thief)
TP_SET_PROTO(is_throwable)
TP_SET_PROTO(is_thrown_as_a_weapon)
TP_SET_PROTO(is_tickable)
TP_SET_PROTO(is_tireless)
TP_SET_PROTO(is_tmp_thing)
TP_SET_PROTO(is_torch)
TP_SET_PROTO(is_treasure)
TP_SET_PROTO(is_treasure_chest)
TP_SET_PROTO(is_treasure_class_a)
TP_SET_PROTO(is_treasure_class_b)
TP_SET_PROTO(is_treasure_class_c)
TP_SET_PROTO(is_treasure_type)
TP_SET_PROTO(is_undead)
TP_SET_PROTO(is_usable)
TP_SET_PROTO(is_used_when_thrown)
TP_SET_PROTO(is_very_combustible)
TP_SET_PROTO(is_very_hard)
TP_SET_PROTO(is_very_heavy)
TP_SET_PROTO(is_wall)
TP_SET_PROTO(is_wall_dungeon)
TP_SET_PROTO(is_weapon)
TP_SET_PROTO(is_weapon_class_a)
TP_SET_PROTO(is_weapon_class_b)
TP_SET_PROTO(is_weapon_class_c)
TP_SET_PROTO(is_wet_grass)
TP_SET_PROTO(is_wooden)
TP_SET_PROTO(item_height)
TP_SET_PROTO(item_width)
TP_SET_PROTO(jump_distance)
TP_SET_PROTO(jump_distance_mod)
TP_SET_PROTO(left1_tile)
TP_SET_PROTO(left2_tile)
TP_SET_PROTO(lifespan_dice)
TP_SET_PROTO(light_color)
TP_SET_PROTO(light_dist)
TP_SET_PROTO(melting_chance_d1000)
TP_SET_PROTO(minion_limit)
TP_SET_PROTO(move_speed)
TP_SET_PROTO(move_speed_mod)
TP_SET_PROTO(name)
TP_SET_PROTO(noise_additional_on_jump_end)
TP_SET_PROTO(noise_additional_on_teleporting)
TP_SET_PROTO(noise_blocker)
TP_SET_PROTO(noise_decibels_hearing)
TP_SET_PROTO(noise_on_born)
TP_SET_PROTO(noise_on_dropping)
TP_SET_PROTO(noise_on_moving)
TP_SET_PROTO(noise_on_open)
TP_SET_PROTO(noise_on_you_are_hit_and_now_dead)
TP_SET_PROTO(noise_on_you_are_hit_but_still_alive)
TP_SET_PROTO(normal_placement_rules)
TP_SET_PROTO(nutrition_dice)
TP_SET_PROTO(on_attacking_dmg_acid_do)
TP_SET_PROTO(on_attacking_dmg_bite_do)
TP_SET_PROTO(on_attacking_dmg_claw_do)
TP_SET_PROTO(on_attacking_dmg_cold_do)
TP_SET_PROTO(on_attacking_dmg_crush_do)
TP_SET_PROTO(on_attacking_dmg_digest_do)
TP_SET_PROTO(on_attacking_dmg_draining_do)
TP_SET_PROTO(on_attacking_dmg_drown_do)
TP_SET_PROTO(on_attacking_dmg_energy_do)
TP_SET_PROTO(on_attacking_dmg_fire_do)
TP_SET_PROTO(on_attacking_dmg_heat_do)
TP_SET_PROTO(on_attacking_dmg_lightning_do)
TP_SET_PROTO(on_attacking_dmg_melee_do)
TP_SET_PROTO(on_attacking_dmg_missile_do)
TP_SET_PROTO(on_attacking_dmg_nat_att_do)
TP_SET_PROTO(on_attacking_dmg_necrosis_do)
TP_SET_PROTO(on_attacking_dmg_negation_do)
TP_SET_PROTO(on_attacking_dmg_poison_do)
TP_SET_PROTO(on_attacking_dmg_stat_att_do)
TP_SET_PROTO(on_attacking_dmg_stat_con_do)
TP_SET_PROTO(on_attacking_dmg_stat_str_do)
TP_SET_PROTO(on_attacking_dmg_water_do)
TP_SET_PROTO(on_awake_do)
TP_SET_PROTO(on_born_do)
TP_SET_PROTO(on_death_do)
TP_SET_PROTO(on_death_drop_all_items)
TP_SET_PROTO(on_death_is_open)
TP_SET_PROTO(on_death_of_a_follower_do)
TP_SET_PROTO(on_death_of_my_leader_do)
TP_SET_PROTO(on_dropped_do)
TP_SET_PROTO(on_enchant_do)
TP_SET_PROTO(on_equip_do)
TP_SET_PROTO(on_fall_begin_do)
TP_SET_PROTO(on_fall_do)
TP_SET_PROTO(on_final_use_do)
TP_SET_PROTO(on_get_text_description_long_do)
TP_SET_PROTO(on_idle_tick_freq_dice)
TP_SET_PROTO(on_jump_do)
TP_SET_PROTO(on_lifespan_tick_do)
TP_SET_PROTO(on_move_do)
TP_SET_PROTO(on_open_do)
TP_SET_PROTO(on_owner_add_do)
TP_SET_PROTO(on_owner_attack_dmg_acid_do)
TP_SET_PROTO(on_owner_attack_dmg_bite_do)
TP_SET_PROTO(on_owner_attack_dmg_claw_do)
TP_SET_PROTO(on_owner_attack_dmg_cold_do)
TP_SET_PROTO(on_owner_attack_dmg_crush_do)
TP_SET_PROTO(on_owner_attack_dmg_digest_do)
TP_SET_PROTO(on_owner_attack_dmg_draining_do)
TP_SET_PROTO(on_owner_attack_dmg_drown_do)
TP_SET_PROTO(on_owner_attack_dmg_energy_do)
TP_SET_PROTO(on_owner_attack_dmg_fire_do)
TP_SET_PROTO(on_owner_attack_dmg_heat_do)
TP_SET_PROTO(on_owner_attack_dmg_lightning_do)
TP_SET_PROTO(on_owner_attack_dmg_melee_do)
TP_SET_PROTO(on_owner_attack_dmg_missile_do)
TP_SET_PROTO(on_owner_attack_dmg_nat_att_do)
TP_SET_PROTO(on_owner_attack_dmg_necrosis_do)
TP_SET_PROTO(on_owner_attack_dmg_negation_do)
TP_SET_PROTO(on_owner_attack_dmg_poison_do)
TP_SET_PROTO(on_owner_attack_dmg_stat_att_do)
TP_SET_PROTO(on_owner_attack_dmg_stat_con_do)
TP_SET_PROTO(on_owner_attack_dmg_stat_str_do)
TP_SET_PROTO(on_owner_attack_dmg_water_do)
TP_SET_PROTO(on_owner_receive_dmg_acid_do)
TP_SET_PROTO(on_owner_receive_dmg_bite_do)
TP_SET_PROTO(on_owner_receive_dmg_claw_do)
TP_SET_PROTO(on_owner_receive_dmg_cold_do)
TP_SET_PROTO(on_owner_receive_dmg_crush_do)
TP_SET_PROTO(on_owner_receive_dmg_digest_do)
TP_SET_PROTO(on_owner_receive_dmg_draining_do)
TP_SET_PROTO(on_owner_receive_dmg_drown_do)
TP_SET_PROTO(on_owner_receive_dmg_energy_do)
TP_SET_PROTO(on_owner_receive_dmg_fire_do)
TP_SET_PROTO(on_owner_receive_dmg_heat_do)
TP_SET_PROTO(on_owner_receive_dmg_lightning_do)
TP_SET_PROTO(on_owner_receive_dmg_melee_do)
TP_SET_PROTO(on_owner_receive_dmg_missile_do)
TP_SET_PROTO(on_owner_receive_dmg_nat_att_do)
TP_SET_PROTO(on_owner_receive_dmg_necrosis_do)
TP_SET_PROTO(on_owner_receive_dmg_negation_do)
TP_SET_PROTO(on_owner_receive_dmg_poison_do)
TP_SET_PROTO(on_owner_receive_dmg_stat_att_do)
TP_SET_PROTO(on_owner_receive_dmg_stat_con_do)
TP_SET_PROTO(on_owner_receive_dmg_stat_str_do)
TP_SET_PROTO(on_owner_receive_dmg_water_do)
TP_SET_PROTO(on_owner_unset_do)
TP_SET_PROTO(on_polymorphed_do)
TP_SET_PROTO(on_receiving_dmg_acid_do)
TP_SET_PROTO(on_receiving_dmg_bite_do)
TP_SET_PROTO(on_receiving_dmg_claw_do)
TP_SET_PROTO(on_receiving_dmg_cold_do)
TP_SET_PROTO(on_receiving_dmg_crush_do)
TP_SET_PROTO(on_receiving_dmg_digest_do)
TP_SET_PROTO(on_receiving_dmg_draining_do)
TP_SET_PROTO(on_receiving_dmg_drown_do)
TP_SET_PROTO(on_receiving_dmg_energy_do)
TP_SET_PROTO(on_receiving_dmg_fire_do)
TP_SET_PROTO(on_receiving_dmg_heat_do)
TP_SET_PROTO(on_receiving_dmg_lightning_do)
TP_SET_PROTO(on_receiving_dmg_melee_do)
TP_SET_PROTO(on_receiving_dmg_missile_do)
TP_SET_PROTO(on_receiving_dmg_nat_att_do)
TP_SET_PROTO(on_receiving_dmg_necrosis_do)
TP_SET_PROTO(on_receiving_dmg_negation_do)
TP_SET_PROTO(on_receiving_dmg_poison_do)
TP_SET_PROTO(on_receiving_dmg_stat_att_do)
TP_SET_PROTO(on_receiving_dmg_stat_con_do)
TP_SET_PROTO(on_receiving_dmg_stat_str_do)
TP_SET_PROTO(on_receiving_dmg_water_do)
TP_SET_PROTO(on_resting_do)
TP_SET_PROTO(on_stuck_do)
TP_SET_PROTO(on_swing_do)
TP_SET_PROTO(on_targetted_do)
TP_SET_PROTO(on_targetted_radially_do)
TP_SET_PROTO(on_teleport_do)
TP_SET_PROTO(on_thrown_do)
TP_SET_PROTO(on_tick_do)
TP_SET_PROTO(on_unequip_do)
TP_SET_PROTO(on_use_do)
TP_SET_PROTO(on_waiting_do)
TP_SET_PROTO(on_want_to_shoot_at_something_do)
TP_SET_PROTO(on_you_are_declared_a_follower_do)
TP_SET_PROTO(on_you_are_declared_leader_do)
TP_SET_PROTO(on_you_are_hit_and_now_dead_do)
TP_SET_PROTO(on_you_are_hit_but_dodge_it_do)
TP_SET_PROTO(on_you_are_hit_but_still_alive_do)
TP_SET_PROTO(on_you_are_on_fire_do)
TP_SET_PROTO(on_you_nat_att_do)
TP_SET_PROTO(range_max)
TP_SET_PROTO(rarity)
TP_SET_PROTO(resurrect_dice)
TP_SET_PROTO(right1_tile)
TP_SET_PROTO(right2_tile)
TP_SET_PROTO(shove_strength)
TP_SET_PROTO(shove_strength_mod)
TP_SET_PROTO(spawn_group_radius)
TP_SET_PROTO(spawn_group_size_dice)
TP_SET_PROTO(spawn_on_shoved)
TP_SET_PROTO(stamina)
TP_SET_PROTO(stamina_drain_on_attacking)
TP_SET_PROTO(stamina_drain_on_using)
TP_SET_PROTO(stat_att)
TP_SET_PROTO(stat_att_mod)
TP_SET_PROTO(stat_att_penalty_when_idle)
TP_SET_PROTO(stat_att_penalty_when_idle_max)
TP_SET_PROTO(stat_att_penalty_when_in_deep_water)
TP_SET_PROTO(stat_att_penalty_when_in_shallow_water)
TP_SET_PROTO(stat_att_penalty_when_stuck)
TP_SET_PROTO(stat_att_penalty_when_stuck_max)
TP_SET_PROTO(stat_con)
TP_SET_PROTO(stat_con_mod)
TP_SET_PROTO(stat_def)
TP_SET_PROTO(stat_def_mod)
TP_SET_PROTO(stat_def_penalty_when_idle)
TP_SET_PROTO(stat_def_penalty_when_idle_max)
TP_SET_PROTO(stat_def_penalty_when_in_deep_water)
TP_SET_PROTO(stat_def_penalty_when_in_shallow_water)
TP_SET_PROTO(stat_def_penalty_when_stuck)
TP_SET_PROTO(stat_def_penalty_when_stuck_max)
TP_SET_PROTO(stat_dex)
TP_SET_PROTO(stat_dex_mod)
TP_SET_PROTO(stat_luck)
TP_SET_PROTO(stat_luck_mod)
TP_SET_PROTO(stats02)
TP_SET_PROTO(stats03)
TP_SET_PROTO(stats04)
TP_SET_PROTO(stats05)
TP_SET_PROTO(stats06)
TP_SET_PROTO(stats07)
TP_SET_PROTO(stats09)
TP_SET_PROTO(stat_str)
TP_SET_PROTO(stat_str_mod)
TP_SET_PROTO(str1)
TP_SET_PROTO(str2)
TP_SET_PROTO(str4)
TP_SET_PROTO(target_name_projectile)
TP_SET_PROTO(teleport_distance)
TP_SET_PROTO(temperature)
TP_SET_PROTO(temperature_max)
TP_SET_PROTO(temperature_min)
TP_SET_PROTO(temperature_sensitive)
TP_SET_PROTO(temperature_sensitive_to_sudden_changes)
TP_SET_PROTO(text_a_or_an)
TP_SET_PROTO(text_debuff)
TP_SET_PROTO(text_description_enchant)
TP_SET_PROTO(text_description_long)
TP_SET_PROTO(text_description_long2)
TP_SET_PROTO(text_description_long3)
TP_SET_PROTO(text_description_short)
TP_SET_PROTO(text_hits)
TP_SET_PROTO(text_long_name)
TP_SET_PROTO(text_skill)
TP_SET_PROTO(text_title)
TP_SET_PROTO(text_unused)
TP_SET_PROTO(text_unused1)
TP_SET_PROTO(text_unused2)
TP_SET_PROTO(text_unused3)
TP_SET_PROTO(thing_size)
TP_SET_PROTO(tick_prio)
TP_SET_PROTO(tile)
TP_SET_PROTO(tl1_tile)
TP_SET_PROTO(tl2_tile)
TP_SET_PROTO(top1_tile)
TP_SET_PROTO(top2_tile)
TP_SET_PROTO(tr1_tile)
TP_SET_PROTO(tr2_tile)
TP_SET_PROTO(unused_chance1_d1000)
TP_SET_PROTO(unused_chance2_d1000)
TP_SET_PROTO(unused_chance3_d1000)
TP_SET_PROTO(unused_chance4_d1000)
TP_SET_PROTO(unused_chance5_d1000)
TP_SET_PROTO(unused_chance6_d1000)
TP_SET_PROTO(unused_flag1)
TP_SET_PROTO(unused_flag10)
TP_SET_PROTO(unused_flag103)
TP_SET_PROTO(unused_flag11)
TP_SET_PROTO(unused_flag12)
TP_SET_PROTO(unused_flag123)
TP_SET_PROTO(unused_flag13)
TP_SET_PROTO(unused_flag14)
TP_SET_PROTO(unused_flag15)
TP_SET_PROTO(unused_flag16)
TP_SET_PROTO(unused_flag17)
TP_SET_PROTO(unused_flag18)
TP_SET_PROTO(unused_flag2)
TP_SET_PROTO(unused_flag27)
TP_SET_PROTO(unused_flag3)
TP_SET_PROTO(unused_flag4)
TP_SET_PROTO(unused_flag40)
TP_SET_PROTO(unused_flag48)
TP_SET_PROTO(unused_flag5)
TP_SET_PROTO(unused_flag6)
TP_SET_PROTO(unused_flag7)
TP_SET_PROTO(unused_flag8)
TP_SET_PROTO(unused_flag9)
TP_SET_PROTO(weapon_dmg)
TP_SET_PROTO(z_depth)
TP_SET_PROTO(z_prio)
// end sort marker1 }

#endif
