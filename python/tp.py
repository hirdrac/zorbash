import zx
import random


class Tp:
    """thing template"""

    def __init__(self, name):
        self.name = name

        #
        # Load it into the game engine
        #
        zx.tp_load(self)

    def update(self):
        zx.tp_update(self)

    def set_tile(self, tile=None, **kw):
        zx.tp_set_tile(self, tile, **kw)

    def set_left_tile(self, left_tile=None, **kw):
        zx.tp_set_left_tile(self, left_tile, **kw)

    def set_right_tile(self, right_tile=None, **kw):
        zx.tp_set_right_tile(self, right_tile, **kw)

    def set_bot_tile(self, bot_tile=None, **kw):
        zx.tp_set_bot_tile(self, bot_tile, **kw)

    def set_top_tile(self, top_tile=None, **kw):
        zx.tp_set_top_tile(self, top_tile, **kw)

    def set_tl_tile(self, tl_tile=None, **kw):
        zx.tp_set_tl_tile(self, tl_tile, **kw)

    def set_tr_tile(self, tr_tile=None, **kw):
        zx.tp_set_tr_tile(self, tr_tile, **kw)

    def set_br_tile(self, br_tile=None, **kw):
        zx.tp_set_br_tile(self, br_tile, **kw)

    def set_bl_tile(self, bl_tile=None, **kw):
        zx.tp_set_bl_tile(self, bl_tile, **kw)


    def set_name(self, value):
        zx.tp_set_name(self, value)

    def set_short_name(self, value):
        zx.tp_set_short_name(self, value)

    def set_blit_top_off(self, value):
        zx.tp_set_blit_top_off(self, value)

    def set_blit_bot_off(self, value):
        zx.tp_set_blit_bot_off(self, value)

    def set_blit_left_off(self, value):
        zx.tp_set_blit_left_off(self, value)

    def set_blit_right_off(self, value):
        zx.tp_set_blit_right_off(self, value)

    def set_gfx_animated(self, value):
        zx.tp_set_gfx_animated(self, value)

    def set_gfx_animated_no_dir(self, value):
        zx.tp_set_gfx_animated_no_dir(self, value)

    def set_gfx_is_an_animation_only(self, value):
        zx.tp_set_gfx_is_an_animation_only(self, value)

    def set_is_monst(self, value):
        zx.tp_set_is_monst(self, value)

    def set_is_key(self, value):
        zx.tp_set_is_key(self, value)

    def set_gfx_is_floor_deco(self, value):
        zx.tp_set_gfx_is_floor_deco(self, value)

    def set_gfx_is_wall_deco(self, value):
        zx.tp_set_gfx_is_wall_deco(self, value)

    def set_is_player(self, value):
        zx.tp_set_is_player(self, value)

    def set_str_zzz1(self, value):
        zx.tp_set_str_zzz1(self, value)

    def set_str_zzz2(self, value):
        zx.tp_set_str_zzz2(self, value)

    def set_str_zzz3(self, value):
        zx.tp_set_str_zzz3(self, value)

    def set_str_zzz4(self, value):
        zx.tp_set_str_zzz4(self, value)

    def set_str_zzz5(self, value):
        zx.tp_set_str_zzz5(self, value)

    def set_str_zzz6(self, value):
        zx.tp_set_str_zzz6(self, value)

    def set_str_zzz7(self, value):
        zx.tp_set_str_zzz7(self, value)

    def set_str_zzz8(self, value):
        zx.tp_set_str_zzz8(self, value)

    def set_str_zzz9(self, value):
        zx.tp_set_str_zzz9(self, value)

    def set_str_zzz10(self, value):
        zx.tp_set_str_zzz10(self, value)

    def set_str_zzz11(self, value):
        zx.tp_set_str_zzz11(self, value)

    def set_str_zzz12(self, value):
        zx.tp_set_str_zzz12(self, value)

    def set_str_zzz13(self, value):
        zx.tp_set_str_zzz13(self, value)

    def set_str_zzz14(self, value):
        zx.tp_set_str_zzz14(self, value)

    def set_str_zzz15(self, value):
        zx.tp_set_str_zzz15(self, value)

    def set_str_zzz16(self, value):
        zx.tp_set_str_zzz16(self, value)

    def set_str_zzz17(self, value):
        zx.tp_set_str_zzz17(self, value)

    def set_str_light_color(self, value):
        zx.tp_set_str_light_color(self, value)

    def set_weapon_carry_anim(self, value):
        zx.tp_set_weapon_carry_anim(self, value)

    def set_weapon_use_anim(self, value):
        zx.tp_set_weapon_use_anim(self, value)

    def set_is_rrr1(self, value):
        zx.tp_set_is_rrr1(self, value)

    def set_is_rrr2(self, value):
        zx.tp_set_is_rrr2(self, value)

    def set_is_rrr3(self, value):
        zx.tp_set_is_rrr3(self, value)

    def set_is_rrr4(self, value):
        zx.tp_set_is_rrr4(self, value)

    def set_is_rrr5(self, value):
        zx.tp_set_is_rrr5(self, value)

    def set_is_rrr6(self, value):
        zx.tp_set_is_rrr6(self, value)

    def set_is_rrr7(self, value):
        zx.tp_set_is_rrr7(self, value)

    def set_is_rrr8(self, value):
        zx.tp_set_is_rrr8(self, value)

    def set_is_rrr9(self, value):
        zx.tp_set_is_rrr9(self, value)

    def set_is_rrr10(self, value):
        zx.tp_set_is_rrr10(self, value)

    def set_is_rrr11(self, value):
        zx.tp_set_is_rrr11(self, value)

    def set_is_rrr12(self, value):
        zx.tp_set_is_rrr12(self, value)

    def set_is_rrr13(self, value):
        zx.tp_set_is_rrr13(self, value)

    def set_is_rrr14(self, value):
        zx.tp_set_is_rrr14(self, value)

    def set_is_rrr15(self, value):
        zx.tp_set_is_rrr15(self, value)

    def set_is_rrr16(self, value):
        zx.tp_set_is_rrr16(self, value)

    def set_is_wall_clinger(self, value):
        zx.tp_set_is_wall_clinger(self, value)

    def set_nutrition_hd(self, value):
        zx.tp_set_nutrition_hd(self, value)

    def set_bite_damage_hd(self, value):
        zx.tp_set_bite_damage_hd(self, value)

    def set_collision_check(self, value):
        zx.tp_set_collision_check(self, value)

    def set_attack_on_collision(self, value):
        zx.tp_set_attack_on_collision(self, value)

    def set_is_water_dweller(self, value):
        zx.tp_set_is_water_dweller(self, value)

    def set_collision_hit_priority(self, value):
        zx.tp_set_collision_hit_priority(self, value)

    def set_collision_radius(self, value):
        zx.tp_set_collision_radius(self, value)

    def set_ai_delay_after_moving_ms(self, value):
        zx.tp_set_ai_delay_after_moving_ms(self, value)

    def set_gfx_bounce_on_move(self, value):
        zx.tp_set_gfx_bounce_on_move(self, value)

    def set_is_rrr27(self, value):
        zx.tp_set_is_rrr27(self, value)

    def set_is_bleeder(self, value):
        zx.tp_set_is_bleeder(self, value)

    def set_is_corpse_on_death(self, value):
        zx.tp_set_is_corpse_on_death(self, value)

    def set_is_meat_eater(self, value):
        zx.tp_set_is_meat_eater(self, value)

    def set_is_made_of_meat(self, value):
        zx.tp_set_is_made_of_meat(self, value)

    def set_is_active(self, value):
        zx.tp_set_is_active(self, value)

    def set_hunger_starving_at_health_pct(self, value):
        zx.tp_set_hunger_starving_at_health_pct(self, value)

    def set_hunger_initial_health_at(self, value):
        zx.tp_set_hunger_initial_health_at(self, value)

    def set_hunger_at_health_pct(self, value):
        zx.tp_set_hunger_at_health_pct(self, value)

    def set_hunger_clock_freq_ms(self, value):
        zx.tp_set_hunger_clock_freq_ms(self, value)

    def set_ai_scent_distance(self, value):
        zx.tp_set_ai_scent_distance(self, value)

    def set_is_ripple(self, value):
        zx.tp_set_is_ripple(self, value)

    def set_is_light_strength(self, value):
        zx.tp_set_is_light_strength(self, value)

    def set_is_blood(self, value):
        zx.tp_set_is_blood(self, value)

    def set_gfx_animated_can_vflip(self, value):
        zx.tp_set_gfx_animated_can_vflip(self, value)

    def set_is_corridor(self, value):
        zx.tp_set_is_corridor(self, value)

    def set_gfx_oversized_but_sitting_on_the_ground(self, value):
        zx.tp_set_gfx_oversized_but_sitting_on_the_ground(self, value)

    def set_is_boring(self, value):
        zx.tp_set_is_boring(self, value)

    def set_is_exit(self, value):
        zx.tp_set_is_exit(self, value)

    def set_is_door(self, value):
        zx.tp_set_is_door(self, value)

    def set_is_entrance(self, value):
        zx.tp_set_is_entrance(self, value)

    def set_move_speed_ms(self, value):
        zx.tp_set_move_speed_ms(self, value)

    def set_weapon_use_delay_hundredths(self, value):
        zx.tp_set_weapon_use_delay_hundredths(self, value)

    def set_collision_box(self, value):
        zx.tp_set_collision_box(self, value)

    def set_collision_circle(self, value):
        zx.tp_set_collision_circle(self, value)

    def set_weapon_damage(self, value):
        zx.tp_set_weapon_damage(self, value)

    def set_is_projectile(self, value):
        zx.tp_set_is_projectile(self, value)

    def set_is_explosion(self, value):
        zx.tp_set_is_explosion(self, value)

    def set_is_combustable(self, value):
        zx.tp_set_is_combustable(self, value)

    def set_weapon_use_distance(self, value):
        zx.tp_set_weapon_use_distance(self, value)

    def set_gfx_is_weapon_carry_anim_only(self, value):
        zx.tp_set_gfx_is_weapon_carry_anim_only(self, value)

    def set_gfx_is_weapon_use_anim(self, value):
        zx.tp_set_gfx_is_weapon_use_anim(self, value)

    def set_is_weapon(self, value):
        zx.tp_set_is_weapon(self, value)

    def set_gfx_outlined(self, value):
        zx.tp_set_gfx_outlined(self, value)

    def set_gfx_large_shadow_caster(self, value):
        zx.tp_set_gfx_large_shadow_caster(self, value)

    def set_z_depth(self, value):
        zx.tp_set_z_depth(self, value)

    def set_is_movable(self, value):
        zx.tp_set_is_movable(self, value)

    def set_gfx_can_hflip(self, value):
        zx.tp_set_gfx_can_hflip(self, value)

    def set_gfx_animated_can_vflip(self, value):
        zx.tp_set_gfx_animated_can_vflip(self, value)

    def set_is_movement_blocking(self, value):
        zx.tp_set_is_movement_blocking(self, value)

    def set_is_treasure(self, value):
        zx.tp_set_is_treasure(self, value)

    def set_is_wall(self, value):
        zx.tp_set_is_wall(self, value)

    def set_is_rock(self, value):
        zx.tp_set_is_rock(self, value)

    def set_is_floor(self, value):
        zx.tp_set_is_floor(self, value)

    def set_is_dirt(self, value):
        zx.tp_set_is_dirt(self, value)

    def set_is_lava(self, value):
        zx.tp_set_is_lava(self, value)

    def set_is_water(self, value):
        zx.tp_set_is_water(self, value)

    def set_is_deep_water(self, value):
        zx.tp_set_is_deep_water(self, value)

    def set_gfx_small_shadow_caster(self, value):
        zx.tp_set_gfx_small_shadow_caster(self, value)
