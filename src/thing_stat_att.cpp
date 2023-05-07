//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_game.hpp"
#include "my_monst.hpp"
#include "my_thing.hpp"

int Thing::stat_att_total()
{
  TRACE_AND_INDENT();

  int stat = 0;
  int prev = 0;

  stat = stat_att();
  prev = stat;
  if (stat) {
    dbg3("Att: %d", stat);
  }

  stat += stat_att_bonus();
  if (stat != prev) {
    prev = stat;
    dbg3("Att: with mod (%s): %d", bonus_to_string(stat_att_bonus()).c_str(), stat);
  }

  //
  // Add str bonus to att
  //
  if (is_monst() || is_player()) {
    int str_total = stat_str_total();
    stat += stat_to_bonus(str_total);
    if (stat != prev) {
      prev = stat;
      dbg3("Att: with: (str %d): %d", str_total, stat);
    }
  }

  FOR_ALL_EQUIP(e)
  {
    auto iter = equip_get(e);
    if (iter) {
      if (iter->stat_att_bonus()) {
        stat += iter->stat_att_total() - 10;
        if (stat != prev) {
          prev = stat;
          dbg3("Att: with (%s %d): %d", iter->to_short_string().c_str(), iter->stat_att_total(), stat);
        }
      }
    }
  }

  if (maybe_itemsp()) {
    FOR_ALL_CARRYING(id)
    {
      auto iter = level->thing_find(id);
      if (iter) {
        //
        // Don't count boots for example twice
        //
        if (is_equipped(iter)) {
          continue;
        }
        //
        // Things that are equipped must be equipped to get the benefit.
        // Other items give the benefit by just being carried.
        //
        if (iter->is_auto_equipped()) {
          continue;
        }
        if (iter->stat_att_bonus()) {
          stat += iter->stat_att_total() - 10;
        }
        if (stat != prev) {
          prev = stat;
          dbg3("Att: with (%s %d): %d", iter->to_short_string().c_str(), iter->stat_att_total(), stat);
        }
      }
    }

    FOR_ALL_BUFFS(id)
    {
      auto iter = level->thing_find(id);
      if (iter) {
        if (iter->stat_att_bonus()) {
          stat += iter->stat_att_total() - 10;
        }
        if (stat != prev) {
          prev = stat;
          dbg3("Att: with (%s %d): %d", iter->to_short_string().c_str(), iter->stat_att_total(), stat);
        }
      }
    }

    FOR_ALL_DEBUFFS(id)
    {
      auto iter = level->thing_find(id);
      if (iter) {
        if (iter->stat_att_bonus()) {
          stat += iter->stat_att_total() - 10;
        }
        if (stat != prev) {
          prev = stat;
          dbg3("Att: with (%s %d): %d", iter->to_short_string().c_str(), iter->stat_att_total(), stat);
        }
      }
    }

    FOR_ALL_SKILLS(id)
    {
      auto iter = level->thing_find(id);
      if (iter && iter->is_activated) {
        if (iter->stat_att_bonus()) {
          stat += iter->stat_att_total() - 10;
        }
        if (stat != prev) {
          prev = stat;
          dbg3("Att: with (%s %d): %d", iter->to_short_string().c_str(), iter->stat_att_total(), stat);
        }
      }
    }
  }

  if (stat_att_bonus()) {
    auto enchant = enchant_count_get();
    stat += enchant;
    if (stat != prev) {
      prev = stat;
      dbg3("Att: with enchant %d: %d", enchant, stat);
    }
  }

  //
  // Size modifiers
  //
  if (is_monst() || is_player()) {
    stat += size_modifier();
    if (stat != prev) {
      prev = stat;
      dbg3("Att: with size modifier: %d", stat);
    }
  }

  return stat;
}

int Thing::stat_att_penalties_total(void)
{
  TRACE_NO_INDENT();

  int penalty = 0;
  int prev    = 0;

  //
  // Positional penalties
  //
  if (stuck_count() && stat_att_penalty_when_stuck()) {
    int p = stat_att_penalty_when_stuck() + stuck_count();
    p     = std::min(p, stat_att_penalty_when_stuck_max());
    penalty += p;
    if (penalty != prev) {
      prev = penalty;
      dbg3("Att penalty: stuck %d", p);
    }
  } else if (idle_count() && stat_att_penalty_when_idle()) {
    int p = stat_att_penalty_when_idle() + idle_count();
    p     = std::min(p, stat_att_penalty_when_idle_max());
    penalty += p;
    if (penalty != prev) {
      prev = penalty;
      dbg3("Att penalty: idle %d", p);
    }
  }

  //
  // Hunger penalties
  //
  if (is_hunger_level_starving) {
    int p = THING_HUNGER_PENALTY_WHEN_STARVING;
    penalty += p;
    if (penalty != prev) {
      prev = penalty;
      dbg3("Att penalty: starving %d", p);
    }
  } else if (is_hunger_level_hungry) {
    int p = THING_HUNGER_PENALTY_WHEN_HUNGRY;
    penalty += p;
    if (penalty != prev) {
      prev = penalty;
      dbg3("Att penalty: hunger %d", p);
    }
  }

  //
  // Terrain penalties
  //
  if (! is_aquatic() && ! buff_is_aquatic()) {
    if (level->is_deep_water(curr_at)) {
      int p = stat_att_penalty_when_in_deep_water();
      if (p) {
        if (is_able_to_swim()) {
          p /= 2;
        }
        if (is_heavy()) {
          p *= 2;
        }
        if (is_stone()) {
          p *= 2;
        }
        penalty += p;
        if (penalty != prev) {
          prev = penalty;
          dbg3("Att penalty: with (in deep water %d): %d", p, penalty);
        }
      }
    } else if (level->is_shallow_water(curr_at)) {
      int p = stat_att_penalty_when_in_shallow_water();
      if (p) {
        if (is_able_to_swim()) {
          p /= 2;
        }
        penalty += p;
        if (penalty != prev) {
          prev = penalty;
          dbg3("Att penalty: with (in shallow water %d): %d", p, penalty);
        }
      }
    }
  }

  if (penalty) {
    dbg3("Att penalty: %d", penalty);
  }
  return penalty;
}

int Thing::stat_att(void)
{
  TRACE_NO_INDENT();
  if (maybe_infop()) {
    return (infop()->stat_att);
  }
  return 0;
}

int Thing::stat_att_set(int v)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_att = v);
  return n;
}

int Thing::stat_att_decr(int v)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_att -= v);
  return n;
}

int Thing::stat_att_incr(int v)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_att += v);
  return n;
}

int Thing::stat_att_decr(void)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_att--);
  return n;
}

int Thing::stat_att_incr(void)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_att++);
  return n;
}

////////////////////////////////////////////////////////////////////////////
// stat_att_bonus
////////////////////////////////////////////////////////////////////////////
int Thing::stat_att_bonus(void)
{
  TRACE_NO_INDENT();
  if (maybe_infop()) {
    return (infop()->stat_att_bonus);
  }
  return 0;
}

int Thing::stat_att_bonus_set(int v)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_att_bonus = v);
  return n;
}

int Thing::stat_att_bonus_decr(int v)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_att_bonus -= v);
  return n;
}

int Thing::stat_att_bonus_incr(int v)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_att_bonus += v);
  return n;
}

int Thing::stat_att_bonus_decr(void)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_att_bonus--);
  return n;
}

int Thing::stat_att_bonus_incr(void)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_att_bonus++);
  return n;
}
