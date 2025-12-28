#pragma once
#include <stdint.h>

/**
 * @brief Logical outputs from the application step.
 *
 * These are decisions/intentions, not direct HAL actions.
 */
typedef struct {
    uint16_t torque_cmd;   // two's complement value expected by inverter
    uint8_t  torque_pct;   // 0..100 for debug/telemetry

    uint8_t  flag_ev23;
    uint8_t  flag_t1189;
} app_outputs_t;
