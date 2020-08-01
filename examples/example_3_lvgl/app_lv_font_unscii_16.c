#include "lvgl/lvgl.h"

/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifndef APP_LV_FONT_UNSCII_16
#define APP_LV_FONT_UNSCII_16 1
#endif

#if APP_LV_FONT_UNSCII_16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t gylph_bitmap[] = {
    /* U+20 " " */
    0x0,

    /* U+21 "!" */
    0xff, 0xff, 0xf,

    /* U+22 "\"" */
    0xcf, 0x3c, 0xc0,

    /* U+23 "#" */
    0x6c, 0xd9, 0xb7, 0xf6, 0xcd, 0x9b, 0x7f, 0x6c,
    0xd9, 0xb0,

    /* U+24 "$" */
    0x30, 0xc7, 0xb3, 0xc1, 0x83, 0x6, 0xf, 0x37,
    0x8c, 0x30,

    /* U+25 "%" */
    0x7, 0x8f, 0x36, 0x61, 0x83, 0xc, 0x18, 0x66,
    0xcf, 0x1e, 0x0,

    /* U+26 "&" */
    0x38, 0xd9, 0xb1, 0xc3, 0xf, 0x77, 0xe6, 0xcd,
    0x99, 0xd8,

    /* U+27 "'" */
    0x6d, 0xe0,

    /* U+28 "(" */
    0x36, 0x6c, 0xcc, 0xcc, 0xcc, 0x66, 0x30,

    /* U+29 ")" */
    0xc6, 0x63, 0x33, 0x33, 0x33, 0x66, 0xc0,

    /* U+2A "*" */
    0x66, 0x66, 0x3c, 0xff, 0x3c, 0x66, 0x66,

    /* U+2B "+" */
    0x30, 0xc3, 0x3f, 0x30, 0xc3, 0x0,

    /* U+2C "," */
    0x73, 0x36, 0xc0,

    /* U+2D "-" */
    0xfc,

    /* U+2E "." */
    0xfc,

    /* U+2F "/" */
    0x3, 0x3, 0x6, 0x6, 0xc, 0xc, 0x18, 0x18,
    0x30, 0x30, 0x60, 0x60, 0xc0, 0xc0,

    /* U+30 "0" */
    0x38, 0xdb, 0x1e, 0x3c, 0xfa, 0xf9, 0xe3, 0xc6,
    0xd8, 0xe0,

    /* U+31 "1" */
    0x31, 0xcf, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xcf,
    0xc0,

    /* U+32 "2" */
    0x7b, 0x3c, 0xc3, 0xc, 0x63, 0x18, 0xc3, 0xf,
    0xc0,

    /* U+33 "3" */
    0x7b, 0x3c, 0xc3, 0xc, 0xe0, 0xc3, 0xcf, 0x37,
    0x80,

    /* U+34 "4" */
    0xc, 0x38, 0xf3, 0x6c, 0xd9, 0xbf, 0x86, 0xc,
    0x18, 0x30,

    /* U+35 "5" */
    0xff, 0xc, 0x30, 0xf8, 0x30, 0xc3, 0xcf, 0x37,
    0x80,

    /* U+36 "6" */
    0x39, 0x8c, 0x30, 0xfb, 0x3c, 0xf3, 0xcf, 0x37,
    0x80,

    /* U+37 "7" */
    0xfc, 0x30, 0xc3, 0x18, 0x63, 0xc, 0x30, 0xc3,
    0x0,

    /* U+38 "8" */
    0x7b, 0x3c, 0xf3, 0xed, 0xed, 0xf3, 0xcf, 0x37,
    0x80,

    /* U+39 "9" */
    0x7b, 0x3c, 0xf3, 0xcd, 0xf0, 0xc3, 0xc, 0x67,
    0x0,

    /* U+3A ":" */
    0xfc, 0x3, 0xf0,

    /* U+3B ";" */
    0x33, 0x30, 0x0, 0x7, 0x33, 0x6c,

    /* U+3C "<" */
    0xc, 0x63, 0x18, 0xc1, 0x83, 0x6, 0xc,

    /* U+3D "=" */
    0xfc, 0x0, 0x0, 0xfc,

    /* U+3E ">" */
    0xc1, 0x83, 0x6, 0xc, 0x63, 0x18, 0xc0,

    /* U+3F "?" */
    0x7b, 0x3c, 0xc3, 0x18, 0xc3, 0xc, 0x0, 0x3,
    0xc,

    /* U+40 "@" */
    0x7d, 0x8f, 0x1e, 0x3d, 0xfb, 0xf7, 0xee, 0xc1,
    0x81, 0xf0,

    /* U+41 "A" */
    0x31, 0xec, 0xf3, 0xcf, 0xfc, 0xf3, 0xcf, 0x3c,
    0xc0,

    /* U+42 "B" */
    0xfb, 0x3c, 0xf3, 0xdb, 0xcd, 0xb3, 0xcf, 0x3f,
    0x80,

    /* U+43 "C" */
    0x7b, 0x3c, 0xf0, 0xc3, 0xc, 0x30, 0xcf, 0x37,
    0x80,

    /* U+44 "D" */
    0xf3, 0x6c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x6f,
    0x0,

    /* U+45 "E" */
    0xff, 0xc, 0x30, 0xc3, 0xec, 0x30, 0xc3, 0xf,
    0xc0,

    /* U+46 "F" */
    0xff, 0xc, 0x30, 0xfb, 0xc, 0x30, 0xc3, 0xc,
    0x0,

    /* U+47 "G" */
    0x7b, 0x3c, 0xf0, 0xc3, 0x7c, 0xf3, 0xcf, 0x37,
    0xc0,

    /* U+48 "H" */
    0xcf, 0x3c, 0xf3, 0xcf, 0xfc, 0xf3, 0xcf, 0x3c,
    0xc0,

    /* U+49 "I" */
    0xfc, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xcf,
    0xc0,

    /* U+4A "J" */
    0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xcf, 0x37,
    0x80,

    /* U+4B "K" */
    0xc7, 0x8f, 0x36, 0x6d, 0x9e, 0x36, 0x66, 0xcd,
    0x8f, 0x18,

    /* U+4C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xf,
    0xc0,

    /* U+4D "M" */
    0xc7, 0xdf, 0xbf, 0xfd, 0x7a, 0xf1, 0xe3, 0xc7,
    0x8f, 0x18,

    /* U+4E "N" */
    0xc7, 0x8f, 0x9f, 0x3f, 0x7f, 0xf7, 0xe7, 0xcf,
    0x8f, 0x18,

    /* U+4F "O" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x37,
    0x80,

    /* U+50 "P" */
    0xfb, 0x3c, 0xf3, 0xcf, 0xec, 0x30, 0xc3, 0xc,
    0x0,

    /* U+51 "Q" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x37,
    0x86, 0xc,

    /* U+52 "R" */
    0xfb, 0x3c, 0xf3, 0xcf, 0xed, 0xb3, 0xcf, 0x3c,
    0xc0,

    /* U+53 "S" */
    0x7b, 0x3c, 0xf0, 0x60, 0xc1, 0x83, 0xcf, 0x37,
    0x80,

    /* U+54 "T" */
    0xfc, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0x0,

    /* U+55 "U" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x37,
    0x80,

    /* U+56 "V" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xde, 0x78, 0xc3,
    0x0,

    /* U+57 "W" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x7a, 0xf5, 0xff, 0xef,
    0xdf, 0x18,

    /* U+58 "X" */
    0xc3, 0xc3, 0x66, 0x3c, 0x18, 0x18, 0x18, 0x3c,
    0x66, 0xc3, 0xc3,

    /* U+59 "Y" */
    0xc3, 0xc3, 0x66, 0x66, 0x3c, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18,

    /* U+5A "Z" */
    0xfc, 0x30, 0xc6, 0x18, 0xc6, 0x18, 0xc3, 0xf,
    0xc0,

    /* U+5B "[" */
    0xfc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xf0,

    /* U+5C "\\" */
    0xc0, 0xc0, 0x60, 0x60, 0x30, 0x30, 0x18, 0x18,
    0xc, 0xc, 0x6, 0x6, 0x3, 0x3,

    /* U+5D "]" */
    0xf3, 0x33, 0x33, 0x33, 0x33, 0x33, 0xf0,

    /* U+5E "^" */
    0x10, 0x71, 0xb3, 0x6c, 0x78, 0xc0,

    /* U+5F "_" */
    0xff,

    /* U+60 "`" */
    0xcc, 0x63,

    /* U+61 "a" */
    0x78, 0x37, 0xf3, 0xcf, 0x37, 0xc0,

    /* U+62 "b" */
    0xc3, 0xc, 0x30, 0xfb, 0x3c, 0xf3, 0xcf, 0x3f,
    0x80,

    /* U+63 "c" */
    0x7b, 0x3c, 0x30, 0xc3, 0x37, 0x80,

    /* U+64 "d" */
    0xc, 0x30, 0xc3, 0x7f, 0x3c, 0xf3, 0xcf, 0x37,
    0xc0,

    /* U+65 "e" */
    0x7b, 0x3c, 0xff, 0xc3, 0x7, 0x80,

    /* U+66 "f" */
    0x3d, 0x86, 0x18, 0xfd, 0x86, 0x18, 0x61, 0x86,
    0x0,

    /* U+67 "g" */
    0x7f, 0x3c, 0xf3, 0xcf, 0x37, 0xc3, 0xf, 0xe0,

    /* U+68 "h" */
    0xc3, 0xc, 0x30, 0xfb, 0x3c, 0xf3, 0xcf, 0x3c,
    0xc0,

    /* U+69 "i" */
    0x30, 0xc0, 0x0, 0xf0, 0xc3, 0xc, 0x30, 0xc3,
    0xc0,

    /* U+6A "j" */
    0x18, 0xc0, 0x1, 0x8c, 0x63, 0x18, 0xc6, 0x31,
    0xf8,

    /* U+6B "k" */
    0xc3, 0xc, 0x30, 0xcf, 0x3d, 0xbc, 0xdb, 0x3c,
    0xc0,

    /* U+6C "l" */
    0xf0, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc0,

    /* U+6D "m" */
    0xcd, 0xff, 0x5e, 0xbd, 0x7a, 0xf1, 0x80,

    /* U+6E "n" */
    0xfb, 0x3c, 0xf3, 0xcf, 0x3c, 0xc0,

    /* U+6F "o" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x37, 0x80,

    /* U+70 "p" */
    0xfb, 0x3c, 0xf3, 0xcf, 0x3f, 0xb0, 0xc3, 0x0,

    /* U+71 "q" */
    0x7f, 0x3c, 0xf3, 0xcf, 0x37, 0xc3, 0xc, 0x30,

    /* U+72 "r" */
    0xfb, 0x3c, 0xf0, 0xc3, 0xc, 0x0,

    /* U+73 "s" */
    0x7f, 0xc, 0x1e, 0xc, 0x3f, 0x80,

    /* U+74 "t" */
    0x61, 0x86, 0x3f, 0x61, 0x86, 0x18, 0x60, 0xf0,

    /* U+75 "u" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x37, 0xc0,

    /* U+76 "v" */
    0xcf, 0x3c, 0xf3, 0xcd, 0xe3, 0x0,

    /* U+77 "w" */
    0xc7, 0x8f, 0x5e, 0xbd, 0x6f, 0x9b, 0x0,

    /* U+78 "x" */
    0xc7, 0x8d, 0xb1, 0xc6, 0xd8, 0xf1, 0x80,

    /* U+79 "y" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x37, 0xc3, 0xd, 0xe0,

    /* U+7A "z" */
    0xfc, 0x31, 0x8c, 0x63, 0xf, 0xc0,

    /* U+7B "{" */
    0xe, 0x30, 0x60, 0xc1, 0x83, 0x3c, 0xc, 0x18,
    0x30, 0x60, 0xc0, 0xe0,

    /* U+7C "|" */
    0xff, 0xff, 0xff, 0xfc,

    /* U+7D "}" */
    0xe0, 0x60, 0xc1, 0x83, 0x6, 0x7, 0x98, 0x30,
    0x60, 0xc1, 0x8e, 0x0,

    /* U+7E "~" */
    0x73, 0xae, 0x70,

    /* U+7F "" */
    0xc1, 0x82, 0x85, 0xa, 0xf5, 0xe9, 0x52, 0xc5,
    0x88, 0x10, 0x20, 0x40, 0x80
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 13},
    {.bitmap_index = 1, .adv_w = 128, .box_w = 2, .box_h = 12, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 128, .box_w = 6, .box_h = 3, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 7, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 27, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 38, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 48, .adv_w = 128, .box_w = 3, .box_h = 4, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 50, .adv_w = 128, .box_w = 4, .box_h = 13, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 57, .adv_w = 128, .box_w = 4, .box_h = 13, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 64, .adv_w = 128, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 71, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 77, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 80, .adv_w = 128, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 81, .adv_w = 128, .box_w = 2, .box_h = 3, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 82, .adv_w = 128, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 96, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 115, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 143, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 161, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 170, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 179, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 188, .adv_w = 128, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 191, .adv_w = 128, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 197, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 204, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 208, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 215, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 224, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 234, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 243, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 252, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 261, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 270, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 279, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 288, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 297, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 306, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 315, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 324, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 334, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 343, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 353, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 363, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 372, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 381, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 391, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 409, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 418, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 427, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 436, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 446, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 457, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 468, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 477, .adv_w = 128, .box_w = 4, .box_h = 13, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 484, .adv_w = 128, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 498, .adv_w = 128, .box_w = 4, .box_h = 13, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 505, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 511, .adv_w = 128, .box_w = 8, .box_h = 1, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 512, .adv_w = 128, .box_w = 4, .box_h = 4, .ofs_x = 3, .ofs_y = 8},
    {.bitmap_index = 514, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 520, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 529, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 535, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 544, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 550, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 559, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 567, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 585, .adv_w = 128, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 594, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 603, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 612, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 619, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 625, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 631, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 639, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 647, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 653, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 659, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 667, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 673, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 679, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 686, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 693, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 701, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 707, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 719, .adv_w = 128, .box_w = 2, .box_h = 15, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 723, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 735, .adv_w = 128, .box_w = 7, .box_h = 3, .ofs_x = 0, .ofs_y = 9},
    {.bitmap_index = 738, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 96, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = gylph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t app_lv_font_unscii_16 = {
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};

#endif /*#if APP_LV_FONT_UNSCII_16*/

