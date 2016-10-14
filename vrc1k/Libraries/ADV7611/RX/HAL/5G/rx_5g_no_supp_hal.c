/**********************************************************************************************
*																						      *
* Copyright (c) 2012 Analog Devices, Inc.  All Rights Reserved.                               *
* This software is proprietary and confidential to Analog Devices, Inc. and its licensors.    *
*                                                                                             *
***********************************************************************************************/

#include "rx_lib.h"
/*============================================================================
 * This file contains all functions that not supported by 5G family of products
 *
 *===========================================================================*/
#if ((RX_DEVICE == 7612)|| (RX_DEVICE == 7611) || (RX_DEVICE == 7619))


/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxAfeAinAutoMuxModeSel(UINT8 AinMode)
{
    return(ATVERR_NOT_AVAILABLE); 
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxAfeSdpEnManAinMux(BOOL Enable)
{
   return(ATVERR_NOT_AVAILABLE);
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxAfeManAinMux(RX_ADC ADC, RX_AIN_CH AinChannel)
{
   return(ATVERR_NOT_AVAILABLE);
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxAfeConfigTriLevelSlicer(RX_TRI_SLICER TriSlicer, RX_TRI_SLICER_MODE SliceMode, RX_TRI_SLICE_LEVEL* SliceLevels )
{
    return(ATVERR_NOT_AVAILABLE);
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxAfeEnTriLevelSlicer(RX_TRI_SLICER TriSlicer,BOOL PowerUp)
{
    return(ATVERR_NOT_AVAILABLE);
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxAfeGetTriLevelSlicerStatus(RX_TRI_SLICER TriSlicer, RX_TRI_SLICER_STATUS* TriStatus)
{
    return(ATVERR_NOT_AVAILABLE);
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxAfeEnAntiAliasFilt(RX_ADC ADC, BOOL Enable)
{
   return(ATVERR_NOT_AVAILABLE);
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxAfeSelAntiAliasFilt(RX_AA_FILT_RESPONSE FiltResponse)
{
    return(ATVERR_NOT_AVAILABLE);
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxAfeEnExtBiasing(BOOL Enable)
{
    return(ATVERR_NOT_AVAILABLE);
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxAfeCfgAfeSlicerEvent(RX_TRI_SLICER Slicer, RX_TRI_SLICER_LEVEL EnableLvl)
{
    return(ATVERR_NOT_AVAILABLE);
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxAfeEnVoltageClamps(BOOL Enable)
{
   return(ATVERR_NOT_AVAILABLE);
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxAfeEnManAinMux(BOOL Enable)
{
    return(ATVERR_NOT_AVAILABLE);
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxAfeEnCurrentClamps(BOOL Enable)
{
    return(ATVERR_NOT_AVAILABLE);
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxAfeSetSyncSliceLevel(RX_SYNC_SLICER SyncSlicer, UINT8 SliceLevel)
{
   return(ATVERR_NOT_AVAILABLE);
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxAfeSetSyncSlicerFilt(RX_SYNC_SLICER SyncSlicer, RX_SYNC_SLICER_FILTER SyncFilter)
{
   return(ATVERR_NOT_AVAILABLE);
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxEnManPllDiv (UINT16 PllDivRatio)
{
     return(ATVERR_NOT_AVAILABLE);
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxDisableManPllDiv (void)
{
     return(ATVERR_NOT_AVAILABLE);
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxEnHdmiSimultMode (BOOL Enable)
{
    return(ATVERR_NOT_AVAILABLE);
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxCpGetHsyncDepthMsrmt(UINT16 *HsdChA, UINT16 *HsdChB, UINT16 *HsdChC)
{
return(ATVERR_NOT_AVAILABLE); 
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxCpGetGainedHsyncDepthMsrmt(UINT16 *HsdChA)
{
 return(ATVERR_NOT_AVAILABLE); 
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxCpGetVideoPeakValue (UINT16 *PkvChA, UINT16 *PkvChB, UINT16 *PkvChC)
{
    return(ATVERR_NOT_AVAILABLE); 
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxCpConfigHsyncLckMsrmt(UINT8 Threshold, RX_CP_DURATION Lines)
{
    return(ATVERR_NOT_AVAILABLE); 
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxCpSetNoiseCalibWindow (UINT16 WindowStart, RX_CP_DURATION WindowLength)
{
   return(ATVERR_NOT_AVAILABLE); 
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxCpGetNoiseCalibMsrmt (UINT16 *Noise, UINT16 *Calib)
{
    return(ATVERR_NOT_AVAILABLE); 
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxCpGetMacrovisionStatus(RX_MCVS_STATUS *MvStatus)
{
   return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxConfigAutoGrMode(RX_AUTO_GR_PARM *AutoGrParm)
{
   return(ATVERR_NOT_AVAILABLE); 
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpCfgAutoFormatDetect(RX_SDP_FORMAT SdpFormat, BOOL Enable)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpCfgFrmtPedStatus(RX_SDP_FORMAT SdpFormat, BOOL PedestalPresent)
{
   return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpEnableSFL(BOOL Enable)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpGetAutoFormatDetectResult(RX_SDP_FORMAT* SdpFormat)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpGetVideoDetectStatus(BOOL* SdpVideoDetectStatus)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpGetBurstLockedStatus(BOOL* BurstLockedStatus)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpGetFieldRateStatus(RX_SDP_FIELD_RATE* SdpFieldRate)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpGetStatus(RX_SDP_STATUS* SdpStatus)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpGetMacrovisionStatus(RX_MCVS_STATUS* McvsStatus)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpSetSaturation(UINT16 SdpSaturation)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpSetBrightness(UINT16 SdpBrightness)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpSetHue(UINT16 SdpHue)
{
   return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpSetLumaGainMode(RX_GAIN_MODE SdpLumaGainMode)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpSetManLumaGain(UINT16 SdpLumaGain)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpGetLumaGain(UINT16* SdpLumaGainRb)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpSetChromaGainMode(RX_GAIN_MODE SdpChromaGainMode)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpSetChromaManGain(UINT16 SdpChromaGain)
{
   return(ATVERR_NOT_AVAILABLE); 
}


/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpEn3dComb(BOOL Enable)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpEn3dDnr(BOOL Enable)
{
   return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpEnFrameTbc(BOOL Enable)
{
   return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpInitMemInterface(RX_SDP_MEM MemType)
{
   return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpSetItoPMode(RX_ItoP_MODE ItoPMode)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpEnItoP(BOOL Enable )
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR  ADIAPI_RxSdpSetSdpClampSpeed(RX_CLAMP Clamp, UINT8 Speed)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxSdpForceFreeRun (BOOL Enable)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxSdpCfgColorKill(BOOL Enable, UINT8 HighThres, UINT8 LowThres)
{
    return(ATVERR_NOT_AVAILABLE); 
}
/*==========================================================================
 * Return:  ATVERR_NOT_AVAILABLE
 *
 * Notes: This function is not available for ADV7612 as there is no Analog Support
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxSdpSetPixClkFreq (RX_PIX_CLK_FREQ PixClkFreq, BOOL Enable)
{
    return(ATVERR_NOT_AVAILABLE); 
}
/*============================================================================
 * Stores the EDID data from the internal EDID area to an external SPI PROM
 *
 *
 * Return:  ATVERR_NOT_AVAILABLE 
 *
 * Notes:   This API is for Edid Replicator function
 *          Edid Replicator is not supported on ADV7612
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiWriteEdidToProm (void)
{
    return(ATVERR_NOT_AVAILABLE); 
}

/*============================================================================
 * Loads EDID data from external SPI PROM to the internal EDID area
 *
 *
 * Return:  ATVERR_OK = function completed successfully
 *
 * Notes:   This API is for Edid Replicator function
 *          Edid Replicator is not supported on ADV7612
 *
 *===========================================================================*/
ATV_ERR ADIAPI_RxHdmiReadEdidFromProm (void)
{
    return(ATVERR_NOT_AVAILABLE); 
}
/*==========================================================================
 * To configure the Video Loopback Mux
 *
 * Entry:   VidOutChannel  Video Output channel to which video is to be routed
 *          AinChannel     Video source which is to be looped back to VidOutChannel
 *
 * Return:  ATVERR_OK
 *          ATVERR_FAILED
 *          ATVERR_INV_PARM
 *
 * Notes:
 *
 *=========================================================================*/
ATV_ERR ADIAPI_RxAfeSetVideoOutMux (RX_VOUT_CH VidOutChannel, RX_AIN_CH AinChannel)
{
    
    return(ATVERR_NOT_AVAILABLE);
    
}
#endif
