/***
* 96 IRQ
* 12 Exceprion
* 1 MSP
* Total 109x4 == 436 bytes
***/
#include "../include/sys/stm32_startup.h"
uint32_t g_tick_count = 0;
void Reset_Handler(void){
	uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
	uint8_t *pDst = (uint8_t*)&_sdata;
	uint8_t *pSrc = (uint8_t*)&_la_data;
	for(uint32_t i=0;i<size;i++){
		*pDst++ = *pSrc++;
	}
	size = (uint32_t)&_ebss - (uint32_t)&_sbss;
	pDst = (uint8_t*)&_sbss;
	for(uint32_t i=0;i<size;i++){
		*pDst++ = 0;
	}
	_text_size = (uint32_t)&_etext - (uint32_t)&_stext;
	_data_size = (uint32_t)&_edata - (uint32_t)&_sdata;
	_bss_size = (uint32_t)&_ebss - (uint32_t)&_sbss;
	kmain();
}
void Default_Handler(void){
	while(1);
}
void  SysTick_Handler(void)
{

	uint32_t *pICSR = (uint32_t*)0xE000ED04;

    update_global_tick_count();

    //unblock_tasks();

    //pend the pendsv exception
    *pICSR |= ( 1 << 28);
}

//2. implement the fault handlers
void HardFault_Handler(void)
{
//	printf("Exception : Hardfault\n");
	while(1);
}


void MemManage_Handler(void)
{
//	printf("Exception : MemManage\n");
	while(1);
}

void BusFault_Handler(void)
{
//	printf("Exception : BusFault\n");
	while(1);
}

void update_global_tick_count(void)
{
	g_tick_count++;
}
