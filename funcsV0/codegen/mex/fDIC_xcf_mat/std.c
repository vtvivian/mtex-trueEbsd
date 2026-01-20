/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * std.c
 *
 * Code generation for function 'std'
 *
 */

/* Include files */
#include "std.h"
#include "blockedSummation.h"
#include "eml_int_forloop_overflow_check.h"
#include "fDIC_xcf_mat_data.h"
#include "fDIC_xcf_mat_emxutil.h"
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo s_emlrtRSI = {
    9,     /* lineNo */
    "std", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\std.m" /* pathName
                                                                        */
};

static emlrtRSInfo t_emlrtRSI = {
    105,      /* lineNo */
    "varstd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\varstd"
    ".m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    96,        /* lineNo */
    "vvarstd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\vvarst"
    "d.m" /* pathName */
};

static emlrtRSInfo v_emlrtRSI = {
    127,       /* lineNo */
    "vvarstd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\vvarst"
    "d.m" /* pathName */
};

static emlrtRSInfo w_emlrtRSI = {
    143,       /* lineNo */
    "vvarstd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\vvarst"
    "d.m" /* pathName */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    126,       /* lineNo */
    34,        /* colNo */
    "vvarstd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\vvarst"
    "d.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    126,       /* lineNo */
    9,         /* colNo */
    "vvarstd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\vvarst"
    "d.m" /* pName */
};

/* Function Definitions */
real_T b_std(const emlrtStack *sp, const emxArray_real_T *x)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_real_T *absdiff;
  real_T dv[2];
  real_T dv1[2];
  const real_T *x_data;
  real_T y;
  real_T *absdiff_data;
  int32_T k;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &s_emlrtRSI;
  n = x->size[0];
  b_st.site = &t_emlrtRSI;
  if (x->size[0] == 0) {
    y = rtNaN;
  } else if (x->size[0] == 1) {
    if ((!muDoubleScalarIsInf(x_data[0])) &&
        (!muDoubleScalarIsNaN(x_data[0]))) {
      y = 0.0;
    } else {
      y = rtNaN;
    }
  } else {
    int32_T scalarLB;
    int32_T vectorUB;
    c_st.site = &u_emlrtRSI;
    d_st.site = &j_emlrtRSI;
    y = blockedSummation(&d_st, x, x->size[0]);
    y /= (real_T)x->size[0];
    emxInit_real_T(&b_st, &absdiff, 1, &hb_emlrtRTEI);
    scalarLB = absdiff->size[0];
    absdiff->size[0] = x->size[0];
    emxEnsureCapacity_real_T(&b_st, absdiff, scalarLB, &gb_emlrtRTEI);
    absdiff_data = absdiff->data;
    c_st.site = &v_emlrtRSI;
    if (x->size[0] > 2147483646) {
      d_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    scalarLB = (x->size[0] / 2) << 1;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      __m128d r;
      _mm_storeu_pd(&dv[0],
                    _mm_sub_pd(_mm_loadu_pd(&x_data[k]), _mm_set1_pd(y)));
      dv1[0] = muDoubleScalarAbs(dv[0]);
      dv1[1] = muDoubleScalarAbs(dv[1]);
      r = _mm_loadu_pd(&dv1[0]);
      _mm_storeu_pd(&absdiff_data[k], r);
    }
    for (k = scalarLB; k < n; k++) {
      absdiff_data[k] = muDoubleScalarAbs(x_data[k] - y);
    }
    n_t = (ptrdiff_t)x->size[0];
    incx_t = (ptrdiff_t)1;
    y = dnrm2(&n_t, &absdiff_data[0], &incx_t);
    emxFree_real_T(&b_st, &absdiff);
    c_st.site = &w_emlrtRSI;
    y /= muDoubleScalarSqrt((real_T)x->size[0] - 1.0);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return y;
}

/* End of code generation (std.c) */
