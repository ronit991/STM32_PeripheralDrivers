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
    __reg AFRL;             // Alternate function - Low
    __reg AFRH;             // Alternate function - High
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
*                                                    Driver APIs
******************************************************************************************************************/
