/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * ifft2.c
 *
 * Code generation for function 'ifft2'
 *
 */

/* Include files */
#include "ifft2.h"
#include "fDIC_xcf_mat_data.h"
#include "fDIC_xcf_mat_emxutil.h"
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo oc_emlrtRSI = {
    73,      /* lineNo */
    "ifft2", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\ifft2.m" /* pathName
                                                                          */
};

static emlrtRTEInfo hc_emlrtRTEI = {
    73,      /* lineNo */
    1,       /* colNo */
    "ifft2", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\ifft2.m" /* pName
                                                                          */
};

/* Function Definitions */
void ifft2(const emlrtStack *sp, const emxArray_creal_T *x, emxArray_creal_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_creal_T *acc;
  const creal_T *x_data;
  creal_T *acc_data;
  creal_T *y_data;
  int32_T lens[2];
  int32_T i;
  int32_T loop_ub;
  boolean_T guard1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  lens[0] = x->size[0];
  lens[1] = x->size[1];
  st.site = &oc_emlrtRSI;
  emxInit_creal_T(&st, &acc, 2, &lb_emlrtRTEI);
  guard1 = false;
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    guard1 = true;
  } else {
    boolean_T b_x;
    boolean_T exitg1;
    b_x = false;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub < 2)) {
      if (lens[loop_ub] == 0) {
        b_x = true;
        exitg1 = true;
      } else {
        loop_ub++;
      }
    }
    if (b_x) {
      guard1 = true;
    } else {
      b_st.site = &y_emlrtRSI;
      c_st.site = &ab_emlrtRSI;
      d_st.site = &bb_emlrtRSI;
      e_st.site = &cb_emlrtRSI;
      if (emlrtIsInParallelRegion(&e_st)) {
        emlrtFFTWSetNumThreads(1);
      } else {
        emlrtFFTWSetNumThreads(6);
      }
      loop_ub = acc->size[0] * acc->size[1];
      acc->size[0] = x->size[0];
      acc->size[1] = x->size[1];
      emxEnsureCapacity_creal_T(&e_st, acc, loop_ub, &kb_emlrtRTEI);
      acc_data = acc->data;
      emlrtFFTW_1D_C2C((real_T *)&x_data[0], (real_T *)&acc_data[0], 1,
                       x->size[0], x->size[0], x->size[1], 1);
      e_st.site = &db_emlrtRSI;
      f_st.site = &eb_emlrtRSI;
      if (emlrtIsInParallelRegion(&f_st)) {
        emlrtFFTWSetNumThreads(1);
      } else {
        emlrtFFTWSetNumThreads(6);
      }
      loop_ub = y->size[0] * y->size[1];
      y->size[0] = acc->size[0];
      y->size[1] = x->size[1];
      emxEnsureCapacity_creal_T(&f_st, y, loop_ub, &kb_emlrtRTEI);
      y_data = y->data;
      emlrtFFTW_1D_C2C((real_T *)&acc_data[0], (real_T *)&y_data[0],
                       acc->size[0], x->size[1], acc->size[1], acc->size[0], 1);
    }
  }
  if (guard1) {
    loop_ub = y->size[0] * y->size[1];
    y->size[0] = x->size[0];
    y->size[1] = x->size[1];
    emxEnsureCapacity_creal_T(&st, y, loop_ub, &hc_emlrtRTEI);
    y_data = y->data;
    loop_ub = x->size[0] * x->size[1];
    for (i = 0; i < loop_ub; i++) {
      y_data[i].re = 0.0;
      y_data[i].im = 0.0;
    }
  }
  emxFree_creal_T(&st, &acc);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (ifft2.c) */
