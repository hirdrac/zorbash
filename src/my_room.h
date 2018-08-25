/*
 * Copyright (C) 2018 goblinhack@gmail.com
 *
 * See the LICENSE file for license.
 */

#include "my_charmap.h"

typedef std::shared_ptr< class Room > Roomp;
typedef std::vector<Roomp> Rooms;

class Room
{
private:
public:
    static uint32_t room_count;
    static Rooms all_rooms;

    Room (void)
    {
        this->roomno = this->room_count;
        this->room_count++;

        newptr(this, "room");
    }

    ~Room (void)
    {
        oldptr(this);
    }

    /*
     * Unique per room.
     */
    uint32_t                 roomno {0};
    std::vector<std::string> data[Charmap::DEPTH_MAX];
    int                      width {};
    int                      height {};
    
    /*
     * All possible exits
     */
    std::vector<point>       left_exits;
    std::vector<point>       right_exits;
    std::vector<point>       up_exits;
    std::vector<point>       down_exits;
    
    bool                    dir_up       {false};
    bool                    dir_down     {false};
    bool                    dir_left     {false};
    bool                    dir_right    {false};
    bool                    is_entrance  {false};
    bool                    is_exit      {false};
    bool                    is_lock      {false};
    bool                    is_key       {false};

    /***********************************************************************
     * This is all room status that changes when rooms are placed.
     * The above is const.
     ***********************************************************************/
    point                    at {};
    point                    rollback_at {};
    
    /*
     * Set when a node uses this room
     */
    uint32_t                 depth {0};

    /*
     * Final placement of this room in the dungeon. 
     */
    bool                     placed {false};

    point                    left_door_at;
    point                    right_door_at;
    point                    up_door_at;
    point                    down_door_at;
    
    point                    left_secret_door_at;
    point                    right_secret_door_at;
    point                    up_secret_door_at;
    point                    down_secret_door_at;
    
    Roomp                    left_room {};
    Roomp                    right_room {};
    Roomp                    up_room {};
    Roomp                    down_room {};
    
    Roomp                    secret_left_room {};
    Roomp                    secret_right_room {};
    Roomp                    secret_up_room {};
    Roomp                    secret_down_room {};
    
    uint8_t                  which_secret_door_up {0};
    uint8_t                  which_secret_door_down {0};
    uint8_t                  which_secret_door_left {0};
    uint8_t                  which_secret_door_right {0};
    uint8_t                  which_door_up {0};
    uint8_t                  which_door_down {0};
    uint8_t                  which_door_left {0};
    uint8_t                  which_door_right {0};
    
    //
    // Temp used for skipping rooms in dungeon placement
    // 
    bool                     skip {};

    static Roomp room_new(void);

    void create_rotated_clones(void);
    void find_exits(void);
    void finalize(void);
    void dump(void);
};
