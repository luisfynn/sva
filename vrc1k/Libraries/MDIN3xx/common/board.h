/**
 *	@file   board.h
 *	@brief	
 *	@author luisfynn <@pinetron.com>
 *	@date   2014/10/14 09:42
 */

#ifndef _BOARD_HEADER_
#define _BOARD_HEADER_

/* system include */

/* local include */
#include "stm32f10x_conf.h"
/* external variable & function */

#define		TEST_MODE2(x)	(x)? GPIO_SetBits(GPIOB, GPIO_Pin_15): GPIO_ResetBits(GPIOB, GPIO_Pin_15)	
#define		TEST_MODE1(x)	(x)? GPIO_SetBits(GPIOB, GPIO_Pin_14): GPIO_ResetBits(GPIOB, GPIO_Pin_14)
#define		GET_MDIN_IRQ()	GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)	

#endif /* _BOARD_HEADER_*/

