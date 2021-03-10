#include "nic.h"

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#include "rgb_matrix_user.h"
#include "rgb_matrix.h"
#endif

#include "lib/lib8tion/lib8tion.h"
#include QMK_KEYBOARD_H

userspace_config_t userspace_config;

__attribute__((weak)) void keyboard_pre_init_keymap(void) {}

void keyboard_pre_init_user(void) {
    userspace_config.raw = eeconfig_read_user();
#ifdef USE_INTERNAL_RESISTORS
    // In case of lag due to no resistors:
    setPinInputHigh(D0);
    setPinInputHigh(D1);
#endif

    keyboard_pre_init_keymap();
}

__attribute__((weak)) void matrix_init_keymap(void) {}

// Call user matrix init, set default RGB colors and then
// call the keymap's init function
void matrix_init_user(void) {
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    set_default_rgb();
#endif
    matrix_init_keymap();
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
    iota_gfx_init(!has_usb());   // turns on the display
#endif
}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

void keyboard_post_init_user(void) {
debug_enable=true;
#if defined(DEBUG_ENABLE)
    debug_enable=true;
    // Customise these values to desired behaviour
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
#endif

    keyboard_post_init_keymap();
}

__attribute__((weak)) void shutdown_keymap(void) {}


// On RESET, set all RGB to red, shutdown the keymap.
void shutdown_user(void) {
#if defined(RGB_MATRIX_ENABLE)
    rgb_matrix_shutdown();
#endif
    shutdown_keymap();
}


__attribute__((weak)) void suspend_power_down_keymap(void) {}

void suspend_power_down_user(void) {

    suspend_power_down_keymap();
}

__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}

void suspend_wakeup_init_user(void) {
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    set_default_rgb();
#endif
    suspend_wakeup_init_keymap();
}

__attribute__((weak)) void matrix_scan_keymap(void) {}

// No global matrix scan code, so just run keymap's matrix
// scan function
__attribute__((weak)) void matrix_scan_user(void) {
    static bool has_ran_yet;
    if (!has_ran_yet) {
        has_ran_yet = true;
        startup_user();
    }

#if defined(RGB_MATRIX_ENABLE)
    matrix_scan_rgb();
#endif  // RGB_MATRIX_ENABLE

    matrix_scan_keymap();
}

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
#if defined(RGB_MATRIX_ENABLE)
    uint8_t layer = get_highest_layer(state);
    rgb_matrix_by_layer(layer);
    dprintf("Set layer change RGB to: %u\n", layer);
#endif
    return layer_state_set_keymap(state);
}

__attribute__((weak)) layer_state_t default_layer_state_set_keymap(layer_state_t state) { return state; }

__attribute__((weak)) void led_set_keymap(uint8_t usb_led) {}

// Any custom LED code goes here.
void led_set_user(uint8_t usb_led) { led_set_keymap(usb_led); }



__attribute__((weak)) void eeconfig_init_kb(void) {
    eeconfig_init_user();
}

__attribute__((weak)) void eeconfig_init_keymap(void) {}

void eeconfig_init_user(void) {
    dprintf("Reseting EEPROM (user)");

    userspace_config.raw              = 0;
    userspace_config.rgb_layer_change = true;
#ifdef RGB_MATRIX_ENABLE
    set_default_rgb();
#endif
    eeconfig_update_user(userspace_config.raw);
    eeconfig_init_keymap();

}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    dprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);

    switch (keycode) {
        case VRSN:  // Prints firmware version
            if (record->event.pressed) {
                send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), TAP_CODE_DELAY);
            }
            break;
        case KC_MAKE:  // Compiles the firmware, and adds the flash command based on keyboard bootloader
            if (!record->event.pressed)
                send_string_with_delay_P(PSTR("make " QMK_KEYBOARD ":" QMK_KEYMAP), 10); // SS_TAP(X_ENTER)), 10);
            break;
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
#if defined(RGB_MATRIX_ENABLE)
        case RGBRST: // Reset RGB status
            dprint("Setting default RGB state");
            if (record->event.pressed) {
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
                set_default_rgb();
#endif
            }
            break;
        case RGB_MOD:
            if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
                rgblight_step();
#endif

#ifdef RGB_MATRIX_ENABLE
                rgb_matrix_step();
#endif
            }
            break;
#endif
        case KC_RGB_T:
            if (record->event.pressed) {
#ifdef RGB_MATRIX_ENABLE
                rgb_matrix_enable_noeeprom();
#endif
            }
            break;
#ifdef UNICODE_ENABLE
        case UC_FLIP:  // (ノಠ痊ಠ)ノ彡┻━┻
            if (record->event.pressed) {
                send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
            }
            break;
        case UC_TABL:  // ┬─┬ノ( º _ ºノ)
            if (record->event.pressed) {
                send_unicode_string("┬─┬ノ( º _ ºノ)");
            }
            break;
        case UC_SHRG:  // ¯\_(ツ)_/¯
            if (record->event.pressed) {
                send_unicode_string("¯\\_(ツ)_/¯");
            }
            break;
        case UC_DISA:  // ಠ_ಠ
            if (record->event.pressed) {
                send_unicode_string("ಠ_ಠ");
            }
            break;
#endif

    }
    return process_record_keymap(keycode, record);
}
