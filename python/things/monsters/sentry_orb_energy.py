import my
import tp


def on_death(me, x, y):
    explode(me, x, y)


def explode(me, x, y):
    if my.thing_is_dead(me):
        return

    my.thing_msg(me, "The sentry orb explodes!")
    my.spawn_at_my_position(me, "explosion_major")


def on_want_to_shoot_at(me, target, target_x, target_y):  # Return True on doing an action
    my.thing_shoot_projectile_or_laser_at(me, "laser_energy", target)
    return True


def tp_init(name, text_long_name, text_short_name):
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker
    my.aggression_pct(self, 100)
    my.ai_wanderer(self, True)
    my.attack_humanoid(self, True)
    my.chance_d1000_shooting(self, 800)
    my.chance_d1000_tameable(self, 0)
    my.collision_check(self, True)
    my.collision_hit_priority(self, 20)
    my.distance_vision(self, 8)
    my.dmg_num_of_attacks(self, 0)  # fires only
    my.dmg_rcv_doubled_from_cold(self, True)
    my.gfx_ascii_fade_with_dist(self, True)
    my.gfx_ascii_shown(self, True)
    my.gfx_pixelart_animated(self, True)
    my.gfx_pixelart_health_bar_shown(self, True)
    my.gfx_pixelart_reflection(self, True)
    my.gfx_pixelart_shadow(self, True)
    my.gfx_pixelart_shadow_short(self, True)
    my.gfx_pixelart_show_highlighted(self, True)
    my.gfx_pixelart_wobbles_when_hit(self, True)
    my.health_initial_dice(self, "1")
    my.is_able_to_be_surprised(self, True)
    my.is_able_to_be_teleported(self, True)
    my.is_able_to_see_in_the_dark(self, True)
    my.is_able_to_shoot_at_close_range(self, True)
    my.is_attackable_by_monst(self, True)
    my.is_attackable_by_player(self, True)
    my.is_biome_chasms(self, True)
    my.is_biome_dungeon(self, True)
    my.is_biome_ice(self, True)
    my.is_buffable(self, True)
    my.is_described_in_leftbar(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_ethereal(self, True)
    my.is_fearless(self, True)
    my.is_floating(self, True)
    my.is_hittable(self, True)
    my.is_immune_to_blinding(self, True)
    my.is_immune_to_necrosis(self, True)
    my.is_immune_to_paralysis(self, True)
    my.is_immune_to_poison(self, True)
    my.is_interesting(self, True)
    my.is_lifeless(self, True)
    my.is_loggable(self, True)
    my.is_magical(self, True)
    my.is_monst_class_B(self, True)
    my.is_monst(self, True)
    my.is_moveable(self, True)
    my.is_msg_allowed_hears_something(self, True)
    my.is_msg_allowed_is_dead(self, True)
    my.is_msg_allowed_is_seen(self, True)
    my.is_msg_allowed_senses_danger(self, True)
    my.is_one_per_tile(self, True)
    my.is_shootable(self, True)
    my.is_tickable(self, True)
    my.is_vanquished_on_negation(self, True)
    my.light_color(self, "yellow")
    my.light_dist(self, 1)
    my.move_speed(self, 50)
    my.noise_decibels_hearing(self, 5)
    my.noise_on_moving(self, 5)
    my.normal_placement_rules(self, True)
    my.on_death_do(self, "me.on_death()")
    my.on_want_to_shoot_at_do(self, "me.on_want_to_shoot_at()")
    my.rarity(self, my.RARITY_UNCOMMON)  # how rare within this monster class
    my.stat_con(self, 10)
    my.stat_def(self, 10)
    my.stat_dex(self, 10)
    my.stat_luck(self, 10)
    my.stat_psi(self, 0)
    my.stat_str(self, 10)
    my.temperature_max(self, 1000)
    my.temperature_min(self, 0)
    my.temperature(self, 200)
    my.temperature_sensitive(self, True)
    my.text_a_or_an(self, "a")
    my.text_description_long2(self, "Note that sentry orbs are fragile and prone to explosive outbursts...")
    my.text_description_long(self, "Sentry orbs patrol the dungeon, raining down punishment on whomever should not be there. Essentially you... This one fires beams of devastating energy.")
    my.text_description_short(self, "A sentry orb.")
    my.text_hits(self, "burns")
    my.thing_size(self, my.THING_SIZE_NORMAL)
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_MONST)  # so it appears over things when consuming
    # end sort marker

    delay = 200
    my.tile(self,
            ascii_fg_char="O", ascii_bg_col_name="", ascii_fg_col_name="yellow",
            tile=name + ".1", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="o", ascii_bg_col_name="", ascii_fg_col_name="yellow",
            tile=name + ".2", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="O", ascii_bg_col_name="", ascii_fg_col_name="yellow",
            tile=name + ".3", delay_ms=delay)

    my.tp_update(self)


def init():
    tp_init(name="sentry_orb_energy", text_long_name="orb of energy", text_short_name="sentry orb")


init()
