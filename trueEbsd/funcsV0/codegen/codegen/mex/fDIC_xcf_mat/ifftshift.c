/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * ifftshift.c
 *
 * Code generation for function 'ifftshift'
 *
 */

/* Include files */
#include "ifftshift.h"
#include "eml_fftshift.h"
#include "eml_int_forloop_overflow_check.h"
#include "fDIC_xcf_mat_data.h"
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo ic_emlrtRSI = {
    12,          /* lineNo */
    "ifftshift", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/datafun/ifftshift.m" /* pathName
                                                                           */
};

static emlrtRSInfo jc_emlrtRSI = {
    41,              /* lineNo */
    "eml_ifftshift", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/datafun/private/"
    "eml_ifftshift.m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI = {
    34,              /* lineNo */
    "eml_ifftshift", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/datafun/private/"
    "eml_ifftshift.m" /* pathName */
};

static emlrtRSInfo lc_emlrtRSI = {
    31,              /* lineNo */
    "eml_ifftshift", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/datafun/private/"
    "eml_ifftshift.m" /* pathName */
};

static emlrtRSInfo mc_emlrtRSI = {
    26,              /* lineNo */
    "eml_ifftshift", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/datafun/private/"
    "eml_ifftshift.m" /* pathName */
};

static emlrtRSInfo nc_emlrtRSI = {
    23,              /* lineNo */
    "eml_ifftshift", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/datafun/private/"
    "eml_ifftshift.m" /* pathName */
};

/* Function Definitions */
void b_ifftshift(const emlrtStack *sp, emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T *x_data;
  int32_T b_k;
  int32_T dim;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  x_data = x->data;
  for (dim = 0; dim < 2; dim++) {
    int32_T a;
    st.site = &ic_emlrtRSI;
    a = x->size[dim];
    if (a > 1) {
      int32_T lowerDim;
      int32_T vlend2;
      vlend2 = (int32_T)((uint32_T)a >> 1) - 1;
      lowerDim = (vlend2 + 1) << 1;
      if (lowerDim == a) {
        int32_T b_lowerDim;
        int32_T npages;
        b_st.site = &nc_emlrtRSI;
        c_st.site = &gc_emlrtRSI;
        npages = 1;
        b_lowerDim = dim + 2;
        for (k = b_lowerDim; k < 3; k++) {
          npages *= x->size[1];
        }
        if (lowerDim == a) {
          int32_T i2;
          i2 = 1;
          c_st.site = &fc_emlrtRSI;
          if (npages > 2147483646) {
            d_st.site = &r_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }
          for (k = 0; k < npages; k++) {
            int32_T i1;
            int32_T ib;
            i1 = i2;
            i2 += a;
            c_st.site = &ec_emlrtRSI;
            ib = i1 + vlend2;
            c_st.site = &dc_emlrtRSI;
            for (b_k = 0; b_k <= vlend2; b_k++) {
              real_T tmp;
              lowerDim = (i1 + b_k) - 1;
              tmp = x_data[lowerDim];
              b_lowerDim = ib + b_k;
              x_data[lowerDim] = x_data[b_lowerDim];
              x_data[b_lowerDim] = tmp;
            }
          }
        } else {
          int32_T i2;
          i2 = 1;
          c_st.site = &cc_emlrtRSI;
          if (npages > 2147483646) {
            d_st.site = &r_emlrtRSI;
            check_forloop_overflow_error(&d_st);
          }
          for (k = 0; k < npages; k++) {
            real_T tmp;
            int32_T i1;
            int32_T ib;
            i1 = i2;
            i2 += a;
            c_st.site = &bc_emlrtRSI;
            ib = i1 + vlend2;
            tmp = x_data[ib];
            c_st.site = &ac_emlrtRSI;
            for (b_k = 0; b_k <= vlend2; b_k++) {
              lowerDim = ib + b_k;
              b_lowerDim = (i1 + b_k) - 1;
              x_data[lowerDim] = x_data[b_lowerDim];
              x_data[b_lowerDim] = x_data[lowerDim + 1];
            }
            ib = (ib + vlend2) + 1;
            x_data[ib] = tmp;
          }
        }
      } else {
        int32_T i1;
        int32_T ib;
        b_st.site = &mc_emlrtRSI;
        c_st.site = &hc_emlrtRSI;
        ib = 1;
        lowerDim = dim + 2;
        for (k = lowerDim; k < 3; k++) {
          ib *= x->size[1];
        }
        i1 = -1;
        b_st.site = &lc_emlrtRSI;
        if (ib > 2147483646) {
          c_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (b_k = 0; b_k < ib; b_k++) {
          real_T tmp;
          lowerDim = i1;
          i1 += a;
          b_st.site = &kc_emlrtRSI;
          lowerDim = (lowerDim + vlend2) + 2;
          tmp = x_data[i1];
          b_st.site = &jc_emlrtRSI;
          for (k = 0; k <= vlend2; k++) {
            int32_T b_lowerDim;
            int32_T i2;
            b_lowerDim = i1 - k;
            i2 = (lowerDim - k) - 1;
            x_data[b_lowerDim] = x_data[i2];
            x_data[i2] = x_data[b_lowerDim - 1];
          }
          x_data[(i1 - vlend2) - 1] = tmp;
        }
      }
    }
  }
}

void ifftshift(const emlrtStack *sp, emxArray_creal_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  creal_T *x_data;
  int32_T b_k;
  int32_T dim;
  int32_T j;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  for (dim = 0; dim < 2; dim++) {
    int32_T midoffset;
    st.site = &ic_emlrtRSI;
    midoffset = x->size[dim];
    if (midoffset > 1) {
      int32_T vlend2;
      vlend2 = (int32_T)((uint32_T)midoffset >> 1);
      if (vlend2 << 1 == midoffset) {
        b_st.site = &nc_emlrtRSI;
        eml_fftshift(&b_st, x, dim + 1);
        x_data = x->data;
      } else {
        int32_T i2;
        int32_T lowerDim;
        int32_T npages;
        int32_T vstride;
        b_st.site = &mc_emlrtRSI;
        vstride = 1;
        for (k = 0; k < dim; k++) {
          vstride *= x->size[0];
        }
        npages = 1;
        lowerDim = dim + 2;
        for (k = lowerDim; k < 3; k++) {
          npages *= x->size[1];
        }
        lowerDim = (midoffset - 1) * vstride;
        midoffset = vlend2 * vstride - 1;
        i2 = -1;
        b_st.site = &lc_emlrtRSI;
        if (npages > 2147483646) {
          c_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (k = 0; k < npages; k++) {
          int32_T i1;
          i1 = i2 + 1;
          i2 += lowerDim;
          b_st.site = &kc_emlrtRSI;
          if (vstride > 2147483646) {
            c_st.site = &r_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }
          for (j = 0; j < vstride; j++) {
            real_T xtmp_im;
            real_T xtmp_re;
            int32_T ia;
            int32_T ib;
            i1++;
            ia = i1 + midoffset;
            ib = (i2 + j) + 1;
            xtmp_re = x_data[ib].re;
            xtmp_im = x_data[ib].im;
            b_st.site = &jc_emlrtRSI;
            for (b_k = 0; b_k < vlend2; b_k++) {
              int32_T b_i1;
              int32_T i;
              i = (b_k + 1) * -vstride;
              b_i1 = ia + i;
              x_data[ib + b_k * -vstride] = x_data[b_i1];
              x_data[b_i1] = x_data[ib + i];
            }
            ib += vlend2 * -vstride;
            x_data[ib].re = xtmp_re;
            x_data[ib].im = xtmp_im;
          }
          if (vstride - 1 >= 0) {
            i2 += vstride;
          }
        }
      }
    }
  }
}

/* End of code generation (ifftshift.c) */
