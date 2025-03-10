import my
import tp


def on_hit_and_still_alive(me, hitter, real_hitter, x, y, crit, damage):
    my.thing_sound_play_channel(me, my.CHANNEL_IMPACT, f"door_hit{my.py_non_pcg_random_range_inclusive(1, 2)}")


def on_death(me, x, y):
    my.thing_sound_play_channel(me, my.CHANNEL_IMPACT, "door_break")


def on_open(me, x, y):
    my.thing_sound_play_channel(me, my.CHANNEL_IMPACT, "door_open")


def tp_init(name):
    self = tp.Tp(name, "reinforced door")
    # begin sort marker
    my.collision_check(self, True)
    my.collision_hit_priority(self, 9)
    my.dmg_chance_d1000_crush(self, 0, 1000)
    my.dmg_crush_dice(self, "2d6")
    my.gfx_ascii_shown_in_bg(self, True)
    my.gfx_ascii_shown(self, True)
    my.gfx_pixelart_animated(self, True)
    my.gfx_pixelart_health_bar_autohide(self, True)
    my.gfx_pixelart_oversized_and_on_floor(self, True)
    my.gfx_pixelart_reflection(self, True)
    my.gfx_pixelart_shadow(self, True)
    my.gfx_pixelart_shadow_short(self, True)
    my.gfx_pixelart_show_highlighted(self, True)
    my.gfx_pixelart_wobbles_when_hit(self, True)
    my.health_initial_dice(self, "5d20")
    my.is_always_hit(self, True)
    my.is_attackable_by_monst(self, True)
    my.is_attackable_by_player(self, True)
    my.is_biome_chasms(self, True)
    my.is_biome_dungeon(self, True)
    my.is_biome_flooded(self, True)
    my.is_biome_ice(self, True)
    my.is_biome_lava(self, True)
    my.is_biome_swamp(self, True)
    my.is_corpse_on_death(self, True)
    my.is_cursor_can_hover_over(self, True)
    my.is_cursor_path_blocker(self, True)
    my.is_described_in_leftbar(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_door(self, True)
    my.is_gas_blocker(self, True)
    my.is_hittable(self, True)
    my.is_interesting(self, True)
    my.is_light_blocker(self, True)
    my.is_loggable(self, True)
    my.is_obs_jump_end(self, True)
    my.is_obs_jumping(self, True)
    my.is_obs_shooting(self, True)
    my.is_obs_shoving(self, True)
    my.is_obs_spawn_monst(self, True)
    my.is_obs_spawn(self, True)
    my.is_obs_wall_or_door(self, True)
    my.is_openable(self, True)
    my.is_shootable(self, True)
    my.is_tickable(self, True)
    my.noise_blocker(self, True)
    my.noise_on_hit_and_now_dead(self, 100)
    my.noise_on_hit_and_still_alive(self, 100)
    my.noise_on_open_or_close(self, 60)
    my.normal_placement_rules(self, True)
    my.on_death_do(self, "me.on_death()")
    my.on_death_is_open(self, True)
    my.on_hit_and_still_alive_do(self, "me.on_hit_and_still_alive()")
    my.on_open_do(self, "me.on_open()")
    my.stat_def(self, 20)
    my.temperature_max(self, 500)
    my.temperature_min(self, -100)
    my.temperature(self, 10)
    my.temperature(self, 20)
    my.temperature_sensitive(self, True)
    my.temperature_sensitive_to_sudden_changes(self, True)
    my.text_a_or_an(self, "the")
    my.text_description_short(self, "A metal door that's not for opening.")
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_ALWAYS_BEHIND)
    # end sort marker

    my.tile(self,
            ascii_fg_char="+", ascii_bg_col_name="gray20", ascii_fg_col_name="white",
            tile=name + ".100", is_hp_100_percent=True)
    my.tile(self,
            ascii_fg_char="+", ascii_bg_col_name="brown", ascii_fg_col_name="white",
            tile=name + ".75", is_hp_75_percent=True)
    my.tile(self,
            ascii_fg_char="+", ascii_bg_col_name="orange", ascii_fg_col_name="white",
            tile=name + ".50", is_hp_50_percent=True)
    my.tile(self,
            ascii_fg_char="+", ascii_bg_col_name="red", ascii_fg_col_name="white",
            tile=name + ".25", is_hp_25_percent=True)
    my.tile(self,
            ascii_fg_char="-", ascii_bg_col_name="gray10", ascii_fg_col_name="white",
            tile=name + ".dead", is_dead=True)
    my.tile(self,
            ascii_fg_char="-", ascii_bg_col_name="gray20", ascii_fg_col_name="white",
            tile=name + ".open", is_hp_100_percent=True, is_open=True)
    my.tile(self,
            ascii_fg_char="-", ascii_bg_col_name="gray20", ascii_fg_col_name="white",
            tile=name + ".open", is_hp_75_percent=True, is_open=True)
    my.tile(self,
            ascii_fg_char="-", ascii_bg_col_name="gray20", ascii_fg_col_name="white",
            tile=name + ".open", is_hp_50_percent=True, is_open=True)
    my.tile(self,
            ascii_fg_char="-", ascii_bg_col_name="gray20", ascii_fg_col_name="white",
            tile=name + ".open", is_hp_25_percent=True, is_open=True)

    my.tp_update(self)


def init():
    tp_init(name="door_metal")


init()
