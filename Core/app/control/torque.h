#pragma once
#include "../model/inputs.h"
#include "../model/outputs.h"
#include "../model/state.h"

/**
 * @brief Compute torque command and safety flags for one step.
 *
 * This function is pure logic: no HAL, no FreeRTOS.
 * It is intended to preserve behavior from your legacy setTorque() implementation.
 */
void torque_step(const app_inputs_t *in, app_state_t *st, app_outputs_t *out);
