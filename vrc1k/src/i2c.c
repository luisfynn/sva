/**
 *	@file   i2c.c
 *	@brief	
 *	@author luisfynn <@pinetron.com>
 *	@date   2014/10/14 13:08
 */

/* system include */
#include <stdio.h>
#include <string.h>
/* local include */
#include "stm32f10x_conf.h"
#include "mdintype.h"
#include "mdini2c.h"
#include "i2c.h"

#define I2C_OK	1

extern MDIN_ERROR_t I2CDLY_5uSec(WORD delay);

void I2C_Initialize(void)
 {
  /* Enable peripheral clocks */
  /* GPIOB Periph clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  /* I2C1 and I2C2 Periph clock enable */
  //RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1 | RCC_APB1Periph_I2C2, ENABLE);
  //RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
   
#if 1 
  /* Configure I2C1 pins: SCL and SDA ----------------------------------------*/
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* Configure I2C2 pins: SCL and SDA ----------------------------------------*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
#endif
  
  /* Enable I2C1 and I2C2 ----------------------------------------------------*/
 // I2C_Cmd(I2C1, ENABLE);
 // I2C_Cmd(I2C2, ENABLE);

#if 1 
  /* I2C1 configuration ------------------------------------------------------*/
  I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
  I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
  I2C_InitStructure.I2C_OwnAddress1 = 0x0;
  I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
  I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
  I2C_InitStructure.I2C_ClockSpeed = ClockSpeed;
  I2C_Init(I2C1, &I2C_InitStructure);

  /* I2C2 configuration ------------------------------------------------------*/
  I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
  I2C_InitStructure.I2C_OwnAddress1 = 0x00;
  I2C_Init(I2C2, &I2C_InitStructure);
#endif
  
  /*Debugging Code*/
 // printf("\r\nI2C init Complete\n\r");
 }

unsigned char I2C1_ByteWrite(unsigned char DevID, unsigned char WriteReg, unsigned char pBuff)
{

 	unsigned char i;

	I2C1_Start();

	I2C1_WriteByte(DevID<<1);   //device address

	I2C1_SlaveAck(ACK);
						
	I2C1_WriteByte(WriteReg);   //register address

	I2C1_SlaveAck(ACK);

	for (i=0; i<1; i++)
	{
		I2C1_WriteByte(pBuff);
		I2C1_SlaveAck(NACK);
	}
	I2C1_Stop();

	return I2C_OK; }

unsigned char I2C1_ByteRead(unsigned char DevID, unsigned char Register, unsigned char* pBuff)
{
	I2C1_Start();
	I2C1_WriteByte(DevID<<1);
	I2C1_SlaveAck(ACK);

	I2C1_WriteByte(Register);
	I2C1_SlaveAck(ACK);
							
	I2C1_Start();
	I2C1_WriteByte(DevID<<1| 0x01);
	I2C1_SlaveAck(ACK);
	
	pBuff[0] = I2C1_ReadByte();

	I2C1_SlaveAck(NACK);

	I2C1_Stop();

	return I2C_OK;
}

unsigned char I2C2_ByteRead(unsigned int DevID, unsigned int Register, unsigned char* pBuff ,WORD bytes)
{
  unsigned char i;
  
  I2C2_Start();
  I2C2_WriteByte(DevID<<1);
  I2C2_SlaveAck(ACK);
	
  I2C2_WriteByte(HIBYTE(Register));
  I2C2_SlaveAck(ACK);
  I2C2_WriteByte(LOBYTE(Register));
  I2C2_SlaveAck(ACK);

  I2C2_Start();
  I2C2_WriteByte(DevID<<1 | 0x01);
  I2C2_SlaveAck(ACK);

  for (i=0; i<bytes-1; i++)
  {
	pBuff[i^0x01] = I2C2_ReadByte();
	I2C2_SlaveAck(ACK);
  }
  pBuff[i^0x01] = I2C2_ReadByte(); 
  I2C2_SlaveAck(NACK);
	
  I2C2_Stop();

  return I2C_OK;
}

unsigned char I2C2_ByteWrite(unsigned int DevID, unsigned int Register, unsigned char* pBuff, WORD bytes)
{
	unsigned int i;

	I2C2_Start();
	I2C2_WriteByte(DevID<<1);               //slave addres
	I2C2_SlaveAck(ACK);
	
	I2C2_WriteByte(HIBYTE(Register));     //start address
	I2C2_SlaveAck(ACK);
	I2C2_WriteByte(LOBYTE(Register));     //start address
	I2C2_SlaveAck(ACK);

	for (i=0; i<bytes-1; i++)
	{
	//	printf("c%02x%s", pBuff[i^1], (i%32==31)? "\r\n" :" ");
		I2C2_WriteByte(pBuff[i^1]);
		I2C2_SlaveAck(ACK);
	}
	I2C2_WriteByte(pBuff[i^1]);
	I2C2_SlaveAck(NACK);

	I2C2_Stop();

	return 1;
}

unsigned char I2C2_ByteWrite2(unsigned int DevID, unsigned int Register, unsigned char* pBuff, WORD bytes)
{
	unsigned int i;

	I2C2_Start();
	I2C2_WriteByte(DevID<<1);               //slave addres
	I2C2_SlaveAck(ACK);
	
	I2C2_WriteByte(HIBYTE(Register));     //start address
	I2C2_SlaveAck(ACK);
	I2C2_WriteByte(LOBYTE(Register));     //start address
	I2C2_SlaveAck(ACK);

	for (i=0; i<bytes-1; i++)
	{
		//printf("c%02x%s", pBuff[i], (i%32==31)? "\r\n" :" ");
		I2C2_WriteByte(pBuff[i]);
		I2C2_SlaveAck(ACK);
	}
	I2C2_WriteByte(pBuff[i]);
	I2C2_SlaveAck(NACK);

	I2C2_Stop();

	return 1;
}

//------------------GPIO I2C-----------------
void I2C2_Start(void)
{
	GPIO_InitTypeDef	GPIO_InitStruct;

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStruct.GPIO_Pin = I2C2_SDA | I2C2_SCL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);

	GPIO_SetBits(GPIOB, I2C2_SDA);
	GPIO_SetBits(GPIOB, I2C2_SCL);
	I2CDLY_5uSec(1);
	GPIO_ResetBits(GPIOB, I2C2_SDA);
	I2CDLY_5uSec(1);
	GPIO_ResetBits(GPIOB, I2C2_SCL);
}
void I2C1_Start(void)
{
	GPIO_InitTypeDef	GPIO_InitStruct;

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStruct.GPIO_Pin = I2C1_SDA | I2C1_SCL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);

	GPIO_SetBits(GPIOB, I2C1_SDA);
	GPIO_SetBits(GPIOB, I2C1_SCL);
	I2CDLY_5uSec(1);
	GPIO_ResetBits(GPIOB, I2C1_SDA);
	I2CDLY_5uSec(1);
	GPIO_ResetBits(GPIOB, I2C1_SCL);
}

void I2C2_Stop(void)
{
	GPIO_ResetBits(GPIOB, I2C2_SDA);
	I2CDLY_5uSec(1);
	GPIO_SetBits(GPIOB, I2C2_SCL);
	I2CDLY_5uSec(1);
	GPIO_SetBits(GPIOB, I2C2_SDA);
}
void I2C1_Stop(void)
{
	GPIO_ResetBits(GPIOB, I2C1_SDA);
	I2CDLY_5uSec(1);
	GPIO_SetBits(GPIOB, I2C1_SCL);
	I2CDLY_5uSec(1);
	GPIO_SetBits(GPIOB, I2C1_SDA);
}

void I2C2_WriteByte(unsigned char data)
{
	unsigned int i, tmpbyte = data;

	for(i = 0; i < 8; i++)
	{       
		if(0x80 & tmpbyte)
			GPIO_SetBits(GPIOB, I2C2_SDA);
		else
			GPIO_ResetBits(GPIOB, I2C2_SDA);
                	
		I2CDLY_5uSec(1);
		GPIO_SetBits(GPIOB, I2C2_SCL);
		I2CDLY_5uSec(1);
		GPIO_ResetBits(GPIOB, I2C2_SCL);
		tmpbyte = tmpbyte << 1;
	}
}

void I2C1_WriteByte(unsigned char data)
{
	unsigned int i, tmpbyte = data;

	for(i = 0; i < 8; i++)
	{       
		if(0x80 & tmpbyte)
			GPIO_SetBits(GPIOB, I2C1_SDA);
		else
			GPIO_ResetBits(GPIOB, I2C1_SDA);
                	
		I2CDLY_5uSec(1);
		GPIO_SetBits(GPIOB, I2C1_SCL);
		I2CDLY_5uSec(1);
		GPIO_ResetBits(GPIOB, I2C1_SCL);
		tmpbyte = tmpbyte << 1;
	}
}

void I2C2_SlaveAck(unsigned char flag)
{
	if(flag == ACK)
		GPIO_ResetBits(GPIOB, I2C2_SDA);
	else
		GPIO_SetBits(GPIOB, I2C2_SDA);
	
	I2CDLY_5uSec(1);
	GPIO_SetBits(GPIOB, I2C2_SCL);
	I2CDLY_5uSec(1);
	GPIO_ResetBits(GPIOB, I2C2_SCL);
}

void I2C1_SlaveAck(unsigned char flag)
{
	if(flag == ACK)
		GPIO_ResetBits(GPIOB, I2C1_SDA);
	else
		GPIO_SetBits(GPIOB, I2C1_SDA);
	
	I2CDLY_5uSec(1);
	GPIO_SetBits(GPIOB, I2C1_SCL);
	I2CDLY_5uSec(1);
	GPIO_ResetBits(GPIOB, I2C1_SCL);
}

unsigned int I2C2_ReadByte(void)
{
	unsigned char i;
	unsigned char ReadValue = 0;
	GPIO_InitTypeDef GPIO_InitStruct;
	unsigned char bit;

	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin  = I2C2_SDA;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);

	for(i = 0; i < 8; i++)
	{
		if(Bit_SET == GPIO_ReadInputDataBit(GPIOB, I2C2_SDA))	bit = 0x01;
		else    bit = 0x00;

		I2CDLY_5uSec(1);			
		GPIO_SetBits(GPIOB, I2C2_SCL);
		I2CDLY_5uSec(1);	
		GPIO_ResetBits(GPIOB, I2C2_SCL);		
		I2CDLY_5uSec(1);
		ReadValue = (ReadValue<<1)|bit;
	}
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin  = I2C2_SDA|I2C2_SCL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);

	return ReadValue;
}
unsigned char I2C1_ReadByte(void)
{
		unsigned char  i, bit, ReadValue = 0;
		GPIO_InitTypeDef GPIO_InitStruct;

		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_InitStruct.GPIO_Pin  = I2C1_SDA;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_Init(GPIOB, &GPIO_InitStruct);

		for(i = 0; i < 8; i++)
		{
			if(Bit_SET == GPIO_ReadInputDataBit(GPIOB, I2C1_SDA))	bit = 0x01;
			else													bit = 0x00;

			I2CDLY_5uSec(1);
			GPIO_SetBits(GPIOB, I2C1_SCL);
			I2CDLY_5uSec(1);		
			GPIO_ResetBits(GPIOB, I2C1_SCL);		
			I2CDLY_5uSec(1);
			ReadValue = (ReadValue<<1)|bit;
		}
									
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_InitStruct.GPIO_Pin = I2C1_SDA | I2C1_SCL;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(GPIOB, &GPIO_InitStruct);
													
			return ReadValue;
}

