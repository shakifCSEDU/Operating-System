#include "../include/dev/clock.h"
void DRV_CLOCK_INIT()
{
RCC->CR |= 1<<16; // set CR bit 16 
/** Check if clock is ready RCC CR register 17th bit set*/ 
while(!(RCC->CR & 1<<17)); //wait for the clock is enabled See RCC CR bit-17; HSE crystal is On
/* Set the POWER enable CLOCK and VOLTAGE REGULATOR */
RCC->APB1ENR |= 1<<28; //power enable for APB1
PWR->CR |= 3<<14; // PWR_CR_VOS; //VOS always correspond to reset value 

/*3. Configure the FLASH PREFETCH and the LATENCY Related Settings */
FLASH->ACR |= 1<<9 | 1<<10 | 1<<8 | 5<<0; //ICEN -- instruction cache, DCEN -- Data Cache, PRFTEN -- prefetch and LAtency;

/* 4. Configure the PRESCALERS HCLK, PCLK1, PCLK2 */
//AHB prescaler 
RCC->CFGR |= 0<<4;
//APB1 prescaler
RCC->CFGR |= 5<<10;
//APB2 prescaler
RCC->CFGR |= 4<<13;
//5. Configugure the main PLL
RCC->PLLCFGR = (PLL_M<<0) | (PLL_N<<6) | (PLL_P<<16) | (1<<22); 
//6. Enable PLL and wait for it to become ready
RCC->CR |= 1<<24;
//Check if PLL clock is ready
while(!(RCC->CR & 1<<25))
	; //wait for PLL ready
//7. Select clock source and wait for it to be set
	RCC->CFGR |= 2<<0;
while((RCC->CFGR & 2<<2) != 2<<2);
}


