/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: A2_V4.c
 *
 * Code generated for Simulink model 'A2_V4'.
 *
 * Model version                  : 1.183
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Fri Nov 25 20:11:10 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "A2_V4.h"
#include "A2_V4_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <math.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "rt_roundd_snf.h"
#include "DCM_SEND.h"
#include "DCM_SEND_private.h"

/* Named constants for Chart: '<S1>/From DCM' */
#define A2_V4_IN_Default               ((uint8_T)1U)
#define A2_V4_IN_ECHO_PARAM            ((uint8_T)2U)
#define A2_V4_IN_SET_PARAM             ((uint8_T)3U)
#define A2_V4_IN_STANDBY               ((uint8_T)4U)

/* Named constants for Chart: '<S3>/Chart' */
#define A2_V4_IN_ATR_CHARGING          ((uint8_T)11U)
#define A2_V4_IN_ATR_CHARGING1         ((uint8_T)15U)
#define A2_V4_IN_ATR_DISCHARGING       ((uint8_T)12U)
#define A2_V4_IN_ATR_DISCHARGING1      ((uint8_T)16U)
#define A2_V4_IN_CHARGING              ((uint8_T)1U)
#define A2_V4_IN_CHARGING_g            ((uint8_T)4U)
#define A2_V4_IN_CHARGING_gl           ((uint8_T)7U)
#define A2_V4_IN_CHARGING_gln          ((uint8_T)9U)
#define A2_V4_IN_CHARGING_glnx         ((uint8_T)20U)
#define A2_V4_IN_CHARGING_glnx2        ((uint8_T)22U)
#define A2_V4_IN_CHARGING_glnx21       ((uint8_T)24U)
#define A2_V4_IN_CHARGING_glnx21l      ((uint8_T)27U)
#define A2_V4_IN_DISCHARGING           ((uint8_T)2U)
#define A2_V4_IN_DISCHARGING_g         ((uint8_T)5U)
#define A2_V4_IN_DISCHARGING_go        ((uint8_T)8U)
#define A2_V4_IN_DISCHARGING_gob       ((uint8_T)10U)
#define A2_V4_IN_DISCHARGING_gob2      ((uint8_T)21U)
#define A2_V4_IN_DISCHARGING_gob2k     ((uint8_T)23U)
#define A2_V4_IN_DISCHARGING_gob2kd    ((uint8_T)25U)
#define A2_V4_IN_DISCHARGING_gob2kdy   ((uint8_T)28U)
#define A2_V4_IN_PROXY                 ((uint8_T)3U)
#define A2_V4_IN_PROXY_p               ((uint8_T)6U)
#define A2_V4_IN_PROXY_pt              ((uint8_T)26U)
#define A2_V4_IN_PROXY_ptm             ((uint8_T)29U)
#define A2_V4_IN_Start                 ((uint8_T)19U)
#define A2_V4_IN_VENT_CHARGING         ((uint8_T)13U)
#define A2_V4_IN_VENT_CHARGING1        ((uint8_T)17U)
#define A2_V4_IN_VENT_DISCHARGING      ((uint8_T)14U)
#define A2_V4_IN_VENT_DISCHARGING1     ((uint8_T)18U)

/* Named constants for Chart: '<S3>/Chart1' */
#define A2_V4_IN_S2FAIL1               ((uint8_T)1U)
#define A2_V4_IN_S3                    ((uint8_T)2U)
#define A2_V4_IN_S4                    ((uint8_T)3U)
#define A2_V4_IN_S_FAILSAFE1           ((uint8_T)4U)
#define A2_V4_IN_Start1                ((uint8_T)5U)

/* Block signals (default storage) */
B_A2_V4_T A2_V4_B;

/* Block states (default storage) */
DW_A2_V4_T A2_V4_DW;

/* Real-time model */
static RT_MODEL_A2_V4_T A2_V4_M_;
RT_MODEL_A2_V4_T *const A2_V4_M = &A2_V4_M_;

/* Forward declaration for local functions */
static int16_T A2_V4_bitshift_anonFcn1(int16_T a1, real_T k1);
static void A2_V4_PROXY_d0h(const real_T *Multiply_i);
static void A2_V4_CHARGING(const real_T *Multiply, const boolean_T *DigitalRead,
  const real_T *Divide);
static void A2_V4_PROXY(const real_T *Multiply);
static void A2_V4_CHARGING_i(const real_T *Multiply, const boolean_T
  *DigitalRead, const real_T *Divide1);
static void A2_V4_PROXY_d(const real_T *Multiply);
static void A2_V4_CHARGING_i5(const real_T *Multiply, const real_T *Divide);
static void A2_V4_CHARGING_i53(const real_T *Multiply, const real_T *Divide1);
static void A2_V4_VENT_CHARGING(const real_T *Multiply_i, const real_T *Divide);
static void A2_V4_VENT_CHARGING1(const real_T *Divide1, const real_T *Multiply_i);
static void A2_V4_Start(void);
static void A2_V4_CHARGING_i53k(const real_T *Multiply_i, const real_T *Divide);
static void A2_V4_CHARGING_i53ko(const real_T *Divide1, const real_T *Multiply_i);
static void A2_V4_CHARGING_i53koo(const real_T *Multiply_i, const real_T *Divide,
  const boolean_T *OR3);
static void A2_V4_PROXY_d0(const real_T *Multiply_i);
static void A2_V4_CHARGING_i53kooo(const real_T *Divide1, const real_T
  *Multiply_i, const boolean_T *OR3);
static void A2_V4_SystemCore_setup_nl(freedomk64f_fxos8700_A2_V4_T *obj);
static void A2_V4_SystemCore_setup_nlg(dsp_simulink_MovingStandardDe_T *obj);
static void A2_V4_SystemCore_setup_n(freedomk64f_SCIRead_A2_V4_T *obj);
static int16_T A2_V4_bitshift_anonFcn1(int16_T a1, real_T k1)
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

/* Function for Chart: '<S3>/Chart' */
static void A2_V4_PROXY_d0h(const real_T *Multiply_i)
{
  if (A2_V4_DW.temporalCounter_i1 >= A2_V4_B.VRP_b) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_CHARGING_glnx21l;
    A2_V4_DW.temporalCounter_i1 = 0U;
  } else {
    A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
    A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
    A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
    A2_V4_B.VENT_GND_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.PACING_REF_PWM = *Multiply_i;
    A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.HIGH;
  }
}

/* Function for Chart: '<S3>/Chart' */
static void A2_V4_CHARGING(const real_T *Multiply, const boolean_T *DigitalRead,
  const real_T *Divide)
{
  real_T tmp_0;
  uint32_T qY;
  uint16_T tmp;
  if ((*DigitalRead == A2_V4_DW.HIGH) && (A2_V4_DW.temporalCounter_i1 >=
       A2_V4_B.LOWER_RATE_LIMIT_l)) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_PROXY;
    A2_V4_DW.temporalCounter_i1 = 0U;
  } else {
    tmp_0 = rt_roundd_snf(*Divide - (real_T)A2_V4_B.ATR_PW_a);
    if (tmp_0 < 65536.0) {
      if (tmp_0 >= 0.0) {
        tmp = (uint16_T)tmp_0;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint16_T;
    }

    qY = (uint32_T)tmp - /*MW:OvSatOk*/ A2_V4_B.ARP_i;
    if (qY > tmp) {
      qY = 0U;
    }

    if (A2_V4_DW.temporalCounter_i1 >= qY) {
      A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_DISCHARGING;
      A2_V4_DW.temporalCounter_i1 = 0U;
    } else if (A2_V4_B.MODE_i != 2) {
      A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_Start;
    } else {
      A2_V4_B.PACING_REF_PWM = *Multiply;
      A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.HIGH;
      A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
      A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
      A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
      A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
      A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
      A2_V4_B.ATR_GND_CTRL = A2_V4_DW.HIGH;
      A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
    }
  }
}

/* Function for Chart: '<S3>/Chart' */
static void A2_V4_PROXY(const real_T *Multiply)
{
  if (A2_V4_DW.temporalCounter_i1 >= A2_V4_B.ARP_i) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_CHARGING;
    A2_V4_DW.temporalCounter_i1 = 0U;
  } else {
    A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
    A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
    A2_V4_B.ATR_GND_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
    A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.PACING_REF_PWM = *Multiply;
    A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.HIGH;
  }
}

/* Function for Chart: '<S3>/Chart' */
static void A2_V4_CHARGING_i(const real_T *Multiply, const boolean_T
  *DigitalRead, const real_T *Divide1)
{
  real_T tmp_0;
  uint32_T qY;
  uint16_T tmp;
  if ((*DigitalRead == A2_V4_DW.HIGH) && (A2_V4_DW.temporalCounter_i1 >=
       A2_V4_B.LOWER_RATE_LIMIT_l)) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_PROXY_p;
    A2_V4_DW.temporalCounter_i1 = 0U;
  } else {
    tmp_0 = rt_roundd_snf(*Divide1 - (real_T)A2_V4_B.ATR_PW_a);
    if (tmp_0 < 65536.0) {
      if (tmp_0 >= 0.0) {
        tmp = (uint16_T)tmp_0;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint16_T;
    }

    qY = (uint32_T)tmp - /*MW:OvSatOk*/ A2_V4_B.ARP_i;
    if (qY > tmp) {
      qY = 0U;
    }

    if (A2_V4_DW.temporalCounter_i1 >= qY) {
      A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_DISCHARGING_g;
      A2_V4_DW.temporalCounter_i1 = 0U;
    } else if (A2_V4_B.MODE_i != 9) {
      A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_Start;
    } else {
      A2_V4_B.PACING_REF_PWM = *Multiply;
      A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.HIGH;
      A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
      A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
      A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
      A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
      A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
      A2_V4_B.ATR_GND_CTRL = A2_V4_DW.HIGH;
      A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
    }
  }
}

/* Function for Chart: '<S3>/Chart' */
static void A2_V4_PROXY_d(const real_T *Multiply)
{
  if (A2_V4_DW.temporalCounter_i1 >= A2_V4_B.ARP_i) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_CHARGING_g;
    A2_V4_DW.temporalCounter_i1 = 0U;
  } else {
    A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
    A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
    A2_V4_B.ATR_GND_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
    A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.PACING_REF_PWM = *Multiply;
    A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.HIGH;
  }
}

/* Function for Chart: '<S3>/Chart' */
static void A2_V4_CHARGING_i5(const real_T *Multiply, const real_T *Divide)
{
  real_T tmp;
  uint16_T tmp_0;
  tmp = rt_roundd_snf(*Divide - (real_T)A2_V4_B.ATR_PW_a);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint16_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  if (A2_V4_DW.temporalCounter_i1 >= tmp_0) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_DISCHARGING_go;
    A2_V4_DW.temporalCounter_i1 = 0U;
  } else if (A2_V4_B.MODE_i != 1) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_Start;
  } else {
    A2_V4_B.PACING_REF_PWM = *Multiply;
    A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
    A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
    A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.ATR_GND_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
  }
}

/* Function for Chart: '<S3>/Chart' */
static void A2_V4_CHARGING_i53(const real_T *Multiply, const real_T *Divide1)
{
  real_T tmp;
  uint16_T tmp_0;
  tmp = rt_roundd_snf(*Divide1 - (real_T)A2_V4_B.ATR_PW_a);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint16_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  if (A2_V4_DW.temporalCounter_i1 >= tmp_0) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_DISCHARGING_gob;
    A2_V4_DW.temporalCounter_i1 = 0U;
  } else if (A2_V4_B.MODE_i != 7) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_Start;
  } else {
    A2_V4_B.PACING_REF_PWM = *Multiply;
    A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
    A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
    A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.ATR_GND_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
  }
}

/* Function for Chart: '<S3>/Chart' */
static void A2_V4_VENT_CHARGING(const real_T *Multiply_i, const real_T *Divide)
{
  real_T tmp_0;
  uint32_T qY;
  uint16_T tmp;
  tmp_0 = rt_roundd_snf(*Divide - (real_T)A2_V4_B.VENT_PW_g);
  if (tmp_0 < 65536.0) {
    if (tmp_0 >= 0.0) {
      tmp = (uint16_T)tmp_0;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint16_T;
  }

  qY = (uint32_T)tmp - /*MW:OvSatOk*/ A2_V4_B.AV_DELAY_c;
  if (qY > tmp) {
    qY = 0U;
  }

  if (A2_V4_DW.temporalCounter_i1 >= qY) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_ATR_DISCHARGING;
    A2_V4_DW.temporalCounter_i1 = 0U;
  } else if (A2_V4_B.MODE_i != 5) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_Start;
  } else {
    A2_V4_B.PACING_REF_PWM = *Multiply_i;
    A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
    A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
    A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
    A2_V4_B.VENT_GND_CTRL = A2_V4_DW.HIGH;
  }
}

/* Function for Chart: '<S3>/Chart' */
static void A2_V4_VENT_CHARGING1(const real_T *Divide1, const real_T *Multiply_i)
{
  real_T tmp_0;
  uint32_T qY;
  uint16_T tmp;
  if (A2_V4_B.MODE_i != 6) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_Start;
  } else {
    tmp_0 = rt_roundd_snf(*Divide1 - (real_T)A2_V4_B.VENT_PW_g);
    if (tmp_0 < 65536.0) {
      if (tmp_0 >= 0.0) {
        tmp = (uint16_T)tmp_0;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint16_T;
    }

    qY = (uint32_T)tmp - /*MW:OvSatOk*/ A2_V4_B.AV_DELAY_c;
    if (qY > tmp) {
      qY = 0U;
    }

    if (A2_V4_DW.temporalCounter_i1 >= qY) {
      A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_ATR_DISCHARGING1;
      A2_V4_DW.temporalCounter_i1 = 0U;
    } else {
      A2_V4_B.PACING_REF_PWM = *Multiply_i;
      A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.HIGH;
      A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
      A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
      A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
      A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
      A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
      A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
      A2_V4_B.VENT_GND_CTRL = A2_V4_DW.HIGH;
    }
  }
}

/* Function for Chart: '<S3>/Chart' */
static void A2_V4_Start(void)
{
  switch (A2_V4_B.MODE_i) {
   case 1:
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_CHARGING_gl;
    A2_V4_DW.temporalCounter_i1 = 0U;
    break;

   case 2:
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_CHARGING;
    A2_V4_DW.temporalCounter_i1 = 0U;
    break;

   case 5:
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_VENT_CHARGING;
    A2_V4_DW.temporalCounter_i1 = 0U;
    break;

   case 4:
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_CHARGING_glnx21;
    A2_V4_DW.temporalCounter_i1 = 0U;
    break;

   case 3:
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_CHARGING_glnx;
    A2_V4_DW.temporalCounter_i1 = 0U;
    break;

   case 6:
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_VENT_CHARGING1;
    A2_V4_DW.temporalCounter_i1 = 0U;
    break;

   case 7:
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_CHARGING_gln;
    A2_V4_DW.temporalCounter_i1 = 0U;
    break;

   case 8:
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_CHARGING_glnx2;
    A2_V4_DW.temporalCounter_i1 = 0U;
    break;

   case 9:
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_CHARGING_g;
    A2_V4_DW.temporalCounter_i1 = 0U;
    break;

   case 10:
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_CHARGING_glnx21l;
    A2_V4_DW.temporalCounter_i1 = 0U;
    break;
  }
}

/* Function for Chart: '<S3>/Chart' */
static void A2_V4_CHARGING_i53k(const real_T *Multiply_i, const real_T *Divide)
{
  real_T tmp;
  uint16_T tmp_0;
  tmp = rt_roundd_snf(*Divide - (real_T)A2_V4_B.VENT_PW_g);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint16_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  if (A2_V4_DW.temporalCounter_i1 >= tmp_0) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_DISCHARGING_gob2;
    A2_V4_DW.temporalCounter_i1 = 0U;
  } else if (A2_V4_B.MODE_i != 3) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_Start;
  } else {
    A2_V4_B.PACING_REF_PWM = *Multiply_i;
    A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
    A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
    A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
    A2_V4_B.VENT_GND_CTRL = A2_V4_DW.HIGH;
  }
}

/* Function for Chart: '<S3>/Chart' */
static void A2_V4_CHARGING_i53ko(const real_T *Divide1, const real_T *Multiply_i)
{
  real_T tmp;
  uint16_T tmp_0;
  tmp = rt_roundd_snf(*Divide1 - (real_T)A2_V4_B.VENT_PW_g);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint16_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint16_T;
  }

  if (A2_V4_DW.temporalCounter_i1 >= tmp_0) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_DISCHARGING_gob2k;
    A2_V4_DW.temporalCounter_i1 = 0U;
  } else if (A2_V4_B.MODE_i != 8) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_Start;
  } else {
    A2_V4_B.PACING_REF_PWM = *Multiply_i;
    A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
    A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
    A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
    A2_V4_B.VENT_GND_CTRL = A2_V4_DW.HIGH;
  }
}

/* Function for Chart: '<S3>/Chart' */
static void A2_V4_CHARGING_i53koo(const real_T *Multiply_i, const real_T *Divide,
  const boolean_T *OR3)
{
  real_T tmp_0;
  uint32_T qY;
  uint16_T tmp;
  if ((*OR3 == A2_V4_DW.HIGH) && (A2_V4_DW.temporalCounter_i1 >=
       A2_V4_B.LOWER_RATE_LIMIT_l)) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_PROXY_pt;
    A2_V4_DW.temporalCounter_i1 = 0U;
  } else {
    tmp_0 = rt_roundd_snf(*Divide - (real_T)A2_V4_B.VENT_PW_g);
    if (tmp_0 < 65536.0) {
      if (tmp_0 >= 0.0) {
        tmp = (uint16_T)tmp_0;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint16_T;
    }

    qY = (uint32_T)tmp - /*MW:OvSatOk*/ A2_V4_B.VRP_b;
    if (qY > tmp) {
      qY = 0U;
    }

    if (A2_V4_DW.temporalCounter_i1 >= qY) {
      A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_DISCHARGING_gob2kd;
      A2_V4_DW.temporalCounter_i1 = 0U;
    } else if (A2_V4_B.MODE_i != 4) {
      A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_Start;
    } else {
      A2_V4_B.PACING_REF_PWM = *Multiply_i;
      A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.HIGH;
      A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
      A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
      A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
      A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
      A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
      A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
      A2_V4_B.VENT_GND_CTRL = A2_V4_DW.HIGH;
    }
  }
}

/* Function for Chart: '<S3>/Chart' */
static void A2_V4_PROXY_d0(const real_T *Multiply_i)
{
  if (A2_V4_DW.temporalCounter_i1 >= A2_V4_B.VRP_b) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_CHARGING_glnx21;
    A2_V4_DW.temporalCounter_i1 = 0U;
  } else {
    A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
    A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
    A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
    A2_V4_B.VENT_GND_CTRL = A2_V4_DW.HIGH;
    A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
    A2_V4_B.PACING_REF_PWM = *Multiply_i;
    A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.HIGH;
  }
}

/* Function for Chart: '<S3>/Chart' */
static void A2_V4_CHARGING_i53kooo(const real_T *Divide1, const real_T
  *Multiply_i, const boolean_T *OR3)
{
  real_T tmp_0;
  uint32_T qY;
  uint16_T tmp;
  if ((*OR3 == A2_V4_DW.HIGH) && (A2_V4_DW.temporalCounter_i1 >=
       A2_V4_B.LOWER_RATE_LIMIT_l)) {
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_PROXY_ptm;
    A2_V4_DW.temporalCounter_i1 = 0U;
  } else {
    tmp_0 = rt_roundd_snf(*Divide1 - (real_T)A2_V4_B.VENT_PW_g);
    if (tmp_0 < 65536.0) {
      if (tmp_0 >= 0.0) {
        tmp = (uint16_T)tmp_0;
      } else {
        tmp = 0U;
      }
    } else {
      tmp = MAX_uint16_T;
    }

    qY = (uint32_T)tmp - /*MW:OvSatOk*/ A2_V4_B.VRP_b;
    if (qY > tmp) {
      qY = 0U;
    }

    if (A2_V4_DW.temporalCounter_i1 >= qY) {
      A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_DISCHARGING_gob2kdy;
      A2_V4_DW.temporalCounter_i1 = 0U;
    } else if (A2_V4_B.MODE_i != 10) {
      A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_Start;
    } else {
      A2_V4_B.PACING_REF_PWM = *Multiply_i;
      A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.HIGH;
      A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
      A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
      A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
      A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
      A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
      A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
      A2_V4_B.VENT_GND_CTRL = A2_V4_DW.HIGH;
    }
  }
}

static void A2_V4_SystemCore_setup_nl(freedomk64f_fxos8700_A2_V4_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  A2_V4_B.ModeType = MW_I2C_MASTER;
  A2_V4_B.i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(A2_V4_B.i2cname, A2_V4_B.ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  A2_V4_B.b_SwappedDataBytes[0] = 43U;
  A2_V4_B.b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &A2_V4_B.b_SwappedDataBytes[0], 2U, false, false);
  OSA_TimeDelay(500U);
  A2_V4_B.status = 42U;
  A2_V4_B.status = MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
    &A2_V4_B.status, 1U, true, false);
  if (A2_V4_B.status == 0) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U, &A2_V4_B.status, 1U, false,
                      true);
    memcpy((void *)&A2_V4_B.b_RegisterValue, (void *)&A2_V4_B.status, (uint32_T)
           ((size_t)1 * sizeof(uint8_T)));
  } else {
    A2_V4_B.b_RegisterValue = 0U;
  }

  A2_V4_B.b_SwappedDataBytes[0] = 42U;
  A2_V4_B.b_SwappedDataBytes[1] = (uint8_T)(A2_V4_B.b_RegisterValue & 254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &A2_V4_B.b_SwappedDataBytes[0], 2U, false, false);
  A2_V4_B.b_SwappedDataBytes[0] = 14U;
  A2_V4_B.b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &A2_V4_B.b_SwappedDataBytes[0], 2U, false, false);
  A2_V4_B.b_SwappedDataBytes[0] = 91U;
  A2_V4_B.b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &A2_V4_B.b_SwappedDataBytes[0], 2U, false, false);
  A2_V4_B.b_SwappedDataBytes[0] = 42U;
  A2_V4_B.b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &A2_V4_B.b_SwappedDataBytes[0], 2U, false, false);
  obj->isSetupComplete = true;
}

static void A2_V4_SystemCore_setup_nlg(dsp_simulink_MovingStandardDe_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->NumChannels = 1;
  obj->_pobj0.isInitialized = 0;
  obj->_pobj0.isInitialized = 0;
  obj->pStatistic = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

static void A2_V4_SystemCore_setup_n(freedomk64f_SCIRead_A2_V4_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  A2_V4_B.TxPinLoc = MW_UNDEFINED_VALUE;
  A2_V4_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&A2_V4_B.SCIModuleLoc, false, 10U,
    A2_V4_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  A2_V4_B.StopBitsValue = MW_SCI_STOPBITS_1;
  A2_V4_B.ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, A2_V4_B.ParityValue,
                        A2_V4_B.StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void A2_V4_step(void)
{
  g_dsp_internal_SlidingWindowV_T *obj;
  int32_T i;
  uint32_T qY;
  uint32_T qY_tmp;
  int16_T b_RegisterValue[3];
  uint16_T rtb_Sum;
  uint8_T output_raw[6];
  uint8_T b_x[2];
  uint8_T y[2];
  uint8_T status;
  boolean_T DigitalRead;
  boolean_T OR3;
  boolean_T rtb_PushButton_0;

  /* MATLABSystem: '<S1>/Serial Receive' */
  if (A2_V4_DW.obj_ob.SampleTime != A2_V4_P.SerialReceive_SampleTime) {
    A2_V4_DW.obj_ob.SampleTime = A2_V4_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(A2_V4_DW.obj_ob.MW_SCIHANDLE, &A2_V4_B.RxDataLocChar[0],
    84U);
  memcpy((void *)&A2_V4_B.RxData[0], (void *)&A2_V4_B.RxDataLocChar[0],
         (uint32_T)((size_t)84 * sizeof(uint8_T)));

  /* MATLABSystem: '<S1>/ATR_SIGNAL' */
  if (A2_V4_DW.obj_l.SampleTime != A2_V4_P.ATR_SIGNAL_SampleTime) {
    A2_V4_DW.obj_l.SampleTime = A2_V4_P.ATR_SIGNAL_SampleTime;
  }

  MW_AnalogIn_Start(A2_V4_DW.obj_l.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(A2_V4_DW.obj_l.MW_ANALOGIN_HANDLE,
    &A2_V4_B.ATR_SIGNAL_f, 7);

  /* End of MATLABSystem: '<S1>/ATR_SIGNAL' */

  /* MATLABSystem: '<S1>/VENT_SIGNAL' */
  if (A2_V4_DW.obj_o.SampleTime != A2_V4_P.VENT_SIGNAL_SampleTime) {
    A2_V4_DW.obj_o.SampleTime = A2_V4_P.VENT_SIGNAL_SampleTime;
  }

  MW_AnalogIn_Start(A2_V4_DW.obj_o.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(A2_V4_DW.obj_o.MW_ANALOGIN_HANDLE,
    &A2_V4_B.VENT_SIGNAL_c, 7);

  /* End of MATLABSystem: '<S1>/VENT_SIGNAL' */

  /* Chart: '<S1>/From DCM' incorporates:
   *  MATLABSystem: '<S1>/Serial Receive'
   */
  if (A2_V4_DW.is_active_c1_A2_V4 == 0U) {
    A2_V4_DW.is_active_c1_A2_V4 = 1U;
    A2_V4_DW.is_c1_A2_V4 = A2_V4_IN_Default;
    A2_V4_B.MODE_i = 6U;
    A2_V4_B.LOWER_RATE_LIMIT_l = 60U;
    A2_V4_B.UPPER_RATE_LIMIT_j = 120U;
    A2_V4_B.PVARP_a = 250U;
    A2_V4_B.AV_DELAY_c = 150U;
    A2_V4_B.REACT_TIME_n = 10U;
    A2_V4_B.RESP_FACTOR_k = 16U;
    A2_V4_B.ACTIVITY_THRESH_j = 0.2;
    A2_V4_B.RCVR_TIME_n = 20U;
    A2_V4_B.MAX_SENSE_l = 180U;
    A2_V4_B.ATR_AMP_a = 3.5;
    A2_V4_B.ATR_PW_a = 10U;
    A2_V4_B.ARP_i = 200U;
    A2_V4_B.ATR_THRESH_o = 1.8;
    A2_V4_B.ATR_SENSE_n = 2.4;
    A2_V4_B.VENT_AMP_n = 3.5;
    A2_V4_B.VENT_PW_g = 10U;
    A2_V4_B.VRP_b = 200U;
    A2_V4_B.VENT_THRESH_k = 2.2;
    A2_V4_B.VENT_SENSE_d = 2.4;
  } else {
    switch (A2_V4_DW.is_c1_A2_V4) {
     case A2_V4_IN_Default:
      A2_V4_DW.is_c1_A2_V4 = A2_V4_IN_STANDBY;
      break;

     case A2_V4_IN_ECHO_PARAM:
      A2_V4_DW.is_c1_A2_V4 = A2_V4_IN_STANDBY;
      break;

     case A2_V4_IN_SET_PARAM:
      A2_V4_DW.is_c1_A2_V4 = A2_V4_IN_STANDBY;
      break;

     default:
      /* case IN_STANDBY: */
      if (status == 0) {
        if (A2_V4_B.RxData[0] == 22) {
          switch (A2_V4_B.RxData[1]) {
           case 34:
            A2_V4_DW.is_c1_A2_V4 = A2_V4_IN_ECHO_PARAM;
            DCM_SEND();
            break;

           case 85:
            A2_V4_DW.is_c1_A2_V4 = A2_V4_IN_SET_PARAM;
            memcpy((void *)&A2_V4_B.MODE_i, (void *)&A2_V4_B.RxData[2],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&A2_V4_B.LOWER_RATE_LIMIT_l, (void *)&A2_V4_B.RxData
                   [4], (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&A2_V4_B.UPPER_RATE_LIMIT_j, (void *)&A2_V4_B.RxData
                   [6], (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&A2_V4_B.PVARP_a, (void *)&A2_V4_B.RxData[8],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&A2_V4_B.AV_DELAY_c, (void *)&A2_V4_B.RxData[10],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&A2_V4_B.REACT_TIME_n, (void *)&A2_V4_B.RxData[12],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&A2_V4_B.RESP_FACTOR_k, (void *)&A2_V4_B.RxData[14],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&A2_V4_B.ACTIVITY_THRESH_j, (void *)&A2_V4_B.RxData
                   [16], (uint32_T)((size_t)1 * sizeof(real_T)));
            memcpy((void *)&A2_V4_B.RCVR_TIME_n, (void *)&A2_V4_B.RxData[24],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&A2_V4_B.MAX_SENSE_l, (void *)&A2_V4_B.RxData[26],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&A2_V4_B.ATR_AMP_a, (void *)&A2_V4_B.RxData[28],
                   (uint32_T)((size_t)1 * sizeof(real_T)));
            memcpy((void *)&A2_V4_B.ATR_PW_a, (void *)&A2_V4_B.RxData[36],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&A2_V4_B.ARP_i, (void *)&A2_V4_B.RxData[38],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&A2_V4_B.ATR_THRESH_o, (void *)&A2_V4_B.RxData[40],
                   (uint32_T)((size_t)1 * sizeof(real_T)));
            memcpy((void *)&A2_V4_B.ATR_SENSE_n, (void *)&A2_V4_B.RxData[48],
                   (uint32_T)((size_t)1 * sizeof(real_T)));
            memcpy((void *)&A2_V4_B.VENT_AMP_n, (void *)&A2_V4_B.RxData[56],
                   (uint32_T)((size_t)1 * sizeof(real_T)));
            memcpy((void *)&A2_V4_B.VENT_PW_g, (void *)&A2_V4_B.RxData[64],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&A2_V4_B.VRP_b, (void *)&A2_V4_B.RxData[66],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            memcpy((void *)&A2_V4_B.VENT_THRESH_k, (void *)&A2_V4_B.RxData[68],
                   (uint32_T)((size_t)1 * sizeof(real_T)));
            memcpy((void *)&A2_V4_B.VENT_SENSE_d, (void *)&A2_V4_B.RxData[76],
                   (uint32_T)((size_t)1 * sizeof(real_T)));
            break;

           default:
            A2_V4_DW.is_c1_A2_V4 = A2_V4_IN_STANDBY;
            break;
          }
        } else {
          A2_V4_DW.is_c1_A2_V4 = A2_V4_IN_STANDBY;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S1>/From DCM' */

  /* MATLABSystem: '<S1>/Digital Read' */
  if (A2_V4_DW.obj_m.SampleTime != A2_V4_P.DigitalRead_SampleTime) {
    A2_V4_DW.obj_m.SampleTime = A2_V4_P.DigitalRead_SampleTime;
  }

  /* MATLABSystem: '<S1>/Digital Read' */
  DigitalRead = MW_digitalIO_read(A2_V4_DW.obj_m.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S1>/Digital Read3' */
  if (A2_V4_DW.obj_h.SampleTime != A2_V4_P.DigitalRead3_SampleTime) {
    A2_V4_DW.obj_h.SampleTime = A2_V4_P.DigitalRead3_SampleTime;
  }

  OR3 = MW_digitalIO_read(A2_V4_DW.obj_h.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S1>/Push Button' */
  if (A2_V4_DW.obj_e.SampleTime != A2_V4_P.PushButton_SampleTime) {
    A2_V4_DW.obj_e.SampleTime = A2_V4_P.PushButton_SampleTime;
  }

  rtb_PushButton_0 = MW_digitalIO_read(A2_V4_DW.obj_e.MW_DIGITALIO_HANDLE);

  /* Logic: '<S1>/OR3' incorporates:
   *  MATLABSystem: '<S1>/Digital Read3'
   *  MATLABSystem: '<S1>/Push Button'
   */
  OR3 = (rtb_PushButton_0 || OR3);

  /* Product: '<S3>/Divide' incorporates:
   *  Constant: '<S3>/msec//min'
   */
  A2_V4_B.Divide = A2_V4_P.msecmin_Value / (real_T)A2_V4_B.LOWER_RATE_LIMIT_l;

  /* Gain: '<S7>/Multiply' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Product: '<S7>/ATR_CYCLE'
   */
  A2_V4_B.Multiply = A2_V4_B.ATR_AMP_a / A2_V4_P.Constant1_Value *
    A2_V4_P.Multiply_Gain;

  /* Gain: '<S8>/Multiply' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Product: '<S8>/Duty Cycle'
   */
  A2_V4_B.Multiply_i = A2_V4_B.VENT_AMP_n / A2_V4_P.Constant1_Value *
    A2_V4_P.Multiply_Gain_l;

  /* Outputs for Enabled SubSystem: '<S3>/Subsystem2' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  /* Logic: '<S3>/AND' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S12>/Compare'
   */
  if ((A2_V4_B.MODE_i > A2_V4_P.CompareToConstant_const) && (A2_V4_B.MODE_i !=
       A2_V4_P.CompareToConstant1_const)) {
    /* MATLABSystem: '<S15>/FXOS8700 6-Axes Sensor1' */
    if (A2_V4_DW.obj_p.SampleTime != A2_V4_P.FXOS87006AxesSensor1_SampleTime) {
      A2_V4_DW.obj_p.SampleTime = A2_V4_P.FXOS87006AxesSensor1_SampleTime;
    }

    status = 1U;
    status = MW_I2C_MasterWrite(A2_V4_DW.obj_p.i2cobj.MW_I2C_HANDLE, 29U,
      &status, 1U, true, false);
    if (status == 0) {
      MW_I2C_MasterRead(A2_V4_DW.obj_p.i2cobj.MW_I2C_HANDLE, 29U, &output_raw[0],
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

    A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 = (real_T)A2_V4_bitshift_anonFcn1
      (b_RegisterValue[0], -2.0) * 2.0 * 0.244 / 1000.0;
    A2_V4_B.rtb_FXOS87006AxesSensor1_idx_1 = (real_T)A2_V4_bitshift_anonFcn1
      (b_RegisterValue[1], -2.0) * 2.0 * 0.244 / 1000.0;
    A2_V4_B.rtb_FXOS87006AxesSensor1_idx_2 = (real_T)A2_V4_bitshift_anonFcn1
      (b_RegisterValue[2], -2.0) * 2.0 * 0.244 / 1000.0;

    /* End of MATLABSystem: '<S15>/FXOS8700 6-Axes Sensor1' */

    /* Sqrt: '<S15>/Sqrt' incorporates:
     *  Math: '<S15>/Math Function'
     *  Math: '<S15>/Math Function1'
     *  Math: '<S15>/Math Function2'
     *  Sum: '<S15>/Add'
     *
     * About '<S15>/Math Function':
     *  Operator: magnitude^2
     *
     * About '<S15>/Math Function1':
     *  Operator: magnitude^2
     *
     * About '<S15>/Math Function2':
     *  Operator: magnitude^2
     */
    A2_V4_B.Sqrt = sqrt((A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 *
                         A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 +
                         A2_V4_B.rtb_FXOS87006AxesSensor1_idx_1 *
                         A2_V4_B.rtb_FXOS87006AxesSensor1_idx_1) +
                        A2_V4_B.rtb_FXOS87006AxesSensor1_idx_2 *
                        A2_V4_B.rtb_FXOS87006AxesSensor1_idx_2);

    /* MATLABSystem: '<S15>/Moving Standard Deviation' */
    if (A2_V4_DW.obj.TunablePropsChanged) {
      A2_V4_DW.obj.TunablePropsChanged = false;
    }

    obj = A2_V4_DW.obj.pStatistic;
    if (obj->isInitialized != 1) {
      obj->isSetupComplete = false;
      obj->isInitialized = 1;
      for (i = 0; i < 128; i++) {
        obj->pReverseSamples[i] = 0.0;
      }

      for (i = 0; i < 128; i++) {
        obj->pReverseT[i] = 0.0;
      }

      for (i = 0; i < 128; i++) {
        obj->pReverseS[i] = 0.0;
      }

      obj->pT = 0.0;
      obj->pS = 0.0;
      obj->pM = 0.0;
      obj->pCounter = 0.0;
      obj->pModValueRev = 0.0;
      obj->isSetupComplete = true;
      for (i = 0; i < 128; i++) {
        obj->pReverseSamples[i] = 0.0;
      }

      for (i = 0; i < 128; i++) {
        obj->pReverseT[i] = 0.0;
      }

      for (i = 0; i < 128; i++) {
        obj->pReverseS[i] = 0.0;
      }

      obj->pT = 0.0;
      obj->pS = 0.0;
      obj->pM = 0.0;
      obj->pCounter = 1.0;
      obj->pModValueRev = 0.0;
    }

    for (i = 0; i < 128; i++) {
      A2_V4_B.reverseSamples[i] = obj->pReverseSamples[i];
    }

    for (i = 0; i < 128; i++) {
      A2_V4_B.x[i] = obj->pReverseT[i];
    }

    for (i = 0; i < 128; i++) {
      A2_V4_B.reverseS[i] = obj->pReverseS[i];
    }

    A2_V4_B.T = obj->pT;
    A2_V4_B.S = obj->pS;
    A2_V4_B.M = obj->pM;
    A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 = obj->pCounter;
    A2_V4_B.rtb_FXOS87006AxesSensor1_idx_1 = obj->pModValueRev;
    A2_V4_B.rtb_FXOS87006AxesSensor1_idx_2 = 0.0;
    A2_V4_B.T += A2_V4_B.Sqrt;
    A2_V4_B.Mprev = A2_V4_B.M;
    A2_V4_B.M += 1.0 / A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 * (A2_V4_B.Sqrt -
      A2_V4_B.M);
    A2_V4_B.Mprev = A2_V4_B.Sqrt - A2_V4_B.Mprev;
    A2_V4_B.S += (A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 - 1.0) * A2_V4_B.Mprev *
      A2_V4_B.Mprev / A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0;
    if (A2_V4_B.rtb_FXOS87006AxesSensor1_idx_1 == 0.0) {
      A2_V4_B.rtb_FXOS87006AxesSensor1_idx_2 = (128.0 -
        A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0) /
        A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 * A2_V4_B.T - A2_V4_B.x[(int32_T)
        (128.0 - A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0) - 1];
      A2_V4_B.rtb_FXOS87006AxesSensor1_idx_2 =
        (A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 / (((128.0 -
            A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0) +
           A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0) * (128.0 -
           A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0)) *
         (A2_V4_B.rtb_FXOS87006AxesSensor1_idx_2 *
          A2_V4_B.rtb_FXOS87006AxesSensor1_idx_2) + (A2_V4_B.reverseS[(int32_T)
          (128.0 - A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0) - 1] + A2_V4_B.S)) /
        127.0;
    }

    A2_V4_B.reverseSamples[(int32_T)(128.0 -
      A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0) - 1] = A2_V4_B.Sqrt;
    if (A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 < 127.0) {
      A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0++;
    } else {
      A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 = 1.0;
      memcpy(&A2_V4_B.x[0], &A2_V4_B.reverseSamples[0], sizeof(real_T) << 7U);
      A2_V4_B.Sqrt = 0.0;
      A2_V4_B.T = 0.0;
      for (i = 0; i < 127; i++) {
        A2_V4_B.S = A2_V4_B.reverseSamples[i];
        A2_V4_B.x[i + 1] += A2_V4_B.x[i];
        A2_V4_B.M = A2_V4_B.Sqrt;
        A2_V4_B.Sqrt += 1.0 / ((real_T)i + 1.0) * (A2_V4_B.S - A2_V4_B.Sqrt);
        A2_V4_B.S -= A2_V4_B.M;
        A2_V4_B.T += (((real_T)i + 1.0) - 1.0) * A2_V4_B.S * A2_V4_B.S /
          ((real_T)i + 1.0);
        A2_V4_B.reverseS[i] = A2_V4_B.T;
      }

      A2_V4_B.T = 0.0;
      A2_V4_B.S = 0.0;
      A2_V4_B.M = 0.0;
    }

    for (i = 0; i < 128; i++) {
      obj->pReverseSamples[i] = A2_V4_B.reverseSamples[i];
    }

    for (i = 0; i < 128; i++) {
      obj->pReverseT[i] = A2_V4_B.x[i];
    }

    for (i = 0; i < 128; i++) {
      obj->pReverseS[i] = A2_V4_B.reverseS[i];
    }

    obj->pT = A2_V4_B.T;
    obj->pS = A2_V4_B.S;
    obj->pM = A2_V4_B.M;
    obj->pCounter = A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0;
    if (A2_V4_B.rtb_FXOS87006AxesSensor1_idx_1 > 0.0) {
      obj->pModValueRev = A2_V4_B.rtb_FXOS87006AxesSensor1_idx_1 - 1.0;
    } else {
      obj->pModValueRev = 0.0;
    }

    /* MATLABSystem: '<S15>/Moving Standard Deviation' */
    A2_V4_B.MovingStandardDeviation = sqrt
      (A2_V4_B.rtb_FXOS87006AxesSensor1_idx_2);
  }

  /* End of Logic: '<S3>/AND' */
  /* End of Outputs for SubSystem: '<S3>/Subsystem2' */

  /* Sum: '<S16>/Sum' incorporates:
   *  Constant: '<S14>/Constant'
   *  Product: '<S14>/Divide'
   *  Product: '<S16>/Product'
   *  Sum: '<S14>/Subtract'
   */
  A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 = (real_T)(uint16_T)
    (A2_V4_B.MAX_SENSE_l - A2_V4_B.LOWER_RATE_LIMIT_l) / A2_V4_P.Constant_Value *
    (real_T)A2_V4_B.RESP_FACTOR_k + (real_T)A2_V4_B.LOWER_RATE_LIMIT_l;
  A2_V4_B.rtb_FXOS87006AxesSensor1_idx_1 = fabs
    (A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0);
  if (A2_V4_B.rtb_FXOS87006AxesSensor1_idx_1 < 4.503599627370496E+15) {
    if (A2_V4_B.rtb_FXOS87006AxesSensor1_idx_1 >= 0.5) {
      A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 = floor
        (A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 + 0.5);
    } else {
      A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 *= 0.0;
    }
  }

  if (rtIsNaN(A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0) || rtIsInf
      (A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0)) {
    A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 = 0.0;
  } else {
    A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 = fmod
      (A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0, 65536.0);
  }

  rtb_Sum = (uint16_T)(A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 < 0.0 ? (int32_T)
                       (uint16_T)-(int16_T)(uint16_T)
                       -A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 : (int32_T)
                       (uint16_T)A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0);

  /* End of Sum: '<S16>/Sum' */

  /* Chart: '<S3>/Chart1' */
  if (A2_V4_DW.temporalCounter_i1_d < 1023U) {
    A2_V4_DW.temporalCounter_i1_d++;
  }

  if (A2_V4_DW.is_active_c4_A2_V4 == 0U) {
    A2_V4_DW.is_active_c4_A2_V4 = 1U;
    qY_tmp = (uint32_T)rtb_Sum - /*MW:OvSatOk*/ A2_V4_B.LOWER_RATE_LIMIT_l;
    qY = qY_tmp;
    if (qY_tmp > rtb_Sum) {
      qY = 0U;
      qY_tmp = 0U;
    }

    if (A2_V4_B.REACT_TIME_n == 0) {
      if ((uint16_T)qY == 0) {
        A2_V4_DW.step_up = 0U;
      } else {
        A2_V4_DW.step_up = MAX_uint16_T;
      }
    } else {
      A2_V4_DW.step_up = (uint16_T)((uint32_T)(uint16_T)qY /
        A2_V4_B.REACT_TIME_n);
      rtb_Sum = (uint16_T)((uint32_T)(uint16_T)qY - (uint16_T)((uint32_T)
        A2_V4_DW.step_up * A2_V4_B.REACT_TIME_n));
      if ((rtb_Sum > 0) && (rtb_Sum >= (int32_T)((uint32_T)A2_V4_B.REACT_TIME_n >>
            1) + (A2_V4_B.REACT_TIME_n & 1))) {
        A2_V4_DW.step_up++;
      }
    }

    if (A2_V4_B.RCVR_TIME_n == 0) {
      if ((uint16_T)qY_tmp == 0) {
        A2_V4_DW.step_down = 0U;
      } else {
        A2_V4_DW.step_down = MAX_uint16_T;
      }
    } else {
      A2_V4_DW.step_down = (uint16_T)((uint32_T)(uint16_T)qY_tmp /
        A2_V4_B.RCVR_TIME_n);
      rtb_Sum = (uint16_T)((uint32_T)(uint16_T)qY_tmp - (uint16_T)((uint32_T)
        A2_V4_DW.step_down * A2_V4_B.RCVR_TIME_n));
      if ((rtb_Sum > 0) && (rtb_Sum >= (int32_T)((uint32_T)A2_V4_B.RCVR_TIME_n >>
            1) + (A2_V4_B.RCVR_TIME_n & 1))) {
        A2_V4_DW.step_down++;
      }
    }

    A2_V4_DW.is_c4_A2_V4 = A2_V4_IN_Start1;
    A2_V4_B.ADAPTED_RATE = A2_V4_B.LOWER_RATE_LIMIT_l;
  } else {
    switch (A2_V4_DW.is_c4_A2_V4) {
     case A2_V4_IN_S2FAIL1:
      if (A2_V4_B.ADAPTED_RATE <= A2_V4_B.LOWER_RATE_LIMIT_l) {
        A2_V4_DW.is_c4_A2_V4 = A2_V4_IN_Start1;
        A2_V4_B.ADAPTED_RATE = A2_V4_B.LOWER_RATE_LIMIT_l;
      } else if ((A2_V4_DW.temporalCounter_i1_d >= 1000U) &&
                 (A2_V4_B.ADAPTED_RATE >= A2_V4_B.LOWER_RATE_LIMIT_l)) {
        A2_V4_DW.is_c4_A2_V4 = A2_V4_IN_S2FAIL1;
        A2_V4_DW.temporalCounter_i1_d = 0U;
        qY = (uint32_T)A2_V4_B.ADAPTED_RATE - /*MW:OvSatOk*/ A2_V4_DW.step_down;
        if (qY > A2_V4_B.ADAPTED_RATE) {
          qY = 0U;
        }

        A2_V4_B.ADAPTED_RATE = (uint16_T)qY;
      } else if (A2_V4_B.MovingStandardDeviation >= A2_V4_B.ACTIVITY_THRESH_j) {
        A2_V4_DW.is_c4_A2_V4 = A2_V4_IN_S4;
        A2_V4_DW.temporalCounter_i1_d = 0U;
        qY = (uint32_T)A2_V4_B.ADAPTED_RATE + A2_V4_DW.step_up;
        if (qY > 65535U) {
          qY = 65535U;
        }

        A2_V4_B.ADAPTED_RATE = (uint16_T)qY;
      }
      break;

     case A2_V4_IN_S3:
      if (A2_V4_B.MovingStandardDeviation < A2_V4_B.ACTIVITY_THRESH_j) {
        A2_V4_DW.is_c4_A2_V4 = A2_V4_IN_S2FAIL1;
        A2_V4_DW.temporalCounter_i1_d = 0U;
        qY = (uint32_T)A2_V4_B.ADAPTED_RATE - /*MW:OvSatOk*/ A2_V4_DW.step_down;
        if (qY > A2_V4_B.ADAPTED_RATE) {
          qY = 0U;
        }

        A2_V4_B.ADAPTED_RATE = (uint16_T)qY;
      } else if (A2_V4_B.MovingStandardDeviation > A2_V4_B.ACTIVITY_THRESH_j) {
        A2_V4_DW.is_c4_A2_V4 = A2_V4_IN_S3;
        A2_V4_B.ADAPTED_RATE = rtb_Sum;
      }
      break;

     case A2_V4_IN_S4:
      if ((A2_V4_DW.temporalCounter_i1_d >= 1000U) && (A2_V4_B.ADAPTED_RATE <=
           rtb_Sum)) {
        A2_V4_DW.is_c4_A2_V4 = A2_V4_IN_S4;
        A2_V4_DW.temporalCounter_i1_d = 0U;
        qY = (uint32_T)A2_V4_B.ADAPTED_RATE + A2_V4_DW.step_up;
        if (qY > 65535U) {
          qY = 65535U;
        }

        A2_V4_B.ADAPTED_RATE = (uint16_T)qY;
      } else if (A2_V4_B.MovingStandardDeviation < A2_V4_B.ACTIVITY_THRESH_j) {
        A2_V4_DW.is_c4_A2_V4 = A2_V4_IN_S_FAILSAFE1;
        A2_V4_DW.temporalCounter_i1_d = 0U;
        qY = (uint32_T)A2_V4_B.ADAPTED_RATE - /*MW:OvSatOk*/ A2_V4_DW.step_up;
        if (qY > A2_V4_B.ADAPTED_RATE) {
          qY = 0U;
        }

        A2_V4_B.ADAPTED_RATE = (uint16_T)qY;
      } else if (A2_V4_B.ADAPTED_RATE >= rtb_Sum) {
        A2_V4_DW.is_c4_A2_V4 = A2_V4_IN_S3;
        A2_V4_B.ADAPTED_RATE = rtb_Sum;
      }
      break;

     case A2_V4_IN_S_FAILSAFE1:
      if (A2_V4_B.MovingStandardDeviation >= A2_V4_B.ACTIVITY_THRESH_j) {
        A2_V4_DW.is_c4_A2_V4 = A2_V4_IN_S4;
        A2_V4_DW.temporalCounter_i1_d = 0U;
        qY = (uint32_T)A2_V4_B.ADAPTED_RATE + A2_V4_DW.step_up;
        if (qY > 65535U) {
          qY = 65535U;
        }

        A2_V4_B.ADAPTED_RATE = (uint16_T)qY;
      } else if (A2_V4_DW.temporalCounter_i1_d >= 1000U) {
        A2_V4_DW.is_c4_A2_V4 = A2_V4_IN_S2FAIL1;
        A2_V4_DW.temporalCounter_i1_d = 0U;
        qY = (uint32_T)A2_V4_B.ADAPTED_RATE - /*MW:OvSatOk*/ A2_V4_DW.step_down;
        if (qY > A2_V4_B.ADAPTED_RATE) {
          qY = 0U;
        }

        A2_V4_B.ADAPTED_RATE = (uint16_T)qY;
      }
      break;

     default:
      /* case IN_Start1: */
      if (A2_V4_B.MovingStandardDeviation >= A2_V4_B.ACTIVITY_THRESH_j) {
        A2_V4_DW.is_c4_A2_V4 = A2_V4_IN_S4;
        A2_V4_DW.temporalCounter_i1_d = 0U;
        qY = (uint32_T)A2_V4_B.ADAPTED_RATE + A2_V4_DW.step_up;
        if (qY > 65535U) {
          qY = 65535U;
        }

        A2_V4_B.ADAPTED_RATE = (uint16_T)qY;
      } else if (A2_V4_B.MovingStandardDeviation < A2_V4_B.ACTIVITY_THRESH_j) {
        A2_V4_DW.is_c4_A2_V4 = A2_V4_IN_Start1;
        A2_V4_B.ADAPTED_RATE = A2_V4_B.LOWER_RATE_LIMIT_l;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart1' */

  /* Product: '<S13>/Divide1' incorporates:
   *  Constant: '<S13>/Constant2'
   */
  A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0 = A2_V4_P.Constant2_Value / (real_T)
    A2_V4_B.ADAPTED_RATE;

  /* Chart: '<S3>/Chart' */
  if (A2_V4_DW.temporalCounter_i1 < MAX_uint32_T) {
    A2_V4_DW.temporalCounter_i1++;
  }

  if (A2_V4_DW.is_active_c3_A2_V4 == 0U) {
    A2_V4_DW.is_active_c3_A2_V4 = 1U;
    A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_Start;
  } else {
    switch (A2_V4_DW.is_c3_A2_V4) {
     case A2_V4_IN_CHARGING:
      A2_V4_CHARGING(&A2_V4_B.Multiply, &DigitalRead, &A2_V4_B.Divide);
      break;

     case A2_V4_IN_DISCHARGING:
      if (A2_V4_DW.temporalCounter_i1 >= A2_V4_B.ATR_PW_a) {
        A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_PROXY;
        A2_V4_DW.temporalCounter_i1 = 0U;
      } else {
        A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
      }
      break;

     case A2_V4_IN_PROXY:
      A2_V4_PROXY(&A2_V4_B.Multiply);
      break;

     case A2_V4_IN_CHARGING_g:
      A2_V4_CHARGING_i(&A2_V4_B.Multiply, &DigitalRead,
                       &A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0);
      break;

     case A2_V4_IN_DISCHARGING_g:
      if (A2_V4_DW.temporalCounter_i1 >= A2_V4_B.ATR_PW_a) {
        A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_PROXY_p;
        A2_V4_DW.temporalCounter_i1 = 0U;
      } else {
        A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
      }
      break;

     case A2_V4_IN_PROXY_p:
      A2_V4_PROXY_d(&A2_V4_B.Multiply);
      break;

     case A2_V4_IN_CHARGING_gl:
      A2_V4_CHARGING_i5(&A2_V4_B.Multiply, &A2_V4_B.Divide);
      break;

     case A2_V4_IN_DISCHARGING_go:
      if (A2_V4_DW.temporalCounter_i1 >= A2_V4_B.ATR_PW_a) {
        A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_CHARGING_gl;
        A2_V4_DW.temporalCounter_i1 = 0U;
      } else {
        A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
      }
      break;

     case A2_V4_IN_CHARGING_gln:
      A2_V4_CHARGING_i53(&A2_V4_B.Multiply,
                         &A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0);
      break;

     case A2_V4_IN_DISCHARGING_gob:
      if (A2_V4_DW.temporalCounter_i1 >= A2_V4_B.ATR_PW_a) {
        A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_CHARGING_gln;
        A2_V4_DW.temporalCounter_i1 = 0U;
      } else {
        A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
      }
      break;

     case A2_V4_IN_ATR_CHARGING:
      qY = (uint32_T)A2_V4_B.AV_DELAY_c - /*MW:OvSatOk*/ A2_V4_B.ATR_PW_a;
      if (qY > A2_V4_B.AV_DELAY_c) {
        qY = 0U;
      }

      if (A2_V4_DW.temporalCounter_i1 >= qY) {
        A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_VENT_DISCHARGING;
        A2_V4_DW.temporalCounter_i1 = 0U;
      } else {
        A2_V4_B.PACING_REF_PWM = A2_V4_B.Multiply;
        A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
        A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.ATR_GND_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
      }
      break;

     case A2_V4_IN_ATR_DISCHARGING:
      if (A2_V4_DW.temporalCounter_i1 >= A2_V4_B.ATR_PW_a) {
        A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_ATR_CHARGING;
        A2_V4_DW.temporalCounter_i1 = 0U;
      } else {
        A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
      }
      break;

     case A2_V4_IN_VENT_CHARGING:
      A2_V4_VENT_CHARGING(&A2_V4_B.Multiply_i, &A2_V4_B.Divide);
      break;

     case A2_V4_IN_VENT_DISCHARGING:
      if (A2_V4_DW.temporalCounter_i1 >= A2_V4_B.VENT_PW_g) {
        A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_VENT_CHARGING;
        A2_V4_DW.temporalCounter_i1 = 0U;
      } else {
        A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.HIGH;
      }
      break;

     case A2_V4_IN_ATR_CHARGING1:
      qY = (uint32_T)A2_V4_B.AV_DELAY_c - /*MW:OvSatOk*/ A2_V4_B.VENT_PW_g;
      if (qY > A2_V4_B.AV_DELAY_c) {
        qY = 0U;
      }

      if (A2_V4_DW.temporalCounter_i1 >= qY) {
        A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_VENT_DISCHARGING1;
        A2_V4_DW.temporalCounter_i1 = 0U;
      } else {
        A2_V4_B.PACING_REF_PWM = A2_V4_B.Multiply;
        A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
        A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.ATR_GND_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
      }
      break;

     case A2_V4_IN_ATR_DISCHARGING1:
      if (A2_V4_DW.temporalCounter_i1 >= A2_V4_B.ATR_PW_a) {
        A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_ATR_CHARGING1;
        A2_V4_DW.temporalCounter_i1 = 0U;
      } else {
        A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.LOW;
      }
      break;

     case A2_V4_IN_VENT_CHARGING1:
      A2_V4_VENT_CHARGING1(&A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0,
                           &A2_V4_B.Multiply_i);
      break;

     case A2_V4_IN_VENT_DISCHARGING1:
      if (A2_V4_DW.temporalCounter_i1 >= A2_V4_B.VENT_PW_g) {
        A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_VENT_CHARGING1;
        A2_V4_DW.temporalCounter_i1 = 0U;
      } else {
        A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.HIGH;
      }
      break;

     case A2_V4_IN_Start:
      A2_V4_Start();
      break;

     case A2_V4_IN_CHARGING_glnx:
      A2_V4_CHARGING_i53k(&A2_V4_B.Multiply_i, &A2_V4_B.Divide);
      break;

     case A2_V4_IN_DISCHARGING_gob2:
      if (A2_V4_DW.temporalCounter_i1 >= A2_V4_B.VENT_PW_g) {
        A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_CHARGING_glnx;
        A2_V4_DW.temporalCounter_i1 = 0U;
      } else {
        A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.HIGH;
      }
      break;

     case A2_V4_IN_CHARGING_glnx2:
      A2_V4_CHARGING_i53ko(&A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0,
                           &A2_V4_B.Multiply_i);
      break;

     case A2_V4_IN_DISCHARGING_gob2k:
      if (A2_V4_DW.temporalCounter_i1 >= A2_V4_B.VENT_PW_g) {
        A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_CHARGING_glnx2;
        A2_V4_DW.temporalCounter_i1 = 0U;
      } else {
        A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.HIGH;
      }
      break;

     case A2_V4_IN_CHARGING_glnx21:
      A2_V4_CHARGING_i53koo(&A2_V4_B.Multiply_i, &A2_V4_B.Divide, &OR3);
      break;

     case A2_V4_IN_DISCHARGING_gob2kd:
      if (A2_V4_DW.temporalCounter_i1 >= A2_V4_B.VENT_PW_g) {
        A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_PROXY_pt;
        A2_V4_DW.temporalCounter_i1 = 0U;
      } else {
        A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.HIGH;
      }
      break;

     case A2_V4_IN_PROXY_pt:
      A2_V4_PROXY_d0(&A2_V4_B.Multiply_i);
      break;

     case A2_V4_IN_CHARGING_glnx21l:
      A2_V4_CHARGING_i53kooo(&A2_V4_B.rtb_FXOS87006AxesSensor1_idx_0,
        &A2_V4_B.Multiply_i, &OR3);
      break;

     case A2_V4_IN_DISCHARGING_gob2kdy:
      if (A2_V4_DW.temporalCounter_i1 >= A2_V4_B.VENT_PW_g) {
        A2_V4_DW.is_c3_A2_V4 = A2_V4_IN_PROXY_ptm;
        A2_V4_DW.temporalCounter_i1 = 0U;
      } else {
        A2_V4_B.PACE_CHARGE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.PACE_GND_CTRL = A2_V4_DW.HIGH;
        A2_V4_B.ATR_PACE_CTRL = A2_V4_DW.LOW;
        A2_V4_B.ATR_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_ATR_CTRL = A2_V4_DW.LOW;
        A2_V4_B.Z_VENT_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_GND_CTRL = A2_V4_DW.LOW;
        A2_V4_B.VENT_PACE_CTRL = A2_V4_DW.HIGH;
      }
      break;

     default:
      /* case IN_PROXY: */
      A2_V4_PROXY_d0h(&A2_V4_B.Multiply_i);
      break;
    }
  }

  /* End of Chart: '<S3>/Chart' */

  /* MATLABSystem: '<S6>/Digital Write 1' */
  MW_digitalIO_write(A2_V4_DW.obj_pu.MW_DIGITALIO_HANDLE, A2_V4_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S6>/Digital Write 2' */
  MW_digitalIO_write(A2_V4_DW.obj_hi.MW_DIGITALIO_HANDLE, A2_V4_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S6>/Digital Write 3' */
  MW_digitalIO_write(A2_V4_DW.obj_o1.MW_DIGITALIO_HANDLE, A2_V4_B.Z_ATR_CTRL);

  /* MATLABSystem: '<S6>/Digital Write 4' */
  MW_digitalIO_write(A2_V4_DW.obj_og.MW_DIGITALIO_HANDLE, A2_V4_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S6>/Digital Write 5' */
  MW_digitalIO_write(A2_V4_DW.obj_pq.MW_DIGITALIO_HANDLE, A2_V4_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S6>/Digital Write 6' */
  MW_digitalIO_write(A2_V4_DW.obj_n.MW_DIGITALIO_HANDLE, A2_V4_B.Z_VENT_CTRL);

  /* MATLABSystem: '<S6>/Digital Write 7' */
  MW_digitalIO_write(A2_V4_DW.obj_lb.MW_DIGITALIO_HANDLE, A2_V4_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S6>/Digital Write 8' */
  MW_PWM_SetDutyCycle(A2_V4_DW.obj_pd.MW_PWM_HANDLE, A2_V4_B.PACING_REF_PWM);

  /* MATLABSystem: '<S6>/Digital Write 9' */
  MW_digitalIO_write(A2_V4_DW.obj_el.MW_DIGITALIO_HANDLE,
                     A2_V4_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S6>/Digital Write 10' incorporates:
   *  Constant: '<S3>/Constant'
   *  Gain: '<S3>/Gain1'
   *  Product: '<S3>/Divide3'
   */
  MW_PWM_SetDutyCycle(A2_V4_DW.obj_i.MW_PWM_HANDLE, A2_V4_P.Gain1_Gain *
                      (A2_V4_B.ATR_THRESH_o / A2_V4_P.Constant_Value_i));

  /* MATLABSystem: '<S6>/Digital Write 11' incorporates:
   *  Constant: '<S3>/Constant'
   *  Gain: '<S3>/Gain'
   *  Product: '<S3>/Divide2'
   */
  MW_PWM_SetDutyCycle(A2_V4_DW.obj_ni.MW_PWM_HANDLE, A2_V4_P.Gain_Gain *
                      (A2_V4_B.VENT_THRESH_k / A2_V4_P.Constant_Value_i));

  /* MATLABSystem: '<S6>/Digital Write 12' */
  MW_digitalIO_write(A2_V4_DW.obj_eh.MW_DIGITALIO_HANDLE, A2_V4_B.FRONTEND_CTRL);
}

/* Model initialize function */
void A2_V4_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    freedomk64f_AnalogInput_A2_V4_T *obj;
    freedomk64f_DigitalRead_A2_V4_T *obj_0;
    freedomk64f_DigitalWrite_A2_V_T *obj_2;
    freedomk64f_PWMOutput_A2_V4_T *obj_3;
    freedomk64f_PushButton_A2_V4_T *obj_1;
    g_dsp_internal_SlidingWindowV_T *obj_4;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S1>/Function Call' incorporates:
     *  SubSystem: '<S1>/Function Call'
     */
    DCM_SEND_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S1>/Function Call' */

    /* SystemInitialize for Enabled SubSystem: '<S3>/Subsystem2' */
    /* Start for MATLABSystem: '<S15>/FXOS8700 6-Axes Sensor1' */
    A2_V4_DW.obj_p.isInitialized = 0;
    A2_V4_DW.obj_p.i2cobj.isInitialized = 0;
    A2_V4_DW.obj_p.i2cobj.matlabCodegenIsDeleted = false;
    A2_V4_DW.obj_p.matlabCodegenIsDeleted = false;
    A2_V4_DW.obj_p.SampleTime = A2_V4_P.FXOS87006AxesSensor1_SampleTime;
    A2_V4_SystemCore_setup_nl(&A2_V4_DW.obj_p);

    /* Start for MATLABSystem: '<S15>/Moving Standard Deviation' */
    A2_V4_DW.obj.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj.isInitialized = 0;
    A2_V4_DW.obj.NumChannels = -1;
    A2_V4_DW.obj.matlabCodegenIsDeleted = false;
    A2_V4_SystemCore_setup_nlg(&A2_V4_DW.obj);

    /* InitializeConditions for MATLABSystem: '<S15>/Moving Standard Deviation' */
    obj_4 = A2_V4_DW.obj.pStatistic;
    if (obj_4->isInitialized == 1) {
      for (A2_V4_B.i = 0; A2_V4_B.i < 128; A2_V4_B.i++) {
        obj_4->pReverseSamples[A2_V4_B.i] = 0.0;
      }

      for (A2_V4_B.i = 0; A2_V4_B.i < 128; A2_V4_B.i++) {
        obj_4->pReverseT[A2_V4_B.i] = 0.0;
      }

      for (A2_V4_B.i = 0; A2_V4_B.i < 128; A2_V4_B.i++) {
        obj_4->pReverseS[A2_V4_B.i] = 0.0;
      }

      obj_4->pT = 0.0;
      obj_4->pS = 0.0;
      obj_4->pM = 0.0;
      obj_4->pCounter = 1.0;
      obj_4->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S15>/Moving Standard Deviation' */

    /* SystemInitialize for MATLABSystem: '<S15>/Moving Standard Deviation' incorporates:
     *  Outport: '<S15>/Activity'
     */
    A2_V4_B.MovingStandardDeviation = A2_V4_P.Activity_Y0;

    /* End of SystemInitialize for SubSystem: '<S3>/Subsystem2' */

    /* SystemInitialize for Chart: '<S3>/Chart' */
    A2_V4_DW.HIGH = true;
    A2_V4_B.FRONTEND_CTRL = true;

    /* Start for MATLABSystem: '<S1>/Serial Receive' */
    A2_V4_DW.obj_ob.isInitialized = 0;
    A2_V4_DW.obj_ob.matlabCodegenIsDeleted = false;
    A2_V4_DW.obj_ob.SampleTime = A2_V4_P.SerialReceive_SampleTime;
    A2_V4_SystemCore_setup_n(&A2_V4_DW.obj_ob);

    /* Start for MATLABSystem: '<S1>/ATR_SIGNAL' */
    A2_V4_DW.obj_l.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_l.isInitialized = 0;
    A2_V4_DW.obj_l.SampleTime = -1.0;
    A2_V4_DW.obj_l.matlabCodegenIsDeleted = false;
    A2_V4_DW.obj_l.SampleTime = A2_V4_P.ATR_SIGNAL_SampleTime;
    obj = &A2_V4_DW.obj_l;
    A2_V4_DW.obj_l.isSetupComplete = false;
    A2_V4_DW.obj_l.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
    A2_V4_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(A2_V4_DW.obj_l.MW_ANALOGIN_HANDLE,
      A2_V4_B.trigger_val, 0U);
    A2_V4_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/VENT_SIGNAL' */
    A2_V4_DW.obj_o.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_o.isInitialized = 0;
    A2_V4_DW.obj_o.SampleTime = -1.0;
    A2_V4_DW.obj_o.matlabCodegenIsDeleted = false;
    A2_V4_DW.obj_o.SampleTime = A2_V4_P.VENT_SIGNAL_SampleTime;
    obj = &A2_V4_DW.obj_o;
    A2_V4_DW.obj_o.isSetupComplete = false;
    A2_V4_DW.obj_o.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
    A2_V4_B.trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(A2_V4_DW.obj_o.MW_ANALOGIN_HANDLE,
      A2_V4_B.trigger_val, 0U);
    A2_V4_DW.obj_o.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Read' */
    A2_V4_DW.obj_m.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_m.isInitialized = 0;
    A2_V4_DW.obj_m.SampleTime = -1.0;
    A2_V4_DW.obj_m.matlabCodegenIsDeleted = false;
    A2_V4_DW.obj_m.SampleTime = A2_V4_P.DigitalRead_SampleTime;
    obj_0 = &A2_V4_DW.obj_m;
    A2_V4_DW.obj_m.isSetupComplete = false;
    A2_V4_DW.obj_m.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    A2_V4_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Digital Read3' */
    A2_V4_DW.obj_h.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_h.isInitialized = 0;
    A2_V4_DW.obj_h.SampleTime = -1.0;
    A2_V4_DW.obj_h.matlabCodegenIsDeleted = false;
    A2_V4_DW.obj_h.SampleTime = A2_V4_P.DigitalRead3_SampleTime;
    obj_0 = &A2_V4_DW.obj_h;
    A2_V4_DW.obj_h.isSetupComplete = false;
    A2_V4_DW.obj_h.isInitialized = 1;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    A2_V4_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<S1>/Push Button' */
    A2_V4_DW.obj_e.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_e.isInitialized = 0;
    A2_V4_DW.obj_e.SampleTime = -1.0;
    A2_V4_DW.obj_e.matlabCodegenIsDeleted = false;
    A2_V4_DW.obj_e.SampleTime = A2_V4_P.PushButton_SampleTime;
    obj_1 = &A2_V4_DW.obj_e;
    A2_V4_DW.obj_e.isSetupComplete = false;
    A2_V4_DW.obj_e.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(46U, 0);
    A2_V4_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write 1' */
    A2_V4_DW.obj_pu.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_pu.isInitialized = 0;
    A2_V4_DW.obj_pu.matlabCodegenIsDeleted = false;
    obj_2 = &A2_V4_DW.obj_pu;
    A2_V4_DW.obj_pu.isSetupComplete = false;
    A2_V4_DW.obj_pu.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    A2_V4_DW.obj_pu.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write 2' */
    A2_V4_DW.obj_hi.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_hi.isInitialized = 0;
    A2_V4_DW.obj_hi.matlabCodegenIsDeleted = false;
    obj_2 = &A2_V4_DW.obj_hi;
    A2_V4_DW.obj_hi.isSetupComplete = false;
    A2_V4_DW.obj_hi.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    A2_V4_DW.obj_hi.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write 3' */
    A2_V4_DW.obj_o1.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_o1.isInitialized = 0;
    A2_V4_DW.obj_o1.matlabCodegenIsDeleted = false;
    obj_2 = &A2_V4_DW.obj_o1;
    A2_V4_DW.obj_o1.isSetupComplete = false;
    A2_V4_DW.obj_o1.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(4U, 1);
    A2_V4_DW.obj_o1.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write 4' */
    A2_V4_DW.obj_og.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_og.isInitialized = 0;
    A2_V4_DW.obj_og.matlabCodegenIsDeleted = false;
    obj_2 = &A2_V4_DW.obj_og;
    A2_V4_DW.obj_og.isSetupComplete = false;
    A2_V4_DW.obj_og.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    A2_V4_DW.obj_og.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write 5' */
    A2_V4_DW.obj_pq.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_pq.isInitialized = 0;
    A2_V4_DW.obj_pq.matlabCodegenIsDeleted = false;
    obj_2 = &A2_V4_DW.obj_pq;
    A2_V4_DW.obj_pq.isSetupComplete = false;
    A2_V4_DW.obj_pq.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    A2_V4_DW.obj_pq.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write 6' */
    A2_V4_DW.obj_n.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_n.isInitialized = 0;
    A2_V4_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_2 = &A2_V4_DW.obj_n;
    A2_V4_DW.obj_n.isSetupComplete = false;
    A2_V4_DW.obj_n.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(7U, 1);
    A2_V4_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write 7' */
    A2_V4_DW.obj_lb.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_lb.isInitialized = 0;
    A2_V4_DW.obj_lb.matlabCodegenIsDeleted = false;
    obj_2 = &A2_V4_DW.obj_lb;
    A2_V4_DW.obj_lb.isSetupComplete = false;
    A2_V4_DW.obj_lb.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    A2_V4_DW.obj_lb.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write 8' */
    A2_V4_DW.obj_pd.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_pd.isInitialized = 0;
    A2_V4_DW.obj_pd.matlabCodegenIsDeleted = false;
    obj_3 = &A2_V4_DW.obj_pd;
    A2_V4_DW.obj_pd.isSetupComplete = false;
    A2_V4_DW.obj_pd.isInitialized = 1;
    obj_3->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 30.0);
    MW_PWM_Start(A2_V4_DW.obj_pd.MW_PWM_HANDLE);
    A2_V4_DW.obj_pd.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write 9' */
    A2_V4_DW.obj_el.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_el.isInitialized = 0;
    A2_V4_DW.obj_el.matlabCodegenIsDeleted = false;
    obj_2 = &A2_V4_DW.obj_el;
    A2_V4_DW.obj_el.isSetupComplete = false;
    A2_V4_DW.obj_el.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    A2_V4_DW.obj_el.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write 10' */
    A2_V4_DW.obj_i.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_i.isInitialized = 0;
    A2_V4_DW.obj_i.matlabCodegenIsDeleted = false;
    obj_3 = &A2_V4_DW.obj_i;
    A2_V4_DW.obj_i.isSetupComplete = false;
    A2_V4_DW.obj_i.isInitialized = 1;
    obj_3->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 30.0);
    MW_PWM_Start(A2_V4_DW.obj_i.MW_PWM_HANDLE);
    A2_V4_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write 11' */
    A2_V4_DW.obj_ni.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_ni.isInitialized = 0;
    A2_V4_DW.obj_ni.matlabCodegenIsDeleted = false;
    obj_3 = &A2_V4_DW.obj_ni;
    A2_V4_DW.obj_ni.isSetupComplete = false;
    A2_V4_DW.obj_ni.isInitialized = 1;
    obj_3->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 30.0);
    MW_PWM_Start(A2_V4_DW.obj_ni.MW_PWM_HANDLE);
    A2_V4_DW.obj_ni.isSetupComplete = true;

    /* Start for MATLABSystem: '<S6>/Digital Write 12' */
    A2_V4_DW.obj_eh.matlabCodegenIsDeleted = true;
    A2_V4_DW.obj_eh.isInitialized = 0;
    A2_V4_DW.obj_eh.matlabCodegenIsDeleted = false;
    obj_2 = &A2_V4_DW.obj_eh;
    A2_V4_DW.obj_eh.isSetupComplete = false;
    A2_V4_DW.obj_eh.isInitialized = 1;
    obj_2->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    A2_V4_DW.obj_eh.isSetupComplete = true;
  }
}

/* Model terminate function */
void A2_V4_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj;
  g_dsp_internal_SlidingWindowV_T *obj_0;

  /* Terminate for MATLABSystem: '<S1>/Serial Receive' */
  if (!A2_V4_DW.obj_ob.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_ob.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_ob.isInitialized == 1) && A2_V4_DW.obj_ob.isSetupComplete)
    {
      MW_SCI_Close(A2_V4_DW.obj_ob.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Serial Receive' */

  /* Terminate for MATLABSystem: '<S1>/ATR_SIGNAL' */
  if (!A2_V4_DW.obj_l.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_l.isInitialized == 1) && A2_V4_DW.obj_l.isSetupComplete) {
      MW_AnalogIn_Stop(A2_V4_DW.obj_l.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(A2_V4_DW.obj_l.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/ATR_SIGNAL' */

  /* Terminate for MATLABSystem: '<S1>/VENT_SIGNAL' */
  if (!A2_V4_DW.obj_o.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_o.isInitialized == 1) && A2_V4_DW.obj_o.isSetupComplete) {
      MW_AnalogIn_Stop(A2_V4_DW.obj_o.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(A2_V4_DW.obj_o.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/VENT_SIGNAL' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<S1>/Function Call' incorporates:
   *  SubSystem: '<S1>/Function Call'
   */
  DCM_SEND_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<S1>/Function Call' */

  /* Terminate for MATLABSystem: '<S1>/Digital Read' */
  if (!A2_V4_DW.obj_m.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_m.isInitialized == 1) && A2_V4_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(A2_V4_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Read' */

  /* Terminate for MATLABSystem: '<S1>/Digital Read3' */
  if (!A2_V4_DW.obj_h.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_h.isInitialized == 1) && A2_V4_DW.obj_h.isSetupComplete) {
      MW_digitalIO_close(A2_V4_DW.obj_h.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Digital Read3' */

  /* Terminate for MATLABSystem: '<S1>/Push Button' */
  if (!A2_V4_DW.obj_e.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_e.isInitialized == 1) && A2_V4_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(A2_V4_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Push Button' */

  /* Terminate for Enabled SubSystem: '<S3>/Subsystem2' */
  /* Terminate for MATLABSystem: '<S15>/FXOS8700 6-Axes Sensor1' */
  if (!A2_V4_DW.obj_p.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_p.isInitialized == 1) && A2_V4_DW.obj_p.isSetupComplete) {
      MW_I2C_Close(A2_V4_DW.obj_p.i2cobj.MW_I2C_HANDLE);
    }
  }

  obj = &A2_V4_DW.obj_p.i2cobj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/FXOS8700 6-Axes Sensor1' */

  /* Terminate for MATLABSystem: '<S15>/Moving Standard Deviation' */
  if (!A2_V4_DW.obj.matlabCodegenIsDeleted) {
    A2_V4_DW.obj.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj.isInitialized == 1) && A2_V4_DW.obj.isSetupComplete) {
      obj_0 = A2_V4_DW.obj.pStatistic;
      if (obj_0->isInitialized == 1) {
        obj_0->isInitialized = 2;
      }

      A2_V4_DW.obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/Moving Standard Deviation' */
  /* End of Terminate for SubSystem: '<S3>/Subsystem2' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write 1' */
  if (!A2_V4_DW.obj_pu.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_pu.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_pu.isInitialized == 1) && A2_V4_DW.obj_pu.isSetupComplete)
    {
      MW_digitalIO_close(A2_V4_DW.obj_pu.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write 1' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write 2' */
  if (!A2_V4_DW.obj_hi.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_hi.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_hi.isInitialized == 1) && A2_V4_DW.obj_hi.isSetupComplete)
    {
      MW_digitalIO_close(A2_V4_DW.obj_hi.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write 2' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write 3' */
  if (!A2_V4_DW.obj_o1.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_o1.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_o1.isInitialized == 1) && A2_V4_DW.obj_o1.isSetupComplete)
    {
      MW_digitalIO_close(A2_V4_DW.obj_o1.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write 3' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write 4' */
  if (!A2_V4_DW.obj_og.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_og.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_og.isInitialized == 1) && A2_V4_DW.obj_og.isSetupComplete)
    {
      MW_digitalIO_close(A2_V4_DW.obj_og.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write 4' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write 5' */
  if (!A2_V4_DW.obj_pq.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_pq.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_pq.isInitialized == 1) && A2_V4_DW.obj_pq.isSetupComplete)
    {
      MW_digitalIO_close(A2_V4_DW.obj_pq.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write 5' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write 6' */
  if (!A2_V4_DW.obj_n.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_n.isInitialized == 1) && A2_V4_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(A2_V4_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write 6' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write 7' */
  if (!A2_V4_DW.obj_lb.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_lb.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_lb.isInitialized == 1) && A2_V4_DW.obj_lb.isSetupComplete)
    {
      MW_digitalIO_close(A2_V4_DW.obj_lb.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write 7' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write 8' */
  if (!A2_V4_DW.obj_pd.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_pd.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_pd.isInitialized == 1) && A2_V4_DW.obj_pd.isSetupComplete)
    {
      MW_PWM_Stop(A2_V4_DW.obj_pd.MW_PWM_HANDLE);
      MW_PWM_Close(A2_V4_DW.obj_pd.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write 8' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write 9' */
  if (!A2_V4_DW.obj_el.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_el.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_el.isInitialized == 1) && A2_V4_DW.obj_el.isSetupComplete)
    {
      MW_digitalIO_close(A2_V4_DW.obj_el.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write 9' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write 10' */
  if (!A2_V4_DW.obj_i.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_i.isInitialized == 1) && A2_V4_DW.obj_i.isSetupComplete) {
      MW_PWM_Stop(A2_V4_DW.obj_i.MW_PWM_HANDLE);
      MW_PWM_Close(A2_V4_DW.obj_i.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write 10' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write 11' */
  if (!A2_V4_DW.obj_ni.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_ni.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_ni.isInitialized == 1) && A2_V4_DW.obj_ni.isSetupComplete)
    {
      MW_PWM_Stop(A2_V4_DW.obj_ni.MW_PWM_HANDLE);
      MW_PWM_Close(A2_V4_DW.obj_ni.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write 11' */

  /* Terminate for MATLABSystem: '<S6>/Digital Write 12' */
  if (!A2_V4_DW.obj_eh.matlabCodegenIsDeleted) {
    A2_V4_DW.obj_eh.matlabCodegenIsDeleted = true;
    if ((A2_V4_DW.obj_eh.isInitialized == 1) && A2_V4_DW.obj_eh.isSetupComplete)
    {
      MW_digitalIO_close(A2_V4_DW.obj_eh.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/Digital Write 12' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
