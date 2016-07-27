/*
 * File: MultiTask.h
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

#ifndef RTW_HEADER_MultiTask_h_
#define RTW_HEADER_MultiTask_h_
#include <string.h>
#include <math.h>
#ifndef MultiTask_COMMON_INCLUDES_
# define MultiTask_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "HostLib_Network.h"
#endif                                 /* MultiTask_COMMON_INCLUDES_ */

#include "MultiTask_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmCounterLimit
# define rtmCounterLimit(rtm, idx)     ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T SineWave;                     /* '<S2>/Sine Wave' */
  real_T SineWave_a;                   /* '<S1>/Sine Wave' */
  uint8_T BytePack[8];                 /* '<S2>/Byte Pack' */
  uint8_T BytePack_m[8];               /* '<S1>/Byte Pack' */
} B_MultiTask_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UDPSend_NetworkLib[137];      /* '<S2>/UDP Send' */
  real_T UDPSend_NetworkLib_i[137];    /* '<S1>/UDP Send' */
} DW_MultiTask_T;

/* Parameters (auto storage) */
struct P_MultiTask_T_ {
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
  real_T SineWave_Amp_f;               /* Expression: 1
                                        * Referenced by: '<S2>/Sine Wave'
                                        */
  real_T SineWave_Bias_g;              /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave'
                                        */
  real_T SineWave_Freq_h;              /* Expression: 1
                                        * Referenced by: '<S2>/Sine Wave'
                                        */
  real_T SineWave_Phase_p;             /* Expression: 0
                                        * Referenced by: '<S2>/Sine Wave'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_MultiTask_T {
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
    struct {
      uint8_T TID[2];
      uint8_T cLimit[2];
    } TaskCounters;

    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_MultiTask_T MultiTask_P;

/* Block signals (auto storage) */
extern B_MultiTask_T MultiTask_B;

/* Block states (auto storage) */
extern DW_MultiTask_T MultiTask_DW;

/* Model entry point functions */
extern void MultiTask_initialize(void);
extern void MultiTask_step0(void);
extern void MultiTask_step1(void);
extern void MultiTask_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MultiTask_T *const MultiTask_M;

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
 * '<Root>' : 'MultiTask'
 * '<S1>'   : 'MultiTask/SendData1'
 * '<S2>'   : 'MultiTask/SendData2'
 */
#endif                                 /* RTW_HEADER_MultiTask_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
