//----------------------------------------------------------------------------------------------------------------------
// (C) Copyright 2008  Macro Image Technology Co., LTd. , All rights reserved
// 
// This source code is the property of Macro Image Technology and is provided
// pursuant to a Software License Agreement. This code's reuse and distribution
// without Macro Image Technology's permission is strictly limited by the confidential
// information provisions of the Software License Agreement.
//-----------------------------------------------------------------------------------------------------------------------
//
// File Name   		:  COMMON.H
// Description 		:  This file contains typedefine for the driver files	
// Ref. Docment		: 
// Revision History 	:

#ifndef		__COMMON_H__
#define		__COMMON_H__

// -----------------------------------------------------------------------------
// Include files
// -----------------------------------------------------------------------------

#include	<stdio.h>		
#include	"mdintype.h"
#include	"board.h"
#include	"mdin3xx.h"

// -----------------------------------------------------------------------------
// Struct/Union Types and define
// -----------------------------------------------------------------------------
// msg.c

typedef enum {
	BANK0 =0,
	BANK1,
	BANK2,
	BANK3,
	BANK4,
	BANK5,
	BANK6
} 	DEC_BANK;

typedef enum {
	NTSC = 0, PAL
} 	VFORMAT;

typedef struct {
	BYTE	cmd;
	BYTE    buf[50];
}	stPACKED NCDEC_MSG, *PNCDEC_MSG;


// -----------------------------------------------------------------------------
// External Variables declaration
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Exported function Prototype
// -----------------------------------------------------------------------------
// init.c
void uComOnChipInitial(void);

// ir.c
void IrReceivePulseDecode(void);
void IrCodeCommandParse(void);
void IrCodeTimeOutCounter(void);
void IrCodeMessageExecution(void);

// key.c
void ButtonMessageClassify(void);
void ButtonMessageExecution(void);

// serial.c
BYTE SerialRxHandler(void);
void SerialTxHandler(void);
BYTE Serial2RxHandler(void);
void Serial2TxHandler(void);

// msg.c
void MessageCtrlHandler(void);
#endif	/* __COMMON_H__ */
