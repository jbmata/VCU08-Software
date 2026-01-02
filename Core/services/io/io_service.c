#include "io_service.h"

/*
 * ESTA función ya existe hoy en tu main.c
 * o en un módulo auxiliar.
 * No se mueve todavía.
 */
extern void build_app_inputs(app_inputs_t *inputs);

void io_service_init(void)
{
    /* nada por ahora */
}

void io_service_get_app_inputs(app_inputs_t *inputs)
{
    if (!inputs) return;

    /* delega exactamente en lo que ya había */
    build_app_inputs(inputs);
}
