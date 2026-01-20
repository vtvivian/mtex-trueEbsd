/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * minOrMax.c
 *
 * Code generation for function 'minOrMax'
 *
 */

/* Include files */
#include "minOrMax.h"
#include "fDIC_xcf_mat_emxutil.h"
#include "fDIC_xcf_mat_types.h"
#include "relop.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Function Definitions */
int b_maximum(const emxArray_creal_T *x, creal_T *ex)
{
  const creal_T *x_data;
  int idx;
  int istop;
  int k;
  x_data = x->data;
  istop = x->size[1];
  idx = 1;
  *ex = x_data[0];
  for (k = 2; k <= istop; k++) {
    creal_T b_x;
    b_x = x_data[k - 1];
    if (relop(*ex, b_x)) {
      *ex = b_x;
      idx = k;
    }
  }
  return idx;
}

void binary_expand_op(const emxArray_creal_T *in1, const emxArray_creal_T *in2,
                      const emxArray_creal_T *in3, const emxArray_creal_T *in4,
                      emxArray_creal_T *in5, emxArray_int32_T *in6)
{
  emxArray_creal_T *b_in1;
  emxArray_creal_T *b_in2;
  const creal_T *in1_data;
  const creal_T *in2_data;
  const creal_T *in3_data;
  const creal_T *in4_data;
  creal_T *b_in1_data;
  creal_T *b_in2_data;
  double b_in1_re_tmp;
  double in1_re_tmp;
  double in3_im;
  double in3_re;
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int c_loop_ub;
  int i;
  int i1;
  int i2;
  int in3_re_tmp;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  in4_data = in4->data;
  in3_data = in3->data;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_creal_T(&b_in2, 2);
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  in3_re_tmp = b_in2->size[0] * b_in2->size[1];
  b_in2->size[0] = loop_ub;
  if (in3->size[1] == 1) {
    b_loop_ub = in2->size[1];
  } else {
    b_loop_ub = in3->size[1];
  }
  b_in2->size[1] = b_loop_ub;
  emxEnsureCapacity_creal_T(b_in2, in3_re_tmp);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in3_re_tmp = i1 * stride_1_0;
      in3_re = in3_data[in3_re_tmp + in3->size[0] * aux_1_1].re;
      in3_im = -in3_data[in3_re_tmp + in3->size[0] * aux_1_1].im;
      c_loop_ub = i1 * stride_0_0;
      in1_re_tmp = in2_data[c_loop_ub + in2->size[0] * aux_0_1].re;
      b_in1_re_tmp = in2_data[c_loop_ub + in2->size[0] * aux_0_1].im;
      b_in2_data[i1 + b_in2->size[0] * i].re =
          in1_re_tmp * in3_re - b_in1_re_tmp * in3_im;
      b_in2_data[i1 + b_in2->size[0] * i].im =
          in1_re_tmp * in3_im + b_in1_re_tmp * in3_re;
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  stride_0_0 = in1->size[0];
  c_loop_ub = in1->size[1];
  emxInit_creal_T(&b_in1, 2);
  in3_re_tmp = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = stride_0_0;
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_creal_T(b_in1, in3_re_tmp);
  b_in1_data = b_in1->data;
  for (i2 = 0; i2 < b_loop_ub; i2++) {
    for (i = 0; i < stride_0_0; i++) {
      b_in1_data[i + b_in1->size[0] * i2].re = 0.0;
      b_in1_data[i + b_in1->size[0] * i2].im = 0.0;
    }
    for (i = 0; i < c_loop_ub; i++) {
      for (i1 = 0; i1 < stride_0_0; i1++) {
        in3_re = in1_data[i1 + in1->size[0] * i].re;
        in3_im = b_in2_data[i + b_in2->size[0] * i2].im;
        in1_re_tmp = in1_data[i1 + in1->size[0] * i].im;
        b_in1_re_tmp = b_in2_data[i + b_in2->size[0] * i2].re;
        b_in1_data[i1 + b_in1->size[0] * i2].re +=
            in3_re * b_in1_re_tmp - in1_re_tmp * in3_im;
        b_in1_data[i1 + b_in1->size[0] * i2].im +=
            in3_re * in3_im + in1_re_tmp * b_in1_re_tmp;
      }
    }
  }
  in3_re_tmp = b_in2->size[0] * b_in2->size[1];
  b_in2->size[0] = stride_0_0;
  c_loop_ub = in4->size[1];
  b_in2->size[1] = c_loop_ub;
  emxEnsureCapacity_creal_T(b_in2, in3_re_tmp);
  b_in2_data = b_in2->data;
  for (i = 0; i < stride_0_0; i++) {
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      in3_re = 0.0;
      in3_im = 0.0;
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        double c_in1_re_tmp;
        double d_in1_re_tmp;
        in1_re_tmp = b_in1_data[i + b_in1->size[0] * i2].re;
        b_in1_re_tmp = in4_data[i2 + in4->size[0] * i1].im;
        c_in1_re_tmp = b_in1_data[i + b_in1->size[0] * i2].im;
        d_in1_re_tmp = in4_data[i2 + in4->size[0] * i1].re;
        in3_re += in1_re_tmp * d_in1_re_tmp - c_in1_re_tmp * b_in1_re_tmp;
        in3_im += in1_re_tmp * b_in1_re_tmp + c_in1_re_tmp * d_in1_re_tmp;
      }
      b_in2_data[i + b_in2->size[0] * i1].re = in3_re;
      b_in2_data[i + b_in2->size[0] * i1].im = -in3_im;
    }
  }
  emxFree_creal_T(&b_in1);
  maximum(b_in2, in5, in6);
  emxFree_creal_T(&b_in2);
}

void maximum(const emxArray_creal_T *x, emxArray_creal_T *ex,
             emxArray_int32_T *idx)
{
  const creal_T *x_data;
  creal_T c_x;
  creal_T *ex_data;
  int b_i;
  int i;
  int i1;
  int j;
  int m;
  int n;
  int *idx_data;
  x_data = x->data;
  m = x->size[0];
  n = x->size[1];
  i = ex->size[0] * ex->size[1];
  ex->size[0] = 1;
  ex->size[1] = x->size[1];
  emxEnsureCapacity_creal_T(ex, i);
  ex_data = ex->data;
  i = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = x->size[1];
  emxEnsureCapacity_int32_T(idx, i);
  idx_data = idx->data;
  for (i1 = 0; i1 < n; i1++) {
    idx_data[i1] = 1;
  }
  if (x->size[1] >= 1) {
    if (x->size[1] * (x->size[0] - 1) < 1600) {
      for (j = 0; j < n; j++) {
        ex_data[j] = x_data[x->size[0] * j];
        for (b_i = 2; b_i <= m; b_i++) {
          creal_T b_x;
          b_x = x_data[(b_i + x->size[0] * j) - 1];
          if (relop(ex_data[j], b_x)) {
            ex_data[j] = b_x;
            idx_data[j] = b_i;
          }
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i, c_x)

      for (j = 0; j < n; j++) {
        ex_data[j] = x_data[x->size[0] * j];
        for (b_i = 2; b_i <= m; b_i++) {
          c_x = x_data[(b_i + x->size[0] * j) - 1];
          if (relop(ex_data[j], c_x)) {
            ex_data[j] = c_x;
            idx_data[j] = b_i;
          }
        }
      }
    }
  }
}

/* End of code generation (minOrMax.c) */
