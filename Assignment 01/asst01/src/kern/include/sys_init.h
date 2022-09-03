#ifndef __SYS_INIT_H
#define __SYS_INIT_H
#include <stdint.h>
void __sys_init(void); 


typedef struct {
  uint32_t CPUID;
  uint32_t ICSR;
  uint32_t VTOR;
  uint32_t AIRCR;
  uint32_t SCR;
  uint32_t CCR;
  uint32_t SHPR1;
  uint32_t SHPR2;
  uint32_t SHPR3;
  uint32_t SHCSR;
  uint32_t CFSR;
  uint32_t HFSR;
  uint32_t MMAR;
  uint32_t BFAR;
  uint32_t AFSR;
  uint8_t reserved[76];
  uint32_t CPACR;
}SCB_type;
#define SCB ((SCB_type *) 0xE000ED00 ) 
void DRV_FPU_ACTIVE(void);

#endif /* SYS_INIT */

