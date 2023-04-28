//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_color_defs.hpp"
#include "my_sys.hpp"

#include <string.h>  // do not remove
#include <strings.h> // do not remove, strcasecmp

color INK;
color LIGHTSTEELBLUE;
color LIGHTSTEELBLUE1;
color LIGHTSTEELBLUE2;
color LIGHTSTEELBLUE3;
color LIGHTSTEELBLUE4;
color LIGHTYELLOW;
color LIGHTYELLOW1;
color LIGHTYELLOW2;
color LIGHTYELLOW3;
color LIGHTYELLOW4;
color LINEN;
color MAGENTA;
color MAGENTA1;
color MAGENTA2;
color MAGENTA3;
color MAGENTA4;
color MAROON;
color MAROON1;
color MAROON2;
color MAROON3;
color MAROON4;
color MEDIUMAQUAMARINE;
color MEDIUMBLUE;
color MEDIUMPURPLE;
color MEDIUMPURPLE1;
color MEDIUMPURPLE2;
color MEDIUMPURPLE3;
color MEDIUMPURPLE4;
color MEDIUMSEAGREEN;
color MEDIUMSLATEBLUE;
color MEDIUMSPRINGGREEN;
color MEDIUMTURQUOISE;
color MEDIUMVIOLETRED;
color MIDNIGHTBLUE;
color MINTCREAM;
color MOCCASIN;
color NAVY;
color NAVYBLUE;
color OLIVE_DRAB;
color OLIVEDRAB;
color OLIVEDRAB1;
color OLIVEDRAB2;
color OLIVEDRAB3;
color OLIVEDRAB4;
color ORANGE;
color ORANGE1;
color ORANGE2;
color ORANGE3;
color ORANGE4;
color ORANGERED;
color ORANGERED1;
color ORANGERED2;
color ORANGERED3;
color ORANGERED4;
color PALEGREEN;
color PALEGREEN1;
color PALEGREEN2;
color PALEGREEN3;
color PALEGREEN4;
color PALETURQUOISE;
color PALETURQUOISE1;
color PALETURQUOISE2;
color PALETURQUOISE3;
color PALETURQUOISE4;
color PALEVIOLETRED;
color PALEVIOLETRED1;
color PALEVIOLETRED2;
color PALEVIOLETRED3;
color PALEVIOLETRED4;
color PEACHPUFF;
color PEACHPUFF1;
color PEACHPUFF2;
color PEACHPUFF3;
color PEACHPUFF4;
color PERU;
color PINK;
color PINK1;
color PINK2;
color PINK3;
color PINK4;
color PLUM;
color PLUM1;
color PLUM2;
color PLUM3;
color PLUM4;
color POWDERBLUE;
color PURPLE;
color PURPLE1;
color PURPLE2;
color PURPLE3;
color PURPLE4;
color RED;
color RED1;
color RED2;
color RED3;
color RED4;
color SADDLE_BROWN;
color SADDLEBROWN;
color SEAGREEN;
color SEAGREEN1;
color SEAGREEN2;
color SEAGREEN3;
color SEAGREEN4;
color SIENNA;
color SIENNA1;
color SIENNA2;
color SIENNA3;
color SIENNA4;
color SKYBLUE;
color SKYBLUE1;
color SKYBLUE2;
color SKYBLUE3;
color SKYBLUE4;
color SLATEBLUE;
color SLATEBLUE1;
color SLATEBLUE2;
color SLATEBLUE3;
color SLATEBLUE4;
color SLATEGRAY;
color SLATEGRAY1;
color SLATEGRAY2;
color SLATEGRAY3;
color SLATEGRAY4;
color SLATEGREY;
color SLATEGREY1;
color SLATEGREY2;
color SLATEGREY3;
color SLATEGREY4;
color SNOW;
color SNOW1;
color SNOW2;
color SNOW3;
color SNOW4;
color SPRINGGREEN;
color SPRINGGREEN1;
color SPRINGGREEN2;
color SPRINGGREEN3;
color SPRINGGREEN4;
color STEELBLUE;
color STEELBLUE1;
color STEELBLUE2;
color STEELBLUE3;
color STEELBLUE4;
color TAN;
color TAN1;
color TAN2;
color TAN3;
color TAN4;
color THISTLE;
color THISTLE1;
color THISTLE2;
color THISTLE3;
color THISTLE4;
color TOMATO;
color TOMATO1;
color TOMATO2;
color TOMATO3;
color TOMATO4;
color TURQUOISE;
color TURQUOISE1;
color TURQUOISE2;
color TURQUOISE3;
color TURQUOISE4;
color VIOLET;
color VIOLETRED;
color VIOLETRED1;
color VIOLETRED2;
color VIOLETRED3;
color VIOLETRED4;
color WHITE;
color WHITE_SMOKE;
color WHITESMOKE;
color YELLOW;
color YELLOW1;
color YELLOW2;
color YELLOW3;
color YELLOW4;
color YELLOWGREEN;

void color_init4(void)
{
  TRACE_AND_INDENT();

  color_set("ink", &INK, 54, 47, 47, 255);
  color_set("lightsteelblue1", &LIGHTSTEELBLUE1, 202, 225, 255, 255);
  color_set("lightsteelblue2", &LIGHTSTEELBLUE2, 188, 210, 238, 255);
  color_set("lightsteelblue3", &LIGHTSTEELBLUE3, 162, 181, 205, 255);
  color_set("lightsteelblue4", &LIGHTSTEELBLUE4, 110, 123, 139, 255);
  color_set("lightsteelblue", &LIGHTSTEELBLUE, 176, 196, 222, 255);
  color_set("lightyellow1", &LIGHTYELLOW1, 255, 255, 224, 255);
  color_set("lightyellow2", &LIGHTYELLOW2, 238, 238, 209, 255);
  color_set("lightyellow3", &LIGHTYELLOW3, 205, 205, 180, 255);
  color_set("lightyellow4", &LIGHTYELLOW4, 139, 139, 122, 255);
  color_set("lightyellow", &LIGHTYELLOW, 255, 255, 224, 255);
  color_set("linen", &LINEN, 250, 240, 230, 255);
  color_set("magenta1", &MAGENTA1, 255, 0, 255, 255);
  color_set("magenta2", &MAGENTA2, 238, 0, 238, 255);
  color_set("magenta3", &MAGENTA3, 205, 0, 205, 255);
  color_set("magenta4", &MAGENTA4, 139, 0, 139, 255);
  color_set("magenta", &MAGENTA, 255, 0, 255, 255);
  color_set("maroon1", &MAROON1, 255, 52, 179, 255);
  color_set("maroon2", &MAROON2, 238, 48, 167, 255);
  color_set("maroon3", &MAROON3, 205, 41, 144, 255);
  color_set("maroon4", &MAROON4, 139, 28, 98, 255);
  color_set("maroon", &MAROON, 176, 48, 96, 255);
  color_set("mediumaquamarine", &MEDIUMAQUAMARINE, 102, 205, 170, 255);
  color_set("mediumblue", &MEDIUMBLUE, 0, 0, 205, 255);
  color_set("mediumpurple1", &MEDIUMPURPLE1, 171, 130, 255, 255);
  color_set("mediumpurple2", &MEDIUMPURPLE2, 159, 121, 238, 255);
  color_set("mediumpurple3", &MEDIUMPURPLE3, 137, 104, 205, 255);
  color_set("mediumpurple4", &MEDIUMPURPLE4, 93, 71, 139, 255);
  color_set("mediumpurple", &MEDIUMPURPLE, 147, 112, 219, 255);
  color_set("mediumseagreen", &MEDIUMSEAGREEN, 60, 179, 113, 255);
  color_set("mediumslateblue", &MEDIUMSLATEBLUE, 123, 104, 238, 255);
  color_set("mediumspringgreen", &MEDIUMSPRINGGREEN, 0, 250, 154, 255);
  color_set("mediumturquoise", &MEDIUMTURQUOISE, 72, 209, 204, 255);
  color_set("mediumvioletred", &MEDIUMVIOLETRED, 199, 21, 133, 255);
  color_set("midnightblue", &MIDNIGHTBLUE, 25, 25, 112, 255);
  color_set("mintcream", &MINTCREAM, 245, 255, 250, 255);
  color_set("moccasin", &MOCCASIN, 255, 228, 181, 255);
  color_set("navyblue", &NAVYBLUE, 0, 0, 128, 255);
  color_set("navy", &NAVY, 0, 0, 128, 255);
  color_set("olivedrab1", &OLIVEDRAB1, 192, 255, 62, 255);
  color_set("olivedrab2", &OLIVEDRAB2, 179, 238, 58, 255);
  color_set("olivedrab3", &OLIVEDRAB3, 154, 205, 50, 255);
  color_set("olivedrab4", &OLIVEDRAB4, 105, 139, 34, 255);
  color_set("olive_drab", &OLIVE_DRAB, 107, 142, 35, 255);
  color_set("olivedrab", &OLIVEDRAB, 107, 142, 35, 255);
  color_set("orange1", &ORANGE1, 255, 165, 0, 255);
  color_set("orange2", &ORANGE2, 238, 154, 0, 255);
  color_set("orange3", &ORANGE3, 205, 133, 0, 255);
  color_set("orange4", &ORANGE4, 139, 90, 0, 255);
  color_set("orange", &ORANGE, 255, 165, 0, 255);
  color_set("orangered1", &ORANGERED1, 255, 69, 0, 255);
  color_set("orangered2", &ORANGERED2, 238, 64, 0, 255);
  color_set("orangered3", &ORANGERED3, 205, 55, 0, 255);
  color_set("orangered4", &ORANGERED4, 139, 37, 0, 255);
  color_set("orangered", &ORANGERED, 255, 69, 0, 255);
  color_set("palegreen1", &PALEGREEN1, 154, 255, 154, 255);
  color_set("palegreen2", &PALEGREEN2, 144, 238, 144, 255);
  color_set("palegreen3", &PALEGREEN3, 124, 205, 124, 255);
  color_set("palegreen4", &PALEGREEN4, 84, 139, 84, 255);
  color_set("palegreen", &PALEGREEN, 152, 251, 152, 255);
  color_set("paleturquoise1", &PALETURQUOISE1, 187, 255, 255, 255);
  color_set("paleturquoise2", &PALETURQUOISE2, 174, 238, 238, 255);
  color_set("paleturquoise3", &PALETURQUOISE3, 150, 205, 205, 255);
  color_set("paleturquoise4", &PALETURQUOISE4, 102, 139, 139, 255);
  color_set("paleturquoise", &PALETURQUOISE, 175, 238, 238, 255);
  color_set("palevioletred1", &PALEVIOLETRED1, 255, 130, 171, 255);
  color_set("palevioletred2", &PALEVIOLETRED2, 238, 121, 159, 255);
  color_set("palevioletred3", &PALEVIOLETRED3, 205, 104, 137, 255);
  color_set("palevioletred4", &PALEVIOLETRED4, 139, 71, 93, 255);
  color_set("palevioletred", &PALEVIOLETRED, 219, 112, 147, 255);
  color_set("peachpuff1", &PEACHPUFF1, 255, 218, 185, 255);
  color_set("peachpuff2", &PEACHPUFF2, 238, 203, 173, 255);
  color_set("peachpuff3", &PEACHPUFF3, 205, 175, 149, 255);
  color_set("peachpuff4", &PEACHPUFF4, 139, 119, 101, 255);
  color_set("peachpuff", &PEACHPUFF, 255, 218, 185, 255);
  color_set("peru", &PERU, 205, 133, 63, 255);
  color_set("pink1", &PINK1, 255, 181, 197, 255);
  color_set("pink2", &PINK2, 238, 169, 184, 255);
  color_set("pink3", &PINK3, 205, 145, 158, 255);
  color_set("pink4", &PINK4, 139, 99, 108, 255);
  color_set("pink", &PINK, 255, 192, 203, 255);
  color_set("plum1", &PLUM1, 255, 187, 255, 255);
  color_set("plum2", &PLUM2, 238, 174, 238, 255);
  color_set("plum3", &PLUM3, 205, 150, 205, 255);
  color_set("plum4", &PLUM4, 139, 102, 139, 255);
  color_set("plum", &PLUM, 221, 160, 221, 255);
  color_set("powderblue", &POWDERBLUE, 176, 224, 230, 255);
  color_set("purple1", &PURPLE1, 155, 48, 255, 255);
  color_set("purple2", &PURPLE2, 145, 44, 238, 255);
  color_set("purple3", &PURPLE3, 125, 38, 205, 255);
  color_set("purple4", &PURPLE4, 85, 26, 139, 255);
  color_set("purple", &PURPLE, 160, 32, 240, 255);
  color_set("red1", &RED1, 255, 0, 0, 255);
  color_set("red2", &RED2, 238, 0, 0, 255);
  color_set("red3", &RED3, 205, 0, 0, 255);
  color_set("red4", &RED4, 139, 0, 0, 255);
  color_set("red", &RED, 255, 0, 0, 255);
  color_set("saddle_brown", &SADDLE_BROWN, 139, 69, 19, 255);
  color_set("saddlebrown", &SADDLEBROWN, 139, 69, 19, 255);
  color_set("seagreen1", &SEAGREEN1, 84, 255, 159, 255);
  color_set("seagreen2", &SEAGREEN2, 78, 238, 148, 255);
  color_set("seagreen3", &SEAGREEN3, 67, 205, 128, 255);
  color_set("seagreen4", &SEAGREEN4, 46, 139, 87, 255);
  color_set("seagreen", &SEAGREEN, 46, 139, 87, 255);
  color_set("sienna1", &SIENNA1, 255, 130, 71, 255);
  color_set("sienna2", &SIENNA2, 238, 121, 66, 255);
  color_set("sienna3", &SIENNA3, 205, 104, 57, 255);
  color_set("sienna4", &SIENNA4, 139, 71, 38, 255);
  color_set("sienna", &SIENNA, 160, 82, 45, 255);
  color_set("skyblue1", &SKYBLUE1, 135, 206, 255, 255);
  color_set("skyblue2", &SKYBLUE2, 126, 192, 238, 255);
  color_set("skyblue3", &SKYBLUE3, 108, 166, 205, 255);
  color_set("skyblue4", &SKYBLUE4, 74, 112, 139, 255);
  color_set("skyblue", &SKYBLUE, 135, 206, 235, 255);
  color_set("slateblue1", &SLATEBLUE1, 131, 111, 255, 255);
  color_set("slateblue2", &SLATEBLUE2, 122, 103, 238, 255);
  color_set("slateblue3", &SLATEBLUE3, 105, 89, 205, 255);
  color_set("slateblue4", &SLATEBLUE4, 71, 60, 139, 255);
  color_set("slateblue", &SLATEBLUE, 106, 90, 205, 255);
  color_set("slategray1", &SLATEGRAY1, 198, 226, 255, 255);
  color_set("slategrey1", &SLATEGREY1, 198, 226, 255, 255);
  color_set("slategray2", &SLATEGRAY2, 185, 211, 238, 255);
  color_set("slategrey2", &SLATEGREY2, 185, 211, 238, 255);
  color_set("slategray3", &SLATEGRAY3, 159, 182, 205, 255);
  color_set("slategrey3", &SLATEGREY3, 159, 182, 205, 255);
  color_set("slategray4", &SLATEGRAY4, 108, 123, 139, 255);
  color_set("slategrey4", &SLATEGREY4, 108, 123, 139, 255);
  color_set("slategray", &SLATEGRAY, 112, 128, 144, 255);
  color_set("slategrey", &SLATEGREY, 112, 128, 144, 255);
  color_set("snow1", &SNOW1, 255, 250, 250, 255);
  color_set("snow2", &SNOW2, 238, 233, 233, 255);
  color_set("snow3", &SNOW3, 205, 201, 201, 255);
  color_set("snow4", &SNOW4, 139, 137, 137, 255);
  color_set("snow", &SNOW, 255, 250, 250, 255);
  color_set("springgreen1", &SPRINGGREEN1, 0, 255, 127, 255);
  color_set("springgreen2", &SPRINGGREEN2, 0, 238, 118, 255);
  color_set("springgreen3", &SPRINGGREEN3, 0, 205, 102, 255);
  color_set("springgreen4", &SPRINGGREEN4, 0, 139, 69, 255);
  color_set("springgreen", &SPRINGGREEN, 0, 255, 127, 255);
  color_set("steelblue1", &STEELBLUE1, 99, 184, 255, 255);
  color_set("steelblue2", &STEELBLUE2, 92, 172, 238, 255);
  color_set("steelblue3", &STEELBLUE3, 79, 148, 205, 255);
  color_set("steelblue4", &STEELBLUE4, 54, 100, 139, 255);
  color_set("steelblue", &STEELBLUE, 70, 130, 180, 255);
  color_set("tan1", &TAN1, 255, 165, 79, 255);
  color_set("tan2", &TAN2, 238, 154, 73, 255);
  color_set("tan3", &TAN3, 205, 133, 63, 255);
  color_set("tan4", &TAN4, 139, 90, 43, 255);
  color_set("tan", &TAN, 210, 180, 140, 255);
  color_set("thistle1", &THISTLE1, 255, 225, 255, 255);
  color_set("thistle2", &THISTLE2, 238, 210, 238, 255);
  color_set("thistle3", &THISTLE3, 205, 181, 205, 255);
  color_set("thistle4", &THISTLE4, 139, 123, 139, 255);
  color_set("thistle", &THISTLE, 216, 191, 216, 255);
  color_set("tomato1", &TOMATO1, 255, 99, 71, 255);
  color_set("tomato2", &TOMATO2, 238, 92, 66, 255);
  color_set("tomato3", &TOMATO3, 205, 79, 57, 255);
  color_set("tomato4", &TOMATO4, 139, 54, 38, 255);
  color_set("tomato", &TOMATO, 255, 99, 71, 255);
  color_set("turquoise1", &TURQUOISE1, 0, 245, 255, 255);
  color_set("turquoise2", &TURQUOISE2, 0, 229, 238, 255);
  color_set("turquoise3", &TURQUOISE3, 0, 197, 205, 255);
  color_set("turquoise4", &TURQUOISE4, 0, 134, 139, 255);
  color_set("turquoise", &TURQUOISE, 64, 224, 208, 255);
  color_set("violetred1", &VIOLETRED1, 255, 62, 150, 255);
  color_set("violetred2", &VIOLETRED2, 238, 58, 140, 255);
  color_set("violetred3", &VIOLETRED3, 205, 50, 120, 255);
  color_set("violetred4", &VIOLETRED4, 139, 34, 82, 255);
  color_set("violetred", &VIOLETRED, 208, 32, 144, 255);
  color_set("violet", &VIOLET, 238, 130, 238, 255);
  color_set("white_smoke", &WHITE_SMOKE, 245, 245, 245, 255);
  color_set("whitesmoke", &WHITESMOKE, 245, 245, 245, 255);
  color_set("white", &WHITE, 255, 255, 255, 255);
  color_set("yellow1", &YELLOW1, 255, 255, 0, 255);
  color_set("yellow2", &YELLOW2, 238, 238, 0, 255);
  color_set("yellow3", &YELLOW3, 205, 205, 0, 255);
  color_set("yellow4", &YELLOW4, 139, 139, 0, 255);
  color_set("yellowgreen", &YELLOWGREEN, 154, 205, 50, 255);
  color_set("yellow", &YELLOW, 255, 255, 0, 255);
}
