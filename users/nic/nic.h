#pragma once

#include QMK_KEYBOARD_H
#include "wrappers.h"

/* Define layer names */
enum userspace_layers {
    _QWERTY  = 0,
    _RAISE,
    _LOWER,
    _ADJUST
};

enum userspace_custom_keycodes {
    VRSN = SAFE_RANGE,  // Prints QMK Firmware and board info
    KC_MAKE,            // Run keyboard's customized make command
    KC_RGB_T,           // Toggles RGB Layer Indication mode
    RGB_IDL,            // RGB Idling animations
    RGBRST,            // Reset RGB
    EPRM,               // Reset eeprom
    DBG_KEY,
    DBG_MX,
    NEW_SAFE_RANGE  // use "NEWPLACEHOLDER for keymap specific codes
};
#define LOWER TL_LOWR //MO(_LOWER)
#define RAISE TL_UPPR //MO(_RAISE)

/* OSM keycodes, to keep things clean and easy to change */
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_MEH OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)

#define MT_TAB MT(MOD_LCTL, KC_TAB)

#define ALT_APP ALT_T(KC_APP)

#define MG_NKRO MAGIC_TOGGLE_NKRO

#define UC_IRNY UC(0x2E2E)
#define UC_CLUE UC(0x203D)

// KWin Window Switching
#define KC_DT1 LCTL(KC_F1)
#define KC_DT2 LCTL(KC_F2)
#define KC_DT3 LCTL(KC_F3)
#define KC_DT4 LCTL(KC_F4)