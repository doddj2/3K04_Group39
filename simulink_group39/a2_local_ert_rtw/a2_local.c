/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a2_local.c
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
#include "a2_local_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include <stddef.h>
#include "MW_I2C.h"
#include "a2_local_private.h"
#include "a2_local_dt.h"

/* Named constants for Chart: '<S3>/4 Modes' */
#define a2_local_HIGH                  (true)
#define a2_local_IN_AAI                (1U)
#define a2_local_IN_AAIR               (2U)
#define a2_local_IN_AOO                (3U)
#define a2_local_IN_AOOR               (4U)
#define a2_local_IN_ARP_Period         (1U)
#define a2_local_IN_Alert_Period       (1U)
#define a2_local_IN_Alert_Period_g     (2U)
#define a2_local_IN_Charging           (1U)
#define a2_local_IN_Charging1          (2U)
#define a2_local_IN_Charging_c         (2U)
#define a2_local_IN_Charging_c0        (3U)
#define a2_local_IN_NO_ACTIVE_CHILD    ((uint8_T)0U)
#define a2_local_IN_Pacing             (2U)
#define a2_local_IN_Pacing_m           (3U)
#define a2_local_IN_Pacing_m4          (4U)
#define a2_local_IN_Start              (5U)
#define a2_local_IN_VOO                (6U)
#define a2_local_IN_VOOR               (7U)
#define a2_local_IN_VRP_Period         (4U)
#define a2_local_IN_VVI                (8U)
#define a2_local_IN_VVIR               (9U)
#define a2_local_LOW                   (false)

/* Block signals (default storage) */
B_a2_local_T a2_local_B;

/* Block states (default storage) */
DW_a2_local_T a2_local_DW;

/* Real-time model */
static RT_MODEL_a2_local_T a2_local_M_;
RT_MODEL_a2_local_T *const a2_local_M = &a2_local_M_;

/* Forward declaration for local functions */
static int16_T a2_local_bitshift_anonFcn1(int16_T a1, real_T k1);
static void a2_l_enter_atomic_Charging_gpsh(void);
static void a2_local_VVIR(void);
static void a2_local_enter_atomic_Charging(void);
static void a2_local_AAIR(void);
static void a2_local_Start(void);
static void a2_local_VVI(void);
static void a2_local_SystemCore_setup(freedomk64f_fxos8700_a2_local_T *obj);
static int16_T a2_local_bitshift_anonFcn1(int16_T a1, real_T k1)
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

/* Function for Chart: '<S3>/4 Modes' */
static void a2_l_enter_atomic_Charging_gpsh(void)
{
  a2_local_B.PACING_REF_PWM = a2_local_B.Gain1;
  a2_local_B.PACE_CHARGE_CTRL = a2_local_HIGH;
  a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
  a2_local_B.VENT_PACE_CTRL = a2_local_LOW;
  a2_local_B.Z_ATR_CTRL = a2_local_LOW;
  a2_local_B.Z_VENT_CTRL = a2_local_LOW;
  a2_local_B.ATR_PACE_CTRL = a2_local_LOW;
  a2_local_B.ATR_GND_CTRL = a2_local_LOW;
  a2_local_B.VENT_GND_CTRL = a2_local_HIGH;
}

/* Function for Chart: '<S3>/4 Modes' */
static void a2_local_VVIR(void)
{
  switch (a2_local_DW.is_VVIR) {
   case a2_local_IN_Alert_Period:
    if (a2_local_B.VENT_CMP_DETECTD1) {
      a2_local_DW.is_VVIR = a2_local_IN_VRP_Period;
      a2_local_DW.temporalCounter_i1 = 0U;
    } else if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil((0.5 *
                 a2_local_B.Divide2_m - a2_local_B.VentricularPluseWidthmsec) -
                a2_local_B.VRPmsec)) {
      a2_local_DW.is_VVIR = a2_local_IN_Pacing_m;
      a2_local_DW.temporalCounter_i1 = 0U;
      a2_local_B.PACE_CHARGE_CTRL = a2_local_LOW;
      a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
      a2_local_B.ATR_PACE_CTRL = a2_local_LOW;
      a2_local_B.ATR_GND_CTRL = a2_local_LOW;
      a2_local_B.Z_ATR_CTRL = a2_local_LOW;
      a2_local_B.Z_VENT_CTRL = a2_local_LOW;
      a2_local_B.VENT_GND_CTRL = a2_local_LOW;
      a2_local_B.VENT_PACE_CTRL = a2_local_HIGH;
    }
    break;

   case a2_local_IN_Charging_c:
    a2_local_B.PACE_CHARGE_CTRL = a2_local_HIGH;
    a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
    a2_local_B.Z_ATR_CTRL = a2_local_LOW;
    a2_local_B.Z_VENT_CTRL = a2_local_LOW;
    a2_local_B.ATR_GND_CTRL = a2_local_LOW;
    a2_local_B.VENT_GND_CTRL = a2_local_HIGH;
    if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil(a2_local_B.VRPmsec)) {
      a2_local_DW.is_VVIR = a2_local_IN_Alert_Period;
      a2_local_DW.temporalCounter_i1 = 0U;
    } else if (a2_local_B.mode != 6.0) {
      a2_local_DW.is_VVIR = a2_local_IN_NO_ACTIVE_CHILD;
      a2_local_DW.is_c3_a2_local = a2_local_IN_Start;
    }
    break;

   case a2_local_IN_Pacing_m:
    a2_local_B.PACE_CHARGE_CTRL = a2_local_LOW;
    a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
    a2_local_B.ATR_GND_CTRL = a2_local_LOW;
    a2_local_B.Z_ATR_CTRL = a2_local_LOW;
    a2_local_B.Z_VENT_CTRL = a2_local_LOW;
    a2_local_B.VENT_GND_CTRL = a2_local_LOW;
    if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil
        (a2_local_B.VentricularPluseWidthmsec)) {
      a2_local_DW.is_VVIR = a2_local_IN_Charging_c;
      a2_local_DW.temporalCounter_i1 = 0U;
      a2_l_enter_atomic_Charging_gpsh();
    }
    break;

   default:
    /* case IN_VRP_Period: */
    if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil(a2_local_B.VRPmsec)) {
      a2_local_DW.is_VVIR = a2_local_IN_Alert_Period;
      a2_local_DW.temporalCounter_i1 = 0U;
    }
    break;
  }
}

/* Function for Chart: '<S3>/4 Modes' */
static void a2_local_enter_atomic_Charging(void)
{
  a2_local_B.PACING_REF_PWM = a2_local_B.Gain;
  a2_local_B.PACE_CHARGE_CTRL = a2_local_HIGH;
  a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
  a2_local_B.VENT_PACE_CTRL = a2_local_LOW;
  a2_local_B.Z_ATR_CTRL = a2_local_LOW;
  a2_local_B.Z_VENT_CTRL = a2_local_LOW;
  a2_local_B.ATR_PACE_CTRL = a2_local_LOW;
  a2_local_B.ATR_GND_CTRL = a2_local_HIGH;
  a2_local_B.VENT_GND_CTRL = a2_local_LOW;
}

/* Function for Chart: '<S3>/4 Modes' */
static void a2_local_AAIR(void)
{
  switch (a2_local_DW.is_AAIR) {
   case a2_local_IN_ARP_Period:
    if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil(a2_local_B.ARPmsec)) {
      a2_local_DW.is_AAIR = a2_local_IN_Alert_Period_g;
      a2_local_DW.temporalCounter_i1 = 0U;
    }
    break;

   case a2_local_IN_Alert_Period_g:
    if (a2_local_B.ATR_CMP_DETECTD0) {
      a2_local_DW.is_AAIR = a2_local_IN_ARP_Period;
      a2_local_DW.temporalCounter_i1 = 0U;
    } else if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil((0.5 *
                 a2_local_B.Divide2_m - a2_local_B.AtrialPluseWidthmsec) -
                a2_local_B.ARPmsec)) {
      a2_local_DW.is_AAIR = a2_local_IN_Pacing_m4;
      a2_local_DW.temporalCounter_i1 = 0U;
      a2_local_B.PACE_CHARGE_CTRL = a2_local_LOW;
      a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
      a2_local_B.ATR_PACE_CTRL = a2_local_HIGH;
      a2_local_B.ATR_GND_CTRL = a2_local_LOW;
      a2_local_B.Z_ATR_CTRL = a2_local_LOW;
      a2_local_B.Z_VENT_CTRL = a2_local_LOW;
      a2_local_B.VENT_GND_CTRL = a2_local_LOW;
      a2_local_B.VENT_PACE_CTRL = a2_local_LOW;
    }
    break;

   case a2_local_IN_Charging_c0:
    a2_local_B.PACE_CHARGE_CTRL = a2_local_HIGH;
    a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
    a2_local_B.Z_ATR_CTRL = a2_local_LOW;
    a2_local_B.Z_VENT_CTRL = a2_local_LOW;
    a2_local_B.ATR_GND_CTRL = a2_local_HIGH;
    a2_local_B.VENT_GND_CTRL = a2_local_LOW;
    if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil(a2_local_B.ARPmsec)) {
      a2_local_DW.is_AAIR = a2_local_IN_Alert_Period_g;
      a2_local_DW.temporalCounter_i1 = 0U;
    } else if (a2_local_B.mode != 7.0) {
      a2_local_DW.is_AAIR = a2_local_IN_NO_ACTIVE_CHILD;
      a2_local_DW.is_c3_a2_local = a2_local_IN_Start;
    }
    break;

   default:
    /* case IN_Pacing: */
    a2_local_B.PACE_CHARGE_CTRL = a2_local_LOW;
    a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
    a2_local_B.ATR_GND_CTRL = a2_local_LOW;
    a2_local_B.Z_ATR_CTRL = a2_local_LOW;
    a2_local_B.Z_VENT_CTRL = a2_local_LOW;
    a2_local_B.VENT_GND_CTRL = a2_local_LOW;
    if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil
        (a2_local_B.AtrialPluseWidthmsec)) {
      a2_local_DW.is_AAIR = a2_local_IN_Charging_c0;
      a2_local_DW.temporalCounter_i1 = 0U;
      a2_local_enter_atomic_Charging();
    }
    break;
  }
}

/* Function for Chart: '<S3>/4 Modes' */
static void a2_local_Start(void)
{
  if (a2_local_B.mode == 5.0) {
    a2_local_DW.is_c3_a2_local = a2_local_IN_AOOR;
    a2_local_DW.is_AOOR = a2_local_IN_Charging;
    a2_local_DW.temporalCounter_i1 = 0U;
    a2_local_enter_atomic_Charging();
  } else if (a2_local_B.mode == 0.0) {
    a2_local_DW.is_c3_a2_local = a2_local_IN_VOO;
    a2_local_DW.is_VOO = a2_local_IN_Charging;
    a2_local_DW.temporalCounter_i1 = 0U;
    a2_l_enter_atomic_Charging_gpsh();
  } else if (a2_local_B.mode == 4.0) {
    a2_local_DW.is_c3_a2_local = a2_local_IN_VOOR;
    a2_local_DW.is_VOOR = a2_local_IN_Charging;
    a2_local_DW.temporalCounter_i1 = 0U;
    a2_l_enter_atomic_Charging_gpsh();
  } else if (a2_local_B.mode == 1.0) {
    a2_local_DW.is_c3_a2_local = a2_local_IN_AOO;
    a2_local_DW.is_AOO = a2_local_IN_Charging;
    a2_local_DW.temporalCounter_i1 = 0U;
    a2_local_enter_atomic_Charging();
  } else if (a2_local_B.mode == 2.0) {
    a2_local_DW.is_c3_a2_local = a2_local_IN_VVI;
    a2_local_DW.is_VVI = a2_local_IN_Charging1;
    a2_local_DW.temporalCounter_i1 = 0U;
    a2_l_enter_atomic_Charging_gpsh();
  } else if (a2_local_B.mode == 3.0) {
    a2_local_DW.is_c3_a2_local = a2_local_IN_AAI;
    a2_local_DW.is_AAI = a2_local_IN_Charging_c0;
    a2_local_DW.temporalCounter_i1 = 0U;
    a2_local_enter_atomic_Charging();
  } else if (a2_local_B.mode == 6.0) {
    a2_local_DW.is_c3_a2_local = a2_local_IN_VVIR;
    a2_local_DW.is_VVIR = a2_local_IN_Charging_c;
    a2_local_DW.temporalCounter_i1 = 0U;
    a2_l_enter_atomic_Charging_gpsh();
  } else if (a2_local_B.mode == 7.0) {
    a2_local_DW.is_c3_a2_local = a2_local_IN_AAIR;
    a2_local_DW.is_AAIR = a2_local_IN_Charging_c0;
    a2_local_DW.temporalCounter_i1 = 0U;
    a2_local_enter_atomic_Charging();
  }
}

/* Function for Chart: '<S3>/4 Modes' */
static void a2_local_VVI(void)
{
  switch (a2_local_DW.is_VVI) {
   case a2_local_IN_Alert_Period:
    if (a2_local_B.VENT_CMP_DETECTD1) {
      a2_local_DW.is_VVI = a2_local_IN_VRP_Period;
      a2_local_DW.temporalCounter_i1 = 0U;
    } else if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil
               (a2_local_B.Divide2 - a2_local_B.VRPmsec)) {
      a2_local_DW.is_VVI = a2_local_IN_Pacing_m;
      a2_local_DW.temporalCounter_i1 = 0U;
      a2_local_B.PACE_CHARGE_CTRL = a2_local_LOW;
      a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
      a2_local_B.ATR_PACE_CTRL = a2_local_LOW;
      a2_local_B.ATR_GND_CTRL = a2_local_LOW;
      a2_local_B.Z_ATR_CTRL = a2_local_LOW;
      a2_local_B.Z_VENT_CTRL = a2_local_LOW;
      a2_local_B.VENT_GND_CTRL = a2_local_LOW;
      a2_local_B.VENT_PACE_CTRL = a2_local_HIGH;
    }
    break;

   case a2_local_IN_Charging1:
    a2_local_B.PACE_CHARGE_CTRL = a2_local_HIGH;
    a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
    a2_local_B.Z_ATR_CTRL = a2_local_LOW;
    a2_local_B.Z_VENT_CTRL = a2_local_LOW;
    a2_local_B.ATR_GND_CTRL = a2_local_LOW;
    a2_local_B.VENT_GND_CTRL = a2_local_HIGH;
    if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil(a2_local_B.VRPmsec)) {
      a2_local_DW.is_VVI = a2_local_IN_Alert_Period;
      a2_local_DW.temporalCounter_i1 = 0U;
    } else if (a2_local_B.mode != 2.0) {
      a2_local_DW.is_VVI = a2_local_IN_NO_ACTIVE_CHILD;
      a2_local_DW.is_c3_a2_local = a2_local_IN_Start;
    }
    break;

   case a2_local_IN_Pacing_m:
    a2_local_B.PACE_CHARGE_CTRL = a2_local_LOW;
    a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
    a2_local_B.ATR_GND_CTRL = a2_local_LOW;
    a2_local_B.Z_ATR_CTRL = a2_local_LOW;
    a2_local_B.Z_VENT_CTRL = a2_local_LOW;
    a2_local_B.VENT_GND_CTRL = a2_local_LOW;
    if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil
        (a2_local_B.VentricularPluseWidthmsec)) {
      a2_local_DW.is_VVI = a2_local_IN_Charging1;
      a2_local_DW.temporalCounter_i1 = 0U;
      a2_l_enter_atomic_Charging_gpsh();
    }
    break;

   default:
    /* case IN_VRP_Period: */
    if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil(a2_local_B.VRPmsec)) {
      a2_local_DW.is_VVI = a2_local_IN_Alert_Period;
      a2_local_DW.temporalCounter_i1 = 0U;
    }
    break;
  }
}

static void a2_local_SystemCore_setup(freedomk64f_fxos8700_a2_local_T *obj)
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
  b_SwappedDataBytes[1] = 25U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  obj->isSetupComplete = true;
}

/* Model step function */
void a2_local_step(void)
{
  real_T tmp;
  int16_T b_RegisterValue[3];
  uint8_T output_raw[6];
  uint8_T b_x[2];
  uint8_T y[2];
  uint8_T status;

  /* Reset subsysRan breadcrumbs */
  srClearBC(a2_local_DW.calculateacceleration3D_SubsysR);

  /* Constant: '<S1>/mode' */
  a2_local_B.mode = a2_local_P.mode_Value;

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   */
  if (a2_local_B.mode >= a2_local_P.Switch_Threshold) {
    tmp = a2_local_P.Constant_Value_d;
  } else {
    tmp = a2_local_P.Constant1_Value;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Outputs for Enabled SubSystem: '<S1>/calculate acceleration(3D)' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (tmp > 0.0) {
    /* MATLABSystem: '<S5>/FXOS8700 6-Axes Sensor' */
    if (a2_local_DW.obj.SampleTime != a2_local_P.FXOS87006AxesSensor_SampleTime)
    {
      a2_local_DW.obj.SampleTime = a2_local_P.FXOS87006AxesSensor_SampleTime;
    }

    status = 1U;
    status = MW_I2C_MasterWrite(a2_local_DW.obj.i2cobj.MW_I2C_HANDLE, 29U,
      &status, 1U, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(a2_local_DW.obj.i2cobj.MW_I2C_HANDLE, 29U, &output_raw[0],
                        6U, false, true);
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

    /* MATLABSystem: '<S5>/FXOS8700 6-Axes Sensor' */
    a2_local_B.FXOS87006AxesSensor[0] = (real_T)a2_local_bitshift_anonFcn1
      (b_RegisterValue[0], -2.0) * 2.0 * 0.244 / 1000.0;
    a2_local_B.FXOS87006AxesSensor[1] = (real_T)a2_local_bitshift_anonFcn1
      (b_RegisterValue[1], -2.0) * 2.0 * 0.244 / 1000.0;
    a2_local_B.FXOS87006AxesSensor[2] = (real_T)a2_local_bitshift_anonFcn1
      (b_RegisterValue[2], -2.0) * 2.0 * 0.244 / 1000.0;

    /* Sum: '<S5>/Add' incorporates:
     *  Abs: '<S5>/Abs'
     *  Abs: '<S5>/Abs1'
     *  Abs: '<S5>/Abs2'
     *  Constant: '<S5>/Constant'
     *  Sum: '<S5>/Minus'
     */
    a2_local_B.Add = (fabs(a2_local_B.FXOS87006AxesSensor[0]) + fabs
                      (a2_local_B.FXOS87006AxesSensor[1])) + fabs
      (a2_local_B.FXOS87006AxesSensor[2] - a2_local_P.Constant_Value);
    srUpdateBC(a2_local_DW.calculateacceleration3D_SubsysR);
  }

  /* End of Outputs for SubSystem: '<S1>/calculate acceleration(3D)' */

  /* RelationalOperator: '<S4>/Relational Operator' incorporates:
   *  Constant: '<S1>/Acceleration threshold'
   */
  a2_local_B.RelationalOperator = (a2_local_B.Add >=
    a2_local_P.Accelerationthreshold_Value);

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Constant: '<S1>/maximum sensor-driven rate'
   *  Constant: '<S1>/ppm'
   *  Constant: '<S1>/reaction time'
   *  Constant: '<S1>/recovery time1'
   *  Memory: '<S3>/Memory'
   */
  if (a2_local_DW.Memory_PreviousInput == 0.0) {
    a2_local_DW.Memory_PreviousInput = a2_local_P.ppm_Value;
  }

  if (a2_local_B.RelationalOperator) {
    a2_local_DW.Memory_PreviousInput +=
      (a2_local_P.maximumsensordrivenrate_Value - a2_local_P.ppm_Value) /
      a2_local_P.reactiontime_Value;
    if (a2_local_DW.Memory_PreviousInput >
        a2_local_P.maximumsensordrivenrate_Value) {
      a2_local_DW.Memory_PreviousInput =
        a2_local_P.maximumsensordrivenrate_Value;
    }
  } else {
    a2_local_DW.Memory_PreviousInput +=
      -(a2_local_P.maximumsensordrivenrate_Value - a2_local_P.ppm_Value) /
      a2_local_P.recoverytime1_Value;
    if (a2_local_DW.Memory_PreviousInput < a2_local_P.ppm_Value) {
      a2_local_DW.Memory_PreviousInput = a2_local_P.ppm_Value;
    }
  }

  a2_local_B.time_response = a2_local_DW.Memory_PreviousInput;

  /* End of MATLAB Function: '<S3>/MATLAB Function' */
  /* Constant: '<S1>/ARP msec' */
  a2_local_B.ARPmsec = a2_local_P.ARPmsec_Value;

  /* Constant: '<S1>/Atrial Pluse Width msec' */
  a2_local_B.AtrialPluseWidthmsec = a2_local_P.AtrialPluseWidthmsec_Value;

  /* Constant: '<S1>/VRP msec' */
  a2_local_B.VRPmsec = a2_local_P.VRPmsec_Value;

  /* Constant: '<S1>/Ventricular Pluse Width msec' */
  a2_local_B.VentricularPluseWidthmsec =
    a2_local_P.VentricularPluseWidthmsec_Value;

  /* Gain: '<S10>/Gain' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S1>/Atrial Amplitude(volt)'
   *  Product: '<S10>/duty cycle calculation2'
   */
  a2_local_B.Gain = a2_local_P.AtrialAmplitudevolt_Value /
    a2_local_P.Constant_Value_b * a2_local_P.Gain_Gain;

  /* Gain: '<S10>/Gain1' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S1>/Ventricular Amplitude'
   *  Product: '<S10>/duty cycle calculation1'
   */
  a2_local_B.Gain1 = a2_local_P.VentricularAmplitude_Value /
    a2_local_P.Constant1_Value_d * a2_local_P.Gain1_Gain;

  /* MATLABSystem: '<S3>/ATR_CMP_DETECT D0' */
  if (a2_local_DW.obj_f.SampleTime != a2_local_P.ATR_CMP_DETECTD0_SampleTime) {
    a2_local_DW.obj_f.SampleTime = a2_local_P.ATR_CMP_DETECTD0_SampleTime;
  }

  /* MATLABSystem: '<S3>/ATR_CMP_DETECT D0' */
  a2_local_B.ATR_CMP_DETECTD0 = MW_digitalIO_read
    (a2_local_DW.obj_f.MW_DIGITALIO_HANDLE);

  /* Product: '<S12>/Divide2' incorporates:
   *  Constant: '<S12>/1min = 60sec = 60000msec2'
   *  Constant: '<S1>/ppm'
   */
  a2_local_B.Divide2 = a2_local_P.umin60sec60000msec2_Value /
    a2_local_P.ppm_Value;

  /* MATLABSystem: '<S3>/VENT_CMP_DETECT D1' */
  if (a2_local_DW.obj_i.SampleTime != a2_local_P.VENT_CMP_DETECTD1_SampleTime) {
    a2_local_DW.obj_i.SampleTime = a2_local_P.VENT_CMP_DETECTD1_SampleTime;
  }

  /* MATLABSystem: '<S3>/VENT_CMP_DETECT D1' */
  a2_local_B.VENT_CMP_DETECTD1 = MW_digitalIO_read
    (a2_local_DW.obj_i.MW_DIGITALIO_HANDLE);

  /* Product: '<S13>/Divide2' incorporates:
   *  Constant: '<S13>/1min = 60sec = 60000msec2'
   */
  a2_local_B.Divide2_m = a2_local_P.umin60sec60000msec2_Value_i /
    a2_local_B.time_response;

  /* Chart: '<S3>/4 Modes' */
  if (a2_local_DW.temporalCounter_i1 < MAX_uint32_T) {
    a2_local_DW.temporalCounter_i1++;
  }

  if (a2_local_DW.is_active_c3_a2_local == 0U) {
    a2_local_DW.is_active_c3_a2_local = 1U;
    a2_local_DW.is_c3_a2_local = a2_local_IN_Start;
  } else {
    switch (a2_local_DW.is_c3_a2_local) {
     case a2_local_IN_AAI:
      switch (a2_local_DW.is_AAI) {
       case a2_local_IN_ARP_Period:
        if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil(a2_local_B.ARPmsec))
        {
          a2_local_DW.is_AAI = a2_local_IN_Alert_Period_g;
          a2_local_DW.temporalCounter_i1 = 0U;
        }
        break;

       case a2_local_IN_Alert_Period_g:
        if (a2_local_B.ATR_CMP_DETECTD0) {
          a2_local_DW.is_AAI = a2_local_IN_ARP_Period;
          a2_local_DW.temporalCounter_i1 = 0U;
        } else if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil
                   (a2_local_B.Divide2 - a2_local_B.ARPmsec)) {
          a2_local_DW.is_AAI = a2_local_IN_Pacing_m4;
          a2_local_DW.temporalCounter_i1 = 0U;
          a2_local_B.PACE_CHARGE_CTRL = a2_local_LOW;
          a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
          a2_local_B.ATR_PACE_CTRL = a2_local_HIGH;
          a2_local_B.ATR_GND_CTRL = a2_local_LOW;
          a2_local_B.Z_ATR_CTRL = a2_local_LOW;
          a2_local_B.Z_VENT_CTRL = a2_local_LOW;
          a2_local_B.VENT_GND_CTRL = a2_local_LOW;
          a2_local_B.VENT_PACE_CTRL = a2_local_LOW;
        }
        break;

       case a2_local_IN_Charging_c0:
        a2_local_B.PACE_CHARGE_CTRL = a2_local_HIGH;
        a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
        a2_local_B.Z_ATR_CTRL = a2_local_LOW;
        a2_local_B.Z_VENT_CTRL = a2_local_LOW;
        a2_local_B.ATR_GND_CTRL = a2_local_HIGH;
        a2_local_B.VENT_GND_CTRL = a2_local_LOW;
        if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil(a2_local_B.ARPmsec))
        {
          a2_local_DW.is_AAI = a2_local_IN_Alert_Period_g;
          a2_local_DW.temporalCounter_i1 = 0U;
        } else if (a2_local_B.mode != 3.0) {
          a2_local_DW.is_AAI = a2_local_IN_NO_ACTIVE_CHILD;
          a2_local_DW.is_c3_a2_local = a2_local_IN_Start;
        }
        break;

       default:
        /* case IN_Pacing: */
        a2_local_B.PACE_CHARGE_CTRL = a2_local_LOW;
        a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
        a2_local_B.ATR_GND_CTRL = a2_local_LOW;
        a2_local_B.Z_ATR_CTRL = a2_local_LOW;
        a2_local_B.Z_VENT_CTRL = a2_local_LOW;
        a2_local_B.VENT_GND_CTRL = a2_local_LOW;
        if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil
            (a2_local_B.AtrialPluseWidthmsec)) {
          a2_local_DW.is_AAI = a2_local_IN_Charging_c0;
          a2_local_DW.temporalCounter_i1 = 0U;
          a2_local_enter_atomic_Charging();
        }
        break;
      }
      break;

     case a2_local_IN_AAIR:
      a2_local_AAIR();
      break;

     case a2_local_IN_AOO:
      if (a2_local_DW.is_AOO == a2_local_IN_Charging) {
        a2_local_B.PACE_CHARGE_CTRL = a2_local_HIGH;
        a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
        a2_local_B.Z_ATR_CTRL = a2_local_LOW;
        a2_local_B.Z_VENT_CTRL = a2_local_LOW;
        a2_local_B.ATR_GND_CTRL = a2_local_HIGH;
        a2_local_B.VENT_GND_CTRL = a2_local_LOW;
        if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil(a2_local_B.Divide2
             - a2_local_B.AtrialPluseWidthmsec)) {
          a2_local_DW.is_AOO = a2_local_IN_Pacing;
          a2_local_DW.temporalCounter_i1 = 0U;
          a2_local_B.PACE_CHARGE_CTRL = a2_local_LOW;
          a2_local_B.ATR_PACE_CTRL = a2_local_HIGH;
          a2_local_B.ATR_GND_CTRL = a2_local_LOW;
          a2_local_B.VENT_PACE_CTRL = a2_local_LOW;
        } else if (a2_local_B.mode != 1.0) {
          a2_local_DW.is_AOO = a2_local_IN_NO_ACTIVE_CHILD;
          a2_local_DW.is_c3_a2_local = a2_local_IN_Start;
        }
      } else {
        /* case IN_Pacing: */
        a2_local_B.PACE_CHARGE_CTRL = a2_local_LOW;
        a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
        a2_local_B.ATR_GND_CTRL = a2_local_LOW;
        a2_local_B.Z_ATR_CTRL = a2_local_LOW;
        a2_local_B.Z_VENT_CTRL = a2_local_LOW;
        a2_local_B.VENT_GND_CTRL = a2_local_LOW;
        if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil
            (a2_local_B.AtrialPluseWidthmsec)) {
          a2_local_DW.is_AOO = a2_local_IN_Charging;
          a2_local_DW.temporalCounter_i1 = 0U;
          a2_local_enter_atomic_Charging();
        }
      }
      break;

     case a2_local_IN_AOOR:
      if (a2_local_DW.is_AOOR == a2_local_IN_Charging) {
        a2_local_B.PACE_CHARGE_CTRL = a2_local_HIGH;
        a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
        a2_local_B.Z_ATR_CTRL = a2_local_LOW;
        a2_local_B.Z_VENT_CTRL = a2_local_LOW;
        a2_local_B.ATR_GND_CTRL = a2_local_HIGH;
        a2_local_B.VENT_GND_CTRL = a2_local_LOW;
        if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil(0.5 *
             a2_local_B.Divide2_m - a2_local_B.AtrialPluseWidthmsec)) {
          a2_local_DW.is_AOOR = a2_local_IN_Pacing;
          a2_local_DW.temporalCounter_i1 = 0U;
          a2_local_B.PACE_CHARGE_CTRL = a2_local_LOW;
          a2_local_B.ATR_PACE_CTRL = a2_local_HIGH;
          a2_local_B.ATR_GND_CTRL = a2_local_LOW;
          a2_local_B.VENT_PACE_CTRL = a2_local_LOW;
        } else if (a2_local_B.mode != 5.0) {
          a2_local_DW.is_AOOR = a2_local_IN_NO_ACTIVE_CHILD;
          a2_local_DW.is_c3_a2_local = a2_local_IN_Start;
        }
      } else {
        /* case IN_Pacing: */
        a2_local_B.PACE_CHARGE_CTRL = a2_local_LOW;
        a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
        a2_local_B.ATR_GND_CTRL = a2_local_LOW;
        a2_local_B.Z_ATR_CTRL = a2_local_LOW;
        a2_local_B.Z_VENT_CTRL = a2_local_LOW;
        a2_local_B.VENT_GND_CTRL = a2_local_LOW;
        if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil
            (a2_local_B.AtrialPluseWidthmsec)) {
          a2_local_DW.is_AOOR = a2_local_IN_Charging;
          a2_local_DW.temporalCounter_i1 = 0U;
          a2_local_enter_atomic_Charging();
        }
      }
      break;

     case a2_local_IN_Start:
      a2_local_Start();
      break;

     case a2_local_IN_VOO:
      if (a2_local_DW.is_VOO == a2_local_IN_Charging) {
        a2_local_B.PACE_CHARGE_CTRL = a2_local_HIGH;
        a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
        a2_local_B.Z_ATR_CTRL = a2_local_LOW;
        a2_local_B.Z_VENT_CTRL = a2_local_LOW;
        a2_local_B.ATR_GND_CTRL = a2_local_LOW;
        a2_local_B.VENT_GND_CTRL = a2_local_HIGH;
        if (a2_local_B.mode != 0.0) {
          a2_local_DW.is_VOO = a2_local_IN_NO_ACTIVE_CHILD;
          a2_local_DW.is_c3_a2_local = a2_local_IN_Start;
        } else if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil
                   (a2_local_B.Divide2 - a2_local_B.VentricularPluseWidthmsec))
        {
          a2_local_DW.is_VOO = a2_local_IN_Pacing;
          a2_local_DW.temporalCounter_i1 = 0U;
          a2_local_B.PACE_CHARGE_CTRL = a2_local_LOW;
          a2_local_B.ATR_PACE_CTRL = a2_local_LOW;
          a2_local_B.VENT_GND_CTRL = a2_local_LOW;
          a2_local_B.VENT_PACE_CTRL = a2_local_HIGH;
        }
      } else {
        /* case IN_Pacing: */
        a2_local_B.PACE_CHARGE_CTRL = a2_local_LOW;
        a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
        a2_local_B.ATR_GND_CTRL = a2_local_LOW;
        a2_local_B.Z_ATR_CTRL = a2_local_LOW;
        a2_local_B.Z_VENT_CTRL = a2_local_LOW;
        a2_local_B.VENT_GND_CTRL = a2_local_LOW;
        if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil
            (a2_local_B.VentricularPluseWidthmsec)) {
          a2_local_DW.is_VOO = a2_local_IN_Charging;
          a2_local_DW.temporalCounter_i1 = 0U;
          a2_l_enter_atomic_Charging_gpsh();
        }
      }
      break;

     case a2_local_IN_VOOR:
      if (a2_local_DW.is_VOOR == a2_local_IN_Charging) {
        a2_local_B.PACE_CHARGE_CTRL = a2_local_HIGH;
        a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
        a2_local_B.Z_ATR_CTRL = a2_local_LOW;
        a2_local_B.Z_VENT_CTRL = a2_local_LOW;
        a2_local_B.ATR_GND_CTRL = a2_local_LOW;
        a2_local_B.VENT_GND_CTRL = a2_local_HIGH;
        if (a2_local_B.mode != 4.0) {
          a2_local_DW.is_VOOR = a2_local_IN_NO_ACTIVE_CHILD;
          a2_local_DW.is_c3_a2_local = a2_local_IN_Start;
        } else if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil(0.5 *
                    a2_local_B.Divide2_m - a2_local_B.VentricularPluseWidthmsec))
        {
          a2_local_DW.is_VOOR = a2_local_IN_Pacing;
          a2_local_DW.temporalCounter_i1 = 0U;
          a2_local_B.PACE_CHARGE_CTRL = a2_local_LOW;
          a2_local_B.ATR_PACE_CTRL = a2_local_LOW;
          a2_local_B.VENT_GND_CTRL = a2_local_LOW;
          a2_local_B.VENT_PACE_CTRL = a2_local_HIGH;
        }
      } else {
        /* case IN_Pacing: */
        a2_local_B.PACE_CHARGE_CTRL = a2_local_LOW;
        a2_local_B.PACE_GND_CTRL = a2_local_HIGH;
        a2_local_B.ATR_GND_CTRL = a2_local_LOW;
        a2_local_B.Z_ATR_CTRL = a2_local_LOW;
        a2_local_B.Z_VENT_CTRL = a2_local_LOW;
        a2_local_B.VENT_GND_CTRL = a2_local_LOW;
        if (a2_local_DW.temporalCounter_i1 >= (uint32_T)ceil
            (a2_local_B.VentricularPluseWidthmsec)) {
          a2_local_DW.is_VOOR = a2_local_IN_Charging;
          a2_local_DW.temporalCounter_i1 = 0U;
          a2_l_enter_atomic_Charging_gpsh();
        }
      }
      break;

     case a2_local_IN_VVI:
      a2_local_VVI();
      break;

     default:
      /* case IN_VVIR: */
      a2_local_VVIR();
      break;
    }
  }

  /* End of Chart: '<S3>/4 Modes' */

  /* MATLABSystem: '<S2>/ATR_GND_CTRL D11' */
  MW_digitalIO_write(a2_local_DW.obj_o.MW_DIGITALIO_HANDLE,
                     a2_local_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S2>/ATR_PACE_CTRL D8' */
  MW_digitalIO_write(a2_local_DW.obj_p.MW_DIGITALIO_HANDLE,
                     a2_local_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S2>/PACING_REF_PWM D5' */
  MW_PWM_SetDutyCycle(a2_local_DW.obj_p4.MW_PWM_HANDLE,
                      a2_local_B.PACING_REF_PWM);

  /* MATLABSystem: '<S2>/Z_VENT_CTRL D7' */
  MW_digitalIO_write(a2_local_DW.obj_m.MW_DIGITALIO_HANDLE,
                     a2_local_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S2>/VENT_PACE_CTRL D9  ' */
  MW_digitalIO_write(a2_local_DW.obj_k.MW_DIGITALIO_HANDLE,
                     a2_local_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S2>/PACE_GND_CTRL D10' */
  MW_digitalIO_write(a2_local_DW.obj_d.MW_DIGITALIO_HANDLE,
                     a2_local_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S2>/VENT_GND_CTRL D12' */
  MW_digitalIO_write(a2_local_DW.obj_e.MW_DIGITALIO_HANDLE,
                     a2_local_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S2>/Z_ATR_CTRL D4' */
  MW_digitalIO_write(a2_local_DW.obj_mn.MW_DIGITALIO_HANDLE,
                     a2_local_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S2>/PACE_CHARGE_CTRL D2' */
  MW_digitalIO_write(a2_local_DW.obj_h.MW_DIGITALIO_HANDLE,
                     a2_local_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S1>/Digital Write' */
  MW_digitalIO_write(a2_local_DW.obj_kr.MW_DIGITALIO_HANDLE,
                     a2_local_B.RelationalOperator);

  /* MATLABSystem: '<S1>/Digital Write1' */
  MW_digitalIO_write(a2_local_DW.obj_ay.MW_DIGITALIO_HANDLE,
                     a2_local_B.RelationalOperator);

  /* Switch: '<S7>/Switch' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   */
  if (a2_local_B.mode >= a2_local_P.Switch_Threshold_l) {
    tmp = a2_local_P.Constant_Value_p;
  } else {
    tmp = a2_local_P.Constant1_Value_o;
  }

  /* End of Switch: '<S7>/Switch' */

  /* MATLABSystem: '<S2>/FRONTEND_CTRL D13' */
  MW_digitalIO_write(a2_local_DW.obj_a.MW_DIGITALIO_HANDLE, tmp != 0.0);

  /* MATLABSystem: '<S2>/ATR_CMP_REF_PWM D6' incorporates:
   *  Constant: '<S1>/Atrial threshold(volt)'
   *  Constant: '<S1>/Voltage'
   *  Gain: '<S9>/Gain'
   *  Product: '<S9>/Divide'
   */
  MW_PWM_SetDutyCycle(a2_local_DW.obj_g.MW_PWM_HANDLE, a2_local_P.Gain_Gain_n *
                      (a2_local_P.Atrialthresholdvolt_Value /
                       a2_local_P.Voltage_Value));

  /* MATLABSystem: '<S2>/VENT_CMP_REF_PWM D3' incorporates:
   *  Constant: '<S1>/Ventricle threshold(volt)'
   *  Constant: '<S1>/Voltage'
   *  Gain: '<S9>/Gain1'
   *  Product: '<S9>/Divide1'
   */
  MW_PWM_SetDutyCycle(a2_local_DW.obj_ki.MW_PWM_HANDLE, a2_local_P.Gain1_Gain_p *
                      (a2_local_P.Ventriclethresholdvolt_Value /
                       a2_local_P.Voltage_Value));

  /* Update for Memory: '<S3>/Memory' */
  a2_local_DW.Memory_PreviousInput = a2_local_B.time_response;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, (real_T)a2_local_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(a2_local_M)!=-1) &&
        !((rtmGetTFinal(a2_local_M)-a2_local_M->Timing.taskTime0) >
          a2_local_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(a2_local_M, "Simulation finished");
    }

    if (rtmGetStopRequested(a2_local_M)) {
      rtmSetErrorStatus(a2_local_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  a2_local_M->Timing.taskTime0 =
    ((time_T)(++a2_local_M->Timing.clockTick0)) * a2_local_M->Timing.stepSize0;
}

/* Model initialize function */
void a2_local_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(a2_local_M, -1);
  a2_local_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  a2_local_M->Sizes.checksums[0] = (1536935259U);
  a2_local_M->Sizes.checksums[1] = (811435545U);
  a2_local_M->Sizes.checksums[2] = (1227525428U);
  a2_local_M->Sizes.checksums[3] = (1513025184U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[25];
    a2_local_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&a2_local_DW.calculateacceleration3D_SubsysR;
    systemRan[4] = (sysRanDType *)&a2_local_DW.calculateacceleration3D_SubsysR;
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
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(a2_local_M->extModeInfo,
      &a2_local_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(a2_local_M->extModeInfo, a2_local_M->Sizes.checksums);
    rteiSetTPtr(a2_local_M->extModeInfo, rtmGetTPtr(a2_local_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    a2_local_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    freedomk64f_DigitalRead_a2_lo_T *obj;
    freedomk64f_DigitalWrite_a2_l_T *obj_0;
    freedomk64f_PWMOutput_a2_loca_T *obj_1;

    /* Start for Constant: '<S1>/mode' */
    a2_local_B.mode = a2_local_P.mode_Value;

    /* Start for Constant: '<S1>/ARP msec' */
    a2_local_B.ARPmsec = a2_local_P.ARPmsec_Value;

    /* Start for Constant: '<S1>/Atrial Pluse Width msec' */
    a2_local_B.AtrialPluseWidthmsec = a2_local_P.AtrialPluseWidthmsec_Value;

    /* Start for Constant: '<S1>/VRP msec' */
    a2_local_B.VRPmsec = a2_local_P.VRPmsec_Value;

    /* Start for Constant: '<S1>/Ventricular Pluse Width msec' */
    a2_local_B.VentricularPluseWidthmsec =
      a2_local_P.VentricularPluseWidthmsec_Value;

    /* InitializeConditions for Memory: '<S3>/Memory' */
    a2_local_DW.Memory_PreviousInput = a2_local_P.Memory_InitialCondition;

    /* Start for MATLABSystem: '<S5>/FXOS8700 6-Axes Sensor' */
    a2_local_DW.obj.isInitialized = 0;
    a2_local_DW.obj.i2cobj.isInitialized = 0;
    a2_local_DW.obj.i2cobj.matlabCodegenIsDeleted = false;
    a2_local_DW.obj.matlabCodegenIsDeleted = false;
    a2_local_DW.obj.SampleTime = a2_local_P.FXOS87006AxesSensor_SampleTime;
    a2_local_SystemCore_setup(&a2_local_DW.obj);

    /* SystemInitialize for Sum: '<S5>/Add' incorporates:
     *  Outport: '<S5>/Out1'
     */
    a2_local_B.Add = a2_local_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S1>/calculate acceleration(3D)' */

    /* Start for MATLABSystem: '<S3>/ATR_CMP_DETECT D0' */
    a2_local_DW.obj_f.matlabCodegenIsDeleted = true;
    a2_local_DW.obj_f.isInitialized = 0;
    a2_local_DW.obj_f.SampleTime = -1.0;
    a2_local_DW.obj_f.matlabCodegenIsDeleted = false;
    a2_local_DW.obj_f.SampleTime = a2_local_P.ATR_CMP_DETECTD0_SampleTime;
    obj = &a2_local_DW.obj_f;
    a2_local_DW.obj_f.isSetupComplete = false;
    a2_local_DW.obj_f.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    a2_local_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_CMP_DETECT D1' */
    a2_local_DW.obj_i.matlabCodegenIsDeleted = true;
    a2_local_DW.obj_i.isInitialized = 0;
    a2_local_DW.obj_i.SampleTime = -1.0;
    a2_local_DW.obj_i.matlabCodegenIsDeleted = false;
    a2_local_DW.obj_i.SampleTime = a2_local_P.VENT_CMP_DETECTD1_SampleTime;
    obj = &a2_local_DW.obj_i;
    a2_local_DW.obj_i.isSetupComplete = false;
    a2_local_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    a2_local_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/ATR_GND_CTRL D11' */
    a2_local_DW.obj_o.matlabCodegenIsDeleted = true;
    a2_local_DW.obj_o.isInitialized = 0;
    a2_local_DW.obj_o.matlabCodegenIsDeleted = false;
    obj_0 = &a2_local_DW.obj_o;
    a2_local_DW.obj_o.isSetupComplete = false;
    a2_local_DW.obj_o.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    a2_local_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/ATR_PACE_CTRL D8' */
    a2_local_DW.obj_p.matlabCodegenIsDeleted = true;
    a2_local_DW.obj_p.isInitialized = 0;
    a2_local_DW.obj_p.matlabCodegenIsDeleted = false;
    obj_0 = &a2_local_DW.obj_p;
    a2_local_DW.obj_p.isSetupComplete = false;
    a2_local_DW.obj_p.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    a2_local_DW.obj_p.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PACING_REF_PWM D5' */
    a2_local_DW.obj_p4.matlabCodegenIsDeleted = true;
    a2_local_DW.obj_p4.isInitialized = 0;
    a2_local_DW.obj_p4.matlabCodegenIsDeleted = false;
    obj_1 = &a2_local_DW.obj_p4;
    a2_local_DW.obj_p4.isSetupComplete = false;
    a2_local_DW.obj_p4.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(a2_local_DW.obj_p4.MW_PWM_HANDLE);
    a2_local_DW.obj_p4.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Z_VENT_CTRL D7' */
    a2_local_DW.obj_m.matlabCodegenIsDeleted = true;
    a2_local_DW.obj_m.isInitialized = 0;
    a2_local_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_0 = &a2_local_DW.obj_m;
    a2_local_DW.obj_m.isSetupComplete = false;
    a2_local_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    a2_local_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/VENT_PACE_CTRL D9  ' */
    a2_local_DW.obj_k.matlabCodegenIsDeleted = true;
    a2_local_DW.obj_k.isInitialized = 0;
    a2_local_DW.obj_k.matlabCodegenIsDeleted = false;
    obj_0 = &a2_local_DW.obj_k;
    a2_local_DW.obj_k.isSetupComplete = false;
    a2_local_DW.obj_k.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    a2_local_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PACE_GND_CTRL D10' */
    a2_local_DW.obj_d.matlabCodegenIsDeleted = true;
    a2_local_DW.obj_d.isInitialized = 0;
    a2_local_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_0 = &a2_local_DW.obj_d;
    a2_local_DW.obj_d.isSetupComplete = false;
    a2_local_DW.obj_d.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    a2_local_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/VENT_GND_CTRL D12' */
    a2_local_DW.obj_e.matlabCodegenIsDeleted = true;
    a2_local_DW.obj_e.isInitialized = 0;
    a2_local_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &a2_local_DW.obj_e;
    a2_local_DW.obj_e.isSetupComplete = false;
    a2_local_DW.obj_e.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    a2_local_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/Z_ATR_CTRL D4' */
    a2_local_DW.obj_mn.matlabCodegenIsDeleted = true;
    a2_local_DW.obj_mn.isInitialized = 0;
    a2_local_DW.obj_mn.matlabCodegenIsDeleted = false;
    obj_0 = &a2_local_DW.obj_mn;
    a2_local_DW.obj_mn.isSetupComplete = false;
    a2_local_DW.obj_mn.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    a2_local_DW.obj_mn.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/PACE_CHARGE_CTRL D2' */
    a2_local_DW.obj_h.matlabCodegenIsDeleted = true;
    a2_local_DW.obj_h.isInitialized = 0;
    a2_local_DW.obj_h.matlabCodegenIsDeleted = false;
    obj_0 = &a2_local_DW.obj_h;
    a2_local_DW.obj_h.isSetupComplete = false;
    a2_local_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    a2_local_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write' */
    a2_local_DW.obj_kr.matlabCodegenIsDeleted = true;
    a2_local_DW.obj_kr.isInitialized = 0;
    a2_local_DW.obj_kr.matlabCodegenIsDeleted = false;
    obj_0 = &a2_local_DW.obj_kr;
    a2_local_DW.obj_kr.isSetupComplete = false;
    a2_local_DW.obj_kr.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    a2_local_DW.obj_kr.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Write1' */
    a2_local_DW.obj_ay.matlabCodegenIsDeleted = true;
    a2_local_DW.obj_ay.isInitialized = 0;
    a2_local_DW.obj_ay.matlabCodegenIsDeleted = false;
    obj_0 = &a2_local_DW.obj_ay;
    a2_local_DW.obj_ay.isSetupComplete = false;
    a2_local_DW.obj_ay.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    a2_local_DW.obj_ay.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/FRONTEND_CTRL D13' */
    a2_local_DW.obj_a.matlabCodegenIsDeleted = true;
    a2_local_DW.obj_a.isInitialized = 0;
    a2_local_DW.obj_a.matlabCodegenIsDeleted = false;
    obj_0 = &a2_local_DW.obj_a;
    a2_local_DW.obj_a.isSetupComplete = false;
    a2_local_DW.obj_a.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    a2_local_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/ATR_CMP_REF_PWM D6' */
    a2_local_DW.obj_g.matlabCodegenIsDeleted = true;
    a2_local_DW.obj_g.isInitialized = 0;
    a2_local_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_1 = &a2_local_DW.obj_g;
    a2_local_DW.obj_g.isSetupComplete = false;
    a2_local_DW.obj_g.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(a2_local_DW.obj_g.MW_PWM_HANDLE);
    a2_local_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/VENT_CMP_REF_PWM D3' */
    a2_local_DW.obj_ki.matlabCodegenIsDeleted = true;
    a2_local_DW.obj_ki.isInitialized = 0;
    a2_local_DW.obj_ki.matlabCodegenIsDeleted = false;
    obj_1 = &a2_local_DW.obj_ki;
    a2_local_DW.obj_ki.isSetupComplete = false;
    a2_local_DW.obj_ki.isInitialized = 1;
    obj_1->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(a2_local_DW.obj_ki.MW_PWM_HANDLE);
    a2_local_DW.obj_ki.isSetupComplete = true;
  }
}

/* Model terminate function */
void a2_local_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj;

  /* Terminate for Enabled SubSystem: '<S1>/calculate acceleration(3D)' */
  /* Terminate for MATLABSystem: '<S5>/FXOS8700 6-Axes Sensor' */
  if (!a2_local_DW.obj.matlabCodegenIsDeleted) {
    a2_local_DW.obj.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj.isInitialized == 1) && a2_local_DW.obj.isSetupComplete)
    {
      MW_I2C_Close(a2_local_DW.obj.i2cobj.MW_I2C_HANDLE);
    }
  }

  obj = &a2_local_DW.obj.i2cobj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/FXOS8700 6-Axes Sensor' */
  /* End of Terminate for SubSystem: '<S1>/calculate acceleration(3D)' */

  /* Terminate for MATLABSystem: '<S3>/ATR_CMP_DETECT D0' */
  if (!a2_local_DW.obj_f.matlabCodegenIsDeleted) {
    a2_local_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj_f.isInitialized == 1) &&
        a2_local_DW.obj_f.isSetupComplete) {
      MW_digitalIO_close(a2_local_DW.obj_f.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/ATR_CMP_DETECT D0' */

  /* Terminate for MATLABSystem: '<S3>/VENT_CMP_DETECT D1' */
  if (!a2_local_DW.obj_i.matlabCodegenIsDeleted) {
    a2_local_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj_i.isInitialized == 1) &&
        a2_local_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(a2_local_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/VENT_CMP_DETECT D1' */

  /* Terminate for MATLABSystem: '<S2>/ATR_GND_CTRL D11' */
  if (!a2_local_DW.obj_o.matlabCodegenIsDeleted) {
    a2_local_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj_o.isInitialized == 1) &&
        a2_local_DW.obj_o.isSetupComplete) {
      MW_digitalIO_close(a2_local_DW.obj_o.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ATR_GND_CTRL D11' */

  /* Terminate for MATLABSystem: '<S2>/ATR_PACE_CTRL D8' */
  if (!a2_local_DW.obj_p.matlabCodegenIsDeleted) {
    a2_local_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj_p.isInitialized == 1) &&
        a2_local_DW.obj_p.isSetupComplete) {
      MW_digitalIO_close(a2_local_DW.obj_p.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ATR_PACE_CTRL D8' */

  /* Terminate for MATLABSystem: '<S2>/PACING_REF_PWM D5' */
  if (!a2_local_DW.obj_p4.matlabCodegenIsDeleted) {
    a2_local_DW.obj_p4.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj_p4.isInitialized == 1) &&
        a2_local_DW.obj_p4.isSetupComplete) {
      MW_PWM_Stop(a2_local_DW.obj_p4.MW_PWM_HANDLE);
      MW_PWM_Close(a2_local_DW.obj_p4.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PACING_REF_PWM D5' */

  /* Terminate for MATLABSystem: '<S2>/Z_VENT_CTRL D7' */
  if (!a2_local_DW.obj_m.matlabCodegenIsDeleted) {
    a2_local_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj_m.isInitialized == 1) &&
        a2_local_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(a2_local_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Z_VENT_CTRL D7' */

  /* Terminate for MATLABSystem: '<S2>/VENT_PACE_CTRL D9  ' */
  if (!a2_local_DW.obj_k.matlabCodegenIsDeleted) {
    a2_local_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj_k.isInitialized == 1) &&
        a2_local_DW.obj_k.isSetupComplete) {
      MW_digitalIO_close(a2_local_DW.obj_k.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/VENT_PACE_CTRL D9  ' */

  /* Terminate for MATLABSystem: '<S2>/PACE_GND_CTRL D10' */
  if (!a2_local_DW.obj_d.matlabCodegenIsDeleted) {
    a2_local_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj_d.isInitialized == 1) &&
        a2_local_DW.obj_d.isSetupComplete) {
      MW_digitalIO_close(a2_local_DW.obj_d.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PACE_GND_CTRL D10' */

  /* Terminate for MATLABSystem: '<S2>/VENT_GND_CTRL D12' */
  if (!a2_local_DW.obj_e.matlabCodegenIsDeleted) {
    a2_local_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj_e.isInitialized == 1) &&
        a2_local_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(a2_local_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/VENT_GND_CTRL D12' */

  /* Terminate for MATLABSystem: '<S2>/Z_ATR_CTRL D4' */
  if (!a2_local_DW.obj_mn.matlabCodegenIsDeleted) {
    a2_local_DW.obj_mn.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj_mn.isInitialized == 1) &&
        a2_local_DW.obj_mn.isSetupComplete) {
      MW_digitalIO_close(a2_local_DW.obj_mn.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Z_ATR_CTRL D4' */

  /* Terminate for MATLABSystem: '<S2>/PACE_CHARGE_CTRL D2' */
  if (!a2_local_DW.obj_h.matlabCodegenIsDeleted) {
    a2_local_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj_h.isInitialized == 1) &&
        a2_local_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(a2_local_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/PACE_CHARGE_CTRL D2' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write' */
  if (!a2_local_DW.obj_kr.matlabCodegenIsDeleted) {
    a2_local_DW.obj_kr.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj_kr.isInitialized == 1) &&
        a2_local_DW.obj_kr.isSetupComplete) {
      MW_digitalIO_close(a2_local_DW.obj_kr.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write' */

  /* Terminate for MATLABSystem: '<S1>/Digital Write1' */
  if (!a2_local_DW.obj_ay.matlabCodegenIsDeleted) {
    a2_local_DW.obj_ay.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj_ay.isInitialized == 1) &&
        a2_local_DW.obj_ay.isSetupComplete) {
      MW_digitalIO_close(a2_local_DW.obj_ay.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S2>/FRONTEND_CTRL D13' */
  if (!a2_local_DW.obj_a.matlabCodegenIsDeleted) {
    a2_local_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj_a.isInitialized == 1) &&
        a2_local_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(a2_local_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/FRONTEND_CTRL D13' */

  /* Terminate for MATLABSystem: '<S2>/ATR_CMP_REF_PWM D6' */
  if (!a2_local_DW.obj_g.matlabCodegenIsDeleted) {
    a2_local_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj_g.isInitialized == 1) &&
        a2_local_DW.obj_g.isSetupComplete) {
      MW_PWM_Stop(a2_local_DW.obj_g.MW_PWM_HANDLE);
      MW_PWM_Close(a2_local_DW.obj_g.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ATR_CMP_REF_PWM D6' */

  /* Terminate for MATLABSystem: '<S2>/VENT_CMP_REF_PWM D3' */
  if (!a2_local_DW.obj_ki.matlabCodegenIsDeleted) {
    a2_local_DW.obj_ki.matlabCodegenIsDeleted = true;
    if ((a2_local_DW.obj_ki.isInitialized == 1) &&
        a2_local_DW.obj_ki.isSetupComplete) {
      MW_PWM_Stop(a2_local_DW.obj_ki.MW_PWM_HANDLE);
      MW_PWM_Close(a2_local_DW.obj_ki.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/VENT_CMP_REF_PWM D3' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
