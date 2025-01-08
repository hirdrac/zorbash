//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_color_defs.hpp"
#include "my_sys.hpp"

#include <string.h>  // do not remove
#include <strings.h> // do not remove, strcasecmp

// begin sort marker1 {
color GRAY10;
color GRAY11;
color GRAY12;
color GRAY13;
color GRAY14;
color GRAY15;
color GRAY16;
color GRAY17;
color GRAY18;
color GRAY19;
color GRAY1;
color GRAY20;
color GRAY21;
color GRAY22;
color GRAY23;
color GRAY24;
color GRAY25;
color GRAY26;
color GRAY27;
color GRAY28;
color GRAY29;
color GRAY2;
color GRAY30;
color GRAY31;
color GRAY32;
color GRAY33;
color GRAY34;
color GRAY35;
color GRAY36;
color GRAY37;
color GRAY38;
color GRAY39;
color GRAY3;
color GRAY40;
color GRAY41;
color GRAY42;
color GRAY43;
color GRAY44;
color GRAY45;
color GRAY46;
color GRAY47;
color GRAY48;
color GRAY49;
color GRAY4;
color GRAY50;
color GRAY51;
color GRAY52;
color GRAY53;
color GRAY54;
color GRAY55;
color GRAY56;
color GRAY57;
color GRAY58;
color GRAY59;
color GRAY5;
color GRAY60;
color GRAY61;
color GRAY62;
color GRAY63;
color GRAY64;
color GRAY65;
color GRAY66;
color GRAY67;
color GRAY68;
color GRAY69;
color GRAY6;
color GRAY70;
color GRAY71;
color GRAY72;
color GRAY73;
color GRAY74;
color GRAY75;
color GRAY76;
color GRAY77;
color GRAY78;
color GRAY79;
color GRAY7;
color GRAY80;
color GRAY81;
color GRAY82;
color GRAY83;
color GRAY84;
color GRAY85;
color GRAY86;
color GRAY87;
color GRAY88;
color GRAY89;
color GRAY8;
color GRAY90;
color GRAY91;
color GRAY92;
color GRAY93;
color GRAY94;
color GRAY95;
color GRAY96;
color GRAY97;
color GRAY98;
color GRAY99;
color GRAY9;
color GRAY;
color GREEN1;
color GREEN2;
color GREEN3;
color GREEN4;
color GREEN;
color GREENYELLOW;
color GREEN_YELLOW;
color GREY10;
color GREY11;
color GREY12;
color GREY13;
color GREY14;
color GREY15;
color GREY16;
color GREY17;
color GREY18;
color GREY19;
color GREY1;
color GREY20;
color GREY21;
color GREY22;
color GREY23;
color GREY24;
color GREY25;
color GREY26;
color GREY27;
color GREY28;
color GREY29;
color GREY2;
color GREY30;
color GREY31;
color GREY32;
color GREY33;
color GREY34;
color GREY35;
color GREY36;
color GREY37;
color GREY38;
color GREY39;
color GREY3;
color GREY40;
color GREY41;
color GREY42;
color GREY43;
color GREY44;
color GREY45;
color GREY46;
color GREY47;
color GREY48;
color GREY49;
color GREY4;
color GREY50;
color GREY51;
color GREY52;
color GREY53;
color GREY54;
color GREY55;
color GREY56;
color GREY57;
color GREY58;
color GREY59;
color GREY5;
color GREY60;
color GREY61;
color GREY62;
color GREY63;
color GREY64;
color GREY65;
color GREY66;
color GREY67;
color GREY68;
color GREY69;
color GREY6;
color GREY70;
color GREY71;
color GREY72;
color GREY73;
color GREY74;
color GREY75;
color GREY76;
color GREY77;
color GREY78;
color GREY79;
color GREY7;
color GREY80;
color GREY81;
color GREY82;
color GREY83;
color GREY84;
color GREY85;
color GREY86;
color GREY87;
color GREY88;
color GREY89;
color GREY8;
color GREY90;
color GREY91;
color GREY92;
color GREY93;
color GREY94;
color GREY95;
color GREY96;
color GREY97;
color GREY98;
color GREY99;
color GREY9;
color GREY;
// end sort marker1 }

void color_init2(void)
{
  TRACE_AND_INDENT();

  // begin sort marker2 {
  color_set("gray", &GRAY, 190, 190, 190, 255);
  color_set("gray1", &GRAY1, 3, 3, 3, 255);
  color_set("gray10", &GRAY10, 26, 26, 26, 255);
  color_set("gray11", &GRAY11, 28, 28, 28, 255);
  color_set("gray12", &GRAY12, 31, 31, 31, 255);
  color_set("gray13", &GRAY13, 33, 33, 33, 255);
  color_set("gray14", &GRAY14, 36, 36, 36, 255);
  color_set("gray15", &GRAY15, 38, 38, 38, 255);
  color_set("gray16", &GRAY16, 41, 41, 41, 255);
  color_set("gray17", &GRAY17, 43, 43, 43, 255);
  color_set("gray18", &GRAY18, 46, 46, 46, 255);
  color_set("gray19", &GRAY19, 48, 48, 48, 255);
  color_set("gray2", &GRAY2, 5, 5, 5, 255);
  color_set("gray20", &GRAY20, 51, 51, 51, 255);
  color_set("gray21", &GRAY21, 54, 54, 54, 255);
  color_set("gray22", &GRAY22, 56, 56, 56, 255);
  color_set("gray23", &GRAY23, 59, 59, 59, 255);
  color_set("gray24", &GRAY24, 61, 61, 61, 255);
  color_set("gray25", &GRAY25, 64, 64, 64, 255);
  color_set("gray26", &GRAY26, 66, 66, 66, 255);
  color_set("gray27", &GRAY27, 69, 69, 69, 255);
  color_set("gray28", &GRAY28, 71, 71, 71, 255);
  color_set("gray29", &GRAY29, 74, 74, 74, 255);
  color_set("gray3", &GRAY3, 8, 8, 8, 255);
  color_set("gray30", &GRAY30, 77, 77, 77, 255);
  color_set("gray31", &GRAY31, 79, 79, 79, 255);
  color_set("gray32", &GRAY32, 82, 82, 82, 255);
  color_set("gray33", &GRAY33, 84, 84, 84, 255);
  color_set("gray34", &GRAY34, 87, 87, 87, 255);
  color_set("gray35", &GRAY35, 89, 89, 89, 255);
  color_set("gray36", &GRAY36, 92, 92, 92, 255);
  color_set("gray37", &GRAY37, 94, 94, 94, 255);
  color_set("gray38", &GRAY38, 97, 97, 97, 255);
  color_set("gray39", &GRAY39, 99, 99, 99, 255);
  color_set("gray4", &GRAY4, 10, 10, 10, 255);
  color_set("gray40", &GRAY40, 102, 102, 102, 255);
  color_set("gray41", &GRAY41, 105, 105, 105, 255);
  color_set("gray42", &GRAY42, 107, 107, 107, 255);
  color_set("gray43", &GRAY43, 110, 110, 110, 255);
  color_set("gray44", &GRAY44, 112, 112, 112, 255);
  color_set("gray45", &GRAY45, 115, 115, 115, 255);
  color_set("gray46", &GRAY46, 117, 117, 117, 255);
  color_set("gray47", &GRAY47, 120, 120, 120, 255);
  color_set("gray48", &GRAY48, 122, 122, 122, 255);
  color_set("gray49", &GRAY49, 125, 125, 125, 255);
  color_set("gray5", &GRAY5, 13, 13, 13, 255);
  color_set("gray50", &GRAY50, 127, 127, 127, 255);
  color_set("gray51", &GRAY51, 130, 130, 130, 255);
  color_set("gray52", &GRAY52, 133, 133, 133, 255);
  color_set("gray53", &GRAY53, 135, 135, 135, 255);
  color_set("gray54", &GRAY54, 138, 138, 138, 255);
  color_set("gray55", &GRAY55, 140, 140, 140, 255);
  color_set("gray56", &GRAY56, 143, 143, 143, 255);
  color_set("gray57", &GRAY57, 145, 145, 145, 255);
  color_set("gray58", &GRAY58, 148, 148, 148, 255);
  color_set("gray59", &GRAY59, 150, 150, 150, 255);
  color_set("gray6", &GRAY6, 15, 15, 15, 255);
  color_set("gray60", &GRAY60, 153, 153, 153, 255);
  color_set("gray61", &GRAY61, 156, 156, 156, 255);
  color_set("gray62", &GRAY62, 158, 158, 158, 255);
  color_set("gray63", &GRAY63, 161, 161, 161, 255);
  color_set("gray64", &GRAY64, 163, 163, 163, 255);
  color_set("gray65", &GRAY65, 166, 166, 166, 255);
  color_set("gray66", &GRAY66, 168, 168, 168, 255);
  color_set("gray67", &GRAY67, 171, 171, 171, 255);
  color_set("gray68", &GRAY68, 173, 173, 173, 255);
  color_set("gray69", &GRAY69, 176, 176, 176, 255);
  color_set("gray7", &GRAY7, 18, 18, 18, 255);
  color_set("gray70", &GRAY70, 179, 179, 179, 255);
  color_set("gray71", &GRAY71, 181, 181, 181, 255);
  color_set("gray72", &GRAY72, 184, 184, 184, 255);
  color_set("gray73", &GRAY73, 186, 186, 186, 255);
  color_set("gray74", &GRAY74, 189, 189, 189, 255);
  color_set("gray75", &GRAY75, 191, 191, 191, 255);
  color_set("gray76", &GRAY76, 194, 194, 194, 255);
  color_set("gray77", &GRAY77, 196, 196, 196, 255);
  color_set("gray78", &GRAY78, 199, 199, 199, 255);
  color_set("gray79", &GRAY79, 201, 201, 201, 255);
  color_set("gray8", &GRAY8, 20, 20, 20, 255);
  color_set("gray80", &GRAY80, 204, 204, 204, 255);
  color_set("gray81", &GRAY81, 207, 207, 207, 255);
  color_set("gray82", &GRAY82, 209, 209, 209, 255);
  color_set("gray83", &GRAY83, 212, 212, 212, 255);
  color_set("gray84", &GRAY84, 214, 214, 214, 255);
  color_set("gray85", &GRAY85, 217, 217, 217, 255);
  color_set("gray86", &GRAY86, 219, 219, 219, 255);
  color_set("gray87", &GRAY87, 222, 222, 222, 255);
  color_set("gray88", &GRAY88, 224, 224, 224, 255);
  color_set("gray89", &GRAY89, 227, 227, 227, 255);
  color_set("gray9", &GRAY9, 23, 23, 23, 255);
  color_set("gray90", &GRAY90, 229, 229, 229, 255);
  color_set("gray91", &GRAY91, 232, 232, 232, 255);
  color_set("gray92", &GRAY92, 235, 235, 235, 255);
  color_set("gray93", &GRAY93, 237, 237, 237, 255);
  color_set("gray94", &GRAY94, 240, 240, 240, 255);
  color_set("gray95", &GRAY95, 242, 242, 242, 255);
  color_set("gray96", &GRAY96, 245, 245, 245, 255);
  color_set("gray97", &GRAY97, 247, 247, 247, 255);
  color_set("gray98", &GRAY98, 250, 250, 250, 255);
  color_set("gray99", &GRAY99, 252, 252, 252, 255);
  color_set("green", &GREEN, 0, 255, 0, 255);
  color_set("green1", &GREEN1, 0, 255, 0, 255);
  color_set("green2", &GREEN2, 0, 238, 0, 255);
  color_set("green3", &GREEN3, 0, 205, 0, 255);
  color_set("green4", &GREEN4, 0, 139, 0, 255);
  color_set("greenyellow", &GREENYELLOW, 173, 255, 47, 255);
  color_set("grey", &GREY, 190, 190, 190, 255);
  color_set("grey1", &GREY1, 3, 3, 3, 255);
  color_set("grey10", &GREY10, 26, 26, 26, 255);
  color_set("grey11", &GREY11, 28, 28, 28, 255);
  color_set("grey12", &GREY12, 31, 31, 31, 255);
  color_set("grey13", &GREY13, 33, 33, 33, 255);
  color_set("grey14", &GREY14, 36, 36, 36, 255);
  color_set("grey15", &GREY15, 38, 38, 38, 255);
  color_set("grey16", &GREY16, 41, 41, 41, 255);
  color_set("grey17", &GREY17, 43, 43, 43, 255);
  color_set("grey18", &GREY18, 46, 46, 46, 255);
  color_set("grey19", &GREY19, 48, 48, 48, 255);
  color_set("grey2", &GREY2, 5, 5, 5, 255);
  color_set("grey20", &GREY20, 51, 51, 51, 255);
  color_set("grey21", &GREY21, 54, 54, 54, 255);
  color_set("grey22", &GREY22, 56, 56, 56, 255);
  color_set("grey23", &GREY23, 59, 59, 59, 255);
  color_set("grey24", &GREY24, 61, 61, 61, 255);
  color_set("grey25", &GREY25, 64, 64, 64, 255);
  color_set("grey26", &GREY26, 66, 66, 66, 255);
  color_set("grey27", &GREY27, 69, 69, 69, 255);
  color_set("grey28", &GREY28, 71, 71, 71, 255);
  color_set("grey29", &GREY29, 74, 74, 74, 255);
  color_set("grey3", &GREY3, 8, 8, 8, 255);
  color_set("grey30", &GREY30, 77, 77, 77, 255);
  color_set("grey31", &GREY31, 79, 79, 79, 255);
  color_set("grey32", &GREY32, 82, 82, 82, 255);
  color_set("grey33", &GREY33, 84, 84, 84, 255);
  color_set("grey34", &GREY34, 87, 87, 87, 255);
  color_set("grey35", &GREY35, 89, 89, 89, 255);
  color_set("grey36", &GREY36, 92, 92, 92, 255);
  color_set("grey37", &GREY37, 94, 94, 94, 255);
  color_set("grey38", &GREY38, 97, 97, 97, 255);
  color_set("grey39", &GREY39, 99, 99, 99, 255);
  color_set("grey4", &GREY4, 10, 10, 10, 255);
  color_set("grey40", &GREY40, 102, 102, 102, 255);
  color_set("grey41", &GREY41, 105, 105, 105, 255);
  color_set("grey42", &GREY42, 107, 107, 107, 255);
  color_set("grey43", &GREY43, 110, 110, 110, 255);
  color_set("grey44", &GREY44, 112, 112, 112, 255);
  color_set("grey45", &GREY45, 115, 115, 115, 255);
  color_set("grey46", &GREY46, 117, 117, 117, 255);
  color_set("grey47", &GREY47, 120, 120, 120, 255);
  color_set("grey48", &GREY48, 122, 122, 122, 255);
  color_set("grey49", &GREY49, 125, 125, 125, 255);
  color_set("grey5", &GREY5, 13, 13, 13, 255);
  color_set("grey50", &GREY50, 127, 127, 127, 255);
  color_set("grey51", &GREY51, 130, 130, 130, 255);
  color_set("grey52", &GREY52, 133, 133, 133, 255);
  color_set("grey53", &GREY53, 135, 135, 135, 255);
  color_set("grey54", &GREY54, 138, 138, 138, 255);
  color_set("grey55", &GREY55, 140, 140, 140, 255);
  color_set("grey56", &GREY56, 143, 143, 143, 255);
  color_set("grey57", &GREY57, 145, 145, 145, 255);
  color_set("grey58", &GREY58, 148, 148, 148, 255);
  color_set("grey59", &GREY59, 150, 150, 150, 255);
  color_set("grey6", &GREY6, 15, 15, 15, 255);
  color_set("grey60", &GREY60, 153, 153, 153, 255);
  color_set("grey61", &GREY61, 156, 156, 156, 255);
  color_set("grey62", &GREY62, 158, 158, 158, 255);
  color_set("grey63", &GREY63, 161, 161, 161, 255);
  color_set("grey64", &GREY64, 163, 163, 163, 255);
  color_set("grey65", &GREY65, 166, 166, 166, 255);
  color_set("grey66", &GREY66, 168, 168, 168, 255);
  color_set("grey67", &GREY67, 171, 171, 171, 255);
  color_set("grey68", &GREY68, 173, 173, 173, 255);
  color_set("grey69", &GREY69, 176, 176, 176, 255);
  color_set("grey7", &GREY7, 18, 18, 18, 255);
  color_set("grey70", &GREY70, 179, 179, 179, 255);
  color_set("grey71", &GREY71, 181, 181, 181, 255);
  color_set("grey72", &GREY72, 184, 184, 184, 255);
  color_set("grey73", &GREY73, 186, 186, 186, 255);
  color_set("grey74", &GREY74, 189, 189, 189, 255);
  color_set("grey75", &GREY75, 191, 191, 191, 255);
  color_set("grey76", &GREY76, 194, 194, 194, 255);
  color_set("grey77", &GREY77, 196, 196, 196, 255);
  color_set("grey78", &GREY78, 199, 199, 199, 255);
  color_set("grey79", &GREY79, 201, 201, 201, 255);
  color_set("grey8", &GREY8, 20, 20, 20, 255);
  color_set("grey80", &GREY80, 204, 204, 204, 255);
  color_set("grey81", &GREY81, 207, 207, 207, 255);
  color_set("grey82", &GREY82, 209, 209, 209, 255);
  color_set("grey83", &GREY83, 212, 212, 212, 255);
  color_set("grey84", &GREY84, 214, 214, 214, 255);
  color_set("grey85", &GREY85, 217, 217, 217, 255);
  color_set("grey86", &GREY86, 219, 219, 219, 255);
  color_set("grey87", &GREY87, 222, 222, 222, 255);
  color_set("grey88", &GREY88, 224, 224, 224, 255);
  color_set("grey89", &GREY89, 227, 227, 227, 255);
  color_set("grey9", &GREY9, 23, 23, 23, 255);
  color_set("grey90", &GREY90, 229, 229, 229, 255);
  color_set("grey91", &GREY91, 232, 232, 232, 255);
  color_set("grey92", &GREY92, 235, 235, 235, 255);
  color_set("grey93", &GREY93, 237, 237, 237, 255);
  color_set("grey94", &GREY94, 240, 240, 240, 255);
  color_set("grey95", &GREY95, 242, 242, 242, 255);
  color_set("grey96", &GREY96, 245, 245, 245, 255);
  color_set("grey97", &GREY97, 247, 247, 247, 255);
  color_set("grey98", &GREY98, 250, 250, 250, 255);
  color_set("grey99", &GREY99, 252, 252, 252, 255);
  // end sort marker2 }
}
