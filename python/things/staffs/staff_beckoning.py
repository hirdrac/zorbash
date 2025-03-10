import my
import tp


def on_targeted(me, x, y):
    owner = my.thing_top_owner_id_get(me)
    if not owner:
        return

    for it in my.level_get_all(me, x, y):
        if my.thing_is_moveable(it):
            for i in range(0, my.thing_enchant_count_get(me) + 1):
                my.thing_beckon(owner, it)


def on_idle(me, x, y):
    #
    # Random recharge
    #
    if my.thing_charge_count(me) < my.thing_initial_charge_count(me):
        my.thing_charge_count_incr(me, 1)
        owner = my.thing_top_owner_id_get(me)
        if owner and my.thing_is_player(owner):
            my.thing_msg(me, f"%%fg=orange$The {my.thing_name_get(me)} pulses.%%fg=reset$")


def explode(me, x, y):
    if my.thing_charge_count(me) == 0:
        return

    if my.thing_is_dead(me):
        return

    owner = my.thing_top_owner_id_get(me)
    if owner:
        if my.thing_is_player(owner):
            my.thing_msg(me, "Your staff of beckoning explodes.")
        else:
            my.thing_msg(me, f"The {my.thing_name_get(owner)}'s staff of beckoning explodes.")
    else:
        my.thing_msg(me, "The staff of beckoning explodes.")

    my.spawn_at_my_position(me, "explosion_major")
    on_targeted(me, x, y)
    my.thing_dead(me, "exploded")


def on_hit_and_now_dead(me, hitter, real_hitter, x, y, crit, damage):
    explode(me, x, y)


def on_fall(me, x, y):
    explode(me, x, y)


def tp_init(name, text_long_name, text_short_name):
    self = tp.Tp(name, text_long_name, text_short_name)
    # begin sort marker
    my.chance_d10000_set_on_fire(self, 5000)
    my.charge_count(self, 5)
    my.collision_hit_priority(self, 6)
    my.dmg_num_of_attacks(self, 0)
    my.environ_dislikes_fire(self, 100)
    my.equip_carry_anim(self, "staff_beckoning_carry")
    my.gfx_ascii_fade_with_dist(self, True)
    my.gfx_ascii_shown(self, True)
    my.gfx_pixelart_animated(self, True)
    my.gfx_pixelart_reflection(self, True)
    my.gfx_pixelart_shadow(self, True)
    my.gfx_pixelart_shadow_short(self, True)
    my.gfx_pixelart_show_highlighted(self, True)
    my.gfx_targeted_laser(self, "laser_magic_effect")
    my.gold_value_dice(self, "300")
    my.health_initial_dice(self, "20+1d10")
    my.is_able_to_be_reflected(self, True)
    my.is_able_to_be_teleported(self, True)
    my.is_able_to_fall(self, True)
    # my.is_able_to_spawn_things(self, False) else we end up owning blades
    my.is_bag_item(self, True)
    my.is_biome_chasms(self, True)
    my.is_biome_dungeon(self, True)
    my.is_biome_ice(self, True)
    my.is_biome_lava(self, True)
    my.is_biome_swamp(self, True)
    my.is_burnable(self, True)
    my.is_collectable(self, True)
    my.is_combustible(self, True)
    my.is_crushable(self, True)
    my.is_described_in_leftbar(self, True)
    my.is_described_when_hovering_over(self, True)
    my.is_droppable(self, True)
    my.is_interesting(self, True)
    my.is_item(self, True)
    my.is_loggable(self, True)
    my.is_magical(self, True)
    my.is_staff(self, True)
    my.is_target_select(self, True)
    my.is_throwable(self, True)
    my.is_tickable(self, True)
    my.is_treasure_class_B(self, True)
    my.is_treasure(self, True)
    my.is_treasure_type(self, True)
    my.is_usable(self, True)
    my.is_value_offensive(self, 1)
    my.is_wooden(self, True)
    my.item_height(self, 4)
    my.item_width(self, 4)
    my.noise_on_dropping(self, 5)
    my.normal_placement_rules(self, True)
    my.on_fall_do(self, "me.on_fall()")
    my.on_hit_and_now_dead_do(self, "me.on_hit_and_now_dead()")
    my.on_idle_tick_freq_dice(self, "1d200+200:me.on_idle()")
    my.on_targeted_do(self, "me.on_targeted()")
    my.range_max(self, 7)
    my.temperature(self, 20)
    my.text_a_or_an(self, "a")
    my.text_description_long(self, "This staff will beckon an unwitting recipient towards you. It would be a shame if there was a chasm in the way...")
    my.text_description_short(self, "A staff of beckoning.")
    my.tick_prio(self, my.MAP_TICK_PRIO_LOW)
    my.z_depth(self, my.MAP_DEPTH_OBJ)
    my.z_prio(self, my.MAP_Z_PRIO_BEHIND)
    # end sort marker

    my.tile(self,
            ascii_fg_char="/", ascii_bg_col_name="", ascii_fg_col_name="red",
            tile=name + ".1", delay_ms=100)
    my.tile(self,
            ascii_fg_char="/", ascii_bg_col_name="", ascii_fg_col_name="red",
            tile=name + ".2", delay_ms=100)
    my.tile(self,
            ascii_fg_char="/", ascii_bg_col_name="", ascii_fg_col_name="red",
            tile=name + ".3", delay_ms=100)
    my.tile(self,
            ascii_fg_char="/", ascii_bg_col_name="", ascii_fg_col_name="red",
            tile=name + ".4", delay_ms=100)
    my.tile(self,
            ascii_fg_char="/", ascii_bg_col_name="", ascii_fg_col_name="red",
            tile=name + ".5", delay_ms=100)
    my.tile(self,
            ascii_fg_char="/", ascii_bg_col_name="", ascii_fg_col_name="red",
            tile=name + ".6", delay_ms=100)

    my.tp_update(self)


def init():
    tp_init(name="staff_beckoning", text_long_name="staff of beckoning", text_short_name="staff, beckoning")


init()
