/**
 *	@file   video380.c
 *	@brief	
 *	@author luisfynn <tani223@pinetron.com>
 *	@date   2014/10/14 14:45
 */

/* system include */
#include 	<stdio.h>
#include	<string.h>
/* local include */
#include    "i2c.h"
#include	"video.h"
#include	"osd.h"
#include    "mdinosd.h"
#include 	"stm32f10x_system.h"

MDIN_VIDEO_INFO		stVideo;
MDIN_INTER_WINDOW	stInterWND;
MDIN_VIDEO_WINDOW	stZOOM, stCROP;
NCDEC_INFO			ncDec;

extern SBOX_CTL_INFO stSBOX[8];

BYTE AdjInterWND,  InputSelect, InputSelOld,  SrcSyncInfo;
BYTE SrcMainFrmt, PrevSrcMainFrmt, SrcMainMode, PrevSrcMainMode;
BYTE OutMainFrmt, PrevOutMainFrmt, OutMainMode, PrevOutMainMode;
BYTE SrcAuxFrmt, PrevSrcAuxFrmt, SrcAuxMode, PrevSrcAuxMode;
BYTE OutAuxFrmt, PrevOutAuxFrmt, OutAuxMode, PrevOutAuxMode;
BYTE AdcVideoFrmt, PrevAdcFrmt, EncVideoFrmt, PrevEncFrmt;
BOOL fSyncParsed;

// ----------------------------------------------------------------------
// External Variable 
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Static Prototype Functions
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Static functions
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Exported functions
// ----------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------------------
static void MDIN3xx_SetHCLKMode(MDIN_HOST_CLK_MODE_t mode)
{
	switch (mode) {
		case MDIN_HCLK_CRYSTAL:	TEST_MODE2( LOW); TEST_MODE1( LOW); break;
		case MDIN_HCLK_MEM_DIV: TEST_MODE2(HIGH); TEST_MODE1(HIGH); break;
	
	#if	defined(SYSTEM_USE_MDIN380)	
		case MDIN_HCLK_HCLK_IN: TEST_MODE2( LOW); TEST_MODE1(HIGH); break;
	#endif	
	}
}

void MDIN3xx_AHDSetRegInitial(PNCDEC_INFO pINFO)
{
	WORD nID = 0;
	BYTE vformat, resolution;

///////////////// nextchip <-> mdin information ///////////////////////
	if( pINFO->vformat == NTSC) vformat = VID_VENC_NTSC_M;
	else						vformat = VID_VENC_PAL_B;
	
	if( pINFO->rx.resolution == NCRESOL_720X480)
	{
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) ==1){
			resolution = VIDSRC_720x480p60;
		}else{
			resolution = VIDSRC_720x480i60;
		}
	}
	else if( pINFO->rx.resolution == NCRESOL_720X576)		resolution = VIDSRC_720x576i50;
	else if( pINFO->rx.resolution == NCRESOL_960X480)		resolution = VIDSRC_960x480i60;
	else if( pINFO->rx.resolution == NCRESOL_960X576)		resolution = VIDSRC_960x576i50;
	else if( pINFO->rx.resolution == NCRESOL_1280X480)		resolution = VIDSRC_1280x480i60;
	else if( pINFO->rx.resolution == NCRESOL_1280X576)		resolution = VIDSRC_1280x576i50;
	else if( pINFO->rx.resolution == NCRESOL_1440X480)		resolution = VIDSRC_1440x480i60;
	else if( pINFO->rx.resolution == NCRESOL_1440X576)		resolution = VIDSRC_1440x576i50;
	else //if( pINFO->rx.resolution == NCRESOL_1280X720P)	
	{
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) ==1){
			resolution = VIDSRC_1280x720p60;				//ADV7611 USE
		}else{
			if(vformat == VID_VENC_NTSC_M) resolution = VIDSRC_1280x720p30;
			else							resolution = VIDSRC_1280x720p25;
		}
	}

///////////////////////////////////////////////////////////////////////

#if	!defined(SYSTEM_USE_PCI_HIF)&&defined(SYSTEM_USE_MCLK202)
	MDIN3xx_SetHCLKMode(MDIN_HCLK_CRYSTAL);	// set HCLK to XTAL
	MDINDLY_mSec(50);	// delay 50ms
#endif
	while (nID!=0x85) MDIN3xx_GetChipID(&nID);	// get chip-id
	MDIN3xx_EnableMainDisplay(OFF);		// set main display off
	MDIN3xx_SetMemoryConfig();			// initialize DDR memory

#if	!defined(SYSTEM_USE_PCI_HIF)&&defined(SYSTEM_USE_MCLK202)
	MDIN3xx_SetHCLKMode(MDIN_HCLK_MEM_DIV);	// set HCLK to MCLK/2
	MDINDLY_mSec(10);	// delay 10ms
#endif

	MDIN3xx_SetVCLKPLLSource(MDIN_PLL_SOURCE_XTAL);		// set PLL source
	MDIN3xx_EnableClockDrive(MDIN_CLK_DRV_ALL, ON);

	MDIN3xx_SetInDataMapMode(MDIN_IN_DATA24_MAP0);	// set 24pin mode in-data map0 
	MDIN3xx_SetDIGOutMapMode(MDIN_DIG_OUT_M_MAP9);	// main -> digital out enable
	MDINOSD_SetBGLayerColor(RGB(128,128,128));		// set BG-Layer color
	MDINOSD_SetBGBoxColor(RGB(0,64,128));			// set BG-BOX color
	MDINOSD_SetAuxBGColor();  						//aux background color;
	
	MDIN3xx_SetFrontNRFilterCoef(NULL);		// set default frontNR filter coef
	MDINAUX_SetFrontNRFilterCoef(NULL);		// set default frontNR filter coef
	MDIN3xx_SetColorEnFilterCoef(NULL);		// set default color enhancer coef
	MDIN3xx_SetBlockNRFilterCoef(NULL);		// set default blockNR filter coef
	MDIN3xx_SetMosquitFilterCoef(NULL);		// set default mosquit filter coef
	MDIN3xx_SetColorTonFilterCoef(NULL);	// set default colorton filter coef
	MDIN3xx_SetPeakingFilterCoef(NULL);		// set default peaking filter coef

	MDIN3xx_EnableLTI(OFF);					// set LTI off
	MDIN3xx_EnableCTI(OFF);					// set CTI off
	MDIN3xx_SetPeakingFilterLevel(0x20);	// set peaking gain
	MDIN3xx_EnablePeakingFilter(ON);		// set peaking on

	MDIN3xx_EnableFrontNRFilter(OFF);		// set frontNR off
	MDIN3xx_EnableBWExtension(OFF);			// set B/W extension off
	
	MDIN3xx_SetIPCBlock();		// initialize IPC block (3DNR gain is 37)

	memset((PBYTE)&stVideo, 0, sizeof(MDIN_VIDEO_INFO));
	MDIN3xx_SetMFCHYFilterCoef(&stVideo, NULL);	// set default MFC filters
	MDIN3xx_SetMFCHCFilterCoef(&stVideo, NULL); 
	MDIN3xx_SetMFCVYFilterCoef(&stVideo, NULL);
	MDIN3xx_SetMFCVCFilterCoef(&stVideo, NULL);

	// set aux display ON
	stVideo.dspFLAG = MDIN_AUX_DISPLAY_ON | MDIN_AUX_FREEZE_OFF;

	// set video path
	stVideo.srcPATH = PATH_MAIN_B_AUX_B;	// set main is B, aux is B 
	stVideo.dacPATH = DAC_PATH_MAIN_OUT;	// set main onlyde // 20140402
	stVideo.encPATH = VENC_PATH_PORT_A;		// set venc is port a 


	// define video format of PORTA-INPUT
	stVideo.stSRC_a.frmt = resolution; 
	stVideo.stSRC_a.mode = MDIN_SRC_MUX656_8; 
	stVideo.stOUT_m.fine = MDIN_SYNC_FREERUN;	// set main outsync free-run
	
	// define video format of MAIN-OUTPUT
	switch(vformat)
	{
		case VID_VENC_NTSC_M : stVideo.stOUT_m.frmt = VIDOUT_1280x720p30; break;
		case VID_VENC_PAL_B  : stVideo.stOUT_m.frmt = VIDOUT_1280x720p25; break;
	}

	stVideo.stOUT_m.mode = MDIN_OUT_MUX656_8;
	stVideo.stOUT_m.fine = MDIN_SYNC_FREERUN;	// set main outsync free-run

	if(vformat == VID_VENC_NTSC_M)
	{
		stVideo.stOUT_m.brightness = 0x80;			// set main picture factor
		stVideo.stOUT_m.contrast = 0x68;
		stVideo.stOUT_m.saturation = 0x78;
		stVideo.stOUT_m.hue = 0x80;
	
		stVideo.stOUT_x.brightness = 0x80;			// set aux picture factor
		stVideo.stOUT_x.contrast = 0x68;
		stVideo.stOUT_x.saturation = 0x78;
		stVideo.stOUT_x.hue = 0x80;
	}
	else
	{
		stVideo.stOUT_m.brightness = 0x80;			// set main picture factor
		stVideo.stOUT_m.contrast = 0x68;
		stVideo.stOUT_m.saturation = 0x78;
		stVideo.stOUT_m.hue = 0x80;
	
		stVideo.stOUT_x.brightness = 0x80;			// set aux picture factor
		stVideo.stOUT_x.contrast = 0x68;
		stVideo.stOUT_x.saturation = 0x78;
		stVideo.stOUT_x.hue = 0x80;
}

#if RGB_GAIN_OFFSET_TUNE == 1
	stVideo.stOUT_m.r_gain = 128;				// set main gain/offset
	stVideo.stOUT_m.g_gain = 128;
	stVideo.stOUT_m.b_gain = 128;
	stVideo.stOUT_m.r_offset = 128;
	stVideo.stOUT_m.g_offset = 128;
	stVideo.stOUT_m.b_offset = 128;
#endif

	// define video format of IPC-block
	stVideo.stIPC_m.mode = MDIN_DEINT_ADAPTIVE;
	//stVideo.stSRC_m.stATTB.attb = MDIN_SCANTYPE_PROG; 			//Do not use
	stVideo.stIPC_m.film = MDIN_DEINT_FILM_OFF;
	stVideo.stIPC_m.gain = 40;
	stVideo.stIPC_m.fine = MDIN_DEINT_3DNR_OFF | MDIN_DEINT_CCS_OFF;  //cross color reduction on : MDIN_DEINT_CCS_OFF

	// define map of frame buffer
	stVideo.stMAP_m.frmt = MDIN_MAP_AUX_ON_NR_OFF;	// when MDIN_DEINT_3DNR_ON

	// define video format of PORTB-INPUT
	stVideo.stSRC_b.frmt = resolution; 		
	stVideo.stSRC_b.mode = MDIN_SRC_MUX656_8;
	stVideo.stSRC_b.fine = MDIN_SYNC_FREERUN;

	// define video format of AUX-OUTPUT : HDMI OUTPUT
	stVideo.stOUT_x.frmt = VIDOUT_1280x720p60;
	stVideo.stOUT_x.mode = MDIN_OUT_EMB422_8;
	stVideo.stOUT_x.fine = MDIN_SYNC_FREERUN;	// set aux outsync free-run

#if RGB_GAIN_OFFSET_TUNE == 1
	stVideo.stOUT_x.r_gain = 128;				// set aux gain/offset
	stVideo.stOUT_x.g_gain = 128;
	stVideo.stOUT_x.b_gain = 128;
	stVideo.stOUT_x.r_offset = 128;
	stVideo.stOUT_x.g_offset = 128;
	stVideo.stOUT_x.b_offset = 128;
#endif

	// define video format of video encoder
	//stVideo.encFRMT = vformat;

	// define video format of HDMI-OUTPUT
	stVideo.stVID_h.mode  = HDMI_OUT_RGB444_8;
	stVideo.stVID_h.fine  = HDMI_CLK_EDGE_RISE;// | HDMI_USE_FORCE_DVI; // when HDMI_USE_FORCE_DVI is removed, screen can be blinked.
	
	stVideo.stAUD_h.frmt  = AUDIO_INPUT_I2S_0;						// audio input format
	stVideo.stAUD_h.freq  = AUDIO_MCLK_256Fs | AUDIO_FREQ_48kHz;	// sampling frequency
	stVideo.stAUD_h.fine  = AUDIO_MAX24B_MINUS0 | AUDIO_SD_JUST_LEFT | AUDIO_WS_POLAR_HIGH |
							AUDIO_SCK_EDGE_RISE | AUDIO_SD_MSB_FIRST | AUDIO_SD_1ST_SHIFT;

	MDINHTX_SetHDMIBlock(&stVideo);		// initialize HDMI block
	
	stVideo.exeFLAG = MDIN_UPDATE_MAINFMT;	// execution of video process
	MDIN3xx_VideoProcess(&stVideo);			// mdin3xx main video process
	
	// define window for inter-area
	stInterWND.lx = 315;	stInterWND.rx = 405;
	stInterWND.ly = 90;		stInterWND.ry = 150;

	MDIN3xx_SetDeintInterWND(&stInterWND, MDIN_INTER_BLOCK0);
	MDIN3xx_EnableDeintInterWND(MDIN_INTER_BLOCK0, OFF);
	
	// character OSD control
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

#if 0
	//OSD Controll
	GPIO_SetBits(GPIOB,GPIO_Pin_14);
	GPIO_SetBits(GPIOB,GPIO_Pin_15);

	//OSD Display
	CreateMDIN3xxGACFontInstance();

	//OSD Controll
	GPIO_ResetBits(GPIOB,GPIO_Pin_14);
	GPIO_ResetBits(GPIOB,GPIO_Pin_15);
#endif 

	// define variable for EDK application
	InputSelOld = 0xff;	

	PrevSrcMainFrmt = 0xff;	SrcMainFrmt = stVideo.stSRC_a.frmt;
	PrevSrcMainMode = 0xff;	SrcMainMode = stVideo.stSRC_a.mode;

	PrevOutMainFrmt = 0xff;	OutMainFrmt = stVideo.stOUT_m.frmt;
	PrevOutMainMode = 0xff;	OutMainMode = stVideo.stOUT_m.mode;

	PrevSrcAuxFrmt = 0xff; SrcAuxFrmt = stVideo.stSRC_b.frmt;
	PrevSrcAuxMode = 0xff; SrcAuxMode = stVideo.stSRC_b.mode;

	PrevOutAuxFrmt = 0xff; OutAuxFrmt = stVideo.stOUT_x.frmt;
	PrevOutAuxMode = 0xff; OutAuxMode = stVideo.stOUT_x.mode;

	PrevEncFrmt = 0xff;	EncVideoFrmt = stVideo.encFRMT;

	stVideo.exeFLAG = MDIN_UPDATE_MAINFMT;	// execution of video process

	printf("\rMDIN3xx initialize Complete\r\n");
}

static void SetSBoxAreaRefresh(void)
{
	switch (stVideo.stOUT_m.frmt) {
		case VIDOUT_720x480p60: 		MDINOSD_SetSBoxArea(&stSBOX[0], 0, 0, 719, 479); break;
		case VIDOUT_720x576p50: 		MDINOSD_SetSBoxArea(&stSBOX[0], 0, 0, 719, 575); break;
		case VIDOUT_960x480p60: 		MDINOSD_SetSBoxArea(&stSBOX[0], 0, 0, 959, 479); break;
		case VIDOUT_960x576p50: 		MDINOSD_SetSBoxArea(&stSBOX[0], 0, 0, 959, 575); break;
		case VIDOUT_1280x480p60: 	MDINOSD_SetSBoxArea(&stSBOX[0], 0, 0, 1279, 479); break;
		case VIDOUT_1280x576p50: 	MDINOSD_SetSBoxArea(&stSBOX[0], 0, 0, 1279, 575); break;
		case VIDOUT_1440x480p60: 	MDINOSD_SetSBoxArea(&stSBOX[0], 0, 0, 1439, 479); break;
		case VIDOUT_1440x576p50: 	MDINOSD_SetSBoxArea(&stSBOX[0], 0, 0, 1439, 575); break;
	}
}


//--------------------------------------------------------------------------------------------------
static void SetOSDMenuRefresh(void)
{
	SetSBoxAreaRefresh();				// refresh OSD-Sbox
	MDINOSD_EnableSBoxBorder(&stSBOX[0], ON);
	MDIN3xx_EnableAuxWithMainOSD(&stVideo, ON);
}

void VideoProcessHandler(void)
{
	MDIN3xx_EnableAuxDisplay(&stVideo, ON);
	MDIN3xx_EnableMainDisplay(ON);

	if (stVideo.exeFLAG==0)	return;		// not change video formats

	MDIN3xx_VideoProcess(&stVideo);		// mdin3xx main video process
	//SetOSDMenuRefresh(); 				//for framebuffer map bug
	
	if(ncDec.rx.resolution == NCRESOL_1280X720P)	MDIN3xx_SetCDeint(ON);

	//test pattern
//	MDIN3xx_SetOutTestPattern(MDIN_OUT_TEST_COLOR);
//	MDIN3xx_SetSrcTestPattern(pINFO, MDIN_IN_TEST_WINDOW);
//	MDIN3xx_SetDelayVCLK_OUT(7);	

	MDINHIF_RegField(MDIN_LOCAL_ID, 0x0A5,  8, 2, 2);
	MDINHIF_RegField(MDIN_LOCAL_ID, 0x145,  8, 1, 1);

	MDINHIF_RegField(MDIN_HOST_ID, 0x046,  3, 2, 0);
	MDINHIF_RegField(MDIN_HOST_ID, 0x047, 14, 2, 2);

}

void VideoHTXCtrlHandler(void)
{
	MDINHTX_CtrlHandler(&stVideo);
}

/*  FILE_END_HERE */
