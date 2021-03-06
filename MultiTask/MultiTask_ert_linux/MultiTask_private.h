/*
 * File: MultiTask_private.h
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

#ifndef RTW_HEADER_MultiTask_private_h_
#define RTW_HEADER_MultiTask_private_h_
#include "rtwtypes.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

extern void printout(SimStruct *rts);

#endif                                 /* RTW_HEADER_MultiTask_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
