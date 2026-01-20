/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * exp.c
 *
 * Code generation for function 'exp'
 *
 */

/* Include files */
#include "exp.h"
#include "eml_int_forloop_overflow_check.h"
#include "fDIC_xcf_mat_data.h"
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "omp.h"

/* Variable Definitions */
static emlrtRSInfo gd_emlrtRSI =
    {
        10,    /* lineNo */
        "exp", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elfun\\exp.m" /* pathName
                                                                          */
};

static emlrtRSInfo hd_emlrtRSI = {
    44,                           /* lineNo */
    "applyScalarFunctionInPlace", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyScalarFunctionInPlace.m" /* pathName */
};

/* Function Definitions */
void b_exp(const emlrtStack *sp, emxArray_creal_T *x)
{
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  creal_T *x_data;
  real_T d1;
  real_T r;
  int32_T b_exp_numThreads;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  st.site = &gd_emlrtRSI;
  nx = x->size[0] * x->size[1];
  b_st.site = &hd_emlrtRSI;
  if (nx > 2147483646) {
    c_st.site = &r_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  if (nx < 1600) {
    for (k = 0; k < nx; k++) {
      if (x_data[k].re == 0.0) {
        real_T d;
        d = x_data[k].im;
        x_data[k].re = muDoubleScalarCos(d);
        x_data[k].im = muDoubleScalarSin(d);
      } else if (x_data[k].im == 0.0) {
        x_data[k].re = muDoubleScalarExp(x_data[k].re);
        x_data[k].im = 0.0;
      } else if (muDoubleScalarIsInf(x_data[k].im) &&
                 muDoubleScalarIsInf(x_data[k].re) && (x_data[k].re < 0.0)) {
        x_data[k].re = 0.0;
        x_data[k].im = 0.0;
      } else {
        real_T d;
        r = muDoubleScalarExp(x_data[k].re / 2.0);
        d = x_data[k].im;
        x_data[k].re = r * (r * muDoubleScalarCos(d));
        x_data[k].im = r * (r * muDoubleScalarSin(d));
      }
    }
  } else {
    emlrtEnterParallelRegion(&st, omp_in_parallel());
    emlrtPushJmpBuf(&st, &emlrtJBStack);
    b_exp_numThreads = emlrtAllocRegionTLSs(
        st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(b_exp_numThreads) private(r, d1)

    for (k = 0; k < nx; k++) {
      if (x_data[k].re == 0.0) {
        d1 = x_data[k].im;
        x_data[k].re = muDoubleScalarCos(d1);
        x_data[k].im = muDoubleScalarSin(d1);
      } else if (x_data[k].im == 0.0) {
        x_data[k].re = muDoubleScalarExp(x_data[k].re);
        x_data[k].im = 0.0;
      } else if (muDoubleScalarIsInf(x_data[k].im) &&
                 muDoubleScalarIsInf(x_data[k].re) && (x_data[k].re < 0.0)) {
        x_data[k].re = 0.0;
        x_data[k].im = 0.0;
      } else {
        r = muDoubleScalarExp(x_data[k].re / 2.0);
        d1 = x_data[k].im;
        x_data[k].re = r * (r * muDoubleScalarCos(d1));
        x_data[k].im = r * (r * muDoubleScalarSin(d1));
      }
    }
    emlrtPopJmpBuf(&st, &emlrtJBStack);
    emlrtExitParallelRegion(&st, omp_in_parallel());
  }
}

/* End of code generation (exp.c) */
