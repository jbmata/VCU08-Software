#pragma once
#include "../model/inputs.h"
#include "../model/state.h"

/**
 * @brief EV 2.3 brake plausibility.
 *
 * Mutates st->flag_ev23 and may force *torque = 0.
 */
void safety_ev23(const app_inputs_t *in, app_state_t *st, int *torque);

/**
 * @brief T11.8.9 accelerator plausibility (sensor deviation).
 *
 * Mutates st->flag_t1189 and may force *torque = 0.
 */
void safety_t1189(const app_inputs_t *in, app_state_t *st, int s1_pct, int s2_pct, int *torque);
