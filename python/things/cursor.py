import zx
import tp


def tp_init(name):
    x = tp.Tp(name)

    x.set_gfx_animated(True)
    x.set_gfx_outlined(True)
    x.set_is_movable(True)
    x.set_is_cursor(True)
    x.set_move_speed_ms(1)
    x.set_z_depth(zx.MAP_DEPTH_CURSOR)

    delay = 50
    x.set_tile(tile=name + ".1", is_dir_none=True, delay_ms=delay)
    x.set_tile(tile=name + ".2", is_dir_none=True, delay_ms=delay)
    x.set_tile(tile=name + ".3", is_dir_none=True, delay_ms=delay)
    x.set_tile(tile=name + ".4", is_dir_none=True, delay_ms=delay)
    x.set_tile(tile=name + ".5", is_dir_none=True, delay_ms=delay)
    x.set_tile(tile=name + ".6", is_dir_none=True, delay_ms=delay)
    x.set_tile(tile=name + ".7", is_dir_none=True, delay_ms=delay)
    x.set_tile(tile=name + ".8", is_dir_none=True, delay_ms=delay)
    x.set_tile(tile=name + ".9", is_dir_none=True, delay_ms=delay)
    x.set_tile(tile=name + ".10", is_dir_none=True, delay_ms=delay)
    x.set_tile(tile=name + ".11", is_dir_none=True, delay_ms=delay)
    x.set_tile(tile=name + ".12", is_dir_none=True, delay_ms=delay)

    x.update()
    
def init():
    tp_init(name="cursor")

init()