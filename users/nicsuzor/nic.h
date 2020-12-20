#pragma once

#include QMK_KEYBOARD_H
#include "version.h"
#include "eeprom.h"
#include "wrappers.h"

#if defined(TAP_DANCE_ENABLE)
#    include "tap_dances.h"
#endif  // TAP_DANCE_ENABLE

#if defined(RGB_MATRIX_ENABLE)
#   include "rgb_matrix_user.h"
#endif

#if defined(KEYBOARD_lily58_rev1) & defined(PROTOCOL_LUFA)
#    include "lufa.h"
#    include "split_util.h"
#endif

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
    KC_CCCV,            // Hold to copy, tap to paste
    UC_FLIP,            // (ಠ痊ಠ)┻━┻
    UC_TABL,            // ┬─┬ノ( º _ ºノ)
    UC_SHRG,            // ¯\_(ツ)_/¯
    UC_DISA,            // ಠ_ಠ
    KC_DT1,
    KC_DT2,
    KC_DT3,
    KC_DT4,
    NEW_SAFE_RANGE  // use "NEWPLACEHOLDER for keymap specific codes
};
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

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


void          matrix_init_keymap(void);
void          shutdown_keymap(void);
void          suspend_power_down_keymap(void);
void          suspend_wakeup_init_keymap(void);
void          matrix_scan_keymap(void);
layer_state_t layer_state_set_keymap(layer_state_t state);
layer_state_t default_layer_state_set_keymap(layer_state_t state);
void          led_set_keymap(uint8_t usb_led);
void          eeconfig_init_keymap(void);


// clang-format off
typedef union {
    uint32_t raw;
    struct {
        bool    rgb_layer_change     :1;
        bool    nuke_switch          :1;
        bool    rgb_matrix_idle_anim :1;
    };
} userspace_config_t;
// clang-format on

extern userspace_config_t userspace_config;
