/**
 *	@file   main.c
 *	@brief  	
 *	@author luisfynn(tani223@pinetron.co.kr)
 *	@date   2015/03/16 09:34
 */

/* system include */
/* local include */
#include "stm32f10x.h"
#include "FreeRTOS.h"
#include "task.h"
#include "xuart.h"
#include "mdin3xx.h"

extern NCDEC_INFO	ncDec;

static void VideoFormatCheck(PNCDEC_INFO pINFO);
static void VideoResolCheck(PNCDEC_INFO pINFO);

static BYTE VideoStatusBuff[10]={0,};
static BYTE VideoBackupBuff[10]={0,};
static BYTE VideoDetectionCheck = 0;
static BYTE WatchDogCounter = 0;

int main()
{
	memset((PBYTE)&ncDec, 0, sizeof(NCDEC_INFO));

    prvSetupHardware();					/*initialize hardware*/

	VideoFormatCheck(&ncDec);			/*NVP6114 or ADV7611 INIT & AUTO detection */
	MDIN3xx_AHDSetRegInitial(&ncDec);	/*MDIN380 INIT*/
	NVP6011_CommonInit(&ncDec);			/*NVP6011 INIT*/

    xTaskCreate( prvUartTask,(signed portCHAR*)"xUART", configMINIMAL_STACK_SIZE + 64, NULL, UART_TASK_PRIORITY, NULL );
    xTaskCreate( prvMdin380Task,(signed portCHAR*)"MDIN380", configMINIMAL_STACK_SIZE + 64, NULL, MDIN_TASK_PRIORITY, NULL );
    xTaskCreate( prvVideoCheckTask,(signed portCHAR*)"VideoCheck", configMINIMAL_STACK_SIZE + 64, &ncDec, VIDEOCHECK_TASK_PRIORITY, NULL );

    vTaskStartScheduler();  			/* Starts the real time kernel tick processing  */

    return FALSE;
}

static void VideoFormatCheck(PNCDEC_INFO pINFO)
{
	BYTE sum = 0;
	BYTE Buff[3] = {0,};
	/*        		VideoType(isHDMI?)		VideoStyle_A(isAHD?)	VideoStyle_B(isPAL?)
	 *					0						0						0
	 *					0						0						1
	 *					0						1						0
	 *					0						1						1
	 *					1						0						0
	 *					1						0						1
	 *					1						1						0
	 *					1						1						1			*/
	
	Buff[0] = VideoType;
	Buff[1] = VideoStyle_A;
	Buff[2] = VideoStyle_B;

	sum = Buff[0] <<2 | Buff[1] <<1 | Buff[2];

	#if defined(AHD_DEBUG)
	xprintf("sum : %x \r\n", sum);
	xprintf("VideoType*4: %x \r\n", VideoType*4);
	xprintf("VideoStyle_A*2: %x \r\n", VideoStyle_A*2);
	xprintf("VideoStyle_B: %x \r\n", VideoStyle_B);
	#endif

	switch(sum)
	{
		case 0x0:
			pINFO->rx.resolution = NCRESOL_960X480;
			pINFO->vformat = NTSC;	
			break;
		case 0x1:
			pINFO->rx.resolution = NCRESOL_960X576;
			pINFO->vformat = PAL;	
			break;
		case 0x2:		//AHD-auto detection
			pINFO->rx.resolution = NCRESOL_1280X720P;
			NVP6114_CommonInit(&ncDec);	
			break;
		case 0x3:		//AHD-auto detection
			pINFO->rx.resolution = NCRESOL_1280X720P;
			NVP6114_CommonInit(&ncDec);	
			break;
		default :
			ADV7611_INIT(&ncDec, RX_OPMODE_HDMI);
			break;
	}

	while(sum > 1 && !VideoDetectionCheck)											/* AHD or HDMI VIDEO Auto detection */
	{
		VideoResolCheck(&ncDec);
		#if defined(AHD_DEBUG)
		xprintf("Video Dectection Check: %d\r\n", VideoDetectionCheck);
		#endif
	}
	(sum > 3)? 	xprintf("HDMI Video selected\r\n") : NVP6114_CommonInit(&ncDec);	/*NVP6114 or ADV7611 Init*/
}

static void prvSetupHardware( void )
{
	RCC_DeInit();					/* RCC system reset(for debug purpose) */	
	RCC_HSEConfig(RCC_HSE_ON);		/* Enable HSE(High SPeed External Clock) */
	HSEStartUpStatus = RCC_WaitForHSEStartUp(); 	 /* Wait till HSE is ready */

	if (HSEStartUpStatus == SUCCESS)
	{
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable); 	/* Enable Prefetch Buffer(FLASH access control enable) */
		FLASH_SetLatency(FLASH_Latency_2); 						/* Flash 2 wait state */
		RCC_HCLKConfig(RCC_SYSCLK_Div1);						/* HCLK = SYSCLK */
		RCC_PCLK2Config(RCC_HCLK_Div1);							/* PCLK2 = HCLK */
		RCC_PCLK1Config(RCC_HCLK_Div2);							/* PCLK1 = HCLK/2 */
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);	/* PLLCLK = 8MHz * 9 = 72 MHz */
		RCC_PLLCmd(ENABLE);										/* Enable PLL */

		while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)		/* Wait till PLL is ready */
		{
		}

		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);				/* Select PLL as system clock source */

		while (RCC_GetSYSCLKSource() != 0x08)					/* Wait till PLL is used as system clock source */
		{
		}
	}

	if (RCC_GetFlagStatus(RCC_FLAG_WWDGRST) != RESET)			/* Check if the system has resumed from WWDG reset */
	{ 															/* WWDGRST flag set */
		RCC_ClearFlag();										/* Clear reset flags */
	}
	else
	{ 															/* WWDGRST flag is not set */
	}

    NVIC_SetVectorTable( NVIC_VectTab_FLASH, 0x0 );				/* Set the Vector Table base address at 0x08000000 */
    NVIC_PriorityGroupConfig( NVIC_PriorityGroup_1 );

    RCC_APB2PeriphClockCmd(    RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB				/* Enable GPIOA, GPIOB, GPIOC, GPIOD, GPIOE  and AFIO clocks */
           						| RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE | RCC_APB2Periph_AFIO, ENABLE );

    xuart_init(115200);											/* Enable UART1 w/ 115200 baud */
	prvTimerSet();												/* Enable TIM2 */
	prvPowerStatus(ON);											/* Enable Power supply & Device Reset */
	prvDeviceRst();
}

static void prvPowerStatus(BYTE status)
{
	xprintf("\r====================================\r\n");
	xprintf("\r======AHD REPEATER/CONVERTER========\r\n");
	xprintf("\r======VERSION 1.0           ========\r\n");
	xprintf("\r====================================\r\n");
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	(status)?	GPIO_SetBits(GPIOD,GPIO_Pin_2) : GPIO_ResetBits(GPIOD,GPIO_Pin_2); 
}

static void prvDeviceRst(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
 
	GPIO_ResetBits(GPIOC,GPIO_Pin_7);
	MDINDLY_mSec(100);	
	GPIO_SetBits(GPIOC,GPIO_Pin_7);
}

static void AHD_1280X720P30(PNCDEC_INFO pINFO)
{
	#if defined(AHD_DEBUG)
	xprintf("AHD Video 1280x720p30 Selected\r\n");
	#endif
	pINFO->vformat = NTSC;
	pINFO->rx.resolution = NCRESOL_1280X720P;

	VideoDetectionCheck = TRUE;
}

static void AHD_1280X720P25(PNCDEC_INFO pINFO)
{
	#if defined(AHD_DEBUG)
	xprintf("AHD Video 1280x720p25 Selected\r\n");
	#endif
	pINFO->vformat = PAL;
	pINFO->rx.resolution = NCRESOL_1280X720P;
	
	VideoDetectionCheck = TRUE;
}

static void VideoDetectErr(void)
{
	VideoDetectionCheck = FALSE;
}

static void AHD_Video(PNCDEC_INFO pINFO)
{
	#if defined(AHD_DEBUG)
	xprintf("AHD Video Selected\r\n");
	#endif
	BYTE sum;

	sum = VideoStatusBuff[3]<<1 | VideoStatusBuff[4];
	(sum == 0x2)? 	AHD_1280X720P30(&ncDec) : (sum ==0x1)? AHD_1280X720P25(&ncDec)	: VideoDetectErr();
}

static void NTSC_720X480I60(PNCDEC_INFO pINFO)
{
	#if defined(AHD_DEBUG)
	xprintf("Composite Video NTSC Selected\r\n");
	#endif
	pINFO->vformat = NTSC;
	pINFO->rx.resolution = NCRESOL_720X480;
	VideoDetectionCheck = TRUE;
}

static void PAL_720X576I50(PNCDEC_INFO pINFO)
{
	#if defined(AHD_DEBUG)
	xprintf("Composite Video PAL Selected\r\n");
	#endif
	pINFO->vformat = PAL;
	pINFO->rx.resolution = NCRESOL_720X576;
	VideoDetectionCheck = TRUE;
}

static void CompositeVideo(PNCDEC_INFO pINFO)
{
#if 0 //RSV
	#if defined(AHD_DEBUG)
	xprintf("Composite Video Selected\r\n");
	#endif
	(VideoStyle_B)? 	NTSC_720X480I60(&ncDec) : PAL_720X576I50(&ncDec);
#endif
}

static void AnalogVideo(PNCDEC_INFO pINFO)
{
	BYTE i;

	I2C1_ByteWrite(I2C_NVP6114_ADDR, 0xFF, BANK3  );
	I2C1_ByteWrite(I2C_NVP6114_ADDR, 0xD4, 0x80 );
	I2C1_ByteWrite(I2C_NVP6114_ADDR, 0xD5, 0x80 );
	I2C1_ByteWrite(I2C_NVP6114_ADDR, 0xFF, BANK1  );

	for(i=0; i<2; i++)
	{
		I2C1_ByteRead(I2C_NVP6114_ADDR, 0xED+i, VideoStatusBuff+i+3 );
	}

	VideoStatusBuff[0] = VideoType;
	VideoStatusBuff[1] = VideoStyle_A;
	VideoStatusBuff[2] = VideoStyle_B;
	VideoStatusBuff[3] = (VideoStatusBuff[3]>>4) & 0x1;
	VideoStatusBuff[4] = (VideoStatusBuff[4]>>4) & 0x1;

	#if	defined(AHD_DEBUG)
	for(i=0; i<5; i++)	xprintf("VideoStatusBuff[%d]=[%d]\r\n", i, VideoStatusBuff[i]); 
	#endif
	(VideoStyle_A)?					AHD_Video(&ncDec) : CompositeVideo(&ncDec);
}

static void HDMIVideo(PNCDEC_INFO pINFO)
{
	xprintf("HDMI video selected\r\n");
}

static void VideoResolCheck(PNCDEC_INFO pINFO)
{
	BYTE i;

	(VideoType)?	HDMIVideo(&ncDec) : AnalogVideo(&ncDec);
	memcpy(VideoBackupBuff,VideoStatusBuff,sizeof(VideoBackupBuff));
}

static void prvUartTask( void *pvParameters )
{
    char Buff[50];

    for( ;; )
    {
        xgets(Buff, 50);
	}
}

static void prvMdin380Task( void *pvParameters )
{
	for(;;)
	{
		VideoProcessHandler();
		VideoHTXCtrlHandler();
	}
}

static void DummyFunction(void)
{
}

static void SystemWatchDog(void)
{
	WatchDogCounter++;
	
	if(WatchDogCounter > 20){
		xprintf("We detect Video type or Resolution or Frame rate cheanged\r\n");
		NVIC_InitTypeDef NVIC_InitStructure;

		NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn;			/* Enable the WWDG Interrupt */
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 10;
		NVIC_Init(&NVIC_InitStructure);

		RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);	/* WWDG configuration */
		WWDG_SetPrescaler(WWDG_Prescaler_8);
		WWDG_SetWindowValue(65);
		WWDG_Enable(127);
		WWDG_ClearFlag();
		WWDG_EnableIT();
	}
}

void WWDG_IRQHandler(void)
{
	WWDG_SetCounter(0x7F);
	WWDG_ClearFlag();
	xprintf("WATCHDOG ...\r\n");
}

static void prvVideoCheckTask( void *pvParameters )
{
	BYTE i;
	/*VideoType? HDMI(high) : Analog(low)*/
	/*VideoStyle_A? AHD(high) : Composite(low)*/
	/*VideoStyle_B? Composite- NTSC(high) :  Composite -PAL(low)*/
	//(VideoType)? 	NVP6114_CommonInit(&ncDec) : xprintf("HDMI Video selected\r\n");
	
	for(;;)
	{
		I2C1_ByteWrite(I2C_NVP6114_ADDR, 0xFF, BANK3  );
		I2C1_ByteWrite(I2C_NVP6114_ADDR, 0xD4, 0x80 );
		I2C1_ByteWrite(I2C_NVP6114_ADDR, 0xD5, 0x80 );
		I2C1_ByteWrite(I2C_NVP6114_ADDR, 0xFF, BANK1  );

		for(i=0; i<2; i++)
		{
			I2C1_ByteRead(I2C_NVP6114_ADDR, 0xED+i, VideoStatusBuff+i+3 );
		}
		
		VideoStatusBuff[3] = (VideoStatusBuff[3]>>4) & 0x1;
		VideoStatusBuff[4] = (VideoStatusBuff[4]>>4) & 0x1;

		#if defined(AHD_DEBUG)
		for(i=0; i<5; i++){
			xprintf("VideoStatusBuff[%d]=[%d], VideoBackupBuff[%d]==[%d] \r\n", i, VideoStatusBuff[i], i, VideoBackupBuff[i]); 
		}
		#endif
		VideoType == VideoBackupBuff[0]? DummyFunction() : SystemWatchDog();							//Video Type compare : Analog or HDMI
		
		if(!VideoType){																					//Analog Video Input
			VideoStyle_A == VideoBackupBuff[1]? DummyFunction() : SystemWatchDog();						//720H(0) or AHD(1) in Analog? 

			if(VideoStyle_A){																				//AHD Video Input
				#if defined(AHD_DEBUG)
				xprintf("Current Video: AHD... Check if Video Changed or not \r\n");
				#endif	
				VideoStatusBuff[3] == VideoBackupBuff[3]? DummyFunction()  : SystemWatchDog();			//check change AHD frame rate 
				VideoStatusBuff[4] == VideoBackupBuff[4]? DummyFunction() : SystemWatchDog(); 		
			}else{										     											//Composite Video Input
				#if	defined(AHD_DEBUG)
				xprintf("Current Video: Composite...  Video Changed or not \r\n");
				VideoStyle_B == VideoBackupBuff[2]? DummyFunction() : SystemWatchDog();
				#endif	
			}
		}else{																							//HDMI Video Input
		}
	}
}
