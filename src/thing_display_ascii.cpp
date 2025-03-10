//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_array_bounds_check.hpp"
#include "my_ascii.hpp"
#include "my_color_defs.hpp"
#include "my_game.hpp"
#include "my_thing.hpp"
#include "my_unicode.hpp"
#include "my_wid.hpp"

//
// For things like walls we color them differently so it is easier to see.
//
void Thing::blit_ascii_adjust_color_hue(color &c, bool fg)
{
  if (fg) {
    if (gfx_ascii_fg_color_spread_hue()) {
      if (fg) {
        c = color_change_hue(c, ((int) blit_fg_color.r) - 128);
      } else {
        c = color_change_hue(c, ((int) blit_fg_color.g) - 128);
      }
      c.a = 255;
      return;
    }

    if (c.r) {
      if (gfx_ascii_fg_color_spread_red()) {
        int adjust  = ((int) blit_fg_color.r - 128);
        int new_col = ((int) c.r) + adjust;
        if (new_col < 0) {
          new_col = 0;
        }
        if (new_col > 255) {
          new_col = 255;
        }
        c.r = new_col;
      }
    }

    if (c.g) {
      if (gfx_ascii_fg_color_spread_green()) {
        int adjust  = ((int) blit_fg_color.g - 128);
        int new_col = ((int) c.g) + adjust;
        if (new_col < 0) {
          new_col = 0;
        }
        if (new_col > 255) {
          new_col = 255;
        }
        c.g = new_col;
      }
    }

    if (c.b) {
      if (gfx_ascii_fg_color_spread_blue()) {
        int adjust  = ((int) blit_fg_color.b - 128);
        int new_col = ((int) c.b) + adjust;
        if (new_col < 0) {
          new_col = 0;
        }
        if (new_col > 255) {
          new_col = 255;
        }
        c.b = new_col;
      }
    }

    if (c.a) {
      if (gfx_ascii_fg_color_spread_alpha()) {
        int adjust  = ((int) blit_fg_color.a - 128);
        int new_col = ((int) c.a) + adjust;
        if (new_col < 0) {
          new_col = 0;
        }
        if (new_col > 255) {
          new_col = 255;
        }
        c.a = new_col;
      }
    }
  } else {
    if (gfx_ascii_bg_color_spread_hue()) {
      if (fg) {
        c = color_change_hue(c, ((int) blit_bg_color.r) - 128);
      } else {
        c = color_change_hue(c, ((int) blit_bg_color.g) - 128);
      }
      c.a = 255;
      return;
    }

    if (c.r) {
      if (gfx_ascii_bg_color_spread_red()) {
        int adjust  = ((int) blit_bg_color.r - 128);
        int new_col = ((int) c.r) + adjust;
        if (new_col < 0) {
          new_col = 0;
        }
        if (new_col > 255) {
          new_col = 255;
        }
        c.r = new_col;
      }
    }

    if (c.g) {
      if (gfx_ascii_bg_color_spread_green()) {
        int adjust  = ((int) blit_bg_color.g - 128);
        int new_col = ((int) c.g) + adjust;
        if (new_col < 0) {
          new_col = 0;
        }
        if (new_col > 255) {
          new_col = 255;
        }
        c.g = new_col;
      }
    }

    if (c.b) {
      if (gfx_ascii_bg_color_spread_blue()) {
        int adjust  = ((int) blit_bg_color.b - 128);
        int new_col = ((int) c.b) + adjust;
        if (new_col < 0) {
          new_col = 0;
        }
        if (new_col > 255) {
          new_col = 255;
        }
        c.b = new_col;
      }
    }

    if (c.a) {
      if (gfx_ascii_bg_color_spread_alpha()) {
        int adjust  = ((int) blit_bg_color.a - 128);
        int new_col = ((int) c.a) + adjust;
        if (new_col < 0) {
          new_col = 0;
        }
        if (new_col > 255) {
          new_col = 255;
        }
        c.a = new_col;
      }
    }
  }
}

//
// Adjust tile for light source color
//
void Thing::blit_ascii_adjust_color(color &c, bool fg, bool left_bar)
{
  //
  // Green tint for the swamp
  //
  if ((level->biome == BIOME_SEWER) || (level->biome == BIOME_SWAMP)) {
    if (is_water()) {
      c.b = 0;
      c.r = 0;
    }
    c.r = (((int) c.r) * 2) / 3;
    c.b = (((int) c.b) * 2) / 3;
  } else if (level->biome == BIOME_LAVA) {
    c.b = (((int) c.b) * 2) / 3;
    c.g = (((int) c.g) * 2) / 3;
  } else if (level->biome == BIOME_ICE) {
    c.g = (((int) c.g) * 2) / 3;
  }

  //
  // Don't adjust hues if we cannot see it. This helps make the visible area
  // look a lot brighter in comparison to the unlit areas.
  //
  if (! get(level->can_see_currently.can_see, curr_at.x, curr_at.y)) {
    return;
  }

  //
  // Keep the cursor path easy to see
  //
  if (is_cursor_path()) {
    return;
  }

  //
  // Poor thing is frozen?
  //
  if (fg) {
    if (is_frozen) {
      if (! is_block_of_ice()) {
        c = LIGHTBLUE;
      }
    } else if (is_burnt) {
      c = BROWN;
    }
  }

  if (is_on_fire()) {
    auto r = non_pcg_random_range(0, 100);
    if (r < 20) {
      c = RED;
    } else if (r < 50) {
      c = YELLOW;
    } else {
      c = ORANGE;
    }
    return;
  }

  //
  // If shown on the left bar we want the original color
  //
  if (left_bar) {
    return;
  }

  //
  // Adjust for hue etc
  //
  blit_ascii_adjust_color_hue(c, fg);

  //
  // Do not brighten things like wall fg that is black
  //
  if (c == BLACK) {
    return;
  }

  //
  // Should light sources keep their color ?
  //
  if (has_light) {
    return;
  }

  //
  // For monsters and the like, if we combine colors then we lose information, like what type of snake it is. It's
  // better instead to just fade the colors with distance.
  //
  if (gfx_ascii_fade_with_dist()) {
    float light_dist = level->player ? level->player->light_dist_get() : 1.0;
    if (light_dist <= 0.1) {
      light_dist = 0.1;
    }
    float brightness = 1.0 - (((float) distance_to_player() - 1) / light_dist);

    IF_DEBUG2 { brightness = 1.0; }

    c.r = ((float) c.r) * brightness;
    c.g = ((float) c.g) * brightness;
    c.b = ((float) c.b) * brightness;
  } else {
    //
    // Else combine the light sources, so we get a nice lava glow.
    //

    //
    // This prevents the L in lava from appearing reddish. Not sure if I want this for other things too.
    //
    if (fg) {
      if (gfx_ascii_color_fg_unchanged_by_lights()) {
        return;
      }
    } else {
      if (gfx_ascii_color_bg_unchanged_by_lights()) {
        return;
      }
    }

    //
    // Get the combined light on this tile
    //
    fcolor combined_light = level->ascii_light_source_no_check(curr_at);
    if (combined_light == COLOR_NONE) {
      return;
    }

    float dim                  = 0.8;
    float light_contribution   = 0.5;
    color combined_light_color = combined_light.tocolor();

    //
    // Don't over dominate the original color, or things like red blood
    // seem white when lit.
    //

    int r = (((float) c.r) * dim) + (((float) combined_light_color.r) * light_contribution);
    if (r > 255) {
      r = 255;
    }
    c.r = r;

    int g = (((float) c.g) * dim) + (((float) combined_light_color.g) * light_contribution);
    if (g > 255) {
      g = 255;
    }
    c.g = g;

    int b = (((float) c.b) * dim) + (((float) combined_light_color.b) * light_contribution);
    if (b > 255) {
      b = 255;
    }
    c.b = b;
  }
}

void Thing::blit_ascii_outline(point p, bool lit, bool left_bar)
{
  TRACE_NO_INDENT();

  color outline_color;
  if (blit_outline_should_be_shown(outline_color)) {
    TRACE_NO_INDENT();
    ascii_set(TILE_LAYER_BG_0, p.x, p.y, outline_color);
    ascii_set(TILE_LAYER_FG_0, p.x, p.y, WHITE);
  }
}

void Thing::blit_ascii_at(point p, bool lit, bool left_bar)
{
  TRACE_NO_INDENT();

  if (is_no_tile()) {
    return;
  }

  auto tile = tile_index_to_tile(tile_curr);
  if (! tile) {
    return;
  }

  if (! g_opt_ascii) {
    ascii_set(TILE_LAYER_FG_3, p.x, p.y, tile);
    return;
  }

  static uint8_t  alpha = 128;
  static int      step  = 10;
  static int      dir   = 1;
  static uint32_t ts;

  if (time_have_x_hundredths_passed_since(2, ts)) {
    alpha += dir * step;
    if (alpha > 240) {
      dir = -1;
    } else if (alpha < 100) {
      dir = 1;
    }
    ts = time_ms_cached();
  }

  //
  // This is for walls that can be composed of multiple tiles.
  //
  if (! tile->ascii_set) {
    auto tpp  = tp();
    auto tmap = &tpp->tiles;
    tile      = tile_first(tmap);
  }

  const bool bg = false;
  const bool fg = true;

  //
  // In debug mode, show all monsters
  //
  bool shown_in_bg = gfx_ascii_shown_in_bg();

  IF_DEBUG2 { shown_in_bg = true; }

  if (gfx_ascii_shown()) {
    if (lit) {
      //
      // e.g dungeon floor
      //
      if (tile->ascii_bg_col_value != COLOR_NONE) {
        ascii_set(TILE_LAYER_BG_0, p.x, p.y, UNICODE_ALIAS_FOR_BLOCK);
        color c = tile->ascii_bg_col_value;
        c.a     = tile->ascii_bg_alpha;
        blit_ascii_adjust_color(c, bg, left_bar);
        ascii_set(TILE_LAYER_BG_0, p.x, p.y, c);
      }

      if (tile->ascii_bg_char) {
        ascii_set(TILE_LAYER_BG_0, p.x, p.y, tile->ascii_bg_char);
      }

      if (tile->ascii_bg_col_value != COLOR_NONE) {
        color c = tile->ascii_bg_col_value;
        c.a     = tile->ascii_bg_alpha;
        blit_ascii_adjust_color(c, bg, left_bar);
        ascii_set(TILE_LAYER_BG_0, p.x, p.y, c);
      }

      color c = tile->ascii_fg_col_value;
      c.a     = tile->ascii_fg_alpha;
      blit_ascii_adjust_color(c, fg, left_bar);

      if (tile->ascii_fg_char) {
        if (c.a != 255) {
          ascii_set(TILE_LAYER_FG_1, p.x, p.y, tile->ascii_fg_char);
        } else {
          ascii_set(TILE_LAYER_FG_0, p.x, p.y, tile->ascii_fg_char);
        }
      }

      if (tile->ascii_fg_col_value != COLOR_NONE) {
        if (c.a != 255) {
          ascii_set(TILE_LAYER_FG_1, p.x, p.y, c);
        } else {
          ascii_set(TILE_LAYER_FG_0, p.x, p.y, c);
        }
      }
    } else if (get(level->can_see_ever.can_see, curr_at.x, curr_at.y) || g_opt_debug2) {
      //
      // e.g unlit areas like the dungeon floor
      //
      // If this is something we would not normally show, like a monster, but it is on
      // a tile that has been seen and is lit, then show it.
      //
      if (0) {
        //
        // Not sure we should show monsters elsewhere. Make it an ability?
        //
        if (! shown_in_bg) {
          fcolor combined_light = level->ascii_light_source_no_check(curr_at);
          if (combined_light != COLOR_NONE) {
            shown_in_bg = true;
          }
        }
      }

      if (shown_in_bg) {
        if (tile->ascii_bg_col_value != COLOR_NONE) {
          ascii_set(TILE_LAYER_BG_0, p.x, p.y, UNICODE_ALIAS_FOR_BLOCK);
          color c = tile->ascii_bg_col_value;
          //
          // Apply a nice tint.
          //
          c.r = ((int) (c.r / 4));
          c.g = ((int) (c.g / 5));
          c.b = ((int) (c.b / 2));
          c.a = tile->ascii_fg_alpha;
          blit_ascii_adjust_color(c, bg, left_bar);

          ascii_set(TILE_LAYER_BG_0, p.x, p.y, c);
        }

        if (tile->ascii_bg_char) {
          ascii_set(TILE_LAYER_BG_0, p.x, p.y, tile->ascii_bg_char);
          color c = tile->ascii_bg_col_value;
          //
          // Apply a nice tint.
          //
          c.r = ((int) (c.r / 4));
          c.g = ((int) (c.g / 5));
          c.b = ((int) (c.b / 2));
          c.a = tile->ascii_fg_alpha;
          blit_ascii_adjust_color(c, bg, left_bar);

          ascii_set(TILE_LAYER_BG_0, p.x, p.y, c);
        }

        if (tile->ascii_fg_char) {
          ascii_set(TILE_LAYER_FG_0, p.x, p.y, tile->ascii_fg_char);
          color c = tile->ascii_fg_col_value;

          //
          // Don't hue adjust fg chars in the shadows. It just makes it harder to see.
          //
          if (gfx_ascii_shown_as_gray_in_shadow()) {
            //
            // Show items plainly so it is easier to see.
            //
            c = GRAY20;
          } else {
            //
            // Dim the char substantially.
            //
            c.r = ((int) (c.r / 4));
            c.g = ((int) (c.g / 4));
            c.b = ((int) (c.b / 4));
            c.a = tile->ascii_fg_alpha;
          }
          blit_ascii_adjust_color(c, fg, left_bar);

          ascii_set(TILE_LAYER_FG_0, p.x, p.y, c);
        }
      }
    }
  }

  //
  // Allow secret doors a chance to be seen
  //
  if (is_secret_door() && discovered()) {
    color outline_color = ORANGE;
    outline_color.a     = alpha;
    ascii_set(TILE_LAYER_BG_0, p.x, p.y, outline_color);
    ascii_set(TILE_LAYER_FG_0, p.x, p.y, WHITE);
  }

  if (gfx_pixelart_show_highlighted() && ! immediate_owner()) {
    if ((this == game->current_wid_thing_info) || (level->cursor && (this->curr_at == level->cursor->curr_at))) {
      color outline_color = ORANGE;
      outline_color.a     = alpha;
      ascii_set(TILE_LAYER_BG_0, p.x, p.y, outline_color);
      ascii_set(TILE_LAYER_FG_0, p.x, p.y, WHITE);
    }
  }

  if (! is_dead) {
    if (is_invisible_currently() && is_player()) {
      color outline_color = WHITE;
      outline_color.a     = alpha;
      ascii_set(TILE_LAYER_BG_0, p.x, p.y, outline_color);
      ascii_set(TILE_LAYER_FG_0, p.x, p.y, WHITE);
    }

    if (! is_invisible_currently() || is_player()) {
      if (is_raging()) {
        if ((this == game->current_wid_thing_info) || (level->cursor && (this->curr_at == level->cursor->curr_at))) {
          color outline_color = ORANGE;
          outline_color.a     = alpha;
          ascii_set(TILE_LAYER_BG_0, p.x, p.y, outline_color);
          ascii_set(TILE_LAYER_FG_0, p.x, p.y, WHITE);
        }
      }
    }
  }
}

void Thing::blit_ascii(point tl, point br, point p, bool left_bar)
{
  TRACE_NO_INDENT();

  auto tpp  = tp();
  auto blit = true;

  if (unlikely(is_changing_level)) {
    blit = false;
  } else if (unlikely(is_hidden)) {
    blit = false;
  } else if (unlikely(tpp->gfx_pixelart_attack_anim() || tpp->gfx_pixelart_equip_carry_anim())) {
    //
    // Hide weapons that have swung
    //
    if (is_dead) {
      blit = false;
    }
  } else if (is_cursor() || is_cursor_path() || is_the_grid()) {
    blit = true;
  }

  auto owner = immediate_owner();
  if (owner) {
    //
    // Prevent items inside bags/chests being seen. This also works for falling.
    //
    if (owner->is_bag_item_container()) {
      blit = false;
    }

    //
    // In ascii mode we do not show equipped items
    //
    if (is_usable() && owner->is_equipped(this)) {
      blit = false;
    }

    //
    // In ascii mode we do not show carried items
    //
    if (gfx_pixelart_equip_carry_anim()) {
      blit = false;
    }
  }

  if (! blit) {
    return;
  }

  //
  // If this code changes make sure and update gas, lasers and projectiles for ascii mode.
  //
  int x = tl.x + (p.x - level->minx) - (MAP_BORDER_ROCK - 1);
  int y = tl.y + (p.y - level->miny) - (MAP_BORDER_ROCK - 1);

  //
  // Can we see it?
  //
  bool lit;
  if (has_light) {
    //
    // Not sure if we should show lights out of view
    //
    if (gfx_ascii_show_light_once_seen()) {
      lit = get(level->can_see_ever.can_see, curr_at.x, curr_at.y);
    } else {
      lit = get(level->can_see_currently.can_see, curr_at.x, curr_at.y);
    }
  } else {
    lit = get(level->can_see_currently.can_see, curr_at.x, curr_at.y);
  }

  IF_DEBUG2 { lit = true; }

  if (left_bar || is_cursor() || is_cursor_path()) {
    lit = true;
  }

  blit_ascii_at(point(x, y), lit, left_bar);

  last_ascii_at = point(x, y);
  last_blit_tl  = point(curr_at.x * TILE_WIDTH, curr_at.y * TILE_HEIGHT);
  last_blit_br  = point((curr_at.x + 1) * TILE_WIDTH, (curr_at.y + 1) * TILE_HEIGHT);
  last_blit_at  = (last_blit_tl + last_blit_br) / (short) 2;
  is_blitted    = true;
}
