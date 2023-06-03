import my
import tp
import skill_gold_to_health0

self = None


def on_tick_when_activated(owner, skill, x, y):
    # my.topcon("owner  {} {}".format(my.thing_name_get(owner), my.thing_health(owner)))
    # my.topcon("skill  {} {}".format(my.thing_name_get(skill), my.thing_health(skill)))

    if not owner:
        return False  # did nothing

    if my.thing_gold(owner) < 6:
        return False  # did nothing

    if my.thing_health(owner) >= my.thing_health_max(owner):
        return False  # did nothing

    my.thing_gold_decr(owner, 6)
    my.thing_health_incr(owner, 3)
    my.spawn_using_items_radius_range(owner, skill, owner, "skill_gold_to_health_effect")
    my.thing_sound_play_channel(owner, my.CHANNEL_WEAPON, "coindrop")
    return False  # did nothing


def tp_init(name, text_long_name, text_short_name):
    global self
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker
    my.stat_con_bonus(self, 1)
    my.stat_dex_bonus(self, -3)
    my.text_description_long3(self, "Conversion rate is 6 gold per turn to 3 health.")
    my.text_description_very_short(self, "GldToHp 3")
    my.skill_replaces(self, "skill_gold_to_health2")
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.z_prio(self, my.MAP_Z_PRIO_ALWAYS_BEHIND)
    # end sort marker
    skill_gold_to_health0.tp_init(self)
    my.tp_update(self)


def init():
    tp_init(name="skill_gold_to_health3", text_long_name="golden health 3", text_short_name="golden health 3")


init()
