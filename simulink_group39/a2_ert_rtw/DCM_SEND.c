/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DCM_SEND.c
 *
 * Code generated for Simulink model 'a2'.
 *
 * Model version                  : 3.7
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Nov 27 11:54:41 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "a2_types.h"
#include "DCM_SEND_private.h"
#include "a2.h"
#include "DCM_SEND.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>

/* Forward declaration for local functions */
static void a2_SystemCore_setup(freedomk64f_SCIWrite_a2_T *obj);
static void a2_SystemCore_setup(freedomk64f_SCIWrite_a2_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* System initialize for Simulink Function: '<S2>/Function Call' */
void DCM_SEND_Init(void)
{
  /* Start for MATLABSystem: '<S6>/Serial Transmit' */
  a2_DW.obj_j1.isInitialized = 0;
  a2_DW.obj_j1.matlabCodegenIsDeleted = false;
  a2_SystemCore_setup(&a2_DW.obj_j1);
}

/* Output and update for Simulink Function: '<S2>/Function Call' */
void DCM_SEND(void)
{
  int32_T i;
  uint8_T status;

  /* SignalConversion generated from: '<S6>/In1' */
  a2_B.lower_rate_limit = a2_B.lower_rate_limit_p;

  /* SignalConversion generated from: '<S6>/In2' */
  a2_B.upper_rate_limit = a2_B.upper_rate_limit_m;

  /* SignalConversion generated from: '<S6>/In3' */
  a2_B.PVARP = a2_B.PVARP_a;

  /* SignalConversion generated from: '<S6>/In4' */
  a2_B.mode = a2_B.mode_f;

  /* SignalConversion generated from: '<S6>/In5' */
  a2_B.av_delay = a2_B.av_delay_f;

  /* SignalConversion generated from: '<S6>/In6' */
  a2_B.reaction_time = a2_B.reaction_time_i;

  /* SignalConversion generated from: '<S6>/In7' */
  a2_B.response_factor = a2_B.response_factor_n;

  /* SignalConversion generated from: '<S6>/In8' */
  a2_B.activity_threshold = a2_B.activity_threshold_o;

  /* SignalConversion generated from: '<S6>/In9' */
  a2_B.recovery_time = a2_B.recovery_time_e;

  /* SignalConversion generated from: '<S6>/In10' */
  a2_B.MSR = a2_B.MSR_g;

  /* SignalConversion generated from: '<S6>/In12' */
  a2_B.atr_amp = a2_B.atr_amp_p;

  /* SignalConversion generated from: '<S6>/In13' */
  a2_B.atr_pulse_width = a2_B.atr_pulse_width_f;

  /* SignalConversion generated from: '<S6>/In14' */
  a2_B.ARP = a2_B.ARP_c;

  /* SignalConversion generated from: '<S6>/In15' */
  a2_B.atr_threshold = a2_B.atr_threshold_e;

  /* SignalConversion generated from: '<S6>/In17' */
  a2_B.vent_amp = a2_B.vent_amp_e;

  /* SignalConversion generated from: '<S6>/In18' */
  a2_B.vent_pulse_width = a2_B.vent_pulse_width_h;

  /* SignalConversion generated from: '<S6>/In19' */
  a2_B.VRP = a2_B.VRP_j;

  /* SignalConversion generated from: '<S6>/In20' */
  a2_B.vent_threshold = a2_B.vent_threshold_o;

  /* S-Function (any2byte): '<S6>/Byte Pack26' */

  /* Pack: <S6>/Byte Pack26 */
  (void) memcpy(&a2_B.BytePack26, &a2_B.mode,
                1);

  /* S-Function (any2byte): '<S6>/Byte Pack 1' */

  /* Pack: <S6>/Byte Pack 1 */
  (void) memcpy(&a2_B.BytePack1, &a2_B.lower_rate_limit,
                1);

  /* S-Function (any2byte): '<S6>/Byte Pack 2' */

  /* Pack: <S6>/Byte Pack 2 */
  (void) memcpy(&a2_B.BytePack2, &a2_B.upper_rate_limit,
                1);

  /* S-Function (any2byte): '<S6>/Byte Pack 3' */

  /* Pack: <S6>/Byte Pack 3 */
  (void) memcpy(&a2_B.BytePack3[0], &a2_B.PVARP,
                2);

  /* S-Function (any2byte): '<S6>/Byte Pack27' */

  /* Pack: <S6>/Byte Pack27 */
  (void) memcpy(&a2_B.BytePack27, &a2_B.av_delay,
                1);

  /* S-Function (any2byte): '<S6>/Byte Pack28' */

  /* Pack: <S6>/Byte Pack28 */
  (void) memcpy(&a2_B.BytePack28[0], &a2_B.reaction_time,
                2);

  /* S-Function (any2byte): '<S6>/Byte Pack29' */

  /* Pack: <S6>/Byte Pack29 */
  (void) memcpy(&a2_B.BytePack29, &a2_B.response_factor,
                1);

  /* S-Function (any2byte): '<S6>/Byte Pack30' */

  /* Pack: <S6>/Byte Pack30 */
  (void) memcpy(&a2_B.BytePack30[0], &a2_B.activity_threshold,
                8);

  /* S-Function (any2byte): '<S6>/Byte Pack31' */

  /* Pack: <S6>/Byte Pack31 */
  (void) memcpy(&a2_B.BytePack31[0], &a2_B.recovery_time,
                2);

  /* S-Function (any2byte): '<S6>/Byte Pack32' */

  /* Pack: <S6>/Byte Pack32 */
  (void) memcpy(&a2_B.BytePack32, &a2_B.MSR,
                1);

  /* S-Function (any2byte): '<S6>/Byte Pack34' */

  /* Pack: <S6>/Byte Pack34 */
  (void) memcpy(&a2_B.BytePack34[0], &a2_B.atr_amp,
                8);

  /* S-Function (any2byte): '<S6>/Byte Pack35' */

  /* Pack: <S6>/Byte Pack35 */
  (void) memcpy(&a2_B.BytePack35[0], &a2_B.atr_pulse_width,
                8);

  /* S-Function (any2byte): '<S6>/Byte Pack36' */

  /* Pack: <S6>/Byte Pack36 */
  (void) memcpy(&a2_B.BytePack36[0], &a2_B.ARP,
                2);

  /* S-Function (any2byte): '<S6>/Byte Pack37' */

  /* Pack: <S6>/Byte Pack37 */
  (void) memcpy(&a2_B.BytePack37[0], &a2_B.atr_threshold,
                8);

  /* S-Function (any2byte): '<S6>/Byte Pack39' */

  /* Pack: <S6>/Byte Pack39 */
  (void) memcpy(&a2_B.BytePack39[0], &a2_B.vent_amp,
                8);

  /* S-Function (any2byte): '<S6>/Byte Pack40' */

  /* Pack: <S6>/Byte Pack40 */
  (void) memcpy(&a2_B.BytePack40[0], &a2_B.vent_pulse_width,
                8);

  /* S-Function (any2byte): '<S6>/Byte Pack41' */

  /* Pack: <S6>/Byte Pack41 */
  (void) memcpy(&a2_B.BytePack41[0], &a2_B.VRP,
                2);

  /* S-Function (any2byte): '<S6>/Byte Pack42' */

  /* Pack: <S6>/Byte Pack42 */
  (void) memcpy(&a2_B.BytePack42[0], &a2_B.vent_threshold,
                8);

  /* SignalConversion generated from: '<S6>/Serial Transmit' */
  a2_B.TmpSignalConversionAtSerial[0] = a2_B.BytePack26;
  a2_B.TmpSignalConversionAtSerial[1] = a2_B.BytePack1;
  a2_B.TmpSignalConversionAtSerial[2] = a2_B.BytePack2;
  a2_B.TmpSignalConversionAtSerial[5] = a2_B.BytePack27;
  a2_B.TmpSignalConversionAtSerial[3] = a2_B.BytePack3[0];
  a2_B.TmpSignalConversionAtSerial[6] = a2_B.BytePack28[0];
  a2_B.TmpSignalConversionAtSerial[4] = a2_B.BytePack3[1];
  a2_B.TmpSignalConversionAtSerial[7] = a2_B.BytePack28[1];
  a2_B.TmpSignalConversionAtSerial[8] = a2_B.BytePack29;
  a2_B.TmpSignalConversionAtSerial[17] = a2_B.BytePack31[0];
  a2_B.TmpSignalConversionAtSerial[18] = a2_B.BytePack31[1];
  a2_B.TmpSignalConversionAtSerial[19] = a2_B.BytePack32;
  a2_B.TmpSignalConversionAtSerial[36] = a2_B.BytePack36[0];
  a2_B.TmpSignalConversionAtSerial[37] = a2_B.BytePack36[1];
  a2_B.TmpSignalConversionAtSerial[62] = a2_B.BytePack41[0];
  a2_B.TmpSignalConversionAtSerial[63] = a2_B.BytePack41[1];
  for (i = 0; i < 8; i++) {
    a2_B.TmpSignalConversionAtSerial[i + 9] = a2_B.BytePack30[i];
    a2_B.TmpSignalConversionAtSerial[i + 20] = a2_B.BytePack34[i];
    a2_B.TmpSignalConversionAtSerial[i + 28] = a2_B.BytePack35[i];
    a2_B.TmpSignalConversionAtSerial[i + 38] = a2_B.BytePack37[i];
    a2_B.TmpSignalConversionAtSerial[i + 46] = a2_B.BytePack39[i];
    a2_B.TmpSignalConversionAtSerial[i + 54] = a2_B.BytePack40[i];
    a2_B.TmpSignalConversionAtSerial[i + 64] = a2_B.BytePack42[i];
  }

  /* End of SignalConversion generated from: '<S6>/Serial Transmit' */

  /* MATLABSystem: '<S6>/Serial Transmit' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&a2_B.TxDataLocChar[0], (void *)
           &a2_B.TmpSignalConversionAtSerial[0], (uint32_T)((size_t)72 * sizeof
            (uint8_T)));
    status = MW_SCI_Transmit(a2_DW.obj_j1.MW_SCIHANDLE, &a2_B.TxDataLocChar[0],
      72U);
  }

  /* End of MATLABSystem: '<S6>/Serial Transmit' */
}

/* Termination for Simulink Function: '<S2>/Function Call' */
void DCM_SEND_Term(void)
{
  /* Terminate for MATLABSystem: '<S6>/Serial Transmit' */
  if (!a2_DW.obj_j1.matlabCodegenIsDeleted) {
    a2_DW.obj_j1.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_j1.isInitialized == 1) && a2_DW.obj_j1.isSetupComplete) {
      MW_SCI_Close(a2_DW.obj_j1.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
