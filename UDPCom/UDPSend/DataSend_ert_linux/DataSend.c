/*
 * File: DataSend.c
 *
 * Code generated for Simulink model 'DataSend'.
 *
 * Model version                  : 1.42
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Tue Jul 26 22:47:29 2016
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
void Task0_fcn(void)
{
  /* Wait until application is initialized properly */
  while (1) {
    /* Call the system: <Root>/Function-Call Subsystem */
    {
      /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
      {
        char_T *sErr;

        /* Asynchronous task reads absolute time. Data (absolute time)
           transfers from high priority task (base rate) to low priority
           task (asynchronous rate). Double buffers are used to ensure
           data integrity.
           -- rtmH2LBufBeingRead is the index of the buffer being read
           -- rtmH2LLastBufWr is the index of the buffer that is written last.
         */
        if (DataSend_M->Timing.rtmH2LLastBufWr1 == 0) {
          DataSend_M->Timing.rtmH2LBufBeingRead1 = 0;
          DataSend_M->Timing.clockTick1 =
            DataSend_M->Timing.rtmH2LDbBufClockTick1[0];
          DataSend_M->Timing.clockTickH1 =
            DataSend_M->Timing.rtmH2LDbBufClockTickH1[0];
        } else {
          DataSend_M->Timing.rtmH2LBufBeingRead1 = 1;
          DataSend_M->Timing.clockTick1 =
            DataSend_M->Timing.rtmH2LDbBufClockTick1[1];
          DataSend_M->Timing.clockTickH1 =
            DataSend_M->Timing.rtmH2LDbBufClockTickH1[1];
        }

        /* Sin: '<S1>/Sine Wave' */
        DataSend_B.SineWave = sin(DataSend_P.SineWave_Freq *
          (((DataSend_M->Timing.clockTick1+DataSend_M->Timing.clockTickH1*
             4294967296.0)) * 0.005) + DataSend_P.SineWave_Phase) *
          DataSend_P.SineWave_Amp + DataSend_P.SineWave_Bias;

        /* Pack: <S1>/Byte Pack */
        (void) memcpy(&DataSend_B.BytePack[0], &DataSend_B.SineWave,
                      8);

        /* Update for S-Function (sdspToNetwork): '<S1>/UDP Send' */
        sErr = GetErrorBuffer(&DataSend_DW.UDPSend_NetworkLib[0U]);
        LibUpdate_Network(&DataSend_DW.UDPSend_NetworkLib[0U],
                          &DataSend_B.BytePack[0U], 8);
        if (*sErr != 0) {
          rtmSetErrorStatus(DataSend_M, sErr);
          rtmSetStopRequested(DataSend_M, 1);
        }

        /* End of Update for S-Function (sdspToNetwork): '<S1>/UDP Send' */
      }
    }
  }
}

/* Model step function */
void DataSend_step(void)
{
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

  /* Base rate updates double buffers of absolute time for
     asynchronous task 1. Double buffers are used to
     ensure data integrity when asynchronous task reads
     absolute time.
     -- rtmH2LBufBeingRead is the index of the buffer being
     read by the asynchronous task 1
     -- rtmH2LLastBufWr is the index of the buffer that is
     written last.
   */
  if (DataSend_M->Timing.rtmH2LBufBeingRead1 != 0) {
    DataSend_M->Timing.rtmH2LDbBufClockTick1[0] = DataSend_M->Timing.clockTick0;
    DataSend_M->Timing.rtmH2LDbBufClockTickH1[0] =
      DataSend_M->Timing.clockTickH0;
    DataSend_M->Timing.rtmH2LLastBufWr1 = 0;
  } else {
    DataSend_M->Timing.rtmH2LDbBufClockTick1[1] = DataSend_M->Timing.clockTick0;
    DataSend_M->Timing.rtmH2LDbBufClockTickH1[1] =
      DataSend_M->Timing.clockTickH0;
    DataSend_M->Timing.rtmH2LLastBufWr1 = 1;
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

  /* Start for S-Function (linux_task): '<S2>/S-Function1' incorporates:
   *  Start for SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Start for function-call system: '<Root>/Function-Call Subsystem' */
  {
    char_T *sErr;

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
    param.sched_priority = (int_T)10.0;
    ret = pthread_attr_setschedparam(&attr, &param);
    CHECK_STATUS(ret, "pthread_attr_setschedpolicy");

    /* Create the thread */
    ret = pthread_create(&thread, &attr, (void *) Task0_fcn, NULL);
    CHECK_STATUS(ret, "pthread_create");
    pthread_attr_destroy(&attr);
  }
}

/* Model terminate function */
void DataSend_terminate(void)
{
  /* Terminate for S-Function (linux_task): '<S2>/S-Function1' incorporates:
   *  Terminate for SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Termination for function-call system: '<Root>/Function-Call Subsystem' */
  {
    char_T *sErr;

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
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
