/*
 * assignment_1_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "assignment_1".
 *
 * Model version              : 1.37
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Mon Nov 14 16:18:54 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(freedomk64f_PWMOutput_assignm_T),
  sizeof(freedomk64f_DigitalWrite_assi_T),
  sizeof(freedomk64f_fxos8700_assignme_T),
  sizeof(dsp_simulink_MovingAverage_as_T),
  sizeof(freedomk64f_DigitalRead_assig_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "freedomk64f_PWMOutput_assignm_T",
  "freedomk64f_DigitalWrite_assi_T",
  "freedomk64f_fxos8700_assignme_T",
  "dsp_simulink_MovingAverage_as_T",
  "freedomk64f_DigitalRead_assig_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&assignment_1_B.Divide2), 0, 0, 12 },

  { (char_T *)(&assignment_1_B.VENT_CMP_DETECTD1), 8, 0, 10 }
  ,

  { (char_T *)(&assignment_1_DW.obj), 18, 0, 1 },

  { (char_T *)(&assignment_1_DW.obj_f), 17, 0, 1 },

  { (char_T *)(&assignment_1_DW.obj_i), 19, 0, 2 },

  { (char_T *)(&assignment_1_DW.obj_k), 15, 0, 3 },

  { (char_T *)(&assignment_1_DW.obj_d), 16, 0, 11 },

  { (char_T *)(&assignment_1_DW.Scope_PWORK.LoggedData), 11, 0, 1 },

  { (char_T *)(&assignment_1_DW.is_c3_assignment_1), 7, 0, 6 },

  { (char_T *)(&assignment_1_DW.is_active_c3_assignment_1), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  10U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&assignment_1_P.Constant_Value), 0, 0, 24 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] assignment_1_dt.h */
