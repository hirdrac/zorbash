import my
import tp

self = None


def on_enchant(me, x, y):
    owner = my.thing_top_owner_id_get(me)
    if my.thing_is_player(owner):
        my.thing_msg(me, "The shield shines a woody wood color.")
    my.thing_stat_def_mod_incr(me, 1)


def tp_init(name, text_long_name, text_short_name):
    global self
    self = tp.Tp(name, text_long_name, text_short_name)
    # start sort marker
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.gfx_ascii_shown(self, True)
    my.damaged_chance_d10000(self, 20)
    my.enchant_max(self, 5)
    my.equip_carry_anim(self, "shield_wooden_carry")
    my.gfx_pixelart_shadow_short(self, True)
    my.gold_value_dice(self, "10")
    my.is_able_to_fall(self, True)
    my.is_shield(self, True)
    my.is_auto_equipped(self, True)
    my.is_bag_item(self, True)
    my.is_collectable(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_biome_dungeon(self, True)
    my.is_able_to_burn(self, True)
    my.is_droppable(self, True)
    my.is_enchantable(self, True)
    my.is_wooden(self, True)
    my.is_interesting(self, True)
    my.noise_on_dropping(self, 25)
    my.is_item(self, True)
    my.collision_hit_priority(self, 6)
    my.is_biome_dungeon(self, True)
    my.is_loggable(self, True)
    my.is_treasure_class_a(self, True)
    my.is_biome_dungeon(self, True)
    my.is_treasure(self, True)
    my.is_biome_dungeon(self, True)
    my.is_treasure_type(self, True)
    my.is_biome_dungeon(self, True)
    my.item_height(self, 4)
    my.item_width(self, 4)
    my.text_long_description(self, "An actual, very rare, wooden shield! I know, I can hardly believe it myself. Gives a staggering +1 to defense.")
    my.normal_placement_rules(self, True)
    my.on_enchant_do(self, "me.on_enchant()")
    my.rarity(self, my.RARITY_COMMON)
    my.stat_def_mod(self, 1)
    my.text_a_or_an(self, "a")
    my.text_short_description(self, "Wooden shield.")
    my.text_enchant(self, "+1 DEF")
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_BEHIND)
    # end sort marker

    my.tile(self,
            ascii_fg_char="[", ascii_bg_col_name="", ascii_fg_col_name="white",
            tile=name)

    my.tp_update(self)


def init():
    tp_init(name="shield_wooden", text_long_name="wooden shield", text_short_name="shield, wood")


init()