//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_game.hpp"
#include "my_monst.hpp"
#include "my_thing.hpp"

void Thing::gas_confused_tick(void)
{
  TRACE_NO_INDENT();

  if (! is_air_breather()) {
    return;
  }

  //
  // How strong is the gas?
  //
  auto intensity = level->is_gas_confusion(curr_at.x, curr_at.y) / 20;
  if (! intensity) {
    return;
  }

  dbg("Confusion gas tick");
  TRACE_AND_INDENT();

  //
  // Due to location checks, we check the start and end move so we end
  // up being paralysed twice per move. As this is a bit cruel, check
  //
  if (game->tick_current == tick_last_gas_confusion_exposure()) {
    return;
  }
  tick_last_gas_confusion_exposure_set(game->tick_current);

  if (d20() < stat_con()) {
    if (is_player()) {
      msg("You hold your breath in the confusion gas!");
    }
    return;
  }

  confused_count_incr(5);

  if (stamina()) {
    if (is_player()) {
      msg("%%fg=yellow$You are confused!%%fg=reset$");
    }
    stamina_decr(d20());
  } else {
    if (is_player()) {
      msg("You are still very very confused!");
    }
  }
}

////////////////////////////////////////////////////////////////////////////
// tick_last_gas_confusion_exposure
////////////////////////////////////////////////////////////////////////////
int Thing::tick_last_gas_confusion_exposure(void)
{
  TRACE_NO_INDENT();
  if (maybe_infop()) {
    return (infop()->tick_last_gas_confusion_exposure);
  }
  return 0;
}

int Thing::tick_last_gas_confusion_exposure_set(uint32_t v)
{
  TRACE_NO_INDENT();
  new_infop();
  return (infop()->tick_last_gas_confusion_exposure = v);
}

int Thing::tick_last_gas_confusion_exposure_decr(uint32_t v)
{
  TRACE_NO_INDENT();
  new_infop();
  return (infop()->tick_last_gas_confusion_exposure -= v);
}

int Thing::tick_last_gas_confusion_exposure_incr(uint32_t v)
{
  TRACE_NO_INDENT();
  new_infop();
  return (infop()->tick_last_gas_confusion_exposure += v);
}

int Thing::tick_last_gas_confusion_exposure_decr(void)
{
  TRACE_NO_INDENT();
  new_infop();
  return (infop()->tick_last_gas_confusion_exposure--);
}

int Thing::tick_last_gas_confusion_exposure_incr(void)
{
  TRACE_NO_INDENT();
  new_infop();
  return (infop()->tick_last_gas_confusion_exposure++);
}
