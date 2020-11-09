#include QMK_KEYBOARD_H
#include <print.h>
#include "4x12.h"
#include nic_layout.c

enum layers {
    _MAIN,
    _RAISE,
    _LOWER,
    _GAMES,
    _ADJUST
};


// Logging debug stuff
#define DEBUG_MATRIX_SCAN_RATE
const uint16_t nic_layout[] = {5, 6, 7, 8};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
  return true;
}

// Readability keycodes
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT_ortho_4x12(

        ARRAY_CONCAT(uint16_t, nic_base[_QWER], 7,
                     _ASDF], 7,_ZXCV], 7,_1234], 7,_YUIO], 7,_HJKL], 7,_NM], 7,_6789, 7, b, 2);)

        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                   KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,                   KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_SPC, KC_LALT, KC_SPC, KC_SPC, LT(1,KC_SPC), LT(2,KC_NO), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

  [_RAISE] = LAYOUT_ortho_4x12(
        OSL(4), KC_HOME, KC_UP, KC_END, KC_PGUP, KC_BSPC, KC_UNDS, KC_LBRC, KC_RBRC, KC_PIPE, KC_GRV, KC_DEL,
        KC_DEL, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_ENT, KC_MINS, KC_LPRN, KC_RPRN, KC_SCLN, KC_EQL, KC_ENT,
        KC_TRNS, KC_NO, KC_LCTL, KC_NO, KC_NO, KC_DEL, KC_PPLS, KC_LCBR, KC_RCBR, KC_COLN, KC_BSLS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, TO(0)),

  [_LOWER] = LAYOUT_ortho_4x12(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_PMNS, KC_4, KC_5, KC_6, KC_PAST, KC_ENT,
        KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_EQL, KC_1, KC_2, KC_3, KC_PSLS,
        KC_LSFT, KC_TRNS, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_P0, KC_PDOT, KC_COLN, TO(0)),

};
