/*
 * Copyright (C) 2018 goblinhack@gmail.com
 *
 * See the LICENSE file for license.
 */

#include "my_main.h"
#include "my_point.h"
#include "my_tile.h"
#include "my_room.h"
#include "my_charmap.h"
#include "my_dmap.h"
#include "my_range.h"
#include "my_dungeon_grid.h"
#include "my_ascii.h"
#include <stack>
#include <list>
#include <algorithm>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

static bool dungeon_debug = true;

#define MAX_NODES_WIDTH 10
#define MAX_NODES_HEIGHT 10

//
// The algorithm
//
// - Create a cyclic dungeon map. Different 'levels' of the dungeon can be
// cycles with a door of some kind to the next level.
//
//    K         S    D    K
//    1____1____1____2____2    -
//    |    |    |         |
//    |    |    |         |
//    |    |    |         |
//    |    |    |        D|   D
//    1    1____1    -    3____4
//    ?                   |    |
//    ?                   |    |
//    ?                   |    |
//    ?                  K|   E|
//    1____1____2    -    3    4
//
//  - Place initial small rooms
//
//  - Now we know we have a possible level, replace some of the small rooms
//  with larger rooms, so it looks more interesting.
//
//  xDxxxxx                                                         xDxxx
// xx.....D               xDx      xDxxDx                           D...xxx
// D......x               D.xx     x.xx.x      xxDxxx               x.....x
// x......x               x..xx    x....x      x..$.D               x.....x
// xxxxDxxx               x...x    x....x      D....x              xx..x..x
//                        x...xx   xx...x      x....x              x......D
//                        xxx..x    xxx.D      xxxDxx              x...xxxx
//                          xDxx      xDx                          xDxxx
//                                 xDx              xxxxx
//                                 x.x              D...D         xxxxx
//                                xx.xx             x...x         D...D
//   xxxxDxxxxx                  xx...xDx           x...xxxxDxxxx x...xxxxxxxxx
//   x........D                  x......x           x...........D x...........D
//   xxxx..xxxx          xDxxxx  x......xx          x...........x xxxx...xxxxxx
//      D..D             D....D  D.......x          x...........x    D...x
//   xxxx..xxxx          x....xx xDxxxxxxx          x...........x xxxx...x
//   D........x          xx....D                    xxxDxxxxxxxxx x......x
//   xxxxxDxxxx           xx...x                                  xxxDxxxx
//                         xx..x
//           xxxxDx         xxDx  xDxx
//           D....x               D..xx                             xxxxxDx
//           x....D  xxDxx        x...xx                xxxxDxx     x.xx..D
//           x...xx xx...D        x....D                x.....D     x.....x
//           D.xxx  D....x        x.xDxx                D.....x     x.....x
//           xDx    xx..xx        xDx                   x.....x     xxxxxxx
//                   xx.x                               xxxDxxx
//                    xDx
//
//
//  - Drag all the rooms to the center of the map, making sure to keep enough
//  of a gap for corridors
//
//                                                   xDxxx
//                                  xDxxDx           D...xxx
//                  xDxxxxx         x.xx.x           x.....x
//                 xx.....D  xDx    x....x  xxDxxx   x.....x
//                 D......x  D.xx   x....x  x..$.D  xx..x..x
//                 x......x  x..xx  xx...x  D....x  x......D  xxxxx
//                 xxxxDxxx  x...x   xxx.D  x....x  x...xxxx  D...D
//                           x...xx    xDx  xxxDxx  xDxxx     x...xxxxxxxxx
//                           xxx..x                           x...........D
//              xxxxDxxxxx     xDxx    xDx                    xxxx...xxxxxx
//              x........D             x.x      xxxxx            D...x
//              xxxx..xxxx            xx.xx     D...D         xxxx...x
//                 D..D     xDxxxx   xx...xDx   x...x         x......x
//              xxxx..xxxx  D....D   x......x   x...xxxxDxxxx xxxDxxxx
//              D........x  x....xx  x......xx  x...........D
//              xxxxxDxxxx  xx....D  D.......x  x...........x
//                           xx...x  xDxxxxxxx  x...........x
//                            xx..x             x...........x
//                     xxxxDx  xxDx             xxxDxxxxxxxxx
//                     D....x         xDxx
//                     x....D         D..xx            xxxxxDx
//                     x...xx  xxDxx  x...xx  xxxxDxx  x.xx..D
//                     D.xxx  xx...D  x....D  x.....D  x.....x
//                     xDx    D....x  x.xDxx  D.....x  x.....x
//                            xx..xx  xDx     x.....x  xxxxxxx
//                             xx.x           xxxDxxx
//                              xDx
//
//  - Now draw corridors, according to the original node layout. Make sure no
//  corridors overlap or touch.
//
//                                                   xxxxx
//                                  xxxxxx          #D...xxx
//                  xxxxxxx         x.xx.x         ##x.....x
//                 xx.....D# xxx    x....x  xxxxxx## x.....x
//                 x......x##D.xx   x....x  x..$.D# xx..x..x
//                 x......x  x..xx  xx...x #D....x  x......x  xxxxx
//                 xxxxDxxx  x...x   xxx.D##x....x  x...xxxx  x...x
//                   ###     x...xx    xDx  xxxxxx  xDxxx     x...xxxxxxxxx
//                  ##       xxx..x     #            #        x...........x
//              xxxxDxxxxx     xDxx    xDx           #        xxxx...xxxxxx
//              x........x    ###      x.x      xxxxx##      ####D...x
//              xxxx..xxxx   ##       xx.xx     x...x ##     #xxxx...x
//                 x..x     xDxxxx   xx...xxx   x...x  ##    #x......x
//              xxxx..xxxx  x....x   x......x   x...xxxxDxxxx#xxxDxxxx
//              x........x  x....xx  x......xx  x...........D#   #
//              xxxxxDxxxx  xx....D##D.......x  x...........x    #
//                   ??????  xx...x  xxxxxxxxx  x...........x   ##
//                        ??  xx..x             x...........x  ##
//                     xxxxDx  xxxx             xxxDxxxxxxxxx ##
//                     x....x         xxxx         #        ###
//                     x....D#       #D..xx       ##   xxxxxDx
//                     x...xx# xxxxx##x...xx  xxxxDxx  x.xx..x
//                     x.xxx #xx...D# x....x  x.....x  x.....x
//                     xxx   #D....x  x.xxxx  x.....x  x.....x
//                            xx..xx  xxx     x.....x  xxxxxxx
//                             xx.x           xxxxxxx
//                              xxx
//
//
class Dungeon {
public:
    //
    // The. Map.
    //
    std::vector<char>                         cells;
    std::vector<char>                         cells_saved;
    std::vector<Roomp>                        cells_room;

    int map_width                             {MAP_WIDTH};
    int map_height                            {MAP_HEIGHT};
    int map_depth                             {Charmap::DEPTH_MAX};

    //
    // This is the target minimum room size given the map size and the number
    // of nodes in the level
    //
    int room_width                            {0};
    int room_height                           {0};

    //
    // High level view of the map.
    //
    int nodes_width                           {0};
    int nodes_height                          {0};
    Nodes                                     *nodes;

    //
    // Root seed for the dungeon
    //
    uint32_t                                  seed;
    
    //
    // Room pointers on the above nodes map
    //
    Roomp                                     node_rooms[MAX_NODES_WIDTH]
                                                        [MAX_NODES_HEIGHT];

    //
    // All possible rooms we will choose from. Initially these are fixed
    // rooms and we add more random ones onto this list.
    //
    int                                       how_many_possible_rooms;

    //
    // Placed rooms
    //
    std::vector<Roomp>                        all_placed_rooms;

    void sanity (void)
    {
        auto exits = 0;
        for (auto r : Room::all_rooms) {
            if (r->placed && r->is_exit) {
                exits++;
            }
        }
        if (exits > 1) {
            DIE("WTF");
        }
    }

    void make_dungeon (void)
    {_
        //
        // Create the high level blueprint of the level layout
        //
        create_node_map();

        for (;;) {
            //
            // Reset the list of rooms we can place. We only place one of
            // each possible room once per level
            //
            reset_possible_rooms();

            //
            // Create the simplest level so we have something possible to 
            // build off of. Place only the smaller rooms here.
            //
            if (!place_initial_small_rooms()) {
                continue;
            }

            //
            // Now try and replace some of the small rooms with larger ones
            //
            if (!replace_small_rooms_randomly_with_larger_rooms()) {
                continue;
            }

            //
            // Choose how rooms are linked
            //
            choose_room_doors();
            
            //
            // Drag rooms to the center of the map
            //
            if (!compress_room_layout_to_center_of_map()) {
                continue;
            }
            
            if (compress_room_corridors()) {
                break;
            }
            
            debug("failed, redo from scratch");
        }
        
        assign_rooms_to_tiles();
        remove_all_doors();
        place_doors_between_depth_changes();
        sanity();

        // secret to secret 
        dump();
        debug("success, created dungeon");
    }

    void debug (std::string s)
    {_
        //return;
        //dump();
        //CON("dungeon (%u): %s", seed, s.c_str());
        CON("dungeon (%u) %s: hash %llx", seed, s.c_str(), level_hash());
    }

    Dungeon (int map_width,
             int map_height,
             int nodes_width,
             int nodes_height,
             int seed) :
        map_width                  (map_width),
        map_height                 (map_height),
        nodes_width                (nodes_width),
        nodes_height               (nodes_height),
        seed                       (seed)
    {_
        make_dungeon();
    }

    Dungeon ()
    {_
        make_dungeon();
    }

    int offset (const int x, const int y, const int z)
    {
        auto offset = (map_width * map_height) * z;
        offset += (map_width) * y;
        offset += x;

        return (offset);
    }

    int offset (const int x, const int y)
    {
        auto offset = (map_width) * y;
        offset += x;

        return (offset);
    }

    bool is_oob (const int x, const int y, const int z)
    {
        return ((x < 0) || (x >= map_width) ||
                (y < 0) || (y >= map_height) ||
                (z < 0) || (z >= map_depth));
    }

    bool is_oob (const int x, const int y)
    {
        return ((x < 0) || (x >= map_width) ||
                (y < 0) || (y >= map_height));
    }

    char *cell_addr (const int x, const int y, const int z)
    {
        if (is_oob(x, y, z)) {
            return (nullptr);
        }

        return (&cells[offset(x, y, z)]);
    }

    char *cell_addr_fast (const int x, const int y, const int z)
    {
        return (&cells[offset(x, y, z)]);
    }

    /*
     * Puts a tile on the map
     */
    void putc (const int x, const int y, const int z, const char c)
    {
        if (!c) {
            DIE("putting nul char at %d,%d,%d", x, y, z);
        }
        auto p = cell_addr(x, y, z);
        if (p != nullptr) {
            *p = c;
        }
    }
    
    /*
     * Puts a tile on the map
     */
    void putc_fast (const int x, const int y, const int z, const char c)
    {
        auto p = cell_addr_fast(x, y, z);
        if (p != nullptr) {
            *p = c;
        }
    }

    /*
     * Gets a tile of the map or None
     */
    char getc (const int x, const int y, const int z)
    {
        auto p = cell_addr(x, y, z);
        if (p != nullptr) {
            return (*p);
        }
        return (Charmap::NONE);
    }

    /*
     * Gets a tile of the map or None
     */
    char getc_fast (const int x, const int y, const int z)
    {
        auto p = cell_addr_fast(x, y, z);
        if (p != nullptr) {
            return (*p);
        }
        return (Charmap::NONE);
    }
    
    Roomp *cell_rooms_addr (const int x, const int y)
    {
        if (is_oob(x, y)) {
            return (nullptr);
        }

        return (&cells_room[offset(x, y)]);
    }

    Roomp *cell_rooms_addr_fast (const int x, const int y)
    {
        return (&cells_room[offset(x, y)]);
    }

    void putr (const int x, const int y, Roomp r)
    {
        auto p = cell_rooms_addr(x, y);
        if (p != nullptr) {
            *p = r;
        }
    }

    Roomp getr (const int x, const int y)
    {
        auto p = cell_rooms_addr(x, y);
        if (p != nullptr) {
            return (*p);
        }
        return (nullptr);
    }

    Roomp getr_fast (const int x, const int y)
    {
        auto p = cell_rooms_addr_fast(x, y);
        if (p != nullptr) {
            return (*p);
        }
        return (nullptr);
    }

    bool is_anything_at (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc(x, y, d);
            if ((c != Charmap::NONE) && (c != Charmap::SPACE)) {
                return true;
            }
        }
        return false;
    }

    bool is_anything_at (const int x, const int y, const int z)
    {
        auto c = getc(x, y, z);
        if ((c != Charmap::NONE) && (c != Charmap::SPACE)) {
            return true;
        }
        return false;
    }

    bool is_floor_or_corridor_at (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_floor ||
                v.is_corridor) {
                return true;
            }
        }
        return false;
    }

    bool is_floor_at (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_floor) {
                return true;
            }
        }
        return false;
    }

    bool is_dusty_at (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_dusty) {
                return true;
            }
        }
        return false;
    }

    bool is_corridor_at (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_corridor || v.is_dusty) {
                return true;
            }
        }
        return false;
    }

    bool is_wall_at (const int x, const int y)
    {
        auto d = Charmap::DEPTH_WALLS;
        auto c = getc(x, y, d);
        auto v = Charmap::all_charmaps[c];
        return (v.is_wall);
    }

    bool is_cwall_at (const int x, const int y)
    {
        auto d = Charmap::DEPTH_WALLS;
        auto c = getc(x, y, d);
        auto v = Charmap::all_charmaps[c];
        return (v.is_cwall);
    }

    bool is_door_at (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_door) {
                return true;
            }
        }
        return false;
    }

    bool is_dungeon_way_up_at (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_dungeon_way_up) {
                return true;
            }
        }
        return false;
    }

    bool is_dungeon_way_down_at (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_dungeon_way_down) {
                return true;
            }
        }
        return false;
    }

    bool is_lava_at (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_lava) {
                return true;
            }
        }
        return false;
    }

    bool is_water_at (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_water) {
                return true;
            }
        }
        return false;
    }

    bool is_chasm_at (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_chasm) {
                return true;
            }
        }
        return false;
    }

    bool is_treasure_at (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_treasure) {
                return true;
            }
        }
        return false;
    }

    bool is_dissolves_walls_at (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_dissolves_walls) {
                return true;
            }
        }
        return false;
    }

    bool is_key_at (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_key) {
                return true;
            }
        }
        return false;
    }

    bool is_movement_blocking_at (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_wall             ||
                v.is_treasure         ||
                v.is_dungeon_way_down ||
                v.is_dungeon_way_up   ||
                v.is_door) {
                return true;
            }
        }
        return false;
    }

    bool is_anything_at_fast (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc_fast(x, y, d);
            if ((c != Charmap::NONE) && (c != Charmap::SPACE)) {
                return true;
            }
        }
        return false;
    }

    bool is_anything_at_fast (const int x, const int y, const int z)
    {
        auto c = getc_fast(x, y, z);
        if ((c != Charmap::NONE) && (c != Charmap::SPACE)) {
            return true;
        }
        return false;
    }

    bool is_floor_or_corridor_at_fast (const int x, const int y)
    {
        const auto d = Charmap::DEPTH_FLOOR;
        auto c = getc_fast(x, y, d);
        auto v = Charmap::all_charmaps[c];

        return (v.is_floor || v.is_corridor);
    }

    bool is_floor_at_fast (const int x, const int y)
    {
        const auto d = Charmap::DEPTH_FLOOR;
        auto c = getc_fast(x, y, d);
        auto v = Charmap::all_charmaps[c];

        return (v.is_floor);
    }

    bool is_dusty_at_fast (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc_fast(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_dusty) {
                return true;
            }
        }
        return false;
    }

    bool is_corridor_at_fast (const int x, const int y)
    {
        const auto d = Charmap::DEPTH_FLOOR;
        auto c = getc_fast(x, y, d);
        auto v = Charmap::all_charmaps[c];

        return (v.is_corridor || v.is_dusty);
    }

    bool is_wall_at_fast (const int x, const int y)
    {
        auto d = Charmap::DEPTH_WALLS;
        auto c = getc_fast(x, y, d);
        auto v = Charmap::all_charmaps[c];
        return (v.is_wall);
    }

    bool is_cwall_at_fast (const int x, const int y)
    {
        auto d = Charmap::DEPTH_WALLS;
        auto c = getc_fast(x, y, d);
        auto v = Charmap::all_charmaps[c];
        return (v.is_cwall);
    }

    bool is_door_at_fast (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc_fast(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_door) {
                return true;
            }
        }
        return false;
    }

    bool is_dungeon_way_up_at_fast (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc_fast(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_dungeon_way_up) {
                return true;
            }
        }
        return false;
    }

    bool is_dungeon_way_down_at_fast (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc_fast(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_dungeon_way_down) {
                return true;
            }
        }
        return false;
    }

    bool is_lava_at_fast (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc_fast(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_lava) {
                return true;
            }
        }
        return false;
    }

    bool is_water_at_fast (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc_fast(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_water) {
                return true;
            }
        }
        return false;
    }

    bool is_chasm_at_fast (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc_fast(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_chasm) {
                return true;
            }
        }
        return false;
    }

    bool is_treasure_at_fast (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc_fast(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_treasure) {
                return true;
            }
        }
        return false;
    }

    bool is_dissolves_walls_at_fast (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc_fast(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_dissolves_walls) {
                return true;
            }
        }
        return false;
    }

    bool is_key_at_fast (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc_fast(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_key) {
                return true;
            }
        }
        return false;
    }

    bool is_movement_blocking_at_fast (const int x, const int y)
    {
        for (auto d = 0; d < map_depth; d++) {
            auto c = getc_fast(x, y, d);
            auto v = Charmap::all_charmaps[c];

            if (v.is_wall             ||
                v.is_treasure         ||
                v.is_dungeon_way_down ||
                v.is_dungeon_way_up   ||
                v.is_door) {
                return true;
            }
        }
        return false;
    }

    void create_node_map (void)
    {
        if (nodes_width >= MAX_NODES_WIDTH) {
            DIE("nodes width overflow");
        }

        if (nodes_height >= MAX_NODES_HEIGHT) {
            DIE("nodes height overflow");
        }

        nodes = new Nodes(nodes_width, nodes_height);
        DIE("x");
        room_width  = map_width / nodes_width;
        room_height  = map_height / nodes_height;
        room_width--;
        room_height--;
    }

#if 0
    std::vector<point> get_line_ (point a, point b, int flag)
    {_
        int temp, dx, dy, tdy, dydx, p, x, y, i;

        if (a.x > b.x) {
            temp = a.x; a.x = b.x; b.x = temp;
            temp = a.y; a.y = b.y; b.y = temp;
        }

        dx = b.x - a.x;
        dy = b.y - a.y;
        tdy = 2 * dy;
        dydx = tdy - 2 * dx;
        p = tdy - dx;   /* p0 = 2dy - dx */
        x = a.x;
        y = a.y;

        std::vector<point> r;

        switch (flag) {
            case 0: r.push_back(point(x, y)); break;
            case 1: r.push_back(point(y, x)); break;
            case 2: r.push_back(point(y, -x)); break;
            case 3: r.push_back(point(x, -y)); break;
        }

        for (i = 1; i <= dx; i++){
            x++;

	    if (p < 0) {
		p += tdy;
	    } else {
		p += dydx;
		y++;
	    }

            switch (flag) {
                case 0: r.push_back(point(x, y)); break;
                case 1: r.push_back(point(y, x)); break;
                case 2: r.push_back(point(y, -x)); break;
                case 3: r.push_back(point(x, -y)); break;
            }
        }

        return (r);
    }

    std::vector<point> get_line (point a, point b)
    {_
        int x0 = a.x;
        int x1 = b.x;
        int y0 = a.y;
        int y1 = b.y;

        float slope = 100;

        if (x0 != x1) slope = (y1 - y0) * 1.0 / (x1 - x0);

        /* call helper function depending on the line slope */
        if ((0 <= slope) && (slope <= 1))
            return get_line_(point(x0, y0), point(x1, y1), 0);
        else if ((-1 <= slope) && (slope <= 0))
            return get_line_(point(x0, -y0), point(x1, -y1), 3);
        else if (slope > 1)
            return get_line_(point(y0, x0), point(y1, x1), 1);
        else
            return get_line_(point(-y0, x0), point(-y1, x1), 2);
    }

    /*
     * Line between points
     */
    void line_draw (point start, point end, int depth, char rchar)
    {_
        auto points = get_line(start, end);
        for (auto p : points) {
            putc(p.x, p.y, depth, rchar);
        }
    }

    /*
     * Flood fill empty space.
     */
    void flood_fill(int x, int y, int depth, char rchar)
    {_
        std::stack<point> s;

        s.push(point(x, y));
        while (s.size() > 0) {

            point p = s.top();
            auto x = p.x;
            auto y = p.y;
            s.pop();

            if (is_oob(x, y)) {
                continue;
            }

            if (is_floor_or_corridor_at(x, y)) {
                continue;
            }

            putc(x, y, depth, rchar);

            s.push(point(x + 1, y));
            s.push(point(x - 1, y));
            s.push(point(x, y + 1));
            s.push(point(x, y - 1));
        }
    }

    /*
     * Flood fill empty space and return the points.
     * Used to get all the tiles in a room.
     */
    std::vector<point> flood_erase (const int x, const int y,
                                    const size_t max_size)
    {_
        bool walked[map_width][map_height];
        std::vector<point> r;
        std::stack<point> s;

        for (auto i = 0; i < map_width; i++) {
            for (auto j = 0; j < map_height; j++) {
                walked[i][j] = false;
            }
        }

        s.push(point(x, y));

        while (s.size() > 0) {
            point p = s.top();
            auto x = p.x;
            auto y = p.y;
            s.pop();

            if ((x >= map_width) || (y >= map_height) || (x < 0) || (y < 0)) {
                continue;
            }

            if (walked[x][y]) {
                continue;
            }

            walked[x][y] = true;

            auto c = getc(x, y, Charmap::DEPTH_FLOOR);
            if (c != Charmap::FLOOR) {
                continue;
            }

            putc(x, y, Charmap::DEPTH_FLOOR, Charmap::SPACE);
            r.push_back(point(x, y));

            // To limit room size
            if (r.size() > max_size) {
                break;
            }

            if ((x < map_width - 1) and not walked[x + 1][y]) {
                s.push(point(x + 1, y));
            }
            if ((x > 1) and not walked[x - 1][y]) {
                s.push(point(x - 1, y));
            }
            if ((y < map_height - 1) and !walked[x][y + 1]) {
                s.push(point(x, y + 1));
            }
            if ((y > 1) and not walked[x][y - 1]) {
                s.push(point(x, y - 1));
            }
        }
        return (r);
    }

    /*
     * Flood fill empty space and return the points.
     * Used to get all the tiles in a room.
     */
    std::vector<point> flood_find (const int x, const int y,
                                   std::function<bool (char)> callback)
    {_
        bool walked[map_width][map_height];
        std::vector<point> r;
        std::stack<point> s;

        for (auto i = 0; i < map_width; i++) {
            for (auto j = 0; j < map_height; j++) {
                walked[i][j] = false;
            }
        }

        s.push(point(x, y));

        while (s.size() > 0) {
            point p = s.top();
            auto x = p.x;
            auto y = p.y;
            s.pop();

            if ((x >= map_width) || (y >= map_height) || (x < 0) || (y < 0)) {
                continue;
            }

            if (walked[x][y]) {
                continue;
            }

            walked[x][y] = true;

            auto c = getc(x, y, Charmap::DEPTH_FLOOR);
            if (!callback(c)) {
                continue;
            }

            r.push_back(point(x, y));

            if ((x < map_width - 1) and not walked[x + 1][y]) {
                s.push(point(x + 1, y));
            }
            if ((x > 1) and not walked[x - 1][y]) {
                s.push(point(x - 1, y));
            }
            if ((y < map_height - 1) and !walked[x][y + 1]) {
                s.push(point(x, y + 1));
            }
            if ((y > 1) and not walked[x][y - 1]) {
                s.push(point(x, y - 1));
            }
        }
        return (r);
    }

    bool Callback(char c);
    void t (void)
    {_
        auto f = std::bind(&Dungeon::Callback, this, std::placeholders::_1);
        flood_find (0, 0, f);
        flood_find (0, 0, [](char c) { return true; });
    }

    /*
     * Find all adjacent characters of the same type.
     */
    void flood_replace (const int x, const int y, const int z,
                        const char old,
                        const char with)
    {_
        bool walked[map_width][map_height];
        std::stack<point> s;

        for (auto i = 0; i < map_width; i++) {
            for (auto j = 0; j < map_height; j++) {
                walked[i][j] = false;
            }
        }

        s.push(point(x, y));

        while (s.size() > 0) {
            point p = s.top();
            auto x = p.x;
            auto y = p.y;
            s.pop();

            if ((x >= map_width) || (y >= map_height) || (x < 0) || (y < 0)) {
                continue;
            }

            if (walked[x][y]) {
                continue;
            }

            walked[x][y] = true;

            auto c = getc(x, y, z);
            if (c != old) {
                continue;
            }

            putc(x, y, z, with);

            if ((x < map_width - 1) and not walked[x + 1][y]) {
                s.push(point(x + 1, y));
            }
            if ((x > 1) and not walked[x - 1][y]) {
                s.push(point(x - 1, y));
            }
            if ((y < map_height - 1) and !walked[x][y + 1]) {
                s.push(point(x, y + 1));
            }
            if ((y > 1) and not walked[x][y - 1]) {
                s.push(point(x, y - 1));
            }
        }
    }
#endif

    void dump (void)
    {_
        if (!dungeon_debug) {
            return;
        }

        CON("dungeon: seed %u", seed);
        for (auto y = 0; y < map_height; y++) {
            std::string s;
            for (auto x = 0; x < map_width; x++) {
                bool got_one = false;
                for (auto d = map_depth - 1; d >= 0; d--) {
                    if (!is_anything_at(x, y, d)) {
                        continue;
                    }

                    auto m = getc(x, y, d);
                    auto cr = Charmap::all_charmaps[m];
                    auto c = cr.c;

                    if (!c) {
                        DIE("unknown map char %c at %d,%d,%d", m, x, y, d);
                    }

                    if (!(x % 2) && !(y % 2)) {
                        if (!is_wall_at(x, y) && is_floor_at(x, y)) {
                            Roomp r = getr(x, y);
                            if (r) {
                                c = '0' + r->depth;
                            }
                        }
                    }
                    
                    s += c;
                    got_one = true;
                    break;
                }
                if (!got_one) {
                    s += " ";
                }
            }
            CON("%s", s.c_str());
        }
    }

    uint64_t level_hash (void)
    {_
        uint64_t h = 0;

        for (auto y = 0; y < map_height; y++) {
            for (auto x = 0; x < map_width; x++) {
                for (auto d = map_depth - 1; d >= 0; d--) {
                    auto m = getc(x, y, d);
                    auto cr = Charmap::all_charmaps[m];
                    auto c = cr.c;

                    h += (c - 32) * x * y;
                    h--;
                }
            }
        }
        return (h);
    }

    //
    // Check for room overlaps
    //
    bool map_can_room_be_places (Roomp room, int x, int y)
    {
        if (x < 0) {
            return false;
        }
        if (x + room->width >= map_width) {
            return false;
        }

        if (y < 0) {
            return false;
        }
        if (y + room->height >= map_height) {
            return false;
        }

        auto d = Charmap::DEPTH_WALLS;

        if (not room->data[d].size()) {
            return true;
        }

        auto dy = 0;
        for (auto s : room->data[d]) {
            auto dx = 0;
            for (auto c : s) {
                if (c != Charmap::SPACE) {
                    if (is_wall_at_fast(x + dx,     y + dy)) {
                        return false;
                    }
                }
                dx++;
            }
            dy++;
        }

        //
        // Need at least one block between rooms for corridors
        //
        dy = 0;
        for (auto s : room->data[d]) {
            auto dx = 0;
            for (auto c : s) {
                if (c != Charmap::SPACE) {
                    if (is_wall_at(x + dx - 1, y + dy) ||
                        is_wall_at(x + dx + 1, y + dy) ||
                        is_wall_at(x + dx, y + dy - 1) ||
                        is_wall_at(x + dx, y + dy + 1)) {
                        return false;
                    }
                }
                dx++;
            }
            dy++;
        }

        return true;
    }

    //
    // Dump a room onto the level. No checks
    //
    void map_place_room_chars (Roomp room, int x, int y)
    {
        for (auto d = 0 ; d < Charmap::DEPTH_MAX; d++) {
            if (not room->data[d].size()) {
                continue;
            }

            auto dy = 0;
            for (auto s : room->data[d]) {
                auto dx = 0;
                for (auto c : s) {
                    if (c != Charmap::SPACE) {
                        putc_fast(x + dx, y + dy, d, c);
                    }
                    dx++;
                }
                dy++;
            }
        }
    }
    
    //
    // Dump a room onto the level along with its roomno. Done when we
    // have finalized positions of rooms.
    //
    void map_place_room_ptr (Roomp r, int x, int y)
    {
        if (!r) {
            DIE("no room to place");
        }
        
        for (auto d = 0 ; d < Charmap::DEPTH_MAX; d++) {
            if (not r->data[d].size()) {
                continue;
            }

            auto dy = 0;
            for (auto s : r->data[d]) {
                auto dx = 0;
                for (auto c : s) {
                    if (c != Charmap::SPACE) {
                        putr(x + dx, y + dy, r);
                    }
                    dx++;
                }
                dy++;
            }
        }
    }

    //
    // Try to push a room on the level
    //
    bool map_room_place_if_no_overlaps (Roomp room, int x, int y)
    {
        if (not map_can_room_be_places(room, x, y)) {
            return false;
        }

        map_place_room_chars(room, x, y);
        return true;
    }

    //
    // From a fixed list of random roomnos, return the next one. This
    // ensures no room will ever appear more than once.
    //
    Roomp get_next_room (int node_x, int node_y)
    {
        auto n = nodes->getn(node_x, node_y);

        auto tries = 100000;
        while (tries-- > 0) {
            auto ri = random_range(0, Room::all_rooms.size());
            auto r = Room::all_rooms[ri];
            
            if (r->placed) {
                continue;
            }
            if (n->dir_left != r->dir_left) {
                continue;
            }
            if (n->dir_right != r->dir_right) {
                continue;
            }
            if (n->dir_up != r->dir_up) {
                continue;
            }
            if (n->dir_down != r->dir_down) {
                continue;
            }
            if (n->is_exit != r->is_exit) {
                continue;
            }
            if (n->is_entrance != r->is_entrance) {
                continue;
            }
            if (n->is_lock != r->is_lock) {
                continue;
            }
            if (n->is_key != r->is_key) {
                continue;
            }
#if 0
            LOG("place node %d,%d room(%d) %d,%d - placed %d u %d d %d l %d r %d S %d E %d L %d k %d", 
                node_x, node_y,
                r->roomno,
                r->at.x, r->at.y,
                r->placed,
                r->dir_up, r->dir_down, r->dir_left, r->dir_right,
                r->is_entrance,
                r->is_exit,
                r->is_lock,
                r->is_key);
            r->dump();
#endif
            return (r);
        }

        LOG("room dump:");
        for (auto r : Room::all_rooms) {
#if 0
            CON("node %d,%d - want %d %d %d %d got %d %d %d %d", 
                node_x, node_y,
                n->dir_up, n->dir_down, n->dir_left, n->dir_right,
                r->dir_up, r->dir_down, r->dir_left, r->dir_right);
            r->dump();
#endif
            LOG("room(%d) %d,%d - placed %d u %d d %d l %d r %d S %d E %d L %d k %d", 
                r->roomno,
                r->at.x, r->at.y,
                r->placed,
                r->dir_up, r->dir_down, r->dir_left, r->dir_right,
                r->is_entrance,
                r->is_exit,
                r->is_lock,
                r->is_key);
        }
        dump();
        DIE("could not satisfy node %d,%d - u %d d %d l %d r %d S %d E %d L %d k %d", 
            node_x, node_y,
            n->dir_up, n->dir_down, n->dir_left, n->dir_right,
            n->is_entrance,
            n->is_exit,
            n->is_lock,
            n->is_key);
    }

    void dmap_print_walls (dmap *d)
    {
        int16_t x;
        int16_t y;

        for (y = 0; y < MAP_HEIGHT; y++) {
            for (x = 0; x < MAP_WIDTH; x++) {
                int16_t e = d->val[x][y];
                if (e == DMAP_IS_WALL) {
                    if (is_corridor_at(x, y)) {
                        printf("#");
                    } else if (is_floor_or_corridor_at(x, y)) {
                        printf(".");
                    } else if (is_wall_at(x, y)) {
                        printf("x");
                    } else {
                        printf("_");
                    }
                    continue;
                }
                if (e == DMAP_IS_PASSABLE) {
                    if (is_floor_or_corridor_at(x, y)) {
                        printf(".");
                    } else {
                        printf(" ");
                    }
                    continue;
                }

                if (e > 0) {
                    printf("%d", e % 10);
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    int draw_corridor (point start, point end, char w)
    {
        dmap d;

        memset(&d, 0, sizeof(d));

#if 0
        if (w == Charmap::CORRIDOR) {
            LOG("create corridor, between %d,%d and %d,%d",
                start.x, start.y,
                end.x, end.y);
        } else {
            LOG("create secret corridor, between %d,%d and %d,%d",
                start.x, start.y,
                end.x, end.y);
        }
#endif
        point dmap_start = start;
        point dmap_end = end;

        int minx, miny, maxx, maxy;
        if (dmap_start.x < dmap_end.x) {
            minx = dmap_start.x;
            maxx = dmap_end.x;
        } else {
            minx = dmap_end.x;
            maxx = dmap_start.x;
        }
        if (dmap_start.y < dmap_end.y) {
            miny = dmap_start.y;
            maxy = dmap_end.y;
        } else {
            miny = dmap_end.y;
            maxy = dmap_start.y;
        }

        auto border = 3;
        minx -= border;
        miny -= border;
        maxx += border;
        maxy += border;

        if (minx < 0) {
            minx = 0;
        }
        if (miny < 0) {
            miny = 0;
        }
        if (maxx >= map_width) {
            maxx = map_width - 1;
        }
        if (maxy >= map_height) {
            maxy = map_height - 1;
        }

        //
        // Set up obstacles for the corridor search
        //
        for (auto y = miny; y < maxy; y++) {
            for (auto x = minx; x < maxx; x++) {
                if (is_anything_at_fast(x, y)) {
                    d.val[x][y] = DMAP_IS_WALL;
                } else {
                    d.val[x][y] = DMAP_IS_PASSABLE;
                }
            }
        }

        //
        // Ensure adjoining corridors are not possible
        //
        for (auto y = miny + 1; y < maxy - 1; y++) {
            for (auto x = minx + 1; x < maxx - 1; x++) {
                if (is_corridor_at_fast(x, y)) {
                    d.val[x-1][y] = DMAP_IS_WALL;
                    d.val[x][y-1] = DMAP_IS_WALL;
                    d.val[x][y] = DMAP_IS_WALL;
                    d.val[x][y+1] = DMAP_IS_WALL;
                    d.val[x+1][y] = DMAP_IS_WALL;
                }
            }
        }

        dmap_start = point(minx, miny);
        dmap_end = point(maxx, maxy);

        d.val[end.x][end.y] = DMAP_IS_GOAL;
        d.val[start.x][start.y] = DMAP_IS_PASSABLE;

        dmap_process(&d, dmap_start, dmap_end);
        //dmap_print_walls(&d);

        //LOG("dmap hash: %llx level hash %llx", dmap_hash(&d), level_hash());
        auto p = dmap_solve(&d, start, end);

        //
        // Too long a corridor?
        //
        if (p.size() > 25) {
            for (auto c : p) {
                putc(c.x, c.y, Charmap::DEPTH_FLOOR, Charmap::DEBUG);
            }
            debug("failed to create corridor, too long a corridor");
            return (0);
        }

        //
        // Check we can reach the end point
        //
        bool got_goal = false;
        for (auto c : p) {
            if (c == end) {
                got_goal = true;
                break;
            }
        }

        if (!got_goal) {
            for (auto c : p) {
                putc(c.x, c.y, Charmap::DEPTH_FLOOR, Charmap::DEBUG);
            }
            putc(start.x, start.y, Charmap::DEPTH_WALLS, Charmap::DEBUG);
            putc(end.x, end.y, Charmap::DEPTH_WALLS, Charmap::DEBUG);

            debug("failed to create corridor, end not found");
            LOG("dungeon: failed to create corridor, end not found between %d,%d and %d,%d",
                start.x, start.y,
                end.x, end.y);
            return (0);
        }

        for (auto c : p) {
            putc(c.x, c.y, Charmap::DEPTH_FLOOR, w);
        }

        putc(start.x, start.y, Charmap::DEPTH_WALLS, Charmap::DOOR);
        putc(end.x, end.y, Charmap::DEPTH_WALLS, Charmap::DOOR);

        //debug("placed corridor");
        return (p.size());
    }

    void reset_possible_rooms (void)
    {
        cells.resize(map_width * map_height * Charmap::DEPTH_MAX,
                     Charmap::SPACE);
        cells_room.resize(map_width * map_height, nullptr);

        std::fill(cells.begin(), cells.end(), Charmap::SPACE);
        std::fill(cells_room.begin(), cells_room.end(), nullptr);
        
        how_many_possible_rooms = (int) Room::all_rooms.size();
        for (auto r : Room::all_rooms) {
            r->placed = false;
        }
    }

    //
    // Place the initial rooms. Choose only small ones we know will
    // fit.
    //
    bool place_initial_small_rooms (void)
    {
        for (auto x = 0; x < nodes->nodes_width; x++) {
            for (auto y = 0; y < nodes->nodes_height; y++) {
                node_rooms[x][y] = nullptr;
            }
        }

        for (auto x = 0; x < nodes->nodes_width; x++) {
            for (auto y = 0; y < nodes->nodes_height; y++) {

                auto n = nodes->getn(x, y);
                if (!n->depth) {
                    continue;
                }

                if (n->depth == nodes->depth_obstacle) {
                    continue;
                }

                auto placed = false;
                for (auto roomi = 0; roomi < how_many_possible_rooms; roomi++) {

                    auto r = get_next_room(x, y);

                    if (r->width >= room_width) {
                        continue;
                    }

                    if (r->height >= room_height) {
                        continue;
                    }

                    if ((n->has_exit_down || n->has_secret_exit_down) &&
                        !r->down_exits.size()) {
                        continue;
                    }
                    if ((n->has_exit_up || n->has_secret_exit_up) &&
                        !r->up_exits.size()) {
                        continue;
                    }
                    if ((n->has_exit_left || n->has_secret_exit_left) &&
                        !r->left_exits.size()) {
                        continue;
                    }
                    if ((n->has_exit_right || n->has_secret_exit_right) &&
                        !r->right_exits.size()) {
                        continue;
                    }

                    r->at.x = x * (room_width+1) + 
                                    random_range(-room_width/2, room_width/2);
                    r->at.y = y * (room_height+1) + 
                                    random_range(-room_width/2, room_height/2);

                    if (map_room_place_if_no_overlaps(r, r->at.x, r->at.y)) {
                        if (node_rooms[x][y]) {
                            DIE("x");
                        }

                        node_rooms[x][y] = r;
                        r->placed = true;
                        placed = true;
                        break;
                    }
                }

                if (!placed) {
                    debug("failed to place initial small rooms");
                    return (false);
                }
            }
        }

        if (!draw_corridors()) {
            debug("failed, placed initial small rooms but is unsolvable");
            return (false);
        }
        
        debug("success, placed initial small rooms");
        return (true);
    }

    //
    // Repeatedly try to place larger rooms
    //
    bool replace_small_rooms_randomly_with_larger_rooms (void)
    {
        auto place_large_room_tries = 4;
        while (place_large_room_tries--) {
            std::fill(cells.begin(), cells.end(), Charmap::SPACE);

            Roomp replace_this_room_with_a_larger_one = nullptr;
            Roomp node_rooms_saved[MAX_NODES_WIDTH][MAX_NODES_HEIGHT];

            for (auto x = 0; x < nodes->nodes_width; x++) {
                for (auto y = 0; y < nodes->nodes_height; y++) {
                    auto r = node_rooms[x][y];
                    node_rooms_saved[x][y] = r;
                }
            }

            //
            // Choose a room to skip
            //
            for (auto x = 0; x < nodes->nodes_width; x++) {
                for (auto y = 0; y < nodes->nodes_height; y++) {
                    auto r = node_rooms[x][y];
                    if (!r) {
                        continue;
                    }

                    //
                    // Already larger
                    //
                    if ((r->width > room_width) ||
                        (r->height > room_height)) {
                        continue;
                    }

                    if (random_range(0, 100) < 10) {
                        replace_this_room_with_a_larger_one = r;
                    }
                }
            }

            if (!replace_this_room_with_a_larger_one) {
                continue;
            }

            //
            // Place all rooms bar the skip room
            //
            for (auto x = 0; x < nodes->nodes_width; x++) {
                for (auto y = 0; y < nodes->nodes_height; y++) {
                    auto r = node_rooms[x][y];
                    if (!r) {
                        continue;
                    }

                    if (r == replace_this_room_with_a_larger_one) {
                        continue;
                    }

                    auto rx = r->at.x;
                    auto ry = r->at.y;
                    
                    if (!map_room_place_if_no_overlaps(r, rx, ry)) {
                        dump();
                        CON("place it anyway below for debugging:");
                        map_place_room_chars(r, x, y);
                        dump();
                        DIE("could not place base room when trying to find larger rooms");
                        break;
                    }
                }
            }

            //
            // Now place a larger room where the skip room is
            //
            bool success = false;
            for (auto x = 0; x < nodes->nodes_width; x++) {
                for (auto y = 0; y < nodes->nodes_height; y++) {
                    auto r = node_rooms[x][y];
                    if (!r) {
                        continue;
                    }

                    if (r != replace_this_room_with_a_larger_one) {
                        continue;
                    }

                    auto n = nodes->getn(x, y);
                    for (auto roomi = 0; roomi < how_many_possible_rooms; roomi++) {

                        auto r = get_next_room(x, y);

                        //
                        // Filter out small rooms
                        //
                        if (r->width < room_width) {
                            continue;
                        }

                        if (r->height < room_height) {
                            continue;
                        }

                        //
                        // Filter to only rooms that match the node 
                        // requirements
                        //
                        if ((n->has_exit_down || n->has_secret_exit_down) &&
                            !r->down_exits.size()) {
                            continue;
                        }
                        if ((n->has_exit_up || n->has_secret_exit_up) &&
                            !r->up_exits.size()) {
                            continue;
                        }
                        if ((n->has_exit_left || n->has_secret_exit_left) &&
                            !r->left_exits.size()) {
                            continue;
                        }
                        if ((n->has_exit_right || n->has_secret_exit_right) &&
                            !r->right_exits.size()) {
                            continue;
                        }

                        auto offsets = 3;
                        for (auto dx = -offsets; dx < offsets; dx++) {
                            for (auto dy = -offsets; dy < offsets; dy++) {
                                auto rx = dx + x * room_width;
                                auto ry = dy + y * room_height;

                                if (map_room_place_if_no_overlaps(r, rx, ry)) {
                                    node_rooms[x][y]->placed = false;
                                    r->placed = true;
                                    node_rooms[x][y] = r;
                                    r->at.x = rx;
                                    r->at.y = ry;
                                    success = true;
                                    goto next;
                                }
                            }
                        }
                    }
                }
            }
next:
            if (success) {
                if (!draw_corridors()) {
                    debug("failed to place unsolvable larger level");
                    
                    for (auto x = 0; x < nodes->nodes_width; x++) {
                        for (auto y = 0; y < nodes->nodes_height; y++) {
                            if (node_rooms[x][y]) {
                                node_rooms[x][y]->placed = false;
                                node_rooms[x][y] = node_rooms_saved[x][y];
                                node_rooms[x][y]->placed = true;
                            }
                        }
                    }
                } else {
                    debug("success, placed solvable larger level");
                }
            } else {
                debug("failed to place larger room on level");
            }
        }

        //
        // Remake the dungeon with the larger rooms
        //
        std::fill(cells.begin(), cells.end(), Charmap::SPACE);

        for (auto x = 0; x < nodes->nodes_width; x++) {
            for (auto y = 0; y < nodes->nodes_height; y++) {
                auto r = node_rooms[x][y];
                if (!r) {
                    continue;
                }

                auto rx = r->at.x;
                auto ry = r->at.y;
                if (!map_room_place_if_no_overlaps(r, rx, ry)) {
                    DIE("could not place base room(2) when trying to find larger rooms");
                    break;
                }
            }
        }

        debug("success, placed larger rooms");

        return (true);
    }

    void save_level (void)
    {
        cells_saved = cells;

        for (unsigned int rs = 0;
                rs < (unsigned int) all_placed_rooms.size(); rs++) {
            auto r = all_placed_rooms[rs];
            r->rollback_at = r->at;
        }
    }

    void restore_level (void)
    {
        cells = cells_saved;

        for (unsigned int rs = 0;
                rs < (unsigned int) all_placed_rooms.size(); rs++) {
            auto r = all_placed_rooms[rs];
            r->at = r->rollback_at;
        }
    }

    //
    // Repeat placing all rooms bar one random one. Try to move
    // that random one closer to the center. Repeat.
    //
    bool compress_room_layout_to_center_of_map (void)
    {
        auto mx = map_width / 2;
        auto my = map_height / 2;
        auto delta = 1;

        all_placed_rooms.resize(0);

        for (auto r : Room::all_rooms) {
            r->placed = false;
        }

        for (auto x = 0; x < nodes->nodes_width; x++) {
            for (auto y = 0; y < nodes->nodes_height; y++) {
                auto r = node_rooms[x][y];
                if (!r) {
                    continue;
                }

                all_placed_rooms.push_back(r);
                r->placed = true;
            }
        }

        //
        // Make sure we start with a solvable room
        //
        save_level();
        if (!draw_corridors()) {
            debug("level before adding corridors is NOT solvable");
            return (false);
        }

        restore_level();
        debug("level before adding corridors is solvable");

        auto failed_attempts = 0;
        auto attempts_to_move_rooms_closer = 200;

        choose_room_doors();
        
        while (attempts_to_move_rooms_closer--) {

            center_room_layout();
            
            for (unsigned int rs = 0;
                 rs < (unsigned int) all_placed_rooms.size();
                 rs++) {

                auto r = all_placed_rooms[rs];
                auto skip_roomno = r->roomno;

                std::fill(cells.begin(), cells.end(), Charmap::SPACE);
                
                auto moved = false;

                /*
                 * Place all except one room
                 */
                auto ri = 0;
                for (auto x = 0; x < nodes->nodes_width; x++) {
                    for (auto y = 0; y < nodes->nodes_height; y++) {

                        auto n = nodes->getn(x, y);
                        if (n->depth <= 0 ) {
                            continue;
                        }

                        auto r = all_placed_rooms[ri++];
                        if (r->roomno == skip_roomno) {
                            continue;
                        }

                        map_place_room_chars(r, r->at.x, r->at.y);
                    }
                }

                /*
                 * Place the room we want to move
                 */
                ri = 0;
                for (auto x = 0; x < nodes->nodes_width; x++) {
                    for (auto y = 0; y < nodes->nodes_height; y++) {

                        auto n = nodes->getn(x, y);
                        if (!n->depth) {
                            continue;
                        }

                        //
                        // water etc..
                        //
                        if (n->depth == nodes->depth_obstacle) {
                            continue;
                        }

                        auto r = all_placed_rooms[ri++];
                        if (r->roomno != skip_roomno) {
                            continue;
                        }

                        if (r->at.x + r->width > mx) {
                            if (map_can_room_be_places(r, r->at.x - delta, r->at.y)) {
                                r->at.x--;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved = true;
                                break;
                            }
                        }

                        if (r->at.x < mx) {
                            if (map_can_room_be_places(r, r->at.x + delta, r->at.y)) {
                                r->at.x++;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved = true;
                                break;
                            }
                        }

                        if (r->at.y + r->height > my) {
                            if (map_can_room_be_places(r, r->at.x, r->at.y - delta)) {
                                r->at.y--;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved = true;
                                break;
                            }
                        }

                        if (r->at.y < my) {
                            if (map_can_room_be_places(r, r->at.x, r->at.y + delta)) {
                                r->at.y++;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved = true;
                                break;
                            }
                        }

                        map_place_room_chars(r, r->at.x, r->at.y);
                        break;
                    }
                }

                if (!moved) {
                    continue;
                }

                //
                // Ok we've moved one room. If we can still place corridors
                // then we can keep going. If not, rollback the room to the
                // last that was solvable.
                //
                std::vector<char> cells_ok = cells;

                if (!draw_corridors()) {
                    debug("failed to placing corridors, rollback");
                    restore_level();

                    if (failed_attempts++ > 20) {
                        debug("success, placed compressed layout");
                        return (true);
                    }
                } else {
                    debug("success, placed corridors");
                    failed_attempts = 0;
                    cells = cells_ok;
                    save_level();
                }
            }
        }
        
        debug("success, placed compressed layout");
        return (true);
    }
    
    bool compress_room_corridors (void)
    {
        auto delta = 1;

        all_placed_rooms.resize(0);

        for (auto r : Room::all_rooms) {
            r->placed = false;
        }

        for (auto x = 0; x < nodes->nodes_width; x++) {
            for (auto y = 0; y < nodes->nodes_height; y++) {
                auto r = node_rooms[x][y];
                if (!r) {
                    continue;
                }

                all_placed_rooms.push_back(r);
                r->placed = true;
            }
        }

        //
        // Make sure we start with a solvable room
        //
        save_level();
        auto corridor_count = draw_corridors();
        if (!corridor_count) {
            debug("level before adding corridors is NOT solvable");
            return (false);
        }

        dump();
        debug("level before adding shorter corridors is solvable");
        restore_level();

        auto failed_to_place_all_corridors = 0;
        auto failed_to_make_shorter_corridors = 0;
        auto attempts_to_move_rooms_closer = 200;

        choose_room_doors();
        
        while (attempts_to_move_rooms_closer--) {

            center_room_layout();
            
            for (unsigned int rs = 0;
                 rs < (unsigned int) all_placed_rooms.size();
                 rs++) {

                std::fill(cells.begin(), cells.end(), Charmap::SPACE);
                
                /*
                 * which rooms shall we move?
                 */
                for (auto x = 0; x < nodes->nodes_width; x++) {
                    for (auto y = 0; y < nodes->nodes_height; y++) {
                        auto r = node_rooms[x][y];
                        if (r) {
                            r->skip = (random_range(0, 100) < 10);
                        }
                    }
                }
                
                /*
                 * Place all rooms that are not going to move
                 */
                for (auto x = 0; x < nodes->nodes_width; x++) {
                    for (auto y = 0; y < nodes->nodes_height; y++) {
                        auto r = node_rooms[x][y];
                        if (!r) {
                            continue;
                        }
                        if (!r->skip) {
                            map_place_room_chars(r, r->at.x, r->at.y);
                        }
                    }
                }

                /*
                 * Place the rooms we want to move
                 */
                auto moved = false;
                for (auto x = 0; x < nodes->nodes_width; x++) {
                    for (auto y = 0; y < nodes->nodes_height; y++) {
                        auto r = node_rooms[x][y];
                        if (!r) {
                            continue;
                        }
                        if (!r->skip) {
                            continue;
                        }

                        auto moved_one = false;
                        switch (random_range(0, 4)) {
                        case 0:
                            if (map_can_room_be_places(r, r->at.x - delta, r->at.y)) {
                                r->at.x--;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved_one = true;
                                break;
                            }
                            if (map_can_room_be_places(r, r->at.x + delta, r->at.y)) {
                                r->at.x++;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved_one = true;
                                break;
                            }
                            if (map_can_room_be_places(r, r->at.x, r->at.y - delta)) {
                                r->at.y--;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved_one = true;
                                break;
                            }
                            if (map_can_room_be_places(r, r->at.x, r->at.y + delta)) {
                                r->at.y++;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved_one = true;
                                break;
                            }
                            break;

                        case 1:
                            if (map_can_room_be_places(r, r->at.x + delta, r->at.y)) {
                                r->at.x++;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved_one = true;
                                break;
                            }
                            if (map_can_room_be_places(r, r->at.x - delta, r->at.y)) {
                                r->at.x--;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved_one = true;
                                break;
                            }
                            if (map_can_room_be_places(r, r->at.x, r->at.y - delta)) {
                                r->at.y--;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved_one = true;
                                break;
                            }
                            if (map_can_room_be_places(r, r->at.x, r->at.y + delta)) {
                                r->at.y++;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved_one = true;
                                break;
                            }
                            break;
                            
                        case 2:
                            if (map_can_room_be_places(r, r->at.x, r->at.y - delta)) {
                                r->at.y--;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved_one = true;
                                break;
                            }
                            if (map_can_room_be_places(r, r->at.x - delta, r->at.y)) {
                                r->at.x--;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved_one = true;
                                break;
                            }
                            if (map_can_room_be_places(r, r->at.x + delta, r->at.y)) {
                                r->at.x++;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved_one = true;
                                break;
                            }
                            if (map_can_room_be_places(r, r->at.x, r->at.y + delta)) {
                                r->at.y++;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved_one = true;
                                break;
                            }
                            break;

                        case 3:
                            if (map_can_room_be_places(r, r->at.x, r->at.y + delta)) {
                                r->at.y++;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved_one = true;
                                break;
                            }
                            if (map_can_room_be_places(r, r->at.x - delta, r->at.y)) {
                                r->at.x--;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved_one = true;
                                break;
                            }
                            if (map_can_room_be_places(r, r->at.x + delta, r->at.y)) {
                                r->at.x++;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved_one = true;
                                break;
                            }
                            if (map_can_room_be_places(r, r->at.x, r->at.y - delta)) {
                                r->at.y--;
                                map_place_room_chars(r, r->at.x, r->at.y);
                                moved_one = true;
                                break;
                            }
                            break;
                        case 4:
                            DIE("wtf");
                        }
                        
                        if (moved_one) {
                            moved = true;
                        } else {
                            map_place_room_chars(r, r->at.x, r->at.y);
                        }
                    }
                }

                if (!moved) {
                    continue;
                }

                //
                // Ok we've moved one room. If we can still place corridors
                // then we can keep going. If not, rollback the room to the
                // last that was solvable.
                //
                std::vector<char> cells_ok = cells;

                auto new_corridor_count = draw_corridors();
//CON("corridor_count %d new_corridor_count %d 
//failed_to_make_shorter_corridors %d ",corridor_count, new_corridor_count, 
//failed_to_make_shorter_corridors);
                if (new_corridor_count >= corridor_count) {
                    debug("failed to place shorter corridors, rollback");
                    
                    restore_level();
                    if (!draw_corridors()) {
                        DIE("rolled back level was not solvable");
                    }

                    if (failed_to_make_shorter_corridors++ > 100) {
                        debug("success, placed shorter corridor layout");
                        return (true);
                    }

                    restore_level();
                } else if (!new_corridor_count) {
                    debug("failed to place all corridors, rollback");
                    
                    restore_level();
                    if (!draw_corridors()) {
                        DIE("rolled back level was not solvable");
                    }

                    if (failed_to_place_all_corridors++ > 20) {
                        debug("success, placed shorter corridor layout");
                        return (true);
                    }

                    restore_level();
                } else {
                    corridor_count = new_corridor_count;
                    debug("success, placed corridors");
                    failed_to_place_all_corridors = 0;
                    failed_to_make_shorter_corridors = 0;
                    cells = cells_ok;
                    save_level();
                }
            }
        }
        debug("success, placed shorter corridor layout");

        return (draw_corridors());
    }
    
    //
    // Find which doors we want to use for a room
    //
    void choose_room_doors (void)
    {
        for (auto x = 0; x < nodes->nodes_width; x++) {
            for (auto y = 0; y < nodes->nodes_height; y++) {
                auto r = node_rooms[x][y];

                if (!r) {
                    continue;
                }
                
                r->down_room = nullptr;
                r->up_room = nullptr;
                r->left_room = nullptr;
                r->right_room = nullptr;
                
                r->secret_down_room = nullptr;
                r->secret_up_room = nullptr;
                r->secret_left_room = nullptr;
                r->secret_right_room = nullptr;
            }
        }

        for (auto x = 0; x < nodes->nodes_width; x++) {
            for (auto y = 0; y < nodes->nodes_height; y++) {

                auto n = nodes->getn(x, y);
                if (!n->depth) {
                    continue;
                }

                if (n->depth == nodes->depth_obstacle) {
                    continue;
                }

                auto r = node_rooms[x][y];

                if (n->has_exit_down) {
                    auto o = node_rooms[x][y+1];
                    if (!o) {
                        debug("bug");
                        DIE("had exit down at %d,%d, but no node exists", x, y);
                    }
                    auto rdoori = random_range(0, r->down_exits.size());
                    auto odoori = random_range(0, o->up_exits.size());
                    if (rdoori >= r->down_exits.size()) {
                        debug("bug");
                        DIE("bug");
                    }
                    if (odoori >= o->up_exits.size()) {
                        debug("bug");
                        DIE("bug");
                    }

                    r->which_door_down = rdoori;
                    o->which_door_up = odoori;
                    
                    r->down_room = o;
                    o->up_room = r;
                }

                if (n->has_exit_right) {
                    auto o = node_rooms[x+1][y];
                    if (!o) {
                        debug("bug");
                        DIE("had exit right at %d,%d, but no node exists", x, y);
                    }
                    auto rdoori = random_range(0, r->right_exits.size());
                    auto odoori = random_range(0, o->left_exits.size());
                    if (rdoori >= r->right_exits.size()) {
                        debug("bug");
                        DIE("bug");
                    }
                    if (odoori >= o->left_exits.size()) {
                        debug("bug");
                        DIE("bug");
                    }

                    r->which_door_right = rdoori;
                    o->which_door_left = odoori;
                    
                    r->right_room = o;
                    o->left_room = r;
                }

                if (n->has_secret_exit_down) {
                    auto o = node_rooms[x][y+1];
                    if (!o) {
                        debug("bug");
                        DIE("had secret exit down at %d,%d, but no node exists", x, y);
                    }
                    auto rdoori = random_range(0, r->down_exits.size());
                    auto odoori = random_range(0, o->up_exits.size());
                    if (rdoori >= r->down_exits.size()) {
                        debug("bug");
                        DIE("bug");
                    }
                    if (odoori >= o->up_exits.size()) {
                        debug("bug");
                        DIE("bug");
                    }

                    r->which_secret_door_down = rdoori;
                    o->which_secret_door_up = odoori;
                    
                    r->secret_down_room = o;
                    o->secret_up_room = r;
                }

                if (n->has_secret_exit_right) {
                    auto o = node_rooms[x+1][y];
                    if (!o) {
                        debug("bug");
                        DIE("had secret exit right at %d,%d, but no node exists", x, y);
                    }
                    auto rdoori = random_range(0, r->right_exits.size());
                    auto odoori = random_range(0, o->left_exits.size());
                    if (rdoori >= r->right_exits.size()) {
                        debug("bug");
                    }
                    if (odoori >= o->left_exits.size()) {
                        debug("bug");
                        DIE("bug");
                    }

                    r->which_secret_door_right = rdoori;
                    o->which_secret_door_left = odoori;
                    
                    r->secret_right_room = o;
                    o->secret_left_room = r;
                }
            }
        }
    }
    
    //
    // Join the corridors of each room
    //
    int draw_corridors (void)
    {
        for (auto x = 0; x < map_width; x++) {
            for (auto y = 0; y < map_height; y++) {
                if (getc(x, y, Charmap::DEPTH_WALLS) == Charmap::DOOR) {
                    putc(x, y, Charmap::DEPTH_WALLS, Charmap::WALL);
                }
            }
        }

        auto corridor_count = 0;
        
        for (auto x = 0; x < nodes->nodes_width; x++) {
            for (auto y = 0; y < nodes->nodes_height; y++) {

                auto n = nodes->getn(x, y);
                if (!n->depth) {
                    continue;
                }

                if (n->depth == nodes->depth_obstacle) {
                    continue;
                }

                auto r = node_rooms[x][y];

                if (n->has_exit_down) {
                    auto o = node_rooms[x][y+1];
                    
                    auto rdoori = r->which_door_down;
                    auto odoori = o->which_door_up;

                    auto rdoor = r->down_exits[rdoori];
                    auto odoor = o->up_exits[odoori];

                    auto start = r->at + rdoor;
                    auto end = o->at + odoor;
                    
                    r->down_door_at = start;
                    o->up_door_at = end;
                    
                    auto cnt = draw_corridor(start, end, Charmap::CORRIDOR);
                    if (!cnt) {
                        return (0);
                    }
                    corridor_count += cnt;
                }

                if (n->has_exit_right) {
                    auto o = node_rooms[x+1][y];
                    
                    auto rdoori = r->which_door_right;
                    auto odoori = o->which_door_left;

                    auto rdoor = r->right_exits[rdoori];
                    auto odoor = o->left_exits[odoori];

                    auto start = r->at + rdoor;
                    auto end = o->at + odoor;
                    
                    r->right_door_at = start;
                    o->left_door_at = end;
                    
                    auto cnt = draw_corridor(start, end, Charmap::CORRIDOR);
                    if (!cnt) {
                        return (0);
                    }
                    corridor_count += cnt;
                }

                if (n->has_secret_exit_down) {
                    auto o = node_rooms[x][y+1];
                    
                    auto rdoori = r->which_secret_door_down;
                    auto odoori = o->which_secret_door_up;

                    auto rdoor = r->down_exits[rdoori];
                    auto odoor = o->up_exits[odoori];
                    
                    auto start = r->at + rdoor;
                    auto end = o->at + odoor;
                    
                    r->down_secret_door_at = start;
                    o->up_secret_door_at = end;
                    
                    auto cnt = draw_corridor(start, end, Charmap::SECRET_CORRIDOR);
                    if (!cnt) {
                        return (0);
                    }
                    corridor_count += cnt;
                }

                if (n->has_secret_exit_right) {
                    auto o = node_rooms[x+1][y];
                    
                    auto rdoori = r->which_secret_door_right;
                    auto odoori = o->which_secret_door_left;

                    auto rdoor = r->right_exits[rdoori];
                    auto odoor = o->left_exits[odoori];

                    auto start = r->at + rdoor;
                    auto end = o->at + odoor;
                    
                    r->right_secret_door_at = start;
                    o->left_secret_door_at = end;
                    
                    auto cnt = draw_corridor(start, end, Charmap::SECRET_CORRIDOR);
                    if (!cnt) {
                        return (0);
                    }
                    corridor_count += cnt;
                }
            }
        }

        return (corridor_count);
    }
    
    void assign_rooms_to_tiles (void)
    {
        for (auto x = 0; x < nodes->nodes_width; x++) {
            for (auto y = 0; y < nodes->nodes_height; y++) {
                auto r = node_rooms[x][y];
                if (r) {
                    auto n = nodes->getn(x, y);
                    r->depth = n->depth;
                    map_place_room_ptr(r, r->at.x, r->at.y);
                }
            }
        }
    }

    void remove_all_doors (void)
    {
        for (auto x = 0; x < map_width; x++) {
            for (auto y = 0; y < map_height; y++) {
                if (getc(x, y, Charmap::DEPTH_WALLS) == Charmap::DOOR) {
                    putc(x, y, Charmap::DEPTH_WALLS, Charmap::SPACE);
                }
            }
        }
    }
    
    void center_room_layout (void)
    {
        auto minx = map_width;
        auto miny = map_height;
        auto maxx = 0;
        auto maxy = 0;
        
        for (auto x = 0; x < nodes->nodes_width; x++) {
            for (auto y = 0; y < nodes->nodes_height; y++) {
                auto r = node_rooms[x][y];
                if (!r) {
                    continue;
                }
                
                if (r->at.x < minx) {
                    minx = r->at.x;
                }
                if (r->at.y < miny) {
                    miny = r->at.y;
                }
                if (r->at.x + r->width > maxx) {
                    maxx = r->at.x + r->width;
                }
                if (r->at.y + r->height > maxy) {
                    maxy = r->at.y + r->height;
                }
            }
        }
        
        auto dx = (map_width - (maxx - minx)) / 2;
        auto dy = (map_height - (maxy - miny)) / 2;
        
        for (auto x = 0; x < nodes->nodes_width; x++) {
            for (auto y = 0; y < nodes->nodes_height; y++) {
                auto r = node_rooms[x][y];
                if (!r) {
                    continue;
                }
                
                r->at.x -= minx;
                r->at.y -= miny;
                
                r->at.x += dx;
                r->at.y += dy;
            }
        }
    }
    
    void place_doors_between_depth_changes (void)
    {
        for (auto x = 0; x < nodes->nodes_width; x++) {
            for (auto y = 0; y < nodes->nodes_height; y++) {
                auto r = node_rooms[x][y];
                if (!r) {
                    continue;
                }

                if (r->down_room) {
                    auto o = r->down_room;
                    if (!o) {
                        DIE("room linkage bug");
                    }
                    
                    if (r->depth > o->depth) {
                        putc(r->down_door_at.x, r->down_door_at.y, 
                             Charmap::DEPTH_WALLS, Charmap::DOOR);
                    }
                }
                
                if (r->up_room) {
                    auto o = r->up_room;
                    if (!o) {
                        DIE("room linkage bug");
                    }
                    
                    if (r->depth > o->depth) {
                        putc(r->up_door_at.x, r->up_door_at.y, 
                             Charmap::DEPTH_WALLS, Charmap::DOOR);
                    }
                }
                
                if (r->right_room) {
                    auto o = r->right_room;
                    if (!o) {
                        DIE("room linkage bug");
                    }
                    
                    if (r->depth > o->depth) {
                        putc(r->right_door_at.x, r->right_door_at.y, 
                             Charmap::DEPTH_WALLS, Charmap::DOOR);
                    }
                }
                
                if (r->left_room) {
                    auto o = r->left_room;
                    if (!o) {
                        DIE("room linkage bug");
                    }
                    
                    if (r->depth > o->depth) {
                        putc(r->left_door_at.x, r->left_door_at.y, 
                             Charmap::DEPTH_WALLS, Charmap::DOOR);
                    }
                }
                
                if (r->secret_down_room) {
                    auto o = r->secret_down_room;
                    if (!o) {
                        DIE("room linkage bug");
                    }
                    
                    putc(r->down_secret_door_at.x, r->down_secret_door_at.y, 
                         Charmap::DEPTH_WALLS, Charmap::SECRET_DOOR);
                    putc(o->up_secret_door_at.x, o->up_secret_door_at.y, 
                         Charmap::DEPTH_WALLS, Charmap::SECRET_DOOR);
                }
                
                if (r->secret_up_room) {
                    auto o = r->secret_up_room;
                    if (!o) {
                        DIE("room linkage bug");
                    }
                    
                    putc(r->up_secret_door_at.x, r->up_secret_door_at.y, 
                         Charmap::DEPTH_WALLS, Charmap::SECRET_DOOR);
                    putc(o->down_secret_door_at.x, o->down_secret_door_at.y, 
                         Charmap::DEPTH_WALLS, Charmap::SECRET_DOOR);
                }
                
                if (r->secret_right_room) {
                    auto o = r->secret_right_room;
                    if (!o) {
                        DIE("room linkage bug");
                    }
                    
                    putc(r->right_secret_door_at.x, r->right_secret_door_at.y, 
                         Charmap::DEPTH_WALLS, Charmap::SECRET_DOOR);
                    putc(o->left_secret_door_at.x, o->left_secret_door_at.y, 
                         Charmap::DEPTH_WALLS, Charmap::SECRET_DOOR);
                }
                
                if (r->secret_left_room) {
                    auto o = r->secret_left_room;
                    if (!o) {
                        DIE("room linkage bug");
                    }
                    
                    putc(r->left_secret_door_at.x, r->left_secret_door_at.y, 
                         Charmap::DEPTH_WALLS, Charmap::SECRET_DOOR);
                    putc(o->right_secret_door_at.x, o->right_secret_door_at.y, 
                         Charmap::DEPTH_WALLS, Charmap::SECRET_DOOR);
                }
            }
        }
    }
};

class Dungeon *dungeon_test (void)
{
#if 0
    auto x = 1000 ;
    while (x--) {
        //
        // smaller node numbers mean larger rooms
        //
        /* auto d = new */ Dungeon(MAP_WIDTH, MAP_HEIGHT, 6, 3, x);
    }

    return (nullptr);
#else
int x = 666;
CON("seed: %d", x);
mysrand(x);
    auto d = new Dungeon(MAP_WIDTH, MAP_HEIGHT, 8, 5, x);

    return (d);
#endif
}
