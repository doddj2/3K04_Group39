/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a2_changes_nov25.c
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

#include "a2_changes_nov25.h"
#include "a2_changes_nov25_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include "rt_roundd_snf.h"
#include <stddef.h>
#include "DCM_SEND.h"
#include "DCM_SEND_private.h"

/* Named constants for Chart: '<S1>/From DCM' */
#define a2_changes_n_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define a2_changes_nov25_IN_Default    ((uint8_T)1U)
#define a2_changes_nov25_IN_ECHO_PARAM ((uint8_T)2U)
#define a2_changes_nov25_IN_SET_PARAM  ((uint8_T)3U)
#define a2_changes_nov25_IN_STANDBY    ((uint8_T)4U)

/* Named constants for Chart: '<S2>/4 Modes' */
#define a2_changes_no_IN_Alert_Period_g ((uint8_T)2U)
#define a2_changes_nov25_IN_AAI        ((uint8_T)1U)
#define a2_changes_nov25_IN_AAIR       ((uint8_T)2U)
#define a2_changes_nov25_IN_AOO        ((uint8_T)3U)
#define a2_changes_nov25_IN_AOOR       ((uint8_T)4U)
#define a2_changes_nov25_IN_ARP_Period ((uint8_T)1U)
#define a2_changes_nov25_IN_Charging   ((uint8_T)1U)
#define a2_changes_nov25_IN_Charging1  ((uint8_T)2U)
#define a2_changes_nov25_IN_Charging_c ((uint8_T)2U)
#define a2_changes_nov25_IN_Charging_c0 ((uint8_T)3U)
#define a2_changes_nov25_IN_Pacing     ((uint8_T)2U)
#define a2_changes_nov25_IN_Pacing_m   ((uint8_T)3U)
#define a2_changes_nov25_IN_Pacing_m4  ((uint8_T)4U)
#define a2_changes_nov25_IN_Start      ((uint8_T)5U)
#define a2_changes_nov25_IN_VOO        ((uint8_T)6U)
#define a2_changes_nov25_IN_VOOR       ((uint8_T)7U)
#define a2_changes_nov25_IN_VRP_Period ((uint8_T)4U)
#define a2_changes_nov25_IN_VVI        ((uint8_T)8U)
#define a2_changes_nov25_IN_VVIR       ((uint8_T)9U)
#define a2_changes_nov2_IN_Alert_Period ((uint8_T)1U)

/* Block signals (default storage) */
B_a2_changes_nov25_T a2_changes_nov25_B;

/* Block states (default storage) */
DW_a2_changes_nov25_T a2_changes_nov25_DW;

/* Real-time model */
static RT_MODEL_a2_changes_nov25_T a2_changes_nov25_M_;
RT_MODEL_a2_changes_nov25_T *const a2_changes_nov25_M = &a2_changes_nov25_M_;

/* Forward declaration for local functions */
static int16_T a2_changes_no_bitshift_anonFcn1(int16_T a1, real_T k1);
static void a2_changes_nov25_VVIR(const uint16_T *time_response, const boolean_T
  *VENT_CMP_DETECTD1);
static void a2_changes_nov25_AAIR(const uint16_T *time_response, const boolean_T
  *ATR_CMP_DETECTD0);
static void a2_changes_nov25_Start(void);
static void a2_changes_nov25_VVI(const real_T *Divide2, const boolean_T
  *VENT_CMP_DETECTD1);
static void a2_changes__SystemCore_setup_kj(freedomk64f_fxos8700_a2_chang_T *obj);
static void a2_changes_n_SystemCore_setup_k(freedomk64f_SCIRead_a2_change_T *obj);
static int16_T a2_changes_no_bitshift_anonFcn1(int16_T a1, real_T k1)
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

/* Function for Chart: '<S2>/4 Modes' */
static void a2_changes_nov25_VVIR(const uint16_T *time_response, const boolean_T
  *VENT_CMP_DETECTD1)
{
  int32_T q0;
  uint32_T qY;
  uint32_T qY_0;
  switch (a2_changes_nov25_DW.bitsForTID0.is_VVIR) {
   case a2_changes_nov2_IN_Alert_Period:
    if (*VENT_CMP_DETECTD1) {
      a2_changes_nov25_DW.bitsForTID0.is_VVIR = a2_changes_nov25_IN_VRP_Period;
      a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    } else {
      q0 = (int32_T)rt_roundd_snf(0.5 * (real_T)*time_response);
      qY_0 = (uint32_T)q0 - /*MW:OvSatOk*/ a2_changes_nov25_B.vent_pulse_width_b;
      if (qY_0 > (uint32_T)q0) {
        qY_0 = 0U;
      }

      qY = qY_0 - /*MW:OvSatOk*/ a2_changes_nov25_B.VRP_f;
      if (qY > qY_0) {
        qY = 0U;
      }

      if (a2_changes_nov25_DW.temporalCounter_i1 >= qY) {
        a2_changes_nov25_DW.bitsForTID0.is_VVIR = a2_changes_nov25_IN_Pacing_m;
        a2_changes_nov25_DW.temporalCounter_i1 = 0U;
      }
    }
    break;

   case a2_changes_nov25_IN_Charging_c:
    if (a2_changes_nov25_DW.temporalCounter_i1 >= a2_changes_nov25_B.VRP_f) {
      a2_changes_nov25_DW.bitsForTID0.is_VVIR = a2_changes_nov2_IN_Alert_Period;
      a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    } else if (a2_changes_nov25_B.mode_a != 6) {
      a2_changes_nov25_DW.bitsForTID0.is_VVIR = a2_changes_n_IN_NO_ACTIVE_CHILD;
      a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
        a2_changes_nov25_IN_Start;
    }
    break;

   case a2_changes_nov25_IN_Pacing_m:
    if (a2_changes_nov25_DW.temporalCounter_i1 >=
        a2_changes_nov25_B.vent_pulse_width_b) {
      a2_changes_nov25_DW.bitsForTID0.is_VVIR = a2_changes_nov25_IN_Charging_c;
      a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    }
    break;

   default:
    /* case IN_VRP_Period: */
    if (a2_changes_nov25_DW.temporalCounter_i1 >= a2_changes_nov25_B.VRP_f) {
      a2_changes_nov25_DW.bitsForTID0.is_VVIR = a2_changes_nov2_IN_Alert_Period;
      a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    }
    break;
  }
}

/* Function for Chart: '<S2>/4 Modes' */
static void a2_changes_nov25_AAIR(const uint16_T *time_response, const boolean_T
  *ATR_CMP_DETECTD0)
{
  int32_T q0;
  uint32_T qY;
  uint32_T qY_0;
  switch (a2_changes_nov25_DW.bitsForTID0.is_AAIR) {
   case a2_changes_nov25_IN_ARP_Period:
    if (a2_changes_nov25_DW.temporalCounter_i1 >= a2_changes_nov25_B.ARP_m) {
      a2_changes_nov25_DW.bitsForTID0.is_AAIR = a2_changes_no_IN_Alert_Period_g;
      a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    }
    break;

   case a2_changes_no_IN_Alert_Period_g:
    if (*ATR_CMP_DETECTD0) {
      a2_changes_nov25_DW.bitsForTID0.is_AAIR = a2_changes_nov25_IN_ARP_Period;
      a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    } else {
      q0 = (int32_T)rt_roundd_snf(0.5 * (real_T)*time_response);
      qY_0 = (uint32_T)q0 - /*MW:OvSatOk*/ a2_changes_nov25_B.atr_pulse_width_g;
      if (qY_0 > (uint32_T)q0) {
        qY_0 = 0U;
      }

      qY = qY_0 - /*MW:OvSatOk*/ a2_changes_nov25_B.ARP_m;
      if (qY > qY_0) {
        qY = 0U;
      }

      if (a2_changes_nov25_DW.temporalCounter_i1 >= qY) {
        a2_changes_nov25_DW.bitsForTID0.is_AAIR = a2_changes_nov25_IN_Pacing_m4;
        a2_changes_nov25_DW.temporalCounter_i1 = 0U;
      }
    }
    break;

   case a2_changes_nov25_IN_Charging_c0:
    if (a2_changes_nov25_DW.temporalCounter_i1 >= a2_changes_nov25_B.ARP_m) {
      a2_changes_nov25_DW.bitsForTID0.is_AAIR = a2_changes_no_IN_Alert_Period_g;
      a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    } else if (a2_changes_nov25_B.mode_a != 7) {
      a2_changes_nov25_DW.bitsForTID0.is_AAIR = a2_changes_n_IN_NO_ACTIVE_CHILD;
      a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
        a2_changes_nov25_IN_Start;
    }
    break;

   default:
    /* case IN_Pacing: */
    if (a2_changes_nov25_DW.temporalCounter_i1 >=
        a2_changes_nov25_B.atr_pulse_width_g) {
      a2_changes_nov25_DW.bitsForTID0.is_AAIR = a2_changes_nov25_IN_Charging_c0;
      a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    }
    break;
  }
}

/* Function for Chart: '<S2>/4 Modes' */
static void a2_changes_nov25_Start(void)
{
  switch (a2_changes_nov25_B.mode_a) {
   case 4:
    a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
      a2_changes_nov25_IN_VOOR;
    a2_changes_nov25_DW.bitsForTID0.is_VOOR = a2_changes_nov25_IN_Charging;
    a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    break;

   case 0:
    a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
      a2_changes_nov25_IN_VOO;
    a2_changes_nov25_DW.bitsForTID0.is_VOO = a2_changes_nov25_IN_Charging;
    a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    break;

   case 5:
    a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
      a2_changes_nov25_IN_AOOR;
    a2_changes_nov25_DW.bitsForTID0.is_AOOR = a2_changes_nov25_IN_Charging;
    a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    break;

   case 1:
    a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
      a2_changes_nov25_IN_AOO;
    a2_changes_nov25_DW.bitsForTID0.is_AOO = a2_changes_nov25_IN_Charging;
    a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    break;

   case 2:
    a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
      a2_changes_nov25_IN_VVI;
    a2_changes_nov25_DW.bitsForTID0.is_VVI = a2_changes_nov25_IN_Charging1;
    a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    break;

   case 6:
    a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
      a2_changes_nov25_IN_VVIR;
    a2_changes_nov25_DW.bitsForTID0.is_VVIR = a2_changes_nov25_IN_Charging_c;
    a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    break;

   case 3:
    a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
      a2_changes_nov25_IN_AAI;
    a2_changes_nov25_DW.bitsForTID0.is_AAI = a2_changes_nov25_IN_Charging_c0;
    a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    break;

   case 7:
    a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
      a2_changes_nov25_IN_AAIR;
    a2_changes_nov25_DW.bitsForTID0.is_AAIR = a2_changes_nov25_IN_Charging_c0;
    a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    break;
  }
}

/* Function for Chart: '<S2>/4 Modes' */
static void a2_changes_nov25_VVI(const real_T *Divide2, const boolean_T
  *VENT_CMP_DETECTD1)
{
  real_T tmp;
  uint16_T tmp_0;
  switch (a2_changes_nov25_DW.bitsForTID0.is_VVI) {
   case a2_changes_nov2_IN_Alert_Period:
    if (*VENT_CMP_DETECTD1) {
      a2_changes_nov25_DW.bitsForTID0.is_VVI = a2_changes_nov25_IN_VRP_Period;
      a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    } else {
      tmp = rt_roundd_snf(*Divide2 - (real_T)a2_changes_nov25_B.VRP_f);
      if (tmp < 65536.0) {
        if (tmp >= 0.0) {
          tmp_0 = (uint16_T)tmp;
        } else {
          tmp_0 = 0U;
        }
      } else {
        tmp_0 = MAX_uint16_T;
      }

      if (a2_changes_nov25_DW.temporalCounter_i1 >= tmp_0) {
        a2_changes_nov25_DW.bitsForTID0.is_VVI = a2_changes_nov25_IN_Pacing_m;
        a2_changes_nov25_DW.temporalCounter_i1 = 0U;
      }
    }
    break;

   case a2_changes_nov25_IN_Charging1:
    if (a2_changes_nov25_DW.temporalCounter_i1 >= a2_changes_nov25_B.VRP_f) {
      a2_changes_nov25_DW.bitsForTID0.is_VVI = a2_changes_nov2_IN_Alert_Period;
      a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    } else if (a2_changes_nov25_B.mode_a != 2) {
      a2_changes_nov25_DW.bitsForTID0.is_VVI = a2_changes_n_IN_NO_ACTIVE_CHILD;
      a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
        a2_changes_nov25_IN_Start;
    }
    break;

   case a2_changes_nov25_IN_Pacing_m:
    if (a2_changes_nov25_DW.temporalCounter_i1 >=
        a2_changes_nov25_B.vent_pulse_width_b) {
      a2_changes_nov25_DW.bitsForTID0.is_VVI = a2_changes_nov25_IN_Charging1;
      a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    }
    break;

   default:
    /* case IN_VRP_Period: */
    if (a2_changes_nov25_DW.temporalCounter_i1 >= a2_changes_nov25_B.VRP_f) {
      a2_changes_nov25_DW.bitsForTID0.is_VVI = a2_changes_nov2_IN_Alert_Period;
      a2_changes_nov25_DW.temporalCounter_i1 = 0U;
    }
    break;
  }
}

static void a2_changes__SystemCore_setup_kj(freedomk64f_fxos8700_a2_chang_T *obj)
{
  uint8_T b_SwappedDataBytes[2];
  uint8_T b_RegisterValue;
  uint8_T status;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  a2_changes_nov25_B.ModeType = MW_I2C_MASTER;
  a2_changes_nov25_B.i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(a2_changes_nov25_B.i2cname,
    a2_changes_nov25_B.ModeType);
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

static void a2_changes_n_SystemCore_setup_k(freedomk64f_SCIRead_a2_change_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  a2_changes_nov25_B.TxPinLoc = MW_UNDEFINED_VALUE;
  a2_changes_nov25_B.SCIModuleLoc = 1;
  obj->MW_SCIHANDLE = MW_SCI_Open(&a2_changes_nov25_B.SCIModuleLoc, false, 10U,
    a2_changes_nov25_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  a2_changes_nov25_B.StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue,
                        a2_changes_nov25_B.StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void a2_changes_nov25_step(void)
{
  real_T Divide2;
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

  /* MATLABSystem: '<S1>/ATR_SIGNAL' */
  if (a2_changes_nov25_DW.obj_e.SampleTime !=
      a2_changes_nov25_P.ATR_SIGNAL_SampleTime) {
    a2_changes_nov25_DW.obj_e.SampleTime =
      a2_changes_nov25_P.ATR_SIGNAL_SampleTime;
  }

  MW_AnalogIn_Start(a2_changes_nov25_DW.obj_e.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(a2_changes_nov25_DW.obj_e.MW_ANALOGIN_HANDLE,
    &a2_changes_nov25_B.d, 7);

  /* End of MATLABSystem: '<S1>/ATR_SIGNAL' */

  /* MATLABSystem: '<S1>/Serial Receive1' */
  if (a2_changes_nov25_DW.obj_o.SampleTime !=
      a2_changes_nov25_P.SerialReceive1_SampleTime) {
    a2_changes_nov25_DW.obj_o.SampleTime =
      a2_changes_nov25_P.SerialReceive1_SampleTime;
  }

  status = MW_SCI_Receive(a2_changes_nov25_DW.obj_o.MW_SCIHANDLE,
    &a2_changes_nov25_B.RxDataLocChar[0], 68U);
  memcpy((void *)&a2_changes_nov25_B.RxData[0], (void *)
         &a2_changes_nov25_B.RxDataLocChar[0], (uint32_T)((size_t)68 * sizeof
          (uint8_T)));

  /* Chart: '<S1>/From DCM' incorporates:
   *  MATLABSystem: '<S1>/Serial Receive1'
   */
  if (a2_changes_nov25_DW.bitsForTID0.is_active_c1_a2_changes_nov25 == 0U) {
    a2_changes_nov25_DW.bitsForTID0.is_active_c1_a2_changes_nov25 = 1U;
    a2_changes_nov25_DW.bitsForTID0.is_c1_a2_changes_nov25 =
      a2_changes_nov25_IN_Default;
    a2_changes_nov25_B.mode_a = 6U;
    a2_changes_nov25_B.lower_rate_limit_p = 60U;
    a2_changes_nov25_B.upper_rate_limit_b = 120U;
    a2_changes_nov25_B.PVARP_l = 250U;
    a2_changes_nov25_B.av_delay_i = 150U;
    a2_changes_nov25_B.reaction_time_f = 10U;
    a2_changes_nov25_B.response_factor_d = 16U;
    a2_changes_nov25_B.activity_threshold_c = 0.2;
    a2_changes_nov25_B.recovery_time_l = 20U;
    a2_changes_nov25_B.MSR_e = 180U;
    a2_changes_nov25_B.atr_amp_g = 3.5;
    a2_changes_nov25_B.atr_pulse_width_g = 10U;
    a2_changes_nov25_B.ARP_m = 200U;
    a2_changes_nov25_B.atr_threshold_a = 1.8;
    a2_changes_nov25_B.vent_amp_h = 3.5;
    a2_changes_nov25_B.vent_pulse_width_b = 10U;
    a2_changes_nov25_B.VRP_f = 200U;
    a2_changes_nov25_B.vent_threshold_n = 2.2;
  } else {
    switch (a2_changes_nov25_DW.bitsForTID0.is_c1_a2_changes_nov25) {
     case a2_changes_nov25_IN_Default:
      a2_changes_nov25_DW.bitsForTID0.is_c1_a2_changes_nov25 =
        a2_changes_nov25_IN_STANDBY;
      break;

     case a2_changes_nov25_IN_ECHO_PARAM:
      a2_changes_nov25_DW.bitsForTID0.is_c1_a2_changes_nov25 =
        a2_changes_nov25_IN_STANDBY;
      break;

     case a2_changes_nov25_IN_SET_PARAM:
      a2_changes_nov25_DW.bitsForTID0.is_c1_a2_changes_nov25 =
        a2_changes_nov25_IN_STANDBY;
      break;

     default:
      /* case IN_STANDBY: */
      if (status == 0) {
        if (a2_changes_nov25_B.RxData[0] == 22) {
          switch (a2_changes_nov25_B.RxData[1]) {
           case 34:
            a2_changes_nov25_DW.bitsForTID0.is_c1_a2_changes_nov25 =
              a2_changes_nov25_IN_ECHO_PARAM;
            DCM_SEND();
            break;

           case 85:
            a2_changes_nov25_DW.bitsForTID0.is_c1_a2_changes_nov25 =
              a2_changes_nov25_IN_SET_PARAM;
            memcpy((void *)&a2_changes_nov25_B.mode_a, (void *)
                   &a2_changes_nov25_B.RxData[2], (uint32_T)((size_t)1 * sizeof
                    (uint16_T)));
            memcpy((void *)&a2_changes_nov25_B.lower_rate_limit_p, (void *)
                   &a2_changes_nov25_B.RxData[4], (uint32_T)((size_t)1 * sizeof
                    (uint16_T)));
            memcpy((void *)&a2_changes_nov25_B.upper_rate_limit_b, (void *)
                   &a2_changes_nov25_B.RxData[6], (uint32_T)((size_t)1 * sizeof
                    (uint16_T)));
            memcpy((void *)&a2_changes_nov25_B.PVARP_l, (void *)
                   &a2_changes_nov25_B.RxData[8], (uint32_T)((size_t)1 * sizeof
                    (uint16_T)));
            memcpy((void *)&a2_changes_nov25_B.av_delay_i, (void *)
                   &a2_changes_nov25_B.RxData[10], (uint32_T)((size_t)1 * sizeof
                    (uint16_T)));
            memcpy((void *)&a2_changes_nov25_B.reaction_time_f, (void *)
                   &a2_changes_nov25_B.RxData[12], (uint32_T)((size_t)1 * sizeof
                    (uint16_T)));
            memcpy((void *)&a2_changes_nov25_B.response_factor_d, (void *)
                   &a2_changes_nov25_B.RxData[14], (uint32_T)((size_t)1 * sizeof
                    (uint16_T)));
            memcpy((void *)&a2_changes_nov25_B.activity_threshold_c, (void *)
                   &a2_changes_nov25_B.RxData[16], (uint32_T)((size_t)1 * sizeof
                    (real_T)));
            memcpy((void *)&a2_changes_nov25_B.recovery_time_l, (void *)
                   &a2_changes_nov25_B.RxData[24], (uint32_T)((size_t)1 * sizeof
                    (uint16_T)));
            memcpy((void *)&a2_changes_nov25_B.MSR_e, (void *)
                   &a2_changes_nov25_B.RxData[26], (uint32_T)((size_t)1 * sizeof
                    (uint16_T)));
            memcpy((void *)&a2_changes_nov25_B.atr_amp_g, (void *)
                   &a2_changes_nov25_B.RxData[28], (uint32_T)((size_t)1 * sizeof
                    (real_T)));
            memcpy((void *)&a2_changes_nov25_B.atr_pulse_width_g, (void *)
                   &a2_changes_nov25_B.RxData[36], (uint32_T)((size_t)1 * sizeof
                    (uint16_T)));
            memcpy((void *)&a2_changes_nov25_B.ARP_m, (void *)
                   &a2_changes_nov25_B.RxData[38], (uint32_T)((size_t)1 * sizeof
                    (uint16_T)));
            memcpy((void *)&a2_changes_nov25_B.atr_threshold_a, (void *)
                   &a2_changes_nov25_B.RxData[40], (uint32_T)((size_t)1 * sizeof
                    (real_T)));
            memcpy((void *)&a2_changes_nov25_B.vent_amp_h, (void *)
                   &a2_changes_nov25_B.RxData[48], (uint32_T)((size_t)1 * sizeof
                    (real_T)));
            memcpy((void *)&a2_changes_nov25_B.vent_pulse_width_b, (void *)
                   &a2_changes_nov25_B.RxData[56], (uint32_T)((size_t)1 * sizeof
                    (uint16_T)));
            memcpy((void *)&a2_changes_nov25_B.VRP_f, (void *)
                   &a2_changes_nov25_B.RxData[58], (uint32_T)((size_t)1 * sizeof
                    (uint16_T)));
            memcpy((void *)&a2_changes_nov25_B.vent_threshold_n, (void *)
                   &a2_changes_nov25_B.RxData[60], (uint32_T)((size_t)1 * sizeof
                    (real_T)));
            break;

           default:
            a2_changes_nov25_DW.bitsForTID0.is_c1_a2_changes_nov25 =
              a2_changes_nov25_IN_STANDBY;
            break;
          }
        } else {
          a2_changes_nov25_DW.bitsForTID0.is_c1_a2_changes_nov25 =
            a2_changes_nov25_IN_STANDBY;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S1>/From DCM' */

  /* MATLABSystem: '<S1>/VENT_SIGNAL' */
  if (a2_changes_nov25_DW.obj_f.SampleTime !=
      a2_changes_nov25_P.VENT_SIGNAL_SampleTime) {
    a2_changes_nov25_DW.obj_f.SampleTime =
      a2_changes_nov25_P.VENT_SIGNAL_SampleTime;
  }

  MW_AnalogIn_Start(a2_changes_nov25_DW.obj_f.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(a2_changes_nov25_DW.obj_f.MW_ANALOGIN_HANDLE,
    &a2_changes_nov25_B.d, 7);

  /* End of MATLABSystem: '<S1>/VENT_SIGNAL' */

  /* MATLABSystem: '<S2>/ATR_CMP_DETECT D0' */
  if (a2_changes_nov25_DW.obj_f0.SampleTime !=
      a2_changes_nov25_P.ATR_CMP_DETECTD0_SampleTime) {
    a2_changes_nov25_DW.obj_f0.SampleTime =
      a2_changes_nov25_P.ATR_CMP_DETECTD0_SampleTime;
  }

  tmp = MW_digitalIO_read(a2_changes_nov25_DW.obj_f0.MW_DIGITALIO_HANDLE);

  /* Product: '<S9>/Divide2' incorporates:
   *  Constant: '<S9>/1min = 60sec = 60000msec2'
   */
  Divide2 = a2_changes_nov25_P.umin60sec60000msec2_Value / (real_T)
    a2_changes_nov25_B.lower_rate_limit_p;

  /* MATLABSystem: '<S2>/VENT_CMP_DETECT D1' */
  if (a2_changes_nov25_DW.obj_i.SampleTime !=
      a2_changes_nov25_P.VENT_CMP_DETECTD1_SampleTime) {
    a2_changes_nov25_DW.obj_i.SampleTime =
      a2_changes_nov25_P.VENT_CMP_DETECTD1_SampleTime;
  }

  /* MATLABSystem: '<S2>/VENT_CMP_DETECT D1' */
  VENT_CMP_DETECTD1 = MW_digitalIO_read
    (a2_changes_nov25_DW.obj_i.MW_DIGITALIO_HANDLE);

  /* Switch: '<S13>/Switch' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S13>/Constant1'
   */
  if (a2_changes_nov25_B.mode_a >= a2_changes_nov25_P.Switch_Threshold) {
    a2_changes_nov25_B.d = a2_changes_nov25_P.Constant_Value_a;
  } else {
    a2_changes_nov25_B.d = a2_changes_nov25_P.Constant1_Value;
  }

  /* End of Switch: '<S13>/Switch' */

  /* Outputs for Enabled SubSystem: '<S10>/calculate acceleration(3D)' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  if (a2_changes_nov25_B.d > 0.0) {
    /* MATLABSystem: '<S12>/FXOS8700 6-Axes Sensor' */
    if (a2_changes_nov25_DW.obj.SampleTime !=
        a2_changes_nov25_P.FXOS87006AxesSensor_SampleTime) {
      a2_changes_nov25_DW.obj.SampleTime =
        a2_changes_nov25_P.FXOS87006AxesSensor_SampleTime;
    }

    status = 1U;
    status = MW_I2C_MasterWrite(a2_changes_nov25_DW.obj.i2cobj.MW_I2C_HANDLE,
      29U, &status, 1U, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(a2_changes_nov25_DW.obj.i2cobj.MW_I2C_HANDLE, 29U,
                        &output_raw[0], 6U, false, true);
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

    /* Sum: '<S12>/Add' incorporates:
     *  Abs: '<S12>/Abs'
     *  Abs: '<S12>/Abs1'
     *  Abs: '<S12>/Abs2'
     *  Constant: '<S12>/Constant'
     *  MATLABSystem: '<S12>/FXOS8700 6-Axes Sensor'
     *  Sum: '<S12>/Minus'
     */
    a2_changes_nov25_B.Add = (fabs((real_T)a2_changes_no_bitshift_anonFcn1
      (b_RegisterValue[0], -2.0) * 2.0 * 0.244 / 1000.0) + fabs((real_T)
      a2_changes_no_bitshift_anonFcn1(b_RegisterValue[1], -2.0) * 2.0 * 0.244 /
      1000.0)) + fabs((real_T)a2_changes_no_bitshift_anonFcn1(b_RegisterValue[2],
      -2.0) * 2.0 * 0.244 / 1000.0 - a2_changes_nov25_P.Constant_Value);
  }

  /* End of Outputs for SubSystem: '<S10>/calculate acceleration(3D)' */

  /* RelationalOperator: '<S11>/Relational Operator' */
  rtb_RelationalOperator = (a2_changes_nov25_B.Add >=
    a2_changes_nov25_B.activity_threshold_c);

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Memory: '<S2>/Memory'
   */
  qY = (uint32_T)a2_changes_nov25_B.MSR_e - /*MW:OvSatOk*/
    a2_changes_nov25_B.lower_rate_limit_p;
  if (qY > a2_changes_nov25_B.MSR_e) {
    qY = 0U;
  }

  if (a2_changes_nov25_B.reaction_time_f == 0) {
    if ((uint16_T)qY == 0) {
      pos_slope = 0U;
    } else {
      pos_slope = MAX_uint16_T;
    }
  } else {
    pos_slope = (uint16_T)((uint32_T)(uint16_T)qY /
      a2_changes_nov25_B.reaction_time_f);
    b_x = (uint16_T)((uint32_T)(uint16_T)qY - (uint16_T)((uint32_T)pos_slope *
      a2_changes_nov25_B.reaction_time_f));
    if ((b_x > 0) && (b_x >= (int32_T)((uint32_T)
          a2_changes_nov25_B.reaction_time_f >> 1) +
                      (a2_changes_nov25_B.reaction_time_f & 1))) {
      pos_slope++;
    }
  }

  if (a2_changes_nov25_DW.Memory_PreviousInput == 0) {
    a2_changes_nov25_DW.Memory_PreviousInput =
      a2_changes_nov25_B.lower_rate_limit_p;
  }

  if (rtb_RelationalOperator) {
    qY = (uint32_T)a2_changes_nov25_DW.Memory_PreviousInput + pos_slope;
    if (qY > 65535U) {
      qY = 65535U;
    }

    a2_changes_nov25_DW.Memory_PreviousInput = (uint16_T)qY;
    if ((uint16_T)qY > a2_changes_nov25_B.MSR_e) {
      a2_changes_nov25_DW.Memory_PreviousInput = a2_changes_nov25_B.MSR_e;
    }
  } else if (a2_changes_nov25_DW.Memory_PreviousInput <
             a2_changes_nov25_B.lower_rate_limit_p) {
    a2_changes_nov25_DW.Memory_PreviousInput =
      a2_changes_nov25_B.lower_rate_limit_p;
  }

  /* Chart: '<S2>/4 Modes' incorporates:
   *  MATLAB Function: '<S2>/MATLAB Function'
   *  MATLABSystem: '<S2>/ATR_CMP_DETECT D0'
   */
  if (a2_changes_nov25_DW.temporalCounter_i1 < MAX_uint32_T) {
    a2_changes_nov25_DW.temporalCounter_i1++;
  }

  if (a2_changes_nov25_DW.bitsForTID0.is_active_c3_a2_changes_nov25 == 0U) {
    a2_changes_nov25_DW.bitsForTID0.is_active_c3_a2_changes_nov25 = 1U;
    a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
      a2_changes_nov25_IN_Start;
  } else {
    switch (a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25) {
     case a2_changes_nov25_IN_AAI:
      switch (a2_changes_nov25_DW.bitsForTID0.is_AAI) {
       case a2_changes_nov25_IN_ARP_Period:
        if (a2_changes_nov25_DW.temporalCounter_i1 >= a2_changes_nov25_B.ARP_m)
        {
          a2_changes_nov25_DW.bitsForTID0.is_AAI =
            a2_changes_no_IN_Alert_Period_g;
          a2_changes_nov25_DW.temporalCounter_i1 = 0U;
        }
        break;

       case a2_changes_no_IN_Alert_Period_g:
        if (tmp) {
          a2_changes_nov25_DW.bitsForTID0.is_AAI =
            a2_changes_nov25_IN_ARP_Period;
          a2_changes_nov25_DW.temporalCounter_i1 = 0U;
        } else {
          a2_changes_nov25_B.d = rt_roundd_snf(Divide2 - (real_T)
            a2_changes_nov25_B.ARP_m);
          if (a2_changes_nov25_B.d < 65536.0) {
            if (a2_changes_nov25_B.d >= 0.0) {
              pos_slope = (uint16_T)a2_changes_nov25_B.d;
            } else {
              pos_slope = 0U;
            }
          } else {
            pos_slope = MAX_uint16_T;
          }

          if (a2_changes_nov25_DW.temporalCounter_i1 >= pos_slope) {
            a2_changes_nov25_DW.bitsForTID0.is_AAI =
              a2_changes_nov25_IN_Pacing_m4;
            a2_changes_nov25_DW.temporalCounter_i1 = 0U;
          }
        }
        break;

       case a2_changes_nov25_IN_Charging_c0:
        if (a2_changes_nov25_DW.temporalCounter_i1 >= a2_changes_nov25_B.ARP_m)
        {
          a2_changes_nov25_DW.bitsForTID0.is_AAI =
            a2_changes_no_IN_Alert_Period_g;
          a2_changes_nov25_DW.temporalCounter_i1 = 0U;
        } else if (a2_changes_nov25_B.mode_a != 3) {
          a2_changes_nov25_DW.bitsForTID0.is_AAI =
            a2_changes_n_IN_NO_ACTIVE_CHILD;
          a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
            a2_changes_nov25_IN_Start;
        }
        break;

       default:
        /* case IN_Pacing: */
        if (a2_changes_nov25_DW.temporalCounter_i1 >=
            a2_changes_nov25_B.atr_pulse_width_g) {
          a2_changes_nov25_DW.bitsForTID0.is_AAI =
            a2_changes_nov25_IN_Charging_c0;
          a2_changes_nov25_DW.temporalCounter_i1 = 0U;
        }
        break;
      }
      break;

     case a2_changes_nov25_IN_AAIR:
      /* Update for Memory: '<S2>/Memory' incorporates:
       *  MATLABSystem: '<S2>/ATR_CMP_DETECT D0'
       */
      a2_changes_nov25_AAIR(&a2_changes_nov25_DW.Memory_PreviousInput, &tmp);
      break;

     case a2_changes_nov25_IN_AOO:
      if (a2_changes_nov25_DW.bitsForTID0.is_AOO == a2_changes_nov25_IN_Charging)
      {
        a2_changes_nov25_B.d = rt_roundd_snf(Divide2 - (real_T)
          a2_changes_nov25_B.atr_pulse_width_g);
        if (a2_changes_nov25_B.d < 65536.0) {
          if (a2_changes_nov25_B.d >= 0.0) {
            pos_slope = (uint16_T)a2_changes_nov25_B.d;
          } else {
            pos_slope = 0U;
          }
        } else {
          pos_slope = MAX_uint16_T;
        }

        if (a2_changes_nov25_DW.temporalCounter_i1 >= pos_slope) {
          a2_changes_nov25_DW.bitsForTID0.is_AOO = a2_changes_nov25_IN_Pacing;
          a2_changes_nov25_DW.temporalCounter_i1 = 0U;
        } else if (a2_changes_nov25_B.mode_a != 1) {
          a2_changes_nov25_DW.bitsForTID0.is_AOO =
            a2_changes_n_IN_NO_ACTIVE_CHILD;
          a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
            a2_changes_nov25_IN_Start;
        }

        /* case IN_Pacing: */
      } else if (a2_changes_nov25_DW.temporalCounter_i1 >=
                 a2_changes_nov25_B.atr_pulse_width_g) {
        a2_changes_nov25_DW.bitsForTID0.is_AOO = a2_changes_nov25_IN_Charging;
        a2_changes_nov25_DW.temporalCounter_i1 = 0U;
      }
      break;

     case a2_changes_nov25_IN_AOOR:
      if (a2_changes_nov25_DW.bitsForTID0.is_AOOR ==
          a2_changes_nov25_IN_Charging) {
        q0 = (int32_T)rt_roundd_snf(0.5 * (real_T)
          a2_changes_nov25_DW.Memory_PreviousInput);
        qY = (uint32_T)q0 - /*MW:OvSatOk*/ a2_changes_nov25_B.atr_pulse_width_g;
        if (qY > (uint32_T)q0) {
          qY = 0U;
        }

        if (a2_changes_nov25_DW.temporalCounter_i1 >= qY) {
          a2_changes_nov25_DW.bitsForTID0.is_AOOR = a2_changes_nov25_IN_Pacing;
          a2_changes_nov25_DW.temporalCounter_i1 = 0U;
        } else if (a2_changes_nov25_B.mode_a != 5) {
          a2_changes_nov25_DW.bitsForTID0.is_AOOR =
            a2_changes_n_IN_NO_ACTIVE_CHILD;
          a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
            a2_changes_nov25_IN_Start;
        }

        /* case IN_Pacing: */
      } else if (a2_changes_nov25_DW.temporalCounter_i1 >=
                 a2_changes_nov25_B.atr_pulse_width_g) {
        a2_changes_nov25_DW.bitsForTID0.is_AOOR = a2_changes_nov25_IN_Charging;
        a2_changes_nov25_DW.temporalCounter_i1 = 0U;
      }
      break;

     case a2_changes_nov25_IN_Start:
      a2_changes_nov25_Start();
      break;

     case a2_changes_nov25_IN_VOO:
      if (a2_changes_nov25_DW.bitsForTID0.is_VOO == a2_changes_nov25_IN_Charging)
      {
        a2_changes_nov25_B.d = rt_roundd_snf(Divide2 - (real_T)
          a2_changes_nov25_B.vent_pulse_width_b);
        if (a2_changes_nov25_B.d < 65536.0) {
          if (a2_changes_nov25_B.d >= 0.0) {
            pos_slope = (uint16_T)a2_changes_nov25_B.d;
          } else {
            pos_slope = 0U;
          }
        } else {
          pos_slope = MAX_uint16_T;
        }

        if (a2_changes_nov25_DW.temporalCounter_i1 >= pos_slope) {
          a2_changes_nov25_DW.bitsForTID0.is_VOO = a2_changes_nov25_IN_Pacing;
          a2_changes_nov25_DW.temporalCounter_i1 = 0U;
        } else if (a2_changes_nov25_B.mode_a != 0) {
          a2_changes_nov25_DW.bitsForTID0.is_VOO =
            a2_changes_n_IN_NO_ACTIVE_CHILD;
          a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
            a2_changes_nov25_IN_Start;
        }

        /* case IN_Pacing: */
      } else if (a2_changes_nov25_DW.temporalCounter_i1 >=
                 a2_changes_nov25_B.vent_pulse_width_b) {
        a2_changes_nov25_DW.bitsForTID0.is_VOO = a2_changes_nov25_IN_Charging;
        a2_changes_nov25_DW.temporalCounter_i1 = 0U;
      }
      break;

     case a2_changes_nov25_IN_VOOR:
      if (a2_changes_nov25_DW.bitsForTID0.is_VOOR ==
          a2_changes_nov25_IN_Charging) {
        if (a2_changes_nov25_B.mode_a != 4) {
          a2_changes_nov25_DW.bitsForTID0.is_VOOR =
            a2_changes_n_IN_NO_ACTIVE_CHILD;
          a2_changes_nov25_DW.bitsForTID0.is_c3_a2_changes_nov25 =
            a2_changes_nov25_IN_Start;
        } else {
          q0 = (int32_T)rt_roundd_snf(0.5 * (real_T)
            a2_changes_nov25_DW.Memory_PreviousInput);
          qY = (uint32_T)q0 - /*MW:OvSatOk*/
            a2_changes_nov25_B.vent_pulse_width_b;
          if (qY > (uint32_T)q0) {
            qY = 0U;
          }

          if (a2_changes_nov25_DW.temporalCounter_i1 >= qY) {
            a2_changes_nov25_DW.bitsForTID0.is_VOOR = a2_changes_nov25_IN_Pacing;
            a2_changes_nov25_DW.temporalCounter_i1 = 0U;
          }
        }

        /* case IN_Pacing: */
      } else if (a2_changes_nov25_DW.temporalCounter_i1 >=
                 a2_changes_nov25_B.vent_pulse_width_b) {
        a2_changes_nov25_DW.bitsForTID0.is_VOOR = a2_changes_nov25_IN_Charging;
        a2_changes_nov25_DW.temporalCounter_i1 = 0U;
      }
      break;

     case a2_changes_nov25_IN_VVI:
      a2_changes_nov25_VVI(&Divide2, &VENT_CMP_DETECTD1);
      break;

     default:
      /* Update for Memory: '<S2>/Memory' */
      /* case IN_VVIR: */
      a2_changes_nov25_VVIR(&a2_changes_nov25_DW.Memory_PreviousInput,
                            &VENT_CMP_DETECTD1);
      break;
    }
  }

  /* End of Chart: '<S2>/4 Modes' */

  /* MATLABSystem: '<S10>/Digital Write' */
  MW_digitalIO_write(a2_changes_nov25_DW.obj_hj.MW_DIGITALIO_HANDLE,
                     rtb_RelationalOperator);

  /* MATLABSystem: '<S10>/Digital Write1' */
  MW_digitalIO_write(a2_changes_nov25_DW.obj_n.MW_DIGITALIO_HANDLE,
                     rtb_RelationalOperator);
}

/* Model initialize function */
void a2_changes_nov25_initialize(void)
{
  {
    freedomk64f_AnalogInput_a2_ch_T *obj;
    freedomk64f_DigitalRead_a2_ch_T *obj_0;
    freedomk64f_DigitalWrite_a2_c_T *obj_1;

    /* InitializeConditions for Memory: '<S2>/Memory' */
    a2_changes_nov25_DW.Memory_PreviousInput =
      a2_changes_nov25_P.Memory_InitialCondition;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S1>/Function Call' incorporates:
     *  SubSystem: '<S1>/Function Call'
     */
    DCM_SEND_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S1>/Function Call' */

    /* SystemInitialize for Enabled SubSystem: '<S10>/calculate acceleration(3D)' */
    /* Start for MATLABSystem: '<S12>/FXOS8700 6-Axes Sensor' */
    a2_changes_nov25_DW.obj.isInitialized = 0;
    a2_changes_nov25_DW.obj.i2cobj.isInitialized = 0;
    a2_changes_nov25_DW.obj.i2cobj.matlabCodegenIsDeleted = false;
    a2_changes_nov25_DW.obj.matlabCodegenIsDeleted = false;
    a2_changes_nov25_DW.obj.SampleTime =
      a2_changes_nov25_P.FXOS87006AxesSensor_SampleTime;
    a2_changes__SystemCore_setup_kj(&a2_changes_nov25_DW.obj);

    /* SystemInitialize for Sum: '<S12>/Add' incorporates:
     *  Outport: '<S12>/Out1'
     */
    a2_changes_nov25_B.Add = a2_changes_nov25_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S10>/calculate acceleration(3D)' */

    /* Start for MATLABSystem: '<S1>/ATR_SIGNAL' */
    a2_changes_nov25_DW.obj_e.matlabCodegenIsDeleted = true;
    a2_changes_nov25_DW.obj_e.isInitialized = 0;
    a2_changes_nov25_DW.obj_e.SampleTime = -1.0;
    a2_changes_nov25_DW.obj_e.matlabCodegenIsDeleted = false;
    a2_changes_nov25_DW.obj_e.SampleTime =
      a2_changes_nov25_P.ATR_SIGNAL_SampleTime;
    obj = &a2_changes_nov25_DW.obj_e;
    a2_changes_nov25_DW.obj_e.isSetupComplete = false;
    a2_changes_nov25_DW.obj_e.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    a2_changes_nov25_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(a2_changes_nov25_DW.obj_e.MW_ANALOGIN_HANDLE,
      a2_changes_nov25_B.trigger_val, 0U);
    a2_changes_nov25_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Serial Receive1' */
    a2_changes_nov25_DW.obj_o.isInitialized = 0;
    a2_changes_nov25_DW.obj_o.matlabCodegenIsDeleted = false;
    a2_changes_nov25_DW.obj_o.SampleTime =
      a2_changes_nov25_P.SerialReceive1_SampleTime;
    a2_changes_n_SystemCore_setup_k(&a2_changes_nov25_DW.obj_o);

    /* Start for MATLABSystem: '<S1>/VENT_SIGNAL' */
    a2_changes_nov25_DW.obj_f.matlabCodegenIsDeleted = true;
    a2_changes_nov25_DW.obj_f.isInitialized = 0;
    a2_changes_nov25_DW.obj_f.SampleTime = -1.0;
    a2_changes_nov25_DW.obj_f.matlabCodegenIsDeleted = false;
    a2_changes_nov25_DW.obj_f.SampleTime =
      a2_changes_nov25_P.VENT_SIGNAL_SampleTime;
    obj = &a2_changes_nov25_DW.obj_f;
    a2_changes_nov25_DW.obj_f.isSetupComplete = false;
    a2_changes_nov25_DW.obj_f.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
    a2_changes_nov25_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(a2_changes_nov25_DW.obj_f.MW_ANALOGIN_HANDLE,
      a2_changes_nov25_B.trigger_val, 0U);
    a2_changes_nov25_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/ATR_CMP_DETECT D0' */
    a2_changes_nov25_DW.obj_f0.matlabCodegenIsDeleted = true;
    a2_changes_nov25_DW.obj_f0.isInitialized = 0;
    a2_changes_nov25_DW.obj_f0.SampleTime = -1.0;
    a2_changes_nov25_DW.obj_f0.matlabCodegenIsDeleted = false;
    a2_changes_nov25_DW.obj_f0.SampleTime =
      a2_changes_nov25_P.ATR_CMP_DETECTD0_SampleTime;
    obj_0 = &a2_changes_nov25_DW.obj_f0;
    a2_changes_nov25_DW.obj_f0.isSetupComplete = false;
    a2_changes_nov25_DW.obj_f0.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    a2_changes_nov25_DW.obj_f0.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/VENT_CMP_DETECT D1' */
    a2_changes_nov25_DW.obj_i.matlabCodegenIsDeleted = true;
    a2_changes_nov25_DW.obj_i.isInitialized = 0;
    a2_changes_nov25_DW.obj_i.SampleTime = -1.0;
    a2_changes_nov25_DW.obj_i.matlabCodegenIsDeleted = false;
    a2_changes_nov25_DW.obj_i.SampleTime =
      a2_changes_nov25_P.VENT_CMP_DETECTD1_SampleTime;
    obj_0 = &a2_changes_nov25_DW.obj_i;
    a2_changes_nov25_DW.obj_i.isSetupComplete = false;
    a2_changes_nov25_DW.obj_i.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    a2_changes_nov25_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S10>/Digital Write' */
    a2_changes_nov25_DW.obj_hj.matlabCodegenIsDeleted = true;
    a2_changes_nov25_DW.obj_hj.isInitialized = 0;
    a2_changes_nov25_DW.obj_hj.matlabCodegenIsDeleted = false;
    obj_1 = &a2_changes_nov25_DW.obj_hj;
    a2_changes_nov25_DW.obj_hj.isSetupComplete = false;
    a2_changes_nov25_DW.obj_hj.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    a2_changes_nov25_DW.obj_hj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S10>/Digital Write1' */
    a2_changes_nov25_DW.obj_n.matlabCodegenIsDeleted = true;
    a2_changes_nov25_DW.obj_n.isInitialized = 0;
    a2_changes_nov25_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_1 = &a2_changes_nov25_DW.obj_n;
    a2_changes_nov25_DW.obj_n.isSetupComplete = false;
    a2_changes_nov25_DW.obj_n.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    a2_changes_nov25_DW.obj_n.isSetupComplete = true;
  }
}

/* Model terminate function */
void a2_changes_nov25_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj;

  /* Terminate for MATLABSystem: '<S1>/ATR_SIGNAL' */
  if (!a2_changes_nov25_DW.obj_e.matlabCodegenIsDeleted) {
    a2_changes_nov25_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((a2_changes_nov25_DW.obj_e.isInitialized == 1) &&
        a2_changes_nov25_DW.obj_e.isSetupComplete) {
      MW_AnalogIn_Stop(a2_changes_nov25_DW.obj_e.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(a2_changes_nov25_DW.obj_e.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/ATR_SIGNAL' */

  /* Terminate for MATLABSystem: '<S1>/Serial Receive1' */
  if (!a2_changes_nov25_DW.obj_o.matlabCodegenIsDeleted) {
    a2_changes_nov25_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((a2_changes_nov25_DW.obj_o.isInitialized == 1) &&
        a2_changes_nov25_DW.obj_o.isSetupComplete) {
      MW_SCI_Close(a2_changes_nov25_DW.obj_o.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Serial Receive1' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<S1>/Function Call' incorporates:
   *  SubSystem: '<S1>/Function Call'
   */
  DCM_SEND_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<S1>/Function Call' */

  /* Terminate for MATLABSystem: '<S1>/VENT_SIGNAL' */
  if (!a2_changes_nov25_DW.obj_f.matlabCodegenIsDeleted) {
    a2_changes_nov25_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((a2_changes_nov25_DW.obj_f.isInitialized == 1) &&
        a2_changes_nov25_DW.obj_f.isSetupComplete) {
      MW_AnalogIn_Stop(a2_changes_nov25_DW.obj_f.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(a2_changes_nov25_DW.obj_f.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/VENT_SIGNAL' */

  /* Terminate for MATLABSystem: '<S2>/ATR_CMP_DETECT D0' */
  if (!a2_changes_nov25_DW.obj_f0.matlabCodegenIsDeleted) {
    a2_changes_nov25_DW.obj_f0.matlabCodegenIsDeleted = true;
    if ((a2_changes_nov25_DW.obj_f0.isInitialized == 1) &&
        a2_changes_nov25_DW.obj_f0.isSetupComplete) {
      MW_digitalIO_close(a2_changes_nov25_DW.obj_f0.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ATR_CMP_DETECT D0' */

  /* Terminate for MATLABSystem: '<S2>/VENT_CMP_DETECT D1' */
  if (!a2_changes_nov25_DW.obj_i.matlabCodegenIsDeleted) {
    a2_changes_nov25_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((a2_changes_nov25_DW.obj_i.isInitialized == 1) &&
        a2_changes_nov25_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(a2_changes_nov25_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/VENT_CMP_DETECT D1' */

  /* Terminate for Enabled SubSystem: '<S10>/calculate acceleration(3D)' */
  /* Terminate for MATLABSystem: '<S12>/FXOS8700 6-Axes Sensor' */
  if (!a2_changes_nov25_DW.obj.matlabCodegenIsDeleted) {
    a2_changes_nov25_DW.obj.matlabCodegenIsDeleted = true;
    if ((a2_changes_nov25_DW.obj.isInitialized == 1) &&
        a2_changes_nov25_DW.obj.isSetupComplete) {
      MW_I2C_Close(a2_changes_nov25_DW.obj.i2cobj.MW_I2C_HANDLE);
    }
  }

  obj = &a2_changes_nov25_DW.obj.i2cobj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S12>/FXOS8700 6-Axes Sensor' */
  /* End of Terminate for SubSystem: '<S10>/calculate acceleration(3D)' */

  /* Terminate for MATLABSystem: '<S10>/Digital Write' */
  if (!a2_changes_nov25_DW.obj_hj.matlabCodegenIsDeleted) {
    a2_changes_nov25_DW.obj_hj.matlabCodegenIsDeleted = true;
    if ((a2_changes_nov25_DW.obj_hj.isInitialized == 1) &&
        a2_changes_nov25_DW.obj_hj.isSetupComplete) {
      MW_digitalIO_close(a2_changes_nov25_DW.obj_hj.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S10>/Digital Write' */

  /* Terminate for MATLABSystem: '<S10>/Digital Write1' */
  if (!a2_changes_nov25_DW.obj_n.matlabCodegenIsDeleted) {
    a2_changes_nov25_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((a2_changes_nov25_DW.obj_n.isInitialized == 1) &&
        a2_changes_nov25_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(a2_changes_nov25_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S10>/Digital Write1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
