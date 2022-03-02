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

#include "config_common.h"

// USB Device parameters
#define VENDOR_ID 0x1209
#define PRODUCT_ID 0x4919
#define DEVICE_VER 0x0001
#define MANUFACTURER Tzarc
#define PRODUCT Djinn

// Matrix
#define MATRIX_ROWS 12
#define MATRIX_COLS 7
#define DIODE_DIRECTION ROW2COL

// Encoders -- right-side is reversed
#define ENCODERS_PAD_A \
    { C14 }
#define ENCODERS_PAD_B \
    { C15 }
#define ENCODERS_PAD_A_RIGHT \
    { C15 }
#define ENCODERS_PAD_B_RIGHT \
    { C14 }

#ifndef ENCODER_RESOLUTION
#    define ENCODER_RESOLUTION 2
#endif  // ENCODER_RESOLUTION

// Bootloader
#define STM32_BOOTLOADER_DUAL_BANK TRUE
#define STM32_BOOTLOADER_DUAL_BANK_GPIO B7

// Peripheral power control pins
#define LCD_POWER_ENABLE_PIN A6

// Split configuration
//#define SPLIT_PLUG_DETECT_PIN B12
#define SPLIT_TRANSACTION_IDS_KB RPC_ID_SYNC_STATE_KB
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
//#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE

#define SPLIT_MAX_CONNECTION_ERRORS 100

#define SPLIT_TRANSACTION_IDS_USER USER_DATA_SYNC
//#define NO_USB_STARTUP_CHECK TRUE



// Audio configuration
#define AUDIO_PIN A5
#define AUDIO_PIN_ALT A4
#define AUDIO_PIN_ALT_AS_NEGATIVE
#define A5_AUDIO
#ifndef STARTUP_SONG
#    define STARTUP_SONG SONG(STARTUP_SOUND)
#endif  // STARTUP_SONG

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
