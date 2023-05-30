import my
import tp

self = None


def on_tick_when_activated(owner, skill, x, y):
    # my.topcon("owner  {} {}".format(my.thing_name_get(owner), my.thing_health(owner)))
    # my.topcon("skill  {} {}".format(my.thing_name_get(skill), my.thing_health(skill)))

    if not owner:
        return False  # did nothing

    if my.thing_gold(owner) < 8:
        return False  # did nothing

    if my.thing_health(owner) >= my.thing_health_max(owner):
        return False  # did nothing

    my.thing_gold_decr(owner, 8)
    my.thing_health_incr(owner, 4)
    my.spawn_using_items_radius_range(owner, skill, owner, "skill_gold_to_health_effect")
    my.thing_sound_play_channel(owner, my.CHANNEL_WEAPON, "coindrop")
    return False  # did nothing


def tp_init(name, text_long_name, text_short_name):
    global self
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker
    my.gfx_ascii_shown(self, True)
    my.is_loggable(self, True)
    my.is_skill(self, True)
    my.is_tickable(self, True)
    my.on_tick_when_activated_do(self, "me.on_tick_when_activated()")
    my.skill_base_name(self, "skill_gold_to_health")
    my.skill_replaces(self, "skill_gold_to_health3")
    my.stat_con_bonus(self, 2)
    my.stat_dex_bonus(self, -4)
    my.text_description_long2(self, "When in use, your skin glows radiantly. However you will also feel sluggish and less dextrous.")
    my.text_description_long3(self, "Conversion rate is 10 gold per turn to 5 health.")
    my.text_description_long(self, "With this skill you are able to trans-mutate your hard earned gold into life giving health.")
    my.text_description_short(self, "Golden health skill.")
    my.text_description_very_short(self, "GldToHp 4")
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.z_prio(self, my.MAP_Z_PRIO_ALWAYS_BEHIND)
    # end sort marker
    my.tile(self, tile="skill_gold_to_health_activated")
    my.tile(self, tile="skill_gold_to_health")
    my.tp_update(self)


def init():
    tp_init(name="skill_gold_to_health4", text_long_name="golden health 4", text_short_name="golden health 4")


init()
