import my
import tp
import skill_healing0

self = None


def on_tick_when_activated(owner, skill, x, y):
    # my.topcon("owner  {} {}".format(my.thing_name_get(owner), my.thing_health(owner)))
    # my.topcon("skill  {} {}".format(my.thing_name_get(skill), my.thing_health(skill)))

    if not owner:
        return False  # did nothing

    if my.thing_stamina(owner) < 8:
        return False  # did nothing

    if my.thing_health(owner) >= my.thing_health_max(owner):
        return False  # did nothing

    my.thing_stamina_decr(owner, 8)
    my.thing_health_incr(owner, 4)
    return False  # did nothing


def tp_init(name, text_long_name, text_short_name):
    global self
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker
    my.skill_replaces(self, "skill_healing3")
    my.stat_con_bonus(self, 4)
    my.text_description_long2(self, "Conversion rate is 8 stamina per turn to 4 health.")
    my.text_description_very_short(self, "AccHeal 4")
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.z_prio(self, my.MAP_Z_PRIO_ALWAYS_BEHIND)
    # end sort marker
    skill_healing0.tp_init(self)
    my.tp_update(self)


def init():
    tp_init(name="skill_healing4", text_long_name="accelerated health 4", text_short_name="accelerated health 4")


init()
