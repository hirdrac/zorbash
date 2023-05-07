//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_game.hpp"
#include "my_monst.hpp"
#include "my_thing.hpp"

int Thing::stat_dex_total(void)
{
  TRACE_AND_INDENT();

  int stat = 0;
  int prev = 0;

  stat = stat_dex();
  prev = stat;
  if (stat) {
    dbg3("Dex: %d", stat);
  }

  stat += stat_dex_bonus();
  if (stat != prev) {
    prev = stat;
    dbg3("Dex: with mod (%s): %d", bonus_to_string(stat_dex_bonus()).c_str(), stat);
  }

  FOR_ALL_EQUIP(e)
  {
    auto iter = equip_get(e);
    if (iter) {
      if (iter->stat_dex_bonus()) {
        stat += iter->stat_dex_total() - 10;
      }
      if (stat != prev) {
        prev = stat;
        dbg3("Dex: with (%s %d): %d", iter->to_short_string().c_str(), iter->stat_dex_total(), stat);
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
        if (iter->stat_dex_bonus()) {
          stat += iter->stat_dex_total() - 10;
        }
        if (stat != prev) {
          prev = stat;
          dbg3("Dex: with (%s %d): %d", iter->to_short_string().c_str(), iter->stat_dex_total(), stat);
        }
      }
    }

    FOR_ALL_BUFFS(id)
    {
      auto iter = level->thing_find(id);
      if (iter) {
        if (iter->stat_dex_bonus()) {
          stat += iter->stat_dex_total() - 10;
        }
        if (stat != prev) {
          prev = stat;
          dbg3("Dex: with (%s %d): %d", iter->to_short_string().c_str(), iter->stat_dex_total(), stat);
        }
      }
    }

    FOR_ALL_DEBUFFS(id)
    {
      auto iter = level->thing_find(id);
      if (iter) {
        if (iter->stat_dex_bonus()) {
          stat += iter->stat_dex_total() - 10;
        }
        if (stat != prev) {
          prev = stat;
          dbg3("Dex: with (%s %d): %d", iter->to_short_string().c_str(), iter->stat_dex_total(), stat);
        }
      }
    }

    FOR_ALL_SKILLS(id)
    {
      auto iter = level->thing_find(id);
      if (iter && iter->is_activated) {
        if (iter->stat_dex_bonus()) {
          stat += iter->stat_dex_total() - 10;
        }
        if (stat != prev) {
          prev = stat;
          dbg3("Dex: with (%s %d): %d", iter->to_short_string().c_str(), iter->stat_dex_total(), stat);
        }
      }
    }
  }

  if (stat_dex_bonus()) {
    auto enchant = enchant_count_get();
    stat += enchant;
    if (stat != prev) {
      prev = stat;
      dbg3("Dex: with enchant %d: %d", enchant, stat);
    }
  }

  return stat;
}

int Thing::stat_dex(void)
{
  TRACE_NO_INDENT();
  if (maybe_infop()) {
    return (infop()->stat_dex);
  }
  return 0;
}

int Thing::stat_dex_set(int v)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_dex = v);
  return n;
}

int Thing::stat_dex_decr(int v)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_dex -= v);
  return n;
}

int Thing::stat_dex_incr(int v)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_dex += v);
  return n;
}

int Thing::stat_dex_decr(void)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_dex--);
  return n;
}

int Thing::stat_dex_incr(void)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_dex++);
  return n;
}

////////////////////////////////////////////////////////////////////////////
// stat_dex_bonus
////////////////////////////////////////////////////////////////////////////
int Thing::stat_dex_bonus(void)
{
  TRACE_NO_INDENT();
  if (maybe_infop()) {
    return (infop()->stat_dex_bonus);
  }
  return 0;
}

int Thing::stat_dex_bonus_set(int v)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_dex_bonus = v);
  return n;
}

int Thing::stat_dex_bonus_decr(int v)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_dex_bonus -= v);
  return n;
}

int Thing::stat_dex_bonus_incr(int v)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_dex_bonus += v);
  return n;
}

int Thing::stat_dex_bonus_decr(void)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_dex_bonus--);
  return n;
}

int Thing::stat_dex_bonus_incr(void)
{
  TRACE_NO_INDENT();
  if (is_player()) {
    game->set_request_to_remake_rightbar();
  }
  new_infop();
  auto n = (infop()->stat_dex_bonus++);
  return n;
}
