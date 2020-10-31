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

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  GAMES,
  ADJUST,
};

const uint16_t nic_layout[] = {5, 6, 7, 8};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LCTL, TO(1), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LGUI, KC_LALT, KC_NO, LT(1,KC_SPC), LT(2,KC_BSPC), LCTL_T(KC_DEL), KC_NO, KC_NO),
[1] = LAYOUT(OSL(4), KC_NO, KC_NO, LCTL(KC_PGUP), LCTL(KC_PGDN), KC_NO, KC_CIRC, KC_AMPR, KC_ASTR, KC_AT, KC_HASH, KC_BSPC, KC_TAB, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_BSPC, KC_UNDS, KC_LBRC, KC_RBRC, KC_PIPE, KC_GRV, KC_DEL, KC_ESC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_ENT, KC_MINS, KC_LPRN, KC_RPRN, KC_SCLN, KC_EQL, KC_ENT, KC_LSFT, KC_NO, KC_LCTL, KC_NO, KC_NO, KC_DEL, KC_NO, TO(2), KC_PPLS, KC_LCBR, KC_RCBR, KC_COLN, KC_BSLS, TO(0), TO(3), KC_LALT, KC_LCTL, KC_SPC, KC_TRNS, KC_TRNS, KC_NO, KC_NO),
[2] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_PEQL, KC_4, KC_5, KC_6, KC_PAST, KC_ENT, KC_TRNS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_PMNS, KC_1, KC_2, KC_3, KC_PSLS, KC_LSFT, KC_LSFT, KC_F11, KC_F12, KC_NO, KC_NO, KC_TRNS, KC_NO, TO(3), KC_PPLS, KC_P0, KC_P0, KC_PDOT, KC_COLN, TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
[3] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS, TO(4), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TO(0), KC_NO, KC_LSFT, KC_SPC, KC_LALT, LT(1,KC_DEL), LT(2,KC_BSPC), KC_NO, KC_NO),
[4] = LAYOUT(TO(3), KC_PSCR, KC_NO, LCTL(LSFT(KC_ESC)), LALT(KC_F4), LCTL(LSFT(KC_ESC)), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, TO(0), LCA(KC_DEL), RGB_SPD, RGB_VAD, RGB_VAI, RGB_SPI, TO(0), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, KC_NO, KC_NO)
};

#define LAYOUT( \
	L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05,  \
	L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15,  \
	L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25,  \
	L30, L31, L32, L33, L34, L35, L45, R40, R30, R31, R32, R33, R34, R35, \
	               L41, L42, L43, L44, R41, R42, R43, R44  \
	) \
	{ \
		{ L00, L01, L02, L03, L04, L05 }, \
		{ L10, L11, L12, L13, L14, L15 }, \
		{ L20, L21, L22, L23, L24, L25 }, \
		{ L30, L31, L32, L33, L34, L35 }, \
		{ KC_NO, L41, L42, L43, L44, L45 }, \
		{ R05, R04, R03, R02, R01, R00 }, \
		{ R15, R14, R13, R12, R11, R10 }, \
		{ R25, R24, R23, R22, R21, R20 }, \
		{ R35, R34, R33, R32, R31, R30 }, \
		{ KC_NO, R44, R43, R42, R41, R40 } \
	}

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

static void render_logo(int layer) {
  // 'adjust', 64x16px
  static const char PROGMEM myBitmap[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0xc0, 0x00, 0x1f, 0x00, 0x1f, 0xc0, 0x03, 0xf0, 0x7f, 0xff, 0x80, 0x3f, 0x00, 0x00,
    0x00, 0x7f, 0xf8, 0x00, 0x1f, 0x00, 0x1f, 0xc0, 0x03, 0xf0, 0x7f, 0xff, 0x81, 0xff, 0xc0, 0x00,
    0x00, 0xff, 0xfc, 0x00, 0x3f, 0x80, 0x1f, 0xc0, 0x07, 0xf0, 0x7f, 0xff, 0x83, 0xff, 0xf0, 0x00,
    0x01, 0xff, 0xfe, 0x00, 0x3f, 0x80, 0x1f, 0xe0, 0x07, 0xf0, 0x7f, 0xff, 0x87, 0xff, 0xf0, 0x00,
    0x03, 0xf0, 0x3e, 0x00, 0x3f, 0x80, 0x1f, 0xe0, 0x07, 0xf0, 0x7c, 0x00, 0x0f, 0xc1, 0xf8, 0x00,
    0x03, 0xe0, 0x1f, 0x00, 0x7f, 0xc0, 0x1f, 0xe0, 0x0f, 0xf0, 0x7c, 0x00, 0x0f, 0x80, 0xf8, 0x00,
    0x07, 0xc0, 0x1f, 0x00, 0x7f, 0xc0, 0x1f, 0xf0, 0x0f, 0xf0, 0x7c, 0x00, 0x0f, 0x80, 0x78, 0x00,
    0x07, 0xc0, 0x00, 0x00, 0xfb, 0xc0, 0x1f, 0xf0, 0x0e, 0xf0, 0x7c, 0x00, 0x0f, 0x80, 0x00, 0x00,
    0x07, 0xc0, 0x00, 0x00, 0xf3, 0xe0, 0x1f, 0x78, 0x1e, 0xf0, 0x7c, 0x00, 0x0f, 0xc0, 0x00, 0x00,
    0x07, 0xc0, 0x00, 0x00, 0xf1, 0xe0, 0x1f, 0x78, 0x1e, 0xf0, 0x7c, 0x00, 0x07, 0xf0, 0x00, 0x00,
    0x07, 0x80, 0x00, 0x01, 0xf1, 0xf0, 0x1f, 0x78, 0x3c, 0xf0, 0x7f, 0xff, 0x03, 0xfe, 0x00, 0x00,
    0x07, 0x81, 0xff, 0x01, 0xe1, 0xf0, 0x1f, 0x3c, 0x3c, 0xf0, 0x7f, 0xff, 0x01, 0xff, 0xc0, 0x00,
    0x07, 0x81, 0xff, 0x01, 0xe0, 0xf0, 0x1f, 0x3c, 0x3c, 0xf0, 0x7f, 0xff, 0x00, 0x7f, 0xe0, 0x00,
    0x07, 0x81, 0xff, 0x03, 0xe0, 0xf8, 0x1f, 0x3c, 0x78, 0xf0, 0x7f, 0xff, 0x00, 0x1f, 0xf0, 0x00,
    0x07, 0xc1, 0xff, 0x03, 0xc0, 0xf8, 0x1f, 0x1e, 0x78, 0xf0, 0x7c, 0x00, 0x00, 0x03, 0xf8, 0x00,
    0x07, 0xc0, 0x1f, 0x07, 0xff, 0xf8, 0x1f, 0x1e, 0x78, 0xf0, 0x7c, 0x00, 0x00, 0x00, 0xf8, 0x00,
    0x07, 0xc0, 0x1f, 0x07, 0xff, 0xfc, 0x1f, 0x0e, 0xf0, 0xf0, 0x7c, 0x00, 0x00, 0x00, 0x78, 0x00,
    0x07, 0xc0, 0x1f, 0x07, 0xff, 0xfc, 0x1f, 0x0f, 0xf0, 0xf0, 0x7c, 0x00, 0x1f, 0x00, 0x7c, 0x00,
    0x03, 0xe0, 0x1f, 0x0f, 0xff, 0xfe, 0x1f, 0x0f, 0xe0, 0xf0, 0x7c, 0x00, 0x0f, 0x80, 0x78, 0x00,
    0x03, 0xf0, 0x1f, 0x0f, 0x80, 0x3e, 0x1f, 0x07, 0xe0, 0xf0, 0x7c, 0x00, 0x0f, 0xc0, 0xf8, 0x00,
    0x01, 0xff, 0xff, 0x0f, 0x00, 0x3e, 0x1f, 0x07, 0xe0, 0xf0, 0x7f, 0xff, 0x87, 0xff, 0xf8, 0x00,
    0x00, 0xff, 0xfe, 0x1f, 0x00, 0x1f, 0x1f, 0x07, 0xc0, 0xf0, 0x7f, 0xff, 0x83, 0xff, 0xf0, 0x00,
    0x00, 0x7f, 0xfc, 0x1f, 0x00, 0x1f, 0x1f, 0x03, 0xc0, 0xf0, 0x7f, 0xff, 0x81, 0xff, 0xe0, 0x00,
    0x00, 0x0f, 0xc0, 0x3e, 0x00, 0x1f, 0x1f, 0x03, 0xc0, 0xf0, 0x7f, 0xff, 0x80, 0x3f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

  oled_write(myBitmap, false);
/*    static const char PROGMEM layer_images[5 ][512] = {
      {
        // 'qwerty', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xf8, 0x01, 0xf0, 0x1e, 0x03, 0xe3, 0xff, 0xfc, 0x7f, 0xf8, 0x07, 0xff, 0xff, 0x7e, 0x00,
    0x07, 0xff, 0x01, 0xf0, 0x1e, 0x03, 0xe3, 0xff, 0xfc, 0x7f, 0xff, 0x07, 0xff, 0xff, 0x3e, 0x00,
    0x0f, 0xff, 0x81, 0xf0, 0x3e, 0x03, 0xe3, 0xff, 0xfc, 0x7f, 0xff, 0x87, 0xff, 0xff, 0x1e, 0x00,
    0x1f, 0xff, 0xc1, 0xf0, 0x3f, 0x03, 0xc3, 0xff, 0xfc, 0x7f, 0xff, 0xc7, 0xff, 0xff, 0x1f, 0x01,
    0x3f, 0x07, 0xe0, 0xf0, 0x3f, 0x03, 0xc3, 0xe0, 0x00, 0x7c, 0x07, 0xc0, 0x0f, 0x80, 0x0f, 0x01,
    0x3e, 0x03, 0xf0, 0xf0, 0x3f, 0x07, 0xc3, 0xe0, 0x00, 0x7c, 0x03, 0xe0, 0x0f, 0x80, 0x0f, 0x83,
    0x7c, 0x01, 0xf0, 0xf8, 0x7f, 0x07, 0xc3, 0xe0, 0x00, 0x7c, 0x03, 0xe0, 0x0f, 0x80, 0x07, 0x83,
    0x7c, 0x00, 0xf0, 0xf8, 0x7f, 0x87, 0x83, 0xe0, 0x00, 0x7c, 0x03, 0xe0, 0x0f, 0x80, 0x07, 0xc7,
    0x7c, 0x00, 0xf8, 0x78, 0x7f, 0x87, 0x83, 0xe0, 0x00, 0x7c, 0x03, 0xe0, 0x0f, 0x80, 0x03, 0xc7,
    0x78, 0x00, 0xf8, 0x78, 0x77, 0x87, 0x83, 0xe0, 0x00, 0x7c, 0x03, 0xe0, 0x0f, 0x80, 0x03, 0xef,
    0x78, 0x00, 0xf8, 0x78, 0xf3, 0x8f, 0x83, 0xff, 0xf8, 0x7c, 0x07, 0xc0, 0x0f, 0x80, 0x01, 0xff,
    0x78, 0x00, 0xf8, 0x7c, 0xf3, 0xcf, 0x83, 0xff, 0xf8, 0x7f, 0xff, 0xc0, 0x0f, 0x80, 0x01, 0xff,
    0x78, 0x00, 0xf8, 0x3c, 0xf3, 0xcf, 0x03, 0xff, 0xf8, 0x7f, 0xff, 0x80, 0x0f, 0x80, 0x00, 0xfe,
    0x78, 0x00, 0xf8, 0x3c, 0xe3, 0xcf, 0x03, 0xff, 0xf8, 0x7f, 0xfe, 0x00, 0x0f, 0x80, 0x00, 0xfe,
    0x78, 0x00, 0xf8, 0x3c, 0xe1, 0xcf, 0x03, 0xe0, 0x00, 0x7f, 0xfe, 0x00, 0x0f, 0x80, 0x00, 0x7c,
    0x7c, 0x00, 0xf8, 0x3d, 0xe1, 0xdf, 0x03, 0xe0, 0x00, 0x7c, 0x1e, 0x00, 0x0f, 0x80, 0x00, 0x7c,
    0x7c, 0x00, 0xf0, 0x3f, 0xe1, 0xfe, 0x03, 0xe0, 0x00, 0x7c, 0x1f, 0x00, 0x0f, 0x80, 0x00, 0x7c,
    0x7c, 0x01, 0xf0, 0x1f, 0xc1, 0xfe, 0x03, 0xe0, 0x00, 0x7c, 0x0f, 0x80, 0x0f, 0x80, 0x00, 0x7c,
    0x3e, 0x03, 0xf0, 0x1f, 0xc0, 0xfe, 0x03, 0xe0, 0x00, 0x7c, 0x0f, 0x80, 0x0f, 0x80, 0x00, 0x7c,
    0x3f, 0x07, 0xe0, 0x1f, 0xc0, 0xfe, 0x03, 0xe0, 0x00, 0x7c, 0x07, 0xc0, 0x0f, 0x80, 0x00, 0x7c,
    0x1f, 0xff, 0xc0, 0x1f, 0xc0, 0xfc, 0x03, 0xff, 0xfc, 0x7c, 0x07, 0xc0, 0x0f, 0x80, 0x00, 0x7c,
    0x0f, 0xff, 0x80, 0x0f, 0x80, 0xfc, 0x03, 0xff, 0xfc, 0x7c, 0x03, 0xe0, 0x0f, 0x80, 0x00, 0x7c,
    0x07, 0xff, 0x80, 0x0f, 0x80, 0x7c, 0x03, 0xff, 0xfc, 0x7c, 0x03, 0xe0, 0x0f, 0x80, 0x00, 0x7c,
    0x00, 0xff, 0xe0, 0x0f, 0x80, 0x7c, 0x03, 0xff, 0xfc, 0x7c, 0x01, 0xf0, 0x0f, 0x80, 0x00, 0x7c,
    0x00, 0x07, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    },

    {

    // 'symbol', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0xe0, 0x3f, 0x00, 0x7e, 0x7f, 0x00, 0x0f, 0xc1, 0xff, 0xe0, 0x00, 0x0f, 0x80, 0x0f, 0x80,
    0x3f, 0xf8, 0x1f, 0x00, 0x7c, 0x7f, 0x00, 0x0f, 0xc1, 0xff, 0xfc, 0x00, 0x7f, 0xf0, 0x0f, 0x80,
    0x7f, 0xfe, 0x0f, 0x00, 0x78, 0x7f, 0x00, 0x1f, 0xc1, 0xff, 0xfe, 0x00, 0xff, 0xf8, 0x0f, 0x80,
    0xff, 0xfe, 0x0f, 0x80, 0xf8, 0x7f, 0x80, 0x1f, 0xc1, 0xff, 0xff, 0x01, 0xff, 0xfc, 0x0f, 0x80,
    0xf8, 0x3f, 0x07, 0x80, 0xf0, 0x7f, 0x80, 0x1f, 0xc1, 0xf0, 0x1f, 0x03, 0xf0, 0x7e, 0x0f, 0x80,
    0xf0, 0x1f, 0x07, 0xc1, 0xf0, 0x7f, 0x80, 0x3f, 0xc1, 0xf0, 0x1f, 0x03, 0xe0, 0x3f, 0x0f, 0x80,
    0xf0, 0x0f, 0x03, 0xc1, 0xe0, 0x7f, 0xc0, 0x3f, 0xc1, 0xf0, 0x0f, 0x07, 0xc0, 0x1f, 0x0f, 0x80,
    0xf0, 0x00, 0x03, 0xe3, 0xe0, 0x7f, 0xc0, 0x3b, 0xc1, 0xf0, 0x0f, 0x07, 0xc0, 0x0f, 0x0f, 0x80,
    0xf8, 0x00, 0x01, 0xe3, 0xc0, 0x7d, 0xe0, 0x7b, 0xc1, 0xf0, 0x1f, 0x07, 0xc0, 0x0f, 0x8f, 0x80,
    0xfe, 0x00, 0x01, 0xf7, 0xc0, 0x7d, 0xe0, 0x7b, 0xc1, 0xf0, 0x3f, 0x07, 0x80, 0x0f, 0x8f, 0x80,
    0x7f, 0xc0, 0x00, 0xff, 0x80, 0x7d, 0xe0, 0xf3, 0xc1, 0xff, 0xfe, 0x07, 0x80, 0x0f, 0x8f, 0x80,
    0x3f, 0xf8, 0x00, 0xff, 0x80, 0x7c, 0xf0, 0xf3, 0xc1, 0xff, 0xfc, 0x07, 0x80, 0x0f, 0x8f, 0x80,
    0x0f, 0xfc, 0x00, 0x7f, 0x00, 0x7c, 0xf0, 0xf3, 0xc1, 0xff, 0xfc, 0x07, 0x80, 0x0f, 0x8f, 0x80,
    0x03, 0xfe, 0x00, 0x7f, 0x00, 0x7c, 0xf1, 0xe3, 0xc1, 0xff, 0xff, 0x07, 0x80, 0x0f, 0x8f, 0x80,
    0x00, 0x7f, 0x00, 0x3e, 0x00, 0x7c, 0x79, 0xe3, 0xc1, 0xf0, 0x1f, 0x07, 0x80, 0x0f, 0x8f, 0x80,
    0x00, 0x1f, 0x00, 0x3e, 0x00, 0x7c, 0x79, 0xe3, 0xc1, 0xf0, 0x0f, 0x87, 0xc0, 0x0f, 0x8f, 0x80,
    0x00, 0x0f, 0x00, 0x3e, 0x00, 0x7c, 0x3b, 0xc3, 0xc1, 0xf0, 0x0f, 0x87, 0xc0, 0x0f, 0x0f, 0x80,
    0xe0, 0x0f, 0x80, 0x3e, 0x00, 0x7c, 0x3f, 0xc3, 0xc1, 0xf0, 0x0f, 0x87, 0xc0, 0x1f, 0x0f, 0x80,
    0xf0, 0x0f, 0x00, 0x3e, 0x00, 0x7c, 0x3f, 0x83, 0xc1, 0xf0, 0x0f, 0x83, 0xe0, 0x3f, 0x0f, 0x80,
    0xf8, 0x1f, 0x00, 0x3e, 0x00, 0x7c, 0x1f, 0x83, 0xc1, 0xf0, 0x1f, 0x83, 0xf0, 0x7e, 0x0f, 0x80,
    0xff, 0xff, 0x00, 0x3e, 0x00, 0x7c, 0x1f, 0x83, 0xc1, 0xff, 0xff, 0x01, 0xff, 0xfc, 0x0f, 0xff,
    0x7f, 0xfe, 0x00, 0x3e, 0x00, 0x7c, 0x1f, 0x03, 0xc1, 0xff, 0xfe, 0x00, 0xff, 0xf8, 0x0f, 0xff,
    0x3f, 0xfc, 0x00, 0x3e, 0x00, 0x7c, 0x0f, 0x03, 0xc1, 0xff, 0xfc, 0x00, 0x7f, 0xf0, 0x0f, 0xff,
    0x07, 0xe0, 0x00, 0x3e, 0x00, 0x7c, 0x0f, 0x03, 0xc1, 0xff, 0xe0, 0x00, 0x0f, 0x80, 0x0f, 0xff,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    },

    {

    // 'numfn', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x7c, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0xfe, 0x00, 0x1f, 0x80, 0x03, 0xff, 0xfc, 0xf8, 0x01, 0xf0,
    0x7e, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0xfe, 0x00, 0x1f, 0x80, 0x03, 0xff, 0xfc, 0xfc, 0x01, 0xf0,
    0x7f, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0xfe, 0x00, 0x3f, 0x80, 0x03, 0xff, 0xfc, 0xfe, 0x01, 0xf0,
    0x7f, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0xff, 0x00, 0x3f, 0x80, 0x03, 0xff, 0xfc, 0xfe, 0x01, 0xf0,
    0x7f, 0x80, 0xf8, 0x7c, 0x01, 0xe0, 0xff, 0x00, 0x3f, 0x80, 0x03, 0xe0, 0x00, 0xff, 0x01, 0xf0,
    0x7f, 0x80, 0xf8, 0x7c, 0x01, 0xe0, 0xff, 0x00, 0x7f, 0x80, 0x03, 0xe0, 0x00, 0xff, 0x01, 0xf0,
    0x7f, 0xc0, 0xf8, 0x7c, 0x01, 0xe0, 0xff, 0x80, 0x7f, 0x80, 0x03, 0xe0, 0x00, 0xff, 0x81, 0xf0,
    0x7f, 0xe0, 0xf8, 0x7c, 0x01, 0xe0, 0xff, 0x80, 0x77, 0x80, 0x03, 0xe0, 0x00, 0xff, 0xc1, 0xf0,
    0x7f, 0xe0, 0xf8, 0x7c, 0x01, 0xe0, 0xfb, 0xc0, 0xf7, 0x80, 0x03, 0xe0, 0x00, 0xff, 0xc1, 0xf0,
    0x7d, 0xf0, 0xf8, 0x7c, 0x01, 0xe0, 0xfb, 0xc0, 0xf7, 0x80, 0x03, 0xe0, 0x00, 0xfb, 0xe1, 0xf0,
    0x7c, 0xf0, 0xf8, 0x7c, 0x01, 0xe0, 0xfb, 0xc1, 0xe7, 0x80, 0x03, 0xff, 0xf8, 0xf9, 0xe1, 0xf0,
    0x7c, 0xf8, 0xf8, 0x7c, 0x01, 0xe0, 0xf9, 0xe1, 0xe7, 0x80, 0x03, 0xff, 0xf8, 0xf9, 0xf1, 0xf0,
    0x7c, 0x7c, 0xf8, 0x7c, 0x01, 0xe0, 0xf9, 0xe1, 0xe7, 0x80, 0x03, 0xff, 0xf8, 0xf8, 0xf9, 0xf0,
    0x7c, 0x3c, 0xf8, 0x7c, 0x01, 0xe0, 0xf9, 0xe3, 0xc7, 0x80, 0x03, 0xff, 0xf8, 0xf8, 0x79, 0xf0,
    0x7c, 0x3e, 0xf8, 0x7c, 0x01, 0xe0, 0xf8, 0xf3, 0xc7, 0x80, 0x03, 0xe0, 0x00, 0xf8, 0x7d, 0xf0,
    0x7c, 0x1f, 0xf8, 0x7c, 0x01, 0xe0, 0xf8, 0xf3, 0xc7, 0x80, 0x03, 0xe0, 0x00, 0xf8, 0x3f, 0xf0,
    0x7c, 0x1f, 0xf8, 0x7c, 0x01, 0xe0, 0xf8, 0x77, 0x87, 0x80, 0x03, 0xe0, 0x00, 0xf8, 0x3f, 0xf0,
    0x7c, 0x0f, 0xf8, 0x7c, 0x03, 0xe0, 0xf8, 0x7f, 0x87, 0x80, 0x03, 0xe0, 0x00, 0xf8, 0x1f, 0xf0,
    0x7c, 0x07, 0xf8, 0x7e, 0x03, 0xe0, 0xf8, 0x7f, 0x07, 0x80, 0x03, 0xe0, 0x00, 0xf8, 0x0f, 0xf0,
    0x7c, 0x07, 0xf8, 0x3f, 0x07, 0xc0, 0xf8, 0x3f, 0x07, 0x80, 0x03, 0xe0, 0x00, 0xf8, 0x0f, 0xf0,
    0x7c, 0x03, 0xf8, 0x3f, 0xff, 0xc0, 0xf8, 0x3f, 0x07, 0x80, 0x03, 0xe0, 0x00, 0xf8, 0x07, 0xf0,
    0x7c, 0x03, 0xf8, 0x1f, 0xff, 0x80, 0xf8, 0x3e, 0x07, 0x80, 0x03, 0xe0, 0x00, 0xf8, 0x07, 0xf0,
    0x7c, 0x01, 0xf8, 0x07, 0xff, 0x00, 0xf8, 0x1e, 0x07, 0x80, 0x03, 0xe0, 0x00, 0xf8, 0x03, 0xf0,
    0x7c, 0x00, 0xf8, 0x01, 0xf8, 0x00, 0xf8, 0x1e, 0x07, 0x80, 0x03, 0xe0, 0x00, 0xf8, 0x01, 0xf0,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    },

    {

    // 'games', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0xc0, 0x00, 0x1f, 0x00, 0x1f, 0xc0, 0x03, 0xf0, 0x7f, 0xff, 0x80, 0x3f, 0x00, 0x00,
    0x00, 0x7f, 0xf8, 0x00, 0x1f, 0x00, 0x1f, 0xc0, 0x03, 0xf0, 0x7f, 0xff, 0x81, 0xff, 0xc0, 0x00,
    0x00, 0xff, 0xfc, 0x00, 0x3f, 0x80, 0x1f, 0xc0, 0x07, 0xf0, 0x7f, 0xff, 0x83, 0xff, 0xf0, 0x00,
    0x01, 0xff, 0xfe, 0x00, 0x3f, 0x80, 0x1f, 0xe0, 0x07, 0xf0, 0x7f, 0xff, 0x87, 0xff, 0xf0, 0x00,
    0x03, 0xf0, 0x3e, 0x00, 0x3f, 0x80, 0x1f, 0xe0, 0x07, 0xf0, 0x7c, 0x00, 0x0f, 0xc1, 0xf8, 0x00,
    0x03, 0xe0, 0x1f, 0x00, 0x7f, 0xc0, 0x1f, 0xe0, 0x0f, 0xf0, 0x7c, 0x00, 0x0f, 0x80, 0xf8, 0x00,
    0x07, 0xc0, 0x1f, 0x00, 0x7f, 0xc0, 0x1f, 0xf0, 0x0f, 0xf0, 0x7c, 0x00, 0x0f, 0x80, 0x78, 0x00,
    0x07, 0xc0, 0x00, 0x00, 0xfb, 0xc0, 0x1f, 0xf0, 0x0e, 0xf0, 0x7c, 0x00, 0x0f, 0x80, 0x00, 0x00,
    0x07, 0xc0, 0x00, 0x00, 0xf3, 0xe0, 0x1f, 0x78, 0x1e, 0xf0, 0x7c, 0x00, 0x0f, 0xc0, 0x00, 0x00,
    0x07, 0xc0, 0x00, 0x00, 0xf1, 0xe0, 0x1f, 0x78, 0x1e, 0xf0, 0x7c, 0x00, 0x07, 0xf0, 0x00, 0x00,
    0x07, 0x80, 0x00, 0x01, 0xf1, 0xf0, 0x1f, 0x78, 0x3c, 0xf0, 0x7f, 0xff, 0x03, 0xfe, 0x00, 0x00,
    0x07, 0x81, 0xff, 0x01, 0xe1, 0xf0, 0x1f, 0x3c, 0x3c, 0xf0, 0x7f, 0xff, 0x01, 0xff, 0xc0, 0x00,
    0x07, 0x81, 0xff, 0x01, 0xe0, 0xf0, 0x1f, 0x3c, 0x3c, 0xf0, 0x7f, 0xff, 0x00, 0x7f, 0xe0, 0x00,
    0x07, 0x81, 0xff, 0x03, 0xe0, 0xf8, 0x1f, 0x3c, 0x78, 0xf0, 0x7f, 0xff, 0x00, 0x1f, 0xf0, 0x00,
    0x07, 0xc1, 0xff, 0x03, 0xc0, 0xf8, 0x1f, 0x1e, 0x78, 0xf0, 0x7c, 0x00, 0x00, 0x03, 0xf8, 0x00,
    0x07, 0xc0, 0x1f, 0x07, 0xff, 0xf8, 0x1f, 0x1e, 0x78, 0xf0, 0x7c, 0x00, 0x00, 0x00, 0xf8, 0x00,
    0x07, 0xc0, 0x1f, 0x07, 0xff, 0xfc, 0x1f, 0x0e, 0xf0, 0xf0, 0x7c, 0x00, 0x00, 0x00, 0x78, 0x00,
    0x07, 0xc0, 0x1f, 0x07, 0xff, 0xfc, 0x1f, 0x0f, 0xf0, 0xf0, 0x7c, 0x00, 0x1f, 0x00, 0x7c, 0x00,
    0x03, 0xe0, 0x1f, 0x0f, 0xff, 0xfe, 0x1f, 0x0f, 0xe0, 0xf0, 0x7c, 0x00, 0x0f, 0x80, 0x78, 0x00,
    0x03, 0xf0, 0x1f, 0x0f, 0x80, 0x3e, 0x1f, 0x07, 0xe0, 0xf0, 0x7c, 0x00, 0x0f, 0xc0, 0xf8, 0x00,
    0x01, 0xff, 0xff, 0x0f, 0x00, 0x3e, 0x1f, 0x07, 0xe0, 0xf0, 0x7f, 0xff, 0x87, 0xff, 0xf8, 0x00,
    0x00, 0xff, 0xfe, 0x1f, 0x00, 0x1f, 0x1f, 0x07, 0xc0, 0xf0, 0x7f, 0xff, 0x83, 0xff, 0xf0, 0x00,
    0x00, 0x7f, 0xfc, 0x1f, 0x00, 0x1f, 0x1f, 0x03, 0xc0, 0xf0, 0x7f, 0xff, 0x81, 0xff, 0xe0, 0x00,
    0x00, 0x0f, 0xc0, 0x3e, 0x00, 0x1f, 0x1f, 0x03, 0xc0, 0xf0, 0x7f, 0xff, 0x80, 0x3f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    },

    {

    // 'adjust', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xf8, 0x00, 0xff, 0xc0, 0x00, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0x03, 0xf0, 0x1f, 0xff, 0xfc,
    0x00, 0xf8, 0x00, 0xff, 0xf8, 0x00, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0x1f, 0xfc, 0x1f, 0xff, 0xfc,
    0x01, 0xfc, 0x00, 0xff, 0xfe, 0x00, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0x3f, 0xff, 0x1f, 0xff, 0xfc,
    0x01, 0xfc, 0x00, 0xff, 0xff, 0x00, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0x7f, 0xff, 0x1f, 0xff, 0xfc,
    0x01, 0xfc, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0xfc, 0x1f, 0x80, 0x3e, 0x00,
    0x03, 0xfe, 0x00, 0xf8, 0x0f, 0x80, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0xf8, 0x0f, 0x80, 0x3e, 0x00,
    0x03, 0xfe, 0x00, 0xf8, 0x07, 0xc0, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0xf8, 0x07, 0x80, 0x3e, 0x00,
    0x07, 0xde, 0x00, 0xf8, 0x07, 0xc0, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0xf8, 0x00, 0x00, 0x3e, 0x00,
    0x07, 0x9f, 0x00, 0xf8, 0x07, 0xc0, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0xfc, 0x00, 0x00, 0x3e, 0x00,
    0x07, 0x8f, 0x00, 0xf8, 0x03, 0xc0, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0x7f, 0x00, 0x00, 0x3e, 0x00,
    0x0f, 0x8f, 0x80, 0xf8, 0x03, 0xc0, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0x3f, 0xe0, 0x00, 0x3e, 0x00,
    0x0f, 0x0f, 0x80, 0xf8, 0x03, 0xc0, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0x1f, 0xfc, 0x00, 0x3e, 0x00,
    0x0f, 0x07, 0x80, 0xf8, 0x03, 0xc0, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0x07, 0xfe, 0x00, 0x3e, 0x00,
    0x1f, 0x07, 0xc0, 0xf8, 0x03, 0xc0, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0x01, 0xff, 0x00, 0x3e, 0x00,
    0x1e, 0x07, 0xc0, 0xf8, 0x03, 0xc0, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0x00, 0x3f, 0x80, 0x3e, 0x00,
    0x3f, 0xff, 0xc0, 0xf8, 0x07, 0xc0, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0x00, 0x0f, 0x80, 0x3e, 0x00,
    0x3f, 0xff, 0xe0, 0xf8, 0x07, 0xc0, 0x00, 0xf8, 0x7c, 0x01, 0xe0, 0x00, 0x07, 0x80, 0x3e, 0x00,
    0x3f, 0xff, 0xe0, 0xf8, 0x07, 0xc7, 0xc0, 0xf8, 0x7c, 0x03, 0xe1, 0xf0, 0x07, 0xc0, 0x3e, 0x00,
    0x7f, 0xff, 0xf0, 0xf8, 0x0f, 0x87, 0xc0, 0xf8, 0x7e, 0x03, 0xe0, 0xf8, 0x07, 0x80, 0x3e, 0x00,
    0x7c, 0x01, 0xf0, 0xf8, 0x3f, 0x07, 0xe1, 0xf0, 0x3f, 0x07, 0xc0, 0xfc, 0x0f, 0x80, 0x3e, 0x00,
    0x78, 0x01, 0xf0, 0xff, 0xff, 0x03, 0xff, 0xf0, 0x3f, 0xff, 0xc0, 0x7f, 0xff, 0x80, 0x3e, 0x00,
    0xf8, 0x00, 0xf8, 0xff, 0xfe, 0x03, 0xff, 0xe0, 0x1f, 0xff, 0x80, 0x3f, 0xff, 0x00, 0x3e, 0x00,
    0xf8, 0x00, 0xf8, 0xff, 0xf8, 0x00, 0xff, 0xc0, 0x07, 0xff, 0x00, 0x1f, 0xfe, 0x00, 0x3e, 0x00,
    0xf0, 0x00, 0xf8, 0xff, 0xc0, 0x00, 0x3e, 0x00, 0x01, 0xf8, 0x00, 0x03, 0xf0, 0x00, 0x3e, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  }*/
/*
    {

    // 'unknown', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x03, 0xe0, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf0, 0x1f, 0xf8, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf8, 0x3f, 0xfc, 0x1f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfc, 0x3f, 0xfe, 0x1f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x7c, 0x7c, 0x3e, 0x3e, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x3e, 0x7c, 0x1f, 0x3e, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x1f, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x1e, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x3e, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x7c, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x00, 0xf8, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x01, 0xf0, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x01, 0xe0, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x03, 0xc0, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x03, 0xc0, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x03, 0xc0, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x01, 0x80, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x03, 0xc0, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x07, 0xc0, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x03, 0xc0, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x01, 0x80, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    }

  };
*/
}


void oled_task_user(void) {

  //oled_write_P(PSTR("\n"), false);
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
           oled_write_ln_P(PSTR("G A M E S"), false);
           break;
       case _ADJUST:
           oled_write_ln_P(PSTR("ADJUST"), false);
           break;
       default:
           // Or use the write_ln shortcut over adding '\n' to the end of your string
           oled_write_ln_P(PSTR("Undefined"), false);
     }

     //oled_write_ln_P(read_timelog(), false);
     oled_write_ln(read_keylog(), false);
     oled_write_ln(read_keylogs(), false);

   } else {

    //render_logo(biton32(layer_state));
    render_logo(1);
     //oled_write_ln(read_timelog(), false);

        // If you want to change the display of OLED, you need to change here
    //oled_write_ln(read_layer_state(), false);

    // oled_write_P(PSTR("\n"), false);
    //
    // oled_write_ln(read_layer_state(), false);
    // oled_write_ln(read_keylog(), false);
    // oled_write_ln(read_keylogs(), false);

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
