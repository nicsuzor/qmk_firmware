/* Copyright 2021 Nick Brassel (@tzarc)
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

// Split configuration
#define SPLIT_HAND_PIN B9
//#define MASTER_LEFT

#undef SERIAL_DRIVER_USART_DUPLEX
#define SERIAL_DRIVER_USART_DUPLEX
#    define SERIAL_USART_DRIVER SD3
#    define SERIAL_USART_PIN_SWAP
#    define SERIAL_USART_TX_PIN B10
#    define SERIAL_USART_TX_PAL_MODE 7
#    define SERIAL_USART_RX_PIN B11
#    define SERIAL_USART_RX_PAL_MODE 7
#    define SERIAL_USART_SPEED 19200
#    define SELECT_SOFT_SERIAL_SPEED 4
#    define SERIAL_USART_FULL_DUPLEX
#    define SERIAL_USART_TIMEOUT 20

#if defined(SERIAL_DRIVER_USART)
#    define SERIAL_USART_DRIVER SD3
#    define SERIAL_USART_PIN_SWAP
#    define SERIAL_USART_TX_PIN B10
#    define SERIAL_USART_TX_PAL_MODE 7
#    define SERIAL_USART_RX_PIN B11
#    define SERIAL_USART_RX_PAL_MODE 7
#    ifndef SERIAL_USART_SPEED
#        define SERIAL_USART_SPEED 19200
#    endif  // SERIAL_USART_SPEED
#    define SELECT_SOFT_SERIAL_SPEED 4
#    define SERIAL_USART_FULL_DUPLEX
#endif  // defined(SERIAL_DRIVER_USART)

// RGB configuration
#define RGB_POWER_ENABLE_PIN B0
#define RGB_CURR_1500mA_OK_PIN C5
#define RGB_CURR_3000mA_OK_PIN C4
#define RGBLED_NUM 86
#define RGBLED_SPLIT \
    { 43, 43 }


// Fault indicators
#define BOARD_POWER_FAULT_PIN C9
#define RGB_POWER_FAULT_PIN C4
