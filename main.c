/**
 *  @file    main.c
 *  @author  Ariel Ivan Diaz (arielivandiaz)
 *  @mail    arielivandiaz@gmail.com
 *	@url     wwww.arielivandiaz.net
 *	@date    7/10/2017
 *  @version 1.1
 *
 *
 *  @section DESCRIPTION
 *
 *  This is a project to read the data of the MPU6050 and send them by serial port.
 *
 *  @section ENVIRONMENT AND COMPILER
 *	> CooCox CoIDE - GNU ARM COMPILER
 *	> Kit STM32F4 Discovery
 *
 **/

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {


	//Init all

	setvbuf(stdout, 0, _IONBF, 0);


	USART3_GPIOB_Config();
	USART3_Config();
	NVIC_USART_Config();
	send_USART_ok(3);

	EnableMPU();

	float angle_z_accel;
	float angle_y_accel;
	float angle_x_accel;

	float angle_z_gyro;
	float angle_y_gyro;
	float angle_x_gyro;

	float angle_x;
	float angle_y;


	char buff[50] = { '\b' };

	float temp;
	float acc_x, acc_y, acc_z;
	float gy_x, gy_y, gy_z;
	float acc_xa, acc_ya, acc_za;
	float gy_xa, gy_ya, gy_za;

	int flag_first = 1;
	int flag=1;

	init_user_button();
	int j=0;

	while (1) {



		//MPU Get Data
		temp = (float) GetMPUTempInt() / 100;
		acc_x = (float) 1.27 * GetMPU_accelX() / 100;
		acc_y = (float) 1.20 * GetMPU_accelY() / 100;
		acc_z = (float) 1.4 * GetMPU_accelZ() / 100;

		gy_x = (float) 1.27 * GetMPU_gyroX() / 100;
		gy_y = (float) 1.20 * GetMPU_gyroY() / 100;
		gy_z = (float) 1.27 * GetMPU_gyroZ() / 100;

		//Filter accelerometers and gyroscopes
		if (flag_first) {
			flag_first = 0;
		} else {
			acc_x = 0.5 * acc_x + 0.5 * acc_xa;
			acc_y = 0.5 * acc_y + 0.5 * acc_ya;
			acc_z = 0.5 * acc_z + 0.5 * acc_za;

			gy_x = 0.5 * gy_x + 0.5 * gy_xa;
			gy_y = 0.5 * gy_y + 0.5 * gy_ya;
			gy_z = 0.5 * gy_z + 0.5 * gy_za;

		}

		//User Button
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)) {
			for (int i = 0; i < 100000; i++)
				;
			if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)) {
				flag++;
				if (flag == 7)
					flag = 0;
			}

		}

		switch (flag) {

				case 1: //Print Acceleration in 3 axes in m/s^2

					sprintf(buff, " %0.2f\t%0.2f\t%0.2f\t",
									acc_x, acc_y, acc_z);
					break;

				case 2: //Print Acceleration in 3 axes in g



					sprintf(buff, " %0.2f\t%0.2f\t%0.2f\t",
							acc_x/10.5, acc_y/9.7, acc_z/9.7);

					break;

				case 3: //Print angular velocity in 2 axes
					sprintf(buff, " %0.2f\t%0.2f\t%0.2f\t",
							gy_x/2, gy_y/2,gy_z/2);
					break;


				case 4: //Print angles calculated with the accelerometers and temperature


					//Calculate angle X & Y
					angle_y_accel = -atan(acc_x / (sqrt(acc_y * acc_y + acc_z * acc_z))) * 57.3;
					angle_x_accel = atan(acc_y / (sqrt(acc_x * acc_x + acc_z * acc_z))) * 57.3;


					sprintf(buff, " %0.2f\t%0.2f\t%0.2f\t", angle_x_accel, angle_y_accel, temp);

					break;

				case 5: // Print angles calculated with gyroscopes and accelerometers

					angle_y_gyro=gy_x*1+gy_xa;
					angle_x_gyro=gy_y*1+gy_ya;



					angle_y_accel = -atan(acc_x / (sqrt(acc_y * acc_y + acc_z * acc_z))) * 57.3;
					angle_x_accel = atan(acc_y / (sqrt(acc_x * acc_x + acc_z * acc_z))) * 57.3;

					angle_x=0.75*(angle_x_accel+angle_x_gyro)+(1-0.75)*angle_x_accel;
					angle_y=0.75*(angle_y_accel+angle_y_gyro)+(1-0.75)*angle_y_accel;

					sprintf(buff, " %0.2f\t%0.2f\t", angle_x, angle_y);


					break;
				case 6: //Print All

					sprintf(buff, " %0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t%0.2f\t",
													acc_x, acc_y, acc_z,gy_x,gy_y,temp);

					break;

				default:
					sprintf(buff, "\n");
				}

		//Send data to USART
		send_data(3, 40, buff);

		//Reset Buffer
		for (int i = 0; i < 40; i++)
			buff[i] = 0;

		//Store Values
		acc_xa = acc_x;
		acc_ya = acc_y;
		acc_za = acc_z;

		gy_xa = gy_x;
		gy_ya = gy_y;
		gy_za = gy_z;
	}
}

void init_user_button() {

	GPIO_InitTypeDef GPIO_InitDef;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	//Pin 0
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_0;
	//Mode output
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_IN;
	//Output type push-pull
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	//With pull down resistor
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_DOWN;
	//50MHz pin speed
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_50MHz;

	//Initialize pin on GPIOA port
	GPIO_Init(GPIOA, &GPIO_InitDef);
}
