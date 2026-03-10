/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_control.h
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

#ifndef motor_control_h_
#define motor_control_h_
#ifndef motor_control_COMMON_INCLUDES_
#define motor_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#include "main.h"
#endif                                 /* motor_control_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "motor_control_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Out;                          /* '<S14>/Out' */
} B_motor_control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  volatile real_T TmpRTBAtFunctionCallSubsystemOu;/* synthesized block */
  real_T BLed_100ms;                   /* '<Root>/Data Store Memory' */
  real_T BLed_500ms;                   /* '<Root>/Data Store Memory1' */
  real_T BLed_1000ms;                  /* '<Root>/Data Store Memory2' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int32_T clockTickCounter_e;          /* '<Root>/Pulse Generator1' */
  int32_T clockTickCounter_g;          /* '<Root>/Pulse Generator2' */
  int32_T clockTickCounter_b;          /* '<Root>/Pulse Generator3' */
  uint8_T Output_DSTATE;               /* '<S15>/Output' */
} DW_motor_control_T;

/* Parameters (default storage) */
struct P_motor_control_T_ {
  real_T RepeatingSequenceStair_OutValue[3];
                              /* Mask Parameter: RepeatingSequenceStair_OutValue
                               * Referenced by: '<S14>/Vector'
                               */
  uint8_T WrapToZero_Threshold;        /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S17>/FixPt Switch'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S10>/Out1'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 2
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T TmpRTBAtFunctionCallSubsystemOu;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory'
                                        */
  real_T DataStoreMemory1_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory1'
                                        */
  real_T DataStoreMemory2_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory2'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;       /* Expression: 2
                                        * Referenced by: '<Root>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty;         /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator1'
                                        */
  real_T PulseGenerator2_Amp;          /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Period;       /* Expression: 2
                                        * Referenced by: '<Root>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_Duty;         /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator2'
                                        */
  real_T PulseGenerator2_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator2'
                                        */
  real_T PulseGenerator3_Amp;          /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_Period;       /* Expression: 2
                                        * Referenced by: '<Root>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_Duty;         /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator3'
                                        */
  real_T PulseGenerator3_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator3'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S17>/Constant'
                                        */
  uint8_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S16>/FixPt Constant'
                                       */
  uint8_T Output_InitialCondition;/* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S15>/Output'
                                   */
};

/* Real-time Model Data Structure */
struct tag_RTM_motor_control_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[5];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_motor_control_T motor_control_P;

/* Block signals (default storage) */
extern B_motor_control_T motor_control_B;

/* Block states (default storage) */
extern DW_motor_control_T motor_control_DW;

/* External function called from main */
extern void motor_control_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void motor_control_initialize(void);
extern void motor_control_step0(void); /* Sample time: [0.001s, 0.0s] */
extern void motor_control_step1(void); /* Sample time: [0.01s, 0.0s] */
extern void motor_control_step2(void); /* Sample time: [0.1s, 0.0s] */
extern void motor_control_step3(void); /* Sample time: [0.5s, 0.0s] */
extern void motor_control_step4(void); /* Sample time: [1.0s, 0.0s] */
extern void motor_control_step(int_T tid);
extern void motor_control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motor_control_T *const motor_control_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void EXTI15_10_IRQHandler(void);
  void motor_control_configure_interrupts (void);
  void motor_control_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S15>/Data Type Propagation' : Unused code path elimination
 * Block '<S16>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/FixPt Data Type Duplicate1' : Unused code path elimination
 */

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
 * '<Root>' : 'motor_control'
 * '<S1>'   : 'motor_control/1000ms'
 * '<S2>'   : 'motor_control/100ms'
 * '<S3>'   : 'motor_control/10ms'
 * '<S4>'   : 'motor_control/1ms'
 * '<S5>'   : 'motor_control/500ms'
 * '<S6>'   : 'motor_control/Pulse'
 * '<S7>'   : 'motor_control/Pulse  '
 * '<S8>'   : 'motor_control/Pulse   '
 * '<S9>'   : 'motor_control/1ms/Digital Port Write'
 * '<S10>'  : 'motor_control/1ms/Function-Call Subsystem'
 * '<S11>'  : 'motor_control/1ms/Hardware Interrupt'
 * '<S12>'  : 'motor_control/1ms/Digital Port Write/ECSoC'
 * '<S13>'  : 'motor_control/1ms/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S14>'  : 'motor_control/1ms/Function-Call Subsystem/Repeating Sequence Stair'
 * '<S15>'  : 'motor_control/1ms/Function-Call Subsystem/Repeating Sequence Stair/LimitedCounter'
 * '<S16>'  : 'motor_control/1ms/Function-Call Subsystem/Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S17>'  : 'motor_control/1ms/Function-Call Subsystem/Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 * '<S18>'  : 'motor_control/1ms/Hardware Interrupt/ECSoC'
 * '<S19>'  : 'motor_control/1ms/Hardware Interrupt/ECSoC/ECSimCodegen'
 */
#endif                                 /* motor_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
