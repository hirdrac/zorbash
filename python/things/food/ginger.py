import my
import tp


def tp_init(name, text_long_name, text_short_name):
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker
    my.collision_hit_priority(self, 6)
    my.gfx_ascii_fade_with_dist(self, True)
    my.gfx_ascii_shown(self, True)
    my.gfx_pixelart_reflection(self, True)
    my.gfx_pixelart_shadow(self, True)
    my.gfx_pixelart_shadow_short(self, True)
    my.gfx_pixelart_show_highlighted(self, True)
    my.gfx_pixelart_submergible(self, True)
    my.is_able_to_be_teleported(self, True)
    my.is_able_to_fall(self, True)
    my.is_able_to_freeze(self, True)
    my.is_bag_item(self, True)
    my.is_biome_chasms(self, True)
    my.is_biome_dungeon(self, True)
    my.is_biome_ice(self, True)
    my.is_biome_lava(self, True)
    my.is_burnable(self, True)
    my.is_collectable(self, True)
    my.is_crushable(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_food(self, True)
    my.is_interesting(self, True)
    my.is_item(self, True)
    my.is_loggable(self, True)
    my.is_organic(self, True)
    my.is_throwable(self, True)
    my.is_usable(self, True)
    my.item_height(self, 4)
    my.item_width(self, 4)
    my.noise_on_dropping(self, 1)
    my.normal_placement_rules(self, True)
    my.nutrition_dice(self, "10+1d10")
    my.rarity(self, my.RARITY_COMMON)
    my.text_a_or_an(self, "a")
    my.text_description_long(self, "About the only thing that really does grow natively here. Good anti-inflammatory properties but don't expect it to help with severed limbs!")
    my.text_description_short(self, "Ginger root.")
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_ITEM)
    # end sort marker

    my.tile(self,
            ascii_fg_char=";", ascii_bg_col_name="", ascii_fg_col_name="yellow",
            tile=name, is_hp_100_percent=True)
    my.tp_update(self)


def init():
    tp_init(name="ginger", text_long_name="ginger", text_short_name="ginger")


init()
