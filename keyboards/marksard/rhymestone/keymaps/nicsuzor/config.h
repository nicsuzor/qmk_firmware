/* Copyright 2020 marksard
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/*
 * PIN LAYOUT
 * 16 = B4 = Col5
 * 14 = E6 = Col4
 * 15 = D7 = Col3
 * A0 = C6 = Col2
 * 4 = D4 = Col 1
 * 2 = F4 = Row 1
 * 3 = F5 = Row 2
 * 4 = F6 = Row 3
 * 5 = F7 = Row 4
 */

#include "config_common.h"

/* USB Device descriptor parameter */
#undef DEVICE_VER
#undef PRODUCT
#define DEVICE_VER      0x0021
#define PRODUCT         RhymestoneNumPad

/* key matrix size */
#undef MATRIX_ROWS
#undef MATRIX_COLS
#define MATRIX_ROWS 4
#define MATRIX_COLS 5


#    define DRIVER_LED_TOTAL 54

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#undef SOFT_SERIAL_PIN
// #define SOFT_SERIAL_PIN D2  // or D1, D2, D3, E6


#define LAYOUT_5x4( \
    k00, k01, k02, k03, \
    k04, k05, k06, k07, \
    k08, k09, k10, k11, \
    k12, k13, k14, k15, \
    k16, k17, k18, k19 \
) \
{ \
    { k03, k07, k11, k15, k19  }, \
    { k02, k06, k10, k14, k18  },       \
    { k01, k05, k09, k13, k17  },       \
    { k00, k04, k08, k12, k16 } \
}

/*{ \
    { k19, k15, k11, k07, k03 }, \
    { k18, k14, k10, k06, k02 },       \
    { k17, k13, k09, k05, k01  },       \
    { k16, k12, k08, k04, k00 }        \
}*/
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define DISABLE_RGB_MATRIX_SPLASH
#define DISABLE_RGB_MATRIX_MULTISPLASH
#define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#define DISABLE_RGB_MATRIX_DIGITAL_RAIN

