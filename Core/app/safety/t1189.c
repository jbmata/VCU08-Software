#include "safety.h"
#include <stdlib.h>

#ifndef APP_APS_DIFF_THRESHOLD_T1189
#define APP_APS_DIFF_THRESHOLD_T1189 10
#endif

void safety_t1189(const app_inputs_t *in, app_state_t *st, int s1_pct, int s2_pct, int *torque)
{
    if (abs(s1_pct - s2_pct) > APP_APS_DIFF_THRESHOLD_T1189) {
        st->flag_t1189 = 1;
    } else {
        st->flag_t1189 = 0;
        st->last_time_t1189 = in->now_ms;
    }

    if (st->flag_t1189) {
        *torque = 0;
    }
}
