#include "nic.h"
#include "rgb_matrix.h"
#include "lib/lib8tion/lib8tion.h"

extern led_config_t g_led_config;

#if defined(SPLIT_KEYBOARD) || defined(KEYBOARD_crkbd)
#    define RGB_MATRIX_REST_MODE RGB_MATRIX_CYCLE_OUT_IN_DUAL
#else
#    define RGB_MATRIX_REST_MODE RGB_MATRIX_CYCLE_OUT_IN
#endif

void rgb_matrix_layer_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode, uint8_t speed, uint8_t led_type) {
    HSV hsv = {hue, sat, val};
    if (hsv.v > rgb_matrix_config.hsv.v) {
        hsv.v = rgb_matrix_config.hsv.v;
    }

    RGB rgb = hsv_to_rgb(hsv);
    for (uint8_t i = 0; i < DRIVER_LED_TOTAL; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], led_type)) {
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
}

void suspend_power_down_keymap(void) { }

void suspend_wakeup_init_keymap(void) { }

void check_default_layer(uint8_t mode, uint8_t type) {
/*    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            dprintf("setting layer to default: %u\n", _QWERTY);
            rgb_matrix_layer_helper(HSV_CYAN, mode, rgb_matrix_config.speed, type);
            break;
    }*/
}

void set_default_rgb(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_enable();
    dprint("Setting default RGB state.");
#endif
#if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS)
    dprintf("RGB Matrix setting mode: %u\n", RGB_MATRIX_TYPING_HEATMAP);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
#endif

}

void rgb_matrix_by_layer(int layer) {
    switch (layer) {
        case _RAISE:
            rgb_matrix_layer_helper(HSV_CORAL, RGB_MATRIX_SOLID_COLOR, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
            dprintf("rgblight layer change raise: %u\n", layer);
            break;
        case _LOWER:
            rgb_matrix_layer_helper(HSV_MAGENTA, RGB_MATRIX_SOLID_COLOR, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
            dprintf("rgblight layer change lower: %u\n", layer);
            break;
        case _ADJUST:
            rgb_matrix_layer_helper(HSV_GOLD, RGB_MATRIX_SOLID_COLOR, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
            dprintf("rgblight layer change adjust: %u\n", layer);
            break;
        default: {
            rgb_matrix_layer_helper(HSV_CYAN, RGB_MATRIX_SOLID_COLOR, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
            dprintf("rgblight layer change default: %u\n", layer);
            break;
        }
    }

}

bool process_record_user_rgb_matrix(uint16_t keycode, keyrecord_t *record) {
    return true;
}
void rgb_matrix_indicators_user(void) {

}

void keyboard_post_init_rgb(void) {
    /*if (userspace_config.rgb_matrix_idle_anim) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_REST_MODE);
    }*/
}

void matrix_scan_rgb(void) {
    /*if (userspace_config.rgb_matrix_idle_anim && rgb_matrix_get_mode() == RGB_MATRIX_TYPING_HEATMAP && timer_elapsed32(hypno_timer) > 15000) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_REST_MODE);
    }*/
}

