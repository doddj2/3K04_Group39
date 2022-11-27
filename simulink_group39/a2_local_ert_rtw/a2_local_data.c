/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a2_local_data.c
 *
 * Code generated for Simulink model 'a2_local'.
 *
 * Model version                  : 1.59
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Nov 27 13:03:16 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "a2_local.h"

/* Block parameters (default storage) */
P_a2_local_T a2_local_P = {
  /* Expression: -1
   * Referenced by: '<S5>/FXOS8700 6-Axes Sensor'
   */
  -1.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S5>/Out1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/Constant'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S6>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S7>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant1'
   */
  0.0,

  /* Expression: SampleTime
   * Referenced by: '<S3>/ATR_CMP_DETECT D0'
   */
  -1.0,

  /* Expression: SampleTime
   * Referenced by: '<S3>/VENT_CMP_DETECT D1'
   */
  -1.0,

  /* Expression: 60
   * Referenced by: '<S1>/ppm'
   */
  60.0,

  /* Expression: 1.5
   * Referenced by: '<S1>/Acceleration threshold'
   */
  1.5,

  /* Expression: 7
   * Referenced by: '<S1>/mode'
   */
  7.0,

  /* Expression: 4
   * Referenced by: '<S6>/Switch'
   */
  4.0,

  /* Expression: 175
   * Referenced by: '<S1>/maximum sensor-driven rate'
   */
  175.0,

  /* Expression: 2000
   * Referenced by: '<S1>/reaction time'
   */
  2000.0,

  /* Expression: 2000
   * Referenced by: '<S1>/recovery time1'
   */
  2000.0,

  /* Expression: 0
   * Referenced by: '<S3>/Memory'
   */
  0.0,

  /* Expression: 130
   * Referenced by: '<S1>/ARP msec'
   */
  130.0,

  /* Expression: 5
   * Referenced by: '<S1>/Atrial Pluse Width msec'
   */
  5.0,

  /* Expression: 120
   * Referenced by: '<S1>/VRP msec'
   */
  120.0,

  /* Expression: 5
   * Referenced by: '<S1>/Ventricular Pluse Width msec'
   */
  5.0,

  /* Expression: 3.2
   * Referenced by: '<S1>/Atrial Amplitude(volt)'
   */
  3.2,

  /* Expression: 5
   * Referenced by: '<S10>/Constant'
   */
  5.0,

  /* Expression: 100
   * Referenced by: '<S10>/Gain'
   */
  100.0,

  /* Expression: 3.5
   * Referenced by: '<S1>/Ventricular Amplitude'
   */
  3.5,

  /* Expression: 5
   * Referenced by: '<S10>/Constant1'
   */
  5.0,

  /* Expression: 100
   * Referenced by: '<S10>/Gain1'
   */
  100.0,

  /* Expression: 60000
   * Referenced by: '<S12>/1min = 60sec = 60000msec2'
   */
  60000.0,

  /* Expression: 60000
   * Referenced by: '<S13>/1min = 60sec = 60000msec2'
   */
  60000.0,

  /* Expression: 2
   * Referenced by: '<S7>/Switch'
   */
  2.0,

  /* Expression: 2.3
   * Referenced by: '<S1>/Atrial threshold(volt)'
   */
  2.3,

  /* Expression: 3.3
   * Referenced by: '<S1>/Voltage'
   */
  3.3,

  /* Expression: 100
   * Referenced by: '<S9>/Gain'
   */
  100.0,

  /* Expression: 2.3
   * Referenced by: '<S1>/Ventricle threshold(volt)'
   */
  2.3,

  /* Expression: 100
   * Referenced by: '<S9>/Gain1'
   */
  100.0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
