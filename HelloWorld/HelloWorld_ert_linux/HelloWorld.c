/*
 * File: HelloWorld.c
 *
 * Code generated for Simulink model 'HelloWorld'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Jun 20 12:15:16 2016
 *
 * Target selection: ert_linux.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HelloWorld.h"
#include "HelloWorld_private.h"

/* Block signals (auto storage) */
B_HelloWorld_T HelloWorld_B;

/* Block states (auto storage) */
DW_HelloWorld_T HelloWorld_DW;

/* Real-time model */
RT_MODEL_HelloWorld_T HelloWorld_M_;
RT_MODEL_HelloWorld_T *const HelloWorld_M = &HelloWorld_M_;
void Hello_fcn(void)
{
  /* Wait until application is initialized properly */
  while (1) {
    /* Call the system: <Root>/HelloWorld */
    {
      /* Output and update for function-call system: '<Root>/HelloWorld' */
      {
        boolean_T rtb_Compare;
        HelloWorld_M->Timing.clockTick1 = HelloWorld_M->Timing.clockTick0;
        HelloWorld_M->Timing.t[1] = (HelloWorld_M->Timing.clockTick1) *
          HelloWorld_M->Timing.stepSize1;

        /* RelationalOperator: '<S4>/Compare' incorporates:
         *  Constant: '<S4>/Constant'
         *  Sin: '<S1>/Sine Wave'
         */
        rtb_Compare = (sin(HelloWorld_P.SineWave_Freq * HelloWorld_M->Timing.t[1]
                           + HelloWorld_P.SineWave_Phase) *
                       HelloWorld_P.SineWave_Amp + HelloWorld_P.SineWave_Bias >
                       HelloWorld_P.Constant_Value);

        /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
         *  RelationalOperator: '<S3>/FixPt Relational Operator'
         *  UnitDelay: '<S3>/Delay Input1'
         */
        HelloWorld_B.DataTypeConversion = ((int32_T)rtb_Compare > (int32_T)
          HelloWorld_DW.DelayInput1_DSTATE);

        /* Level2 S-Function Block: '<S1>/S-Function1' (printout) */
        {
          SimStruct *rts = HelloWorld_M->childSfunctions[0];
          sfcnOutputs(rts, 1);
        }

        /* Update for UnitDelay: '<S3>/Delay Input1' */
        HelloWorld_DW.DelayInput1_DSTATE = rtb_Compare;

        /* Level2 S-Function Block: '<S1>/S-Function1' (printout) */
        {
          SimStruct *rts = HelloWorld_M->childSfunctions[0];
          sfcnUpdate(rts, 1);
          if (ssGetErrorStatus(rts) != (NULL))
            return;
        }
      }
    }
  }
}

/* Model step function */
void HelloWorld_step(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  HelloWorld_M->Timing.clockTick0++;
}

/* Model initialize function */
void HelloWorld_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)HelloWorld_M, 0,
                sizeof(RT_MODEL_HelloWorld_T));
  rtsiSetSolverName(&HelloWorld_M->solverInfo,"FixedStepDiscrete");
  HelloWorld_M->solverInfoPtr = (&HelloWorld_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = HelloWorld_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    HelloWorld_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    HelloWorld_M->Timing.sampleTimes = (&HelloWorld_M->Timing.sampleTimesArray[0]);
    HelloWorld_M->Timing.offsetTimes = (&HelloWorld_M->Timing.offsetTimesArray[0]);

    /* task periods */
    HelloWorld_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    HelloWorld_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(HelloWorld_M, &HelloWorld_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = HelloWorld_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    HelloWorld_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(HelloWorld_M, -1);
  HelloWorld_M->Timing.stepSize1 = 0.01;
  HelloWorld_M->solverInfoPtr = (&HelloWorld_M->solverInfo);
  HelloWorld_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&HelloWorld_M->solverInfo, 0.01);
  rtsiSetSolverMode(&HelloWorld_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &HelloWorld_B), 0,
                sizeof(B_HelloWorld_T));

  /* states (dwork) */
  (void) memset((void *)&HelloWorld_DW, 0,
                sizeof(DW_HelloWorld_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &HelloWorld_M->NonInlinedSFcns.sfcnInfo;
    HelloWorld_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(HelloWorld_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &HelloWorld_M->Sizes.numSampTimes);
    HelloWorld_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(HelloWorld_M)[0]);
    HelloWorld_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(HelloWorld_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,HelloWorld_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(HelloWorld_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(HelloWorld_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(HelloWorld_M));
    rtssSetStepSizePtr(sfcnInfo, &HelloWorld_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(HelloWorld_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &HelloWorld_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &HelloWorld_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &HelloWorld_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &HelloWorld_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &HelloWorld_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &HelloWorld_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &HelloWorld_M->solverInfoPtr);
  }

  HelloWorld_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&HelloWorld_M->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    HelloWorld_M->childSfunctions =
      (&HelloWorld_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    HelloWorld_M->childSfunctions[0] =
      (&HelloWorld_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: HelloWorld/<S1>/S-Function1 (printout) */
    {
      SimStruct *rts = HelloWorld_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = HelloWorld_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = HelloWorld_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = HelloWorld_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &HelloWorld_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, HelloWorld_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &HelloWorld_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &HelloWorld_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &HelloWorld_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &HelloWorld_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &HelloWorld_B.DataTypeConversion);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &HelloWorld_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &HelloWorld_B.SFunction1));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts, "HelloWorld/HelloWorld/S-Function1");
      ssSetRTModel(rts,HelloWorld_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      printout(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, -1.0);
      ssSetOffsetTime(rts, 0, -2.0);
      sfcnTsMap[0] = 1;

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

  /* Start for S-Function (linux_task): '<S2>/S-Function1' incorporates:
   *  Start for SubSystem: '<Root>/HelloWorld'
   */
  /* Start for function-call system: '<Root>/HelloWorld' */

  /* Level2 S-Function Block: '<S1>/S-Function1' (printout) */
  {
    SimStruct *rts = HelloWorld_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (linux_task): '<S2>/S-Function1' */
  {
    pthread_attr_t attr;
    pthread_t thread;
    struct sched_param param;
    int policy;
    int inherit;
    int ret;
    size_t stackSize;
    pthread_attr_init(&attr);

    /* Set thread inherit attribute */
    inherit = PTHREAD_EXPLICIT_SCHED;
    ret = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    CHECK_STATUS(ret, "pthread_attr_setinheritsched");

    /* Set thread detach attribute */
    ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    CHECK_STATUS(ret, "pthread_attr_setdetachstate");

    /* Set thread stack size attribute */
    stackSize = (512 > PTHREAD_STACK_MIN) ? 512:PTHREAD_STACK_MIN;
    ret = pthread_attr_setstacksize(&attr, stackSize);
    CHECK_STATUS(ret, "pthread_attr_setstacksize");

    /* Set thread schedule policy attribute */
    policy = SCHED_FIFO;
    ret = pthread_attr_setschedpolicy(&attr, policy);
    CHECK_STATUS(ret, "pthread_attr_setschedpolicy");

    /* Set thread priority attribute */
    param.sched_priority = (int_T)1.0;
    ret = pthread_attr_setschedparam(&attr, &param);
    CHECK_STATUS(ret, "pthread_attr_setschedpolicy");

    /* Create the thread */
    ret = pthread_create(&thread, &attr, (void *) Hello_fcn, NULL);
    CHECK_STATUS(ret, "pthread_create");
    pthread_attr_destroy(&attr);
  }

  /* InitializeConditions for S-Function (linux_task): '<S2>/S-Function1' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/HelloWorld'
   */
  /* Initial conditions for function-call system: '<Root>/HelloWorld' */

  /* InitializeConditions for UnitDelay: '<S3>/Delay Input1' */
  HelloWorld_DW.DelayInput1_DSTATE = HelloWorld_P.DetectRisePositive_vinit;

  /* Level2 S-Function Block: '<S1>/S-Function1' (printout) */
  {
    SimStruct *rts = HelloWorld_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void HelloWorld_terminate(void)
{
  /* Terminate for S-Function (linux_task): '<S2>/S-Function1' incorporates:
   *  Terminate for SubSystem: '<Root>/HelloWorld'
   */
  /* Termination for function-call system: '<Root>/HelloWorld' */

  /* Level2 S-Function Block: '<S1>/S-Function1' (printout) */
  {
    SimStruct *rts = HelloWorld_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
