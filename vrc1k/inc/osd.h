/**
 *	@file   osd.h
 *	@brief	
 *	@author luisfynn <@pinetron.com>
 *	@date   2014/10/14 14:56
 */

#ifndef _OSD_HEADER_
#define _OSD_HEADER_

/* system include */

/* local include */
#include	"video.h"
/* external variable & function */

typedef	enum {
	icnWidth	= 0,
	icnHeight
}	ICON_SIZE_t;	

typedef	struct
{
	DWORD	addr_m;
	DWORD	addr_s;

	WORD	w_m;
	WORD	h_m;
	WORD	w_s;
	WORD	h_s;

}	stPACKED OSD_4CHVIEW_INFO, *POSD_4CHVIEW_INFO;

typedef	struct
{
	DWORD	addr_rom;
	DWORD	addr_mem;

	WORD	w;
	WORD	h;
	DWORD	size;
}	stPACKED OSD_ICON_INFO, *POSD_ICON_INFO;	//by hungry 2013.05.22 for cmx

#define		OSD_RGB_PALETTE		0
#define		OSD_YUV_PALETTE		1

//by hungry 2013.05.14 for cmx
//#define	BASE_ADDR_MEM		(DWORD)MDIN3xx_GetSizeOfBank()*2*8192-32*112-384*152-32*32	//font + text_menu + cursor
#define	BASE_ADDR_MEM		(DWORD)MDIN3xx_GetSizeOfBank()*2*8192-32*112-384*152-32*32 -512	//font + text_menu + cursor	//by hungry 2013.06.07
#define	DUMMY_MEM			2048

//by hungry 2013.05.22 for cmx
//sprite3 : back ground region
#define	SPRITE3_W			0
#define	SPRITE3_H			0
#define	SPRITE3_X			0
#define	SPRITE3_Y			0
#define	SPRITE3_SIZE		SPRITE3_W * SPRITE3_H * 2
#define	SPRITE3_ADDR_MEM	BASE_ADDR_MEM - SPRITE3_SIZE - DUMMY_MEM	//by hungry 2013.06.13

//sprite4 : main menu region
#define	SPRITE4_W			0
#define	SPRITE4_H			0
#define	SPRITE4_X			0
#define	SPRITE4_Y			0
#define	SPRITE4_SIZE		SPRITE4_W * SPRITE4_H * 2
#define	SPRITE4_ADDR_MEM	SPRITE3_ADDR_MEM - SPRITE4_SIZE - DUMMY_MEM

//sprite5 : temporary region-1
#define	SPRITE5_W			800
#define	SPRITE5_H			480
#define	SPRITE5_X			0
#define	SPRITE5_Y			0
#define	SPRITE5_SIZE		SPRITE5_W * SPRITE5_H * 2
#define	SPRITE5_ADDR_MEM	SPRITE4_ADDR_MEM - SPRITE5_SIZE - DUMMY_MEM

//sprite6 : temporary region-2
#define	SPRITE6_W			800
#define	SPRITE6_H			480
#define	SPRITE6_X			0
#define	SPRITE6_Y			0
#define	SPRITE6_SIZE		SPRITE6_W * SPRITE6_H * 2
#define	SPRITE6_ADDR_MEM	SPRITE5_ADDR_MEM - SPRITE6_SIZE - DUMMY_MEM

//sprite7 : temporary region-3
#define	SPRITE7_W			800
#define	SPRITE7_H			480
#define	SPRITE7_X			0
#define	SPRITE7_Y			0
#define	SPRITE7_SIZE		SPRITE7_W * SPRITE7_H * 2
#define	SPRITE7_ADDR_MEM	SPRITE6_ADDR_MEM - SPRITE7_SIZE - DUMMY_MEM

#define	ICON_ADDR_MEM		(SPRITE7_ADDR_MEM - DUMMY_MEM)

#endif /* _OSD_HEADER_*/

