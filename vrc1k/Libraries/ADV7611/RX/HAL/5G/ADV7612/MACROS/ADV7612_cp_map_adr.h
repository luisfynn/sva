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


#ifndef ADV7612_CP_MAP_ADR_H
#define ADV7612_CP_MAP_ADR_H

#define VRX_REG_DE_POS_ADJ_1                                0x30

#define VRX_REG_DE_POS_ADJ_2                                0x31

#define VRX_REG_BIT_REDUCTION_DITHER                        0x36
#define VRX_BIT_TEN_TO_EIGHT_CONV                           0x01

#define VRX_REG_CONTRAST_CNTRL                              0x3A

#define VRX_REG_SATURATION_CNTRL                            0x3B

#define VRX_REG_BRIGHTNESS_CNTRL                            0x3C

#define VRX_REG_HUE_CNTRL                                   0x3D

#define VRX_BIT_VID_ADJ_EN                                  0x80
#define VRX_BIT_CP_UV_DVAL_INV                              0x08
#define VRX_BIT_CP_MODE_GAIN_ADJ_EN                         0x04
#define VRX_BIT_ALT_SAT_UV_MAN                              0x02
#define VRX_BIT_ALT_SAT_UV                                  0x01

#define VRX_REG_CP_PRE_GAIN_CNTRL                           0x40

#define VRX_REG_CSC_COEFFS_1                                0x52

#define VRX_REG_CSC_COEFFS_2                                0x53

#define VRX_REG_CSC_COEFFS_3                                0x54

#define VRX_REG_CSC_COEFFS_4                                0x55

#define VRX_REG_CSC_COEFFS_5                                0x56

#define VRX_REG_CSC_COEFFS_6                                0x57

#define VRX_REG_CSC_COEFFS_7                                0x58

#define VRX_REG_CSC_COEFFS_8                                0x59

#define VRX_REG_CSC_COEFFS_9                                0x5A

#define VRX_REG_CSC_COEFFS_10                               0x5B

#define VRX_REG_CSC_COEFFS_11                               0x5C

#define VRX_REG_CSC_COEFFS_12                               0x5D

#define VRX_REG_CSC_COEFFS_13                               0x5E

#define VRX_REG_CSC_COEFFS_14                               0x5F

#define VRX_REG_CSC_COEFFS_15                               0x60

#define VRX_REG_CSC_COEFFS_16                               0x61

#define VRX_REG_CSC_COEFFS_17                               0x62

#define VRX_REG_CSC_COEFFS_18                               0x63

#define VRX_REG_CSC_COEFFS_19                               0x64

#define VRX_REG_CSC_COEFFS_20                               0x65

#define VRX_REG_CSC_COEFFS_21                               0x66

#define VRX_REG_CSC_DECIM_CNTRL                             0x68

#define VRX_BIT_MAN_CP_CSC_EN                               0x10
#define VRX_BIT_EIA_861_COMPLIANCE                          0x04

#define VRX_REG_CLMP_CNTRL_1                                0x6C
#define VRX_BIT_CLMP_A_MAN                                  0x80
#define VRX_BIT_CLMP_BC_MAN                                 0x40
#define VRX_BIT_CLMP_FREEZE                                 0x20

#define VRX_REG_CLMP_CNTRL_2                                0x6D

#define VRX_REG_CLMP_CNTRL_3                                0x6E

#define VRX_REG_CLMP_CNTRL_4                                0x6F

#define VRX_REG_CLMP_CNTRL_5                                0x70

#define VRX_REG_GAIN_CNTRL_3                                0x73
#define VRX_BIT_GAIN_MAN                                    0x80
#define VRX_BIT_AGC_MODE_MAN                                0x40

#define VRX_REG_GAIN_CNTRL_4                                0x74

#define VRX_REG_GAIN_CNTRL_5                                0x75

#define VRX_REG_GAIN_CNTRL_6                                0x76

#define VRX_REG_OFFSET_CNTRL_1                              0x77

#define VRX_REG_OFFSET_CNTRL_2                              0x78

#define VRX_REG_OFFSET_CNTRL_3                              0x79

#define VRX_REG_OFFSET_CNTRL_4                              0x7A

#define VRX_REG_AVCODE_CNTRL                                0x7B
#define VRX_BIT_AV_INV_F                                    0x80
#define VRX_BIT_AV_INV_V                                    0x40
#define VRX_BIT_AV_POS_SEL                                  0x04
#define VRX_BIT_DE_WITH_AVCODE                              0x01

#define VRX_REG_SYNC_CNTRL_1                                0x7C
#define VRX_BIT_CP_INV_HS                                   0x80
#define VRX_BIT_CP_INV_VS                                   0x40
#define VRX_BIT_CP_INV_DE                                   0x10

#define VRX_REG_SYNC_CNTRL_2                                0x7D

#define VRX_REG_SYNC_CNTRL_3                                0x7E

#define VRX_REG_SYNC_CNTRL_4                                0x7F

#define VRX_REG_SYNC_CNTRL_5                                0x80

#define VRX_REG_SYNC_DET_CNTRL_CH1_1                        0x84

#define VRX_REG_SYNC_DET_CNTRL_CH1_3                        0x86
#define VRX_BIT_CH1_TRIG_STDI                               0x04
#define VRX_BIT_CH1_STDI_CONT                               0x02

#define VRX_REG_DE_POS_ADJ_3                                0x88

#define VRX_REG_SYNC_CNTRL_6                                0x89

#define VRX_REG_DE_POS_ADJ_4                                0x8B

#define VRX_REG_DE_POS_ADJ_5                                0x8C

#define VRX_REG_DE_POS_ADJ_6                                0x8D

#define VRX_REG_DE_POS_ADJ_7                                0x8E

#define VRX_REG_SYNC_DET_CNTRL_CH1_4_1                      0x8F

#define VRX_REG_SYNC_DET_CNTRL_CH1_4_2                      0x90

#define VRX_BIT_INTERLACED                                  0x40

#define VRX_REG_SYNC_DET_CNTRL_CH1_RB_1                     0xA3

#define VRX_REG_SYNC_DET_CNTRL_CH1_RB_2                     0xA4

#define VRX_REG_SYNC_DET_CNTRL_CH1_4                        0xAB

#define VRX_REG_SYNC_DET_CNTRL_CH1_5                        0xAC

#define VRX_REG_SYNC_DET_CNTRL_CH1_RB_3                     0xB1
#define VRX_BIT_CH1_STDI_DVALID                             0x80
#define VRX_BIT_CH1_STDI_INTLCD                             0x40

#define VRX_REG_SYNC_DET_CNTRL_CH1_RB_4                     0xB2

#define VRX_REG_SYNC_DET_CNTRL_CH1_RB_5                     0xB3

#define VRX_REG_SYNC_DET_CNTRL_CH1_RB_6_1                   0xB8

#define VRX_REG_SYNC_DET_CNTRL_CH1_RB_6_2                   0xB9

#define VRX_REG_HDMI_CP_CNTRL_1                             0xBA
#define VRX_BIT_HDMI_FRUN_MODE                              0x02
#define VRX_BIT_HDMI_FRUN_EN                                0x01

#define VRX_REG_COAST_CNTRL_1                               0xBD
#define VRX_BIT_DPP_BYPASS_EN                               0x10

#define VRX_BIT_DLY_A                                       0x80
#define VRX_BIT_DLY_B                                       0x40
#define VRX_BIT_DLY_C                                       0x20

#define VRX_REG_FR_COLOR_SEL_1                              0xBF
#define VRX_BIT_CP_DEF_COL_MAN_VAL                          0x04
#define VRX_BIT_CP_DEF_COL_AUTO                             0x02
#define VRX_BIT_CP_FORCE_FREERUN                            0x01

#define VRX_REG_FR_COLOR_SEL_2                              0xC0

#define VRX_REG_FR_COLOR_SEL_3                              0xC1

#define VRX_REG_FR_COLOR_SEL_4                              0xC2

#define VRX_REG_CLMP_POS_CNTRL_4                            0xC9
#define VRX_BIT_SWAP_SPLIT_AV                               0x04
#define VRX_BIT_DIS_AUTO_PARAM_BUFF                         0x01

#define VRX_REG_HDMI_CP_CNTRL_2                             0xCB

#define VRX_BIT_HDMI_CP_AUTOPARM_LOCKED                     0x40

#define VRX_REG_HSYNC_DEPTH_RB_5                            0xEB

#define VRX_REG_HSYNC_DEPTH_RB_6                            0xEC

#define VRX_REG_CP_REG_F2                                   0xF2
#define VRX_BIT_CRC_ENABLE                                  0x04

#define VRX_REG_SYNC_DET_CNTRL_CH1_6                        0xF3

#define VRX_REG_CSC_COEFF_SEL_RB                            0xF4

#define VRX_BIT_BYPASS_STDI1_LOCKING                        0x02

#define VRX_REG_CP_REG_FF                                   0xFF
#define VRX_BIT_CP_FREE_RUN                                 0x10


#endif
