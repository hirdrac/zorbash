import my
import tp

self = None


def on_tick_when_activated(owner, skill, x, y):
    if owner and my.pcg_randint(1, 100) < 10:
        my.thing_stamina_decr(owner, 1)
    return False  # didn't do anything


def on_use(owner, skill, target, x, y):
    my.spawn_using_items_radius_range(owner, skill, target, "skill_devoted_thrust_effect")
    bonus = int(my.thing_stamina(owner) / 10) * 3

    if bonus > 1:
        if my.thing_is_player(owner):
            my.thing_msg(owner, f"%%fg=yellow$You strike with a mighty thrust of {bonus} additional damage.%%fg=reset$")
        my.thing_dmg_current_incr(owner, bonus)
    else:
        if my.thing_is_player(owner):
            my.thing_msg(owner, "You run out of devotion.")
        my.thing_skill_deactivate(owner, skill)


def tp_init(name, text_long_name, text_short_name):
    global self
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker

    my.gfx_ascii_shown(self, True)
    my.is_loggable(self, True)
    my.is_skill(self, True)
    my.is_tickable(self, True)
    my.on_tick_when_activated_do(self, "me.on_tick_when_activated()")
    my.on_use_do(self, "me.on_use()")
    my.skill_base_name(self, "skill_devoted_thrust")
    my.skill_replaces(self, "skill_devoted_thrust1")
    my.stat_def_bonus(self, -1)
    my.stat_str_bonus(self, 1)
    my.text_description_long2(self, "Uses 30 percent of your stamina points up in one mighty strike.")
    my.text_description_long2(self, "When activated, 10 percent chance of draining stamina.")
    my.text_description_long(self, "Prove your devotion to the gods by sacrificing your stamina in exchange for vanquishing damage.")
    my.text_description_short(self, "Devoted thrust skill.")
    my.text_description_very_short(self, "DevtThr 2")
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.z_prio(self, my.MAP_Z_PRIO_ALWAYS_BEHIND)
    # end sort marker
    my.tile(self, tile="skill_devoted_thrust_activated")
    my.tile(self, tile="skill_devoted_thrust")
    my.tp_update(self)


def init():
    tp_init(name="skill_devoted_thrust2", text_long_name="devoted thrust 2", text_short_name="devoted thrust 2")


init()
