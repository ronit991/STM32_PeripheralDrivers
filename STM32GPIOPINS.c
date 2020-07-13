/******************************************************************************************************************
* This file contains the name & address resolver functions for the GPIO pins of STM32F446RE microcontroller.
******************************************************************************************************************/


#include "STM32F446RE.h"



/******************************************************************************************************************
* @getPortName()
*
* @param pin - Name of a GPIO pin (@ref - GPIO_PIN_NAME_ALIASES [STM32GPIOPINS.h]).
*
* @return - Name of the GPIO port on which the pin is present.
******************************************************************************************************************/
uint8_t getPortName(uint16_t pin)
{
  uint8_t GPIOx = pin/100;
  return GPIOx;

  /* Pin name aliases are assigned values in the format "XXNN". XX represents port# (@ref - PERIPHERAL_GPIO_PORTS [STM32F446RE.h])
   * Ex: PC5 has value 1205 - 12 for GPIOC & 05 for pin num 5.
   * Dividing the pin argument value by 100 gives us the first two digits of the value representing the GPIO port.
   */
}



/******************************************************************************************************************
* @getPinNumber()
* 
* @param pin - Name of a GPIO pin (@ref - GPIO_PIN_NAME_ALIASES [STM32GPIOPINS.h]).
*
* @return - Pin Number (Ex: 5 for PA5, 13 for PF13 etc.).
******************************************************************************************************************/
uint8_t getPinNumber(uint16_t pin)
{
  uint8_t pinNum = pin%100;
  return pinNum;
  /* Pin name aliases are assigned values in the format "X0NN", where NN represents the pin number.
   * Ex: PC5 has value 3005 - 3 for GPIOC & 05 for pin num 5.
   * Dividing the pin argument value by 100 & taking the remainder gives us the last two digits of the value i.e. the
   * pin number.
   */
}



/******************************************************************************************************************
* @getPortAddr()
* @description - This function takes a "pin name" or "port name" as an argument and returns the pointer to the
*                associated GPIO Port Registers.
*
* @param pinOrPort - Name of a GPIO pin (@ref - GPIO_PIN_NAME_ALIASES [STM32GPIOPINS.h]) or GPIO port
*                    (@ref - PERIPHERAL_GPIO_PORTS [STM32F446RE.h]).
*
* @return          - Pointer to the GPIO registers.
******************************************************************************************************************/

GPIO_reg* getPortAddr(uint16_t pinOrPort)
{
  uint8_t GPIOPortName = 0;
  if(pinOrPort > 999)                       // If true => A pin name is given to the function.
  {
    GPIOPortName = (pin/100);               // Get port name from the pin number.
    // For explanation of the above expression, see getPortName() function definition in this file.
  }
  else                                      // If false => A port name is given to the function
  {
    GPIOPortName = pinOrPort;
  }
  

  switch(GPIOPortName)
  {
    case GPIOA:         return pGPIOA;
    case GPIOB:         return pGPIOB;
    case GPIOC:         return pGPIOC;
    case GPIOD:         return pGPIOD;
    case GPIOE:         return pGPIOE;
    case GPIOF:         return pGPIOF;
    case GPIOG:         return pGPIOG;
    case GPIOH:         return pGPIOH;
  }

  // In case an invalid argument is passed to this function, it returns pointer to GPIOA by default.
  return pGPIOA;
}
