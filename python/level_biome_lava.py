import my

#
# entrance rooms
#
my.map_load_room(
    biome_lava=True,
    entrance=True,
    room_data=[
        "           ", "           ", "       .   ", "       ^   ", "       ^   ",
        "           ", " ..  .     ", "     ..    ", "  ..   .   ", " .     .   ",
        "     .     ", "   .  . .  ", "  .. .  .  ", "   ... .   ", "  .  . .   ",
        "   ......  ", " .......   ", "<.......   ", "<....... . ", "   .....   ",
        "  ......   ", "   ......  ", " . ......  ", "  .......  ", "   ..... . ",
        "  ...S...  ", "   ..S.... ", "  ...S..   ", "   ..S...  ", " . ..S.... ",
        "   .....   ", " . .....   ", "   ......  ", "  ......   ", " .......   ",
        "  ........>", "  .......> ", " .........>", " . .......>", "  .......  ",
        " .  ..  .  ", "   . .     ", "  ...   .  ", "   .  . .  ", " . .  .    ",
        "     ..    ", "   .       ", "   .   .   ", "   .    .  ", "   .  .    ",
        "           ", "   v       ", "   v       ", "   v       ", "   v       ",
    ],
)

#
# exit rooms
#
my.map_load_room(
    biome_lava=True,
    exit=True,
    room_data=[
        "           ", "           ", "       .   ", "       ^   ", "       ^   ",
        "           ", " ..  .     ", "     ..    ", "  ..   .   ", " .     .   ",
        "     .     ", "   .  . .  ", "  .. .  .  ", "   ... .   ", "  .  . .   ",
        "   ......  ", " .......   ", "<.......   ", "<....... . ", "   .....   ",
        "  ..LLL.   ", "   ..L...  ", " . ...L..  ", "  ..LLL..  ", "   ..... . ",
        "  ..LEL..  ", "   .LEL... ", "  ..LEL.   ", "   .LE...  ", " . ..E.... ",
        "   .LLL.   ", " . ..L..   ", "   .LLL..  ", "  ..L...   ", " .......   ",
        "  ........>", "  .......> ", " .........>", " . .......>", "  .......  ",
        " .  ..  .  ", "   . .     ", "  ...   .  ", "   .  . .  ", " . .  .    ",
        "     ..    ", "   .       ", "   .   .   ", "   .    .  ", "   .  .    ",
        "           ", "   v       ", "   v       ", "   v       ", "   v       ",
    ],
)

#
# lock rooms
#
my.map_load_room(
    biome_lava=True,
    lock=True,
    room_data=[
        "           ", "           ", "           ", "       ^   ", "       ^   ",
        "      .    ", "   .       ", "      .    ", "       .   ", "       .   ",
        "   . .  .. ", "    .. . . ", "    .. . . ", "     . L   ", "    .  L   ",
        " . .....   ", "  ......   ", "<.L......  ", "<.L.....   ", "   .....   ",
        "  .......  ", "  .......  ", "   ....... ", "   ......  ", "  .......  ",
        "   .....   ", " . ......  ", "  ......   ", " ....... . ", " ........  ",
        "  ......   ", "  ......   ", " . .....   ", "   .....   ", " . .....   ",
        "   .....L.>", "   .....L.>", "   .....L.>", "   .....L.>", "   ......  ",
        " .  ..     ", "   L       ", "   L       ", "   L .     ", "   L   ..  ",
        "    .      ", "   .       ", "   .       ", "   .       ", "   .       ",
        "           ", "   v       ", "   v       ", "   v       ", "   v       ",
    ],
)

#
# key rooms
#
my.map_load_room(
    biome_lava=True,
    key=True,
    room_data=[
        "           ", "           ", "           ", "       ^   ", "       ^   ",
        "      .    ", "   .       ", "      .    ", "       .   ", "       .   ",
        "   . .  .. ", "    .. . . ", "    .. . . ", "     . L   ", "    .  L   ",
        " . .....   ", "  ......   ", "<.L......  ", "<.L.....   ", "   .....   ",
        "  .......  ", "  ...k...  ", "   ....... ", "   ......  ", "  ....k..  ",
        "   ..k..   ", " . ......  ", "  ...k..   ", " ....k.. . ", " ........  ",
        "  ......   ", "  ......   ", " . .....   ", "   .....   ", " . .....   ",
        "   .....L.>", "   .....L.>", "   .....L.>", "   .....L.>", "   ......  ",
        " .  ..     ", "   L       ", "   L       ", "   L .     ", "   L   ..  ",
        "    .      ", "   .       ", "   .       ", "   .       ", "   .       ",
        "           ", "   v       ", "   v       ", "   v       ", "   v       ",
    ],
)

#
# depth 1 rooms
#
my.map_load_room(
    biome_lava=True,
    depth=1,
    room_data=[
        "           ", "           ", "           ", "       ^   ", "       ^   ",
        "      .    ", "   .       ", "      .    ", "       .   ", "       .   ",
        "   . .  .. ", "    .. . . ", "    .. . . ", "     . m   ", "    .  m   ",
        " . .....   ", "  .g....   ", "<.m......  ", "<.m.....   ", "   .....   ",
        "  .......  ", "  .......  ", "   ....... ", "   ......  ", "  .......  ",
        "   .g...   ", " . ......  ", "  ...g..   ", " ....g.. . ", " ....g...  ",
        "  ......   ", "  ......   ", " . .....   ", "   .....   ", " . .....   ",
        "   .....m.>", "   .....m.>", "   .....m.>", "   .....m.>", "   ......  ",
        " .  ..     ", "   m       ", "   m       ", "   m .     ", "   m   ..  ",
        "    .      ", "   .       ", "   .       ", "   .       ", "   .       ",
        "           ", "   v       ", "   v       ", "   v       ", "   v       ",
    ],
)

#
# depth 2 rooms
#
my.map_load_room(
    biome_lava=True,
    depth=2,
    room_data=[
        "           ", "           ", "           ", "       ^   ", "       ^   ",
        "      .    ", "   .       ", "      .    ", "       .   ", "       .   ",
        "   . .  .. ", "    .. . . ", "    .. . . ", "     . m   ", "    .  m   ",
        " . .....   ", "  ......   ", "<.M......  ", "<.M.....   ", "   .....   ",
        "  .......  ", "  .......  ", "   ....... ", "   ......  ", "  .......  ",
        "   .....   ", " . ......  ", "  ......   ", " ....... . ", " ........  ",
        "  ......   ", "  ......   ", " . .....   ", "   .....   ", " . .....   ",
        "   .....M.>", "   .....M.>", "   .....M.>", "   .....M.>", "   ......  ",
        " .  ..     ", "   M       ", "   M       ", "   M .     ", "   M   ..  ",
        "    .      ", "   .       ", "   .       ", "   .       ", "   .       ",
        "           ", "   v       ", "   v       ", "   v       ", "   v       ",
    ],
)

#
# secret rooms
#
my.map_load_room(
    biome_lava=True,
    secret=True,
    room_data=[
        "           ", "           ", "           ", "       ^   ", "       ^   ",
        "   ..$..   ", "           ", "           ", "       C   ", "       C   ",
        "   .   .   ", "           ", "           ", "       C   ", "       C   ",
        "   .   .   ", "   .C.C.   ", "<CC..mC.   ", "<CC.....   ", "   .....   ",
        "   . ...   ", "   .C.C.   ", "   ...C.   ", "   CCCCC   ", "   .CCC.   ",
        "   . ...   ", "   .C$C.   ", "   ..$C.   ", "   ..$..   ", "   .C$C.   ",
        "   . .m.   ", "   .CCC.   ", "   CCCC.   ", "   CCCCC   ", "   .CCC.   ",
        "   .....CC>", "   .....CC>", "   .....CC>", "   .....CC>", "   .....   ",
        "           ", "   C       ", "   C       ", "   .       ", "   C       ",
        "           ", "   C       ", "   C       ", "   .       ", "   C       ",
        "           ", "   v       ", "   v       ", "   v       ", "   v       ",
    ],
)