/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * sumMatrixIncludeNaN.c
 *
 * Code generation for function 'sumMatrixIncludeNaN'
 *
 */

/* Include files */
#include "sumMatrixIncludeNaN.h"
#include "eml_int_forloop_overflow_check.h"
#include "fDIC_xcf_mat_data.h"
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo o_emlrtRSI = {
    178,          /* lineNo */
    "sumColumnB", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    189,          /* lineNo */
    "sumColumnB", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    210,         /* lineNo */
    "sumColumn", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

/* Function Definitions */
real_T b_sumColumnB(const emlrtStack *sp, const emxArray_real_T *x,
                    int32_T vlen, int32_T vstart)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const real_T *x_data;
  real_T y;
  int32_T b_k;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  if (vlen <= 1024) {
    st.site = &o_emlrtRSI;
    y = x_data[vstart - 1];
    b_st.site = &q_emlrtRSI;
    if (vlen - 1 > 2147483646) {
      c_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 0; k <= vlen - 2; k++) {
      y += x_data[vstart + k];
    }
  } else {
    real_T b_y;
    int32_T b_vstart;
    int32_T inb;
    int32_T nfb;
    nfb = (int32_T)((uint32_T)vlen >> 10);
    inb = nfb << 10;
    y = x_data[vstart - 1];
    for (k = 0; k < 1023; k++) {
      y += x_data[vstart + k];
    }
    for (k = 2; k <= nfb; k++) {
      b_vstart = vstart + ((k - 1) << 10);
      b_y = x_data[b_vstart - 1];
      for (b_k = 0; b_k < 1023; b_k++) {
        b_y += x_data[b_vstart + b_k];
      }
      y += b_y;
    }
    if (vlen > inb) {
      nfb = vstart + inb;
      st.site = &p_emlrtRSI;
      b_y = x_data[nfb - 1];
      b_vstart = vlen - inb;
      b_st.site = &q_emlrtRSI;
      for (k = 0; k <= b_vstart - 2; k++) {
        b_y += x_data[nfb + k];
      }
      y += b_y;
    }
  }
  return y;
}

real_T sumColumnB(const emlrtStack *sp, const emxArray_real_T *x, int32_T vlen)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const real_T *x_data;
  real_T y;
  int32_T b_k;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  if (vlen <= 1024) {
    int32_T vstart;
    st.site = &o_emlrtRSI;
    y = x_data[0];
    b_st.site = &q_emlrtRSI;
    if (vlen - 1 > 2147483646) {
      c_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    vstart = (uint16_T)(vlen - 1);
    for (k = 0; k < vstart; k++) {
      y += x_data[k + 1];
    }
  } else {
    real_T b_y;
    int32_T inb;
    int32_T nfb;
    int32_T vstart;
    nfb = (int32_T)((uint32_T)vlen >> 10);
    inb = nfb << 10;
    y = x_data[0];
    for (k = 0; k < 1023; k++) {
      y += x_data[k + 1];
    }
    for (k = 2; k <= nfb; k++) {
      vstart = (k - 1) << 10;
      b_y = x_data[vstart];
      for (b_k = 0; b_k < 1023; b_k++) {
        b_y += x_data[(vstart + b_k) + 1];
      }
      y += b_y;
    }
    if (vlen > inb) {
      st.site = &p_emlrtRSI;
      b_y = x_data[inb];
      vstart = vlen - inb;
      b_st.site = &q_emlrtRSI;
      for (k = 0; k <= vstart - 2; k++) {
        b_y += x_data[(inb + k) + 1];
      }
      y += b_y;
    }
  }
  return y;
}

real_T sumColumnB4(const emxArray_real_T *x, int32_T vstart)
{
  const real_T *x_data;
  real_T psum2;
  real_T psum3;
  real_T psum4;
  real_T y;
  int32_T k;
  x_data = x->data;
  y = x_data[vstart - 1];
  psum2 = x_data[vstart + 1023];
  psum3 = x_data[vstart + 2047];
  psum4 = x_data[vstart + 3071];
  for (k = 0; k < 1023; k++) {
    int32_T psum1_tmp;
    psum1_tmp = vstart + k;
    y += x_data[psum1_tmp];
    psum2 += x_data[psum1_tmp + 1024];
    psum3 += x_data[psum1_tmp + 2048];
    psum4 += x_data[psum1_tmp + 3072];
  }
  return (y + psum2) + (psum3 + psum4);
}

/* End of code generation (sumMatrixIncludeNaN.c) */
