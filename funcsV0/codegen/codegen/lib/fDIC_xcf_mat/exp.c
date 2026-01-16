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
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
void b_exp(emxArray_creal_T *x)
{
  creal_T *x_data;
  double d1;
  double r;
  int k;
  int nx;
  x_data = x->data;
  nx = x->size[0] * x->size[1];
  if (nx < 1600) {
    for (k = 0; k < nx; k++) {
      if (x_data[k].re == 0.0) {
        double d;
        d = x_data[k].im;
        x_data[k].re = cos(d);
        x_data[k].im = sin(d);
      } else if (x_data[k].im == 0.0) {
        x_data[k].re = exp(x_data[k].re);
        x_data[k].im = 0.0;
      } else if (rtIsInf(x_data[k].im) && rtIsInf(x_data[k].re) &&
                 (x_data[k].re < 0.0)) {
        x_data[k].re = 0.0;
        x_data[k].im = 0.0;
      } else {
        double d;
        r = exp(x_data[k].re / 2.0);
        d = x_data[k].im;
        x_data[k].re = r * (r * cos(d));
        x_data[k].im = r * (r * sin(d));
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(r, d1)

    for (k = 0; k < nx; k++) {
      if (x_data[k].re == 0.0) {
        d1 = x_data[k].im;
        x_data[k].re = cos(d1);
        x_data[k].im = sin(d1);
      } else if (x_data[k].im == 0.0) {
        x_data[k].re = exp(x_data[k].re);
        x_data[k].im = 0.0;
      } else if (rtIsInf(x_data[k].im) && rtIsInf(x_data[k].re) &&
                 (x_data[k].re < 0.0)) {
        x_data[k].re = 0.0;
        x_data[k].im = 0.0;
      } else {
        r = exp(x_data[k].re / 2.0);
        d1 = x_data[k].im;
        x_data[k].re = r * (r * cos(d1));
        x_data[k].im = r * (r * sin(d1));
      }
    }
  }
}

/* End of code generation (exp.c) */
