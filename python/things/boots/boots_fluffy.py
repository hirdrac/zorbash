import my
import tp

self = None


def on_equip(owner, me, x, y):
    if owner and my.thing_is_player(owner):
        my.thing_msg_if_not_dead_or_dying(me, "Your feet are nice and warm!")


def on_unequip(owner, me, x, y):
    if owner and my.thing_is_player(owner):
        my.thing_msg_if_not_dead_or_dying(me, "Your feet are cold again!")


def on_enchant(me, x, y):
    owner = my.thing_top_owner_id_get(me)
    if owner and my.thing_is_player(owner):
        my.thing_msg_if_not_dead_or_dying(me, "The boots become yet more fluffy and quiet.")
    my.thing_noise_incr(me, -10)


def tp_init(name, text_long_name, text_short_name):
    global self
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker
    my.chance_d10000_enchanted(self, 20)
    my.equip_carry_anim(self, "boots_fluffy_carry")
    my.gfx_ascii_shown(self, True)
    my.gfx_pixelart_reflection(self, True)
    my.gfx_pixelart_shadow(self, True)
    my.gfx_pixelart_shadow_short(self, True)
    my.gfx_pixelart_show_highlighted(self, True)
    my.gold_value_dice(self, "50")
    my.health_initial_dice(self, "10")
    my.is_able_to_be_equipped(self, True)
    my.is_able_to_be_teleported(self, True)
    my.is_able_to_fall(self, True)
    my.is_auto_equipped(self, True)
    my.is_bag_item(self, True)
    my.is_biome_chasms(self, True)
    my.is_biome_dungeon(self, True)
    my.is_biome_ice(self, True)
    my.is_biome_lava(self, True)
    my.is_biome_swamp(self, True)
    my.is_boots(self, True)
    my.is_burnable(self, True)
    my.is_collectable(self, True)
    my.is_described_in_leftbar(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_droppable(self, True)
    my.is_enchantable(self, True)
    my.is_interesting(self, True)
    my.is_item(self, True)
    my.is_loggable(self, True)
    my.is_treasure_class_C(self, True)
    my.is_treasure(self, True)
    my.is_treasure_type(self, True)
    my.is_value_defensive(self, 1)
    my.item_height(self, 4)
    my.item_width(self, 4)
    my.noise_additional_on_jump_end(self, -50)
    my.noise_on_dropping(self, -50)
    my.normal_placement_rules(self, True)
    my.on_enchant_do(self, "me.on_enchant()")
    my.on_equip_do(self, "me.on_equip()")
    my.on_unequip_do(self, "me.on_unequip()")
    my.rarity(self, my.RARITY_UNCOMMON)
    my.temperature(self, 50)
    my.text_a_or_an(self, "a")
    my.text_description_enchant(self, "-10 decibels")
    my.text_description_long(self, "Fluffy boots. Keeps your feet warm and lowers your noise footprint. Pun intended.")
    my.text_description_short(self, "Fluffy boots.")
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_BEHIND)
    # end sort marker

    my.tile(self,
            ascii_fg_char="[", ascii_bg_col_name="", ascii_fg_col_name="pink",
            tile=name)

    my.tp_update(self)


def init():
    tp_init(
        name="boots_fluffy",
        text_long_name="fluffy boots",
        text_short_name="boots, fluffy",
    )


init()
