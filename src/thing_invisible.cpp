//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_level.hpp"
#include "my_thing.hpp"

void Thing::invisible_tick(void) { is_currently_invisible = is_invisible(); }

bool Thing::is_invisible(void)
{
  TRACE_NO_INDENT();

  auto old_is_currently_invisible = is_currently_invisible;
  bool new_is_currently_invisible = tp()->is_invisible();

  if (buff_is_invisible()) {
    new_is_currently_invisible = true;
  }

  if (old_is_currently_invisible != new_is_currently_invisible) {
    level_pop();
    is_currently_invisible = new_is_currently_invisible;
    level_push();
  }

  return is_currently_invisible;
}

bool Thing::can_see_is_invisible(Thingp what)
{
  if (! what->is_currently_invisible) {
    return true;
  }

  if (is_able_to_see_invisible()) {
    return true;
  }

  //
  // If the thing is adjacent to us and has attacked us, then we should be aware
  // of a translucent enemy close to us.
  //
  if (is_enemy(what)) {
    if ((abs(what->curr_at.x - curr_at.x) <= 1) && (abs(what->curr_at.y - curr_at.y) <= 1)) {
      return true;
    }
  }

  return false;
}
