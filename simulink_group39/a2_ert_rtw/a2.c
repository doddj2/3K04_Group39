/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a2.c
 *
 * Code generated for Simulink model 'a2'.
 *
 * Model version                  : 3.3
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Nov 26 14:52:51 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "a2.h"
#include "a2_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include "rt_roundd_snf.h"
#include <stddef.h>
#include "DCM_SEND.h"
#include "DCM_SEND_private.h"

/* Named constants for Chart: '<S2>/From DCM' */
#define a2_IN_Default                  ((uint8_T)1U)
#define a2_IN_ECHO_PARAM               ((uint8_T)2U)
#define a2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define a2_IN_SET_PARAM                ((uint8_T)3U)
#define a2_IN_STANDBY                  ((uint8_T)4U)

/* Named constants for Chart: '<S3>/4 Modes' */
#define a2_HIGH                        (true)
#define a2_IN_AAI                      ((uint8_T)1U)
#define a2_IN_AAIR                     ((uint8_T)2U)
#define a2_IN_AOO                      ((uint8_T)3U)
#define a2_IN_AOOR                     ((uint8_T)4U)
#define a2_IN_ARP_Period               ((uint8_T)1U)
#define a2_IN_Alert_Period             ((uint8_T)1U)
#define a2_IN_Alert_Period_h           ((uint8_T)2U)
#define a2_IN_Charging                 ((uint8_T)1U)
#define a2_IN_Charging1                ((uint8_T)2U)
#define a2_IN_Charging_j               ((uint8_T)2U)
#define a2_IN_Charging_jb              ((uint8_T)3U)
#define a2_IN_Pacing                   ((uint8_T)2U)
#define a2_IN_Pacing_o                 ((uint8_T)3U)
#define a2_IN_Pacing_ob                ((uint8_T)4U)
#define a2_IN_Start                    ((uint8_T)5U)
#define a2_IN_VOO                      ((uint8_T)6U)
#define a2_IN_VOOR                     ((uint8_T)7U)
#define a2_IN_VRP_Period               ((uint8_T)4U)
#define a2_IN_VVI                      ((uint8_T)8U)
#define a2_IN_VVIR                     ((uint8_T)9U)
#define a2_LOW                         (false)

/* Block signals (default storage) */
B_a2_T a2_B;

/* Block states (default storage) */
DW_a2_T a2_DW;

/* Real-time model */
static RT_MODEL_a2_T a2_M_;
RT_MODEL_a2_T *const a2_M = &a2_M_;

/* Forward declaration for local functions */
static int16_T a2_bitshift_anonFcn1(int16_T a1, real_T k1);
static void a2_enter_atomic_Charging_nltu(const real_T *Gain1);
static void a2_VVIR(const uint16_T *time_response, const boolean_T
                    *VENT_CMP_DETECTD1, const real_T *Gain1);
static void a2_enter_atomic_Charging(const real_T *Gain);
static void a2_AAIR(const uint16_T *time_response, const boolean_T
                    *ATR_CMP_DETECTD0, const real_T *Gain);
static void a2_Start(const real_T *Gain1, const real_T *Gain);
static void a2_VVI(const real_T *Divide2, const boolean_T *VENT_CMP_DETECTD1,
                   const real_T *Gain1);
static void a2_SystemCore_setup_j0(freedomk64f_fxos8700_a2_T *obj);
static void a2_SystemCore_setup_j(freedomk64f_SCIRead_a2_T *obj);
static int16_T a2_bitshift_anonFcn1(int16_T a1, real_T k1)
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
static void a2_enter_atomic_Charging_nltu(const real_T *Gain1)
{
  a2_B.PACING_REF_PWM = *Gain1;
  a2_B.PACE_CHARGE_CTRL = a2_HIGH;
  a2_B.PACE_GND_CTRL = a2_HIGH;
  a2_B.VENT_PACE_CTRL = a2_LOW;
  a2_B.Z_ATR_CTRL = a2_LOW;
  a2_B.Z_VENT_CTRL = a2_LOW;
  a2_B.ATR_PACE_CTRL = a2_LOW;
  a2_B.ATR_GND_CTRL = a2_LOW;
  a2_B.VENT_GND_CTRL = a2_HIGH;
}

/* Function for Chart: '<S3>/4 Modes' */
static void a2_VVIR(const uint16_T *time_response, const boolean_T
                    *VENT_CMP_DETECTD1, const real_T *Gain1)
{
  int32_T q0;
  uint32_T qY;
  uint32_T qY_0;
  switch (a2_DW.is_VVIR) {
   case a2_IN_Alert_Period:
    if (*VENT_CMP_DETECTD1) {
      a2_DW.is_VVIR = a2_IN_VRP_Period;
      a2_DW.temporalCounter_i1 = 0U;
    } else {
      q0 = (int32_T)rt_roundd_snf(0.5 * (real_T)*time_response);
      qY_0 = (uint32_T)q0 - /*MW:OvSatOk*/ a2_B.vent_pulse_width_h;
      if (qY_0 > (uint32_T)q0) {
        qY_0 = 0U;
      }

      qY = qY_0 - /*MW:OvSatOk*/ a2_B.VRP_j;
      if (qY > qY_0) {
        qY = 0U;
      }

      if (a2_DW.temporalCounter_i1 >= qY) {
        a2_DW.is_VVIR = a2_IN_Pacing_o;
        a2_DW.temporalCounter_i1 = 0U;
        a2_B.PACE_CHARGE_CTRL = a2_LOW;
        a2_B.PACE_GND_CTRL = a2_HIGH;
        a2_B.ATR_PACE_CTRL = a2_LOW;
        a2_B.ATR_GND_CTRL = a2_LOW;
        a2_B.Z_ATR_CTRL = a2_LOW;
        a2_B.Z_VENT_CTRL = a2_LOW;
        a2_B.VENT_GND_CTRL = a2_LOW;
        a2_B.VENT_PACE_CTRL = a2_HIGH;
      }
    }
    break;

   case a2_IN_Charging_j:
    a2_B.PACE_CHARGE_CTRL = a2_HIGH;
    a2_B.PACE_GND_CTRL = a2_HIGH;
    a2_B.Z_ATR_CTRL = a2_LOW;
    a2_B.Z_VENT_CTRL = a2_LOW;
    a2_B.ATR_GND_CTRL = a2_LOW;
    a2_B.VENT_GND_CTRL = a2_HIGH;
    if (a2_DW.temporalCounter_i1 >= a2_B.VRP_j) {
      a2_DW.is_VVIR = a2_IN_Alert_Period;
      a2_DW.temporalCounter_i1 = 0U;
    } else if (a2_B.mode_f != 6) {
      a2_DW.is_VVIR = a2_IN_NO_ACTIVE_CHILD;
      a2_DW.is_c4_a2 = a2_IN_Start;
    }
    break;

   case a2_IN_Pacing_o:
    a2_B.PACE_CHARGE_CTRL = a2_LOW;
    a2_B.PACE_GND_CTRL = a2_HIGH;
    a2_B.ATR_GND_CTRL = a2_LOW;
    a2_B.Z_ATR_CTRL = a2_LOW;
    a2_B.Z_VENT_CTRL = a2_LOW;
    a2_B.VENT_GND_CTRL = a2_LOW;
    if (a2_DW.temporalCounter_i1 >= a2_B.vent_pulse_width_h) {
      a2_DW.is_VVIR = a2_IN_Charging_j;
      a2_DW.temporalCounter_i1 = 0U;
      a2_enter_atomic_Charging_nltu(Gain1);
    }
    break;

   default:
    /* case IN_VRP_Period: */
    if (a2_DW.temporalCounter_i1 >= a2_B.VRP_j) {
      a2_DW.is_VVIR = a2_IN_Alert_Period;
      a2_DW.temporalCounter_i1 = 0U;
    }
    break;
  }
}

/* Function for Chart: '<S3>/4 Modes' */
static void a2_enter_atomic_Charging(const real_T *Gain)
{
  a2_B.PACING_REF_PWM = *Gain;
  a2_B.PACE_CHARGE_CTRL = a2_HIGH;
  a2_B.PACE_GND_CTRL = a2_HIGH;
  a2_B.VENT_PACE_CTRL = a2_LOW;
  a2_B.Z_ATR_CTRL = a2_LOW;
  a2_B.Z_VENT_CTRL = a2_LOW;
  a2_B.ATR_PACE_CTRL = a2_LOW;
  a2_B.ATR_GND_CTRL = a2_HIGH;
  a2_B.VENT_GND_CTRL = a2_LOW;
}

/* Function for Chart: '<S3>/4 Modes' */
static void a2_AAIR(const uint16_T *time_response, const boolean_T
                    *ATR_CMP_DETECTD0, const real_T *Gain)
{
  int32_T q0;
  uint32_T qY;
  uint32_T qY_0;
  switch (a2_DW.is_AAIR) {
   case a2_IN_ARP_Period:
    if (a2_DW.temporalCounter_i1 >= a2_B.ARP_c) {
      a2_DW.is_AAIR = a2_IN_Alert_Period_h;
      a2_DW.temporalCounter_i1 = 0U;
    }
    break;

   case a2_IN_Alert_Period_h:
    if (*ATR_CMP_DETECTD0) {
      a2_DW.is_AAIR = a2_IN_ARP_Period;
      a2_DW.temporalCounter_i1 = 0U;
    } else {
      q0 = (int32_T)rt_roundd_snf(0.5 * (real_T)*time_response);
      qY_0 = (uint32_T)q0 - /*MW:OvSatOk*/ a2_B.atr_pulse_width_f;
      if (qY_0 > (uint32_T)q0) {
        qY_0 = 0U;
      }

      qY = qY_0 - /*MW:OvSatOk*/ a2_B.ARP_c;
      if (qY > qY_0) {
        qY = 0U;
      }

      if (a2_DW.temporalCounter_i1 >= qY) {
        a2_DW.is_AAIR = a2_IN_Pacing_ob;
        a2_DW.temporalCounter_i1 = 0U;
        a2_B.PACE_CHARGE_CTRL = a2_LOW;
        a2_B.PACE_GND_CTRL = a2_HIGH;
        a2_B.ATR_PACE_CTRL = a2_HIGH;
        a2_B.ATR_GND_CTRL = a2_LOW;
        a2_B.Z_ATR_CTRL = a2_LOW;
        a2_B.Z_VENT_CTRL = a2_LOW;
        a2_B.VENT_GND_CTRL = a2_LOW;
        a2_B.VENT_PACE_CTRL = a2_LOW;
      }
    }
    break;

   case a2_IN_Charging_jb:
    a2_B.PACE_CHARGE_CTRL = a2_HIGH;
    a2_B.PACE_GND_CTRL = a2_HIGH;
    a2_B.Z_ATR_CTRL = a2_LOW;
    a2_B.Z_VENT_CTRL = a2_LOW;
    a2_B.ATR_GND_CTRL = a2_HIGH;
    a2_B.VENT_GND_CTRL = a2_LOW;
    if (a2_DW.temporalCounter_i1 >= a2_B.ARP_c) {
      a2_DW.is_AAIR = a2_IN_Alert_Period_h;
      a2_DW.temporalCounter_i1 = 0U;
    } else if (a2_B.mode_f != 7) {
      a2_DW.is_AAIR = a2_IN_NO_ACTIVE_CHILD;
      a2_DW.is_c4_a2 = a2_IN_Start;
    }
    break;

   default:
    /* case IN_Pacing: */
    a2_B.PACE_CHARGE_CTRL = a2_LOW;
    a2_B.PACE_GND_CTRL = a2_HIGH;
    a2_B.ATR_GND_CTRL = a2_LOW;
    a2_B.Z_ATR_CTRL = a2_LOW;
    a2_B.Z_VENT_CTRL = a2_LOW;
    a2_B.VENT_GND_CTRL = a2_LOW;
    if (a2_DW.temporalCounter_i1 >= a2_B.atr_pulse_width_f) {
      a2_DW.is_AAIR = a2_IN_Charging_jb;
      a2_DW.temporalCounter_i1 = 0U;
      a2_enter_atomic_Charging(Gain);
    }
    break;
  }
}

/* Function for Chart: '<S3>/4 Modes' */
static void a2_Start(const real_T *Gain1, const real_T *Gain)
{
  switch (a2_B.mode_f) {
   case 4:
    a2_DW.is_c4_a2 = a2_IN_VOOR;
    a2_DW.is_VOOR = a2_IN_Charging;
    a2_DW.temporalCounter_i1 = 0U;
    a2_enter_atomic_Charging_nltu(Gain1);
    break;

   case 0:
    a2_DW.is_c4_a2 = a2_IN_VOO;
    a2_DW.is_VOO = a2_IN_Charging;
    a2_DW.temporalCounter_i1 = 0U;
    a2_enter_atomic_Charging_nltu(Gain1);
    break;

   case 5:
    a2_DW.is_c4_a2 = a2_IN_AOOR;
    a2_DW.is_AOOR = a2_IN_Charging;
    a2_DW.temporalCounter_i1 = 0U;
    a2_enter_atomic_Charging(Gain);
    break;

   case 1:
    a2_DW.is_c4_a2 = a2_IN_AOO;
    a2_DW.is_AOO = a2_IN_Charging;
    a2_DW.temporalCounter_i1 = 0U;
    a2_enter_atomic_Charging(Gain);
    break;

   case 2:
    a2_DW.is_c4_a2 = a2_IN_VVI;
    a2_DW.is_VVI = a2_IN_Charging1;
    a2_DW.temporalCounter_i1 = 0U;
    a2_enter_atomic_Charging_nltu(Gain1);
    break;

   case 6:
    a2_DW.is_c4_a2 = a2_IN_VVIR;
    a2_DW.is_VVIR = a2_IN_Charging_j;
    a2_DW.temporalCounter_i1 = 0U;
    a2_enter_atomic_Charging_nltu(Gain1);
    break;

   case 3:
    a2_DW.is_c4_a2 = a2_IN_AAI;
    a2_DW.is_AAI = a2_IN_Charging_jb;
    a2_DW.temporalCounter_i1 = 0U;
    a2_enter_atomic_Charging(Gain);
    break;

   case 7:
    a2_DW.is_c4_a2 = a2_IN_AAIR;
    a2_DW.is_AAIR = a2_IN_Charging_jb;
    a2_DW.temporalCounter_i1 = 0U;
    a2_enter_atomic_Charging(Gain);
    break;
  }
}

/* Function for Chart: '<S3>/4 Modes' */
static void a2_VVI(const real_T *Divide2, const boolean_T *VENT_CMP_DETECTD1,
                   const real_T *Gain1)
{
  real_T tmp;
  uint16_T tmp_0;
  switch (a2_DW.is_VVI) {
   case a2_IN_Alert_Period:
    if (*VENT_CMP_DETECTD1) {
      a2_DW.is_VVI = a2_IN_VRP_Period;
      a2_DW.temporalCounter_i1 = 0U;
    } else {
      tmp = rt_roundd_snf(*Divide2 - (real_T)a2_B.VRP_j);
      if (tmp < 65536.0) {
        if (tmp >= 0.0) {
          tmp_0 = (uint16_T)tmp;
        } else {
          tmp_0 = 0U;
        }
      } else {
        tmp_0 = MAX_uint16_T;
      }

      if (a2_DW.temporalCounter_i1 >= tmp_0) {
        a2_DW.is_VVI = a2_IN_Pacing_o;
        a2_DW.temporalCounter_i1 = 0U;
        a2_B.PACE_CHARGE_CTRL = a2_LOW;
        a2_B.PACE_GND_CTRL = a2_HIGH;
        a2_B.ATR_PACE_CTRL = a2_LOW;
        a2_B.ATR_GND_CTRL = a2_LOW;
        a2_B.Z_ATR_CTRL = a2_LOW;
        a2_B.Z_VENT_CTRL = a2_LOW;
        a2_B.VENT_GND_CTRL = a2_LOW;
        a2_B.VENT_PACE_CTRL = a2_HIGH;
      }
    }
    break;

   case a2_IN_Charging1:
    a2_B.PACE_CHARGE_CTRL = a2_HIGH;
    a2_B.PACE_GND_CTRL = a2_HIGH;
    a2_B.Z_ATR_CTRL = a2_LOW;
    a2_B.Z_VENT_CTRL = a2_LOW;
    a2_B.ATR_GND_CTRL = a2_LOW;
    a2_B.VENT_GND_CTRL = a2_HIGH;
    if (a2_DW.temporalCounter_i1 >= a2_B.VRP_j) {
      a2_DW.is_VVI = a2_IN_Alert_Period;
      a2_DW.temporalCounter_i1 = 0U;
    } else if (a2_B.mode_f != 2) {
      a2_DW.is_VVI = a2_IN_NO_ACTIVE_CHILD;
      a2_DW.is_c4_a2 = a2_IN_Start;
    }
    break;

   case a2_IN_Pacing_o:
    a2_B.PACE_CHARGE_CTRL = a2_LOW;
    a2_B.PACE_GND_CTRL = a2_HIGH;
    a2_B.ATR_GND_CTRL = a2_LOW;
    a2_B.Z_ATR_CTRL = a2_LOW;
    a2_B.Z_VENT_CTRL = a2_LOW;
    a2_B.VENT_GND_CTRL = a2_LOW;
    if (a2_DW.temporalCounter_i1 >= a2_B.vent_pulse_width_h) {
      a2_DW.is_VVI = a2_IN_Charging1;
      a2_DW.temporalCounter_i1 = 0U;
      a2_enter_atomic_Charging_nltu(Gain1);
    }
    break;

   default:
    /* case IN_VRP_Period: */
    if (a2_DW.temporalCounter_i1 >= a2_B.VRP_j) {
      a2_DW.is_VVI = a2_IN_Alert_Period;
      a2_DW.temporalCounter_i1 = 0U;
    }
    break;
  }
}

static void a2_SystemCore_setup_j0(freedomk64f_fxos8700_a2_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  a2_B.ModeType = MW_I2C_MASTER;
  a2_B.i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(a2_B.i2cname, a2_B.ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  a2_B.b_SwappedDataBytes[0] = 43U;
  a2_B.b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &a2_B.b_SwappedDataBytes[0],
                     2U, false, false);
  OSA_TimeDelay(500U);
  a2_B.status = 42U;
  a2_B.status = MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &a2_B.status,
    1U, true, false);
  if (a2_B.status == 0) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U, &a2_B.status, 1U, false,
                      true);
    memcpy((void *)&a2_B.b_RegisterValue, (void *)&a2_B.status, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
  } else {
    a2_B.b_RegisterValue = 0U;
  }

  a2_B.b_SwappedDataBytes[0] = 42U;
  a2_B.b_SwappedDataBytes[1] = (uint8_T)(a2_B.b_RegisterValue & 254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &a2_B.b_SwappedDataBytes[0],
                     2U, false, false);
  a2_B.b_SwappedDataBytes[0] = 14U;
  a2_B.b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &a2_B.b_SwappedDataBytes[0],
                     2U, false, false);
  a2_B.b_SwappedDataBytes[0] = 91U;
  a2_B.b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &a2_B.b_SwappedDataBytes[0],
                     2U, false, false);
  a2_B.b_SwappedDataBytes[0] = 42U;
  a2_B.b_SwappedDataBytes[1] = 25U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &a2_B.b_SwappedDataBytes[0],
                     2U, false, false);
  obj->isSetupComplete = true;
}

static void a2_SystemCore_setup_j(freedomk64f_SCIRead_a2_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  a2_B.TxPinLoc = MW_UNDEFINED_VALUE;
  a2_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&a2_B.SCIModuleLoc, false, 10U, a2_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  a2_B.StopBitsValue = MW_SCI_STOPBITS_1;
  a2_B.ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, a2_B.ParityValue,
                        a2_B.StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void a2_step(void)
{
  real_T tmp_0;
  int32_T q0;
  uint32_T qY;
  int16_T b_RegisterValue[3];
  uint16_T b_x;
  uint16_T pos_slope;
  uint8_T output_raw[6];
  uint8_T b_x_0[2];
  uint8_T y[2];
  uint8_T status;
  boolean_T VENT_CMP_DETECTD1;
  boolean_T rtb_RelationalOperator;
  boolean_T tmp;

  /* MATLABSystem: '<S2>/Serial Receive1' */
  if (a2_DW.obj_b.SampleTime != a2_P.SerialReceive1_SampleTime) {
    a2_DW.obj_b.SampleTime = a2_P.SerialReceive1_SampleTime;
  }

  status = MW_SCI_Receive(a2_DW.obj_b.MW_SCIHANDLE, &a2_B.RxDataLocChar[0], 68U);
  memcpy((void *)&a2_B.RxData[0], (void *)&a2_B.RxDataLocChar[0], (uint32_T)
         ((size_t)68 * sizeof(uint8_T)));

  /* Chart: '<S2>/From DCM' incorporates:
   *  MATLABSystem: '<S2>/Serial Receive1'
   */
  if (a2_DW.is_active_c2_a2 == 0U) {
    a2_DW.is_active_c2_a2 = 1U;
    a2_DW.is_c2_a2 = a2_IN_Default;
    a2_B.mode_f = 6U;
    a2_B.lower_rate_limit_p = 60U;
    a2_B.upper_rate_limit_m = 120U;
    a2_B.PVARP_a = 250U;
    a2_B.av_delay_f = 150U;
    a2_B.reaction_time_i = 10U;
    a2_B.response_factor_n = 16U;
    a2_B.activity_threshold_o = 0.2;
    a2_B.recovery_time_e = 20U;
    a2_B.MSR_g = 180U;
    a2_B.atr_amp_p = 3.5;
    a2_B.atr_pulse_width_f = 10U;
    a2_B.ARP_c = 200U;
    a2_B.atr_threshold_e = 1.8;
    a2_B.vent_amp_e = 3.5;
    a2_B.vent_pulse_width_h = 10U;
    a2_B.VRP_j = 200U;
    a2_B.vent_threshold_o = 2.2;
  } else {
    switch (a2_DW.is_c2_a2) {
     case a2_IN_Default:
      a2_DW.is_c2_a2 = a2_IN_STANDBY;
      break;

     case a2_IN_ECHO_PARAM:
      a2_DW.is_c2_a2 = a2_IN_STANDBY;
      break;

     case a2_IN_SET_PARAM:
      a2_DW.is_c2_a2 = a2_IN_STANDBY;
      break;

     default:
      /* case IN_STANDBY: */
      if (status == 0) {
        if (a2_B.RxData[0] == 22) {
          switch (a2_B.RxData[1]) {
           case 34:
            a2_DW.is_c2_a2 = a2_IN_ECHO_PARAM;
            DCM_SEND();
            break;

           case 85:
            a2_DW.is_c2_a2 = a2_IN_SET_PARAM;
            memcpy((void *)&a2_B.mode_f, (void *)&a2_B.RxData[2], (uint32_T)
                   ((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&a2_B.lower_rate_limit_p, (void *)&a2_B.RxData[4],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&a2_B.upper_rate_limit_m, (void *)&a2_B.RxData[6],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&a2_B.PVARP_a, (void *)&a2_B.RxData[8], (uint32_T)
                   ((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&a2_B.av_delay_f, (void *)&a2_B.RxData[10], (uint32_T)
                   ((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&a2_B.reaction_time_i, (void *)&a2_B.RxData[12],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&a2_B.response_factor_n, (void *)&a2_B.RxData[14],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&a2_B.activity_threshold_o, (void *)&a2_B.RxData[16],
                   (uint32_T)((size_t)1 * sizeof(real_T)));
            memcpy((void *)&a2_B.recovery_time_e, (void *)&a2_B.RxData[24],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&a2_B.MSR_g, (void *)&a2_B.RxData[26], (uint32_T)
                   ((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&a2_B.atr_amp_p, (void *)&a2_B.RxData[28], (uint32_T)
                   ((size_t)1 * sizeof(real_T)));
            memcpy((void *)&a2_B.atr_pulse_width_f, (void *)&a2_B.RxData[36],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&a2_B.ARP_c, (void *)&a2_B.RxData[38], (uint32_T)
                   ((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&a2_B.atr_threshold_e, (void *)&a2_B.RxData[40],
                   (uint32_T)((size_t)1 * sizeof(real_T)));
            memcpy((void *)&a2_B.vent_amp_e, (void *)&a2_B.RxData[48], (uint32_T)
                   ((size_t)1 * sizeof(real_T)));
            memcpy((void *)&a2_B.vent_pulse_width_h, (void *)&a2_B.RxData[56],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&a2_B.VRP_j, (void *)&a2_B.RxData[58], (uint32_T)
                   ((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&a2_B.vent_threshold_o, (void *)&a2_B.RxData[60],
                   (uint32_T)((size_t)1 * sizeof(real_T)));
            break;

           default:
            a2_DW.is_c2_a2 = a2_IN_STANDBY;
            break;
          }
        } else {
          a2_DW.is_c2_a2 = a2_IN_STANDBY;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S2>/From DCM' */

  /* MATLABSystem: '<S1>/ATR_CMP_REF_PWM D6' incorporates:
   *  Constant: '<S8>/Constant'
   *  Gain: '<S8>/Gain'
   *  Product: '<S8>/Divide'
   */
  MW_PWM_SetDutyCycle(a2_DW.obj_h.MW_PWM_HANDLE, a2_P.Gain_Gain *
                      (a2_B.atr_threshold_e / a2_P.Constant_Value_a));

  /* Gain: '<S9>/Gain' incorporates:
   *  Constant: '<S9>/Constant'
   *  Product: '<S9>/duty cycle calculation2'
   */
  a2_B.Gain = a2_B.atr_amp_p / a2_P.Constant_Value_i * a2_P.Gain_Gain_d;

  /* Gain: '<S9>/Gain1' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Product: '<S9>/duty cycle calculation1'
   */
  a2_B.Gain1 = a2_B.vent_amp_e / a2_P.Constant1_Value_c * a2_P.Gain1_Gain;

  /* MATLABSystem: '<S3>/ATR_CMP_DETECT D0' */
  if (a2_DW.obj_l.SampleTime != a2_P.ATR_CMP_DETECTD0_SampleTime) {
    a2_DW.obj_l.SampleTime = a2_P.ATR_CMP_DETECTD0_SampleTime;
  }

  tmp = MW_digitalIO_read(a2_DW.obj_l.MW_DIGITALIO_HANDLE);

  /* Product: '<S11>/Divide2' incorporates:
   *  Constant: '<S11>/1min = 60sec = 60000msec2'
   */
  a2_B.Divide2 = a2_P.umin60sec60000msec2_Value / (real_T)
    a2_B.lower_rate_limit_p;

  /* MATLABSystem: '<S3>/VENT_CMP_DETECT D1' */
  if (a2_DW.obj_a.SampleTime != a2_P.VENT_CMP_DETECTD1_SampleTime) {
    a2_DW.obj_a.SampleTime = a2_P.VENT_CMP_DETECTD1_SampleTime;
  }

  /* MATLABSystem: '<S3>/VENT_CMP_DETECT D1' */
  VENT_CMP_DETECTD1 = MW_digitalIO_read(a2_DW.obj_a.MW_DIGITALIO_HANDLE);

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S15>/Constant1'
   */
  if (a2_B.mode_f >= a2_P.Switch_Threshold) {
    tmp_0 = a2_P.Constant_Value_n;
  } else {
    tmp_0 = a2_P.Constant1_Value_b;
  }

  /* End of Switch: '<S15>/Switch' */

  /* Outputs for Enabled SubSystem: '<S12>/calculate acceleration(3D)' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  if (tmp_0 > 0.0) {
    /* MATLABSystem: '<S14>/FXOS8700 6-Axes Sensor' */
    if (a2_DW.obj.SampleTime != a2_P.FXOS87006AxesSensor_SampleTime) {
      a2_DW.obj.SampleTime = a2_P.FXOS87006AxesSensor_SampleTime;
    }

    status = 1U;
    status = MW_I2C_MasterWrite(a2_DW.obj.i2cobj.MW_I2C_HANDLE, 29U, &status, 1U,
      true, false);
    if (status == 0) {
      MW_I2C_MasterRead(a2_DW.obj.i2cobj.MW_I2C_HANDLE, 29U, &output_raw[0], 6U,
                        false, true);
      memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (uint32_T)
             ((size_t)3 * sizeof(int16_T)));
      memcpy((void *)&y[0], (void *)&b_RegisterValue[0], (uint32_T)((size_t)2 *
              sizeof(uint8_T)));
      b_x_0[0] = y[1];
      b_x_0[1] = y[0];
      memcpy((void *)&b_RegisterValue[0], (void *)&b_x_0[0], (uint32_T)((size_t)
              1 * sizeof(int16_T)));
      memcpy((void *)&y[0], (void *)&b_RegisterValue[1], (uint32_T)((size_t)2 *
              sizeof(uint8_T)));
      b_x_0[0] = y[1];
      b_x_0[1] = y[0];
      memcpy((void *)&b_RegisterValue[1], (void *)&b_x_0[0], (uint32_T)((size_t)
              1 * sizeof(int16_T)));
      memcpy((void *)&y[0], (void *)&b_RegisterValue[2], (uint32_T)((size_t)2 *
              sizeof(uint8_T)));
      b_x_0[0] = y[1];
      b_x_0[1] = y[0];
      memcpy((void *)&b_RegisterValue[2], (void *)&b_x_0[0], (uint32_T)((size_t)
              1 * sizeof(int16_T)));
    } else {
      b_RegisterValue[0] = 0;
      b_RegisterValue[1] = 0;
      b_RegisterValue[2] = 0;
    }

    /* Sum: '<S14>/Add' incorporates:
     *  Abs: '<S14>/Abs'
     *  Abs: '<S14>/Abs1'
     *  Abs: '<S14>/Abs2'
     *  Constant: '<S14>/Constant'
     *  MATLABSystem: '<S14>/FXOS8700 6-Axes Sensor'
     *  Sum: '<S14>/Minus'
     */
    a2_B.Add = (fabs((real_T)a2_bitshift_anonFcn1(b_RegisterValue[0], -2.0) *
                     2.0 * 0.244 / 1000.0) + fabs((real_T)a2_bitshift_anonFcn1
      (b_RegisterValue[1], -2.0) * 2.0 * 0.244 / 1000.0)) + fabs((real_T)
      a2_bitshift_anonFcn1(b_RegisterValue[2], -2.0) * 2.0 * 0.244 / 1000.0 -
      a2_P.Constant_Value_p);
  }

  /* End of Outputs for SubSystem: '<S12>/calculate acceleration(3D)' */

  /* RelationalOperator: '<S13>/Relational Operator' */
  rtb_RelationalOperator = (a2_B.Add >= a2_B.activity_threshold_o);

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Memory: '<S3>/Memory'
   */
  qY = (uint32_T)a2_B.MSR_g - /*MW:OvSatOk*/ a2_B.lower_rate_limit_p;
  if (qY > a2_B.MSR_g) {
    qY = 0U;
  }

  if (a2_B.reaction_time_i == 0) {
    if ((uint16_T)qY == 0) {
      pos_slope = 0U;
    } else {
      pos_slope = MAX_uint16_T;
    }
  } else {
    pos_slope = (uint16_T)((uint32_T)(uint16_T)qY / a2_B.reaction_time_i);
    b_x = (uint16_T)((uint32_T)(uint16_T)qY - (uint16_T)((uint32_T)pos_slope *
      a2_B.reaction_time_i));
    if ((b_x > 0) && (b_x >= (int32_T)((uint32_T)a2_B.reaction_time_i >> 1) +
                      (a2_B.reaction_time_i & 1))) {
      pos_slope++;
    }
  }

  if (a2_DW.Memory_PreviousInput == 0) {
    a2_DW.Memory_PreviousInput = a2_B.lower_rate_limit_p;
  }

  if (rtb_RelationalOperator) {
    qY = (uint32_T)a2_DW.Memory_PreviousInput + pos_slope;
    if (qY > 65535U) {
      qY = 65535U;
    }

    a2_DW.Memory_PreviousInput = (uint16_T)qY;
    if ((uint16_T)qY > a2_B.MSR_g) {
      a2_DW.Memory_PreviousInput = a2_B.MSR_g;
    }
  } else if (a2_DW.Memory_PreviousInput < a2_B.lower_rate_limit_p) {
    a2_DW.Memory_PreviousInput = a2_B.lower_rate_limit_p;
  }

  /* Chart: '<S3>/4 Modes' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  MATLABSystem: '<S3>/ATR_CMP_DETECT D0'
   */
  if (a2_DW.temporalCounter_i1 < MAX_uint32_T) {
    a2_DW.temporalCounter_i1++;
  }

  if (a2_DW.is_active_c4_a2 == 0U) {
    a2_DW.is_active_c4_a2 = 1U;
    a2_DW.is_c4_a2 = a2_IN_Start;
  } else {
    switch (a2_DW.is_c4_a2) {
     case a2_IN_AAI:
      switch (a2_DW.is_AAI) {
       case a2_IN_ARP_Period:
        if (a2_DW.temporalCounter_i1 >= a2_B.ARP_c) {
          a2_DW.is_AAI = a2_IN_Alert_Period_h;
          a2_DW.temporalCounter_i1 = 0U;
        }
        break;

       case a2_IN_Alert_Period_h:
        if (tmp) {
          a2_DW.is_AAI = a2_IN_ARP_Period;
          a2_DW.temporalCounter_i1 = 0U;
        } else {
          tmp_0 = rt_roundd_snf(a2_B.Divide2 - (real_T)a2_B.ARP_c);
          if (tmp_0 < 65536.0) {
            if (tmp_0 >= 0.0) {
              pos_slope = (uint16_T)tmp_0;
            } else {
              pos_slope = 0U;
            }
          } else {
            pos_slope = MAX_uint16_T;
          }

          if (a2_DW.temporalCounter_i1 >= pos_slope) {
            a2_DW.is_AAI = a2_IN_Pacing_ob;
            a2_DW.temporalCounter_i1 = 0U;
            a2_B.PACE_CHARGE_CTRL = a2_LOW;
            a2_B.PACE_GND_CTRL = a2_HIGH;
            a2_B.ATR_PACE_CTRL = a2_HIGH;
            a2_B.ATR_GND_CTRL = a2_LOW;
            a2_B.Z_ATR_CTRL = a2_LOW;
            a2_B.Z_VENT_CTRL = a2_LOW;
            a2_B.VENT_GND_CTRL = a2_LOW;
            a2_B.VENT_PACE_CTRL = a2_LOW;
          }
        }
        break;

       case a2_IN_Charging_jb:
        a2_B.PACE_CHARGE_CTRL = a2_HIGH;
        a2_B.PACE_GND_CTRL = a2_HIGH;
        a2_B.Z_ATR_CTRL = a2_LOW;
        a2_B.Z_VENT_CTRL = a2_LOW;
        a2_B.ATR_GND_CTRL = a2_HIGH;
        a2_B.VENT_GND_CTRL = a2_LOW;
        if (a2_DW.temporalCounter_i1 >= a2_B.ARP_c) {
          a2_DW.is_AAI = a2_IN_Alert_Period_h;
          a2_DW.temporalCounter_i1 = 0U;
        } else if (a2_B.mode_f != 3) {
          a2_DW.is_AAI = a2_IN_NO_ACTIVE_CHILD;
          a2_DW.is_c4_a2 = a2_IN_Start;
        }
        break;

       default:
        /* case IN_Pacing: */
        a2_B.PACE_CHARGE_CTRL = a2_LOW;
        a2_B.PACE_GND_CTRL = a2_HIGH;
        a2_B.ATR_GND_CTRL = a2_LOW;
        a2_B.Z_ATR_CTRL = a2_LOW;
        a2_B.Z_VENT_CTRL = a2_LOW;
        a2_B.VENT_GND_CTRL = a2_LOW;
        if (a2_DW.temporalCounter_i1 >= a2_B.atr_pulse_width_f) {
          a2_DW.is_AAI = a2_IN_Charging_jb;
          a2_DW.temporalCounter_i1 = 0U;
          a2_enter_atomic_Charging(&a2_B.Gain);
        }
        break;
      }
      break;

     case a2_IN_AAIR:
      /* Update for Memory: '<S3>/Memory' incorporates:
       *  MATLABSystem: '<S3>/ATR_CMP_DETECT D0'
       */
      a2_AAIR(&a2_DW.Memory_PreviousInput, &tmp, &a2_B.Gain);
      break;

     case a2_IN_AOO:
      if (a2_DW.is_AOO == a2_IN_Charging) {
        a2_B.PACE_CHARGE_CTRL = a2_HIGH;
        a2_B.PACE_GND_CTRL = a2_HIGH;
        a2_B.Z_ATR_CTRL = a2_LOW;
        a2_B.Z_VENT_CTRL = a2_LOW;
        a2_B.ATR_GND_CTRL = a2_HIGH;
        a2_B.VENT_GND_CTRL = a2_LOW;
        tmp_0 = rt_roundd_snf(a2_B.Divide2 - (real_T)a2_B.atr_pulse_width_f);
        if (tmp_0 < 65536.0) {
          if (tmp_0 >= 0.0) {
            pos_slope = (uint16_T)tmp_0;
          } else {
            pos_slope = 0U;
          }
        } else {
          pos_slope = MAX_uint16_T;
        }

        if (a2_DW.temporalCounter_i1 >= pos_slope) {
          a2_DW.is_AOO = a2_IN_Pacing;
          a2_DW.temporalCounter_i1 = 0U;
          a2_B.PACE_CHARGE_CTRL = a2_LOW;
          a2_B.ATR_PACE_CTRL = a2_HIGH;
          a2_B.ATR_GND_CTRL = a2_LOW;
          a2_B.VENT_PACE_CTRL = a2_LOW;
        } else if (a2_B.mode_f != 1) {
          a2_DW.is_AOO = a2_IN_NO_ACTIVE_CHILD;
          a2_DW.is_c4_a2 = a2_IN_Start;
        }
      } else {
        /* case IN_Pacing: */
        a2_B.PACE_CHARGE_CTRL = a2_LOW;
        a2_B.PACE_GND_CTRL = a2_HIGH;
        a2_B.ATR_GND_CTRL = a2_LOW;
        a2_B.Z_ATR_CTRL = a2_LOW;
        a2_B.Z_VENT_CTRL = a2_LOW;
        a2_B.VENT_GND_CTRL = a2_LOW;
        if (a2_DW.temporalCounter_i1 >= a2_B.atr_pulse_width_f) {
          a2_DW.is_AOO = a2_IN_Charging;
          a2_DW.temporalCounter_i1 = 0U;
          a2_enter_atomic_Charging(&a2_B.Gain);
        }
      }
      break;

     case a2_IN_AOOR:
      if (a2_DW.is_AOOR == a2_IN_Charging) {
        a2_B.PACE_CHARGE_CTRL = a2_HIGH;
        a2_B.PACE_GND_CTRL = a2_HIGH;
        a2_B.Z_ATR_CTRL = a2_LOW;
        a2_B.Z_VENT_CTRL = a2_LOW;
        a2_B.ATR_GND_CTRL = a2_HIGH;
        a2_B.VENT_GND_CTRL = a2_LOW;
        q0 = (int32_T)rt_roundd_snf(0.5 * (real_T)a2_DW.Memory_PreviousInput);
        qY = (uint32_T)q0 - /*MW:OvSatOk*/ a2_B.atr_pulse_width_f;
        if (qY > (uint32_T)q0) {
          qY = 0U;
        }

        if (a2_DW.temporalCounter_i1 >= qY) {
          a2_DW.is_AOOR = a2_IN_Pacing;
          a2_DW.temporalCounter_i1 = 0U;
          a2_B.PACE_CHARGE_CTRL = a2_LOW;
          a2_B.ATR_PACE_CTRL = a2_HIGH;
          a2_B.ATR_GND_CTRL = a2_LOW;
          a2_B.VENT_PACE_CTRL = a2_LOW;
        } else if (a2_B.mode_f != 5) {
          a2_DW.is_AOOR = a2_IN_NO_ACTIVE_CHILD;
          a2_DW.is_c4_a2 = a2_IN_Start;
        }
      } else {
        /* case IN_Pacing: */
        a2_B.PACE_CHARGE_CTRL = a2_LOW;
        a2_B.PACE_GND_CTRL = a2_HIGH;
        a2_B.ATR_GND_CTRL = a2_LOW;
        a2_B.Z_ATR_CTRL = a2_LOW;
        a2_B.Z_VENT_CTRL = a2_LOW;
        a2_B.VENT_GND_CTRL = a2_LOW;
        if (a2_DW.temporalCounter_i1 >= a2_B.atr_pulse_width_f) {
          a2_DW.is_AOOR = a2_IN_Charging;
          a2_DW.temporalCounter_i1 = 0U;
          a2_enter_atomic_Charging(&a2_B.Gain);
        }
      }
      break;

     case a2_IN_Start:
      a2_Start(&a2_B.Gain1, &a2_B.Gain);
      break;

     case a2_IN_VOO:
      if (a2_DW.is_VOO == a2_IN_Charging) {
        a2_B.PACE_CHARGE_CTRL = a2_HIGH;
        a2_B.PACE_GND_CTRL = a2_HIGH;
        a2_B.Z_ATR_CTRL = a2_LOW;
        a2_B.Z_VENT_CTRL = a2_LOW;
        a2_B.ATR_GND_CTRL = a2_LOW;
        a2_B.VENT_GND_CTRL = a2_HIGH;
        tmp_0 = rt_roundd_snf(a2_B.Divide2 - (real_T)a2_B.vent_pulse_width_h);
        if (tmp_0 < 65536.0) {
          if (tmp_0 >= 0.0) {
            pos_slope = (uint16_T)tmp_0;
          } else {
            pos_slope = 0U;
          }
        } else {
          pos_slope = MAX_uint16_T;
        }

        if (a2_DW.temporalCounter_i1 >= pos_slope) {
          a2_DW.is_VOO = a2_IN_Pacing;
          a2_DW.temporalCounter_i1 = 0U;
          a2_B.PACE_CHARGE_CTRL = a2_LOW;
          a2_B.ATR_PACE_CTRL = a2_LOW;
          a2_B.VENT_GND_CTRL = a2_LOW;
          a2_B.VENT_PACE_CTRL = a2_HIGH;
        } else if (a2_B.mode_f != 0) {
          a2_DW.is_VOO = a2_IN_NO_ACTIVE_CHILD;
          a2_DW.is_c4_a2 = a2_IN_Start;
        }
      } else {
        /* case IN_Pacing: */
        a2_B.PACE_CHARGE_CTRL = a2_LOW;
        a2_B.PACE_GND_CTRL = a2_HIGH;
        a2_B.ATR_GND_CTRL = a2_LOW;
        a2_B.Z_ATR_CTRL = a2_LOW;
        a2_B.Z_VENT_CTRL = a2_LOW;
        a2_B.VENT_GND_CTRL = a2_LOW;
        if (a2_DW.temporalCounter_i1 >= a2_B.vent_pulse_width_h) {
          a2_DW.is_VOO = a2_IN_Charging;
          a2_DW.temporalCounter_i1 = 0U;
          a2_enter_atomic_Charging_nltu(&a2_B.Gain1);
        }
      }
      break;

     case a2_IN_VOOR:
      if (a2_DW.is_VOOR == a2_IN_Charging) {
        a2_B.PACE_CHARGE_CTRL = a2_HIGH;
        a2_B.PACE_GND_CTRL = a2_HIGH;
        a2_B.Z_ATR_CTRL = a2_LOW;
        a2_B.Z_VENT_CTRL = a2_LOW;
        a2_B.ATR_GND_CTRL = a2_LOW;
        a2_B.VENT_GND_CTRL = a2_HIGH;
        if (a2_B.mode_f != 4) {
          a2_DW.is_VOOR = a2_IN_NO_ACTIVE_CHILD;
          a2_DW.is_c4_a2 = a2_IN_Start;
        } else {
          q0 = (int32_T)rt_roundd_snf(0.5 * (real_T)a2_DW.Memory_PreviousInput);
          qY = (uint32_T)q0 - /*MW:OvSatOk*/ a2_B.vent_pulse_width_h;
          if (qY > (uint32_T)q0) {
            qY = 0U;
          }

          if (a2_DW.temporalCounter_i1 >= qY) {
            a2_DW.is_VOOR = a2_IN_Pacing;
            a2_DW.temporalCounter_i1 = 0U;
            a2_B.PACE_CHARGE_CTRL = a2_LOW;
            a2_B.ATR_PACE_CTRL = a2_LOW;
            a2_B.VENT_GND_CTRL = a2_LOW;
            a2_B.VENT_PACE_CTRL = a2_HIGH;
          }
        }
      } else {
        /* case IN_Pacing: */
        a2_B.PACE_CHARGE_CTRL = a2_LOW;
        a2_B.PACE_GND_CTRL = a2_HIGH;
        a2_B.ATR_GND_CTRL = a2_LOW;
        a2_B.Z_ATR_CTRL = a2_LOW;
        a2_B.Z_VENT_CTRL = a2_LOW;
        a2_B.VENT_GND_CTRL = a2_LOW;
        if (a2_DW.temporalCounter_i1 >= a2_B.vent_pulse_width_h) {
          a2_DW.is_VOOR = a2_IN_Charging;
          a2_DW.temporalCounter_i1 = 0U;
          a2_enter_atomic_Charging_nltu(&a2_B.Gain1);
        }
      }
      break;

     case a2_IN_VVI:
      a2_VVI(&a2_B.Divide2, &VENT_CMP_DETECTD1, &a2_B.Gain1);
      break;

     default:
      /* Update for Memory: '<S3>/Memory' */
      /* case IN_VVIR: */
      a2_VVIR(&a2_DW.Memory_PreviousInput, &VENT_CMP_DETECTD1, &a2_B.Gain1);
      break;
    }
  }

  /* End of Chart: '<S3>/4 Modes' */

  /* MATLABSystem: '<S1>/ATR_GND_CTRL D11' */
  MW_digitalIO_write(a2_DW.obj_go.MW_DIGITALIO_HANDLE, a2_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S1>/ATR_PACE_CTRL D8' */
  MW_digitalIO_write(a2_DW.obj_lh.MW_DIGITALIO_HANDLE, a2_B.ATR_PACE_CTRL);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant'
   *  Constant: '<S4>/Constant1'
   */
  if (a2_B.mode_f >= a2_P.Switch_Threshold_p) {
    tmp_0 = a2_P.Constant_Value;
  } else {
    tmp_0 = a2_P.Constant1_Value;
  }

  /* End of Switch: '<S4>/Switch' */

  /* MATLABSystem: '<S1>/FRONTEND_CTRL D13' */
  MW_digitalIO_write(a2_DW.obj_oh.MW_DIGITALIO_HANDLE, tmp_0 != 0.0);

  /* MATLABSystem: '<S1>/PACING_REF_PWM D5' */
  MW_PWM_SetDutyCycle(a2_DW.obj_bg.MW_PWM_HANDLE, a2_B.PACING_REF_PWM);

  /* MATLABSystem: '<S1>/Z_VENT_CTRL D7' */
  MW_digitalIO_write(a2_DW.obj_ec.MW_DIGITALIO_HANDLE, a2_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S1>/VENT_CMP_REF_PWM D3' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Gain: '<S8>/Gain1'
   *  Product: '<S8>/Divide1'
   */
  MW_PWM_SetDutyCycle(a2_DW.obj_ds.MW_PWM_HANDLE, a2_P.Gain1_Gain_l *
                      (a2_B.vent_threshold_o / a2_P.Constant1_Value_n));

  /* MATLABSystem: '<S1>/VENT_PACE_CTRL D9  ' */
  MW_digitalIO_write(a2_DW.obj_h0.MW_DIGITALIO_HANDLE, a2_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S1>/PACE_GND_CTRL D10' */
  MW_digitalIO_write(a2_DW.obj_jn.MW_DIGITALIO_HANDLE, a2_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S1>/VENT_GND_CTRL D12' */
  MW_digitalIO_write(a2_DW.obj_j.MW_DIGITALIO_HANDLE, a2_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S1>/Z_ATR_CTRL D4' */
  MW_digitalIO_write(a2_DW.obj_n.MW_DIGITALIO_HANDLE, a2_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S1>/PACE_CHARGE_CTRL D2' */
  MW_digitalIO_write(a2_DW.obj_aq.MW_DIGITALIO_HANDLE, a2_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S2>/ATR_SIGNAL' */
  if (a2_DW.obj_d.SampleTime != a2_P.ATR_SIGNAL_SampleTime) {
    a2_DW.obj_d.SampleTime = a2_P.ATR_SIGNAL_SampleTime;
  }

  MW_AnalogIn_Start(a2_DW.obj_d.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(a2_DW.obj_d.MW_ANALOGIN_HANDLE, &tmp_0, 7);

  /* End of MATLABSystem: '<S2>/ATR_SIGNAL' */

  /* MATLABSystem: '<S2>/VENT_SIGNAL' */
  if (a2_DW.obj_o.SampleTime != a2_P.VENT_SIGNAL_SampleTime) {
    a2_DW.obj_o.SampleTime = a2_P.VENT_SIGNAL_SampleTime;
  }

  MW_AnalogIn_Start(a2_DW.obj_o.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(a2_DW.obj_o.MW_ANALOGIN_HANDLE, &tmp_0, 7);

  /* End of MATLABSystem: '<S2>/VENT_SIGNAL' */

  /* MATLABSystem: '<S12>/Digital Write' */
  MW_digitalIO_write(a2_DW.obj_e.MW_DIGITALIO_HANDLE, rtb_RelationalOperator);

  /* MATLABSystem: '<S12>/Digital Write1' */
  MW_digitalIO_write(a2_DW.obj_g.MW_DIGITALIO_HANDLE, rtb_RelationalOperator);
}

/* Model initialize function */
void a2_initialize(void)
{
  {
    freedomk64f_AnalogInput_a2_T *obj_2;
    freedomk64f_DigitalRead_a2_T *obj_0;
    freedomk64f_DigitalWrite_a2_T *obj_1;
    freedomk64f_PWMOutput_a2_T *obj;

    /* InitializeConditions for Memory: '<S3>/Memory' */
    a2_DW.Memory_PreviousInput = a2_P.Memory_InitialCondition;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S2>/Function Call' incorporates:
     *  SubSystem: '<S2>/Function Call'
     */
    DCM_SEND_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S2>/Function Call' */

    /* SystemInitialize for Enabled SubSystem: '<S12>/calculate acceleration(3D)' */
    /* Start for MATLABSystem: '<S14>/FXOS8700 6-Axes Sensor' */
    a2_DW.obj.isInitialized = 0;
    a2_DW.obj.i2cobj.isInitialized = 0;
    a2_DW.obj.i2cobj.matlabCodegenIsDeleted = false;
    a2_DW.obj.matlabCodegenIsDeleted = false;
    a2_DW.obj.SampleTime = a2_P.FXOS87006AxesSensor_SampleTime;
    a2_SystemCore_setup_j0(&a2_DW.obj);

    /* SystemInitialize for Sum: '<S14>/Add' incorporates:
     *  Outport: '<S14>/Out1'
     */
    a2_B.Add = a2_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S12>/calculate acceleration(3D)' */

    /* Start for MATLABSystem: '<S2>/Serial Receive1' */
    a2_DW.obj_b.isInitialized = 0;
    a2_DW.obj_b.matlabCodegenIsDeleted = false;
    a2_DW.obj_b.SampleTime = a2_P.SerialReceive1_SampleTime;
    a2_SystemCore_setup_j(&a2_DW.obj_b);

    /* Start for MATLABSystem: '<S1>/ATR_CMP_REF_PWM D6' */
    a2_DW.obj_h.matlabCodegenIsDeleted = true;
    a2_DW.obj_h.isInitialized = 0;
    a2_DW.obj_h.matlabCodegenIsDeleted = false;
    obj = &a2_DW.obj_h;
    a2_DW.obj_h.isSetupComplete = false;
    a2_DW.obj_h.isInitialized = 1;
    obj->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(a2_DW.obj_h.MW_PWM_HANDLE);
    a2_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/ATR_CMP_DETECT D0' */
    a2_DW.obj_l.matlabCodegenIsDeleted = true;
    a2_DW.obj_l.isInitialized = 0;
    a2_DW.obj_l.SampleTime = -1.0;
    a2_DW.obj_l.matlabCodegenIsDeleted = false;
    a2_DW.obj_l.SampleTime = a2_P.ATR_CMP_DETECTD0_SampleTime;
    obj_0 = &a2_DW.obj_l;
    a2_DW.obj_l.isSetupComplete = false;
    a2_DW.obj_l.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    a2_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/VENT_CMP_DETECT D1' */
    a2_DW.obj_a.matlabCodegenIsDeleted = true;
    a2_DW.obj_a.isInitialized = 0;
    a2_DW.obj_a.SampleTime = -1.0;
    a2_DW.obj_a.matlabCodegenIsDeleted = false;
    a2_DW.obj_a.SampleTime = a2_P.VENT_CMP_DETECTD1_SampleTime;
    obj_0 = &a2_DW.obj_a;
    a2_DW.obj_a.isSetupComplete = false;
    a2_DW.obj_a.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    a2_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/ATR_GND_CTRL D11' */
    a2_DW.obj_go.matlabCodegenIsDeleted = true;
    a2_DW.obj_go.isInitialized = 0;
    a2_DW.obj_go.matlabCodegenIsDeleted = false;
    obj_1 = &a2_DW.obj_go;
    a2_DW.obj_go.isSetupComplete = false;
    a2_DW.obj_go.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    a2_DW.obj_go.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/ATR_PACE_CTRL D8' */
    a2_DW.obj_lh.matlabCodegenIsDeleted = true;
    a2_DW.obj_lh.isInitialized = 0;
    a2_DW.obj_lh.matlabCodegenIsDeleted = false;
    obj_1 = &a2_DW.obj_lh;
    a2_DW.obj_lh.isSetupComplete = false;
    a2_DW.obj_lh.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    a2_DW.obj_lh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/FRONTEND_CTRL D13' */
    a2_DW.obj_oh.matlabCodegenIsDeleted = true;
    a2_DW.obj_oh.isInitialized = 0;
    a2_DW.obj_oh.matlabCodegenIsDeleted = false;
    obj_1 = &a2_DW.obj_oh;
    a2_DW.obj_oh.isSetupComplete = false;
    a2_DW.obj_oh.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    a2_DW.obj_oh.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PACING_REF_PWM D5' */
    a2_DW.obj_bg.matlabCodegenIsDeleted = true;
    a2_DW.obj_bg.isInitialized = 0;
    a2_DW.obj_bg.matlabCodegenIsDeleted = false;
    obj = &a2_DW.obj_bg;
    a2_DW.obj_bg.isSetupComplete = false;
    a2_DW.obj_bg.isInitialized = 1;
    obj->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(a2_DW.obj_bg.MW_PWM_HANDLE);
    a2_DW.obj_bg.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Z_VENT_CTRL D7' */
    a2_DW.obj_ec.matlabCodegenIsDeleted = true;
    a2_DW.obj_ec.isInitialized = 0;
    a2_DW.obj_ec.matlabCodegenIsDeleted = false;
    obj_1 = &a2_DW.obj_ec;
    a2_DW.obj_ec.isSetupComplete = false;
    a2_DW.obj_ec.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    a2_DW.obj_ec.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/VENT_CMP_REF_PWM D3' */
    a2_DW.obj_ds.matlabCodegenIsDeleted = true;
    a2_DW.obj_ds.isInitialized = 0;
    a2_DW.obj_ds.matlabCodegenIsDeleted = false;
    obj = &a2_DW.obj_ds;
    a2_DW.obj_ds.isSetupComplete = false;
    a2_DW.obj_ds.isInitialized = 1;
    obj->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(a2_DW.obj_ds.MW_PWM_HANDLE);
    a2_DW.obj_ds.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/VENT_PACE_CTRL D9  ' */
    a2_DW.obj_h0.matlabCodegenIsDeleted = true;
    a2_DW.obj_h0.isInitialized = 0;
    a2_DW.obj_h0.matlabCodegenIsDeleted = false;
    obj_1 = &a2_DW.obj_h0;
    a2_DW.obj_h0.isSetupComplete = false;
    a2_DW.obj_h0.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    a2_DW.obj_h0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PACE_GND_CTRL D10' */
    a2_DW.obj_jn.matlabCodegenIsDeleted = true;
    a2_DW.obj_jn.isInitialized = 0;
    a2_DW.obj_jn.matlabCodegenIsDeleted = false;
    obj_1 = &a2_DW.obj_jn;
    a2_DW.obj_jn.isSetupComplete = false;
    a2_DW.obj_jn.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    a2_DW.obj_jn.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/VENT_GND_CTRL D12' */
    a2_DW.obj_j.matlabCodegenIsDeleted = true;
    a2_DW.obj_j.isInitialized = 0;
    a2_DW.obj_j.matlabCodegenIsDeleted = false;
    obj_1 = &a2_DW.obj_j;
    a2_DW.obj_j.isSetupComplete = false;
    a2_DW.obj_j.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    a2_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Z_ATR_CTRL D4' */
    a2_DW.obj_n.matlabCodegenIsDeleted = true;
    a2_DW.obj_n.isInitialized = 0;
    a2_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_1 = &a2_DW.obj_n;
    a2_DW.obj_n.isSetupComplete = false;
    a2_DW.obj_n.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    a2_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/PACE_CHARGE_CTRL D2' */
    a2_DW.obj_aq.matlabCodegenIsDeleted = true;
    a2_DW.obj_aq.isInitialized = 0;
    a2_DW.obj_aq.matlabCodegenIsDeleted = false;
    obj_1 = &a2_DW.obj_aq;
    a2_DW.obj_aq.isSetupComplete = false;
    a2_DW.obj_aq.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    a2_DW.obj_aq.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/ATR_SIGNAL' */
    a2_DW.obj_d.matlabCodegenIsDeleted = true;
    a2_DW.obj_d.isInitialized = 0;
    a2_DW.obj_d.SampleTime = -1.0;
    a2_DW.obj_d.matlabCodegenIsDeleted = false;
    a2_DW.obj_d.SampleTime = a2_P.ATR_SIGNAL_SampleTime;
    obj_2 = &a2_DW.obj_d;
    a2_DW.obj_d.isSetupComplete = false;
    a2_DW.obj_d.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    a2_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(a2_DW.obj_d.MW_ANALOGIN_HANDLE,
      a2_B.trigger_val, 0U);
    a2_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/VENT_SIGNAL' */
    a2_DW.obj_o.matlabCodegenIsDeleted = true;
    a2_DW.obj_o.isInitialized = 0;
    a2_DW.obj_o.SampleTime = -1.0;
    a2_DW.obj_o.matlabCodegenIsDeleted = false;
    a2_DW.obj_o.SampleTime = a2_P.VENT_SIGNAL_SampleTime;
    obj_2 = &a2_DW.obj_o;
    a2_DW.obj_o.isSetupComplete = false;
    a2_DW.obj_o.isInitialized = 1;
    obj_2->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
    a2_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(a2_DW.obj_o.MW_ANALOGIN_HANDLE,
      a2_B.trigger_val, 0U);
    a2_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S12>/Digital Write' */
    a2_DW.obj_e.matlabCodegenIsDeleted = true;
    a2_DW.obj_e.isInitialized = 0;
    a2_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_1 = &a2_DW.obj_e;
    a2_DW.obj_e.isSetupComplete = false;
    a2_DW.obj_e.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    a2_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S12>/Digital Write1' */
    a2_DW.obj_g.matlabCodegenIsDeleted = true;
    a2_DW.obj_g.isInitialized = 0;
    a2_DW.obj_g.matlabCodegenIsDeleted = false;
    obj_1 = &a2_DW.obj_g;
    a2_DW.obj_g.isSetupComplete = false;
    a2_DW.obj_g.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    a2_DW.obj_g.isSetupComplete = true;
  }
}

/* Model terminate function */
void a2_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj;

  /* Terminate for MATLABSystem: '<S2>/Serial Receive1' */
  if (!a2_DW.obj_b.matlabCodegenIsDeleted) {
    a2_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_b.isInitialized == 1) && a2_DW.obj_b.isSetupComplete) {
      MW_SCI_Close(a2_DW.obj_b.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Serial Receive1' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<S2>/Function Call' incorporates:
   *  SubSystem: '<S2>/Function Call'
   */
  DCM_SEND_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<S2>/Function Call' */

  /* Terminate for MATLABSystem: '<S1>/ATR_CMP_REF_PWM D6' */
  if (!a2_DW.obj_h.matlabCodegenIsDeleted) {
    a2_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_h.isInitialized == 1) && a2_DW.obj_h.isSetupComplete) {
      MW_PWM_Stop(a2_DW.obj_h.MW_PWM_HANDLE);
      MW_PWM_Close(a2_DW.obj_h.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/ATR_CMP_REF_PWM D6' */

  /* Terminate for MATLABSystem: '<S3>/ATR_CMP_DETECT D0' */
  if (!a2_DW.obj_l.matlabCodegenIsDeleted) {
    a2_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_l.isInitialized == 1) && a2_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(a2_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/ATR_CMP_DETECT D0' */

  /* Terminate for MATLABSystem: '<S3>/VENT_CMP_DETECT D1' */
  if (!a2_DW.obj_a.matlabCodegenIsDeleted) {
    a2_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_a.isInitialized == 1) && a2_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(a2_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/VENT_CMP_DETECT D1' */

  /* Terminate for Enabled SubSystem: '<S12>/calculate acceleration(3D)' */
  /* Terminate for MATLABSystem: '<S14>/FXOS8700 6-Axes Sensor' */
  if (!a2_DW.obj.matlabCodegenIsDeleted) {
    a2_DW.obj.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj.isInitialized == 1) && a2_DW.obj.isSetupComplete) {
      MW_I2C_Close(a2_DW.obj.i2cobj.MW_I2C_HANDLE);
    }
  }

  obj = &a2_DW.obj.i2cobj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S14>/FXOS8700 6-Axes Sensor' */
  /* End of Terminate for SubSystem: '<S12>/calculate acceleration(3D)' */

  /* Terminate for MATLABSystem: '<S1>/ATR_GND_CTRL D11' */
  if (!a2_DW.obj_go.matlabCodegenIsDeleted) {
    a2_DW.obj_go.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_go.isInitialized == 1) && a2_DW.obj_go.isSetupComplete) {
      MW_digitalIO_close(a2_DW.obj_go.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/ATR_GND_CTRL D11' */

  /* Terminate for MATLABSystem: '<S1>/ATR_PACE_CTRL D8' */
  if (!a2_DW.obj_lh.matlabCodegenIsDeleted) {
    a2_DW.obj_lh.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_lh.isInitialized == 1) && a2_DW.obj_lh.isSetupComplete) {
      MW_digitalIO_close(a2_DW.obj_lh.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/ATR_PACE_CTRL D8' */

  /* Terminate for MATLABSystem: '<S1>/FRONTEND_CTRL D13' */
  if (!a2_DW.obj_oh.matlabCodegenIsDeleted) {
    a2_DW.obj_oh.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_oh.isInitialized == 1) && a2_DW.obj_oh.isSetupComplete) {
      MW_digitalIO_close(a2_DW.obj_oh.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/FRONTEND_CTRL D13' */

  /* Terminate for MATLABSystem: '<S1>/PACING_REF_PWM D5' */
  if (!a2_DW.obj_bg.matlabCodegenIsDeleted) {
    a2_DW.obj_bg.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_bg.isInitialized == 1) && a2_DW.obj_bg.isSetupComplete) {
      MW_PWM_Stop(a2_DW.obj_bg.MW_PWM_HANDLE);
      MW_PWM_Close(a2_DW.obj_bg.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PACING_REF_PWM D5' */

  /* Terminate for MATLABSystem: '<S1>/Z_VENT_CTRL D7' */
  if (!a2_DW.obj_ec.matlabCodegenIsDeleted) {
    a2_DW.obj_ec.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_ec.isInitialized == 1) && a2_DW.obj_ec.isSetupComplete) {
      MW_digitalIO_close(a2_DW.obj_ec.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Z_VENT_CTRL D7' */

  /* Terminate for MATLABSystem: '<S1>/VENT_CMP_REF_PWM D3' */
  if (!a2_DW.obj_ds.matlabCodegenIsDeleted) {
    a2_DW.obj_ds.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_ds.isInitialized == 1) && a2_DW.obj_ds.isSetupComplete) {
      MW_PWM_Stop(a2_DW.obj_ds.MW_PWM_HANDLE);
      MW_PWM_Close(a2_DW.obj_ds.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/VENT_CMP_REF_PWM D3' */

  /* Terminate for MATLABSystem: '<S1>/VENT_PACE_CTRL D9  ' */
  if (!a2_DW.obj_h0.matlabCodegenIsDeleted) {
    a2_DW.obj_h0.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_h0.isInitialized == 1) && a2_DW.obj_h0.isSetupComplete) {
      MW_digitalIO_close(a2_DW.obj_h0.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/VENT_PACE_CTRL D9  ' */

  /* Terminate for MATLABSystem: '<S1>/PACE_GND_CTRL D10' */
  if (!a2_DW.obj_jn.matlabCodegenIsDeleted) {
    a2_DW.obj_jn.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_jn.isInitialized == 1) && a2_DW.obj_jn.isSetupComplete) {
      MW_digitalIO_close(a2_DW.obj_jn.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PACE_GND_CTRL D10' */

  /* Terminate for MATLABSystem: '<S1>/VENT_GND_CTRL D12' */
  if (!a2_DW.obj_j.matlabCodegenIsDeleted) {
    a2_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_j.isInitialized == 1) && a2_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(a2_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/VENT_GND_CTRL D12' */

  /* Terminate for MATLABSystem: '<S1>/Z_ATR_CTRL D4' */
  if (!a2_DW.obj_n.matlabCodegenIsDeleted) {
    a2_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_n.isInitialized == 1) && a2_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(a2_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Z_ATR_CTRL D4' */

  /* Terminate for MATLABSystem: '<S1>/PACE_CHARGE_CTRL D2' */
  if (!a2_DW.obj_aq.matlabCodegenIsDeleted) {
    a2_DW.obj_aq.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_aq.isInitialized == 1) && a2_DW.obj_aq.isSetupComplete) {
      MW_digitalIO_close(a2_DW.obj_aq.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/PACE_CHARGE_CTRL D2' */

  /* Terminate for MATLABSystem: '<S2>/ATR_SIGNAL' */
  if (!a2_DW.obj_d.matlabCodegenIsDeleted) {
    a2_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_d.isInitialized == 1) && a2_DW.obj_d.isSetupComplete) {
      MW_AnalogIn_Stop(a2_DW.obj_d.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(a2_DW.obj_d.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ATR_SIGNAL' */

  /* Terminate for MATLABSystem: '<S2>/VENT_SIGNAL' */
  if (!a2_DW.obj_o.matlabCodegenIsDeleted) {
    a2_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_o.isInitialized == 1) && a2_DW.obj_o.isSetupComplete) {
      MW_AnalogIn_Stop(a2_DW.obj_o.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(a2_DW.obj_o.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/VENT_SIGNAL' */

  /* Terminate for MATLABSystem: '<S12>/Digital Write' */
  if (!a2_DW.obj_e.matlabCodegenIsDeleted) {
    a2_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_e.isInitialized == 1) && a2_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(a2_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S12>/Digital Write' */

  /* Terminate for MATLABSystem: '<S12>/Digital Write1' */
  if (!a2_DW.obj_g.matlabCodegenIsDeleted) {
    a2_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((a2_DW.obj_g.isInitialized == 1) && a2_DW.obj_g.isSetupComplete) {
      MW_digitalIO_close(a2_DW.obj_g.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S12>/Digital Write1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
