import my
import tp

self = None


def on_owner_add(me, owner, x, y):
    if my.thing_is_player(owner):
        my.thing_msg(me, "You are on fire!")


# Called on removing a ring. Not called on death of the owner.
def on_owner_unset(me, owner, x, y):
    if my.thing_is_player(owner):
        my.thing_msg(me, "You are fire proof!")
    my.thing_buff_add(owner, "buff_permanent_immune_to_fire")


def on_tick(owner, item, x, y):
    roll = my.py_d100()
    if roll < 25:
        my.thing_stamina_decr(owner, 1)
    return True


def tp_init(name, text_long_name, text_short_name):
    global self
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker

    my.gfx_ascii_shown(self, True)
    my.is_buff(self, True)
    my.is_loggable(self, True)
    my.is_runic(self, True)
    my.is_tickable(self, True)
    my.lifespan_dice(self, "1d10+10")
    my.move_speed_bonus(self, 100)
    my.on_owner_add_do(self, "me.on_owner_add()")
    my.on_owner_unset_do(self, "me.on_owner_unset()")
    my.on_tick_do(self, "me.on_tick()")
    my.text_description_long(self, "You are on fire! Should you survive this, you'll be tougher.")
    my.text_description_short(self, "You are on fire!")
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.z_prio(self, my.MAP_Z_PRIO_ALWAYS_BEHIND)
    # end sort marker
    my.tile(self,
            tile="small_fire.1")
    my.tp_update(self)


def init():
    tp_init(name="buff_temporary_immolation", text_long_name="immolation", text_short_name="immolation")


init()