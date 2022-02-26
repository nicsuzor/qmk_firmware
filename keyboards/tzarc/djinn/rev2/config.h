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

#define SERIAL_USART_DRIVER SD3
#    define SERIAL_USART_PIN_SWAP
#    define SERIAL_USART_TX_PIN B10
#    define SERIAL_USART_TX_PAL_MODE 7
#    define SERIAL_USART_RX_PIN B11
#    define SERIAL_USART_RX_PAL_MODE 7

#    define SERIAL_USART_SPEED 38400

#    define SERIAL_USART_FULL_DUPLEX

// Fault indicators
#define BOARD_POWER_FAULT_PIN C9
#define RGB_POWER_FAULT_PIN C4

#ifndef STM32_BOOTLOADER_DUAL_BANK
#    define STM32_BOOTLOADER_DUAL_BANK FALSE
#endif

// To Enter bootloader from `RESET` keycode, you'll need to dedicate a GPIO to
// charge an RC network on the BOOT0 pin.
// See the QMK Discord's #hardware channel pins for an example circuit.
// Insert these two lines into your keyboard's `config.h` file.
// In the case below, PB7 is selected to charge.
#if 0
#define STM32_BOOTLOADER_DUAL_BANK TRUE
#define STM32_BOOTLOADER_DUAL_BANK_GPIO B7
#endif