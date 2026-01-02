#pragma once

/* El header público de app DEBE exponer su modelo */
#include "inputs.h"
#include "state.h"
#include "outputs.h"

/* API pública de la aplicación */
void app_step(const app_inputs_t *in,
              app_state_t *st,
              app_outputs_t *out);
