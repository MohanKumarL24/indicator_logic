/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: indicator_logic.c
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

#include "indicator_logic.h"
#include <stdint.h>
#include <stdbool.h>

/* Named constants for Chart: '<Root>/Chart' */
#define indicator_logic_IN_Hazard      ((uint8_t)1U)
#define indicator_logic_IN_Hold_1      ((uint8_t)2U)
#define indicator_logic_IN_Hold_2      ((uint8_t)3U)
#define indicator_logic_IN_Hold_3      ((uint8_t)4U)
#define indicator_logic_IN_Hold_4      ((uint8_t)5U)
#define indicator_logic_IN_Hold_5      ((uint8_t)6U)
#define indicator_logic_IN_Hold_6      ((uint8_t)7U)
#define indicator_logic_IN_Hold_7      ((uint8_t)8U)
#define indicator_logic_IN_Hold_8      ((uint8_t)9U)
#define indicator_logic_IN_Idle        ((uint8_t)10U)
#define indicator_logic_IN_Left        ((uint8_t)11U)
#define indicator_logic_IN_Right       ((uint8_t)12U)

/* Block states (default storage) */
DW_indicator_logic_T indicator_logic_DW;

/* External inputs (root inport signals with default storage) */
ExtU_indicator_logic_T indicator_logic_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_indicator_logic_T indicator_logic_Y;

/* Real-time model */
static RT_MODEL_indicator_logic_T indicator_logic_M_;
RT_MODEL_indicator_logic_T *const indicator_logic_M = &indicator_logic_M_;

/* Forward declaration for local functions */
static void indicator_logic_Right(void);
static void indicator_logic_Hold_1(void);
static void indicator_logic_Hold_2(void);
static void indicator_logic_Idle(void);
static void indicator_logic_Left(void);

/* Function for Chart: '<Root>/Chart' */
static void indicator_logic_Right(void)
{
  /* Inport: '<Root>/BTNL' incorporates:
   *  Inport: '<Root>/BTNR'
   */
  if ((indicator_logic_U.BTNL == 0) && (indicator_logic_U.BTNR == 0)) {
    indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Right;

    /* Outport: '<Root>/led_left' */
    indicator_logic_Y.led_left = 0U;

    /* Outport: '<Root>/led_right' */
    indicator_logic_Y.led_right = 1U;

    /* Outport: '<Root>/pwm' */
    indicator_logic_Y.pwm = 1U;
  } else if ((indicator_logic_U.BTNL == 0) && (indicator_logic_U.BTNR == 1)) {
    indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Hold_3;

    /* Inport: '<Root>/time' */
    indicator_logic_DW.entry_time = indicator_logic_U.time;
  } else if ((indicator_logic_U.BTNL == 1) && (indicator_logic_U.BTNR == 0)) {
    indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Hold_5;

    /* Inport: '<Root>/time' */
    indicator_logic_DW.entry_time = indicator_logic_U.time;
  } else {
    /* Outport: '<Root>/led_left' */
    indicator_logic_Y.led_left = 0U;

    /* Outport: '<Root>/led_right' */
    indicator_logic_Y.led_right = 1U;

    /* Outport: '<Root>/pwm' */
    indicator_logic_Y.pwm = 1U;
  }

  /* End of Inport: '<Root>/BTNL' */
}

/* Function for Chart: '<Root>/Chart' */
static void indicator_logic_Hold_1(void)
{
  uint32_t qY;
  uint32_t qY_tmp;
  bool tmp;

  /* Inport: '<Root>/time' */
  qY_tmp = indicator_logic_U.time -
    /*MW:operator MISRA2012:D4.1 CERT-C:INT30-C 'Justifying MISRA C rule violation'*/
    /*MW:OvSatOk*/ indicator_logic_DW.entry_time;
  qY = qY_tmp;

  /* Inport: '<Root>/time' */
  if (qY_tmp > indicator_logic_U.time) {
    qY = 0U;
  }

  /* Inport: '<Root>/BTNL' incorporates:
   *  Inport: '<Root>/BTNR'
   */
  /* Inport: '<Root>/BTNL' incorporates:
   *  Inport: '<Root>/BTNR'
   *  Inport: '<Root>/time'
   */
  tmp = ((indicator_logic_U.BTNL == 0) && (indicator_logic_U.BTNR == 0));
  if (tmp && (qY >= 1000U)) {
    indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Right;

    /* Outport: '<Root>/led_left' */
    indicator_logic_Y.led_left = 0U;

    /* Outport: '<Root>/led_right' */
    indicator_logic_Y.led_right = 1U;

    /* Outport: '<Root>/pwm' */
    indicator_logic_Y.pwm = 1U;
  } else if ((indicator_logic_U.BTNL == 1) && (indicator_logic_U.BTNR == 1)) {
    indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Hold_4;

    /* Inport: '<Root>/time' */
    indicator_logic_DW.entry_time = indicator_logic_U.time;
  } else {
    if (qY_tmp > indicator_logic_U.time) {
      qY_tmp = 0U;
    }

    if (tmp && (qY_tmp < 1000U)) {
      indicator_logic_DW.tp_Idle = 1U;
      indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Idle;

      /* Outport: '<Root>/led_left' */
      indicator_logic_Y.led_left = 0U;

      /* Outport: '<Root>/led_right' */
      indicator_logic_Y.led_right = 0U;

      /* Outport: '<Root>/pwm' */
      indicator_logic_Y.pwm = 0U;
    }
  }
}

/* Function for Chart: '<Root>/Chart' */
static void indicator_logic_Hold_2(void)
{
  uint32_t qY;
  uint32_t qY_tmp;
  bool tmp;

  /* Inport: '<Root>/BTNL' incorporates:
   *  Inport: '<Root>/BTNR'
   */
  if ((indicator_logic_U.BTNL == 1) && (indicator_logic_U.BTNR == 1)) {
    indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Hold_4;

    /* Inport: '<Root>/time' */
    indicator_logic_DW.entry_time = indicator_logic_U.time;
  } else {
    /* Inport: '<Root>/time' */
    qY_tmp = indicator_logic_U.time -
      /*MW:operator MISRA2012:D4.1 CERT-C:INT30-C 'Justifying MISRA C rule violation'*/
      /*MW:OvSatOk*/ indicator_logic_DW.entry_time;
    qY = qY_tmp;

    /* Inport: '<Root>/time' */
    if (qY_tmp > indicator_logic_U.time) {
      qY = 0U;
    }

    /* Inport: '<Root>/time' */
    tmp = ((indicator_logic_U.BTNL == 0) && (indicator_logic_U.BTNR == 0));
    if (tmp && (qY < 1000U)) {
      indicator_logic_DW.tp_Idle = 1U;
      indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Idle;

      /* Outport: '<Root>/led_left' */
      indicator_logic_Y.led_left = 0U;

      /* Outport: '<Root>/led_right' */
      indicator_logic_Y.led_right = 0U;

      /* Outport: '<Root>/pwm' */
      indicator_logic_Y.pwm = 0U;
    } else {
      if (qY_tmp > indicator_logic_U.time) {
        qY_tmp = 0U;
      }

      if (tmp && (qY_tmp >= 1000U)) {
        indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Left;

        /* Outport: '<Root>/led_left' */
        indicator_logic_Y.led_left = 1U;

        /* Outport: '<Root>/led_right' */
        indicator_logic_Y.led_right = 0U;

        /* Outport: '<Root>/pwm' */
        indicator_logic_Y.pwm = 1U;
      }
    }
  }

  /* End of Inport: '<Root>/BTNL' */
}

/* Function for Chart: '<Root>/Chart' */
static void indicator_logic_Idle(void)
{
  /* Inport: '<Root>/BTNL' incorporates:
   *  Inport: '<Root>/BTNR'
   */
  if ((indicator_logic_U.BTNL == 0) && (indicator_logic_U.BTNR == 1)) {
    indicator_logic_DW.tp_Idle = 0U;
    indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Hold_1;

    /* Inport: '<Root>/time' */
    indicator_logic_DW.entry_time = indicator_logic_U.time;
  } else if ((indicator_logic_U.BTNL == 1) && (indicator_logic_U.BTNR == 0)) {
    indicator_logic_DW.tp_Idle = 0U;
    indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Hold_2;

    /* Inport: '<Root>/time' */
    indicator_logic_DW.entry_time = indicator_logic_U.time;
  } else if ((indicator_logic_U.BTNL == 1) && (indicator_logic_U.BTNR == 1)) {
    indicator_logic_DW.tp_Idle = 0U;
    indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Hold_4;

    /* Inport: '<Root>/time' */
    indicator_logic_DW.entry_time = indicator_logic_U.time;
  } else {
    /* Outport: '<Root>/led_left' */
    indicator_logic_Y.led_left = 0U;

    /* Outport: '<Root>/led_right' */
    indicator_logic_Y.led_right = 0U;

    /* Outport: '<Root>/pwm' */
    indicator_logic_Y.pwm = 0U;
  }

  /* End of Inport: '<Root>/BTNL' */
}

/* Function for Chart: '<Root>/Chart' */
static void indicator_logic_Left(void)
{
  /* Inport: '<Root>/BTNL' incorporates:
   *  Inport: '<Root>/BTNR'
   */
  if ((indicator_logic_U.BTNL == 0) && (indicator_logic_U.BTNR == 0)) {
    indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Left;

    /* Outport: '<Root>/led_left' */
    indicator_logic_Y.led_left = 1U;

    /* Outport: '<Root>/led_right' */
    indicator_logic_Y.led_right = 0U;

    /* Outport: '<Root>/pwm' */
    indicator_logic_Y.pwm = 1U;
  } else if ((indicator_logic_U.BTNL == 1) && (indicator_logic_U.BTNR == 0)) {
    indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Hold_7;

    /* Inport: '<Root>/time' */
    indicator_logic_DW.entry_time = indicator_logic_U.time;
  } else if ((indicator_logic_U.BTNL == 0) && (indicator_logic_U.BTNR == 1)) {
    indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Hold_6;

    /* Inport: '<Root>/time' */
    indicator_logic_DW.entry_time = indicator_logic_U.time;
  } else {
    /* Outport: '<Root>/led_left' */
    indicator_logic_Y.led_left = 1U;

    /* Outport: '<Root>/led_right' */
    indicator_logic_Y.led_right = 0U;

    /* Outport: '<Root>/pwm' */
    indicator_logic_Y.pwm = 1U;
  }

  /* End of Inport: '<Root>/BTNL' */
}

/* Model step function */
void indicator_logic_step(void)
{
  uint32_t qY;
  uint32_t qY_tmp;
  bool tmp;

  /* Chart: '<Root>/Chart' incorporates:
   *  Inport: '<Root>/BTNL'
   *  Inport: '<Root>/BTNR'
   *  Inport: '<Root>/time'
   */
  if (indicator_logic_DW.is_active_c3_indicator_logic == 0) {
    indicator_logic_DW.is_active_c3_indicator_logic = 1U;
    indicator_logic_DW.tp_Idle = 1U;
    indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Idle;

    /* Outport: '<Root>/led_left' */
    indicator_logic_Y.led_left = 0U;

    /* Outport: '<Root>/led_right' */
    indicator_logic_Y.led_right = 0U;

    /* Outport: '<Root>/pwm' */
    indicator_logic_Y.pwm = 0U;
  } else {
    switch (indicator_logic_DW.is_c3_indicator_logic) {
     case indicator_logic_IN_Hazard:
      if ((indicator_logic_U.BTNL == 1) || (indicator_logic_U.BTNR == 1)) {
        indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Hold_8;
        indicator_logic_DW.entry_time = indicator_logic_U.time;
      } else {
        /* Outport: '<Root>/led_left' */
        indicator_logic_Y.led_left = 1U;

        /* Outport: '<Root>/led_right' */
        indicator_logic_Y.led_right = 1U;

        /* Outport: '<Root>/pwm' */
        indicator_logic_Y.pwm = 1U;
      }
      break;

     case indicator_logic_IN_Hold_1:
      indicator_logic_Hold_1();
      break;

     case indicator_logic_IN_Hold_2:
      indicator_logic_Hold_2();
      break;

     case indicator_logic_IN_Hold_3:
      qY_tmp = indicator_logic_U.time -
        /*MW:operator MISRA2012:D4.1 CERT-C:INT30-C 'Justifying MISRA C rule violation'*/
        /*MW:OvSatOk*/ indicator_logic_DW.entry_time;
      qY = qY_tmp;
      if (qY_tmp > indicator_logic_U.time) {
        qY = 0U;
      }

      tmp = ((indicator_logic_U.BTNL == 0) && (indicator_logic_U.BTNR == 0));
      if (tmp && (qY >= 1000U)) {
        indicator_logic_DW.tp_Idle = 1U;
        indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Idle;

        /* Outport: '<Root>/led_left' */
        indicator_logic_Y.led_left = 0U;

        /* Outport: '<Root>/led_right' */
        indicator_logic_Y.led_right = 0U;

        /* Outport: '<Root>/pwm' */
        indicator_logic_Y.pwm = 0U;
      } else {
        if (qY_tmp > indicator_logic_U.time) {
          qY_tmp = 0U;
        }

        if (tmp && (qY_tmp < 1000U)) {
          indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Right;

          /* Outport: '<Root>/led_left' */
          indicator_logic_Y.led_left = 0U;

          /* Outport: '<Root>/led_right' */
          indicator_logic_Y.led_right = 1U;

          /* Outport: '<Root>/pwm' */
          indicator_logic_Y.pwm = 1U;
        }
      }
      break;

     case indicator_logic_IN_Hold_4:
      qY_tmp = indicator_logic_U.time -
        /*MW:operator MISRA2012:D4.1 CERT-C:INT30-C 'Justifying MISRA C rule violation'*/
        /*MW:OvSatOk*/ indicator_logic_DW.entry_time;
      qY = qY_tmp;
      if (qY_tmp > indicator_logic_U.time) {
        qY = 0U;
      }

      tmp = ((indicator_logic_U.BTNL == 0) && (indicator_logic_U.BTNR == 0));
      if (tmp && (qY >= 1000U)) {
        indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Hazard;

        /* Outport: '<Root>/led_left' */
        indicator_logic_Y.led_left = 1U;

        /* Outport: '<Root>/led_right' */
        indicator_logic_Y.led_right = 1U;

        /* Outport: '<Root>/pwm' */
        indicator_logic_Y.pwm = 1U;
      } else {
        if (qY_tmp > indicator_logic_U.time) {
          qY_tmp = 0U;
        }

        if (tmp && (qY_tmp < 1000U)) {
          indicator_logic_DW.tp_Idle = 1U;
          indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Idle;

          /* Outport: '<Root>/led_left' */
          indicator_logic_Y.led_left = 0U;

          /* Outport: '<Root>/led_right' */
          indicator_logic_Y.led_right = 0U;

          /* Outport: '<Root>/pwm' */
          indicator_logic_Y.pwm = 0U;
        }
      }
      break;

     case indicator_logic_IN_Hold_5:
      qY_tmp = indicator_logic_U.time -
        /*MW:operator MISRA2012:D4.1 CERT-C:INT30-C 'Justifying MISRA C rule violation'*/
        /*MW:OvSatOk*/ indicator_logic_DW.entry_time;
      qY = qY_tmp;
      if (qY_tmp > indicator_logic_U.time) {
        qY = 0U;
      }

      tmp = ((indicator_logic_U.BTNL == 0) && (indicator_logic_U.BTNR == 0));
      if (tmp && (qY >= 1000U)) {
        indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Left;

        /* Outport: '<Root>/led_left' */
        indicator_logic_Y.led_left = 1U;

        /* Outport: '<Root>/led_right' */
        indicator_logic_Y.led_right = 0U;

        /* Outport: '<Root>/pwm' */
        indicator_logic_Y.pwm = 1U;
      } else {
        if (qY_tmp > indicator_logic_U.time) {
          qY_tmp = 0U;
        }

        if (tmp && (qY_tmp < 1000U)) {
          indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Right;

          /* Outport: '<Root>/led_left' */
          indicator_logic_Y.led_left = 0U;

          /* Outport: '<Root>/led_right' */
          indicator_logic_Y.led_right = 1U;

          /* Outport: '<Root>/pwm' */
          indicator_logic_Y.pwm = 1U;
        }
      }
      break;

     case indicator_logic_IN_Hold_6:
      qY_tmp = indicator_logic_U.time -
        /*MW:operator MISRA2012:D4.1 CERT-C:INT30-C 'Justifying MISRA C rule violation'*/
        /*MW:OvSatOk*/ indicator_logic_DW.entry_time;
      qY = qY_tmp;
      if (qY_tmp > indicator_logic_U.time) {
        qY = 0U;
      }

      tmp = ((indicator_logic_U.BTNL == 0) && (indicator_logic_U.BTNR == 0));
      if (tmp && (qY >= 1000U)) {
        indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Right;

        /* Outport: '<Root>/led_left' */
        indicator_logic_Y.led_left = 0U;

        /* Outport: '<Root>/led_right' */
        indicator_logic_Y.led_right = 1U;

        /* Outport: '<Root>/pwm' */
        indicator_logic_Y.pwm = 1U;
      } else {
        if (qY_tmp > indicator_logic_U.time) {
          qY_tmp = 0U;
        }

        if (tmp && (qY_tmp < 1000U)) {
          indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Left;

          /* Outport: '<Root>/led_left' */
          indicator_logic_Y.led_left = 1U;

          /* Outport: '<Root>/led_right' */
          indicator_logic_Y.led_right = 0U;

          /* Outport: '<Root>/pwm' */
          indicator_logic_Y.pwm = 1U;
        }
      }
      break;

     case indicator_logic_IN_Hold_7:
      qY_tmp = indicator_logic_U.time -
        /*MW:operator MISRA2012:D4.1 CERT-C:INT30-C 'Justifying MISRA C rule violation'*/
        /*MW:OvSatOk*/ indicator_logic_DW.entry_time;
      qY = qY_tmp;
      if (qY_tmp > indicator_logic_U.time) {
        qY = 0U;
      }

      tmp = ((indicator_logic_U.BTNL == 0) && (indicator_logic_U.BTNR == 0));
      if (tmp && (qY >= 1000U)) {
        indicator_logic_DW.tp_Idle = 1U;
        indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Idle;

        /* Outport: '<Root>/led_left' */
        indicator_logic_Y.led_left = 0U;

        /* Outport: '<Root>/led_right' */
        indicator_logic_Y.led_right = 0U;

        /* Outport: '<Root>/pwm' */
        indicator_logic_Y.pwm = 0U;
      } else {
        if (qY_tmp > indicator_logic_U.time) {
          qY_tmp = 0U;
        }

        if (tmp && (qY_tmp < 1000U)) {
          indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Left;

          /* Outport: '<Root>/led_left' */
          indicator_logic_Y.led_left = 1U;

          /* Outport: '<Root>/led_right' */
          indicator_logic_Y.led_right = 0U;

          /* Outport: '<Root>/pwm' */
          indicator_logic_Y.pwm = 1U;
        }
      }
      break;

     case indicator_logic_IN_Hold_8:
      qY_tmp = indicator_logic_U.time -
        /*MW:operator MISRA2012:D4.1 CERT-C:INT30-C 'Justifying MISRA C rule violation'*/
        /*MW:OvSatOk*/ indicator_logic_DW.entry_time;
      qY = qY_tmp;
      if (qY_tmp > indicator_logic_U.time) {
        qY = 0U;
      }

      tmp = ((indicator_logic_U.BTNL == 0) && (indicator_logic_U.BTNR == 0));
      if (tmp && (qY >= 1000U)) {
        indicator_logic_DW.tp_Idle = 1U;
        indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Idle;

        /* Outport: '<Root>/led_left' */
        indicator_logic_Y.led_left = 0U;

        /* Outport: '<Root>/led_right' */
        indicator_logic_Y.led_right = 0U;

        /* Outport: '<Root>/pwm' */
        indicator_logic_Y.pwm = 0U;
      } else {
        if (qY_tmp > indicator_logic_U.time) {
          qY_tmp = 0U;
        }

        if (tmp && (qY_tmp < 1000U)) {
          indicator_logic_DW.is_c3_indicator_logic = indicator_logic_IN_Hazard;

          /* Outport: '<Root>/led_left' */
          indicator_logic_Y.led_left = 1U;

          /* Outport: '<Root>/led_right' */
          indicator_logic_Y.led_right = 1U;

          /* Outport: '<Root>/pwm' */
          indicator_logic_Y.pwm = 1U;
        }
      }
      break;

     case indicator_logic_IN_Idle:
      indicator_logic_Idle();
      break;

     case indicator_logic_IN_Left:
      indicator_logic_Left();
      break;

     default:
      /* case IN_Right: */
      indicator_logic_Right();
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */
}

/* Model initialize function */
void indicator_logic_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void indicator_logic_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
