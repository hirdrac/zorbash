import my
import tp
import skill_double_strike0

self = None


def on_tick_when_activated(owner, skill, x, y):
    if owner and my.pcg_randint(1, 100) < 10:
        my.thing_stamina_decr(owner, 1)
    return False  # didn't do anything


def on_use(owner, skill, target, x, y):
    attack = my.thing_attack_num_get(owner)
    if attack == 0:
        return

    my.spawn_using_items_radius_range(owner, skill, target, "skill_double_strike_effect")

    dmg = my.thing_dmg_current(owner)
    dmg = int(dmg / 100) * 30
    if (dmg == 0):
        dmg = 1
    my.thing_dmg_current_set(owner, dmg)


def tp_init(name, text_long_name, text_short_name):
    global self
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker
    my.dmg_num_of_attacks(self, 2)
    my.skill_replaces(self, "skill_double_strike1")
    my.stat_def_bonus(self, -1)
    my.stat_str_bonus(self, 1)
    my.text_description_long2(self, "The additional attack will be 30 percent of the initial attack.")
    my.text_description_long3(self, "When activated, 10 percent chance of draining stamina by 1 per move.")
    my.text_description_short(self, "Double strike skill.")
    my.text_description_very_short(self, "DbStrike2")
    # end sort marker
    skill_double_strike0.tp_init(self)
    my.tp_update(self)


def init():
    tp_init(name="skill_double_strike2", text_long_name="double strike 2", text_short_name="double attack 2")


init()
