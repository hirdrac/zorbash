//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#include "my_game.h"
#include "my_wid_minicon.h"
#include "my_wid_console.h"
#include "my_wid_popup.h"
#include "my_ascii.h"

static WidPopup *game_config_other_window;

static void game_config_other_destroy (void)
{
    if (game_config_other_window) {
        delete game_config_other_window;
        game_config_other_window = nullptr;
    }
    game->soft_unpause();
}

uint8_t game_config_other_cancel (Widp w, int32_t x, int32_t y, uint32_t button)
{
    CON("USERCFG: reload config");
    game->load_config();
    game_config_other_destroy();
    game->config_top_select();
    return (true);
}

uint8_t game_config_other_save (Widp w, int32_t x, int32_t y, uint32_t button)
{
    CON("USERCFG: save config");
    game->save_config();
    game_config_other_destroy();
    game->config_top_select();
    return (true);
}

uint8_t game_config_other_back (Widp w, int32_t x, int32_t y, uint32_t button)
{
    game_config_other_destroy();
    game->config_top_select();
    return (true);
}

uint8_t game_config_other_debug_mode_toggle (Widp w, int32_t x, int32_t y, uint32_t button)
{
    CON("USERCFG: toggle debug_mode");
    game->config.debug_mode = !game->config.debug_mode;
    game->config_other_select();
    return (true);
}

uint8_t game_config_other_arcade_mode_toggle (Widp w, int32_t x, int32_t y, uint32_t button)
{
    CON("USERCFG: toggle arcade_mode");
    game->config.arcade_mode = !game->config.arcade_mode;
    game->config_other_select();
    return (true);
}

uint8_t game_config_other_fps_counter_toggle (Widp w, int32_t x, int32_t y, uint32_t button)
{
    CON("USERCFG: toggle fps_counter");
    game->config.fps_counter = !game->config.fps_counter;
    game->config_other_select();
    return (true);
}

uint8_t game_config_other_sdl_delay_incr (Widp w, int32_t x, int32_t y, uint32_t button)
{
    CON("USERCFG: incr sdl_delay");
    game->config.sdl_delay++;
    game->config_other_select();
    return (true);
}

uint8_t game_config_other_sdl_delay_decr (Widp w, int32_t x, int32_t y, uint32_t button)
{
    CON("USERCFG: incr sdl_delay");
    game->config.sdl_delay--;
    game->config_other_select();
    return (true);
}

uint8_t game_config_other_key_up (Widp w, const struct SDL_KEYSYM *key)
{
    switch (key->mod) {
        case KMOD_LCTRL:
        case KMOD_RCTRL:
        default:
        switch (key->sym) {
            default: {
                auto c = wid_event_to_char(key);
                switch (c) {
                    case CONSOLE_KEY1:
                    case CONSOLE_KEY2:
                    case CONSOLE_KEY3:
                        //
                        // Magic keys we use to toggle the console.
                        //
                        return (false);
                    case 'b':
                        game_config_other_back(nullptr, 0, 0, 0);
                        return (true);
                    case 'c':
                        game_config_other_cancel(nullptr, 0, 0, 0);
                        return (true);
                    case 's':
                        game_config_other_save(nullptr, 0, 0, 0);
                        return (true);
                    case SDLK_ESCAPE:
                        game_config_other_cancel(nullptr, 0, 0, 0);
                        return (true);
                }
            }
        }
    }

    return (false);
}

uint8_t game_config_other_key_down (Widp w, const struct SDL_KEYSYM *key)
{
    switch (key->mod) {
        case KMOD_LCTRL:
        case KMOD_RCTRL:
        default:
        switch (key->sym) {
            default: {
                auto c = wid_event_to_char(key);
                switch (c) {
                    case CONSOLE_KEY1:
                    case CONSOLE_KEY2:
                    case CONSOLE_KEY3:
                        //
                        // Magic keys we use to toggle the console.
                        //
                        return (false);
                }
            }
        }
    }

    return (true);
}

void Game::config_other_select (void)
{_
    if (game_config_other_window) {
        game_config_other_destroy();
    }
    game->soft_pause();

    auto m = ASCII_WIDTH / 2;
    point tl = {m - WID_POPUP_WIDTH_WIDEST / 2, MINICON_VIS_HEIGHT + 2};
    point br = {m + WID_POPUP_WIDTH_WIDEST / 2, ITEMBAR_TL_Y - 2};
    auto width = br.x - tl.x;

    game_config_other_window = new WidPopup(tl, br, nullptr, "ui_popup_widest");
    {
        Widp w = game_config_other_window->wid_popup_container;
        wid_set_on_key_up(w, game_config_other_key_up);
        wid_set_on_key_down(w, game_config_other_key_down);
    }

    int y_at = 0;
    {
        auto p = game_config_other_window->wid_text_area->wid_text_area;
        auto w = wid_new_square_button(p, "configuration");

        point tl = {0, y_at};
        point br = {width, y_at + 2};
        wid_set_shape_none(w);
        wid_set_pos(w, tl, br);
        wid_set_text(w, "Configuration");
    }

    y_at = 3;
    {
        auto p = game_config_other_window->wid_text_area->wid_text_area;
        auto w = wid_new_square_button(p, "Back");

        point tl = {1, y_at};
        point br = {6, y_at + 2};
        wid_set_style(w, WID_STYLE_DARK);
        wid_set_on_mouse_up(w, game_config_other_back);
        wid_set_pos(w, tl, br);
        wid_set_text(w, "%%fg=white$B%%fg=reset$ack");
    }
    {
        auto p = game_config_other_window->wid_text_area->wid_text_area;
        auto w = wid_new_square_button(p, "Save");

        point tl = {width - 16, y_at};
        point br = {width - 11, y_at + 2};
        wid_set_style(w, WID_STYLE_GREEN);
        wid_set_on_mouse_up(w, game_config_other_save);
        wid_set_pos(w, tl, br);
        wid_set_text(w, "%%fg=white$S%%fg=reset$ave");
    }
    {
        auto p = game_config_other_window->wid_text_area->wid_text_area;
        auto w = wid_new_square_button(p, "Cancel");

        point tl = {width - 9, y_at};
        point br = {width - 2, y_at + 2};
        wid_set_style(w, WID_STYLE_RED);
        wid_set_on_mouse_up(w, game_config_other_cancel);
        wid_set_pos(w, tl, br);
        wid_set_text(w, "%%fg=white$C%%fg=reset$ancel");
    }

    y_at += 3;
    {
        auto p = game_config_other_window->wid_text_area->wid_text_area;
        auto w = wid_new_square_button(p, "Debug mode");

        point tl = {0, y_at};
        point br = {width / 2, y_at + 2};
        wid_set_shape_none(w);
        wid_set_pos(w, tl, br);
        wid_set_text_lhs(w, true);
        wid_set_text(w, "Debug mode");
    }
    {
        auto p = game_config_other_window->wid_text_area->wid_text_area;
        auto w = wid_new_square_button(p, "Debug mode value");

        point tl = {width / 2 , y_at};
        point br = {width / 2 + 6, y_at + 2};
        wid_set_style(w, WID_STYLE_DARK);
        wid_set_pos(w, tl, br);
        wid_set_on_mouse_up(w, game_config_other_debug_mode_toggle);

        if (game->config.debug_mode) {
            wid_set_text(w, "True");
        } else {
            wid_set_text(w, "False");
        }
    }

    y_at += 3;
    {
        auto p = game_config_other_window->wid_text_area->wid_text_area;
        auto w = wid_new_square_button(p, "Arcade mode");

        point tl = {0, y_at};
        point br = {width / 2, y_at + 2};
        wid_set_shape_none(w);
        wid_set_pos(w, tl, br);
        wid_set_text_lhs(w, true);
        wid_set_text(w, "Arcade mode");
    }
    {
        auto p = game_config_other_window->wid_text_area->wid_text_area;
        auto w = wid_new_square_button(p, "Arcade mode value");

        point tl = {width / 2 , y_at};
        point br = {width / 2 + 6, y_at + 2};
        wid_set_style(w, WID_STYLE_DARK);
        wid_set_pos(w, tl, br);
        wid_set_on_mouse_up(w, game_config_other_arcade_mode_toggle);

        if (game->config.arcade_mode) {
            wid_set_text(w, "True");
        } else {
            wid_set_text(w, "False");
        }
    }

    y_at += 3;
    {
        auto p = game_config_other_window->wid_text_area->wid_text_area;
        auto w = wid_new_square_button(p, "FPS counter");

        point tl = {0, y_at};
        point br = {width / 2, y_at + 2};
        wid_set_shape_none(w);
        wid_set_pos(w, tl, br);
        wid_set_text_lhs(w, true);
        wid_set_text(w, "FPS counter");
    }
    {
        auto p = game_config_other_window->wid_text_area->wid_text_area;
        auto w = wid_new_square_button(p, "FPS counter value");

        point tl = {width / 2 , y_at};
        point br = {width / 2 + 6, y_at + 2};
        wid_set_style(w, WID_STYLE_DARK);
        wid_set_pos(w, tl, br);
        wid_set_on_mouse_up(w, game_config_other_fps_counter_toggle);

        if (game->config.fps_counter) {
            wid_set_text(w, "True");
        } else {
            wid_set_text(w, "False");
        }
    }

    y_at += 3;
    {
        auto p = game_config_other_window->wid_text_area->wid_text_area;
        auto w = wid_new_square_button(p, "SDL delay ms per frame");

        point tl = {0, y_at};
        point br = {width / 2, y_at + 2};
        wid_set_shape_none(w);
        wid_set_pos(w, tl, br);
        wid_set_text_lhs(w, true);
        wid_set_text(w, "SDL delay ms per frame");
    }
    {
        auto p = game_config_other_window->wid_text_area->wid_text_area;
        auto w = wid_new_square_button(p, "SDL delay value");

        point tl = {width / 2 , y_at};
        point br = {width / 2 + 6, y_at + 2};
        wid_set_style(w, WID_STYLE_DARK);
        wid_set_pos(w, tl, br);
        wid_set_text(w,  std::to_string(game->config.sdl_delay));
    }
    {
        auto p = game_config_other_window->wid_text_area->wid_text_area;
        auto w = wid_new_square_button(p, "SDL delay value +");

        point tl = {width / 2 + 7 , y_at};
        point br = {width / 2 + 9, y_at + 2};
        wid_set_style(w, WID_STYLE_DARK);
        wid_set_pos(w, tl, br);
        wid_set_on_mouse_up(w, game_config_other_sdl_delay_incr);
        wid_set_text(w, "+");
    }
    {
        auto p = game_config_other_window->wid_text_area->wid_text_area;
        auto w = wid_new_square_button(p, "SDL delay value -");

        point tl = {width / 2 + 10 , y_at};
        point br = {width / 2 + 12, y_at + 2};
        wid_set_style(w, WID_STYLE_DARK);
        wid_set_pos(w, tl, br);
        wid_set_on_mouse_up(w, game_config_other_sdl_delay_decr);
        wid_set_text(w, "-");
    }

    wid_update(game_config_other_window->wid_text_area->wid_text_area);
}