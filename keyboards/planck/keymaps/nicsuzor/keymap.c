#include QMK_KEYBOARD_H
#include "nic.h"
#include "muse.h"

#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;


#ifdef KEYBOARD_planck_ez
#define LAYOUT_planck_grid_wrapper(...)       LAYOUT_planck_1x2uC(__VA_ARGS__)
#define ______________PLANCK_NS_BOTTOM_____________ _____________DOUBLE_BOTTOM_ROW_____________
#else
#define LAYOUT_planck_grid_wrapper(...)       LAYOUT_planck_grid(__VA_ARGS__)
#define ______________PLANCK_NS_BOTTOM_____________ _______________GRID_BOTTOM_ROW_____________
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_planck_grid_wrapper(
    _________________QWERTY_L1_________________,                _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________,                _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________,                _________________QWERTY_R3_________________,
    ______________PLANCK_NS_BOTTOM_____________
),

[_LOWER] = LAYOUT_planck_grid_wrapper(
    _________________LOWER_L2__________________,                _________________LOWER_R2__________________,
    _________________LOWER_L3__________________,                _________________LOWER_R3__________________,
    _________________LOWER_L4__________________,                _________________LOWER_R4__________________,
    ______________PLANCK_NS_BOTTOM_____________
),

[_RAISE] = LAYOUT_planck_grid_wrapper(
    _________________RAISE_L1__________________,                _________________RAISE_R1__________________,
    _________________RAISE_L2__________________,                _________________RAISE_R2__________________,
    _________________RAISE_L3__________________,                _________________RAISE_R3__________________,
    ______________PLANCK_NS_BOTTOM_____________
),

[_ADJUST] = LAYOUT_planck_grid_wrapper(
    _________________ADJUST_L1_________________,                    _________________ADJUST_R1_________________,
    _________________ADJUST_L2_________________,                    _________________ADJUST_R2_________________,
    _________________ADJUST_L3_________________,                    _________________ADJUST_R3_________________,
    ______________PLANCK_NS_BOTTOM_____________
)
};

