//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_gfx.hpp"
#include "my_tile.hpp"
#include "my_ui.hpp"

void gfx_init4(void)
{
  {
    std::initializer_list< std::string > tiles = {
        "ui.pixelart.4,0,0",   "ui.pixelart.4,1,0",   "ui.pixelart.4,2,0",   "ui.pixelart.4,3,0",
        "ui.pixelart.4,4,0",   "ui.pixelart.4,5,0",   "ui.pixelart.4,6,0",   "ui.pixelart.4,7,0",
        "ui.pixelart.4,8,0",   "ui.pixelart.4,9,0",   "ui.pixelart.4,10,0",  "ui.pixelart.4,11,0",
        "ui.pixelart.4,12,0",  "ui.pixelart.4,13,0",  "ui.pixelart.4,14,0",  "ui.pixelart.4,15,0",
        "ui.pixelart.4,0,1",   "ui.pixelart.4,1,1",   "ui.pixelart.4,2,1",   "ui.pixelart.4,3,1",
        "ui.pixelart.4,4,1",   "ui.pixelart.4,5,1",   "ui.pixelart.4,6,1",   "ui.pixelart.4,7,1",
        "ui.pixelart.4,8,1",   "ui.pixelart.4,9,1",   "ui.pixelart.4,10,1",  "ui.pixelart.4,11,1",
        "ui.pixelart.4,12,1",  "ui.pixelart.4,13,1",  "ui.pixelart.4,14,1",  "ui.pixelart.4,15,1",
        "ui.pixelart.4,0,2",   "ui.pixelart.4,1,2",   "ui.pixelart.4,2,2",   "ui.pixelart.4,3,2",
        "ui.pixelart.4,4,2",   "ui.pixelart.4,5,2",   "ui.pixelart.4,6,2",   "ui.pixelart.4,7,2",
        "ui.pixelart.4,8,2",   "ui.pixelart.4,9,2",   "ui.pixelart.4,10,2",  "ui.pixelart.4,11,2",
        "ui.pixelart.4,12,2",  "ui.pixelart.4,13,2",  "ui.pixelart.4,14,2",  "ui.pixelart.4,15,2",
        "ui.pixelart.4,0,3",   "ui.pixelart.4,1,3",   "ui.pixelart.4,2,3",   "ui.pixelart.4,3,3",
        "ui.pixelart.4,4,3",   "ui.pixelart.4,5,3",   "ui.pixelart.4,6,3",   "ui.pixelart.4,7,3",
        "ui.pixelart.4,8,3",   "ui.pixelart.4,9,3",   "ui.pixelart.4,10,3",  "ui.pixelart.4,11,3",
        "ui.pixelart.4,12,3",  "ui.pixelart.4,13,3",  "ui.pixelart.4,14,3",  "ui.pixelart.4,15,3",
        "ui.pixelart.4,0,4",   "ui.pixelart.4,1,4",   "ui.pixelart.4,2,4",   "ui.pixelart.4,3,4",
        "ui.pixelart.4,4,4",   "ui.pixelart.4,5,4",   "ui.pixelart.4,6,4",   "ui.pixelart.4,7,4",
        "ui.pixelart.4,8,4",   "ui.pixelart.4,9,4",   "ui.pixelart.4,10,4",  "ui.pixelart.4,11,4",
        "ui.pixelart.4,12,4",  "ui.pixelart.4,13,4",  "ui.pixelart.4,14,4",  "ui.pixelart.4,15,4",
        "ui.pixelart.4,0,5",   "ui.pixelart.4,1,5",   "ui.pixelart.4,2,5",   "ui.pixelart.4,3,5",
        "ui.pixelart.4,4,5",   "ui.pixelart.4,5,5",   "ui.pixelart.4,6,5",   "ui.pixelart.4,7,5",
        "ui.pixelart.4,8,5",   "ui.pixelart.4,9,5",   "ui.pixelart.4,10,5",  "ui.pixelart.4,11,5",
        "ui.pixelart.4,12,5",  "ui.pixelart.4,13,5",  "ui.pixelart.4,14,5",  "ui.pixelart.4,15,5",
        "ui.pixelart.4,0,6",   "ui.pixelart.4,1,6",   "ui.pixelart.4,2,6",   "ui.pixelart.4,3,6",
        "ui.pixelart.4,4,6",   "ui.pixelart.4,5,6",   "ui.pixelart.4,6,6",   "ui.pixelart.4,7,6",
        "ui.pixelart.4,8,6",   "ui.pixelart.4,9,6",   "ui.pixelart.4,10,6",  "ui.pixelart.4,11,6",
        "ui.pixelart.4,12,6",  "ui.pixelart.4,13,6",  "ui.pixelart.4,14,6",  "ui.pixelart.4,15,6",
        "ui.pixelart.4,0,7",   "ui.pixelart.4,1,7",   "ui.pixelart.4,2,7",   "ui.pixelart.4,3,7",
        "ui.pixelart.4,4,7",   "ui.pixelart.4,5,7",   "ui.pixelart.4,6,7",   "ui.pixelart.4,7,7",
        "ui.pixelart.4,8,7",   "ui.pixelart.4,9,7",   "ui.pixelart.4,10,7",  "ui.pixelart.4,11,7",
        "ui.pixelart.4,12,7",  "ui.pixelart.4,13,7",  "ui.pixelart.4,14,7",  "ui.pixelart.4,15,7",
        "ui.pixelart.4,0,8",   "ui.pixelart.4,1,8",   "ui.pixelart.4,2,8",   "ui.pixelart.4,3,8",
        "ui.pixelart.4,4,8",   "ui.pixelart.4,5,8",   "ui.pixelart.4,6,8",   "ui.pixelart.4,7,8",
        "ui.pixelart.4,8,8",   "ui.pixelart.4,9,8",   "ui.pixelart.4,10,8",  "ui.pixelart.4,11,8",
        "ui.pixelart.4,12,8",  "ui.pixelart.4,13,8",  "ui.pixelart.4,14,8",  "ui.pixelart.4,15,8",
        "ui.pixelart.4,0,9",   "ui.pixelart.4,1,9",   "ui.pixelart.4,2,9",   "ui.pixelart.4,3,9",
        "ui.pixelart.4,4,9",   "ui.pixelart.4,5,9",   "ui.pixelart.4,6,9",   "ui.pixelart.4,7,9",
        "ui.pixelart.4,8,9",   "ui.pixelart.4,9,9",   "ui.pixelart.4,10,9",  "ui.pixelart.4,11,9",
        "ui.pixelart.4,12,9",  "ui.pixelart.4,13,9",  "ui.pixelart.4,14,9",  "ui.pixelart.4,15,9",
        "ui.pixelart.4,0,10",  "ui.pixelart.4,1,10",  "ui.pixelart.4,2,10",  "ui.pixelart.4,3,10",
        "ui.pixelart.4,4,10",  "ui.pixelart.4,5,10",  "ui.pixelart.4,6,10",  "ui.pixelart.4,7,10",
        "ui.pixelart.4,8,10",  "ui.pixelart.4,9,10",  "ui.pixelart.4,10,10", "ui.pixelart.4,11,10",
        "ui.pixelart.4,12,10", "ui.pixelart.4,13,10", "ui.pixelart.4,14,10", "ui.pixelart.4,15,10",
        "ui.pixelart.4,0,11",  "ui.pixelart.4,1,11",  "ui.pixelart.4,2,11",  "ui.pixelart.4,3,11",
        "ui.pixelart.4,4,11",  "ui.pixelart.4,5,11",  "ui.pixelart.4,6,11",  "ui.pixelart.4,7,11",
        "ui.pixelart.4,8,11",  "ui.pixelart.4,9,11",  "ui.pixelart.4,10,11", "ui.pixelart.4,11,11",
        "ui.pixelart.4,12,11", "ui.pixelart.4,13,11", "ui.pixelart.4,14,11", "ui.pixelart.4,15,11",
        "ui.pixelart.4,0,12",  "ui.pixelart.4,1,12",  "ui.pixelart.4,2,12",  "ui.pixelart.4,3,12",
        "ui.pixelart.4,4,12",  "ui.pixelart.4,5,12",  "ui.pixelart.4,6,12",  "ui.pixelart.4,7,12",
        "ui.pixelart.4,8,12",  "ui.pixelart.4,9,12",  "ui.pixelart.4,10,12", "ui.pixelart.4,11,12",
        "ui.pixelart.4,12,12", "ui.pixelart.4,13,12", "ui.pixelart.4,14,12", "ui.pixelart.4,15,12",
        "ui.pixelart.4,0,13",  "ui.pixelart.4,1,13",  "ui.pixelart.4,2,13",  "ui.pixelart.4,3,13",
        "ui.pixelart.4,4,13",  "ui.pixelart.4,5,13",  "ui.pixelart.4,6,13",  "ui.pixelart.4,7,13",
        "ui.pixelart.4,8,13",  "ui.pixelart.4,9,13",  "ui.pixelart.4,10,13", "ui.pixelart.4,11,13",
        "ui.pixelart.4,12,13", "ui.pixelart.4,13,13", "ui.pixelart.4,14,13", "ui.pixelart.4,15,13",
        "ui.pixelart.4,0,14",  "ui.pixelart.4,1,14",  "ui.pixelart.4,2,14",  "ui.pixelart.4,3,14",
        "ui.pixelart.4,4,14",  "ui.pixelart.4,5,14",  "ui.pixelart.4,6,14",  "ui.pixelart.4,7,14",
        "ui.pixelart.4,8,14",  "ui.pixelart.4,9,14",  "ui.pixelart.4,10,14", "ui.pixelart.4,11,14",
        "ui.pixelart.4,12,14", "ui.pixelart.4,13,14", "ui.pixelart.4,14,14", "ui.pixelart.4,15,14",
        "ui.pixelart.4,0,15",  "ui.pixelart.4,1,15",  "ui.pixelart.4,2,15",  "ui.pixelart.4,3,15",
        "ui.pixelart.4,4,15",  "ui.pixelart.4,5,15",  "ui.pixelart.4,6,15",  "ui.pixelart.4,7,15",
        "ui.pixelart.4,8,15",  "ui.pixelart.4,9,15",  "ui.pixelart.4,10,15", "ui.pixelart.4,11,15",
        "ui.pixelart.4,12,15", "ui.pixelart.4,13,15", "ui.pixelart.4,14,15", "ui.pixelart.4,15,15",
    };
    const std::vector< std::string > arr(tiles);
    tile_load_arr("data/gfx/ui/pixelart/ui_box4.tga", "ui_pixelart_box4", UI_TILE_PIXELART_WIDTH,
                  UI_TILE_PIXELART_HEIGHT, arr);
  }

  {
    std::initializer_list< std::string > tiles = {
        "ui.ascii.4,0,0",   "ui.ascii.4,1,0",   "ui.ascii.4,2,0",   "ui.ascii.4,3,0",   "ui.ascii.4,4,0",
        "ui.ascii.4,5,0",   "ui.ascii.4,6,0",   "ui.ascii.4,7,0",   "ui.ascii.4,8,0",   "ui.ascii.4,9,0",
        "ui.ascii.4,10,0",  "ui.ascii.4,11,0",  "ui.ascii.4,12,0",  "ui.ascii.4,13,0",  "ui.ascii.4,14,0",
        "ui.ascii.4,15,0",  "ui.ascii.4,0,1",   "ui.ascii.4,1,1",   "ui.ascii.4,2,1",   "ui.ascii.4,3,1",
        "ui.ascii.4,4,1",   "ui.ascii.4,5,1",   "ui.ascii.4,6,1",   "ui.ascii.4,7,1",   "ui.ascii.4,8,1",
        "ui.ascii.4,9,1",   "ui.ascii.4,10,1",  "ui.ascii.4,11,1",  "ui.ascii.4,12,1",  "ui.ascii.4,13,1",
        "ui.ascii.4,14,1",  "ui.ascii.4,15,1",  "ui.ascii.4,0,2",   "ui.ascii.4,1,2",   "ui.ascii.4,2,2",
        "ui.ascii.4,3,2",   "ui.ascii.4,4,2",   "ui.ascii.4,5,2",   "ui.ascii.4,6,2",   "ui.ascii.4,7,2",
        "ui.ascii.4,8,2",   "ui.ascii.4,9,2",   "ui.ascii.4,10,2",  "ui.ascii.4,11,2",  "ui.ascii.4,12,2",
        "ui.ascii.4,13,2",  "ui.ascii.4,14,2",  "ui.ascii.4,15,2",  "ui.ascii.4,0,3",   "ui.ascii.4,1,3",
        "ui.ascii.4,2,3",   "ui.ascii.4,3,3",   "ui.ascii.4,4,3",   "ui.ascii.4,5,3",   "ui.ascii.4,6,3",
        "ui.ascii.4,7,3",   "ui.ascii.4,8,3",   "ui.ascii.4,9,3",   "ui.ascii.4,10,3",  "ui.ascii.4,11,3",
        "ui.ascii.4,12,3",  "ui.ascii.4,13,3",  "ui.ascii.4,14,3",  "ui.ascii.4,15,3",  "ui.ascii.4,0,4",
        "ui.ascii.4,1,4",   "ui.ascii.4,2,4",   "ui.ascii.4,3,4",   "ui.ascii.4,4,4",   "ui.ascii.4,5,4",
        "ui.ascii.4,6,4",   "ui.ascii.4,7,4",   "ui.ascii.4,8,4",   "ui.ascii.4,9,4",   "ui.ascii.4,10,4",
        "ui.ascii.4,11,4",  "ui.ascii.4,12,4",  "ui.ascii.4,13,4",  "ui.ascii.4,14,4",  "ui.ascii.4,15,4",
        "ui.ascii.4,0,5",   "ui.ascii.4,1,5",   "ui.ascii.4,2,5",   "ui.ascii.4,3,5",   "ui.ascii.4,4,5",
        "ui.ascii.4,5,5",   "ui.ascii.4,6,5",   "ui.ascii.4,7,5",   "ui.ascii.4,8,5",   "ui.ascii.4,9,5",
        "ui.ascii.4,10,5",  "ui.ascii.4,11,5",  "ui.ascii.4,12,5",  "ui.ascii.4,13,5",  "ui.ascii.4,14,5",
        "ui.ascii.4,15,5",  "ui.ascii.4,0,6",   "ui.ascii.4,1,6",   "ui.ascii.4,2,6",   "ui.ascii.4,3,6",
        "ui.ascii.4,4,6",   "ui.ascii.4,5,6",   "ui.ascii.4,6,6",   "ui.ascii.4,7,6",   "ui.ascii.4,8,6",
        "ui.ascii.4,9,6",   "ui.ascii.4,10,6",  "ui.ascii.4,11,6",  "ui.ascii.4,12,6",  "ui.ascii.4,13,6",
        "ui.ascii.4,14,6",  "ui.ascii.4,15,6",  "ui.ascii.4,0,7",   "ui.ascii.4,1,7",   "ui.ascii.4,2,7",
        "ui.ascii.4,3,7",   "ui.ascii.4,4,7",   "ui.ascii.4,5,7",   "ui.ascii.4,6,7",   "ui.ascii.4,7,7",
        "ui.ascii.4,8,7",   "ui.ascii.4,9,7",   "ui.ascii.4,10,7",  "ui.ascii.4,11,7",  "ui.ascii.4,12,7",
        "ui.ascii.4,13,7",  "ui.ascii.4,14,7",  "ui.ascii.4,15,7",  "ui.ascii.4,0,8",   "ui.ascii.4,1,8",
        "ui.ascii.4,2,8",   "ui.ascii.4,3,8",   "ui.ascii.4,4,8",   "ui.ascii.4,5,8",   "ui.ascii.4,6,8",
        "ui.ascii.4,7,8",   "ui.ascii.4,8,8",   "ui.ascii.4,9,8",   "ui.ascii.4,10,8",  "ui.ascii.4,11,8",
        "ui.ascii.4,12,8",  "ui.ascii.4,13,8",  "ui.ascii.4,14,8",  "ui.ascii.4,15,8",  "ui.ascii.4,0,9",
        "ui.ascii.4,1,9",   "ui.ascii.4,2,9",   "ui.ascii.4,3,9",   "ui.ascii.4,4,9",   "ui.ascii.4,5,9",
        "ui.ascii.4,6,9",   "ui.ascii.4,7,9",   "ui.ascii.4,8,9",   "ui.ascii.4,9,9",   "ui.ascii.4,10,9",
        "ui.ascii.4,11,9",  "ui.ascii.4,12,9",  "ui.ascii.4,13,9",  "ui.ascii.4,14,9",  "ui.ascii.4,15,9",
        "ui.ascii.4,0,10",  "ui.ascii.4,1,10",  "ui.ascii.4,2,10",  "ui.ascii.4,3,10",  "ui.ascii.4,4,10",
        "ui.ascii.4,5,10",  "ui.ascii.4,6,10",  "ui.ascii.4,7,10",  "ui.ascii.4,8,10",  "ui.ascii.4,9,10",
        "ui.ascii.4,10,10", "ui.ascii.4,11,10", "ui.ascii.4,12,10", "ui.ascii.4,13,10", "ui.ascii.4,14,10",
        "ui.ascii.4,15,10", "ui.ascii.4,0,11",  "ui.ascii.4,1,11",  "ui.ascii.4,2,11",  "ui.ascii.4,3,11",
        "ui.ascii.4,4,11",  "ui.ascii.4,5,11",  "ui.ascii.4,6,11",  "ui.ascii.4,7,11",  "ui.ascii.4,8,11",
        "ui.ascii.4,9,11",  "ui.ascii.4,10,11", "ui.ascii.4,11,11", "ui.ascii.4,12,11", "ui.ascii.4,13,11",
        "ui.ascii.4,14,11", "ui.ascii.4,15,11", "ui.ascii.4,0,12",  "ui.ascii.4,1,12",  "ui.ascii.4,2,12",
        "ui.ascii.4,3,12",  "ui.ascii.4,4,12",  "ui.ascii.4,5,12",  "ui.ascii.4,6,12",  "ui.ascii.4,7,12",
        "ui.ascii.4,8,12",  "ui.ascii.4,9,12",  "ui.ascii.4,10,12", "ui.ascii.4,11,12", "ui.ascii.4,12,12",
        "ui.ascii.4,13,12", "ui.ascii.4,14,12", "ui.ascii.4,15,12", "ui.ascii.4,0,13",  "ui.ascii.4,1,13",
        "ui.ascii.4,2,13",  "ui.ascii.4,3,13",  "ui.ascii.4,4,13",  "ui.ascii.4,5,13",  "ui.ascii.4,6,13",
        "ui.ascii.4,7,13",  "ui.ascii.4,8,13",  "ui.ascii.4,9,13",  "ui.ascii.4,10,13", "ui.ascii.4,11,13",
        "ui.ascii.4,12,13", "ui.ascii.4,13,13", "ui.ascii.4,14,13", "ui.ascii.4,15,13", "ui.ascii.4,0,14",
        "ui.ascii.4,1,14",  "ui.ascii.4,2,14",  "ui.ascii.4,3,14",  "ui.ascii.4,4,14",  "ui.ascii.4,5,14",
        "ui.ascii.4,6,14",  "ui.ascii.4,7,14",  "ui.ascii.4,8,14",  "ui.ascii.4,9,14",  "ui.ascii.4,10,14",
        "ui.ascii.4,11,14", "ui.ascii.4,12,14", "ui.ascii.4,13,14", "ui.ascii.4,14,14", "ui.ascii.4,15,14",
        "ui.ascii.4,0,15",  "ui.ascii.4,1,15",  "ui.ascii.4,2,15",  "ui.ascii.4,3,15",  "ui.ascii.4,4,15",
        "ui.ascii.4,5,15",  "ui.ascii.4,6,15",  "ui.ascii.4,7,15",  "ui.ascii.4,8,15",  "ui.ascii.4,9,15",
        "ui.ascii.4,10,15", "ui.ascii.4,11,15", "ui.ascii.4,12,15", "ui.ascii.4,13,15", "ui.ascii.4,14,15",
        "ui.ascii.4,15,15",
    };
    const std::vector< std::string > arr(tiles);
    tile_load_arr("data/gfx/ui/ascii/ui_box4.tga", "ui_ascii_box4", UI_TILE_PIXELART_WIDTH, UI_TILE_PIXELART_HEIGHT,
                  arr);
  }
}