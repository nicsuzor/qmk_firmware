/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"
#include "nic.h"

#define LAYOUT_grid_wrapper(...)       LAYOUT_ortho_5x12(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_grid_wrapper(
________________NUMBER_LEFT________________,                ________________NUMBER_RIGHT_______________,
_________________QWERTY_L1_________________,                _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________,                _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________,                _________________QWERTY_R3_________________,
_______________GRID_BOTTOM_ROW_____________
    ),

    [_LOWER] = LAYOUT_grid_wrapper(
    ________________NUMBER_LEFT________________,                ________________NUMBER_RIGHT_______________,
        _________________LOWER_L2__________________,                _________________LOWER_R2__________________,
        _________________LOWER_L3__________________,                _________________LOWER_R3__________________,
        _________________LOWER_L4__________________,                _________________LOWER_R4__________________,
    _______________GRID_BOTTOM_ROW_____________
    ),

    [_RAISE] = LAYOUT_grid_wrapper(
    ________________NUMBER_LEFT________________,                ________________NUMBER_RIGHT_______________,
        _________________RAISE_L1__________________,                _________________RAISE_R1__________________,
        _________________RAISE_L2__________________,                _________________RAISE_R2__________________,
        _________________RAISE_L3__________________,                _________________RAISE_R3__________________,
    _______________GRID_BOTTOM_ROW_____________
    ),

    [_ADJUST] = LAYOUT_grid_wrapper(
    ________________NUMBER_LEFT________________,                ________________NUMBER_RIGHT_______________,
        _________________ADJUST_L1_________________,                    _________________ADJUST_R1_________________,
        _________________ADJUST_L2_________________,                    _________________ADJUST_R2_________________,
        _________________ADJUST_L3_________________,                    _________________ADJUST_R3_________________,
    _______________GRID_BOTTOM_ROW_____________
    )
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case KC_RGB_T:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
#ifdef RGBLIGHT_ENABLE
              rgblight_step();
#endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};



uint32_t layer_state_set_kb(uint32_t state) {

    return state;  // this is required, DO NOT REMOVE
}