/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_control.c
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

#include "motor_control.h"
#include "motor_control_private.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_motor_control_T motor_control_B;

/* Block states (default storage) */
DW_motor_control_T motor_control_DW;

/* Real-time model */
static RT_MODEL_motor_control_T motor_control_M_;
RT_MODEL_motor_control_T *const motor_control_M = &motor_control_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void motor_control_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(motor_control_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(motor_control_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(motor_control_M, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(motor_control_M, 4));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (motor_control_M->Timing.TaskCounters.TID[1])++;
  if ((motor_control_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    motor_control_M->Timing.TaskCounters.TID[1] = 0;
  }

  (motor_control_M->Timing.TaskCounters.TID[2])++;
  if ((motor_control_M->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.1s, 0.0s] */
    motor_control_M->Timing.TaskCounters.TID[2] = 0;
  }

  (motor_control_M->Timing.TaskCounters.TID[3])++;
  if ((motor_control_M->Timing.TaskCounters.TID[3]) > 499) {/* Sample time: [0.5s, 0.0s] */
    motor_control_M->Timing.TaskCounters.TID[3] = 0;
  }

  (motor_control_M->Timing.TaskCounters.TID[4])++;
  if ((motor_control_M->Timing.TaskCounters.TID[4]) > 999) {/* Sample time: [1.0s, 0.0s] */
    motor_control_M->Timing.TaskCounters.TID[4] = 0;
  }
}

/* Model step function for TID0 */
void motor_control_step0(void)         /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void motor_control_step1(void)         /* Sample time: [0.01s, 0.0s] */
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_TmpRTBAtFunctionCallSubsyst;
  int32_T c;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  if (motor_control_DW.clockTickCounter >= motor_control_P.PulseGenerator_Period
      - 1.0) {
    motor_control_DW.clockTickCounter = 0;
  } else {
    motor_control_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */
  /* RateTransition generated from: '<S4>/Function-Call Subsystem' */
  rtb_TmpRTBAtFunctionCallSubsyst =
    motor_control_DW.TmpRTBAtFunctionCallSubsystemOu;

  /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
   *  DataStoreRead: '<S4>/Data Store Read'
   *  DataStoreRead: '<S4>/Data Store Read1'
   *  DataStoreRead: '<S4>/Data Store Read2'
   */
  switch ((int32_T)rtb_TmpRTBAtFunctionCallSubsyst) {
   case 0:
    rtb_TmpRTBAtFunctionCallSubsyst = motor_control_DW.BLed_100ms;
    break;

   case 1:
    rtb_TmpRTBAtFunctionCallSubsyst = motor_control_DW.BLed_500ms;
    break;

   default:
    rtb_TmpRTBAtFunctionCallSubsyst = motor_control_DW.BLed_1000ms;
    break;
  }

  /* End of MultiPortSwitch: '<S4>/Multiport Switch' */

  /* MATLABSystem: '<S13>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (rtb_TmpRTBAtFunctionCallSubsyst != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S13>/Digital Port Write' */
}

/* Model step function for TID2 */
void motor_control_step2(void)         /* Sample time: [0.1s, 0.0s] */
{
  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' incorporates:
   *  DataStoreWrite: '<S6>/Data Store Write'
   */
  motor_control_DW.BLed_100ms = (motor_control_DW.clockTickCounter_e <
    motor_control_P.PulseGenerator1_Duty) &&
    (motor_control_DW.clockTickCounter_e >= 0) ?
    motor_control_P.PulseGenerator1_Amp : 0.0;
  if (motor_control_DW.clockTickCounter_e >=
      motor_control_P.PulseGenerator1_Period - 1.0) {
    motor_control_DW.clockTickCounter_e = 0;
  } else {
    motor_control_DW.clockTickCounter_e++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator1' */
}

/* Model step function for TID3 */
void motor_control_step3(void)         /* Sample time: [0.5s, 0.0s] */
{
  /* DiscretePulseGenerator: '<Root>/Pulse Generator2' incorporates:
   *  DataStoreWrite: '<S7>/Data Store Write'
   */
  motor_control_DW.BLed_500ms = (motor_control_DW.clockTickCounter_g <
    motor_control_P.PulseGenerator2_Duty) &&
    (motor_control_DW.clockTickCounter_g >= 0) ?
    motor_control_P.PulseGenerator2_Amp : 0.0;
  if (motor_control_DW.clockTickCounter_g >=
      motor_control_P.PulseGenerator2_Period - 1.0) {
    motor_control_DW.clockTickCounter_g = 0;
  } else {
    motor_control_DW.clockTickCounter_g++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator2' */
}

/* Model step function for TID4 */
void motor_control_step4(void)         /* Sample time: [1.0s, 0.0s] */
{
  /* DiscretePulseGenerator: '<Root>/Pulse Generator3' incorporates:
   *  DataStoreWrite: '<S8>/Data Store Write'
   */
  motor_control_DW.BLed_1000ms = (motor_control_DW.clockTickCounter_b <
    motor_control_P.PulseGenerator3_Duty) &&
    (motor_control_DW.clockTickCounter_b >= 0) ?
    motor_control_P.PulseGenerator3_Amp : 0.0;
  if (motor_control_DW.clockTickCounter_b >=
      motor_control_P.PulseGenerator3_Period - 1.0) {
    motor_control_DW.clockTickCounter_b = 0;
  } else {
    motor_control_DW.clockTickCounter_b++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator3' */
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void motor_control_step(int_T tid)
{
  switch (tid) {
   case 0 :
    motor_control_step0();
    break;

   case 1 :
    motor_control_step1();
    break;

   case 2 :
    motor_control_step2();
    break;

   case 3 :
    motor_control_step3();
    break;

   case 4 :
    motor_control_step4();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void motor_control_initialize(void)
{
  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  motor_control_DW.BLed_100ms = motor_control_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  motor_control_DW.BLed_500ms = motor_control_P.DataStoreMemory1_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  motor_control_DW.BLed_1000ms = motor_control_P.DataStoreMemory2_InitialValue;

  /* InitializeConditions for RateTransition generated from: '<S4>/Function-Call Subsystem' */
  motor_control_DW.TmpRTBAtFunctionCallSubsystemOu =
    motor_control_P.TmpRTBAtFunctionCallSubsystemOu;

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S19>/Hardware Interrupt' incorporates:
   *  SubSystem: '<S4>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<S4>/Function-Call Subsystem' */

  /* InitializeConditions for UnitDelay: '<S15>/Output' */
  motor_control_DW.Output_DSTATE = motor_control_P.Output_InitialCondition;

  /* SystemInitialize for SignalConversion: '<S14>/Out' incorporates:
   *  Outport: '<S10>/Out1'
   */
  motor_control_B.Out = motor_control_P.Out1_Y0;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S19>/Hardware Interrupt' */
}

/* Model terminate function */
void motor_control_terminate(void)
{
  /* (no terminate code required) */
}

void motor_control_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(55,&EXTI15_10_IRQHandler,3);
  MW_NVIC_EnableIRQ(55);
}

/* Hardware Interrupt Block: '<S19>/Hardware Interrupt' */
void EXTI15_10_IRQHandler(void)
{
  /* Event: EXTI13 Event */
  /* Check event EXTI13 Event occurred */
  if (0 != ((0 != LL_EXTI_IsEnabledIT_0_31(LL_EXTI_LINE_13)) && (0 !=
        LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_13)))) {
    /* Clear occurred EXTI13 Event event */
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_13);
    if (1 == runModel) {
      {
        /* S-Function (HardwareInterrupt_sfun): '<S19>/Hardware Interrupt' */

        /* Output and update for function-call system: '<S4>/Function-Call Subsystem' */
        {
          uint8_T rtb_FixPtSum1;

          /* Sum: '<S16>/FixPt Sum1' incorporates:
           *  Constant: '<S16>/FixPt Constant'
           *  UnitDelay: '<S15>/Output'
           */
          rtb_FixPtSum1 = (uint8_T)(motor_control_DW.Output_DSTATE +
            motor_control_P.FixPtConstant_Value);

          /* SignalConversion: '<S14>/Out' incorporates:
           *  Constant: '<S14>/Vector'
           *  MultiPortSwitch: '<S14>/Output'
           *  UnitDelay: '<S15>/Output'
           */
          motor_control_B.Out =
            motor_control_P.RepeatingSequenceStair_OutValue[motor_control_DW.Output_DSTATE];

          /* Switch: '<S17>/FixPt Switch' */
          if (rtb_FixPtSum1 > motor_control_P.WrapToZero_Threshold) {
            /* Update for UnitDelay: '<S15>/Output' incorporates:
             *  Constant: '<S17>/Constant'
             */
            motor_control_DW.Output_DSTATE = motor_control_P.Constant_Value;
          } else {
            /* Update for UnitDelay: '<S15>/Output' */
            motor_control_DW.Output_DSTATE = rtb_FixPtSum1;
          }

          /* End of Switch: '<S17>/FixPt Switch' */
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S19>/Hardware Interrupt' */

        /* RateTransition generated from: '<S4>/Function-Call Subsystem' */
        motor_control_DW.TmpRTBAtFunctionCallSubsystemOu = motor_control_B.Out;
      }
    }
  }

  __ISB();
  __DSB();
}

void motor_control_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(55);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
