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
    if not my.thing_sound_play_channel(me, my.CHANNEL_MONST, "squelch"):
        my.thing_sound_play_channel(me, my.CHANNEL_MONST_DEATH, "squelch")


def tp_init(name, text_long_name, text_short_name):
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker
    my.aggression_pct(self, -10)
    my.ai_resent_count(self, 10)
    my.attack_eater(self, True)
    my.chance_d1000_jump_attack(self, 800)
    my.chance_d1000_jump_onto(self, 100)
    my.chance_d1000_jump_randomly(self, 20)
    my.chance_d1000_tameable(self, 0)
    my.collision_check(self, True)
    my.collision_hit_priority(self, 20)
    my.consume_per_bite_amount(self, 30)
    my.distance_avoid(self, 5)
    my.distance_vision(self, 5)
    my.dmg_chance_d1000_nat_att(self, 0, 100)
    my.dmg_chance_d1000_necrosis(self, 0, 50)
    my.dmg_chance_d1000_poison(self, 0, 900)
    my.dmg_limited_per_tick(self, True)
    my.dmg_nat_att_dice(self, "1d3")
    my.dmg_nat_att_type(self, "gore")
    my.dmg_necrosis_dice(self, "1")
    my.dmg_poison_dice(self, "1d3")
    my.dmg_rcv_doubled_from_fire(self, True)
    my.environ_dislikes_water(self, 100)
    my.environ_hates_fire(self, 10)
    my.gfx_anim_use(self, "attack_green")
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
    my.gfx_pixelart_submergible(self, True)
    my.gfx_pixelart_wobbles_when_hit(self, True)
    my.health_initial_dice(self, "1d4")
    my.hunger_clock_tick_freq(self, 50)
    my.hunger_is_insatiable(self, True)
    my.is_able_to_be_teleported(self, True)
    my.is_able_to_fall(self, True)
    my.is_able_to_freeze(self, True)
    my.is_able_to_jump_attack(self, True)
    my.is_able_to_jump_escape(self, True)
    my.is_able_to_jump_onto(self, True)
    my.is_able_to_jump(self, True)
    my.is_able_to_jump_without_tiring(self, True)
    my.is_able_to_lunge(self, True)
    my.is_able_to_rest(self, True)
    my.is_able_to_see_in_the_dark(self, True)
    my.is_able_to_tire(self, True)
    my.is_air_breather(self, True)
    my.is_attackable_by_monst(self, True)
    my.is_attackable_by_player(self, True)
    my.is_biome_dungeon(self, True)
    my.is_bleeder(self, True)
    my.is_buffable(self, True)
    my.is_burnable(self, True)
    my.is_corpse_on_death(self, True)
    my.is_crushable(self, True)
    my.is_described_in_leftbar(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_eater_of_meat(self, True)
    my.is_green_blooded(self, True)
    my.is_hittable(self, True)
    my.is_immune_to_necrosis(self, True)
    my.is_immune_to_spiderwebs(self, True)
    my.is_interesting(self, True)
    my.is_living(self, True)
    my.is_loggable(self, True)
    my.is_monst_class_A(self, True)
    my.is_monst(self, True)
    my.is_moveable(self, True)
    my.is_msg_allowed_hears_something(self, True)
    my.is_msg_allowed_is_dead(self, True)
    my.is_msg_allowed_is_seen(self, True)
    my.is_msg_allowed_is_wounded(self, True)
    my.is_msg_allowed_senses_danger(self, True)
    my.is_necrotic_danger_level(self, 1)  # danger level
    my.is_poisonous_danger_level(self, 2)  # danger level
    my.is_shootable(self, True)
    my.is_shovable(self, True)
    my.is_spider(self, True)
    my.is_tickable(self, True)
    my.jump_distance(self, 5)
    my.move_speed(self, 200)
    my.noise_decibels_hearing(self, 0)
    my.noise_on_moving(self, 15)
    my.normal_placement_rules(self, True)
    my.nutrition_dice(self, "1d6")
    my.on_death_do(self, "me.on_death()")
    my.on_hit_and_still_alive_do(self, "me.on_hit_and_still_alive()")
    my.on_hit_dodge_do(self, "me.on_hit_dodge_do()")
    my.on_you_nat_attack_attempt_do(self, "me.on_you_nat_attack_attempt()")
    my.rarity(self, my.RARITY_UNCOMMON)  # how rare within this monster class
    my.stamina(self, 100)
    my.stat_con(self, 12)
    my.stat_def(self, 10)
    my.stat_dex(self, 12)
    my.stat_luck(self, 10)
    my.stat_psi(self, 0)
    my.stat_str(self, 8)
    my.temperature_max(self, 50)
    my.temperature_min(self, 0)
    my.temperature(self, 20)
    my.temperature_sensitive(self, True)
    my.text_a_or_an(self, "a")
    my.text_description_long(self, "A disturbingly large brown spider, the extrovert spider is a close relative of the brown recluse. Beware of its necrotic bite, especially at parties, which it loves to turn up as a surprise guest.")
    my.text_description_short(self, "A brown extrovert spider.")
    my.text_hits(self, "bites")
    my.thing_size(self, my.THING_SIZE_LARGE)
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_MONST)
    # end sort marker

    delay = 150
    my.tile(self,
            ascii_fg_char="s", ascii_bg_col_name="", ascii_fg_col_name="brown",
            tile="spider_brown.1", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="s", ascii_bg_col_name="", ascii_fg_col_name="brown",
            tile="spider_brown.2", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="s", ascii_bg_col_name="", ascii_fg_col_name="brown",
            tile="spider_brown.3", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="s", ascii_bg_col_name="", ascii_fg_col_name="brown",
            tile="spider_brown.4", delay_ms=delay)

    my.tile(self,
            ascii_fg_char="s", ascii_bg_col_name="", ascii_fg_col_name="gray30",
            tile="spider_brown.dead", is_dead=True, delay_ms=delay)

    my.tp_update(self)


def init():
    tp_init(name="spider_brown", text_long_name="brown extrovert spider", text_short_name="extrovert spider")


init()
