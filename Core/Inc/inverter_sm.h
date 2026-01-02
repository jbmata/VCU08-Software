#pragma once
#include <stdint.h>

/*
 * IMPORTANTE:
 * Los valores numéricos de los estados SON LOS MISMOS
 * que los que tienes actualmente en main.c.
 * NO CAMBIAR estos números.
 */

typedef enum {
    INV_STATE_BOOT        = 0,
    INV_STATE_WAIT_HV     = 1,
    INV_STATE_PRECHARGE   = 2,
    INV_STATE_READY       = 3,
    INV_STATE_RTD         = 4,
    INV_STATE_TORQUE      = 5,
    INV_STATE_FAULT       = 6
} inverter_state_t;

/*
 * Inputs lógicos de la máquina de estados.
 * Estos valores hoy vienen de main.c (GPIO, CAN, flags).
 */
typedef struct {
    uint8_t hv_ok;
    uint8_t precharge_done;
    uint8_t inverter_ok;
    uint8_t start_button;
    uint8_t fault_present;
} inverter_sm_inputs_t;

/*
 * Outputs lógicos de la máquina de estados.
 * main.c se encarga de aplicar estos outputs al hardware.
 */
typedef struct {
    uint8_t enable_precharge;
    uint8_t enable_inverter;
    uint8_t allow_torque;
    uint8_t request_shutdown;
} inverter_sm_outputs_t;

/*
 * Estado interno persistente del state machine.
 * Sustituye al "uint8_t state" global.
 */
typedef struct {
    inverter_state_t current;
} inverter_sm_state_t;

/*
 * API pública de la máquina de estados.
 * Equivale al switch(state) original.
 */
void inverter_sm_step(const inverter_sm_inputs_t *in,
                      inverter_sm_state_t *st,
                      inverter_sm_outputs_t *out);
