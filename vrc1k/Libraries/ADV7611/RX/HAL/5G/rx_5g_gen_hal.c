/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

/*============================================================================
 * This file contains all functions that are chip-specific
 *
 *===========================================================================*/
#include "rx_lib.h"

#if (RX_DEVICE == 7612 || RX_DEVICE == 7611|| RX_DEVICE == 7619) 

#include "rx_cfg.h"
#include "rx_isr.h"

/*======================================================================
 * ADV7844 Primary Mode & Video Standard Details 
 *======================================================================*/
#define RX_VFRQ_24_VAL            0x4
#define RX_VFRQ_25_VAL            0x3     
#define RX_VFRQ_30_VAL            0x2
#define RX_VFRQ_50_VAL            0x1
#define RX_VFRQ_60_VAL            0x0
#define RX_HDMI_TBL_SIZE          25
#define RX_HDMI_CMP_PM            0x5
#define RX_HDMI_GR_PM             0x6
#define RX_NOT_SUP                0xFF
#define RX_OS_NOT_SUP             0xFF
#define RX_FREQ_NOT_SUP           0xFF
#define RX_NO_CMP_FREQ            {FALSE,FALSE,FALSE,FALSE,FALSE}
#define RX_NO_CMP_VIDSTD          {RX_NOT_SUP,RX_NOT_SUP,RX_NOT_SUP,RX_NOT_SUP,RX_NOT_SUP} 
#define RX_NO_GR_VIDSTD           {RX_NOT_SUP,RX_NOT_SUP,RX_NOT_SUP,RX_NOT_SUP,RX_NOT_SUP, RX_NOT_SUP}



/*=======================================================================
 * Local constants
 *======================================================================*/


STATIC CONSTANT RX_HDMI_VIDSTD_INFO HdmiVidStdTable[RX_HDMI_TBL_SIZE ] =
{    {RX_HDMI_GR_PM,  RX_SVGA,          {0x0,0x1,RX_OS_NOT_SUP,0x2,0x3,0x4},RX_NO_CMP_VIDSTD ,RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_SXGA,          {RX_FREQ_NOT_SUP,0x5,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x6,RX_FREQ_NOT_SUP},RX_NO_CMP_VIDSTD, RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_VGA,           {RX_FREQ_NOT_SUP,0x8,RX_FREQ_NOT_SUP,0x9,0xA,0xB},RX_NO_CMP_VIDSTD,RX_NO_CMP_FREQ},
     {RX_HDMI_GR_PM,  RX_XGA,           {RX_FREQ_NOT_SUP,0xC,0xD,RX_OS_NOT_SUP,0xE,0xF},RX_NO_CMP_VIDSTD,RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_WXGA,          {RX_FREQ_NOT_SUP,0x10,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP},RX_NO_CMP_VIDSTD, RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_WXGAR,         {RX_FREQ_NOT_SUP,0x11,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP}, RX_NO_CMP_VIDSTD,RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_WXGA_1360,     {RX_FREQ_NOT_SUP,0x12,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP},RX_NO_CMP_VIDSTD, RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_WXGA_1366,     {RX_FREQ_NOT_SUP,0x13,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP},RX_NO_CMP_VIDSTD, RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_SXGA_PLUS,     {RX_FREQ_NOT_SUP,0x14,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x15,RX_FREQ_NOT_SUP},   RX_NO_CMP_VIDSTD,RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_UXGA,          {RX_FREQ_NOT_SUP,0x16,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x15,RX_FREQ_NOT_SUP}, RX_NO_CMP_VIDSTD,RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_UXGAR,         {RX_FREQ_NOT_SUP,0x17,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x15,RX_FREQ_NOT_SUP}, RX_NO_CMP_VIDSTD,RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_WSXGA,         {RX_FREQ_NOT_SUP,0x18,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x15,RX_FREQ_NOT_SUP}, RX_NO_CMP_VIDSTD,RX_NO_CMP_FREQ },
     {RX_HDMI_GR_PM,  RX_WUXGA,         {RX_FREQ_NOT_SUP,0x19,RX_FREQ_NOT_SUP,RX_FREQ_NOT_SUP,0x15,RX_FREQ_NOT_SUP}, RX_NO_CMP_VIDSTD,RX_NO_CMP_FREQ },
     {RX_HDMI_CMP_PM, RX_525I,          RX_NO_GR_VIDSTD,{0x0 ,0x2,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}}, 
     {RX_HDMI_CMP_PM, RX_625I,          RX_NO_GR_VIDSTD,{0x1,0x3,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,TRUE,FALSE}},
     {RX_HDMI_CMP_PM, RX_525P,          RX_NO_GR_VIDSTD,{0x0A,0xC,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
     {RX_HDMI_CMP_PM, RX_625P,          RX_NO_GR_VIDSTD,{0x0B,0xD,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,TRUE,FALSE}},
     {RX_HDMI_CMP_PM, RX_720P,          RX_NO_GR_VIDSTD,{0x13,0x19,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,TRUE,TRUE,TRUE}},
     {RX_HDMI_CMP_PM, RX_1125I_274M,    RX_NO_GR_VIDSTD,{0x14,0x1A,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,TRUE,TRUE}},
     {RX_HDMI_CMP_PM, RX_1125I_240M,    RX_NO_GR_VIDSTD,{0x15,0x1B,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
     {RX_HDMI_CMP_PM, RX_1250I_295M,    RX_NO_GR_VIDSTD,{0x16,0x1C,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
     {RX_HDMI_CMP_PM, RX_1920I_1152,    RX_NO_GR_VIDSTD,{0x17,0x1D,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
     {RX_HDMI_CMP_PM, RX_1125P_274M,    RX_NO_GR_VIDSTD,{0x1E,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{TRUE,TRUE,TRUE,TRUE,TRUE}},
     {RX_HDMI_CMP_PM, RX_1250P_295M,    RX_NO_GR_VIDSTD,{0x1F,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
     {RX_HDMI_CMP_PM, RX_1125P_RB,      RX_NO_GR_VIDSTD,{0x34,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP,RX_OS_NOT_SUP},{FALSE,FALSE,FALSE,FALSE,TRUE}},
};

STATIC CONSTANT UCHAR RxCeaId00RecSettingTable[] = 
{
    /*===============================
     * recommended sync 
     * adjustment settings
     * for 861 Vid = 0
     *==============================*/
    RX_I2C_CP_MAP_ADDR, 0x7C, 0xC0,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x7D, 0x00,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x7F, 0x00,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8B, 0x40,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8C, 0x00,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8B, 0x40,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8D, 0x00,     /*Default value*/
    RX_I2C_CP_MAP_ADDR, 0x8E, 0x00,     /*Default value*/
    0
};

/*===============================================
 * Local Function Prototypes
 *==============================================*/
void RxSetSpecificResCnfg(UINT8 PrimMode, RX_VID_RES Res );
BOOL RxGetHdmiVidStdCfg(UINT8 Index, RX_VRT_FRQ Freq, RX_OS_RATE OvrSmplng, UINT8* VidStd, UINT8* VFreq);


/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetManagePowerDown(RX_CHIP_SECTION Section, RX_PWRDN_MODE PowerDownMode)
{
    return (ATVERR_FAILED);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetChipReset(RX_CHIP_SECTION Section)
{
    ATV_ERR ErrVal = ATVERR_OK;

    switch (Section)
    {
        case RX_ALL_SECTIONS:
            VRX_set_MAIN_RESET(0x1);
            break;
        case RX_EDID_REP_MPU:
            VRX_set_HDCP_REPT_EDID_RESET(0x1);
            break;
        case RX_CEC_CTRL:
            VRX_set_CEC_SOFT_RESET(0x1);
            break;
        default:
            ErrVal = ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetPinFunction(RX_PIN PinId, RX_PIN_FUNCTION PinFunction)
{
    ATV_ERR ErrVal = ATVERR_OK;

    switch(PinId)
    {
        case RX_VS_OUT_PIN:
            switch(PinFunction)
            {
               case RX_VS_SIG:
                    VRX_set_VS_OUT_SEL(0x1);
                    break;
               case RX_FIELD_SIG:
                    VRX_set_VS_OUT_SEL(0x0);
                    break;
               default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
       
   
       case RX_DE_OUT_PIN:
            switch(PinFunction)
            {
                case RX_DE_SIG:
                    VRX_set_F_OUT_SEL(0x0);
                    break;
                case RX_FIELD_SIG:
                    VRX_set_F_OUT_SEL(0x1);
                    break;
                    default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
       
       case RX_FIELD_OUT_PIN:
            switch(PinFunction)
            {
                case RX_DE_SIG:
                    VRX_set_F_OUT_SEL(0x0);
                    break;
                case RX_FIELD_SIG:
                    VRX_set_F_OUT_SEL(0x1);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_MCLK_PIN:
            switch(PinFunction)
            {
                case RX_MCLK_SIG:
                    VRX_set_INTRQ2_MUX_SEL(0x0);
                    break;
                case RX_INT_SIG:
                    VRX_set_INTRQ2_MUX_SEL(0x1);
                    VRX_set_EN_MUTE_OUT_INTRQ2(0x0);
                    break;
                 case RX_AUDIO_MUTE_SIG:
                    VRX_set_EN_MUTE_OUT_INTRQ2(0x1);
                    VRX_set_INTRQ2_MUX_SEL(0x1);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_SCLK_PIN:
            switch(PinFunction)
            {
                case RX_SCLK_SIG:
                    VRX_set_INTRQ2_MUX_SEL(0x0);
                    break;
                /* 7619 doesn't use the SCLK as INT2, correct this later. kfkfkf */ 
                case RX_INT_SIG:
                    VRX_set_INTRQ2_MUX_SEL(0x2);
                    VRX_set_EN_MUTE_OUT_INTRQ2(0x0);
                    break;
                 case RX_AUDIO_MUTE_SIG:
                    VRX_set_EN_MUTE_OUT_INTRQ2(0x2);
                    VRX_set_INTRQ2_MUX_SEL(0x1);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
         case RX_HPA_A_PIN:
            switch(PinFunction)
            {
                case RX_HP_SIG:
                    VRX_set_INTRQ2_MUX_SEL(0x0);
                    break;
                case RX_INT_SIG:
                    VRX_set_INTRQ2_MUX_SEL(0x3);
                    VRX_set_EN_MUTE_OUT_INTRQ2(0x0);
                    break;
                 case RX_AUDIO_MUTE_SIG:
                    VRX_set_EN_MUTE_OUT_INTRQ2(0x3);
                    VRX_set_INTRQ2_MUX_SEL(0x1);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_INT1_OUT_PIN:
            switch(PinFunction)
            {                
                 case RX_AUDIO_MUTE_SIG:
                    VRX_set_EN_MUTE_OUT_INTRQ(0x1);
                    break;
                default:
                    break;
            }
            break;
        case RX_CABLE_DET_PINS:
            switch(PinFunction)
            {
                case RX_DISABLE_PIN:
                    VRX_set_FILT_5V_DET_DIS(0x1);
                    break;
                case RX_ENABLE_PIN:
                    VRX_set_FILT_5V_DET_DIS(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        default:
            ErrVal = ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);        
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetTristatePin(RX_PIN Pin, BOOL Tristate)
{
    ATV_ERR ErrVal = ATVERR_OK;
    switch (Pin)
    {
        case RX_LLC_OUT_PIN:
            switch(Tristate)
            {
                case TRUE:
                    VRX_set_TRI_LLC(0x1);
                    break;
                case FALSE:
                    VRX_set_TRI_LLC(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_PIX_OUT_PINS:
            switch(Tristate)
            {
                case TRUE:
                    VRX_set_TRI_PIX(0x1);
                    break;
                case FALSE:
                    VRX_set_TRI_PIX(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_SYNC_OUT_PINS:
            switch(Tristate)
            {
                case TRUE:
                    VRX_set_TRI_SYNCS(0x1);
                    break;
                case FALSE:
                    VRX_set_TRI_SYNCS(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        case RX_AUD_OUT_PINS:
            switch(Tristate)
            {
                case TRUE:
                    VRX_set_TRI_AUDIO(0x1); 
                    break;
                case FALSE:
                    VRX_set_TRI_AUDIO(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        
        case RX_OUT_PINS:
            switch(Tristate)
            {
                case TRUE:
                    VRX_set_TRI_AUDIO(0x1); 
                    VRX_set_TRI_SYNCS(0x1);
                    VRX_set_TRI_PIX(0x1);
                    VRX_set_TRI_LLC(0x1);
                    
                    break;
                case FALSE:
                    VRX_set_TRI_AUDIO(0x0);
                    VRX_set_TRI_SYNCS(0x0);
                    VRX_set_TRI_PIX(0x0);
                    VRX_set_TRI_LLC(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
        default:
            ErrVal = ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);
}
/*==========================================================================
 * 
 * 
 *
 *=========================================================================*/
ATV_ERR HAL_RxSetPixelClkFreq (RX_PIX_CLK_FREQ PixClkFreq, BOOL Enable)
{
    ATV_ERR ErrVal = ATVERR_OK;
   

    switch (PixClkFreq)
    {
        
        case RX_2X_CLK:
          if (Enable)
          {
             VRX_set_LLC_DLL_MUX(1);
             VRX_set_LLC_DLL_EN(1);
             VRX_set_LLC_DLL_DOUBLE(1);
           }
           else
           { 
              VRX_set_LLC_DLL_DOUBLE(0);
            }
            break;
       
        default:
            
            ErrVal = ATVERR_INV_PARM;
            break;
    }        
    return (ErrVal);
}
/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetPinPolarity(RX_PIN Pin, BOOL PosPolarity)
{
    ATV_ERR ErrVal;
    ErrVal = ATVERR_OK;
    switch(Pin)
    {
        case RX_VS_OUT_PIN:
            switch(PosPolarity)
            {
                case TRUE:
                    VRX_set_INV_VS_POL(0x1);
                    break;
                case FALSE:
                    VRX_set_INV_VS_POL(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
       case RX_HS_OUT_PIN:
            switch(PosPolarity)
            {
                case TRUE:
                    VRX_set_INV_HS_POL(0x1);
                    break;
                case FALSE:
                    VRX_set_INV_HS_POL(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
       case RX_DE_OUT_PIN:
            switch(PosPolarity)
            {
                case TRUE:
                    VRX_set_INV_F_POL(0x1);
                    break;
                case FALSE:
                    VRX_set_INV_F_POL(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
       case RX_FIELD_OUT_PIN:
            switch(PosPolarity)
            {
                case TRUE:
                    VRX_set_INV_F_POL(0x1);
                    break;
                case FALSE:
                    VRX_set_INV_F_POL(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;
       case RX_LLC_OUT_PIN:
            switch(PosPolarity)
            {
                case TRUE:
                    VRX_set_INV_LLC_POL(0x1);
                    break;
                case FALSE:
                    VRX_set_INV_LLC_POL(0x0);
                    break;
                default:
                    ErrVal = ATVERR_INV_PARM;
                    break;
            }
            break;       
        default:
            ErrVal = ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_ConfigInt(RX_PIN IntPin, RX_INT_DURATION Duration, RX_PIN_LEVEL PinLevel)
{
    ATV_ERR ErrVal;
    UINT8 TmpDur;
    UINT8 TmpLevel;
    ErrVal = ATVERR_OK;
    switch(Duration)
    {
       case RX_3_XTAL_CLK:
            TmpDur = 0x0;
            break;
       case RX_15_XTAL_CLK:
            TmpDur = 0x1;
            break;
       case RX_63_XTAL_CLK:
            TmpDur = 0x2;
            break;
       case RX_ACT_UNTIL_CLR:
            TmpDur = 0x3;
            break;
       default:
            ErrVal = ATVERR_INV_PARM;
            return (ErrVal);
    }
   
     switch(IntPin)
     {
        case RX_INT1_OUT_PIN:
             VRX_set_INTRQ_DUR_SEL(TmpDur);    
             switch(PinLevel)
             {
                   case RX_OPEN_DRAIN:
                        TmpLevel = 0x0;
                        break;
                   case RX_LOW_LEVEL:
                        TmpLevel = 0x1;
                        break;
                   case RX_HIGH_LEVEL:
                        TmpLevel = 0x2;
                        break;
                    default:
                        ErrVal = ATVERR_INV_PARM;
                        return (ErrVal);
             }
             VRX_set_INTRQ1_OP_SEL(TmpLevel);
             break;
        case RX_INT2_OUT_PIN:
             VRX_set_INTRQ2_DUR_SEL(TmpDur);
              switch(PinLevel)
             {
                   case RX_LOW_LEVEL:
                         TmpLevel = 0x1;
                        break;
                   case RX_HIGH_LEVEL:
                        TmpLevel = 0x0;
                        break;
                    default:
                        ErrVal = ATVERR_INV_PARM;
                        return (ErrVal);
             }
             VRX_set_INTRQ2_OP_SEL(TmpLevel);
             break;
        default:
             ErrVal = ATVERR_INV_PARM;
             break;
     }
     return (ErrVal);
    
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_ForceIntLevel(RX_PIN IntPin, BOOL ForceLevel)
{
    ATV_ERR ErrVal = ATVERR_OK;

    if(ForceLevel)
    {
        switch(IntPin)
        {
            case RX_INT1_OUT_PIN:
                VRX_set_MPU_STIM_INTRQ_MB1(0x1);
                break;
            case RX_INT2_OUT_PIN:
                VRX_set_MPU_STIM_INTRQ_MB2(0x1);
                break;
            default:
                ErrVal = ATVERR_INV_PARM;
                return (ErrVal);
        }
        VRX_set_MPU_STIM_INTRQ(0x1);
    }
    else
    {
        switch(IntPin)
        {
            case RX_INT1_OUT_PIN:
                VRX_set_MPU_STIM_INTRQ_MB1(0x0);
                break;
            case RX_INT2_OUT_PIN:
                VRX_set_MPU_STIM_INTRQ_MB2(0x0);
                break;
            default:
                ErrVal = ATVERR_INV_PARM;
                return (ErrVal);
        }
        VRX_set_MPU_STIM_INTRQ(0x0);
    }
    return (ErrVal);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetDriveStrength(RX_PIN PinId,  RX_OP_DR_STR DriveLevel)
{
    ATV_ERR ErrVal = ATVERR_OK;
    UINT8 TmpDrStrngth;
    
    switch(DriveLevel)
    {
        case RX_DR_STR_2X :
             TmpDrStrngth =0x1;
             break;           
        case RX_DR_STR_3X:
            TmpDrStrngth =0x2;
             break;      
        case RX_DR_STR_4X:
            TmpDrStrngth =0x3;
             break;
        default: 
             ErrVal = ATVERR_INV_PARM;
             return (ErrVal);
    }
    switch(PinId)
    {
        case RX_LLC_OUT_PIN:
            VRX_set_DR_STR_CLK(TmpDrStrngth);
            break;
        case RX_PIX_OUT_PINS:
            VRX_set_DR_STR(TmpDrStrngth);
            break;
        case RX_SYNC_OUT_PINS:
            VRX_set_DR_STR_SYNC(TmpDrStrngth);
            break;
        case RX_OUT_PINS:
            VRX_set_DR_STR_CLK(TmpDrStrngth);
            VRX_set_DR_STR(TmpDrStrngth);
            VRX_set_DR_STR_SYNC(TmpDrStrngth);
            break; 
        default:
            ErrVal = ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetManSigPhase(RX_CLOCK_SIG Signal, UINT8 Phase)
{
    ATV_ERR ErrVal;
    ErrVal = ATVERR_OK;
    
    if(Phase > 31)
    {
        return (ATVERR_INV_PARM);
    }
    switch(Signal)
    {
        case RX_LLC_SIG:
             VRX_set_LLC_DLL_PHASE(Phase);  
             break;
     
        default:
             ErrVal = ATVERR_INV_PARM; 
    }
    return (ErrVal);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetManSigPhaseEn(RX_CLOCK_SIG Signal, BOOL Enable)
{
    ATV_ERR ErrVal;
    ErrVal = ATVERR_OK;
    
    switch(Signal)
    {       
       case RX_LLC_SIG:
            if(Enable)
            {
                VRX_set_LLC_DLL_EN(0x1);
                VRX_set_LLC_DLL_MUX(0x1);
            }
            else
            {
                VRX_set_LLC_DLL_EN(0x0);
                VRX_set_LLC_DLL_MUX(0x0);
            }
            break;
       default:
            ErrVal = ATVERR_INV_PARM;  
            break;
    }
    return (ErrVal);
}





/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  TRUE
 *          FALSE
 *
 * Notes:
 *
 *=========================================================================*/
BOOL RxGetHdmiVidStdCfg(UINT8 Index, RX_VRT_FRQ Freq, RX_OS_RATE OvrSmplng, UINT8* VidStd, UINT8* VFreq)
{
    switch(HdmiVidStdTable[Index].PrimMode)
    {
        case RX_HDMI_GR_PM:
            switch(Freq)
            {
                case RX_VFRQ_56HZ:
                    if (HdmiVidStdTable[Index].GrVidStdSet[0] == RX_FREQ_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].GrVidStdSet[0];
                    break;
                case RX_VFRQ_60HZ:
                    if (HdmiVidStdTable[Index].GrVidStdSet[1] == RX_FREQ_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].GrVidStdSet[1];
                    break;
                case RX_VFRQ_70HZ:
                    if (HdmiVidStdTable[Index].GrVidStdSet[2] == RX_FREQ_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].GrVidStdSet[2];
                    break;
                case RX_VFRQ_72HZ:
                    if (HdmiVidStdTable[Index].GrVidStdSet[3] == RX_FREQ_NOT_SUP)
                    {
                    return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].GrVidStdSet[3];
                    break;
                case RX_VFRQ_75HZ:
                    if (HdmiVidStdTable[Index].GrVidStdSet[4] == RX_FREQ_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].GrVidStdSet[4];
                    break;
                case RX_VFRQ_85HZ:
                    if (HdmiVidStdTable[Index].GrVidStdSet[5] == RX_FREQ_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].GrVidStdSet[5];
                    break;
                 
                default:
                    RX_DEBUG("Vertical Frequency not supported \r\n");
                    return FALSE; 
             }
             break;
            
        case RX_HDMI_CMP_PM:
            
            switch (Freq)
            {
                case RX_VFRQ_24HZ:
                    if (HdmiVidStdTable[Index].CmpVFreq[0]==FALSE)
                    {
                        return FALSE;
                    }
                    *VFreq =  RX_VFRQ_24_VAL;
                    break;
                case RX_VFRQ_25HZ:
                    if (HdmiVidStdTable[Index].CmpVFreq[1]==FALSE)
                    {
                        return FALSE;
                    }
                    *VFreq =  RX_VFRQ_25_VAL;
                    break;
                case RX_VFRQ_30HZ:
                    if (HdmiVidStdTable[Index].CmpVFreq[2]==FALSE)
                    {
                       return FALSE;
                    }
                    *VFreq =  RX_VFRQ_30_VAL;
                    break;
                case RX_VFRQ_50HZ:
                    if (HdmiVidStdTable[Index].CmpVFreq[3]==FALSE)
                    {
                        return FALSE;
                    }
                    *VFreq =  RX_VFRQ_50_VAL;
                    break;
                case RX_VFRQ_60HZ:
                    if (HdmiVidStdTable[Index].CmpVFreq[4]==FALSE)
                    {
                        return FALSE;
                    }
                    *VFreq =  RX_VFRQ_60_VAL;
                    break;
                default:
                    RX_DEBUG("Vertical Frequency not supported \r\n"); 
                    return FALSE; 
            }

            switch(OvrSmplng)
            {
                case RX_OS_1X1:
                    if (HdmiVidStdTable[Index].CmpVidStdSet[0] == RX_OS_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].CmpVidStdSet[0];
                    break;
                case RX_OS_2X1:
                    if (HdmiVidStdTable[Index].CmpVidStdSet[1] == RX_OS_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].CmpVidStdSet[1];
                    break;
                case RX_OS_4X1:
                    if (HdmiVidStdTable[Index].CmpVidStdSet[2] == RX_OS_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].CmpVidStdSet[2];
                    break;
                case RX_OS_2X2:
                    if (HdmiVidStdTable[Index].CmpVidStdSet[3] == RX_OS_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].CmpVidStdSet[3];
                    break;
                case RX_OS_4X2:
                    if (HdmiVidStdTable[Index].CmpVidStdSet[4] == RX_OS_NOT_SUP)
                    {
                        return FALSE;
                    }
                    *VidStd = HdmiVidStdTable[Index].CmpVidStdSet[4];
                    break;        
                default:
                    RX_DEBUG("Over Sampling Mode Not Supported \r\n");
                    return FALSE; 
            }
            break;

        default:
            break;
    }
    return (TRUE);
}

/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_RxSetInpVidCfg(RX_OP_MODE OpMode, RX_VID_RES Res, RX_VRT_FRQ Freq, RX_OS_RATE OvrSmplng)
{
    ATV_ERR ErrVal = ATVERR_OK;
    UINT8 i,index;
    UINT8 TmpPrimMode;
    UINT8 TmpVidStd;
    UINT8 TmpVFreq;
    
    switch(OpMode)
    {


         case RX_OPMODE_HDMI:
            for (i=0; i<RX_HDMI_TBL_SIZE; i++)
            {
                if ((HdmiVidStdTable[i].Res == Res))
                {
                    index =i;
                    RX_DEBUG("Resolution index: %d\r\n", i); 
                    TmpPrimMode = HdmiVidStdTable[index].PrimMode;
                    if(RxGetHdmiVidStdCfg(index, Freq, OvrSmplng, &TmpVidStd, &TmpVFreq)== TRUE)
                    { 
                        VRX_set_VID_STD( TmpVidStd); 
                        VRX_set_PRIM_MODE(TmpPrimMode);  
                        if(TmpPrimMode == RX_HDMI_CMP_PM)
                        {
                            VRX_set_V_FREQ(TmpVFreq); 
                        }
                        RxSetSpecificResCnfg(TmpPrimMode, Res); 
                        RX_DEBUG("Primary Mode: %x, Video Std: %x\r\n", TmpPrimMode,TmpVidStd); 
                        return(ATVERR_OK);         
                    }
                }
            }
            RX_DEBUG("Resolution not directly supported\r\n");
            return(ATVERR_FAILED);


        default:
            ErrVal = ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);    
}



/*============================================================================
 * This Local function is used to Set Specific ADI Recommended Configuration based 
 * on Primary mode and Resolution
 *
 * Entry:   Primary Mode: Primary Mode of Operation
 *          Res: Expected Resolution of the video
 * Return:  
 *
 * Notes:   None
 *
 *===========================================================================*/
void RxSetSpecificResCnfg(UINT8 PrimMode, RX_VID_RES Res )
{
    
}


/*==========================================================================
 * 
 *
 * Entry:   
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR HAL_SetManagePower(RX_CHIP_SECTION Section, BOOL PowerUp)
{
    ATV_ERR ErrVal;
    ErrVal = ATVERR_OK;
    switch(Section)
    {
        case RX_ALL_SECTIONS:
            VRX_set_POWER_DOWN(!PowerUp);
            break;
        case RX_CP:
            VRX_set_CP_PWRDN(!PowerUp);
            break;
        case RX_XTAL:
            VRX_set_XTAL_PDN(!PowerUp);
            break;
        case RX_ALL_CORES:
            VRX_set_CORE_PDN(!PowerUp);
            break;
        case RX_CEC_CTRL:
            VRX_set_CEC_POWER_UP(PowerUp);
            break;
        default:
            ErrVal= ATVERR_INV_PARM;
            break;
    }
    return (ErrVal);
}

/*============================================================================
 * This function sets 861 related settings i.e. sync adjustment and sync 
 * polarity for inputs processed via the CP section
 * 
 * Entry:   None
 *  
 * Return:  ATVERR_OK
 *          ATVERR_INV_PARM: Combination of Vid861 and operating mode not
 *                           supported
 *
 * Notes:   This function should be called periodically by the application
 *
 *===========================================================================*/
ATV_ERR HAL_CpSet861RecSettings(UINT8 Vid861, RX_OP_MODE OperatingMode)
{
    switch(OperatingMode)
    {

        case RX_OPMODE_HDMI:
            VRX_set_INV_HS_POL(0);
            VRX_set_INV_VS_POL(0);
            ATV_I2CWriteTable((UCHAR *)RxCeaId00RecSettingTable, 0);
            break;            
        default:
            return (ATVERR_INV_PARM);
    }
    return (ATVERR_OK);
}
/*============================================================================
 * Enables/Disable downsampling 
 *
 * Entry:   FiltMode : FILTER_DOWNSAMPLE = Filter and downsample in all 
 *                     modes but HDMI 4:2:2.
 *                     Downsample only (no filtering) in HDMI 4:2:2
 *                     DOWNSAMPLE_ONLY = Downsample only (no filtering) in all
 *                     modes but HDMI 4:2:2.
 *                     Filter and downsample in HDMI 4:2:2
 *
 * Return:  ATVERR_OK = Function completed successfully
 *          ATVERR_INV_PARM = Invalid input parameter
 *          ATVERR_FAILED = Function failed to perform the required action
 *                          because the DPP section is not enabled
 *
 * Notes:   None
 *
 *===========================================================================*/ 
ATV_ERR HAL_RxDppFiltMode(RX_FILT_MODE FiltMode)
{
    UINT8 Val;
    
    switch(FiltMode)
    {
        case RX_FILTER_DOWNSAMPLE:
            Val = 0;
            break;
        case RX_DOWNSAMPLE_ONLY:
            Val = 1;
            break;
        default:
            return (ATVERR_INV_PARM);
    }
    VRX_set_DS_WITHOUT_FILTER(Val);
    if(VRX_is_DPP_BYPASS_EN_true())
    {
        return (ATVERR_FAILED);
    }
    return (ATVERR_OK); 
}
#if (RX_DEVICE != 7619) 
/*============================================================================
 *
 * Entry:   None
 *  
 * Return:  void
 *
 * Notes:   None
 *
 *===========================================================================*/
ATV_ERR HAL_SetOpPixFormat (RX_PIX_BUS_INFO* PixBusInfo,  RX_OP_MODE* OpMode)
{
   

    ATV_ERR ErrVal = ATVERR_OK;
    UINT8 TmpBusWidth=0;
    UINT8 TmpFormat=0;
    UINT8 TmpMode=0;
    UINT8 OpFormatSel; 
    ErrVal = ATVERR_OK;
    
    switch(PixBusInfo->BitWidth)
    {
        case RX_BUS_BITS_8:
            TmpBusWidth = 0x0;
            break;
        case RX_BUS_BITS_10:
            TmpBusWidth = 0x1;
            break;
        case RX_BUS_BITS_12:
            TmpBusWidth = 0x2;
            break;
        default:
            ErrVal=  ATVERR_INV_PARM;   
            break;
    }

    switch(PixBusInfo->Mode)
    {
        case RX_BUS_MODE0:
            TmpMode = 0x0;
            break;
        case RX_BUS_MODE1:
            TmpMode = 0x1;
            break;
        case RX_BUS_MODE2:
            TmpMode = 0x2;
            break;
        default:
            ErrVal=  ATVERR_INV_PARM;   
            break;
    }
    
    switch(PixBusInfo->Format)
    {
        case RX_BUS_OP_MODE_422PSDR:
            TmpFormat= 0x00;
            break;
        case RX_BUS_OP_MODE_422DDR:
            TmpFormat= 0x01;
            break;
        case RX_BUS_OP_MODE_444SDR:
            TmpFormat= 0x02;
            break;
        case RX_BUS_OP_MODE_444DDR:
            TmpFormat= 0x03;
            break;
        case RX_BUS_OP_MODE_422SDR:
            TmpFormat= 0x04;
            break;
        default:
            ErrVal=  ATVERR_INV_PARM;   
            break;
    }

    OpFormatSel= ( TmpFormat << 5) | (TmpMode <<2)| (TmpBusWidth);
    VRX_set_OP_FORMAT_SEL(OpFormatSel);
    
    switch(PixBusInfo->ChOrder)
    {
        case RX_BUS_OP_CH_GBR:

             VRX_set_OP_CH_SEL(0x0);
             break;     
        case RX_BUS_OP_CH_GRB:
             VRX_set_OP_CH_SEL(0x1);
             break;
        case RX_BUS_OP_CH_BGR:
             VRX_set_OP_CH_SEL(0x2);
             break;
        case RX_BUS_OP_CH_RGB:
             VRX_set_OP_CH_SEL(0x3);
             break;
        case RX_BUS_OP_CH_BRG:
             VRX_set_OP_CH_SEL(0x4);
             break;
        case RX_BUS_OP_CH_RBG:
             VRX_set_OP_CH_SEL(0x5);
             break;
        default:
              ErrVal=  ATVERR_INV_PARM; 
              break;
    }
    VRX_set_PIXBUS_MSB_TO_LSB_REORDER(PixBusInfo->BitReorder);
    VRX_set_OP_SWAP_CB_CR(PixBusInfo->CrCbSwap);
    return (ErrVal);
}
#endif
#endif
