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


//#undef USE_I2C // I2C doesn't work for split common

//#    define RGB_MATRIX_SPLIT { 27, 27 }
#    define DRIVER_LED_TOTAL 54
#define MASTER_LEFT

#define USE_SERIAL
#define USE_SERIAL_PD2
#define SOFT_SERIAL_PIN D2
#define RGB_DI_PIN D3
#define WS2812_DRIVER = pwm

/*

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// #define SSD1306OLED
//#undef USE_I2C

#undef SSD1306OLED

//#define USE_SERIAL_PD2

*/
