/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#ifndef _7612_HAL_H_ 
#define _7612_HAL_H_

#if (RX_DEVICE==7612)

#include "ADV7612_cfg.h"
#include "ADV7612_lib.h"
#include "rx_5g_hal.h"


#define VRX_is_DIS_I2S_ZERO_COMPR_true()                   ATV_I2CIsField8(VRX_HDMI_MAP_ADDR, 0x03, 0x80, 0x7)
#define VRX_get_DIS_I2S_ZERO_COMPR(pval)                   ATV_I2CGetField8(VRX_HDMI_MAP_ADDR, 0x03, 0x80, 0x7, pval)
#define VRX_ret_DIS_I2S_ZERO_COMPR()                       ATV_I2CReadField8(VRX_HDMI_MAP_ADDR, 0x03, 0x80, 0x7)
#define VRX_set_DIS_I2S_ZERO_COMPR(val)                    ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x03, 0x80, 0x7, val)


#ifdef __cplusplus
extern "C" {
#endif





#ifdef __cplusplus
}
#endif

#endif

#endif
