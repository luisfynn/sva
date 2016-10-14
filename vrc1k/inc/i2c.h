/**
 *	@file   i2c.h
 *	@brief	
 *	@author luisfynn <tani223@pinetron.com>
 *	@date   2014/10/14 13:17
 */

#ifndef _I2C_HEADER_
#define _I2C_HEADER_

/* system include */
/* local include */
#include "stm32f10x_conf.h"
#include "mdintype.h"
#include "stm32f10x_system.h"
/* external variable & function */
#define ClockSpeed	400000

#define I2C1_SCL	GPIO_Pin_6
#define I2C1_SDA	GPIO_Pin_7

#define I2C2_SCL	GPIO_Pin_10
#define I2C2_SDA	GPIO_Pin_11

I2C_InitTypeDef I2C_InitStructure;

void I2C1_Start(void);
void I2C1_Stop(void);
BYTE I2C1_ByteRead(BYTE DevID, BYTE Register, PBYTE pBuff);
BYTE I2C1_ByteWrite(BYTE DevID, BYTE WriteReg, BYTE pBuff);
void I2C1_WriteByte(BYTE data);
void I2C1_SlaveAck(BYTE flag);
BYTE I2C1_ReadByte(void);

void I2C2_Start(void);
void I2C2_Stop(void);
BYTE I2C2_ByteRead(unsigned int DevID, unsigned int Register, PBYTE pBuff, WORD bytes);
BYTE I2C2_ByteWrite(unsigned int DevID, unsigned int Register, PBYTE pBuff, WORD bytes);
void I2C2_WriteByte(BYTE data);
void I2C2_SlaveAck(BYTE flag);
unsigned int I2C2_ReadByte(void);
void I2C2_SlaveAck(BYTE flag);

#endif /* _I2C_HEADER_*/

