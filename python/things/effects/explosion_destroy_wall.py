import my
import tp


def on_born(me, x, y):
    my.thing_sound_play_channel(me, my.CHANNEL_EXPLOSION, "explosion_e")
    my.if_matches_then_dead(me, "is_wall", x, y)
    my.if_matches_then_dead(me, "is_rock", x, y)
    my.if_matches_then_dead(me, "is_door", x, y)
    my.if_matches_then_dead(me, "is_block_of_crystal", x, y)
    my.if_matches_then_dead(me, "is_block_of_ice", x, y)
    my.if_matches_then_dead(me, "is_turret", x, y)
    my.if_matches_then_dead(me, "is_mob", x, y)


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
            ascii_bg_char="block", ascii_bg_col_name="orange", ascii_fg_col_name="",
            tile="nothing")
    my.tile(self,
            ascii_bg_char="block", ascii_bg_col_name="orange", ascii_fg_col_name="",
            tile="explosion_fire.1", delay_ms=delay)
    my.tile(self,
            ascii_bg_char="block", ascii_bg_col_name="orange", ascii_fg_col_name="",
            tile="explosion_fire.2", delay_ms=delay)
    my.tile(self,
            ascii_bg_char="block", ascii_bg_col_name="orange", ascii_fg_col_name="",
            tile="explosion_fire.3", delay_ms=delay)
    my.tile(self,
            ascii_bg_char="block", ascii_bg_col_name="orange", ascii_fg_col_name="",
            tile="explosion_fire.4",
            delay_ms=delay,
            is_end_of_anim=True,
            is_dead_on_end_of_anim=True)

    my.tp_update(self)


def init():
    tp_init(name="explosion_destroy_wall",
            text_long_name="earthquake",
            text_short_name="earthquake")


init()
