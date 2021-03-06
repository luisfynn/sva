/**
 *	@file   delay.c
 *	@brief	
 *	@author luisfynn <tani223@pinetron.com>
 *	@date   2015/03/30 09:43
 */

/* system include */
#include "stm32f10x.h"
#include "mdin3xx.h"
/* local include */

static DWORD SetTimerValue;

void prvTimerSet(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);			//TIM1 clock enable

	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;					/* Enable the TIM4 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 14;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	//Time base configuration
	//time of 1 clock count = (Period * Prescaler) / (System Core Clock)
	//(10000*72)/72000000 = 0.01(1mS)
	TIM_TimeBaseStructure.TIM_Period = 10000-1;		//Interrupt occured, every 10000 Clock count. 
	TIM_TimeBaseStructure.TIM_Prescaler = 72-1; 	// Timer clock setting. Up to 1s, Clock Count need to 1,000,000(72/System Clock(=72Mhz)) 	
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);		/* Enable TIM2 Update interrupt */
	TIM_Cmd(TIM2, ENABLE);							//TIM2 enable counter			
}

void TIM2_ISR(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
	{
		SetTimerValue++;
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}

void Delay5US(WORD TimerValue)
{
	TIM2->CNT = 0;	
	WORD t0=TIM2->CNT;

	while(TIM2->CNT < (t0+(5*TimerValue)))
	{
	}
}

void Delay1MS(WORD TimeValue)
{
	TIM_Cmd(TIM2, ENABLE);
	
	BYTE i,j;
	
	for(j=0; j<TimeValue; j++)
	{
		for(i=0; i< 200; i++)
		{
			Delay5US(1);
		}
	}
	TIM_Cmd(TIM2, DISABLE);
}
