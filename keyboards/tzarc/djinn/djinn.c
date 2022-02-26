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

#include <string.h>
#include <quantum.h>
#include <hal_pal.h>

#include "djinn.h"
#include "serial.h"
#include "split_util.h"

void kb_state_sync(void) {
    if (!is_transport_connected()) return;

}

#define MATRIX_ROW_PINS \
    { B13, B14, B15, C6, C7, C8 }
#define MATRIX_COL_PINS \
    { C0, C1, C2, C3, A0, A1, A2 }

void housekeeping_task_kb(void) {

    // Data sync from master to slave
    kb_state_sync();
}

//----------------------------------------------------------
// Initialisation

void keyboard_post_init_kb(void) {
    // Allow for user post-init
    keyboard_post_init_user();
}

//----------------------------------------------------------
// QMK overrides

// Read the ports in one go
#define GPIOB_BITMASK (1 << 13 | 1 << 14 | 1 << 15)  // B13, B14, B15
#define GPIOB_OFFSET 13
#define GPIOB_COUNT 3
#define GPIOC_BITMASK (1 << 6 | 1 << 7 | 1 << 8)  // C6, C7, C8
#define GPIOC_OFFSET 6

// Pin definitions
static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;

void matrix_init_pins(void) {
    for (int i = 0; i < MATRIX_ROWS; ++i) setPinInputHigh(row_pins[i]);
    for (int i = 0; i < MATRIX_COLS; ++i) setPinInputHigh(col_pins[i]);
}

void matrix_read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col, matrix_row_t row_shifter) {
    // Setup the output column pin
    setPinOutput(col_pins[current_col]);
    writePinLow(col_pins[current_col]);
    rtcnt_t start = chSysGetRealtimeCounterX();
    rtcnt_t end   = start + 500;
    while (chSysIsCounterWithinX(chSysGetRealtimeCounterX(), start, end))
        if (readPin(col_pins[current_col]) == 0) break;

    // Read the row ports
    uint32_t gpio_b = palReadPort(GPIOB);
    uint32_t gpio_c = palReadPort(GPIOC);

    // Unselect the row pin
    setPinInputHigh(col_pins[current_col]);

    // Consutrct the packed bitmask for the pins
    uint32_t readback = ~(((gpio_b & GPIOB_BITMASK) >> GPIOB_OFFSET) | (((gpio_c & GPIOC_BITMASK) >> GPIOC_OFFSET) << GPIOB_COUNT));

    // Inject values into the matrix
    for (int i = 0; i < MATRIX_ROWS; ++i) {
        if (readback & (1 << i))
            current_matrix[i] |= (1ul << current_col);
        else
            current_matrix[i] &= ~(1ul << current_col);
    }

    // Wait for readback of each port to go high -- unselecting the row would have been completed
    start = chSysGetRealtimeCounterX();
    end   = start + 500;
    while (chSysIsCounterWithinX(chSysGetRealtimeCounterX(), start, end))
        if ((palReadPort(GPIOB) & GPIOB_BITMASK) == GPIOB_BITMASK) break;
    while (chSysIsCounterWithinX(chSysGetRealtimeCounterX(), start, end))
        if ((palReadPort(GPIOC) & GPIOC_BITMASK) == GPIOC_BITMASK) break;
}
