/*
 * File: MultiTask.c
 *
 * Code generated for Simulink model 'MultiTask'.
 *
 * Model version                  : 1.59
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Sep 26 06:46:24 2016
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
  /* Sin: '<S2>/Sine Wave' */
  MultiTask_B.SineWave_l = sin(MultiTask_P.SineWave_Freq *
    (((MultiTask_M->Timing.clockTick0+MultiTask_M->Timing.clockTickH0*
       4294967296.0)) * 0.005) + MultiTask_P.SineWave_Phase) *
    MultiTask_P.SineWave_Amp + MultiTask_P.SineWave_Bias;

  /* Pack: <S2>/Byte Pack */
  (void) memcpy(&MultiTask_B.BytePack_k[0], &MultiTask_B.SineWave_l,
                8);

  /* Update for S-Function (sdspToNetwork): '<S2>/UDP Send' */
  sErr = GetErrorBuffer(&MultiTask_DW.UDPSend_NetworkLib_i[0U]);
  LibUpdate_Network(&MultiTask_DW.UDPSend_NetworkLib_i[0U],
                    &MultiTask_B.BytePack_k[0U], 8);
  if (*sErr != 0) {
    rtmSetErrorStatus(MultiTask_M, sErr);
    rtmSetStopRequested(MultiTask_M, 1);
  }

  /* End of Update for S-Function (sdspToNetwork): '<S2>/UDP Send' */

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
  /* Sin: '<S3>/Sine Wave' */
  MultiTask_B.SineWave = sin(MultiTask_P.SineWave_Freq_f *
    (((MultiTask_M->Timing.clockTick1+MultiTask_M->Timing.clockTickH1*
       4294967296.0)) * 0.01) + MultiTask_P.SineWave_Phase_k) *
    MultiTask_P.SineWave_Amp_n + MultiTask_P.SineWave_Bias_m;

  /* Pack: <S3>/Byte Pack */
  (void) memcpy(&MultiTask_B.BytePack[0], &MultiTask_B.SineWave,
                8);

  /* Update for S-Function (sdspToNetwork): '<S3>/UDP Send' */
  sErr = GetErrorBuffer(&MultiTask_DW.UDPSend_NetworkLib[0U]);
  LibUpdate_Network(&MultiTask_DW.UDPSend_NetworkLib[0U], &MultiTask_B.BytePack
                    [0U], 8);
  if (*sErr != 0) {
    rtmSetErrorStatus(MultiTask_M, sErr);
    rtmSetStopRequested(MultiTask_M, 1);
  }

  /* End of Update for S-Function (sdspToNetwork): '<S3>/UDP Send' */

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

/* Model step function for TID2 */
void MultiTask_step2(void)             /* Sample time: [0.02s, 0.0s] */
{
  boolean_T rtb_Compare;

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator2' incorporates:
   *  SubSystem: '<Root>/HelloWorld'
   */
  /* RelationalOperator: '<S5>/Compare' incorporates:
   *  Constant: '<S5>/Constant'
   *  Sin: '<S1>/Sine Wave'
   */
  rtb_Compare = (sin(MultiTask_P.SineWave_Freq_b * MultiTask_M->Timing.t[2] +
                     MultiTask_P.SineWave_Phase_d) * MultiTask_P.SineWave_Amp_i
                 + MultiTask_P.SineWave_Bias_d > MultiTask_P.Constant_Value);

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  RelationalOperator: '<S4>/FixPt Relational Operator'
   *  UnitDelay: '<S4>/Delay Input1'
   */
  MultiTask_B.DataTypeConversion = ((int32_T)rtb_Compare > (int32_T)
    MultiTask_DW.DelayInput1_DSTATE);

  /* Level2 S-Function Block: '<S1>/S-Function1' (printout) */
  {
    SimStruct *rts = MultiTask_M->childSfunctions[0];
    sfcnOutputs(rts, 2);
  }

  /* Update for UnitDelay: '<S4>/Delay Input1' */
  MultiTask_DW.DelayInput1_DSTATE = rtb_Compare;

  /* Level2 S-Function Block: '<S1>/S-Function1' (printout) */
  {
    SimStruct *rts = MultiTask_M->childSfunctions[0];
    sfcnUpdate(rts, 2);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++MultiTask_M->Timing.clockTick2)) {
    ++MultiTask_M->Timing.clockTickH2;
  }

  MultiTask_M->Timing.t[2] = MultiTask_M->Timing.clockTick2 *
    MultiTask_M->Timing.stepSize2 + MultiTask_M->Timing.clockTickH2 *
    MultiTask_M->Timing.stepSize2 * 4294967296.0;
}

/* Model initialize function */
void MultiTask_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)MultiTask_M, 0,
                sizeof(RT_MODEL_MultiTask_T));
  (MultiTask_M)->Timing.TaskCounters.cLimit[0] = 1;
  (MultiTask_M)->Timing.TaskCounters.cLimit[1] = 2;
  (MultiTask_M)->Timing.TaskCounters.cLimit[2] = 4;
  rtsiSetSolverName(&MultiTask_M->solverInfo,"FixedStepDiscrete");
  MultiTask_M->solverInfoPtr = (&MultiTask_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = MultiTask_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    MultiTask_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    MultiTask_M->Timing.sampleTimes = (&MultiTask_M->Timing.sampleTimesArray[0]);
    MultiTask_M->Timing.offsetTimes = (&MultiTask_M->Timing.offsetTimesArray[0]);

    /* task periods */
    MultiTask_M->Timing.sampleTimes[0] = (0.005);
    MultiTask_M->Timing.sampleTimes[1] = (0.01);
    MultiTask_M->Timing.sampleTimes[2] = (0.02);

    /* task offsets */
    MultiTask_M->Timing.offsetTimes[0] = (0.0);
    MultiTask_M->Timing.offsetTimes[1] = (0.0);
    MultiTask_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(MultiTask_M, &MultiTask_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = MultiTask_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = MultiTask_M->Timing.perTaskSampleHitsArray;
    MultiTask_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    MultiTask_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(MultiTask_M, -1);
  MultiTask_M->Timing.stepSize2 = 0.02;
  MultiTask_M->solverInfoPtr = (&MultiTask_M->solverInfo);
  MultiTask_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&MultiTask_M->solverInfo, 0.005);
  rtsiSetSolverMode(&MultiTask_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  (void) memset(((void *) &MultiTask_B), 0,
                sizeof(B_MultiTask_T));

  /* states (dwork) */
  (void) memset((void *)&MultiTask_DW, 0,
                sizeof(DW_MultiTask_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &MultiTask_M->NonInlinedSFcns.sfcnInfo;
    MultiTask_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(MultiTask_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &MultiTask_M->Sizes.numSampTimes);
    MultiTask_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(MultiTask_M)[0]);
    MultiTask_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(MultiTask_M)[1]);
    MultiTask_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr(MultiTask_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,MultiTask_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(MultiTask_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(MultiTask_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(MultiTask_M));
    rtssSetStepSizePtr(sfcnInfo, &MultiTask_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(MultiTask_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &MultiTask_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &MultiTask_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &MultiTask_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &MultiTask_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &MultiTask_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &MultiTask_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &MultiTask_M->solverInfoPtr);
  }

  MultiTask_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&MultiTask_M->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    MultiTask_M->childSfunctions =
      (&MultiTask_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    MultiTask_M->childSfunctions[0] =
      (&MultiTask_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: MultiTask/<S1>/S-Function1 (printout) */
    {
      SimStruct *rts = MultiTask_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = MultiTask_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = MultiTask_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = MultiTask_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &MultiTask_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, MultiTask_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &MultiTask_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &MultiTask_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &MultiTask_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &MultiTask_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &MultiTask_B.DataTypeConversion);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &MultiTask_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &MultiTask_B.SFunction1));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts, "MultiTask/HelloWorld/S-Function1");
      ssSetRTModel(rts,MultiTask_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      printout(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.02);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  {
    char_T *sErr;
    char_T *sErr_0;

    /* Start for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
     *  Start for SubSystem: '<Root>/SendData1'
     */
    /* Start for S-Function (sdspToNetwork): '<S2>/UDP Send' */
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

    /* End of Start for S-Function (sdspToNetwork): '<S2>/UDP Send' */

    /* Start for S-Function (fcncallgen): '<Root>/Function-Call Generator1' incorporates:
     *  Start for SubSystem: '<Root>/SendData2'
     */
    /* Start for S-Function (sdspToNetwork): '<S3>/UDP Send' */
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

    /* End of Start for S-Function (sdspToNetwork): '<S3>/UDP Send' */

    /* Start for S-Function (fcncallgen): '<Root>/Function-Call Generator2' incorporates:
     *  Start for SubSystem: '<Root>/HelloWorld'
     */
    /* Level2 S-Function Block: '<S1>/S-Function1' (printout) */
    {
      SimStruct *rts = MultiTask_M->childSfunctions[0];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  /* InitializeConditions for S-Function (fcncallgen): '<Root>/Function-Call Generator2' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/HelloWorld'
   */
  /* InitializeConditions for UnitDelay: '<S4>/Delay Input1' */
  MultiTask_DW.DelayInput1_DSTATE = MultiTask_P.DetectRisePositive_vinit;

  /* Level2 S-Function Block: '<S1>/S-Function1' (printout) */
  {
    SimStruct *rts = MultiTask_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
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
  /* Terminate for S-Function (sdspToNetwork): '<S2>/UDP Send' */
  sErr = GetErrorBuffer(&MultiTask_DW.UDPSend_NetworkLib_i[0U]);
  LibTerminate(&MultiTask_DW.UDPSend_NetworkLib_i[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(MultiTask_M, sErr);
    rtmSetStopRequested(MultiTask_M, 1);
  }

  LibDestroy(&MultiTask_DW.UDPSend_NetworkLib_i[0U], 1);
  DestroyUDPInterface(&MultiTask_DW.UDPSend_NetworkLib_i[0U]);

  /* End of Terminate for S-Function (sdspToNetwork): '<S2>/UDP Send' */

  /* Terminate for S-Function (fcncallgen): '<Root>/Function-Call Generator1' incorporates:
   *  Terminate for SubSystem: '<Root>/SendData2'
   */
  /* Terminate for S-Function (sdspToNetwork): '<S3>/UDP Send' */
  sErr_0 = GetErrorBuffer(&MultiTask_DW.UDPSend_NetworkLib[0U]);
  LibTerminate(&MultiTask_DW.UDPSend_NetworkLib[0U]);
  if (*sErr_0 != 0) {
    rtmSetErrorStatus(MultiTask_M, sErr_0);
    rtmSetStopRequested(MultiTask_M, 1);
  }

  LibDestroy(&MultiTask_DW.UDPSend_NetworkLib[0U], 1);
  DestroyUDPInterface(&MultiTask_DW.UDPSend_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspToNetwork): '<S3>/UDP Send' */

  /* Terminate for S-Function (fcncallgen): '<Root>/Function-Call Generator2' incorporates:
   *  Terminate for SubSystem: '<Root>/HelloWorld'
   */
  /* Level2 S-Function Block: '<S1>/S-Function1' (printout) */
  {
    SimStruct *rts = MultiTask_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
