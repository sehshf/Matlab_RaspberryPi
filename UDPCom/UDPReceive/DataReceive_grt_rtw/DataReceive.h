/*
 * DataReceive.h
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
#ifndef RTW_HEADER_DataReceive_h_
#define RTW_HEADER_DataReceive_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef DataReceive_COMMON_INCLUDES_
# define DataReceive_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "HostLib_Network.h"
#endif                                 /* DataReceive_COMMON_INCLUDES_ */

#include "DataReceive_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

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

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T ByteUnpack;                   /* '<Root>/Byte Unpack' */
  uint16_T UDPReceive1_o2;             /* '<Root>/UDP Receive1' */
  uint8_T UDPReceive1_o1[8];           /* '<Root>/UDP Receive1' */
} B_DataReceive_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UDPReceive1_NetworkLib[137];  /* '<Root>/UDP Receive1' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_DataReceive_T;

/* Real-time Model Data Structure */
struct tag_RTM_DataReceive_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    struct {
      uint8_T TID[2];
      uint8_T cLimit[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (auto storage) */
extern B_DataReceive_T DataReceive_B;

/* Block states (auto storage) */
extern DW_DataReceive_T DataReceive_DW;

/* Model entry point functions */
extern void DataReceive_initialize(void);
extern void DataReceive_step(int_T tid);
extern void DataReceive_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DataReceive_T *const DataReceive_M;

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
 * '<Root>' : 'DataReceive'
 */
#endif                                 /* RTW_HEADER_DataReceive_h_ */
