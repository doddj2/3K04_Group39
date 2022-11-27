/*
 * a2_local_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "a2_local".
 *
 * Model version              : 1.59
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Sun Nov 27 13:03:16 2022
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
  sizeof(freedomk64f_DigitalWrite_a2_l_T),
  sizeof(freedomk64f_fxos8700_a2_local_T),
  sizeof(freedomk64f_PWMOutput_a2_loca_T),
  sizeof(freedomk64f_DigitalRead_a2_lo_T),
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
  "freedomk64f_DigitalWrite_a2_l_T",
  "freedomk64f_fxos8700_a2_local_T",
  "freedomk64f_PWMOutput_a2_loca_T",
  "freedomk64f_DigitalRead_a2_lo_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&a2_local_B.mode), 0, 0, 15 },

  { (char_T *)(&a2_local_B.RelationalOperator), 8, 0, 11 }
  ,

  { (char_T *)(&a2_local_DW.obj), 16, 0, 1 },

  { (char_T *)(&a2_local_DW.obj_i), 18, 0, 2 },

  { (char_T *)(&a2_local_DW.obj_m), 15, 0, 11 },

  { (char_T *)(&a2_local_DW.obj_ki), 17, 0, 3 },

  { (char_T *)(&a2_local_DW.Memory_PreviousInput), 0, 0, 1 },

  { (char_T *)(&a2_local_DW.sensorresponserate_PWORK.LoggedData), 11, 0, 7 },

  { (char_T *)(&a2_local_DW.is_c3_a2_local), 7, 0, 10 },

  { (char_T *)(&a2_local_DW.calculateacceleration3D_SubsysR), 2, 0, 1 },

  { (char_T *)(&a2_local_DW.is_active_c3_a2_local), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  11U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&a2_local_P.FXOS87006AxesSensor_SampleTime), 0, 0, 35 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] a2_local_dt.h */
