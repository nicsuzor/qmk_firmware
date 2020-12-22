#pragma once
#include "nic.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off
#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)

#define _________________QWERTY_L1_________________         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T
#define _________________QWERTY_L2_________________         KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G
#define _________________QWERTY_L3_________________         KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B

#define _________________QWERTY_R1_________________         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC
#define _________________QWERTY_R2_________________         KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,  KC_ENT
#define _________________QWERTY_R3_________________         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH, KC_RSFT


#define ________________NUMBER_LEFT________________         KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5
#define ________________NUMBER_RIGHT_______________         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_DEL

#define _________________FUNC_1____________________         KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_2____________________         KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define _________________FUNC_3____________________         KC_LSFT, KC_F11, KC_F12,   KC_TRNS, KC_TRNS, KC_TRNS


#define ___________________BLANK___________________         _______, _______, _______, _______, _______, _______

#define _______________GRID_BOTTOM_ROW_____________         KC_LCTL, KC_LGUI, KC_NO, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT
#define _____________DOUBLE_BOTTOM_ROW_____________         KC_LCTL, KC_LGUI, KC_NO,  KC_LALT,LOWER,     KC_SPC,     RAISE, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT


#define _________________LOWER_L1__________________         KC_NO, KC_NO, KC_NO, LCTL(KC_PGUP), LCTL(KC_PGDN), KC_NO
#define _________________LOWER_L2__________________         KC_TAB, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_BSPC
#define _________________LOWER_L3__________________         KC_ESC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_ENT
#define _________________LOWER_L4__________________         KC_LSFT, KC_NO, KC_LCTL, KC_NO, KC_NO, KC_DEL

#define _________________LOWER_R1__________________         KC_CIRC, KC_AMPR, KC_ASTR, KC_AT, KC_HASH, KC_BSPC
#define _________________LOWER_R2__________________         KC_UNDS, KC_LBRC, KC_RBRC, KC_PIPE, KC_GRV, KC_DEL
#define _________________LOWER_R3__________________         KC_MINS, KC_LPRN, KC_RPRN, KC_SCLN, KC_EQL, KC_ENT
#define _________________LOWER_R4__________________         KC_PPLS, KC_LCBR, KC_RCBR, KC_COLN, KC_BSLS, TO(0)

#define _________________RAISE_L1__________________         ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________         _________________FUNC_1____________________
#define _________________RAISE_L3__________________         _________________FUNC_2____________________
#define _________________RAISE_L4__________________         _________________FUNC_3____________________

#define _________________RAISE_R1__________________         ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________         KC_PEQL, KC_4, KC_5, KC_6, KC_PAST, KC_ENT
#define _________________RAISE_R3__________________         KC_PMNS, KC_1, KC_2, KC_3, KC_PSLS, KC_LSFT
#define _________________RAISE_R4__________________         KC_PPLS, KC_P0, KC_P0, KC_PDOT, KC_COLN, TO(0)

#define _________________ADJUST_L1_________________         RGB_MOD, KC_RGB_T, KC_PSCR, LCTL(LSFT(KC_ESC)), LALT(KC_F4), LCTL(LSFT(KC_ESC))
#define _________________ADJUST_L2_________________         MU_TOG , CK_TOGG, AU_ON,   AU_OFF,  CG_NORM, KC_NO
#define _________________ADJUST_L3_________________         RGB_RMOD,RGB_HUD,RGB_SAD, RGB_VAD, RGB_TOG, RGB_IDL

#define _________________ADJUST_R1_________________         KC_F11, KC_F12,  KC_C, KC_F14,  DEBUG, RESET
#define _________________ADJUST_R2_________________         ___________________BLANK___________________
#define _________________ADJUST_R3_________________         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0)

// clang-format on
