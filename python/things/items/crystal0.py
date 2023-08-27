import my


def tp_init(self):
    # begin sort marker
    my.gfx_ascii_fade_with_dist(self, True)
    my.gfx_ascii_shown(self, True)
    my.gfx_pixelart_animated(self, True)
    my.gfx_pixelart_bounce_on_move(self, True)
    my.gfx_pixelart_flickers(self, True)
    my.gfx_pixelart_oversized_and_on_floor(self, True)
    my.gfx_pixelart_reflection(self, True)
    my.gfx_pixelart_shadow(self, True)
    my.gfx_pixelart_shadow_short(self, True)
    my.gfx_pixelart_show_highlighted(self, True)
    my.gfx_pixelart_show_outlined(self, True)
    my.gfx_pixelart_submergible(self, True)
    my.is_able_to_be_teleported(self, True)
    my.is_able_to_fall(self, True)
    my.is_bag_item(self, True)
    my.is_collectable(self, True)
    my.is_crystal(self, True)
    my.is_described_in_leftbar(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_droppable(self, True)
    my.is_interesting(self, True)
    my.is_item(self, True)
    my.is_loggable(self, True)
    my.is_moveable(self, True)
    my.item_height(self, 3)
    my.item_width(self, 3)
    my.light_color(self, "white")
    my.light_dist(self, 1)
    my.noise_on_dropping(self, 25)
    my.temperature_never_changes(self, True)
    my.text_a_or_an(self, "a")
    my.text_description_long3(self, "Collecting all 7 crystals will unlock the final door that leads back to the surface world.")
    my.text_description_long4(self, "Each crystal will bestow different ability bonuses. Collect them all for maximum power!")
    my.text_description_short(self, "Magical crystal I.")
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_BEHIND)
    # end sort marker
