#ifndef CAN_SERVICE_H
#define CAN_SERVICE_H

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    uint32_t id;
    uint8_t  dlc;
    uint8_t  data[8];
} can_frame_t;

void can_service_init(void);

/* envío */
bool can_service_send(const can_frame_t *frame);

/* recepción (si ya lo tienes implementado) */
bool can_service_receive(can_frame_t *frame);

#endif
