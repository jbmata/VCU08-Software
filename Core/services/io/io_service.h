#ifndef IO_SERVICE_H
#define IO_SERVICE_H

#include "inputs.h"

/* Inicialización (vacía por ahora) */
void io_service_init(void);

/* Construye los inputs de app */
void io_service_get_app_inputs(app_inputs_t *inputs);

#endif
