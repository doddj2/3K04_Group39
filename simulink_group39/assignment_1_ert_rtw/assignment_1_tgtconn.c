/*
 * assignment_1_tgtconn.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "assignment_1".
 *
 * Model version              : 1.37
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Mon Nov 14 16:18:54 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtwtypes.h"
#define EXTERN_C
#include <stdio.h>
#include "RTIOStreamTgtAppSvc/RTIOStreamTgtAppSvcCIntrf.h"

extern void initializeCommService( );
extern void terminateCommService();
EXTERN_C void TgtConnBackgroundTask()
{
}

EXTERN_C const char *TgtConnInit(int_T argc, char_T *argv[])
{
  const char *result = (NULL);         /* assume success */
  initializeCommService( );
  return(result);
}

EXTERN_C void TgtConnTerm()
{
  terminateCommService();
}

EXTERN_C void TgtConnPreStep(int_T tid)
{
}

EXTERN_C void TgtConnPostStep(int_T tid)
{
}

/* EOF: assignment_1_tgtconn.c */
