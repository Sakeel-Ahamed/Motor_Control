/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'motor_control'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun Mar  8 10:07:53 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdio.h>
#include <stdlib.h>
#include "motor_control.h"
#include "motor_control_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "mw_stm32_board_header.h"
#include "mw_freertos.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
SemaphoreHandle_t stopSem;
SemaphoreHandle_t baserateTaskSem;
SemaphoreHandle_t subrateTaskSem[4];
int taskId[4];
mw_thread_t schedulerThread;
mw_thread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
mw_thread_t subRateThread[4];
int subratePriority[4];
void *subrateTask(void *arg)
{
  int tid = *((int *) arg);
  int subRateId;
  subRateId = tid + 1;
  while (runModel) {
    mw_osSemaphoreWaitEver(&subrateTaskSem[tid]);
    if (terminatingmodel)
      break;

#ifdef MW_RTOS_DEBUG

    printf(" -subrate task %d semaphore received\n", subRateId);

#endif

    motor_control_step(subRateId);

    /* Get model outputs here */
  }

  mw_osThreadExit((void *)0);
  return NULL;
}

void *baseRateTask(void *arg)
{
  int_T i;
  runModel = (rtmGetErrorStatus(motor_control_M) == (NULL));
  while (runModel) {
    mw_osSemaphoreWaitEver(&baserateTaskSem);

#ifdef MW_RTOS_DEBUG

    printf("*base rate task semaphore received\n");
    fflush(stdout);

#endif

    for (i = 1
         ; i <= 4; i++) {
      if (rtmStepTask(motor_control_M, i)
          ) {
        mw_osSemaphoreRelease(&subrateTaskSem[ i - 1
                              ]);
      }
    }

    motor_control_step(0);

    /* Get model outputs here */
    stopRequested = !((rtmGetErrorStatus(motor_control_M) == (NULL)));
  }

  terminateTask(arg);
  mw_osThreadExit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(motor_control_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    int i;

    /* Signal all periodic tasks to complete */
    for (i=0; i<4; i++) {
      CHECK_STATUS(mw_osSemaphoreRelease(&subrateTaskSem[i]), 0,
                   "mw_osSemaphoreRelease");
      CHECK_STATUS(mw_osSemaphoreDelete(&subrateTaskSem[i]), 0,
                   "mw_osSemaphoreDelete");
    }

    /* Wait for all periodic tasks to complete */
    for (i=0; i<4; i++) {
      CHECK_STATUS(mw_osThreadJoin(subRateThread[i], &threadJoinStatus), 0,
                   "mw_osThreadJoin");
    }

    runModel = 0;
  }

#if !defined(MW_FREERTOS) && !defined(USE_RTX)

  (void) systemClock;

#endif

  ;

  /* Terminate model */
  motor_control_terminate();
  mw_osSemaphoreRelease(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  MW_EnableNVICPeripheral();
  subratePriority[0] = 39;
  subratePriority[1] = 38;
  subratePriority[2] = 37;
  subratePriority[3] = 36;

#if !defined(MW_FREERTOS) && defined(MW_MULTI_TASKING_MODE) && (MW_MULTI_TASKING_MODE == 1)

  MW_ASM (" SVC #1");

#endif

  ;

  // Peripheral initialization imported from STM32CubeMX project;
  HAL_Init();
  SystemClock_Config();
  PeriphCommonClock_Config();
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART2_UART_Init();
  rtmSetErrorStatus(motor_control_M, 0);
  motor_control_configure_interrupts();

  /* Initialize model */
  motor_control_initialize();

  /* Call RTOS Initialization function */
  mw_RTOSInit(0.001, 4);

  /* Wait for stop semaphore */
  mw_osSemaphoreWaitEver(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(mw_osSemaphoreDelete(&timerTaskSem[i]), 0,
                   "mw_osSemaphoreDelete");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
