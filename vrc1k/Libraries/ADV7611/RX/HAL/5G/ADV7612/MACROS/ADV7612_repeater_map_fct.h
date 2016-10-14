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
* DATE: 10 Aug 2010 11:2:23                                                    *
*                                                                              *
*******************************************************************************/


#ifndef ADV7612_REPEATER_MAP_FCT_H
#define ADV7612_REPEATER_MAP_FCT_H

#include "ADV7612_cfg.h"

#define VRX_get_BKSV(pval)                                  ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0x00, 5, pval)

#define VRX_get_RI(pval)                                    ATV_I2CGetField32LE(VRX_REPEATER_MAP_ADDR, 0x08, 0xFF, 0xFF, 0, 2, pval)
#define VRX_ret_RI()                                        ATV_I2CReadField32LE(VRX_REPEATER_MAP_ADDR, 0x08, 0xFF, 0xFF, 0, 2)

#define VRX_get_PJ(pval)                                    ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x0A, 0xFF, 0, pval)
#define VRX_ret_PJ()                                        ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x0A, 0xFF, 0)

#define VRX_get_AKSV(pval)                                  ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0x10, 5, pval)
#define VRX_set_AKSV(pval)                                  ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0x10, 5, pval)

#define VRX_get_AINFO(pval)                                 ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x15, 0xFF, 0, pval)
#define VRX_ret_AINFO()                                     ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x15, 0xFF, 0)
#define VRX_set_AINFO(val)                                  ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x15, 0xFF, 0, val)

#define VRX_get_AN(pval)                                    ATV_I2CGetMultiField(VRX_REPEATER_MAP_ADDR, 0x18, 8, pval)
#define VRX_set_AN(pval)                                    ATV_I2CSetMultiField(VRX_REPEATER_MAP_ADDR, 0x18, 8, pval)

#define VRX_get_SHA_A(pval)                                 ATV_I2CGetField32LE(VRX_REPEATER_MAP_ADDR, 0x20, 0xFF, 0xFF, 0, 4, pval)
#define VRX_ret_SHA_A()                                     ATV_I2CReadField32LE(VRX_REPEATER_MAP_ADDR, 0x20, 0xFF, 0xFF, 0, 4)
#define VRX_set_SHA_A(val)                                  ATV_I2CWriteField32LE(VRX_REPEATER_MAP_ADDR, 0x20, 0xFF, 0xFF, 0, 4, val)

#define VRX_get_SHA_B(pval)                                 ATV_I2CGetField32LE(VRX_REPEATER_MAP_ADDR, 0x24, 0xFF, 0xFF, 0, 4, pval)
#define VRX_ret_SHA_B()                                     ATV_I2CReadField32LE(VRX_REPEATER_MAP_ADDR, 0x24, 0xFF, 0xFF, 0, 4)
#define VRX_set_SHA_B(val)                                  ATV_I2CWriteField32LE(VRX_REPEATER_MAP_ADDR, 0x24, 0xFF, 0xFF, 0, 4, val)

#define VRX_get_BCAPS(pval)                                 ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x40, 0xFF, 0, pval)
#define VRX_ret_BCAPS()                                     ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x40, 0xFF, 0)
#define VRX_set_BCAPS(val)                                  ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x40, 0xFF, 0, val)

#define VRX_get_BSTATUS(pval)                               ATV_I2CGetField32LE(VRX_REPEATER_MAP_ADDR, 0x41, 0xFF, 0xFF, 0, 2, pval)
#define VRX_ret_BSTATUS()                                   ATV_I2CReadField32LE(VRX_REPEATER_MAP_ADDR, 0x41, 0xFF, 0xFF, 0, 2)
#define VRX_set_BSTATUS(val)                                ATV_I2CWriteField32LE(VRX_REPEATER_MAP_ADDR, 0x41, 0xFF, 0xFF, 0, 2, val)

#define VRX_get_SPA_PORT_B(pval)                            ATV_I2CGetField32(VRX_REPEATER_MAP_ADDR, 0x52, 0xFF, 0xFF, 0, 2, pval)
#define VRX_ret_SPA_PORT_B()                                ATV_I2CReadField32(VRX_REPEATER_MAP_ADDR, 0x52, 0xFF, 0xFF, 0, 2)
#define VRX_set_SPA_PORT_B(val)                             ATV_I2CWriteField32(VRX_REPEATER_MAP_ADDR, 0x52, 0xFF, 0xFF, 0, 2, val)

#define VRX_get_PORT_B_CHECKSUM(pval)                       ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x61, 0xFF, 0, pval)
#define VRX_ret_PORT_B_CHECKSUM()                           ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x61, 0xFF, 0)
#define VRX_set_PORT_B_CHECKSUM(val)                        ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x61, 0xFF, 0, val)

#define VRX_get_SPA_LOCATION(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x70, 0xFF, 0, pval)
#define VRX_ret_SPA_LOCATION()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x70, 0xFF, 0)
#define VRX_set_SPA_LOCATION(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x70, 0xFF, 0, val)

#define VRX_is_KSV_LIST_READY_true()                        ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x71, 0x80, 0x7)
#define VRX_get_KSV_LIST_READY(pval)                        ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x71, 0x80, 0x7, pval)
#define VRX_ret_KSV_LIST_READY()                            ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x71, 0x80, 0x7)
#define VRX_set_KSV_LIST_READY(val)                         ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x71, 0x80, 0x7, val)

#define VRX_is_SPA_STORAGE_MODE_true()                      ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x71, 0x2, 0x1)
#define VRX_get_SPA_STORAGE_MODE(pval)                      ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x71, 0x2, 0x1, pval)
#define VRX_ret_SPA_STORAGE_MODE()                          ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x71, 0x2, 0x1)
#define VRX_set_SPA_STORAGE_MODE(val)                       ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x71, 0x2, 0x1, val)

#define VRX_is_SPA_LOCATION_MSB_true()                      ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x71, 0x1, 0x0)
#define VRX_get_SPA_LOCATION_MSB(pval)                      ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x71, 0x1, 0x0, pval)
#define VRX_ret_SPA_LOCATION_MSB()                          ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x71, 0x1, 0x0)
#define VRX_set_SPA_LOCATION_MSB(val)                       ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x71, 0x1, 0x0, val)

#define VRX_is_EDID_B_ENABLE_true()                         ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x74, 0x2, 0x1)
#define VRX_get_EDID_B_ENABLE(pval)                         ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x74, 0x2, 0x1, pval)
#define VRX_ret_EDID_B_ENABLE()                             ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x74, 0x2, 0x1)
#define VRX_set_EDID_B_ENABLE(val)                          ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x74, 0x2, 0x1, val)

#define VRX_is_EDID_A_ENABLE_true()                         ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x74, 0x1, 0x0)
#define VRX_get_EDID_A_ENABLE(pval)                         ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x74, 0x1, 0x0, pval)
#define VRX_ret_EDID_A_ENABLE()                             ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x74, 0x1, 0x0)
#define VRX_set_EDID_A_ENABLE(val)                          ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x74, 0x1, 0x0, val)

#define VRX_is_EDID_B_ENABLE_CPU_true()                     ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x76, 0x2, 0x1)
#define VRX_get_EDID_B_ENABLE_CPU(pval)                     ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x76, 0x2, 0x1, pval)
#define VRX_ret_EDID_B_ENABLE_CPU()                         ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x76, 0x2, 0x1)

#define VRX_is_EDID_A_ENABLE_CPU_true()                     ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x76, 0x1, 0x0)
#define VRX_get_EDID_A_ENABLE_CPU(pval)                     ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x76, 0x1, 0x0, pval)
#define VRX_ret_EDID_A_ENABLE_CPU()                         ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x76, 0x1, 0x0)

#define VRX_set_KSV_LIST_READY_CLR_B(val)                   ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x78, 0x2, 0x1, val)

#define VRX_set_KSV_LIST_READY_CLR_A(val)                   ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x78, 0x1, 0x0, val)

#define VRX_get_KSV_MAP_SELECT(pval)                        ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x79, 0x70, 4, pval)
#define VRX_ret_KSV_MAP_SELECT()                            ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x79, 0x70, 4)
#define VRX_set_KSV_MAP_SELECT(val)                         ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x79, 0x70, 4, val)

#define VRX_is_AUTO_HDCP_MAP_ENABLE_true()                  ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x79, 0x8, 0x3)
#define VRX_get_AUTO_HDCP_MAP_ENABLE(pval)                  ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x79, 0x8, 0x3, pval)
#define VRX_ret_AUTO_HDCP_MAP_ENABLE()                      ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x79, 0x8, 0x3)
#define VRX_set_AUTO_HDCP_MAP_ENABLE(val)                   ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x79, 0x8, 0x3, val)

#define VRX_get_HDCP_MAP_SELECT(pval)                       ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x79, 0x7, 0, pval)
#define VRX_ret_HDCP_MAP_SELECT()                           ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x79, 0x7, 0)
#define VRX_set_HDCP_MAP_SELECT(val)                        ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x79, 0x7, 0, val)

#define VRX_is_DISABLE_AUTO_EDID_true()                     ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x7A, 0x2, 0x1)
#define VRX_get_DISABLE_AUTO_EDID(pval)                     ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x7A, 0x2, 0x1, pval)
#define VRX_ret_DISABLE_AUTO_EDID()                         ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x7A, 0x2, 0x1)
#define VRX_set_DISABLE_AUTO_EDID(val)                      ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x7A, 0x2, 0x1, val)

#define VRX_is_EDID_SEGMENT_POINTER_true()                  ATV_I2CIsField8(VRX_REPEATER_MAP_ADDR, 0x7A, 0x1, 0x0)
#define VRX_get_EDID_SEGMENT_POINTER(pval)                  ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x7A, 0x1, 0x0, pval)
#define VRX_ret_EDID_SEGMENT_POINTER()                      ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x7A, 0x1, 0x0)
#define VRX_set_EDID_SEGMENT_POINTER(val)                   ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x7A, 0x1, 0x0, val)

#define VRX_get_KSV_BYTE_0(pval)                            ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x80, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_0()                                ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x80, 0xFF, 0)
#define VRX_set_KSV_BYTE_0(val)                             ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x80, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_1(pval)                            ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x81, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_1()                                ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x81, 0xFF, 0)
#define VRX_set_KSV_BYTE_1(val)                             ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x81, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_2(pval)                            ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x82, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_2()                                ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x82, 0xFF, 0)
#define VRX_set_KSV_BYTE_2(val)                             ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x82, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_3(pval)                            ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x83, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_3()                                ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x83, 0xFF, 0)
#define VRX_set_KSV_BYTE_3(val)                             ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x83, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_4(pval)                            ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x84, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_4()                                ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x84, 0xFF, 0)
#define VRX_set_KSV_BYTE_4(val)                             ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x84, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_5(pval)                            ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x85, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_5()                                ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x85, 0xFF, 0)
#define VRX_set_KSV_BYTE_5(val)                             ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x85, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_6(pval)                            ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x86, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_6()                                ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x86, 0xFF, 0)
#define VRX_set_KSV_BYTE_6(val)                             ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x86, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_7(pval)                            ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x87, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_7()                                ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x87, 0xFF, 0)
#define VRX_set_KSV_BYTE_7(val)                             ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x87, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_8(pval)                            ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x88, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_8()                                ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x88, 0xFF, 0)
#define VRX_set_KSV_BYTE_8(val)                             ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x88, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_9(pval)                            ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x89, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_9()                                ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x89, 0xFF, 0)
#define VRX_set_KSV_BYTE_9(val)                             ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x89, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_10(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x8A, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_10()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x8A, 0xFF, 0)
#define VRX_set_KSV_BYTE_10(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x8A, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_11(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x8B, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_11()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x8B, 0xFF, 0)
#define VRX_set_KSV_BYTE_11(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x8B, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_12(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x8C, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_12()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x8C, 0xFF, 0)
#define VRX_set_KSV_BYTE_12(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x8C, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_13(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x8D, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_13()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x8D, 0xFF, 0)
#define VRX_set_KSV_BYTE_13(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x8D, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_14(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x8E, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_14()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x8E, 0xFF, 0)
#define VRX_set_KSV_BYTE_14(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x8E, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_15(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x8F, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_15()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x8F, 0xFF, 0)
#define VRX_set_KSV_BYTE_15(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x8F, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_16(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x90, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_16()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x90, 0xFF, 0)
#define VRX_set_KSV_BYTE_16(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x90, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_17(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x91, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_17()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x91, 0xFF, 0)
#define VRX_set_KSV_BYTE_17(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x91, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_18(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x92, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_18()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x92, 0xFF, 0)
#define VRX_set_KSV_BYTE_18(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x92, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_19(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x93, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_19()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x93, 0xFF, 0)
#define VRX_set_KSV_BYTE_19(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x93, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_20(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x94, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_20()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x94, 0xFF, 0)
#define VRX_set_KSV_BYTE_20(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x94, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_21(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x95, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_21()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x95, 0xFF, 0)
#define VRX_set_KSV_BYTE_21(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x95, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_22(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x96, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_22()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x96, 0xFF, 0)
#define VRX_set_KSV_BYTE_22(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x96, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_23(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x97, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_23()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x97, 0xFF, 0)
#define VRX_set_KSV_BYTE_23(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x97, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_24(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x98, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_24()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x98, 0xFF, 0)
#define VRX_set_KSV_BYTE_24(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x98, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_25(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x99, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_25()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x99, 0xFF, 0)
#define VRX_set_KSV_BYTE_25(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x99, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_26(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x9A, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_26()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x9A, 0xFF, 0)
#define VRX_set_KSV_BYTE_26(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x9A, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_27(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x9B, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_27()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x9B, 0xFF, 0)
#define VRX_set_KSV_BYTE_27(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x9B, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_28(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x9C, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_28()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x9C, 0xFF, 0)
#define VRX_set_KSV_BYTE_28(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x9C, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_29(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x9D, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_29()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x9D, 0xFF, 0)
#define VRX_set_KSV_BYTE_29(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x9D, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_30(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x9E, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_30()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x9E, 0xFF, 0)
#define VRX_set_KSV_BYTE_30(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x9E, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_31(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0x9F, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_31()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0x9F, 0xFF, 0)
#define VRX_set_KSV_BYTE_31(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0x9F, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_32(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xA0, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_32()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xA0, 0xFF, 0)
#define VRX_set_KSV_BYTE_32(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xA0, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_33(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xA1, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_33()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xA1, 0xFF, 0)
#define VRX_set_KSV_BYTE_33(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xA1, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_34(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xA2, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_34()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xA2, 0xFF, 0)
#define VRX_set_KSV_BYTE_34(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xA2, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_35(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xA3, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_35()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xA3, 0xFF, 0)
#define VRX_set_KSV_BYTE_35(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xA3, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_36(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xA4, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_36()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xA4, 0xFF, 0)
#define VRX_set_KSV_BYTE_36(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xA4, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_37(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xA5, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_37()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xA5, 0xFF, 0)
#define VRX_set_KSV_BYTE_37(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xA5, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_38(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xA6, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_38()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xA6, 0xFF, 0)
#define VRX_set_KSV_BYTE_38(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xA6, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_39(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xA7, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_39()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xA7, 0xFF, 0)
#define VRX_set_KSV_BYTE_39(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xA7, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_40(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xA8, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_40()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xA8, 0xFF, 0)
#define VRX_set_KSV_BYTE_40(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xA8, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_41(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xA9, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_41()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xA9, 0xFF, 0)
#define VRX_set_KSV_BYTE_41(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xA9, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_42(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xAA, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_42()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xAA, 0xFF, 0)
#define VRX_set_KSV_BYTE_42(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xAA, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_43(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xAB, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_43()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xAB, 0xFF, 0)
#define VRX_set_KSV_BYTE_43(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xAB, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_44(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xAC, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_44()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xAC, 0xFF, 0)
#define VRX_set_KSV_BYTE_44(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xAC, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_45(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xAD, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_45()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xAD, 0xFF, 0)
#define VRX_set_KSV_BYTE_45(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xAD, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_46(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xAE, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_46()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xAE, 0xFF, 0)
#define VRX_set_KSV_BYTE_46(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xAE, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_47(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xAF, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_47()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xAF, 0xFF, 0)
#define VRX_set_KSV_BYTE_47(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xAF, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_48(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xB0, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_48()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xB0, 0xFF, 0)
#define VRX_set_KSV_BYTE_48(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xB0, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_49(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xB1, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_49()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xB1, 0xFF, 0)
#define VRX_set_KSV_BYTE_49(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xB1, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_50(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xB2, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_50()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xB2, 0xFF, 0)
#define VRX_set_KSV_BYTE_50(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xB2, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_51(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xB3, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_51()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xB3, 0xFF, 0)
#define VRX_set_KSV_BYTE_51(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xB3, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_52(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xB4, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_52()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xB4, 0xFF, 0)
#define VRX_set_KSV_BYTE_52(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xB4, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_53(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xB5, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_53()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xB5, 0xFF, 0)
#define VRX_set_KSV_BYTE_53(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xB5, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_54(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xB6, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_54()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xB6, 0xFF, 0)
#define VRX_set_KSV_BYTE_54(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xB6, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_55(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xB7, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_55()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xB7, 0xFF, 0)
#define VRX_set_KSV_BYTE_55(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xB7, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_56(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xB8, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_56()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xB8, 0xFF, 0)
#define VRX_set_KSV_BYTE_56(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xB8, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_57(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xB9, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_57()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xB9, 0xFF, 0)
#define VRX_set_KSV_BYTE_57(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xB9, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_58(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xBA, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_58()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xBA, 0xFF, 0)
#define VRX_set_KSV_BYTE_58(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xBA, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_59(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xBB, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_59()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xBB, 0xFF, 0)
#define VRX_set_KSV_BYTE_59(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xBB, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_60(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xBC, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_60()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xBC, 0xFF, 0)
#define VRX_set_KSV_BYTE_60(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xBC, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_61(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xBD, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_61()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xBD, 0xFF, 0)
#define VRX_set_KSV_BYTE_61(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xBD, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_62(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xBE, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_62()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xBE, 0xFF, 0)
#define VRX_set_KSV_BYTE_62(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xBE, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_63(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xBF, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_63()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xBF, 0xFF, 0)
#define VRX_set_KSV_BYTE_63(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xBF, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_64(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xC0, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_64()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xC0, 0xFF, 0)
#define VRX_set_KSV_BYTE_64(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xC0, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_65(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xC1, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_65()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xC1, 0xFF, 0)
#define VRX_set_KSV_BYTE_65(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xC1, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_66(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xC2, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_66()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xC2, 0xFF, 0)
#define VRX_set_KSV_BYTE_66(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xC2, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_67(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xC3, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_67()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xC3, 0xFF, 0)
#define VRX_set_KSV_BYTE_67(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xC3, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_68(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xC4, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_68()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xC4, 0xFF, 0)
#define VRX_set_KSV_BYTE_68(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xC4, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_69(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xC5, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_69()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xC5, 0xFF, 0)
#define VRX_set_KSV_BYTE_69(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xC5, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_70(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xC6, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_70()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xC6, 0xFF, 0)
#define VRX_set_KSV_BYTE_70(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xC6, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_71(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xC7, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_71()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xC7, 0xFF, 0)
#define VRX_set_KSV_BYTE_71(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xC7, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_72(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xC8, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_72()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xC8, 0xFF, 0)
#define VRX_set_KSV_BYTE_72(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xC8, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_73(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xC9, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_73()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xC9, 0xFF, 0)
#define VRX_set_KSV_BYTE_73(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xC9, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_74(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xCA, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_74()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xCA, 0xFF, 0)
#define VRX_set_KSV_BYTE_74(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xCA, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_75(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xCB, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_75()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xCB, 0xFF, 0)
#define VRX_set_KSV_BYTE_75(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xCB, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_76(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xCC, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_76()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xCC, 0xFF, 0)
#define VRX_set_KSV_BYTE_76(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xCC, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_77(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xCD, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_77()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xCD, 0xFF, 0)
#define VRX_set_KSV_BYTE_77(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xCD, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_78(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xCE, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_78()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xCE, 0xFF, 0)
#define VRX_set_KSV_BYTE_78(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xCE, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_79(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xCF, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_79()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xCF, 0xFF, 0)
#define VRX_set_KSV_BYTE_79(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xCF, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_80(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xD0, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_80()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xD0, 0xFF, 0)
#define VRX_set_KSV_BYTE_80(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xD0, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_81(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xD1, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_81()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xD1, 0xFF, 0)
#define VRX_set_KSV_BYTE_81(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xD1, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_82(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xD2, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_82()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xD2, 0xFF, 0)
#define VRX_set_KSV_BYTE_82(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xD2, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_83(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xD3, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_83()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xD3, 0xFF, 0)
#define VRX_set_KSV_BYTE_83(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xD3, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_84(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xD4, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_84()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xD4, 0xFF, 0)
#define VRX_set_KSV_BYTE_84(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xD4, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_85(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xD5, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_85()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xD5, 0xFF, 0)
#define VRX_set_KSV_BYTE_85(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xD5, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_86(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xD6, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_86()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xD6, 0xFF, 0)
#define VRX_set_KSV_BYTE_86(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xD6, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_87(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xD7, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_87()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xD7, 0xFF, 0)
#define VRX_set_KSV_BYTE_87(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xD7, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_88(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xD8, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_88()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xD8, 0xFF, 0)
#define VRX_set_KSV_BYTE_88(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xD8, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_89(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xD9, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_89()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xD9, 0xFF, 0)
#define VRX_set_KSV_BYTE_89(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xD9, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_90(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xDA, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_90()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xDA, 0xFF, 0)
#define VRX_set_KSV_BYTE_90(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xDA, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_91(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xDB, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_91()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xDB, 0xFF, 0)
#define VRX_set_KSV_BYTE_91(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xDB, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_92(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xDC, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_92()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xDC, 0xFF, 0)
#define VRX_set_KSV_BYTE_92(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xDC, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_93(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xDD, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_93()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xDD, 0xFF, 0)
#define VRX_set_KSV_BYTE_93(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xDD, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_94(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xDE, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_94()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xDE, 0xFF, 0)
#define VRX_set_KSV_BYTE_94(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xDE, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_95(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xDF, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_95()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xDF, 0xFF, 0)
#define VRX_set_KSV_BYTE_95(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xDF, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_96(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xE0, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_96()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xE0, 0xFF, 0)
#define VRX_set_KSV_BYTE_96(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xE0, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_97(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xE1, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_97()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xE1, 0xFF, 0)
#define VRX_set_KSV_BYTE_97(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xE1, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_98(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xE2, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_98()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xE2, 0xFF, 0)
#define VRX_set_KSV_BYTE_98(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xE2, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_99(pval)                           ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xE3, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_99()                               ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xE3, 0xFF, 0)
#define VRX_set_KSV_BYTE_99(val)                            ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xE3, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_100(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xE4, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_100()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xE4, 0xFF, 0)
#define VRX_set_KSV_BYTE_100(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xE4, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_101(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xE5, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_101()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xE5, 0xFF, 0)
#define VRX_set_KSV_BYTE_101(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xE5, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_102(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xE6, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_102()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xE6, 0xFF, 0)
#define VRX_set_KSV_BYTE_102(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xE6, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_103(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xE7, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_103()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xE7, 0xFF, 0)
#define VRX_set_KSV_BYTE_103(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xE7, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_104(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xE8, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_104()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xE8, 0xFF, 0)
#define VRX_set_KSV_BYTE_104(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xE8, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_105(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xE9, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_105()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xE9, 0xFF, 0)
#define VRX_set_KSV_BYTE_105(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xE9, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_106(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xEA, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_106()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xEA, 0xFF, 0)
#define VRX_set_KSV_BYTE_106(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xEA, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_107(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xEB, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_107()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xEB, 0xFF, 0)
#define VRX_set_KSV_BYTE_107(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xEB, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_108(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xEC, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_108()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xEC, 0xFF, 0)
#define VRX_set_KSV_BYTE_108(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xEC, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_109(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xED, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_109()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xED, 0xFF, 0)
#define VRX_set_KSV_BYTE_109(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xED, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_110(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xEE, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_110()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xEE, 0xFF, 0)
#define VRX_set_KSV_BYTE_110(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xEE, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_111(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xEF, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_111()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xEF, 0xFF, 0)
#define VRX_set_KSV_BYTE_111(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xEF, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_112(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xF0, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_112()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xF0, 0xFF, 0)
#define VRX_set_KSV_BYTE_112(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xF0, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_113(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xF1, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_113()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xF1, 0xFF, 0)
#define VRX_set_KSV_BYTE_113(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xF1, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_114(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xF2, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_114()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xF2, 0xFF, 0)
#define VRX_set_KSV_BYTE_114(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xF2, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_115(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xF3, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_115()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xF3, 0xFF, 0)
#define VRX_set_KSV_BYTE_115(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xF3, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_116(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xF4, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_116()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xF4, 0xFF, 0)
#define VRX_set_KSV_BYTE_116(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xF4, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_117(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xF5, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_117()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xF5, 0xFF, 0)
#define VRX_set_KSV_BYTE_117(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xF5, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_118(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xF6, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_118()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xF6, 0xFF, 0)
#define VRX_set_KSV_BYTE_118(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xF6, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_119(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xF7, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_119()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xF7, 0xFF, 0)
#define VRX_set_KSV_BYTE_119(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xF7, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_120(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xF8, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_120()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xF8, 0xFF, 0)
#define VRX_set_KSV_BYTE_120(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xF8, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_121(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xF9, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_121()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xF9, 0xFF, 0)
#define VRX_set_KSV_BYTE_121(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xF9, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_122(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xFA, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_122()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xFA, 0xFF, 0)
#define VRX_set_KSV_BYTE_122(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xFA, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_123(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xFB, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_123()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xFB, 0xFF, 0)
#define VRX_set_KSV_BYTE_123(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xFB, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_124(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xFC, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_124()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xFC, 0xFF, 0)
#define VRX_set_KSV_BYTE_124(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xFC, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_125(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xFD, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_125()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xFD, 0xFF, 0)
#define VRX_set_KSV_BYTE_125(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xFD, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_126(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xFE, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_126()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xFE, 0xFF, 0)
#define VRX_set_KSV_BYTE_126(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xFE, 0xFF, 0, val)

#define VRX_get_KSV_BYTE_127(pval)                          ATV_I2CGetField8(VRX_REPEATER_MAP_ADDR, 0xFF, 0xFF, 0, pval)
#define VRX_ret_KSV_BYTE_127()                              ATV_I2CReadField8(VRX_REPEATER_MAP_ADDR, 0xFF, 0xFF, 0)
#define VRX_set_KSV_BYTE_127(val)                           ATV_I2CWriteField8(VRX_REPEATER_MAP_ADDR, 0xFF, 0xFF, 0, val)

#endif
