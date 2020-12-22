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

//#    define RGB_MATRIX_SPLIT { 27, 27 }
//#    define DRIVER_LED_TOTAL 54
#define MASTER_LEFT
//#define WS2812_DRIVER = pwm

// #undef SSD1306OLED

#ifdef AUDIO_ENABLE
#    define NO_MUSIC_MODE
#    define AUDIO_CLICKY
#endif