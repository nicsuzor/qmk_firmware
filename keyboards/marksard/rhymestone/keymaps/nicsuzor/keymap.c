/* Copyright 2020 marksard
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

#include "./common/oled_helper.h"
#include <print.h>
#include QMK_KEYBOARD_H
#include <config.h>

enum layer_number {
  _BASE,
  _UPPER
};

enum custom_keycodes {
    BASE = SAFE_RANGE,
    UPPER,
    RGBRST
};

/*const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    UPPER, KC_7,    KC_8,    KC_9, KC_MINUS , \
    RGBRST, KC_4,    KC_5,    KC_6,  KC_PLUS ,         \
    KC_TAB, KC_1,    KC_2,    KC_3, KC_ENTER,         \
    KC_SPACE, KC_0, KC_DOT, KC_SLSH, KC_ASTR   \
  ),
[_GAME] = LAYOUT(
    BASE, KC_Q,    KC_W,    KC_E, KC_R, \
    KC_TAB, KC_A,    KC_S,    KC_D, KC_F,            \
    KC_LSHIFT, KC_Z,    KC_X,    KC_C, KC_V,         \
    KC_LCTL, KC_ESC, KC_GRV, KC_ENTER, KC_SPACE
  )
};*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_5x4(
    KC_ESC , KC_SLSH, KC_ASTR, KC_MINUS, \
    KC_7,    KC_8,    KC_9,     KC_PLUS, \
    KC_4,    KC_5,    KC_6,     KC_EQL, \
    KC_1,    KC_2,    KC_3,     KC_ENTER,         \
    KC_0,    KC_DOT,   KC_DEL, RGBRST     \
   ),
[_UPPER] = LAYOUT_5x4(
    KC_ESC , KC_SLSH, KC_ASTR, KC_MINUS, \
    KC_7,    KC_8,    KC_9, KC_PLUS, \
    KC_4,    KC_5,    KC_6,   KC_EQL, \
    KC_1,    KC_2,    KC_3, KC_ENTER,         \
    TO(_BASE), KC_0,    KC_DOT, RGBRST         \
   ),
};

