#include "safety.h"

/**
 * NOTE: Keep this threshold identical to your current firmware to preserve behavior.
 * If your project already defines a brake threshold macro, you can override this
 * by defining APP_BRAKE_THRESHOLD_EV23 before including this module.
 */
#ifndef APP_BRAKE_THRESHOLD_EV23
#define APP_BRAKE_THRESHOLD_EV23 900
#endif

void safety_ev23(const app_inputs_t *in, app_state_t *st, int *torque)
{
    // Latch behavior preserved from the original main(2).c logic.
    if (in->brake_raw > APP_BRAKE_THRESHOLD_EV23 && (*torque) > 25) {
        st->flag_ev23 = 1;
    } else if (in->brake_raw < APP_BRAKE_THRESHOLD_EV23 && (*torque) < 5) {
        st->flag_ev23 = 0;
    }

    if (st->flag_ev23) {
        *torque = 0;
    }
}
