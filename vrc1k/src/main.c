/**
 *	@file   main.c
 *	@brief	
 *	@author luisfynn<tani223@pinetron.co.kr>
 *	@date   2014/10/14 09:36
 */

/* system include */
#include <stdio.h>
#include <string.h>
/* local include */
#include "stm32f10x_system.h"
#include "video.h"

BYTE RTC_Display_Enable = 0;
extern  WORD TMM_Old;

int main(int argc, char* argv[])
{
	BYTE time_change_detect = 0;
	
	NCDEC_INFO	ncDec;
	memset((PBYTE)&ncDec, 0, sizeof(NCDEC_INFO));

	System_Init();

	Video_Init(&ncDec);

	while(1){
		Debug_main();	
		VideoProcessHandler();
		//VideoHTXCtrlHandler();
		REMOCON_data_check();
		Video_Status_Check();
		RTC_Display_Enable = 1;
	
		if(TMM_Old != TMM)
		{
			TMM_Old = TMM;
			time_change_detect = 1;
		}

		if(time_change_detect)
		{
	//		CreateMDIN3xxGACFontInstance();
			time_change_detect = 0;
		}
	}
	return 0;
}

