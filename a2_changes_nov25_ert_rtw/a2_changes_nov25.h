/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a2_changes_nov25.h
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

#ifndef RTW_HEADER_a2_changes_nov25_h_
#define RTW_HEADER_a2_changes_nov25_h_
#ifndef a2_changes_nov25_COMMON_INCLUDES_
#define a2_changes_nov25_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_AnalogIn.h"
#include "MW_SCI.h"
#include "MW_digitalIO.h"
#include "MW_I2C.h"
#endif                                 /* a2_changes_nov25_COMMON_INCLUDES_ */

#include "a2_changes_nov25_types.h"
#include <stddef.h>
#include "DCM_SEND.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T RxData[68];
  uint8_T RxDataLocChar[68];
  uint8_T TxDataLocChar[66];
  uint8_T TmpSignalConversionAtSerial[66];
  MW_AnalogIn_TriggerSource_Type trigger_val;
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  real_T Add;                          /* '<S12>/Add' */
  real_T activity_threshold;
  real_T atr_amp;
  real_T atr_threshold;
  real_T vent_amp;
  real_T vent_threshold;
  real_T activity_threshold_c;         /* '<S1>/From DCM' */
  real_T atr_amp_g;                    /* '<S1>/From DCM' */
  real_T atr_threshold_a;              /* '<S1>/From DCM' */
  real_T vent_amp_h;                   /* '<S1>/From DCM' */
  real_T vent_threshold_n;             /* '<S1>/From DCM' */
  real_T d;
  uint16_T lower_rate_limit;
  uint16_T upper_rate_limit;
  uint16_T PVARP;
  uint16_T mode;
  uint16_T av_delay;
  uint16_T reaction_time;
  uint16_T response_factor;
  uint16_T recovery_time;
  uint16_T MSR;
  uint16_T atr_pulse_width;
  uint16_T ARP;
  uint16_T vent_pulse_width;
  uint16_T VRP;
  uint16_T lower_rate_limit_p;         /* '<S1>/From DCM' */
  uint16_T upper_rate_limit_b;         /* '<S1>/From DCM' */
  uint16_T PVARP_l;                    /* '<S1>/From DCM' */
  uint16_T mode_a;                     /* '<S1>/From DCM' */
  uint16_T av_delay_i;                 /* '<S1>/From DCM' */
  uint16_T reaction_time_f;            /* '<S1>/From DCM' */
  uint16_T response_factor_d;          /* '<S1>/From DCM' */
  uint16_T recovery_time_l;            /* '<S1>/From DCM' */
  uint16_T MSR_e;                      /* '<S1>/From DCM' */
  uint16_T atr_pulse_width_g;          /* '<S1>/From DCM' */
  uint16_T ARP_m;                      /* '<S1>/From DCM' */
  uint16_T vent_pulse_width_b;         /* '<S1>/From DCM' */
  uint16_T VRP_f;                      /* '<S1>/From DCM' */
  uint8_T BytePack26[2];               /* '<S4>/Byte Pack26' */
  uint8_T BytePack1[2];                /* '<S4>/Byte Pack 1' */
  uint8_T BytePack2[2];                /* '<S4>/Byte Pack 2' */
  uint8_T BytePack3[2];                /* '<S4>/Byte Pack 3' */
  uint8_T BytePack27[2];               /* '<S4>/Byte Pack27' */
  uint8_T BytePack28[2];               /* '<S4>/Byte Pack28' */
  uint8_T BytePack29[2];               /* '<S4>/Byte Pack29' */
  uint8_T BytePack30[8];               /* '<S4>/Byte Pack30' */
  uint8_T BytePack31[2];               /* '<S4>/Byte Pack31' */
  uint8_T BytePack32[2];               /* '<S4>/Byte Pack32' */
  uint8_T BytePack34[8];               /* '<S4>/Byte Pack34' */
  uint8_T BytePack35[2];               /* '<S4>/Byte Pack35' */
  uint8_T BytePack36[2];               /* '<S4>/Byte Pack36' */
  uint8_T BytePack37[8];               /* '<S4>/Byte Pack37' */
  uint8_T BytePack39[8];               /* '<S4>/Byte Pack39' */
  uint8_T BytePack40[2];               /* '<S4>/Byte Pack40' */
  uint8_T BytePack41[2];               /* '<S4>/Byte Pack41' */
  uint8_T BytePack42[8];               /* '<S4>/Byte Pack42' */
} B_a2_changes_nov25_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_fxos8700_a2_chang_T obj; /* '<S12>/FXOS8700 6-Axes Sensor' */
  freedomk64f_AnalogInput_a2_ch_T obj_f;/* '<S1>/VENT_SIGNAL' */
  freedomk64f_AnalogInput_a2_ch_T obj_e;/* '<S1>/ATR_SIGNAL' */
  freedomk64f_SCIRead_a2_change_T obj_o;/* '<S1>/Serial Receive1' */
  freedomk64f_DigitalRead_a2_ch_T obj_i;/* '<S2>/VENT_CMP_DETECT D1' */
  freedomk64f_DigitalRead_a2_ch_T obj_f0;/* '<S2>/ATR_CMP_DETECT D0' */
  freedomk64f_SCIWrite_a2_chang_T obj_h;/* '<S4>/Serial Transmit' */
  freedomk64f_DigitalWrite_a2_c_T obj_n;/* '<S10>/Digital Write1' */
  freedomk64f_DigitalWrite_a2_c_T obj_hj;/* '<S10>/Digital Write' */
  uint32_T temporalCounter_i1;         /* '<S2>/4 Modes' */
  struct {
    uint_T is_c3_a2_changes_nov25:4;   /* '<S2>/4 Modes' */
    uint_T is_VVIR:3;                  /* '<S2>/4 Modes' */
    uint_T is_AAIR:3;                  /* '<S2>/4 Modes' */
    uint_T is_VVI:3;                   /* '<S2>/4 Modes' */
    uint_T is_AAI:3;                   /* '<S2>/4 Modes' */
    uint_T is_c1_a2_changes_nov25:3;   /* '<S1>/From DCM' */
    uint_T is_VOOR:2;                  /* '<S2>/4 Modes' */
    uint_T is_AOOR:2;                  /* '<S2>/4 Modes' */
    uint_T is_VOO:2;                   /* '<S2>/4 Modes' */
    uint_T is_AOO:2;                   /* '<S2>/4 Modes' */
    uint_T is_active_c3_a2_changes_nov25:1;/* '<S2>/4 Modes' */
    uint_T is_active_c1_a2_changes_nov25:1;/* '<S1>/From DCM' */
  } bitsForTID0;

  uint16_T Memory_PreviousInput;       /* '<S2>/Memory' */
} DW_a2_changes_nov25_T;

/* Parameters (default storage) */
struct P_a2_changes_nov25_T_ {
  real_T ATR_SIGNAL_SampleTime;        /* Expression: SampleTime
                                        * Referenced by: '<S1>/ATR_SIGNAL'
                                        */
  real_T SerialReceive1_SampleTime;    /* Expression: -1
                                        * Referenced by: '<S1>/Serial Receive1'
                                        */
  real_T VENT_SIGNAL_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S1>/VENT_SIGNAL'
                                        */
  real_T ATR_CMP_DETECTD0_SampleTime;  /* Expression: SampleTime
                                        * Referenced by: '<S2>/ATR_CMP_DETECT D0'
                                        */
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: -1
                                         * Referenced by: '<S12>/FXOS8700 6-Axes Sensor'
                                         */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S12>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: 1
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Constant1'
                                        */
  real_T VENT_CMP_DETECTD1_SampleTime; /* Expression: SampleTime
                                        * Referenced by: '<S2>/VENT_CMP_DETECT D1'
                                        */
  real_T Constant_Value_b;             /* Expression: 5
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Constant1_Value_d;            /* Expression: 5
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T umin60sec60000msec2_Value;    /* Expression: 60000
                                        * Referenced by: '<S9>/1min = 60sec = 60000msec2'
                                        */
  uint16_T Memory_InitialCondition;
                                  /* Computed Parameter: Memory_InitialCondition
                                   * Referenced by: '<S2>/Memory'
                                   */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S13>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_a2_changes_nov25_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_a2_changes_nov25_T a2_changes_nov25_P;

/* Block signals (default storage) */
extern B_a2_changes_nov25_T a2_changes_nov25_B;

/* Block states (default storage) */
extern DW_a2_changes_nov25_T a2_changes_nov25_DW;

/* Model entry point functions */
extern void a2_changes_nov25_initialize(void);
extern void a2_changes_nov25_step(void);
extern void a2_changes_nov25_terminate(void);

/* Real-time Model object */
extern RT_MODEL_a2_changes_nov25_T *const a2_changes_nov25_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Divide' : Unused code path elimination
 * Block '<S6>/Divide1' : Unused code path elimination
 * Block '<S6>/Gain' : Unused code path elimination
 * Block '<S6>/Gain1' : Unused code path elimination
 * Block '<S10>/acceleration' : Unused code path elimination
 * Block '<S12>/Scope' : Unused code path elimination
 * Block '<S2>/acc_detect(0//1)' : Unused code path elimination
 * Block '<S2>/accel_active' : Unused code path elimination
 * Block '<S2>/sensor-response rate' : Unused code path elimination
 * Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'a2_changes_nov25'
 * '<S1>'   : 'a2_changes_nov25/Serial Com//Inputs'
 * '<S2>'   : 'a2_changes_nov25/VOO//AOO//VVI//AAI (R)'
 * '<S3>'   : 'a2_changes_nov25/Serial Com//Inputs/From DCM'
 * '<S4>'   : 'a2_changes_nov25/Serial Com//Inputs/Function Call'
 * '<S5>'   : 'a2_changes_nov25/VOO//AOO//VVI//AAI (R)/4 Modes'
 * '<S6>'   : 'a2_changes_nov25/VOO//AOO//VVI//AAI (R)/Detection PWM'
 * '<S7>'   : 'a2_changes_nov25/VOO//AOO//VVI//AAI (R)/Duty cycle calculation'
 * '<S8>'   : 'a2_changes_nov25/VOO//AOO//VVI//AAI (R)/MATLAB Function'
 * '<S9>'   : 'a2_changes_nov25/VOO//AOO//VVI//AAI (R)/Not ~~'
 * '<S10>'  : 'a2_changes_nov25/VOO//AOO//VVI//AAI (R)/Subsystem'
 * '<S11>'  : 'a2_changes_nov25/VOO//AOO//VVI//AAI (R)/Subsystem/accel detect'
 * '<S12>'  : 'a2_changes_nov25/VOO//AOO//VVI//AAI (R)/Subsystem/calculate acceleration(3D)'
 * '<S13>'  : 'a2_changes_nov25/VOO//AOO//VVI//AAI (R)/Subsystem/triger'
 */
#endif                                 /* RTW_HEADER_a2_changes_nov25_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
