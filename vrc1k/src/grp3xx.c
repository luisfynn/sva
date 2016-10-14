//----------------------------------------------------------------------------------------------------------------------
// (C) Copyright 2010  Macro Image Technology Co., LTd. , All rights reserved
// 
// This source code is the property of Macro Image Technology and is provided
// pursuant to a Software License Agreement. This code's reuse and distribution
// without Macro Image Technology's permission is strictly limited by the confidential
// information provisions of the Software License Agreement.
//-----------------------------------------------------------------------------------------------------------------------
//
// File Name   		:	GRP3xx.C
// Description 		:
// Ref. Docment		: 
// Revision History 	:

//--------------------------------------------------------------------------------------------------------------------------
// You must make drive functions for I2C read & I2C write.
//--------------------------------------------------------------------------------------------------------------------------
// static BYTE MDINI2C_Write(BYTE nID, WORD rAddr, PBYTE pBuff, WORD bytes)
// static BYTE MDINI2C_Read(BYTE nID, WORD rAddr, PBYTE pBuff, WORD bytes)

//--------------------------------------------------------------------------------------------------------------------------
// If you use MDIN380, you must make drive functions for BUS read & BUS write.
//--------------------------------------------------------------------------------------------------------------------------
// static BYTE MDINBUS_Write(BYTE nID, WORD rAddr, PBYTE pBuff, WORD bytes)
// static BYTE MDINBUS_Read(BYTE nID, WORD rAddr, PBYTE pBuff, WORD bytes)

//--------------------------------------------------------------------------------------------------------------------------
// If you use DMA-function, you must make drive functions for DMA read & DMA write.
//--------------------------------------------------------------------------------------------------------------------------
// MDIN_ERROR_t MDINBUS_DMAWrite(BYTE nID, DWORD rAddr, PBYTE pBuff, DWORD bytes)
// MDIN_ERROR_t MDINBUS_DMARead(BYTE nID, DWORD rAddr, PBYTE pBuff, DWORD bytes)

// ----------------------------------------------------------------------
// Include files
// ----------------------------------------------------------------------
#include	<string.h>
#include	"mdin3xx.h"
#include	"mdinaero.h"
#include	"mdinpalt.h"
#include	"mdintrue.h"

// ----------------------------------------------------------------------
// Static Global Data section variables
// ----------------------------------------------------------------------
static CURSOR_CTL_INFO stCurCTL;
static SPRITE_CTL_INFO stOSD[12];
static LAYER_CTL_INFO stLayer[3];

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
static void CreateMDIN3xxCursorInstance(void)
{
//	Suppose BMP is 32x32 8color.
//	Suppose the start address of BMP data is mdin3xx_aero_cnv_bmp.

	MDIN_BITMAP_INFO stBMP;
	DWORD e_addr = MDIN3xx_GetSizeOfBank()*2*8192;			// SDRAM end address

	// load cursor bmp
	stBMP.pBuff		= (PBYTE)mdin3xx_aero_cnv_bmp;
	stBMP.size		= sizeof(mdin3xx_aero_cnv_bmp);
	stBMP.addr		= e_addr-stBMP.size;					// BMP address [e_addr-BMP size]
	MDINOSD_SetBitmapData(stBMP.addr, stBMP.size, stBMP.pBuff);

	// set cursor
	memset(&stCurCTL, 0, sizeof(CURSOR_CTL_INFO));			// clear stCurCTL
	stCurCTL.ctrl			= CURSOR_32BIT_8COLOR;
	stCurCTL.alpha			= CURSOR_OPAQUE;
	stCurCTL.x				= 316;							// set position
	stCurCTL.y				= 124;
	stCurCTL.stBMP.w		= 32;							// set BMP size
	stCurCTL.stBMP.h		= 32;
	stCurCTL.stBMP.addr		= stBMP.addr;
	stCurCTL.stPAL.pBuff	= (PBYTE)mdin3xx_aero_rgb_pal;	// set palette
	stCurCTL.stPAL.size		= sizeof(mdin3xx_aero_rgb_pal);
	MDINCUR_SetCursorConfig(&stCurCTL);

	// enable cursor
	MDINCUR_EnableCursor(&stCurCTL, ON);	// cursor display ON
}

//--------------------------------------------------------------------------------------------------------------------------
static void CreateMDIN3xxTrueColorInstance(void)
{
//	Suppose BMP is 144x128 24bit-true color.
//	Suppose the start address of BMP data is mdin3xx_true_cnv_bmp.

	MDIN_BITMAP_INFO stBMP;
	DWORD e_addr = MDIN3xx_GetSizeOfBank()*2*8192;			// SDRAM end address

	// load true-color bmp
	stBMP.pBuff		= (PBYTE)mdin3xx_true_cnv_bmp;
	stBMP.size		= sizeof(mdin3xx_true_cnv_bmp);
	stBMP.addr		= e_addr-stBMP.size;					// BMP address [e_addr-BMP size]
	MDINOSD_SetBitmapData(stBMP.addr, stBMP.size, stBMP.pBuff);

	// set sprite3 in bmp-display
	memset(&stOSD[SPRITE_INDEX3], 0, sizeof(SPRITE_CTL_INFO));	// clear stOSD[SPRITE_INDEX3]
	stOSD[SPRITE_INDEX3].ctrl		= SPRITE_aRGB0888_24BIT;
	stOSD[SPRITE_INDEX3].alpha		= SPRITE_OPAQUE;
	stOSD[SPRITE_INDEX3].x			= 100;					// set position
	stOSD[SPRITE_INDEX3].y			= 60;
	stOSD[SPRITE_INDEX3].stBMP.w	= 144;					// set BMP size
	stOSD[SPRITE_INDEX3].stBMP.h	= 128;
	stOSD[SPRITE_INDEX3].stBMP.addr	= stBMP.addr;
	MDINOSD_SetSpriteConfig(&stOSD[SPRITE_INDEX3], SPRITE_INDEX3);

	// set layer0 in default mode
	memset(&stLayer[LAYER_INDEX0], 0, sizeof(LAYER_CTL_INFO));	// clear stLayer[LAYER_INDEX0]
	MDINOSD_SetLayerConfig(&stLayer[LAYER_INDEX0], LAYER_INDEX0);

	// enable sprite3
	MDINOSD_EnableSprite(&stOSD[SPRITE_INDEX3], ON);	// bitmap display ON
}

//--------------------------------------------------------------------------------------------------------------------------
static void CreateMDIN3xxPaletteInstance(void)
{
//	Suppose BMP is 144x128 8bit-palette color.
//	Suppose the start address of BMP data is mdin3xx_palt_cnv_bmp.
//	Suppose the start address of palette data is mdin3xx_palt_rgb_pal.

	MDIN_BITMAP_INFO stBMP;
	DWORD e_addr = MDIN3xx_GetSizeOfBank()*2*8192;			// SDRAM end address

	// load palette-color bmp
	stBMP.pBuff		= (PBYTE)mdin3xx_palt_cnv_bmp;
	stBMP.size		= sizeof(mdin3xx_palt_cnv_bmp);
	stBMP.addr		= e_addr-stBMP.size;					// BMP address [e_addr-BMP size]
	MDINOSD_SetBitmapData(stBMP.addr, stBMP.size, stBMP.pBuff);

	// set sprite4 in bmp display
	memset(&stOSD[SPRITE_INDEX4], 0, sizeof(SPRITE_CTL_INFO));	// clear stOSD[SPRITE_INDEX3]
	stOSD[SPRITE_INDEX4].ctrl		= SPRITE_8BITPALT_COLOR;
	stOSD[SPRITE_INDEX4].alpha		= SPRITE_OPAQUE;
	stOSD[SPRITE_INDEX4].x			= 388;					// set position
	stOSD[SPRITE_INDEX4].y			= 60;
	stOSD[SPRITE_INDEX4].stBMP.w	= 144;					// set BMP size
	stOSD[SPRITE_INDEX4].stBMP.h	= 128;
	stOSD[SPRITE_INDEX4].stBMP.addr	= stBMP.addr;
	MDINOSD_SetSpriteConfig(&stOSD[SPRITE_INDEX4], SPRITE_INDEX4);

	// set palette in bmp display => LAYER_INDEX1
	memset(&stLayer[LAYER_INDEX1], 0, sizeof(LAYER_CTL_INFO));		// clear stLayer[LAYER_INDEX1]
	MDINOSD_SetLayerConfig(&stLayer[LAYER_INDEX1], LAYER_INDEX1);
	MDINOSD_SetLayerPalette(&stLayer[LAYER_INDEX1], 0, sizeof(mdin3xx_palt_rgb_pal), (PBYTE)mdin3xx_palt_rgb_pal);

	// enable sprite4
	MDINOSD_EnableSprite(&stOSD[SPRITE_INDEX4], ON);	// bitmap display ON
}

/*  FILE_END_HERE */

