/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * fReg.c
 *
 * Code generation for function 'fReg'
 *
 */

/* Include files */
#include "fReg.h"
#include "abs.h"
#include "eml_fftshift.h"
#include "exp.h"
#include "fDIC_xcf_mat_emxutil.h"
#include "fDIC_xcf_mat_types.h"
#include "ifft2.h"
#include "ifftshift.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Declarations */
static void binary_expand_op_1(emxArray_creal_T *in1,
                               const emxArray_creal_T *in2,
                               const emxArray_creal_T *in3);

/* Function Definitions */
static void binary_expand_op_1(emxArray_creal_T *in1,
                               const emxArray_creal_T *in2,
                               const emxArray_creal_T *in3)
{
  const creal_T *in2_data;
  const creal_T *in3_data;
  creal_T *in1_data;
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int i;
  int i1;
  int in3_re_tmp;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  in3_re_tmp = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_creal_T(in1, in3_re_tmp);
  if (in3->size[1] == 1) {
    b_loop_ub = in2->size[1];
  } else {
    b_loop_ub = in3->size[1];
  }
  in3_re_tmp = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_creal_T(in1, in3_re_tmp);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      double b_re_tmp;
      double in3_im;
      double in3_re;
      double re_tmp;
      in3_re_tmp = i1 * stride_1_0;
      in3_re = in3_data[in3_re_tmp + in3->size[0] * aux_1_1].re;
      in3_im = -in3_data[in3_re_tmp + in3->size[0] * aux_1_1].im;
      in3_re_tmp = i1 * stride_0_0;
      re_tmp = in2_data[in3_re_tmp + in2->size[0] * aux_0_1].re;
      b_re_tmp = in2_data[in3_re_tmp + in2->size[0] * aux_0_1].im;
      in1_data[i1 + in1->size[0] * i].re = re_tmp * in3_re - b_re_tmp * in3_im;
      in1_data[i1 + in1->size[0] * i].im = re_tmp * in3_im + b_re_tmp * in3_re;
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

double fReg(const emxArray_creal_T *buf1ft, const emxArray_creal_T *buf2ft,
            double XCF_roisize, double XCF_mesh,
            const emxArray_real_T *data_fill, double *row_shift, double *CCmax)
{
  __m128d r3;
  emxArray_creal_T *CC;
  emxArray_creal_T *b_buf2ft;
  emxArray_creal_T *b_prefac;
  emxArray_creal_T *ex;
  emxArray_creal_T *r;
  emxArray_creal_T *r2;
  emxArray_int32_T *idx;
  emxArray_real_T *b_c_i;
  emxArray_real_T *c_i;
  emxArray_real_T *loc1;
  emxArray_real_T *r_i;
  emxArray_real_T *y;
  const creal_T *buf1ft_data;
  const creal_T *buf2ft_data;
  creal_T prefac;
  creal_T *CC_data;
  creal_T *ex_data;
  creal_T *prefac_data;
  creal_T *r1;
  const double *data_fill_data;
  double b_buf2ft_im;
  double b_buf2ft_re;
  double buf1ft_im;
  double buf1ft_re;
  double buf2ft_im;
  double buf2ft_re;
  double coff;
  double col_shift;
  double d;
  double d1;
  double d10;
  double d2;
  double d3;
  double d4;
  double d5;
  double d6;
  double d7;
  double d8;
  double d9;
  double dftshift;
  double prefac_im;
  double prefac_re;
  double re_tmp;
  double roff;
  double *c_i_data;
  double *loc1_data;
  double *r_i_data;
  double *y_data;
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int i;
  int i1;
  int i10;
  int i2;
  int i3;
  int i4;
  int i5;
  int i6;
  int i7;
  int i8;
  int i9;
  int loop_ub;
  int unnamed_idx_0;
  int *idx_data;
  boolean_T b;
  boolean_T b_b;
  data_fill_data = data_fill->data;
  buf2ft_data = buf2ft->data;
  buf1ft_data = buf1ft->data;
  /* FREG Register two FFTs to subpixel accuracy */
  /* a reduced form of the code submitted to the matlab file exchange */
  /* http://www.mathworks.co.uk/matlabcentral/fileexchange/18401-efficient-subpixel-image-registration-by-cross-correlation
   */
  /*  */
  /* reported in the literature: */
  /* Manuel Guizar-Sicairos, Samuel T. Thurman, and James R. Fienup */
  /* "Efficient subpixel image registration algorithms," Opt. Lett. 33, 156-158
   * (2008). */
  /*  */
  /* also modded to handle the filtered FFT sizes */
  /* TBB 2012 */
  coff = XCF_roisize * 2.0;
  emxInit_creal_T(&CC, 2);
  i = (int)coff;
  loop_ub = CC->size[0] * CC->size[1];
  CC->size[0] = (int)coff;
  CC->size[1] = (int)coff;
  emxEnsureCapacity_creal_T(CC, loop_ub);
  CC_data = CC->data;
  b_loop_ub = (int)coff * (int)coff;
  for (i1 = 0; i1 < b_loop_ub; i1++) {
    CC_data[i1].re = 0.0;
    CC_data[i1].im = 0.0;
  }
  buf2ft_re = (XCF_roisize + 1.0) - trunc((double)data_fill->size[0] / 2.0);
  buf2ft_im =
      (XCF_roisize + 1.0) + trunc(((double)data_fill->size[0] - 1.0) / 2.0);
  if (buf2ft_re > buf2ft_im) {
    c_loop_ub = 0;
    d_loop_ub = 0;
    e_loop_ub = 0;
  } else {
    c_loop_ub = (int)buf2ft_re - 1;
    d_loop_ub = (int)buf2ft_im;
    e_loop_ub = (int)buf2ft_re - 1;
  }
  b = ((buf1ft->size[0] == buf2ft->size[0]) &&
       (buf1ft->size[1] == buf2ft->size[1]));
  emxInit_creal_T(&r, 2);
  if (b) {
    loop_ub = r->size[0] * r->size[1];
    r->size[0] = buf1ft->size[0];
    r->size[1] = buf1ft->size[1];
    emxEnsureCapacity_creal_T(r, loop_ub);
    r1 = r->data;
    loop_ub = buf1ft->size[0] * buf1ft->size[1];
    if (loop_ub < 1600) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        buf2ft_re = buf2ft_data[i2].re;
        buf2ft_im = -buf2ft_data[i2].im;
        roff = buf1ft_data[i2].re;
        re_tmp = buf1ft_data[i2].im;
        r1[i2].re = roff * buf2ft_re - re_tmp * buf2ft_im;
        r1[i2].im = roff * buf2ft_im + re_tmp * buf2ft_re;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        b_buf2ft_re, b_buf2ft_im, d, d1)

      for (i2 = 0; i2 < loop_ub; i2++) {
        b_buf2ft_re = buf2ft_data[i2].re;
        b_buf2ft_im = -buf2ft_data[i2].im;
        d = buf1ft_data[i2].re;
        d1 = buf1ft_data[i2].im;
        r1[i2].re = d * b_buf2ft_re - d1 * b_buf2ft_im;
        r1[i2].im = d * b_buf2ft_im + d1 * b_buf2ft_re;
      }
    }
  } else {
    binary_expand_op_1(r, buf1ft, buf2ft);
  }
  eml_fftshift(r, 1);
  eml_fftshift(r, 2);
  r1 = r->data;
  unnamed_idx_0 = d_loop_ub - c_loop_ub;
  for (i1 = 0; i1 < unnamed_idx_0; i1++) {
    for (i3 = 0; i3 < unnamed_idx_0; i3++) {
      CC_data[(c_loop_ub + i3) + CC->size[0] * (e_loop_ub + i1)] =
          r1[i3 + unnamed_idx_0 * i1];
    }
  }
  /*  Compute crosscorrelation and locate the peak  */
  loop_ub = r->size[0] * r->size[1];
  r->size[0] = i;
  r->size[1] = i;
  emxEnsureCapacity_creal_T(r, loop_ub);
  r1 = r->data;
  for (i1 = 0; i1 < b_loop_ub; i1++) {
    r1[i1] = CC_data[i1];
  }
  ifftshift(r);
  /*  Calculate cross-correlation */
  emxInit_creal_T(&r2, 2);
  ifft2(r, r2);
  emxInit_creal_T(&ex, 2);
  emxInit_int32_T(&idx, 2);
  maximum(r2, ex, idx);
  idx_data = idx->data;
  emxInit_real_T(&loc1, 2);
  loop_ub = loc1->size[0] * loc1->size[1];
  loc1->size[0] = 1;
  unnamed_idx_0 = idx->size[1];
  loc1->size[1] = idx->size[1];
  emxEnsureCapacity_real_T(loc1, loop_ub);
  loc1_data = loc1->data;
  for (i1 = 0; i1 < unnamed_idx_0; i1++) {
    loc1_data[i1] = idx_data[i1];
  }
  loop_ub = b_maximum(ex, &prefac);
  /*  Obtain shift in original pixel grid from the position of the
   * crosscorrelation peak  */
  /* %% DFT computation %%% */
  /*  Initial shift estimate in upsampled grid */
  buf2ft_re = loc1_data[loop_ub - 1];
  if (buf2ft_re > XCF_roisize) {
    buf2ft_re = (buf2ft_re - coff) - 1.0;
  } else {
    buf2ft_re--;
  }
  buf2ft_re = buf2ft_re / 2.0 * XCF_mesh;
  if (fabs(buf2ft_re) < 4.503599627370496E+15) {
    if (buf2ft_re >= 0.5) {
      buf2ft_re = floor(buf2ft_re + 0.5);
    } else if (buf2ft_re > -0.5) {
      buf2ft_re *= 0.0;
    } else {
      buf2ft_re = ceil(buf2ft_re - 0.5);
    }
  }
  *row_shift = buf2ft_re / XCF_mesh;
  if (loop_ub > XCF_roisize) {
    buf2ft_re = ((double)loop_ub - coff) - 1.0;
  } else {
    buf2ft_re = (double)loop_ub - 1.0;
  }
  buf2ft_re = buf2ft_re / 2.0 * XCF_mesh;
  if (fabs(buf2ft_re) < 4.503599627370496E+15) {
    if (buf2ft_re >= 0.5) {
      buf2ft_re = floor(buf2ft_re + 0.5);
    } else if (buf2ft_re > -0.5) {
      buf2ft_re *= 0.0;
    } else {
      buf2ft_re = ceil(buf2ft_re - 0.5);
    }
  }
  col_shift = buf2ft_re / XCF_mesh;
  buf2ft_re = ceil(XCF_mesh * 1.5);
  dftshift = trunc(buf2ft_re / 2.0);
  /*  Center of output array at dftshift+1 */
  /*  Matrix multiply DFT around the current shift estimate */
  roff = dftshift - *row_shift * XCF_mesh;
  coff = dftshift - col_shift * XCF_mesh;
  /*  Compute kernels and obtain DFT by matrix products */
  prefac.im = -6.2831853071795862 / (XCF_roisize * XCF_mesh);
  /* speed up kernel generation for reduced filtered FFT */
  buf2ft_im = floor(XCF_roisize / 2.0);
  b_b = rtIsNaN(XCF_roisize - 1.0);
  if (b_b) {
    loop_ub = loc1->size[0] * loc1->size[1];
    loc1->size[0] = 1;
    loc1->size[1] = 1;
    emxEnsureCapacity_real_T(loc1, loop_ub);
    loc1_data = loc1->data;
    loc1_data[0] = rtNaN;
  } else if (XCF_roisize - 1.0 < 0.0) {
    loc1->size[0] = 1;
    loc1->size[1] = 0;
  } else {
    loop_ub = loc1->size[0] * loc1->size[1];
    loc1->size[0] = 1;
    loc1->size[1] = (int)(XCF_roisize - 1.0) + 1;
    emxEnsureCapacity_real_T(loc1, loop_ub);
    loc1_data = loc1->data;
    loop_ub = (int)(XCF_roisize - 1.0);
    for (i1 = 0; i1 <= loop_ub; i1++) {
      loc1_data[i1] = i1;
    }
  }
  b_ifftshift(loc1);
  loc1_data = loc1->data;
  emxInit_real_T(&c_i, 1);
  d_loop_ub = loc1->size[1];
  loop_ub = c_i->size[0];
  c_i->size[0] = loc1->size[1];
  emxEnsureCapacity_real_T(c_i, loop_ub);
  c_i_data = c_i->data;
  loop_ub = (loc1->size[1] / 2) << 1;
  unnamed_idx_0 = loop_ub - 2;
  for (i1 = 0; i1 <= unnamed_idx_0; i1 += 2) {
    r3 = _mm_loadu_pd(&loc1_data[i1]);
    _mm_storeu_pd(&c_i_data[i1], _mm_sub_pd(r3, _mm_set1_pd(buf2ft_im)));
  }
  for (i1 = loop_ub; i1 < d_loop_ub; i1++) {
    c_i_data[i1] = loc1_data[i1] - buf2ft_im;
  }
  emxInit_real_T(&b_c_i, 1);
  e_loop_ub = data_fill->size[0];
  loop_ub = b_c_i->size[0];
  b_c_i->size[0] = data_fill->size[0];
  emxEnsureCapacity_real_T(b_c_i, loop_ub);
  r_i_data = b_c_i->data;
  for (i1 = 0; i1 < e_loop_ub; i1++) {
    r_i_data[i1] = c_i_data[(int)data_fill_data[i1] - 1];
  }
  loop_ub = c_i->size[0];
  c_i->size[0] = data_fill->size[0];
  emxEnsureCapacity_real_T(c_i, loop_ub);
  c_i_data = c_i->data;
  for (i1 = 0; i1 < e_loop_ub; i1++) {
    c_i_data[i1] = r_i_data[i1];
  }
  emxFree_real_T(&b_c_i);
  emxInit_real_T(&r_i, 2);
  if (b_b) {
    loop_ub = r_i->size[0] * r_i->size[1];
    r_i->size[0] = 1;
    r_i->size[1] = 1;
    emxEnsureCapacity_real_T(r_i, loop_ub);
    r_i_data = r_i->data;
    r_i_data[0] = rtNaN;
  } else if (XCF_roisize - 1.0 < 0.0) {
    r_i->size[0] = 1;
    r_i->size[1] = 0;
  } else {
    loop_ub = r_i->size[0] * r_i->size[1];
    r_i->size[0] = 1;
    r_i->size[1] = (int)(XCF_roisize - 1.0) + 1;
    emxEnsureCapacity_real_T(r_i, loop_ub);
    r_i_data = r_i->data;
    loop_ub = (int)(XCF_roisize - 1.0);
    for (i1 = 0; i1 <= loop_ub; i1++) {
      r_i_data[i1] = i1;
    }
  }
  b_ifftshift(r_i);
  loop_ub = r_i->size[0] * r_i->size[1];
  r_i->size[0] = 1;
  emxEnsureCapacity_real_T(r_i, loop_ub);
  r_i_data = r_i->data;
  loop_ub = r_i->size[1] - 1;
  unnamed_idx_0 = (r_i->size[1] / 2) << 1;
  d_loop_ub = unnamed_idx_0 - 2;
  for (i1 = 0; i1 <= d_loop_ub; i1 += 2) {
    r3 = _mm_loadu_pd(&r_i_data[i1]);
    _mm_storeu_pd(&r_i_data[i1], _mm_sub_pd(r3, _mm_set1_pd(buf2ft_im)));
  }
  for (i1 = unnamed_idx_0; i1 <= loop_ub; i1++) {
    r_i_data[i1] -= buf2ft_im;
  }
  emxInit_real_T(&y, 2);
  y_data = y->data;
  if (rtIsNaN(buf2ft_re - 1.0)) {
    loop_ub = loc1->size[0] * loc1->size[1];
    loc1->size[0] = 1;
    loc1->size[1] = 1;
    emxEnsureCapacity_real_T(loc1, loop_ub);
    loc1_data = loc1->data;
    loc1_data[0] = rtNaN;
    loop_ub = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = 1;
    emxEnsureCapacity_real_T(y, loop_ub);
    y_data = y->data;
    y_data[0] = rtNaN;
  } else if (buf2ft_re - 1.0 < 0.0) {
    loc1->size[0] = 1;
    loc1->size[1] = 0;
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    loop_ub = loc1->size[0] * loc1->size[1];
    loc1->size[0] = 1;
    loc1->size[1] = (int)(buf2ft_re - 1.0) + 1;
    emxEnsureCapacity_real_T(loc1, loop_ub);
    loc1_data = loc1->data;
    unnamed_idx_0 = (int)(buf2ft_re - 1.0);
    for (i1 = 0; i1 <= unnamed_idx_0; i1++) {
      loc1_data[i1] = i1;
    }
    loop_ub = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)(buf2ft_re - 1.0) + 1;
    emxEnsureCapacity_real_T(y, loop_ub);
    y_data = y->data;
    for (i1 = 0; i1 <= unnamed_idx_0; i1++) {
      y_data[i1] = i1;
    }
  }
  /*  Locate maximum and map back to original pixel grid */
  emxInit_creal_T(&b_prefac, 1);
  unnamed_idx_0 = y->size[1];
  loop_ub = b_prefac->size[0];
  b_prefac->size[0] = y->size[1];
  emxEnsureCapacity_creal_T(b_prefac, loop_ub);
  prefac_data = b_prefac->data;
  loop_ub = y->size[1];
  if (y->size[1] < 1600) {
    for (i4 = 0; i4 < unnamed_idx_0; i4++) {
      buf2ft_re = y_data[i4] - roff;
      prefac_data[i4].re = buf2ft_re * 0.0;
      prefac_data[i4].im = buf2ft_re * prefac.im;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d2)

    for (i4 = 0; i4 < loop_ub; i4++) {
      d2 = y_data[i4] - roff;
      prefac_data[i4].re = d2 * 0.0;
      prefac_data[i4].im = d2 * prefac.im;
    }
  }
  emxFree_real_T(&y);
  loop_ub = ex->size[0] * ex->size[1];
  ex->size[0] = 1;
  ex->size[1] = e_loop_ub;
  emxEnsureCapacity_creal_T(ex, loop_ub);
  ex_data = ex->data;
  for (i1 = 0; i1 < e_loop_ub; i1++) {
    ex_data[i1].re = r_i_data[(int)data_fill_data[i1] - 1];
    ex_data[i1].im = 0.0;
  }
  emxFree_real_T(&r_i);
  loop_ub = r->size[0] * r->size[1];
  r->size[0] = unnamed_idx_0;
  r->size[1] = e_loop_ub;
  emxEnsureCapacity_creal_T(r, loop_ub);
  r1 = r->data;
  d_loop_ub = (b_prefac->size[0] * ex->size[1] < 1600);
  if (d_loop_ub) {
    for (i5 = 0; i5 < e_loop_ub; i5++) {
      for (i6 = 0; i6 < unnamed_idx_0; i6++) {
        buf2ft_re = prefac_data[i6].re;
        buf2ft_im = ex_data[i5].im;
        roff = prefac_data[i6].im;
        re_tmp = ex_data[i5].re;
        r1[i6 + r->size[0] * i5].re = buf2ft_re * re_tmp - roff * buf2ft_im;
        r1[i6 + r->size[0] * i5].im = buf2ft_re * buf2ft_im + roff * re_tmp;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        i6, d3, d4, d5, d6)

    for (i5 = 0; i5 < e_loop_ub; i5++) {
      for (i6 = 0; i6 < unnamed_idx_0; i6++) {
        d3 = prefac_data[i6].re;
        d4 = ex_data[i5].im;
        d5 = prefac_data[i6].im;
        d6 = ex_data[i5].re;
        r1[i6 + r->size[0] * i5].re = d3 * d6 - d5 * d4;
        r1[i6 + r->size[0] * i5].im = d3 * d4 + d5 * d6;
      }
    }
  }
  emxFree_creal_T(&b_prefac);
  b_exp(r);
  r1 = r->data;
  loop_ub = ex->size[0] * ex->size[1];
  ex->size[0] = 1;
  ex->size[1] = unnamed_idx_0;
  emxEnsureCapacity_creal_T(ex, loop_ub);
  ex_data = ex->data;
  for (i1 = 0; i1 < unnamed_idx_0; i1++) {
    ex_data[i1].re = loc1_data[i1] - coff;
    ex_data[i1].im = 0.0;
  }
  loop_ub = CC->size[0] * CC->size[1];
  CC->size[0] = e_loop_ub;
  CC->size[1] = unnamed_idx_0;
  emxEnsureCapacity_creal_T(CC, loop_ub);
  CC_data = CC->data;
  if (d_loop_ub) {
    for (i7 = 0; i7 < unnamed_idx_0; i7++) {
      for (i8 = 0; i8 < e_loop_ub; i8++) {
        buf2ft_re = c_i_data[i8] * 0.0;
        buf2ft_im = c_i_data[i8] * prefac.im;
        roff = ex_data[i7].im;
        re_tmp = ex_data[i7].re;
        CC_data[i8 + CC->size[0] * i7].re =
            buf2ft_re * re_tmp - buf2ft_im * roff;
        CC_data[i8 + CC->size[0] * i7].im =
            buf2ft_re * roff + buf2ft_im * re_tmp;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        i8, prefac_re, prefac_im, d7, d8)

    for (i7 = 0; i7 < unnamed_idx_0; i7++) {
      for (i8 = 0; i8 < e_loop_ub; i8++) {
        prefac_re = c_i_data[i8] * 0.0;
        prefac_im = c_i_data[i8] * prefac.im;
        d7 = ex_data[i7].im;
        d8 = ex_data[i7].re;
        CC_data[i8 + CC->size[0] * i7].re = prefac_re * d8 - prefac_im * d7;
        CC_data[i8 + CC->size[0] * i7].im = prefac_re * d7 + prefac_im * d8;
      }
    }
  }
  emxFree_real_T(&c_i);
  b_exp(CC);
  CC_data = CC->data;
  if (b) {
    emxInit_creal_T(&b_buf2ft, 2);
    loop_ub = b_buf2ft->size[0] * b_buf2ft->size[1];
    b_buf2ft->size[0] = buf2ft->size[0];
    c_loop_ub = buf2ft->size[1];
    b_buf2ft->size[1] = buf2ft->size[1];
    emxEnsureCapacity_creal_T(b_buf2ft, loop_ub);
    prefac_data = b_buf2ft->data;
    loop_ub = buf2ft->size[0] * buf2ft->size[1];
    if (loop_ub < 1600) {
      for (i9 = 0; i9 < loop_ub; i9++) {
        buf2ft_re = buf1ft_data[i9].re;
        buf2ft_im = -buf1ft_data[i9].im;
        roff = buf2ft_data[i9].re;
        re_tmp = buf2ft_data[i9].im;
        prefac_data[i9].re = roff * buf2ft_re - re_tmp * buf2ft_im;
        prefac_data[i9].im = roff * buf2ft_im + re_tmp * buf2ft_re;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
        buf1ft_re, buf1ft_im, d9, d10)

      for (i9 = 0; i9 < loop_ub; i9++) {
        buf1ft_re = buf1ft_data[i9].re;
        buf1ft_im = -buf1ft_data[i9].im;
        d9 = buf2ft_data[i9].re;
        d10 = buf2ft_data[i9].im;
        prefac_data[i9].re = d9 * buf1ft_re - d10 * buf1ft_im;
        prefac_data[i9].im = d9 * buf1ft_im + d10 * buf1ft_re;
      }
    }
    unnamed_idx_0 = r->size[0];
    d_loop_ub = r->size[1];
    loop_ub = r2->size[0] * r2->size[1];
    r2->size[0] = r->size[0];
    r2->size[1] = c_loop_ub;
    emxEnsureCapacity_creal_T(r2, loop_ub);
    ex_data = r2->data;
    for (i10 = 0; i10 < c_loop_ub; i10++) {
      for (i1 = 0; i1 < unnamed_idx_0; i1++) {
        ex_data[i1 + r2->size[0] * i10].re = 0.0;
        ex_data[i1 + r2->size[0] * i10].im = 0.0;
      }
      for (i1 = 0; i1 < d_loop_ub; i1++) {
        for (i3 = 0; i3 < unnamed_idx_0; i3++) {
          buf2ft_re = r1[i3 + r->size[0] * i1].re;
          buf2ft_im = prefac_data[i1 + b_buf2ft->size[0] * i10].im;
          roff = r1[i3 + r->size[0] * i1].im;
          re_tmp = prefac_data[i1 + b_buf2ft->size[0] * i10].re;
          ex_data[i3 + r2->size[0] * i10].re +=
              buf2ft_re * re_tmp - roff * buf2ft_im;
          ex_data[i3 + r2->size[0] * i10].im +=
              buf2ft_re * buf2ft_im + roff * re_tmp;
        }
      }
    }
    emxFree_creal_T(&b_buf2ft);
    loop_ub = r->size[0] * r->size[1];
    r->size[0] = unnamed_idx_0;
    d_loop_ub = CC->size[1];
    r->size[1] = CC->size[1];
    emxEnsureCapacity_creal_T(r, loop_ub);
    r1 = r->data;
    for (i1 = 0; i1 < unnamed_idx_0; i1++) {
      for (i3 = 0; i3 < d_loop_ub; i3++) {
        buf2ft_re = 0.0;
        buf2ft_im = 0.0;
        for (i10 = 0; i10 < c_loop_ub; i10++) {
          double b_re_tmp;
          re_tmp = ex_data[i1 + r2->size[0] * i10].re;
          roff = CC_data[i10 + CC->size[0] * i3].im;
          coff = ex_data[i1 + r2->size[0] * i10].im;
          b_re_tmp = CC_data[i10 + CC->size[0] * i3].re;
          buf2ft_re += re_tmp * b_re_tmp - coff * roff;
          buf2ft_im += re_tmp * roff + coff * b_re_tmp;
        }
        r1[i1 + r->size[0] * i3].re = buf2ft_re;
        r1[i1 + r->size[0] * i3].im = -buf2ft_im;
      }
    }
    maximum(r, ex, idx);
    idx_data = idx->data;
  } else {
    binary_expand_op(r, buf2ft, buf1ft, CC, ex, idx);
    idx_data = idx->data;
  }
  emxFree_creal_T(&r2);
  emxFree_creal_T(&r);
  emxFree_creal_T(&CC);
  loop_ub = loc1->size[0] * loc1->size[1];
  loc1->size[0] = 1;
  unnamed_idx_0 = idx->size[1];
  loc1->size[1] = idx->size[1];
  emxEnsureCapacity_real_T(loc1, loop_ub);
  loc1_data = loc1->data;
  for (i1 = 0; i1 < unnamed_idx_0; i1++) {
    loc1_data[i1] = idx_data[i1];
  }
  emxFree_int32_T(&idx);
  loop_ub = b_maximum(ex, &prefac);
  emxFree_creal_T(&ex);
  *CCmax = b_abs(prefac);
  /*      CCmax = CC(rloc,cloc); */
  *row_shift += ((loc1_data[loop_ub - 1] - dftshift) - 1.0) / XCF_mesh;
  emxFree_real_T(&loc1);
  col_shift += (((double)loop_ub - dftshift) - 1.0) / XCF_mesh;
  return col_shift;
}

/* End of code generation (fReg.c) */
