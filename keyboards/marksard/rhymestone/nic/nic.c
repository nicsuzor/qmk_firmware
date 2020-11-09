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

#include "./common/oled_helper.h"
#include <print.h>
#include QMK_KEYBOARD_H
#include "nic.h"


#define UPDATE_KEYMAP_STATUS()

__attribute__((weak))
void matrix_init_user(void) {}
void matrix_init_kb(void) {
    matrix_init_user();
}

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
  {  0, 1, 2, 3, 4 },
                {  0, 1, 2, 3, 4 },
                              {  0, 1, 2, 3, 4 },
                                            {  0, 1, 2, 3, 4 }
}, {
  { 100,   0 }, { 100,  21 }, { 100,  43 }, { 100,  64 },
  {  75,  64 }, {  50,  64 }, {  25,  64 }, {   0,  64 },
  {   0,  43 }, {   0,  21 }, {   0,   0 }, {  25,   0 },
  {  50,   0 }, {  75,   0 },{  75,  21 }, {  75,  43 },
  {  50,  43 }, {  25,  43 }, {  25,  21 }, {  50,  21 }
}, {
  4, 4, 4, 1,
  1, 1, 1, 1,
  4, 4, 4, 4,
  4, 4, 2, 4,
  4, 4, 8, 4
} };
#endif