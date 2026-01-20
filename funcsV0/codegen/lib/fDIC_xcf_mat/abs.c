/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "abs.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
double b_abs(const creal_T x)
{
  double b;
  double y;
  y = fabs(x.re);
  b = fabs(x.im);
  if (y < b) {
    y /= b;
    y = b * sqrt(y * y + 1.0);
  } else if (y > b) {
    b /= y;
    y *= sqrt(b * b + 1.0);
  } else if (rtIsNaN(b)) {
    y = rtNaN;
  } else {
    y *= 1.4142135623730951;
  }
  return y;
}

/* End of code generation (abs.c) */
