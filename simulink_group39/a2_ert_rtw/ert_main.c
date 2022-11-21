/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include "a2.h"
#include "a2_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "board.h"
#include "mw_cmsis_rtos.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16
#define EXIT_ON_ERROR(msg, cond)       if (cond) { return(0); }

extern const char *TgtConnInit(int_T argc, char_T *argv[]);
extern void TgtConnTerm();
extern void TgtConnPreStep(int_T tid);
extern void TgtConnPostStep(int_T tid);
const char * csErrorStatus;

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
mw_signal_event_t stopSem;
mw_signal_event_t baserateTaskSem;
mw_thread_t schedulerThread;
mw_thread_t baseRateThread;
mw_thread_t backgroundThread;
void *threadJoinStatus;
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(a2_M) == (NULL)) && !rtmGetStopRequested(a2_M);
  while (runModel) {
    mw_osSignalEventWaitEver(&baserateTaskSem);

    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModePauseIfNeeded(a2_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(a2_M, true);
      }

      if (rtmGetStopRequested(a2_M) == true) {
        rtmSetErrorStatus(a2_M, "Simulation finished");
        break;
      }
    }

    a2_step();

    /* Get model outputs here */
    rtExtModeCheckEndTrigger();
    stopRequested = !((rtmGetErrorStatus(a2_M) == (NULL)) &&
                      !rtmGetStopRequested(a2_M));
    runModel = !stopRequested;
  }

  runModel = 0;
  terminateTask(arg);
  mw_osThreadExit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(a2_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;

    /* Wait for background task to complete */
    CHECK_STATUS(mw_osThreadJoin(backgroundThread, &threadJoinStatus), 0,
                 "mw_osThreadJoin");
  }

  /* Terminate model */
  a2_terminate();
  rtExtModeShutdown(1);
  TgtConnTerm();
  mw_osSignalEventRelease(&stopSem);
  return NULL;
}

void *backgroundTask(void *arg)
{
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(a2_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(a2_M, true);
      }
    }

    runCommService();
  }

  return NULL;
}

int main(int argc, char **argv)
{
  SystemCoreClockUpdate();
  hardware_init();
  rtmSetErrorStatus(a2_M, 0);
  rtExtModeParseArgs(argc, (const char_T **)argv, NULL);

  /* Target connectivity initialization */
  csErrorStatus = TgtConnInit(argc, argv);
  EXIT_ON_ERROR("Error initializing target connectivity: %s\n", csErrorStatus);

  /* Initialize model */
  a2_initialize();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(a2_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(a2_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(a2_M, true);
    }
  }

  rtERTExtModeStartMsg();

  /* Call RTOS Initialization function */
  mw_RTOSInit(0.001, 0);

  /* Wait for stop semaphore */
  mw_osSignalEventWaitEver(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(mw_osSignalEventDelete(&timerTaskSem[i]), 0,
                   "mw_osSignalEventDelete");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
