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

#include QMK_KEYBOARD_H
#include <hal.h>
#include <string.h>
#include <ctype.h>
#include <printf.h>
#include <transactions.h>
#include <split_util.h>

#include "config.h"
#include "nic.h"
#define MEDIA_KEY_DELAY 5

#define KC_LWR MO(_LOWER)
#define KC_RSE MO(_RAISE)

// clang-format off

#define LAYOUT_dj_wrapper(...)       LAYOUT_all(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_dj_wrapper(
        ________________NUMBER_LEFT________________,   RGB_RMOD,                           RGB_RMOD,  ________________NUMBER_RIGHT_______________ ,
       _________________QWERTY_L1_________________,    KC_PGUP,                                         KC_RBRC, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________,   KC_PGDN ,                                KC_HOME,  _________________QWERTY_R2_________________,
       _________________QWERTY_L3_________________,    KC_DEL,                           KC_END,  _________________QWERTY_R3_________________,
                                   KC_LALT,  KC_LCTL, KC_LWR, KC_SPC,                          KC_SPC,  KC_RSE,  KC_LGUI,  KC_LCTL,
                                                                      RGB_RMOD,         RGB_MOD,
                                                     RGB_RMOD,                                              RGB_RMOD,
                                            DEBUG,   EEP_RST, RESET,                         RESET,   EEP_RST, DEBUG,
                                                     EEP_RST,                                            EEP_RST
    ),
    [_LOWER] = LAYOUT_dj_wrapper(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                         _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _________________LOWER_L2__________________, _______,                         _______,  _________________LOWER_R3__________________,
       _________________LOWER_L3__________________, _______,                         _______,  _________________LOWER_R3__________________,
       _________________LOWER_L4__________________, _______,                         _______,  _________________LOWER_R4__________________,
                                   _______, _______, _______, _______,                         _______, _______, _______, _______,
                                                                     BL_DEC,             BL_INC,
                                                     _______,                                           _______,
                                            _______, _______, _______,                         _______, _______, _______,
                                                     _______,                                           _______
    ),
    [_RAISE] = LAYOUT_dj_wrapper(
        _________________RAISE_L1__________________,   _______,                         _______, _________________RAISE_R1__________________,
       _________________RAISE_L2__________________, _______,                         _______, _________________RAISE_R2__________________,
        _________________RAISE_L3__________________, KC_NO,                           KC_NO,   _________________RAISE_R3__________________,
        _________________RAISE_L4__________________, KC_NO,                           KC_NO,   _________________RAISE_R4__________________,
                                   _______, _______, _______, _______,                         _______, _______, _______, _______,
                                                                     _______,           _______,
                                                     _______,                                           _______,
                                            _______, _______, _______,                         _______, _______, _______,
                                                     _______,                                           _______
    ),
    [_ADJUST] = LAYOUT_dj_wrapper(
        _________________ADJUST_L1_________________, _______,                         _______, _________________ADJUST_R1_________________,
        _________________ADJUST_L2_________________, _______,                         _______,  _________________ADJUST_R2_________________,
        _________________ADJUST_L3_________________, _______,                         _______,  _________________ADJUST_R3_________________,
        _________________ADJUST_L4_________________, _______,                         _______,  _________________ADJUST_R4_________________,
                                   _______, _______, _______, _______,                         _______, _______, _______, _______,
                                                                     _______,           _______,
                                                     _______,                                           _______,
                                            _______, _______, _______,                         _______, _______, _______,
                                                     _______,                                           _______
    )
};


// clang-format on


#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_LOWER]  = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
    [_RAISE]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_SPD, RGB_SPI)},
    [_ADJUST] = {ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
};
#else
bool encoder_update_user(uint8_t index, bool clockwise) {


    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code16(KC_MS_WH_DOWN);
        } else {
            tap_code16(KC_MS_WH_UP);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, MEDIA_KEY_DELAY);
        } else {
            tap_code_delay(KC_VOLD, MEDIA_KEY_DELAY);
        }
    }

    return false;
}
#endif

// clang-format off
#ifdef SWAP_HANDS_ENABLE
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
   { { 6,  6 }, { 5,  6 }, { 4,  6 }, { 3,  6 }, { 2,  6 }, { 1,  6 }, { 0,  6 } },
   { { 6,  7 }, { 5,  7 }, { 4,  7 }, { 3,  7 }, { 2,  7 }, { 1,  7 }, { 0,  7 } },
   { { 6,  8 }, { 5,  8 }, { 4,  8 }, { 3,  8 }, { 2,  8 }, { 1,  8 }, { 0,  8 } },
   { { 6,  9 }, { 5,  9 }, { 4,  9 }, { 3,  9 }, { 2,  9 }, { 1,  9 }, { 0,  9 } },
   { { 0,  0 }, { 0,  0 }, { 0,  0 }, { 6, 10 }, { 5, 10 }, { 4, 10 }, { 3, 10 } },
   { { 0,  0 }, { 6, 11 }, { 5, 11 }, { 4, 11 }, { 3, 11 }, { 2, 11 }, { 1, 11 } },

   { { 6,  0 }, { 5,  0 }, { 4,  0 }, { 3,  0 }, { 2,  0 }, { 1,  0 }, { 0,  0 } },
   { { 6,  1 }, { 5,  1 }, { 4,  1 }, { 3,  1 }, { 2,  1 }, { 1,  1 }, { 0,  1 } },
   { { 6,  2 }, { 5,  2 }, { 4,  2 }, { 3,  2 }, { 2,  2 }, { 1,  2 }, { 0,  2 } },
   { { 6,  3 }, { 5,  3 }, { 4,  3 }, { 3,  3 }, { 2,  3 }, { 1,  3 }, { 0,  3 } },
   { { 0,  0 }, { 0,  0 }, { 0,  0 }, { 6,  4 }, { 5,  4 }, { 4,  4 }, { 3,  4 } },
   { { 0,  0 }, { 6,  5 }, { 5,  5 }, { 4,  5 }, { 3,  5 }, { 2,  5 }, { 1,  5 } },
};
#    ifdef ENCODER_MAP_ENABLE
const uint8_t PROGMEM encoder_hand_swap_config[NUM_ENCODERS] = { 1, 0 };
#    endif
#endif
// clang-format on

//----------------------------------------------------------
// Sync
#pragma pack(push)
#pragma pack(1)

typedef struct user_runtime_config {
    uint32_t scan_rate;
} user_runtime_config;

#pragma pack(pop)

_Static_assert(sizeof(user_runtime_config) == 4, "Invalid data transfer size for user sync data");

user_runtime_config user_state;

void rpc_user_sync_callback(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size, void *target2initiator_buffer) {
    if (initiator2target_buffer_size == sizeof(user_state)) {
        memcpy(&user_state, initiator2target_buffer, sizeof(user_runtime_config));
    }
}

__attribute__((weak)) void keyboard_post_init_keymap(void)  {
    // Register keyboard state sync split transaction
    transaction_register_rpc(USER_DATA_SYNC, rpc_user_sync_callback);

    // Reset the initial shared data value between master and slave
    memset(&user_state, 0, sizeof(user_state));


}

void user_state_update(void) {
    if (is_keyboard_master()) {
        // Keep the scan rate in sync
        user_state.scan_rate = get_matrix_scan_rate();
    }
}

void user_state_sync(void) {
    if (!is_transport_connected()) return;

    if (is_keyboard_master()) {
        // Keep track of the last state, so that we can tell if we need to propagate to slave
        static user_runtime_config last_user_state;
        static uint32_t            last_sync;
        bool                       needs_sync = false;

        // Check if the state values are different
        if (memcmp(&user_state, &last_user_state, sizeof(user_runtime_config))) {
            needs_sync = true;
            memcpy(&last_user_state, &user_state, sizeof(user_runtime_config));
        }

        // Send to slave every 125ms regardless of state change
        if (timer_elapsed32(last_sync) > 125) {
            needs_sync = true;
        }

        // Perform the sync if requested
        if (needs_sync) {
            if (transaction_rpc_send(USER_DATA_SYNC, sizeof(user_runtime_config), &user_state)) {
                last_sync = timer_read32();
            }
        }
    }
}

void housekeeping_task_user(void) {
    // Update kb_state so we can send to slave
    user_state_update();

    // Data sync from master to slave
    user_state_sync();
}
