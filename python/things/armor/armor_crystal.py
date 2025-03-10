import my
import tp

self = None


def on_enchant(me, x, y):
    owner = my.thing_top_owner_id_get(me)
    if owner and my.thing_is_player(owner):
        my.thing_msg_if_not_dead_or_dying(me, "The armor glows.")
    my.thing_stat_def_bonus_incr(me, 1)


def tp_init(name, text_long_name, text_short_name):
    global self
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker
    my.chance_d10000_damaged(self, 50)
    my.chance_d10000_enchanted(self, 1000)
    my.chance_d10000_runic_class_A(self, 100)
    my.collision_hit_priority(self, 6)
    my.equip_carry_anim(self, "armor_crystal_carry")
    my.gfx_ascii_show_light_once_seen(self, True)
    my.gfx_ascii_shown(self, True)
    my.gfx_pixelart_reflection(self, True)
    my.gfx_pixelart_shadow(self, True)
    my.gfx_pixelart_shadow_short(self, True)
    my.gfx_pixelart_show_highlighted(self, True)
    my.gold_value_dice(self, "2000")
    my.is_able_to_be_equipped(self, True)
    my.is_able_to_be_teleported(self, True)
    my.is_able_to_fall(self, True)
    my.is_armor(self, True)
    my.is_auto_equipped(self, True)
    my.is_bag_item(self, True)
    my.is_biome_chasms(self, True)
    my.is_biome_dungeon(self, True)
    my.is_biome_lava(self, True)
    my.is_biome_swamp(self, True)
    my.is_collectable(self, True)
    my.is_crystalline(self, True)
    my.is_described_in_leftbar(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_droppable(self, True)
    my.is_enchantable(self, True)
    my.is_heavy(self, True)
    my.is_interesting(self, True)
    my.is_item(self, True)
    my.is_loggable(self, True)
    my.is_reflective(self, True)
    my.is_treasure_class_C(self, True)
    my.is_treasure(self, True)
    my.is_treasure_type(self, True)
    my.is_value_defensive(self, 1)
    my.item_height(self, 4)
    my.item_width(self, 4)
    my.light_color(self, "white")
    my.light_dist(self, 2)
    my.noise_on_dropping(self, 10)
    my.normal_placement_rules(self, True)
    my.on_enchant_do(self, "me.on_enchant()")
    my.rarity(self, my.RARITY_RARE)
    my.stat_def_bonus(self, 4)
    my.text_a_or_an(self, "a")
    my.text_description_enchant(self, "+1 DEF")
    my.text_description_long(self, "Crystal armor. Strong, reflective but more fragile than other armors.")
    my.text_description_short(self, "Crystal armor.")
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_ITEM)
    # end sort marker

    my.tile(self,
            ascii_fg_char="[", ascii_bg_col_name="", ascii_fg_col_name="white",
            tile=name)

    my.tp_update(self)


def init():
    tp_init(
        name="armor_crystal",
        text_long_name="crystal armor",
        text_short_name="armor, crystal",
    )


init()
