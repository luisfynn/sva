/**
 *	@file   osd.c
 *	@brief	
 *	@author luisfynn <@pinetron.com>
 *	@date   2014/10/14 14:52
 */

/* system include */
#include 	<stdio.h>
#include	<string.h>
/* local include */
#include	"osd.h"
//#include	"mdinfont.h"
//#include	"mdinpalt.h"

SBOX_CTL_INFO stSBOX[8];

void CreateSBoxInstance(void)
{
	memset(&stSBOX[SBOX_INDEX0], 0, sizeof(SBOX_CTL_INFO));
	stSBOX[SBOX_INDEX0].ctrl		= SBOX_BORDER_OFF | SBOX_PLANE_OFF;
//	stSBOX[SBOX_INDEX0].alpha		= 10;//h SBOX_OPAQUE;
	stSBOX[SBOX_INDEX0].alpha		= 31;//h SBOX_OPAQUE;
	stSBOX[SBOX_INDEX0].h_thk		= 1;
	stSBOX[SBOX_INDEX0].v_thk		= 1;
/*
	stSBOX[SBOX_INDEX0].stRECT.lx	= 0;		// SBOX area
	stSBOX[SBOX_INDEX0].stRECT.ly	= 0;
	stSBOX[SBOX_INDEX0].stRECT.rx	= 719;
	stSBOX[SBOX_INDEX0].stRECT.ry	= 479;
*/
//	stSBOX[SBOX_INDEX0].b_color		= RGB(0,64,128);	// SBOX border color
//	stSBOX[SBOX_INDEX0].b_color 	= RGB(0x72,0x23,0xD4); // SBOX border color // Blue modified on 06Mar2014
	stSBOX[SBOX_INDEX0].b_color 	= RGB(0x80,0x10,0x80); // SBOX border color // Black modified on 06Mar2014
//	stSBOX[SBOX_INDEX0].p_color		= RGB(0,255,0);		// SBOX plane color

	MDINOSD_SetSBoxConfig(&stSBOX[SBOX_INDEX0], SBOX_INDEX0);
/*
	memset(&stSBOX[SBOX_INDEX1], 0, sizeof(SBOX_CTL_INFO));
	stSBOX[SBOX_INDEX1].ctrl		= SBOX_BORDER_OFF | SBOX_PLANE_OFF;
	stSBOX[SBOX_INDEX1].alpha		= SBOX_OPAQUE;
	stSBOX[SBOX_INDEX1].h_thk		= 1;
	stSBOX[SBOX_INDEX1].v_thk		= 1;

	stSBOX[SBOX_INDEX1].b_color		= RGB(0,64,128);	// SBOX border color
//	stSBOX[SBOX_INDEX1].p_color		= RGB(0,255,255);	// SBOX plane color

	MDINOSD_SetSBoxConfig(&stSBOX[SBOX_INDEX1], SBOX_INDEX1);
*/
}

/*  FILE_END_HERE */
