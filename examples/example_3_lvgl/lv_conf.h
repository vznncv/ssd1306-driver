/**
 * Minimal littlevgl configuration file for a "SSD1306" based OLED displays.
 *
 * Note: for missed settings default values from "lv_conf_internal.h" are used.
 *
 * Configuration file for LVGL v7.2.0
 */

#ifndef LV_CONF_H
#define LV_CONF_H

#include <stdint.h>

/*====================
   Graphical settings
 *====================*/

/* Color depth:
 * - 1:  1 byte per pixel
 * - 8:  RGB332
 * - 16: RGB565
 * - 32: ARGB8888
 */
#define LV_COLOR_DEPTH 1

/* Disable anti-aliasing as we use monochrome display */
#define LV_ANTIALIAS 0

/* Default display refresh period.
 *
 */
#define LV_DISP_DEF_REFR_PERIOD 30 /*[ms]*/

/* Type of coordinates. Should be `int16_t` (or `int32_t` for extreme cases) */
typedef int16_t lv_coord_t;

/*=========================
   Memory manager settings
 *=========================*/

/* use system malloc/free */
#define LV_MEM_CUSTOM 1
#define LV_MEM_CUSTOM_INCLUDE <stdlib.h> /*Header for the dynamic memory function*/
#define LV_MEM_CUSTOM_ALLOC malloc /*Wrapper to malloc*/
#define LV_MEM_CUSTOM_FREE free /*Wrapper to free*/

/*=======================
   Input device settings
 *=======================*/

/*==================
 * Feature usage
 *==================*/

/*1: Enable the Animations */
#define LV_USE_ANIMATION 0
/*1: Enable shadow drawing*/
#define LV_USE_SHADOW 0
/*1: Enable GPU interface*/
#define LV_USE_GPU 0 /*Only enables `gpu_fill_cb` and `gpu_blend_cb` in the disp. drv- */

#define LV_USE_FILESYSTEM 0

/*1: Add a `user_data` to drivers and objects*/
#define LV_USE_USER_DATA 1

/*1: Use the functions and types from the older API if possible */
#define LV_USE_API_EXTENSION_V6 0
#define LV_USE_API_EXTENSION_V7 1

/* group data */
typedef void *lv_group_user_data_t;

/*========================
 * Image decoder and cache
 *========================*/

/*Declare the type of the user data of image decoder (can be e.g. `void *`, `int`, `struct`)*/
typedef void *lv_img_decoder_user_data_t;

/*=====================
 *  Compiler settings
 *====================*/

/* For big endian systems set to 1 */
#define LV_BIG_ENDIAN_SYSTEM 0

/*===================
 *  HAL settings
 *==================*/

/* 1: use a custom tick source.
 * It removes the need to manually update the tick with `lv_tick_inc`) */
#define LV_TICK_CUSTOM 1
#if LV_TICK_CUSTOM == 1
#define LV_TICK_CUSTOM_INCLUDE "lv_mbed_tick_port.h" /*Header for the system time function*/
#define LV_TICK_CUSTOM_SYS_TIME_EXPR (lv_mbed_tick_get()) /*Expression evaluating to current system time in ms*/
#endif /*LV_TICK_CUSTOM*/

typedef void *lv_disp_drv_user_data_t; /*Type of user data in the display driver*/
typedef void *lv_indev_drv_user_data_t; /*Type of user data in the input device driver*/

/*================
 * Log settings
 *===============*/

/*1: Enable the log module*/
#define LV_USE_LOG 0

/*=================
 * Debug settings
 *================*/

/* If Debug is enabled LittelvGL validates the parameters of the functions.
 * If an invalid parameter is found an error log message is printed and
 * the MCU halts at the error. (`LV_USE_LOG` should be enabled)
 * If you are debugging the MCU you can pause
 * the debugger to see exactly where  the issue is.
 *
 * The behavior of asserts can be overwritten by redefining them here.
 * E.g. #define LV_ASSERT_MEM(p)  <my_assert_code>
 */
#define LV_USE_DEBUG 1

/*==================
 *    FONT USAGE
 *===================*/

/* The built-in fonts contains the ASCII range and some Symbols with  4 bit-per-pixel.
 * The symbols are available via `LV_SYMBOL_...` defines
 * More info about fonts: https://docs.lvgl.io/v7/en/html/overview/font.html
 * To create a new font go to: https://lvgl.com/ttf-font-to-c-array
 */

/* Montserrat fonts with bpp = 4
 * https://fonts.google.com/specimen/Montserrat  */
#define LV_FONT_MONTSERRAT_12 0
#define LV_FONT_MONTSERRAT_14 0
#define LV_FONT_MONTSERRAT_16 0
#define LV_FONT_MONTSERRAT_18 0
#define LV_FONT_MONTSERRAT_20 0
#define LV_FONT_MONTSERRAT_22 0
#define LV_FONT_MONTSERRAT_24 0
#define LV_FONT_MONTSERRAT_26 0
#define LV_FONT_MONTSERRAT_28 0
#define LV_FONT_MONTSERRAT_30 0
#define LV_FONT_MONTSERRAT_32 0
#define LV_FONT_MONTSERRAT_34 0
#define LV_FONT_MONTSERRAT_36 0
#define LV_FONT_MONTSERRAT_38 0
#define LV_FONT_MONTSERRAT_40 0
#define LV_FONT_MONTSERRAT_42 0
#define LV_FONT_MONTSERRAT_44 0
#define LV_FONT_MONTSERRAT_46 0
#define LV_FONT_MONTSERRAT_48 0

/*Pixel perfect monospace font
 * http://pelulamu.net/unscii/ */
#define LV_FONT_UNSCII_8 1

/* Optionally declare your custom fonts here.
 * You can use these fonts as default font too
 * and they will be available globally. E.g.
 * #define LV_FONT_CUSTOM_DECLARE LV_FONT_DECLARE(my_font_1) \
 *                                LV_FONT_DECLARE(my_font_2)
 */
#define LV_FONT_CUSTOM_DECLARE LV_FONT_DECLARE(app_lv_font_unscii_16)

/*Declare the type of the user data of fonts (can be e.g. `void *`, `int`, `struct`)*/
typedef void *lv_font_user_data_t;

/*================
 *  THEME USAGE
 *================*/

/* Disable all themes, except MONO */

#define LV_USE_THEME_EMPTY 0
#define LV_USE_THEME_TEMPLATE 0
#define LV_USE_THEME_MATERIAL 0

/* Mono-color theme for monochrome displays.
 * If LV_THEME_DEFAULT_COLOR_PRIMARY is LV_COLOR_BLACK the
 * texts and borders will be black and the background will be
 * white. Else the colors are inverted.
 * No flags. Set LV_THEME_DEFAULT_FLAG 0 */
#define LV_USE_THEME_MONO 1

#define LV_THEME_DEFAULT_INCLUDE <stdint.h> /*Include a header for the init. function*/
#define LV_THEME_DEFAULT_INIT lv_theme_mono_init
#define LV_THEME_DEFAULT_COLOR_PRIMARY LV_COLOR_WHITE
#define LV_THEME_DEFAULT_COLOR_SECONDARY LV_COLOR_WHITE
#define LV_THEME_DEFAULT_FLAG 0
#define LV_THEME_DEFAULT_FONT_SMALL &lv_font_unscii_8
#define LV_THEME_DEFAULT_FONT_NORMAL &app_lv_font_unscii_16
#define LV_THEME_DEFAULT_FONT_SUBTITLE &app_lv_font_unscii_16
#define LV_THEME_DEFAULT_FONT_TITLE &app_lv_font_unscii_16

/*=================
 *  Text settings
 *=================*/

/* Select a character encoding for strings.
 * Your IDE or editor should have the same character encoding
 * - LV_TXT_ENC_UTF8
 * - LV_TXT_ENC_ASCII
 * */
#define LV_TXT_ENC LV_TXT_ENC_UTF8

/* use mbed printf function */
#define LV_SPRINTF_CUSTOM 1
#if LV_SPRINTF_CUSTOM
#define LV_SPRINTF_INCLUDE <stdio.h>
#define lv_snprintf snprintf
#define lv_vsnprintf vsnprintf
#else /*!LV_SPRINTF_CUSTOM*/
#define LV_SPRINTF_DISABLE_FLOAT 1
#endif /*LV_SPRINTF_CUSTOM*/

/*===================
 *  LV_OBJ SETTINGS
 *==================*/

/*Declare the type of the user data of object (can be e.g. `void *`, `int`, `struct`)*/
typedef void *lv_obj_user_data_t;

/*==================
 *  LV OBJ X USAGE
 *================*/
/*
 * Documentation of the object types: https://docs.lvgl.com/#Object-types.
 */

/* Disable items that require any animation */
#define LV_USE_SWITCH 0
#define LV_USE_SPINBOX 0
#define LV_USE_TILEVIEW 0
#define LV_USE_TABVIEW 0
#define LV_USE_WIN 0
#define LV_USE_DROPDOWN 0
#define LV_USE_KEYBOARD 0
#define LV_USE_TEXTAREA 0
#define LV_USE_LIST 0
#define LV_USE_TEXTAREA 0
#define LV_USE_ROLLER 0
#define LV_USE_PAGE 0
#define LV_USE_SPINNER 0

#endif /*LV_CONF_H*/
