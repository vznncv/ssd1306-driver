#include "lv_mbed_ticker_port.h"

#include "hal/lp_ticker_api.h"

#ifndef DEVICE_LPTICKER
#error "LittlevGL tick internface isn't implemented for devices without low power ticker"
#endif

static const ticker_data_t *lp_ticker = NULL;

uint32_t lv_mbed_tick_get()
{
    if (NULL == lp_ticker) {
        lp_ticker = get_lp_ticker_data();
    }
    return ticker_read_us(lp_ticker) / 1000;
}
