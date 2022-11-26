/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DCM_SEND.c
 *
 * Code generated for Simulink model 'a2_changes_nov25'.
 *
 * Model version                  : 1.91
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Nov 26 02:08:26 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "a2_changes_nov25_types.h"
#include "DCM_SEND_private.h"
#include "a2_changes_nov25.h"
#include "DCM_SEND.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>

/* Forward declaration for local functions */
static void a2_changes_nov_SystemCore_setup(freedomk64f_SCIWrite_a2_chang_T *obj);
static void a2_changes_nov_SystemCore_setup(freedomk64f_SCIWrite_a2_chang_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 1;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* System initialize for Simulink Function: '<S1>/Function Call' */
void DCM_SEND_Init(void)
{
  /* Start for MATLABSystem: '<S4>/Serial Transmit' */
  a2_changes_nov25_DW.obj_h.isInitialized = 0;
  a2_changes_nov25_DW.obj_h.matlabCodegenIsDeleted = false;
  a2_changes_nov_SystemCore_setup(&a2_changes_nov25_DW.obj_h);
}

/* Output and update for Simulink Function: '<S1>/Function Call' */
void DCM_SEND(void)
{
  int32_T i;
  uint8_T status;

  /* SignalConversion generated from: '<S4>/In1' */
  a2_changes_nov25_B.lower_rate_limit = a2_changes_nov25_B.lower_rate_limit_p;

  /* SignalConversion generated from: '<S4>/In2' */
  a2_changes_nov25_B.upper_rate_limit = a2_changes_nov25_B.upper_rate_limit_b;

  /* SignalConversion generated from: '<S4>/In3' */
  a2_changes_nov25_B.PVARP = a2_changes_nov25_B.PVARP_l;

  /* SignalConversion generated from: '<S4>/In4' */
  a2_changes_nov25_B.mode = a2_changes_nov25_B.mode_a;

  /* SignalConversion generated from: '<S4>/In5' */
  a2_changes_nov25_B.av_delay = a2_changes_nov25_B.av_delay_i;

  /* SignalConversion generated from: '<S4>/In6' */
  a2_changes_nov25_B.reaction_time = a2_changes_nov25_B.reaction_time_f;

  /* SignalConversion generated from: '<S4>/In7' */
  a2_changes_nov25_B.response_factor = a2_changes_nov25_B.response_factor_d;

  /* SignalConversion generated from: '<S4>/In8' */
  a2_changes_nov25_B.activity_threshold =
    a2_changes_nov25_B.activity_threshold_c;

  /* SignalConversion generated from: '<S4>/In9' */
  a2_changes_nov25_B.recovery_time = a2_changes_nov25_B.recovery_time_l;

  /* SignalConversion generated from: '<S4>/In10' */
  a2_changes_nov25_B.MSR = a2_changes_nov25_B.MSR_e;

  /* SignalConversion generated from: '<S4>/In12' */
  a2_changes_nov25_B.atr_amp = a2_changes_nov25_B.atr_amp_g;

  /* SignalConversion generated from: '<S4>/In13' */
  a2_changes_nov25_B.atr_pulse_width = a2_changes_nov25_B.atr_pulse_width_g;

  /* SignalConversion generated from: '<S4>/In14' */
  a2_changes_nov25_B.ARP = a2_changes_nov25_B.ARP_m;

  /* SignalConversion generated from: '<S4>/In15' */
  a2_changes_nov25_B.atr_threshold = a2_changes_nov25_B.atr_threshold_a;

  /* SignalConversion generated from: '<S4>/In17' */
  a2_changes_nov25_B.vent_amp = a2_changes_nov25_B.vent_amp_h;

  /* SignalConversion generated from: '<S4>/In18' */
  a2_changes_nov25_B.vent_pulse_width = a2_changes_nov25_B.vent_pulse_width_b;

  /* SignalConversion generated from: '<S4>/In19' */
  a2_changes_nov25_B.VRP = a2_changes_nov25_B.VRP_f;

  /* SignalConversion generated from: '<S4>/In20' */
  a2_changes_nov25_B.vent_threshold = a2_changes_nov25_B.vent_threshold_n;

  /* S-Function (any2byte): '<S4>/Byte Pack26' */

  /* Pack: <S4>/Byte Pack26 */
  (void) memcpy(&a2_changes_nov25_B.BytePack26[0], &a2_changes_nov25_B.mode,
                2);

  /* S-Function (any2byte): '<S4>/Byte Pack 1' */

  /* Pack: <S4>/Byte Pack 1 */
  (void) memcpy(&a2_changes_nov25_B.BytePack1[0],
                &a2_changes_nov25_B.lower_rate_limit,
                2);

  /* S-Function (any2byte): '<S4>/Byte Pack 2' */

  /* Pack: <S4>/Byte Pack 2 */
  (void) memcpy(&a2_changes_nov25_B.BytePack2[0],
                &a2_changes_nov25_B.upper_rate_limit,
                2);

  /* S-Function (any2byte): '<S4>/Byte Pack 3' */

  /* Pack: <S4>/Byte Pack 3 */
  (void) memcpy(&a2_changes_nov25_B.BytePack3[0], &a2_changes_nov25_B.PVARP,
                2);

  /* S-Function (any2byte): '<S4>/Byte Pack27' */

  /* Pack: <S4>/Byte Pack27 */
  (void) memcpy(&a2_changes_nov25_B.BytePack27[0], &a2_changes_nov25_B.av_delay,
                2);

  /* S-Function (any2byte): '<S4>/Byte Pack28' */

  /* Pack: <S4>/Byte Pack28 */
  (void) memcpy(&a2_changes_nov25_B.BytePack28[0],
                &a2_changes_nov25_B.reaction_time,
                2);

  /* S-Function (any2byte): '<S4>/Byte Pack29' */

  /* Pack: <S4>/Byte Pack29 */
  (void) memcpy(&a2_changes_nov25_B.BytePack29[0],
                &a2_changes_nov25_B.response_factor,
                2);

  /* S-Function (any2byte): '<S4>/Byte Pack30' */

  /* Pack: <S4>/Byte Pack30 */
  (void) memcpy(&a2_changes_nov25_B.BytePack30[0],
                &a2_changes_nov25_B.activity_threshold,
                8);

  /* S-Function (any2byte): '<S4>/Byte Pack31' */

  /* Pack: <S4>/Byte Pack31 */
  (void) memcpy(&a2_changes_nov25_B.BytePack31[0],
                &a2_changes_nov25_B.recovery_time,
                2);

  /* S-Function (any2byte): '<S4>/Byte Pack32' */

  /* Pack: <S4>/Byte Pack32 */
  (void) memcpy(&a2_changes_nov25_B.BytePack32[0], &a2_changes_nov25_B.MSR,
                2);

  /* S-Function (any2byte): '<S4>/Byte Pack34' */

  /* Pack: <S4>/Byte Pack34 */
  (void) memcpy(&a2_changes_nov25_B.BytePack34[0], &a2_changes_nov25_B.atr_amp,
                8);

  /* S-Function (any2byte): '<S4>/Byte Pack35' */

  /* Pack: <S4>/Byte Pack35 */
  (void) memcpy(&a2_changes_nov25_B.BytePack35[0],
                &a2_changes_nov25_B.atr_pulse_width,
                2);

  /* S-Function (any2byte): '<S4>/Byte Pack36' */

  /* Pack: <S4>/Byte Pack36 */
  (void) memcpy(&a2_changes_nov25_B.BytePack36[0], &a2_changes_nov25_B.ARP,
                2);

  /* S-Function (any2byte): '<S4>/Byte Pack37' */

  /* Pack: <S4>/Byte Pack37 */
  (void) memcpy(&a2_changes_nov25_B.BytePack37[0],
                &a2_changes_nov25_B.atr_threshold,
                8);

  /* S-Function (any2byte): '<S4>/Byte Pack39' */

  /* Pack: <S4>/Byte Pack39 */
  (void) memcpy(&a2_changes_nov25_B.BytePack39[0], &a2_changes_nov25_B.vent_amp,
                8);

  /* S-Function (any2byte): '<S4>/Byte Pack40' */

  /* Pack: <S4>/Byte Pack40 */
  (void) memcpy(&a2_changes_nov25_B.BytePack40[0],
                &a2_changes_nov25_B.vent_pulse_width,
                2);

  /* S-Function (any2byte): '<S4>/Byte Pack41' */

  /* Pack: <S4>/Byte Pack41 */
  (void) memcpy(&a2_changes_nov25_B.BytePack41[0], &a2_changes_nov25_B.VRP,
                2);

  /* S-Function (any2byte): '<S4>/Byte Pack42' */

  /* Pack: <S4>/Byte Pack42 */
  (void) memcpy(&a2_changes_nov25_B.BytePack42[0],
                &a2_changes_nov25_B.vent_threshold,
                8);

  /* SignalConversion generated from: '<S4>/Serial Transmit' */
  a2_changes_nov25_B.TmpSignalConversionAtSerial[0] =
    a2_changes_nov25_B.BytePack26[0];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[2] =
    a2_changes_nov25_B.BytePack1[0];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[4] =
    a2_changes_nov25_B.BytePack2[0];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[6] =
    a2_changes_nov25_B.BytePack3[0];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[8] =
    a2_changes_nov25_B.BytePack27[0];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[10] =
    a2_changes_nov25_B.BytePack28[0];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[12] =
    a2_changes_nov25_B.BytePack29[0];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[1] =
    a2_changes_nov25_B.BytePack26[1];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[3] =
    a2_changes_nov25_B.BytePack1[1];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[5] =
    a2_changes_nov25_B.BytePack2[1];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[7] =
    a2_changes_nov25_B.BytePack3[1];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[9] =
    a2_changes_nov25_B.BytePack27[1];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[11] =
    a2_changes_nov25_B.BytePack28[1];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[13] =
    a2_changes_nov25_B.BytePack29[1];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[22] =
    a2_changes_nov25_B.BytePack31[0];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[24] =
    a2_changes_nov25_B.BytePack32[0];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[23] =
    a2_changes_nov25_B.BytePack31[1];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[25] =
    a2_changes_nov25_B.BytePack32[1];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[34] =
    a2_changes_nov25_B.BytePack35[0];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[36] =
    a2_changes_nov25_B.BytePack36[0];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[35] =
    a2_changes_nov25_B.BytePack35[1];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[37] =
    a2_changes_nov25_B.BytePack36[1];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[54] =
    a2_changes_nov25_B.BytePack40[0];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[56] =
    a2_changes_nov25_B.BytePack41[0];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[55] =
    a2_changes_nov25_B.BytePack40[1];
  a2_changes_nov25_B.TmpSignalConversionAtSerial[57] =
    a2_changes_nov25_B.BytePack41[1];
  for (i = 0; i < 8; i++) {
    a2_changes_nov25_B.TmpSignalConversionAtSerial[i + 14] =
      a2_changes_nov25_B.BytePack30[i];
    a2_changes_nov25_B.TmpSignalConversionAtSerial[i + 26] =
      a2_changes_nov25_B.BytePack34[i];
    a2_changes_nov25_B.TmpSignalConversionAtSerial[i + 38] =
      a2_changes_nov25_B.BytePack37[i];
    a2_changes_nov25_B.TmpSignalConversionAtSerial[i + 46] =
      a2_changes_nov25_B.BytePack39[i];
    a2_changes_nov25_B.TmpSignalConversionAtSerial[i + 58] =
      a2_changes_nov25_B.BytePack42[i];
  }

  /* End of SignalConversion generated from: '<S4>/Serial Transmit' */

  /* MATLABSystem: '<S4>/Serial Transmit' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&a2_changes_nov25_B.TxDataLocChar[0], (void *)
           &a2_changes_nov25_B.TmpSignalConversionAtSerial[0], (uint32_T)
           ((size_t)66 * sizeof(uint8_T)));
    status = MW_SCI_Transmit(a2_changes_nov25_DW.obj_h.MW_SCIHANDLE,
      &a2_changes_nov25_B.TxDataLocChar[0], 66U);
  }

  /* End of MATLABSystem: '<S4>/Serial Transmit' */
}

/* Termination for Simulink Function: '<S1>/Function Call' */
void DCM_SEND_Term(void)
{
  /* Terminate for MATLABSystem: '<S4>/Serial Transmit' */
  if (!a2_changes_nov25_DW.obj_h.matlabCodegenIsDeleted) {
    a2_changes_nov25_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((a2_changes_nov25_DW.obj_h.isInitialized == 1) &&
        a2_changes_nov25_DW.obj_h.isSetupComplete) {
      MW_SCI_Close(a2_changes_nov25_DW.obj_h.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Serial Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
