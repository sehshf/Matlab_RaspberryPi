/*
 * File: DataSend.c
 *
 * Code generated for Simulink model 'DataSend'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Wed Jul 27 21:07:07 2016
 *
 * Target selection: ert_linux.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DataSend.h"
#include "DataSend_private.h"

/* Block signals (auto storage) */
B_DataSend_T DataSend_B;

/* Block states (auto storage) */
DW_DataSend_T DataSend_DW;

/* Real-time model */
RT_MODEL_DataSend_T DataSend_M_;
RT_MODEL_DataSend_T *const DataSend_M = &DataSend_M_;

/* Model step function */
void DataSend_step(void)
{
  char_T *sErr;

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/SendData'
   */
  /* Sin: '<S1>/Sine Wave' */
  DataSend_B.SineWave = sin(DataSend_P.SineWave_Freq *
    (((DataSend_M->Timing.clockTick0+DataSend_M->Timing.clockTickH0*
       4294967296.0)) * 0.005) + DataSend_P.SineWave_Phase) *
    DataSend_P.SineWave_Amp + DataSend_P.SineWave_Bias;

  /* Pack: <S1>/Byte Pack */
  (void) memcpy(&DataSend_B.BytePack[0], &DataSend_B.SineWave,
                8);

  /* Update for S-Function (sdspToNetwork): '<S1>/UDP Send' */
  sErr = GetErrorBuffer(&DataSend_DW.UDPSend_NetworkLib[0U]);
  LibUpdate_Network(&DataSend_DW.UDPSend_NetworkLib[0U], &DataSend_B.BytePack[0U],
                    8);
  if (*sErr != 0) {
    rtmSetErrorStatus(DataSend_M, sErr);
    rtmSetStopRequested(DataSend_M, 1);
  }

  /* End of Update for S-Function (sdspToNetwork): '<S1>/UDP Send' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  DataSend_M->Timing.clockTick0++;
  if (!DataSend_M->Timing.clockTick0) {
    DataSend_M->Timing.clockTickH0++;
  }
}

/* Model initialize function */
void DataSend_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)DataSend_M, 0,
                sizeof(RT_MODEL_DataSend_T));

  /* block I/O */
  (void) memset(((void *) &DataSend_B), 0,
                sizeof(B_DataSend_T));

  /* states (dwork) */
  (void) memset((void *)&DataSend_DW, 0,
                sizeof(DW_DataSend_T));

  {
    char_T *sErr;

    /* Start for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
     *  Start for SubSystem: '<Root>/SendData'
     */
    /* Start for S-Function (sdspToNetwork): '<S1>/UDP Send' */
    sErr = GetErrorBuffer(&DataSend_DW.UDPSend_NetworkLib[0U]);
    CreateUDPInterface(&DataSend_DW.UDPSend_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&DataSend_DW.UDPSend_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "192.168.0.11", 5000, 8192, 1, 0);
    }

    if (*sErr == 0) {
      LibStart(&DataSend_DW.UDPSend_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&DataSend_DW.UDPSend_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(DataSend_M, sErr);
        rtmSetStopRequested(DataSend_M, 1);
      }
    }

    /* End of Start for S-Function (sdspToNetwork): '<S1>/UDP Send' */
  }
}

/* Model terminate function */
void DataSend_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  Terminate for SubSystem: '<Root>/SendData'
   */
  /* Terminate for S-Function (sdspToNetwork): '<S1>/UDP Send' */
  sErr = GetErrorBuffer(&DataSend_DW.UDPSend_NetworkLib[0U]);
  LibTerminate(&DataSend_DW.UDPSend_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(DataSend_M, sErr);
    rtmSetStopRequested(DataSend_M, 1);
  }

  LibDestroy(&DataSend_DW.UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&DataSend_DW.UDPSend_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspToNetwork): '<S1>/UDP Send' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
