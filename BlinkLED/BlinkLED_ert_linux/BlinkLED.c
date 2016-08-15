/*
 * File: BlinkLED.c
 *
 * Code generated for Simulink model 'BlinkLED'.
 *
 * Model version                  : 1.49
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Thu Aug 11 21:13:43 2016
 *
 * Target selection: ert_linux.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "BlinkLED.h"
#include "BlinkLED_private.h"

/* Block signals (auto storage) */
B_BlinkLED_T BlinkLED_B;

/* Block states (auto storage) */
DW_BlinkLED_T BlinkLED_DW;

/* Real-time model */
RT_MODEL_BlinkLED_T BlinkLED_M_;
RT_MODEL_BlinkLED_T *const BlinkLED_M = &BlinkLED_M_;

/* Model step function */
void BlinkLED_step(void)
{
  boolean_T rtb_Compare;

  /* S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/BlinkLED'
   */
  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  Sin: '<S1>/Sine Wave'
   */
  rtb_Compare = (sin(BlinkLED_P.SineWave_Freq * BlinkLED_M->Timing.t[0] +
                     BlinkLED_P.SineWave_Phase) * BlinkLED_P.SineWave_Amp +
                 BlinkLED_P.SineWave_Bias > BlinkLED_P.Constant_Value);

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  RelationalOperator: '<S2>/FixPt Relational Operator'
   *  UnitDelay: '<S2>/Delay Input1'
   */
  BlinkLED_B.DataTypeConversion = ((int32_T)rtb_Compare > (int32_T)
    BlinkLED_DW.DelayInput1_DSTATE);

  /* Level2 S-Function Block: '<S1>/S-Function1' (dgio_sfun) */
  {
    SimStruct *rts = BlinkLED_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* Update for UnitDelay: '<S2>/Delay Input1' */
  BlinkLED_DW.DelayInput1_DSTATE = rtb_Compare;

  /* Level2 S-Function Block: '<S1>/S-Function1' (dgio_sfun) */
  {
    SimStruct *rts = BlinkLED_M->childSfunctions[0];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++BlinkLED_M->Timing.clockTick0)) {
    ++BlinkLED_M->Timing.clockTickH0;
  }

  BlinkLED_M->Timing.t[0] = BlinkLED_M->Timing.clockTick0 *
    BlinkLED_M->Timing.stepSize0 + BlinkLED_M->Timing.clockTickH0 *
    BlinkLED_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void BlinkLED_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)BlinkLED_M, 0,
                sizeof(RT_MODEL_BlinkLED_T));
  rtsiSetSolverName(&BlinkLED_M->solverInfo,"FixedStepDiscrete");
  BlinkLED_M->solverInfoPtr = (&BlinkLED_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = BlinkLED_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    BlinkLED_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    BlinkLED_M->Timing.sampleTimes = (&BlinkLED_M->Timing.sampleTimesArray[0]);
    BlinkLED_M->Timing.offsetTimes = (&BlinkLED_M->Timing.offsetTimesArray[0]);

    /* task periods */
    BlinkLED_M->Timing.sampleTimes[0] = (0.005);

    /* task offsets */
    BlinkLED_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(BlinkLED_M, &BlinkLED_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = BlinkLED_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    BlinkLED_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(BlinkLED_M, -1);
  BlinkLED_M->Timing.stepSize0 = 0.005;
  BlinkLED_M->solverInfoPtr = (&BlinkLED_M->solverInfo);
  BlinkLED_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&BlinkLED_M->solverInfo, 0.005);
  rtsiSetSolverMode(&BlinkLED_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &BlinkLED_B), 0,
                sizeof(B_BlinkLED_T));

  /* states (dwork) */
  (void) memset((void *)&BlinkLED_DW, 0,
                sizeof(DW_BlinkLED_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &BlinkLED_M->NonInlinedSFcns.sfcnInfo;
    BlinkLED_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(BlinkLED_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &BlinkLED_M->Sizes.numSampTimes);
    BlinkLED_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(BlinkLED_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,BlinkLED_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(BlinkLED_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(BlinkLED_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(BlinkLED_M));
    rtssSetStepSizePtr(sfcnInfo, &BlinkLED_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(BlinkLED_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &BlinkLED_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &BlinkLED_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &BlinkLED_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &BlinkLED_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &BlinkLED_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &BlinkLED_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &BlinkLED_M->solverInfoPtr);
  }

  BlinkLED_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&BlinkLED_M->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    BlinkLED_M->childSfunctions =
      (&BlinkLED_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    BlinkLED_M->childSfunctions[0] =
      (&BlinkLED_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: BlinkLED/<S1>/S-Function1 (dgio_sfun) */
    {
      SimStruct *rts = BlinkLED_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = BlinkLED_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = BlinkLED_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = BlinkLED_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &BlinkLED_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, BlinkLED_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &BlinkLED_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &BlinkLED_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &BlinkLED_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &BlinkLED_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &BlinkLED_B.DataTypeConversion);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &BlinkLED_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &BlinkLED_B.SFunction1));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts, "BlinkLED/BlinkLED/S-Function1");
      ssSetRTModel(rts,BlinkLED_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      dgio_sfun(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.005);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

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

  /* Start for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<Root>/BlinkLED'
   */
  /* Level2 S-Function Block: '<S1>/S-Function1' (dgio_sfun) */
  {
    SimStruct *rts = BlinkLED_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  InitializeConditions for SubSystem: '<Root>/BlinkLED'
   */
  /* InitializeConditions for UnitDelay: '<S2>/Delay Input1' */
  BlinkLED_DW.DelayInput1_DSTATE = BlinkLED_P.DetectRisePositive_vinit;

  /* Level2 S-Function Block: '<S1>/S-Function1' (dgio_sfun) */
  {
    SimStruct *rts = BlinkLED_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void BlinkLED_terminate(void)
{
  /* Terminate for S-Function (fcncallgen): '<Root>/Function-Call Generator' incorporates:
   *  Terminate for SubSystem: '<Root>/BlinkLED'
   */
  /* Level2 S-Function Block: '<S1>/S-Function1' (dgio_sfun) */
  {
    SimStruct *rts = BlinkLED_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
