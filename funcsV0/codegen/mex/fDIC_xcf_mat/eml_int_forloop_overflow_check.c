/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * eml_int_forloop_overflow_check.c
 *
 * Code generation for function 'eml_int_forloop_overflow_check'
 *
 */

/* Include files */
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo n_emlrtRTEI = {
    87,                             /* lineNo */
    33,                             /* colNo */
    "check_forloop_overflow_error", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" /* pName */
};

/* Function Definitions */
void check_forloop_overflow_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2018a(
      sp, &n_emlrtRTEI, "Coder:toolbox:int_forloop_overflow",
      "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
}

/* End of code generation (eml_int_forloop_overflow_check.c) */
