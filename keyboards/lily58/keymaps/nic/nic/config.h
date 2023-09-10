/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

//#undef USE_SERIAL_PD2
//#define USE_MATRIX_I2C

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_ANIMATIONS
#endif

#define FORCE_NKRO

/* key matrix size */
// Rows are doubled-up
#undef MATRIX_ROWS
#undef MATRIX_COLS
#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS

#define MATRIX_ROWS 10
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { B4, B3, B2, B1, B0 }

// wiring of each half
#define MATRIX_COL_PINS { A0, B8, B13, B14, B15, B9 }

#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN A10
#undef RGB_DI_PIN
#define RGB_DI_PIN A9