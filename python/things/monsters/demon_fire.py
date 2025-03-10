import my
import tp


def on_you_nat_attack_attempt(me, x, y):
    sound = f"hiss{my.py_non_pcg_random_range_inclusive(1, 10)}"
    my.thing_sound_play_channel(me, my.CHANNEL_MONST, sound)


def on_hit_and_still_alive(me, hitter, real_hitter, x, y, crit, damage):
    sound = f"hiss{my.py_non_pcg_random_range_inclusive(1, 10)}"
    my.thing_sound_play_channel(me, my.CHANNEL_MONST, sound)


def on_hit_dodge_do(me, hitter, x, y):
    sound = f"hiss{my.py_non_pcg_random_range_inclusive(1, 10)}"
    my.thing_sound_play_channel(me, my.CHANNEL_MONST, sound)


def on_tick(owner, me, x, y):
    if my.py_pcg_random_range_inclusive(1, 100) < 90:
        return False

    my.spawn_at_my_position(me, "fire")
    return True


def on_death(me, x, y):
    my.thing_msg(me, "The demon screams angrily and vanishes!")
    my.spawn_at_my_position(me, "fire")

    sound = f"growl{my.py_non_pcg_random_range_inclusive(1, 10)}"
    if not my.thing_sound_play_channel(me, my.CHANNEL_MONST, sound):
        my.thing_sound_play_channel(me, my.CHANNEL_MONST_DEATH, sound)


def on_want_to_shoot_at(me, target, target_x, target_y):  # Return True on doing an action
    my.thing_shoot_projectile_or_laser_at(me, "projectile_fire", target)
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
    my.chance_d1000_jump_attack(self, 800)
    my.chance_d1000_jump_onto(self, 100)
    my.chance_d1000_jump_randomly(self, 20)
    my.chance_d1000_shooting(self, 300)
    my.chance_d1000_shove(self, 200)
    my.chance_d1000_tameable(self, 20)
    my.chance_d1000_teleport_self(self, 50)
    my.collision_check(self, True)
    my.collision_hit_priority(self, 20)
    my.consume_per_bite_amount(self, 10)
    my.distance_vision(self, 7)
    my.dmg_chance_d1000_fire(self, 1, 1000)
    my.dmg_chance_d1000_nat_att(self, 0, 1000)
    my.dmg_fire_dice(self, "1d6+6")
    my.dmg_nat_att_dice(self, "1d14+4")
    my.dmg_nat_att_type(self, "bludgeon")
    my.dmg_num_of_attacks(self, 2)
    my.dmg_rcv_doubled_from_cold(self, True)
    my.dmg_rcv_doubled_from_water(self, True)
    my.environ_hates_cold(self, 100)
    my.environ_hates_water(self, 100)
    my.gfx_anim_use(self, "attack_major_orange")
    my.gfx_anim_use(self, "sword_plutonium_swing")
    my.gfx_ascii_fade_with_dist(self, True)
    my.gfx_ascii_shown(self, True)
    my.gfx_pixelart_animated_can_hflip(self, True)
    my.gfx_pixelart_animated(self, True)
    my.gfx_pixelart_bounce_on_move(self, True)
    my.gfx_pixelart_health_bar_shown(self, True)
    my.gfx_pixelart_oversized_and_on_floor(self, True)
    my.gfx_pixelart_reflection(self, True)
    my.gfx_pixelart_shadow(self, True)
    my.gfx_pixelart_shadow_short(self, True)
    my.gfx_pixelart_show_highlighted(self, True)
    my.gfx_pixelart_submergible(self, True)
    my.gfx_pixelart_wobbles_when_hit(self, True)
    my.has_a_head(self, True)
    my.health_initial_dice(self, "10d8")
    my.hunger_is_insatiable(self, True)
    my.is_able_to_be_surprised(self, True)
    my.is_able_to_be_teleported(self, True)
    my.is_able_to_fall(self, True)
    my.is_able_to_lunge(self, True)
    my.is_able_to_rest(self, True)
    my.is_able_to_see_in_magical_darkness(self, True)
    my.is_able_to_see_in_the_dark(self, True)
    my.is_able_to_see_through_doors(self, True)
    my.is_able_to_teleport_escape(self, True)
    my.is_able_to_teleport_self(self, True)
    my.is_able_to_teleport_without_tiring(self, True)
    my.is_always_submerged_in_lava(self, True)
    my.is_attackable_by_monst(self, True)
    my.is_attackable_by_player(self, True)
    my.is_biome_dungeon(self, True)
    my.is_biome_lava(self, True)
    my.is_buffable(self, True)
    my.is_demon(self, True)
    my.is_described_in_leftbar(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_eater_of_meat(self, True)
    my.is_eater_of_red_blood(self, True)
    my.is_fearless(self, True)
    my.is_fire_elemental(self, True)
    my.is_heavy(self, True)
    my.is_hittable(self, True)
    my.is_humanoid(self, True)
    my.is_immune_to_fire(self, True)
    my.is_immune_to_necrosis(self, True)
    my.is_immune_to_poison(self, True)
    my.is_immune_to_vorpal_weapons(self, True)
    my.is_intelligent(self, True)
    my.is_interesting(self, True)
    my.is_lifeless(self, True)
    my.is_loggable(self, True)
    my.is_monst_class_D(self, True)
    my.is_monst(self, True)
    my.is_moveable(self, True)
    my.is_msg_allowed_hears_something(self, True)
    my.is_msg_allowed_is_dead(self, True)
    my.is_msg_allowed_is_seen(self, True)
    my.is_msg_allowed_is_surprised(self, True)
    my.is_msg_allowed_is_wounded(self, True)
    my.is_msg_allowed_senses_danger(self, True)
    my.is_obs_when_dead(self, True)
    my.is_shootable(self, True)
    my.is_tickable(self, True)
    my.is_very_intelligent(self, True)
    my.light_color(self, "red")
    my.light_dist(self, 2)
    my.move_speed(self, 150)
    my.noise_decibels_hearing(self, 50)
    my.noise_on_moving(self, 25)
    my.normal_placement_rules(self, True)
    my.on_death_do(self, "me.on_death()")
    my.on_hit_and_still_alive_do(self, "me.on_hit_and_still_alive()")
    my.on_hit_dodge_do(self, "me.on_hit_dodge_do()")
    my.on_tick_do(self, "me.on_tick()")
    my.on_want_to_shoot_at_do(self, "me.on_want_to_shoot_at()")
    my.on_you_nat_attack_attempt_do(self, "me.on_you_nat_attack_attempt()")
    my.rarity(self, my.RARITY_UNCOMMON)  # how rare within this monster class
    my.shove_bonus(self, 1)
    my.stamina(self, 100)
    my.stat_con(self, 20)
    my.stat_def(self, 14)
    my.stat_dex(self, 8)
    my.stat_int(self, 22)
    my.stat_luck(self, 2)
    my.stat_psi(self, 18)
    my.stat_str(self, 18)
    my.teleport_distance(self, 5)
    my.temperature_min(self, 50)
    my.temperature(self, 100)
    my.temperature_sensitive(self, True)
    my.temperature_sensitive_to_sudden_changes(self, True)
    my.text_a_or_an(self, "a")
    my.text_description_long2(self, "Fire demons are formidable enemies. Execute extreme caution or be executed extremely...")
    my.text_description_long(self, "Accursed creature of the abyss. Devoid of life. Full of hatred, and just wants to get back to the pit so it can take care of its pet cats. And you are in the way...")
    my.text_description_short(self, "A hot fire demon.")
    my.text_hits(self, "whips")
    my.thing_size(self, my.THING_SIZE_GIANT)
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_MONST)
    # end sort marker

    delay = 350
    my.tile(self,
            ascii_fg_char="D", ascii_bg_col_name="", ascii_fg_col_name="red",
            tile=name + ".1", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="D", ascii_bg_col_name="", ascii_fg_col_name="orange",
            tile=name + ".2", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="D", ascii_bg_col_name="", ascii_fg_col_name="yellow",
            tile=name + ".3", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="D", ascii_bg_col_name="", ascii_fg_col_name="gray30",
            tile="demon_fire.dead", is_dead=True, delay_ms=delay)

    my.tp_update(self)


def init():
    tp_init(name="demon_fire", text_long_name="fire demon")


init()
