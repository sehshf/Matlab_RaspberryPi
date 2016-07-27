/*
 * DataReceive.c
 *
 * Code generation for model "DataReceive".
 *
 * Model version              : 1.25
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Mon Jun 20 15:33:54 2016
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "DataReceive.h"
#include "DataReceive_private.h"

/* Block signals (auto storage) */
B_DataReceive_T DataReceive_B;

/* Block states (auto storage) */
DW_DataReceive_T DataReceive_DW;

/* Real-time model */
RT_MODEL_DataReceive_T DataReceive_M_;
RT_MODEL_DataReceive_T *const DataReceive_M = &DataReceive_M_;

/* Model step function for TID0 */
void DataReceive_step0(void)           /* Sample time: [0.01s, 0.0s] */
{
  /* Matfile logging */
  rt_UpdateTXYLogVars(DataReceive_M->rtwLogInfo,
                      (&DataReceive_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(DataReceive_M)!=-1) &&
        !((rtmGetTFinal(DataReceive_M)-DataReceive_M->Timing.taskTime0) >
          DataReceive_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(DataReceive_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++DataReceive_M->Timing.clockTick0)) {
    ++DataReceive_M->Timing.clockTickH0;
  }

  DataReceive_M->Timing.taskTime0 = DataReceive_M->Timing.clockTick0 *
    DataReceive_M->Timing.stepSize0 + DataReceive_M->Timing.clockTickH0 *
    DataReceive_M->Timing.stepSize0 * 4294967296.0;
}

/* Model step function for TID1 */
void DataReceive_step1(void)           /* Sample time: [0.1s, 0.0s] */
{
  char_T *sErr;
  int32_T samplesRead;
  int32_T i;

  /* S-Function (sdspFromNetwork): '<Root>/UDP Receive1' */
  sErr = GetErrorBuffer(&DataReceive_DW.UDPReceive1_NetworkLib[0U]);
  samplesRead = 8;
  LibOutputs_Network(&DataReceive_DW.UDPReceive1_NetworkLib[0U],
                     &DataReceive_B.UDPReceive1_o1[0U], &samplesRead);
  if (*sErr != 0) {
    rtmSetErrorStatus(DataReceive_M, sErr);
    rtmSetStopRequested(DataReceive_M, 1);
  }

  DataReceive_B.UDPReceive1_o2 = (uint16_T)samplesRead;
  if (samplesRead == 0) {
    for (i = 0; i < 8; i++) {
      DataReceive_B.UDPReceive1_o1[i] = 0U;
    }
  }

  /* End of S-Function (sdspFromNetwork): '<Root>/UDP Receive1' */

  /* Unpack: <Root>/Byte Unpack */
  (void) memcpy(&DataReceive_B.ByteUnpack, &DataReceive_B.UDPReceive1_o1[0],
                8);
}

/* Model step wrapper function for compatibility with a static main program */
void DataReceive_step(int_T tid)
{
  switch (tid) {
   case 0 :
    DataReceive_step0();
    break;

   case 1 :
    DataReceive_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void DataReceive_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)DataReceive_M, 0,
                sizeof(RT_MODEL_DataReceive_T));
  (DataReceive_M)->Timing.TaskCounters.cLimit[0] = 1;
  (DataReceive_M)->Timing.TaskCounters.cLimit[1] = 10;
  rtmSetTFinal(DataReceive_M, -1);
  DataReceive_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    DataReceive_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(DataReceive_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(DataReceive_M->rtwLogInfo, (NULL));
    rtliSetLogT(DataReceive_M->rtwLogInfo, "tout");
    rtliSetLogX(DataReceive_M->rtwLogInfo, "");
    rtliSetLogXFinal(DataReceive_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(DataReceive_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(DataReceive_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(DataReceive_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(DataReceive_M->rtwLogInfo, 1);
    rtliSetLogY(DataReceive_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(DataReceive_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(DataReceive_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &DataReceive_B), 0,
                sizeof(B_DataReceive_T));

  /* states (dwork) */
  (void) memset((void *)&DataReceive_DW, 0,
                sizeof(DW_DataReceive_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(DataReceive_M->rtwLogInfo, 0.0, rtmGetTFinal
    (DataReceive_M), DataReceive_M->Timing.stepSize0, (&rtmGetErrorStatus
    (DataReceive_M)));

  {
    char_T *sErr;

    /* Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive1' */
    sErr = GetErrorBuffer(&DataReceive_DW.UDPReceive1_NetworkLib[0U]);
    CreateUDPInterface(&DataReceive_DW.UDPReceive1_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&DataReceive_DW.UDPReceive1_NetworkLib[0U], 0, "0.0.0.0",
                        51001, "192.168.137.2", -1, 8192, 1, 1000);
    }

    if (*sErr == 0) {
      LibStart(&DataReceive_DW.UDPReceive1_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&DataReceive_DW.UDPReceive1_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(DataReceive_M, sErr);
        rtmSetStopRequested(DataReceive_M, 1);
      }
    }

    /* End of Start for S-Function (sdspFromNetwork): '<Root>/UDP Receive1' */
  }
}

/* Model terminate function */
void DataReceive_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive1' */
  sErr = GetErrorBuffer(&DataReceive_DW.UDPReceive1_NetworkLib[0U]);
  LibTerminate(&DataReceive_DW.UDPReceive1_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(DataReceive_M, sErr);
    rtmSetStopRequested(DataReceive_M, 1);
  }

  LibDestroy(&DataReceive_DW.UDPReceive1_NetworkLib[0U], 0);
  DestroyUDPInterface(&DataReceive_DW.UDPReceive1_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspFromNetwork): '<Root>/UDP Receive1' */
}
