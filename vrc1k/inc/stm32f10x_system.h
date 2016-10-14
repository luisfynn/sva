/**
 *	@file   stm32f10x_system.h
 *	@brief	
 *	@author luisfynn<tani223@pinetron.com>
 *	@date   2014/10/14 13:14
 */

#ifndef _STM32F10X_SYSTEM_HEADER_
#define _STM32F10X_SYSTEM_HEADER_

/* system include */
/* local include */
#include "mdintype.h"
#include "video.h"
/* external variable & function */
#define RESTART	2

GPIO_InitTypeDef GPIO_InitStructure;
NVIC_InitTypeDef NVIC_InitStructure;
USART_InitTypeDef USART_InitStructure;
NVIC_InitTypeDef NVIC_InitStructure;
EXTI_InitTypeDef EXTI_InitStructure;
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

void RCC_Configuration(void);
void GPIO_Initialize(void);
void USART_Initialize(void);
void IR_Receiver(void);
void Device_Reset(void);
void Power_Status(BYTE control);
void TimingDelay_Decrement(void);
void Debug_message(void);

WORD Time_Regulate(void);

void Video_Detection(PNCDEC_INFO pINFO);

WORD THH, TMM, TSS;

typedef enum {
	JANUARY =1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER,
}MONTH;



#endif /* _STM32F10X_SYSTEM_HEADER_*/

