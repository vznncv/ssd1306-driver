#include "lv_mbed_tick_port.h"

#include "mbed.h"
#include <chrono>

uint32_t lv_mbed_tick_get()
{
    Kernel::Clock::time_point tp = Kernel::Clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch()).count();
}
