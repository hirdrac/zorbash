import my
import tp


def on_you_nat_attack_attempt(me, x, y):
    my.thing_sound_play_channel(me, my.CHANNEL_MONST, "slime_attack")


def on_hit_and_still_alive(me, hitter, real_hitter, x, y, crit, damage):
    my.thing_sound_play_channel(me, my.CHANNEL_MONST, "slime_attack")


def on_death(me, x, y):
    my.thing_sound_play_channel(me, my.CHANNEL_MONST, f"slime{my.py_non_pcg_random_range_inclusive(1, 9)}")


def on_jump(me, x, y):
    my.thing_sound_play_channel(me, my.CHANNEL_MONST, "slime_jump")


def tp_init(name, text_long_name):
    self = tp.Tp(name, text_long_name)
    # begin sort marker
    my.aggression_pct(self, 100)
    my.ai_resent_count(self, 3)
    my.ai_wanderer(self, True)
    my.attack_eater(self, True)
    my.chance_d1000_jump_attack(self, 100)
    my.chance_d1000_jump_on_low_hp(self, 500)
    my.chance_d1000_jump_randomly(self, 20)
    my.chance_d1000_tameable(self, 0)
    my.collision_check(self, True)
    my.collision_hit_priority(self, 20)
    my.consume_per_bite_amount(self, 1)
    my.distance_avoid(self, 2)
    my.distance_vision(self, 5)
    my.dmg_acid_dice(self, "1d5")
    my.dmg_chance_d1000_acid(self, 0, 500)
    my.dmg_chance_d1000_nat_att(self, 0, 500)
    my.dmg_limited_per_tick(self, True)
    my.dmg_nat_att_dice(self, "1")
    my.dmg_nat_att_type(self, "sting")
    my.dmg_rcv_doubled_from_cold(self, True)
    my.dmg_rcv_doubled_from_fire(self, True)
    my.environ_hates_fire(self, 100)
    my.gfx_anim_use(self, "green_splatter")
    my.gfx_ascii_fade_with_dist(self, True)
    my.gfx_ascii_shown(self, True)
    my.gfx_pixelart_animated_can_hflip(self, True)
    my.gfx_pixelart_animated(self, True)
    my.gfx_pixelart_bounce_on_move(self, True)
    my.gfx_pixelart_health_bar_shown(self, True)
    my.gfx_pixelart_reflection(self, True)
    my.gfx_pixelart_shadow(self, True)
    my.gfx_pixelart_shadow_short(self, True)
    my.gfx_pixelart_show_highlighted(self, True)
    my.gfx_pixelart_show_outlined(self, True)
    my.gfx_pixelart_submergible(self, True)
    my.gfx_pixelart_wobbles_when_hit(self, True)
    my.has_a_head(self, True)
    my.health_initial_dice(self, "1")
    my.hunger_clock_tick_freq(self, 50)
    my.hunger_is_insatiable(self, True)
    my.is_able_to_be_teleported(self, True)
    my.is_able_to_fall(self, True)
    my.is_able_to_freeze(self, True)
    my.is_able_to_jump_attack(self, True)
    my.is_able_to_jump_escape(self, True)
    my.is_able_to_jump(self, True)
    my.is_able_to_lunge(self, True)
    my.is_able_to_see_in_the_dark(self, True)
    my.is_acid(self, True)
    my.is_attackable_by_monst(self, True)
    my.is_attackable_by_player(self, True)
    my.is_biome_dungeon(self, True)
    my.is_biome_flooded(self, True)
    my.is_biome_swamp(self, True)
    my.is_bleeder(self, True)
    my.is_buffable(self, True)
    my.is_burnable(self, True)
    my.is_crushable(self, True)
    my.is_described_in_leftbar(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_eater_of_green_blood(self, True)
    my.is_eater_of_meat(self, True)
    my.is_eater_of_red_blood(self, True)
    my.is_eater_of_slime(self, True)
    my.is_fearless(self, True)
    my.is_green_blooded(self, True)
    my.is_hittable(self, True)
    my.is_immune_to_acid(self, True)
    my.is_immune_to_cold(self, True)
    my.is_immune_to_electricity(self, True)
    my.is_immune_to_lightning(self, True)
    my.is_immune_to_necrosis(self, True)
    my.is_interesting(self, True)
    my.is_living(self, True)
    my.is_loggable(self, True)
    my.is_monst_class_B(self, True)
    my.is_monst(self, True)
    my.is_moveable(self, True)
    my.is_msg_allowed_hears_something(self, True)
    my.is_msg_allowed_is_dead(self, True)
    my.is_msg_allowed_is_seen(self, True)
    my.is_msg_allowed_is_wounded(self, True)
    my.is_msg_allowed_senses_danger(self, True)
    my.is_shootable(self, True)
    my.is_slime(self, True)
    my.is_soft(self, True)
    my.is_tickable(self, True)
    my.jump_distance(self, 3)
    my.move_speed(self, 120)
    my.noise_decibels_hearing(self, 50)
    my.noise_on_moving(self, 15)
    my.normal_placement_rules(self, True)
    my.nutrition_dice(self, "1d4")
    my.on_death_do(self, "me.on_death()")
    my.on_hit_and_still_alive_do(self, "me.on_hit_and_still_alive()")
    my.on_jump_do(self, "me.on_jump()")
    my.on_you_nat_attack_attempt_do(self, "me.on_you_nat_attack_attempt()")
    my.rarity(self, my.RARITY_COMMON)  # how rare within this monster class
    my.stat_con(self, 10)
    my.stat_def(self, 5)
    my.stat_dex(self, 10)
    my.stat_luck(self, 10)
    my.stat_psi(self, 0)
    my.stat_str(self, 5)
    my.temperature_max(self, 50)
    my.temperature_min(self, 0)
    my.temperature(self, 20)
    my.temperature_sensitive(self, True)
    my.text_a_or_an(self, "a")
    my.text_description_long(self, "Baby black puddings are inky masses of gooey nastiness. Much quicker than their heavier parents, they are best avoided.")
    my.text_description_short(self, "A small black pudding.")
    my.text_hits(self, "splats")
    my.thing_size(self, my.THING_SIZE_SMALL)
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_MONST)
    # end sort marker

    delay = 200
    my.tile(self,
            ascii_fg_char="p", ascii_bg_col_name="", ascii_fg_col_name="purple",
            tile=name + ".1", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="p", ascii_bg_col_name="", ascii_fg_col_name="purple",
            tile=name + ".2", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="p", ascii_bg_col_name="", ascii_fg_col_name="purple",
            tile=name + ".3", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="p", ascii_bg_col_name="", ascii_fg_col_name="purple",
            tile=name + ".4", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="p", ascii_bg_col_name="", ascii_fg_col_name="purple",
            tile=name + ".5", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="p", ascii_bg_col_name="", ascii_fg_col_name="purple",
            tile=name + ".6", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="p", ascii_bg_col_name="", ascii_fg_col_name="purple",
            tile=name + ".7", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="p", ascii_bg_col_name="", ascii_fg_col_name="purple",
            tile=name + ".8", delay_ms=delay)

    my.tp_update(self)


def init():
    tp_init(name="pudding_baby", text_long_name="baby black pudding")


init()
