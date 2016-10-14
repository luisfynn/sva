/**
 *	@file   i2c.c
 *	@brief	
 *	@author luisfynn <tani223@pinetron.com>
 *	@date   2014/10/14 13:08
 */

/* system include */
/* local include */
#include "stm32f10x.h"
#include "mdindly.h"
#include "i2c.h"

static void I2C1_Start(void);
static void I2C1_Stop(void);
static void I2C1_WriteByte(BYTE data);
static void I2C1_SlaveAck(BYTE flag);
static BYTE I2C1_ReadByte(void);

static void I2C2_Start(void);
static void I2C2_Stop(void);
static void I2C2_WriteByte(BYTE data);
static void I2C2_SlaveAck(BYTE flag);
static WORD I2C2_ReadByte(void);
static void I2C2_SlaveAck(BYTE flag);

void I2C_Initialize(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	/* GPIOB Periph clock enable */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

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
}

BYTE I2C1_ByteWrite(BYTE DevID, BYTE WriteReg, BYTE pBuff)
{
	BYTE i;

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

	return I2C_OK; 
}

BYTE I2C1_ByteRead(BYTE DevID, BYTE Register, PBYTE pBuff)
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

BYTE I2C2_ByteRead(WORD DevID, WORD Register, PBYTE pBuff ,WORD bytes)
{
	BYTE i;

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

BYTE I2C2_ByteWrite(WORD DevID, WORD Register, PBYTE pBuff, WORD bytes)
{
	WORD i;

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

BYTE I2C2_ByteWrite2(WORD DevID, WORD Register, PBYTE pBuff, WORD bytes)
{
	WORD i;

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
static void I2C2_Start(void)
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
static void I2C1_Start(void)
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

static void I2C2_Stop(void)
{
	GPIO_ResetBits(GPIOB, I2C2_SDA);
	I2CDLY_5uSec(1);
	GPIO_SetBits(GPIOB, I2C2_SCL);
	I2CDLY_5uSec(1);
	GPIO_SetBits(GPIOB, I2C2_SDA);
}
static void I2C1_Stop(void)
{
	GPIO_ResetBits(GPIOB, I2C1_SDA);
	I2CDLY_5uSec(1);
	GPIO_SetBits(GPIOB, I2C1_SCL);
	I2CDLY_5uSec(1);
	GPIO_SetBits(GPIOB, I2C1_SDA);
}

static void I2C2_WriteByte(BYTE data)
{
	WORD i, tmpbyte = data;

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

static void I2C1_WriteByte(BYTE data)
{
	WORD i, tmpbyte = data;

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

static void I2C2_SlaveAck(BYTE flag)
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

static void I2C1_SlaveAck(BYTE flag)
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

WORD I2C2_ReadByte(void)
{
	BYTE i;
	BYTE ReadValue = 0;
	GPIO_InitTypeDef GPIO_InitStruct;
	BYTE bit;

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
BYTE I2C1_ReadByte(void)
{
	BYTE i, bit, ReadValue = 0;
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

