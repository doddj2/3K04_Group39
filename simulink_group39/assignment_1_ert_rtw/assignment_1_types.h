/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: assignment_1_types.h
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

#ifndef RTW_HEADER_assignment_1_types_h_
#define RTW_HEADER_assignment_1_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<S4>/VENT_CMP_DETECT D1' */
#include "MW_SVD.h"
#ifndef struct_tag_0QIIqIWUIOhUbf1p9QN9pB
#define struct_tag_0QIIqIWUIOhUbf1p9QN9pB

struct tag_0QIIqIWUIOhUbf1p9QN9pB
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_0QIIqIWUIOhUbf1p9QN9pB */

#ifndef typedef_b_freedomk64f_Hardware_assign_T
#define typedef_b_freedomk64f_Hardware_assign_T

typedef struct tag_0QIIqIWUIOhUbf1p9QN9pB b_freedomk64f_Hardware_assign_T;

#endif                             /* typedef_b_freedomk64f_Hardware_assign_T */

#ifndef struct_tag_RYgVoAXTz61tXGMaBAGv7F
#define struct_tag_RYgVoAXTz61tXGMaBAGv7F

struct tag_RYgVoAXTz61tXGMaBAGv7F
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_assign_T Hw;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_RYgVoAXTz61tXGMaBAGv7F */

#ifndef typedef_freedomk64f_PWMOutput_assignm_T
#define typedef_freedomk64f_PWMOutput_assignm_T

typedef struct tag_RYgVoAXTz61tXGMaBAGv7F freedomk64f_PWMOutput_assignm_T;

#endif                             /* typedef_freedomk64f_PWMOutput_assignm_T */

#ifndef struct_tag_EkIWEs70Gs0LyfeXELZ2TC
#define struct_tag_EkIWEs70Gs0LyfeXELZ2TC

struct tag_EkIWEs70Gs0LyfeXELZ2TC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_assign_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /* struct_tag_EkIWEs70Gs0LyfeXELZ2TC */

#ifndef typedef_freedomk64f_DigitalWrite_assi_T
#define typedef_freedomk64f_DigitalWrite_assi_T

typedef struct tag_EkIWEs70Gs0LyfeXELZ2TC freedomk64f_DigitalWrite_assi_T;

#endif                             /* typedef_freedomk64f_DigitalWrite_assi_T */

/* Custom Type definition for MATLABSystem: '<S3>/FXOS8700 6-Axes Sensor' */
#include "MW_I2C.h"
#ifndef struct_tag_0QIIqIWUIOhUbf1p9QN9pB
#define struct_tag_0QIIqIWUIOhUbf1p9QN9pB

struct tag_0QIIqIWUIOhUbf1p9QN9pB
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_0QIIqIWUIOhUbf1p9QN9pB */

#ifndef typedef_c_freedomk64f_Hardware_assign_T
#define typedef_c_freedomk64f_Hardware_assign_T

typedef struct tag_0QIIqIWUIOhUbf1p9QN9pB c_freedomk64f_Hardware_assign_T;

#endif                             /* typedef_c_freedomk64f_Hardware_assign_T */

#ifndef struct_tag_O0UAiliRyLLAe38ibfdAhE
#define struct_tag_O0UAiliRyLLAe38ibfdAhE

struct tag_O0UAiliRyLLAe38ibfdAhE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  c_freedomk64f_Hardware_assign_T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
};

#endif                                 /* struct_tag_O0UAiliRyLLAe38ibfdAhE */

#ifndef typedef_b_freedomk64f_I2CMasterWrite__T
#define typedef_b_freedomk64f_I2CMasterWrite__T

typedef struct tag_O0UAiliRyLLAe38ibfdAhE b_freedomk64f_I2CMasterWrite__T;

#endif                             /* typedef_b_freedomk64f_I2CMasterWrite__T */

#ifndef struct_tag_v5Zyp5raUQrCF4f9Ln2EwE
#define struct_tag_v5Zyp5raUQrCF4f9Ln2EwE

struct tag_v5Zyp5raUQrCF4f9Ln2EwE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
  b_freedomk64f_I2CMasterWrite__T i2cobj;
};

#endif                                 /* struct_tag_v5Zyp5raUQrCF4f9Ln2EwE */

#ifndef typedef_freedomk64f_fxos8700_assignme_T
#define typedef_freedomk64f_fxos8700_assignme_T

typedef struct tag_v5Zyp5raUQrCF4f9Ln2EwE freedomk64f_fxos8700_assignme_T;

#endif                             /* typedef_freedomk64f_fxos8700_assignme_T */

#ifndef struct_tag_q6HQSF2nXq6EjCNj0vbuLD
#define struct_tag_q6HQSF2nXq6EjCNj0vbuLD

struct tag_q6HQSF2nXq6EjCNj0vbuLD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_freedomk64f_Hardware_assign_T Hw;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
  real_T SampleTime;
};

#endif                                 /* struct_tag_q6HQSF2nXq6EjCNj0vbuLD */

#ifndef typedef_freedomk64f_DigitalRead_assig_T
#define typedef_freedomk64f_DigitalRead_assig_T

typedef struct tag_q6HQSF2nXq6EjCNj0vbuLD freedomk64f_DigitalRead_assig_T;

#endif                             /* typedef_freedomk64f_DigitalRead_assig_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_assignment_1_T
#define typedef_cell_wrap_assignment_1_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_assignment_1_T;

#endif                                 /* typedef_cell_wrap_assignment_1_T */

#ifndef struct_tag_makEXEAW3pQFwWLQ5R6ifF
#define struct_tag_makEXEAW3pQFwWLQ5R6ifF

struct tag_makEXEAW3pQFwWLQ5R6ifF
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum[3];
  real_T pCumSumRev[102];
  real_T pCumRevIndex;
  real_T pModValueRev;
};

#endif                                 /* struct_tag_makEXEAW3pQFwWLQ5R6ifF */

#ifndef typedef_g_dsp_internal_SlidingWindowA_T
#define typedef_g_dsp_internal_SlidingWindowA_T

typedef struct tag_makEXEAW3pQFwWLQ5R6ifF g_dsp_internal_SlidingWindowA_T;

#endif                             /* typedef_g_dsp_internal_SlidingWindowA_T */

#ifndef struct_tag_fqNvyU0hA2HwNRRr5pCkYE
#define struct_tag_fqNvyU0hA2HwNRRr5pCkYE

struct tag_fqNvyU0hA2HwNRRr5pCkYE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_assignment_1_T inputVarSize;
  g_dsp_internal_SlidingWindowA_T *pStatistic;
  int32_T NumChannels;
  g_dsp_internal_SlidingWindowA_T _pobj0;
};

#endif                                 /* struct_tag_fqNvyU0hA2HwNRRr5pCkYE */

#ifndef typedef_dsp_simulink_MovingAverage_as_T
#define typedef_dsp_simulink_MovingAverage_as_T

typedef struct tag_fqNvyU0hA2HwNRRr5pCkYE dsp_simulink_MovingAverage_as_T;

#endif                             /* typedef_dsp_simulink_MovingAverage_as_T */

/* Parameters (default storage) */
typedef struct P_assignment_1_T_ P_assignment_1_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_assignment_1_T RT_MODEL_assignment_1_T;

#endif                                 /* RTW_HEADER_assignment_1_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
