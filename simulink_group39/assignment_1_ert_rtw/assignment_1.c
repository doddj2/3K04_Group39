/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: assignment_1.c
 *
 * Code generated for Simulink model 'assignment_1'.
 *
 * Model version                  : 1.37
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Nov 14 16:18:54 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "assignment_1.h"
#include "assignment_1_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include <stddef.h>
#include "MW_I2C.h"
#include "assignment_1_private.h"
#include "assignment_1_dt.h"

/* Named constants for Chart: '<S4>/4 Modes' */
#define assignment_1_HIGH              (true)
#define assignment_1_IN_AAI            (1U)
#define assignment_1_IN_AOO            (2U)
#define assignment_1_IN_ARP_Period     (1U)
#define assignment_1_IN_Alert_Period   (1U)
#define assignment_1_IN_Alert_Period_g (2U)
#define assignment_1_IN_Charging       (1U)
#define assignment_1_IN_Charging1      (2U)
#define assignment_1_IN_Charging_c     (3U)
#define assignment_1_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define assignment_1_IN_Pacing         (2U)
#define assignment_1_IN_Pacing_m       (3U)
#define assignment_1_IN_Pacing_m4      (4U)
#define assignment_1_IN_Start          (3U)
#define assignment_1_IN_VOO            (4U)
#define assignment_1_IN_VRP_Period     (4U)
#define assignment_1_IN_VVI            (5U)
#define assignment_1_LOW               (false)

/* Block signals (default storage) */
B_assignment_1_T assignment_1_B;

/* Block states (default storage) */
DW_assignment_1_T assignment_1_DW;

/* Real-time model */
static RT_MODEL_assignment_1_T assignment_1_M_;
RT_MODEL_assignment_1_T *const assignment_1_M = &assignment_1_M_;

/* Forward declaration for local functions */
static int16_T assignment_1_bitshift_anonFcn1(int16_T a1, real_T k1);
static void assign_enter_atomic_Charging_gp(void);
static void assignmen_enter_atomic_Charging(void);
static void assignment_1_SystemCore_setup(freedomk64f_fxos8700_assignme_T *obj);
static int16_T assignment_1_bitshift_anonFcn1(int16_T a1, real_T k1)
{
  int16_T varargout_1;
  if (k1 >= 0.0) {
    if (k1 <= 15.0) {
      varargout_1 = (int16_T)(a1 << (uint8_T)k1);
    } else {
      varargout_1 = 0;
    }
  } else if (k1 >= -15.0) {
    varargout_1 = (int16_T)(a1 >> (uint8_T)-k1);
  } else if (a1 < 0) {
    varargout_1 = -1;
  } else {
    varargout_1 = 0;
  }

  return varargout_1;
}

/* Function for Chart: '<S4>/4 Modes' */
static void assign_enter_atomic_Charging_gp(void)
{
  assignment_1_B.PACING_REF_PWM = assignment_1_B.Gain1;
  assignment_1_B.PACE_CHARGE_CTRL = assignment_1_HIGH;
  assignment_1_B.PACE_GND_CTRL = assignment_1_HIGH;
  assignment_1_B.VENT_PACE_CTRL = assignment_1_LOW;
  assignment_1_B.Z_ATR_CTRL = assignment_1_LOW;
  assignment_1_B.Z_VENT_CTRL = assignment_1_LOW;
  assignment_1_B.ATR_PACE_CTRL = assignment_1_LOW;
  assignment_1_B.ATR_GND_CTRL = assignment_1_LOW;
  assignment_1_B.VENT_GND_CTRL = assignment_1_HIGH;
}

/* Function for Chart: '<S4>/4 Modes' */
static void assignmen_enter_atomic_Charging(void)
{
  assignment_1_B.PACING_REF_PWM = assignment_1_B.Gain;
  assignment_1_B.PACE_CHARGE_CTRL = assignment_1_HIGH;
  assignment_1_B.PACE_GND_CTRL = assignment_1_HIGH;
  assignment_1_B.VENT_PACE_CTRL = assignment_1_LOW;
  assignment_1_B.Z_ATR_CTRL = assignment_1_LOW;
  assignment_1_B.Z_VENT_CTRL = assignment_1_LOW;
  assignment_1_B.ATR_PACE_CTRL = assignment_1_LOW;
  assignment_1_B.ATR_GND_CTRL = assignment_1_HIGH;
  assignment_1_B.VENT_GND_CTRL = assignment_1_LOW;
}

static void assignment_1_SystemCore_setup(freedomk64f_fxos8700_assignme_T *obj)
{
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  uint8_T b_SwappedDataBytes[2];
  uint8_T b_RegisterValue;
  uint8_T status;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  ModeType = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  b_SwappedDataBytes[0] = 43U;
  b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  OSA_TimeDelay(500U);
  status = 42U;
  status = MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &status, 1U, true,
    false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U, &status, 1U, false, true);
    memcpy((void *)&b_RegisterValue, (void *)&status, (uint32_T)((size_t)1 *
            sizeof(uint8_T)));
  } else {
    b_RegisterValue = 0U;
  }

  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = (uint8_T)(b_RegisterValue & 254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  b_SwappedDataBytes[0] = 14U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  b_SwappedDataBytes[0] = 91U;
  b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  obj->isSetupComplete = true;
}

/* Model step function */
void assignment_1_step(void)
{
  g_dsp_internal_SlidingWindowA_T *obj;
  real_T csum_tmp;
  real_T csum_tmp_0;
  real_T csum_tmp_1;
  int32_T b_k;
  int32_T csumrev_tmp;
  int32_T k;
  int16_T b_RegisterValue[3];
  uint8_T output_raw[6];
  uint8_T b_x[2];
  uint8_T y[2];
  uint8_T status;

  /* MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */
  if (assignment_1_DW.obj_f.SampleTime !=
      assignment_1_P.FXOS87006AxesSensor_SampleTime) {
    assignment_1_DW.obj_f.SampleTime =
      assignment_1_P.FXOS87006AxesSensor_SampleTime;
  }

  status = 1U;
  status = MW_I2C_MasterWrite(assignment_1_DW.obj_f.i2cobj.MW_I2C_HANDLE, 29U,
    &status, 1U, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(assignment_1_DW.obj_f.i2cobj.MW_I2C_HANDLE, 29U,
                      &output_raw[0], 6U, false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (uint32_T)
           ((size_t)3 * sizeof(int16_T)));
    memcpy((void *)&y[0], (void *)&b_RegisterValue[0], (uint32_T)((size_t)2 *
            sizeof(uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_RegisterValue[0], (void *)&b_x[0], (uint32_T)((size_t)1 *
            sizeof(int16_T)));
    memcpy((void *)&y[0], (void *)&b_RegisterValue[1], (uint32_T)((size_t)2 *
            sizeof(uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_RegisterValue[1], (void *)&b_x[0], (uint32_T)((size_t)1 *
            sizeof(int16_T)));
    memcpy((void *)&y[0], (void *)&b_RegisterValue[2], (uint32_T)((size_t)2 *
            sizeof(uint8_T)));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_RegisterValue[2], (void *)&b_x[0], (uint32_T)((size_t)1 *
            sizeof(int16_T)));
  } else {
    b_RegisterValue[0] = 0;
    b_RegisterValue[1] = 0;
    b_RegisterValue[2] = 0;
  }

  assignment_1_B.rtb_FXOS87006AxesSensor_idx_0 = (real_T)
    assignment_1_bitshift_anonFcn1(b_RegisterValue[0], -2.0) * 2.0 * 0.244 /
    1000.0;
  assignment_1_B.rtb_FXOS87006AxesSensor_idx_1 = (real_T)
    assignment_1_bitshift_anonFcn1(b_RegisterValue[1], -2.0) * 2.0 * 0.244 /
    1000.0;
  assignment_1_B.rtb_FXOS87006AxesSensor_idx_2 = (real_T)
    assignment_1_bitshift_anonFcn1(b_RegisterValue[2], -2.0) * 2.0 * 0.244 /
    1000.0;

  /* End of MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */

  /* MATLABSystem: '<S3>/Moving Average' incorporates:
   *  MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor'
   */
  if (assignment_1_DW.obj.TunablePropsChanged) {
    assignment_1_DW.obj.TunablePropsChanged = false;
  }

  obj = assignment_1_DW.obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum[0] = 0.0;
    obj->pCumSum[1] = 0.0;
    obj->pCumSum[2] = 0.0;
    for (b_k = 0; b_k < 102; b_k++) {
      obj->pCumSumRev[b_k] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum[0] = 0.0;
    obj->pCumSum[1] = 0.0;
    obj->pCumSum[2] = 0.0;
    for (b_k = 0; b_k < 102; b_k++) {
      obj->pCumSumRev[b_k] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  assignment_1_B.cumRevIndex = obj->pCumRevIndex;
  assignment_1_B.csum[0] = obj->pCumSum[0];
  assignment_1_B.csum[1] = obj->pCumSum[1];
  assignment_1_B.csum[2] = obj->pCumSum[2];
  for (b_k = 0; b_k < 102; b_k++) {
    assignment_1_B.csumrev[b_k] = obj->pCumSumRev[b_k];
  }

  assignment_1_B.modValueRev = obj->pModValueRev;
  assignment_1_B.z_idx_0 = 0.0;
  assignment_1_B.MovingAverage[0] = 0.0;
  csum_tmp = assignment_1_B.csum[0] +
    assignment_1_B.rtb_FXOS87006AxesSensor_idx_0;
  assignment_1_B.csum[0] = csum_tmp;
  assignment_1_B.z_idx_1 = 0.0;
  assignment_1_B.MovingAverage[1] = 0.0;
  csum_tmp_0 = assignment_1_B.csum[1] +
    assignment_1_B.rtb_FXOS87006AxesSensor_idx_1;
  assignment_1_B.csum[1] = csum_tmp_0;
  assignment_1_B.z_idx_2 = 0.0;
  assignment_1_B.MovingAverage[2] = 0.0;
  csum_tmp_1 = assignment_1_B.csum[2] +
    assignment_1_B.rtb_FXOS87006AxesSensor_idx_2;
  assignment_1_B.csum[2] = csum_tmp_1;
  if (assignment_1_B.modValueRev == 0.0) {
    assignment_1_B.z_idx_0 = assignment_1_B.csumrev[(int32_T)
      assignment_1_B.cumRevIndex - 1] + csum_tmp;
    assignment_1_B.z_idx_1 = assignment_1_B.csumrev[(int32_T)
      assignment_1_B.cumRevIndex + 33] + csum_tmp_0;
    assignment_1_B.z_idx_2 = assignment_1_B.csumrev[(int32_T)
      assignment_1_B.cumRevIndex + 67] + csum_tmp_1;
  }

  assignment_1_B.csumrev[(int32_T)assignment_1_B.cumRevIndex - 1] =
    assignment_1_B.rtb_FXOS87006AxesSensor_idx_0;
  assignment_1_B.csumrev[(int32_T)assignment_1_B.cumRevIndex + 33] =
    assignment_1_B.rtb_FXOS87006AxesSensor_idx_1;
  assignment_1_B.csumrev[(int32_T)assignment_1_B.cumRevIndex + 67] =
    assignment_1_B.rtb_FXOS87006AxesSensor_idx_2;
  if (assignment_1_B.cumRevIndex != 34.0) {
    assignment_1_B.cumRevIndex++;
  } else {
    assignment_1_B.cumRevIndex = 1.0;
    for (b_k = 0; b_k < 3; b_k++) {
      assignment_1_B.csum[b_k] = 0.0;
      for (k = 32; k >= 0; k--) {
        csumrev_tmp = b_k * 34 + k;
        assignment_1_B.csumrev[csumrev_tmp] +=
          assignment_1_B.csumrev[csumrev_tmp + 1];
      }
    }
  }

  if (assignment_1_B.modValueRev == 0.0) {
    assignment_1_B.MovingAverage[0] = assignment_1_B.z_idx_0 / 35.0;
    assignment_1_B.MovingAverage[1] = assignment_1_B.z_idx_1 / 35.0;
    assignment_1_B.MovingAverage[2] = assignment_1_B.z_idx_2 / 35.0;
  }

  obj->pCumSum[0] = assignment_1_B.csum[0];
  obj->pCumSum[1] = assignment_1_B.csum[1];
  obj->pCumSum[2] = assignment_1_B.csum[2];
  for (b_k = 0; b_k < 102; b_k++) {
    obj->pCumSumRev[b_k] = assignment_1_B.csumrev[b_k];
  }

  obj->pCumRevIndex = assignment_1_B.cumRevIndex;
  if (assignment_1_B.modValueRev > 0.0) {
    obj->pModValueRev = assignment_1_B.modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }

  /* End of MATLABSystem: '<S3>/Moving Average' */
  /* Product: '<S9>/Divide2' incorporates:
   *  Constant: '<S1>/ppm'
   *  Constant: '<S9>/1min = 60sec = 60000msec2'
   */
  assignment_1_B.Divide2 = assignment_1_P.umin60sec60000msec2_Value /
    assignment_1_P.ppm_Value;

  /* Constant: '<S1>/ARP msec' */
  assignment_1_B.ARPmsec = assignment_1_P.ARPmsec_Value;

  /* Constant: '<S1>/Atrial Pluse Width msec' */
  assignment_1_B.AtrialPluseWidthmsec =
    assignment_1_P.AtrialPluseWidthmsec_Value;

  /* Constant: '<S1>/mode' */
  assignment_1_B.mode = assignment_1_P.mode_Value;

  /* Constant: '<S1>/VRP msec' */
  assignment_1_B.VRPmsec = assignment_1_P.VRPmsec_Value;

  /* Constant: '<S1>/Ventricular Pluse Width msec' */
  assignment_1_B.VentricularPluseWidthmsec =
    assignment_1_P.VentricularPluseWidthmsec_Value;

  /* Gain: '<S8>/Gain' incorporates:
   *  Constant: '<S1>/Atrial Amplitude(volt)'
   *  Constant: '<S8>/Constant'
   *  Product: '<S8>/duty cycle calculation2'
   */
  assignment_1_B.Gain = assignment_1_P.AtrialAmplitudevolt_Value /
    assignment_1_P.Constant_Value_b * assignment_1_P.Gain_Gain;

  /* Gain: '<S8>/Gain1' incorporates:
   *  Constant: '<S1>/Ventricular Amplitude'
   *  Constant: '<S8>/Constant1'
   *  Product: '<S8>/duty cycle calculation1'
   */
  assignment_1_B.Gain1 = assignment_1_P.VentricularAmplitude_Value /
    assignment_1_P.Constant1_Value_d * assignment_1_P.Gain1_Gain;

  /* MATLABSystem: '<S4>/ATR_CMP_DETECT D0' */
  if (assignment_1_DW.obj_f0.SampleTime !=
      assignment_1_P.ATR_CMP_DETECTD0_SampleTime) {
    assignment_1_DW.obj_f0.SampleTime =
      assignment_1_P.ATR_CMP_DETECTD0_SampleTime;
  }

  /* MATLABSystem: '<S4>/ATR_CMP_DETECT D0' */
  assignment_1_B.ATR_CMP_DETECTD0 = MW_digitalIO_read
    (assignment_1_DW.obj_f0.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S4>/VENT_CMP_DETECT D1' */
  if (assignment_1_DW.obj_i.SampleTime !=
      assignment_1_P.VENT_CMP_DETECTD1_SampleTime) {
    assignment_1_DW.obj_i.SampleTime =
      assignment_1_P.VENT_CMP_DETECTD1_SampleTime;
  }

  /* MATLABSystem: '<S4>/VENT_CMP_DETECT D1' */
  assignment_1_B.VENT_CMP_DETECTD1 = MW_digitalIO_read
    (assignment_1_DW.obj_i.MW_DIGITALIO_HANDLE);

  /* Chart: '<S4>/4 Modes' */
  if (assignment_1_DW.temporalCounter_i1 < MAX_uint32_T) {
    assignment_1_DW.temporalCounter_i1++;
  }

  if (assignment_1_DW.is_active_c3_assignment_1 == 0U) {
    assignment_1_DW.is_active_c3_assignment_1 = 1U;
    assignment_1_DW.is_c3_assignment_1 = assignment_1_IN_Start;
  } else {
    switch (assignment_1_DW.is_c3_assignment_1) {
     case assignment_1_IN_AAI:
      switch (assignment_1_DW.is_AAI) {
       case assignment_1_IN_ARP_Period:
        if (assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil
            (assignment_1_B.ARPmsec)) {
          assignment_1_DW.is_AAI = assignment_1_IN_Alert_Period_g;
          assignment_1_DW.temporalCounter_i1 = 0U;
        }
        break;

       case assignment_1_IN_Alert_Period_g:
        if (assignment_1_B.ATR_CMP_DETECTD0) {
          assignment_1_DW.is_AAI = assignment_1_IN_ARP_Period;
          assignment_1_DW.temporalCounter_i1 = 0U;
        } else if (assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil
                   (assignment_1_B.Divide2 - assignment_1_B.ARPmsec)) {
          assignment_1_DW.is_AAI = assignment_1_IN_Pacing_m4;
          assignment_1_DW.temporalCounter_i1 = 0U;
          assignment_1_B.PACE_CHARGE_CTRL = assignment_1_LOW;
          assignment_1_B.PACE_GND_CTRL = assignment_1_HIGH;
          assignment_1_B.ATR_PACE_CTRL = assignment_1_HIGH;
          assignment_1_B.ATR_GND_CTRL = assignment_1_LOW;
          assignment_1_B.Z_ATR_CTRL = assignment_1_LOW;
          assignment_1_B.Z_VENT_CTRL = assignment_1_LOW;
          assignment_1_B.VENT_GND_CTRL = assignment_1_LOW;
          assignment_1_B.VENT_PACE_CTRL = assignment_1_LOW;
        }
        break;

       case assignment_1_IN_Charging_c:
        assignment_1_B.PACE_CHARGE_CTRL = assignment_1_HIGH;
        assignment_1_B.PACE_GND_CTRL = assignment_1_HIGH;
        assignment_1_B.Z_ATR_CTRL = assignment_1_LOW;
        assignment_1_B.Z_VENT_CTRL = assignment_1_LOW;
        assignment_1_B.ATR_GND_CTRL = assignment_1_HIGH;
        assignment_1_B.VENT_GND_CTRL = assignment_1_LOW;
        if (assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil
            (assignment_1_B.ARPmsec)) {
          assignment_1_DW.is_AAI = assignment_1_IN_Alert_Period_g;
          assignment_1_DW.temporalCounter_i1 = 0U;
        } else if (assignment_1_B.mode != 3.0) {
          assignment_1_DW.is_AAI = assignment_1_IN_NO_ACTIVE_CHILD;
          assignment_1_DW.is_c3_assignment_1 = assignment_1_IN_Start;
        }
        break;

       default:
        /* case IN_Pacing: */
        assignment_1_B.PACE_CHARGE_CTRL = assignment_1_LOW;
        assignment_1_B.PACE_GND_CTRL = assignment_1_HIGH;
        assignment_1_B.ATR_GND_CTRL = assignment_1_LOW;
        assignment_1_B.Z_ATR_CTRL = assignment_1_LOW;
        assignment_1_B.Z_VENT_CTRL = assignment_1_LOW;
        assignment_1_B.VENT_GND_CTRL = assignment_1_LOW;
        if (assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil
            (assignment_1_B.AtrialPluseWidthmsec)) {
          assignment_1_DW.is_AAI = assignment_1_IN_Charging_c;
          assignment_1_DW.temporalCounter_i1 = 0U;
          assignmen_enter_atomic_Charging();
        }
        break;
      }
      break;

     case assignment_1_IN_AOO:
      if (assignment_1_DW.is_AOO == assignment_1_IN_Charging) {
        assignment_1_B.PACE_CHARGE_CTRL = assignment_1_HIGH;
        assignment_1_B.PACE_GND_CTRL = assignment_1_HIGH;
        assignment_1_B.Z_ATR_CTRL = assignment_1_LOW;
        assignment_1_B.Z_VENT_CTRL = assignment_1_LOW;
        assignment_1_B.ATR_GND_CTRL = assignment_1_HIGH;
        assignment_1_B.VENT_GND_CTRL = assignment_1_LOW;
        if (assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil
            (assignment_1_B.Divide2 - assignment_1_B.AtrialPluseWidthmsec)) {
          assignment_1_DW.is_AOO = assignment_1_IN_Pacing;
          assignment_1_DW.temporalCounter_i1 = 0U;
          assignment_1_B.PACE_CHARGE_CTRL = assignment_1_LOW;
          assignment_1_B.ATR_PACE_CTRL = assignment_1_HIGH;
          assignment_1_B.ATR_GND_CTRL = assignment_1_LOW;
          assignment_1_B.VENT_PACE_CTRL = assignment_1_LOW;
        } else if (assignment_1_B.mode != 1.0) {
          assignment_1_DW.is_AOO = assignment_1_IN_NO_ACTIVE_CHILD;
          assignment_1_DW.is_c3_assignment_1 = assignment_1_IN_Start;
        }
      } else {
        /* case IN_Pacing: */
        assignment_1_B.PACE_CHARGE_CTRL = assignment_1_LOW;
        assignment_1_B.PACE_GND_CTRL = assignment_1_HIGH;
        assignment_1_B.ATR_GND_CTRL = assignment_1_LOW;
        assignment_1_B.Z_ATR_CTRL = assignment_1_LOW;
        assignment_1_B.Z_VENT_CTRL = assignment_1_LOW;
        assignment_1_B.VENT_GND_CTRL = assignment_1_LOW;
        if (assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil
            (assignment_1_B.AtrialPluseWidthmsec)) {
          assignment_1_DW.is_AOO = assignment_1_IN_Charging;
          assignment_1_DW.temporalCounter_i1 = 0U;
          assignmen_enter_atomic_Charging();
        }
      }
      break;

     case assignment_1_IN_Start:
      if (assignment_1_B.mode == 0.0) {
        assignment_1_DW.is_c3_assignment_1 = assignment_1_IN_VOO;
        assignment_1_DW.is_VOO = assignment_1_IN_Charging;
        assignment_1_DW.temporalCounter_i1 = 0U;
        assign_enter_atomic_Charging_gp();
      } else if (assignment_1_B.mode == 1.0) {
        assignment_1_DW.is_c3_assignment_1 = assignment_1_IN_AOO;
        assignment_1_DW.is_AOO = assignment_1_IN_Charging;
        assignment_1_DW.temporalCounter_i1 = 0U;
        assignmen_enter_atomic_Charging();
      } else if (assignment_1_B.mode == 2.0) {
        assignment_1_DW.is_c3_assignment_1 = assignment_1_IN_VVI;
        assignment_1_DW.is_VVI = assignment_1_IN_Charging1;
        assignment_1_DW.temporalCounter_i1 = 0U;
        assign_enter_atomic_Charging_gp();
      } else if (assignment_1_B.mode == 3.0) {
        assignment_1_DW.is_c3_assignment_1 = assignment_1_IN_AAI;
        assignment_1_DW.is_AAI = assignment_1_IN_Charging_c;
        assignment_1_DW.temporalCounter_i1 = 0U;
        assignmen_enter_atomic_Charging();
      }
      break;

     case assignment_1_IN_VOO:
      if (assignment_1_DW.is_VOO == assignment_1_IN_Charging) {
        assignment_1_B.PACE_CHARGE_CTRL = assignment_1_HIGH;
        assignment_1_B.PACE_GND_CTRL = assignment_1_HIGH;
        assignment_1_B.Z_ATR_CTRL = assignment_1_LOW;
        assignment_1_B.Z_VENT_CTRL = assignment_1_LOW;
        assignment_1_B.ATR_GND_CTRL = assignment_1_LOW;
        assignment_1_B.VENT_GND_CTRL = assignment_1_HIGH;
        if (assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil
            (assignment_1_B.Divide2 - assignment_1_B.VentricularPluseWidthmsec))
        {
          assignment_1_DW.is_VOO = assignment_1_IN_Pacing;
          assignment_1_DW.temporalCounter_i1 = 0U;
          assignment_1_B.PACE_CHARGE_CTRL = assignment_1_LOW;
          assignment_1_B.ATR_PACE_CTRL = assignment_1_LOW;
          assignment_1_B.VENT_GND_CTRL = assignment_1_LOW;
          assignment_1_B.VENT_PACE_CTRL = assignment_1_HIGH;
        } else if (assignment_1_B.mode != 0.0) {
          assignment_1_DW.is_VOO = assignment_1_IN_NO_ACTIVE_CHILD;
          assignment_1_DW.is_c3_assignment_1 = assignment_1_IN_Start;
        }
      } else {
        /* case IN_Pacing: */
        assignment_1_B.PACE_CHARGE_CTRL = assignment_1_LOW;
        assignment_1_B.PACE_GND_CTRL = assignment_1_HIGH;
        assignment_1_B.ATR_GND_CTRL = assignment_1_LOW;
        assignment_1_B.Z_ATR_CTRL = assignment_1_LOW;
        assignment_1_B.Z_VENT_CTRL = assignment_1_LOW;
        assignment_1_B.VENT_GND_CTRL = assignment_1_LOW;
        if (assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil
            (assignment_1_B.VentricularPluseWidthmsec)) {
          assignment_1_DW.is_VOO = assignment_1_IN_Charging;
          assignment_1_DW.temporalCounter_i1 = 0U;
          assign_enter_atomic_Charging_gp();
        }
      }
      break;

     default:
      /* case IN_VVI: */
      switch (assignment_1_DW.is_VVI) {
       case assignment_1_IN_Alert_Period:
        if (assignment_1_B.VENT_CMP_DETECTD1) {
          assignment_1_DW.is_VVI = assignment_1_IN_VRP_Period;
          assignment_1_DW.temporalCounter_i1 = 0U;
        } else if (assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil
                   (assignment_1_B.Divide2 - assignment_1_B.VRPmsec)) {
          assignment_1_DW.is_VVI = assignment_1_IN_Pacing_m;
          assignment_1_DW.temporalCounter_i1 = 0U;
          assignment_1_B.PACE_CHARGE_CTRL = assignment_1_LOW;
          assignment_1_B.PACE_GND_CTRL = assignment_1_HIGH;
          assignment_1_B.ATR_PACE_CTRL = assignment_1_LOW;
          assignment_1_B.ATR_GND_CTRL = assignment_1_LOW;
          assignment_1_B.Z_ATR_CTRL = assignment_1_LOW;
          assignment_1_B.Z_VENT_CTRL = assignment_1_LOW;
          assignment_1_B.VENT_GND_CTRL = assignment_1_LOW;
          assignment_1_B.VENT_PACE_CTRL = assignment_1_HIGH;
        }
        break;

       case assignment_1_IN_Charging1:
        assignment_1_B.PACE_CHARGE_CTRL = assignment_1_HIGH;
        assignment_1_B.PACE_GND_CTRL = assignment_1_HIGH;
        assignment_1_B.Z_ATR_CTRL = assignment_1_LOW;
        assignment_1_B.Z_VENT_CTRL = assignment_1_LOW;
        assignment_1_B.ATR_GND_CTRL = assignment_1_LOW;
        assignment_1_B.VENT_GND_CTRL = assignment_1_HIGH;
        if (assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil
            (assignment_1_B.VRPmsec)) {
          assignment_1_DW.is_VVI = assignment_1_IN_Alert_Period;
          assignment_1_DW.temporalCounter_i1 = 0U;
        } else if (assignment_1_B.mode != 2.0) {
          assignment_1_DW.is_VVI = assignment_1_IN_NO_ACTIVE_CHILD;
          assignment_1_DW.is_c3_assignment_1 = assignment_1_IN_Start;
        }
        break;

       case assignment_1_IN_Pacing_m:
        assignment_1_B.PACE_CHARGE_CTRL = assignment_1_LOW;
        assignment_1_B.PACE_GND_CTRL = assignment_1_HIGH;
        assignment_1_B.ATR_GND_CTRL = assignment_1_LOW;
        assignment_1_B.Z_ATR_CTRL = assignment_1_LOW;
        assignment_1_B.Z_VENT_CTRL = assignment_1_LOW;
        assignment_1_B.VENT_GND_CTRL = assignment_1_LOW;
        if (assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil
            (assignment_1_B.VentricularPluseWidthmsec)) {
          assignment_1_DW.is_VVI = assignment_1_IN_Charging1;
          assignment_1_DW.temporalCounter_i1 = 0U;
          assign_enter_atomic_Charging_gp();
        }
        break;

       default:
        /* case IN_VRP_Period: */
        if (assignment_1_DW.temporalCounter_i1 >= (uint32_T)ceil
            (assignment_1_B.VRPmsec)) {
          assignment_1_DW.is_VVI = assignment_1_IN_Alert_Period;
          assignment_1_DW.temporalCounter_i1 = 0U;
        }
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S4>/4 Modes' */

  /* MATLABSystem: '<S2>/ATR_GND_CTRL D11' */
  MW_digitalIO_write(assignment_1_DW.obj_o.MW_DIGITALIO_HANDLE,
                     assignment_1_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S2>/ATR_PACE_CTRL D8' */
  MW_digitalIO_write(assignment_1_DW.obj_pu.MW_DIGITALIO_HANDLE,
                     assignment_1_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S2>/PACING_REF_PWM D5' */
  MW_PWM_SetDutyCycle(assignment_1_DW.obj_p.MW_PWM_HANDLE,
                      assignment_1_B.PACING_REF_PWM);

  /* MATLABSystem: '<S2>/Z_VENT_CTRL D7' */
  MW_digitalIO_write(assignment_1_DW.obj_m.MW_DIGITALIO_HANDLE,
                     assignment_1_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S2>/VENT_PACE_CTRL D9  ' */
  MW_digitalIO_write(assignment_1_DW.obj_ko.MW_DIGITALIO_HANDLE,
                     assignment_1_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S2>/PACE_GND_CTRL D10' */
  MW_digitalIO_write(assignment_1_DW.obj_df.MW_DIGITALIO_HANDLE,
                     assignment_1_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S2>/VENT_GND_CTRL D12' */
  MW_digitalIO_write(assignment_1_DW.obj_e.MW_DIGITALIO_HANDLE,
                     assignment_1_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S2>/Z_ATR_CTRL D4' */
  MW_digitalIO_write(assignment_1_DW.obj_mn.MW_DIGITALIO_HANDLE,
                     assignment_1_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S2>/PACE_CHARGE_CTRL D2' */
  MW_digitalIO_write(assignment_1_DW.obj_h.MW_DIGITALIO_HANDLE,
                     assignment_1_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write1' */
  MW_digitalIO_write(assignment_1_DW.obj_d.MW_DIGITALIO_HANDLE,
                     assignment_1_B.VENT_CMP_DETECTD1);

  /* MATLABSystem: '<S4>/Digital Write' */
  MW_digitalIO_write(assignment_1_DW.obj_i4.MW_DIGITALIO_HANDLE,
                     assignment_1_B.ATR_CMP_DETECTD0);

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   */
  if (assignment_1_B.mode >= assignment_1_P.Switch_Threshold) {
    assignment_1_B.rtb_FXOS87006AxesSensor_idx_0 = assignment_1_P.Constant_Value;
  } else {
    assignment_1_B.rtb_FXOS87006AxesSensor_idx_0 =
      assignment_1_P.Constant1_Value;
  }

  /* End of Switch: '<S5>/Switch' */

  /* MATLABSystem: '<S2>/FRONTEND_CTRL D13' */
  MW_digitalIO_write(assignment_1_DW.obj_a.MW_DIGITALIO_HANDLE,
                     assignment_1_B.rtb_FXOS87006AxesSensor_idx_0 != 0.0);

  /* MATLABSystem: '<S2>/ATR_CMP_REF_PWM D6' incorporates:
   *  Constant: '<S1>/Atrial threshold(volt)'
   *  Constant: '<S1>/Voltage'
   *  Gain: '<S7>/Gain'
   *  Product: '<S7>/Divide'
   */
  MW_PWM_SetDutyCycle(assignment_1_DW.obj_g.MW_PWM_HANDLE,
                      assignment_1_P.Gain_Gain_n *
                      (assignment_1_P.Atrialthresholdvolt_Value /
                       assignment_1_P.Voltage_Value));

  /* MATLABSystem: '<S2>/VENT_CMP_REF_PWM D3' incorporates:
   *  Constant: '<S1>/Ventricle threshold(volt)'
   *  Constant: '<S1>/Voltage'
   *  Gain: '<S7>/Gain1'
   *  Product: '<S7>/Divide1'
   */
  MW_PWM_SetDutyCycle(assignment_1_DW.obj_k.MW_PWM_HANDLE,
                      assignment_1_P.Gain1_Gain_p *
                      (assignment_1_P.Ventriclethresholdvolt_Value /
                       assignment_1_P.Voltage_Value));

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)assignment_1_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(assignment_1_M)!=-1) &&
        !((rtmGetTFinal(assignment_1_M)-assignment_1_M->Timing.taskTime0) >
          assignment_1_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(assignment_1_M, "Simulation finished");
    }

    if (rtmGetStopRequested(assignment_1_M)) {
      rtmSetErrorStatus(assignment_1_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  assignment_1_M->Timing.taskTime0 =
    ((time_T)(++assignment_1_M->Timing.clockTick0)) *
    assignment_1_M->Timing.stepSize0;
}

/* Model initialize function */
void assignment_1_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(assignment_1_M, -1);
  assignment_1_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  assignment_1_M->Sizes.checksums[0] = (112361251U);
  assignment_1_M->Sizes.checksums[1] = (3456612692U);
  assignment_1_M->Sizes.checksums[2] = (2888552710U);
  assignment_1_M->Sizes.checksums[3] = (666746467U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[22];
    assignment_1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(assignment_1_M->extModeInfo,
      &assignment_1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(assignment_1_M->extModeInfo,
                        assignment_1_M->Sizes.checksums);
    rteiSetTPtr(assignment_1_M->extModeInfo, rtmGetTPtr(assignment_1_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    assignment_1_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    freedomk64f_DigitalRead_assig_T *obj;
    freedomk64f_DigitalWrite_assi_T *obj_0;
    freedomk64f_PWMOutput_assignm_T *obj_1;
    g_dsp_internal_SlidingWindowA_T *iobj_0;
    int32_T i;

    /* Start for Constant: '<S1>/ARP msec' */
    assignment_1_B.ARPmsec = assignment_1_P.ARPmsec_Value;

    /* Start for Constant: '<S1>/Atrial Pluse Width msec' */
    assignment_1_B.AtrialPluseWidthmsec =
      assignment_1_P.AtrialPluseWidthmsec_Value;

    /* Start for Constant: '<S1>/mode' */
    assignment_1_B.mode = assignment_1_P.mode_Value;

    /* Start for Constant: '<S1>/VRP msec' */
    assignment_1_B.VRPmsec = assignment_1_P.VRPmsec_Value;

    /* Start for Constant: '<S1>/Ventricular Pluse Width msec' */
    assignment_1_B.VentricularPluseWidthmsec =
      assignment_1_P.VentricularPluseWidthmsec_Value;

    /* Start for MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */
    assignment_1_DW.obj_f.isInitialized = 0;
    assignment_1_DW.obj_f.i2cobj.isInitialized = 0;
    assignment_1_DW.obj_f.i2cobj.matlabCodegenIsDeleted = false;
    assignment_1_DW.obj_f.matlabCodegenIsDeleted = false;
    assignment_1_DW.obj_f.SampleTime =
      assignment_1_P.FXOS87006AxesSensor_SampleTime;
    assignment_1_SystemCore_setup(&assignment_1_DW.obj_f);

    /* Start for MATLABSystem: '<S3>/Moving Average' */
    assignment_1_DW.obj.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj.isInitialized = 0;
    assignment_1_DW.obj.NumChannels = -1;
    assignment_1_DW.obj.matlabCodegenIsDeleted = false;
    assignment_1_DW.obj.isSetupComplete = false;
    assignment_1_DW.obj.isInitialized = 1;
    assignment_1_DW.obj.NumChannels = 3;
    iobj_0 = &assignment_1_DW.obj._pobj0;
    iobj_0->isInitialized = 0;
    iobj_0->isInitialized = 0;
    assignment_1_DW.obj.pStatistic = iobj_0;
    assignment_1_DW.obj.isSetupComplete = true;
    assignment_1_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S3>/Moving Average' */
    iobj_0 = assignment_1_DW.obj.pStatistic;
    if (iobj_0->isInitialized == 1) {
      iobj_0->pCumSum[0] = 0.0;
      iobj_0->pCumSum[1] = 0.0;
      iobj_0->pCumSum[2] = 0.0;
      for (i = 0; i < 102; i++) {
        iobj_0->pCumSumRev[i] = 0.0;
      }

      iobj_0->pCumRevIndex = 1.0;
      iobj_0->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S3>/Moving Average' */

    /* Start for MATLABSystem: '<S4>/ATR_CMP_DETECT D0' */
    assignment_1_DW.obj_f0.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj_f0.isInitialized = 0;
    assignment_1_DW.obj_f0.SampleTime = -1.0;
    assignment_1_DW.obj_f0.matlabCodegenIsDeleted = false;
    assignment_1_DW.obj_f0.SampleTime =
      assignment_1_P.ATR_CMP_DETECTD0_SampleTime;
    obj = &assignment_1_DW.obj_f0;
    assignment_1_DW.obj_f0.isSetupComplete = false;
    assignment_1_DW.obj_f0.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    assignment_1_DW.obj_f0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/VENT_CMP_DETECT D1' */
    assignment_1_DW.obj_i.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj_i.isInitialized = 0;
    assignment_1_DW.obj_i.SampleTime = -1.0;
    assignment_1_DW.obj_i.matlabCodegenIsDeleted = false;
    assignment_1_DW.obj_i.SampleTime =
      assignment_1_P.VENT_CMP_DETECTD1_SampleTime;
    obj = &assignment_1_DW.obj_i;
    assignment_1_DW.obj_i.isSetupComplete = false;
    assignment_1_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    assignment_1_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/ATR_GND_CTRL D11' */
    assignment_1_DW.obj_o.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj_o.isInitialized = 0;
    assignment_1_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_0 = &assignment_1_DW.obj_o;
    assignment_1_DW.obj_o.isSetupComplete = false;
    assignment_1_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    assignment_1_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/ATR_PACE_CTRL D8' */
    assignment_1_DW.obj_pu.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj_pu.isInitialized = 0;
    assignment_1_DW.obj_pu.matlabCodegenIsDeleted = false;
    obj_0 = &assignment_1_DW.obj_pu;
    assignment_1_DW.obj_pu.isSetupComplete = false;
    assignment_1_DW.obj_pu.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    assignment_1_DW.obj_pu.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PACING_REF_PWM D5' */
    assignment_1_DW.obj_p.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj_p.isInitialized = 0;
    assignment_1_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_1 = &assignment_1_DW.obj_p;
    assignment_1_DW.obj_p.isSetupComplete = false;
    assignment_1_DW.obj_p.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(assignment_1_DW.obj_p.MW_PWM_HANDLE);
    assignment_1_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Z_VENT_CTRL D7' */
    assignment_1_DW.obj_m.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj_m.isInitialized = 0;
    assignment_1_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &assignment_1_DW.obj_m;
    assignment_1_DW.obj_m.isSetupComplete = false;
    assignment_1_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    assignment_1_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/VENT_PACE_CTRL D9  ' */
    assignment_1_DW.obj_ko.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj_ko.isInitialized = 0;
    assignment_1_DW.obj_ko.matlabCodegenIsDeleted = false;
    obj_0 = &assignment_1_DW.obj_ko;
    assignment_1_DW.obj_ko.isSetupComplete = false;
    assignment_1_DW.obj_ko.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    assignment_1_DW.obj_ko.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PACE_GND_CTRL D10' */
    assignment_1_DW.obj_df.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj_df.isInitialized = 0;
    assignment_1_DW.obj_df.matlabCodegenIsDeleted = false;
    obj_0 = &assignment_1_DW.obj_df;
    assignment_1_DW.obj_df.isSetupComplete = false;
    assignment_1_DW.obj_df.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    assignment_1_DW.obj_df.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/VENT_GND_CTRL D12' */
    assignment_1_DW.obj_e.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj_e.isInitialized = 0;
    assignment_1_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &assignment_1_DW.obj_e;
    assignment_1_DW.obj_e.isSetupComplete = false;
    assignment_1_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    assignment_1_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Z_ATR_CTRL D4' */
    assignment_1_DW.obj_mn.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj_mn.isInitialized = 0;
    assignment_1_DW.obj_mn.matlabCodegenIsDeleted = false;
    obj_0 = &assignment_1_DW.obj_mn;
    assignment_1_DW.obj_mn.isSetupComplete = false;
    assignment_1_DW.obj_mn.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    assignment_1_DW.obj_mn.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PACE_CHARGE_CTRL D2' */
    assignment_1_DW.obj_h.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj_h.isInitialized = 0;
    assignment_1_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &assignment_1_DW.obj_h;
    assignment_1_DW.obj_h.isSetupComplete = false;
    assignment_1_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    assignment_1_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write1' */
    assignment_1_DW.obj_d.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj_d.isInitialized = 0;
    assignment_1_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_0 = &assignment_1_DW.obj_d;
    assignment_1_DW.obj_d.isSetupComplete = false;
    assignment_1_DW.obj_d.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    assignment_1_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write' */
    assignment_1_DW.obj_i4.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj_i4.isInitialized = 0;
    assignment_1_DW.obj_i4.matlabCodegenIsDeleted = false;
    obj_0 = &assignment_1_DW.obj_i4;
    assignment_1_DW.obj_i4.isSetupComplete = false;
    assignment_1_DW.obj_i4.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    assignment_1_DW.obj_i4.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/FRONTEND_CTRL D13' */
    assignment_1_DW.obj_a.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj_a.isInitialized = 0;
    assignment_1_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_0 = &assignment_1_DW.obj_a;
    assignment_1_DW.obj_a.isSetupComplete = false;
    assignment_1_DW.obj_a.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    assignment_1_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/ATR_CMP_REF_PWM D6' */
    assignment_1_DW.obj_g.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj_g.isInitialized = 0;
    assignment_1_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_1 = &assignment_1_DW.obj_g;
    assignment_1_DW.obj_g.isSetupComplete = false;
    assignment_1_DW.obj_g.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(assignment_1_DW.obj_g.MW_PWM_HANDLE);
    assignment_1_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/VENT_CMP_REF_PWM D3' */
    assignment_1_DW.obj_k.matlabCodegenIsDeleted = true;
    assignment_1_DW.obj_k.isInitialized = 0;
    assignment_1_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_1 = &assignment_1_DW.obj_k;
    assignment_1_DW.obj_k.isSetupComplete = false;
    assignment_1_DW.obj_k.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(assignment_1_DW.obj_k.MW_PWM_HANDLE);
    assignment_1_DW.obj_k.isSetupComplete = true;
  }
}

/* Model terminate function */
void assignment_1_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj;
  g_dsp_internal_SlidingWindowA_T *obj_0;

  /* Terminate for MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */
  if (!assignment_1_DW.obj_f.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_f.isInitialized == 1) &&
        assignment_1_DW.obj_f.isSetupComplete) {
      MW_I2C_Close(assignment_1_DW.obj_f.i2cobj.MW_I2C_HANDLE);
    }
  }

  obj = &assignment_1_DW.obj_f.i2cobj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */

  /* Terminate for MATLABSystem: '<S3>/Moving Average' */
  if (!assignment_1_DW.obj.matlabCodegenIsDeleted) {
    assignment_1_DW.obj.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj.isInitialized == 1) &&
        assignment_1_DW.obj.isSetupComplete) {
      obj_0 = assignment_1_DW.obj.pStatistic;
      if (obj_0->isInitialized == 1) {
        obj_0->isInitialized = 2;
      }

      assignment_1_DW.obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Moving Average' */

  /* Terminate for MATLABSystem: '<S4>/ATR_CMP_DETECT D0' */
  if (!assignment_1_DW.obj_f0.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_f0.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_f0.isInitialized == 1) &&
        assignment_1_DW.obj_f0.isSetupComplete) {
      MW_digitalIO_close(assignment_1_DW.obj_f0.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/ATR_CMP_DETECT D0' */

  /* Terminate for MATLABSystem: '<S4>/VENT_CMP_DETECT D1' */
  if (!assignment_1_DW.obj_i.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_i.isInitialized == 1) &&
        assignment_1_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(assignment_1_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/VENT_CMP_DETECT D1' */

  /* Terminate for MATLABSystem: '<S2>/ATR_GND_CTRL D11' */
  if (!assignment_1_DW.obj_o.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_o.isInitialized == 1) &&
        assignment_1_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(assignment_1_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ATR_GND_CTRL D11' */

  /* Terminate for MATLABSystem: '<S2>/ATR_PACE_CTRL D8' */
  if (!assignment_1_DW.obj_pu.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_pu.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_pu.isInitialized == 1) &&
        assignment_1_DW.obj_pu.isSetupComplete) {
      MW_digitalIO_close(assignment_1_DW.obj_pu.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ATR_PACE_CTRL D8' */

  /* Terminate for MATLABSystem: '<S2>/PACING_REF_PWM D5' */
  if (!assignment_1_DW.obj_p.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_p.isInitialized == 1) &&
        assignment_1_DW.obj_p.isSetupComplete) {
      MW_PWM_Stop(assignment_1_DW.obj_p.MW_PWM_HANDLE);
      MW_PWM_Close(assignment_1_DW.obj_p.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PACING_REF_PWM D5' */

  /* Terminate for MATLABSystem: '<S2>/Z_VENT_CTRL D7' */
  if (!assignment_1_DW.obj_m.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_m.isInitialized == 1) &&
        assignment_1_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(assignment_1_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Z_VENT_CTRL D7' */

  /* Terminate for MATLABSystem: '<S2>/VENT_PACE_CTRL D9  ' */
  if (!assignment_1_DW.obj_ko.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_ko.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_ko.isInitialized == 1) &&
        assignment_1_DW.obj_ko.isSetupComplete) {
      MW_digitalIO_close(assignment_1_DW.obj_ko.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/VENT_PACE_CTRL D9  ' */

  /* Terminate for MATLABSystem: '<S2>/PACE_GND_CTRL D10' */
  if (!assignment_1_DW.obj_df.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_df.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_df.isInitialized == 1) &&
        assignment_1_DW.obj_df.isSetupComplete) {
      MW_digitalIO_close(assignment_1_DW.obj_df.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PACE_GND_CTRL D10' */

  /* Terminate for MATLABSystem: '<S2>/VENT_GND_CTRL D12' */
  if (!assignment_1_DW.obj_e.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_e.isInitialized == 1) &&
        assignment_1_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(assignment_1_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/VENT_GND_CTRL D12' */

  /* Terminate for MATLABSystem: '<S2>/Z_ATR_CTRL D4' */
  if (!assignment_1_DW.obj_mn.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_mn.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_mn.isInitialized == 1) &&
        assignment_1_DW.obj_mn.isSetupComplete) {
      MW_digitalIO_close(assignment_1_DW.obj_mn.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Z_ATR_CTRL D4' */

  /* Terminate for MATLABSystem: '<S2>/PACE_CHARGE_CTRL D2' */
  if (!assignment_1_DW.obj_h.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_h.isInitialized == 1) &&
        assignment_1_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(assignment_1_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PACE_CHARGE_CTRL D2' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write1' */
  if (!assignment_1_DW.obj_d.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_d.isInitialized == 1) &&
        assignment_1_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close(assignment_1_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write' */
  if (!assignment_1_DW.obj_i4.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_i4.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_i4.isInitialized == 1) &&
        assignment_1_DW.obj_i4.isSetupComplete) {
      MW_digitalIO_close(assignment_1_DW.obj_i4.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write' */

  /* Terminate for MATLABSystem: '<S2>/FRONTEND_CTRL D13' */
  if (!assignment_1_DW.obj_a.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_a.isInitialized == 1) &&
        assignment_1_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(assignment_1_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/FRONTEND_CTRL D13' */

  /* Terminate for MATLABSystem: '<S2>/ATR_CMP_REF_PWM D6' */
  if (!assignment_1_DW.obj_g.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_g.isInitialized == 1) &&
        assignment_1_DW.obj_g.isSetupComplete) {
      MW_PWM_Stop(assignment_1_DW.obj_g.MW_PWM_HANDLE);
      MW_PWM_Close(assignment_1_DW.obj_g.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ATR_CMP_REF_PWM D6' */

  /* Terminate for MATLABSystem: '<S2>/VENT_CMP_REF_PWM D3' */
  if (!assignment_1_DW.obj_k.matlabCodegenIsDeleted) {
    assignment_1_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((assignment_1_DW.obj_k.isInitialized == 1) &&
        assignment_1_DW.obj_k.isSetupComplete) {
      MW_PWM_Stop(assignment_1_DW.obj_k.MW_PWM_HANDLE);
      MW_PWM_Close(assignment_1_DW.obj_k.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/VENT_CMP_REF_PWM D3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
