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
#include	"common.h"
#include    "mdintype.h"
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
	NCRESOL_1280X720P,
	NCRESOL_1920X1080P
} NCDEC_OUTRESOL_t;

typedef enum {
	NC_ENCSRC_720X480 = 0,
	NC_ENCSRC_720X576,
	NC_ENCSRC_960X480,
	NC_ENCSRC_960X576,
	NC_ENCSRC_1280X720P,
	NC_ENCSRC_1920X1080P
} NCDEC_ENCSRC_t;

typedef enum {
	SVIDEO_TW = 0,
	CVBS_TW
} NCENC_SRCSEL_t;

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
	NORMAL_MODE,
	COMET_MODE
} NCDEC_PROT_t;


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
	DEMO_DEINT_FILM_DISABLE = 0,	// disables film mode
	DEMO_DEINT_FILM_32,				// enables 3:2 film mode only
	DEMO_DEINT_FILM_22,				// enables 2:2 film mode only
	DEMO_DEINT_FILM_ALL = 4			// enables both 3:2 and 2:2 film modes
}	DEMO_DEINT_FILM_t;

typedef enum {
	DEMO_DEINT_FAST_DISABLE = 0,	// disables fsat mode
	DEMO_DEINT_FAST_NORMAL,			// enables normal fast mode
	DEMO_DEINT_FAST_VERY			// enables very fast mode
}	DEMO_DEINT_FAST_t;

typedef enum {
	DEMO_DEINT_EDGE_DISABLE = 0,	// vertical (90-deg) interpolation only
	DEMO_DEINT_EDGE_45 = 2,			// 90-deg and 45-deg interpolation
	DEMO_DEINT_EDGE_26 = 3,			// up to 26-deg interpolation
	DEMO_DEINT_EDGE_ALL = 7			// all angle interpolation
}	DEMO_DEINT_EDGE_t;


typedef enum {
	DEMO_DISPLAY_PIP_OFF	= 0,	// disables pip/pop
	DEMO_DISPLAY_A_A_PIP,			// display pip crop
	DEMO_DISPLAY_A_B_PIP,			// display pip mainA auxB
	DEMO_DISPLAY_B_A_PIP,			// display pip mainB auxA
	DEMO_DISPLAY_FULL_POP,		// display pop full
	DEMO_DISPLAY_SIZE_POP		// display pop size
}	DEMO_DISPLAY_PIP_t;

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


void TEST_UpdateMFCCoef(void);
void TEST_SetUpdateMFC(BOOL OnOff);
void TEST_UpdateFRBSize(void);
void TEST_SetUpdateFRB(BOOL OnOff);
void TEST_UpdateRSTCtrl(void);
void TEST_SetUpdateRST(BOOL OnOff);

void NVP1918C_SetRegInitial(BYTE mode);
BYTE NVP1918C_GetVideoFormat(void);
void NVP1918C_SetVideoFormat(BYTE mode);
BYTE NVP1918C_GetVideoSystem(void);
void NVP1918C_SetVideoSystem(BYTE mode);
void NVP1918C_SetContrast(BYTE value);
void NVP1918C_SetBrightness(BYTE value);
void NVP1918C_SetSaturation(BYTE value);
void NVP1918C_SetHue(BYTE value);

void TW9960_ToggleInput(BYTE input);
void TW9960_DecoderInitial(PNCDEC_INFO pINFO, BYTE in_type);

#endif	/* __VIDEO_H__ */
