import my
import tp
import random


def tp_init(name, text_long_name, tiles=[]):
    self = tp.Tp(name, text_long_name)
    # begin sort marker
    my.chance_d1000_appearing(self, 100)
    my.collision_hit_priority(self, 2)
    my.dmg_chance_d1000_crush(self, 0, 1000)
    my.dmg_crush_dice(self, "1d6")
    my.gfx_ascii_show_light_once_seen(self, True)
    my.gfx_ascii_shown_as_gray_in_shadow(self, True)
    my.gfx_ascii_shown_in_bg(self, True)
    my.gfx_ascii_shown(self, True)
    my.gfx_glows(self, True)
    my.gfx_pixelart_animated_can_hflip(self, True)
    my.gfx_pixelart_animated(self, True)
    my.gfx_pixelart_flickers(self, True)
    my.gfx_pixelart_oversized_and_on_floor(self, True)
    my.gfx_pixelart_reflection(self, True)
    my.gfx_pixelart_shadow(self, True)
    my.gfx_pixelart_shadow_short(self, True)
    my.gfx_pixelart_show_highlighted(self, True)
    my.gfx_pixelart_show_outlined(self, True)
    my.gfx_pixelart_submergible(self, True)
    my.is_able_to_fall(self, True)
    my.is_biome_chasms(self, True)
    my.is_biome_dungeon(self, True)
    my.is_biome_ice(self, True)
    my.is_biome_lava(self, True)
    my.is_brazier(self, True)
    my.is_corpse_on_death(self, True)
    my.is_cursor_path_blocker(self, True)
    my.is_dead_on_shove(self, True)
    my.is_described_in_leftbar(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_fire(self, True)
    my.is_floor_deco(self, True)
    my.is_heavy(self, True)
    my.is_immune_to_fire(self, True)
    my.is_interesting(self, True)  # so it can be shoved
    my.is_loggable(self, True)
    my.is_moveable(self, True)
    my.is_obs_ai(self, True)
    my.is_obs_shooting(self, True)
    my.is_obs_throwing(self, True)
    my.is_one_per_tile(self, True)
    my.is_shovable(self, True)
    my.is_tickable(self, True)
    my.light_color(self, "orange")
    my.light_dist(self, 2)
    my.normal_placement_rules(self, True)
    my.spawn_on_shoved(self, "fire")
    my.temperature(self, 100)
    my.text_a_or_an(self, "a")
    my.text_description_short(self, "A beacon of light in this blighted place.")
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_BARREL)
    # end sort marker

    delay = 60
    for t in tiles:
        colors = ["yellow", "red", "orange", "orange", "yellow", "white"]
        color = random.choice(colors)
        my.tile(self,
                ascii_fg_char="currency_sign", ascii_bg_col_name="", ascii_fg_col_name=color,
                tile=t, delay_ms=delay)

    my.tile(self,
            ascii_fg_char="currency_sign", ascii_bg_col_name="", ascii_fg_col_name="darkgray",
            tile=name + ".dead", is_dead=True, delay_ms=delay)

    my.tp_update(self)


def init():
    tp_init(
        name="brazier",
        text_long_name="brazier",
        tiles=[
            "brazier.1",
            "brazier.2",
            "brazier.3",
            "brazier.4",
            "brazier.5",
            "brazier.6",
            "brazier.7",
            "brazier.8",
            "brazier.9",
            "brazier.10",
            "brazier.11",
            "brazier.12",
            "brazier.13",
            "brazier.14",
            "brazier.15",
            "brazier.16",
            "brazier.17",
            "brazier.18",
            "brazier.19",
            "brazier.20",
            "brazier.21",
            "brazier.22",
            "brazier.23",
            "brazier.24",
            "brazier.25",
            "brazier.26",
            "brazier.27",
            "brazier.28",
            "brazier.29",
            "brazier.30",
            "brazier.31",
            "brazier.32",
            "brazier.33",
            "brazier.34",
            "brazier.35",
            "brazier.36",
            "brazier.37",
        ],
    )


init()
