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
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xDFA1
#define DEVICE_VER      0x0020
#define MANUFACTURER    marksard
#define PRODUCT         Rhymestone

/* key matrix size */
#undef MATRIX_ROWS
#undef MATRIX_COLS
#define MATRIX_ROWS 4
#define MATRIX_COLS 5
/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { F4, F5, F6, F7 }
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4 }


/* COL2ROW, ROW2COL*/
#undef DIODE_DIRECTION
#define DIODE_DIRECTION COL2ROW

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#undef SOFT_SERIAL_PIN
// #define SOFT_SERIAL_PIN D2  // or D1, D2, D3, E6


#define RGB_DI_PIN D3

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5


#define LAYOUT( \
    k00, k01, k02, k03, k04, \
    k05, k06, k07, k08, k09, \
    k10, k11, k12, k13, k14, \
    k15, k16, k17, k18, k19 \
) \
{ \
    { k00, k01, k02, k03, k04  }, \
    { k05, k06, k07, k08, k09  },       \
    { k10, k11, k12, k13, k14  },       \
    { k15, k16, k17, k18, k19 }        \
}
