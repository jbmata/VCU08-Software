#include "inverter_sm.h"

static void push_setpoint(inverter_sm_outputs_t *out, uint8_t v)
{
    if (out->setpoint_count < INV_SM_MAX_SETPOINTS) {
        out->setpoint_value[out->setpoint_count++] = v;
    }
}

void inverter_sm_step(const inverter_sm_inputs_t *in,
                      inverter_sm_outputs_t *out)
{
    /* Defaults OBLIGATORIOS */
    out->setpoint_count   = 0;
    out->send_torque      = 0;
    out->torque_zero      = 0;
    out->torque_compute   = 0;
    out->set_flag_react   = 0;
    out->flag_react_value = 0;

    out->dbg_ready       = 0;
    out->dbg_torque      = 0;
    out->dbg_soft_fault  = 0;
    out->dbg_hard_fault  = 0;
    out->dbg_shutdown    = 0;

    if (!in) return;

    /* === BLOQUE PREVIO ===
     * if ((state == 4 || state == 6) && flag_r2d == 1)
     */
    if ((in->state == 4 || in->state == 6) && in->flag_r2d == 1) {
        push_setpoint(out, 0x06);
    }

    /* === SWITCH PRINCIPAL === */
    if (in->flag_r2d != 1) {
        return;
    }

    switch (in->state)
    {
        case 0:
            push_setpoint(out, 0x01);
            /* FALLTHROUGH */

        case 3:
            out->set_flag_react   = 1;
            out->flag_react_value = 0;
            push_setpoint(out, 0x04);
            /* FALLTHROUGH */

        case 4:
            out->dbg_ready = 1;

            if (in->flag_r2d == 1) {
                out->send_torque = 1;
                out->torque_zero = 1;
                out->set_flag_react   = 1;
                out->flag_react_value = 0;
            } else {
                out->set_flag_react   = 1;
                out->flag_react_value = 0;
                push_setpoint(out, 0x04);
            }
            break;

        case 6:
            out->dbg_torque    = 1;
            out->send_torque  = 1;
            out->torque_compute = 1;
            break;

        case 10:
            out->dbg_soft_fault = 1;
            push_setpoint(out, 0x13);
            /* FALLTHROUGH */

        case 11:
            out->dbg_hard_fault = 1;
            out->set_flag_react   = 1;
            out->flag_react_value = 1;
            push_setpoint(out, 13);
            /* FALLTHROUGH */

        case 13:
            out->dbg_shutdown = 1;
            push_setpoint(out, 0x01);
            break;

        default:
            break;
    }
}
