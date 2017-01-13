/*
 * File: ert_main.c
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

/* Multirate - Multitasking case main file */
#define _BSD_SOURCE                                              /* For usleep() */
#define _POSIX_C_SOURCE                200112L                   /* For clock_gettime() & clock_nanosleep() */
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include <pthread.h>                   /* Thread library header file */
#include <sched.h>                     /* OS scheduler header file */
#include <semaphore.h>                 /* Semaphores library header file */
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/mman.h>                  /* For mlockall() */
#include "MultiTask.h"                 /* Model's header file */
#include "rtwtypes.h"                  /* MathWorks types */
#ifndef TRUE
#define TRUE                           true
#define FALSE                          false
#endif

/*==================*
 * Required defines *
 *==================*/
#ifndef MODEL
# error Must specify a model name. Define MODEL=name.
#else

/* create generic macros that work with any model */
# define EXPAND_CONCAT(name1,name2)    name1 ## name2
# define CONCAT(name1,name2)           EXPAND_CONCAT(name1,name2)
# define MODEL_INITIALIZE              CONCAT(MODEL,_initialize)
# define MODEL_STEP                    CONCAT(MODEL,_step)
# define MODEL_TERMINATE               CONCAT(MODEL,_terminate)
# define RT_MDL                        CONCAT(MODEL,_M)
#endif

/* Error checking */
#define STRINGIZE(num)                 #num
#define POS(line)                      __FILE__ ":" STRINGIZE(line)
#define CHECK0(expr)                   do { int __err = (expr); if (__err) { fprintf(stderr, "Error: %s returned '%s' at " POS(__LINE__) "\n", #expr, strerror(__err)); exit(1); } } while (0);
#define CHECKE(expr)                   do { if ((expr) == -1) { perror(#expr " at " POS(__LINE__)); exit(1); } } while (0);

/**
 * Maximal priority used by base rate thread.
 */
#define MAX_PRIO                       (sched_get_priority_min(SCHED_FIFO) + 3)

/**
 * Thread handle of the base rate thread.
 * Fundamental sample time = 0.005s
 */
pthread_t base_rate_thread;

/**
 * Thread handles of and semaphores for sub rate threads. The array
 * is indexed by TID, i.e. the first one or two elements are unused.
 * TID1: sample time = 0.01s, offset = 0.0s
 * TID2: sample time = 0.02s, offset = 0.0s
 */
struct sub_rate {
  pthread_t thread;
  sem_t sem;
} sub_rate[3];

/**
 * Flag if the simulation has been terminated.
 */
int simulationFinished = 0;
void *sub_rate1(void *arg)
{
  while (!simulationFinished) {
    sem_wait(&sub_rate[1].sem);        /* sem_val = 1 */
    MultiTask_step1();
    sem_wait(&sub_rate[1].sem);        /* sem_val = 0 */
  }

  return NULL;
}

void *sub_rate2(void *arg)
{
  while (!simulationFinished) {
    sem_wait(&sub_rate[2].sem);        /* sem_val = 1 */
    MultiTask_step2();
    sem_wait(&sub_rate[2].sem);        /* sem_val = 0 */
  }

  return NULL;
}

/**
 * This is the thread function of the base rate loop.
 * Fundamental sample time = 0.005s
 */
void * base_rate()
{
  struct timespec now, next;
  struct timespec period = { 0U, 5000000U };/* 0.005 seconds */

  boolean_T eventFlags[3];             /* Model has 3 rates */
  int_T taskCounter[3] = { 0, 0, 0 };

  int_T OverrunFlags[3];
  int step_sem_value;
  int_T i;
  clock_gettime(CLOCK_MONOTONIC, &next);

  /* Main loop, running until all the threads are terminated */
  while (rtmGetErrorStatus(MultiTask_M) == NULL && !rtmGetStopRequested
         (MultiTask_M)) {
    /* Check subrate overrun, set rates that need to run this time step*/
    for (i = 1; i < 3; i++) {
      if (taskCounter[i] == 0) {
        if (eventFlags[i]) {
          OverrunFlags[0] = false;
          OverrunFlags[i] = true;

          /* Sampling too fast */
          rtmSetErrorStatus(MultiTask_M, "Overrun");
          return;
        }

        eventFlags[i] = true;
      }
    }

    taskCounter[1]++;
    if (taskCounter[1] == 2) {
      taskCounter[1]= 0;
    }

    taskCounter[2]++;
    if (taskCounter[2] == 4) {
      taskCounter[2]= 0;
    }

    /* Trigger sub-rate threads */
    /* Sampling rate 1, sample time = 0.01, offset = 0.0 */
    if (eventFlags[1]) {
      eventFlags[1] = FALSE;
      sem_getvalue(&sub_rate[1].sem, &step_sem_value);
      if (step_sem_value) {
        rtmSetErrorStatus(MultiTask_M, "Overrun");
        printf("Sub rate 1 overrun, sample time=0.01s, offset=0.0s is too fast\n");
        break;
      }

      sem_post(&sub_rate[1].sem);
      sem_post(&sub_rate[1].sem);
    }

    /* Sampling rate 2, sample time = 0.02, offset = 0.0 */
    if (eventFlags[2]) {
      eventFlags[2] = FALSE;
      sem_getvalue(&sub_rate[2].sem, &step_sem_value);
      if (step_sem_value) {
        rtmSetErrorStatus(MultiTask_M, "Overrun");
        printf("Sub rate 2 overrun, sample time=0.02s, offset=0.0s is too fast\n");
        break;
      }

      sem_post(&sub_rate[2].sem);
      sem_post(&sub_rate[2].sem);
    }

    /* Execute base rate step */
    MultiTask_step0();
    do {
      next.tv_sec += period.tv_sec;
      next.tv_nsec += period.tv_nsec;
      if (next.tv_nsec >= 1000000000) {
        next.tv_sec++;
        next.tv_nsec -= 1000000000;
      }

      clock_gettime(CLOCK_MONOTONIC, &now);
      if (now.tv_sec > next.tv_sec ||
          (now.tv_sec == next.tv_sec && now.tv_nsec > next.tv_nsec)) {
        uint32_T usec = (now.tv_sec - next.tv_sec) * 1000000 + (now.tv_nsec -
          next.tv_nsec)/1000;
        fprintf(stderr, "Base rate (0.005s) overrun by %d us\n", usec);
        next = now;
        continue;
      }
    } while (0);

    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &next, NULL);
  }

  simulationFinished = 1;

  /* Final step */
  for (i = 1; i < 3; i++) {
    sem_post(&sub_rate[i].sem);
    sem_post(&sub_rate[i].sem);
  }
}

/**
 * This is the main function of the model.
 * Multirate - Multitasking case main file
 */
int_T main(int_T argc, const char_T *argv[])
{
  const char_T *errStatus;
  int_T i;
  pthread_attr_t attr;
  struct sched_param sched_param;
  (void)(argc);
  (void *)(argv);
  CHECKE(mlockall(MCL_CURRENT | MCL_FUTURE));

  /* Initialize model */
  MultiTask_initialize();
  simulationFinished = 0;

  /* Prepare task attributes */
  CHECK0(pthread_attr_init(&attr));
  CHECK0(pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED));
  CHECK0(pthread_attr_setschedpolicy(&attr, SCHED_FIFO));

  /* Initializing the step semaphore of the loop 1 */
  CHECKE(sem_init(&sub_rate[1].sem, 0, 0));

  /* Starting loop 1 thread for sample time = 0.01s, offset = 0.0s. */
  sched_param.sched_priority = MAX_PRIO - 1;
  CHECK0(pthread_attr_setschedparam(&attr, &sched_param));
  CHECK0(pthread_create(&sub_rate[1].thread, &attr, sub_rate1, (void*)1));

  /* Initializing the step semaphore of the loop 2 */
  CHECKE(sem_init(&sub_rate[2].sem, 0, 0));

  /* Starting loop 2 thread for sample time = 0.02s, offset = 0.0s. */
  sched_param.sched_priority = MAX_PRIO - 2;
  CHECK0(pthread_attr_setschedparam(&attr, &sched_param));
  CHECK0(pthread_create(&sub_rate[2].thread, &attr, sub_rate2, (void*)2));

  /* Starting the base rate thread */
  sched_param.sched_priority = MAX_PRIO;
  CHECK0(pthread_attr_setschedparam(&attr, &sched_param));
  CHECK0(pthread_create(&base_rate_thread, &attr, base_rate, NULL));
  CHECK0(pthread_attr_destroy(&attr));

  /* Wait for threads to finish */
  pthread_join(base_rate_thread, NULL);
  pthread_join(sub_rate[1].thread, NULL);
  pthread_join(sub_rate[2].thread, NULL);

  /* Terminate model */
  MultiTask_terminate();
  errStatus = rtmGetErrorStatus(MultiTask_M);
  if (errStatus != NULL && strcmp(errStatus, "Simulation finished")) {
    if (!strcmp(errStatus, "Overrun")) {
      printf("ISR overrun - sampling rate too fast\n");
    }

    return(1);
  }

  return 0;
}

/* Local Variables: */
/* compile-command: "make -f MultiTask.mk" */
/* End: */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
