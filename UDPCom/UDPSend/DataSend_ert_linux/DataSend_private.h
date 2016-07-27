/*
 * File: DataSend_private.h
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

#ifndef RTW_HEADER_DataSend_private_h_
#define RTW_HEADER_DataSend_private_h_
#include "rtwtypes.h"

/* Define number of LINUX task blocks */
#define NUM_TSK_BLOCKS                 (1)
#define CHECK_STATUS(status, fcn)      if (status != 0) {fprintf(stderr, "Call to %s returned error status (%d).\n", fcn, status); perror(fcn); fflush(stderr); exit(EXIT_FAILURE);}
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */
#endif                                 /* RTW_HEADER_DataSend_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
