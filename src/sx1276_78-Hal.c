/*
 * THE FOLLOWING FIRMWARE IS PROVIDED: (1) "AS IS" WITH NO WARRANTY; AND 
 * (2)TO ENABLE ACCESS TO CODING INFORMATION TO GUIDE AND FACILITATE CUSTOMER.
 * CONSEQUENTLY, SEMTECH SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR
 * CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
 * OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
 * CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * 
 * Copyright (C) SEMTECH S.A.
 */
/*! 
 * \file       sx1276-Hal.c
 * \brief      SX1276 Hardware Abstraction Layer
 *
 * \version    2.0.B2 
 * \date       Nov 21 2012
 * \author     Miguel Luis
 *
 * Last modified by Miguel Luis on Jun 19 2013
 */
#include <stdint.h>
#include <stdbool.h>

#include "platform.h"

#if defined(USE_SX1276_78_RADIO)

#include "spi.h"
#include "sx1276_78-Hal.h"

void SX1276SetReset(uint8_t state)
{
    if (state == RADIO_RESET_ON)
    {
        // Set RESET pin to 0
        HAL_GPIO_WritePin(RESET_IOPORT, RESET_PIN, GPIO_PIN_RESET);
    }
    else
    {
        // Configure RESET as input
        HAL_GPIO_WritePin(RESET_IOPORT, RESET_PIN, GPIO_PIN_SET);
    }
}

void SX1276Write(uint8_t addr, uint8_t data)
{
    SX1276WriteBuffer(addr, &data, 1);
}

void SX1276Read(uint8_t addr, uint8_t *data)
{
    SX1276ReadBuffer(addr, data, 1);
}



void SX1276WriteBuffer(uint8_t addr, uint8_t *buffer, uint8_t size)
{
    uint8_t addr_send[1];
		uint8_t data_recv[255];
		uint8_t data_send[255];
	
    for (uint8_t i = 0; i < size; i++)
    {
        data_send[i] = buffer[i];
    }	

    //NSS = 0;
    HAL_GPIO_WritePin(NSS_IOPORT, NSS_PIN, GPIO_PIN_RESET);
    addr_send[0] = addr | 0x80;
    HAL_SPI_TransmitReceive(SPI_NAME, addr_send, data_recv, 1, 1000);
    HAL_SPI_TransmitReceive(SPI_NAME, data_send, data_recv, size, 1000);

    //NSS = 1;
    HAL_GPIO_WritePin(NSS_IOPORT, NSS_PIN, GPIO_PIN_SET);
}

void SX1276ReadBuffer(uint8_t addr, uint8_t *buffer, uint8_t size)
{
    uint8_t i;
    uint8_t addr_send[1];
    uint8_t data_send[255];
    uint8_t data_recv[255];
    //NSS = 0;
    HAL_GPIO_WritePin(NSS_IOPORT, NSS_PIN, GPIO_PIN_RESET);
    addr_send[0] = addr & 0x7F;
    HAL_SPI_Transmit(SPI_NAME, addr_send, 1, 1000);
    for (i = 0; i < size; i++)
    {
        data_send[i] = 0;
    }
    HAL_SPI_TransmitReceive(SPI_NAME, data_send, data_recv, size, 1000);
    for (uint8_t i = 0; i < size; i++)
    {
        buffer[i] = data_recv[i];
    }
    

    //NSS = 1;
    HAL_GPIO_WritePin(NSS_IOPORT, NSS_PIN, GPIO_PIN_SET);
}

void SX1276WriteFifo(uint8_t *buffer, uint8_t size)
{
    SX1276WriteBuffer(0, buffer, size);
}

void SX1276ReadFifo(uint8_t *buffer, uint8_t size)
{
    SX1276ReadBuffer(0, buffer, size);
}

inline uint8_t SX1276ReadDio0(void)
{
    return HAL_GPIO_ReadPin(DIO0_IOPORT, DIO0_PIN);
}

inline uint8_t SX1276ReadDio1(void)
{
    return HAL_GPIO_ReadPin(DIO1_IOPORT, DIO1_PIN);
}

inline uint8_t SX1276ReadDio2(void)
{
    return HAL_GPIO_ReadPin(DIO2_IOPORT, DIO2_PIN);
}

inline uint8_t SX1276ReadDio3(void)
{
    return HAL_GPIO_ReadPin(DIO3_IOPORT, DIO3_PIN);
}

inline uint8_t SX1276ReadDio4(void)
{
    return HAL_GPIO_ReadPin(DIO4_IOPORT, DIO4_PIN);
}

inline uint8_t SX1276ReadDio5(void)
{
    return HAL_GPIO_ReadPin(DIO5_IOPORT, DIO5_PIN);
}

inline void SX1276WriteRxTx(uint8_t txEnable)
{
    if (txEnable != 0)
    {
        HAL_GPIO_WritePin(RXTX_IOPORT, RXTX_PIN, GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(RXTX_IOPORT, RXTX_PIN, GPIO_PIN_RESET);
    }
}

#endif // USE_SX1276_78_RADIO
