#include "nic.h"
#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

userspace_config_t userspace_config;

#define CURRY_UNICODE_MODE 1

void bootmagic_lite(void) {
    matrix_scan();
#if defined(DEBOUNCING_DELAY) && DEBOUNCING_DELAY > 0
    wait_ms(DEBOUNCING_DELAY * 2);
#elif defined(DEBOUNCE) && DEBOUNCE > 0
    wait_ms(DEBOUNCE * 2);
#else
    wait_ms(30);
#endif
    matrix_scan();
    if (matrix_get_row(BOOTMAGIC_LITE_ROW) & (1 << BOOTMAGIC_LITE_COLUMN)) {
        bootloader_jump();
    }
}

__attribute__((weak)) void keyboard_pre_init_keymap(void) {}

void keyboard_pre_init_user(void) {
    userspace_config.raw = eeconfig_read_user();
#ifdef USE_INTERNAL_RESISTORS
    // In case of log due to no resistors:
    setPinInputHigh(D0);
    setPinInputHigh(D1);
#endif

    keyboard_pre_init_keymap();
}

void rgb_matrix_update_pwm_buffers(void);

__attribute__((weak)) void matrix_init_keymap(void) {}

// Call user matrix init, set default RGB colors and then
// call the keymap's init function
void matrix_init_user(void) {
    eeconfig_update_rgb_matrix_default();
    rgb_matrix_set_color_all(0xFF, 0x00, 0x00);
    rgb_matrix_update_pwm_buffers();
    rgb_matrix_enable();
    rgb_matrix_enable_noeeprom();
    rgb_matrix_mode(RGB_MATRIX_BAND_SPIRAL_SAT);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_SPIRAL_SAT);
    matrix_init_keymap();
}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

void keyboard_post_init_user(void) {
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
    keyboard_post_init_rgb();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_SPIRAL_SAT);
    rgb_matrix_enable();
#endif
    keyboard_post_init_keymap();
}

__attribute__((weak)) void shutdown_keymap(void) {}


// On RESET, set all RGB to red, shutdown the keymap.
void shutdown_user(void) {
#if defined(RGBLIGHT_ENABLE)
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(1);
    rgblight_setrgb_red();
#endif

#if defined(RGB_MATRIX_ENABLE)
    rgb_matrix_set_color_all(0xFF, 0x00, 0x00);
    rgb_matrix_update_pwm_buffers();
#endif
    shutdown_keymap();
}

__attribute__((weak)) void suspend_power_down_keymap(void) {}

void suspend_power_down_user(void) {
#if defined(RGB_MATRIX_ENABLE)
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_keymap();
#endif
}

__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}

void suspend_wakeup_init_user(void) {
#if defined(RGB_MATRIX_ENABLE)
    rgb_matrix_set_suspend_state(false);
    rgb_matrix_set_color_all(0xFF, 0x00, 0x00);
    rgb_matrix_update_pwm_buffers();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_SPIRAL_SAT);
    rgb_matrix_enable();
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
#endif  // RGBLIGHT_ENABLE

    matrix_scan_keymap();
}

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
#if defined(RGBLIGHT_ENABLE)
    state = layer_state_set_rgb(state);
#endif  // RGBLIGHT_ENABLE
#if defined(RGB_MATRIX_ENABLE)
    uint8_t layer = get_highest_layer(state);
    rgb_matrix_by_layer(layer);
#endif
    return layer_state_set_keymap(state);
}

__attribute__((weak)) layer_state_t default_layer_state_set_keymap(layer_state_t state) { return state; }

__attribute__((weak)) void led_set_keymap(uint8_t usb_led) {}

// Any custom LED code goes here.
void led_set_user(uint8_t usb_led) { led_set_keymap(usb_led); }

__attribute__((weak)) void eeconfig_init_keymap(void) {}

void eeconfig_init_user(void) {
    userspace_config.raw              = 0;
    userspace_config.rgb_layer_change = true;
    eeconfig_update_user(userspace_config.raw);
    eeconfig_init_keymap();
    keyboard_init();
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef DEBUG
#endif
    xprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);

    switch (keycode) {
        case VRSN:  // Prints firmware version
            if (record->event.pressed) {
                send_string_with_delay_P(PSTR(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE), TAP_CODE_DELAY);
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
        case KC_RGB_T:  // This allows me to use underglow as layer indication, or as normal
#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
            if (record->event.pressed) {
                userspace_config.rgb_layer_change ^= 1;
                dprintf("rgblight layer change [EEPROM]: %u\n", userspace_config.rgb_layer_change);
                eeconfig_update_user(userspace_config.raw);
                if (userspace_config.rgb_layer_change) {
#    if defined(RGBLIGHT_ENABLE) && defined(RGB_MATRIX_ENABLE)
                    rgblight_enable_noeeprom();
#    endif
                    layer_state_set(layer_state);  // This is needed to immediately set the layer color (looks better)
#    if defined(RGBLIGHT_ENABLE) && defined(RGB_MATRIX_ENABLE)
                } else {
                    rgblight_disable_noeeprom();
#    endif
                }
            }
#endif  // RGBLIGHT_ENABLE
            break;

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
            case RGB_TOG:
            // Split keyboards need to trigger on key-up for edge-case issue
#    ifndef SPLIT_KEYBOARD
            if (record->event.pressed) {
#    else
            if (!record->event.pressed) {
#    endif
#    if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                rgblight_toggle();
#    endif
#    if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                rgb_matrix_toggle();
#    endif
            }
            return false;
            break;
        case RGB_MODE_FORWARD ... RGB_MODE_GRADIENT:  // quantum_keycodes.h L400 for definitions
            if (record->event.pressed) {
                bool is_eeprom_updated;
#    if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                // This disables layer indication, as it's assumed that if you're changing this ... you want that disabled
                if (userspace_config.rgb_layer_change) {
                    userspace_config.rgb_layer_change = false;
                    dprintf("rgblight layer change [EEPROM]: %u\n", userspace_config.rgb_layer_change);
                    is_eeprom_updated = true;
                }
#    endif
#    if defined(RGB_MATRIX_ENABLE) && defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)
                if (userspace_config.rgb_matrix_idle_anim) {
                    userspace_config.rgb_matrix_idle_anim = false;
                    dprintf("RGB Matrix Idle Animation [EEPROM]: %u\n", userspace_config.rgb_matrix_idle_anim);
                    is_eeprom_updated = true;
                }
#    endif
                if (is_eeprom_updated) {
                    eeconfig_update_user(userspace_config.raw);
                }
            }
#endif

    }
    return process_record_keymap(keycode, record) &&
           #if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
           process_record_user_rgb(keycode, record);
           #endif  // RGBLIGHT_ENABLE
}
