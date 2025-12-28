#include "app.h"
#include "control/torque.h"

void app_step(const app_inputs_t *in, app_state_t *st, app_outputs_t *out)
{
    // Phase A: torque + safety only.
    // Later phases may add inverter state machine, telemetry builder, etc.
    torque_step(in, st, out);
}
