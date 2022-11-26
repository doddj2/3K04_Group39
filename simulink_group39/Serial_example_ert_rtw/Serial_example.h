/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Serial_example.h
 *
 * Code generated for Simulink model 'Serial_example'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Nov 24 16:06:15 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Serial_example_h_
#define RTW_HEADER_Serial_example_h_
#ifndef Serial_example_COMMON_INCLUDES_
#define Serial_example_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_SCI.h"
#include "MW_digitalIO.h"
#endif                                 /* Serial_example_COMMON_INCLUDES_ */

#include "Serial_example_types.h"
#include <stddef.h>
#include "send_params.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint32_T TxPinLoc;
  real32_T off_time;
  real32_T off_time_m;                 /* '<Root>/COM_IN' */
  uint16_T switch_time;
  uint16_T switch_time_p;              /* '<Root>/COM_IN' */
  uint8_T BytePack[4];                 /* '<S2>/Byte Pack' */
  uint8_T BytePack1[2];                /* '<S2>/Byte Pack1' */
  uint8_T red_en;                      /* '<Root>/COM_IN' */
  uint8_T green_en;                    /* '<Root>/COM_IN' */
  uint8_T blue_en;                     /* '<Root>/COM_IN' */
} B_Serial_example_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  freedomk64f_SCIRead_Serial_ex_T obj; /* '<Root>/Serial Receive' */
  freedomk64f_SCIWrite_Serial_e_T obj_o;/* '<S2>/Serial Transmit' */
  freedomk64f_DigitalWrite_Seri_T obj_j;/* '<S4>/RED' */
  freedomk64f_DigitalWrite_Seri_T obj_l;/* '<S4>/GREEN' */
  freedomk64f_DigitalWrite_Seri_T obj_b;/* '<S4>/BLUE' */
  uint32_T temporalCounter_i1;         /* '<Root>/LED_CONTROL' */
  uint8_T is_active_c1_Serial_example; /* '<Root>/LED_CONTROL' */
  uint8_T is_c1_Serial_example;        /* '<Root>/LED_CONTROL' */
  uint8_T is_active_c3_Serial_example; /* '<Root>/COM_IN' */
  uint8_T is_c3_Serial_example;        /* '<Root>/COM_IN' */
} DW_Serial_example_T;

/* Parameters (default storage) */
struct P_Serial_example_T_ {
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Serial_example_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_Serial_example_T Serial_example_P;

/* Block signals (default storage) */
extern B_Serial_example_T Serial_example_B;

/* Block states (default storage) */
extern DW_Serial_example_T Serial_example_DW;

/* Model entry point functions */
extern void Serial_example_initialize(void);
extern void Serial_example_step(void);
extern void Serial_example_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Serial_example_T *const Serial_example_M;

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
 * '<Root>' : 'Serial_example'
 * '<S1>'   : 'Serial_example/COM_IN'
 * '<S2>'   : 'Serial_example/Function-Call Subsystem'
 * '<S3>'   : 'Serial_example/LED_CONTROL'
 * '<S4>'   : 'Serial_example/Subsystem'
 */
#endif                                 /* RTW_HEADER_Serial_example_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
