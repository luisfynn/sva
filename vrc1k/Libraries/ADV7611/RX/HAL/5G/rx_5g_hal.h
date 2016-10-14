/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#ifndef _RX_5G_HAL_H_
#define _RX_5G_HAL_H_
#if ((RX_DEVICE == 7612) || (RX_DEVICE == 7611) || (RX_DEVICE == 7619))

#define TMDSFRAQ_SHIFT                          0
#define CEC_CFG02_REV_2                         1



enum                                            /* Audio unmute delays */
{
    RX_AUD_UNMUTE_AFTER_0MS,
    RX_AUD_UNMUTE_AFTER_250MS,
    RX_AUD_UNMUTE_AFTER_500MS,
    RX_AUD_UNMUTE_AFTER_750MS,
    RX_AUD_UNMUTE_AFTER_1000MS
};


/*==========================================
 * 3G to - 5G Direct Mapping
 *=========================================*/
#define VRX_DPLL_MAP_ADDR                       VRX_AFE_DPLL_MAP_ADDR
#define VRX_is_INTERLACED_HDMI_true             VRX_is_HDMI_INTERLACED_true
#define VRX_get_FIELD_0_HEIGHT                  VRX_get_FIELD0_HEIGHT
#define VRX_get_FIELD_1_HEIGHT                  VRX_get_FIELD1_HEIGHT
#define VRX_set_SDP_MAIN_RESET              
#define VRX_set_NEW_TMDS_PARAM(a)               VRX_set_NEW_VS_PARAM(a)

#define VRX_is_INT2_EN_true()                   VRX_ret_INTRQ2_MUX_SEL()
#define VRX_set_INT2_EN(val)                    VRX_set_INTRQ2_MUX_SEL(val)
#define VRX_set_INTRQ2_OP_SEL(a)                VRX_set_INT2_POL(a)
#define VRX_set_INTRQ1_OP_SEL                   VRX_set_INTRQ_OP_SEL
#define VRX_set_EN_MUTE_OUT_INTRQ(a)            VRX_set_EN_UMASK_RAW_INTRQ(a)
#define VRX_is_EN_MUTE_OUT_INTRQ_true()         VRX_is_EN_UMASK_RAW_INTRQ_true()
#define VRX_set_EN_MUTE_OUT_INTRQ2(a)           VRX_set_EN_UMASK_RAW_INTRQ2(a)
#define VRX_is_EN_MUTE_OUT_INTRQ2_true()        VRX_is_EN_UMASK_RAW_INTRQ2_true()

#define VRX_set_SPA_PORT_1                      VRX_set_SPA_PORT_B
#define VRX_set_SPA_PORT_2                      VRX_set_SPA_PORT_C
#define VRX_set_SPA_PORT_3                      VRX_set_SPA_PORT_D
#define VRX_ret_SPA_PORT_1                      VRX_ret_SPA_PORT_B
#define VRX_ret_SPA_PORT_2                      VRX_ret_SPA_PORT_C
#define VRX_ret_SPA_PORT_3                      VRX_ret_SPA_PORT_D

/*==========================================
 * ADV7623- 5G Devices Direct Mapping
 *=========================================*/
#define VRX_set_HPD_MANUAL(a)                   VRX_set_HPA_MANUAL(a)


/*==========================================
 * Non- Supported Regs on 5G Devices
 *=========================================*/







/*====================================================================
 * For all Port C and Port D query macros should return FALSe
 * All configuration macros shoul do nothing
 *====================================================================*/
#define VRX_is_CABLE_DET_C_RAW_true()           0x0
#define VRX_is_CABLE_DET_D_RAW_true()           0x0
#define VRX_is_TMDS_CLK_C_RAW_true()            0x0
#define VRX_is_TMDS_CLK_D_RAW_true()            0x0
#define VRX_ret_AKSV_UPDATE_C_RAW()             0x0
#define VRX_ret_AKSV_UPDATE_D_RAW()             0x0
#define VRX_ret_HDMI_ENCRPT_C_RAW()             0x0
#define VRX_ret_HDMI_ENCRPT_D_RAW()             0x0
#define VRX_ret_HPA_STATUS_PORT_C()             0x0
#define VRX_ret_HPA_STATUS_PORT_D()             0x0
#define VRX_ret_TMDSPLL_LCK_C_RAW()             0x0
#define VRX_ret_TMDSPLL_LCK_D_RAW()             0x0

#define VRX_ret_HPA_MAN_VALUE_C(a)              0x0   
#define VRX_ret_HPA_MAN_VALUE_D(a)              0x0
#define VRX_set_HPA_MAN_VALUE_C(a)              
#define VRX_set_HPA_MAN_VALUE_D(a)              

#define VRX_set_SPA_PORT_C(a)                   
#define VRX_set_SPA_PORT_D(a)                   
#define VRX_ret_SPA_PORT_C()                    0x0
#define VRX_ret_SPA_PORT_D()                    0x0

/* ------------ Repeater Map ----------- */
#define VRX_BIT_EDID_C_ENABLE                   0x0
#define VRX_BIT_EDID_D_ENABLE                   0x0

/* ------------ hdmi Map ----------- */
#define VRX_ret_CLOCK_TERMC_DISABLE()           0x0
#define VRX_ret_CLOCK_TERMD_DISABLE()           0x0
#define VRX_set_CLOCK_TERMC_DISABLE(a)          
#define VRX_set_CLOCK_TERMD_DISABLE(a)          
#define VRX_set_EN_BG_PORT_C(val)              
#define VRX_set_EN_BG_PORT_D(val)               

/*====================================================================
 * For the Rx and CP status APIs the 
 *     - Macrovision Status
 *     - STDI 2 Status
 * Must return FALSE as these blocks are not available
 *====================================================================*/
#define VRX_is_MV_AGC_DET_true()                FALSE
#define VRX_is_MV_PS_DET_true()                 FALSE
#define VRX_is_CP_UNLOCK_CH2_RAW_true()         FALSE

/*====================================================================
 * ALL VGA support not supported on 5G devices
 *====================================================================*/
#define HAL_RxEnInternalVgaEdid(a,b)            (ATVERR_NOT_AVAILABLE)
/*====================================================================
 * ALL HEAC APIs are not suppoted on 5G Devices
 *====================================================================*/
#define HAL_RxHdmiSetArcMode(a,b)                 (ATVERR_NOT_AVAILABLE)
#define HAL_RxHdmiSetEthernetPath(a,b,c)        (ATVERR_NOT_AVAILABLE)
#define HAL_RxCpSetSignalPolarity(a, b)         (ATVERR_NOT_AVAILABLE)
#define HAL_RxSetAudioPassThrough(a)            (ATVERR_NOT_AVAILABLE)
#define HAL_RxCpRouteSyncToSyncCh (a, b, c, d)  (ATVERR_NOT_AVAILABLE)
/*====================================================================
 * The Following SPI Edid APIs are not supported on 5G Devices
 *===================================================================*/

#define HAL_RxEdidCfgSpiInterface(a,b)  (ATVERR_NOT_AVAILABLE)
#define HAL_RxEdidCfgSpiHeader(a)  (ATVERR_NOT_AVAILABLE)
/*====================================================================
 * VDP SPI Interface is not supported on 5G Devices
 *===================================================================*/
#define HAL_RxVdpCfgSpiInterface(a,b)              (ATVERR_NOT_AVAILABLE) 
/*====================================================================
 * All SDP APIs not supported on 5G Devices 
 *===================================================================*/
#define HAL_RxSdpSetEnabledEvents(a,b,c)
#define HAL_RxVdpSetEnabledEvents(a,b,c)
#define HAL_RxMvSetEnabledEvents(a,b,c)
#define HAL_RxSdpHouseKeeping()
#define HAL_RXLIB_SdpIsr()                      (ATVERR_OK)
#define HAL_RXLIB_VdpIsr()                      (ATVERR_OK)
#define HAL_RXLIB_MvIsr()                      (ATVERR_OK)
#define HAL_SetSdp861RecSettings(a,b,c)         (ATVERR_NOT_AVAILABLE)

/*====================================================================
 * All DPP Filtering APIs are not supported on 5G Devices
 *===================================================================*/
#define HAL_RxDppEnDcmStageManMode(a)           (ATVERR_NOT_AVAILABLE) 
#define HAL_RxDppEnDppStageManMode(a)           (ATVERR_NOT_AVAILABLE)
#define HAL_RxDppEnChromaFiltManMode(a)         (ATVERR_NOT_AVAILABLE)
#define HAL_RxDppSetDcmResponse(a)              (ATVERR_NOT_AVAILABLE) 
#define HAL_RxDppSetDppResponse(a)              (ATVERR_NOT_AVAILABLE)
#define HAL_RxDppSetDppCoeffs(a,b)              (ATVERR_NOT_AVAILABLE)
#define HAL_RxDppSetChromaResponse(a)           (ATVERR_NOT_AVAILABLE)
#define HAL_RxDppSetChromaBandwidth(a)          (ATVERR_NOT_AVAILABLE)


/*====================================================================
 * All Video Output Mux APIs are not supported on 5G Devices
 *===================================================================*/
#define HAL_RxAfeSetVideoOutMux(a, b)              (ATVERR_NOT_AVAILABLE)
/*====================================================================
 * All Audio Codec APIs are not supported on 5G Devices
 *===================================================================*/
#define HAL_RxCdecHouseKeeping ()
#define HAL_RxCdecConfig(a)                         (ATVERR_NOT_AVAILABLE)
#define HAL_RxCdecRouteAudInToTx(a,b)                 (ATVERR_NOT_AVAILABLE)
#define HAL_RxCdecRouteAudInToAudLoopback(a,b,c)    (ATVERR_NOT_AVAILABLE)
#define HAL_RxCdecConfigAudioOut(a,b)             (ATVERR_NOT_AVAILABLE)
#define HAL_RxCdecSetVolume(a,b)                    (ATVERR_NOT_AVAILABLE)
#define HAL_RxCdecSetMute(a,b)                      (ATVERR_NOT_AVAILABLE)
/*====================================================================
 * VDP SPI Interface is not supported on 5G Devices
 *===================================================================*/
#define HAL_RxVdpCfgSpiInterface(a,b)              (ATVERR_NOT_AVAILABLE) 
#define HAL_RxVdpEnFastI2cInterface(a)				(ATVERR_NOT_AVAILABLE) 
/*====================================================================
 * To be added to 5G Macro libraries
 *====================================================================*/
#define VRX_set_NEW_VS_PARAM(val)               ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x4C, 0x04, 0x2, val)
#define VRX_set_TMDSPLL_GEAR_MON(val)           ATV_I2CWriteField8(VRX_HDMI_MAP_ADDR, 0x3D, 0x10, 0x4, val)

#define VRX_is_CH1_SSPD_DVALID_true()           ATV_I2CIsField8(VRX_CP_MAP_ADDR, 0xB5, 0x80, 0x7)
#define VRX_get_CH1_SSPD_DVALID(pval)           ATV_I2CGetField8(VRX_CP_MAP_ADDR, 0xB5, 0x80, 0x7, pval)
#define VRX_ret_CH1_SSPD_DVALID()               ATV_I2CReadField8(VRX_CP_MAP_ADDR, 0xB5, 0x80, 0x7)
#define VRX_set_audio_core_pdn(val)             ATV_I2CWriteField8(VRX_AFE_DPLL_MAP_ADDR, 0xC3, 0x20, 0x5, val)

#endif
#endif
