/******************************************************************************************************************
* This file contains the Aliases for the GPIO Pins of STM32F446RE microcontroller. This aliases/names can be used
* as the arguments of GPIO driver APIs. This discards the need of providing two separate arguments (GPIO Port &
* Pin Number) to the APIs. Only pin name (Ex: PF3) can be provided to the function and it will get the port address
* as well as the pin number from the pin name itself.
******************************************************************************************************************/

[STM32GPIOPINS.h]
[STM32GPIODRIVER.h]
[STM32F446RE.h]

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
* Pin name aliases are assigned values in the format "XXNN". XX represents port number (@ref - PERIPHERAL_GPIO_PORTS
* [STM32F446RE.h]) and NN represents the pin number (Ex: PC5 has value 1205 - 12 for GPIOC & 05 for pin num 5).
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

#define PB0     1100
#define PB1     1101
#define PB2     1102
#define PB3     1103
#define PB4     1104
#define PB5     1105
#define PB6     1106
#define PB7     1107
#define PB8     1108
#define PB9     1109
#define PB10    1110
#define PB11    1111
#define PB12    1112
#define PB13    1113
#define PB14    1114
#define PB15    1115

#define PC0     1200
#define PC1     1201
#define PC2     1202
#define PC3     1203
#define PC4     1204
#define PC5     1205
#define PC6     1206
#define PC7     1207
#define PC8     1208
#define PC9     1209
#define PC10    1210
#define PC11    1211
#define PC12    1212
#define PC13    1213
#define PC14    1214
#define PC15    1215

#define PD0     1300
#define PD1     1301
#define PD2     1302
#define PD3     1303
#define PD4     1304
#define PD5     1305
#define PD6     1306
#define PD7     1307
#define PD8     1308
#define PD9     1309
#define PD10    1310
#define PD11    1311
#define PD12    1312
#define PD13    1313
#define PD14    1314
#define PD15    1315

#define PE0     1400
#define PE1     1401
#define PE2     1402
#define PE3     1403
#define PE4     1404
#define PE5     1405
#define PE6     1406
#define PE7     1407
#define PE8     1408
#define PE9     1409
#define PE10    1410
#define PE11    1411
#define PE12    1412
#define PE13    1413
#define PE14    1414
#define PE15    1415

#define PF0     1500
#define PF1     1501
#define PF2     1502
#define PF3     1503
#define PF4     1504
#define PF5     1505
#define PF6     1506
#define PF7     1507
#define PF8     1508
#define PF9     1509
#define PF10    1510
#define PF11    1511
#define PF12    1512
#define PF13    1513
#define PF14    1514
#define PF15    1515

#define PG0     1600
#define PG1     1601
#define PG2     1602
#define PG3     1603
#define PG4     1604
#define PG5     1605
#define PG6     1606
#define PG7     1607
#define PG8     1608
#define PG9     1609
#define PG10    1610
#define PG11    1611
#define PG12    1612
#define PG13    1613
#define PG14    1614
#define PG15    1615

#define PH0     1700
#define PH1     1701
#define PH2     1702
#define PH3     1703
#define PH4     1704
#define PH5     1705
#define PH6     1706
#define PH7     1707
#define PH8     1708
#define PH9     1709
#define PH10    1710
#define PH11    1711
#define PH12    1712
#define PH13    1713
#define PH14    1714
#define PH15    1715

#define INVALID_PIN   44
#define INVALID_PORT  55



/******************************************************************************************************************
*                                           On-Board Switches and LEDs
* @defgroup NUCLEO_BOARD
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
