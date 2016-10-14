//----------------------------------------------------------------------------------------------------------------------
// (C) Copyright 2008  Macro Image Technology Co., LTd. , All rights reserved
// 
// This source code is the property of Macro Image Technology and is provided
// pursuant to a Software License Agreement. This code's reuse and distribution
// without Macro Image Technology's permission is strictly limited by the confidential
// information provisions of the Software License Agreement.
//-----------------------------------------------------------------------------------------------------------------------
//
// File Name   		:  VIDEO.H
// Description 		:  This file contains typedefine for the driver files	
// Ref. Docment		: 
// Revision History 	:

#ifndef		__VIDEO_H__
#define		__VIDEO_H__

// -----------------------------------------------------------------------------
// Include files
// -----------------------------------------------------------------------------
#include    "mdin3xx.h"
// -----------------------------------------------------------------------------
// Struct/Union Types and define
// -----------------------------------------------------------------------------
// video.c
typedef	struct
{
	BYTE    enc_resol;
	BYTE    enc_inputclk;
	BYTE	enc_input_bus;
	BYTE	comet;
}	stPACKED NCTX_INFO, *PNCTX_INFO;

typedef	struct
{
	BYTE	resolution;
	BYTE    pllclk;
	BYTE	vclk;
}	stPACKED NCRX_INFO, *PNCRX_INFO;

typedef struct {
	BYTE	vformat;
	BYTE	dispmode;
	NCRX_INFO	rx;
	NCTX_INFO	tx;
}	stPACKED NCDEC_INFO, *PNCDEC_INFO;

typedef enum {
	NCRESOL_720X480 = 0,
	NCRESOL_720X576,
	NCRESOL_960X480,	
	NCRESOL_960X576,	
	NCRESOL_1280X480,
	NCRESOL_1280X576,
	NCRESOL_1440X480,
	NCRESOL_1440X576,
	NCRESOL_1280X720P
} NCDEC_OUTRESOL_t;

typedef enum {
	NC_ENCSRC_720X480 = 0,
	NC_ENCSRC_720X576,
	NC_ENCSRC_960X480,
	NC_ENCSRC_960X576,
	NC_ENCSRC_1280X720P
} NCDEC_ENCSRC_t;

typedef enum {
	ENC_INBUS_8B = 0,
	ENC_INBUS_16B
} NCENC_BUSSIZE_t;

typedef enum {
	VDCNV_NTSC = 0,
	VDCNV_PAL,
	VDCNV_AUTO,
	VDCNV_NONE
} NCDEC_VFORMAT_t;


typedef enum {
	PLL_27M=0,
	PLL_36M
} NCDEC_PLLCLK_t;

typedef enum {
	VCLK_27M=0,
	VCLK_54M,
	VCLK_108M,
	VCLK_36M,
	VCLK_72M,
	VCLK_144M
} NCDEC_DECCLK_t;

typedef enum {
	ENC_CLK_37M=0,
	ENC_CLK_74M,
	ENC_CLK_148M
} NCDEC_ENCCLK_t;

typedef enum {                                                                                  
     BANK0 =0,                                                                                 
     BANK1,                                                                                   
     BANK2,                                                                                     
     BANK3,                                                                                
     BANK4,                                                                         
     BANK5,                                                                  
     BANK6                                                              
}   DEC_BANK;                                                       
                                                                 
typedef enum {                                              
    NTSC = 0, PAL                                       
}   VFORMAT;                                        
                                                  
typedef struct {                              
     BYTE    cmd;                          
     BYTE    buf[50];                 
}   stPACKED NCDEC_MSG, *PNCDEC_MSG;  

// ----------------------------------------------------------------------
// Exported Variables
// ----------------------------------------------------------------------
extern MDIN_VIDEO_INFO		stVideo;
extern MDIN_INTER_WINDOW	stInterWND;
extern MDIN_VIDEO_WINDOW	stZOOM, stCROP;

extern BYTE AdjInterWND,  InputSelect, InputSelOld,  SrcSyncInfo;
extern BYTE SrcMainFrmt, PrevSrcMainFrmt, SrcMainMode, PrevSrcMainMode;
extern BYTE OutMainFrmt, PrevOutMainFrmt, OutMainMode, PrevOutMainMode;
extern BYTE SrcAuxFrmt, PrevSrcAuxFrmt, SrcAuxMode, PrevSrcAuxMode;
extern BYTE OutAuxFrmt, PrevOutAuxFrmt, OutAuxMode, PrevOutAuxMode;
extern BYTE AdcVideoFrmt, PrevAdcFrmt, EncVideoFrmt, PrevEncFrmt;

// -----------------------------------------------------------------------------
// Exported function Prototype
// -----------------------------------------------------------------------------
// video.c
void HDRX_SetRegInitial(void);
void CreateVideoInstance(void);
void VideoProcessHandler(void);
void VideoHTXCtrlHandler(void);
void VideoSetEdgeEnhance(BYTE mode);
void VideoSetAspectRatio(BYTE mode);
void VideoSetOverScanning(BYTE mode);
void VideoSetMFCHYFilter(BYTE mode);
void VideoSetMFCHCFilter(BYTE mode);
void VideoSetMFCVYFilter(BYTE mode);
void VideoSetMFCVCFilter(BYTE mode);
void VideoSetOutCSCCoef(BYTE mode);
void VideoSetInCSCCoef(BYTE mode);
void VideoSetIPCNoiseRobust1(BOOL OnOff);
void VideoSetIPCNoiseRobust2(BOOL OnOff);
void VideoSetIPCSlowMotion(BOOL OnOff);
void DecoderInitial(PNCDEC_INFO pINFO);
#endif	/* __VIDEO_H__ */
