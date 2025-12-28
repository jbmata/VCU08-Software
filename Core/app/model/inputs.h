#pragma once
#include <stdint.h>

/**
 * @brief Logical inputs for the application step.
 *
 * Keep these as "logic-level" values (already interpreted),
 * not peripheral handles or HAL types.
 */
typedef struct {
    uint16_t accel1_raw;
    uint16_t accel2_raw;
    uint16_t brake_raw;

    float    v_cell_min;

    uint32_t now_ms;
} app_inputs_t;
