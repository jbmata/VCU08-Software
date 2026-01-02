#include "inverter_service.h"
#include "can_service.h"

/*
 * ESTA función ya existe hoy.
 * Contiene GPIO + CAN + HAL.
 */
extern void apply_inverter_control(
    const inverter_sm_outputs_t *sm_out,
    float torque_cmd
);

void inverter_service_init(void)
{
    /* nada por ahora */
}

void inverter_service_apply(
    const inverter_sm_outputs_t *sm_out,
    float torque_cmd
)
{
    if (!sm_out) return;

    /* delega exactamente en el código existente */
    apply_inverter_control(sm_out, torque_cmd);
}
