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


#ifndef ADV7612_CP_MAP_FCT_H
#define ADV7612_CP_MAP_FCT_H

#include "ADV7612_cfg.h"

#define VRX_get_DE_V_START_R(pval)                          ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x30, 0xF0, 4, pval)
#define VRX_ret_DE_V_START_R()                              ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x30, 0xF0, 4)
#define VRX_set_DE_V_START_R(val)                           ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x30, 0xF0, 4, val)

#define VRX_get_DE_V_END_R(pval)                            ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x30, 0xF, 0, pval)
#define VRX_ret_DE_V_END_R()                                ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x30, 0xF, 0)
#define VRX_set_DE_V_END_R(val)                             ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x30, 0xF, 0, val)

#define VRX_get_DE_V_START_EVEN_R(pval)                     ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x31, 0xF0, 4, pval)
#define VRX_ret_DE_V_START_EVEN_R()                         ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x31, 0xF0, 4)
#define VRX_set_DE_V_START_EVEN_R(val)                      ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x31, 0xF0, 4, val)

#define VRX_get_DE_V_END_EVEN_R(pval)                       ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x31, 0xF, 0, pval)
#define VRX_ret_DE_V_END_EVEN_R()                           ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x31, 0xF, 0)
#define VRX_set_DE_V_END_EVEN_R(val)                        ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x31, 0xF, 0, val)

#define VRX_is_TEN_TO_EIGHT_CONV_true()                     ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x36, 0x1, 0x0)
#define VRX_get_TEN_TO_EIGHT_CONV(pval)                     ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x36, 0x1, 0x0, pval)
#define VRX_ret_TEN_TO_EIGHT_CONV()                         ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x36, 0x1, 0x0)
#define VRX_set_TEN_TO_EIGHT_CONV(val)                      ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x36, 0x1, 0x0, val)

#define VRX_get_CP_CONTRAST(pval)                           ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x3A, 0xFF, 0, pval)
#define VRX_ret_CP_CONTRAST()                               ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x3A, 0xFF, 0)
#define VRX_set_CP_CONTRAST(val)                            ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x3A, 0xFF, 0, val)

#define VRX_get_CP_SATURATION(pval)                         ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x3B, 0xFF, 0, pval)
#define VRX_ret_CP_SATURATION()                             ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x3B, 0xFF, 0)
#define VRX_set_CP_SATURATION(val)                          ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x3B, 0xFF, 0, val)

#define VRX_get_CP_BRIGHTNESS(pval)                         ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x3C, 0xFF, 0, pval)
#define VRX_ret_CP_BRIGHTNESS()                             ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x3C, 0xFF, 0)
#define VRX_set_CP_BRIGHTNESS(val)                          ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x3C, 0xFF, 0, val)

#define VRX_get_CP_HUE(pval)                                ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x3D, 0xFF, 0, pval)
#define VRX_ret_CP_HUE()                                    ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x3D, 0xFF, 0)
#define VRX_set_CP_HUE(val)                                 ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x3D, 0xFF, 0, val)

#define VRX_is_VID_ADJ_EN_true()                            ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x3E, 0x80, 0x7)
#define VRX_get_VID_ADJ_EN(pval)                            ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x3E, 0x80, 0x7, pval)
#define VRX_ret_VID_ADJ_EN()                                ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x3E, 0x80, 0x7)
#define VRX_set_VID_ADJ_EN(val)                             ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x3E, 0x80, 0x7, val)

#define VRX_get_CP_UV_ALIGN_SEL(pval)                       ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x3E, 0x30, 4, pval)
#define VRX_ret_CP_UV_ALIGN_SEL()                           ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x3E, 0x30, 4)
#define VRX_set_CP_UV_ALIGN_SEL(val)                        ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x3E, 0x30, 4, val)

#define VRX_is_CP_UV_DVAL_INV_true()                        ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x3E, 0x8, 0x3)
#define VRX_get_CP_UV_DVAL_INV(pval)                        ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x3E, 0x8, 0x3, pval)
#define VRX_ret_CP_UV_DVAL_INV()                            ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x3E, 0x8, 0x3)
#define VRX_set_CP_UV_DVAL_INV(val)                         ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x3E, 0x8, 0x3, val)

#define VRX_is_CP_MODE_GAIN_ADJ_EN_true()                   ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x3E, 0x4, 0x2)
#define VRX_get_CP_MODE_GAIN_ADJ_EN(pval)                   ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x3E, 0x4, 0x2, pval)
#define VRX_ret_CP_MODE_GAIN_ADJ_EN()                       ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x3E, 0x4, 0x2)
#define VRX_set_CP_MODE_GAIN_ADJ_EN(val)                    ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x3E, 0x4, 0x2, val)

#define VRX_is_ALT_SAT_UV_MAN_true()                        ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x3E, 0x2, 0x1)
#define VRX_get_ALT_SAT_UV_MAN(pval)                        ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x3E, 0x2, 0x1, pval)
#define VRX_ret_ALT_SAT_UV_MAN()                            ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x3E, 0x2, 0x1)
#define VRX_set_ALT_SAT_UV_MAN(val)                         ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x3E, 0x2, 0x1, val)

#define VRX_is_ALT_SAT_UV_true()                            ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x3E, 0x1, 0x0)
#define VRX_get_ALT_SAT_UV(pval)                            ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x3E, 0x1, 0x0, pval)
#define VRX_ret_ALT_SAT_UV()                                ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x3E, 0x1, 0x0)
#define VRX_set_ALT_SAT_UV(val)                             ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x3E, 0x1, 0x0, val)

#define VRX_get_CP_MODE_GAIN_ADJ(pval)                      ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x40, 0xFF, 0, pval)
#define VRX_ret_CP_MODE_GAIN_ADJ()                          ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x40, 0xFF, 0)
#define VRX_set_CP_MODE_GAIN_ADJ(val)                       ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x40, 0xFF, 0, val)

#define VRX_get_CSC_SCALE(pval)                             ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x52, 0xC0, 6, pval)
#define VRX_ret_CSC_SCALE()                                 ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x52, 0xC0, 6)
#define VRX_set_CSC_SCALE(val)                              ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x52, 0xC0, 6, val)

#define VRX_get_A4(pval)                                    ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x52, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_A4()                                        ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x52, 0x1F, 0xFF, 0, 2)
#define VRX_set_A4(val)                                     ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x52, 0x1F, 0xFF, 0, 2, val)

#define VRX_get_A3(pval)                                    ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x54, 0x7F, 0xFC, 2, 2, pval)
#define VRX_ret_A3()                                        ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x54, 0x7F, 0xFC, 2, 2)
#define VRX_set_A3(val)                                     ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x54, 0x7F, 0xFC, 2, 2, val)

#define VRX_get_A2(pval)                                    ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x55, 0x3, 0xE0, 5, 3, pval)
#define VRX_ret_A2()                                        ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x55, 0x3, 0xE0, 5, 3)
#define VRX_set_A2(val)                                     ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x55, 0x3, 0xE0, 5, 3, val)

#define VRX_get_A1(pval)                                    ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x57, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_A1()                                        ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x57, 0x1F, 0xFF, 0, 2)
#define VRX_set_A1(val)                                     ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x57, 0x1F, 0xFF, 0, 2, val)

#define VRX_get_B4(pval)                                    ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x59, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_B4()                                        ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x59, 0x1F, 0xFF, 0, 2)
#define VRX_set_B4(val)                                     ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x59, 0x1F, 0xFF, 0, 2, val)

#define VRX_get_B3(pval)                                    ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x5B, 0x7F, 0xFC, 2, 2, pval)
#define VRX_ret_B3()                                        ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x5B, 0x7F, 0xFC, 2, 2)
#define VRX_set_B3(val)                                     ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x5B, 0x7F, 0xFC, 2, 2, val)

#define VRX_get_B2(pval)                                    ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x5C, 0x3, 0xE0, 5, 3, pval)
#define VRX_ret_B2()                                        ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x5C, 0x3, 0xE0, 5, 3)
#define VRX_set_B2(val)                                     ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x5C, 0x3, 0xE0, 5, 3, val)

#define VRX_get_B1(pval)                                    ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x5E, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_B1()                                        ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x5E, 0x1F, 0xFF, 0, 2)
#define VRX_set_B1(val)                                     ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x5E, 0x1F, 0xFF, 0, 2, val)

#define VRX_get_C4(pval)                                    ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x60, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_C4()                                        ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x60, 0x1F, 0xFF, 0, 2)
#define VRX_set_C4(val)                                     ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x60, 0x1F, 0xFF, 0, 2, val)

#define VRX_get_C3(pval)                                    ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x62, 0x7F, 0xFC, 2, 2, pval)
#define VRX_ret_C3()                                        ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x62, 0x7F, 0xFC, 2, 2)
#define VRX_set_C3(val)                                     ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x62, 0x7F, 0xFC, 2, 2, val)

#define VRX_get_C2(pval)                                    ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x63, 0x3, 0xE0, 5, 3, pval)
#define VRX_ret_C2()                                        ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x63, 0x3, 0xE0, 5, 3)
#define VRX_set_C2(val)                                     ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x63, 0x3, 0xE0, 5, 3, val)

#define VRX_get_C1(pval)                                    ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x65, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_C1()                                        ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x65, 0x1F, 0xFF, 0, 2)
#define VRX_set_C1(val)                                     ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x65, 0x1F, 0xFF, 0, 2, val)

#define VRX_get_CSC_COEFF_SEL(pval)                         ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x68, 0xF0, 4, pval)
#define VRX_ret_CSC_COEFF_SEL()                             ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x68, 0xF0, 4)
#define VRX_set_CSC_COEFF_SEL(val)                          ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x68, 0xF0, 4, val)

#define VRX_is_MAN_CP_CSC_EN_true()                         ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x69, 0x10, 0x4)
#define VRX_get_MAN_CP_CSC_EN(pval)                         ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x69, 0x10, 0x4, pval)
#define VRX_ret_MAN_CP_CSC_EN()                             ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x69, 0x10, 0x4)
#define VRX_set_MAN_CP_CSC_EN(val)                          ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x69, 0x10, 0x4, val)

#define VRX_is_EIA_861_COMPLIANCE_true()                    ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x69, 0x4, 0x2)
#define VRX_get_EIA_861_COMPLIANCE(pval)                    ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x69, 0x4, 0x2, pval)
#define VRX_ret_EIA_861_COMPLIANCE()                        ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x69, 0x4, 0x2)
#define VRX_set_EIA_861_COMPLIANCE(val)                     ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x69, 0x4, 0x2, val)

#define VRX_is_CLMP_A_MAN_true()                            ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x6C, 0x80, 0x7)
#define VRX_get_CLMP_A_MAN(pval)                            ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x6C, 0x80, 0x7, pval)
#define VRX_ret_CLMP_A_MAN()                                ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x6C, 0x80, 0x7)
#define VRX_set_CLMP_A_MAN(val)                             ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x6C, 0x80, 0x7, val)

#define VRX_is_CLMP_BC_MAN_true()                           ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x6C, 0x40, 0x6)
#define VRX_get_CLMP_BC_MAN(pval)                           ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x6C, 0x40, 0x6, pval)
#define VRX_ret_CLMP_BC_MAN()                               ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x6C, 0x40, 0x6)
#define VRX_set_CLMP_BC_MAN(val)                            ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x6C, 0x40, 0x6, val)

#define VRX_is_CLMP_FREEZE_true()                           ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x6C, 0x20, 0x5)
#define VRX_get_CLMP_FREEZE(pval)                           ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x6C, 0x20, 0x5, pval)
#define VRX_ret_CLMP_FREEZE()                               ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x6C, 0x20, 0x5)
#define VRX_set_CLMP_FREEZE(val)                            ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x6C, 0x20, 0x5, val)

#define VRX_get_CLMP_A(pval)                                ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x6C, 0xF, 0xFF, 0, 2, pval)
#define VRX_ret_CLMP_A()                                    ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x6C, 0xF, 0xFF, 0, 2)
#define VRX_set_CLMP_A(val)                                 ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x6C, 0xF, 0xFF, 0, 2, val)

#define VRX_get_CLMP_B(pval)                                ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x6E, 0xFF, 0xF0, 4, 2, pval)
#define VRX_ret_CLMP_B()                                    ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x6E, 0xFF, 0xF0, 4, 2)
#define VRX_set_CLMP_B(val)                                 ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x6E, 0xFF, 0xF0, 4, 2, val)

#define VRX_get_CLMP_C(pval)                                ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x6F, 0xF, 0xFF, 0, 2, pval)
#define VRX_ret_CLMP_C()                                    ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x6F, 0xF, 0xFF, 0, 2)
#define VRX_set_CLMP_C(val)                                 ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x6F, 0xF, 0xFF, 0, 2, val)

#define VRX_is_GAIN_MAN_true()                              ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x73, 0x80, 0x7)
#define VRX_get_GAIN_MAN(pval)                              ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x73, 0x80, 0x7, pval)
#define VRX_ret_GAIN_MAN()                                  ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x73, 0x80, 0x7)
#define VRX_set_GAIN_MAN(val)                               ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x73, 0x80, 0x7, val)

#define VRX_is_AGC_MODE_MAN_true()                          ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x73, 0x40, 0x6)
#define VRX_get_AGC_MODE_MAN(pval)                          ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x73, 0x40, 0x6, pval)
#define VRX_ret_AGC_MODE_MAN()                              ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x73, 0x40, 0x6)
#define VRX_set_AGC_MODE_MAN(val)                           ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x73, 0x40, 0x6, val)

#define VRX_get_A_GAIN(pval)                                ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x73, 0x3F, 0xF0, 4, 2, pval)
#define VRX_ret_A_GAIN()                                    ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x73, 0x3F, 0xF0, 4, 2)
#define VRX_set_A_GAIN(val)                                 ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x73, 0x3F, 0xF0, 4, 2, val)

#define VRX_get_B_GAIN(pval)                                ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x74, 0xF, 0xFC, 2, 2, pval)
#define VRX_ret_B_GAIN()                                    ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x74, 0xF, 0xFC, 2, 2)
#define VRX_set_B_GAIN(val)                                 ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x74, 0xF, 0xFC, 2, 2, val)

#define VRX_get_C_GAIN(pval)                                ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x75, 0x3, 0xFF, 0, 2, pval)
#define VRX_ret_C_GAIN()                                    ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x75, 0x3, 0xFF, 0, 2)
#define VRX_set_C_GAIN(val)                                 ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x75, 0x3, 0xFF, 0, 2, val)

#define VRX_get_CP_PREC(pval)                               ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x77, 0xC0, 6, pval)
#define VRX_ret_CP_PREC()                                   ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x77, 0xC0, 6)
#define VRX_set_CP_PREC(val)                                ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x77, 0xC0, 6, val)

#define VRX_get_A_OFFSET(pval)                              ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x77, 0x3F, 0xF0, 4, 2, pval)
#define VRX_ret_A_OFFSET()                                  ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x77, 0x3F, 0xF0, 4, 2)
#define VRX_set_A_OFFSET(val)                               ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x77, 0x3F, 0xF0, 4, 2, val)

#define VRX_get_B_OFFSET(pval)                              ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x78, 0xF, 0xFC, 2, 2, pval)
#define VRX_ret_B_OFFSET()                                  ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x78, 0xF, 0xFC, 2, 2)
#define VRX_set_B_OFFSET(val)                               ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x78, 0xF, 0xFC, 2, 2, val)

#define VRX_get_C_OFFSET(pval)                              ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x79, 0x3, 0xFF, 0, 2, pval)
#define VRX_ret_C_OFFSET()                                  ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x79, 0x3, 0xFF, 0, 2)
#define VRX_set_C_OFFSET(val)                               ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x79, 0x3, 0xFF, 0, 2, val)

#define VRX_is_AV_INV_F_true()                              ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x7B, 0x80, 0x7)
#define VRX_get_AV_INV_F(pval)                              ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x7B, 0x80, 0x7, pval)
#define VRX_ret_AV_INV_F()                                  ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x7B, 0x80, 0x7)
#define VRX_set_AV_INV_F(val)                               ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x7B, 0x80, 0x7, val)

#define VRX_is_AV_INV_V_true()                              ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x7B, 0x40, 0x6)
#define VRX_get_AV_INV_V(pval)                              ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x7B, 0x40, 0x6, pval)
#define VRX_ret_AV_INV_V()                                  ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x7B, 0x40, 0x6)
#define VRX_set_AV_INV_V(val)                               ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x7B, 0x40, 0x6, val)

#define VRX_is_AV_POS_SEL_true()                            ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x7B, 0x4, 0x2)
#define VRX_get_AV_POS_SEL(pval)                            ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x7B, 0x4, 0x2, pval)
#define VRX_ret_AV_POS_SEL()                                ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x7B, 0x4, 0x2)
#define VRX_set_AV_POS_SEL(val)                             ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x7B, 0x4, 0x2, val)

#define VRX_is_DE_WITH_AVCODE_true()                        ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x7B, 0x1, 0x0)
#define VRX_get_DE_WITH_AVCODE(pval)                        ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x7B, 0x1, 0x0, pval)
#define VRX_ret_DE_WITH_AVCODE()                            ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x7B, 0x1, 0x0)
#define VRX_set_DE_WITH_AVCODE(val)                         ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x7B, 0x1, 0x0, val)

#define VRX_is_CP_INV_HS_true()                             ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x7C, 0x80, 0x7)
#define VRX_get_CP_INV_HS(pval)                             ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x7C, 0x80, 0x7, pval)
#define VRX_ret_CP_INV_HS()                                 ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x7C, 0x80, 0x7)
#define VRX_set_CP_INV_HS(val)                              ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x7C, 0x80, 0x7, val)

#define VRX_is_CP_INV_VS_true()                             ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x7C, 0x40, 0x6)
#define VRX_get_CP_INV_VS(pval)                             ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x7C, 0x40, 0x6, pval)
#define VRX_ret_CP_INV_VS()                                 ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x7C, 0x40, 0x6)
#define VRX_set_CP_INV_VS(val)                              ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x7C, 0x40, 0x6, val)

#define VRX_is_CP_INV_DE_true()                             ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x7C, 0x10, 0x4)
#define VRX_get_CP_INV_DE(pval)                             ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x7C, 0x10, 0x4, pval)
#define VRX_ret_CP_INV_DE()                                 ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x7C, 0x10, 0x4)
#define VRX_set_CP_INV_DE(val)                              ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x7C, 0x10, 0x4, val)

#define VRX_get_START_HS(pval)                              
#define VRX_get_START_HS(pval)                              

#define VRX_set_START_HS(val)                               

#define VRX_get_END_HS(pval)                                ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x7C, 0x3, 0xFF, 0, 2, pval)
#define VRX_ret_END_HS()                                    ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x7C, 0x3, 0xFF, 0, 2)
#define VRX_set_END_HS(val)                                 ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x7C, 0x3, 0xFF, 0, 2, val)

#define VRX_get_START_VS(pval)                              ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x7F, 0xF0, 4, pval)
#define VRX_ret_START_VS()                                  ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x7F, 0xF0, 4)
#define VRX_set_START_VS(val)                               ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x7F, 0xF0, 4, val)

#define VRX_get_END_VS(pval)                                ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x7F, 0xF, 0, pval)
#define VRX_ret_END_VS()                                    ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x7F, 0xF, 0)
#define VRX_set_END_VS(val)                                 ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x7F, 0xF, 0, val)

#define VRX_get_START_FE(pval)                              ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x80, 0xF0, 4, pval)
#define VRX_ret_START_FE()                                  ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x80, 0xF0, 4)
#define VRX_set_START_FE(val)                               ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x80, 0xF0, 4, val)

#define VRX_get_START_FO(pval)                              ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x80, 0xF, 0, pval)
#define VRX_ret_START_FO()                                  ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x80, 0xF, 0)
#define VRX_set_START_FO(val)                               ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x80, 0xF, 0, val)

#define VRX_get_CP_GAIN_FILT(pval)                          ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x84, 0xF0, 4, pval)
#define VRX_ret_CP_GAIN_FILT()                              ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x84, 0xF0, 4)
#define VRX_set_CP_GAIN_FILT(val)                           ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x84, 0xF0, 4, val)

#define VRX_is_CH1_TRIG_STDI_true()                         ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x86, 0x4, 0x2)
#define VRX_get_CH1_TRIG_STDI(pval)                         ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x86, 0x4, 0x2, pval)
#define VRX_ret_CH1_TRIG_STDI()                             ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x86, 0x4, 0x2)
#define VRX_set_CH1_TRIG_STDI(val)                          ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x86, 0x4, 0x2, val)

#define VRX_is_CH1_STDI_CONT_true()                         ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x86, 0x2, 0x1)
#define VRX_get_CH1_STDI_CONT(pval)                         ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x86, 0x2, 0x1, pval)
#define VRX_ret_CH1_STDI_CONT()                             ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x86, 0x2, 0x1)
#define VRX_set_CH1_STDI_CONT(val)                          ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x86, 0x2, 0x1, val)

#define VRX_get_DE_V_START_EVEN(pval)                       ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x88, 0xF0, 4, pval)
#define VRX_ret_DE_V_START_EVEN()                           ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x88, 0xF0, 4)
#define VRX_set_DE_V_START_EVEN(val)                        ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x88, 0xF0, 4, val)

#define VRX_get_DE_V_END_EVEN(pval)                         ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x88, 0xF, 0, pval)
#define VRX_ret_DE_V_END_EVEN()                             ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x88, 0xF, 0)
#define VRX_set_DE_V_END_EVEN(val)                          ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x88, 0xF, 0, val)

#define VRX_get_START_VS_EVEN(pval)                         ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x89, 0xF0, 4, pval)
#define VRX_ret_START_VS_EVEN()                             ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x89, 0xF0, 4)
#define VRX_set_START_VS_EVEN(val)                          ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x89, 0xF0, 4, val)

#define VRX_get_END_VS_EVEN(pval)                           ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x89, 0xF, 0, pval)
#define VRX_ret_END_VS_EVEN()                               ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x89, 0xF, 0)
#define VRX_set_END_VS_EVEN(val)                            ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x89, 0xF, 0, val)

#define VRX_get_DE_H_START(pval)                            
#define VRX_get_DE_H_START(pval)                            

#define VRX_set_DE_H_START(val)                             

#define VRX_get_DE_H_END(pval)                              ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x8B, 0x3, 0xFF, 0, 2, pval)
#define VRX_ret_DE_H_END()                                  ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x8B, 0x3, 0xFF, 0, 2)
#define VRX_set_DE_H_END(val)                               ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x8B, 0x3, 0xFF, 0, 2, val)

#define VRX_get_DE_V_START(pval)                            ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x8E, 0xF0, 4, pval)
#define VRX_ret_DE_V_START()                                ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x8E, 0xF0, 4)
#define VRX_set_DE_V_START(val)                             ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x8E, 0xF0, 4, val)

#define VRX_get_DE_V_END(pval)                              ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x8E, 0xF, 0, pval)
#define VRX_ret_DE_V_END()                                  ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x8E, 0xF, 0)
#define VRX_set_DE_V_END(val)                               ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x8E, 0xF, 0, val)

#define VRX_get_CH1_FR_LL(pval)                             ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0x8F, 0x7, 0xFF, 0, 2, pval)
#define VRX_ret_CH1_FR_LL()                                 ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0x8F, 0x7, 0xFF, 0, 2)
#define VRX_set_CH1_FR_LL(val)                              ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0x8F, 0x7, 0xFF, 0, 2, val)

#define VRX_is_INTERLACED_true()                            ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0x91, 0x40, 0x6)
#define VRX_get_INTERLACED(pval)                            ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0x91, 0x40, 0x6, pval)
#define VRX_ret_INTERLACED()                                ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0x91, 0x40, 0x6)
#define VRX_set_INTERLACED(val)                             ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0x91, 0x40, 0x6, val)

#define VRX_get_CH1_LCF(pval)                               ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0xA3, 0xF, 0xFF, 0, 2, pval)
#define VRX_ret_CH1_LCF()                                   ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0xA3, 0xF, 0xFF, 0, 2)

#define VRX_get_CP_LCOUNT_MAX(pval)                         ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0xAB, 0xFF, 0xF0, 4, 2, pval)
#define VRX_ret_CP_LCOUNT_MAX()                             ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0xAB, 0xFF, 0xF0, 4, 2)
#define VRX_set_CP_LCOUNT_MAX(val)                          ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0xAB, 0xFF, 0xF0, 4, 2, val)

#define VRX_is_CH1_STDI_DVALID_true()                       ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xB1, 0x80, 0x7)
#define VRX_get_CH1_STDI_DVALID(pval)                       ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xB1, 0x80, 0x7, pval)
#define VRX_ret_CH1_STDI_DVALID()                           ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xB1, 0x80, 0x7)

#define VRX_is_CH1_STDI_INTLCD_true()                       ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xB1, 0x40, 0x6)
#define VRX_get_CH1_STDI_INTLCD(pval)                       ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xB1, 0x40, 0x6, pval)
#define VRX_ret_CH1_STDI_INTLCD()                           ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xB1, 0x40, 0x6)

#define VRX_get_CH1_BL(pval)                                ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0xB1, 0x3F, 0xFF, 0, 2, pval)
#define VRX_ret_CH1_BL()                                    ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0xB1, 0x3F, 0xFF, 0, 2)

#define VRX_get_CH1_LCVS(pval)                              ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xB3, 0xF8, 3, pval)
#define VRX_ret_CH1_LCVS()                                  ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xB3, 0xF8, 3)

#define VRX_get_CH1_FCL(pval)                               ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0xB8, 0x1F, 0xFF, 0, 2, pval)
#define VRX_ret_CH1_FCL()                                   ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0xB8, 0x1F, 0xFF, 0, 2)

#define VRX_is_HDMI_FRUN_MODE_true()                        ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xBA, 0x2, 0x1)
#define VRX_get_HDMI_FRUN_MODE(pval)                        ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xBA, 0x2, 0x1, pval)
#define VRX_ret_HDMI_FRUN_MODE()                            ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xBA, 0x2, 0x1)
#define VRX_set_HDMI_FRUN_MODE(val)                         ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xBA, 0x2, 0x1, val)

#define VRX_is_HDMI_FRUN_EN_true()                          ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xBA, 0x1, 0x0)
#define VRX_get_HDMI_FRUN_EN(pval)                          ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xBA, 0x1, 0x0, pval)
#define VRX_ret_HDMI_FRUN_EN()                              ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xBA, 0x1, 0x0)
#define VRX_set_HDMI_FRUN_EN(val)                           ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xBA, 0x1, 0x0, val)

#define VRX_is_DPP_BYPASS_EN_true()                         ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xBD, 0x10, 0x4)
#define VRX_get_DPP_BYPASS_EN(pval)                         ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xBD, 0x10, 0x4, pval)
#define VRX_ret_DPP_BYPASS_EN()                             ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xBD, 0x10, 0x4)
#define VRX_set_DPP_BYPASS_EN(val)                          ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xBD, 0x10, 0x4, val)

#define VRX_is_DLY_A_true()                                 ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xBE, 0x80, 0x7)
#define VRX_get_DLY_A(pval)                                 ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xBE, 0x80, 0x7, pval)
#define VRX_ret_DLY_A()                                     ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xBE, 0x80, 0x7)
#define VRX_set_DLY_A(val)                                  ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xBE, 0x80, 0x7, val)

#define VRX_is_DLY_B_true()                                 ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xBE, 0x40, 0x6)
#define VRX_get_DLY_B(pval)                                 ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xBE, 0x40, 0x6, pval)
#define VRX_ret_DLY_B()                                     ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xBE, 0x40, 0x6)
#define VRX_set_DLY_B(val)                                  ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xBE, 0x40, 0x6, val)

#define VRX_is_DLY_C_true()                                 ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xBE, 0x20, 0x5)
#define VRX_get_DLY_C(pval)                                 ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xBE, 0x20, 0x5, pval)
#define VRX_ret_DLY_C()                                     ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xBE, 0x20, 0x5)
#define VRX_set_DLY_C(val)                                  ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xBE, 0x20, 0x5, val)

#define VRX_get_HCOUNT_ALIGN_ADJ(pval)                      ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0xBE, 0x3, 0xE0, 5, 2, pval)
#define VRX_ret_HCOUNT_ALIGN_ADJ()                          ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0xBE, 0x3, 0xE0, 5, 2)
#define VRX_set_HCOUNT_ALIGN_ADJ(val)                       ATV_I2CWriteField32(VRX_CP_MAP_ADDR, 0xBE, 0x3, 0xE0, 5, 2, val)

#define VRX_is_CP_DEF_COL_MAN_VAL_true()                    ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xBF, 0x4, 0x2)
#define VRX_get_CP_DEF_COL_MAN_VAL(pval)                    ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xBF, 0x4, 0x2, pval)
#define VRX_ret_CP_DEF_COL_MAN_VAL()                        ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xBF, 0x4, 0x2)
#define VRX_set_CP_DEF_COL_MAN_VAL(val)                     ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xBF, 0x4, 0x2, val)

#define VRX_is_CP_DEF_COL_AUTO_true()                       ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xBF, 0x2, 0x1)
#define VRX_get_CP_DEF_COL_AUTO(pval)                       ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xBF, 0x2, 0x1, pval)
#define VRX_ret_CP_DEF_COL_AUTO()                           ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xBF, 0x2, 0x1)
#define VRX_set_CP_DEF_COL_AUTO(val)                        ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xBF, 0x2, 0x1, val)

#define VRX_is_CP_FORCE_FREERUN_true()                      ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xBF, 0x1, 0x0)
#define VRX_get_CP_FORCE_FREERUN(pval)                      ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xBF, 0x1, 0x0, pval)
#define VRX_ret_CP_FORCE_FREERUN()                          ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xBF, 0x1, 0x0)
#define VRX_set_CP_FORCE_FREERUN(val)                       ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xBF, 0x1, 0x0, val)

#define VRX_get_DEF_COL_CHA(pval)                           ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xC0, 0xFF, 0, pval)
#define VRX_ret_DEF_COL_CHA()                               ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xC0, 0xFF, 0)
#define VRX_set_DEF_COL_CHA(val)                            ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xC0, 0xFF, 0, val)

#define VRX_get_DEF_COL_CHB(pval)                           ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xC1, 0xFF, 0, pval)
#define VRX_ret_DEF_COL_CHB()                               ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xC1, 0xFF, 0)
#define VRX_set_DEF_COL_CHB(val)                            ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xC1, 0xFF, 0, val)

#define VRX_get_DEF_COL_CHC(pval)                           ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xC2, 0xFF, 0, pval)
#define VRX_ret_DEF_COL_CHC()                               ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xC2, 0xFF, 0)
#define VRX_set_DEF_COL_CHC(val)                            ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xC2, 0xFF, 0, val)

#define VRX_is_SWAP_SPLIT_AV_true()                         ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xC9, 0x4, 0x2)
#define VRX_get_SWAP_SPLIT_AV(pval)                         ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xC9, 0x4, 0x2, pval)
#define VRX_ret_SWAP_SPLIT_AV()                             ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xC9, 0x4, 0x2)
#define VRX_set_SWAP_SPLIT_AV(val)                          ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xC9, 0x4, 0x2, val)

#define VRX_is_DIS_AUTO_PARAM_BUFF_true()                   ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xC9, 0x1, 0x0)
#define VRX_get_DIS_AUTO_PARAM_BUFF(pval)                   ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xC9, 0x1, 0x0, pval)
#define VRX_ret_DIS_AUTO_PARAM_BUFF()                       ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xC9, 0x1, 0x0)
#define VRX_set_DIS_AUTO_PARAM_BUFF(val)                    ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xC9, 0x1, 0x0, val)

#define VRX_get_HDMI_CP_LOCK_THRESHOLD(pval)                ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xCB, 0x3, 0, pval)
#define VRX_ret_HDMI_CP_LOCK_THRESHOLD()                    ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xCB, 0x3, 0)
#define VRX_set_HDMI_CP_LOCK_THRESHOLD(val)                 ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xCB, 0x3, 0, val)

#define VRX_is_HDMI_CP_AUTOPARM_LOCKED_true()               ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xE0, 0x40, 0x6)
#define VRX_get_HDMI_CP_AUTOPARM_LOCKED(pval)               ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xE0, 0x40, 0x6, pval)
#define VRX_ret_HDMI_CP_AUTOPARM_LOCKED()                   ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xE0, 0x40, 0x6)

#define VRX_get_HDMI_AUTOPARM_STS(pval)                     ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xE0, 0x30, 4, pval)
#define VRX_ret_HDMI_AUTOPARM_STS()                         ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xE0, 0x30, 4)

#define VRX_get_HSD_FB(pval)                                ATV_I2CGetField32(VRX_CP_MAP_ADDR, 0xEB, 0xF, 0xFF, 0, 2, pval)
#define VRX_ret_HSD_FB()                                    ATV_I2CReadField32(VRX_CP_MAP_ADDR, 0xEB, 0xF, 0xFF, 0, 2)

#define VRX_is_CRC_ENABLE_true()                            ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xF2, 0x4, 0x2)
#define VRX_get_CRC_ENABLE(pval)                            ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xF2, 0x4, 0x2, pval)
#define VRX_ret_CRC_ENABLE()                                ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xF2, 0x4, 0x2)
#define VRX_set_CRC_ENABLE(val)                             ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xF2, 0x4, 0x2, val)

#define VRX_get_CH1_FL_FR_THRESHOLD(pval)                   ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xF3, 0x38, 3, pval)
#define VRX_ret_CH1_FL_FR_THRESHOLD()                       ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xF3, 0x38, 3)
#define VRX_set_CH1_FL_FR_THRESHOLD(val)                    ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xF3, 0x38, 3, val)

#define VRX_get_CH1_F_RUN_THR(pval)                         ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xF3, 0x7, 0, pval)
#define VRX_ret_CH1_F_RUN_THR()                             ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xF3, 0x7, 0)
#define VRX_set_CH1_F_RUN_THR(val)                          ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xF3, 0x7, 0, val)

#define VRX_get_CSC_COEFF_SEL_RB(pval)                      ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xF4, 0xF0, 4, pval)
#define VRX_ret_CSC_COEFF_SEL_RB()                          ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xF4, 0xF0, 4)

#define VRX_is_BYPASS_STDI1_LOCKING_true()                  ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xF5, 0x2, 0x1)
#define VRX_get_BYPASS_STDI1_LOCKING(pval)                  ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xF5, 0x2, 0x1, pval)
#define VRX_ret_BYPASS_STDI1_LOCKING()                      ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xF5, 0x2, 0x1)
#define VRX_set_BYPASS_STDI1_LOCKING(val)                   ATV_I2CWriteField8(VRX_CP_MAP_ADDR, 0xF5, 0x2, 0x1, val)

#define VRX_is_CP_FREE_RUN_true()                           ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xFF, 0x10, 0x4)
#define VRX_get_CP_FREE_RUN(pval)                           ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xFF, 0x10, 0x4, pval)
#define VRX_ret_CP_FREE_RUN()                               ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xFF, 0x10, 0x4)

#endif
