#include "torque.h"
#include "../safety/safety.h"
#include <stdlib.h> // abs()

static int clamp_int(int v, int lo, int hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

void torque_step(const app_inputs_t *in, app_state_t *st, app_outputs_t *out)
{
    // 1) Convert raw sensors to percent (keep formulas aligned with legacy code)
    int s1_pct = (int)((in->accel1_raw - 2050) / (29.5 - 20.5));
    int s2_pct = (int)((in->accel2_raw - 1915) / (25.70 - 19.15));

    s1_pct = clamp_int(s1_pct, 0, 100);
    s2_pct = clamp_int(s2_pct, 0, 100);

    // 2) Average if both above small threshold
    int torque_total;
    if (s1_pct > 8 && s2_pct > 8) {
        torque_total = (s1_pct + s2_pct) / 2;
    } else {
        torque_total = 0;
    }

    // 3) Deadband and saturation (preserve behavior)
    if (torque_total < 10) {
        torque_total = 0;
    } else if (torque_total > 90) {
        torque_total = 100;
    }

    // 4) Safety checks may latch flags and force torque to zero
    safety_ev23(in, st, &torque_total);
    safety_t1189(in, st, s1_pct, s2_pct, &torque_total);

    // 5) Battery limitation (preserve legacy behavior; ensure aligns with your main(2).c)
    if (in->v_cell_min < 3500.0f) {
        if (in->v_cell_min > 2800.0f) {
            torque_total = (int)(torque_total * (1.357f * in->v_cell_min - 3750.0f) / 1000.0f);
        } else {
            torque_total = (int)(torque_total * 0.05f);
        }
    }

    // Clamp again after scaling (defensive; keep 0..100)
    torque_total = clamp_int(torque_total, 0, 100);

    // 6) Legacy scaling + two's complement for inverter command
    int scaled = torque_total;
    if (scaled >= 10) {
        scaled = (scaled * 240 / 90 - 2400 / 90);
    }

    uint16_t c1 = (uint16_t)(~((uint16_t)scaled));
    out->torque_cmd = (uint16_t)(c1 + 1u);

    out->torque_pct = (uint8_t)torque_total;
    out->flag_ev23  = st->flag_ev23;
    out->flag_t1189 = st->flag_t1189;
}
