/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * assertValidSizeArg.c
 *
 * Code generation for function 'assertValidSizeArg'
 *
 */

/* Include files */
#include "assertValidSizeArg.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRTEInfo l_emlrtRTEI = {
    64,                   /* lineNo */
    15,                   /* colNo */
    "assertValidSizeArg", /* fName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/"
    "assertValidSizeArg.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    49,                   /* lineNo */
    19,                   /* colNo */
    "assertValidSizeArg", /* fName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/"
    "assertValidSizeArg.m" /* pName */
};

/* Function Definitions */
void assertValidSizeArg(const emlrtStack *sp, const real_T varargin_1[2])
{
  real_T d;
  int32_T k;
  boolean_T exitg1;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((varargin_1[k] != varargin_1[k]) ||
        muDoubleScalarIsInf(varargin_1[k])) {
      emlrtErrorWithMessageIdR2018a(
          sp, &m_emlrtRTEI,
          "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector",
          "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector", 4, 12,
          MIN_int32_T, 12, MAX_int32_T);
    } else {
      k++;
    }
  }
  if (varargin_1[0] <= 0.0) {
    d = 0.0;
  } else {
    d = varargin_1[0];
  }
  if (varargin_1[1] <= 0.0) {
    d = 0.0;
  } else {
    d *= varargin_1[1];
  }
  if (!(d <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(sp, &l_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
}

/* End of code generation (assertValidSizeArg.c) */
