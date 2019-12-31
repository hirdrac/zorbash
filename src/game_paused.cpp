/*
 * Copyright goblinhack@gmail.com
 * See the README file for license info.
 */

#include "my_game.h"
#include "my_wid_minicon.h"
#include "my_wid_console.h"
#include "my_wid_popup.h"
#include "my_ascii.h"

void Game::soft_pause (void)
{
    soft_paused = true;
}

void Game::soft_unpause (void)
{
    soft_paused = false;
    if (!hard_paused) {
        last_pause = time_get_time_ms();
    }
}

void Game::hard_pause (void)
{
    hard_paused = true;
}

void Game::hard_unpause (void)
{
    hard_paused = false;
    if (!soft_paused) {
        last_pause = time_get_time_ms();
    }
}

bool Game::paused (void)
{
    if (soft_paused || hard_paused) {
        return (true);
    }

    if (!time_have_x_tenths_passed_since(5, last_pause)) {
        return (true);
    }
    return (false);
}

static WidPopup *wid_paused_window;

static void wid_paused_destroy (void)
{
    if (wid_paused_window) {
        delete wid_paused_window;
        wid_paused_window = nullptr;
    }
    game->soft_unpause();
}

uint8_t wid_paused_key_up (Widp w, const struct SDL_KEYSYM *key)
{
    switch (key->mod) {
        case KMOD_LCTRL:
        case KMOD_RCTRL:
        default:
        switch (key->sym) {
            default: {
                auto c = wid_event_to_char(key);
                switch (c) {
                    case ' ':
                    case '\n':
                    case SDLK_ESCAPE: {
                        wid_paused_destroy();
                        return (true);
                    }
                }
            }
        }
    }

    return (true);
}

uint8_t wid_paused_key_down (Widp w, const struct SDL_KEYSYM *key)
{
    return (true);
}

uint8_t wid_paused_mouse_up (Widp w, int32_t x, int32_t y, uint32_t button)
{
    wid_paused_destroy();
    return (true);
}

void Game::pause_select (void)
{_
    if (wid_paused_window) {
        wid_paused_destroy();
    }
    game->soft_pause();

    point tl = {0, ASCII_HEIGHT - 14};
    point br = {WID_POPUP_WIDTH_NORMAL, ASCII_HEIGHT - 1};
    auto width = br.x - tl.x - 1;

    wid_paused_window =
      new WidPopup(tl, br, tile_find_mand("pause"), "ui_popup_short");
    wid_set_on_key_up(
      wid_paused_window->wid_popup_container, wid_paused_key_up);
    wid_set_on_key_down(
      wid_paused_window->wid_popup_container, wid_paused_key_down);

    {
        auto p = wid_paused_window->wid_text_area->wid_text_area;
        auto w = wid_new_square_button(p, "PAUSED");

        point tl = {0, 0};
        point br = {width - 1, 2};

        wid_set_style(w, WID_STYLE_RED);
        wid_set_on_mouse_up(w, wid_paused_mouse_up);

        wid_set_pos(w, tl, br);
        wid_set_text(w, "CONTINUE");
    }

    wid_update(wid_paused_window->wid_text_area->wid_text_area);
}