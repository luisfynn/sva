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
#include 	"stm32f10x.h"
#include	"mdin3xx.h"

// ----------------------------------------------------------------------
// Struct/Union Types and define
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Static Global Data section variables
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
// External Variable 
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Static Prototype Functions
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Static functions
// ----------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------------------
// Drive Function for delay (usec and msec)
// You must make functions which is defined below.
//--------------------------------------------------------------------------------------------------------------------------
MDIN_ERROR_t I2CDLY_5uSec(WORD delay)
{
	//Delay5US(delay);
	return MDIN_NO_ERROR;
}

MDIN_ERROR_t MDINDLY_5uSec(WORD delay)
{
	Delay5US(delay);
	return MDIN_NO_ERROR;
}

MDIN_ERROR_t MDINDLY_10uSec(WORD delay)
{
	Delay5US(2*delay);
	return MDIN_NO_ERROR;
}

//--------------------------------------------------------------------------------------------------------------------------
MDIN_ERROR_t MDINDLY_mSec(WORD delay)
{
	Delay1MS(delay);
	return MDIN_NO_ERROR;
}

/*  FILE_END_HERE */
