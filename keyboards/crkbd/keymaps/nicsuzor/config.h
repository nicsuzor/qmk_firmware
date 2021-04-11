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

#define MASTER_LEFT

#ifdef AUDIO_ENABLE
#    define NO_MUSIC_MODE
#    define AUDIO_CLICKY
#endif

//#define USE_I2C
//#define USE_SERIAL_PD2
//#undef USE_SERIAL
//#define USE_MATRIX_I2C

#define SELECT_SOFT_SERIAL_SPEED 4
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN A10
#define SERIAL_USE_MULTI_TRANSACTION

#define SPLIT_USB_DETECT

/* key matrix size */
// Rows are doubled-up
#undef MATRIX_ROWS
#undef MATRIX_COLS
#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS

#define MATRIX_ROWS 8
#define MATRIX_COLS 6
#define MATRIX_ROW_PINS { B5, B4, B3, B2 }

// wiring of each half
#define MATRIX_COL_PINS { A2, A1, A0, B8, B13, B14 }
// #define MATRIX_COL_PINS { B2, B3, B1, F7, F6, F5, F4 } //uncomment this line and comment line above if you need to reverse left-to-right key order

// LEDs

/* ws2812 RGB LED */
#undef RGB_DI_PIN
//#define RGB_DI_PIN A9

#define WS2812_PWM_DRIVER PWMD2
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 10
#define WS2812_DMA_STREAM STM32_DMA1_STREAM2
#define WS2812_DMA_CHANNEL 2

#undef DRIVER_LED_TOTAL
//#define DRIVER_LED_TOTAL 54

//#define RGBLED_NUM 58
//#define RGBLIGHT_SPLIT
#undef RGB_MATRIX_SPLIT
//#define RGB_MATRIX_SPLIT { 27, 27 }

#ifdef SPLIT_TRANSPORT_MIRROR
#undef SPLIT_TRANSPORT_MIRROR
#endif
//#define SPLIT_TRANSPORT_MIRROR

//#define SSD1306OLED
//#define USE_I2C