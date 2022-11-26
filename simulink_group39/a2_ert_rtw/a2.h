/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: a2.h
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

#ifndef RTW_HEADER_a2_h_
#define RTW_HEADER_a2_h_
#ifndef a2_COMMON_INCLUDES_
#define a2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_PWM.h"
#include "MW_digitalIO.h"
#include "MW_AnalogIn.h"
#include "MW_SCI.h"
#include "MW_I2C.h"
#endif                                 /* a2_COMMON_INCLUDES_ */

#include "a2_types.h"
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
  MW_SCI_Parity_Type ParityValue;
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  real_T Add;                          /* '<S14>/Add' */
  real_T PACING_REF_PWM;               /* '<S3>/4 Modes' */
  real_T activity_threshold;
  real_T atr_amp;
  real_T atr_threshold;
  real_T vent_amp;
  real_T vent_threshold;
  real_T activity_threshold_o;         /* '<S2>/From DCM' */
  real_T atr_amp_p;                    /* '<S2>/From DCM' */
  real_T atr_threshold_e;              /* '<S2>/From DCM' */
  real_T vent_amp_e;                   /* '<S2>/From DCM' */
  real_T vent_threshold_o;             /* '<S2>/From DCM' */
  real_T Divide2;
  real_T Gain1;
  real_T Gain;
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
  uint16_T lower_rate_limit_p;         /* '<S2>/From DCM' */
  uint16_T upper_rate_limit_m;         /* '<S2>/From DCM' */
  uint16_T PVARP_a;                    /* '<S2>/From DCM' */
  uint16_T mode_f;                     /* '<S2>/From DCM' */
  uint16_T av_delay_f;                 /* '<S2>/From DCM' */
  uint16_T reaction_time_i;            /* '<S2>/From DCM' */
  uint16_T response_factor_n;          /* '<S2>/From DCM' */
  uint16_T recovery_time_e;            /* '<S2>/From DCM' */
  uint16_T MSR_g;                      /* '<S2>/From DCM' */
  uint16_T atr_pulse_width_f;          /* '<S2>/From DCM' */
  uint16_T ARP_c;                      /* '<S2>/From DCM' */
  uint16_T vent_pulse_width_h;         /* '<S2>/From DCM' */
  uint16_T VRP_j;                      /* '<S2>/From DCM' */
  uint8_T BytePack26[2];               /* '<S6>/Byte Pack26' */
  uint8_T BytePack1[2];                /* '<S6>/Byte Pack 1' */
  uint8_T BytePack2[2];                /* '<S6>/Byte Pack 2' */
  uint8_T BytePack3[2];                /* '<S6>/Byte Pack 3' */
  uint8_T BytePack27[2];               /* '<S6>/Byte Pack27' */
  uint8_T BytePack28[2];               /* '<S6>/Byte Pack28' */
  uint8_T BytePack29[2];               /* '<S6>/Byte Pack29' */
  uint8_T BytePack30[8];               /* '<S6>/Byte Pack30' */
  uint8_T BytePack31[2];               /* '<S6>/Byte Pack31' */
  uint8_T BytePack32[2];               /* '<S6>/Byte Pack32' */
  uint8_T BytePack34[8];               /* '<S6>/Byte Pack34' */
  uint8_T BytePack35[2];               /* '<S6>/Byte Pack35' */
  uint8_T BytePack36[2];               /* '<S6>/Byte Pack36' */
  uint8_T BytePack37[8];               /* '<S6>/Byte Pack37' */
  uint8_T BytePack39[8];               /* '<S6>/Byte Pack39' */
  uint8_T BytePack40[2];               /* '<S6>/Byte Pack40' */
  uint8_T BytePack41[2];               /* '<S6>/Byte Pack41' */
  uint8_T BytePack42[8];               /* '<S6>/Byte Pack42' */
  uint8_T b_SwappedDataBytes[2];
  uint8_T b_RegisterValue;
  uint8_T status;
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
  freedomk64f_fxos8700_a2_T obj;       /* '<S14>/FXOS8700 6-Axes Sensor' */
  freedomk64f_AnalogInput_a2_T obj_o;  /* '<S2>/VENT_SIGNAL' */
  freedomk64f_AnalogInput_a2_T obj_d;  /* '<S2>/ATR_SIGNAL' */
  freedomk64f_SCIRead_a2_T obj_b;      /* '<S2>/Serial Receive1' */
  freedomk64f_DigitalRead_a2_T obj_a;  /* '<S3>/VENT_CMP_DETECT D1' */
  freedomk64f_DigitalRead_a2_T obj_l;  /* '<S3>/ATR_CMP_DETECT D0' */
  freedomk64f_PWMOutput_a2_T obj_ds;   /* '<S1>/VENT_CMP_REF_PWM D3' */
  freedomk64f_PWMOutput_a2_T obj_bg;   /* '<S1>/PACING_REF_PWM D5' */
  freedomk64f_PWMOutput_a2_T obj_h;    /* '<S1>/ATR_CMP_REF_PWM D6' */
  freedomk64f_DigitalWrite_a2_T obj_g; /* '<S12>/Digital Write1' */
  freedomk64f_DigitalWrite_a2_T obj_e; /* '<S12>/Digital Write' */
  freedomk64f_DigitalWrite_a2_T obj_ec;/* '<S1>/Z_VENT_CTRL D7' */
  freedomk64f_DigitalWrite_a2_T obj_n; /* '<S1>/Z_ATR_CTRL D4' */
  freedomk64f_DigitalWrite_a2_T obj_h0;/* '<S1>/VENT_PACE_CTRL D9  ' */
  freedomk64f_DigitalWrite_a2_T obj_j; /* '<S1>/VENT_GND_CTRL D12' */
  freedomk64f_DigitalWrite_a2_T obj_jn;/* '<S1>/PACE_GND_CTRL D10' */
  freedomk64f_DigitalWrite_a2_T obj_aq;/* '<S1>/PACE_CHARGE_CTRL D2' */
  freedomk64f_DigitalWrite_a2_T obj_oh;/* '<S1>/FRONTEND_CTRL D13' */
  freedomk64f_DigitalWrite_a2_T obj_lh;/* '<S1>/ATR_PACE_CTRL D8' */
  freedomk64f_DigitalWrite_a2_T obj_go;/* '<S1>/ATR_GND_CTRL D11' */
  freedomk64f_SCIWrite_a2_T obj_j1;    /* '<S6>/Serial Transmit' */
  uint32_T temporalCounter_i1;         /* '<S3>/4 Modes' */
  uint16_T Memory_PreviousInput;       /* '<S3>/Memory' */
  uint8_T is_active_c4_a2;             /* '<S3>/4 Modes' */
  uint8_T is_c4_a2;                    /* '<S3>/4 Modes' */
  uint8_T is_VOOR;                     /* '<S3>/4 Modes' */
  uint8_T is_AOOR;                     /* '<S3>/4 Modes' */
  uint8_T is_VVIR;                     /* '<S3>/4 Modes' */
  uint8_T is_AAIR;                     /* '<S3>/4 Modes' */
  uint8_T is_VOO;                      /* '<S3>/4 Modes' */
  uint8_T is_AOO;                      /* '<S3>/4 Modes' */
  uint8_T is_VVI;                      /* '<S3>/4 Modes' */
  uint8_T is_AAI;                      /* '<S3>/4 Modes' */
  uint8_T is_active_c2_a2;             /* '<S2>/From DCM' */
  uint8_T is_c2_a2;                    /* '<S2>/From DCM' */
} DW_a2_T;

/* Parameters (default storage) */
struct P_a2_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T ATR_SIGNAL_SampleTime;        /* Expression: SampleTime
                                        * Referenced by: '<S2>/ATR_SIGNAL'
                                        */
  real_T SerialReceive1_SampleTime;    /* Expression: -1
                                        * Referenced by: '<S2>/Serial Receive1'
                                        */
  real_T VENT_SIGNAL_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S2>/VENT_SIGNAL'
                                        */
  real_T ATR_CMP_DETECTD0_SampleTime;  /* Expression: SampleTime
                                        * Referenced by: '<S3>/ATR_CMP_DETECT D0'
                                        */
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: -1
                                         * Referenced by: '<S14>/FXOS8700 6-Axes Sensor'
                                         */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S14>/Out1'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real_T VENT_CMP_DETECTD1_SampleTime; /* Expression: SampleTime
                                        * Referenced by: '<S3>/VENT_CMP_DETECT D1'
                                        */
  real_T Constant_Value_a;             /* Expression: 3.3
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Constant_Value_i;             /* Expression: 5
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 100
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Constant1_Value_c;            /* Expression: 5
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T umin60sec60000msec2_Value;    /* Expression: 60000
                                        * Referenced by: '<S11>/1min = 60sec = 60000msec2'
                                        */
  real_T Constant1_Value_n;            /* Expression: 3.3
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: 100
                                        * Referenced by: '<S8>/Gain1'
                                        */
  uint16_T Memory_InitialCondition;
                                  /* Computed Parameter: Memory_InitialCondition
                                   * Referenced by: '<S3>/Memory'
                                   */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S15>/Switch'
                                        */
  uint16_T Switch_Threshold_p;         /* Computed Parameter: Switch_Threshold_p
                                        * Referenced by: '<S4>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_a2_T {
  const char_T * volatile errorStatus;
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
 * Block '<S12>/acceleration' : Unused code path elimination
 * Block '<S14>/Scope' : Unused code path elimination
 * Block '<S3>/acc_detect(0//1)' : Unused code path elimination
 * Block '<S3>/accel_active' : Unused code path elimination
 * Block '<S3>/sensor-response rate' : Unused code path elimination
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S1>'   : 'a2/Outputs'
 * '<S2>'   : 'a2/Serial Com//Inputs'
 * '<S3>'   : 'a2/VOO//AOO//VVI//AAI (R)'
 * '<S4>'   : 'a2/Outputs/sensing control'
 * '<S5>'   : 'a2/Serial Com//Inputs/From DCM'
 * '<S6>'   : 'a2/Serial Com//Inputs/Function Call'
 * '<S7>'   : 'a2/VOO//AOO//VVI//AAI (R)/4 Modes'
 * '<S8>'   : 'a2/VOO//AOO//VVI//AAI (R)/Detection PWM'
 * '<S9>'   : 'a2/VOO//AOO//VVI//AAI (R)/Duty cycle calculation'
 * '<S10>'  : 'a2/VOO//AOO//VVI//AAI (R)/MATLAB Function'
 * '<S11>'  : 'a2/VOO//AOO//VVI//AAI (R)/Not ~~'
 * '<S12>'  : 'a2/VOO//AOO//VVI//AAI (R)/Subsystem'
 * '<S13>'  : 'a2/VOO//AOO//VVI//AAI (R)/Subsystem/accel detect'
 * '<S14>'  : 'a2/VOO//AOO//VVI//AAI (R)/Subsystem/calculate acceleration(3D)'
 * '<S15>'  : 'a2/VOO//AOO//VVI//AAI (R)/Subsystem/triger'
 */
#endif                                 /* RTW_HEADER_a2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
