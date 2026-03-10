/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motor_control_data.c
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

/* Block parameters (default storage) */
P_motor_control_T motor_control_P = {
  /* Mask Parameter: RepeatingSequenceStair_OutValue
   * Referenced by: '<S14>/Vector'
   */
  { 1.0, 2.0, 0.0 },

  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S17>/FixPt Switch'
   */
  2U,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S10>/Out1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<Root>/Pulse Generator'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator1'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<Root>/Pulse Generator1'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator2'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<Root>/Pulse Generator2'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator3'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<Root>/Pulse Generator3'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator3'
   */
  0.0,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S17>/Constant'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S16>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S15>/Output'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
