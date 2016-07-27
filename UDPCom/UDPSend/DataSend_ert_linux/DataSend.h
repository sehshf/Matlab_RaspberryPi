/*
 * File: DataSend.h
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

#ifndef RTW_HEADER_DataSend_h_
#define RTW_HEADER_DataSend_h_
#include <string.h>
#include <math.h>
#ifndef DataSend_COMMON_INCLUDES_
# define DataSend_COMMON_INCLUDES_
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <semaphore.h>
#include <errno.h>
#include <stdio.h>
#include <limits.h>
#include "rtwtypes.h"
#include "HostLib_Network.h"
#endif                                 /* DataSend_COMMON_INCLUDES_ */

#include "DataSend_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T SineWave;                     /* '<S1>/Sine Wave' */
  uint8_T BytePack[8];                 /* '<S1>/Byte Pack' */
} B_DataSend_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UDPSend_NetworkLib[137];      /* '<S1>/UDP Send' */
} DW_DataSend_T;

/* Parameters (auto storage) */
struct P_DataSend_T_ {
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<S1>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<S1>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<S1>/Sine Wave'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_DataSend_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    uint8_T rtmH2LBufBeingRead1;
    uint8_T rtmH2LLastBufWr1;
    uint32_T rtmH2LDbBufClockTick1[2];
    uint32_T rtmH2LDbBufClockTickH1[2];
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_DataSend_T DataSend_P;

/* Block signals (auto storage) */
extern B_DataSend_T DataSend_B;

/* Block states (auto storage) */
extern DW_DataSend_T DataSend_DW;

/* Model entry point functions */
extern void DataSend_initialize(void);
extern void DataSend_step(void);
extern void DataSend_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DataSend_T *const DataSend_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'DataSend'
 * '<S1>'   : 'DataSend/Function-Call Subsystem'
 * '<S2>'   : 'DataSend/Task'
 */
#endif                                 /* RTW_HEADER_DataSend_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
