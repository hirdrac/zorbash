import my
import tp


def melt(me, x, y):
    if my.thing_is_dead(me):
        return

    my.thing_msg(me, "The ice melts.")
    for dx in range(-1, 2):
        for dy in range(-1, 2):
            my.place_at(me, "water", x + dx, y + dy)
            my.thing_sound_play_channel(me, my.CHANNEL_IMPACT, "splash6")
            for it in my.level_get_all(me, x + dx, y + dy):
                if my.thing_is_lava(it) or my.thing_is_fire(it):
                    my.thing_dead(it, "frozen")


def on_fire(me, x, y):
    melt(me, x, y)


def on_fall(me, x, y):
    melt(me, x, y)


def on_death(me, x, y):
    melt(me, x, y)


def tp_init(name, text_long_name):
    self = tp.Tp(name, text_long_name)
    # begin sort marker

    my.chance_d1000_appearing(self, 10)
    my.chance_d1000_melting(self, 100)
    my.collision_check(self, True)
    my.collision_hit_priority(self, 100)
    my.dmg_chance_d1000_cold(self, 0, 1000)
    my.dmg_chance_d1000_crush(self, 0, 1000)
    my.dmg_cold_dice(self, "1d6")
    my.dmg_crush_dice(self, "2d6")
    my.dmg_received_doubled_from_fire(self, True)
    my.environ_dislikes_fire(self, 100)
    my.gfx_ascii_fade_with_dist(self, True)
    my.gfx_ascii_shown_as_gray_in_shadow(self, True)
    my.gfx_ascii_shown_in_bg(self, True)
    my.gfx_ascii_shown(self, True)
    my.gfx_pixelart_oversized_and_on_floor(self, True)
    my.gfx_pixelart_reflection(self, True)
    my.gfx_pixelart_shadow(self, True)
    my.gfx_pixelart_shadow_short(self, True)
    my.gfx_pixelart_show_highlighted(self, True)
    my.gfx_pixelart_shown_in_bg(self, True)
    my.gfx_pixelart_submergible(self, True)
    my.gfx_pixelart_wobbles_when_hit(self, True)
    my.health_initial_dice(self, "1d20")
    my.is_able_to_fall(self, True)
    my.is_able_to_melt(self, True)
    my.is_always_hit(self, True)
    my.is_attackable_by_monst(self, True)
    my.is_attackable_by_player(self, True)
    my.is_biome_chasms(self, True)
    my.is_biome_dungeon(self, True)
    my.is_biome_ice(self, True)
    my.is_biome_lava(self, True)
    my.is_block_of_ice(self, True)
    my.is_brittle(self, True)
    my.is_cursor_can_hover_over(self, True)
    my.is_cursor_path_blocker(self, True)
    my.is_described_in_leftbar(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_gas_blocker(self, True)
    my.is_hittable(self, True)
    my.is_immune_to_cold(self, True)
    my.is_immune_to_necrosis(self, True)
    my.is_immune_to_poison(self, True)
    my.is_immune_to_stamina_drain(self, True)
    my.is_interesting(self, True)  # so it can be shoved
    my.is_light_blocker_for_monst(self, True)  # to give cover to the player
    my.is_light_blocker(self, True)
    my.is_loggable(self, True)
    my.is_obs_ai(self, True)
    my.is_obs_casting(self, True)
    my.is_obs_jump_end(self, True)
    my.is_obs_jumping(self, True)
    my.is_obs_shooting(self, True)
    my.is_obs_shoving(self, True)
    my.is_obs_spawn_monst(self, True)
    my.is_obs_throwing(self, True)
    my.is_only_one_per_tile(self, True) # so wands of ice do not pile these up
    my.is_shovable_and_sticky(self, True)  # so a dogman in ice is also shoved
    my.is_shovable(self, True)
    my.is_tickable(self, True)  # So it can interact with fire
    my.is_very_heavy(self, True)
    my.noise_blocker(self, True)
    my.normal_placement_rules(self, True)
    my.on_death_do(self, "me.on_death()")
    my.on_fall_do(self, "me.on_fall()")
    my.on_you_are_on_fire_do(self, "me.on_fire()")
    my.temperature_max(self, 0)
    my.temperature(self, -100)
    my.temperature_sensitive(self, True)
    my.text_a_or_an(self, "a")
    my.text_description_short(self, "A block of ice.")
    my.thing_size(self, my.THING_SIZE_GIANT)
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_EFFECT)
    # end sort marker

    my.tile(self,
            ascii_bg_char="block", ascii_bg_col_name="cyan", tile=name)

    my.tp_update(self)


def init():
    tp_init(name="block_of_ice", text_long_name="block of ice")


init()
