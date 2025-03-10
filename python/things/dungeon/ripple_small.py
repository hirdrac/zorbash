import my
import tp


def tp_init(name):
    self = tp.Tp(name, "small ripple", "small ripple")
    # begin sort marker
    my.gfx_ascii_shown(self, True)
    my.gfx_pixelart_animated(self, True)
    my.gfx_pixelart_reflection(self, True)
    my.gfx_pixelart_shadow(self, True)
    my.is_one_per_tile(self, True)
    my.is_removable_if_out_of_slots(self, True)
    my.is_ripple(self, True)
    my.is_tmp_thing(self, True)
    my.noise_on_born(self, 10)
    my.text_a_or_an(self, "a")
    my.text_description_short(self, "A small ripple.")
    my.thing_size(self, my.THING_SIZE_SMALL)
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_ALWAYS_BEHIND)
    # end sort marker

    delay = 25
    my.tile(self,
            ascii_fg_char="middle_dot", ascii_bg_col_name="", ascii_fg_col_name="white",
            tile=name + ".1", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="middle_dot", ascii_bg_col_name="", ascii_fg_col_name="white",
            tile=name + ".2", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="middle_dot", ascii_bg_col_name="", ascii_fg_col_name="white",
            tile=name + ".3", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="middle_dot", ascii_bg_col_name="", ascii_fg_col_name="white",
            tile=name + ".4", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="middle_dot", ascii_bg_col_name="", ascii_fg_col_name="white",
            tile=name + ".5", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="middle_dot", ascii_bg_col_name="", ascii_fg_col_name="white",
            tile=name + ".6", delay_ms=delay)
    my.tile(self,
            ascii_fg_char="middle_dot", ascii_bg_col_name="", ascii_fg_col_name="white",
            tile=name + ".7", delay_ms=delay)
    my.tile(self,
            tile=name + ".8",
            delay_ms=delay,
            is_end_of_anim=True,
            is_dead_on_end_of_anim=True)

    my.tp_update(self)


def init():
    tp_init(name="ripple_small1")
    tp_init(name="ripple_small2")


init()
