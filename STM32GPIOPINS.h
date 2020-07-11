/******************************************************************************************************************
* This file contains the Aliases for the GPIO Pins of STM32F446RE microcontroller. This aliases/names can be used
* as the arguments of GPIO driver APIs. This discards the need of providing two separate arguments (GPIO Port &
* Pin Number) to the APIs. Only pin name (Ex: PF3) can be provided to the function and it will get the port address
* as well as the pin number from the pin name itself.
******************************************************************************************************************/


#ifndef STM32GPIOPINS_H
#define STM32GPIOPINS_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "STM32F446RE.h"

/******************************************************************************************************************
*                                                   Pin Names
* @defgroup GPIO_PIN_NAME_ALIASES
*
* Pin name aliases are assigned values in the format "X0NN". X represents port number in the order (1-A, 2-B, ...
* 8-H), and NN represents the pin number (Ex: PC5 has value 3005 - 3 for GPIOC & 05 for pin num 5).
*
******************************************************************************************************************/

#define PA0     1000
#define PA1     1001
#define PA2     1002
#define PA3     1003
#define PA4     1004
#define PA5     1005
#define PA6     1006
#define PA7     1007
#define PA8     1008
#define PA9     1009
#define PA10    1010
#define PA11    1011
#define PA12    1012
#define PA13    1013
#define PA14    1014
#define PA15    1015

#define PB0     2000
#define PB1     2001
#define PB2     2002
#define PB3     2003
#define PB4     2004
#define PB5     2005
#define PB6     2006
#define PB7     2007
#define PB8     2008
#define PB9     2009
#define PB10    2010
#define PB11    2011
#define PB12    2012
#define PB13    2013
#define PB14    2014
#define PB15    2015

#define PC0     3000
#define PC1     3001
#define PC2     3002
#define PC3     3003
#define PC4     3004
#define PC5     3005
#define PC6     3006
#define PC7     3007
#define PC8     3008
#define PC9     3009
#define PC10    3010
#define PC11    3011
#define PC12    3012
#define PC13    3013
#define PC14    3014
#define PC15    3015

#define PD0     4000
#define PD1     4001
#define PD2     4002
#define PD3     4003
#define PD4     4004
#define PD5     4005
#define PD6     4006
#define PD7     4007
#define PD8     4008
#define PD9     4009
#define PD10    4010
#define PD11    4011
#define PD12    4012
#define PD13    4013
#define PD14    4014
#define PD15    4015

#define PE0     5000
#define PE1     5001
#define PE2     5002
#define PE3     5003
#define PE4     5004
#define PE5     5005
#define PE6     5006
#define PE7     5007
#define PE8     5008
#define PE9     5009
#define PE10    5010
#define PE11    5011
#define PE12    5012
#define PE13    5013
#define PE14    5014
#define PE15    5015

#define PF0     6000
#define PF1     6001
#define PF2     6002
#define PF3     6003
#define PF4     6004
#define PF5     6005
#define PF6     6006
#define PF7     6007
#define PF8     6008
#define PF9     6009
#define PF10    6010
#define PF11    6011
#define PF12    6012
#define PF13    6013
#define PF14    6014
#define PF15    6015

#define PG0     7000
#define PG1     7001
#define PG2     7002
#define PG3     7003
#define PG4     7004
#define PG5     7005
#define PG6     7006
#define PG7     7007
#define PG8     7008
#define PG9     7009
#define PG10    7010
#define PG11    7011
#define PG12    7012
#define PG13    7013
#define PG14    7014
#define PG15    7015

#define PH0     8000
#define PH1     8001
#define PH2     8002
#define PH3     8003
#define PH4     8004
#define PH5     8005
#define PH6     8006
#define PH7     8007
#define PH8     8008
#define PH9     8009
#define PH10    8010
#define PH11    8011
#define PH12    8012
#define PH13    8013
#define PH14    8014
#define PH15    8015

#define INVALID_PIN   44
#define INVALID_PORT  55



/******************************************************************************************************************
*                                           On-Board Switches and LEDs
******************************************************************************************************************/
#define USER_SW0      PC13
#define USER_LED0     PA5



/******************************************************************************************************************
*                                        Name & Address Resolver Functions
******************************************************************************************************************/
GPIO_reg* getPortAddr(uint16_t pinOrPort);
uint8_t getPortName(uint16_t pin);
uint8_t getPinNumber(uint16_t pin);

#ifdef __cplusplus
}
#endif

#endif
