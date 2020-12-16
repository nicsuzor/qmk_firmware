#pragma once

// Use custom magic number so that when switching branches, EEPROM always gets reset
#define EECONFIG_MAGIC_NUMBER (uint16_t)0x237

#ifdef SSD1306OLED
#undef SSD1306OLED
#endif

/* Set Polling rate to 1000Hz */
#define USB_POLLING_INTERVAL_MS 1

#if defined(RGB_MATRIX_ENABLE)
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_DISABLE_WHEN_USB_SUSPENDED true

#   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#   define RGB_MATRIX_HUE_STEP 8
#   define RGB_MATRIX_SAT_STEP 8
#   define RGB_MATRIX_VAL_STEP 8
#   define RGB_MATRIX_SPD_STEP 10

#    define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_TYPING_HEATMAP

#    define DISABLE_RGB_MATRIX_ALPHAS_MODS
#    define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
//#    define DISABLE_RGB_MATRIX_BREATHING
#    define DISABLE_RGB_MATRIX_BAND_SAT
#    define DISABLE_RGB_MATRIX_BAND_VAL
#    define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    define DISABLE_RGB_MATRIX_CYCLE_ALL
#    define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
//#    define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
#       define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define DISABLE_RGB_MATRIX_DUAL_BEACON
#    define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define DISABLE_RGB_MATRIX_RAINBOW_BEACON
#    define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define DISABLE_RGB_MATRIX_RAINDROPS
#    define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
//       define DISABLE_RGB_MATRIX_TYPING_HEATMAP
#    define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
//#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define DISABLE_RGB_MATRIX_SPLASH
#    define DISABLE_RGB_MATRIX_MULTISPLASH
#    define DISABLE_RGB_MATRIX_SOLID_SPLASH
#    define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif  // RGB_MATRIX_ENABLE

#if !defined(ONESHOT_TAP_TOGGLE)
#    define ONESHOT_TAP_TOGGLE 2
#endif  // !ONESHOT_TAP_TOGGLE

#if !defined(ONESHOT_TIMEOUT)
#    define ONESHOT_TIMEOUT 3000
#endif  // !ONESHOT_TIMEOUT

#if !defined(QMK_KEYS_PER_SCAN)
#    define QMK_KEYS_PER_SCAN 4
#endif  // !QMK_KEYS_PER_SCAN

#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD

#define FORCE_NKRO

#if !defined(TAPPING_TOGGLE)
#    define TAPPING_TOGGLE 1
#endif

#if defined(TAPPING_TERM)
#    undef TAPPING_TERM
#endif  // TAPPING_TERM

// Keyboard specific customisations
#if defined(KEYBOARD_lily58_rev1)
#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 160
#elif defined(KEYBOARD_crkbd)
#    define TAPPING_TERM 150
#elif defined(KEYBOARD_planck_ez)
#    undef AUTO_SHIFT_ENABLE
#    undef RGB_MATRIX_ENABLE
#else
#    define TAPPING_TERM 175
#endif


#if defined(AUTO_SHIFT_ENABLE)
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_NO_AUTO_REPEAT
#define AUTO_SHIFT_MODIFIERS
#endif

#define TAP_CODE_DELAY 5

#define LEADER_TIMEOUT 250
#define LEADER_PER_KEY_TIMING

/* Disable unused and unneeded features to reduce on firmware size */
#if defined(LOCKING_SUPPORT_ENABLE)
#    undef LOCKING_SUPPORT_ENABLE
#endif

#if defined(LOCKING_RESYNC_ENABLE)
#    undef LOCKING_RESYNC_ENABLE
#endif

#if defined(OLED_FONT_H)
#    undef OLED_FONT_H
#endif

#define OLED_FONT_H "users/nic/glcdfont.c"
