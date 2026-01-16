/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * blockedSummation.c
 *
 * Code generation for function 'blockedSummation'
 *
 */

/* Include files */
#include "blockedSummation.h"
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"

/* Variable Definitions */
static emlrtRSInfo k_emlrtRSI = {
    107,                /* lineNo */
    "blockedSummation", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    42,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    57,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

/* Function Definitions */
real_T blockedSummation(const emlrtStack *sp, const emxArray_real_T *x,
                        int32_T vlen)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T y;
  int32_T ib;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if ((x->size[0] == 0) || (vlen == 0)) {
    y = 0.0;
  } else {
    st.site = &k_emlrtRSI;
    b_st.site = &l_emlrtRSI;
    if (vlen < 4096) {
      c_st.site = &m_emlrtRSI;
      y = sumColumnB(&c_st, x, vlen);
    } else {
      int32_T inb;
      int32_T nfb;
      int32_T nleft;
      nfb = (int32_T)((uint32_T)vlen >> 12);
      inb = nfb << 12;
      nleft = vlen - inb;
      y = sumColumnB4(x, 1);
      for (ib = 2; ib <= nfb; ib++) {
        y += sumColumnB4(x, ((ib - 1) << 12) + 1);
      }
      if (nleft > 0) {
        c_st.site = &n_emlrtRSI;
        y += b_sumColumnB(&c_st, x, nleft, inb + 1);
      }
    }
  }
  return y;
}

/* End of code generation (blockedSummation.c) */
