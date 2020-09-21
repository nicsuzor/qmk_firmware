#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _GAMES 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  GAMES,
  ADJUST,
};


int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE
/*
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}*/

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

const char *read_mode_icon(bool swap);
const char *read_host_led_state(void);
void set_timelog(void);
const char *read_timelog(void);

void oled_task_user(void) {
  oled_write_P(PSTR("\n\n"), false);
  if (is_keyboard_master()) {
    //oled_write_ln_P(PSTR("Layer"), false);
    switch (biton32(layer_state)) {
       case _QWERTY:
           oled_write_ln_P(PSTR("Default"), false);
           break;
       case _LOWER:
           oled_write_ln_P(PSTR("SYMBOLS"), false);
           break;
       case _RAISE:
           oled_write_ln_P(PSTR("NUM FN"), false);
           break;
       case _GAMES:
           oled_write_ln_P(PSTR("GAMES"), false);
           break;
       case _ADJUST:
           oled_write_ln_P(PSTR("ADJUST"), false);
           break;
       default:
           // Or use the write_ln shortcut over adding '\n' to the end of your string
           oled_write_ln_P(PSTR("Undefined"), false);
     }

     //oled_write_ln_P(read_timelog(), false);

   } else {
     //oled_write_ln(read_timelog(), false);

        // If you want to change the display of OLED, you need to change here
    //oled_write_ln(read_layer_state(), false);
    oled_write_P(PSTR("\n\n"), false);

    oled_write_ln_P(read_keylog(), false);
    oled_write_ln_P(read_keylogs(), false);

    //oled_write_ln_P(read_keylog(), false);
    //oled_write_ln_P(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
//(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
    //oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
  }
  return true;
}
