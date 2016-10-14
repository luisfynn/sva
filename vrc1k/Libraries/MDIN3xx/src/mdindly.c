//----------------------------------------------------------------------------------------------------------------------
// (C) Copyright 2010  Macro Image Technology Co., LTd. , All rights reserved
// 
// This source code is the property of Macro Image Technology and is provided
// pursuant to a Software License Agreement. This code's reuse and distribution
// without Macro Image Technology's permission is strictly limited by the confidential
// information provisions of the Software License Agreement.
//-----------------------------------------------------------------------------------------------------------------------
//
// File Name   		:	MDINDLY.C
// Description 		:
// Ref. Docment		: 
// Revision History 	:

// ----------------------------------------------------------------------
// Include files
// ----------------------------------------------------------------------
#include	"mdin3xx.h"
#include	"mdintype.h"
#include	"board.h"

// ----------------------------------------------------------------------
// Struct/Union Types and define
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Static Global Data section variables
// ----------------------------------------------------------------------
static volatile DWORD TimingDelay;
// ----------------------------------------------------------------------
// External Variable 
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Static Prototype Functions
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Static functions
// ----------------------------------------------------------------------

void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{ 
		TimingDelay--;
	}
}

//--------------------------------------------------------------------------------------------------------------------------
// Drive Function for delay (usec and msec)
// You must make functions which is defined below.
//--------------------------------------------------------------------------------------------------------------------------
MDIN_ERROR_t I2CDLY_5uSec(WORD delay)
{

	SysTick_SetReload(90);
	SysTick_ITConfig(ENABLE);

	/* Enable the SysTick Counter */
	SysTick_CounterCmd(SysTick_Counter_Enable);
							    
   	TimingDelay = delay*5;

	while(TimingDelay != 0);

	/* Disable SysTick Counter */
	SysTick_CounterCmd(SysTick_Counter_Disable);
	/* Clear SysTick Counter */
	SysTick_CounterCmd(SysTick_Counter_Clear);

	return MDIN_NO_ERROR;
}

MDIN_ERROR_t MDINDLY_5uSec(WORD delay)
{

	SysTick_SetReload(90);
	SysTick_ITConfig(ENABLE);

	/* Enable the SysTick Counter */
	SysTick_CounterCmd(SysTick_Counter_Enable);
							    
   	TimingDelay = delay*5;

	while(TimingDelay != 0);

	/* Disable SysTick Counter */
	SysTick_CounterCmd(SysTick_Counter_Disable);
	/* Clear SysTick Counter */
	SysTick_CounterCmd(SysTick_Counter_Clear);

	return MDIN_NO_ERROR;
}

MDIN_ERROR_t MDINDLY_10uSec(WORD delay)
{
	SysTick_SetReload(90);
	SysTick_ITConfig(ENABLE);

	/* Enable the SysTick Counter */
	SysTick_CounterCmd(SysTick_Counter_Enable);
							    
   	TimingDelay = delay*10;

	while(TimingDelay != 0);

	/* Disable SysTick Counter */
	SysTick_CounterCmd(SysTick_Counter_Disable);
	/* Clear SysTick Counter */
	SysTick_CounterCmd(SysTick_Counter_Clear);

	return MDIN_NO_ERROR;
}

//--------------------------------------------------------------------------------------------------------------------------
MDIN_ERROR_t MDINDLY_mSec(WORD delay)
{
	SysTick_SetReload(9000);
	SysTick_ITConfig(ENABLE);

	/* Enable the SysTick Counter */
	SysTick_CounterCmd(SysTick_Counter_Enable);
							    
   	TimingDelay = delay;

	while(TimingDelay != 0);

	/* Disable SysTick Counter */
	SysTick_CounterCmd(SysTick_Counter_Disable);
	/* Clear SysTick Counter */
	SysTick_CounterCmd(SysTick_Counter_Clear);

	return MDIN_NO_ERROR;
}

/*  FILE_END_HERE */
