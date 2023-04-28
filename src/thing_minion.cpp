//
// Copyright Neil McGill, goblinhack@gmail.com
//

// REMOVED #include "my_array_bounds_check.hpp"
#include "my_game.hpp"
// REMOVED #include "my_globals_extra.hpp"
#include "my_monst.hpp"
// REMOVED #include "my_ptrcheck.hpp"
#include "my_thing.hpp"

int Thing::minion_count(void)
{
  TRACE_NO_INDENT();
  if (maybe_infop()) {
    return (int) infop()->minions.size();
  }
  return 0;
}

int Thing::is_minion(void)
{
  TRACE_NO_INDENT();
  return (is_minion_set || tp()->is_minion());
}

int Thing::distance_minion_vision_shared(void)
{
  TRACE_NO_INDENT();
  return (tp()->distance_minion_vision_shared());
}

int Thing::minion_limit(void)
{
  TRACE_NO_INDENT();
  return (tp()->minion_limit());
}
