#include "control_service.h"

/* servicios */
#include "io_service.h"
#include "inverter_service.h"

/* modelos */
#include "inputs.h"
#include "outputs.h"
#include "inverter_sm.h"

/* ================================
 * Inicialización
 * ================================ */
void control_service_init(control_service_state_t *s)
{
    if (!s) return;

    app_init(&s->app_state);
    inverter_sm_init(&s->inverter_state);
}

/* ================================
 * Ciclo principal de control
 * ================================ */
void control_service_step(control_service_state_t *s)
{
    if (!s) return;

    /* -----------------------------
     * 1. Inputs lógicos
     * ----------------------------- */
    app_inputs_t app_in;
    inverter_sm_inputs_t inv_in;

    io_service_get_app_inputs(&app_in);
    inverter_service_get_sm_inputs(&inv_in);

    /* -----------------------------
     * 2. Lógica funcional
     * ----------------------------- */
    app_outputs_t app_out;
    inverter_sm_outputs_t inv_out;

    app_step(&app_in, &s->app_state, &app_out);
    inverter_sm_step(&inv_in, &s->inverter_state, &inv_out);

    /* -----------------------------
     * 3. Arbitraje (CLAVE)
     * ----------------------------- */
    float torque_cmd =
        inv_out.allow_torque ? app_out.torque_cmd : 0.0f;

    /* -----------------------------
     * 4. Aplicación (delegada)
     * ----------------------------- */
    inverter_service_apply(&inv_out, torque_cmd);
}
