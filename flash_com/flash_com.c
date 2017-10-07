
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"
#include "misc.h"




void USART1_Config(void)
{
    USART_InitTypeDef USART_InitStructure;

  /* USARTx configuration ------------------------------------------------------*/
  /* USARTx configured as follow:
        - BaudRate = 9600 bauda
        - Word Length = 8 Bits
        - Two Stop Bit
        - Odd parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate =  9600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  USART_Init(USART1, &USART_InitStructure);
  //USART3->BRR = CalcUSART_BRR(9600, 42000000,0);
  USART_Cmd(USART1, ENABLE);
}

void USART1_GPIOA_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // USART3 clock enable
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

  // GPIOD clock enable
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);



  //-------------------------- GPIO Configuration ----------------------------
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  // Connect USART pins to AF
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);


}

void USART1_GPIOB_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // USART3 clock enable
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

  // GPIOD clock enable
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);



  //-------------------------- GPIO Configuration ----------------------------
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  // Connect USART pins to AF
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_USART1);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_USART1);


}

void USART2_Config(void)
{
    USART_InitTypeDef USART_InitStructure;

  /* USARTx configuration ------------------------------------------------------*/
  /* USARTx configured as follow:
        - BaudRate = 9600 baud
        - Word Length = 8 Bits
        - Two Stop Bit
        - Odd parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate =  9600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  USART_Init(USART2, &USART_InitStructure);
  //USART3->BRR = CalcUSART_BRR(9600, 42000000,0);
  USART_Cmd(USART2, ENABLE);
}

void USART2_GPIOA_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // USART3 clock enable
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

  // GPIOD clock enable
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);


  // Connect USART pins to AF
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);

  //-------------------------- GPIO Configuration ----------------------------
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);


}

void USART2_GPIOD_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // USART3 clock enable
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

  // GPIOD clock enable
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);


  // Connect USART pins to AF
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource5, GPIO_AF_USART2);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource6, GPIO_AF_USART2);

  //-------------------------- GPIO Configuration ----------------------------
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);


}
void USART3_Config(void)
{
    USART_InitTypeDef USART_InitStructure;

  /* USARTx configuration ------------------------------------------------------*/
  /* USARTx configured as follow:
        - BaudRate = 9600 baud
        - Word Length = 8 Bits
        - Two Stop Bit
        - Odd parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate =  9600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  USART_Init(USART3, &USART_InitStructure);
  //USART3->BRR = CalcUSART_BRR(9600, 42000000,0);
  USART_Cmd(USART3, ENABLE);
}
void USART3_GPIOB_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // USART3 clock enable
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

  // GPIOD clock enable
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);



  //-------------------------- GPIO Configuration ----------------------------
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  // Connect USART pins to AF
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3);




}
void USART3_GPIOC_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // USART3 clock enable
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

  // GPIOD clock enable
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);



  //-------------------------- GPIO Configuration ----------------------------
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  // Connect USART pins to AF
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_USART3);
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_USART3);




}
void USART3_GPIOD_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // USART3 clock enable
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

  // GPIOD clock enable
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);



  //-------------------------- GPIO Configuration ----------------------------
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  // Connect USART pins to AF
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_USART3);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_USART3);




}


void USART6_Config(void)
{
    USART_InitTypeDef USART_InitStructure;

  /* USARTx configuration ------------------------------------------------------*/
  /* USARTx configured as follow:
        - BaudRate = 9600 baud
        - Word Length = 8 Bits
        - Two Stop Bit
        - Odd parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate =  9600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  USART_Init(USART6, &USART_InitStructure);
  //USART3->BRR = CalcUSART_BRR(9600, 42000000,0);
  USART_Cmd(USART6, ENABLE);
}

void USART6_GPIOC_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // USART3 clock enable
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);
  // GPIOD clock enable
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);



  //-------------------------- GPIO Configuration ----------------------------
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  // Connect USART pins to AF
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6);
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);




}
void USART6_GPIOG_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // USART3 clock enable
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);
  // GPIOD clock enable
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);



  //-------------------------- GPIO Configuration ----------------------------
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOG, &GPIO_InitStructure);

  // Connect USART pins to AF
  GPIO_PinAFConfig(GPIOG, GPIO_PinSource9, GPIO_AF_USART6);
  GPIO_PinAFConfig(GPIOG, GPIO_PinSource14, GPIO_AF_USART6);




}

void NVIC_USART_Config(void){

	//USART interrupts are most important
	//USART1 is more important than USART2, so it has lower sub priority number
	NVIC_InitTypeDef NVIC_InitStruct;
	  /* Configure the NVIC Preemption Priority Bits */
	  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

	  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); // enable the USART2 receive interrupt
	  USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); // enable the USART2 receive interrupt
	  USART_ITConfig(USART3, USART_IT_RXNE, ENABLE); // enable the USART2 receive interrupt
	  USART_ITConfig(USART6, USART_IT_RXNE, ENABLE); // enable the USART2 receive interrupt


	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStruct);

	NVIC_InitStruct.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);

	NVIC_InitStruct.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStruct);

	NVIC_InitStruct.NVIC_IRQChannel = USART6_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);


}
void USART1_IRQHandler(void) {
	static  char rx;

    //Check if interrupt was because data is received
    if (USART_GetITStatus(USART1, USART_IT_RXNE)) {
    	   GPIO_ToggleBits(GPIOD, GPIO_Pin_15);
    	rx =  USART_ReceiveData(USART1);

    	send_char(1,rx);
    	/* send_USART_ok(1);
         send_char(1,rx);
*/
        //Clear interrupt flag
        USART_ClearITPendingBit(USART1, USART_IT_RXNE);
    }
}
void USART2_IRQHandler(void) {
	static  char rx;

    //Check if interrupt was because data is received
    if (USART_GetITStatus(USART2, USART_IT_RXNE)) {
    	GPIO_ToggleBits(GPIOD, GPIO_Pin_15);
       rx =  USART_ReceiveData(USART2);
       send_USART_ok(2);
       send_char(2,rx);
        //Clear interrupt flag
        USART_ClearITPendingBit(USART2, USART_IT_RXNE);
    }
}

int  send_USART_ok(unsigned int usart){

	int active_usart;
	switch(usart){
	case 1:
		active_usart=USART1;
		break;
	case 2:
		active_usart=USART2;
		break;
	case 3:
		active_usart=USART3;
		break;
	case 6:
		active_usart=USART6;
		break;
	default:
		return -1;
		break;
	}
	while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET) {} // Espera que el registro de transmision este libre
	USART_SendData(active_usart, 'O'); // Envia un caracter

	while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET) {} // Espera que el registro de transmision este libre
	USART_SendData(active_usart, 'K'); // Envia un caracter

	while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET) {} // Espera que el registro de transmision este libre
	USART_SendData(active_usart, ' '); // Envia un caracter

	while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET) {} // Espera que el registro de transmision este libre
	USART_SendData(active_usart, 'U'); // Envia un caracter

	while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET) {} // Espera que el registro de transmision este libre
	USART_SendData(active_usart, 'S'); // Envia un caracter

	while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET) {} // Espera que el registro de transmision este libre
	USART_SendData(active_usart, 'A'); // Envia un caracter

	while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET) {} // Espera que el registro de transmision este libre
	USART_SendData(active_usart, 'R'); // Envia un caracter

	while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET) {} // Espera que el registro de transmision este libre
	USART_SendData(active_usart, 'T'); // Envia un caracter

	while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET) {} // Espera que el registro de transmision este libre
	USART_SendData(active_usart, usart+48); // Envia un caracter

	while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET) {} // Espera que el registro de transmision este libre
	USART_SendData(active_usart, '\n'); // Envia un caracter

	while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET) {} // Espera que el registro de transmision este libre
	USART_SendData(active_usart, '\r'); // Envia un caracter



}

uint16_t CalcUSART_BRR(uint32_t BAUD, uint32_t APBclock, uint8_t Sampling8Enable)
{
  uint32_t tmpreg = 0x00;
  uint32_t integerdivider = 0x00;
  uint32_t fractionaldivider = 0x00;

  // If USART_OverSampling8Cmd is Enable, Sampling8Enable should be 1(true)
  // Else Sampling8Enable should be 0(false)
  if(Sampling8Enable == 0)
  {
    APBclock = APBclock / 4;
  }

  integerdivider = ((25 * APBclock) / (2 * (BAUD)));
  tmpreg = (integerdivider / 100) << 4;
  fractionaldivider = integerdivider - (100 * (tmpreg >> 4));

  tmpreg |= ((((fractionaldivider * 8) + 50) / 100)) & ((uint8_t)0x07);

  return (uint16_t)tmpreg;
}





void send_char(unsigned int usart, char c){


	int active_usart;
	switch(usart){
	case 1:
		active_usart=USART1;
		break;
	case 2:
		active_usart=USART2;
		break;
	case 3:
		active_usart=USART3;
		break;
	case 6:
		active_usart=USART6;
		break;
	default:
		return -1;
		break;
	}




	  	 while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET){} // Espera que el registro de transmision este libre

	  	            USART_SendData(active_usart, '<'); // Envia un caracter

	 while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET){} // Espera que el registro de transmision este libre

	            USART_SendData(active_usart, c); // Envia un caracter

	   	  	 while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET){} // Espera que el registro de transmision este libre

	   	  	            USART_SendData(active_usart, '>'); // Envia un caracter


	   	  	  	 while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET){} // Espera que el registro de transmision este libre

	   	  	  	       USART_SendData(active_usart, '\n'); // Envia un caracter

	   	  	  	  	 while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET){} // Espera que el registro de transmision este libre

	   	  	  	  	       USART_SendData(active_usart, '\r'); // Envia un caracter


}


void send_data(unsigned int usart, uint16_t n, char *arr){

	uint16_t i=0;
	int active_usart;
	switch(usart){
	case 1:
		active_usart=USART1;
		break;
	case 2:
		active_usart=USART2;
		break;
	case 3:
		active_usart=USART3;
		break;
	case 6:
		active_usart=USART6;
		break;
	default:
		return -1;
		break;
	}

	while(i<n){

    while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET){} // Espera que el registro de transmision este libre

       USART_SendData(active_usart, arr[i]); // Envia un caracter
	i++;
	}


	 while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET){} // Espera que el registro de transmision este libre

	       USART_SendData(active_usart, '\n'); // Envia un caracter
	while(USART_GetFlagStatus(active_usart, USART_FLAG_TXE) == RESET){} // Espera que el registro de transmision este libre

	             USART_SendData(active_usart, '\r'); // Envia un caracter

}

