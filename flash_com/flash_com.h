#ifndef FLASH_COM_H_INCLUDED
#define FLASH_COM_H_INCLUDED

#include "stdint.h"


/* For Init:
 *     SystemInit();
 *     USART1_GPIOB_Config()
 *     USART1_Config()
 *     NVIC_USART_Config();
 *     send_USART_ok(1); */





void USART1_Config(void);
void USART1_GPIOA_Config(void);
void USART1_GPIOB_Config(void);

void USART2_Config(void);
void USART2_GPIOA_Config(void);
void USART2_GPIOD_Config(void);

void USART3_Config(void);
void USART3_GPIOB_Config(void);
void USART3_GPIOC_Config(void);
void USART3_GPIOD_Config(void);

void USART6_Config(void);
void USART6_GPIOC_Config(void);
void USART6_GPIOG_Config(void);

void NVIC_USART_Config(void);
void USART1_IRQHandler(void);
void USART2_IRQHandler(void);

void send_USART_ok(unsigned int usart);




void send_char(unsigned int usart, char c);
void send_data(unsigned int usart, uint16_t n, char *arr);
uint16_t CalcUSART_BRR(uint32_t BAUD, uint32_t APBclock, uint8_t Sampling8Enable);

#endif // FLASH_COM_H_INCLUDED
