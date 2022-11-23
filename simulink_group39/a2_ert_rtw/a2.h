/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a2.h
 *
 * Code generated for Simulink model 'a2'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Mon Nov 21 12:59:53 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_a2_h_
#define RTW_HEADER_a2_h_
#ifndef a2_COMMON_INCLUDES_
#define a2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_digitalIO.h"
#include "MW_I2C.h"
#include "MW_PWM.h"
#endif                                 /* a2_COMMON_INCLUDES_ */

#include "a2_types.h"
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
  real_T FXOS87006AxesSensor[3];       /* '<S5>/FXOS8700 6-Axes Sensor' */
  real_T csumrev[3];
  real_T Divide2;                      /* '<S11>/Divide2' */
  real_T ARPmsec;                      /* '<S1>/ARP msec' */
  real_T AtrialPluseWidthmsec;         /* '<S1>/Atrial Pluse Width msec' */
  real_T mode;                         /* '<S1>/mode' */
  real_T VRPmsec;                      /* '<S1>/VRP msec' */
  real_T VentricularPluseWidthmsec;    /* '<S1>/Ventricular Pluse Width msec' */
  real_T Gain;                         /* '<S9>/Gain' */
  real_T Gain1;                        /* '<S9>/Gain1' */
  real_T time_response;                /* '<S3>/MATLAB Function' */
  real_T PACING_REF_PWM;               /* '<S3>/4 Modes' */
  real_T MovingAverage;                /* '<S5>/Moving Average' */
  real_T cumRevIndex;
  boolean_T RelationalOperator;        /* '<S4>/Relational Operator' */
  boolean_T VENT_CMP_DETECTD1;         /* '<S3>/VENT_CMP_DETECT D1' */
  boolean_T ATR_CMP_DETECTD0;          /* '<S3>/ATR_CMP_DETECT D0' */
  boolean_T Z_VENT_CTRL;               /* '<S3>/4 Modes' */
  boolean_T VENT_PACE_CTRL;            /* '<S3>/4 Modes' */
  boolean_T PACE_GND_CTRL;             /* '<S3>/4 Modes' */
  boolean_T ATR_PACE_CTRL;             /* '<S3>/4 Modes' */
  boolean_T VENT_GND_CTRL;             /* '<S3>/4 Modes' */
  boolean_T Z_ATR_CTRL;                /* '<S3>/4 Modes' */
  boolean_T PACE_CHARGE_CTRL;          /* '<S3>/4 Modes' */
  boolean_T ATR_GND_CTRL;              /* '<S3>/4 Modes' */
} B_a2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_a2_T obj; /* '<S5>/Moving Average' */
  freedomk64f_fxos8700_a2_T obj_g;     /* '<S5>/FXOS8700 6-Axes Sensor' */
  freedomk64f_DigitalRead_a2_T obj_i;  /* '<S3>/VENT_CMP_DETECT D1' */
  freedomk64f_DigitalRead_a2_T obj_f;  /* '<S3>/ATR_CMP_DETECT D0' */
  freedomk64f_DigitalWrite_a2_T obj_m; /* '<S2>/Z_VENT_CTRL D7' */
  freedomk64f_DigitalWrite_a2_T obj_mn;/* '<S2>/Z_ATR_CTRL D4' */
  freedomk64f_DigitalWrite_a2_T obj_k; /* '<S2>/VENT_PACE_CTRL D9  ' */
  freedomk64f_DigitalWrite_a2_T obj_e; /* '<S2>/VENT_GND_CTRL D12' */
  freedomk64f_DigitalWrite_a2_T obj_d; /* '<S2>/PACE_GND_CTRL D10' */
  freedomk64f_DigitalWrite_a2_T obj_h; /* '<S2>/PACE_CHARGE_CTRL D2' */
  freedomk64f_DigitalWrite_a2_T obj_a; /* '<S2>/FRONTEND_CTRL D13' */
  freedomk64f_DigitalWrite_a2_T obj_p; /* '<S2>/ATR_PACE_CTRL D8' */
  freedomk64f_DigitalWrite_a2_T obj_o; /* '<S2>/ATR_GND_CTRL D11' */
  freedomk64f_DigitalWrite_a2_T obj_ay;/* '<S1>/Digital Write1' */
  freedomk64f_DigitalWrite_a2_T obj_kr;/* '<S1>/Digital Write' */
  freedomk64f_PWMOutput_a2_T obj_ki;   /* '<S2>/VENT_CMP_REF_PWM D3' */
  freedomk64f_PWMOutput_a2_T obj_p4;   /* '<S2>/PACING_REF_PWM D5' */
  freedomk64f_PWMOutput_a2_T obj_gc;   /* '<S2>/ATR_CMP_REF_PWM D6' */
  real_T Memory_PreviousInput;         /* '<S3>/Memory' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S5>/Scope' */

  struct {
    void *LoggedData;
  } acc_detect01_PWORK;                /* '<S1>/acc_detect(0//1)' */

  struct {
    void *LoggedData;
  } accel_active_PWORK;                /* '<S3>/accel_active' */

  struct {
    void *LoggedData;
  } sensorresponserate_PWORK;          /* '<S3>/sensor-response rate' */

  struct {
    void *LoggedData;
  } acc_PWORK;                         /* '<S1>/acc' */

  uint32_T is_c3_a2;                   /* '<S3>/4 Modes' */
  uint32_T is_VOO;                     /* '<S3>/4 Modes' */
  uint32_T is_AOO;                     /* '<S3>/4 Modes' */
  uint32_T is_VVI;                     /* '<S3>/4 Modes' */
  uint32_T is_AAI;                     /* '<S3>/4 Modes' */
  uint32_T temporalCounter_i1;         /* '<S3>/4 Modes' */
  uint8_T is_active_c3_a2;             /* '<S3>/4 Modes' */
} DW_a2_T;

/* Parameters (default storage) */
struct P_a2_T_ {
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: -1
                                         * Referenced by: '<S5>/FXOS8700 6-Axes Sensor'
                                         */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T ATR_CMP_DETECTD0_SampleTime;  /* Expression: SampleTime
                                        * Referenced by: '<S3>/ATR_CMP_DETECT D0'
                                        */
  real_T VENT_CMP_DETECTD1_SampleTime; /* Expression: SampleTime
                                        * Referenced by: '<S3>/VENT_CMP_DETECT D1'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Accelerationthreshold_Value;  /* Expression: 1.5
                                        * Referenced by: '<S1>/Acceleration threshold'
                                        */
  real_T ppm_Value;                    /* Expression: 60
                                        * Referenced by: '<S1>/ppm'
                                        */
  real_T maximumsensordrivenrate_Value;/* Expression: 175
                                        * Referenced by: '<S1>/maximum sensor-driven rate'
                                        */
  real_T reactiontime_Value;           /* Expression: 2000
                                        * Referenced by: '<S1>/reaction time'
                                        */
  real_T recoverytime1_Value;          /* Expression: 4000
                                        * Referenced by: '<S1>/recovery time1'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S3>/Memory'
                                        */
  real_T umin60sec60000msec2_Value;    /* Expression: 60000
                                        * Referenced by: '<S11>/1min = 60sec = 60000msec2'
                                        */
  real_T ARPmsec_Value;                /* Expression: 130
                                        * Referenced by: '<S1>/ARP msec'
                                        */
  real_T AtrialPluseWidthmsec_Value;   /* Expression: 5
                                        * Referenced by: '<S1>/Atrial Pluse Width msec'
                                        */
  real_T mode_Value;                   /* Expression: 0
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
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T VentricularAmplitude_Value;   /* Expression: 3.5
                                        * Referenced by: '<S1>/Ventricular Amplitude'
                                        */
  real_T Constant1_Value_d;            /* Expression: 5
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Switch_Threshold;             /* Expression: 2
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Atrialthresholdvolt_Value;    /* Expression: 2.3
                                        * Referenced by: '<S1>/Atrial threshold(volt)'
                                        */
  real_T Voltage_Value;                /* Expression: 3.3
                                        * Referenced by: '<S1>/Voltage'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 100
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Ventriclethresholdvolt_Value; /* Expression: 2.3
                                        * Referenced by: '<S1>/Ventricle threshold(volt)'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 100
                                        * Referenced by: '<S8>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_a2_T {
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
extern P_a2_T a2_P;

/* Block signals (default storage) */
extern B_a2_T a2_B;

/* Block states (default storage) */
extern DW_a2_T a2_DW;

/* Model entry point functions */
extern void a2_initialize(void);
extern void a2_step(void);
extern void a2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_a2_T *const a2_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/upper rate limit' : Unused code path elimination
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
 * '<Root>' : 'a2'
 * '<S1>'   : 'a2/Inputs'
 * '<S2>'   : 'a2/Outputs'
 * '<S3>'   : 'a2/VOO//AOO//VVI//AAI'
 * '<S4>'   : 'a2/Inputs/accel detect'
 * '<S5>'   : 'a2/Inputs/calculate acceleration(3D)'
 * '<S6>'   : 'a2/Outputs/sensing control'
 * '<S7>'   : 'a2/VOO//AOO//VVI//AAI/4 Modes'
 * '<S8>'   : 'a2/VOO//AOO//VVI//AAI/Detection PWM'
 * '<S9>'   : 'a2/VOO//AOO//VVI//AAI/Duty cycle calculation'
 * '<S10>'  : 'a2/VOO//AOO//VVI//AAI/MATLAB Function'
 * '<S11>'  : 'a2/VOO//AOO//VVI//AAI/Not ~~'
 */
#endif                                 /* RTW_HEADER_a2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
