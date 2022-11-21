/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: assignment_1.h
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

#ifndef RTW_HEADER_assignment_1_h_
#define RTW_HEADER_assignment_1_h_
#ifndef assignment_1_COMMON_INCLUDES_
#define assignment_1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_PWM.h"
#include "MW_digitalIO.h"
#include "MW_I2C.h"
#endif                                 /* assignment_1_COMMON_INCLUDES_ */

#include "assignment_1_types.h"
#include <stddef.h>
#include <float.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T csumrev[102];
  real_T csum[3];
  real_T Divide2;                      /* '<S9>/Divide2' */
  real_T ARPmsec;                      /* '<S1>/ARP msec' */
  real_T AtrialPluseWidthmsec;         /* '<S1>/Atrial Pluse Width msec' */
  real_T mode;                         /* '<S1>/mode' */
  real_T VRPmsec;                      /* '<S1>/VRP msec' */
  real_T VentricularPluseWidthmsec;    /* '<S1>/Ventricular Pluse Width msec' */
  real_T Gain;                         /* '<S8>/Gain' */
  real_T Gain1;                        /* '<S8>/Gain1' */
  real_T PACING_REF_PWM;               /* '<S4>/4 Modes' */
  real_T MovingAverage[3];             /* '<S3>/Moving Average' */
  real_T cumRevIndex;
  real_T modValueRev;
  real_T z_idx_0;
  real_T z_idx_1;
  real_T z_idx_2;
  real_T rtb_FXOS87006AxesSensor_idx_0;
  real_T rtb_FXOS87006AxesSensor_idx_1;
  real_T rtb_FXOS87006AxesSensor_idx_2;
  boolean_T VENT_CMP_DETECTD1;         /* '<S4>/VENT_CMP_DETECT D1' */
  boolean_T ATR_CMP_DETECTD0;          /* '<S4>/ATR_CMP_DETECT D0' */
  boolean_T Z_VENT_CTRL;               /* '<S4>/4 Modes' */
  boolean_T VENT_PACE_CTRL;            /* '<S4>/4 Modes' */
  boolean_T PACE_GND_CTRL;             /* '<S4>/4 Modes' */
  boolean_T ATR_PACE_CTRL;             /* '<S4>/4 Modes' */
  boolean_T VENT_GND_CTRL;             /* '<S4>/4 Modes' */
  boolean_T Z_ATR_CTRL;                /* '<S4>/4 Modes' */
  boolean_T PACE_CHARGE_CTRL;          /* '<S4>/4 Modes' */
  boolean_T ATR_GND_CTRL;              /* '<S4>/4 Modes' */
} B_assignment_1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_as_T obj; /* '<S3>/Moving Average' */
  freedomk64f_fxos8700_assignme_T obj_f;/* '<S3>/FXOS8700 6-Axes Sensor' */
  freedomk64f_DigitalRead_assig_T obj_i;/* '<S4>/VENT_CMP_DETECT D1' */
  freedomk64f_DigitalRead_assig_T obj_f0;/* '<S4>/ATR_CMP_DETECT D0' */
  freedomk64f_PWMOutput_assignm_T obj_k;/* '<S2>/VENT_CMP_REF_PWM D3' */
  freedomk64f_PWMOutput_assignm_T obj_p;/* '<S2>/PACING_REF_PWM D5' */
  freedomk64f_PWMOutput_assignm_T obj_g;/* '<S2>/ATR_CMP_REF_PWM D6' */
  freedomk64f_DigitalWrite_assi_T obj_d;/* '<S4>/Digital Write1' */
  freedomk64f_DigitalWrite_assi_T obj_i4;/* '<S4>/Digital Write' */
  freedomk64f_DigitalWrite_assi_T obj_m;/* '<S2>/Z_VENT_CTRL D7' */
  freedomk64f_DigitalWrite_assi_T obj_mn;/* '<S2>/Z_ATR_CTRL D4' */
  freedomk64f_DigitalWrite_assi_T obj_ko;/* '<S2>/VENT_PACE_CTRL D9  ' */
  freedomk64f_DigitalWrite_assi_T obj_e;/* '<S2>/VENT_GND_CTRL D12' */
  freedomk64f_DigitalWrite_assi_T obj_df;/* '<S2>/PACE_GND_CTRL D10' */
  freedomk64f_DigitalWrite_assi_T obj_h;/* '<S2>/PACE_CHARGE_CTRL D2' */
  freedomk64f_DigitalWrite_assi_T obj_a;/* '<S2>/FRONTEND_CTRL D13' */
  freedomk64f_DigitalWrite_assi_T obj_pu;/* '<S2>/ATR_PACE_CTRL D8' */
  freedomk64f_DigitalWrite_assi_T obj_o;/* '<S2>/ATR_GND_CTRL D11' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S3>/Scope' */

  uint32_T is_c3_assignment_1;         /* '<S4>/4 Modes' */
  uint32_T is_VOO;                     /* '<S4>/4 Modes' */
  uint32_T is_AOO;                     /* '<S4>/4 Modes' */
  uint32_T is_VVI;                     /* '<S4>/4 Modes' */
  uint32_T is_AAI;                     /* '<S4>/4 Modes' */
  uint32_T temporalCounter_i1;         /* '<S4>/4 Modes' */
  uint8_T is_active_c3_assignment_1;   /* '<S4>/4 Modes' */
} DW_assignment_1_T;

/* Parameters (default storage) */
struct P_assignment_1_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: -1
                                         * Referenced by: '<S3>/FXOS8700 6-Axes Sensor'
                                         */
  real_T ATR_CMP_DETECTD0_SampleTime;  /* Expression: SampleTime
                                        * Referenced by: '<S4>/ATR_CMP_DETECT D0'
                                        */
  real_T VENT_CMP_DETECTD1_SampleTime; /* Expression: SampleTime
                                        * Referenced by: '<S4>/VENT_CMP_DETECT D1'
                                        */
  real_T ppm_Value;                    /* Expression: 120
                                        * Referenced by: '<S1>/ppm'
                                        */
  real_T umin60sec60000msec2_Value;    /* Expression: 60000
                                        * Referenced by: '<S9>/1min = 60sec = 60000msec2'
                                        */
  real_T ARPmsec_Value;                /* Expression: 130
                                        * Referenced by: '<S1>/ARP msec'
                                        */
  real_T AtrialPluseWidthmsec_Value;   /* Expression: 5
                                        * Referenced by: '<S1>/Atrial Pluse Width msec'
                                        */
  real_T mode_Value;                   /* Expression: 3
                                        * Referenced by: '<S1>/mode'
                                        */
  real_T VRPmsec_Value;                /* Expression: 120
                                        * Referenced by: '<S1>/VRP msec'
                                        */
  real_T VentricularPluseWidthmsec_Value;/* Expression: 5
                                          * Referenced by: '<S1>/Ventricular Pluse Width msec'
                                          */
  real_T AtrialAmplitudevolt_Value;    /* Expression: 3.2
                                        * Referenced by: '<S1>/Atrial Amplitude(volt)'
                                        */
  real_T Constant_Value_b;             /* Expression: 5
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T VentricularAmplitude_Value;   /* Expression: 3.5
                                        * Referenced by: '<S1>/Ventricular Amplitude'
                                        */
  real_T Constant1_Value_d;            /* Expression: 5
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Switch_Threshold;             /* Expression: 2
                                        * Referenced by: '<S5>/Switch'
                                        */
  real_T Atrialthresholdvolt_Value;    /* Expression: 2.3
                                        * Referenced by: '<S1>/Atrial threshold(volt)'
                                        */
  real_T Voltage_Value;                /* Expression: 3.3
                                        * Referenced by: '<S1>/Voltage'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 100
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Ventriclethresholdvolt_Value; /* Expression: 2.3
                                        * Referenced by: '<S1>/Ventricle threshold(volt)'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 100
                                        * Referenced by: '<S7>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_assignment_1_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_assignment_1_T assignment_1_P;

/* Block signals (default storage) */
extern B_assignment_1_T assignment_1_B;

/* Block states (default storage) */
extern DW_assignment_1_T assignment_1_DW;

/* Model entry point functions */
extern void assignment_1_initialize(void);
extern void assignment_1_step(void);
extern void assignment_1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_assignment_1_T *const assignment_1_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/mode1' : Unused code path elimination
 * Block '<S1>/mode2' : Unused code path elimination
 * Block '<S1>/mode3' : Unused code path elimination
 * Block '<S1>/mode4' : Unused code path elimination
 * Block '<S1>/mode5' : Unused code path elimination
 * Block '<S1>/upper rate limit' : Unused code path elimination
 * Block '<S3>/Relational Operator' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'assignment_1'
 * '<S1>'   : 'assignment_1/Inputs'
 * '<S2>'   : 'assignment_1/Outputs'
 * '<S3>'   : 'assignment_1/Rate Adaptive'
 * '<S4>'   : 'assignment_1/VOO//AOO//VVI//AAI'
 * '<S5>'   : 'assignment_1/Outputs/sensing control'
 * '<S6>'   : 'assignment_1/VOO//AOO//VVI//AAI/4 Modes'
 * '<S7>'   : 'assignment_1/VOO//AOO//VVI//AAI/Detection PWM'
 * '<S8>'   : 'assignment_1/VOO//AOO//VVI//AAI/Duty cycle calculation'
 * '<S9>'   : 'assignment_1/VOO//AOO//VVI//AAI/Not ~~'
 */
#endif                                 /* RTW_HEADER_assignment_1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
