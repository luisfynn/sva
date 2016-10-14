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
* DATE: 10 Aug 2010 11:2:29                                                    *
*                                                                              *
*******************************************************************************/


#ifndef ADV7612_IO_MAP_DEF_H
#define ADV7612_IO_MAP_DEF_H

#define VRX_FIELD_VID_STD_DEF                               0x8
#define VRX_FIELD_VID_STD_BIT_SIZE                          6

#define VRX_FIELD_V_FREQ_DEF                                0x0
#define VRX_FIELD_V_FREQ_BIT_SIZE                           3

#define VRX_FIELD_PRIM_MODE_DEF                             0x6
#define VRX_FIELD_PRIM_MODE_BIT_SIZE                        4

#define VRX_REG_IO_02H_DEF                                  0xF0
#define VRX_FIELD_INP_COLOR_SPACE_DEF                       0xf
#define VRX_FIELD_INP_COLOR_SPACE_BIT_SIZE                  4

#define VRX_FIELD_ALT_GAMMA_DEF                             0x0
#define VRX_FIELD_ALT_GAMMA_BIT_SIZE                        1

#define VRX_FIELD_OP_656_RANGE_DEF                          0x0
#define VRX_FIELD_OP_656_RANGE_BIT_SIZE                     1

#define VRX_FIELD_RGB_OUT_DEF                               0x0
#define VRX_FIELD_RGB_OUT_BIT_SIZE                          1

#define VRX_FIELD_ALT_DATA_SAT_DEF                          0x0
#define VRX_FIELD_ALT_DATA_SAT_BIT_SIZE                     1

#define VRX_REG_IO_03H_DEF                                  0x00
#define VRX_FIELD_OP_FORMAT_SEL_DEF                         0x0
#define VRX_FIELD_OP_FORMAT_SEL_BIT_SIZE                    8

#define VRX_REG_IO_04H_DEF                                  0x62
#define VRX_FIELD_OP_CH_SEL_DEF                             0x3
#define VRX_FIELD_OP_CH_SEL_BIT_SIZE                        3

#define VRX_FIELD_XTAL_FREQ_SEL_DEF                         0x1
#define VRX_FIELD_XTAL_FREQ_SEL_BIT_SIZE                    2

#define VRX_REG_IO_05H_DEF                                  0x2C
#define VRX_FIELD_F_OUT_SEL_DEF                             0x0
#define VRX_FIELD_F_OUT_SEL_BIT_SIZE                        1

#define VRX_FIELD_DATA_BLANK_EN_DEF                         0x1
#define VRX_FIELD_DATA_BLANK_EN_BIT_SIZE                    1

#define VRX_FIELD_AVCODE_INSERT_EN_DEF                      0x1
#define VRX_FIELD_AVCODE_INSERT_EN_BIT_SIZE                 1

#define VRX_FIELD_REPL_AV_CODE_DEF                          0x0
#define VRX_FIELD_REPL_AV_CODE_BIT_SIZE                     1

#define VRX_FIELD_OP_SWAP_CB_CR_DEF                         0x0
#define VRX_FIELD_OP_SWAP_CB_CR_BIT_SIZE                    1

#define VRX_REG_IO_06H_DEF                                  0xA0
#define VRX_FIELD_VS_OUT_SEL_DEF                            0x1
#define VRX_FIELD_VS_OUT_SEL_BIT_SIZE                       1

#define VRX_FIELD_INV_F_POL_DEF                             0x0
#define VRX_FIELD_INV_F_POL_BIT_SIZE                        1

#define VRX_FIELD_INV_VS_POL_DEF                            0x0
#define VRX_FIELD_INV_VS_POL_BIT_SIZE                       1

#define VRX_FIELD_INV_HS_POL_DEF                            0x0
#define VRX_FIELD_INV_HS_POL_BIT_SIZE                       1

#define VRX_FIELD_INV_LLC_POL_DEF                           0x0
#define VRX_FIELD_INV_LLC_POL_BIT_SIZE                      1

#define VRX_REG_IO_0BH_DEF                                  0x44
#define VRX_FIELD_CORE_PDN_DEF                              0x0
#define VRX_FIELD_CORE_PDN_BIT_SIZE                         1

#define VRX_FIELD_XTAL_PDN_DEF                              0x0
#define VRX_FIELD_XTAL_PDN_BIT_SIZE                         1

#define VRX_REG_IO_0CH_DEF                                  0x62
#define VRX_FIELD_POWER_DOWN_DEF                            0x1
#define VRX_FIELD_POWER_DOWN_BIT_SIZE                       1

#define VRX_FIELD_PWR_SAVE_MODE_DEF                         0x0
#define VRX_FIELD_PWR_SAVE_MODE_BIT_SIZE                    1

#define VRX_FIELD_CP_PWRDN_DEF                              0x0
#define VRX_FIELD_CP_PWRDN_BIT_SIZE                         1

#define VRX_FIELD_PADS_PDN_DEF                              0x0
#define VRX_FIELD_PADS_PDN_BIT_SIZE                         1

#define VRX_REG_IO_12H_DEF                                  0x00
#define VRX_FIELD_CP_STDI_INTERLACED_DEF                    0x0
#define VRX_FIELD_CP_STDI_INTERLACED_BIT_SIZE               1

#define VRX_FIELD_CP_INTERLACED_DEF                         0x0
#define VRX_FIELD_CP_INTERLACED_BIT_SIZE                    1

#define VRX_FIELD_CP_PROG_PARM_FOR_INT_DEF                  0x0
#define VRX_FIELD_CP_PROG_PARM_FOR_INT_BIT_SIZE             1

#define VRX_FIELD_CP_FORCE_INTERLACED_DEF                   0x0
#define VRX_FIELD_CP_FORCE_INTERLACED_BIT_SIZE              1

#define VRX_REG_IO_14H_DEF                                  0x6A
#define VRX_FIELD_DR_STR_DEF                                0x2
#define VRX_FIELD_DR_STR_BIT_SIZE                           2

#define VRX_FIELD_DR_STR_CLK_DEF                            0x2
#define VRX_FIELD_DR_STR_CLK_BIT_SIZE                       2

#define VRX_FIELD_DR_STR_SYNC_DEF                           0x2
#define VRX_FIELD_DR_STR_SYNC_BIT_SIZE                      2

#define VRX_REG_IO_15H_DEF                                  0xBE
#define VRX_FIELD_TRI_AUDIO_DEF                             0x1
#define VRX_FIELD_TRI_AUDIO_BIT_SIZE                        1

#define VRX_FIELD_TRI_SYNCS_DEF                             0x1
#define VRX_FIELD_TRI_SYNCS_BIT_SIZE                        1

#define VRX_FIELD_TRI_LLC_DEF                               0x1
#define VRX_FIELD_TRI_LLC_BIT_SIZE                          1

#define VRX_FIELD_TRI_PIX_DEF                               0x1
#define VRX_FIELD_TRI_PIX_BIT_SIZE                          1

#define VRX_REG_IO_19H_DEF                                  0x00
#define VRX_FIELD_LLC_DLL_EN_DEF                            0x0
#define VRX_FIELD_LLC_DLL_EN_BIT_SIZE                       1

#define VRX_FIELD_LLC_DLL_DOUBLE_DEF                        0x0
#define VRX_FIELD_LLC_DLL_DOUBLE_BIT_SIZE                   1

#define VRX_FIELD_LLC_DLL_PHASE_DEF                         0x0
#define VRX_FIELD_LLC_DLL_PHASE_BIT_SIZE                    5

#define VRX_REG_IO_1BH_DEF                                  0x00
#define VRX_FIELD_SAMPLE_ALSB_DEF                           0x0
#define VRX_FIELD_SAMPLE_ALSB_BIT_SIZE                      1

#define VRX_REG_IO_20H_DEF                                  0xF0
#define VRX_FIELD_HPA_MAN_VALUE_A_DEF                       0x1
#define VRX_FIELD_HPA_MAN_VALUE_A_BIT_SIZE                  1

#define VRX_FIELD_HPA_MAN_VALUE_B_DEF                       0x1
#define VRX_FIELD_HPA_MAN_VALUE_B_BIT_SIZE                  1

#define VRX_FIELD_HPA_TRISTATE_A_DEF                        0x0
#define VRX_FIELD_HPA_TRISTATE_A_BIT_SIZE                   1

#define VRX_FIELD_HPA_TRISTATE_B_DEF                        0x0
#define VRX_FIELD_HPA_TRISTATE_B_BIT_SIZE                   1

#define VRX_REG_IO_21H_DEF                                  0x00
#define VRX_FIELD_HPA_STATUS_PORT_A_DEF                     0x0
#define VRX_FIELD_HPA_STATUS_PORT_A_BIT_SIZE                1

#define VRX_FIELD_HPA_STATUS_PORT_B_DEF                     0x0
#define VRX_FIELD_HPA_STATUS_PORT_B_BIT_SIZE                1

#define VRX_REG_IO_30H_DEF                                  0x88
#define VRX_FIELD_PIXBUS_MSB_TO_LSB_REORDER_DEF             0x0
#define VRX_FIELD_PIXBUS_MSB_TO_LSB_REORDER_BIT_SIZE        1

#define VRX_REG_IO_33H_DEF                                  0x00
#define VRX_FIELD_LLC_DLL_MUX_DEF                           0x0
#define VRX_FIELD_LLC_DLL_MUX_BIT_SIZE                      1

#define VRX_REG_IO_3FH_DEF                                  0x00
#define VRX_FIELD_INTRQ_RAW_DEF                             0x0
#define VRX_FIELD_INTRQ_RAW_BIT_SIZE                        1

#define VRX_FIELD_INTRQ2_RAW_DEF                            0x0
#define VRX_FIELD_INTRQ2_RAW_BIT_SIZE                       1

#define VRX_REG_IO_40H_DEF                                  0x20
#define VRX_FIELD_INTRQ_DUR_SEL_DEF                         0x0
#define VRX_FIELD_INTRQ_DUR_SEL_BIT_SIZE                    2

#define VRX_FIELD_STORE_UNMASKED_IRQS_DEF                   0x0
#define VRX_FIELD_STORE_UNMASKED_IRQS_BIT_SIZE              1

#define VRX_FIELD_EN_UMASK_RAW_INTRQ_DEF                    0x0
#define VRX_FIELD_EN_UMASK_RAW_INTRQ_BIT_SIZE               1

#define VRX_FIELD_MPU_STIM_INTRQ_DEF                        0x0
#define VRX_FIELD_MPU_STIM_INTRQ_BIT_SIZE                   1

#define VRX_FIELD_INTRQ_OP_SEL_DEF                          0x0
#define VRX_FIELD_INTRQ_OP_SEL_BIT_SIZE                     2

#define VRX_REG_IO_41H_DEF                                  0x30
#define VRX_FIELD_INTRQ2_DUR_SEL_DEF                        0x0
#define VRX_FIELD_INTRQ2_DUR_SEL_BIT_SIZE                   2

#define VRX_FIELD_CP_LOCK_UNLOCK_EDGE_SEL_DEF               0x1
#define VRX_FIELD_CP_LOCK_UNLOCK_EDGE_SEL_BIT_SIZE          1

#define VRX_FIELD_STDI_DATA_VALID_EDGE_SEL_DEF              0x1
#define VRX_FIELD_STDI_DATA_VALID_EDGE_SEL_BIT_SIZE         1

#define VRX_FIELD_EN_UMASK_RAW_INTRQ2_DEF                   0x0
#define VRX_FIELD_EN_UMASK_RAW_INTRQ2_BIT_SIZE              1

#define VRX_FIELD_INT2_POL_DEF                              0x0
#define VRX_FIELD_INT2_POL_BIT_SIZE                         1

#define VRX_FIELD_INTRQ2_MUX_SEL_DEF                        0x0
#define VRX_FIELD_INTRQ2_MUX_SEL_BIT_SIZE                   2

#define VRX_REG_IO_42H_DEF                                  0x00
#define VRX_FIELD_STDI_DATA_VALID_RAW_DEF                   0x0
#define VRX_FIELD_STDI_DATA_VALID_RAW_BIT_SIZE              1

#define VRX_FIELD_CP_UNLOCK_RAW_DEF                         0x0
#define VRX_FIELD_CP_UNLOCK_RAW_BIT_SIZE                    1

#define VRX_FIELD_CP_LOCK_RAW_DEF                           0x0
#define VRX_FIELD_CP_LOCK_RAW_BIT_SIZE                      1

#define VRX_REG_IO_43H_DEF                                  0x00
#define VRX_FIELD_STDI_DATA_VALID_ST_DEF                    0x0
#define VRX_FIELD_STDI_DATA_VALID_ST_BIT_SIZE               1

#define VRX_FIELD_CP_UNLOCK_ST_DEF                          0x0
#define VRX_FIELD_CP_UNLOCK_ST_BIT_SIZE                     1

#define VRX_FIELD_CP_LOCK_ST_DEF                            0x0
#define VRX_FIELD_CP_LOCK_ST_BIT_SIZE                       1

#define VRX_REG_IO_44H_DEF                                  0x00
#define VRX_FIELD_STDI_DATA_VALID_CLR_DEF                   0x0
#define VRX_FIELD_STDI_DATA_VALID_CLR_BIT_SIZE              1

#define VRX_FIELD_CP_UNLOCK_CLR_DEF                         0x0
#define VRX_FIELD_CP_UNLOCK_CLR_BIT_SIZE                    1

#define VRX_FIELD_CP_LOCK_CLR_DEF                           0x0
#define VRX_FIELD_CP_LOCK_CLR_BIT_SIZE                      1

#define VRX_REG_IO_45H_DEF                                  0x00
#define VRX_FIELD_STDI_DATA_VALID_MB2_DEF                   0x0
#define VRX_FIELD_STDI_DATA_VALID_MB2_BIT_SIZE              1

#define VRX_FIELD_CP_UNLOCK_MB2_DEF                         0x0
#define VRX_FIELD_CP_UNLOCK_MB2_BIT_SIZE                    1

#define VRX_FIELD_CP_LOCK_MB2_DEF                           0x0
#define VRX_FIELD_CP_LOCK_MB2_BIT_SIZE                      1

#define VRX_REG_IO_46H_DEF                                  0x00
#define VRX_FIELD_STDI_DATA_VALID_MB1_DEF                   0x0
#define VRX_FIELD_STDI_DATA_VALID_MB1_BIT_SIZE              1

#define VRX_FIELD_CP_UNLOCK_MB1_DEF                         0x0
#define VRX_FIELD_CP_UNLOCK_MB1_BIT_SIZE                    1

#define VRX_FIELD_CP_LOCK_MB1_DEF                           0x0
#define VRX_FIELD_CP_LOCK_MB1_BIT_SIZE                      1

#define VRX_REG_IO_47H_DEF                                  0x00
#define VRX_FIELD_MPU_STIM_INTRQ_RAW_DEF                    0x0
#define VRX_FIELD_MPU_STIM_INTRQ_RAW_BIT_SIZE               1

#define VRX_REG_IO_48H_DEF                                  0x00
#define VRX_FIELD_MPU_STIM_INTRQ_ST_DEF                     0x0
#define VRX_FIELD_MPU_STIM_INTRQ_ST_BIT_SIZE                1

#define VRX_REG_IO_49H_DEF                                  0x00
#define VRX_FIELD_MPU_STIM_INTRQ_CLR_DEF                    0x0
#define VRX_FIELD_MPU_STIM_INTRQ_CLR_BIT_SIZE               1

#define VRX_REG_IO_4AH_DEF                                  0x00
#define VRX_FIELD_MPU_STIM_INTRQ_MB2_DEF                    0x0
#define VRX_FIELD_MPU_STIM_INTRQ_MB2_BIT_SIZE               1

#define VRX_REG_IO_4BH_DEF                                  0x00
#define VRX_FIELD_MPU_STIM_INTRQ_MB1_DEF                    0x0
#define VRX_FIELD_MPU_STIM_INTRQ_MB1_BIT_SIZE               1

#define VRX_REG_IO_5BH_DEF                                  0x00
#define VRX_FIELD_CP_LOCK_CH1_RAW_DEF                       0x0
#define VRX_FIELD_CP_LOCK_CH1_RAW_BIT_SIZE                  1

#define VRX_FIELD_CP_UNLOCK_CH1_RAW_DEF                     0x0
#define VRX_FIELD_CP_UNLOCK_CH1_RAW_BIT_SIZE                1

#define VRX_FIELD_STDI_DVALID_CH1_RAW_DEF                   0x0
#define VRX_FIELD_STDI_DVALID_CH1_RAW_BIT_SIZE              1

#define VRX_REG_IO_5CH_DEF                                  0x00
#define VRX_FIELD_CP_LOCK_CH1_ST_DEF                        0x0
#define VRX_FIELD_CP_LOCK_CH1_ST_BIT_SIZE                   1

#define VRX_FIELD_CP_UNLOCK_CH1_ST_DEF                      0x0
#define VRX_FIELD_CP_UNLOCK_CH1_ST_BIT_SIZE                 1

#define VRX_FIELD_STDI_DVALID_CH1_ST_DEF                    0x0
#define VRX_FIELD_STDI_DVALID_CH1_ST_BIT_SIZE               1

#define VRX_REG_IO_5DH_DEF                                  0x00
#define VRX_FIELD_CP_LOCK_CH1_CLR_DEF                       0x0
#define VRX_FIELD_CP_LOCK_CH1_CLR_BIT_SIZE                  1

#define VRX_FIELD_CP_UNLOCK_CH1_CLR_DEF                     0x0
#define VRX_FIELD_CP_UNLOCK_CH1_CLR_BIT_SIZE                1

#define VRX_FIELD_STDI_DVALID_CH1_CLR_DEF                   0x0
#define VRX_FIELD_STDI_DVALID_CH1_CLR_BIT_SIZE              1

#define VRX_REG_IO_5EH_DEF                                  0x00
#define VRX_FIELD_CP_LOCK_CH1_MB2_DEF                       0x0
#define VRX_FIELD_CP_LOCK_CH1_MB2_BIT_SIZE                  1

#define VRX_FIELD_CP_UNLOCK_CH1_MB2_DEF                     0x0
#define VRX_FIELD_CP_UNLOCK_CH1_MB2_BIT_SIZE                1

#define VRX_FIELD_STDI_DVALID_CH1_MB2_DEF                   0x0
#define VRX_FIELD_STDI_DVALID_CH1_MB2_BIT_SIZE              1

#define VRX_REG_IO_5FH_DEF                                  0x00
#define VRX_FIELD_CP_LOCK_CH1_MB1_DEF                       0x0
#define VRX_FIELD_CP_LOCK_CH1_MB1_BIT_SIZE                  1

#define VRX_FIELD_CP_UNLOCK_CH1_MB1_DEF                     0x0
#define VRX_FIELD_CP_UNLOCK_CH1_MB1_BIT_SIZE                1

#define VRX_FIELD_STDI_DVALID_CH1_MB1_DEF                   0x0
#define VRX_FIELD_STDI_DVALID_CH1_MB1_BIT_SIZE              1

#define VRX_REG_IO_60H_DEF                                  0x00
#define VRX_FIELD_ISRC2_PCKT_RAW_DEF                        0x0
#define VRX_FIELD_ISRC2_PCKT_RAW_BIT_SIZE                   1

#define VRX_FIELD_ISRC1_PCKT_RAW_DEF                        0x0
#define VRX_FIELD_ISRC1_PCKT_RAW_BIT_SIZE                   1

#define VRX_FIELD_ACP_PCKT_RAW_DEF                          0x0
#define VRX_FIELD_ACP_PCKT_RAW_BIT_SIZE                     1

#define VRX_FIELD_VS_INFO_RAW_DEF                           0x0
#define VRX_FIELD_VS_INFO_RAW_BIT_SIZE                      1

#define VRX_FIELD_MS_INFO_RAW_DEF                           0x0
#define VRX_FIELD_MS_INFO_RAW_BIT_SIZE                      1

#define VRX_FIELD_SPD_INFO_RAW_DEF                          0x0
#define VRX_FIELD_SPD_INFO_RAW_BIT_SIZE                     1

#define VRX_FIELD_AUDIO_INFO_RAW_DEF                        0x0
#define VRX_FIELD_AUDIO_INFO_RAW_BIT_SIZE                   1

#define VRX_FIELD_AVI_INFO_RAW_DEF                          0x0
#define VRX_FIELD_AVI_INFO_RAW_BIT_SIZE                     1

#define VRX_REG_IO_61H_DEF                                  0x00
#define VRX_FIELD_ISRC2_PCKT_ST_DEF                         0x0
#define VRX_FIELD_ISRC2_PCKT_ST_BIT_SIZE                    1

#define VRX_FIELD_ISRC1_PCKT_ST_DEF                         0x0
#define VRX_FIELD_ISRC1_PCKT_ST_BIT_SIZE                    1

#define VRX_FIELD_ACP_PCKT_ST_DEF                           0x0
#define VRX_FIELD_ACP_PCKT_ST_BIT_SIZE                      1

#define VRX_FIELD_VS_INFO_ST_DEF                            0x0
#define VRX_FIELD_VS_INFO_ST_BIT_SIZE                       1

#define VRX_FIELD_MS_INFO_ST_DEF                            0x0
#define VRX_FIELD_MS_INFO_ST_BIT_SIZE                       1

#define VRX_FIELD_SPD_INFO_ST_DEF                           0x0
#define VRX_FIELD_SPD_INFO_ST_BIT_SIZE                      1

#define VRX_FIELD_AUDIO_INFO_ST_DEF                         0x0
#define VRX_FIELD_AUDIO_INFO_ST_BIT_SIZE                    1

#define VRX_FIELD_AVI_INFO_ST_DEF                           0x0
#define VRX_FIELD_AVI_INFO_ST_BIT_SIZE                      1

#define VRX_REG_IO_62H_DEF                                  0x00
#define VRX_FIELD_ISRC2_PCKT_CLR_DEF                        0x0
#define VRX_FIELD_ISRC2_PCKT_CLR_BIT_SIZE                   1

#define VRX_FIELD_ISRC1_PCKT_CLR_DEF                        0x0
#define VRX_FIELD_ISRC1_PCKT_CLR_BIT_SIZE                   1

#define VRX_FIELD_ACP_PCKT_CLR_DEF                          0x0
#define VRX_FIELD_ACP_PCKT_CLR_BIT_SIZE                     1

#define VRX_FIELD_VS_INFO_CLR_DEF                           0x0
#define VRX_FIELD_VS_INFO_CLR_BIT_SIZE                      1

#define VRX_FIELD_MS_INFO_CLR_DEF                           0x0
#define VRX_FIELD_MS_INFO_CLR_BIT_SIZE                      1

#define VRX_FIELD_SPD_INFO_CLR_DEF                          0x0
#define VRX_FIELD_SPD_INFO_CLR_BIT_SIZE                     1

#define VRX_FIELD_AUDIO_INFO_CLR_DEF                        0x0
#define VRX_FIELD_AUDIO_INFO_CLR_BIT_SIZE                   1

#define VRX_FIELD_AVI_INFO_CLR_DEF                          0x0
#define VRX_FIELD_AVI_INFO_CLR_BIT_SIZE                     1

#define VRX_REG_IO_63H_DEF                                  0x00
#define VRX_FIELD_ISRC2_PCKT_MB2_DEF                        0x0
#define VRX_FIELD_ISRC2_PCKT_MB2_BIT_SIZE                   1

#define VRX_FIELD_ISRC1_PCKT_MB2_DEF                        0x0
#define VRX_FIELD_ISRC1_PCKT_MB2_BIT_SIZE                   1

#define VRX_FIELD_ACP_PCKT_MB2_DEF                          0x0
#define VRX_FIELD_ACP_PCKT_MB2_BIT_SIZE                     1

#define VRX_FIELD_VS_INFO_MB2_DEF                           0x0
#define VRX_FIELD_VS_INFO_MB2_BIT_SIZE                      1

#define VRX_FIELD_MS_INFO_MB2_DEF                           0x0
#define VRX_FIELD_MS_INFO_MB2_BIT_SIZE                      1

#define VRX_FIELD_SPD_INFO_MB2_DEF                          0x0
#define VRX_FIELD_SPD_INFO_MB2_BIT_SIZE                     1

#define VRX_FIELD_AUDIO_INFO_MB2_DEF                        0x0
#define VRX_FIELD_AUDIO_INFO_MB2_BIT_SIZE                   1

#define VRX_FIELD_AVI_INFO_MB2_DEF                          0x0
#define VRX_FIELD_AVI_INFO_MB2_BIT_SIZE                     1

#define VRX_REG_IO_64H_DEF                                  0x00
#define VRX_FIELD_ISRC2_PCKT_MB1_DEF                        0x0
#define VRX_FIELD_ISRC2_PCKT_MB1_BIT_SIZE                   1

#define VRX_FIELD_ISRC1_PCKT_MB1_DEF                        0x0
#define VRX_FIELD_ISRC1_PCKT_MB1_BIT_SIZE                   1

#define VRX_FIELD_ACP_PCKT_MB1_DEF                          0x0
#define VRX_FIELD_ACP_PCKT_MB1_BIT_SIZE                     1

#define VRX_FIELD_VS_INFO_MB1_DEF                           0x0
#define VRX_FIELD_VS_INFO_MB1_BIT_SIZE                      1

#define VRX_FIELD_MS_INFO_MB1_DEF                           0x0
#define VRX_FIELD_MS_INFO_MB1_BIT_SIZE                      1

#define VRX_FIELD_SPD_INFO_MB1_DEF                          0x0
#define VRX_FIELD_SPD_INFO_MB1_BIT_SIZE                     1

#define VRX_FIELD_AUDIO_INFO_MB1_DEF                        0x0
#define VRX_FIELD_AUDIO_INFO_MB1_BIT_SIZE                   1

#define VRX_FIELD_AVI_INFO_MB1_DEF                          0x0
#define VRX_FIELD_AVI_INFO_MB1_BIT_SIZE                     1

#define VRX_REG_IO_65H_DEF                                  0x00
#define VRX_FIELD_CS_DATA_VALID_RAW_DEF                     0x0
#define VRX_FIELD_CS_DATA_VALID_RAW_BIT_SIZE                1

#define VRX_FIELD_INTERNAL_MUTE_RAW_DEF                     0x0
#define VRX_FIELD_INTERNAL_MUTE_RAW_BIT_SIZE                1

#define VRX_FIELD_AV_MUTE_RAW_DEF                           0x0
#define VRX_FIELD_AV_MUTE_RAW_BIT_SIZE                      1

#define VRX_FIELD_AUDIO_CH_MD_RAW_DEF                       0x0
#define VRX_FIELD_AUDIO_CH_MD_RAW_BIT_SIZE                  1

#define VRX_FIELD_HDMI_MODE_RAW_DEF                         0x0
#define VRX_FIELD_HDMI_MODE_RAW_BIT_SIZE                    1

#define VRX_FIELD_GEN_CTL_PCKT_RAW_DEF                      0x0
#define VRX_FIELD_GEN_CTL_PCKT_RAW_BIT_SIZE                 1

#define VRX_FIELD_AUDIO_C_PCKT_RAW_DEF                      0x0
#define VRX_FIELD_AUDIO_C_PCKT_RAW_BIT_SIZE                 1

#define VRX_FIELD_GAMUT_MDATA_RAW_DEF                       0x0
#define VRX_FIELD_GAMUT_MDATA_RAW_BIT_SIZE                  1

#define VRX_REG_IO_66H_DEF                                  0x00
#define VRX_FIELD_CS_DATA_VALID_ST_DEF                      0x0
#define VRX_FIELD_CS_DATA_VALID_ST_BIT_SIZE                 1

#define VRX_FIELD_INTERNAL_MUTE_ST_DEF                      0x0
#define VRX_FIELD_INTERNAL_MUTE_ST_BIT_SIZE                 1

#define VRX_FIELD_AV_MUTE_ST_DEF                            0x0
#define VRX_FIELD_AV_MUTE_ST_BIT_SIZE                       1

#define VRX_FIELD_AUDIO_CH_MD_ST_DEF                        0x0
#define VRX_FIELD_AUDIO_CH_MD_ST_BIT_SIZE                   1

#define VRX_FIELD_HDMI_MODE_ST_DEF                          0x0
#define VRX_FIELD_HDMI_MODE_ST_BIT_SIZE                     1

#define VRX_FIELD_GEN_CTL_PCKT_ST_DEF                       0x0
#define VRX_FIELD_GEN_CTL_PCKT_ST_BIT_SIZE                  1

#define VRX_FIELD_AUDIO_C_PCKT_ST_DEF                       0x0
#define VRX_FIELD_AUDIO_C_PCKT_ST_BIT_SIZE                  1

#define VRX_FIELD_GAMUT_MDATA_ST_DEF                        0x0
#define VRX_FIELD_GAMUT_MDATA_ST_BIT_SIZE                   1

#define VRX_REG_IO_67H_DEF                                  0x00
#define VRX_FIELD_CS_DATA_VALID_CLR_DEF                     0x0
#define VRX_FIELD_CS_DATA_VALID_CLR_BIT_SIZE                1

#define VRX_FIELD_INTERNAL_MUTE_CLR_DEF                     0x0
#define VRX_FIELD_INTERNAL_MUTE_CLR_BIT_SIZE                1

#define VRX_FIELD_AV_MUTE_CLR_DEF                           0x0
#define VRX_FIELD_AV_MUTE_CLR_BIT_SIZE                      1

#define VRX_FIELD_AUDIO_CH_MD_CLR_DEF                       0x0
#define VRX_FIELD_AUDIO_CH_MD_CLR_BIT_SIZE                  1

#define VRX_FIELD_HDMI_MODE_CLR_DEF                         0x0
#define VRX_FIELD_HDMI_MODE_CLR_BIT_SIZE                    1

#define VRX_FIELD_GEN_CTL_PCKT_CLR_DEF                      0x0
#define VRX_FIELD_GEN_CTL_PCKT_CLR_BIT_SIZE                 1

#define VRX_FIELD_AUDIO_C_PCKT_CLR_DEF                      0x0
#define VRX_FIELD_AUDIO_C_PCKT_CLR_BIT_SIZE                 1

#define VRX_FIELD_GAMUT_MDATA_CLR_DEF                       0x0
#define VRX_FIELD_GAMUT_MDATA_CLR_BIT_SIZE                  1

#define VRX_REG_IO_68H_DEF                                  0x00
#define VRX_FIELD_CS_DATA_VALID_MB2_DEF                     0x0
#define VRX_FIELD_CS_DATA_VALID_MB2_BIT_SIZE                1

#define VRX_FIELD_INTERNAL_MUTE_MB2_DEF                     0x0
#define VRX_FIELD_INTERNAL_MUTE_MB2_BIT_SIZE                1

#define VRX_FIELD_AV_MUTE_MB2_DEF                           0x0
#define VRX_FIELD_AV_MUTE_MB2_BIT_SIZE                      1

#define VRX_FIELD_AUDIO_CH_MD_MB2_DEF                       0x0
#define VRX_FIELD_AUDIO_CH_MD_MB2_BIT_SIZE                  1

#define VRX_FIELD_HDMI_MODE_MB2_DEF                         0x0
#define VRX_FIELD_HDMI_MODE_MB2_BIT_SIZE                    1

#define VRX_FIELD_GEN_CTL_PCKT_MB2_DEF                      0x0
#define VRX_FIELD_GEN_CTL_PCKT_MB2_BIT_SIZE                 1

#define VRX_FIELD_AUDIO_C_PCKT_MB2_DEF                      0x0
#define VRX_FIELD_AUDIO_C_PCKT_MB2_BIT_SIZE                 1

#define VRX_FIELD_GAMUT_MDATA_MB2_DEF                       0x0
#define VRX_FIELD_GAMUT_MDATA_MB2_BIT_SIZE                  1

#define VRX_REG_IO_69H_DEF                                  0x00
#define VRX_FIELD_CS_DATA_VALID_MB1_DEF                     0x0
#define VRX_FIELD_CS_DATA_VALID_MB1_BIT_SIZE                1

#define VRX_FIELD_INTERNAL_MUTE_MB1_DEF                     0x0
#define VRX_FIELD_INTERNAL_MUTE_MB1_BIT_SIZE                1

#define VRX_FIELD_AV_MUTE_MB1_DEF                           0x0
#define VRX_FIELD_AV_MUTE_MB1_BIT_SIZE                      1

#define VRX_FIELD_AUDIO_CH_MD_MB1_DEF                       0x0
#define VRX_FIELD_AUDIO_CH_MD_MB1_BIT_SIZE                  1

#define VRX_FIELD_HDMI_MODE_MB1_DEF                         0x0
#define VRX_FIELD_HDMI_MODE_MB1_BIT_SIZE                    1

#define VRX_FIELD_GEN_CTL_PCKT_MB1_DEF                      0x0
#define VRX_FIELD_GEN_CTL_PCKT_MB1_BIT_SIZE                 1

#define VRX_FIELD_AUDIO_C_PCKT_MB1_DEF                      0x0
#define VRX_FIELD_AUDIO_C_PCKT_MB1_BIT_SIZE                 1

#define VRX_FIELD_GAMUT_MDATA_MB1_DEF                       0x0
#define VRX_FIELD_GAMUT_MDATA_MB1_BIT_SIZE                  1

#define VRX_REG_IO_6AH_DEF                                  0x00
#define VRX_FIELD_CABLE_DET_B_RAW_DEF                       0x0
#define VRX_FIELD_CABLE_DET_B_RAW_BIT_SIZE                  1

#define VRX_FIELD_TMDSPLL_LCK_A_RAW_DEF                     0x0
#define VRX_FIELD_TMDSPLL_LCK_A_RAW_BIT_SIZE                1

#define VRX_FIELD_TMDSPLL_LCK_B_RAW_DEF                     0x0
#define VRX_FIELD_TMDSPLL_LCK_B_RAW_BIT_SIZE                1

#define VRX_FIELD_TMDS_CLK_A_RAW_DEF                        0x0
#define VRX_FIELD_TMDS_CLK_A_RAW_BIT_SIZE                   1

#define VRX_FIELD_TMDS_CLK_B_RAW_DEF                        0x0
#define VRX_FIELD_TMDS_CLK_B_RAW_BIT_SIZE                   1

#define VRX_FIELD_VIDEO_3D_RAW_DEF                          0x0
#define VRX_FIELD_VIDEO_3D_RAW_BIT_SIZE                     1

#define VRX_FIELD_V_LOCKED_RAW_DEF                          0x0
#define VRX_FIELD_V_LOCKED_RAW_BIT_SIZE                     1

#define VRX_FIELD_DE_REGEN_LCK_RAW_DEF                      0x0
#define VRX_FIELD_DE_REGEN_LCK_RAW_BIT_SIZE                 1

#define VRX_REG_IO_6BH_DEF                                  0x00
#define VRX_FIELD_CABLE_DET_B_ST_DEF                        0x0
#define VRX_FIELD_CABLE_DET_B_ST_BIT_SIZE                   1

#define VRX_FIELD_TMDSPLL_LCK_A_ST_DEF                      0x0
#define VRX_FIELD_TMDSPLL_LCK_A_ST_BIT_SIZE                 1

#define VRX_FIELD_TMDSPLL_LCK_B_ST_DEF                      0x0
#define VRX_FIELD_TMDSPLL_LCK_B_ST_BIT_SIZE                 1

#define VRX_FIELD_TMDS_CLK_A_ST_DEF                         0x0
#define VRX_FIELD_TMDS_CLK_A_ST_BIT_SIZE                    1

#define VRX_FIELD_TMDS_CLK_B_ST_DEF                         0x0
#define VRX_FIELD_TMDS_CLK_B_ST_BIT_SIZE                    1

#define VRX_FIELD_VIDEO_3D_ST_DEF                           0x0
#define VRX_FIELD_VIDEO_3D_ST_BIT_SIZE                      1

#define VRX_FIELD_V_LOCKED_ST_DEF                           0x0
#define VRX_FIELD_V_LOCKED_ST_BIT_SIZE                      1

#define VRX_FIELD_DE_REGEN_LCK_ST_DEF                       0x0
#define VRX_FIELD_DE_REGEN_LCK_ST_BIT_SIZE                  1

#define VRX_REG_IO_6CH_DEF                                  0x00
#define VRX_FIELD_CABLE_DET_B_CLR_DEF                       0x0
#define VRX_FIELD_CABLE_DET_B_CLR_BIT_SIZE                  1

#define VRX_FIELD_TMDSPLL_LCK_A_CLR_DEF                     0x0
#define VRX_FIELD_TMDSPLL_LCK_A_CLR_BIT_SIZE                1

#define VRX_FIELD_TMDSPLL_LCK_B_CLR_DEF                     0x0
#define VRX_FIELD_TMDSPLL_LCK_B_CLR_BIT_SIZE                1

#define VRX_FIELD_TMDS_CLK_A_CLR_DEF                        0x0
#define VRX_FIELD_TMDS_CLK_A_CLR_BIT_SIZE                   1

#define VRX_FIELD_TMDS_CLK_B_CLR_DEF                        0x0
#define VRX_FIELD_TMDS_CLK_B_CLR_BIT_SIZE                   1

#define VRX_FIELD_VIDEO_3D_CLR_DEF                          0x0
#define VRX_FIELD_VIDEO_3D_CLR_BIT_SIZE                     1

#define VRX_FIELD_V_LOCKED_CLR_DEF                          0x0
#define VRX_FIELD_V_LOCKED_CLR_BIT_SIZE                     1

#define VRX_FIELD_DE_REGEN_LCK_CLR_DEF                      0x0
#define VRX_FIELD_DE_REGEN_LCK_CLR_BIT_SIZE                 1

#define VRX_REG_IO_6DH_DEF                                  0x00
#define VRX_FIELD_CABLE_DET_B_MB2_DEF                       0x0
#define VRX_FIELD_CABLE_DET_B_MB2_BIT_SIZE                  1

#define VRX_FIELD_TMDSPLL_LCK_A_MB2_DEF                     0x0
#define VRX_FIELD_TMDSPLL_LCK_A_MB2_BIT_SIZE                1

#define VRX_FIELD_TMDSPLL_LCK_B_MB2_DEF                     0x0
#define VRX_FIELD_TMDSPLL_LCK_B_MB2_BIT_SIZE                1

#define VRX_FIELD_TMDS_CLK_A_MB2_DEF                        0x0
#define VRX_FIELD_TMDS_CLK_A_MB2_BIT_SIZE                   1

#define VRX_FIELD_TMDS_CLK_B_MB2_DEF                        0x0
#define VRX_FIELD_TMDS_CLK_B_MB2_BIT_SIZE                   1

#define VRX_FIELD_VIDEO_3D_MB2_DEF                          0x0
#define VRX_FIELD_VIDEO_3D_MB2_BIT_SIZE                     1

#define VRX_FIELD_V_LOCKED_MB2_DEF                          0x0
#define VRX_FIELD_V_LOCKED_MB2_BIT_SIZE                     1

#define VRX_FIELD_DE_REGEN_LCK_MB2_DEF                      0x0
#define VRX_FIELD_DE_REGEN_LCK_MB2_BIT_SIZE                 1

#define VRX_REG_IO_6EH_DEF                                  0x00
#define VRX_FIELD_CABLE_DET_B_MB1_DEF                       0x0
#define VRX_FIELD_CABLE_DET_B_MB1_BIT_SIZE                  1

#define VRX_FIELD_TMDSPLL_LCK_A_MB1_DEF                     0x0
#define VRX_FIELD_TMDSPLL_LCK_A_MB1_BIT_SIZE                1

#define VRX_FIELD_TMDSPLL_LCK_B_MB1_DEF                     0x0
#define VRX_FIELD_TMDSPLL_LCK_B_MB1_BIT_SIZE                1

#define VRX_FIELD_TMDS_CLK_A_MB1_DEF                        0x0
#define VRX_FIELD_TMDS_CLK_A_MB1_BIT_SIZE                   1

#define VRX_FIELD_TMDS_CLK_B_MB1_DEF                        0x0
#define VRX_FIELD_TMDS_CLK_B_MB1_BIT_SIZE                   1

#define VRX_FIELD_VIDEO_3D_MB1_DEF                          0x0
#define VRX_FIELD_VIDEO_3D_MB1_BIT_SIZE                     1

#define VRX_FIELD_V_LOCKED_MB1_DEF                          0x0
#define VRX_FIELD_V_LOCKED_MB1_BIT_SIZE                     1

#define VRX_FIELD_DE_REGEN_LCK_MB1_DEF                      0x0
#define VRX_FIELD_DE_REGEN_LCK_MB1_BIT_SIZE                 1

#define VRX_REG_IO_6FH_DEF                                  0x00
#define VRX_FIELD_HDMI_ENCRPT_A_RAW_DEF                     0x0
#define VRX_FIELD_HDMI_ENCRPT_A_RAW_BIT_SIZE                1

#define VRX_FIELD_HDMI_ENCRPT_B_RAW_DEF                     0x0
#define VRX_FIELD_HDMI_ENCRPT_B_RAW_BIT_SIZE                1

#define VRX_FIELD_CABLE_DET_A_RAW_DEF                       0x0
#define VRX_FIELD_CABLE_DET_A_RAW_BIT_SIZE                  1

#define VRX_REG_IO_70H_DEF                                  0x00
#define VRX_FIELD_HDMI_ENCRPT_A_ST_DEF                      0x0
#define VRX_FIELD_HDMI_ENCRPT_A_ST_BIT_SIZE                 1

#define VRX_FIELD_HDMI_ENCRPT_B_ST_DEF                      0x0
#define VRX_FIELD_HDMI_ENCRPT_B_ST_BIT_SIZE                 1

#define VRX_FIELD_CABLE_DET_A_ST_DEF                        0x0
#define VRX_FIELD_CABLE_DET_A_ST_BIT_SIZE                   1

#define VRX_REG_IO_71H_DEF                                  0x00
#define VRX_FIELD_HDMI_ENCRPT_A_CLR_DEF                     0x0
#define VRX_FIELD_HDMI_ENCRPT_A_CLR_BIT_SIZE                1

#define VRX_FIELD_HDMI_ENCRPT_B_CLR_DEF                     0x0
#define VRX_FIELD_HDMI_ENCRPT_B_CLR_BIT_SIZE                1

#define VRX_FIELD_CABLE_DET_A_CLR_DEF                       0x0
#define VRX_FIELD_CABLE_DET_A_CLR_BIT_SIZE                  1

#define VRX_REG_IO_72H_DEF                                  0x00
#define VRX_FIELD_HDMI_ENCRPT_A_MB2_DEF                     0x0
#define VRX_FIELD_HDMI_ENCRPT_A_MB2_BIT_SIZE                1

#define VRX_FIELD_HDMI_ENCRPT_B_MB2_DEF                     0x0
#define VRX_FIELD_HDMI_ENCRPT_B_MB2_BIT_SIZE                1

#define VRX_FIELD_CABLE_DET_A_MB2_DEF                       0x0
#define VRX_FIELD_CABLE_DET_A_MB2_BIT_SIZE                  1

#define VRX_REG_IO_73H_DEF                                  0x00
#define VRX_FIELD_HDMI_ENCRPT_A_MB1_DEF                     0x0
#define VRX_FIELD_HDMI_ENCRPT_A_MB1_BIT_SIZE                1

#define VRX_FIELD_HDMI_ENCRPT_B_MB1_DEF                     0x0
#define VRX_FIELD_HDMI_ENCRPT_B_MB1_BIT_SIZE                1

#define VRX_FIELD_CABLE_DET_A_MB1_DEF                       0x0
#define VRX_FIELD_CABLE_DET_A_MB1_BIT_SIZE                  1

#define VRX_REG_IO_79H_DEF                                  0x00
#define VRX_FIELD_NEW_ISRC2_PCKT_RAW_DEF                    0x0
#define VRX_FIELD_NEW_ISRC2_PCKT_RAW_BIT_SIZE               1

#define VRX_FIELD_NEW_ISRC1_PCKT_RAW_DEF                    0x0
#define VRX_FIELD_NEW_ISRC1_PCKT_RAW_BIT_SIZE               1

#define VRX_FIELD_NEW_ACP_PCKT_RAW_DEF                      0x0
#define VRX_FIELD_NEW_ACP_PCKT_RAW_BIT_SIZE                 1

#define VRX_FIELD_NEW_VS_INFO_RAW_DEF                       0x0
#define VRX_FIELD_NEW_VS_INFO_RAW_BIT_SIZE                  1

#define VRX_FIELD_NEW_MS_INFO_RAW_DEF                       0x0
#define VRX_FIELD_NEW_MS_INFO_RAW_BIT_SIZE                  1

#define VRX_FIELD_NEW_SPD_INFO_RAW_DEF                      0x0
#define VRX_FIELD_NEW_SPD_INFO_RAW_BIT_SIZE                 1

#define VRX_FIELD_NEW_AUDIO_INFO_RAW_DEF                    0x0
#define VRX_FIELD_NEW_AUDIO_INFO_RAW_BIT_SIZE               1

#define VRX_FIELD_NEW_AVI_INFO_RAW_DEF                      0x0
#define VRX_FIELD_NEW_AVI_INFO_RAW_BIT_SIZE                 1

#define VRX_REG_IO_7AH_DEF                                  0x00
#define VRX_FIELD_NEW_ISRC2_PCKT_ST_DEF                     0x0
#define VRX_FIELD_NEW_ISRC2_PCKT_ST_BIT_SIZE                1

#define VRX_FIELD_NEW_ISRC1_PCKT_ST_DEF                     0x0
#define VRX_FIELD_NEW_ISRC1_PCKT_ST_BIT_SIZE                1

#define VRX_FIELD_NEW_ACP_PCKT_ST_DEF                       0x0
#define VRX_FIELD_NEW_ACP_PCKT_ST_BIT_SIZE                  1

#define VRX_FIELD_NEW_VS_INFO_ST_DEF                        0x0
#define VRX_FIELD_NEW_VS_INFO_ST_BIT_SIZE                   1

#define VRX_FIELD_NEW_MS_INFO_ST_DEF                        0x0
#define VRX_FIELD_NEW_MS_INFO_ST_BIT_SIZE                   1

#define VRX_FIELD_NEW_SPD_INFO_ST_DEF                       0x0
#define VRX_FIELD_NEW_SPD_INFO_ST_BIT_SIZE                  1

#define VRX_FIELD_NEW_AUDIO_INFO_ST_DEF                     0x0
#define VRX_FIELD_NEW_AUDIO_INFO_ST_BIT_SIZE                1

#define VRX_FIELD_NEW_AVI_INFO_ST_DEF                       0x0
#define VRX_FIELD_NEW_AVI_INFO_ST_BIT_SIZE                  1

#define VRX_REG_IO_7BH_DEF                                  0x00
#define VRX_FIELD_NEW_ISRC2_PCKT_CLR_DEF                    0x0
#define VRX_FIELD_NEW_ISRC2_PCKT_CLR_BIT_SIZE               1

#define VRX_FIELD_NEW_ISRC1_PCKT_CLR_DEF                    0x0
#define VRX_FIELD_NEW_ISRC1_PCKT_CLR_BIT_SIZE               1

#define VRX_FIELD_NEW_ACP_PCKT_CLR_DEF                      0x0
#define VRX_FIELD_NEW_ACP_PCKT_CLR_BIT_SIZE                 1

#define VRX_FIELD_NEW_VS_INFO_CLR_DEF                       0x0
#define VRX_FIELD_NEW_VS_INFO_CLR_BIT_SIZE                  1

#define VRX_FIELD_NEW_MS_INFO_CLR_DEF                       0x0
#define VRX_FIELD_NEW_MS_INFO_CLR_BIT_SIZE                  1

#define VRX_FIELD_NEW_SPD_INFO_CLR_DEF                      0x0
#define VRX_FIELD_NEW_SPD_INFO_CLR_BIT_SIZE                 1

#define VRX_FIELD_NEW_AUDIO_INFO_CLR_DEF                    0x0
#define VRX_FIELD_NEW_AUDIO_INFO_CLR_BIT_SIZE               1

#define VRX_FIELD_NEW_AVI_INFO_CLR_DEF                      0x0
#define VRX_FIELD_NEW_AVI_INFO_CLR_BIT_SIZE                 1

#define VRX_REG_IO_7CH_DEF                                  0x00
#define VRX_FIELD_NEW_ISRC2_PCKT_MB2_DEF                    0x0
#define VRX_FIELD_NEW_ISRC2_PCKT_MB2_BIT_SIZE               1

#define VRX_FIELD_NEW_ISRC1_PCKT_MB2_DEF                    0x0
#define VRX_FIELD_NEW_ISRC1_PCKT_MB2_BIT_SIZE               1

#define VRX_FIELD_NEW_ACP_PCKT_MB2_DEF                      0x0
#define VRX_FIELD_NEW_ACP_PCKT_MB2_BIT_SIZE                 1

#define VRX_FIELD_NEW_VS_INFO_MB2_DEF                       0x0
#define VRX_FIELD_NEW_VS_INFO_MB2_BIT_SIZE                  1

#define VRX_FIELD_NEW_MS_INFO_MB2_DEF                       0x0
#define VRX_FIELD_NEW_MS_INFO_MB2_BIT_SIZE                  1

#define VRX_FIELD_NEW_SPD_INFO_MB2_DEF                      0x0
#define VRX_FIELD_NEW_SPD_INFO_MB2_BIT_SIZE                 1

#define VRX_FIELD_NEW_AUDIO_INFO_MB2_DEF                    0x0
#define VRX_FIELD_NEW_AUDIO_INFO_MB2_BIT_SIZE               1

#define VRX_FIELD_NEW_AVI_INFO_MB2_DEF                      0x0
#define VRX_FIELD_NEW_AVI_INFO_MB2_BIT_SIZE                 1

#define VRX_REG_IO_7DH_DEF                                  0x00
#define VRX_FIELD_NEW_ISRC2_PCKT_MB1_DEF                    0x0
#define VRX_FIELD_NEW_ISRC2_PCKT_MB1_BIT_SIZE               1

#define VRX_FIELD_NEW_ISRC1_PCKT_MB1_DEF                    0x0
#define VRX_FIELD_NEW_ISRC1_PCKT_MB1_BIT_SIZE               1

#define VRX_FIELD_NEW_ACP_PCKT_MB1_DEF                      0x0
#define VRX_FIELD_NEW_ACP_PCKT_MB1_BIT_SIZE                 1

#define VRX_FIELD_NEW_VS_INFO_MB1_DEF                       0x0
#define VRX_FIELD_NEW_VS_INFO_MB1_BIT_SIZE                  1

#define VRX_FIELD_NEW_MS_INFO_MB1_DEF                       0x0
#define VRX_FIELD_NEW_MS_INFO_MB1_BIT_SIZE                  1

#define VRX_FIELD_NEW_SPD_INFO_MB1_DEF                      0x0
#define VRX_FIELD_NEW_SPD_INFO_MB1_BIT_SIZE                 1

#define VRX_FIELD_NEW_AUDIO_INFO_MB1_DEF                    0x0
#define VRX_FIELD_NEW_AUDIO_INFO_MB1_BIT_SIZE               1

#define VRX_FIELD_NEW_AVI_INFO_MB1_DEF                      0x0
#define VRX_FIELD_NEW_AVI_INFO_MB1_BIT_SIZE                 1

#define VRX_REG_IO_7EH_DEF                                  0x00
#define VRX_FIELD_FIFO_NEAR_OVFL_RAW_DEF                    0x0
#define VRX_FIELD_FIFO_NEAR_OVFL_RAW_BIT_SIZE               1

#define VRX_FIELD_FIFO_UNDERFLO_RAW_DEF                     0x0
#define VRX_FIELD_FIFO_UNDERFLO_RAW_BIT_SIZE                1

#define VRX_FIELD_FIFO_OVERFLO_RAW_DEF                      0x0
#define VRX_FIELD_FIFO_OVERFLO_RAW_BIT_SIZE                 1

#define VRX_FIELD_CTS_PASS_THRSH_RAW_DEF                    0x0
#define VRX_FIELD_CTS_PASS_THRSH_RAW_BIT_SIZE               1

#define VRX_FIELD_CHANGE_N_RAW_DEF                          0x0
#define VRX_FIELD_CHANGE_N_RAW_BIT_SIZE                     1

#define VRX_FIELD_PACKET_ERROR_RAW_DEF                      0x0
#define VRX_FIELD_PACKET_ERROR_RAW_BIT_SIZE                 1

#define VRX_FIELD_AUDIO_PCKT_ERR_RAW_DEF                    0x0
#define VRX_FIELD_AUDIO_PCKT_ERR_RAW_BIT_SIZE               1

#define VRX_FIELD_NEW_GAMUT_MDATA_RAW_DEF                   0x0
#define VRX_FIELD_NEW_GAMUT_MDATA_RAW_BIT_SIZE              1

#define VRX_REG_IO_7FH_DEF                                  0x00
#define VRX_FIELD_FIFO_NEAR_OVFL_ST_DEF                     0x0
#define VRX_FIELD_FIFO_NEAR_OVFL_ST_BIT_SIZE                1

#define VRX_FIELD_FIFO_UNDERFLO_ST_DEF                      0x0
#define VRX_FIELD_FIFO_UNDERFLO_ST_BIT_SIZE                 1

#define VRX_FIELD_FIFO_OVERFLO_ST_DEF                       0x0
#define VRX_FIELD_FIFO_OVERFLO_ST_BIT_SIZE                  1

#define VRX_FIELD_CTS_PASS_THRSH_ST_DEF                     0x0
#define VRX_FIELD_CTS_PASS_THRSH_ST_BIT_SIZE                1

#define VRX_FIELD_CHANGE_N_ST_DEF                           0x0
#define VRX_FIELD_CHANGE_N_ST_BIT_SIZE                      1

#define VRX_FIELD_PACKET_ERROR_ST_DEF                       0x0
#define VRX_FIELD_PACKET_ERROR_ST_BIT_SIZE                  1

#define VRX_FIELD_AUDIO_PCKT_ERR_ST_DEF                     0x0
#define VRX_FIELD_AUDIO_PCKT_ERR_ST_BIT_SIZE                1

#define VRX_FIELD_NEW_GAMUT_MDATA_ST_DEF                    0x0
#define VRX_FIELD_NEW_GAMUT_MDATA_ST_BIT_SIZE               1

#define VRX_REG_IO_80H_DEF                                  0x00
#define VRX_FIELD_FIFO_NEAR_OVFL_CLR_DEF                    0x0
#define VRX_FIELD_FIFO_NEAR_OVFL_CLR_BIT_SIZE               1

#define VRX_FIELD_FIFO_UNDERFLO_CLR_DEF                     0x0
#define VRX_FIELD_FIFO_UNDERFLO_CLR_BIT_SIZE                1

#define VRX_FIELD_FIFO_OVERFLO_CLR_DEF                      0x0
#define VRX_FIELD_FIFO_OVERFLO_CLR_BIT_SIZE                 1

#define VRX_FIELD_CTS_PASS_THRSH_CLR_DEF                    0x0
#define VRX_FIELD_CTS_PASS_THRSH_CLR_BIT_SIZE               1

#define VRX_FIELD_CHANGE_N_CLR_DEF                          0x0
#define VRX_FIELD_CHANGE_N_CLR_BIT_SIZE                     1

#define VRX_FIELD_PACKET_ERROR_CLR_DEF                      0x0
#define VRX_FIELD_PACKET_ERROR_CLR_BIT_SIZE                 1

#define VRX_FIELD_AUDIO_PCKT_ERR_CLR_DEF                    0x0
#define VRX_FIELD_AUDIO_PCKT_ERR_CLR_BIT_SIZE               1

#define VRX_FIELD_NEW_GAMUT_MDATA_CLR_DEF                   0x0
#define VRX_FIELD_NEW_GAMUT_MDATA_CLR_BIT_SIZE              1

#define VRX_REG_IO_81H_DEF                                  0x00
#define VRX_FIELD_FIFO_NEAR_OVFL_MB2_DEF                    0x0
#define VRX_FIELD_FIFO_NEAR_OVFL_MB2_BIT_SIZE               1

#define VRX_FIELD_FIFO_UNDERFLO_MB2_DEF                     0x0
#define VRX_FIELD_FIFO_UNDERFLO_MB2_BIT_SIZE                1

#define VRX_FIELD_FIFO_OVERFLO_MB2_DEF                      0x0
#define VRX_FIELD_FIFO_OVERFLO_MB2_BIT_SIZE                 1

#define VRX_FIELD_CTS_PASS_THRSH_MB2_DEF                    0x0
#define VRX_FIELD_CTS_PASS_THRSH_MB2_BIT_SIZE               1

#define VRX_FIELD_CHANGE_N_MB2_DEF                          0x0
#define VRX_FIELD_CHANGE_N_MB2_BIT_SIZE                     1

#define VRX_FIELD_PACKET_ERROR_MB2_DEF                      0x0
#define VRX_FIELD_PACKET_ERROR_MB2_BIT_SIZE                 1

#define VRX_FIELD_AUDIO_PCKT_ERR_MB2_DEF                    0x0
#define VRX_FIELD_AUDIO_PCKT_ERR_MB2_BIT_SIZE               1

#define VRX_FIELD_NEW_GAMUT_MDATA_MB2_DEF                   0x0
#define VRX_FIELD_NEW_GAMUT_MDATA_MB2_BIT_SIZE              1

#define VRX_REG_IO_82H_DEF                                  0x00
#define VRX_FIELD_FIFO_NEAR_OVFL_MB1_DEF                    0x0
#define VRX_FIELD_FIFO_NEAR_OVFL_MB1_BIT_SIZE               1

#define VRX_FIELD_FIFO_UNDERFLO_MB1_DEF                     0x0
#define VRX_FIELD_FIFO_UNDERFLO_MB1_BIT_SIZE                1

#define VRX_FIELD_FIFO_OVERFLO_MB1_DEF                      0x0
#define VRX_FIELD_FIFO_OVERFLO_MB1_BIT_SIZE                 1

#define VRX_FIELD_CTS_PASS_THRSH_MB1_DEF                    0x0
#define VRX_FIELD_CTS_PASS_THRSH_MB1_BIT_SIZE               1

#define VRX_FIELD_CHANGE_N_MB1_DEF                          0x0
#define VRX_FIELD_CHANGE_N_MB1_BIT_SIZE                     1

#define VRX_FIELD_PACKET_ERROR_MB1_DEF                      0x0
#define VRX_FIELD_PACKET_ERROR_MB1_BIT_SIZE                 1

#define VRX_FIELD_AUDIO_PCKT_ERR_MB1_DEF                    0x0
#define VRX_FIELD_AUDIO_PCKT_ERR_MB1_BIT_SIZE               1

#define VRX_FIELD_NEW_GAMUT_MDATA_MB1_DEF                   0x0
#define VRX_FIELD_NEW_GAMUT_MDATA_MB1_BIT_SIZE              1

#define VRX_REG_IO_83H_DEF                                  0x00
#define VRX_FIELD_DEEP_COLOR_CHNG_RAW_DEF                   0x0
#define VRX_FIELD_DEEP_COLOR_CHNG_RAW_BIT_SIZE              1

#define VRX_FIELD_VCLK_CHNG_RAW_DEF                         0x0
#define VRX_FIELD_VCLK_CHNG_RAW_BIT_SIZE                    1

#define VRX_FIELD_AUDIO_MODE_CHNG_RAW_DEF                   0x0
#define VRX_FIELD_AUDIO_MODE_CHNG_RAW_BIT_SIZE              1

#define VRX_FIELD_PARITY_ERROR_RAW_DEF                      0x0
#define VRX_FIELD_PARITY_ERROR_RAW_BIT_SIZE                 1

#define VRX_FIELD_NEW_SAMP_RT_RAW_DEF                       0x0
#define VRX_FIELD_NEW_SAMP_RT_RAW_BIT_SIZE                  1

#define VRX_FIELD_AUDIO_FLT_LINE_RAW_DEF                    0x0
#define VRX_FIELD_AUDIO_FLT_LINE_RAW_BIT_SIZE               1

#define VRX_FIELD_NEW_TMDS_FRQ_RAW_DEF                      0x0
#define VRX_FIELD_NEW_TMDS_FRQ_RAW_BIT_SIZE                 1

#define VRX_FIELD_FIFO_NEAR_UFLO_RAW_DEF                    0x0
#define VRX_FIELD_FIFO_NEAR_UFLO_RAW_BIT_SIZE               1

#define VRX_REG_IO_84H_DEF                                  0x00
#define VRX_FIELD_DEEP_COLOR_CHNG_ST_DEF                    0x0
#define VRX_FIELD_DEEP_COLOR_CHNG_ST_BIT_SIZE               1

#define VRX_FIELD_VCLK_CHNG_ST_DEF                          0x0
#define VRX_FIELD_VCLK_CHNG_ST_BIT_SIZE                     1

#define VRX_FIELD_AUDIO_MODE_CHNG_ST_DEF                    0x0
#define VRX_FIELD_AUDIO_MODE_CHNG_ST_BIT_SIZE               1

#define VRX_FIELD_PARITY_ERROR_ST_DEF                       0x0
#define VRX_FIELD_PARITY_ERROR_ST_BIT_SIZE                  1

#define VRX_FIELD_NEW_SAMP_RT_ST_DEF                        0x0
#define VRX_FIELD_NEW_SAMP_RT_ST_BIT_SIZE                   1

#define VRX_FIELD_AUDIO_FLT_LINE_ST_DEF                     0x0
#define VRX_FIELD_AUDIO_FLT_LINE_ST_BIT_SIZE                1

#define VRX_FIELD_NEW_TMDS_FRQ_ST_DEF                       0x0
#define VRX_FIELD_NEW_TMDS_FRQ_ST_BIT_SIZE                  1

#define VRX_FIELD_FIFO_NEAR_UFLO_ST_DEF                     0x0
#define VRX_FIELD_FIFO_NEAR_UFLO_ST_BIT_SIZE                1

#define VRX_REG_IO_85H_DEF                                  0x00
#define VRX_FIELD_DEEP_COLOR_CHNG_CLR_DEF                   0x0
#define VRX_FIELD_DEEP_COLOR_CHNG_CLR_BIT_SIZE              1

#define VRX_FIELD_VCLK_CHNG_CLR_DEF                         0x0
#define VRX_FIELD_VCLK_CHNG_CLR_BIT_SIZE                    1

#define VRX_FIELD_AUDIO_MODE_CHNG_CLR_DEF                   0x0
#define VRX_FIELD_AUDIO_MODE_CHNG_CLR_BIT_SIZE              1

#define VRX_FIELD_PARITY_ERROR_CLR_DEF                      0x0
#define VRX_FIELD_PARITY_ERROR_CLR_BIT_SIZE                 1

#define VRX_FIELD_NEW_SAMP_RT_CLR_DEF                       0x0
#define VRX_FIELD_NEW_SAMP_RT_CLR_BIT_SIZE                  1

#define VRX_FIELD_AUDIO_FLT_LINE_CLR_DEF                    0x0
#define VRX_FIELD_AUDIO_FLT_LINE_CLR_BIT_SIZE               1

#define VRX_FIELD_NEW_TMDS_FRQ_CLR_DEF                      0x0
#define VRX_FIELD_NEW_TMDS_FRQ_CLR_BIT_SIZE                 1

#define VRX_FIELD_FIFO_NEAR_UFLO_CLR_DEF                    0x0
#define VRX_FIELD_FIFO_NEAR_UFLO_CLR_BIT_SIZE               1

#define VRX_REG_IO_86H_DEF                                  0x00
#define VRX_FIELD_DEEP_COLOR_CHNG_MB2_DEF                   0x0
#define VRX_FIELD_DEEP_COLOR_CHNG_MB2_BIT_SIZE              1

#define VRX_FIELD_VCLK_CHNG_MB2_DEF                         0x0
#define VRX_FIELD_VCLK_CHNG_MB2_BIT_SIZE                    1

#define VRX_FIELD_AUDIO_MODE_CHNG_MB2_DEF                   0x0
#define VRX_FIELD_AUDIO_MODE_CHNG_MB2_BIT_SIZE              1

#define VRX_FIELD_PARITY_ERROR_MB2_DEF                      0x0
#define VRX_FIELD_PARITY_ERROR_MB2_BIT_SIZE                 1

#define VRX_FIELD_NEW_SAMP_RT_MB2_DEF                       0x0
#define VRX_FIELD_NEW_SAMP_RT_MB2_BIT_SIZE                  1

#define VRX_FIELD_AUDIO_FLT_LINE_MB2_DEF                    0x0
#define VRX_FIELD_AUDIO_FLT_LINE_MB2_BIT_SIZE               1

#define VRX_FIELD_NEW_TMDS_FRQ_MB2_DEF                      0x0
#define VRX_FIELD_NEW_TMDS_FRQ_MB2_BIT_SIZE                 1

#define VRX_FIELD_FIFO_NEAR_UFLO_MB2_DEF                    0x0
#define VRX_FIELD_FIFO_NEAR_UFLO_MB2_BIT_SIZE               1

#define VRX_REG_IO_87H_DEF                                  0x00
#define VRX_FIELD_DEEP_COLOR_CHNG_MB1_DEF                   0x0
#define VRX_FIELD_DEEP_COLOR_CHNG_MB1_BIT_SIZE              1

#define VRX_FIELD_VCLK_CHNG_MB1_DEF                         0x0
#define VRX_FIELD_VCLK_CHNG_MB1_BIT_SIZE                    1

#define VRX_FIELD_AUDIO_MODE_CHNG_MB1_DEF                   0x0
#define VRX_FIELD_AUDIO_MODE_CHNG_MB1_BIT_SIZE              1

#define VRX_FIELD_PARITY_ERROR_MB1_DEF                      0x0
#define VRX_FIELD_PARITY_ERROR_MB1_BIT_SIZE                 1

#define VRX_FIELD_NEW_SAMP_RT_MB1_DEF                       0x0
#define VRX_FIELD_NEW_SAMP_RT_MB1_BIT_SIZE                  1

#define VRX_FIELD_AUDIO_FLT_LINE_MB1_DEF                    0x0
#define VRX_FIELD_AUDIO_FLT_LINE_MB1_BIT_SIZE               1

#define VRX_FIELD_NEW_TMDS_FRQ_MB1_DEF                      0x0
#define VRX_FIELD_NEW_TMDS_FRQ_MB1_BIT_SIZE                 1

#define VRX_FIELD_FIFO_NEAR_UFLO_MB1_DEF                    0x0
#define VRX_FIELD_FIFO_NEAR_UFLO_MB1_BIT_SIZE               1

#define VRX_REG_IO_88H_DEF                                  0x00
#define VRX_FIELD_MS_INF_CKS_ERR_RAW_DEF                    0x0
#define VRX_FIELD_MS_INF_CKS_ERR_RAW_BIT_SIZE               1

#define VRX_FIELD_SPD_INF_CKS_ERR_RAW_DEF                   0x0
#define VRX_FIELD_SPD_INF_CKS_ERR_RAW_BIT_SIZE              1

#define VRX_FIELD_AUD_INF_CKS_ERR_RAW_DEF                   0x0
#define VRX_FIELD_AUD_INF_CKS_ERR_RAW_BIT_SIZE              1

#define VRX_FIELD_AVI_INF_CKS_ERR_RAW_DEF                   0x0
#define VRX_FIELD_AVI_INF_CKS_ERR_RAW_BIT_SIZE              1

#define VRX_FIELD_RI_EXPIRED_B_RAW_DEF                      0x0
#define VRX_FIELD_RI_EXPIRED_B_RAW_BIT_SIZE                 1

#define VRX_FIELD_RI_EXPIRED_A_RAW_DEF                      0x0
#define VRX_FIELD_RI_EXPIRED_A_RAW_BIT_SIZE                 1

#define VRX_FIELD_AKSV_UPDATE_B_RAW_DEF                     0x0
#define VRX_FIELD_AKSV_UPDATE_B_RAW_BIT_SIZE                1

#define VRX_FIELD_AKSV_UPDATE_A_RAW_DEF                     0x0
#define VRX_FIELD_AKSV_UPDATE_A_RAW_BIT_SIZE                1

#define VRX_REG_IO_89H_DEF                                  0x00
#define VRX_FIELD_MS_INF_CKS_ERR_ST_DEF                     0x0
#define VRX_FIELD_MS_INF_CKS_ERR_ST_BIT_SIZE                1

#define VRX_FIELD_SPD_INF_CKS_ERR_ST_DEF                    0x0
#define VRX_FIELD_SPD_INF_CKS_ERR_ST_BIT_SIZE               1

#define VRX_FIELD_AUD_INF_CKS_ERR_ST_DEF                    0x0
#define VRX_FIELD_AUD_INF_CKS_ERR_ST_BIT_SIZE               1

#define VRX_FIELD_AVI_INF_CKS_ERR_ST_DEF                    0x0
#define VRX_FIELD_AVI_INF_CKS_ERR_ST_BIT_SIZE               1

#define VRX_FIELD_RI_EXPIRED_B_ST_DEF                       0x0
#define VRX_FIELD_RI_EXPIRED_B_ST_BIT_SIZE                  1

#define VRX_FIELD_RI_EXPIRED_A_ST_DEF                       0x0
#define VRX_FIELD_RI_EXPIRED_A_ST_BIT_SIZE                  1

#define VRX_FIELD_AKSV_UPDATE_B_ST_DEF                      0x0
#define VRX_FIELD_AKSV_UPDATE_B_ST_BIT_SIZE                 1

#define VRX_FIELD_AKSV_UPDATE_A_ST_DEF                      0x0
#define VRX_FIELD_AKSV_UPDATE_A_ST_BIT_SIZE                 1

#define VRX_REG_IO_8AH_DEF                                  0x00
#define VRX_FIELD_MS_INF_CKS_ERR_CLR_DEF                    0x0
#define VRX_FIELD_MS_INF_CKS_ERR_CLR_BIT_SIZE               1

#define VRX_FIELD_SPD_INF_CKS_ERR_CLR_DEF                   0x0
#define VRX_FIELD_SPD_INF_CKS_ERR_CLR_BIT_SIZE              1

#define VRX_FIELD_AUD_INF_CKS_ERR_CLR_DEF                   0x0
#define VRX_FIELD_AUD_INF_CKS_ERR_CLR_BIT_SIZE              1

#define VRX_FIELD_AVI_INF_CKS_ERR_CLR_DEF                   0x0
#define VRX_FIELD_AVI_INF_CKS_ERR_CLR_BIT_SIZE              1

#define VRX_FIELD_RI_EXPIRED_B_CLR_DEF                      0x0
#define VRX_FIELD_RI_EXPIRED_B_CLR_BIT_SIZE                 1

#define VRX_FIELD_RI_EXPIRED_A_CLR_DEF                      0x0
#define VRX_FIELD_RI_EXPIRED_A_CLR_BIT_SIZE                 1

#define VRX_FIELD_AKSV_UPDATE_B_CLR_DEF                     0x0
#define VRX_FIELD_AKSV_UPDATE_B_CLR_BIT_SIZE                1

#define VRX_FIELD_AKSV_UPDATE_A_CLR_DEF                     0x0
#define VRX_FIELD_AKSV_UPDATE_A_CLR_BIT_SIZE                1

#define VRX_REG_IO_8BH_DEF                                  0x00
#define VRX_FIELD_MS_INF_CKS_ERR_MB2_DEF                    0x0
#define VRX_FIELD_MS_INF_CKS_ERR_MB2_BIT_SIZE               1

#define VRX_FIELD_SPD_INF_CKS_ERR_MB2_DEF                   0x0
#define VRX_FIELD_SPD_INF_CKS_ERR_MB2_BIT_SIZE              1

#define VRX_FIELD_AUD_INF_CKS_ERR_MB2_DEF                   0x0
#define VRX_FIELD_AUD_INF_CKS_ERR_MB2_BIT_SIZE              1

#define VRX_FIELD_AVI_INF_CKS_ERR_MB2_DEF                   0x0
#define VRX_FIELD_AVI_INF_CKS_ERR_MB2_BIT_SIZE              1

#define VRX_FIELD_RI_EXPIRED_B_MB2_DEF                      0x0
#define VRX_FIELD_RI_EXPIRED_B_MB2_BIT_SIZE                 1

#define VRX_FIELD_RI_EXPIRED_A_MB2_DEF                      0x0
#define VRX_FIELD_RI_EXPIRED_A_MB2_BIT_SIZE                 1

#define VRX_FIELD_AKSV_UPDATE_B_MB2_DEF                     0x0
#define VRX_FIELD_AKSV_UPDATE_B_MB2_BIT_SIZE                1

#define VRX_FIELD_AKSV_UPDATE_A_MB2_DEF                     0x0
#define VRX_FIELD_AKSV_UPDATE_A_MB2_BIT_SIZE                1

#define VRX_REG_IO_8CH_DEF                                  0x00
#define VRX_FIELD_MS_INF_CKS_ERR_MB1_DEF                    0x0
#define VRX_FIELD_MS_INF_CKS_ERR_MB1_BIT_SIZE               1

#define VRX_FIELD_SPD_INF_CKS_ERR_MB1_DEF                   0x0
#define VRX_FIELD_SPD_INF_CKS_ERR_MB1_BIT_SIZE              1

#define VRX_FIELD_AUD_INF_CKS_ERR_MB1_DEF                   0x0
#define VRX_FIELD_AUD_INF_CKS_ERR_MB1_BIT_SIZE              1

#define VRX_FIELD_AVI_INF_CKS_ERR_MB1_DEF                   0x0
#define VRX_FIELD_AVI_INF_CKS_ERR_MB1_BIT_SIZE              1

#define VRX_FIELD_RI_EXPIRED_B_MB1_DEF                      0x0
#define VRX_FIELD_RI_EXPIRED_B_MB1_BIT_SIZE                 1

#define VRX_FIELD_RI_EXPIRED_A_MB1_DEF                      0x0
#define VRX_FIELD_RI_EXPIRED_A_MB1_BIT_SIZE                 1

#define VRX_FIELD_AKSV_UPDATE_B_MB1_DEF                     0x0
#define VRX_FIELD_AKSV_UPDATE_B_MB1_BIT_SIZE                1

#define VRX_FIELD_AKSV_UPDATE_A_MB1_DEF                     0x0
#define VRX_FIELD_AKSV_UPDATE_A_MB1_BIT_SIZE                1

#define VRX_REG_IO_8DH_DEF                                  0x00
#define VRX_FIELD_BG_MEAS_DONE_RAW_DEF                      0x0
#define VRX_FIELD_BG_MEAS_DONE_RAW_BIT_SIZE                 1

#define VRX_FIELD_VS_INF_CKS_ERR_RAW_DEF                    0x0
#define VRX_FIELD_VS_INF_CKS_ERR_RAW_BIT_SIZE               1

#define VRX_REG_IO_8EH_DEF                                  0x00
#define VRX_FIELD_BG_MEAS_DONE_ST_DEF                       0x0
#define VRX_FIELD_BG_MEAS_DONE_ST_BIT_SIZE                  1

#define VRX_FIELD_VS_INF_CKS_ERR_ST_DEF                     0x0
#define VRX_FIELD_VS_INF_CKS_ERR_ST_BIT_SIZE                1

#define VRX_REG_IO_8FH_DEF                                  0x00
#define VRX_FIELD_BG_MEAS_DONE_CLR_DEF                      0x0
#define VRX_FIELD_BG_MEAS_DONE_CLR_BIT_SIZE                 1

#define VRX_FIELD_VS_INF_CKS_ERR_CLR_DEF                    0x0
#define VRX_FIELD_VS_INF_CKS_ERR_CLR_BIT_SIZE               1

#define VRX_REG_IO_90H_DEF                                  0x00
#define VRX_FIELD_BG_MEAS_DONE_MB2_DEF                      0x0
#define VRX_FIELD_BG_MEAS_DONE_MB2_BIT_SIZE                 1

#define VRX_FIELD_VS_INF_CKS_ERR_MB2_DEF                    0x0
#define VRX_FIELD_VS_INF_CKS_ERR_MB2_BIT_SIZE               1

#define VRX_REG_IO_91H_DEF                                  0x00
#define VRX_FIELD_BG_MEAS_DONE_MB1_DEF                      0x0
#define VRX_FIELD_BG_MEAS_DONE_MB1_BIT_SIZE                 1

#define VRX_FIELD_VS_INF_CKS_ERR_MB1_DEF                    0x0
#define VRX_FIELD_VS_INF_CKS_ERR_MB1_BIT_SIZE               1

#define VRX_REG_IO_92H_DEF                                  0x00
#define VRX_FIELD_CEC_RX_RDY2_RAW_DEF                       0x0
#define VRX_FIELD_CEC_RX_RDY2_RAW_BIT_SIZE                  1

#define VRX_FIELD_CEC_RX_RDY1_RAW_DEF                       0x0
#define VRX_FIELD_CEC_RX_RDY1_RAW_BIT_SIZE                  1

#define VRX_FIELD_CEC_RX_RDY0_RAW_DEF                       0x0
#define VRX_FIELD_CEC_RX_RDY0_RAW_BIT_SIZE                  1

#define VRX_FIELD_CEC_TX_RETRY_TIMEOUT_RAW_DEF              0x0
#define VRX_FIELD_CEC_TX_RETRY_TIMEOUT_RAW_BIT_SIZE         1

#define VRX_FIELD_CEC_TX_ARBITRATION_LOST_RAW_DEF           0x0
#define VRX_FIELD_CEC_TX_ARBITRATION_LOST_RAW_BIT_SIZE      1

#define VRX_FIELD_CEC_TX_READY_RAW_DEF                      0x0
#define VRX_FIELD_CEC_TX_READY_RAW_BIT_SIZE                 1

#define VRX_REG_IO_93H_DEF                                  0x00
#define VRX_FIELD_CEC_RX_RDY2_ST_DEF                        0x0
#define VRX_FIELD_CEC_RX_RDY2_ST_BIT_SIZE                   1

#define VRX_FIELD_CEC_RX_RDY1_ST_DEF                        0x0
#define VRX_FIELD_CEC_RX_RDY1_ST_BIT_SIZE                   1

#define VRX_FIELD_CEC_RX_RDY0_ST_DEF                        0x0
#define VRX_FIELD_CEC_RX_RDY0_ST_BIT_SIZE                   1

#define VRX_FIELD_CEC_TX_RETRY_TIMEOUT_ST_DEF               0x0
#define VRX_FIELD_CEC_TX_RETRY_TIMEOUT_ST_BIT_SIZE          1

#define VRX_FIELD_CEC_TX_ARBITRATION_LOST_ST_DEF            0x0
#define VRX_FIELD_CEC_TX_ARBITRATION_LOST_ST_BIT_SIZE       1

#define VRX_FIELD_CEC_TX_READY_ST_DEF                       0x0
#define VRX_FIELD_CEC_TX_READY_ST_BIT_SIZE                  1

#define VRX_REG_IO_94H_DEF                                  0x00
#define VRX_FIELD_CEC_RX_RDY2_CLR_DEF                       0x0
#define VRX_FIELD_CEC_RX_RDY2_CLR_BIT_SIZE                  1

#define VRX_FIELD_CEC_RX_RDY1_CLR_DEF                       0x0
#define VRX_FIELD_CEC_RX_RDY1_CLR_BIT_SIZE                  1

#define VRX_FIELD_CEC_RX_RDY0_CLR_DEF                       0x0
#define VRX_FIELD_CEC_RX_RDY0_CLR_BIT_SIZE                  1

#define VRX_FIELD_CEC_TX_RETRY_TIMEOUT_CLR_DEF              0x0
#define VRX_FIELD_CEC_TX_RETRY_TIMEOUT_CLR_BIT_SIZE         1

#define VRX_FIELD_CEC_TX_ARBITRATION_LOST_CLR_DEF           0x0
#define VRX_FIELD_CEC_TX_ARBITRATION_LOST_CLR_BIT_SIZE      1

#define VRX_FIELD_CEC_TX_READY_CLR_DEF                      0x0
#define VRX_FIELD_CEC_TX_READY_CLR_BIT_SIZE                 1

#define VRX_REG_IO_95H_DEF                                  0x00
#define VRX_FIELD_CEC_RX_RDY2_MB2_DEF                       0x0
#define VRX_FIELD_CEC_RX_RDY2_MB2_BIT_SIZE                  1

#define VRX_FIELD_CEC_RX_RDY1_MB2_DEF                       0x0
#define VRX_FIELD_CEC_RX_RDY1_MB2_BIT_SIZE                  1

#define VRX_FIELD_CEC_RX_RDY0_MB2_DEF                       0x0
#define VRX_FIELD_CEC_RX_RDY0_MB2_BIT_SIZE                  1

#define VRX_FIELD_CEC_TX_RETRY_TIMEOUT_MB2_DEF              0x0
#define VRX_FIELD_CEC_TX_RETRY_TIMEOUT_MB2_BIT_SIZE         1

#define VRX_FIELD_CEC_TX_ARBITRATION_LOST_MB2_DEF           0x0
#define VRX_FIELD_CEC_TX_ARBITRATION_LOST_MB2_BIT_SIZE      1

#define VRX_FIELD_CEC_TX_READY_MB2_DEF                      0x0
#define VRX_FIELD_CEC_TX_READY_MB2_BIT_SIZE                 1

#define VRX_REG_IO_96H_DEF                                  0x00
#define VRX_FIELD_CEC_RX_RDY2_MB1_DEF                       0x0
#define VRX_FIELD_CEC_RX_RDY2_MB1_BIT_SIZE                  1

#define VRX_FIELD_CEC_RX_RDY1_MB1_DEF                       0x0
#define VRX_FIELD_CEC_RX_RDY1_MB1_BIT_SIZE                  1

#define VRX_FIELD_CEC_RX_RDY0_MB1_DEF                       0x0
#define VRX_FIELD_CEC_RX_RDY0_MB1_BIT_SIZE                  1

#define VRX_FIELD_CEC_TX_RETRY_TIMEOUT_MB1_DEF              0x0
#define VRX_FIELD_CEC_TX_RETRY_TIMEOUT_MB1_BIT_SIZE         1

#define VRX_FIELD_CEC_TX_ARBITRATION_LOST_MB1_DEF           0x0
#define VRX_FIELD_CEC_TX_ARBITRATION_LOST_MB1_BIT_SIZE      1

#define VRX_FIELD_CEC_TX_READY_MB1_DEF                      0x0
#define VRX_FIELD_CEC_TX_READY_MB1_BIT_SIZE                 1

#define VRX_REG_IO_97H_DEF                                  0x00
#define VRX_FIELD_CEC_INTERRUPT_BYTE_DEF                    0x0
#define VRX_FIELD_CEC_INTERRUPT_BYTE_BIT_SIZE               8

#define VRX_REG_IO_98H_DEF                                  0x00
#define VRX_FIELD_CEC_INTERRUPT_BYTE_ST_DEF                 0x0
#define VRX_FIELD_CEC_INTERRUPT_BYTE_ST_BIT_SIZE            8

#define VRX_REG_IO_99H_DEF                                  0x00
#define VRX_FIELD_CEC_INTERRUPT_BYTE_CLR_DEF                0x0
#define VRX_FIELD_CEC_INTERRUPT_BYTE_CLR_BIT_SIZE           8

#define VRX_REG_IO_9AH_DEF                                  0x00
#define VRX_FIELD_CEC_INTERRUPT_BYTE_MB2_DEF                0x0
#define VRX_FIELD_CEC_INTERRUPT_BYTE_MB2_BIT_SIZE           8

#define VRX_REG_IO_9BH_DEF                                  0x00
#define VRX_FIELD_CEC_INTERRUPT_BYTE_MB1_DEF                0x0
#define VRX_FIELD_CEC_INTERRUPT_BYTE_MB1_BIT_SIZE           8

#define VRX_REG_IO_BFH_DEF                                  0x00
#define VRX_FIELD_CP_COMPLETE_BYPASS_IN_HDMI_MODE_DEF       0x0
#define VRX_FIELD_CP_COMPLETE_BYPASS_IN_HDMI_MODE_BIT_SIZE  1

#define VRX_REG_IO_D6H_DEF                                  0x00
#define VRX_FIELD_PIN_CHECKER_EN_DEF                        0x0
#define VRX_FIELD_PIN_CHECKER_EN_BIT_SIZE                   1

#define VRX_REG_IO_D7H_DEF                                  0x00
#define VRX_FIELD_PIN_CHECKER_VAL_DEF                       0x0
#define VRX_FIELD_PIN_CHECKER_VAL_BIT_SIZE                  8

#define VRX_REG_IO_DDH_DEF                                  0x00
#define VRX_FIELD_MAN_OP_CLK_SEL_EN_DEF                     0x0
#define VRX_FIELD_MAN_OP_CLK_SEL_EN_BIT_SIZE                1

#define VRX_FIELD_MAN_OP_CLK_SEL_DEF                        0x0
#define VRX_FIELD_MAN_OP_CLK_SEL_BIT_SIZE                   3

#define VRX_REG_IO_E0H_DEF                                  0x00
#define VRX_FIELD_DS_WITHOUT_FILTER_DEF                     0x0
#define VRX_FIELD_DS_WITHOUT_FILTER_BIT_SIZE                1

#define VRX_REG_IO_EAH_DEF                                  0x00
#define VRX_REG_IO_EBH_DEF                                  0x00
#define VRX_FIELD_RD_INFO_DEF                               0x0
#define VRX_FIELD_RD_INFO_BIT_SIZE                          16

#define VRX_REG_IO_F4H_DEF                                  0x00
#define VRX_FIELD_CEC_SLAVE_ADDR_DEF                        0x0
#define VRX_FIELD_CEC_SLAVE_ADDR_BIT_SIZE                   7

#define VRX_REG_IO_F5H_DEF                                  0x00
#define VRX_FIELD_INFOFRAME_SLAVE_ADDR_DEF                  0x0
#define VRX_FIELD_INFOFRAME_SLAVE_ADDR_BIT_SIZE             7

#define VRX_REG_IO_F8H_DEF                                  0x00
#define VRX_FIELD_DPLL_SLAVE_ADDR_DEF                       0x0
#define VRX_FIELD_DPLL_SLAVE_ADDR_BIT_SIZE                  7

#define VRX_REG_IO_F9H_DEF                                  0x00
#define VRX_FIELD_KSV_SLAVE_ADDR_DEF                        0x0
#define VRX_FIELD_KSV_SLAVE_ADDR_BIT_SIZE                   7

#define VRX_REG_IO_FAH_DEF                                  0x00
#define VRX_FIELD_EDID_SLAVE_ADDR_DEF                       0x0
#define VRX_FIELD_EDID_SLAVE_ADDR_BIT_SIZE                  7

#define VRX_REG_IO_FBH_DEF                                  0x00
#define VRX_FIELD_HDMI_SLAVE_ADDR_DEF                       0x0
#define VRX_FIELD_HDMI_SLAVE_ADDR_BIT_SIZE                  7

#define VRX_REG_IO_FDH_DEF                                  0x00
#define VRX_FIELD_CP_SLAVE_ADDR_DEF                         0x0
#define VRX_FIELD_CP_SLAVE_ADDR_BIT_SIZE                    7

#define VRX_REG_IO_FFH_DEF                                  0x00
#define VRX_FIELD_MAIN_RESET_DEF                            0x0
#define VRX_FIELD_MAIN_RESET_BIT_SIZE                       1

#endif
