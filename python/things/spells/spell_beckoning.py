import my
import tp


def on_use(owner, item, target, x, y):
    # my.topcon("owner  {} {}".format(my.thing_name_get(owner), my.thing_health(owner)))
    # my.topcon("item   {} {}".format(my.thing_name_get(item), my.thing_health(item)))
    # my.topcon("target {} {}".format(my.thing_name_get(target), my.thing_health(target)))
    return


def tp_init(name, text_long_name, text_short_name):
    global self
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker
    my.is_loggable(self, True)
    my.is_spell(self, True)
    my.is_spell_beckoning(self, True)
    my.is_target_select(self, True)
    my.is_usable(self, True)
    my.on_use_do(self, "me.on_use()")
    my.range_max(self, 7)
    my.gfx_targeted_projectile(self, "projectile_magical_effect")
    my.spell_base_name(self, name)
    my.spell_cost(self, 2)
    my.text_a_or_an(self, "a")
    my.text_description_long(self, "The target of this spell will be drawn towards you.")
    my.text_description_long2(self, "It would be a shame if there was a chasm in the way.")
    my.text_description_short(self, "Spell, beckoning.")
    my.text_description_very_short(self, "Beckon")
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_BEHIND)
    # end sort marker

    my.tile(self, tile="spell_beckoning")
    my.tile(self, tile="spell_beckoning_activated")
    my.tp_update(self)


def init():
    tp_init(name="spell_beckoning", text_long_name="beckoning", text_short_name="beckoning")


init()
