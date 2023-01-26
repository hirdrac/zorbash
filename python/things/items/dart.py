import my
import tp


def on_thrown(owner, me, x, y):
    for it in my.level_get_all(me, x, y):
        if my.thing_is_interesting(it):
            if it == me:
                continue
            my.thing_hit_dmg_missile(owner, me, it, thrown=True)


def tp_init(name, text_long_name, text_short_name):
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker
    my.appearing_chance_d1000(self, 10)
    my.dmg_missile_chance_d1000(self, 0, 1000)
    my.dmg_missile_dice(self, "1d4")
    my.gfx_ascii_fade_with_dist(self, True)
    my.gfx_ascii_shown(self, True)
    my.gfx_pixelart_show_highlighted(self, True)
    my.gfx_pixelart_submergable(self, True)
    my.is_able_to_fall(self, True)
    my.is_bag_item(self, True)
    my.is_biome_dungeon(self, True)
    my.is_biome_swamp(self, True)
    my.is_collectable(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_droppable(self, True)
    my.is_enchantable(self, True)
    my.is_interesting(self, True)
    my.is_item(self, True)
    my.is_loggable(self, True)
    my.is_missile(self, True)
    my.is_moveable(self, True)
    my.is_throwable(self, True)
    my.is_thrown_as_a_weapon(self, True)
    my.is_treasure_class_a(self, True)
    my.is_treasure(self, True)
    my.is_treasure_type(self, True)
    my.item_height(self, 2)
    my.item_width(self, 2)
    my.noise_on_dropping(self, 1)
    my.normal_placement_rules(self, True)
    my.on_thrown_do(self, "me.on_thrown()")
    my.rarity(self, my.RARITY_COMMON)
    my.target_name_projectile(self, "projectile_dart")
    my.text_a_or_an(self, "a")
    my.text_description_long(self, "The gentle person's melee weapon.")
    my.text_description_short(self, "A small dart.")
    my.thing_size(self, my.THING_SIZE_TINY)
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_BEHIND)
    # end sort marker

    my.tile(self,
            ascii_fg_char="'", ascii_bg_col_name="", ascii_fg_col_name="gray90",
            tile=name, delay_ms=100)

    my.tp_update(self)


def init():
    tp_init(name="dart", text_long_name="dart", text_short_name="dart")


init()