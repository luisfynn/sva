/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "stm32f10x_it.h"
#include "stm32f10x_conf.h"
#include "stm32f10x_system.h"
#include "mdindly.h"
#include "mdintype.h"

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

BYTE 	TxBuffer[30];
BYTE 	RxBuffer[RxBufferSize];
BYTE 	TxCounter = 0;
WORD 	RxCounter = 0;
BYTE 	NbrOfDataToTransfer = TxBufferSize;
BYTE 	NbrOfDataToRead = RxBufferSize;
BYTE 	usart_receive_end = 0;

WORD Ir_Execute_Delay = 0;

extern WORD Ir_Timer_Count;
extern DWORD TimeDisplay;

extern BYTE RTC_Display_Enable;
/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}
/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
	TimingDelay_Decrement();	
}

void USART3_IRQHandler(void)
{
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
 	{
		BYTE RxCounter_old;
		/* Clear the USART1 Receive interrupt */
		USART_ClearITPendingBit(USART3, USART_IT_RXNE);
	   
		if(USART_ReceiveData(USART3) != 0xd){
			/* Read one byte from the receive data register */
			RxBuffer[RxCounter++] = USART_ReceiveData(USART3) & 0xFF;
			
			if(RxCounter == RxBufferSize-1){
				RxCounter = 0;
			}
}else if(USART_ReceiveData(USART3) == 0xd){
			usart_receive_end = 1;
		}
		/* Disable the USART3 Receive interrupt */
		USART_ITConfig(USART3, USART_IT_RXNE, DISABLE);
    }

	if(USART_GetITStatus(USART3, USART_IT_TXE) != RESET)
    {
	  	USART_ClearITPendingBit(USART3, USART_IT_TXE);  
	    /* Write one byte to the transmit data register */
	    USART_SendData(USART3, TxBuffer[TxCounter++]);                    
	    
		if(TxCounter == NbrOfDataToTransfer)
	    {
		    /* Disable the USART3 Transmit interrupt */
		    USART_ITConfig(USART3, USART_IT_TXE, DISABLE);
		   	TxCounter = 0;
	    }    
	 }
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line13) != RESET)
  	{
		Ir_Receive_code();
    	EXTI_ClearITPendingBit(EXTI_Line13);
    }
}

void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update) != RESET)
    {
		Ir_Timer_Count++;
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update); // Clear the interrupt flag
	}
}

void WWDG_IRQHandler(void)
{
  	/* Update WWDG counter */
 	WWDG_SetCounter(0x7F);

 	RTC_Display_Enable = 0;
   	TimeDisplay = 0;
	
	/* Clear EWI flag */	
  	WWDG_ClearFlag();
}

void RTC_IRQHandler(void)
{
  if (RTC_GetITStatus(RTC_IT_SEC) != RESET)
  {
	/* Enable time update */
   	TimeDisplay = 1;
	//if(RTC_Display_Enable)	Time_Show();

    /* Clear the RTC Second interrupt */
    RTC_ClearITPendingBit(RTC_IT_SEC);

  }

	/* Wait until last write operation on RTC registers has finished */
  RTC_WaitForLastTask();
  /* Reset RTC Counter when Time is 23:59:59 */
  if (RTC_GetCounter() == 0x00015180)
  {
    	RTC_SetCounter(0x0);
 	    /* Wait until last write operation on RTC registers has finished */
	    RTC_WaitForLastTask();
  }
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
