import my
import tp


def on_you_nat_attack_attempt(me, x, y):
    sound = f"growl{my.py_non_pcg_random_range_inclusive(1, 10)}"
    my.thing_sound_play_channel(me, my.CHANNEL_MONST, sound)


def on_hit_and_still_alive(me, hitter, real_hitter, x, y, crit, damage):
    sound = f"hiss{my.py_non_pcg_random_range_inclusive(1, 10)}"
    if not my.thing_sound_play_channel(me, my.CHANNEL_MONST, sound):
        my.thing_sound_play_channel(me, my.CHANNEL_MONST_DEATH, sound)


def on_hit_dodge_do(me, hitter, x, y):
    sound = f"hiss{my.py_non_pcg_random_range_inclusive(1, 10)}"
    if not my.thing_sound_play_channel(me, my.CHANNEL_MONST, sound):
        my.thing_sound_play_channel(me, my.CHANNEL_MONST_DEATH, sound)


def on_death(me, x, y):
    if not my.thing_sound_play_channel(me, my.CHANNEL_MONST, "monst_death1"):
        my.thing_sound_play_channel(me, my.CHANNEL_MONST_DEATH, "monst_death1")


def on_want_to_shoot_at(me, target, x, y):  # Return True on doing an action
    my.thing_shoot_projectile_or_laser_at(me, "laser_energy", target)
    return True


def tp_init(name, text_long_name):
    self = tp.Tp(name, text_long_name)
    # begin sort marker
    my.aggression_pct(self, 100)
    my.ai_resent_count(self, 100)
    my.ai_wanderer(self, True)
    my.attack_eater(self, True)
    my.attack_humanoid(self, True)
    my.attack_meat(self, True)
    my.chance_d1000_shooting(self, 300)
    my.collision_check(self, True)
    my.collision_hit_priority(self, 20)
    my.consume_per_bite_amount(self, 30)
    my.distance_avoid(self, 4)
    my.distance_vision(self, 8)
    my.is_burnable(self, True)
    my.dmg_nat_att_dice(self, "2d6")
    my.dmg_nat_att_type(self, "whip")
    my.dmg_received_doubled_from_fire(self, True)
    my.environ_dislikes_fire(self, 10)
    my.gfx_anim_use(self, "attack_green")
    my.gfx_ascii_fade_with_dist(self, True)
    my.gfx_ascii_shown(self, True)
    my.gfx_pixelart_animated_can_hflip(self, True)
    my.gfx_pixelart_animated(self, True)
    my.gfx_pixelart_health_bar_shown(self, True)
    my.gfx_pixelart_reflection(self, True)
    my.gfx_pixelart_shadow(self, True)
    my.gfx_pixelart_shadow_short(self, True)
    my.gfx_pixelart_show_asleep_anim(self, True)
    my.gfx_pixelart_show_highlighted(self, True)
    my.gfx_pixelart_show_outlined(self, True)
    my.gfx_pixelart_wobbles_when_hit(self, True)
    my.health_initial_dice(self, "10d8")
    my.hunger_clock_tick_freq(self, 50)
    my.hunger_is_insatiable(self, True)
    my.is_able_to_be_surprised(self, True)
    my.is_able_to_be_teleported(self, True)
    my.is_able_to_change_levels(self, True)
    my.is_able_to_freeze(self, True)
    my.is_able_to_lunge(self, True)
    my.is_able_to_rest(self, True)
    my.is_able_to_see_in_the_dark(self, True)
    my.is_able_to_shoot_at(self, True)
    my.is_able_to_sleep(self, True)
    my.is_able_to_tire(self, True)
    my.is_attackable_by_monst(self, True)
    my.is_attackable_by_player(self, True)
    my.is_biome_chasms(self, True)
    my.is_biome_dungeon(self, True)
    my.is_biome_flooded(self, True)
    my.is_biome_lava(self, True)
    my.is_biome_swamp(self, True)
    my.is_corpse_on_death(self, True)
    my.is_crushable(self, True)
    my.is_described_in_leftbar(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_eater_of_meat(self, True)
    my.is_floating(self, True)
    my.is_hittable(self, True)
    my.is_immune_to_poison(self, True)
    my.is_immune_to_water(self, True)
    my.is_interesting(self, True)
    my.is_loggable(self, True)
    my.is_meat(self, True)
    my.is_monst_class_C(self, True)
    my.is_monst(self, True)
    my.is_moveable(self, True)
    my.is_msg_allowed_hears_something(self, True)
    my.is_msg_allowed_is_dead(self, True)
    my.is_msg_allowed_is_seen(self, True)
    my.is_msg_allowed_is_surprised(self, True)
    my.is_msg_allowed_is_wounded(self, True)
    my.is_msg_allowed_senses_danger(self, True)
    my.is_shovable(self, True)
    my.is_soft(self, True)
    my.is_tentacleye(self, True)
    my.is_undead(self, True)
    my.is_very_intelligent(self, True)
    my.move_speed(self, 100)
    my.noise_decibels_hearing(self, 50)
    my.noise_on_moving(self, 3)
    my.normal_placement_rules(self, True)
    my.on_death_do(self, "me.on_death()")
    my.on_hit_and_still_alive_do(self, "me.on_hit_and_still_alive()")
    my.on_hit_dodge_do(self, "me.on_hit_dodge_do()")
    my.on_want_to_shoot_at_do(self, "me.on_want_to_shoot_at()")
    my.on_you_nat_attack_attempt_do(self, "me.on_you_nat_attack_attempt()")
    my.rarity(self, my.RARITY_COMMON)  # how rare within this monster class
    my.stamina(self, 100)
    my.stat_con(self, 10)
    my.stat_def(self, 10)
    my.stat_dex(self, 14)
    my.stat_int(self, 14)
    my.stat_luck(self, 10)
    my.stat_psi(self, 14)
    my.stat_str(self, 10)
    my.temperature(self, 5)
    my.text_a_or_an(self, "a")
    my.text_description_long(self, "A floating mass of tentacles and eyeballs. These creatures are often employed to monitor the dark and dank dungeons with their impressive vision. Beware their lightning gaze...")
    my.text_description_short(self, "A writhing mass of tentacles and eyeballs.")
    my.text_hits(self, "slashes")
    my.thing_size(self, my.THING_SIZE_NORMAL)
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_MONST)
    # end sort marker

    delay = 300
    my.tile(self,
            ascii_fg_char="T", ascii_bg_col_name="", ascii_fg_col_name="green",
            tile=name + ".1.100", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="T", ascii_bg_col_name="", ascii_fg_col_name="green",
            tile=name + ".2.100", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="T", ascii_bg_col_name="", ascii_fg_col_name="green",
            tile=name + ".3.100", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="T", ascii_bg_col_name="", ascii_fg_col_name="green",
            tile=name + ".4.100", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="T", ascii_bg_col_name="", ascii_fg_col_name="green",
            tile=name + ".5.100", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="T", ascii_bg_col_name="", ascii_fg_col_name="green",
            tile=name + ".6.100", delay_ms=delay)

    my.tile(self,
            ascii_fg_char="t", ascii_bg_col_name="", ascii_fg_col_name="green",
            tile=name + ".sleeping.1", is_sleeping=True, delay_ms=delay)
    my.tile(self,
            ascii_fg_char="T", ascii_bg_col_name="", ascii_fg_col_name="green",
            tile=name + ".sleeping.2", is_sleeping=True, delay_ms=delay)

    my.tile(self,
            ascii_fg_char="T", ascii_bg_col_name="", ascii_fg_col_name="gray30",
            tile=name + ".dead.1", is_dead=True, delay_ms=delay)
    my.tile(self,
            ascii_fg_char="T", ascii_bg_col_name="", ascii_fg_col_name="gray30",
            tile=name + ".dead.2", is_dead=True, delay_ms=delay)
    my.tile(self,
            ascii_fg_char="T", ascii_bg_col_name="", ascii_fg_col_name="gray30",
            tile=name + ".dead.3", is_dead=True, delay_ms=delay)
    my.tile(self,
            ascii_fg_char="T", ascii_bg_col_name="", ascii_fg_col_name="gray30",
            tile=name + ".dead.4", is_dead=True, delay_ms=delay)
    my.tile(self,
            ascii_fg_char="T", ascii_bg_col_name="", ascii_fg_col_name="gray30",
            tile=name + ".dead.5", is_dead=True, delay_ms=delay)
    my.tile(self,
            ascii_fg_char="T", ascii_bg_col_name="", ascii_fg_col_name="gray30",
            tile=name + ".dead.6", is_dead=True, delay_ms=delay)
    my.tile(self,
            ascii_fg_char="T", ascii_bg_col_name="", ascii_fg_col_name="gray30",
            tile=name + ".dead.7", is_dead=True, delay_ms=delay)
    my.tile(self,
            ascii_fg_char="T", ascii_bg_col_name="", ascii_fg_col_name="gray30",
            tile=name + ".dead.8", is_dead=True, is_end_of_anim=True)

    my.tp_update(self)


def init():
    tp_init(name="tentacleye", text_long_name="lesser tentacleye")


init()
