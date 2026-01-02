#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Inputs EXACTOS del main original */
typedef struct
{
    uint8_t state;     /* == state */
    uint8_t flag_r2d;  /* == flag_r2d */
    uint8_t error;     /* == error */
} inverter_sm_inputs_t;

/* Salidas lógicas (intenciones), sin HAL */
#define INV_SM_MAX_SETPOINTS 3

typedef struct
{
    /* RX_SETPOINT_1 (TxData_Inv[2]) */
    uint8_t setpoint_count;
    uint8_t setpoint_value[INV_SM_MAX_SETPOINTS];

    /* Torque CAN 0x362 */
    uint8_t send_torque;
    uint8_t torque_zero;
    uint8_t torque_compute;

    /* flag_react side-effect */
    uint8_t set_flag_react;
    uint8_t flag_react_value;

    /* Debug / eventos */
    uint8_t dbg_ready;
    uint8_t dbg_torque;
    uint8_t dbg_soft_fault;
    uint8_t dbg_hard_fault;
    uint8_t dbg_shutdown;

} inverter_sm_outputs_t;

/* Máquina de estados PURA */
void inverter_sm_step(const inverter_sm_inputs_t *in,
                      inverter_sm_outputs_t *out);

#ifdef __cplusplus
}
#endif
