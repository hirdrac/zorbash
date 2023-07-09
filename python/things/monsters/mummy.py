import my
import tp


def on_you_nat_attack_attempt(me, x, y):
    sound = f"growl{my.non_pcg_randint(1, 10)}"
    my.thing_sound_play_channel(me, my.CHANNEL_MONST, sound)


def on_hit_and_still_alive(me, hitter, real_hitter, x, y, crit, damage):
    sound = f"hiss{my.non_pcg_randint(1, 10)}"
    if not my.thing_sound_play_channel(me, my.CHANNEL_MONST, sound):
        my.thing_sound_play_channel(me, my.CHANNEL_MONST_DEATH, sound)


def on_hit_dodge_do(me, hitter, x, y):
    sound = f"hiss{my.non_pcg_randint(1, 10)}"
    if not my.thing_sound_play_channel(me, my.CHANNEL_MONST, sound):
        my.thing_sound_play_channel(me, my.CHANNEL_MONST_DEATH, sound)


def on_death(me, x, y):
    if not my.thing_sound_play_channel(me, my.CHANNEL_MONST, "monst_death1"):
        my.thing_sound_play_channel(me, my.CHANNEL_MONST_DEATH, "monst_death1")


def tp_init(name, text_long_name):
    self = tp.Tp(name, text_long_name)
    # begin sort marker
    my.aggression_pct(self, 100)
    my.ai_resent_count(self, 100)
    my.ai_wanderer(self, True)
    my.attack_eater(self, True)
    my.attack_humanoid(self, True)
    my.attack_living(self, True)
    my.attack_meat(self, True)
    my.chance_d1000_shove(self, 200)
    my.collision_check(self, True)
    my.collision_hit_priority(self, 20)
    my.consume_per_bite_amount(self, 30)
    my.distance_leader_max(self, 5)
    my.distance_vision(self, 5)
    my.dmg_chance_d1000_nat_att(self, 0, 800)
    my.dmg_chance_d1000_stamina_drain(self, 1, 200)
    my.dmg_nat_att_dice(self, "1d10+10")
    my.dmg_nat_att_type(self, "gore")
    my.dmg_num_of_attacks(self, 2)
    my.dmg_received_doubled_from_fire(self, True)
    my.dmg_received_doubled_from_water(self, True)
    my.dmg_stamina_dice(self, "1d10")
    my.environ_hates_fire(self, 100)
    my.environ_hates_water(self, 100)
    my.gfx_anim_use(self, "attack_red")
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
    my.health_initial_dice(self, "4d20")
    my.hunger_is_insatiable(self, True)
    my.is_able_to_be_resurrected(self, True)
    my.is_able_to_be_surprised(self, True)
    my.is_able_to_be_teleported(self, True)
    my.is_able_to_change_levels(self, True)
    my.is_able_to_fall(self, True)
    my.is_able_to_lunge(self, True)
    my.is_able_to_see_in_the_dark(self, True)
    my.is_attackable_by_monst(self, True)
    my.is_attackable_by_player(self, True)
    my.is_biome_chasms(self, True)
    my.is_biome_dungeon(self, True)
    my.is_burnable(self, True)
    my.is_corpse_on_death(self, True)
    my.is_crushable(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_eater_of_red_blood(self, True)
    my.is_fearless(self, True)
    my.is_hittable(self, True)
    my.is_immune_to_cold(self, True)
    my.is_immune_to_fire(self, True)
    my.is_immune_to_necrosis(self, True)
    my.is_immune_to_poison(self, True)
    my.is_immune_to_stamina_drain(self, True)
    my.is_interesting(self, True)
    my.is_loggable(self, True)
    my.is_magical(self, True)
    my.is_monst_class_B(self, True)
    my.is_monst(self, True)
    my.is_moveable(self, True)
    my.is_msg_allowed_hears_something(self, True)
    my.is_msg_allowed_is_dead(self, True)
    my.is_msg_allowed_is_seen(self, True)
    my.is_msg_allowed_is_surprised(self, True)
    my.is_msg_allowed_is_wounded(self, True)
    my.is_msg_allowed_senses_danger(self, True)
    my.is_shovable(self, True)
    my.is_tickable(self, True)
    my.is_undead(self, True)
    my.move_speed(self, 100)
    my.noise_decibels_hearing(self, 50)
    my.noise_on_moving(self, 5)
    my.normal_placement_rules(self, True)
    my.on_death_do(self, "me.on_death()")
    my.on_hit_and_still_alive_do(self, "me.on_hit_and_still_alive()")
    my.on_hit_dodge_do(self, "me.on_hit_dodge_do()")
    my.on_you_nat_attack_attempt_do(self, "me.on_you_nat_attack_attempt()")
    my.rarity(self, my.RARITY_COMMON)  # how rare within this monster class
    my.resurrect_dice(self, "1d10+30")
    my.shove_bonus(self, 1)
    my.stat_con(self, 15)
    my.stat_def(self, 11)
    my.stat_dex(self, 10)
    my.stat_int(self, 12)
    my.stat_luck(self, 10)
    my.stat_psi(self, 12)
    my.stat_str(self, 16)
    my.temperature(self, 5)
    my.text_a_or_an(self, "a")
    my.text_description_long2(self, "Death is no release for this poor creature. Watch out for its necrotic touch!")
    my.text_description_long(self, "Possibly the corpse of one who ventured into this dungeon before. All life is gone now, and what remains is a corpse wrapped in rags.")
    my.text_description_short(self, "A staggering corpse, covered in tissue paper.")
    my.text_hits(self, "claws")
    my.thing_size(self, my.THING_SIZE_NORMAL)
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_MONST)
    # end sort marker

    delay = 200
    my.tile(self,
            ascii_fg_char="M", ascii_bg_col_name="", ascii_fg_col_name="gray80",
            tile=name + ".1", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="M", ascii_bg_col_name="", ascii_fg_col_name="gray80",
            tile=name + ".2", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="M", ascii_bg_col_name="", ascii_fg_col_name="gray80",
            tile=name + ".3", delay_ms=delay)

    delay = 50
    my.tile(self,
            ascii_fg_char="M", ascii_bg_col_name="", ascii_fg_col_name="gray30",
            tile=name + ".dead.1", is_dead=True, delay_ms=delay)
    my.tile(self,
            ascii_fg_char="M", ascii_bg_col_name="", ascii_fg_col_name="gray30",
            tile=name + ".dead.2", is_dead=True, delay_ms=delay)
    my.tile(self,
            ascii_fg_char="M", ascii_bg_col_name="", ascii_fg_col_name="gray30",
            tile=name + ".dead.3", is_dead=True, delay_ms=delay)
    my.tile(self,
            ascii_fg_char="M", ascii_bg_col_name="", ascii_fg_col_name="gray30",
            tile=name + ".dead.4", is_dead=True, delay_ms=delay)
    my.tile(self,
            ascii_fg_char="M", ascii_bg_col_name="", ascii_fg_col_name="gray30",
            tile=name + ".dead.5", is_dead=True, is_end_of_anim=True)

    delay = 200
    my.tile(self,
            ascii_fg_char="M", ascii_bg_col_name="", ascii_fg_col_name="gray80",
            tile=name + ".dead.5", is_resurrecting=True, delay_ms=delay)
    my.tile(self,
            ascii_fg_char="M", ascii_bg_col_name="", ascii_fg_col_name="gray80",
            tile=name + ".dead.4", is_resurrecting=True, delay_ms=delay)
    my.tile(self,
            ascii_fg_char="M", ascii_bg_col_name="", ascii_fg_col_name="gray80",
            tile=name + ".dead.3", is_resurrecting=True, delay_ms=delay)
    my.tile(self,
            ascii_fg_char="M", ascii_bg_col_name="", ascii_fg_col_name="gray80",
            tile=name + ".dead.2", is_resurrecting=True, delay_ms=delay)
    my.tile(self,
            ascii_fg_char="M", ascii_bg_col_name="", ascii_fg_col_name="gray80",
            tile=name + ".dead.1",
            is_resurrecting=True,
            is_end_of_anim=True,
            is_alive_on_end_of_anim=True)

    my.tp_update(self)


def init():
    tp_init(name="mummy", text_long_name="mummy")


init()
