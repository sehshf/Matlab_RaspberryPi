/*
 * File: MultiTask.c
 *
 * Code generated for Simulink model 'MultiTask'.
 *
 * Model version                  : 1.50
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Wed Jul 27 21:20:20 2016
 *
 * Target selection: ert_linux.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MultiTask.h"
#include "MultiTask_private.h"

/* Block signals (auto storage) */
B_MultiTask_T MultiTask_B;

/* Block states (auto storage) */
DW_MultiTask_T MultiTask_DW;

/* Real-time model */
RT_MODEL_MultiTask_T MultiTask_M_;
RT_MODEL_MultiTask_T *const MultiTask_M = &MultiTask_M_;

/* Model step function for TID0 */
void MultiTask_step0(void)             /* Sample time: [0.005s, 0.0s] */
{
  char_T *sErr;

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/SendData1'
   */
  /* Sin: '<S1>/Sine Wave' */
  MultiTask_B.SineWave_a = sin(MultiTask_P.SineWave_Freq *
    (((MultiTask_M->Timing.clockTick0+MultiTask_M->Timing.clockTickH0*
       4294967296.0)) * 0.005) + MultiTask_P.SineWave_Phase) *
    MultiTask_P.SineWave_Amp + MultiTask_P.SineWave_Bias;

  /* Pack: <S1>/Byte Pack */
  (void) memcpy(&MultiTask_B.BytePack_m[0], &MultiTask_B.SineWave_a,
                8);

  /* Update for S-Function (sdspToNetwork): '<S1>/UDP Send' */
  sErr = GetErrorBuffer(&MultiTask_DW.UDPSend_NetworkLib_i[0U]);
  LibUpdate_Network(&MultiTask_DW.UDPSend_NetworkLib_i[0U],
                    &MultiTask_B.BytePack_m[0U], 8);
  if (*sErr != 0) {
    rtmSetErrorStatus(MultiTask_M, sErr);
    rtmSetStopRequested(MultiTask_M, 1);
  }

  /* End of Update for S-Function (sdspToNetwork): '<S1>/UDP Send' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  MultiTask_M->Timing.clockTick0++;
  if (!MultiTask_M->Timing.clockTick0) {
    MultiTask_M->Timing.clockTickH0++;
  }
}

/* Model step function for TID1 */
void MultiTask_step1(void)             /* Sample time: [0.01s, 0.0s] */
{
  char_T *sErr;

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator1' incorporates:
   *  SubSystem: '<Root>/SendData2'
   */
  /* Sin: '<S2>/Sine Wave' */
  MultiTask_B.SineWave = sin(MultiTask_P.SineWave_Freq_h *
    (((MultiTask_M->Timing.clockTick1+MultiTask_M->Timing.clockTickH1*
       4294967296.0)) * 0.01) + MultiTask_P.SineWave_Phase_p) *
    MultiTask_P.SineWave_Amp_f + MultiTask_P.SineWave_Bias_g;

  /* Pack: <S2>/Byte Pack */
  (void) memcpy(&MultiTask_B.BytePack[0], &MultiTask_B.SineWave,
                8);

  /* Update for S-Function (sdspToNetwork): '<S2>/UDP Send' */
  sErr = GetErrorBuffer(&MultiTask_DW.UDPSend_NetworkLib[0U]);
  LibUpdate_Network(&MultiTask_DW.UDPSend_NetworkLib[0U], &MultiTask_B.BytePack
                    [0U], 8);
  if (*sErr != 0) {
    rtmSetErrorStatus(MultiTask_M, sErr);
    rtmSetStopRequested(MultiTask_M, 1);
  }

  /* End of Update for S-Function (sdspToNetwork): '<S2>/UDP Send' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  MultiTask_M->Timing.clockTick1++;
  if (!MultiTask_M->Timing.clockTick1) {
    MultiTask_M->Timing.clockTickH1++;
  }
}

/* Model initialize function */
void MultiTask_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)MultiTask_M, 0,
                sizeof(RT_MODEL_MultiTask_T));
  (MultiTask_M)->Timing.TaskCounters.cLimit[0] = 1;
  (MultiTask_M)->Timing.TaskCounters.cLimit[1] = 2;

  /* block I/O */
  (void) memset(((void *) &MultiTask_B), 0,
                sizeof(B_MultiTask_T));

  /* states (dwork) */
  (void) memset((void *)&MultiTask_DW, 0,
                sizeof(DW_MultiTask_T));

  {
    char_T *sErr;
    char_T *sErr_0;

    /* Start for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
     *  Start for SubSystem: '<Root>/SendData1'
     */
    /* Start for S-Function (sdspToNetwork): '<S1>/UDP Send' */
    sErr = GetErrorBuffer(&MultiTask_DW.UDPSend_NetworkLib_i[0U]);
    CreateUDPInterface(&MultiTask_DW.UDPSend_NetworkLib_i[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&MultiTask_DW.UDPSend_NetworkLib_i[0U], 1, "0.0.0.0", -1,
                        "192.168.0.11", 5000, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&MultiTask_DW.UDPSend_NetworkLib_i[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&MultiTask_DW.UDPSend_NetworkLib_i[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(MultiTask_M, sErr);
        rtmSetStopRequested(MultiTask_M, 1);
      }
    }

    /* End of Start for S-Function (sdspToNetwork): '<S1>/UDP Send' */

    /* Start for S-Function (fcncallgen): '<Root>/Function-Call Generator1' incorporates:
     *  Start for SubSystem: '<Root>/SendData2'
     */
    /* Start for S-Function (sdspToNetwork): '<S2>/UDP Send' */
    sErr_0 = GetErrorBuffer(&MultiTask_DW.UDPSend_NetworkLib[0U]);
    CreateUDPInterface(&MultiTask_DW.UDPSend_NetworkLib[0U]);
    if (*sErr_0 == 0) {
      LibCreate_Network(&MultiTask_DW.UDPSend_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "192.168.0.11", 5100, 8192, 1, 0);
    }

    if (*sErr_0 == 0) {
      LibStart(&MultiTask_DW.UDPSend_NetworkLib[0U]);
    }

    if (*sErr_0 != 0) {
      DestroyUDPInterface(&MultiTask_DW.UDPSend_NetworkLib[0U]);
      if (*sErr_0 != 0) {
        rtmSetErrorStatus(MultiTask_M, sErr_0);
        rtmSetStopRequested(MultiTask_M, 1);
      }
    }

    /* End of Start for S-Function (sdspToNetwork): '<S2>/UDP Send' */
  }
}

/* Model terminate function */
void MultiTask_terminate(void)
{
  char_T *sErr;
  char_T *sErr_0;

  /* Terminate for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  Terminate for SubSystem: '<Root>/SendData1'
   */
  /* Terminate for S-Function (sdspToNetwork): '<S1>/UDP Send' */
  sErr = GetErrorBuffer(&MultiTask_DW.UDPSend_NetworkLib_i[0U]);
  LibTerminate(&MultiTask_DW.UDPSend_NetworkLib_i[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(MultiTask_M, sErr);
    rtmSetStopRequested(MultiTask_M, 1);
  }

  LibDestroy(&MultiTask_DW.UDPSend_NetworkLib_i[0U], 1);
  DestroyUDPInterface(&MultiTask_DW.UDPSend_NetworkLib_i[0U]);

  /* End of Terminate for S-Function (sdspToNetwork): '<S1>/UDP Send' */

  /* Terminate for S-Function (fcncallgen): '<Root>/Function-Call Generator1' incorporates:
   *  Terminate for SubSystem: '<Root>/SendData2'
   */
  /* Terminate for S-Function (sdspToNetwork): '<S2>/UDP Send' */
  sErr_0 = GetErrorBuffer(&MultiTask_DW.UDPSend_NetworkLib[0U]);
  LibTerminate(&MultiTask_DW.UDPSend_NetworkLib[0U]);
  if (*sErr_0 != 0) {
    rtmSetErrorStatus(MultiTask_M, sErr_0);
    rtmSetStopRequested(MultiTask_M, 1);
  }

  LibDestroy(&MultiTask_DW.UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&MultiTask_DW.UDPSend_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspToNetwork): '<S2>/UDP Send' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
