#ifndef CONTROL_SERVICE_H
#define CONTROL_SERVICE_H

#include "app.h"
#include "inverter_sm.h"

/* ================================
 * Estado persistente del control
 * ================================ */
typedef struct
{
    app_state_t         app_state;
    inverter_sm_state_t inverter_state;
} control_service_state_t;

/* ================================
 * API
 * ================================ */
void control_service_init(control_service_state_t *state);
void control_service_step(control_service_state_t *state);

#endif
