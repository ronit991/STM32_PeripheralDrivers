/**/

#ifndef STM32F446RE_H
#define STM32F446RE_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>

#define __vo    volatile
#define __reg   volatile uint32_t


/*
  Per
*/

/*
  CORE COMPONENTS
*/

//  1.1 - Base Addresses
#define FLASH_BASEADDR                0x08000000U             // Base Addr of Flash Memory
#define SRAM1_BASEADDR                0x20000000U             // Base Addr of SRAM1
#define SRAM2_BASEADDR                0x2001C000U             // Base Addr of SRAM2
#define SRAM_BASEADDR                 SRAM1_BASEADDR          // SRAM1 is the main SRAM
#define ROM_BASEADDR                  0x1FFF0000U             // Base Addr of ROM / SYSTEM MEMORY
#define SYSTEM_MEMORY_BASEADDR        ROM_BASE_ADDR           // ROM is the System Memory


#define CORE_PERIPHERAL_BASE_ADDR     0xE000E000U             // Base Addr of Core Peripherals
#define SYSTEM_CONTROL_BASE_ADDR      0x400FE000U             // Base Addr of System Control Block Register
#define NVIC_BASE_ADDR                0xE000E100U             // Base Addr of NVIC registers
#define VECTOR_TABLE_BASE_ADDR        0x00000000U             // Base Addr of Vector Table

#define PERIPH_BASEADDR               0x40000000U
#define APB1PERIPH_BASEADDR           PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR           0x40010000U
#define AHB1PERIPH_BASEADDR           0x40020000U
#define AHB2PERIPH_BASEADDR           0x50000000U

#define RCC_BASEADDR                  ( AHB1PERIPH_BASEADDR + 0x3800)
#define EXTI_BASEADDR                 ( APB2PERIPH_BASEADDR + 0x3C00)
#define SYSCFG_BASEADDR               ( APB2PERIPH_BASEADDR + 0x3800)



//  1.2 - Reset & Clock Control Block
typedef struct
{
  __reg CR;
  __reg PLLCFGR;
  __reg CFGR;
  __reg CIR;
  __reg AHB1RSTR;
  __reg AHB2RSTR;
  __reg AHB3RSTR;
  __reg Reserved1;
  __reg APB1RSTR;
  __reg APB2RSTR;
  __reg Reserved2[2];
  __reg AHB1ENR;
  __reg AHB2ENR;
  __reg AHB3ENR;
  __reg Reserved3;
  __reg APB1ENR;
  __reg APB2ENR;
  __reg Reserved4[2];
  __reg AHB1LPENR;
  __reg AHB2LPENR;
  __reg AHB3LPENR;
  __reg Reserved5;
  __reg APB1LPENR;
  __reg APB2LPENR;
  __reg Reserved6[2];
  __reg BDCR;
  __reg CSR;
  __reg Reserved7[2];
  __reg SSCGR;
  __reg PLLI2SCFGR;
  __reg PLLSAICFGR;
  __reg DCKCFGR;
  __reg CKGATENR;
  __reg DCKCFGR2;

}RCC_reg;
#define RCC ( (RCC_reg*) RCC_BASEADDR )


// 1.3 EXTI - External Interrupt Controller

typedef struct
{
  __reg IMR;
  __reg EMR;
  __reg RTSR;
  __reg FTSR;
  __reg SWIER;
  __reg PR;
}EXTI_reg;
#define EXTI ( (EXTI_reg*) EXTI_BASEADDR )

// 1.4 SYSCFG - System Configuration

typedef struct
{
  __reg MEMRMP;
  __reg PMC;
  __reg EXTICR[4];
  __reg Reserved0[2];
  __reg CMPCR;
  __reg Reserved1[2];
  __reg CFGR;
}SYSCFG_Reg;
#define SYSCFG ( (SYSCFG_reg*) SYSCFG_BASEADDR )



#ifdef __cplusplus
}
#endif

#endif