import my
import tp


def on_born(me, x, y):
    my.thing_sound_play_channel(me, my.CHANNEL_EXPLOSION, "explosion_e")

    if my.level_is_floor_at(me, x, y) or\
       my.level_is_dirt_at(me, x, y) or\
       my.level_is_corridor_at(me, x, y):
        if my.level_is_bridge_at(me, x + 1, y):
            my.place_at(me, "explosion_destroy_floor", x + 1, y)
        if my.level_is_bridge_at(me, x - 1, y):
            my.place_at(me, "explosion_destroy_floor", x - 1, y)
        if my.level_is_bridge_at(me, x, y + 1):
            my.place_at(me, "explosion_destroy_floor", x, y + 1)
        if my.level_is_bridge_at(me, x, y - 1):
            my.place_at(me, "explosion_destroy_floor", x, y - 1)

    my.if_matches_then_dead(me, "is_floor", x, y)
    my.if_matches_then_dead(me, "is_bridge", x, y)
    my.if_matches_then_dead(me, "is_corridor", x, y)
    my.if_matches_then_dead(me, "is_dirt", x, y)
    my.place_at(me, "chasm1", x, y)


def tp_init(name, text_long_name, text_short_name):
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker
    my.gfx_ascii_shown(self, True)
    my.gfx_pixelart_animated(self, True)
    my.gfx_pixelart_reflection(self, True)
    my.gfx_pixelart_shadow(self, True)
    my.gfx_pixelart_shadow_short(self, True)
    my.gfx_pixelart_show_outlined(self, True)
    my.is_explosion(self, True)
    my.is_floating(self, True)
    my.is_loggable(self, True)
    my.is_one_per_tile(self, True)
    my.noise_on_born(self, 100)
    my.on_born_do(self, "me.on_born()")
    my.text_hits(self, "blasts")
    my.tick_prio(self, my.MAP_TICK_PRIO_VERY_HIGH)
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_EFFECT)
    # end sort marker

    delay = 50
    my.tile(self,
            ascii_bg_char="block", ascii_bg_col_name="cyan", ascii_fg_col_name="",
            tile="nothing")
    my.tile(self,
            ascii_bg_char="block", ascii_bg_col_name="cyan", ascii_fg_col_name="",
            tile="explosion_fire.1", delay_ms=delay)
    my.tile(self,
            ascii_bg_char="block", ascii_bg_col_name="cyan", ascii_fg_col_name="",
            tile="explosion_fire.2", delay_ms=delay)
    my.tile(self,
            ascii_bg_char="block", ascii_bg_col_name="cyan", ascii_fg_col_name="",
            tile="explosion_fire.3", delay_ms=delay)
    my.tile(self,
            ascii_bg_char="block", ascii_bg_col_name="cyan", ascii_fg_col_name="",
            tile="explosion_fire.4",
            delay_ms=delay,
            is_end_of_anim=True,
            is_dead_on_end_of_anim=True)

    my.tp_update(self)


def init():
    tp_init(name="explosion_destroy_floor",
            text_long_name="earthquake",
            text_short_name="earthquake")


init()
