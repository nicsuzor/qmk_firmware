#include QMK_KEYBOARD_H
#include "nic.h"

#include "lufa.h"
#include "split_util.h"
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// clang-format off
#define LAYOUT_LILY( \
	L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05,  \
	L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15,  \
	L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25,  \
	L30, L31, L32, L33, L34, L35, L45, R40, R30, R31, R32, R33, R34, R35, \
	               L41, L42, L43, L44, R41, R42, R43, R44  \
	) \
    { \
		{ L00, L01, L02, L03, L04, L05 }, \
		{ L10, L11, L12, L13, L14, L15 }, \
		{ L20, L21, L22, L23, L24, L25 }, \
		{ L30, L31, L32, L33, L34, L35 }, \
		{ KC_NO, L41, L42, L43, L44, L45 }, \
		{ KC_BSPC, R04, R03, R02, R01, R00 }, \
		{ KC_F17, R14, R13, R12, R11, R10 }, \
		{ R25, R24, R23, R22, R21, R20 }, \
		{ R35, R34, R33, R32, R31, R30 }, \
		{ KC_NO, R44, R43, R42, R41, R40 } \
    }

#define LAYOUT_lily_base_wrapper(...)       LAYOUT_LILY(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_lily_base_wrapper(
    ________________NUMBER_LEFT________________,                ________________NUMBER_RIGHT_______________,
    _________________QWERTY_L1_________________,                _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________,                _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, KC_F13, KC_F14, _________________QWERTY_R3_________________,
            KC_F15, KC_LALT, KC_LCTL, LT(_LOWER, KC_SPC), LT(_RAISE, KC_BSPC), KC_DEL, KC_RGUI, KC_RGUI
),

[_LOWER] = LAYOUT_lily_base_wrapper(
    _________________LOWER_L1__________________,                _________________LOWER_R1__________________,
    _________________LOWER_L2__________________,                _________________LOWER_R2__________________,
    _________________LOWER_L3__________________,                _________________LOWER_R3__________________,
    _________________LOWER_L4__________________, KC_TRNS, KC_TRNS, _________________LOWER_R4__________________,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

[_RAISE] = LAYOUT_lily_base_wrapper(
    _________________RAISE_L1__________________,                _________________RAISE_R1__________________,
    _________________RAISE_L2__________________,                _________________RAISE_R2__________________,
    _________________RAISE_L3__________________,                _________________RAISE_R3__________________,
    _________________RAISE_L4__________________, KC_TRNS, KC_TRNS, _________________RAISE_R4__________________,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

[_ADJUST] = LAYOUT_lily_base_wrapper(
    ________________NUMBER_LEFT________________,                    ________________NUMBER_RIGHT_______________,
    _________________ADJUST_L1_________________,                    _________________ADJUST_R1_________________,
    _________________ADJUST_L2_________________,                    _________________ADJUST_R2_________________,
    _________________ADJUST_L3_________________, KC_TRNS, TO(0),    _________________ADJUST_R3_________________,
                     _______, _______, _______,   _______, _______,      _______, _______, _______
)
};
  