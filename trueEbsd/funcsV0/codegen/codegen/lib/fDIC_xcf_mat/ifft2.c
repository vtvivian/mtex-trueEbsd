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
#include "FFTImplementationCallback.h"
#include "fDIC_xcf_mat_emxutil.h"
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void ifft2(const emxArray_creal_T *x, emxArray_creal_T *y)
{
  emxArray_creal_T *acc;
  emxArray_creal_T *xPerm;
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  creal_T *acc_data;
  creal_T *y_data;
  int lens[2];
  int i;
  int i1;
  int loop_ub;
  boolean_T guard1;
  lens[0] = x->size[0];
  lens[1] = x->size[1];
  emxInit_creal_T(&acc, 2);
  emxInit_creal_T(&xPerm, 2);
  emxInit_real_T(&costab, 2);
  emxInit_real_T(&sintab, 2);
  emxInit_real_T(&sintabinv, 2);
  guard1 = false;
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    guard1 = true;
  } else {
    boolean_T exitg1;
    boolean_T useRadix2;
    useRadix2 = false;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub < 2)) {
      if (lens[loop_ub] == 0) {
        useRadix2 = true;
        exitg1 = true;
      } else {
        loop_ub++;
      }
    }
    if (useRadix2) {
      guard1 = true;
    } else {
      int N2blue;
      int b_loop_ub;
      useRadix2 =
          ((x->size[0] > 0) && ((int)((unsigned int)x->size[0] &
                                      (unsigned int)(x->size[0] - 1)) == 0));
      N2blue = c_FFTImplementationCallback_get(x->size[0], useRadix2, &loop_ub);
      c_FFTImplementationCallback_gen(loop_ub, useRadix2, costab, sintab,
                                      sintabinv);
      if (useRadix2) {
        e_FFTImplementationCallback_r2b(x, x->size[0], costab, sintab, acc);
        acc_data = acc->data;
      } else {
        c_FFTImplementationCallback_dob(x, N2blue, x->size[0], costab, sintab,
                                        sintabinv, acc);
        acc_data = acc->data;
      }
      N2blue = acc->size[1];
      loop_ub = xPerm->size[0] * xPerm->size[1];
      xPerm->size[0] = acc->size[1];
      b_loop_ub = acc->size[0];
      xPerm->size[1] = acc->size[0];
      emxEnsureCapacity_creal_T(xPerm, loop_ub);
      y_data = xPerm->data;
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < N2blue; i1++) {
          y_data[i1 + xPerm->size[0] * i] = acc_data[i + acc->size[0] * i1];
        }
      }
      useRadix2 =
          ((x->size[1] > 0) && ((int)((unsigned int)x->size[1] &
                                      (unsigned int)(x->size[1] - 1)) == 0));
      N2blue = c_FFTImplementationCallback_get(x->size[1], useRadix2, &loop_ub);
      c_FFTImplementationCallback_gen(loop_ub, useRadix2, costab, sintab,
                                      sintabinv);
      if (useRadix2) {
        e_FFTImplementationCallback_r2b(xPerm, x->size[1], costab, sintab, acc);
        acc_data = acc->data;
      } else {
        c_FFTImplementationCallback_dob(xPerm, N2blue, x->size[1], costab,
                                        sintab, sintabinv, acc);
        acc_data = acc->data;
      }
      N2blue = acc->size[1];
      loop_ub = y->size[0] * y->size[1];
      y->size[0] = acc->size[1];
      b_loop_ub = acc->size[0];
      y->size[1] = acc->size[0];
      emxEnsureCapacity_creal_T(y, loop_ub);
      y_data = y->data;
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < N2blue; i1++) {
          y_data[i1 + y->size[0] * i] = acc_data[i + acc->size[0] * i1];
        }
      }
    }
  }
  if (guard1) {
    loop_ub = y->size[0] * y->size[1];
    y->size[0] = x->size[0];
    y->size[1] = x->size[1];
    emxEnsureCapacity_creal_T(y, loop_ub);
    y_data = y->data;
    loop_ub = x->size[0] * x->size[1];
    for (i = 0; i < loop_ub; i++) {
      y_data[i].re = 0.0;
      y_data[i].im = 0.0;
    }
  }
  emxFree_real_T(&sintabinv);
  emxFree_real_T(&sintab);
  emxFree_real_T(&costab);
  emxFree_creal_T(&xPerm);
  emxFree_creal_T(&acc);
}

/* End of code generation (ifft2.c) */
