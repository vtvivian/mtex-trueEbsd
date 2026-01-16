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
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
double b_std(const emxArray_real_T *x)
{
  const double *x_data;
  double y;
  int k;
  int n;
  x_data = x->data;
  n = x->size[0];
  if (x->size[0] == 0) {
    y = rtNaN;
  } else if (x->size[0] == 1) {
    if ((!rtIsInf(x_data[0])) && (!rtIsNaN(x_data[0]))) {
      y = 0.0;
    } else {
      y = rtNaN;
    }
  } else {
    double scale;
    double xbar;
    xbar = blockedSummation(x, x->size[0]) / (double)x->size[0];
    y = 0.0;
    scale = 3.3121686421112381E-170;
    for (k = 0; k < n; k++) {
      double d;
      d = fabs(x_data[k] - xbar);
      if (d > scale) {
        double t;
        t = scale / d;
        y = y * t * t + 1.0;
        scale = d;
      } else {
        double t;
        t = d / scale;
        y += t * t;
      }
    }
    y = scale * sqrt(y);
    y /= sqrt((double)x->size[0] - 1.0);
  }
  return y;
}

/* End of code generation (std.c) */
