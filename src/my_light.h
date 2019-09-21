//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#pragma once

#ifndef _MY_LIGHT_H
#define _MY_LIGHT_H

#include <memory>
#include "my_game.h"
#include "my_point.h"
#include "my_thing.h"

typedef enum {
    LIGHT_QUALITY_POINT,
    LIGHT_QUALITY_LOW,
    LIGHT_QUALITY_HIGH,
} LightQuality;

typedef struct {
    double depth_closest;
    double depth_furthest;
    double sinr;
    double cosr;
} Ray;

class Light
{
private:

public:
    Light (void);
    ~Light (void);
    //
    // Where the light is. Rays are calculated at this point and invalidated
    // if the light moves.
    //
    fpoint             at;

    //
    // The owner of the light, so we don't block our own light.
    //
    Thingp             owner;

    double             flicker_radius;
    uint8_t            flicker {0};

    //
    // Precalculated light rays.
    //
    double              strength;
    uint16_t            max_light_rays;
    std::vector<Ray>    ray;
    std::vector<float>  glbuf;
    LightQuality        quality;
    color               col;

    uint8_t             is_being_destroyed:1 {};

    void destroy();
    void destroyed(void);
    void reset(void);
    void calculate(void);
    void render_triangle_fans(void);
    void render_point_light(void);
    void render(int fbo, int pass);

    void log_(const char *fmt, va_list args); // compile error without
    void log(const char *fmt, ...) __attribute__ ((format (printf, 2, 3)));
    void die_(const char *fmt, va_list args); // compile error without
    void die(const char *fmt, ...) __attribute__ ((format (printf, 2, 3)));
    void con_(const char *fmt, va_list args); // compile error without
    void con(const char *fmt, ...) __attribute__ ((format (printf, 2, 3)));
    void minicon_(const char *fmt, va_list args); // compile error without
    void minicon(const char *fmt, ...) __attribute__ ((format (printf, 2, 3)));
    void err_(const char *fmt, va_list args); // compile error without
    void err(const char *fmt, ...) __attribute__ ((format (printf, 2, 3)));
    void dbg(const char *fmt, ...) __attribute__ ((format (printf, 2, 3)));
};

extern Lightp light_new(Thingp owner,
                        fpoint at,
                        double strength,
                        LightQuality quality,
                        color col);
extern void lights_render_points(int minx, int miny, 
                                 int maxx, int maxy, int fbo, int pass);
extern void lights_render_high_quality(int minx, int miny, 
                                       int maxx, int maxy, int fbo);

#endif // LIGHT_H 
