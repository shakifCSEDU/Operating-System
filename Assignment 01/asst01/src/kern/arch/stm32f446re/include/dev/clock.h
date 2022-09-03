#ifndef __CLOCK_H
#define __CLOCK_H 
#include "../sys/stm32_peps.h"
#define PLL_M 4
#define PLL_N 180
#define PLL_P 0 
void DRV_CLOCK_INIT(void);
#endif
