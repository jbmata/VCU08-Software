#include "can_service.h"

/*
 * Estas funciones YA existen hoy
 * (HAL_FDCAN, colas, etc.)
 */
extern bool can_send_raw(uint32_t id, const uint8_t *data, uint8_t dlc);
extern bool can_receive_raw(uint32_t *id, uint8_t *data, uint8_t *dlc);

void can_service_init(void)
{
    /* nada por ahora */
}

bool can_service_send(const can_frame_t *frame)
{
    if (!frame) return false;

    return can_send_raw(frame->id, frame->data, frame->dlc);
}

bool can_service_receive(can_frame_t *frame)
{
    if (!frame) return false;

    return can_receive_raw(&frame->id, frame->data, &frame->dlc);
}
