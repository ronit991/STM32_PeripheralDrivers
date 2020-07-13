/******************************************************************************************************************
* This file contains the name & address resolver functions for the GPIO pins of STM32F446RE microcontroller.
******************************************************************************************************************/


#include "STM32F446RE.h"



/******************************************************************************************************************
* @getPortAddr()
* @description - This function takes a "pin name" or "port name" as an argument and returns the pointer to the
* associated GPIO Port Registers.
*
* @param pinOrPort - Name of a GPIO pin (@ref - GPIO_PIN_NAME_ALIASES) or GPIO port (@ref - PERIPHERAL_GPIO_PORTS).
*
* @return - Pointer to the GPIO registers.
******************************************************************************************************************/

GPIO_reg* getPortAddr(uint16_t pinOrPort)
{
  uint8_t GPIOPortName = 0;
  if(pinOrPort > 999)                       // If true => A pin name is given to the function.
  {
    GPIOPortName = (pinOrPort/1000 + 9);    // Extract port name from the pin number.
    // For explanation of the above expression, see getPortName() function definition in this file.
  }
  else                                      // A port name is given to the function
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



/******************************************************************************************************************
* @getPortName()
*
* @param pin - Name of a GPIO pin (@ref - GPIO_PIN_NAME_ALIASES).
*
* @return - Name of the GPIO port on which the pin is present.
******************************************************************************************************************/
uint8_t getPortName(uint16_t pin)
{
  uint16_t a = pin/1000;
  
  return (a + 9);

  // All pin name aliases are assigned values in the format - X0NN. X represents port number in the
  // order (1-A, 2-B, ... 8-H). Dividing the pin argument value by 1000 gives us the first digit of
  // the value i.e. the port number. GPIO Port Names (defined in the Peripheral Name macros section
  // in STM32F446RE.h file) use values starting from 10 (10-GPIOA, 11-GPIOB, ... 17-GPIOH). Adding 9
  // to the port number results in the same values defined by GPIOx macros. Hence the expression (9+
  // pin/1000) gives us the port name.
}



/******************************************************************************************************************
* @getPinNumber()
* 
* @param pin - Name of a GPIO pin (@ref - GPIO_PIN_NAME_ALIASES).
*
* @return - Pin Number (Ex: 5 for PA5, 13 for PF13 etc.).
******************************************************************************************************************/
uint8_t getPinNumber(uint16_t pin)
{
  uint8_t pinNum = pin%100;
  //return ( (uint8_t) pin%100 );
  return pinNum;
  /* Pin name aliases are assigned values in the format "X0NN", where NN represents the pin number.
   * Ex: PC5 has value 3005 - 3 for GPIOC & 05 for pin num 5.
   * Dividing the pin argument value by 100 & taking the remainder gives us the last two digits of the value i.e. the
   * pin number.
   */
}
