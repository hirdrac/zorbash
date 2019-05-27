//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#include <algorithm>
#include "my_main.h"
#include "my_thing.h"
#include "my_dmap.h"
#include "my_math.h"

bool Thing::will_attack (const Thingp itp)
{
    auto me = tp;
    auto it = itp->tp;

    if (tp_is_meat_eater(me)) {
        if (tp_is_made_of_meat(it) || tp_is_blood(it)) {
            return (true);
        }
    }
    return (false);
}

bool Thing::will_avoid (const Thingp itp)
{
    auto me = tp;
    auto it = itp->tp;

    if (tp_is_made_of_meat(me)) {
        if (tp_is_meat_eater(it)) {
            return (true);
        }
    }
    return (false);
}

bool Thing::will_eat (const Thingp itp)
{
    auto me = tp;
    auto it = itp->tp;

    if (tp_is_meat_eater(me)) {
        if (tp_is_made_of_meat(it) || tp_is_blood(it)) {
            return (true);
        }
    }
    return (false);
}

bool Thing::will_prefer (const Thingp itp)
{
    auto me = tp;
    auto it = itp->tp;

    if (tp_is_water_dweller(me)) {
        if (tp_is_water(it) || tp_is_deep_water(it)) {
            return (true);
        }
    }
    return (false);
}

bool Thing::is_obstacle_for_me (point p)
{
    if (game.state.map.is_wall_at(p)) {
        return (true);
    }
    if (game.state.map.is_rock_at(p)) {
        return (true);
    }
    if (game.state.map.is_door_at(p)) {
        return (true);
    }
    if (game.state.map.is_lava_at(p)) {
        return (true);
    }

    //
    // This is more of a look at the future position that some monst is
    // already walking toward
    //
    if (game.state.map.is_monst_at(p)) {
        return (true);
    }

    //
    // Avoid threats and treat them as obstacles
    //
    for (auto i : game.state.map.all_non_boring_things_at[p.x][p.y]) {
        auto it = i.second;
        if (it == this) {
            continue;
        }

        if (will_avoid(it)) {
            return (true);
        }
    }

    return (false);
}

//
// Lower scores are more preferred
// k
bool Thing::is_goal_for_me (point p, int priority, double *score)
{
    double distance_scale = distance(mid_at, fpoint(p.x, p.y));
    if (!distance_scale) {
        distance_scale = 1.0;
    }

    //
    // Check from highest (0) to lowest priority for things to do
    //
    switch (priority) {
    case 0:
        if (is_starving) {
            for (auto i : game.state.map.all_non_boring_things_at[p.x][p.y]) {
                auto it = i.second;
                if (it == this) {
                    continue;
                }

                if (will_eat(it)) {
                    *score -= 1000 / distance_scale;
                    return (true);
                }
            }
        }
        break;
    case 1:
        if (is_hungry) {
            for (auto i : game.state.map.all_non_boring_things_at[p.x][p.y]) {
                auto it = i.second;
                if (it == this) {
                    continue;
                }

                if (will_eat(it)) {
                    *score -= 500;
                    return (true);
                }

                if (will_attack(it)) {
                    *score -= 1000 / distance_scale;
                    return (true);
                }
            }
        }
        break;
    case 2:
        for (auto i : game.state.map.all_non_boring_things_at[p.x][p.y]) {
            auto it = i.second;
            if (it == this) {
                continue;
            }

            if (will_prefer(it)) {
                return (true);
            }
            break;
        }
    }
    return (false);
}

fpoint Thing::get_next_hop (void)
{
    auto minx = 0;
    auto miny = 0;
    auto maxx = MAP_WIDTH;
    auto maxy = MAP_HEIGHT;
    fpoint fstart;

    if (is_wall_clinger()) {
        fstart = ground_at;
    } else {
        fstart = mid_at;
    }

    point start((int)fstart.x, (int)fstart.y);

    for (auto y = miny; y < maxy; y++) {
        for (auto x = minx; x < maxx; x++) {
            point p(x, y);
            if (is_obstacle_for_me(p)) {
                dmap_scent->val[x][y] = DMAP_IS_WALL;
                dmap_goals->val[x][y] = DMAP_IS_WALL;
            } else {
                dmap_scent->val[x][y] = DMAP_IS_PASSABLE;
                dmap_goals->val[x][y] = DMAP_IS_PASSABLE;
            }
        }
    }

    //
    // We want to find how far everything is from us.
    //
    dmap_scent->val[start.x][start.y] = DMAP_IS_GOAL;

    point tl(minx, miny);
    point br(maxx, maxy);
    dmap_process(dmap_scent, tl, br);
    // dmap_print(dmap_scent);

    //
    // Find all the possible goals we can smell.
    //
    std::multiset<Goal> goals;
    int oldest = 0;

    for (auto y = miny; y < maxy; y++) {
        for (auto x = minx; x < maxx; x++) {
            point p(x, y);
            fpoint fp(x, y);
            if (dmap_scent->val[x][y] > tp->ai_scent_distance) {
                continue;
            }

            //
            // Look at the cell for each priority level. This means we can
            // have multiple goals per cell. We combine them all together.
            //
            for (auto priority = 0; priority < 3; priority++) {
                double score = 0;
                if (!is_goal_for_me(p, priority, &score)) {
                    continue;
                }

                score += dmap_scent->val[p.x][p.y];
                score += 100 * (priority + 1);

                Goal goal(score);
                goal.at = p;
                goals.insert(goal);

                //
                // Also take note of the oldest cell age; we will use this
                // later.
                //
                int age = age_map->val[p.x][p.y];
                oldest = std::min(oldest, age);
            }
        }
    }

    //
    // Combine the scores of multiple goals on each cell.
    //
    double cell_totals[MAP_WIDTH][MAP_HEIGHT];
    memset(&cell_totals, 0, sizeof(cell_totals));
    double highest_least_preferred = 0;
    double lowest_most_preferred = 0;
    const double wanderlust = 10;

    {
        uint8_t walked[MAP_WIDTH][MAP_HEIGHT];
        memset(&walked, 0, sizeof(walked));
        for (auto g : goals) {
            auto p = g.at;
            if (!walked[p.x][p.y]) {
                int age = age_map->val[p.x][p.y];
                cell_totals[p.x][p.y] = wanderlust * (age - oldest);
            }

            walked[p.x][p.y] = true;
            cell_totals[p.x][p.y] += g.score;
            auto score = cell_totals[p.x][p.y];

            //
            // Find the highest/least preferred score so we can scale all
            // the goals later.
            //
            highest_least_preferred = std::max(highest_least_preferred, score);
            lowest_most_preferred = std::min(lowest_most_preferred, score);
        }
    }

    //
    // Scale the goals so they will fit in the dmap.
    //
    for (auto g : goals) {
        auto p = g.at;
        auto score = cell_totals[p.x][p.y];
        score = score - lowest_most_preferred;
        score /= (highest_least_preferred - lowest_most_preferred);
        score *= DMAP_IS_PASSABLE / 2;
        dmap_goals->val[p.x][p.y] = score;
    }

    //
    // Record we've neen here.
    //
    age_map->val[start.x][start.y]++;

    //
    // Find the best next-hop to the best goal.
    //

    //
    // By commenting this out we will also consider staying put and not
    // moving as an option
    //
    dmap_goals->val[start.x][start.y] = DMAP_IS_PASSABLE;

    //
    // Wall clingers create a dmap that is essentially a border around
    // the existing walls
    //
    const double wall_clinger_scale = 3;
    if (is_wall_clinger()) {
        double s, c;
#if 0
CON("                 ");
CON("                 ");
CON("                 ");
CON("                 ");
CON("                 ");
CON("                 ");
CON("                 ");
CON("                 ");
CON("                 ");
CON("                 ");
CON("                 ");
CON("                 ");
CON("                 ");
CON("                 ");
CON("                 ");
CON("                 ");
CON("                 ");
CON("                 ");
#endif
        sincos(rot + RAD_270, &s, &c);
#if 0
        dmap_print(dmap_goals, start);
#endif
        dmap_scale_and_recenter(dmap_goals, fstart, (int)wall_clinger_scale);
        //
        // This "zoomed in" dmap is centered on the creature with each
        // neighboring tile now taking up wall_clinger_scale^2 cells.
        // This allows us to choose a path around the edge of a single tile.
        // 
        start.x = MAP_WIDTH / 2;
        start.y = MAP_HEIGHT / 2;
        dmap_convert_to_wall_clinging(dmap_goals);
    }

#if 0
    dmap_print(dmap_goals, start);
#endif
    dmap_process(dmap_goals, tl, br);

    //
    // Move diagonally if not blocked by walls
    //
    auto hops = dmap_solve(dmap_goals, start);
    point best;
    if (hops.size() >= 2) {
        if (dmap_can_i_move_diagonally(dmap_goals, start, hops[0], hops[1])) {
            best = hops[1];
        } else {
            best = hops[0];
        }
    } else if (hops.size() >= 1) {
        best = hops[0];
    } else {
        best = start;
    }

    fpoint fbest;
    if (is_wall_clinger()) {
        fbest.x = mid_at.x + ((1.0 / wall_clinger_scale) * (best.x - start.x));
        fbest.y = mid_at.y + ((1.0 / wall_clinger_scale) * (best.y - start.y));

        //
        // Find which wall is the closest to cling onto post move.
        //
        fpoint closest(-1, -1);
        double closest_dist = 999;

        auto x = (int)fbest.x;
        auto y = (int)fbest.y;
        for (auto dx = -1; dx <= 1; dx++) {
            for (auto dy = -1; dy <= 1; dy++) {
                fpoint n(x + dx, y + dy);
//CON("XXX try     %f %f", n.x, n.y);
                if (!game.state.map.is_oob(n)) {
                    if (game.state.map.is_wall[(int)n.x][(int)n.y]) {
                        auto d = DISTANCE(n.x, n.y, fbest.x, fbest.y);
//CON("XXX try     %f %f dx %d dy %d dist %f ", n.x, n.y, dx, dy, d);
                        if (d < closest_dist) {
                            closest_dist = d;
                            closest = n;
                        }
                    }
                }
            }
        }

        if (closest.x > 0) {
            if (closest.y > 0) {
//CON("XXX 1");
            } else if (closest.y < 0) {
//CON("XXX 2");
            } else {
//CON("XXX 3");
            }
        } else if (closest.x > 0) {
            if (closest.y > 0) {
//CON("XXX 4");
            } else if (closest.y < 0) {
//CON("XXX 5");
            } else {
//CON("XXX 6");
            }
        }
    } else {
        fbest.x = best.x;
        fbest.y = best.y;
    }

    return (fbest);
}
