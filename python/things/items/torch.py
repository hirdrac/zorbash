import my
import tp


def on_thrown(owner, me, x, y):
    if my.level_is_chasm_at(me, x, y):
        return
    if my.level_is_water_at(me, x, y):
        return
    for it in my.level_get_all(me, x, y):
        if my.thing_is_combustible(it):
            my.spawn_at_my_position(me, "fire")
            return


def on_lifespan_tick(owner, me, x, y):
    if owner and my.thing_is_player(owner):
        my.thing_msg(me, "One of your torches fizzles out.")


def tp_init(name, text_long_name, text_short_name, tiles=[]):
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker
    my.chance_d10000_set_on_fire(self, 2000)
    my.chance_d1000_appearing(self, 100)
    my.charge_count(self, 10)
    my.collision_hit_priority(self, 1)
    my.collision_hit_priority(self, 6)
    my.gfx_ascii_show_light_once_seen(self, True)
    my.gfx_ascii_shown_as_gray_in_shadow(self, True)
    my.gfx_ascii_shown_in_bg(self, True)
    my.gfx_ascii_shown(self, True)
    my.gfx_glows(self, True)
    my.gfx_pixelart_animated(self, True)
    my.gfx_pixelart_flickers(self, True)
    my.gfx_pixelart_reflection(self, True)
    my.gfx_pixelart_shadow(self, True)
    my.gfx_pixelart_shadow_short(self, True)
    my.gfx_pixelart_show_highlighted(self, True)
    my.gfx_pixelart_show_outlined(self, True)
    my.gfx_pixelart_submergible(self, True)
    my.health_initial_dice(self, "30")
    my.is_able_to_be_teleported(self, True)
    my.is_able_to_fall(self, True)
    my.is_bag_item(self, True)
    my.is_biome_chasms(self, True)
    my.is_biome_dungeon(self, True)
    my.is_biome_ice(self, True)
    my.is_biome_lava(self, True)
    my.is_burnable(self, True)
    my.is_collectable(self, True)
    my.is_described_in_leftbar(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_droppable(self, True)
    my.is_hittable(self, True)
    my.is_interesting(self, True)
    my.is_item(self, True)
    my.is_loggable(self, True)
    my.is_throwable(self, True)
    my.is_tickable(self, True)  # for pushing and falling
    my.is_torch(self, True)
    my.is_treasure_class_A(self, True)
    my.is_treasure(self, True)
    my.is_treasure_type(self, True)
    my.is_wooden(self, True)
    my.item_height(self, 4)
    my.item_width(self, 4)
    my.lifespan_dice(self, "1d300+100")
    my.light_color(self, "orange")
    my.light_dist(self, 1)
    my.noise_on_dropping(self, 1)
    my.normal_placement_rules(self, True)
    my.on_lifespan_tick_do(self, "me.on_lifespan_tick()")
    my.on_thrown_do(self, "me.on_thrown()")
    my.temperature(self, 50)
    my.text_a_or_an(self, "a")
    my.text_description_long(self, "A bundle of torches to light the way. Be warned, they do burn out slowly. Don't find yourself lost in the dark...")
    my.text_description_short(self, "A small beacon of light in this blighted place.")
    my.tick_prio(self, my.MAP_TICK_PRIO_NORMAL)
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_ALWAYS_BEHIND)
    # end sort marker

    delay = 100
    for t in tiles:
        my.tile(self,
                ascii_fg_char="(", ascii_bg_col_name="", ascii_fg_col_name="orange",
                tile=t, delay_ms=delay)

    my.tp_update(self)


def init():
    tp_init(name="torch", text_long_name="torch", text_short_name="torch",
            tiles=[
                "torch.1",
                "torch.2",
                "torch.3",
                "torch.4",
                "torch.5",
                "torch.6",
            ])


init()
