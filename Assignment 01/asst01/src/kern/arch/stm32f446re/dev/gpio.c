#include "../include/dev/gpio.h"
void DRV_GPIO_INIT(GPIO_TypeDef* gpio)
{
gpio->MODER |= 1<<0;	
}


