#ifndef __M880A_HAL_H__
#define __M880A_HAL_H__

#include "platform.h"

#include <stdint.h>
#include <stdbool.h>

#include "stm32f0xx_hal.h"


/*!
 *  SPI DEFINES
*/
#define SPI_NAME 																		&hspi1


/*!
 * SX127x definitions
 */

/*!
 * SX1272 RESET I/O definitions
 */
#define RESET_IOPORT                                GPIOB
#define RESET_PIN                                   GPIO_PIN_6

/*!
 * SX1272 SPI NSS I/O definitions
 */
#define NSS_IOPORT                                  GPIOA
#define NSS_PIN                                     GPIO_PIN_4

/*!
 * SX1272 DIO pins  I/O definitions
 */
#define DIO0_IOPORT                                 GPIOB
#define DIO0_PIN                                    GPIO_PIN_5

#define DIO1_IOPORT                                 GPIOB
#define DIO1_PIN                                    GPIO_PIN_4

#define DIO2_IOPORT                                 GPIOB
#define DIO2_PIN                                    GPIO_PIN_3

#define DIO3_IOPORT                                 GPIOA
#define DIO3_PIN                                    GPIO_PIN_15

#define DIO4_IOPORT                                 GPIOB
#define DIO4_PIN                                    GPIO_PIN_1

#define DIO5_IOPORT                                 GPIOB
#define DIO5_PIN                                    GPIO_PIN_0

//FEM_CTX_PIN
#define RXTX_IOPORT                                 GPIOA
#define RXTX_PIN                                    GPIO_PIN_10



/*!
 * Initializes board peripherals
 */
void BoardInit( void );

#endif //__M880A_HAL_H__

