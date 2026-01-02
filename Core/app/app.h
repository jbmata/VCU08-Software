#pragma once

#include "inputs.h"
#include "outputs.h"
#include "state.h"

/**
 * @brief One deterministic application step.
 *
 * This is the only entry-point the scheduler (ISR/polling/FreeRTOS/SIL) should call.
 * It is pure logic: no HAL, no FreeRTOS calls.
 */
void app_step(const app_inputs_t *in, app_state_t *st, app_outputs_t *out);
