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


#ifndef ADV7612_REPEATER_MAP_ADR_H
#define ADV7612_REPEATER_MAP_ADR_H

#define VRX_REG_BKSV_1                                      0x00

#define VRX_REG_BKSV_2                                      0x01

#define VRX_REG_BKSV_3                                      0x02

#define VRX_REG_BKSV_4                                      0x03

#define VRX_REG_BKSV_5                                      0x04

#define VRX_REG_RI_1                                        0x08

#define VRX_REG_RI_2                                        0x09

#define VRX_REG_PJ                                          0x0A

#define VRX_REG_AKSV_1                                      0x10

#define VRX_REG_AKSV_2                                      0x11

#define VRX_REG_AKSV_3                                      0x12

#define VRX_REG_AKSV_4                                      0x13

#define VRX_REG_AKSV_5                                      0x14

#define VRX_REG_AINFO                                       0x15

#define VRX_REG_AN_1                                        0x18

#define VRX_REG_AN_2                                        0x19

#define VRX_REG_AN_3                                        0x1A

#define VRX_REG_AN_4                                        0x1B

#define VRX_REG_AN_5                                        0x1C

#define VRX_REG_AN_6                                        0x1D

#define VRX_REG_AN_7                                        0x1E

#define VRX_REG_AN_8                                        0x1F

#define VRX_REG_SHA_A_1                                     0x20

#define VRX_REG_SHA_A_2                                     0x21

#define VRX_REG_SHA_A_3                                     0x22

#define VRX_REG_SHA_A_4                                     0x23

#define VRX_REG_SHA_B_1                                     0x24

#define VRX_REG_SHA_B_2                                     0x25

#define VRX_REG_SHA_B_3                                     0x26

#define VRX_REG_SHA_B_4                                     0x27

#define VRX_REG_BCAPS                                       0x40

#define VRX_REG_BSTATUS_1                                   0x41

#define VRX_REG_BSTATUS_2                                   0x42

#define VRX_REG_SPA_PORT_B_1                                0x52

#define VRX_REG_SPA_PORT_B_2                                0x53

#define VRX_REG_PORT_B_CHECKSUM                             0x61

#define VRX_REG_SPA_LOCATION                                0x70

#define VRX_BIT_KSV_LIST_READY                              0x80
#define VRX_BIT_SPA_STORAGE_MODE                            0x02
#define VRX_BIT_SPA_LOCATION_MSB                            0x01

#define VRX_REG_HDCP_EDID_CONTROLS                          0x74
#define VRX_BIT_EDID_B_ENABLE                               0x02
#define VRX_BIT_EDID_A_ENABLE                               0x01

#define VRX_REG_EDID_DEBUG_2                                0x76
#define VRX_BIT_EDID_B_ENABLE_CPU                           0x02
#define VRX_BIT_EDID_A_ENABLE_CPU                           0x01

#define VRX_REG_EDID_DEBUG                                  VRX_REG_EDID_DEBUG_2
#define VRX_REG_EDID_DEBUG_3                                0x78

#define VRX_BIT_AUTO_HDCP_MAP_ENABLE                        0x08

#define VRX_BIT_DISABLE_AUTO_EDID                           0x02
#define VRX_BIT_EDID_SEGMENT_POINTER                        0x01

#define VRX_REG_KSV_0_1                                     0x80

#define VRX_REG_KSV_0_2                                     0x81

#define VRX_REG_KSV_0_3                                     0x82

#define VRX_REG_KSV_0_4                                     0x83

#define VRX_REG_KSV_0_5                                     0x84

#define VRX_REG_KSV_0_6                                     0x85

#define VRX_REG_KSV_0_7                                     0x86

#define VRX_REG_KSV_0_8                                     0x87

#define VRX_REG_KSV_0_9                                     0x88

#define VRX_REG_KSV_0_10                                    0x89

#define VRX_REG_KSV_0_11                                    0x8A

#define VRX_REG_KSV_0_12                                    0x8B

#define VRX_REG_KSV_0_13                                    0x8C

#define VRX_REG_KSV_0_14                                    0x8D

#define VRX_REG_KSV_0_15                                    0x8E

#define VRX_REG_KSV_0_16                                    0x8F

#define VRX_REG_KSV_0_17                                    0x90

#define VRX_REG_KSV_0_18                                    0x91

#define VRX_REG_KSV_0_19                                    0x92

#define VRX_REG_KSV_0_20                                    0x93

#define VRX_REG_KSV_0_21                                    0x94

#define VRX_REG_KSV_0_22                                    0x95

#define VRX_REG_KSV_0_23                                    0x96

#define VRX_REG_KSV_0_24                                    0x97

#define VRX_REG_KSV_0_25                                    0x98

#define VRX_REG_KSV_0_26                                    0x99

#define VRX_REG_KSV_0_27                                    0x9A

#define VRX_REG_KSV_0_28                                    0x9B

#define VRX_REG_KSV_0_29                                    0x9C

#define VRX_REG_KSV_0_30                                    0x9D

#define VRX_REG_KSV_0_31                                    0x9E

#define VRX_REG_KSV_0_32                                    0x9F

#define VRX_REG_KSV_0_33                                    0xA0

#define VRX_REG_KSV_0_34                                    0xA1

#define VRX_REG_KSV_0_35                                    0xA2

#define VRX_REG_KSV_0_36                                    0xA3

#define VRX_REG_KSV_0_37                                    0xA4

#define VRX_REG_KSV_0_38                                    0xA5

#define VRX_REG_KSV_0_39                                    0xA6

#define VRX_REG_KSV_0_40                                    0xA7

#define VRX_REG_KSV_0_41                                    0xA8

#define VRX_REG_KSV_0_42                                    0xA9

#define VRX_REG_KSV_0_43                                    0xAA

#define VRX_REG_KSV_0_44                                    0xAB

#define VRX_REG_KSV_0_45                                    0xAC

#define VRX_REG_KSV_0_46                                    0xAD

#define VRX_REG_KSV_0_47                                    0xAE

#define VRX_REG_KSV_0_48                                    0xAF

#define VRX_REG_KSV_0_49                                    0xB0

#define VRX_REG_KSV_0_50                                    0xB1

#define VRX_REG_KSV_0_51                                    0xB2

#define VRX_REG_KSV_0_52                                    0xB3

#define VRX_REG_KSV_0_53                                    0xB4

#define VRX_REG_KSV_0_54                                    0xB5

#define VRX_REG_KSV_0_55                                    0xB6

#define VRX_REG_KSV_0_56                                    0xB7

#define VRX_REG_KSV_0_57                                    0xB8

#define VRX_REG_KSV_0_58                                    0xB9

#define VRX_REG_KSV_0_59                                    0xBA

#define VRX_REG_KSV_0_60                                    0xBB

#define VRX_REG_KSV_0_61                                    0xBC

#define VRX_REG_KSV_0_62                                    0xBD

#define VRX_REG_KSV_0_63                                    0xBE

#define VRX_REG_KSV_0_64                                    0xBF

#define VRX_REG_KSV_0_65                                    0xC0

#define VRX_REG_KSV_0_66                                    0xC1

#define VRX_REG_KSV_0_67                                    0xC2

#define VRX_REG_KSV_0_68                                    0xC3

#define VRX_REG_KSV_0_69                                    0xC4

#define VRX_REG_KSV_0_70                                    0xC5

#define VRX_REG_KSV_0_71                                    0xC6

#define VRX_REG_KSV_0_72                                    0xC7

#define VRX_REG_KSV_0_73                                    0xC8

#define VRX_REG_KSV_0_74                                    0xC9

#define VRX_REG_KSV_0_75                                    0xCA

#define VRX_REG_KSV_0_76                                    0xCB

#define VRX_REG_KSV_0_77                                    0xCC

#define VRX_REG_KSV_0_78                                    0xCD

#define VRX_REG_KSV_0_79                                    0xCE

#define VRX_REG_KSV_0_80                                    0xCF

#define VRX_REG_KSV_0_81                                    0xD0

#define VRX_REG_KSV_0_82                                    0xD1

#define VRX_REG_KSV_0_83                                    0xD2

#define VRX_REG_KSV_0_84                                    0xD3

#define VRX_REG_KSV_0_85                                    0xD4

#define VRX_REG_KSV_0_86                                    0xD5

#define VRX_REG_KSV_0_87                                    0xD6

#define VRX_REG_KSV_0_88                                    0xD7

#define VRX_REG_KSV_0_89                                    0xD8

#define VRX_REG_KSV_0_90                                    0xD9

#define VRX_REG_KSV_0_91                                    0xDA

#define VRX_REG_KSV_0_92                                    0xDB

#define VRX_REG_KSV_0_93                                    0xDC

#define VRX_REG_KSV_0_94                                    0xDD

#define VRX_REG_KSV_0_95                                    0xDE

#define VRX_REG_KSV_0_96                                    0xDF

#define VRX_REG_KSV_0_97                                    0xE0

#define VRX_REG_KSV_0_98                                    0xE1

#define VRX_REG_KSV_0_99                                    0xE2

#define VRX_REG_KSV_0_100                                   0xE3

#define VRX_REG_KSV_0_101                                   0xE4

#define VRX_REG_KSV_0_102                                   0xE5

#define VRX_REG_KSV_0_103                                   0xE6

#define VRX_REG_KSV_0_104                                   0xE7

#define VRX_REG_KSV_0_105                                   0xE8

#define VRX_REG_KSV_0_106                                   0xE9

#define VRX_REG_KSV_0_107                                   0xEA

#define VRX_REG_KSV_0_108                                   0xEB

#define VRX_REG_KSV_0_109                                   0xEC

#define VRX_REG_KSV_0_110                                   0xED

#define VRX_REG_KSV_0_111                                   0xEE

#define VRX_REG_KSV_0_112                                   0xEF

#define VRX_REG_KSV_0_113                                   0xF0

#define VRX_REG_KSV_0_114                                   0xF1

#define VRX_REG_KSV_0_115                                   0xF2

#define VRX_REG_KSV_0_116                                   0xF3

#define VRX_REG_KSV_0_117                                   0xF4

#define VRX_REG_KSV_0_118                                   0xF5

#define VRX_REG_KSV_0_119                                   0xF6

#define VRX_REG_KSV_0_120                                   0xF7

#define VRX_REG_KSV_0_121                                   0xF8

#define VRX_REG_KSV_0_122                                   0xF9

#define VRX_REG_KSV_0_123                                   0xFA

#define VRX_REG_KSV_0_124                                   0xFB

#define VRX_REG_KSV_0_125                                   0xFC

#define VRX_REG_KSV_0_126                                   0xFD

#define VRX_REG_KSV_0_127                                   0xFE

#define VRX_REG_KSV_0_128                                   0xFF


#endif
