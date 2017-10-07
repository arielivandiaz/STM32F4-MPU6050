
/*
 *
 * \author no1wudi
 * \file MPU6050_HW.h
 *
 */

#ifndef __MPU6050_HW_H
#define __MPU6050_HW_H



/*
 * \addtogroup Hardware dependence
 * \brief Include files of the driver,by default,it's for STM32F407,please modify it for your project
 */

#include <stm32f4xx_gpio.h>
#include "stm32f4xx_i2c.h"
#include "stm32f4xx_rcc.h"

/*
 * \addtogroup Hardware dependence
 * \brief Pin map for the microcontroller,by default,it's for STM32F407,please modify it for your project
 */

#define MPU6050SCL 		GPIO_Pin_6
#define MPU6050SCLLine 	GPIO_PinSource6
#define MPU6050SDA 		GPIO_Pin_7
#define MPU6050SDALine 	GPIO_PinSource7
#define MPU6050PORT 	GPIOB
#define MPU6050I2C 		I2C1

/*\addtogroup Hardware dependence
 * \brief The command of the reading and writing,it's consist of 7-bit I2C address and a read/write bit
 */

#define MPU6050R 0xD1
#define MPU6050W 0xD0


/*
 * \addtogroup Chip Init
 *\brief Configure the GPIO for the MPU6050,include the SDA and the SCL line
 */

void MPUGPIOConfig(void);

/*
 * \addtogroup Chip Init
 * \brief Configure the parameter of the I2C bus to communicate with the chip
 */

void MPUI2CConfig(void);

/*	\addtogroup Chip Init
 * \brief  Read data from MPU6050
 *
 *  \param Address The address of the object register
 *  \return				The data of the object register
 */

unsigned char ReadMPU(unsigned char Address);

/*
 *\brief  Write command or data to the object register
 *
 * \param Address 	The address of the object register
 * \param Value		The value will be written to the object register
 */

void WriteMPU(unsigned char Address, unsigned char Value);

#endif
