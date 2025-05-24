/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: indicator_logic.h
 *
 * Code generated for Simulink model 'indicator_logic'.
 *
 * Model version                  : 1.57
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri May 23 17:25:22 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef indicator_logic_h_
#define indicator_logic_h_
#ifndef indicator_logic_COMMON_INCLUDES_
#define indicator_logic_COMMON_INCLUDES_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#endif                                 /* indicator_logic_COMMON_INCLUDES_ */

#include "indicator_logic_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint32_t entry_time;                 /* '<Root>/Chart' */
  uint8_t is_active_c3_indicator_logic;/* '<Root>/Chart' */
  uint8_t is_c3_indicator_logic;       /* '<Root>/Chart' */
  uint8_t tp_Idle;                     /* '<Root>/Chart' */
} DW_indicator_logic_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_t BTNL;                        /* '<Root>/BTNL' */
  uint8_t BTNR;                        /* '<Root>/BTNR' */
  uint32_t time;                       /* '<Root>/time' */
} ExtU_indicator_logic_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint8_t led_left;                    /* '<Root>/led_left' */
  uint8_t led_right;                   /* '<Root>/led_right' */
  uint8_t pwm;                         /* '<Root>/pwm' */
} ExtY_indicator_logic_T;

/* Real-time Model Data Structure */
struct tag_RTM_indicator_logic_T {
  const char * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_indicator_logic_T indicator_logic_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_indicator_logic_T indicator_logic_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_indicator_logic_T indicator_logic_Y;

/* Model entry point functions */
extern void indicator_logic_initialize(void);
extern void indicator_logic_step(void);
extern void indicator_logic_terminate(void);

/* Real-time Model object */
extern RT_MODEL_indicator_logic_T *const indicator_logic_M;

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
 * '<Root>' : 'indicator_logic'
 * '<S1>'   : 'indicator_logic/Chart'
 */
#endif                                 /* indicator_logic_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
