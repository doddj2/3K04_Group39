/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Serial_example.c
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

#include "Serial_example.h"
#include "Serial_example_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <stddef.h>
#include "send_params.h"
#include "send_params_private.h"

/* Named constants for Chart: '<Root>/COM_IN' */
#define Serial_example_IN_ECHO_PARAM   ((uint8_T)1U)
#define Serial_example_IN_INITIAL      ((uint8_T)2U)
#define Serial_example_IN_SET_PARAM    ((uint8_T)3U)
#define Serial_example_IN_STANDBY      ((uint8_T)4U)

/* Named constants for Chart: '<Root>/LED_CONTROL' */
#define Serial_example_IN_BLUE_ON      ((uint8_T)1U)
#define Serial_example_IN_GREEN_ON     ((uint8_T)2U)
#define Serial_example_IN_OFF          ((uint8_T)3U)
#define Serial_example_IN_RED_ON       ((uint8_T)4U)

/* Block signals (default storage) */
B_Serial_example_T Serial_example_B;

/* Block states (default storage) */
DW_Serial_example_T Serial_example_DW;

/* Real-time model */
static RT_MODEL_Serial_example_T Serial_example_M_;
RT_MODEL_Serial_example_T *const Serial_example_M = &Serial_example_M_;

/* Forward declaration for local functions */
static void Serial_examp_SystemCore_setup_n(freedomk64f_SCIRead_Serial_ex_T *obj);
static void Serial_examp_SystemCore_setup_n(freedomk64f_SCIRead_Serial_ex_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T SCIModuleLoc;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  Serial_example_B.TxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, 10U,
    Serial_example_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* Model step function */
void Serial_example_step(void)
{
  uint8_T RxData[11];
  uint8_T RxDataLocChar[11];
  uint8_T status;
  boolean_T rtb_blue_out;
  boolean_T rtb_green_out;
  boolean_T rtb_red_out;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (Serial_example_DW.obj.SampleTime !=
      Serial_example_P.SerialReceive_SampleTime) {
    Serial_example_DW.obj.SampleTime = Serial_example_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(Serial_example_DW.obj.MW_SCIHANDLE, &RxDataLocChar[0],
    11U);
  memcpy((void *)&RxData[0], (void *)&RxDataLocChar[0], (uint32_T)((size_t)11 *
          sizeof(uint8_T)));

  /* Chart: '<Root>/COM_IN' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  if (Serial_example_DW.is_active_c3_Serial_example == 0U) {
    Serial_example_DW.is_active_c3_Serial_example = 1U;
    Serial_example_DW.is_c3_Serial_example = Serial_example_IN_INITIAL;
    Serial_example_B.red_en = 1U;
    Serial_example_B.green_en = 1U;
    Serial_example_B.blue_en = 1U;
    Serial_example_B.off_time_m = 0.5F;
    Serial_example_B.switch_time_p = 200U;
  } else {
    switch (Serial_example_DW.is_c3_Serial_example) {
     case Serial_example_IN_ECHO_PARAM:
      Serial_example_DW.is_c3_Serial_example = Serial_example_IN_STANDBY;
      break;

     case Serial_example_IN_INITIAL:
      Serial_example_DW.is_c3_Serial_example = Serial_example_IN_STANDBY;
      break;

     case Serial_example_IN_SET_PARAM:
      Serial_example_DW.is_c3_Serial_example = Serial_example_IN_STANDBY;
      break;

     default:
      /* case IN_STANDBY: */
      if (status == 0) {
        if (RxData[0] == 22) {
          switch (RxData[1]) {
           case 85:
            Serial_example_DW.is_c3_Serial_example = Serial_example_IN_SET_PARAM;
            Serial_example_B.red_en = RxData[2];
            Serial_example_B.green_en = RxData[3];
            Serial_example_B.blue_en = RxData[4];
            memcpy((void *)&Serial_example_B.off_time_m, (void *)&RxData[5],
                   (uint32_T)((size_t)1 * sizeof(real32_T)));
            memcpy((void *)&Serial_example_B.switch_time_p, (void *)&RxData[9],
                   (uint32_T)((size_t)1 * sizeof(uint16_T)));
            break;

           case 34:
            Serial_example_DW.is_c3_Serial_example =
              Serial_example_IN_ECHO_PARAM;
            send_params();
            break;

           default:
            Serial_example_DW.is_c3_Serial_example = Serial_example_IN_STANDBY;
            break;
          }
        } else {
          Serial_example_DW.is_c3_Serial_example = Serial_example_IN_STANDBY;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/COM_IN' */

  /* Chart: '<Root>/LED_CONTROL' */
  if (Serial_example_DW.temporalCounter_i1 < MAX_uint32_T) {
    Serial_example_DW.temporalCounter_i1++;
  }

  if (Serial_example_DW.is_active_c1_Serial_example == 0U) {
    Serial_example_DW.is_active_c1_Serial_example = 1U;
    Serial_example_DW.is_c1_Serial_example = Serial_example_IN_OFF;
    Serial_example_DW.temporalCounter_i1 = 0U;
    rtb_red_out = false;
    rtb_green_out = false;
    rtb_blue_out = false;
  } else {
    switch (Serial_example_DW.is_c1_Serial_example) {
     case Serial_example_IN_BLUE_ON:
      rtb_red_out = false;
      rtb_green_out = false;
      rtb_blue_out = true;
      if (Serial_example_DW.temporalCounter_i1 >= Serial_example_B.switch_time_p)
      {
        Serial_example_DW.is_c1_Serial_example = Serial_example_IN_OFF;
        Serial_example_DW.temporalCounter_i1 = 0U;
        rtb_blue_out = false;
      }
      break;

     case Serial_example_IN_GREEN_ON:
      rtb_red_out = false;
      rtb_green_out = true;
      rtb_blue_out = false;
      if (Serial_example_DW.temporalCounter_i1 >= Serial_example_B.switch_time_p)
      {
        if (Serial_example_B.blue_en == 1) {
          Serial_example_DW.is_c1_Serial_example = Serial_example_IN_BLUE_ON;
          Serial_example_DW.temporalCounter_i1 = 0U;
          rtb_green_out = false;
          rtb_blue_out = true;
        } else {
          Serial_example_DW.is_c1_Serial_example = Serial_example_IN_OFF;
          Serial_example_DW.temporalCounter_i1 = 0U;
          rtb_green_out = false;
        }
      }
      break;

     case Serial_example_IN_OFF:
      rtb_red_out = false;
      rtb_green_out = false;
      rtb_blue_out = false;
      if (Serial_example_DW.temporalCounter_i1 >= Serial_example_B.off_time_m *
          1000.0F) {
        if (Serial_example_B.red_en == 1) {
          Serial_example_DW.is_c1_Serial_example = Serial_example_IN_RED_ON;
          Serial_example_DW.temporalCounter_i1 = 0U;
          rtb_red_out = true;
        } else if (Serial_example_B.green_en == 1) {
          Serial_example_DW.is_c1_Serial_example = Serial_example_IN_GREEN_ON;
          Serial_example_DW.temporalCounter_i1 = 0U;
          rtb_green_out = true;
        } else if (Serial_example_B.blue_en == 1) {
          Serial_example_DW.is_c1_Serial_example = Serial_example_IN_BLUE_ON;
          Serial_example_DW.temporalCounter_i1 = 0U;
          rtb_blue_out = true;
        } else {
          Serial_example_DW.is_c1_Serial_example = Serial_example_IN_OFF;
          Serial_example_DW.temporalCounter_i1 = 0U;
        }
      }
      break;

     default:
      /* case IN_RED_ON: */
      rtb_red_out = true;
      rtb_green_out = false;
      rtb_blue_out = false;
      if (Serial_example_DW.temporalCounter_i1 >= Serial_example_B.switch_time_p)
      {
        if (Serial_example_B.green_en == 1) {
          Serial_example_DW.is_c1_Serial_example = Serial_example_IN_GREEN_ON;
          Serial_example_DW.temporalCounter_i1 = 0U;
          rtb_red_out = false;
          rtb_green_out = true;
        } else if (Serial_example_B.blue_en == 1) {
          Serial_example_DW.is_c1_Serial_example = Serial_example_IN_BLUE_ON;
          Serial_example_DW.temporalCounter_i1 = 0U;
          rtb_red_out = false;
          rtb_blue_out = true;
        } else {
          Serial_example_DW.is_c1_Serial_example = Serial_example_IN_OFF;
          Serial_example_DW.temporalCounter_i1 = 0U;
          rtb_red_out = false;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/LED_CONTROL' */

  /* MATLABSystem: '<S4>/RED' */
  MW_digitalIO_write(Serial_example_DW.obj_j.MW_DIGITALIO_HANDLE, rtb_red_out);

  /* MATLABSystem: '<S4>/GREEN' */
  MW_digitalIO_write(Serial_example_DW.obj_l.MW_DIGITALIO_HANDLE, rtb_green_out);

  /* MATLABSystem: '<S4>/BLUE' */
  MW_digitalIO_write(Serial_example_DW.obj_b.MW_DIGITALIO_HANDLE, rtb_blue_out);
}

/* Model initialize function */
void Serial_example_initialize(void)
{
  {
    freedomk64f_DigitalWrite_Seri_T *obj;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem'
     */
    send_params_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' */

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    Serial_example_DW.obj.isInitialized = 0;
    Serial_example_DW.obj.matlabCodegenIsDeleted = false;
    Serial_example_DW.obj.SampleTime = Serial_example_P.SerialReceive_SampleTime;
    Serial_examp_SystemCore_setup_n(&Serial_example_DW.obj);

    /* Start for MATLABSystem: '<S4>/RED' */
    Serial_example_DW.obj_j.matlabCodegenIsDeleted = true;
    Serial_example_DW.obj_j.isInitialized = 0;
    Serial_example_DW.obj_j.matlabCodegenIsDeleted = false;
    obj = &Serial_example_DW.obj_j;
    Serial_example_DW.obj_j.isSetupComplete = false;
    Serial_example_DW.obj_j.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Serial_example_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/GREEN' */
    Serial_example_DW.obj_l.matlabCodegenIsDeleted = true;
    Serial_example_DW.obj_l.isInitialized = 0;
    Serial_example_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &Serial_example_DW.obj_l;
    Serial_example_DW.obj_l.isSetupComplete = false;
    Serial_example_DW.obj_l.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    Serial_example_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/BLUE' */
    Serial_example_DW.obj_b.matlabCodegenIsDeleted = true;
    Serial_example_DW.obj_b.isInitialized = 0;
    Serial_example_DW.obj_b.matlabCodegenIsDeleted = false;
    obj = &Serial_example_DW.obj_b;
    Serial_example_DW.obj_b.isSetupComplete = false;
    Serial_example_DW.obj_b.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(44U, 1);
    Serial_example_DW.obj_b.isSetupComplete = true;
  }
}

/* Model terminate function */
void Serial_example_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!Serial_example_DW.obj.matlabCodegenIsDeleted) {
    Serial_example_DW.obj.matlabCodegenIsDeleted = true;
    if ((Serial_example_DW.obj.isInitialized == 1) &&
        Serial_example_DW.obj.isSetupComplete) {
      MW_SCI_Close(Serial_example_DW.obj.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  send_params_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S4>/RED' */
  if (!Serial_example_DW.obj_j.matlabCodegenIsDeleted) {
    Serial_example_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Serial_example_DW.obj_j.isInitialized == 1) &&
        Serial_example_DW.obj_j.isSetupComplete) {
      MW_digitalIO_close(Serial_example_DW.obj_j.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/RED' */

  /* Terminate for MATLABSystem: '<S4>/GREEN' */
  if (!Serial_example_DW.obj_l.matlabCodegenIsDeleted) {
    Serial_example_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Serial_example_DW.obj_l.isInitialized == 1) &&
        Serial_example_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(Serial_example_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/GREEN' */

  /* Terminate for MATLABSystem: '<S4>/BLUE' */
  if (!Serial_example_DW.obj_b.matlabCodegenIsDeleted) {
    Serial_example_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Serial_example_DW.obj_b.isInitialized == 1) &&
        Serial_example_DW.obj_b.isSetupComplete) {
      MW_digitalIO_close(Serial_example_DW.obj_b.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/BLUE' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
