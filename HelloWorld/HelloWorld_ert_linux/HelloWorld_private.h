/*
 * File: HelloWorld_private.h
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

#ifndef RTW_HEADER_HelloWorld_private_h_
#define RTW_HEADER_HelloWorld_private_h_
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

/* Define number of LINUX task blocks */
#define NUM_TSK_BLOCKS                 (1)
#define CHECK_STATUS(status, fcn)      if (status != 0) {fprintf(stderr, "Call to %s returned error status (%d).\n", fcn, status); perror(fcn); fflush(stderr); exit(EXIT_FAILURE);}
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

extern void printout(SimStruct *rts);

#endif                                 /* RTW_HEADER_HelloWorld_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
