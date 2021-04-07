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
#define ________________NUMBER_RIGHT_______________         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPC

#define _________________FUNC_1____________________         KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_2____________________         KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define _________________FUNC_3____________________         KC_TRNS, KC_F11, KC_F12,   KC_F13, KC_F14, KC_F15


#define ___________________BLANK___________________         _______, _______, _______, _______, _______, _______

#define _______________GRID_BOTTOM_ROW_____________         KC_LCTL, KC_LGUI, KC_NO, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT
#define _____________DOUBLE_BOTTOM_ROW_____________         KC_LCTL, KC_LGUI, KC_NO,  KC_LALT,LOWER,     KC_SPC,     RAISE, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT

#define ________________NAV_LEFT_1_________________         EPRM, KC_HOME, KC_UP, KC_END, KC_PGUP,  KC_BSPC //????
#define ________________NAV_LEFT_2_________________         RESET, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,  KC_ENT //????

#define _________________NUMPAD_1__________________         ________________NUMBER_RIGHT_______________
#define _________________NUMPAD_2__________________         KC_PEQL, KC_4, KC_5, KC_6, KC_PAST, KC_ENT
#define _________________NUMPAD_3__________________         KC_PMNS, KC_1, KC_2, KC_3, KC_PSLS, KC_LSFT
#define _________________NUMPAD_4__________________         KC_PPLS, KC_P0, KC_P0, KC_PDOT, KC_COLN, TO(0)


#define _________________LOWER_L1__________________         ___________________BLANK___________________
#define _________________LOWER_L2__________________         ________________NAV_LEFT_1_________________
#define _________________LOWER_L3__________________         ________________NAV_LEFT_2_________________
#define _________________LOWER_L4__________________         _________________FUNC_2____________________

#define _________________LOWER_R1__________________         KC_CIRC, KC_AMPR, KC_ASTR, KC_AT, KC_HASH, KC_DEL
#define _________________LOWER_R2__________________         KC_UNDS, KC_LBRC, KC_RBRC, KC_PIPE, KC_GRV, KC_TRNS
#define _________________LOWER_R3__________________         KC_MINS, KC_LPRN, KC_RPRN, KC_SCLN, KC_EQL, KC_TRNS
#define _________________LOWER_R4__________________         KC_PPLS, KC_LCBR, KC_RCBR, KC_COLN, KC_BSLS, KC_TRNS

#define _________________RAISE_L1__________________         ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________         ________________NUMBER_LEFT________________
#define _________________RAISE_L3__________________         _________________FUNC_1____________________
#define _________________RAISE_L4__________________         _________________FUNC_3____________________

#define _________________RAISE_R1__________________         ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________         ________________NUMBER_RIGHT_______________
#define _________________RAISE_R3__________________         _________________NUMPAD_2__________________
#define _________________RAISE_R4__________________         _________________NUMPAD_3__________________

#define _________________ADJUST_L1_________________         ___________________BLANK___________________
#define _________________ADJUST_L2_________________         RGB_MOD, RGB_TOG, RGBRST, VRSN, DEBUG, EPRM
#define _________________ADJUST_L3_________________         MU_TOG , CK_TOGG, AU_ON,   AU_OFF,  CG_NORM, RESET
#define _________________ADJUST_L4_________________         DBG_KEY,DBG_MX,RGB_SAD, RGB_VAD, RGB_TOG, RGB_IDL

#define _________________ADJUST_R1_________________         ___________________BLANK___________________
#define _________________ADJUST_R2_________________         KC_NO, KC_NO,  EPRM, KC_MAKE,  DEBUG, RESET
#define _________________ADJUST_R3_________________         RGB_MOD, KC_MAKE,  DEBUG, RESET,EPRM,RGB_TOG
#define _________________ADJUST_R4_________________         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0)

// clang-format on
