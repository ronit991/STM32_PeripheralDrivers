/******************************************************************************************************************
* 
******************************************************************************************************************/
#include "STM32F446RE.h"


/******************************************************************************************************************
* @GPIOClockControl()
* @description  - This function enables or disables peripheral clock for a particular GPIO port.
*
* @param GPIOx  - Name of the GPIO port (@ref - PERIPHERAL_GPIO_PORTS [STM32F446RE.h]) for which the clock needs to
*                 be enabled or disabled.
*
* @param enableOrDisable  - Use one of the following for this parameter (@ref - GENERAL_MACROS [STM32F446RE.h]) :
*                           ENABLE
*                           DISABLE
*
* @return       - Nothing.
******************************************************************************************************************/
void GPIOClockControl( uint8_t GPIOx, uint8_t enableOrDisable)
{
  if(enableOrDisable == ENABLE)
  {
    switch(GPIOx)
    {
      case GPIOA:     GPIOA_PCLK_EN();         return;
      case GPIOB:     GPIOB_PCLK_EN();         return;
      case GPIOC:     GPIOC_PCLK_EN();         return;
      case GPIOD:     GPIOD_PCLK_EN();         return;
      case GPIOE:     GPIOE_PCLK_EN();         return;
      case GPIOF:     GPIOF_PCLK_EN();         return;
      case GPIOG:     GPIOG_PCLK_EN();         return;
      case GPIOH:     GPIOH_PCLK_EN();         return;
    }
  }
  else
  {
    switch(GPIOx)
    {
      case GPIOA:     GPIOA_PCLK_DIS();        return;
      case GPIOB:     GPIOB_PCLK_DIS();        return;
      case GPIOC:     GPIOC_PCLK_DIS();        return;
      case GPIOD:     GPIOD_PCLK_DIS();        return;
      case GPIOE:     GPIOE_PCLK_DIS();        return;
      case GPIOF:     GPIOF_PCLK_DIS();        return;
      case GPIOG:     GPIOG_PCLK_DIS();        return;
      case GPIOH:     GPIOH_PCLK_DIS();        return;
    }
  }
}



/******************************************************************************************************************
* @GPIOInit()
* @description      -   This function initializes a GPIO pin with the given configuration.
*
* @param pin        -   Name of the GPIO pin.
*                       @ref - GPIO_PIN_NAME_ALIASES [STM32GPIOPINS.h]
*
* @param ioMode     -   Defines the input/output mode of the pin.
*                       @ref - GPIOPin_IOMode [STM32GPIODRIVER.h]

* @param outMode    -   Defines the output mode (push-pull or open drain) of the pin.
*                       @ref - GPIOPin_OutputMode [STM32GPIODRIVER.h]

* @param inMode     -   Defines the input mode (pull-up or pull-down) of the pin.
*                       @ref - GPIOPin_InputMode [STM32GPIODRIVER.h]

* @param gpioSpeed  -   Defines the speed at which output values change from 0 to 1 and vice versa.
*                       @ref - GPIOPin_OutputSpeed [STM32GPIODRIVER.h]

* @param trigger    -   Defines the trigger mode if the pin is configured to issue interrupts.
*                       @ref - GPIOPin_InterruptTrigger [STM32GPIODRIVER.h]

* @param alternateFunctionMode  -   Defines the the alternate mode in which the gpio pin need to be used.
*                                   @ref - GPIOPin_AlternateMode [STM32GPIODRIVER.h]
* @Note             -   This function should not be used while configuring a pin for alternate functions. Use the
*                       peripheral specific APIs for that purpose.
******************************************************************************************************************/

void GPIOInit(uint16_t pin, uint8_t ioMode, uint8_t outMode, uint8_t inMode, uint8_t gpioSpeed, uint8_t trigger, uint8_t alternateFunctionMode)
{
  GPIO_reg* pGPIOx = getPortAddr(pin);              // Pointer to the GPIO Port.
  uint8_t GPIOx = getPortName(pin);                 // Name of the GPIO Port.
  uint8_t pinNumber = getPinNumber(pin);            // Pin number to be configured.

  // Step 0: Enable Peripheral Clock for the GPIO Port.
  GPIOClockControl(GPIOx, ENABLE);

  // Step 1: Configure MODE Register
  pGPIOx->MODE &= ~( 0x11<<(2*pinNumber) );        // Clear the MODER register bits associated with the pin number.
  pGPIOx->MODE |= (ioMode<<(2*pinNumber) );

  // Step 2: Configure OTYPE Register
  switch(outMode)
  {
    case GPIOOutNA:       break;
    case GPIOPushPull:    pGPIOx->OTYPE ClrBit(pinNumber);    break;
    case GPIOOpenDrain:   pGPIOx->OTYPE SetBit(pinNumber);    break;

    default:              return;
  }

  // Step 3: Configure OSPEED register
  pGPIOx->OSPEED &= ~( 0x11<<(2*pinNumber) );      // Clear the OSPEEDR register bits associated with the pin.
  if(gpioSpeed != GPIOSpeedNA)
    pGPIOx->OSPEED |= ( gpioSpeed<<(2*pinNumber) );

  // Step 4: Configure PUPD register
  pGPIOx->PUPD &= ~( 0x11<<(2*pinNumber) );        // Clear the PUPDR register bits associated with the pin.
  if(inMode != GPIOInNA)
    pGPIOx->PUPD |= ( inMode<<(2*pinNumber) );

  // Step 5: Configure Alternate Function Register
  if(alternateFunctionMode != NoAlternateFunction)
  {
    uint8_t shiftAmount = 4*(pinNumber%8);
    uint8_t AFRindex = ( (pinNumber>7)?1:0 );

    pGPIOx->AFR[AFRindex] &= ~(0xF<<shiftAmount);  // Clear the AF bits associated with the pin
    pGPIOx->AFR[AFRindex] |= (alternateFunctionMode<<shiftAmount);
  }
  // All Configuration is Done.
}



/******************************************************************************************************************
* @GPIODeInit()
* @description  - Reset and Turn GPIO port.
*
* @param GPIOx  - Name of the port to be turned off.
*                 @ref - PERIPHERAL_GPIO_PORTS [STM32F446RE.h]
******************************************************************************************************************/
void GPIODeInit(void)
{

}



/******************************************************************************************************************
* @WriteToPin()
* @description  - Write a "digital" value to a GPIO pin.
*
* @param pin    - Name of the pin onto which data is to be written.
*                 @ref - GPIO_PIN_NAME_ALIASES 
*
* @param value  - Value to be written on the pin.
*                 @ref - GPIOPin_State [STM32GPIODRIVER.h]
*
* @Note         - It is assumed that the GPIO pin has been properly configured before calling this function. If it
*                 isn't, the function may generate bus fault or other errors.
******************************************************************************************************************/
void WriteToPin( uint16_t pin, uint8_t value)
{
  GPIO_reg* pGPIOx = getPortAddr(pin);              // Pointer to the GPIO Port.
  uint8_t pinNumber = getPinNumber(pin);            // Pin number to be configured.

  if(value == PIN_SET)
    pGPIOx->OD SetBit(pinNumber);
  else
    pGPIOx->OD ClrBit(pinNumber);
}



/******************************************************************************************************************
* @WriteToPort()
* @description  - Write "digital" values to a GPIO port.
*
* @param GPIOx  - Name of the port onto which data is to be written.
*                 @ref - PERIPHERAL_GPIO_PORTS [STM32F446RE.h]
*
* @param values - Values to be written on the port.
*
* @Note         - It is assumed that the GPIO pin has been properly configured before calling this function. If it
*                 isn't, the function may generate bus fault or other errors.
******************************************************************************************************************/
void WriteToPort(uint8_t GPIOx, uint16_t values)
{
  GPIO_reg* pGPIOx = getPortAddr(pin);              // Pointer to the GPIO Port.
  pGPIOx->OD |= (values<<0);
}

uint8_t ReadFromPin(uint8_t pin);
uint16_t ReadFromPort(uint8_t GPIOx);



void blinkLED(void);
