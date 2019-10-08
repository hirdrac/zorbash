//
// Copyright goblinhack@gmail.com
// See the README file for license info.
//

#pragma once

#include "my_wid.h"

class WidPopup {
private:
    std::map< unsigned int, std::wstring > wid_popup_lines;
    int width {};
    int height {};
    int line_count {};
    int scroll_height {};

    Widp wid_popup_container {};
    Widp wid_vert_scroll {};
    Widp wid_horiz_scroll {};
    Widp wid_text_last {};
    Widp wid_text_area {};

    std::vector<Widp> children;

public:
    point tl;
    point br;

public:
    ~WidPopup();
    WidPopup(point tl, point br);

private:
    void log_(std::wstring str);

public:
    void log(std::string s);
    void log(std::wstring s);
};
