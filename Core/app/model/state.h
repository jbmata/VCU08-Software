#pragma once
#include <stdint.h>

/**
 * @brief Persistent application state across app_step() calls.
 */
typedef struct {
    // EV 2.3 (brake plausibility)
    uint8_t  flag_ev23;

    // T11.8.9 (APS plausibility)
    uint8_t  flag_t1189;
    uint32_t last_time_t1189;

} app_state_t;
