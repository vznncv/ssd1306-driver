#ifndef LV_MBED_TICKER_PORT_H
#define LV_MBED_TICKER_PORT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Mbed system timer wrapper for LittlevGL.
 */
uint32_t lv_mbed_tick_get();

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // LV_MBED_TICKER_PORT_H
