#include QMK_KEYBOARD_H
#include "nic.h"

// clang-format off

#define LAYOUT_crkbd_wrapper(...)       LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_crkbd_wrapper(
    _________________QWERTY_L1_________________,                _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________,                _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________,                _________________QWERTY_R3_________________,

                        KC_LALT, KC_LCTL, LT(_LOWER, KC_SPC), LT(_RAISE, KC_BSPC), KC_DEL, KC_RGUI
),

[_LOWER] = LAYOUT_crkbd_wrapper(
    _________________LOWER_L2__________________,                _________________LOWER_R2__________________,
    _________________LOWER_L3__________________,                _________________LOWER_R3__________________,
    _________________LOWER_L4__________________,                _________________LOWER_R4__________________,
            TO(_ADJUST), KC_LCTL, LT(_LOWER, KC_SPC), LT(_RAISE, KC_DEL), KC_LALT, KC_RGUI
),

[_RAISE] = LAYOUT_crkbd_wrapper(
    _________________RAISE_L2__________________,                _________________RAISE_R2__________________,
    _________________RAISE_L3__________________,                _________________RAISE_R3__________________,
    _________________RAISE_L4__________________,                _________________RAISE_R4__________________,
            TO(_ADJUST), KC_LCTL, LT(_LOWER, KC_SPC), LT(_RAISE, KC_DEL), KC_LALT, KC_RGUI
),

[_ADJUST] = LAYOUT_crkbd_wrapper(
    _________________ADJUST_L2_________________,                    _________________ADJUST_R2_________________,
    _________________ADJUST_L3_________________,                    _________________ADJUST_R3_________________,
    _________________ADJUST_L4_________________,                    _________________ADJUST_R4_________________,
    TO(0), KC_LCTL, LT(_LOWER, KC_SPC), LT(_RAISE, KC_DEL), KC_LALT, KC_RGUI
)
};
