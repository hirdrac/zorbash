/*
 * Copyright (C) 2018 goblinhack@gmail.com
 *
 * See the LICENSE file for license.
 */

#include "my_main.h"
#include "my_python.h"
#include "my_tile.h"
#include "my_room.h"

PyObject *map_load_room_ (PyObject *obj, PyObject *args, PyObject *keywds)
{_
    char *room_name = 0;
    int xxx = 0;
    int yyy = 0;
    PyObject *py_floor = 0;
    PyObject *py_walls = 0;
    PyObject *py_items = 0;

    static char *kwlist[] = {
        (char*) "floor", 
        (char*) "walls", 
        (char*) "items", 
        (char*) "xxx", 
        (char*) "yyy", 
        (char*) "room_name", 
        0};

    if (!PyArg_ParseTupleAndKeywords(args, keywds, 
                                     "OOO|iis", 
                                     kwlist, 
                                     &py_floor,
                                     &py_walls,
                                     &py_items,
                                     &xxx, 
                                     &yyy, 
                                     &room_name)) {
        Py_RETURN_NONE;
    }

    if (!py_floor) {
        ERR("map_load_room, missing floor data");
        Py_RETURN_NONE;
    }
    if (!py_walls) {
        ERR("map_load_room, missing walls data");
        Py_RETURN_NONE;
    }
    if (!py_items) {
        ERR("map_load_room, missing objects data");
        Py_RETURN_NONE;
    }

    auto r = Room::fixed_room_new();

    int floor_lines = PyList_Size(py_floor);
    int walls_lines = PyList_Size(py_walls);
    int items_lines  = PyList_Size(py_items);
    int i;

    if (floor_lines != walls_lines) {
        ERR("mismatch in floor vs wall lines");
        py_err();
    }

    if (items_lines != walls_lines) {
        ERR("mismatch in items vs wall lines");
        py_err();
    }

    for (i=0; i<floor_lines; i++){
        auto o = PyList_GetItem(py_floor, i); /* Can't fail */
        if (!o) {
            continue;
        }

        r->floor_data.push_back(py_obj_to_string(o));
    }

    for (i=0; i<walls_lines; i++){
        auto o = PyList_GetItem(py_walls, i); /* Can't fail */
        if (!o) {
            continue;
        }

        r->walls_data.push_back(py_obj_to_string(o));
    }

    for (i=0; i<items_lines; i++){
        auto o = PyList_GetItem(py_items, i); /* Can't fail */
        if (!o) {
            continue;
        }

        r->items_data.push_back(py_obj_to_string(o));
    }

    r->finalize();

    Py_RETURN_NONE;
}
