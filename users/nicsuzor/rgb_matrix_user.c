#include "nic.h"

#if defined(RGB_MATRIX_ENABLE)
#    include "rgb_matrix.h"
extern led_config_t g_led_config;
#endif

#include "lib/lib8tion/lib8tion.h"




void rgb_matrix_layer_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t mode, uint8_t speed, uint8_t led_type) {


#ifdef RGBLIGHT_ENABLE
    rgblight_sethsv(hue, sat, val);
#endif
#ifdef RGB_MATRIX_ENABLE
    if (val > rgb_matrix_config.hsv.v) {
        val = rgb_matrix_config.hsv.v;
    }
    HSV hsv = {hue, sat, val};
    RGB rgb = hsv_to_rgb(hsv);
    if (led_type == -1) {
        rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
    } else {
        for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
            if ( HAS_FLAGS(g_led_config.flags[i], led_type)) {
                dprintf("rgblight layer change setting led: %u\n", i);
                if (HAS_FLAGS(g_led_config.flags[i], led_type)) {
                    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                }
            }
        }
    }
#endif
}

void suspend_power_down_keymap(void) {
#if defined(RGB_MATRIX_ENABLE)
    rgb_matrix_set_suspend_state(true);
#endif
}

void suspend_wakeup_init_keymap(void) {
#if defined(RGB_MATRIX_ENABLE)
    rgb_matrix_set_suspend_state(false);
#endif
}

void set_default_rgb(void) {
    dprint("Setting default RGB state, if applicable.");
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_mode_noeeprom(RGB_MATRIX_STARTUP_MODE);
    rgb_matrix_sethsv_noeeprom(HSV_CYAN);
#endif

#ifdef BACKLIGHT_ENABLE
    backlight_enable();
    backlight_level(3);
#endif
#ifdef RGBLIGHT_ENABLE
    rgblight_enable(); // Enable RGB by default
    rgblight_sethsv(0, 255, 70);  // Set default HSV - red hue, full saturation, full brightness
    #ifdef RGBLIGHT_ANIMATIONS
        rgblight_mode(0);
        //rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 2); // set to RGB_RAINBOW_SWIRL by default
    #endif
#endif
    eeconfig_update_kb(0);
}

void rgb_matrix_by_layer(int layer) {
#ifdef RGBLIGHT_ENABLE
    // change the color any time a layer switches
    // This function is called every time a layer switches, no matter how it switches

    switch (layer) {
        case _QWERTY:
            rgblight_sethsv(115, 255, 70);
            break;
        case _LOWER:
            rgblight_sethsv(213, 255, 70);
            break;
        case _RAISE:
            rgblight_sethsv(0, 255, 70);
            break;
        case _ADJUST:
            rgblight_sethsv(60, 255, 70);
            break;
        default: //  for any other layers, or the default layer
            rgblight_sethsv(240, 150, 70);
            break;
    }
#endif
#ifdef RGB_MATRIX_ENABLE
    switch (layer) {
        case _RAISE:
            rgb_matrix_layer_helper(HSV_CORAL, RGB_MATRIX_SOLID_COLOR, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
            dprintf("rgb matrix layer change raise: %u\n", layer);
            break;
        case _LOWER:
            rgb_matrix_layer_helper(HSV_MAGENTA, RGB_MATRIX_SOLID_COLOR, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
            dprintf("rgb matrix layer change lower: %u\n", layer);
            break;
        case _ADJUST:
            rgb_matrix_layer_helper(HSV_GOLD, RGB_MATRIX_SOLID_COLOR, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
            dprintf("rgb matrix layer change adjust: %u\n", layer);
            break;
        default: {
            rgb_matrix_layer_helper(HSV_CYAN, RGB_MATRIX_SOLID_COLOR, rgb_matrix_config.speed, LED_FLAG_UNDERGLOW);
            dprintf("rgb matrix layer change default: %u\n", layer);
            break;
        }
    }
#endif
}

bool process_record_user_rgb_matrix(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void rgb_matrix_shutdown(void) {
}

void keyboard_post_init_rgb(void) {

}

void matrix_scan_rgb(void) {

}

