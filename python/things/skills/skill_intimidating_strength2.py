import my
import tp
import skill_intimidating_strength0

self = None


def tp_init(name, text_long_name, text_short_name):
    global self
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker
    my.shove_bonus(self, 2)
    my.skill_replaces(self, "skill_intimidating_strength1")
    my.stat_att_bonus(self, 2)
    my.stat_str_bonus(self, 3)
    my.text_description_very_short(self, "IntimStr2")
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.z_prio(self, my.MAP_Z_PRIO_ALWAYS_BEHIND)
    # end sort marker
    skill_intimidating_strength0.tp_init(self)
    my.tp_update(self)


def init():
    tp_init(name="skill_intimidating_strength2", text_long_name="intimidating strength 2", text_short_name="intimidating strength 2")


init()
