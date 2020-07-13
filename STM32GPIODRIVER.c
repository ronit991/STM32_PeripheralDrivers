/******************************************************************************************************************
* 
******************************************************************************************************************/
#include "STM32F446RE.h"


/******************************************************************************************************************
* @GPIOClockControl()
* @description  - This function enables or disables peripheral clock for a particular GPIO port.
*
* @param GPIOx  - Name of the GPIO port for which the clock needs to be enabled or disabled.
*                 @ref - PERIPHERAL_GPIO_PORTS [STM32F446RE.h]
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
* @param ioMode     -   Defines the input/output mode of the pin (Digital In/Out, Analog, AltFn).
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
*
* @return           - Nothing.
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
* @description  - Reset and Turn off a GPIO port.
*
* @param GPIOx  - Name of the port to be turned off.
*                 @ref - PERIPHERAL_GPIO_PORTS [STM32F446RE.h]
******************************************************************************************************************/
void GPIODeInit(uint8_t GPIOx)
{
  uint8_t PortNum = (GPIOx - 10);         // Port Number (0 - A, 1 - B, ... 7 - H)
  RCC->AHB1RSTR SetBit(PortNum);          // Set the GPIOx bit in the AH1 Reset Register.
  RCC->AHB1RSTR ClrBit(PortNum);          // Clear the bit so that the port registers don't always remain in reset state.

  GPIOClockControl(GPIOx, DISABLE);       // Disable the clock to the port.
}



/******************************************************************************************************************
* @WriteToPin()
* @description  - Write a "digital" value to a GPIO pin.
*
* @param pin    - Name of the pin onto which data is to be written.
*                 @ref - GPIO_PIN_NAME_ALIASES [STM32GPIOPINS.h]
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
  uint8_t pinNumber = getPinNumber(pin);            // Pin number.

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
* @Note         - It is assumed that the GPIO pins have been properly configured before calling this function. If
*                 they aren't, the function may generate bus fault or other errors.
******************************************************************************************************************/
void WriteToPort(uint8_t GPIOx, uint16_t values)
{
  GPIO_reg* pGPIOx = getPortAddr(pin);              // Pointer to the GPIO Port.
  pGPIOx->OD |= (values<<0);
}



/******************************************************************************************************************
* @ReadFromPin()
* @description  - Read a "digital" value from a GPIO pin.
*
* @param pin    - Name of the pin to be read. @ref - GPIO_PIN_NAME_ALIASES [STM32GPIOPINS.h]
*
* @return       - Pin State. @ref - GPIOPin_State [STM32GPIODRIVER.h]
*
* @Note         - It is assumed that the GPIO pin has been properly configured before calling this function. If it
*                 isn't, the function may generate bus fault or other errors.
******************************************************************************************************************/
uint8_t ReadFromPin(uint8_t pin)
{
  GPIO_reg* pGPIOx = getPortAddr(pin);              // Pointer to the GPIO Port.
  uint8_t pinNumber = getPinNumber(pin);            // Pin number.

  uint8_t PinState = GetBit( pGPIOx->ID, pinNumber );

  return PinState;
}



/******************************************************************************************************************
* @ReadFromPort()
* @description  - Read "digital" values from a GPIO port.
*
* @param GPIOx  - Name of the port to be read. @ref - PERIPHERAL_GPIO_PORTS [STM32F446RE.h]
*
* @return       - State of pins on the port.
*
* @Note         - It is assumed that the GPIO pins have been properly configured before calling this function. If
*                 they aren't, the function may generate bus fault or other errors.
******************************************************************************************************************/
uint16_t ReadFromPort(uint8_t GPIOx)
{
  GPIO_reg* pGPIOx = getPortAddr(pin);              // Pointer to the GPIO Port.
  uint16_t portValues = (pGPIOx->ID &= 0x0000FFFF);

  return portValues;
}



/******************************************************************************************************************
* @ToggleGPIOPin()
* @description  - Toggle a GPIO pin.
*
* @param pin    - Name of the pin to be toggled. @ref - GPIO_PIN_NAME_ALIASES [STM32GPIOPINS.h]
*
* @return       - Nothing.
*
* @Note         - It is assumed that the GPIO pin has been properly configured before calling this function. If it
*                 isn't, the function may generate bus fault or other errors.
******************************************************************************************************************/
void ToggleGPIOPin(uint8_t pin)
{
  GPIO_reg* pGPIOx = getPortAddr(pin);              // Pointer to the GPIO Port.
  uint8_t pinNumber = getPinNumber(pin);            // Pin number.

  pGPIOx->OD ^= (1<<pinNumber);
}



/******************************************************************************************************************
* @useLEDandButtons()
* @description     - Configures the User LED and Button on the Nucleo Board. @ref - NUCLEO_BOARD [STM32GPIOPINS.h]
*
* @return          - Nothing.
******************************************************************************************************************/
void useLEDandButtons(void)
{
  // Configure User LED
  GPIOInit(USER_LED0, GPIODigitalOut, GPIOPushPull, GPIOInNA, GPIOLowSpeed, GPIONoIntr, NoAlternateFunction);
  // Configure User Button
  GPIOInit(USER_SW0, GPIODigitalIn, GPIOOutNA, GPIOPullUp, GPIOLowSpeed, GPIONoIntr, NoAlternateFunction);
}



/******************************************************************************************************************
* @blinkLED()
* @description     - Blink the on-board LED. @ref - NUCLEO_BOARD [STM32GPIOPINS.h]
*
* @param count     - No. of times the LED needs to be blinked.
*
* @param blinkTime - Delay between the toggling of LED. @ref - LED_Blink_Speed [STM32GPIODRIVER.h]
*
* @return          - Nothing.
*
* @Note            - It is assumed that the on-board LED has been properly configured before calling this function.
*                    If it isn't, the function may generate bus fault or other errors.
******************************************************************************************************************/
void blinkLED(uint32_t count, uint32_t blinkTime)
{
  for(int i = 0; i < (2*count); i++)
  {
    ToggleGPIOPin(USER_LED0);
    for(int j = 0; j<blinkTime; j++);
  }
}
