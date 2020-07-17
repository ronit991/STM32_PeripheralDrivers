/******************************************************************************************************************
* 
******************************************************************************************************************/


#ifndef STM32F446RE_H
#define STM32F446RE_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>


/******************************************************************************************************************
*                                                General Macros
* @defgroup GENERAL_MACROS
******************************************************************************************************************/

#define __vo    volatile
#define __reg   volatile uint32_t

#define SetBit(x) |= (1<<x)
#define ClrBit(x) &= ~(1<<x)
#define GetBit(reg,bit) ( (reg & (1<<bit))?1:0 )

#define ENABLE      1
#define DISABLE     0



/******************************************************************************************************************
*                                        Base Addresses of Core Components
******************************************************************************************************************/

#define FLASH_BASEADDR                0x08000000U             // Base Addr of Flash Memory
#define SRAM1_BASEADDR                0x20000000U             // Base Addr of SRAM1
#define SRAM2_BASEADDR                0x2001C000U             // Base Addr of SRAM2
#define SRAM_BASEADDR                 SRAM1_BASEADDR          // SRAM1 is the main SRAM
#define ROM_BASEADDR                  0x1FFF0000U             // Base Addr of ROM / SYSTEM MEMORY
#define SYSTEM_MEMORY_BASEADDR        ROM_BASE_ADDR           // ROM is the System Memory

#define PERIPH_BASEADDR               0x40000000U
#define APB1PERIPH_BASEADDR           PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR           0x40010000U
#define AHB1PERIPH_BASEADDR           0x40020000U
#define AHB2PERIPH_BASEADDR           0x50000000U

#define RCC_BASEADDR                  ( AHB1PERIPH_BASEADDR + 0x3800)
#define EXTI_BASEADDR                 ( APB2PERIPH_BASEADDR + 0x3C00)
#define SYSCFG_BASEADDR               ( APB2PERIPH_BASEADDR + 0x3800)



/******************************************************************************************************************
*                                        RCC: Reset & Clock Control Block
******************************************************************************************************************/

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

//  Bit Position Alias for RCC Registers - AHB1 Peripherals

#define RCC_GPIOA         0
#define RCC_GPIOB         1
#define RCC_GPIOC         2
#define RCC_GPIOD         3
#define RCC_GPIOE         4
#define RCC_GPIOF         5
#define RCC_GPIOG         6
#define RCC_GPIOH         7
#define RCC_CRC           12
#define RCC_BPK_SRAM      18
#define RCC_DMA1          21
#define RCC_DMA2          22
#define RCC_OTGHS         29
#define RCC_OTGHS_ULPI    30

//  Bit Position Alias for RCC Registers - AHB2 Peripherals

#define RCC_DCMI          0
#define RCC_OTGFS         7

//  Bit Position Alias for RCC Registers - AHB3 Peripherals

#define RCC_FMC           0
#define RCC_QSPI          1

//  Bit Position Alias for RCC Registers - APB1 Peripherals

#define RCC_TIM2          0
#define RCC_TIM3          1
#define RCC_TIM4          2
#define RCC_TIM5          3
#define RCC_TIM6          4
#define RCC_TIM7          5
#define RCC_TIM12         6
#define RCC_TIM13         7
#define RCC_TIM14         8
#define RCC_WWDG          11
#define RCC_SPI2          14
#define RCC_SPI3          15
#define RCC_SPDIFRX       16
#define RCC_USART2        17
#define RCC_USART3        18
#define RCC_UART4         19
#define RCC_UART5         20
#define RCC_I2C1          21
#define RCC_I2C2          22
#define RCC_I2C3          23
#define RCC_FMPI2C1       24
#define RCC_CAN1          25
#define RCC_CAN2          26
#define RCC_CEC           27
#define RCC_PWR           28
#define RCC_DAC           29

//  Bit Position Alias for RCC Registers - APB2 Peripherals

#define RCC_TIM1          0
#define RCC_TIM8          1
#define RCC_USART1        4
#define RCC_USART6        5
#define RCC_ADC1          8
#define RCC_ADC2          9
#define RCC_ADC3          10
#define RCC_SDIO          11
#define RCC_SPI1          12
#define RCC_SPI4          13
#define RCC_SYSCFG        14
#define RCC_TIM9          16
#define RCC_TIM10         17
#define RCC_TIM11         28
#define RCC_SAI1          22
#define RCC_SAI2          23



/******************************************************************************************************************
*                                    NVIC - Nested Vector Interrupt Controller
******************************************************************************************************************/
#define NVICISER0ADDR     0xE000E100
#define NVICISER1ADDR     0xE000E104
#define NVICISER2ADDR     0xE000E108

#define NVICICER0ADDR     0xE000E180
#define NVICICER1ADDR     0xE000E184
#define NVICICER2ADDR     0xE000E188

#define NVICISPR0ADDR     0xE000E200
#define NVICISPR1ADDR     0xE000E204
#define NVICISPR2ADDR     0xE000E208

#define NVICICPR0ADDR     0xE000E280
#define NVICICPR1ADDR     0xE000E284
#define NVICICPR2ADDR     0xE000E288

#define NVICIABR0ADDR     0xE000E300
#define NVICIABR1ADDR     0xE000E304
#define NVICIABR2ADDR     0xE000E308

#define NVICIPR0ADDR      0xE000E400
#define NVICIPR1ADDR      0xE000E404
#define NVICIPR2ADDR      0xE000E408

#define NVICSTIRADDR      0xE000EF00


#define NVIC_ISER0        ( (__reg*) NVICISER0ADDR )
#define NVIC_ISER1        ( (__reg*) NVICISER1ADDR )
#define NVIC_ISER2        ( (__reg*) NVICISER2ADDR )

#define NVIC_ICER0        *( (__reg*) NVICICER0ADDR )
#define NVIC_ICER1        *( (__reg*) NVICICER1ADDR )
#define NVIC_ICER2        *( (__reg*) NVICICER2ADDR )

#define NVIC_ISPR0        *( (__reg*) NVICISPR0ADDR )
#define NVIC_ISPR1        *( (__reg*) NVICISPR1ADDR )
#define NVIC_ISPR2        *( (__reg*) NVICISPR2ADDR )

#define NVIC_ICPR0        *( (__reg*) NVICICPR0ADDR )
#define NVIC_ICPR1        *( (__reg*) NVICICPR1ADDR )
#define NVIC_ICPR2        *( (__reg*) NVICICPR2ADDR )

#define NVIC_IABR0        *( (__reg*) NVICIABR0ADDR )
#define NVIC_IABR1        *( (__reg*) NVICIABR1ADDR )
#define NVIC_IABR2        *( (__reg*) NVICIABR2ADDR )

#define NVIC_IPR0         *( (__reg*) NVICIPR0ADDR )
#define NVIC_IPR1         *( (__reg*) NVICIPR1ADDR )
#define NVIC_IPR2         *( (__reg*) NVICIPR2ADDR )
#define NVIC_STIR         *( (__reg*) NVICSTIRADDR )



/******************************************************************************************************************
*                                      EXTI - External Interrupt Controller
******************************************************************************************************************/

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



/******************************************************************************************************************
*                                          SYSCFG - System Configuration
******************************************************************************************************************/

typedef struct
{
  __reg MEMRMP;
  __reg PMC;
  __reg EXTICR[4];
  __reg Reserved0[2];
  __reg CMPCR;
  __reg Reserved1[2];
  __reg CFGR;
}SYSCFG_reg;

#define SYSCFG_CLK_EN()       ( RCC->APB2ENR SetBit(RCC_SYSCFG) )
#define SYSCFG_CLK_DIS()      ( RCC->APB2ENR ClrBit(RCC_SYSCFG) )

#define SYSCFG                ( (SYSCFG_reg*) SYSCFG_BASEADDR )



/******************************************************************************************************************
*                                                Peripheral Names
******************************************************************************************************************/

// @defgroup PERIPHERAL_GPIO_PORTS
#define GPIOA         10
#define GPIOB         11
#define GPIOC         12
#define GPIOD         13
#define GPIOE         14
#define GPIOF         15
#define GPIOG         16
#define GPIOH         17




/******************************************************************************************************************
*                                           Driver & Other Dependencies
******************************************************************************************************************/

#include "STM32GPIODRIVER.h"
#include "STM32GPIOPINS.h"


#ifdef __cplusplus
}
#endif

#endif
