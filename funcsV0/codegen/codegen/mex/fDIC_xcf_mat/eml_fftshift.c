/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * eml_fftshift.c
 *
 * Code generation for function 'eml_fftshift'
 *
 */

/* Include files */
#include "eml_fftshift.h"
#include "eml_int_forloop_overflow_check.h"
#include "fDIC_xcf_mat_data.h"
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void eml_fftshift(const emlrtStack *sp, emxArray_creal_T *x, int32_T dim)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  creal_T *x_data;
  int32_T b_k;
  int32_T j;
  int32_T k;
  int32_T xtmp_re_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  xtmp_re_tmp = x->size[dim - 1];
  if (xtmp_re_tmp > 1) {
    int32_T lowerDim;
    int32_T midoffset;
    int32_T npages;
    int32_T vlend2;
    int32_T vspread;
    int32_T vstride;
    vlend2 = (int32_T)((uint32_T)xtmp_re_tmp >> 1);
    st.site = &gc_emlrtRSI;
    vstride = 1;
    b_st.site = &hc_emlrtRSI;
    if (dim - 1 > 2147483646) {
      c_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    lowerDim = (uint8_T)(dim - 1);
    for (k = 0; k < lowerDim; k++) {
      vstride *= x->size[0];
    }
    npages = 1;
    lowerDim = dim + 1;
    for (k = lowerDim; k < 3; k++) {
      npages *= x->size[1];
    }
    vspread = (xtmp_re_tmp - 1) * vstride;
    midoffset = vlend2 * vstride - 1;
    if (vlend2 << 1 == xtmp_re_tmp) {
      int32_T i2;
      i2 = 0;
      st.site = &fc_emlrtRSI;
      if (npages > 2147483646) {
        b_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (k = 0; k < npages; k++) {
        int32_T i1;
        i1 = i2;
        i2 += vspread;
        st.site = &ec_emlrtRSI;
        if (vstride > 2147483646) {
          b_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        for (j = 0; j < vstride; j++) {
          int32_T ib;
          i1++;
          i2++;
          ib = i1 + midoffset;
          st.site = &dc_emlrtRSI;
          for (b_k = 0; b_k < vlend2; b_k++) {
            real_T xtmp_im;
            real_T xtmp_re;
            lowerDim = b_k * vstride;
            xtmp_re_tmp = (i1 + lowerDim) - 1;
            xtmp_re = x_data[xtmp_re_tmp].re;
            xtmp_im = x_data[xtmp_re_tmp].im;
            lowerDim += ib;
            x_data[xtmp_re_tmp] = x_data[lowerDim];
            x_data[lowerDim].re = xtmp_re;
            x_data[lowerDim].im = xtmp_im;
          }
        }
      }
    } else {
      int32_T i2;
      i2 = 0;
      st.site = &cc_emlrtRSI;
      if (npages > 2147483646) {
        b_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (k = 0; k < npages; k++) {
        int32_T i1;
        i1 = i2;
        i2 += vspread;
        st.site = &bc_emlrtRSI;
        if (vstride > 2147483646) {
          b_st.site = &r_emlrtRSI;
          check_forloop_overflow_error(&b_st);
        }
        for (j = 0; j < vstride; j++) {
          real_T xtmp_im;
          real_T xtmp_re;
          int32_T ib;
          i1++;
          i2++;
          ib = i1 + midoffset;
          xtmp_re = x_data[ib].re;
          xtmp_im = x_data[ib].im;
          st.site = &ac_emlrtRSI;
          for (b_k = 0; b_k < vlend2; b_k++) {
            lowerDim = ib + vstride;
            xtmp_re_tmp = (i1 + b_k * vstride) - 1;
            x_data[ib] = x_data[xtmp_re_tmp];
            x_data[xtmp_re_tmp] = x_data[lowerDim];
            ib = lowerDim;
          }
          x_data[ib].re = xtmp_re;
          x_data[ib].im = xtmp_im;
        }
      }
    }
  }
}

/* End of code generation (eml_fftshift.c) */
