/**********************************************************************************************
*																						      *
* Copyright (c) 2008 - 2012 Analog Devices, Inc.  All Rights Reserved.                        *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/
/*******************************************************************************
*                                                                              *

* This software is intended for use with the ADV7612 part only.                *
*                                                                              *
*******************************************************************************/

/*******************************************************************************
*                                                                              *
* FILE AUTOMATICALLY GENERATED.                                                *
* DATE: 10 Aug 2010 11:2:28                                                    *
*                                                                              *
*******************************************************************************/


#ifndef ADV7612_DPLL_MAP_FCT_H
#define ADV7612_DPLL_MAP_FCT_H

#include "ADV7612_cfg.h"

#define VRX_get_CLK_DIVIDE_RATIO(pval)                      ATV_I2CGetField8(VRX_DPLL_MAP_ADDR, 0xA0, 0xF, 0, pval)
#define VRX_ret_CLK_DIVIDE_RATIO()                          ATV_I2CReadField8(VRX_DPLL_MAP_ADDR, 0xA0, 0xF, 0)
#define VRX_set_CLK_DIVIDE_RATIO(val)                       ATV_I2CWriteField8(VRX_DPLL_MAP_ADDR, 0xA0, 0xF, 0, val)

#define VRX_get_MCLK_FS_N(pval)                             ATV_I2CGetField8(VRX_DPLL_MAP_ADDR, 0xB5, 0x7, 0, pval)
#define VRX_ret_MCLK_FS_N()                                 ATV_I2CReadField8(VRX_DPLL_MAP_ADDR, 0xB5, 0x7, 0)
#define VRX_set_MCLK_FS_N(val)                              ATV_I2CWriteField8(VRX_DPLL_MAP_ADDR, 0xB5, 0x7, 0, val)

#endif
