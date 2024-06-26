//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_array_bounds_check.hpp"
#include "my_game.hpp"
#include "my_math.hpp"
#include "my_monst.hpp"
#include "my_ptrcheck.hpp"
#include "my_thing.hpp"

bool Thing::attempt_to_tame_with(point target_at, Thingp what)
{
  TRACE_NO_INDENT();

  FOR_ALL_MONSTS(level, t, target_at.x, target_at.y)
  {
    if (! t->is_alive_monst()) {
      continue;
    }

    if (attempt_to_tame_with(t, what)) {
      return true;
    }
    break;
  }
  FOR_ALL_THINGS_END()

  return false;
}

bool Thing::attempt_to_tame_with(Thingp it, Thingp what)
{
  TRACE_NO_INDENT();

  if (! it->is_tameable()) {
    return false;
  }

  if (it->leader() == this) {
    return false;
  }

  //
  // Smarter more dominant things can tame others.
  //
  if (d1000() + (stat_int_total() * 10) + (stat_psi_total() * 10) >= it->chance_d1000_tameable()) {
    return false;
  }

  if (! it->can_eat(what)) {
    return false;
  }

  if (is_player()) {
    msg("%%fg=green$You tame %s.%%fg=reset$", it->text_the().c_str());
  } else {
    msg("%s tames %s.", text_The().c_str(), it->text_the().c_str());
  }

  if (it->is_sleeping) {
    it->wake("food");
  } else {
    it->eat(what);
  }

  it->leader_set(this);

  return true;
}
