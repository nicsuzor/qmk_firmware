/*
Copyright 2015-2017 Jack Humbert
Modified by Nicolas Suzor  @nicsuzor 31 July 2020

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include QMK_KEYBOARD_H
#include "rgblight.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

void encoder_update_user(uint8_t index, bool clockwise) {
    //if (index == 0) {
    switch(biton32(layer_state)) {
    case _QWERTY:
    if (clockwise) {
      tap_code(KC_RIGHT);
    } else {
      tap_code(KC_LEFT);
    }
    break;

    case _LOWER:
      if (clockwise) {
        tap_code(KC_DOWN);
      } else {
        tap_code(KC_UP);
      }
      break;
    case _RAISE:
      if (clockwise) {
        register_code16(KC_LCTRL);
        register_code16(KC_LALT);
        register_code16(KC_LGUI);
        tap_code(KC_RIGHT);
        unregister_code16(KC_LCTRL);
        unregister_code16(KC_LALT);
        unregister_code16(KC_LGUI);

      } else {
        register_code16(KC_LCTRL);
        register_code16(KC_LALT);
        register_code16(KC_LGUI);
        tap_code(KC_LEFT);
        unregister_code16(KC_LCTRL);
        unregister_code16(KC_LALT);
        unregister_code16(KC_LGUI);

      }
      break;
    case _ADJUST:
        if (clockwise) {
          tap_code(KC_RIGHT);
        } else {
          tap_code(KC_LEFT);
        }
        break;
    default: //  for any other layers, or the default layer
        if (clockwise) {
          tap_code(KC_RIGHT);
        } else {
          tap_code(KC_LEFT);
        }
        break;
    }
  }


void matrix_init_user(void) { // Runs boot tasks for keyboard
#ifdef BACKLIGHT_ENABLE
    backlight_enable();
    backlight_level(3);
#endif
#ifdef RGBLIGHT_ENABLE
    rgblight_enable(); // Enable RGB by default
    rgblight_sethsv(0, 255, 255);  // Set default HSV - red hue, full saturation, full brightness
#ifdef RGBLIGHT_ANIMATIONS
    rgblight_mode(0);
    //rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 2); // set to RGB_RAINBOW_SWIRL by default
#endif
#endif

    eeconfig_update_kb(0);
}

uint32_t layer_state_set_kb(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
    // change the color any time a layer switches
    // This function is called every time a layer switches, no matter how it switches
    switch (biton32(state)) {
      case _QWERTY:
          rgblight_sethsv(115, 255, 255);
          break;
      case _LOWER:
          rgblight_sethsv(213, 255, 255);
          break;
      case _RAISE:
          rgblight_sethsv(0, 255, 255);
          break;
      case _ADJUST:
          rgblight_sethsv(60, 255, 255);
          break;
      default: //  for any other layers, or the default layer
          rgblight_sethsv(240, 255, 255);
          break;
    }
#endif
   return state;  // this is required, DO NOT REMOVE
}
/*'layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _QWERTY:
            rgblight_sethsv(240, 255, 255);
            break;
        case _LOWER:
            rgblight_sethsv(213, 255, 255);
            break;
        case _RAISE:
            rgblight_sethsv(0, 255, 255);
            break;
        case _ADJUST:
            rgblight_sethsv(60, 255, 255);
            break;
        default: //  for any other layers, or the default layer
            rgblight_sethsv(240, 255, 255);
            break;
    }
  return state;
}*/
/*
// Tap Dance Declarations
enum {
    YOUR_TAPDANCE_1 = 0,
    YOUR_TAPDANCE_2,
    // ..., the rest of your tap dances
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // simple tap dance
    [YOUR_TAPDANCE_1] = ACTION_TAP_DANCE_DOUBLE(KC_XXXX, KC_YYYY), // replace with your keyco.des

    // complex tap dance function (to specify what happens when key is pressed 3+ times, for example). See https://docs.qmk.fm/tap_dance.html for how to define
    [YOUR_TAPDANCE_2] = ACTION_TAP_DANCE_FN(your_function_name),
};

 in your KEYMAP(), add :

TD(YOUR_TAPDANCE_1) */
