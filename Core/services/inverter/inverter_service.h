#ifndef INVERTER_SERVICE_H
#define INVERTER_SERVICE_H

#include "inverter_sm.h"

void inverter_service_init(void);

/*
 * Aplica lo que decidió el control
 * (ANTES estaba en main.c)
 */
void inverter_service_apply(
    const inverter_sm_outputs_t *sm_out,
    float torque_cmd
);

#endif
