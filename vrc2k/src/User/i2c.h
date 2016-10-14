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
#include "stm32f10x.h"
#include "mdin3xx.h"

#define ClockSpeed	400000
#define I2C_OK	1

#define I2C1_SCL	GPIO_Pin_6
#define I2C1_SDA	GPIO_Pin_7

#define I2C2_SCL	GPIO_Pin_10
#define I2C2_SDA	GPIO_Pin_11

extern MDIN_ERROR_t I2CDLY_5uSec(WORD delay);

BYTE I2C1_ByteRead(BYTE DevID, BYTE Register, PBYTE pBuff);
BYTE I2C1_ByteWrite(BYTE DevID, BYTE WriteReg, BYTE pBuff);

BYTE I2C2_ByteRead(WORD DevID, WORD Register, PBYTE pBuff, WORD bytes);
BYTE I2C2_ByteWrite(WORD DevID, WORD Register, PBYTE pBuff, WORD bytes);

#endif /* _I2C_HEADER_*/

