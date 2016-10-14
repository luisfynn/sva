/**
 *	@file   stm32f10x_system.c
 *	@brief	
 *	@author luisfynn <tani223@pinetron.com>
 *	@date   2014/09/24 14:01
 */

/* system include */
#include <stdio.h>
#include <string.h>
/* local include */
#include "stm32f10x_conf.h"
#include "stm32f10x_system.h"
#include "stm32f10x_it.h"
#include "video.h"
#include "mdintype.h"
#include "mdini2c.h"
#include "mdin3xx.h"
#include "mdindly.h"
#include "mdinosd.h"
#include "rx_lib.h"

NCDEC_INFO	ncDec;

//Remocon 
#define	LEADER_VAL	133				// Leader code = 13.5mSec	((FREQUENCY/12000000)*13500)/256
#define	LEADER_MAX	LEADER_VAL+1	// leader code duty maximum
#define	LEADER_MIN	LEADER_VAL-1	// leader code duty minimum

#define	BIT_HI_VAL	22				// bit high = 2.25mSec	((FREQUENCY/12000000)*2250)/256	
#define	BIT_HI_MAX	BIT_HI_VAL+1	// bit high duty maximum
#define	BIT_HI_MIN	BIT_HI_VAL-1	// bit high duty minimum

#define	BIT_LO_VAL	11				// bit low = 1.125mSec	((FREQUENCY/12000000)*1125)/256
#define	BIT_LO_MAX	BIT_LO_VAL+1	// bit low duty maximum
#define	BIT_LO_MIN	BIT_LO_VAL-1	// bit low duty maximum

WORD 	Ir_Timer_Count =0;
BYTE	chk_bit_cnt;
BYTE	data_bit_cnt;
BYTE	data_cnt;
BYTE	remocon_temp;
BYTE	remocon_data[4];
BYTE	remocon_trans_data[4];
BYTE	Repeat_IR_Key=0;
BYTE	Old_IR_Key=0;
BYTE	LEADER_OK;		// leader code check ok flag
BYTE 	IR_Buffer[20];
BYTE 	IR_Buffer_Count = 0;
BYTE 	IR_Key_Pressed = 0;
BYTE 	First_IR_Pressed = 0;

//video check 
BYTE	Video_Change_Det_A = 0;
BYTE	Video_Change_Det_B = 0;
BYTE	System_Watchdog_En = 0;

//debug 
BYTE 	message_load_ok = 0;

//USART
extern 	BYTE RxBuffer[RxBufferSize];
extern 	BYTE usart_receive_end;
extern 	WORD RxCounter;

//OSD
extern 	SPRITE_CTL_INFO stOSD[12];
extern 	LAYER_CTL_INFO stLayer[3];

//RTC
BYTE 	RTC_Year, RTC_Mon, RTC_Day, RTC_Hour, RTC_Min, RTC_Sec = 0;
WORD 	TYEAR = 2014, TMON = 12, TDAY = 31;
WORD 	THH = 0, TMM = 0, TSS = 0;
WORD 	TMM_Old;
DWORD 	RTC_Count, TimeDisplay = 0;

void System_Init(void)
{
	RCC_Configuration();		//system clock initialize

	NVIC_Configuration();		//vector table set

	GPIO_Initialize();			//GPIO initialize
				
	USART_Initialize();			//USART initialize
					
	I2C_Initialize();			//I2C initialize

	Remocon_Configuration();

	RTC_Time_Init();

	Power_Status(ON);

	Device_Reset();

	Video_Detection(&ncDec);
}

void Video_Init(PNCDEC_INFO pINFO, RX_OP_MODE OperatingMode)
{
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 1)
	{
		ADV7611_INIT(&ncDec,RX_OPMODE_HDMI);
	}else{
		NVP6114_CommonInit(&ncDec);
	}
	NVP6011_CommonInit(&ncDec);
	MDIN3xx_AHDSetRegInitial(&ncDec);
}

void Remocon_Configuration(void)
{
	Timer2_Init();

	IR_Receiver(); 
}

void RCC_Configuration(void)			//Reset & Clock control
{
	ErrorStatus HSEStartUpStatus;
	 
	/* Reset the RCC clock configuration to default reset state */
	RCC_DeInit();
	
	/* Configure the High Speed External oscillator */
	RCC_HSEConfig(RCC_HSE_ON);
			 
	/* Wait for HSE start-up */
	HSEStartUpStatus = RCC_WaitForHSEStartUp();
				 
	if(HSEStartUpStatus == SUCCESS)
	{
		/* Enable Prefetch Buffer */
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
										 
		/* Set the code latency value: FLASH Two Latency cycles */
		FLASH_SetLatency(FLASH_Latency_2);
												 
		/* Configure the AHB clock(HCLK): HCLK = SYSCLK */
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
														 
		/* Configure the High Speed APB2 clcok(PCLK2): PCLK2 = HCLK */
		RCC_PCLK2Config(RCC_HCLK_Div1);
																 
		/* Configure the Low Speed APB1 clock(PCLK1): PCLK1 = HCLK/2 */
		RCC_PCLK1Config(RCC_HCLK_Div2);
																		 
		/* Configure the PLL clock source and multiplication factor     */
		/* PLLCLK = HSE*PLLMul = 8*9 = 72MHz */
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_9);
																				 
		/* Enable PLL   */
		RCC_PLLCmd(ENABLE);
																						 
		/* Check whether the specified RCC flag is set or not */
		/* Wait till PLL is ready       */
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
																								 
		/* Select PLL as system clock source */
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
																								 
		/* Get System Clock Source */
		/* Wait till PLL is used as system clock source */
		while(RCC_GetSYSCLKSource() != 0x08);
	} 
}

void NVIC_Configuration(void)
{
#ifdef  VECT_TAB_RAM  
	/* Set the Vector Table base location at 0x20000000 */ 
	 NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0); 
#else  /* VECT_TAB_FLASH  */
	/* Set the Vector Table base location at 0x08000000 */ 
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);   
#endif
	/* Configure one bit for preemption priority */
	/*PriorityGroup_4 has 16 Group Priorities & zero SubPriority */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	
	/* Enable the USART3 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/*TIM2 global interrupt initialize*/
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* Enable the EXTI15_10 Interrupt */
  	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* Enable the RTC Interrupt */
  	NVIC_InitStructure.NVIC_IRQChannel = RTC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
 	NVIC_Init(&NVIC_InitStructure);

	/* Enable the WWDG Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4;
    NVIC_Init(&NVIC_InitStructure);
}

void GPIO_Initialize(void)
{ 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
			               RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD |
						   RCC_APB2Periph_GPIOE, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_Init(GPIOE, &GPIO_InitStructure);
					  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	//ADV7611 OR NVP6114 SELECT-TBD
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
  	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
						   RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD |
 						   RCC_APB2Periph_GPIOE, DISABLE); 
}

void USART_Initialize(void)
{
	/*Enable GPIOx clock*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
	   
	/* Enable USART3 clocks */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE); 
		  
	/* Configure the USART3 Software Pins remapping */
	GPIO_PinRemapConfig(GPIO_PartialRemap_USART3, ENABLE);
		   
	/* Configure USARTx_Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* Configure USARTx_Rx as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* USARTx configuration ------------------------------------------------------*/
	/* USARTx configured as follow:
	*         - BaudRate = 115200 baud  
	*         - Word Length = 8 Bits
	*         - One Stop Bit
	*    	  - No parity
	*         - Hardware flow control disabled (RTS and CTS signals)
	*         - Receive and transmit enabled
	* */

	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	/* Configure the USARTx */ 
	USART_Init(USART3, &USART_InitStructure);

	/* Enable the USARTx */
	USART_Cmd(USART3, ENABLE);

	/* Enable USART3 interrupt */
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	USART_ITConfig(USART3, USART_IT_TXE, ENABLE);

	printf("\rUSART3 init Complete\n");
}

void Device_Reset(void)
{
	/*Enable GPIOx clock*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	    
	/*GPIO Pin Configuration*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_ResetBits(GPIOC,GPIO_Pin_7);
	MDINDLY_mSec(300);

	//TIM2 test funciton 
#if 0	
	BYTE i;
	for(i=0;i<10;i++){
		Timer_delay(45000);
	}
#endif
	//-------END--------

	GPIO_SetBits(GPIOC,GPIO_Pin_7);
}

void Power_Status(BYTE control)
{   
	/*Enable GPIOx clock*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	    
	/*GPIO Pin Configuration*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
			   
	switch(control)
	{
		case ON:
			GPIO_SetBits(GPIOD,GPIO_Pin_2); 
			break;
											     
		case OFF:
			GPIO_ResetBits(GPIOD,GPIO_Pin_2);
			break;
														      
		case RESTART:
			MDINDLY_mSec(300);	//300ms
			GPIO_ResetBits(GPIOD,GPIO_Pin_2);
			MDINDLY_mSec(300);               
			GPIO_SetBits(GPIOD,GPIO_Pin_2);
			break;
																						    
		default:
			break;
	}
}

void Video_Detection(PNCDEC_INFO pINFO)
{
	Video_Change_Det_A = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8);
	Video_Change_Det_B = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9);
	
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) ==1){		//ADV7611 INIT
		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8)==1) //1280X720P60
		{
			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9)==1){        //NTSC
				pINFO->vformat = NTSC;
				pINFO->tx.enc_inputclk = ENC_CLK_74M;
				pINFO->tx.enc_input_bus = ENC_INBUS_16B;
				pINFO->rx.resolution = NCRESOL_1280X720P;
			}else{  //PAL
				pINFO->vformat = PAL;
				pINFO->tx.enc_inputclk = ENC_CLK_74M;
				pINFO->tx.enc_input_bus = ENC_INBUS_16B;
				pINFO->rx.resolution = NCRESOL_1280X720P;
			}
		}else{											//720X480P60
			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9)==1){        //NTSC
				pINFO->vformat = NTSC;
				pINFO->tx.enc_inputclk = ENC_CLK_74M;
				pINFO->tx.enc_input_bus = ENC_INBUS_16B;
				pINFO->rx.resolution = NCRESOL_720X480;
			}else{  //PAL
				pINFO->vformat = PAL;
				pINFO->tx.enc_inputclk = ENC_CLK_74M;
				pINFO->tx.enc_input_bus = ENC_INBUS_16B;
				pINFO->rx.resolution = NCRESOL_720X480;
			}
		}
	}else{													//NVP6114 INIT
		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8)==1) //AHD
		{
			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9)==1){        //30Hz
				pINFO->vformat = NTSC;
				pINFO->tx.enc_inputclk = ENC_CLK_74M;
				pINFO->tx.enc_input_bus = ENC_INBUS_16B;
				pINFO->rx.resolution = NCRESOL_1280X720P;
			}else{  //25Hz
				pINFO->vformat = PAL;
				pINFO->tx.enc_inputclk = ENC_CLK_74M;
				pINFO->tx.enc_input_bus = ENC_INBUS_16B;
				pINFO->rx.resolution = NCRESOL_1280X720P;
			}
		}else    //SD 
		{
			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9)==1){//NTSC
				pINFO->rx.resolution = NCRESOL_960X480;
				pINFO->vformat = NTSC;
				pINFO->tx.enc_inputclk = ENC_CLK_74M;
				pINFO->tx.enc_input_bus = ENC_INBUS_16B;
			}else{ //PAL
				pINFO->rx.resolution = NCRESOL_960X576;
				pINFO->vformat = PAL;
				pINFO->tx.enc_inputclk = ENC_CLK_74M;
				pINFO->tx.enc_input_bus = ENC_INBUS_16B;
			}													
		}
	}
}

void Timer2_Init(void)
{
	//TIM2 clock enable
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	//Time base configuration
	//(100*72)/72000000 = 0.0001s
	TIM_TimeBaseStructure.TIM_Period = 100-1; 
	TIM_TimeBaseStructure.TIM_Prescaler = 72-1; 		
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);

	//TIM2 enable counter
	TIM_Cmd(TIM2, ENABLE);	
	
	//TIM interrupt enable
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
}

void Timer_delay(WORD del)
{
	Ir_Timer_Count = 0;
	while(Ir_Timer_Count < del){
		printf("Timer2_counter : %d\r\n",Ir_Timer_Count);
	}
}

void IR_Receiver(void)
{
  	/* Set pin as input */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource13);

	/* Configure Key Button EXTI Line to generate an interrupt on falling edge */  
	EXTI_InitStructure.EXTI_Line = EXTI_Line13;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}

void Ir_Receive_code(void)
{
	//NEC Remocon 
	WORD count = Ir_Timer_Count ;
	//TIM2 enable counter
	TIM_Cmd(TIM2, DISABLE);

//	printf("ir_count %d\r\n",Ir_Timer_Count);
	TIM2->CNT = 0;
	Ir_Timer_Count  = 0;
	TIM_Cmd(TIM2, ENABLE);

	if(!LEADER_OK) 
	{
//		printf("count %d\r\n", count);
		if (count>=LEADER_MIN && count<=LEADER_MAX)			//first IR	
		{
			LEADER_OK		= 1;	// leader code ok flag
			chk_bit_cnt		= 4*8;	// remocon data bit number
			data_bit_cnt	= 8;	// data bit number
			data_cnt		= 0;
		}
	}else{
//		printf("count %d\r\n", count);
		if(count >= BIT_LO_MIN && count <= BIT_LO_MAX){		// low bit check
			remocon_temp >>= 1;		// shift right
			remocon_temp &= 0x7f;	// low data read
			data_end_check();
		}else if(count >= BIT_HI_MIN && count <= BIT_HI_MAX){	// high bit check
			remocon_temp >>= 1;		// shift right
			remocon_temp |= 0x80;	// high data read
			data_end_check();
		}else{						// data bit error
			LEADER_OK	= 0;		// leader code clear
		}
	}
}

void data_end_check(void)
{
	data_bit_cnt--;
	if(data_bit_cnt == 0)
	{
		remocon_data[data_cnt] = remocon_temp;
		data_bit_cnt = 8;
		data_cnt++;

		if(data_cnt == 4)
		{
			LEADER_OK	= 0;
		}
	}
}

void REMOCON_data_check(void)
{
	if(Old_IR_Key != remocon_data[2])
	{
		First_IR_Pressed = 1; 		//New IR key  
		printf("remocon data : %x\r\n", remocon_data[0]<<24 | remocon_data[1]<<16 | remocon_data[2] <<8 | remocon_data[3]);
		Old_IR_Key = remocon_data[2];

#if 1 
		switch(remocon_data[2])
		{
			case 0x36:
				remocon_trans_data[2] = 1;
				break;
			case 0x37:
				remocon_trans_data[2] = 2;
				break;
			case 0x41:
				remocon_trans_data[2] = 3;
				break;
			case 0x42:
				remocon_trans_data[2] = 4;
				break;
			case 0x43:
				remocon_trans_data[2] = 5;
				break;
			case 0x44:
				remocon_trans_data[2] = 6;
				break;
			case 0x45:
				remocon_trans_data[2] = 7;
				break;
			case 0x46:
				remocon_trans_data[2] = 8;
				break;
			case 0x47:
				remocon_trans_data[2] = 9;
				break;
			case 0x51:
				remocon_trans_data[2] = 0;
				break;
			default:
				break;
		}
		IR_Buffer[IR_Buffer_Count] = remocon_trans_data[2];
#endif	
		printf("IR_Buffer[%d] -- %d\r\n", IR_Buffer_Count, IR_Buffer[IR_Buffer_Count]);
		IR_Buffer_Count++;
		
		if(IR_Buffer_Count >20) 	IR_Buffer_Count = 0;
	}else if(First_IR_Pressed)
	{
		IR_Key_Pressed = 1; 		//New IR key confirmed 
		First_IR_Pressed = 0;
	}else{
	}

	if(IR_Key_Pressed)
	{
		if(remocon_data[0] != 0x68)	return;	// custom code 1 error
		if(remocon_data[1] != 0x72)	return;	// custom code 2 error
		if(remocon_data[2] != (remocon_data[3] ^ 0xff))	return;	// data error
	
		else
		{
			switch(remocon_data[2])
			{
				case 0x13:
					printf("remocon code ok\r\n");
					if(Repeat_IR_Key == 0){
						MDINOSD_EnableSprite(&stOSD[SPRITE_INDEX0], OFF);	// main-OSD display OFF 
						MDINOSD_EnableSprite(&stOSD[SPRITE_INDEX8], OFF);	// aux-OSD display OFF
						Repeat_IR_Key = 1;
					}else{
						MDINOSD_EnableSprite(&stOSD[SPRITE_INDEX0], ON);	// main-OSD display ON 
						MDINOSD_EnableSprite(&stOSD[SPRITE_INDEX8], ON);	// aux-OSD display ON
						Repeat_IR_Key = 0;
					}		
					remocon_data[2] = 0x0;
					Old_IR_Key = 0;
					
					IR_Buffer_Count = 0;
					IR_Key_Pressed = 0;
					break;
				
				case 0x05:
					TYEAR = 2000 + IR_Buffer[0]*10 + IR_Buffer[1];
					TMON =IR_Buffer[2]*10 + IR_Buffer[3];
					TDAY =IR_Buffer[4]*10 + IR_Buffer[5];
					
					BKP_WriteBackupRegister(BKP_DR2, TYEAR);
					BKP_WriteBackupRegister(BKP_DR3, TMON);
					BKP_WriteBackupRegister(BKP_DR4, TDAY);
				
					RTC_Hour =IR_Buffer[6]*10 + IR_Buffer[7];
					RTC_Min =IR_Buffer[8]*10 + IR_Buffer[9];
					RTC_Sec =IR_Buffer[10]*10 + IR_Buffer[11];
				
					RTC_Count = RTC_Hour*3600 + RTC_Min*60 + RTC_Sec;
						
					printf("RTC_Hour--->%d\r\n",RTC_Hour);
					printf("RTC_Min--->%d\r\n",RTC_Min);
					printf("RTC_Sec--->%d\r\n",RTC_Sec);
					printf("RTC_Count--->%d\r\n",RTC_Count);
						
					//RTC Reset	
					BKP_WriteBackupRegister(BKP_DR1, 0xffff);
					/* Wait until last write operation on RTC registers has finished */
  					RTC_WaitForLastTask();
 					/* Change the current time */
					RTC_SetCounter(RTC_Count);
 					/* Wait until last write operation on RTC registers has finished */
  					RTC_WaitForLastTask();
					BKP_WriteBackupRegister(BKP_DR1, 0xA5A5);

					CreateMDIN3xxGACFontInstance();
					
					Old_IR_Key = 0;
					remocon_data[2] = 0;
					IR_Buffer_Count = 0;
					IR_Key_Pressed = 0;
					break;
				default:
					remocon_data[2] = 0;
					Old_IR_Key = 0;
					IR_Key_Pressed = 0;
					break;
			}
		}
	}
}

void Video_Status_Check(void)
{
	if(Video_Change_Det_A != GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_8) ||Video_Change_Det_B != GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9))
	{
		printf("Video setting change detection\r\n");
		MDINDLY_mSec(3000);	//3s

		if(System_Watchdog_En == 0){
			System_WatchDog();
			System_Watchdog_En = 1;
		}
	}
}

void System_WatchDog(void)
{
	/* WWDG configuration */
	/* Enable WWDG clock */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);

	/* WWDG clock counter = (PCLK1/4096)/8 = 244 Hz (~4 ms)  */
	WWDG_SetPrescaler(WWDG_Prescaler_8);

	/* Set Window value to 65 */
	WWDG_SetWindowValue(65);

	/* Enable WWDG and set counter value to 127, WWDG timeout = ~4 ms * 64 = 262 ms */
	WWDG_Enable(127);

	/* Clear EWI flag */
	WWDG_ClearFlag();

	/* Enable EW interrupt */
	WWDG_EnableIT();
}

void RTC_Configuration(void)
{
 	/* Enable PWR and BKP clocks */
 	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);

 	/* Allow access to BKP Domain */
 	PWR_BackupAccessCmd(ENABLE);

 	/* Reset Backup Domain */
 	BKP_DeInit();

 	/* Enable LSE */
 	RCC_LSEConfig(RCC_LSE_ON);
 
 	/* Wait till LSE is ready */
 	while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)
 	{}

 	/* Select LSE as RTC Clock Source */
 	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);

 	/* Enable RTC Clock */
 	RCC_RTCCLKCmd(ENABLE);

 	/* Wait for RTC registers synchronization */
 	RTC_WaitForSynchro();

 	/* Wait until last write operation on RTC registers has finished */
 	RTC_WaitForLastTask();

 	/* Enable the RTC Second */
 	RTC_ITConfig(RTC_IT_SEC, ENABLE);

 	/* Wait until last write operation on RTC registers has finished */
 	RTC_WaitForLastTask();

 	/* Set RTC prescaler: set RTC period to 1sec */
 	RTC_SetPrescaler(32767); /* RTC period = RTCCLK/RTC_PR = (32.768 KHz)/(32767+1) */

 	/* Wait until last write operation on RTC registers has finished */
 	RTC_WaitForLastTask();
}

void RTC_Time_Init(void)
{
  	if (BKP_ReadBackupRegister(BKP_DR1) != 0xA5A5)
	{
	   /* Backup data register value is not correct or not yet programmed (when
		*        the first time the program is executed) */

		printf("RTC not yet configured....\r\n");

		/* RTC Configuration */
	    RTC_Configuration();

	    printf("RTC configured....\r\n");

	    /* Adjust time by values entred by the user on the hyperterminal */
	    Time_Adjust();
	
		BKP_WriteBackupRegister(BKP_DR1, 0xA5A5);
  	}
    else
  	{
      	/* Check if the Power On Reset flag is set */
	    if (RCC_GetFlagStatus(RCC_FLAG_PORRST) != RESET)
	    {
	        printf("Power On Reset occurred....\r\n");
		}
	  	/* Check if the Pin Reset flag is set */
	 	else if (RCC_GetFlagStatus(RCC_FLAG_PINRST) != RESET)
		{
		    printf("External Reset occurred....\r\n");
		}

		printf("No need to configure RTC....\r\n");
	    /* Wait for RTC registers synchronization */
	    RTC_WaitForSynchro();

	    /* Enable the RTC Second */
	    RTC_ITConfig(RTC_IT_SEC, ENABLE);
	    
		/* Wait until last write operation on RTC registers has finished */
	    RTC_WaitForLastTask();
	}
	
	/* Enable PWR and BKP clocks */
  	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);

    /* Allow access to BKP Domain */
    PWR_BackupAccessCmd(ENABLE);

	/* Disable the Tamper Pin */
	BKP_TamperPinCmd(DISABLE); /* To output RTCCLK/64 on Tamper pin, the tamper
									                                 functionality must be disabled */
	/* Enable RTC Clock Output on Tamper Pin */
 	BKP_RTCOutputConfig(BKP_RTCOutputSource_CalibClock);
	
	/* Clear reset flags */
  	RCC_ClearFlag();

   	/* Display time */
   	Time_Show();
}

void Time_Adjust(void)
{
 	/* Wait until last write operation on RTC registers has finished */
  	RTC_WaitForLastTask();
 	/* Change the current time */
	RTC_SetCounter(Time_Regulate());
 	/* Wait until last write operation on RTC registers has finished */
  	RTC_WaitForLastTask();
}

WORD Time_Regulate(void)
{
#if 0
	WORD Hour = 0xff, Min = 0xff, Sec = 0xff;
	WORD Year = 0xff, Month = 0xff, Day = 0xff;

	printf("==============Time Setting============\r\n");
	printf("==============Type Year, MOnth, Day============\r\n");
	while(Year == 0xff && usart_receive_end ==1)
	{
		Year =(RxBuffer[0]<<12)|(RxBuffer[1]<<8)|(RxBuffer[2]<<4)|RxBuffer[3];
		printf("Year value is %d \r\n", Year);
	}
#endif
	return 50000;
}

BYTE Leap_Year(BYTE year)
{
	if(TYEAR % 400 == 0)		return TRUE; 		//leap year
	else if(TYEAR % 100 == 0)	return FALSE;		//not leap year
	else if(TYEAR % 4 == 0)		return TRUE;
	else						return FALSE;
}

void Time_Display(u32 TimeVar)
{	
	TYEAR = BKP_ReadBackupRegister(BKP_DR2);
	TMON = BKP_ReadBackupRegister(BKP_DR3);
	TDAY = BKP_ReadBackupRegister(BKP_DR4);

    /* Compute  hours */
    THH = TimeVar / 3600;
  	/* Compute minutes */
	TMM = (TimeVar % 3600) / 60;
    /* Compute seconds */
    TSS = (TimeVar % 3600) % 60;

	if(TSS > 59) TSS = TSS % 60;

	if(TMM > 59) TMM = TMM % 60;
	
	if(THH > 23) THH = THH % 24;
	
	if(TimeVar == 0)			//1 day = 86400s
	{
		TDAY ++;
		BKP_WriteBackupRegister(BKP_DR2, TYEAR);
		BKP_WriteBackupRegister(BKP_DR3, TMON);
		BKP_WriteBackupRegister(BKP_DR4, TDAY);
	}

	if(TMON == JANUARY || TMON == MARCH || TMON == MAY || TMON == JULY || TMON ==AUGUST || TMON == OCTOBER || TMON == DECEMBER) 
	{	
		if(TDAY >31)
		{
			TMON ++;
			TDAY = 1;
		}

		if(TMON >12)
		{
			TDAY = 1;
			TMON = 1;
			TYEAR ++;
		}
	}else if(TMON == APRIL || TMON == JUNE || TMON == SEPTEMBER || TMON == NOVEMBER)
	{
		if(TDAY >30)
		{
			TDAY = 1;
			TMON ++;
		}
	}else
	{
		if(TDAY == 29)
		{
			if(!Leap_Year(TYEAR))
			{
				TMON ++;
				TDAY =1;
			}else
			{
				if(TDAY == 30)
				{
					TMON ++;
					TDAY =1;
				}
			}
		}
	}
	printf("Time: %0.2d - %0.2d - %0.2d  %0.2d:%0.2d:%0.2d\r\n", TYEAR, TMON, TDAY, THH, TMM, TSS);
}

void Time_Show(void)
{
    /* If 1s has paased */
    if (TimeDisplay == 1)
    {
      	/* Display current time */
      	Time_Display(RTC_GetCounter());
   		TimeDisplay = 0;
	}
}

void Debug_main(void){
		
		if(usart_receive_end == 1){

			switch(RxBuffer[0])
			{
				WORD i, ID, data, temp_addr, temp_value;
				BYTE Data, Temp_addr, Temp_value;
				BYTE nData;
				DWORD RTC_Count;

				case 'd': 	
					printf("=====MDIN Host Register Dump start=====\r\n");	
					printf("       00   01   02   03   04   05   06   07   08   09   0A   0B   0C   0D   0E   0F\r\n");	
					printf("====================================================================================\r\n");	
					for(i=0;i<0x100;i++)
					{
						MDINI2C_RegRead(0xc0, i, &data);
						
						if(i%16==0) printf("%04x: ", i);
						printf("%04x%s", data, (i%16==15)? "\r\n":" ");
					}
					
					printf("=====MDIN Local Register Dump start=====\r\n");	
					printf("       00   01   02   03   04   05   06   07   08   09   0A   0B   0C   0D   0E   0F\r\n");	
					printf("====================================================================================\r\n");	
					for(i=0;i<0x400;i++)
					{
						MDINI2C_RegRead(0xc2, i, &data);

						if(i%16==0) printf("%04x: ", i);
						printf("%04x%s", data, (i%16==15)? "\r\n":" ");
					}
					
					printf("=====MDIN Hdmi Register Dump start=====\r\n");	
					printf("       00   01   02   03   04   05   06   07   08   09   0A   0B   0C   0D   0E   0F\r\n");	
					printf("====================================================================================\r\n");	
					for(i=0;i<0x200;i++)
					{
						MDINI2C_RegRead(0xc4, i, &data);

						if(i%16==0) printf("%04x: ", i);
						printf("%04x%s", data, (i%16==15)? "\r\n":" ");
					}

					usart_receive_end = 0;
					RxCounter = 0;
	   				USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
					break;
					
					usart_receive_end = 0;
					RxCounter = 0;
	   				USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
					break;

				////////////////////////////////////////////////////////////////////////////////////////////////////////
				////////////////////////////////////////////////////////////////////////////////////////////////////////
				
				case 't':
					printf("=====ADV7611 IO Register Dump start=====\r\n");	
					printf("       00   01   02   03   04   05   06   07   08   09   0A   0B   0C   0D   0E   0F\r\n");	
					printf("====================================================================================\r\n");	
					for(i=0;i<0x100;i++)
					{
						I2C1_ByteRead(0x98>>1, i, &Data);
						
						if(i%16==0) printf("%04x: ", i);
						printf("%04x%s", Data, (i%16==15)? "\r\n":" ");
					}
					
					printf("=====ADV7611 CP Register Dump start=====\r\n");	
					printf("       00   01   02   03   04   05   06   07   08   09   0A   0B   0C   0D   0E   0F\r\n");	
					printf("====================================================================================\r\n");	
					for(i=0;i<0x100;i++)
					{
						I2C1_ByteRead(0x44>>1, i, &Data);

						if(i%16==0) printf("%04x: ", i);
						printf("%04x%s", Data, (i%16==15)? "\r\n":" ");
					}
					
					printf("=====ADV7611 HDMI Register Dump start=====\r\n");	
					printf("       00   01   02   03   04   05   06   07   08   09   0A   0B   0C   0D   0E   0F\r\n");	
					printf("====================================================================================\r\n");	
					for(i=0;i<0x100;i++)
					{
						I2C1_ByteRead(0x68>>1, i, &Data);

						if(i%16==0) printf("%04x: ", i);
						printf("%04x%s", Data, (i%16==15)? "\r\n":" ");
					}

					printf("=====ADV7611 KSV Register Dump start=====\r\n");	
					printf("       00   01   02   03   04   05   06   07   08   09   0A   0B   0C   0D   0E   0F\r\n");	
					printf("====================================================================================\r\n");	
					for(i=0;i<0x100;i++)
					{
						I2C1_ByteRead(0x64>>1, i, &Data);

						if(i%16==0) printf("%04x: ", i);
						printf("%04x%s", Data, (i%16==15)? "\r\n":" ");
					}

					printf("=====ADV7611 DPLL Register Dump start=====\r\n");	
					printf("       00   01   02   03   04   05   06   07   08   09   0A   0B   0C   0D   0E   0F\r\n");	
					printf("====================================================================================\r\n");	
					for(i=0;i<0x100;i++)
					{
						I2C1_ByteRead(0x30>>1, i, &Data);

						if(i%16==0) printf("%04x: ", i);
						printf("%04x%s", Data, (i%16==15)? "\r\n":" ");
					}

					printf("=====ADV7611 INFORFRAME Register Dump start=====\r\n");	
					printf("       00   01   02   03   04   05   06   07   08   09   0A   0B   0C   0D   0E   0F\r\n");	
					printf("====================================================================================\r\n");	
					for(i=0;i<0x100;i++)
					{
						I2C1_ByteRead(0x76>>1, i, &Data);

						if(i%16==0) printf("%04x: ", i);
						printf("%04x%s", Data, (i%16==15)? "\r\n":" ");
					}

					printf("=====ADV7611 EDID Register Dump start=====\r\n");	
					printf("       00   01   02   03   04   05   06   07   08   09   0A   0B   0C   0D   0E   0F\r\n");	
					printf("====================================================================================\r\n");	
					for(i=0;i<0x100;i++)
					{
						I2C1_ByteRead(0x6C>>1, i, &Data);

						if(i%16==0) printf("%04x: ", i);
						printf("%04x%s", Data, (i%16==15)? "\r\n":" ");
					}

					printf("=====ADV7611 CEC Register Dump start=====\r\n");	
					printf("       00   01   02   03   04   05   06   07   08   09   0A   0B   0C   0D   0E   0F\r\n");	
					printf("====================================================================================\r\n");	
					for(i=0;i<0x100;i++)
					{
						I2C1_ByteRead(0x80>>1, i, &Data);

						if(i%16==0) printf("%04x: ", i);
						printf("%04x%s", Data, (i%16==15)? "\r\n":" ");
					}

					usart_receive_end = 0;
					RxCounter = 0;
	   				USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
					break;


				case 'i':
					if((RxBuffer[1] =='c')&&(RxBuffer[11] =='w')){
						printf("MDIN I2C WRITE\r\n");

						switch(RxBuffer[2])
						{
							case '0':
								ID = 0xc0;
								break;
							case '1':
								ID = 0xc2;
								break;
							case '2':
								ID = 0xc4;
								break;
							default:
								ID = 0xc0;
								break;
						}
						printf("ID -->%x\r\n", ID);
						
						for(i=0;i<11;i++){
							if((RxBuffer[3+i]>='a')&&(RxBuffer[3+i]<='f')){
								RxBuffer[3+i] = RxBuffer[3+i] - 'W';
						//		printf("RxBuffer[3+%x]-->%x\r\n",i,RxBuffer[3+i]);
							}else{
								RxBuffer[3+i] = RxBuffer[3+i] - '0';
						//		printf("RxBuffer[3+%x]-->%x\r\n",i,RxBuffer[3+i]);
							}
						}

						temp_addr =(RxBuffer[3]<<12)|(RxBuffer[4]<<8)|(RxBuffer[5]<<4)|RxBuffer[6];
						temp_value =(RxBuffer[7]<<12)|(RxBuffer[8]<<8)|(RxBuffer[9]<<4)|RxBuffer[10];

						printf("temp_addr--->%x\r\n",temp_addr);
						printf("temp_value--->%x\r\n",temp_value);
						
						MDINI2C_RegWrite(ID, temp_addr, temp_value);
						MDINI2C_RegRead(ID, temp_addr, &temp_value);
						printf("read value --->%x\r\n",temp_value);

						RxBuffer[11] = '0';

					}else if((RxBuffer[1]=='c')&&(RxBuffer[7] =='r')){

						printf("MDIN I2C READ\r\n");

						switch(RxBuffer[2])
						{
							case '0':
								ID = 0xc0;
								break;
							case '1':
								ID = 0xc2;
								break;
							case '2':
								ID = 0xc4;
								break;
							case '3':
								ID = 0xc6;
								break;
							default:
								ID = 0xc0;
								break;
						}
						printf("ID -->%x\r\n",ID);
				
						for(i=0;i<4;i++){
							if((RxBuffer[3+i]>='a')&&(RxBuffer[3+i]<='f')){
								RxBuffer[3+i] = RxBuffer[3+i] - 'W';
								//printf("RxBuffer[3+%x]-->%x\r\n",i,RxBuffer[3+i]);
							}else{
								RxBuffer[3+i] = RxBuffer[3+i] - '0';
							//	printf("RxBuffer[3+%x]-->%x\r\n",i,RxBuffer[3+i]);
							}
						}

						temp_addr =(RxBuffer[3]<<12)|(RxBuffer[4]<<8)|(RxBuffer[5]<<4)|RxBuffer[6];
						printf("temp_addr--->%x\r\n",temp_addr);
					
						MDINI2C_RegRead(ID, temp_addr, &temp_value);
						printf("read value --->%x\r\n",temp_value);
						RxBuffer[7] = '0';
					}else if((RxBuffer[0]=='i') &&(RxBuffer[1] != 'c')){
						RxBuffer[7] = '0';
						RxBuffer[11] = '0';
					}else{
						RxBuffer[7] = '0';
						RxBuffer[11] = '0';
					}
					usart_receive_end = 0;
					RxCounter = 0;
	   				USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
					break;

				case 'a':
					if((RxBuffer[1] =='c')&&(RxBuffer[7] =='w')){
						printf("I2C WRITE\r\n");

						switch(RxBuffer[2])
						{
							case '0':
								ID = 0x98;			//IO MAP
								break;
							case '1':
								ID = 0x80;			//CEC MAP
								break;
							case '2':
								ID = 0x7c;			//INFORFRAME
								break;
							case '3':
								ID = 0x4c;			//DPLL MAP
								break;
							case '4':
								ID = 0x64;			//KSV MAP
								break;
							case '5':
								ID = 0x6c;			//EDID
								break;
							case '6':
								ID = 0x68;			//HDMI MAP
								break;
							case '7':
								ID = 0x44;			//CP
								break;
							default:
								ID = 0x98;
								break;
						}
						printf("ID -->%x\r\n", ID);
						
						for(i=0;i<4;i++){
							if((RxBuffer[3+i]>='a')&&(RxBuffer[3+i]<='f')){
								RxBuffer[3+i] = RxBuffer[3+i] - 'W';
							}else{
								RxBuffer[3+i] = RxBuffer[3+i] - '0';
							}
						}

						Temp_addr =(RxBuffer[3]<<4)|(RxBuffer[4]);
						Temp_value =(RxBuffer[5]<<4)|(RxBuffer[6]);

						printf("Temp_addr--->%x\r\n",Temp_addr);
						printf("Temp_value--->%x\r\n",Temp_value);
						
						I2C1_ByteWrite(ID>>1, Temp_addr, Temp_value);  
						I2C1_ByteRead(ID>>1, Temp_addr , &Temp_value); 
						printf("read value --->%x\r\n",Temp_value);

						RxBuffer[7] = '0';

					}else if((RxBuffer[1]=='c')&&(RxBuffer[5] =='r')){

						printf("MDIN I2C READ\r\n");

						switch(RxBuffer[2])
						{
							case '0':
								ID = 0x98;			//IO MAP
								break;
							case '1':
								ID = 0x80;			//CEC MAP
								break;
							case '2':
								ID = 0x7c;			//INFORFRAME
								break;
							case '3':
								ID = 0x4c;			//DPLL MAP
								break;
							case '4':
								ID = 0x64;			//KSV MAP
								break;
							case '5':
								ID = 0x6c;			//EDID
								break;
							case '6':
								ID = 0x68;			//HDMI MAP
								break;
							case '7':
								ID = 0x44;			//CP
								break;
							default:
								ID = 0x98;
								break;
						}
						printf("ID -->%x\r\n",ID);
				
						for(i=0;i<2;i++){
							if((RxBuffer[3+i]>='a')&&(RxBuffer[3+i]<='f')){
								RxBuffer[3+i] = RxBuffer[3+i] - 'W';
							}else{
								RxBuffer[3+i] = RxBuffer[3+i] - '0';
							}
						}
						Temp_addr =(RxBuffer[3]<<4)|(RxBuffer[4]);
						printf("Temp_addr--->%x\r\n",Temp_addr);
						
						I2C1_ByteRead(ID>>1,Temp_addr, &Temp_value); 
						printf("read value --->%x\r\n",Temp_value);

						RxBuffer[5] = '0';
					}else if((RxBuffer[0]=='a') &&(RxBuffer[1] != 'c')){
						RxBuffer[5] = '0';
						RxBuffer[7] = '0';
					}else{
						RxBuffer[5] = '0';
						RxBuffer[7] = '0';
					}
					usart_receive_end = 0;
					RxCounter = 0;
	   				USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
					break;
				case 'h':
					if(message_load_ok == 0) debug_message();
					break;
				case 'r':
					if(RxBuffer[1] == 't' || RxBuffer[2] == 'c')
					{
						RTC_Year = ((RxBuffer[3] - 0x30) * 10) +( RxBuffer[4] -0x30);
						RTC_Mon = ((RxBuffer[5] - 0x30) * 10) +( RxBuffer[6] -0x30);
						RTC_Day = ((RxBuffer[7] - 0x30) * 10) +( RxBuffer[8] -0x30);

						RTC_Hour =((RxBuffer[9] - 0x30) * 10) +( RxBuffer[10] -0x30);
						RTC_Min =((RxBuffer[11] - 0x30) * 10) +( RxBuffer[12] -0x30);
						RTC_Sec =((RxBuffer[13] - 0x30) * 10) +( RxBuffer[14] -0x30);
						RTC_Count = RTC_Hour*3600 + RTC_Min*60 + RTC_Sec;
						
						//RTC Reset	
						BKP_WriteBackupRegister(BKP_DR1, 0xffff);
						/* Wait until last write operation on RTC registers has finished */
  						RTC_WaitForLastTask();
 						/* Change the current time */
						RTC_SetCounter(RTC_Count);
 						/* Wait until last write operation on RTC registers has finished */
  						RTC_WaitForLastTask();
						BKP_WriteBackupRegister(BKP_DR1, 0xA5A5);

						CreateMDIN3xxGACFontInstance();
					}	
				default:
					usart_receive_end = 0;
					RxCounter = 0;
					message_load_ok = 0;
	   				USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
					break;
			}
		}else{
	   		USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
		}

	#if 0 //MDIN-380 device ID Check
		WORD nID;
		nID = 0;
				
	//	MDINI2C_RegWrite(0xc0, 0x400, 0x02);       //select hdmi reg

		while(nID!=0x9736)
		{
			printf("\rMDIN Dev_ID check routine\n");
			MDINI2C_RegRead(0xc4, 0x0002, &nID);  
		}
		printf("\rMDIN Dev_ID check success\n");
	#endif
}

void debug_message(void)
{
	printf("======================= Debug option =================\r\n");	
	printf("d :  mdin register dump                               \r\n");	
	printf("t :  adv7611 register dump                            \r\n");	
	printf("                                                      \r\n");	
	printf("MDIN380 register access                               \r\n");	
	printf("usage: i2cx[addr(xxxxx)][data(xxxx)][r/w]             \r\n");	
	printf("    i2cx(host : x->0, local : x->1, hdmi : x->3)      \r\n");	
	printf("    addr & data : ex 0x300  -> 0300                   \r\n");	
	printf("    r/w -> read/write(if read, don't write data )     \r\n");	
	printf("                                                      \r\n");	
	printf("ADV7611 register access                               \r\n");	
	printf("usage: a2cx[addr(xxxxx)][data(xxxx)]                  \r\n");	
	printf("   a2cx(iomap : x->0, cec : x->1, inforframe : x->2)  \r\n");	
	printf("   a2cx(dpllmap : x->3, ksv: x->4, edid : x->5)       \r\n");	
	printf("   a2cx(hdmi : x->6, cp : x->7)                       \r\n");	
	printf("   addr & data : ex 0x300  -> 0300                    \r\n");	
	printf("   r/w -> read/write(if read, don't write data )      \r\n");	
	printf("============================================== =======\r\n");

	message_load_ok = 1;
}
