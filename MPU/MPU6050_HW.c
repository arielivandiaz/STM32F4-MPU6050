
/*
 * \author no1wudi
 * \file MPU6050_HW.c
 */
#include "MPU6050_HW.h"

void MPUGPIOConfig() {
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); //Enable the peripheral clock of GPIOB

	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode = GPIO_Mode_AF;
	gpio.GPIO_OType = GPIO_OType_OD;
	gpio.GPIO_Pin = MPU6050SCL | MPU6050SDA;
	gpio.GPIO_PuPd = GPIO_PuPd_UP;
	gpio.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(MPU6050PORT, &gpio);

	GPIO_PinAFConfig(MPU6050PORT, MPU6050SCLLine, GPIO_AF_I2C1); //Enable the AF function of the GPIO
	GPIO_PinAFConfig(MPU6050PORT, MPU6050SDALine, GPIO_AF_I2C1);
}

void MPUI2CConfig() {
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE); //Enable the peripheral clock of I2C

	I2C_InitTypeDef i2c;

	i2c.I2C_Ack = I2C_Ack_Enable;
	i2c.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	i2c.I2C_ClockSpeed = 300000;
	i2c.I2C_DutyCycle = I2C_DutyCycle_2;
	i2c.I2C_Mode = I2C_Mode_I2C;
	i2c.I2C_OwnAddress1 = 0xAA;
	I2C_Init(MPU6050I2C, &i2c);
	I2C_Cmd(MPU6050I2C, ENABLE);
}

unsigned char ReadMPU(unsigned char Address) {
	unsigned char Data;
	I2C_GenerateSTART(MPU6050I2C, ENABLE);
	while (!I2C_CheckEvent(MPU6050I2C, I2C_EVENT_MASTER_MODE_SELECT))
		;
	I2C_Send7bitAddress(MPU6050I2C, MPU6050W, I2C_Direction_Transmitter);
	while (!I2C_CheckEvent(MPU6050I2C,
			I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
		;
	I2C_SendData(MPU6050I2C, Address);
	while (!I2C_CheckEvent(MPU6050I2C, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
		;
	I2C_GenerateSTART(MPU6050I2C, ENABLE);
	while (!I2C_CheckEvent(MPU6050I2C, I2C_EVENT_MASTER_MODE_SELECT))
		;
	I2C_Send7bitAddress(MPU6050I2C, MPU6050R, I2C_Direction_Receiver);
	while (!I2C_CheckEvent(MPU6050I2C, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
		;
	I2C_AcknowledgeConfig(MPU6050I2C, DISABLE);
	I2C_GenerateSTOP(MPU6050I2C, ENABLE);
	while (!(I2C_CheckEvent(MPU6050I2C, I2C_EVENT_MASTER_BYTE_RECEIVED)))
		;
	Data = I2C_ReceiveData(MPU6050I2C);
	I2C_AcknowledgeConfig(MPU6050I2C, ENABLE);
	return Data;
}

void WriteMPU(unsigned char Address, unsigned char Value) {
	I2C_GenerateSTART(MPU6050I2C, ENABLE);
	while (!I2C_CheckEvent(MPU6050I2C, I2C_EVENT_MASTER_MODE_SELECT))
		;
	I2C_Send7bitAddress(MPU6050I2C, MPU6050W, I2C_Direction_Transmitter);
	while (!I2C_CheckEvent(MPU6050I2C,
			I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
		;
	I2C_SendData(MPU6050I2C, Address);
	while (!I2C_CheckEvent(MPU6050I2C, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
		;
	I2C_SendData(MPU6050I2C, Value);
	while (!I2C_CheckEvent(MPU6050I2C, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
		;
	I2C_GenerateSTOP(MPU6050I2C, ENABLE);
}
