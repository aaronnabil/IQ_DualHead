/*! \mainpage IQmeasure Library Documentation
 *
 * The IQmeasure Library brings ease of use to programming LitePoint wireless test instruments,
 * including IQview/IQflex, IQnxn_plus, IQmax, and IQ2010.
 *
 * A number of high-level functions provided by the library greatly reduce the steep learning
 * curve associated with using the C++ IQapi.  The code below shows how easily an EVM measurement
 * for OFDM-54 can be done:
 *
 * \code
  void main(void)
  {
      LP_InitTester("192.168.100.254");
      LP_SetVsa(2412e6, 18, PORT_LEFT, 0, -25);
      LP_VsaDataCapture(200);
      LP_Analyze80211ag();
      double evm = LP_GetScalarMeasurement("evmAll");
      printf("EVM for OFDM-54 = %.2f\n", evm);
  }
 * \endcode
 *
 * Please see below the functions provided by the IQmeasure Library:
 * -# Instrument Control Functions:
 *   - LP_Init();
 *   - LP_Term();
 *   - LP_InitTester();
 *   - LP_InitTester2();
 *   - LP_InitTester3();
 *   - LP_InitTester4();
 *   - LP_GetVersion();
 *   - LP_ConClose();
 *   - LP_ConOpen();
 * -# Configuration Functions:
 *   - LP_SetVsg();
 *	 - LP_SetVsg_Compensation();
 *	 - LP_SetVsgTriggerType();
 *	 - LP_SetVsg_GapPower();
 *   - LP_SetVsa();
 *   - LP_SetVsgCw();
 *	 - LP_SaveSignalArrays();
 *   - LP_SetVsgModulation();
 *   - LP_SetAnalysisParameterInteger();
 *   - LP_SetAnalysisParameterIntegerArray();
 *   - LP_SaveVsaSignalFile();
 *   - LP_LoadVsaSignalFile();
 *   - LP_SaveVsaGeneratorFile();
 *   - LP_SaveIQDataToModulationFile();
 *   - LP_Agc();
 *   - LP_SetFrameCnt();
 *   - LP_EnableVsgRF();
 *   - LP_EnableSpecifiedVsgRF();
 *   - LP_SetLpcPath();
 * -# Data Capture Functions:
 *   - LP_VsaDataCapture();
 * -# Analysis Functions:
 *   - LP_Analyze80216d();
 *   - LP_Analyze80216e();
 *   - LP_Analyze80211ag();
 *   - LP_Analyze80211n();
 *   - LP_Analyze80211b();
 *   - LP_AnalyzePower();
 *   - LP_AnalyzeFFT();
 *   - LP_AnalyzeCCDF();
 *   - LP_AnalyzeCW();
 *   - LP_AnalysisWave();
 *   - LP_AnalyzeSidelobe();
 *   - LP_AnalyzePowerRampOFDM();
 *   - LP_AnalyzePowerRamp80211b();
 *   - LP_AnalyzeBluetooth();
 *   - LP_AnalyzeZigbee();
 * -# Result Retrieving Functions:
 *   - LP_GetScalarMeasurement();
 *   - LP_GetStringMeasurement();
 *   - LP_GetVectorMeasurement();
 * -# Error Handling Functions:
 *   - LP_GetErrorString();
 *   - LP_GetIQapiHndlLastErrMsg();
 *   - LP_GetCapture();
 *	 - LP_EnableMultiThread();
 *	 - LP_SetDefaultNfc();
 *	 - LP_SetNfcTxAmplitude();
 *	 - LP_SetTriggerMaskNfc();
 *	 - LP_InitiateNfc();
 *	 - LP_SetRxNfc();
 *	 - LP_SetTxNfc();
 *	 - LP_ContCapture();
 *	 - LP_TerminateNfc();
 *	 - LP_AnalysisNfc();
 *
 * \section revision_sec Revision History
 *
 * \subsection revision_1_8_77_6 1.8.77.6
 * Date: March 9nd, 2012 - Seshadri
 * Fixed LP_FM_StartVsgInterference() & LP_FM_SetVsg() FM functions to properly round off power level setting since iqapi takes double but has a limit on the decimal points 
 * it can take as input.
 *
 * \subsection revision_1_8_77_5 1.8.77.5
 * Date: Feb 7nd, 2012 - Seshadri
 * Updated LP_InitTester, LP_InitTester2, LP_InitTester3, LP_InitTester4 functions to specify serial number for IQ2010 Mimo connection	
 * For Mimo IQ2010 setup - user can specify the serial number of all the IQ2010 Testers(For Eg: IQP00101) 
 * or can specify IPADDR:PORT_NO:SERIAL_NO (For Eg: 127.0.0.1:4000:IQP00101)
 *
 * \subsection revision_1_8_77_4 1.8.77.4
 * Date: Feb 2nd, 2012 - Seshadri
 * Added error codes in enum IQMEASURE_ERROR_CODES in IQMeasure.h to LP_GetErrorString() that were missing.	
 *
 * \subsection revision_1_8_77_3 1.8.77.3
 * Date: Jan 25th, 2012 - Seshadri
 * Added "PSDU" Measurement to resultMimo in IQMeasure
 *
 * \subsection revision_1_8_77_2 1.8.77.2
 * Date: Jan 5th, 2012 - Seshadri
 * Added FM Set VSA function with AGC - LP_FM_SetVsa_Agc_On()
 *
 * \subsection revision_1_8_77_1 1.8.77.1
 * Date: Dec 22th, 2011 - Henrik Lin
 * update IQApi version to 1.8.77.00
 *
 * \subsection revision_1_8_76_13 1.8.76.13
 * Date: Dec 19th, 2011 - Henrik Lin
 * Multi EVM measurement in long capture
 *
 * \subsection revision_1_8_76_12 1.8.76.12
 * Date: Nov 18th, 2011 - Seshadri
 * Added extAttenDb as an input parameter to the function LP_SetVsaBluetooth_BTShiftHz()
 *
 * \subsection revision_1_8_76_11 1.8.76.11
 * Date: Nov 18th, 2011 - Seshadri
 *   -# LP_SetVsaBluetooth_BTShiftHz()
 * Created a copy of the SetVsaBluetooth function and Added the vsa IF frequency as a user input since Qualcomm requested for it.
 *
 * \subsection revision_1_8_76_10 1.8.76.10
 * Date: Nov 18th, 2011 - Seshadri
 *   -# LP_FM_SetVsg()
 * Added	hndl->hndlFm->RemoveParamAllAudioTone(); before calling SetTx to avoid fail to set multitone errors, 
 *	the setTx command applies some uninitialized values that caused this error. This line fixes that.
 *
 * \subsection revision_1_8_76_9 1.8.76.9
 * Date: Nov 10th, 2011 - Seshadri
 *   -# LP_FreeMemory()
 * //if (hndl) { delete hndl; hndl = NULL; } - this line was causing FM to crash in IQFact+. Commenting it for now.

 * \subsection revision_1_8_76_8 1.8.76.8
 * Date: Nov 8th, 2011 - Seshadri
 *   -# LP_FM_SetVsg()
 *   - added SetTx() in LP_FM_SetVsg to catch any errors while trying to setVsg 
 
 // 
 * \subsection revision_1_8_76_7 1.8.76.7
 * Date: October 24, 2011 - Sherry
 *   -# LP_VsaDataCapture()
 *      - Enhance the trigger type check.
 *      - Error code check if doing SetTxRx() failed.
 *
 * \subsection revision_1_8_76_6 1.8.76.6
 * Date: October 21, 2011 - Seshadri
 *   -# Add another function LP_SetVsgModulation_SetPlayCondition() so that the user can specify if the autoPlay of the VSG file needs to be on or off(default is OFF)
 *
 * \subsection revision_1_8_76_5 1.8.76.5
 * Date: October 14, 2011 - Justin
 *   -# Add "dcLeakageDbc" into " LP_GetScalarMeasurement()" function to get 802.11ag LO leakage in dBc.
 *
 * \Subsection revision_1_8_76_4 1.8.76.4
 * Date: October 07, 2011 - Sherry
 *   -# Add related analysis type and result for the following enum from IQV_CAPTURE_TYPE_ENUM:
 *      - IQV_HT_40_WIDE_BAND_HI_ACCURACY_CAPTURE_TYPE
 *      - IQV_HT_20_WIDE_BAND_LO_ACCURACY_CAPTURE_TYPE
 *      - IQV_HT_20_WIDE_BAND_HI_ACCURACY_CAPTURE_TYPE
 *
 * \Subsection revision_1_8_76_3 1.8.76.3
 * Date: September 21, 2011 - Kenny
 *   -# Added IQmeasure for NFC
 *
 *	 - LP_SetDefaultNfc();
 *	 - LP_SetNfcTxAmplitude();
 *	 - LP_SetTriggerMaskNfc();
 *	 - LP_InitiateNfc();
 *	 - LP_SetRxNfc();
 *	 - LP_SetTxNfc();
 *	 - LP_ContCapture();
 *	 - LP_TerminateNfc();
 *	 - LP_AnalysisNfc();
 *
 * \subsection revision_1_8_76_2 1.8.76.2
 * Date: September 20, 2011 - Justin
 *   -# Add "ALC_MANUAL_HIGH_PRECISION" into "enum IQAPI_ALC_MODES" to let tester output high accurate CW power level.
 *
 * \subsection revision_1_8_76_1 1.8.76.1
 * Date: September 14, 2011 - Justin
 *   -# Update the IQapi to 1.8.76
 *
 * \subsection revision_1_8_73_2 1.8.73.2
 * Date: September 08, 2011 - Sherry
 *   -# Update LP_SetLpcPath() to check if the input path is null. 
 *
 * \subsection revision_1_8_73_1 1.8.73.1
 * Date: April 20, 2011 - Lanjiang
 *   -# Update the IQapi to 1.8.73
 *
 * \subsection revision_1_8_71_7 1.8.71.7
 * Date: March 16, 2011 - Leo Chen
 *
 *   -# Modify original function "LP_GPS_PlayScenarioFile" to separate another functions.
 *   -# Add one functions "LP_GPS_LoadScenarioFile" to implement Transmit Scenario File mode
 *
 * \subsection revision_1_8_71_6 1.8.71.6
 * Date: March 14, 2011 - Seshadri
 *
 *   -# Fixed LP_GetAlcMode() function to return the correct ALC value
 *
 * \subsection revision_1_8_71_5 1.8.71.5
 * Date: March 14, 2011 - Justin Lin
 *
 *   -# Add two functions "LP_IQ2010EXT_Init()" and "LP_IQ2010EXT_Terminate()" to Enter/Exit IQ2010Ext mode
 *
 * \subsection revision_1_8_71_4 1.8.71.4
 * Date: March 04, 2011 - Seshadri
 *
 *   -# Fixed LP_FM_SetVsa() function to set the VSA gain value as provided by the user.
 *   -# Updated LP_GPS_ContinueWave() function to change IQV_MODULATION_STATE_OFF to IQV_MODULATION_STATE_ON in the 
 *		hndl->hndlGps->SetParamModulationState inorder to see the signal at the GPS port during CW mode.
 *
 * \subsection revision_1_8_71_3 1.8.71.3
 * Date: Feb 28, 2011 Kenny Lee
 *
 *   -# Added LP_GetCapture() function to IQMeasure.cpp and IQMeasure.h
 *   -# Added LP_EnableMultiThread() function to IQMeasure.cpp and IQMeasure.h
 *
 * \subsection revision_1_8_68_6 1.8.68.6
 * Date: February 18, 2011 Leo Chen
 *
 * Add GPS function to IQMeasure. The following are the GPS functions supported.
 *	LP_GPS_GetChannelInfo
 *  LP_GPS_SetChannelInfo
 *  LP_GPS_SetData
 *  LP_GPS_SetDeactivate
 *  LP_GPS_SetActivate
 *  LP_GPS_ContinueWave
 *  LP_GPS_ModulatedMode
 *  LP_GPS_PlayScenarioFile
 * The functions is easy to use, please following the steps for those function.
 *  1. calling LP_GPS_SetActivate 1st.
 *  2. calling what you want 2nd, such as : 
 *    LP_GPS_ContinueWave
 *    LP_GPS_ModulatedMode
 *    LP_GPS_PlayScenarioFile
 *     or do something set/get : 
 *    LP_GPS_SetData        // for the overall tester setting
 *    LP_GPS_SetChannelInfo // for the channel setting
 *    LP_GPS_GetChannelInfo
 *  3. At last, calling LP_GPS_SetDeactivate to stop the RF output.
 *
 * \subsection revision_1_8_68_5 1.8.68.5
 * Date: February 15, 2011 Seshadri
 *
 * Integrated BT LE to IQMeasure(does not include dirty packet PER). The following are the BT LE measurement results supported 
 *	The analysis function call is the same as the classic bluetooh(LP_AnalyzeBluetooth()).
 *	please use LP_GetScalarMeasurement function to retrieve the LE measurement results.
 *  leFreqOffset
 *  leDeltaF1Avg          
 *  leDeltaF2Max          
 *  leDeltaF2Avg          
 *  leBelow185F2Max       
 *  leFn        
 *  leFnMax               
 *  leDeltaF0FnMax        
 *  leDeltaF1F0         
 *  leDeltaFnFn_5Max     
 *  leFreqDevSyncAv     
 *  lePduLength           
 *  leIsCrcOk             
 *  leValid              
 *  leMaxPowerDbm         
 *  lePreambleSeq        
 *  leSyncWordSeq        
 *  lePduHeaderSeq        
 *  lePduLengthSeq       
 *  lePayloadSeq         
 *  leCrcSeq           
 *
 * \subsection revision_1_8_68_4 1.8.68.4
 * Date: October 20, 2010
 *
 *	 -# Added LP_GetIQapiHndl() function to IQMeasure.cpp and IQMeasure.h
 *	 -# Updated LP_GetVersion() function to use GetAllVersions() instead of individually calling version information from iqapi. 
 *	 -# updated FM deviation values to use 1000 instead of 0 since the lower limits were changed and 0 is an illegal value for all fm deviation values
 *	 -# updated LP_FM_DeleteAudioTones() function to remove audio tones only if there are any tones in the tone table in iqapi
 *
 * \subsection revision_1_8_68_3 1.8.68.3
 * Date: October 14, 2010
 *
 *	 -# Added "P_pk_each_burst_dBm" Vector measurement result keyword for Power Analysis(resultPower) in LP_GetVectorMeasurement_NoTimer() function
 *
 * \subsection revision_1_8_68_2 1.8.68.2
 * Date: October 11, 2010
 *
 *	 -# Added Vector measurement results for Power Analysis(resultPower) in LP_GetVectorMeasurement_NoTimer() function
 *
 * \subsection revision_1_8_68_1 1.8.68.1
 * Date: September 21, 2010
 *
 *   -# Add new IQapi 
 *   -# IQapi version: 1.8.68
 *
 * \subsection revision_1_8_67_2 1.8.67.2
 * Date: September 16, 2010
 *
 *	 -# Edited LP_SetVsg_triggerType() function name to LP_SetVsgTriggerType to maintain convention
 *	 -# Edited LP_SetVsg_triggerType() to only set the VSG Trigger type when called. 
 *	 -# Initially this function included LP_SetVsg() functionality.
 *
 * \subsection revision_1_8_67_1 1.8.67.1
 * Date: September 15, 2010
 *
 *   -# Add new IQapi 
 *   -# IQapi version: 1.8.67
 * 
 * \subsection revision_1_8_65_7 1.8.65.7
 * Date: August 26, 2010
 *
 *   -# Added LP_SetVsg_triggerType() so that user can control the VSG Trigger type.
 *
 * \subsection revision_1_8_65_6 1.8.65.6
 * Date: August 16, 2010
 *
 *   -# Merged FM IQMeasure code. Added additional code to existing IQMeasure functions to support FM
 *	 -#	No Existing IQMeasure functions were modified except the following functions that have additional code related to FM.
 *	 -# LP_GetErrorString(), LP_Term(), LP_InitTester(), InstantiateAnalysisClasses(), LP_DualHead_ObtainControl()   
 *   -# IQapi version: 1.8.65
 *   -# Added LP_SetVsg_GapPower() so that GapPower feature can be turned On or Off using the paramter gapPowerOff.
 *
 * \subsection revision_1_8_65_5 1.8.65.5
 * Date: August 09, 2010
 *
 *   -# Added LP_SaveSignalArrays() from IQMeasure for Mimo used for LabView ( 1.7.48.1 )
 *
 *
 * \subsection revision_1_8_65_4 1.8.65.4
 * Date: June 15, 2010
 *
 *   -# In testers >1, apply 1st tester setting to the rest testers if NxN function is not called.
 *   -# Add variable, g_nxnFunctionCalled, to remeber whethere NxN function is called or not.
 *   -# IQapi version: 1.8.65
 *
 * \subsection revision_1_8_65_3 1.8.65.3
 * Date: June 11, 2010
 *
 *   -# Modify LP_GetVersion() to get FW/VSA/VSG version of testers.     
 *   -# IQapi version: 1.8.65
 *
 * \subsection revision_1_8_65_2 1.8.65.2
 * Date: June 9, 2010
 *
 *   -# Added the following functions to support spcified the path that is used to invoke LitePoint Connectivity server.
 *      LP_SetLpcPath()
 *   -# IQapi version: 1.8.65
 *
 * \subsection revision_1_8_65_1 1.8.65.1
 * Date: June 9, 2010
 *
 *   -# IQapi version: 1.8.65
 *
 * \subsection revision_1_8_56_7 1.8.56.7
 * Date: July 20, 2010
 *
 *   -# Add LP_GetHandlDataPointers()
 *   -# IQapi version: 1.8.56
 * 
 * \subsection revision_1_8_56_6 1.8.56.6
 * Date: June 2, 2010
 *
 *   -# Recognize IQ201X in LP_GetVersion()
 *   -# IQapi version: 1.8.56
 *
 * \subsection revision_1_8_56_5 1.8.56.5
 * Date: May 28, 2010
 *
 *   -# Use iqapiVersion() to get version value since GetAllVersions() will crash while testers >=3
 *   -# IQapi version: 1.8.56
 *
 * \subsection revision_1_8_56_4 1.8.56.4
 * Date: April 27, 2010
 *
 *   -# Add IQlite_Logger into IQmeasure.
 *   -# IQapi version: 1.8.56
 *
 * \subsection revision_1_8_56_3 1.8.56.3
 * Date: April 14, 2010
 *
 *   -# Modify the LP_SetVsg() to take care the condition of VSG1 is disabled or enabled.
 *   -# IQapi version: 1.8.56
 *
 * \subsection revision_1_8_56_2 1.8.56.2
 * Date: March 30, 2010
 *
 *   -# Modify the LP_SetVsgCw(), since there is a bug inside IQapi, we must call SetTxRx() twice to set CW frequency offset.
 *   -# IQapi version: 1.8.56
 *
 * \subsection revision_1_8_56_1 1.8.56.1
 * Date: March 23, 2010
 *
 *   -# IQapi version: 1.8.56
 *
 * \subsection revision_1_8_52_4 1.8.52.4
 * Date: March 9, 2010
 *
 *   -# Set "frequencyCorr" for 802.11n in LP_SetAnalysisParameterInteger()
 *   -# IQapi version: 1.8.52
 *
 * \subsection revision_1_8_52_3 1.8.52.3
 * Date: February 16, 2010
 *
 *   -# Fixed a bug LP_SetVsa can cause VSG turn off.
 *   -# IQapi version: 1.8.52
 *
 * \subsection revision_1_8_52_2 1.8.52.2
 * Date: February 8, 2010
 *
 *   -# Added LP_SaveIQDataToModulationFile().
 *   -# IQapi version: 1.8.52
 *
 * \subsection revision_1_8_52_1 1.8.52.1
 * Date: January 28, 2010
 *
 *   -# Updated IQapi version to 1.8.52.
 *   -# IQapi version: 1.8.52
 *
 * \subsection revision_1_7_48_13 1.7.48.13
 * Date: January 23, 2010
 *
 *   -# Updated two function "LP_Analyze80216e()" and "LP_Analyze80216d()".
 *   -# IQapi version: 1.7.48
 *
 * \subsection revision_1_7_48_12 1.7.48.12
 * Date: January 14, 2010
 *
 *   -# Replaced NaN in code with -99999.99.
 *   -# IQapi version: 1.7.48
 *
 * \subsection revision_1_7_48_11 1.7.48.11
 * Date: January 14, 2010
 *
 *   -# Merged 1.7.48.1 and 1.7.48.10. to have both Bluetooth fixes and MIMO changes.
 *   -# IQapi version: 1.7.48
 *
 * \subsection revision_1_7_48_10 1.7.48.10
 * Date: January 04, 2010
 *
 *   -# Added the following functions to support MIMO.
 *      LP_SetAnalysisParameterIntegerArray()
 *      LP_SetAnalysisParameterInteger()
 *   -# IQapi version: 1.7.48
 *
 * \subsection revision_1_7_48_1 1.7.48.1
 * Date: December 11, 2009
 *
 *   -# Modify LP_SetAnalysisParameterInteger() to specify vsaNum in 802.11b and OFDM analysis
 *   -# IQapi version: 1.7.48
 *
 * \subsection revision_1_7_46_3 1.7.46.3
 * Date: November 24, 2009
 *
 *	 -# Removed the code setting VSG to PORT_OFF (caused IQnxn_plus not to capture properly)
 *	 -# Added define of VERY_LOW_VSG_POWER_DBM to disable VSG RF power on unwanted VSGs
 *   -# IQapi version: 1.7.46
 *
 * \subsection revision_1_7_46_2 1.7.46.2
 * Date: November 20, 2009
 *
 *	 -# The following functions were added to support IQnxn:
 *		- LP_SetVsaNxN()
 *      - LP_SetVsgNxN()
 *      - LP_EnableVsgRFNxN()
 *   -# IQapi version: 1.7.46
 *
 * \subsection revision_1_7_46_1 1.7.46.1
 * Date: November 13, 2009
 *
 *	 -# Added LP_CopyVsaCaptureData()
 *   -# Added LP_SetAnalysisParameterInteger() and LP_SetAnalysisParameterIntegerArray()
 *      to enable more analysis parameters can be specifed
 *   -# MATLAB Run-time upgraded to v79
 *   -# IQapi version: 1.7.46
 *
 * \subsection revision_1_7_13_1 1.7.13.1
 * Date: November 04, 2009
 *
 *   -# Add a internal function LP_FreeMemory() to free memory automatically when IQmeasure DLL detached.
 *   -# IQapi version: 1.7.13
 *  
 * \subsection revision_1_7_13_0 1.7.13.0
 * Date: October 14, 2009
 *
 *   -# Moved back to IQapi 1.7.13 to work with fully supported version with testers.
 *   -# IQapi version: 1.7.13
 *  
 * \subsection revision_1_8_38_2 1.8.38.2
 * Date: September 24, 2009
 *
 *   -# Remove feature of "Reuse Data Capture" to keep the IQmeasure function simple and clear.
 *   -# IQapi version: 1.8.38
 *  
 * \subsection revision_1_8_38_1 1.8.38.1
 * Date: September 17, 2009
 *
 *   -# Fixed a bug in LP_VsaDataCapture() where "g_multiCaptures.push_back(userData)" cause memory leak.
 *   -# IQapi version: 1.8.38
 *
 * \subsection revision_1_8_38_0 1.8.38.0
 * Date: September 17, 2009
 *  
 *   -# Made a few glitch fixes to work with the latest of IQapi
 *   -# IQapi version: 1.8.38
 *
 * \subsection revision_1_7_12_1_9 1.7.12.1.9
 * Date: September 01, 2009
 *  
 *   -# Added packet format support to LP_Analyze80211n()
 *   -# IQapi version: 1.7.12.1
 *
 * \subsection revision_1_7_12_1_8 1.7.12.1.8
 * Date: August 27, 2009
 *  
 *   -# Added parameter g_amplitudeToleranceDb (default=3dB) and function LP_SetVsaAmplitudeTolerance() to set amplitude tolerance of VSA. 
 *   -# IQapi version: 1.7.12.1
 *
 * \subsection revision_1_7_12_1_7 1.7.12.1.7
 * Date: August 27, 2009
 *  
 *   -# Added vector g_multiCaptures and function LP_SetCaptureReuse(), LP_Analyze() to support reuse dataCapture. 
 *   -# IQapi version: 1.7.12.1
 *
 * \subsection revision_1_7_12_1_6 1.7.12.1.6
 * Date: August 13, 2009
 *  
 *   -# Added timer support for each LP_ function
 *   -# IQapi version: 1.7.12.1
 *
 * \subsection revision_1_7_12_1_5 1.7.12.1.5
 * Date: July 21, 2009
 *  
 *   -# Added "triggerPreTime" into "LP_SetVsa()" and "LP_SetVsaBluetooth()" functions for the pre-trigger time used for signal capture.
 *   -# The following functions were added for the dual-head operation:
 *          - LP_DualHead_ConOpen()
 *          - LP_DualHead_ObtainControl()
 *          - LP_DualHead_ReleaseControl()
 *          - LP_DualHead_ConClose()
 *   -# IQapi version: 1.7.12.1
 *
 * \subsection revision_1_7_12_1_4 1.7.12.1.4
 * Date: July 17, 2009
 *
 *   -# Add "P_av_each_burst" and "P_pk_each_burst" into "LP_GetScalarMeasurement()" function for "iqapiResultBluetooth".
 *   -# IQapi version: 1.7.12.1
 *
 * \subsection revision_1_7_12_1_3 1.7.12.1.3
 * Date: July 16, 2009
 *
 *   -# Update LP_SetVsg() function, shift the baseband frequency back to zero.
 *   -# IQapi version: 1.7.12.1
 *
 * \subsection revision_1_7_12_1_2 1.7.12.1.2
 * Date: May 29, 2009
 *
 *   -# Fixed a bug in GetVectorMeasurement() where FFT analysis "x" returned 0 length
 *   -# IQapi version: 1.7.12.1
 *
 * \subsection revision_1_7_12_1_1 1.7.12.1.1
 * Date: May 26, 2009
 *
 *   -# Upgrade to IQapi 1.7.12.1
 *   -# IQapi version: 1.7.12.1
 *
 * \subsection revision_1_7_10_2 1.7.10.2
 * Date: May 15, 2009
 *
 *   -# Added LP_SetVsaBluetooth() for support Bluetooth data capture and analysis.
 *   -# IQapi version: 1.7.10
 *
 * \subsection revision_1_7_10_1 1.7.10.1
 * Date: April 17, 2009
 *
 *   -# Added LP_AnalyzeHT40Mask() to support HT40 spectrum mask analysis.  In order to do so, 
 *      ht40Mode in LP_VsaDataCapture() needs to set to 1.
 *   -# Added LP_TxDone() to check if VSG transmission is done
 *   -# Added one more parameter to LP_Plot() to allow multiple curves in the same window.  Default value
 *      for this parameter (keepPlot) is 0.
 *   -# IQapi version: 1.7.10
 *
 * \subsection revision_1_6_2_3 1.6.2.3
 * Date: Mar 25, 2009
 *
 *   -# Changed the VSA power mode to peak power mode (IQV_VSA_TYPE_1)
 *   -# IQapi version: 1.6.2
 *
 * \subsection revision_1_6_2_2 1.6.2.2
 * Date: Feb 20, 2009
 *
 *   -# First release of IQmeasure source code
 *   -# IQapi version: 1.6.2
 *
 */

/*! \file IQmeasure.h
 * \brief IQmeasure Library Interface functions 
 */ 

/*! @defgroup group1 How to make an accurate measurement?
 * \image html AmplSweepWithIdealSignal.gif "Sweeping ampl Setting with Ideal Signal" width=300
 */

/*! @defgroup group2 How to re-use the capture for multiple analysis?
 * 
 */

/*! @defgroup group3 How to transmit a waveform continuously?
 * 
 */

/*! @defgroup group4 What is Packet Engine?
 * 
 */

#ifndef _IQMEASURE_H_
#define _IQMEASURE_H_

/* IQmeasure version follows the IQapi version by appending its own number.
 * For example, if IQapi version is 1.8.65, IQmeasure version will be:
 *      1.8.65.n (yyyy-mm-dd)
 *      Note: n starts with 1
 */
#define IQMeasureVersion                "1 (2012-3-13)"	// Modified /* -cfy@sunnyvale, 2012/3/13- */

#ifndef WIN32
	#define IQMEASURE_API extern "C"
#elif defined( IQMEASURE_EXPORTS )
	#define IQMEASURE_API extern "C" __declspec(dllexport)
#else
	#define IQMEASURE_API extern "C" __declspec(dllimport)
#endif

#include "iqapiDefines.h"

IQMEASURE_API enum IQAPI_PORT_ENUM
{
    PORT_OFF   = 1,                       /*!< Port has been disabled. */
    PORT_LEFT  = 2,                       /*!< RF uses left port(RF1).      */
    PORT_RIGHT = 3,                       /*!< RF uses right port(RF2).     */
    PORT_BB    = 4						  /*!< BB ports in use.        */
};

IQMEASURE_API enum LP_ANALYSIS_TYPE_ENUM
{
	ANALYSIS_80211AG,                    /*!< 802.11a/g analysis*/ 
	ANALYSIS_80211B,                     /*!< 802.11b analysis*/
	ANALYSIS_MIMO,                       /*!< 802.11n MIMO analysis*/
	ANALYSIS_POWER,                      /*!< Power analysis*/
	ANALYSIS_FFT,                        /*!< FFT analysis*/
	ANALYSIS_CCDF,                       /*!< CCDF analysis*/
	ANALYSIS_CW,                         /*!< CW analysis*/
	ANALYSIS_WAVE,                       /*!< Wave analysis*/
	ANALYSIS_SIDELOBE,                   /*!< Sidelobe analysis*/
	ANALYSIS_POWERRAMPOFDM,              /*!< Power Ramp analysis for OFDM*/
	ANALYSIS_POWERRAMP80211B,            /*!< Power Ramp analysis for 802.11b*/
	ANALYSIS_BLUETOOTH,                  /*!< Bluetooth analysis*/
	ANALYSIS_ZIGBEE,                     /*!< Zigbee analysis*/
	ANALYSIS_HT40,                       /*!< 802.11n HT40 spectrum mask analysis*/
	ANALYSIS_80211p,					 /*!< 802.11p analysis*/
	ANALYSIS_MAX_NUM                     /*!< Invalid analysis type*/
};

IQMEASURE_API enum LP_MEASUREMENT_VSG_MODE
{
    VSG_NO_MOD_FILE_LOADED = 0,             /*!< No MOD file has been loaded*/
    VSG_SINGLE_MOD_FILE,                    /*!< Single MOD file has been loaded*/
    VSG_MULTI_SEGMENT_MOD_FILE,             /*!< Multi-segment MOD file has been loaded*/
    VSG_INVALID_MODE                        /*!< Invalid VSG mode*/
};

#define MAX_MPTA_PORTS			4
#define VERY_LOW_VSG_POWER_DBM	-110

#ifndef ON
#define ON 1
#endif

#ifndef OFF
#define OFF 0
#endif

// FM definitions

//FM VSA 

//VSA Capture Sample Rate 
enum {SAMPLE_640KHz, SAMPLE_5_12MHz};

//FM Filter Selection
enum {BLACKMAN_HARRIS, HANNING, FLAT_TOP};

//FM Mode Selection
enum {FM_MONO, FM_STEREO, FM_AUTO};

// FM Pre-emphasis Time Constant Select
enum {PRE_EMPHASIS_NONE, PRE_EMPHASIS_25US, PRE_EMPHASIS_50US, PRE_EMPHASIS_75US};

// RDS Phase Shift Selection
enum {RDS_PHASE_SHIFT_NONE, RDS_PHASE_SHIFT_90};

// FM Channel Selection
//Note: LEFT_EQUALS_RIGHT and LEFT_EQUALS_MINUS_RIGHT can be used only for generating audio stimulus for FM RX Test.
// It cannot be used for setting up VSG Tones.

enum {LEFT_ONLY, RIGHT_ONLY, LEFT_RIGHT, LEFT_EQUALS_RIGHT, LEFT_EQUALS_MINUS_RIGHT};


IQMEASURE_API enum IQAPI_ALC_MODES
{
	ALC_MANUAL,	// Indicates ALC Manual is on
	/* This is the default value */
	ALC_AUTO_ON_TIMEOUT, // Indicates ALC Automatic on Timeout
	ALC_OFF,		// Indicates that ALC is off 
	ALC_MANUAL_HIGH_PRECISION
};

IQMEASURE_API enum IQMEASURE_ERROR_CODES
{
	ERR_OK,
	ERR_NO_CONNECTION,
	ERR_NOT_INITIALIZED,
	ERR_SAVE_WAVE_FAILED,
	ERR_LOAD_WAVE_FAILED,
	ERR_SET_TX_FAILED,
	ERR_SET_WAVE_FAILED,
	ERR_SET_RX_FAILED,
	ERR_CAPTURE_FAILED,
	ERR_NO_CAPTURE_DATA,
	ERR_VSA_NUM_OUT_OF_RANGE,
	ERR_ANALYSIS_FAILED,
	ERR_NO_VALID_ANALYSIS,
	ERR_VSG_PORT_IS_OFF,
    ERR_NO_MOD_FILE_LOADED,
    ERR_NO_CONT_FOR_MULTI_SEGMENT,
    ERR_MEASUREMENT_NAME_NOT_FOUND,
    ERR_INVALID_ANALYSIS_TYPE,
    ERR_NO_ANALYSIS_RESULT_AVAILABLE,
    ERR_NO_MEASUREMENT_RESULT,
    ERR_INVALID_IP_ADDRESS,
    ERR_GENERAL_ERR,
	ERR_TX_NOT_DONE,
    ERR_SET_TOKEN_FAILED,
    ERR_TOKEN_RETRIEVAL_TIMEDOUT,
	ERR_INVALID_CAPTURE_INDEX,
	ERR_VSG_POWER_EXCEED_LIMIT,
    ERR_ANALYSIS_NULL_POINTER,
    ERR_ANALYSIS_UNSUPPORTED_PARAM_NAME,
    ERR_ANALYSIS_INVALID_PARAM_VALUE,
	ERR_INVALID_DATA_CAPTURE_RANGE,
	ERR_DATARATE_DOES_NOT_EXIST,
	ERR_BUFFER_OVERFLOW,
	ERR_SET_PATH_NOT_DONE,
    //FM Error Codes
	ERR_FM_NOT_INITIALIZED,
	ERR_FM_SET_TX_FAILED,
	ERR_FM_GET_TX_FAILED,
	ERR_FM_SET_AUDIO_TONE_FAILED,
	ERR_FM_GET_AUDIO_TONE_FAILED,
	ERR_FM_NO_CAPTURE_DATA,
	ERR_FM_VSA_CAPTURE_FAILED,
	ERR_FM_SET_RX_FAILED,
	ERR_FM_GET_RX_FAILED,
	ERR_FM_ANALYSIS_FAILED,
	ERR_FM_CAPTURE_AUDIO_FAILED,
	ERR_FM_GENERATE_AUDIO_FAILED,
	ERR_FM_QUERY_AIM_FAILED,
	ERR_FM_SAVE_WAV_AUDIO_FAILED,
	ERR_FM_PLAY_AUDIO_FAILED,
	ERR_FM_LOAD_AUDIO_FAILED,
	ERR_FM_STOP_AUDIO_PLAY_FAILED,
	ERR_GPS,
	ERR_SET_MULTI_THREAD_FAILED
};

IQMEASURE_API enum IQMEASURE_CAPTURE_NONBLOCKING_STATES
{
	BLOCKING,	// NONBLOCKING is off
	ARM_TRIGGER,
	CHECK_DATA
};

/*********************/
/* Internal function */
/*********************/
int LP_Analyze(void);
//FM
int LP_Analyze_FMHndl(void);
int LP_FreeMemory(void);

/******************/
/* Error handling */
/******************/
IQMEASURE_API char *LP_GetErrorString(int err);
IQMEASURE_API char *LP_GetIQapiHndlLastErrMsg();

/***************************/
/* Init and Term Functions */
/***************************/

//! Initializes the MATLAB environment for running IQmeasure
/*!
 * \return 0 if MATLAB initialized OK; non-zero indicates MATLAB failed to initialize.
 * \remakr This function needs to be run only once, typically at the very beginning of a program.
 */
IQMEASURE_API int  LP_Init(void);


//! Terminates the MATLAB environment
/*!
 * \return 0 if MATLAB initialized OK; non-zero indicates MATLAB failed to terminate.
 * \remark This function only needs to be run at the very end when a programm is going to exit.
 *         Calling this function in the middle of a program will cause the program not to function.
 *         Since the programm is exiting anyway, you may skip calling LP_Term().
 */
IQMEASURE_API int  LP_Term(void);


//! Gets the IQapi handle and tester initialized status
/*!
* \param[in] getHndl Pointer to IQapi handle
* \param[in] testerInitialized Pointer to tester initialized status
*
* \return always return ERR_OK
*/
IQMEASURE_API int LP_GetIQapiHndl(void **getHndl, bool *testerInitialized);

//! Gets the version information
/*!
 * \param[out] buffer The buffer that will return the version information
 * \param[in] buf_size Indicates the size of the buffer
 *
 */
IQMEASURE_API bool LP_GetVersion(char *buffer, int buf_size);


/*********************************/
/* Connection Handling Functions */
/*********************************/


//! Initializes a tester
/*! 
 * \param[in] ipAddress The IP address of the tester or Serial Number of the IQ2010 Tester - Note Serial number works only for IQ2010 Testers
 *
 * \return ERR_OK if the tester has been successfully initialized; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_InitTester(char *ipAddress);


//! Initializes a 2x2 802.11n setup
/*!
 * \param[in] ipAddress1 The IP address of the master tester or Serial Number of the IQ2010 Tester - Note Serial number works only for IQ2010 Testers
 * \param[in] ipAddress2 The IP address of the slave tester or Serial Number of the IQ2010 Tester - Note Serial number works only for IQ2010 Testers
 *
 * \return ERR_OK if testers has been successfully initialized; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_InitTester2(char *ipAddress1, char *ipAddress2);


//! Initializes a 3x3 802.11n setup
/*!
 * \param[in] ipAddress1 The IP address of the master tester or Serial Number of the IQ2010 Tester - Note Serial number works only for IQ2010 Testers
 * \param[in] ipAddress2 The IP address of the slave tester or Serial Number of the IQ2010 Tester - Note Serial number works only for IQ2010 Testers
 * \param[in] ipAddress3 The IP address of the slave tester or Serial Number of the IQ2010 Tester - Note Serial number works only for IQ2010 Testers
 *
 * \return ERR_OK if testers has been successfully initialized; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_InitTester3(char *ipAddress1, char *ipAddress2, char *ipAddress3);


//! Initializes a 4x4 802.11n setup
/*!
 * \param[in] ipAddress1 The IP address of the master tester or Serial Number of the IQ2010 Tester - Note Serial number works only for IQ2010 Testers
 * \param[in] ipAddress2 The IP address of the slave tester or Serial Number of the IQ2010 Tester - Note Serial number works only for IQ2010 Testers
 * \param[in] ipAddress3 The IP address of the slave tester or Serial Number of the IQ2010 Tester - Note Serial number works only for IQ2010 Testers
 * \param[in] ipAddress4 The IP address of the slave tester or Serial Number of the IQ2010 Tester - Note Serial number works only for IQ2010 Testers
 *
 * \return ERR_OK if testers has been successfully initialized; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_InitTester4(char *ipAddress1, char *ipAddress2, char *ipAddress3, char *ipAddress4);


//! Closes the connection to tester(s)
/*!
 * \return ERR_OK if the tester has been successfully initialized; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_ConClose(void);


//! Re-establish the connection to tester(s)
/*!
 * \return ERR_OK if the tester has been successfully initialized; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_ConOpen(void);


//! Establish the connection to tester(s) with dual-head support
/*!
 * \return ERR_OK if the tester has been successfully initialized; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_DualHead_ConOpen(int tokenID, char *ipAddress1, char *ipAddress2=NULL, char *ipAddress3=NULL, char *ipAddress4=NULL);


//! Retrieve the Token ID being used for dual-head operation
/*!
 * \return ERR_OK if the tester has been successfully initialized; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_DualHead_GetTokenID(int *tokenID);


IQMEASURE_API int LP_DualHead_ConClose();

//! Obtain the control of tester(s) for dual-head operation
/*!
 * \return ERR_OK if the tester has been successfully initialized; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_DualHead_ObtainControl(unsigned int probeTimeMS=100, unsigned int timeOutMS=0);


//! Release the control of tester(s) for dual-head operation
/*!
 * \return ERR_OK if the tester has been successfully initialized; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_DualHead_ReleaseControl();


/********************************/
/* Instrument Control Functions */
/********************************/
IQMEASURE_API int LP_SetAlcMode(IQAPI_ALC_MODES alcMode);
IQMEASURE_API int LP_GetAlcMode(IQAPI_ALC_MODES* alcMode);


//! Sets up VSG
/*!
 * \param[in] rfFreqHz The center frequency of VSG (Hz)
 * \param[in] rfGainDb The output power level of VSG (dBm)
 * \param[in] port The port to which the VSG connects, with the following options:
 *				- =1: OFF
 *				- =2: Left RF port (RF1)
 *				- =3: Right RF port (RF2) (Default)
 *				- =4: Baseband
 *
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SetVsg(double rfFreqHz, double rfPowerLeveldBm, int port, bool setGapPowerOff = true);

//! Sets up VSG Compensation Table
/*!
 * \param[in] dcErrI I part of the DC compensation
 * \param[in] dcErrQ Q part of the DC compensation
 * \param[in] phaseErr Phase compensation
 * \param[in] gainErr Gain compensation
 * \param[in] delayErr Delay compensation
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SetVsg_Compensation(double		  dcErrI,
										 double		  dcErrQ,
										 double		  phaseErr,
										 double		  gainErr,
										 double		  delayErr);
										 
//! Sets up VSG triggerType
/*!
 * \param[in] triggerType Select VSG trigger Type. 0 = IQV_VSG_TRIG_FREE_RUN; 1 = IQV_VSG_TRIG_EXT_1; 2 = IQV_VSG_TRIG_EXT_2
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SetVsgTriggerType(int triggerType);

//! Sets up VSG including gapPOwerrOff parameter
/*!
 * \param[in] rfFreqHz The center frequency of VSG (Hz)
 * \param[in] rfGainDb The output power level of VSG (dBm)
 * \param[in] port The port to which the VSG connects, with the following options:
 *				- =1: OFF
 *				- =2: Left RF port (RF1)
 *				- =3: Right RF port (RF2) (Default)
 *				- =4: Baseband
 * \param[in] gapPowerOff Turn the GapPowerOff feature On and Off On = 0( means that gap power is Off) Off = 1( means gap power is On)
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SetVsg_GapPower(double rfFreqHz, double rfPowerLeveldBm, int port, int gapPowerOff);

//! Sets up VSGs for IQnxn
/*!
 * \param[in] rfFreqHz The center frequency of all VSGs (Hz)
 * \param[in] rfGainDb[4] The output power levels of VSGs (dBm).  There must be 4 elements in the double array
 * \param[in] port[4] The port to which the VSGs connect. A 4 integer array, with the following options for each element:
 *				- =1: OFF
 *				- =2: Left RF port (RF1)
 *				- =3: Right RF port (RF2) (Default)
 *				- =4: Baseband
 *
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SetVsgNxN(double rfFreqHz, double rfPowerLeveldBm[], int port[]);

//! Sets up VSG for transmitting CW
/*!
 * \param[in] sineFreqHz The center frequency of VSG (Hz)
 * \param[in] offsetFrequencyMHz The offset frequency to the center.  The generated CW frequency (Hz) = sineFreqHz + offsetFrequencyMHz * 1e6
 * \param[in] rfPowerLeveldBm The output power level of CW (dBm)
 * \param[in] port The port to which the VSG connects, with the following options:
 *				- =1: OFF
 *				- =2: Left RF port (RF1)
 *				- =3: Right RF port (RF2) (Default)
 *				- =4: Baseband
 *
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SetVsgCw(double sineFreqHz, double offsetFrequencyMHz, double rfPowerLeveldBm, int port);

//! Saves Signal Arrays
/*!
 * \param[in] real[N_MAX_TESTERS]
 * \param[in] imag[N_MAX_TESTERS]
 * \param[in] length[N_MAX_TESTERS]
 * \param[in] sampleFreqHz[N_MAX_TESTERS]
 * \param[in] fileNameToSave
 *
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SaveSignalArrays(double *real[N_MAX_TESTERS],
									  double *imag[N_MAX_TESTERS],
									  int length[N_MAX_TESTERS],
									  double sampleFreqHz[N_MAX_TESTERS],
									  char *fileNameToSave);

//! Save I/Q data in memory to MOD file and load to the VSG memory
/*!
 * \param[in] real A double pointer to the I data in memory, for multiple streams
 * \param[in] imag A double pointer to the Q data in memory, for multiple streams
 * \param[in] length An integer array indicating the I/Q data length for each stream
 * \param[in] modFileName The modulation file name
 * \param[in] normalization A flag indicating if normalization is needed.
 *				- 1=Normalize I/Q data (RMS power = 0dBm)
 *				- 0=Do not normalize I/Q data
 * \param[in] loadIQDataToVsg A flag indicating if the I/Q data will be loaded to VSG.
 *				- 1=load I/Q data to VSG
 *				- 0=do not load I/Q data to VSG
 *
 * \return ERR_OK if the function runs OK; otherwise call LP_GetErrorString() for detailed error message.
 *
 * \remark
 *         -# The sampling rate for I/Q data has to be 80MHz
 *         -# For multiple stream I/Q, "real" and "imag" assumes that two dimentional double
 *			  arrays are constructed in memory, the first dimension indicating number of streams, and
 *			  second dimension indicating the length of I/Q data, specified by the length array.
 */
IQMEASURE_API int LP_SaveIQDataToModulationFile(double *real,
												double *imag,
												int length[N_MAX_TESTERS],
												char *modFileName,
												int  normalization,
												int loadIQDataToVsg);

//! Loads the modulation file (waveform) to VSG and performs auto transmit of the loaded VSG mod file in free run mode
/*!
 * \param[in] modFileName The .mod file to be loaded
 *
 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SetVsgModulation(char *modFileName);

//! Set VSA integer parameter before doing analysis
/*!
 * \param[in] measurement The measurement name.  Please refer to \ref group_analysis_name "Analysis Name" for all available analysis names
 * \param[in] parameter The parameter will specify which VSA parameter will be set.
 * \param[in] value The int value will be set in VSA.
 *
 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SetAnalysisParameterInteger(char *measurement, char *parameter, int value);

//! Set VSA integer array before doing analysis
/*!
 * \param[in] measurement The measurement name.  Please refer to \ref group_analysis_name "Analysis Name" for all available analysis names
 * \param[in] parameter The parameter will specify which VSA parameter will be set.
 * \param[in] value The Integer array will be set in VSA.
 * \param[in] valuesize The size of integer array.
 *
 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SetAnalysisParameterIntegerArray(char *measurement, char *parameter, int *value, int valuesize);


//! Copy one VSA capture data to another
/*!
 * \param[in] fromVsaNum The VSA number from which data capture will be copied.  Valid values are 1,2,3, or 4.
 * \param[in] toVsaNum The VSA number to which data capture will be copied.  Valid values are 1,2,3, or 4.
 *
 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 * \remark Both VSAs have to contain capture data, with the same length.
 */
IQMEASURE_API int LP_CopyVsaCaptureData(int fromVsaNum, int toVsaNum);


//! Saves the captured data to a file (.sig)
/*!
 * \param[in] sigFileName Specifies the .sig file name
 *
 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SaveVsaSignalFile(char *sigFileName);


//! Saves the captured data to a txt file (.txt)
/*!
* \param[in] sigFileName Specifies the .sig file name
*
* \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
*/
IQMEASURE_API int LP_SaveVsaSignalFileText(char *txtFileName);


//! Loads the signal file (.sig) for analysis
/*!
 * \param[in] sigFileName The path for the signal (.sig) file to be loaded
 *
 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_LoadVsaSignalFile(char *sigFileName);



//! Saves the captured data into .mod (For VSG to play)
/*!
 * \param[in] modFileName The path for the signal (.mod) file to be saved
 *
 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 * \remark When a captured data is saved to a .mod file, the average power level will be normalized to 0dBm.
 */
IQMEASURE_API int LP_SaveVsaGeneratorFile(char *modFileName);


//! Sets up VSA for Bluetooth data capturing
/*!
 * \param[in] rfFreqHz The center frequency of Bluetooth RF signal (Hz)
 * \param[in] rfAmplDb The amplitude of the peak power (dBm) of the signal
 * \param[in] port The port to which the VSG connects, with the following options:
 *				- =1: OFF
 *				- =2: Left RF port (RF1) (Default)
 *				- =3: Right RF port (RF2)
 *				- =4: Baseband
 * \param[in] triggerLevelDb The trigger level (dBm) used for signal trigger (ignored in Free-run and External Trigger Modes)
 * \param[in] triggerPreTime The pre-trigger time used for signal capture
 *
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 * \remark For VSA to work optimally with the input signal, set rfAmplDb to the peak power of the input signal.
 */
IQMEASURE_API int LP_SetVsaBluetooth(double rfFreqHz, double rfAmplDb, int port, double triggerLevelDb=-25, double triggerPreTime=10e-6);


//! Sets up VSA for data capturing
/*!
 * \param[in] rfFreqHz The center frequency of VSA (Hz)
 * \param[in] rfAmplDb The amplitude of the peak power (dBm) for VSA to work with
 * \param[in] port The port to which the VSG connects, with the following options:
 *				- =1: OFF
 *				- =2: Left RF port (RF1) (Default)
 *				- =3: Right RF port (RF2)
 *				- =4: Baseband
 * \param[in] extAttenDb The external attenuation (dB).  Set to 0 always.
 * \param[in] triggerLevelDb The trigger level (dBm) used for signal trigger (ignored in Free-run and External Trigger Modes)
 * \param[in] triggerPreTime The pre-trigger time used for signal capture
 *
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 * \remark For VSA to work optimally with the input signal, set rfAmplDb to the peak power of the input signal.
 */
IQMEASURE_API int LP_SetVsa(double rfFreqHz, double rfAmplDb, int port, double extAttenDb=0, double triggerLevelDb=-25, double triggerPreTime=10e-6);

IQMEASURE_API int LP_SetVsaTriggerTimeout(double triggerTimeoutSec);


//! Sets up VSAs for IQnxn
/*!
 * \param[in] rfFreqHz The center frequency of VSA (Hz)
 * \param[in] rfAmplDb[4] The amplitude of the peak power (dBm) for VSA to work with.  A 4 double array.
 * \param[in] port[4] The port to which the VSG connects. A 4 integer array, with the following options for each element:
 *				- =1: OFF
 *				- =2: Left RF port (RF1) (Default)
 *				- =3: Right RF port (RF2)
 *				- =4: Baseband
 * \param[in] extAttenDb The external attenuation (dB).  Set to 0 always.
 * \param[in] triggerLevelDb The trigger level (dBm) used for signal trigger (ignored in Free-run and External Trigger Modes)
 * \param[in] triggerPreTime The pre-trigger time used for signal capture
 *
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 * \remark For VSA to work optimally with the input signal, set rfAmplDb to the peak power of the input signal.
 */
IQMEASURE_API int LP_SetVsaNxN(double rfFreqHz, double rfAmplDb[], int port[], double extAttenDb=0, double triggerLevelDb=-25, double triggerPreTime=10e-6);


//! Set Vsa amplitude tolerance in dB
/*!
 * \param[in] amplitudeToleranceDb, the setting of Vsa amplitude tolerance
 *
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SetVsaAmplitudeTolerance(double amplitudeToleranceDb);


//! Performs AGC (Automatic Gain Control) on VSA
/*!
 * \param[out] rfAmplDb The setting of rfAmplDb of VSA set by AGC
 *
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_Agc(double *rfAmplDb, bool allTesters = false); // Modified /* -cfy@sunnyvale, 2012/3/13- */



//! Sets up the number of frames for VSG to transmit
/*!
 * \param[in] frameCnt The number of frames to be transmitted between 0 and 65534, where "0" indicates continuous transmission
 *
 * \return ERR_OK if number of frames accepted; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SetFrameCnt(int frameCnt);


IQMEASURE_API int LP_TxDone(void);


//! Turn ON/OFF the first VSG RF
/*!
 * \param[in] enabled 1 to turn on the first VSG RF; 0 to turn off the first VSG RF
 *
 * \return ERR_OK if the first VSG RF is turned on or off; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_EnableVsgRF(int enabled);


//! Turn ON/OFF the VSG RF for IQnxn
/*!
 * \param[in] vsg1Enabled 1 to turn on the first VSG RF; 0 to turn off the first VSG RF
 * \param[in] vsg2Enabled 1 to turn on the second VSG RF; 0 to turn off the second VSG RF
 * \param[in] vsg3Enabled 1 to turn on the third VSG RF; 0 to turn off the third VSG RF
 * \param[in] vsg4Enabled 1 to turn on the fourth VSG RF; 0 to turn off the fourth VSG RF
 *
 * \return ERR_OK if the first VSG RF is turned on or off; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_EnableVsgRFNxN(int vsg1Enabled, int vsg2Enabled, int vsg3Enabled, int vsg4Enabled);

//! Turn ON/OFF the specified VSG RF
/*!
 * \param[in] enabled 1 to turn on the specified VSG RF; 0 to turn off the specified VSG RF
 * \param[in] vsgNumber The specified VSG.
 *
 * \return ERR_OK if the specified VSG RF is turned on or off; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_EnableSpecifiedVsgRF(int enabled, int vsgNumber);

//! Turn ON/OFF the specified VSA RF
/*!
 * \param[in] enabled 1 to turn on the specified VSA RF; 0 to turn off the specified VSA RF
 * \param[in] vsaNumber The specified VSA.
 *
 * \return ERR_OK if the specified VSA RF is turned on or off; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_EnableSpecifiedVsaRF(int enabled, int vsaNumber);

//! Return the VSA settings
/*!
 * \param[out] freqHz VSA frequency (Hz) setting
 * \param[out] ampl VSA amplitude (dBm);
 * \param[out] port VSA port: 1=PORT_OFF, 2=PORT_LEFT, 3=PORT_RIGHT, 4=PORT_BB;
 * \param[out] rfEnabled VSA RF state: 0=disalbed; 1=enabled
 * \param[out] triggerLevel VSA trigger level
 *
 * \return ERR_OK if the VSA settings are returned; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_GetVsaSettings(double *freqHz, double *ampl, IQAPI_PORT_ENUM *port, int *rfEnabled, double *triggerLevel);


//! Perform VSA data capture
/*!
 * \param[in] samplingTimeSecs Capture time in seconds
 * \param[in] triggerType Trigger type used for capturing.  Valid options are:
 *      - 1 = Free-run
 *      - 2 = External trigger
 *      - 6 = Signal Trigger
 * \param[optinal] modeHT40 Specifies if the capture is for the HT40 mask (802.11n only).  1--HT40 mask mode; 0--Normal mode
 *
 * \return ERR_OK if the data capture is successful; otherwise call LP_GetErrorString() for detailed error message.
 * \remark modeHT40 only needs to set to 1 if the HT40 mask (120MHz) analysis is desired.  For LP_Analyze80211n(), this flag can be set to 0.
 */
IQMEASURE_API int LP_VsaDataCapture(double samplingTimeSecs, int triggerType=6, double sampleFreqHz=80e6, int ht40Mode=OFF, IQMEASURE_CAPTURE_NONBLOCKING_STATES nonBlockingState=BLOCKING );


//! Retrieves the captured I/Q raw data from VSA
/*!
 * \param[in] vsaNum Number of VSA (0-3)
 * \param[out] bufferReal[] Returns I samples
 * \param[out] bufferImag[] Returns Q samples
 * \param[in] bufferLength Indicates the length of bufferReal and bufferImag (in bytes)
 *
 * \return ERR_OK if no erros; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_GetSampleData(int vsaNum, double bufferReal[], double bufferImag[], int bufferLength);

//! Get memory addresses for a capture
/*!
 * \param[out] real[] Returns I samples.
 * \param[out] imag[] Returns Q samples.
 * \param[out] length[] Returnes length.
 * \param[in] arraySize Size of array real[], imag[], and length[]
 *
 * \return ERR_OK if no erros; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_GetHndlDataPointers(double *real[],double *imag[],int *length, double *sampleFreqHz, int arraySize);


//! Save I/Q samples in user's memory to LP sig file
/*!
 * \param[in] sigFileName The .sig file name
 * \param[in] real[] start pointer of I samples.
 * \param[in] imag[] start pointer of Q samples.
 * \param[in] length[] Length.
 * \param[in] arraySize Size of array real[], imag[], and length[]
 *
 * \return ERR_OK if no erros; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SaveUserDataToSigFile(char* sigFileName,
                                           double *real[],
                                           double *imag[],
                                           int *length,
                                           double *sampleFreqHz,
                                           int arraySize);


//! Select a portion of the capture for analysis
/*!
 * \param[in] startPositionUs Start position in the capture (us) for analysis
 * \param[in] lengthUs The length (us) in the capture for analysis
 *
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SelectCaptureRangeForAnalysis(double startPositionUs, double lengthUs);

//! Saves the selected captured data range to a file (.sig)
/*!
 * \param[in] sigFileName Specifies the .sig file name
 *
 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SaveTruncateCapture(char *sigFileName);

// Analysis Functions (TODO: Bluetooth)


//! Perform 802.16d Analysis on current capture
/*!
 * \param[in] sigType Indicates the type of signal. Default: -1
 *		      Valid values are as follows:
 *		      1=downlink signal
 *		      2=uplink signal
 *		     -1=auto-detect
 * \param[in] bandwidthHz Indicates signal bandwidth. Default: -1
 *		      Valid values for the signal bandwidth are as follows:
 *		      -1, 1.25, 1.5, 1.75, 2.5, 3, 3.5, 5, 5.5, 6, 7, 8.75, 10, 11, 12, 14, 15, 20
 *		      -1=auto detect
 * \param[in] cyclicPrefix Indicates signal cyclic prefix ratio. Default: -1
 *            Valid values for signal cyclic prefix ratio are as follows: -1, 1/4, 1/8, 1/16, 1/32
 *            -1=auto detect
 * \param[in] rateId Indicates signal modulation rate. Default: -1
 *            Valid values for signal modulation rate are as follows: 0, 1, 2, 3, 4, 5, 6 and
 *            correspond to {BPSK 1/2, QPSK 1/2, QPSK 3/4, 16-QAM 1/2, 16-QAM 3/4, 64-QAM 2/3, 64-QAM 3/4}, respectively
 *            -1=auto detect
 * \param[in] numSymbols Number of OFDM symbols in burst. Default: -1
 *            -1=auto detect
 * \param[in] ph_corr Phase Correction Mode with the following valid options:
 *         - 1: Phase correction off
 *         - 2: Symbol-by-symbol correction (Default)
 *         - 3: Moving avg. correction (10 symbols)
 * \param[in] ch_corr Channel Estimate with the following options:
 *         - 1: Raw Channel Estimate (based on long trainling symbols) (Default)
 *         - 2: 2nd Order Polyfit
 *         - 3: Full packet estimate
 * \param[in] freq_corr Frequency Sync. Mode with the following options:
 *         - 1: Short Training Symbol
 *         - 2: Long Training Symbol (Default)
 *         - 3: Full Data Packet
 * \param[in] timing_corr Symbol Timing Correction with the following options:
 *         - 1: Symbol Timing Correction Off
 *         - 2: Symbol Timing Correction ON (Default)
 * \param[in] ampl_track Amplitude Tracking with the following options:
 *         - 1: Amplitude tracking off (Default)
 *         - 2: Amplitude tracking on
 * \param[in] decode Decode the payload or not //TODO: check decode
 *         - 0: Decode OFF (Default)
 *         - 1: Decode ON
 *
 * \return ERR_OK if the 802.16d analysis succeeded; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_Analyze80216d( double sigType		= -1,
								    double bandwidthHz	= -1,
									double cyclicPrefix	= -1,
									double rateId		= -1,
									double numSymbols	= -1,
								    int ph_corr			= 2,
								    int ch_corr			= 1,
								    int freq_corr		= 2,
								    int timing_corr		= 2,
								    int ampl_track		= 1,
								    double decode		= 0
								    );

//! Perform 802.16e Analysis on current capture
/*!
 * \param[in] sigType Indicates the type of signal. Default: -1
 *		      Valid values are as follows:
 *		      1=downlink signal
 *		      2=uplink signal
 *		     -1=auto-detect
 * \param[in] bandwidthHz Indicates signal bandwidth. Default: -1
 *		      Valid values for the signal bandwidth are as follows:
 *		      -1, 1.25, 1.5, 1.75, 2.5, 3, 3.5, 5, 5.5, 6, 7, 8.75, 10, 11, 12, 14, 15, 20
 *		      -1=auto detect
 * \param[in] cyclicPrefix Indicates signal cyclic prefix ratio. Default: -1
 *            Valid values for signal cyclic prefix ratio are as follows: -1, 1/4, 1/8, 1/16, 1/32
 *            -1=auto detect
 * \param[in] rateId Indicates signal modulation rate. Default: -1
 *            Valid values for signal modulation rate are as follows: 0, 1, 2, 3, 4, 5, 6 and
 *            correspond to {BPSK 1/2, QPSK 1/2, QPSK 3/4, 16-QAM 1/2, 16-QAM 3/4, 64-QAM 2/3, 64-QAM 3/4}, respectively
 *            -1=auto detect
 * \param[in] numSymbols Number of OFDM symbols in burst. Default: -1
 *            -1=auto detect
 * \param[in] ph_corr Phase Correction Mode with the following valid options:
 *         - 1: Phase correction off
 *         - 2: Symbol-by-symbol correction (Default)
 *         - 3: Moving avg. correction (10 symbols)
 * \param[in] ch_corr Channel Estimate with the following options:
 *         - 1: Raw Channel Estimate (based on long trainling symbols) (Default)
 *         - 2: 2nd Order Polyfit
 *         - 3: Full packet estimate
 * \param[in] freq_corr Frequency Sync. Mode with the following options:
 *         - 1: Short Training Symbol
 *         - 2: Long Training Symbol (Default)
 *         - 3: Full Data Packet
 * \param[in] timing_corr Symbol Timing Correction with the following options:
 *         - 1: Symbol Timing Correction Off
 *         - 2: Symbol Timing Correction ON (Default)
 * \param[in] ampl_track Amplitude Tracking with the following options:
 *         - 1: Amplitude tracking off (Default)
 *         - 2: Amplitude tracking on
 * \param[in] decode Decode the payload or not //TODO: check decode
 *         - 0: Decode OFF (Default)
 *         - 1: Decode ON
 * \param[in] map_conf_file The map configuration file.
 *
 * \return ERR_OK if the 802.16e analysis succeeded; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_Analyze80216e( double sigType		= -1,
								    double bandwidthHz	= -1,
									double cyclicPrefix	= -1,
									double rateId		= -1,
									double numSymbols	= -1,
								    int ph_corr			= 2,
								    int ch_corr			= 1,
								    int freq_corr		= 2,
								    int timing_corr		= 2,
								    int ampl_track		= 1,
								    double decode		= 0,
								    char *map_conf_file = NULL
									);

//! Perform 802.11p Analysis on current capture
/*!
 * \param[in] ph_corr_mode Phase Correction Mode with the following valid options:
 *         - 1: Phase correction off
 *         - 2: Symbol-by-symbol correction (Default)
 *         - 3: Moving avg. correction (10 symbols)
 * \param[in] ch_estimate Channel Estimate with the following options:
 *         - 1: Raw Channel Estimate (based on long trainling symbols) (Default)
 *         - 2: 2nd Order Polyfit
 *         - 3: Full packet estimate
 * \param[in] sym_tim_corr Symbol Timing Correction with the following options:
 *         - 1: Symbol Timing Correction Off
 *         - 2: Symbol Timing Correction ON (Default)
 * \param[in] freq_sync Frequency Sync. Mode with the following options:
 *         - 1: Short Training Symbol
 *         - 2: Long Training Symbol (Default)
 *         - 3: Full Data Packet
 * \param[in] ampl_track Amplitude Tracking with the following options:
 *         - 1: Amplitude tracking off (Default)
 *         - 2: Amplitude tracking on
 * \param[in] ofdm_mode Specifies OFDM mode with the following options:
 *         - 0: OFDM mode based on IEEE 802.11a or 802.11g standards specification
 *         - 1: OFDM turbo mode based on IEEE 802.11a or 802.11g standards specification
 *         - 2: ASTM DSRC standards specification (Default)
 *         - 3: OFDM quarter rate
 *
 * \return ERR_OK if the 802.11p analysis succeeded; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_Analyze80211p(int ph_corr_mode=2, int ch_estimate=1, int sym_tim_corr=2, int freq_sync=2, int ampl_track=1, int ofdm_mode=2);

//! Perform 802.11 a/g Analysis on current capture
/*!
 * \param[in] ph_corr_mode Phase Correction Mode with the following valid options:
 *         - 1: Phase correction off
 *         - 2: Symbol-by-symbol correction (Default)
 *         - 3: Moving avg. correction (10 symbols)
 * \param[in] ch_estimate Channel Estimate with the following options:
 *         - 1: Raw Channel Estimate (based on long trainling symbols) (Default)
 *         - 2: 2nd Order Polyfit
 *         - 3: Full packet estimate
 * \param[in] sym_tim_corr Symbol Timing Correction with the following options:
 *         - 1: Symbol Timing Correction Off
 *         - 2: Symbol Timing Correction ON (Default)
 * \param[in] freq_sync Frequency Sync. Mode with the following options:
 *         - 1: Short Training Symbol
 *         - 2: Long Training Symbol (Default)
 *         - 3: Full Data Packet
 * \param[in] ampl_track Amplitude Tracking with the following options:
 *         - 1: Amplitude tracking off (Default)
 *         - 2: Amplitude tracking on
 *
 * \return ERR_OK if the 802.11 a/g analysis succeeded; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_Analyze80211ag(int ph_corr_mode=2, int ch_estimate=1, int sym_tim_corr=2, int freq_sync=2, int ampl_track=1);



//! Perform 802.11 n Analysis on current capture
/*!
 * \param[in] type only "EWC" is supported
 * \param[in] mode Valid options are:
 *         - "nxn": for true 802.11n capture
 *         - "composite: for a composite capture
 *         - "sequential_mimo": for a switched capture
 * \param[in] enablePhaseCorr Phase Correction Mode:
 *         - 0: Disable
 *         - 1: Enable (Default)
 * \param[in] enableSymTimingCorr Symbol Timing Correction:
 *         - 0: Disable
 *         - 1: Enable (Default)
 * \param[in] enableAmplitudeTracking Amplitude Tracking:
 *         - 0: Disable (Default)
 *         - 1: Enable
 * \param[in] decodePSDU Decode PSDU:
 *         - 0: Disable (Default)
 *         - 1: Enable
 * \param[in] enableFullPacketChannelEst Channel Estimate on full packet:
 *         - 0: Disable (Default)
 *         - 1: Enable
 * \param[in] referenceFile PSDU reference file (needed for Composite EVM)
 * \param[in] packetFormat indicates format of the 80211n MIMO packet:
 *         - 0: auto-detect mode (Default)
 *         - 1: mixed format
 *         - 2: greenfield format
 *
 * \return ERR_OK if the 802.11n analysis succeeded; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_Analyze80211n(char *type,
                                   char *mode,
                                   int enablePhaseCorr            = 1,
                                   int enableSymTimingCorr        = 1,
                                   int enableAmplitudeTracking    = 0,
                                   int decodePSDU                 = 0,
                                   int enableFullPacketChannelEst = 0,
                                   char *referenceFile=NULL,
                                   int packetFormat = 0);

// LP_AnalyzeMimo has been replaced by LP_Analyze802.11n
IQMEASURE_API int LP_AnalyzeMimo(char *type, char *mode, int enablePhaseCorr, int enableSymTimingCorr, int enableAmplitudeTracking, int decodePSDU, int enableFullPacketChannelEst, char *referenceFile);



//! Perform 802.11b Analysis on current capture
/*!
 * \param[in] eq_taps Number of equalizer taps, valid options are:
 *         - 1: Equalizer Off
 *         - 5: 5 Taps Equalizer (Default)
 *         - 7: 7 Taps Equalizer
 *         - 9: 9 Taps Equalizer
 * \param[in] DCremove11b_flag DC removal, valid options are:
 *         - 0: DC Removal OFF (Default)
 *         - 1: DC Removal ON
 * \param[in] method_11b 802.11b method, valid options are:
 *         - 1: Use 11b standard TX accuracy (Default)
 *         - 2: Use 11b RMS error vector
 *
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_Analyze80211b(int eq_taps          = 5, // IQfuji merge /* -cfy@sunnyvale, 2012/3/13- */
                                   int DCremove11b_flag = 0,
                                   int method_11b       = 1);



//! Perform power Analysis on current capture
/*!
 * \param[in] T_interval Gap between packets (bursts).  Ignored
 * \param[in] max_pow_diff_dB Power difference between noise floor and packets.  Ignored
 *
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_AnalyzePower(double T_interval=0.0, double max_pow_diff_dB=0.0);



//! Perform Generic FFT Analysis on current capture
/*!
 * \param[in] NFFT Number of FFT.  Default to 0
 * \param[in] res_bw Resolution bandwidth.  Default to 100KHz
 * \param[in] window_type FFT window type.  Default to NULL
 *
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_AnalyzeFFT(double NFFT=0, double res_bw=100e3, char *window_type=NULL);



//! Perform CCDF Analysis on current capture
/*!
 * \return ERR_OK if the CCDE analysis succeeded; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_AnalyzeCCDF();



//! Perform CW Frequency Analysis on current capture (Replaced by LP_AnalyzeCWFreq)
/*!
 * \return ERR_OK if the CW analysis succeeded; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_AnalyzeCW();


//! Perform CW Frequency Analysis on current capture
/*!
 * \return ERR_OK if the CW analysis succeeded; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_AnalyzeCWFreq();



//! Perform Wave Analysis on current capture //TODO: what are results from AnalysisWave()?
/*!
 * \return ERR_OK if the Wave analysis succeeded; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_AnalysisWave();



//! Perform Sidelobe Analysis on current capture
/*!
 * \return ERR_OK if the Sidelobe analysis succeeded; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_AnalyzeSidelobe();



//! Perform Power Ramp Analysis (OFDM) on current capture
/*!
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_AnalyzePowerRampOFDM();



//! Perform Power Ramp Analysis (80211b) on current capture
/*!
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_AnalyzePowerRamp80211b();



//! Perform Bluetooth Analysis on current capture
/*!
 * \param[in] data_rate, Bluetooth data rate, with the following options:
 *         - 1: 1Mbit/s BDR
 *         - 2: 2Mbit/s EDR
 *         - 3: 3Mbit/s EDR
 *         - 0: Auto detect
 * \param[in] analysis_type, Specifies what type of analysis to perform. Default: 'All'. Valid values are as follows:
 *         - PowerOnly
 *         - 20dbBandwidthOnly
 *         - PowerandFreq
 *         - All  (This is the set default value)
 *		   - ACP  (only does the new ACP analysis)
 *		   - AllPlus  (performs all the analyses that are done by All?plus the ACP analysis)
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_AnalyzeBluetooth(double data_rate, char *analysis_type="All" );



//! Perform Zigbee Analysis Analysis on current capture
/*!
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_AnalyzeZigbee();



//! Perform HT40 mask (120MHz) analysis
/*!
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 * \remark Before calling LP_AnalyzeHT40Mask(), modeHT40 needs to set to 1 in LP_VsaDataCapture().
 */
IQMEASURE_API int LP_AnalyzeHT40Mask();

/*****************************/
/* Result Handling Functions */
/*****************************/


// The following three functions are obsoleted due to the typo.
IQMEASURE_API double LP_GetScalarMeasurment(char *measurement, int index=0);
IQMEASURE_API int LP_GetVectorMeasurment(char *measurement, double bufferReal[], double bufferImag[], int bufferLength);
IQMEASURE_API int LP_GetStringMeasurment(char *measurement, char bufferChar[], int bufferLength);



//! Get a scalar measurement result
/*!
 * \param[in] measurement The measurement name.  Please refer to \ref group_scalar_measurement "Scalar Measurements" for all available measurement names
 * \param[in] index The index of the measurement.  In most case, index would be zero.  For MIMO analysis, some measurements, such as EVM, may have more than one results
 *
 * \return The value of the measurement.  -99999.99 (a special defined negative value) will be returned if no measurement available
 */
IQMEASURE_API double LP_GetScalarMeasurement(char *measurement, int index=0);



//! Get a vector measurement result
/*!
 * \param[in] measurement The measurement name.  Please refer to \ref group_vector_measurement "Vector Measurements" for all available measurement names
 * \param[out] bufferReal Returns the real part of vector
 * \param[out] bufferImag Returns the imag part of vector
 * \param[in] bufferLength Indicates the length of bufferReal and bufferImag (in Bytes)
 *
 * \return The number of elements in bufferReal or/and bufferImag
 */
IQMEASURE_API int LP_GetVectorMeasurement(char *measurement, double bufferReal[], double bufferImag[], int bufferLength);



//! Get a string measurement result
/*!
 * \param[in] measurement The measurement name.  Please refer to \ref group_string_measurement "String Measurements" for all available measurement names
 * \param[out] bufferChar Returns the string result
 * \param[in] bufferLength Indicates the length of bufferChar (in Bytes)
 *
 * \return The number of elements in bufferChar
 */
IQMEASURE_API int LP_GetStringMeasurement(char *measurement, char bufferChar[], int bufferLength);

//!Following functions for fast power measurement, since API analysis power requires at least 10us data, but MPS for OFDM only need 8us
IQMEASURE_API int LP_FastCalGetPowerData (int bGetOrFree);
IQMEASURE_API int LP_PwrCalFreeElement(void);
IQMEASURE_API int LP_PwrCalFastGetElement(void);
IQMEASURE_API int LP_FastCalMeasPower (unsigned int start_time, unsigned int  stop_time, double *result);
IQMEASURE_API int LP_SetDefault(void);

/***********************/
/* Debugging Functions */
/***********************/

//! Plot the data capture
/*!
 * \return ERR_OK
 */
IQMEASURE_API int LP_PlotDataCapture();

IQMEASURE_API int LP_Plot(int figNum, double *x, double *y, int length, char *plotArgs, char *title, char *xtitle, char *ytitle, int keepPlot=0);

//! Start IQmeasure internal timer
/*!
 * \return ERR_OK
 */
IQMEASURE_API int LP_StartIQmeasureTimer();


//! Stop IQmeasure internal timer
/*!
 * \return ERR_OK
 */
IQMEASURE_API int LP_StopIQmeasureTimer();


//! Start IQmeasure internal timer
/*!
 * \return ERR_OK
 */
IQMEASURE_API int LP_ReportTimerDurations();



/*--------------*
 * TX Functions *
 *--------------*/

//! Perform multiple captures, then user can later perform different analysis based on these captures.
//! Use it along with IQ2010EXT_AddMultiAnalysisCapture() and IQ2010EXT_FinishMultiAnalysisCapture()
/*!
 * \param[in] dataRate Datarate the DUT uses to transmit the signal
 * \param[in] freqMHz Frequency (MHz) at which the DUT transmits
 * \param[in] rmsPowerLeveldBm Estimated DUT RMS power level (dBm) at the tester RF ports
 * \param[in] skipPktCnt Skip count before capture.                                         Max allowed: 255
 * \param[in] rfPort RF port. Valid values are IQV_PORT_LEFT (RF1) and IQV_PORT_RIGHT (RF2).
 * \param[in] triggerLeveldBm Trigger level in dBm
*/
IQMEASURE_API int LP_IQ2010EXT_NewMultiAnalysisCapture( char		   *dataRate,
                                                        double          freqMHz,
                                                        double	        rmsPowerLeveldBm,
													    int	            skipPktCnt,
													    int		        rfPort,
													    double	        triggerLeveldBm);

//! Add multiple capture type with specified capture length and count. This function should be called after IQ2010EXT_NewMultiAnalysisCapture()
/*!
 * \param[in] analysisType  analysis type 
 * \param[in] captureLengthUs Capture length in us.                                         Max allowed: 1023 us
 * \param[in] captureCnt Capture count.                                                     Max allowed: 255
*/
IQMEASURE_API int LP_IQ2010EXT_AddMultiAnalysisCapture( int		    analysisType,
													    int			captureLengthUs,  
													    int			captureCnt);

//! VSA Multi-packet analysis capture. Should use it along with IQ2010EXT_FinishMultiAnalysisCapture(). The function should be called first.
/*!
 * \return ERR_OK if the VSA capture is done successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
*/
IQMEASURE_API int LP_IQ2010EXT_InitiateMultiAnalysisCapture(void);


//! VSA multi-packet capture based on the  . The function should be called after IQ2010EXT_AddMultiAnalysisCapture()
/*!
 * \return ERR_OK if the VSA capture is done successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
*/
IQMEASURE_API int LP_IQ2010EXT_FinishMultiAnalysisCapture(void);

 
//! VSA Multi-packet capture. Should use it along with IQ2010EXT_FinishMultiCapture(). The function should be called first.
/*!
 * \param[in] dataRate Datarate the DUT uses to transmit
 * \param[in] freqMHz Frequency (MHz) at which the DUT transmits
 * \param[in] rmsPowerLeveldBm Estimated DUT RMS power level (dBm) at the tester RF ports
 * \param[in] captureLengthUs Capture length in us.                                         Max allowed: 1023 us
 * \param[in] skipPktCnt Skip count before capture.                                         Max allowed: 255
 * \param[in] captureCnt Capture count.                                                     Max allowed: 255
 * \param[in] rfPort RF port. Valid values are IQV_PORT_LEFT (RF1) and IQV_PORT_RIGHT (RF2).
 * \param[in] triggerLeveldBm Trigger level in dBm
 *
 * \return ERR_OK if the VSA capture is initiated successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
*/
IQMEASURE_API int LP_IQ2010EXT_InitiateMultiCapture( char				*dataRate,
													 double              freqMHz,
													 double	             rmsPowerLeveldBm,
													 int	             captureLengthUs,  
													 int	             skipPktCnt,
													 int	             captureCnt,
													 int				 rfPort,
													 double	             triggerLeveldBm);


//! VSA Multi-packet Capture for HT40. Should use it along with IQ2010EXT_FinishMultiCapture(). The function should be called first.
/*!
 * \param[in] dataRate Datarate the DUT uses to transmit
 * \param[in] freqMHz Frequency (MHz) at which the DUT transmits
 * \param[in] rmsPowerLeveldBm Estimated DUT RMS power level (dBm) at the tester RF ports
 * \param[in] captureLengthUs Capture length in us.                                         Max allowed: 1023 us
 * \param[in] skipPktCnt Skip count before capture.                                         Max allowed: 255
 * \param[in] captureCnt Capture count.                                                     Max allowed: 255
 * \param[in] rfPort RF port. Valid values are IQV_PORT_LEFT (RF1) and IQV_PORT_RIGHT(RF2).
 * \param[in] triggerLeveldBm Trigger-level in dBm
 *
 * \return ERR_OK if the VSA capture is initiated successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
*/
IQMEASURE_API int LP_IQ2010EXT_InitiateMultiCaptureHT40( char			   *dataRate,
														 double             freqMHz,
														 double	            rmsPowerLeveldBm,
														 int	            captureLengthUs,  
														 int	            skipPktCnt,
														 int	            captureCnt,
														 int                rfPort,
														 double	            triggerLeveldBm);

//! VSA multi-packet capture. Should use it along with IQ2010EXT_InitiateMultiCapture(). The function should be called after IQ2010EXT_InitiateMultiCapture() or IQ2010EXT_InitiateMultiCaptureHT40().
/*!
 * \return ERR_OK if the VSA capture is done successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
*/
IQMEASURE_API int LP_IQ2010EXT_FinishMultiCapture(void);


//! Perform 802.11a/g Analysis on Multi-packet Capture
/*!
 * \param[in] ph_corr_mode Phase Correction Mode with the following valid options:
 *         - IQV_PH_CORR_OFF: Phase correction off
 *         - IQV_PH_CORR_SYM_BY_SYM: Symbol-by-symbol correction  (Default)
 *         - IQV_PH_CORR_MOVING_AVG: Moving avg. correction (10 symbols)
 * \param[in] ch_estimate Channel Estimate with the following options:
 *         - IQV_CH_EST_RAW_LONG: Raw Channel Estimate (based on long trainling symbols) (Default)
 *         - IQV_CH_EST_2ND_ORDER: 2nd Order Polyfit
 *         - IQV_CH_EST_RAW_FULL: Full packet estimate
 * \param[in] sym_tim_corr Symbol Timing Correction with the following options:
 *         - IQV_SYM_TIM_OFF: Symbol Timing Correction Off
 *         - IQV_SYM_TIM_ON: Symbol Timing Correction ON (Default)
 * \param[in] freq_sync Frequency Sync. Mode with the following options:
 *         - IQV_FREQ_SYNC_SHORT_TRAIN: Short Training Symbol
 *         - IQV_FREQ_SYNC_LONG_TRAIN: Long Training Symbol (Default)
 *         - IQV_FREQ_SYNC_FULL_PACKET: Full Data Packet
 * \param[in] ampl_track Amplitude Tracking with the following options:
 *         - IQV_AMPL_TRACK_OFF: Amplitude tracking off (Default)
 *         - IQV_AMPL_TRACK_ON: Amplitude tracking on
 *
 * \return ERR_OK if the 802.11 a/g analysis succeeded; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
 */
IQMEASURE_API int LP_IQ2010EXT_Analyze80211ag( IQV_PH_CORR_ENUM ph_corr_mode    =IQV_PH_CORR_SYM_BY_SYM, 
											   IQV_CH_EST_ENUM ch_estimate      =IQV_CH_EST_RAW_LONG, 
											   IQV_SYM_TIM_ENUM sym_tim_corr    =IQV_SYM_TIM_ON, 
											   IQV_FREQ_SYNC_ENUM freq_sync     =IQV_FREQ_SYNC_LONG_TRAIN, 
											   IQV_AMPL_TRACK_ENUM ampl_track   =IQV_AMPL_TRACK_OFF);

//! Perform 802.11n Analysis on Multi-packet Capture 
/*!
 * \param[in] enablePhaseCorr Phase Correction Mode:
 *         - 0: Disable
 *         - 1: Enable (Default)
 * \param[in] enableSymTimingCorr Symbol Timing Correction:
 *         - 0: Disable
 *         - 1: Enable (Default)
 * \param[in] enableAmplitudeTracking Amplitude Tracking:
 *         - 0: Disable (Default)
 *         - 1: Enable
 * \param[in] decodePSDU Decode PSDU:
 *         - 0: Disable (Default)
 *         - 1: Enable
 * \param[in] enableFullPacketChannelEst Channel Estimate on full packet:
 *         - 0: Disable (Default)
 *         - 1: Enable
 * \param[in] packetFormat indicates format of the 80211n MIMO packet:
 *         - 0: auto-detect mode (Default)
 *         - 1: mixed format
 *         - 2: greenfield format
 *
 * \return ERR_OK if the 802.11n analysis is successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
 */
IQMEASURE_API int LP_IQ2010EXT_Analyze80211nSISO( int enablePhaseCorr            = 1, 
												  int enableSymTimingCorr        = 1, 
												  int enableAmplitudeTracking    = 0, 
												  int decodePSDU                 = 0, 
												  int enableFullPacketChannelEst = 0, 
												  int packetFormat               = 0);

//! Perform 802.11n Analysis on Multi-packet Capture in composite mode
/*!
 * \param[in] enablePhaseCorr Phase Correction Mode:
 *         - 0: Disable
 *         - 1: Enable (Default)
 * \param[in] enableSymTimingCorr Symbol Timing Correction:
 *         - 0: Disable
 *         - 1: Enable (Default)
 * \param[in] enableAmplitudeTracking Amplitude Tracking:
 *         - 0: Disable (Default)
 *         - 1: Enable
 * \param[in] enableFullPacketChannelEst Channel Estimate on full packet:
 *         - 0: Disable (Default)
 *         - 1: Enable
 * \param[in] referenceFile PSDU reference file (needed for Composite EVM)
 * \param[in] packetFormat indicates format of the 80211n MIMO packet:
 *         - 0: auto-detect mode (Default)
 *         - 1: mixed format
 *         - 2: greenfield format
 *
 * \return ERR_OK if the 802.11n analysis is successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
 */
IQMEASURE_API int LP_IQ2010EXT_Analyze80211nComposite(int enablePhaseCorr            = 1, 
													  int enableSymTimingCorr        = 1, 
													  int enableAmplitudeTracking    = 0, 
													  int enableFullPacketChannelEst = 0, 
													  char *referenceFile            = NULL,
													  int packetFormat               = 0);

//! Perform 802.11b Analysis on Multi-packet Capture
/*!
 * \param[in] eq_taps Number of equalizer taps, valid options are as follows:
 *         - IQV_EQ_OFF: Equalizer Off  (Default)
 *         - IQV_EQ_5_TAPS: 5 Taps Equalizer 
 *         - IQV_EQ_7_TAPS: 7 Taps Equalizer
 *         - IQV_EQ_9_TAPS: 9 Taps Equalizer
 * \param[in] DCremove11b_flag DC removal, valid options are:
 *         - IQV_DC_REMOVAL_OFF: DC Removal OFF (Default)
 *         - IQV_DC_REMOVAL_ON: DC Removal ON
 * \param[in] method_11b 802.11b method, valid options are as follows:
 *         - IQV_11B_STANDARD_TX_ACC: Use 11b standard TX accuracy (Default)
 *         - IQV_11B_RMS_ERROR_VECTOR: Use 11b RMS error vector
 *
 * \return ERR_OK if the 802.11b analysis is successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
 */
IQMEASURE_API int LP_IQ2010EXT_Analyze80211b( IQV_EQ_ENUM eq_taps                   = IQV_EQ_OFF, 
											  IQV_DC_REMOVAL_ENUM DCremove11b_flag  = IQV_DC_REMOVAL_OFF, 
											  IQV_11B_METHOD_ENUM method_11b        = IQV_11B_STANDARD_TX_ACC);

//! Perform power analysis on Multi-packet Capture
/*!
 * \return ERR_OK if the power analysis is successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
*/
IQMEASURE_API int LP_IQ2010EXT_AnalyzePower(void);

//! Perform FFT analysis on Multi-packet Capture
/*!
 * \param [in] NFFT        Number of points in FFT.                        Default: 0
 * \param [in] res_bwHz    The resolution bandwidth in Hz.                 Default: 100000
 * \param [in] window_type Window type with following options              Default: "blackmanharris"
 *                 - "blackmanharris"
 *                 - "hanning"
 *                 - "flattop"
 *                 - "rect"
*/
IQMEASURE_API int LP_IQ2010EXT_AnalyzeFFT( double NFFT          = 0, 
										   double res_bwHz      = 100000, 
										   char *window_type    = "blackmanharris");

//! Perform mask verification and get OBW based on the OBW percentage
/*!
 * \param [in] maskType         indicate what mask type should be applied to the captured data
 * \param [in] obwPercentage    OBW percentage. The valid range should be between 0 - 1
 * \return ERR_OK if the mask measurement is successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
*/
IQMEASURE_API int LP_IQ2010EXT_AnalyzeMaskMeasurement(int maskType, double obwPercentage);

//! Perform power-ramp analysis for 11B
/*!
 * \return ERR_OK if the mask measurement is successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
*/
IQMEASURE_API int LP_IQ2010EXT_AnalyzePowerRamp80211b();

//! Perform Bluetooth Analysis on Multi-packet Capture
/*!
 * \param[in] data_rate Bluetooth data rate, with the following options:
 *         - 1: 1Mbit/s BDR
 *         - 2: 2Mbit/s EDR
 *         - 3: 3Mbit/s EDR
 *         - 0: Auto detect
 * \param[in] analysis_type Specifies what type of analysis to perform.                 Default: 'All'. 
 *         Valid values are as follows:
 *         - PowerOnly
 *         - 20dbBandwidthOnly
 *         - PowerandFreq
 *         - All  (This is the set default value)
 *		   - ACP  (only does the new ACP analysis)
 *		   - AllPlus  (performs all the analyses that are done by �All?plus the ACP analysis)
 * \return ERR_OK if the bluetooth analysis is successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
 */
IQMEASURE_API int LP_IQ2010EXT_AnalyzeBluetooth(double data_rate, char *analysis_type="All");

//! Perform spectral analysis based on the selected spectral type
/*!
 * param [in] spectralType  indicate the spectral type to be applied to the captured data
 * \return ERR_OK if the spectral measurement is successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
*/
IQMEASURE_API int LP_IQ2010EXT_AnalyzeSpectralMeasurement(int spectralType);

//////! Set Analysis Parameters
/////*!
//// * \param[in] analysisType One of the analysis types defined in IQ2010EXT_ANALYSIS_TYPE_ENUM
//// * \param[in] parameter One of the parameter names for the specified analysis type (see TODO for details)
//// * \param[in] value The value for the specified parameter
//// *
//// * \return ERR_OK if successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
//// */
//////IQ2010EXT_API int IQ2010EXT_SetAnalysisParameterInteger(Q2010EXT_ANALYSIS_TYPE_ENUM analysisType,
//////                                                        char *parameter, 
//////                                                        int value);



/*--------------*
 * RX Functions *
 *--------------*/

//! IQ2010 ACK-based RX PER Test
/*!
 * \param[in] waveformIndex A wave form index (0 based) of the multi-segment wavefile, specifying which wave form should be used
 * \param[in] freqMHz Frequency (MHz) on which DUT operates
 * \param[in] powerLevelStartdBm The start of power level (dBm at IQ2010 RF ports)
 * \param[in] powerLevelStopdBm The stop of power level (dBm at IQ2010 RF ports)
 * \param[in] stepdB Power level step(dB).  Minimum step is 0.5dB.
 * \param[in] packetCount Number of packets to be transmitted for power level. Maximum number of packets is 32767.
 * \param[in] rfPort The RF ports used for RX PER testing. Valid values are IQV_PORT_LEFT (RF1) and IQV_PORT_RIGHT(RF2).
 * \param[in] ackPowerRmsdBm The DUT ACK RMS Power at the tester port
 * \param[in] ackTriggerLeveldBm The trigger level set to do ACK detection
 *
 * \return ERR_OK if the RX PER is successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
 *
 * \remark 
 *         -# In most cases, the stop power level would be lower than the start power level, but it could be
 *            higher than the start power level.  In either way, step would be relative, meaning always positive.
 *         -# If only one power level is interested for RX PER, make the powerLevelStopdBm the same as powerLevelStartdBm.
 *         -# power level should be within [-10, -95] dBm
 */
IQMEASURE_API int LP_IQ2010EXT_RxPer( int               waveformIndex,
									  double            freqMHz,
									  double            powerLevelStartdBm, 
									  double            powerLevelStopdBm, 
									  double            stepdB,
									  int               packetCount,
									  int				rfPort,
									  double            ackPowerRmsdBm,
									  double            ackTriggerLeveldBm
									  );


/*---------------------------------*
 * Multi-segment Waveform Handling *
 *---------------------------------*/
//! Start a new Multi-segment Waveform Creation
/*!
 *
 * \return ERR_OK if successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
 *
 * \remark 
 *         -# After calling this function, you can then call IQ2010EXT_AddWaveform()
 */
IQMEASURE_API int LP_IQ2010EXT_NewMultiSegmentWaveform();

 
//! Add a Waveform to the Multi-segment Waveform. 
/*!
 * \param[in] modFile A .mod file that contains only one data rate
 * \param[out] waveformIndex The waveform index used by IQ2010EXT_RxPer() identifying this data rate
 *
 * \return ERR_OK if successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
 *
 * \remark 
 *         -# You can only call this function after IQ2010EXT_NewMultiSegmentWaveform() and before IQ2010EXT_FinalizeMultiSegmentWaveform()
 *         - The maximum number of file can be added is 32
 */
IQMEASURE_API int LP_IQ2010EXT_AddWaveform(const char *modFile, unsigned int *waveformIndex );
 
//! Finalize the Multi-segment Waveform Creation and Upload to VSG Memory
/*!
 * \return ERR_OK if successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
 * \remark 
 *         -# You cannot call IQ2010EXT_AddWaveform() anytime after calling this function
 */
IQMEASURE_API int LP_IQ2010EXT_FinalizeMultiSegmentWaveform();


//! Generate a wave form at VSG by the specified segment index with the packet count 
/*!
 * \param[in] waveformIndex index (base 0) to wave form (wave form is preloaded by IQ2010EXT_LoadMultiSegmentWaveFile(...) ) to be played at VSG
 * \param[in] packetCount number of packets to be played
 * \return ERR_OK if successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
*/
IQMEASURE_API int LP_IQ2010EXT_VsgSingleSegmentPlay(int waveformIndex, int packetCount);

//! After calling IQ2010EXT_VsgSingleSegmentPlay(...). Should call IQ2010EXT_VsgSingleSegmentStop() to stop the segment played
/*!
 * \return ERR_OK if successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
*/
IQMEASURE_API int LP_IQ2010EXT_VsgSingleSegmentStop();


/*--------------------------*
 * Getting result Functions *
 *--------------------------*/

//! Get the number of results for a particular measurement element (pointed to by indexResult) by measurement name
/*!
 * \param [in] measurementName         measurement name
 * \param [in] indexResult             index to a particular measurement element
 * \param [out] numberOfMeasurementElement return number of measurement element 
 * \return ERR_OK if successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
*/
IQMEASURE_API int LP_IQ2010EXT_GetNumberOfMeasurementElements(char *measurementName, int indexResult, int *numberOfMeasurementElement);


//! Get the number of results for a particular measurement element (pointed to by indexResult) by measurement name
/*!
 * \param [in] measurementName         measurement name
 * \param [out] numberOfPerPowerLevel return number of per power level 
 * \return ERR_OK if successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
*/
IQMEASURE_API int LP_IQ2010EXT_GetNumberOfPerPowerLevels(char *measurementName, int *numberOfPerPowerLevel);

//! Retrieve Analysis Results [Double] in average, minimum and maximum value
/*!
 * \param[in]  measurementName          The measurement name.  Please refer to \ref group_scalar_measurement "Vector Measurements" for all available measurement names.
 * \param[out] average Average value    Average value for all the result(s). Result set can be more than one if the specified capture count is larger than one when using multi-capture function 'IQ2010EXT_VsaMultiCapture(...)'
 * \param[out] minimum Minimum value    Minimum value of all the result(s)
 * \param[out] maximum Maximum value    Maximum value of all the result(s)
 *
 * \return ERR_OK if successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
 */
IQMEASURE_API int LP_IQ2010EXT_GetDoubleMeasurements(char *measurementName, double *average, double *minimum, double *maximum);


//! Retrieve Analysis Results [char] 
/*!
 * \param[in] measurementName The measurement name.  Please refer to \ref group_scalar_measurement "Vector Measurements" for all available measurement names.
 * \param[out] result Result in 'char' pointer type
 * \param[in] bufferSize Indicates the buffer size of result
 * \param[in] indexResult (starts with 0 as the first set of result) indicates which set of result to be retrieved. It has to be less than the number of capture set in IQ2010EXT_VsaMultiCapture(...)
 *
 * \return ERR_OK if successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
 */
IQMEASURE_API int LP_IQ2010EXT_GetStringMeasurement(char *measurementName, char *result, int  bufferSize, int indexResult = 0);


//! Retrieve Analysis Results [Double] in vector format ( more than one value in one particular result set as indicated by indexResult )
/*!
 * \param[in] measurementName The measurement name.  Please refer to \ref group_vector_measurement "Vector Measurements" for all available measurement names
 * \param[out] values Returns the real part of vector
 * \param[in] bufferLength Indicates the length of bufferReal and bufferImag (in number of element)
 * \param[out] *dataSize indicates the number of element in the result. If the dataSize is greater than bufferLength, then only the data with bufferLength will be filled up in the buffer
 * \param[in] indexResult (starts with 0 as the first set of result) indicates which set of result to be retrieved. It has to be less than the number of capture set in IQ2010EXT_VsaMultiCapture(...)
 *
 * \return ERR_OK if successful; otherwise, call IQ2010EXT_GetLastErr() for detailed error message.
 */
IQMEASURE_API int LP_IQ2010EXT_GetVectorMeasurement(char *measurementName, double values[], int bufferLength, int *dataSize, int indexResult = 0);


//! Retrieve Analysis Results [int] 
/*!
 * \param[in] measurementName The measurement name.  Please refer to \ref group_vector_measurement "Vector Measurements" for all available measurement names
 * \param[out] result Result in 'int' type
 * \param[in] indexResult (starts with 0 as the first set of result) indicates which set of result to be retrieved. It has to be less than the number of capture set in IQ2010EXT_VsaMultiCapture(...)
*/
IQMEASURE_API int LP_IQ2010EXT_GetIntMeasurement(char *measurementName, int *result, int indexResult = 0);

//! Initializes IQ2010 Extension
/*!
 * \return ERR_OK if initialzation is done successfully; otherwise call IQ2010EXT_GetLastErr() for detailed error message.
 * \remark This function has to be called right after IQ2010 software has been connected to the test system
 */
IQMEASURE_API int LP_IQ2010EXT_Init(void);


//! Exit IQ2010 extension
/*!
 * \return ERR_OK if exiting IQ2010 extension successfully; otherwise call IQ2010EXT_GetLastErr() for detailed error message.
 * \remark This function has to be called if user wants to switch the tester back to legacy mode after using IQ2010 extension.
 */
IQMEASURE_API int LP_IQ2010EXT_Terminate(void);

//--


#pragma region GPS related functions

IQMEASURE_API enum LP_GPS_REPLAY_MODE
{
   GPS_REPLAY_OFF,
   GPS_REPLAY_ON
};

//! ENUM values for the GPS channel number
IQMEASURE_API enum LP_GPS_CHANNEL_NUMBER
{
   GPS_CHANNEL_NUMBER_1,	//!< Indicates the first GPS channel
   GPS_CHANNEL_NUMBER_2,	//!< Indicates the second GPS channel
   GPS_CHANNEL_NUMBER_3,	//!< Indicates the third GPS channel
   GPS_CHANNEL_NUMBER_4,	//!< Indicates the fourth GPS channel
   GPS_CHANNEL_NUMBER_5,	//!< Indicates the fifth GPS channel
   GPS_CHANNEL_NUMBER_6	    //!< Indicates the sixth GPS channel
};

//! ENUM values for GPS modulation state
IQMEASURE_API enum LP_GPS_MODULATION_STATE
{
   MODULATION_STATE_OFF,	//!< Indicates that modulation state is off
   MODULATION_STATE_ON	    //!< Indicates that modulation state is on
};

//IQMEASURE_API int LP_GPS_GetData(char* inputName, char* &inputValue);
//!
/*! @defgroup gps_measurement Measurement
 *  The process sequence is :
 * 1. Activate Tester
 *    LP_GPS_SetActivate
 * 2. Call the main test function :
 *    LP_GPS_LoadScenarioFile & LP_GPS_PlayScenarioFile
 *    LP_GPS_ModulatedMode
 *    LP_GPS_ContinueWave
 * 3. Deactivate Tester
 *    LP_GPS_SetDeactivate
 * @. Others
 *    LP_GPS_SetData
 *    LP_GPS_SetChannelInfo
 * @. Internal function
 *    LP_GPS_CaculateTesterPower
 */

//! Calling LP_GPS_SetActivate to activate Tester.
IQMEASURE_API int LP_GPS_SetActivate();
//! Calling LP_GPS_LoadScenarioFile to load scenario file.
/*!
 * \param[in] fileName     : Path of the scenario file.
 * \param[in] triggerState : Trigger State.
*/
IQMEASURE_API int LP_GPS_LoadScenarioFile(char* fileName, IQV_GPS_TRIGGER_STATE triggerState);

//! Calling LP_GPS_PlayScenarioFile to start playing scenario file.
/*!
 * \param[in] power        : Power at the DUT.
 * \param[in] pathloss     : Cable loss.
*/
IQMEASURE_API int LP_GPS_PlayScenarioFile(double powerDbm, double pathlossDb);

//! Calling LP_GPS_ModulatedMode to transmit modulate mode signal.
/*!
 * \param[in] Nav_Mode         : Navigation mode. 0 means OFF (Default), "IQV_OPERATION_MODE_MODULATION_NAV_DATA_OFF" and 1 means ON, "IQV_OPERATION_MODE_MODULATION".
 * \param[in] pathloss         : Cable loss.
 * \param[in] powerA[6]        : Power array of each channel at the DUT.
 * \param[in] satelliteNumA[6] : Satellite number array of each channel.
 * \param[in] dopplerFrequenc  : Doppler frequence revise.
 * \param[in] triggerState     : Trigger State.
*/
IQMEASURE_API int LP_GPS_ModulatedMode(int Nav_Mode, double pathlossDb, double powerA[6], int satelliteNumA[6], int dopplerFrequency, IQV_GPS_TRIGGER_STATE triggerState);

//! Calling LP_GPS_ContinueWave to transmit continue wave signal.
/*!
 * \param[in] power        : Power at the DUT.
 * \param[in] pathloss     : Cable loss.
 * \param[in] triggerState : Trigger State.
*/
IQMEASURE_API int LP_GPS_ContinueWave(double powerDbm, double pathlossDb, IQV_GPS_TRIGGER_STATE triggerState);
//! Calling LP_GPS_SetDeactivate to stop and deactivate Tester.
IQMEASURE_API int LP_GPS_SetDeactivate();
//! Calling LP_GPS_GetChannelInfo to get information of each channel.
/*!
 * \param[in] channelNumber   : channel number.
 * \param[in] satelliteNumber : apply satellite number of the channel.
 * \param[in] powerDbm        : apply power of the channel.
*/
IQMEASURE_API int LP_GPS_GetChannelInfo(
    IQV_GPS_CHANNEL_NUMBER channelNumber,
    int *satelliteNumber,
    double *powerDbm,
    IQV_GPS_MODULATION_STATE *modulationState);

//! Calling LP_GPS_SetChannelInfo to set information of each channel.
/*!
 * \param[in] channelNumber   : channel number.
 * \param[in] satelliteNumber : setup satellite number of the channel.
 * \param[in] powerDbm        : setup power of the channel.
*/
IQMEASURE_API int LP_GPS_SetChannelInfo(
    IQV_GPS_CHANNEL_NUMBER channelNumber,
    int satelliteNumber,
    double powerDbm,
    IQV_GPS_MODULATION_STATE modulationState);

//! Calling LP_GPS_SetData to set information of the tester.
/*!
 * \param[in] inputName  : setup function name.
 * \param[in] inputValue : setup value of the function.
 * <b>SetParamOperationMode</b>    :
 *        <b>IQV_OPERATION_MODE_MODULATION_OFF</b>
 *        <b>IQV_OPERATION_MODE_MODULATION</b>
 *        <b>IQV_OPERATION_MODE_CW</b>
 *        <b>IQV_OPERATION_MODE_MODULATION_NAV_DATA_OFF</b>
 * <b>SetParamPowerDbm</b>         :
 *        <b>[tester Power]</b>
 * <b>SetParamModulationState</b>  :
 *        <b>IQV_MODULATION_STATE_OFF</b>
 *        <b>IQV_MODULATION_STATE_ON</b>
 * <b>SetParamDopplerFrequency</b> :
 *        <b>[doppler Frequency]</b>
 * <b>SetParamRfOutput</b>         :
 *        <b>IQV_RF_OUTPUT_OFF</b>
 *        <b>IQV_RF_OUTPUT_ON</b>
 * <b>SetParamTriggerState</b>     :
 *        <b>IQV_TRIGGER_STATE_INT</b>
 *        <b>IQV_TRIGGER_STATE_EXT</b>
 * <b>SetReplayScenarioMode</b>    :
 *        <b>IQV_GPS_REPLAY_OFF</b>
 *        <b>IQV_GPS_REPLAY_ON</b>
*/
IQMEASURE_API int LP_GPS_SetData(const char* inputName, const char* inputValue);
double LP_GPS_CaculateTesterPower(double power, double pathloss);


#pragma endregion



//--

/*! @defgroup group_scalar_measurement Measurement Names for IQ2010EXT_GetDoubleMeasurements(), IQ2010EXT_GetStringMeasurement(), IQ2010EXT_GetVectorMeasurement(), IQ2010EXT_GetIntMeasurement()
 *
 * Available measurement names vary for various analysis.  After an analysis has been performed successfully, by calling one of the following functions:
 *   - IQ2010EXT_Analyze80211ag();
 *   - IQ2010EXT_Analyze80211nSISO();
 *   - IQ2010EXT_Analyze80211nComposite();
 *   - IQ2010EXT_Analyze80211b();
 *   - IQ2010EXT_AnalyzePower();
 *   - IQ2010EXT_AnalyzeFFT();
 *   - IQ2010EXT_AnalyzePowerRamp80211b();
 *   - IQ2010EXT_AnalyzeBluetooth();
 *   - IQ2010EXT_AnalyzeSpectralMeasurement();
 *   - IQ2010EXT_AnalyzeMaskMeasurement();
 *   - IQ2010EXT_AnalyzeSpectralMeasurement();
 *
 * \section analysis_80211ag Measurement Names for IQ2010EXT_Analyze80211ag() and IQ2010EXT_AnalyzeSpectralMeasurement() with spectral type 'IQ2010EXT_SPECTRAL_11AG'
 *  - <b>evmAll</b>:  EVM for entire frame.  index value: 0
 *  - <b>evmData</b>:  EVM for data part of the frame.  index value: 0
 *  - <b>evmPilot</b>:  EVM of all pilot part of the frame.  index value: 0
 *  - <b>codingRate</b>:  Coding Rate in the capture.  index value: 0
 *  - <b>freqErr</b>:  Frequency Error in the capture.  index value: 0
 *  - <b>clockErr</b>:  Symbol Clock Error in the capture.  index value: 0
 *  - <b>ampErr</b>:  IQ Match Amplitude Error in the capture.  index value: 0
 *  - <b>ampErrDb</b>:  IQ Match Amplitude Error in dB in the capture.  index value: 0
 *  - <b>phaseErr</b>:  IQ Match Phase Error in the capture.  index value: 0
 *  - <b>rmsPhaseNoise</b>:  Frequency RMS Phase Noise in rms in the capture.  index value: 0
 *  - <b>rmsPowerNoGap</b>:  RMS Power No Gap in the capture.  index value: 0
 *  - <b>rmsPower</b>:  RMS Power in the capture.  index  value: 0
 *  - <b>pkPower</b>:  Peak power in the capture.  index value: 0
 *  - <b>rmsMaxAvgPower</b>:  Average max RMS power in the capture.  index value: 0
 *  - <b>psduCrcFail</b>:  1 = PSDU CRC Check Failed, 0 = PSDU CRC Check Passed.  index value: 0
 *  - <b>plcpCrcPass</b>:  1 = PLCP CRC Check Passed, 0 = PLCP CRC Check Failed.  index value: 0
 *  - <b>dataRate</b>:  Data rate in Mbps in the capture.  index value: 0
 *  - <b>numSymbols</b>:  Number of Symbols in the capture.  index value: 0
 *  - <b>numPsduBytes</b>:  Number of bytes in PSDU.  index value: 0
 *  - <b>SUBCARRIER_LO_B_VSA1</b>:  Subcarrier number for lower region B ( tester VSA 1 ).  index value: 0
 *  - <b>VALUE_DB_LO_B_VSA1</b>:  Value at worst margin for lower region B (tester VSA 1).  index value: 0
 *  - <b>SUBCARRIER_LO_A_VSA1</b>:  Subcarrier number for lower region A ( tester VSA 1 ).  index value: 0
 *  - <b>VALUE_DB_LO_A_VSA1</b>:  Value at worst margin for lower region A (tester VSA 1).  index value: 0
 *  - <b>SUBCARRIER_UP_A_VSA1</b>:  Subcarrier number for upper region A ( tester VSA 1 ).  index value: 0
 *  - <b>VALUE_DB_UP_A_VSA1</b>:  Value at worst margin for upper region A (tester VSA 1).  index value: 0
 *  - <b>SUBCARRIER_UP_B_VSA1</b>:  Subcarrier number for upper region B ( tester VSA 1 ).  index value: 0
 *  - <b>VALUE_DB_UP_B_VSA1</b>:  Value at worst margin for upper region B (tester VSA 1).  index value: 0
 *  - <b>LO_LEAKAGE_DBR_VSA1</b>:  LO leakage (tester VSA 1).  index value: 0
 *
 * \section analysis_mimo Measurement Names for IQ2010EXT_Analyze80211nSISO, IQ2010EXT_Analyze80211nComposite() and IQ2010EXT_AnalyzeSpectralMeasurement() with 11N spectral type ( like, IQ2010EXT_SPECTRAL_11N_HT20 or IQ2010EXT_SPECTRAL_11N_HT40 )
 *  - <b>evmAvgAll</b>:  Average EVM of all symbols per stream in the capture. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>packetDetection</b>:  Indicates at least one valid packet detected. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>psduCRC</b>:  Indicates valid CRC on PSDU. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>acquisition</b>:  Indicates at least one valid HT packet detected. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>demodulation</b>:  Indicates demodulated streams (packet may be truncated). Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>dcLeakageDbc</b>:  DC Leakage in dBc per RX. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>rxRmsPowerDb</b>:  RMS power of estimated channels per stream. Dimension is NStreams X NRx. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>freqErrorHz</b>:  Frequency error in Hz. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>symClockErrorPpm</b>:  Symbol clock error in ppm. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>PhaseNoiseDeg_RmsAll</b>:  RMS phase noise, over all received signals. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>IQImbal_amplDb</b>:  IQ gain imbalance in dB per stream. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>IQImbal_phaseDeg</b>:  IQ phase imbalance in degree per stream. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>rateInfo_bandwidthMhz</b>:  Bandwidth in MHz. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>rateInfo_dataRateMbps</b>:  Data Rate in Mbps. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>rateInfo_spatialStreams</b>:  Number in spatial streams. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>analyzedRange</b>:  Start and end point of the signal part that was used for analysis. The API picks the first packet in the input signal for analysis; the following packets are ignored. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>htSig1_htLength</b>:  Information from HT-SIG1: value in Length field as decimal number. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>htSig1_mcsIndex</b>:  Information from HT-SIG1: MCS index as a decimal number. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>htSig1_bandwidth</b>:  Information from HT-SIG1: bandwidth (0) 20MHz (1) 40MHz. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>htSig2_advancedCoding</b>:  Information from HT-SIG2: advanced coding. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>rateInfo_spaceTimeStreams</b>:  Number in Space-Time Streams. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>SUBCARRIER_LO_B_VSA1</b>:  Subcarrier number for lower region B ( tester VSA 1 ).  index value: 0
 *  - <b>VALUE_DB_LO_B_VSA1</b>:  Value at worst margin for lower region B (tester VSA 1).  index value: 0
 *  - <b>SUBCARRIER_LO_A_VSA1</b>:  Subcarrier number for lower region A ( tester VSA 1 ).  index value: 0
 *  - <b>VALUE_DB_LO_A_VSA1</b>:  Value at worst margin for lower region A (tester VSA 1).  index value: 0
 *  - <b>SUBCARRIER_UP_A_VSA1</b>:  Subcarrier number for upper region A ( tester VSA 1 ).  index value: 0
 *  - <b>VALUE_DB_UP_A_VSA1</b>:  Value at worst margin for upper region A (tester VSA 1).  index value: 0
 *  - <b>SUBCARRIER_UP_B_VSA1</b>:  Subcarrier number for upper region B ( tester VSA 1 ).  index value: 0
 *  - <b>VALUE_DB_UP_B_VSA1</b>:  Value at worst margin for upper region B (tester VSA 1).  index value: 0
 *  - <b>LO_LEAKAGE_DBR_VSA1</b>:  LO leakage (tester VSA 1).  index value: 0
 *
 * \section analysis_80211b Measurement Names for IQ2010EXT_Analyze80211b()
 *  - <b>evmPk</b>:  EVM peak value of all symbols in the capture.  index value: 0
 *  - <b>evmAll</b>:  EVM for entire frame in the capture.  index value: 0
 *  - <b>evmInPreamble</b>:  EVM in the preamble of the capture.  index value: 0
 *  - <b>evmInPsdu</b>:  EVM in the PSDU of the capture.  index value: 0
 *  - <b>freqErr</b>:  Frequency Error in the capture.  index value: 0
 *  - <b>clockErr</b>:  Symbol Clock Error in the capture.  index value: 0
 *  - <b>ampErr</b>:  IQ Match Amplitude Error in the capture.  index value: 0
 *  - <b>ampErrDb</b>:  IQ Match Amplitude Error in the capture; specified in dB  index value: 0
 *  - <b>phaseErr</b>:  IQ Match Phase Error in the capture.  index value: 0
 *  - <b>rmsPhaseNoise</b>:  Frequency RMS Phase Noise in the capture.  index value: 0
 *  - <b>rmsPowerNoGap</b>:  RMS Power No Gap in the capture.  index value: 0
 *  - <b>rmsPower</b>:  RMS Power in the capture.  index value: 0
 *  - <b>pkPower</b>:  Peak power in the capture.  index value: 0
 *  - <b>rmsMaxAvgPower</b>:  Average max RMS power in the capture.  index value: 0
 *  - <b>bitRate</b>:  Bit Rate, see 802.11b standard.  index value: 0
 *  - <b>modType</b>:  Mod Type, see 802.11b standard.  index value: 0
 *  - <b>valid</b>:  Checks if the capture is valid.  index value: 0
 *  - <b>P_av_each_burst</b>:  Average power of each burst in the capture.  index value: 0
 *  - <b>P_pk_each_burst</b>:  Peak power of each burst in the capture.  index value: 0
 *  - <b>P_av_all</b>:  Average power in the capture.  index value: 0
 *  - <b>P_peak_all</b>:  Peak power in the capture.  index value: 0
 *  - <b>P_av_no_gap_all</b>:  Average power with no gap in the capture.  index value: 0
 *  - <b>P_av_all_dBm</b>:  Average power in the capture; specified in dBm.  index value: 0
 *  - <b>P_peak_all_dBm</b>:  Peak power in the capture; specified in dBm.  index value: 0
 *  - <b>P_av_no_gap_all_dBm</b>:  Average power with no gap in the capture; specified in dBm  index value: 0
 *  - <b>lockedClock</b>:  Locked Clock, see 802.11b standard.  index value: 0
 *  - <b>plcpCrcFail</b>:  1 = PLCP CRC Check Failed, 0 = PLCP CRC Check Passes.  index value: 0
 *  - <b>psduCrcFail</b>:  1 = PSDU CRC Check Failed, 0 = PSDU CRC Check Passes.  index value: 0
 *  - <b>longPreamble</b>:  1 = Long Preamble, 0 = Short Preamble.  index value: 0
 *  - <b>bitRateInMHz</b>:  Bit rate in Mhz in the capture.  index value: 0
 *  - <b>loLeakageDb</b>:  LO leakage in dBc.  index value: 0
 *  - <b>MaxfreqErr</b>:  Maximum frequency error.  index value: 0
 *
 * \section analysis_Power Measurement Names for IQ2010EXT_AnalyzePower()
 *  - <b>valid</b>:  Indicates valid results (1 valid, 0 invalid).  index value: 0
 *  - <b>P_av_each_burst</b>:  Average power of each burst in the capture.  index value: 0
 *  - <b>P_pk_each_burst</b>:  Peak power of each burst in the capture.  index value: 0
 *  - <b>P_av_all</b>:  Average power of whole capture.  index value: 0
 *  - <b>P_peak_all</b>:  Peak power of whole capture.  index value: 0
 *  - <b>P_av_no_gap_all</b>:  Average power with no gap in the capture.  index value: 0
 *  - <b>P_av_all_dBm</b>:  Average power of whole capture; specified in dBm.  index value: 0
 *  - <b>P_peak_all_dBm</b>:  Peak power of whole capture; specified in dBm.  index value: 0
 *  - <b>P_av_no_gap_all_dBm</b>:  Average power, not counting gaps in dBm.  index value: 0
 *
 * \section analysis_FFT Measurement Names for IQ2010EXT_AnalyzeFFT()
 *  - <b>valid</b>:  Returns (value) whether results are valid or not. 1 valid, 0 invalid.  index value: 0
 *  - <b>length</b>:  Returns length of X and Y Vectors above.  index value: 0
 *
 * \section analysis_Bluetooth Measurement Names for IQ2010EXT_AnalyzeBluetooth()
 *  - <b>dataRateDetect</b>:  Detects which data rate is in capture.  index value: 0
 *  - <b>valid</b>:  Flag indicating whether or not the power portion of the Bluetooth analysis was successful (1), or not (0).  index value: 0
 *  - <b>bandwidth20dB</b>:   20 dB bandwidth value Hz.  index value: 0
 *  - <b>deltaF1Average</b>:  The measurement result for deltaF1Avg as specified in BLUETOOTH TEST SPECIFICATION Ver. 1.2/2.0/2.0 + EDR [vol 2] version 2.0.E.2. Requires 00001111 data pattern. Results in Hz.  index value: 0
 *  - <b>deltaF2Max</b>:  The measurement result for deltaF2Max as specified in BLUETOOTH TEST SPECIFICATION Ver. 1.2/2.0/2.0 + EDR [vol 2] version 2.0.E.2. Requires alternating data pattern. Results in Hz.  index value: 0
 *  - <b>deltaF2Average</b>:  The measurement result for deltaF2Avg as specified in BLUETOOTH TEST SPECIFICATION Ver. 1.2/2.0/2.0 + EDR [vol 2] version 2.0.E.2. Requires alternating data pattern. Results in Hz.  index value: 0
 *  - <b>deltaF2MaxAccess</b>:  Similar to the measurement result for deltaF2Max as specified in BLUETOOTH TEST SPECIFICATION Ver. 1.2/2.0/2.0 + EDR [vol 2] version 2.0.E.2. Results measured from Access data. Results in Hz.  index value: 0
 *  - <b>deltaF2AvAccess</b>:  Similar to the measurement result for deltaF2Avg as specified in BLUETOOTH TEST SPECIFICATION Ver. 1.2/2.0/2.0 + EDR [vol 2] version 2.0.E.2. Results measured from Access data. Results in Hz.  index value: 0
 *  - <b>EdrEVMAv</b>:  RMS Differential EVM value (EDR only).  index value: 0
 *  - <b>EdrEVMpk</b>:  Peak Differential EVM value (EDR only).  index value: 0
 *  - <b>EdrEVMvalid</b>:  Indicates validity of EDR EVM Measurements.  index value: 0
 *  - <b>EdrPowDiffdB</b>:  Relative power of EDR section to FM section of packet, in dB.  index value: 0
 *  - <b>freq_deviation</b>:  Similar to the measurement result for deltaF1Avg as specified in BLUETOOTH TEST SPECIFICATION Ver. 1.2/2.0/2.0 + EDR [vol 2] version 2.0.E.2.
 *					  Results measured from Header data. Results in Hz.  index value: 0
 *  - <b>freq_deviationpktopk</b>:  Peak to Peak Frequency Deviation, in Hz during header.  index value: 0
 *  - <b>freq_estHeader</b>:  Estimates the Frequency Offset during the Header in Hz.  index value: 0
 *  - <b>EdrFreqExtremeEdronly</b>:  Reports the extreme value of the frequency variation during DPSK in Hz. Does not include the offset during the header.  index value: 0
 *  - <b>EdrprobEVM99pass</b>:  The percentage of symbols with EVM below the threshold. Threshold for 2 Mbps is 0.3 for 3 Mbps is 0.2.  index value: 0
 *  - <b>EdrEVMvsTime</b>:  Max DEVM Average as specified in BLUETOOTH TEST SPECIFICATION Ver. 1.2/2.0/2.0 + EDR [vol 2] version 2.0.E.2.  index value: 0
 *  - <b>validInput</b>:  Indicates whether or not the input wave was valid.  index value: 0
 *  - <b>maxfreqDriftRate</b>:  1 Mbps only, takes the maximum drift over specified time interval.  index value: 0
 *  - <b>payloadErrors</b>:  Reports the number of data errors in Payload. Not counting CRC. If -1, this value has not been calculated.
 *					 If larger negative number, it reports the length of the payload data vector. This happens when the length of the payload vector is shorter than the length indicated in the payload header.  index value: 0
 *
 * \section analysis_mask Measurement Names for IQ2010EXT_AnalyzeMaskMeasurement() with mask type WIFI_11B
 *  - <b>FREQ_MHZ_LO_B_VSA1</b>:    frequency (M Hz) in region LO_B at worst margin
 *  - <b>MARGIN_DB_LO_B_VSA1</b>:   power (Db) in region LO_B at worst margin
 *  - <b>FREQ_MHZ_LO_A_VSA1</b>:    frequency (M Hz) in region LO_A at worst margin
 *  - <b>MARGIN_DB_LO_A_VSA1</b>:   power (Db) in region LO_A at worst margin
 *  - <b>FREQ_MHZ_UP_A_VSA1</b>:    frequency (M Hz) in region UP_A at worst margin
 *  - <b>MARGIN_DB_UP_A_VSA1</b>:   power (Db) in region UP_A at worst margin
 *  - <b>FREQ_MHZ_UP_B_VSA1</b>:    frequency (M Hz) in region UP_B at worst margin
 *  - <b>MARGIN_DB_UP_B_VSA1</b>:   power (Db) in region UP_B at worst margin
 *  - <b>OBW_MHZ_VSA1</b>:          Occupied Bandwidth measurement in MHz
 *
 * \section analysis_mask Measurement Names for IQ2010EXT_AnalyzeMaskMeasurement() with mask type WIFI_11AG, WIFI_11N_HT20 and WIFI_11N_HT40
 *  - <b>FREQ_MHZ_LO_D_VSA1</b>:    frequency (M Hz) in region LO_D at worst margin
 *  - <b>MARGIN_DB_LO_D_VSA1</b>:   power (Db) in region LO_D at worst margin
 *  - <b>FREQ_MHZ_LO_C_VSA1</b>:    frequency (M Hz) in region LO_C at worst margin
 *  - <b>MARGIN_DB_LO_C_VSA1</b>:   power (Db) in region LO_C at worst margin
 *  - <b>FREQ_MHZ_LO_B_VSA1</b>:    frequency (M Hz) in region LO_B at worst margin
 *  - <b>MARGIN_DB_LO_B_VSA1</b>:   power (Db) in region LO_B at worst margin
 *  - <b>FREQ_MHZ_LO_A_VSA1</b>:    frequency (M Hz) in region LO_A at worst margin
 *  - <b>MARGIN_DB_LO_A_VSA1</b>:   power (Db) in region LO_A at worst margin
 *  - <b>FREQ_MHZ_UP_A_VSA1</b>:    frequency (M Hz) in region UP_A at worst margin
 *  - <b>MARGIN_DB_UP_A_VSA1</b>:   power (Db) in region UP_A at worst margin
 *  - <b>FREQ_MHZ_UP_B_VSA1</b>:    frequency (M Hz) in region UP_B at worst margin
 *  - <b>MARGIN_DB_UP_B_VSA1</b>:   power (Db) in region UP_B at worst margin
 *  - <b>FREQ_MHZ_UP_C_VSA1</b>:    frequency (M Hz) in region UP_C at worst margin
 *  - <b>MARGIN_DB_UP_C_VSA1</b>:   power (Db) in region UP_C at worst margin
 *  - <b>FREQ_MHZ_UP_D_VSA1</b>:    frequency (M Hz) in region UP_D at worst margin
 *  - <b>MARGIN_DB_UP_D_VSA1</b>:   power (Db) in region UP_D at worst margin
 *  - <b>OBW_MHZ_VSA1</b>:          Occupied Bandwidth measurement in MHz
 *
 * \section analysis_spectral Measurement Names for IQ2010EXT_AnalyzeSpectralMeasurement() with spectral type IQ2010EXT_SPECTRAL_11AG, IQ2010EXT_SPECTRAL_11N_HT20, IQ2010EXT_SPECTRAL_11N_HT40 and IQ2010EXT_SPECTRAL_11N
 *  - <b>SUBCARRIER_LO_B_VSA1</b>:  Subcarrier number in region LO_B at worst margin
 *  - <b>VALUE_DB_LO_B_VSA1</b>:    power (Db) in region LO_B at worst margin
 *  - <b>SUBCARRIER_LO_A_VSA1</b>:  Subcarrier number in region LO_A at worst margin
 *  - <b>VALUE_DB_LO_A_VSA1</b>:    power (Db) in region LO_A at worst margin
 *  - <b>SUBCARRIER_UP_B_VSA1</b>:  Subcarrier number in region UP_B at worst margin
 *  - <b>VALUE_DB_UP_B_VSA1</b>:    power (Db) in region UP_B at worst margin
 *  - <b>SUBCARRIER_UP_A_VSA1</b>:  Subcarrier number in region UP_A at worst margin
 *  - <b>VALUE_DB_UP_A_VSA1</b>:    power (Db) in region UP_A at worst margin
 *  - <b>LO_LEAKAGE_DBR_VSA1</b>:   LO leakage
 *
 * \section Rx per Measurement names for IQ2010EXT_RxPer()
 *  - <b>powerLeveldBm</b>:  powerLeveldBm the actual power levels for each enabled port at each power level
 *  - <b>ackRespMaxUs</b>:  ackRespMaxUs maximmum ack response time in us
 *  - <b>ackRespMinUs</b>:  ackRespMinUs minimum ack response time in us
 *  - <b>perPercent</b>:  perPercent the PER result at each power level (%)
 *
 */

/*! @defgroup group_vector_measurement Measurement Names for IQ2010EXT_GetVectorMeasurement()
 *
 * Available measurement names vary for various analysis.  After an analysis has been performed successfully, by calling
 * one of the following functions:
 *   - IQ2010EXT_Analyze80211ag();
 *   - IQ2010EXT_Analyze80211nSISO();
 *   - IQ2010EXT_Analyze80211nComposite();
 *   - IQ2010EXT_Analyze80211b();
 *   - IQ2010EXT_AnalyzeFFT();
 *   - IQ2010EXT_AnalyzePowerRamp80211b();
 *   - IQ2010EXT_AnalyzeBluetooth();
 *   - IQ2010EXT_AnalyzeMaskMeasurement();
 *
 * \section analysis_80211ag Measurement Names for IQ2010EXT_Analyze80211ag()
 *  - <b>hhEst</b>:  64-element complex vector that represents the FFT output of the two long symbols in the PLCP preamble of the OFDM signal.  index value: 0
 *  - <b>psdu</b>:  The PSDU data. 0/1 values. Includes the MAC Header and the FCS, if present .  index value: 0
 *  - <b>startPointers</b>:  Provides the approximate starting locations of each packet detected in the input data.
 *					 If no packet detected, this is an empty vector.  index value: 0
 *  - <b>plcp</b>:  PLCP (binary) data as 1/0s.  index value: 0
 *
 * \section analysis_mimo Measurement Names for IQ2010EXT_AnalyzeMimo()
 *  - <b>channelEst</b>:  Channel estimate matrix; dimension NStreams x NTones x NRx. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>rxRmsPowerDb</b>:  RMS power of estimated channels; dimension NStreams x NRx. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>isolationDb</b>:  Matrix that indicates isolation between streams; column 1 is for Rx signal containing main power for stream 1, etc; dimension NStreams x NStreams.
 *				   Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *				   Note: Isolation can only be measured with direct-mapping signals.
 *  - <b>evmSymbols</b>:  Per symbol and stream; dimension NStreams x NSymbols. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>evmTones</b>:  Per tone and stream; dimension NStreams x Ntones. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>PhaseNoiseDeg_Symbols</b>:  Per symbol and VSA signal; dimension NRx x Nsymbols. Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *  - <b>demodSymbols</b>: Complex demodulated symbols; dimension NTones x NSymbols x Nstreams.  This provides the symbol constellation I (Re) and Q (Im) arrays.
 *					Each stream will have a corresponding value; therefore, the index value is [0 - (StreamNum-1)]
 *
 * \section analysis_80211b Measurement Names for IQ2010EXT_Analyze80211b()
 *  - <b>evmInPlcp</b>: Evm in PLCP.  index value: 0
 *  - <b>evmErr</b>: Evm error.  index value: 0
 *  - <b>loLeakageDb</b>: LO/DC Leakage [dBc].  index value: 0
 *
 * \section analysis_FFT Measurement Names for IQ2010EXT_AnalyzeFFT()
 *  - <b>x</b>: X-axis values, typically frequency. Vector is returned.  index value: 0
 *  - <b>y</b>: Y-axis values, power in dBm. Vector is returned.  index value: 0
 *
 * \section analysis_PowerRamp80211b Measurement Names for IQ2010EXT_AnalyzePowerRamp80211b()
 *  - <b>on_mask_x</b>: Power on ramp mask x-axis.  index value: 0
 *  - <b>off_mask_x</b>: Power off ramp mask x-axis.  index value: 0
 *  - <b>on_mask_y</b>: Power on ramp mask y-axis.  index value: 0
 *  - <b>off_mask_y</b>: Power off ramp mask y-axis.  index value: 0
 *  - <b>on_power_inst</b>: Instant power on ramp.  index value: 0
 *  - <b>off_power_inst</b>: Instant power off ramp.  index value: 0
 *  - <b>on_power_peak</b>: Power on ramp peak values.  index value: 0
 *  - <b>off_power_peak</b>: Power off ramp peak values.  index value: 0
 *  - <b>on_time_vect</b>: Power on ramp time vector.  index value: 0
 *  - <b>off_time_vect</b>: Power off ramp time vector.  index value: 0
 *  - <b>on_time</b>: Ramp on time.  index value: 0
 *  - <b>off_time</b>: Ramp off time.  index value: 0
 *
 * \section analysis_Bluetooth Measurement Names for IQ2010EXT_AnalyzeBluetooth()
 *  - <b>P_av_each_burst</b>: Average power of each burst.  index value: 0
 *  - <b>P_pk_each_burst</b>: Peak power of each burst.  index value: 0
 *  - <b>complete_burst</b>: Vector indicating whether or not each burst is complete.
 *					  All elements are either (1 beginning and end transitions detected), or (0 burst is missing either beginning or end transition).
 *					  index value: 0
 *  - <b>start_sec</b>: Starting time of each burst, in seconds.  index value: 0
 *  - <b>stop_sec</b>: End time of each burst, in seconds.  index value: 0
 *  - <b>freq_est</b>: Initial freq offset of each burst detected, in Hz.  index value: 0
 *  - <b>freqEstPacketPointer</b>: Pointers to which packet is pointed to in each element of freq_est.  index value: 0
 *  - <b>freq_drift</b>: Initial freq carrier drift of each burst detected, in Hz.  index value: 0
 *  - <b>freqDriftPacketPointer</b>: Pointers to which packet is pointed to in each element of freq_drift.  index value: 0
 *  - <b>freqDeviationPointer</b>: Pointers to which packet is pointed to in each element of the above two measurements.  index value: 0
 *  - <b>EdrFreqvsTime</b>: Enhanced data rate for frequency versus time.  index value: 0
 *  - <b>EdrExtremeOmegaI0</b>: Extreme value of (Omega_0 + Omega_i).  index value: 0
 *
 * \section analysis_mask Measurement Names for IQ2010EXT_AnalyzeMaskMeasurement() with mask type WIFI_11B, WIFI_11AG, WIFI_11N_HT20 and WIFI_11N_HT40
 *  - <b>x</b>: X-axis values, typically frequency. Vector is returned.  index value: 0
 *  - <b>y</b>: Y-axis values, power in dBm. Vector is returned.  index value: 0
 *
 */



//! spcified the path that is used to invoke LitePoint Connectivity server.
/*!
 * \param[in] litePointConnectionPath The path of connectivity server.
 *
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_SetLpcPath(char *litePointConnectionPath);

//FM IQMeasure functions - merged on 08/09/2010

//! Set FM VSG Parameters
/*!
 * \param[in] carrierFreqHz Sets the FM Carrier Frequency (Hz).
 * \param[in] carrierPowerdBm Sets the FM Carrier Power (dBm).
 * \param[in] modulationEnable Sets the FM Modulation (ON/OFF).
 * \param[in] totalFmDeviationHz Sets the Total Peak FM Deviation (Hz). Note : totalFmPeakDeviationHz = Audio Deviation + Pilot Deviation( if stereo is enabled) + RDS Deviation( if RDS is enabled).
 * \param[in] stereoEnable Enable or Disable Stereo Mode ( ON/OFF).
 * \param[in] pilotDeviationHz Sets the Pilot Deviation(Hz) and will be used if Stereo is Enabled.
 * \param[in] rdsEnable Enable or Disable RDS ( ON/OFF).
 * \param[in] rdsDeviationHz Sets the RDS Deviation(Hz) and will be used if RDS is Enabled.
 * \param[in] preEmphasisMode Sets the Pre-Emphasis Filter value in us(Example: 0, 25, 50, 75).

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_SetVsg(unsigned int carrierFreqHz = 100000000,
							   double carrierPowerdBm = -40,
							   int modulationEnable = ON,
							   unsigned int totalFmDeviationHz = 75000,
							   int stereoEnable = OFF,
							   unsigned int pilotDeviationHz = 7500,
							   int rdsEnable = OFF,
							   unsigned int rdsDeviationHz = 2000,
							   unsigned int preEmphasisUs = PRE_EMPHASIS_75US,
							   char* rdsTransmitString = "LP_rds_transmit");

//! Return the FM VSG Parameters that is currently setup in the Tester
/*!
 * \param[out] carrierFreqHz Returns the FM Carrier Frequency (Hz).
 * \param[out] carrierPowerdBm Returns the FM Carrier Power (dBm).
 * \param[out] modulationEnabled Returns the FM Modulation State(1: ON/0: OFF).
 * \param[out] totalFmDeviationHz Returns the Total Peak FM Deviation (Hz). Note : totalFmPeakDeviationHz = Audio Deviation + Pilot Deviation( if stereo is enabled) + RDS Deviation( if RDS is enabled).
 * \param[out] stereoEnabled Returns Stereo Mode (1: ON/0: OFF).
 * \param[out] pilotDeviationHz Returns the Pilot Deviation(Hz) and will be used if Stereo is Enabled.
 * \param[out] rdsEnabled Returns RDS status(1: ON/0: OFF).
 * \param[out] rdsDeviationHz Returns the RDS Deviation(Hz) and will be used if RDS is Enabled.
 * \param[out] preEmphasisMode Returns the Pre-Emphasis Filter value.


 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */

IQMEASURE_API int LP_FM_GetVsgSettings(unsigned int *carrierFreqHz,
									   double *carrierPowerdBm,
									   int *modulationEnabled,
									   unsigned int *totalFmDeviationHz,
									   int *stereoEnabled,
									   unsigned int *pilotDeviationHz,
									   int *rdsEnabled,
									   unsigned int *rdsDeviationHz,
									   unsigned int *preEmphasisMode
									   );

//! Sets the FM carrier frequency.
/*!
* \param[in] carrierFreqHz Sets the FM Carrier Frequency (Hz).
* \param[in][Optional] carrierPowerdBm Sets the FM Carrier Power (dBm) if needed to compensate for cable loss due to the changed frequency.

* \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
*/
IQMEASURE_API int LP_FM_SetFrequency(unsigned int carrierFreqHz, double carrierPowerdBm);

//! Sets the FM carrier power.
/*!
* \param[in] carrierPowerdBm Sets the FM Carrier Power (dBm).

* \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
*/
IQMEASURE_API int LP_FM_SetCarrierPower(double carrierPowerdBm);

//! Sets the Single tone audio signal parameters for VSG Transmit: Stereo mode assigns the single tone to a left and right channel and the phase relationship between the channels is arbitrary.
/*!
 * \param[in] audioToneFreqHz Sets the single tone audio frequency (Hz).
 * \param[in] leftRightChannelSelect Sets the channel information for a stereo Tone. LEFT assigns single tone to LEFT Channel only ,RIGHT assigns single tone to RIGHT Channel only , LEFT_RIGHT assigns single tone to LEFT and RIGHT Channel with arbitrary phase relationship.
 * \param[in] audioToneAmpdB Sets the audio signal power for the single tone(dB). Note: 0 dB corresponds to 1Vpp.
 * \param[in] stereo Indicates if Stereo is Enabled or not ( ON / OFF).Note: The Stereo Mode is enabled in the LP_FM_SetVsg function.

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_SetAudioSingleTone(double audioToneFreqHz,
										   int leftRightChannelSelect,
										   double audioToneAmpPercent,
										   int stereo);

//! Sets the Audio Tone Mode to Amplitude.  Neede before calling any of the tone settings for amplitude functions
/*!

* \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
*/
IQMEASURE_API int LP_FM_SetAudioToneModeAmplitude(void);

//! Sets the multi tone audio signal parameters: upto maximum of 12 tones. Note: Stereo tone limits the maximum Left Channels and Right Channels to 6 and there is not defined phase relationship between the channels.
/*!
 * \param[in] freqHz Sets an array of audio tones (Hz). Note: Maximum size = 12.
 * \param[in] channelSelect Sets an array of audio tones channel corresponding to freqHz tones.LEFT assigns single tone to LEFT Channel only ,RIGHT assigns single tone to RIGHT Channel only. This array is ignored if Stereo is not enabled in the LP_FM_SetVsg Function. Note: Maximum size = 12.
 * \param[in] amplitudePercent Sets an array of audio signal power corresponding to freqHz tones (dB).
 * \param[in] stereo Indicates if Stereo is Enabled or not ( ON / OFF).Note: The Stereo Mode is enabled in the LP_FM_SetVsg function.
 * \param[in] toneCount Provides information about the total number of tones that will be set.

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_SetAudioToneArray(double* freqHz,
										  int* channelSelect,
										  double* amplitudePercent,
										  int stereo,
										  unsigned int toneCount);

//! Sets the multi tone audio signal parameters: upto maximum of 12 tones. Note: Stereo tone limits the maximum Left Channels and Right Channels to 6 and there is not defined phase relationship between the channels.
/*!
 * \param[in] freqHz Sets an array of audio tones (Hz). Note: Maximum size = 12.
 * \param[in] channelSelect Sets an array of audio tones channel corresponding to freqHz tones.LEFT assigns single tone to LEFT Channel only ,RIGHT assigns single tone to RIGHT Channel only. This array is ignored if Stereo is not enabled in the LP_FM_SetVsg Function. Note: Maximum size = 12.
 * \param[in] amplitudeDeviationHz Sets an array of individual audio signal deviation corresponding to freqHz tones (Hz).
 * \param[in] stereo Indicates if Stereo is Enabled or not ( ON / OFF).Note: The Stereo Mode is enabled in the LP_FM_SetVsg function.
 * \param[in] toneCount Provides information about the total number of tones that will be set.

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */

IQMEASURE_API int LP_FM_SetAudioToneArrayDeviation(double* freqHz,
										  int* channelSelect,
										  double* amplitudeDeviationHz,
										  int stereo,
										  unsigned int toneCount);

//! Returns the multi tone audio signal Parameters
/*!
 * \param[out] freqHz Returns an array of audio tones (Hz).
 * \param[out] channelSelect Returns an array of audio tones channel corresponding to freqHz tones.
 * \param[out] amplitudePercent Returns an array of audio signal power corresponding to freqHz tones (dB). Note: 0 dB corresponds to 1Vpp.
 * \param[in] toneCount Provides information about the total number of tones that will be returned.

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_GetAudioToneArray(double *freqHz,
										  int *channelSelect,
										  double *amplitudePercent,
										  unsigned int toneCount);

//! Clears all the Audio tones
/*!
 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_DeleteAudioTones();

//! Starts FM VSG Transmit
/*!
 * \return ERR_OK RR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_StartVsg();

//! Stops FM VSG Transmit
/*!
 * \return ERR_OK
 */
IQMEASURE_API int LP_FM_StopVsg();

//! IQMeasure FM VSG AM Distortion setup and Enable/Disable
/*!
 * \param[in] amDistortionEnable Enable AM Distortion settings ( ON/OFF).
 * \param[in] amFrequencyHz Sets the AM Modulating Frequency (Hz).
 * \param[in] amDepthPercent Sets the am Distortion depth (percent).

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_SetVsgDistortion(int amDistortionEnable = OFF,
										 unsigned int amFrequencyHz = 1000,
										 unsigned int amDepthPercent = 30);

//! Get FM VSG AM Distortion Parameters currently applied to the tester
/*!
 * \param[out] amDistortionEnableStatus Returns AM Distortion Status (1: ON/0: OFF).
 * \param[out] amFrequencyHz Returns the AM Modulating Frequency (Hz).
 * \param[out] amDepthPercent Returns the am Distortion depth (percent).

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_GetVsgDistortion(double *amDistortionEnableStatus,
										 unsigned int *amFrequencyHz,
										 unsigned int *amDepthPercent);

//! Setup FM VSG Interference Parameters and Start transmit
/*!
 * \param[in] interfererRelativePowerdBm Sets the Interfering Carrier Power (dBm) - relative to the main carrier. Note: The total power(Main Carrier Power + Interference Carrier Power is limited to -40 dBm
 * \param[in] interfererCarrierOffsetHz Sets the FM Carrier Frequency Offset from the Main Carrier Frequency (Hz).
 * \param[in] interfererPeakFreqDeviationHz Sets the total peak FM Deviation (Hz) of the Interferer.
 * \param[in] interfererModulationEnable Enable or Disable FM Modulation on the Interferer ( ON/OFF).
 * \param[in] interfererAudioFreqHz Sets the Single tone audio frequency(Hz) corresponding to the interferencePeakDeviationHz.

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_StartVsgInterference(double interfererRelativePowerdBm,
											 int interfererCarrierOffsetHz,
											 int interfererPeakFreqDeviationHz,
											 int interfererModulationEnable,
											 unsigned int interfererAudioFreqHz);

//! Get FM VSG Interference Parameters currently applied to the tester
/*!
 * \param[in] interfererRelativePowerdBm Returns the Interfering Carrier Power (dBm) - relative to the main carrier. Note: The total power is limited to -40 dBm
 * \param[in] interfererCarrierOffsetHz Returns the FM Carrier Frequency Offset from the Main Carrier Frequency (Hz).
 * \param[in] interfererPeakFreqDeviationHz Returns the total peak FM Deviation (Hz) of the Interferer.
 * \param[in] interfererModulationEnabled Returns FM Modulation Status on the Interferer (1: ON/0: OFF).
 * \param[in] interfererAudioFreqHz Returns the Single tone audio frequency(Hz).

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_GetVsgInterferenceSettings(double *interfererRelativePowerdBm,
												   int *interfererCarrierOffsetHz,
												   int *interfererPeakFreqDeviationHz,
												   int *interfererModulationEnabled,
												   unsigned int *interfererAudioFreqHz);

//! Stops FM VSG Interference Transmit
/*!
 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_StopVsgInterference();

//! Set FM VSA Parameters
/*!
 * \param[in] carrierFreqHz Sets the VSA Carrier Frequency (Hz)
 * \param[in] expectedPeakInputPowerdBm Sets the Expected Peak input power (dBm)

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_SetVsa(unsigned int carrierFreqHz = 100e6,
							   double expectedPeakInputPowerdBm = -20);

//! Get FM VSA Parameters currently applied to the tester
/*!
 * \param[out] getCarrierFreqHz Gets the VSA Carrier Frequency (Hz)
 * \param[out] getInputPowerdBm Gets the Expected Peak input power (dBm)

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_GetVsaSettings(unsigned int *carrierFreqHz,
									   double *expectedPeakInputPowerdBm);

//! Start VSA Data capture
/*!
 * \param[in] captureTimemillisec Sets the VSA Capture Time (ms)

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_VsaDataCapture(double captureTimemillisec = 170.67);

//! performs RF Analysis on the VSA Data Capture
/*!
 * \param[in] rfRBWHz Specifies the RF Resolution Bandwidth (Hz)
 * \param[in] rfOBWPercent Specifies the RF Occupied Bandwidth (percent)
 * \param[in] rfPowerMeasBWHz Specifies the RF Power Measurement Bandwidth (Hz)
 * \param[in] windowType Specifies the Window type (BLACKMAN_HARRIS, HANNING, FLAT_TOP)

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_Analyze_RF(int rfRBWHz = 200,
								   int rfOBWPercent = 99,
								   int rfPowerMeasBWHz = 200000,
								   int windowType = BLACKMAN_HARRIS);

//! performs Demod Analysis on the VSA Data Capture
/*!
 * \param[in] audioRBWHz Specifies the Audio Resolution Bandwidth (Hz)

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_Analyze_Demod(int audioRBWHz = 100);

//! performs Mono Audio Analysis on the VSA Data Capture ( or ) Audio waveform data loaded using LP_FM_LoadAudioCapture function
/*!
 * \param[in] audioRBWHz Specifies the Audio Resolution Bandwidth (Hz)
 * \param[in] audioFreqLowLimitHz Specifies the lower bound (Hz) of analyzed range for audio analysis (Hz)
 * \param[in] audioFreqHiLimitHz Specifies the Upper bound (Hz) of analyzed range for audio analysis (Hz)
 * \param[in] filterCount Specifies total number of audio filters to be applied Note: MAX = 3
 * \param[in] filterType1 Type of filter to be applied
 * \param[in] filterParam1 Filter parameter corresponding to filterType1
 * \param[in] filterType2 Type of filter to be applied
 * \param[in] filterParam2  Filter parameter corresponding to filterType2
 * \param[in] filterType3 Type of filter to be applied
 * \param[in] filterParam3  Filter parameter corresponding to filterType3

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_Analyze_Audio_Mono(int audioRBWHz = 50,
										   int audioFreqLowLimitHz = 300,
										   int audioFreqHiLimitHz = 15000,
										   int filterCount = 3,
									       int filterType1 = 2,
									       double filterParam1 = 15000,
									       int filterType2 = 6,
									       double filterParam2 = 0,
									       int filterType3 = 3,
									       double filterParam3 = 75e-6);

//! performs Stereo Audio Analysis on the VSA Data Capture ( or ) Audio waveform data loaded using LP_FM_LoadAudioCapture function
/*!
 * \param[in] audioRBWHz Specifies the Audio Resolution Bandwidth (Hz)
 * \param[in] audioFreqLowLimitHz Specifies the lower bound (Hz) of analyzed range for audio analysis (Hz)
 * \param[in] audioFreqHiLimitHz Specifies the Upper bound (Hz) of analyzed range for audio analysis (Hz)
 * \param[in] filterCount Specifies total number of audio filters to be applied Note: MAX = 3
 * \param[in] filterType1 Type of filter to be applied
 * \param[in] filterParam1 Filter parameter corresponding to filterType1
 * \param[in] filterType2 Type of filter to be applied
 * \param[in] filterParam2  Filter parameter corresponding to filterType2
 * \param[in] filterType3 Type of filter to be applied
 * \param[in] filterParam3  Filter parameter corresponding to filterType3

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_Analyze_Audio_Stereo(int audioRBWHz,
										     int audioFreqLowLimitHz,
										     int audioFreqHiLimitHz,
											 int filterCount,
											 int filterType1,
											 double filterParam1,
											 int filterType2,
											 double filterParam2,
											 int filterType3,
											 double filterParam3);


//! Get an FM scalar measurement result
/*!
 * \param[in] measurement The measurement name.  Please refer to \ref group_fm_scalar_measurement "Scalar FM Measurements" for all available measurement names
 * \param[in] index The index of the measurement.  In most case, index would be zero.
 *
 * \return The value of the measurement.  -99999.99 (a special defined negative value) will be returned if no measurement available
 */
IQMEASURE_API double LP_FM_GetScalarMeasurement(char *measurement, int index=0);



//! Get a vector measurement result
/*!
 * \param[in] measurement The measurement name.  Please refer to \ref group_fm_vector_measurement "Vector FM Measurements" for all available measurement names
 * \param[out] bufferReal Returns the real part of vector
 * \param[out] bufferImag Returns the imag part of vector
 * \param[in] bufferLength Indicates the length of bufferReal and bufferImag (in Bytes)
 *
 * \return The number of elements in bufferReal or/and bufferImag
 */
IQMEASURE_API int LP_FM_GetVectorMeasurement(char *measurement, double bufferReal[], double bufferImag[], int bufferLength);

//! Captures the Audio data using the AIM Module
/*!
 * \param[in] saveFileLocation Specifies the location including the file name where the wav file needs to be stored( Path)
 * \param[in] captureDurationSec Specifies the capture duration ( seconds)
 * \param[in] samplingRate Specifies the sampling rate ( Hz)
 * \param[in] stereo Specifies the stereo status (ON/OFF)

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_AudioDataCapture(char* saveFileLocation,
										 double captureDurationMilliSec,
										 int samplingRate,
										 int stereo);
//! Loads the Audio wave file for Audio Analysis
/*!
 * \param[in] fileName Specifies the full path of the file that is to be loaded ( Path)

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_LoadAudioCapture(char* fileName);

//! Generates the Audio Stimulus to the DUT
/*!
 * \param[in] toneCount Specifies the total number of tones
 * \param[in] stereoEnable Specifies if the audio is mono or stereo
 * \param[in] leftRightRelation Specifies the channel relation(applies only if stereo is enabled) - LEFT_ONLY, RIGHT_ONLY, LEFT_EQUALS_RIGHT, LEFT_EQUALS_MINUS_RIGHT
 * \param[in] freq_Hz Specifies the array of audio tones
 * \param[out] stimulusOutput Specifies the location of the audio wave file generated ( path)
 * \param[in] bufferSize Specifies the maximun size of characters for the stimulusOutput

 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */
IQMEASURE_API int LP_FM_AudioStimulusGenerateAndPlayMultiTone(double sampleRateHz = 48000,
													double deviationPercent = 100,
													double peakVoltageLevelVolts = 1,
													int toneCount = 1,
													int stereoEnable = 0,
													int* leftRightRelation = NULL,
													double* freqHz = NULL,
													double durationMilliSeconds = 500,
													char* audioWaveFileOutput = NULL);

IQMEASURE_API int LP_FM_AudioStimulusGenerateAndPlaySingleTone(double sampleRateHz = 48000,
													double deviationPercent = 100,
													double peakVoltageLevelVolts = 1,
													int stereoEnable = 0,
													int leftRightRelation = LEFT_EQUALS_RIGHT,
													double freqHz = 1000,
													double durationMilliSeconds = 500,
													char* audioWaveFileOutput = NULL);

IQMEASURE_API int LP_FM_StopAudioPlay();

// IQfuji merge /* -cfy@sunnyvale, 2012/3/13- */
IQMEASURE_API int SetTesterHwVersion(double hwVersion);
IQMEASURE_API int GetTesterHwVersion(double *hwVersion);
/* <><~~ */

//! Get memory addresses for a capture
/*!
* \param[in] dut
* \param[in] captureIndex
* \param[out] real
* \param[out] imag
* \param[out] length
*
* \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
*/

IQMEASURE_API int LP_GetCapture(int    dut,
                                int    captureIndex,
                                double *real[],
                                double *imag[],
                                int    length[]);

//! Enable/Disable Multi-thread
/*!
* \param[in] enableMultiThread
* \param[in] numberOfThreads
*
* \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
*/

IQMEASURE_API int LP_EnableMultiThread(int enableMultiThread,
									   int numberOfThreads);

IQMEASURE_API int LP_SetUserDataPtr(void *userData);

//! Set default NFC
/*!
* \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
*/

IQMEASURE_API int LP_SetDefaultNfc();

//! Set Tx Amplitude
/*!
* \param[in] userSignalAmplitudeType - in A/m or Volt
* \param[in] userSignalAmplitude
*
* \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
*/

IQMEASURE_API int LP_SetNfcTxAmplitude(IQV_USER_SIGNAL_AMPLITUDE_TYPE userSignalAmplitudeType, double userSignalAmplitude);

//! Set Trigger Mask NFC
/*!
* \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
*/

IQMEASURE_API int LP_SetTriggerMaskNfc();

//! Initiate NFC
/*!
* \param[in] filename - File name of the wave file
*
* \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
*/

IQMEASURE_API int LP_InitiateNfc(char *fileName);

//! Set Rx NFC
/*!
* \param[in] triggerTimeout - trigger timeout
* \param[in] sampleingTimeSecs - sampleing time
*
* \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
*/

IQMEASURE_API int LP_SetRxNfc(double triggerTimeout, double sampleingTimeSecs);

//! Set Tx NFC
/*!
* \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
*/

IQMEASURE_API int LP_SetTxNfc();

//! Continuous Data Capture Handling
/*!
* \param[in] dcContEnum - type of data capture handling
*
* \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
*/

IQMEASURE_API int LP_ContCapture(IQV_DC_CONT_ENUM dcContEnum);

//! Terminate NFC
/*!
* \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
*/

IQMEASURE_API int LP_TerminateNfc();

//! Analysis NFC
/*!
* \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
*/

IQMEASURE_API int LP_AnalysisNfc();

//! Loads the modulation file (waveform) to VSG
/*!
 * \param[in] modFileName The .mod file to be loaded
 * \param[in] autoPlay - Lets the user to turn of autoPlay On or Off(TRUE or FALSE)
 *
 * \return ERR_OK if successful; otherwise call LP_GetErrorString() for detailed error message.
 */

IQMEASURE_API int LP_SetVsgModulation_SetPlayCondition(char *modFileName, bool autoPlay = false);

//! Sets up VSA for Bluetooth data capturing and lets user select the VSA IF
/*!
 * \param[in] rfFreqHz The center frequency of Bluetooth RF signal (Hz)
 * \param[in] rfAmplDb The amplitude of the peak power (dBm) of the signal
 * \param[in] port The port to which the VSG connects, with the following options:
 *				- =1: OFF
 *				- =2: Left RF port (RF1) (Default)
 *				- =3: Right RF port (RF2)
 *				- =4: Baseband
 * \param[in] triggerLevelDb The trigger level (dBm) used for signal trigger (ignored in Free-run and External Trigger Modes)
 * \param[in] triggerPreTime The pre-trigger time used for signal capture
 * \param[in] btShiftHz The VSA IF Freq (Hz). Default : 7MHz
 * \param[in] extAttenDb The external attenuation (dB).  Set to 0 always.
 *
 * \return ERR_OK if no errors; otherwise call LP_GetErrorString() for detailed error message.
 * \remark For VSA to work optimally with the input signal, set rfAmplDb to the peak power of the input signal.
 */

IQMEASURE_API int LP_SetVsaBluetooth_BTShiftHz(double rfFreqHz, double rfAmplDb, int port, double extAttenDb = 0, double triggerLevelDb = -25, double triggerPreTime = 10e-6, double btShiftHz = 7e6);

IQMEASURE_API int LP_FM_SetVsa_Agc_On(unsigned int carrierFreqHz, double expectedPeakInputPowerdBm);

#endif // end of _IQMEASURE_H_
