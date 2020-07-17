

#ifndef STM32GPIODRIVER_H
#define STM32GPIODRIVER_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "STM32F446RE.h"

/******************************************************************************************************************
*                                                Base Addresses
******************************************************************************************************************/

#define GPIO_BASE         AHB1PERIPH_BASEADDR
#define GPIOA_BASEADDR    (GPIO_BASE + 0x0000)
#define GPIOB_BASEADDR    (GPIO_BASE + 0x0400)
#define GPIOC_BASEADDR    (GPIO_BASE + 0x0800)
#define GPIOD_BASEADDR    (GPIO_BASE + 0x0C00)
#define GPIOE_BASEADDR    (GPIO_BASE + 0x1000)
#define GPIOF_BASEADDR    (GPIO_BASE + 0x1400)
#define GPIOG_BASEADDR    (GPIO_BASE + 0x1800)
#define GPIOH_BASEADDR    (GPIO_BASE + 0x1C00)



/******************************************************************************************************************
*                                          Clock Enable & Disable Macros
******************************************************************************************************************/

#define GPIOA_PCLK_EN() ( RCC->AHB1ENR SetBit(RCC_GPIOA) )
#define GPIOB_PCLK_EN() ( RCC->AHB1ENR SetBit(RCC_GPIOB) )
#define GPIOC_PCLK_EN() ( RCC->AHB1ENR SetBit(RCC_GPIOC) )
#define GPIOD_PCLK_EN() ( RCC->AHB1ENR SetBit(RCC_GPIOD) )
#define GPIOE_PCLK_EN() ( RCC->AHB1ENR SetBit(RCC_GPIOE) )
#define GPIOF_PCLK_EN() ( RCC->AHB1ENR SetBit(RCC_GPIOF) )
#define GPIOG_PCLK_EN() ( RCC->AHB1ENR SetBit(RCC_GPIOG) )
#define GPIOH_PCLK_EN() ( RCC->AHB1ENR SetBit(RCC_GPIOH) )

#define GPIOA_PCLK_DIS() ( RCC->AHB1ENR ClrBit(RCC_GPIOA) )
#define GPIOB_PCLK_DIS() ( RCC->AHB1ENR ClrBit(RCC_GPIOB) )
#define GPIOC_PCLK_DIS() ( RCC->AHB1ENR ClrBit(RCC_GPIOC) )
#define GPIOD_PCLK_DIS() ( RCC->AHB1ENR ClrBit(RCC_GPIOD) )
#define GPIOE_PCLK_DIS() ( RCC->AHB1ENR ClrBit(RCC_GPIOE) )
#define GPIOF_PCLK_DIS() ( RCC->AHB1ENR ClrBit(RCC_GPIOF) )
#define GPIOG_PCLK_DIS() ( RCC->AHB1ENR ClrBit(RCC_GPIOG) )
#define GPIOH_PCLK_DIS() ( RCC->AHB1ENR ClrBit(RCC_GPIOH) )



/******************************************************************************************************************
*                                               Register Definition
******************************************************************************************************************/

typedef struct
{
    __reg MODE;             // Port Mode
    __reg OTYPE;            // Output Type (Push-Pull, Open-Drain)
    __reg OSPEED;           // Output speed
    __reg PUPD;             // Pull Up - Pull Down
    __reg ID;               // Input Data
    __reg OD;               // Output Data
    __reg BSR;              // Bit Set/Reset
    __reg LCK;              // Lock
    __reg AFR[2];           // Alternate function - Low & High
}GPIO_reg;



/******************************************************************************************************************
*                                             Module Access Pointers
******************************************************************************************************************/

#define pGPIOA ( (GPIO_reg*) GPIOA_BASEADDR )
#define pGPIOB ( (GPIO_reg*) GPIOB_BASEADDR )
#define pGPIOC ( (GPIO_reg*) GPIOC_BASEADDR )
#define pGPIOD ( (GPIO_reg*) GPIOD_BASEADDR )
#define pGPIOE ( (GPIO_reg*) GPIOE_BASEADDR )
#define pGPIOF ( (GPIO_reg*) GPIOF_BASEADDR )
#define pGPIOG ( (GPIO_reg*) GPIOG_BASEADDR )
#define pGPIOH ( (GPIO_reg*) GPIOH_BASEADDR )



/******************************************************************************************************************
*                                           API  STD Parameter Values
******************************************************************************************************************/

// @defgroup GPIOPin_IOMode
#define GPIODigitalIn         0b00
#define GPIODigitalOut        0b01
#define GPIOAlternateFn       0b10
#define GPIOAnalog            0b11

// @defgroup GPIOPin_OutputMode
#define GPIOPushPull          0b00
#define GPIOOpenDrain         0b01
#define GPIOOutNA             0b10

// @defgroup GPIOPin_InputMode
#define GPIOPullUp            0b01
#define GPIOPullDown          0b10
#define GPIOInNA              0b00

// @defgroup GPIOPin_OutputSpeed
#define GPIOLowSpeed          0b000
#define GPIOMediumSpeed       0b001
#define GPIOFastSpeed         0b010
#define GPIOHighSpeed         0b011
#define GPIOSpeedNA           0b100

// @defgroup GPIOPin_InterruptTrigger
#define GPIOIntrRisingEdge    0x01
#define GPIOIntrFallingEdge   0x10
#define GPIOIntrBothEdges     0x11
#define GPIONoIntr            0xFF

// @defgroup GPIOPin_AlternateMode
#define GPIOAltFn0            0b0000
#define GPIOAltFn1            0b0001
#define GPIOAltFn2            0b0010
#define GPIOAltFn3            0b0011
#define GPIOAltFn4            0b0100
#define GPIOAltFn5            0b0101
#define GPIOAltFn6            0b0110
#define GPIOAltFn7            0b0111
#define GPIOAltFn8            0b1000
#define GPIOAltFn9            0b1001
#define GPIOAltFn10           0b1010
#define GPIOAltFn11           0b1011
#define GPIOAltFn12           0b1100
#define GPIOAltFn13           0b1101
#define GPIOAltFn14           0b1110
#define GPIOAltFn15           0b1111
#define NoAlternateFunction   0xFF

// @defgroup GPIOPin_State
#define PIN_SET               1
#define PIN_CLR               0

// @defgroup LED_Blink_Speed
#define LEDblinkSpeed_Low     1000000
#define LEDblinkSpeed_Medium  500000
#define LEDblinkSpeed_Fast    100000

/******************************************************************************************************************
*                                                    Driver APIs
******************************************************************************************************************/

void GPIOClockControl( uint8_t GPIOx, uint8_t enableOrDisable);
void GPIOInit(uint16_t pin, uint8_t ioMode, uint8_t outMode, uint8_t inMode, uint8_t gpioSpeed, uint8_t trigger, uint8_t alternateFunctionMode);
void GPIODeInit(uint8_t GPIOx);

void WriteToPin( uint16_t pin, uint8_t value);
void WriteToPort(uint8_t GPIOx, uint16_t values);

uint8_t ReadFromPin(uint16_t pin);
uint16_t ReadFromPort(uint8_t GPIOx);

void ToggleGPIOPin(uint16_t pin);

void useLEDandButtons(uint8_t trigger);
void blinkLED(uint32_t count, uint32_t blinkTime);

void GPIOClearInterrupt(uint16_t pin);


#ifdef __cplusplus
}
#endif

#endif
