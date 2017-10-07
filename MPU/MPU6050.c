/*
 * \author no1wudi
 * \file MPU6050.c
 */

#include "MPU6050.h"

void EnableMPU() {
	MPUGPIOConfig();
	MPUI2CConfig();
	WriteMPU(PWR_MGMT_1, 0x00);
}

void DisableMPU() {
	WriteMPU(PWR_MGMT_2, 0x40);
}

void DeinitMPU() {
	WriteMPU(PWR_MGMT_2, 0xC0);
}

float GetMPUTemp() {
	float temp;
	temp = GetDataMPU(TEMP_OUT_H,TEMP_OUT_L);
	temp = temp / 340 + 36.53;
	return temp;
}
int GetMPUTempInt() {
	float temp;
	int temp_int;
	temp = GetDataMPU(TEMP_OUT_H,TEMP_OUT_L);
	temp_int = (int ) 100*(temp / 340 + 36.53);

	return temp_int;
}


///*****************************************************************////

int GetMPU_accelX(){

	float accel;
	int accel_int;
	accel = GetDataMPU(ACCEL_XOUT_H,ACCEL_XOUT_L);
	accel_int = (int )100*( accel / DIV_ACCEL_RANGE_16g);

	return accel_int;



}
int GetMPU_accelY(){


	float accel;
	int accel_int;
	accel = GetDataMPU(ACCEL_YOUT_H,ACCEL_YOUT_L);
	accel_int = (int ) 100*(accel / DIV_ACCEL_RANGE_16g);

	return accel_int;



}
int GetMPU_accelZ(){


	float accel;
	int accel_int;
	accel = GetDataMPU(ACCEL_ZOUT_H,ACCEL_ZOUT_L);
	accel_int = (int ) 100*(accel / DIV_ACCEL_RANGE_16g);

	return accel_int;

}
int GetMPU_gyroX(){


	float gyro;
	int gyro_init;
	gyro = GetDataMPU(GYRO_XOUT_H,GYRO_XOUT_L);
	gyro_init = (int ) gyro / DIV_GYRO_RANGE_2000;

	return gyro_init;

}
int GetMPU_gyroY(){

	float gyro;
	int gyro_init;
	gyro = GetDataMPU(GYRO_YOUT_H,GYRO_YOUT_L);
	gyro_init = (int ) gyro / DIV_GYRO_RANGE_2000;

	return gyro_init;

}
int GetMPU_gyroZ(){

	float gyro;
	int gyro_init;
	gyro = GetDataMPU(GYRO_ZOUT_H,GYRO_ZOUT_L);
	gyro_init = (int ) gyro / DIV_GYRO_RANGE_2000;

	return gyro_init;


}

///*****************************************************************////







void MPU_Register_FIFO_Init(MPU_Register_FIFO_InitType * InitType) {
	WriteMPU(FIFO_EN,
			((InitType->ACCEL) | (InitType->GYRO) | (InitType->TEMP)));
}


void MPU_Register_Config_Init(MPU_Register_Config_InitType * InitType) {
	WriteMPU(CONFIG, ((InitType->DLPF) | (InitType->SYNC)));
}

void MPU_Register_GYRO_Init(MPU_Register_GYRO_InitType * InitType) {
	WriteMPU(GYRO_CONFIG,
			((InitType->GYRO_SELF_TEST) | (InitType->GYRO_RANGE)));
}

void MPU_Register_ACCEL_Init(MPU_Register_ACCEL_InitType * InitType) {
	WriteMPU(ACCEL_CONFIG,
			((InitType->ACCEL_SELF_TEST) | (InitType->ACCEL_RANGE)));
}





short GetDataMPU(unsigned char AddressH, unsigned char AddressL) {
	short DataH;
	char DataL;
	DataH = ReadMPU(AddressH);
	DataL = ReadMPU(AddressL);
	return ((DataH << 8) + DataL);
}
