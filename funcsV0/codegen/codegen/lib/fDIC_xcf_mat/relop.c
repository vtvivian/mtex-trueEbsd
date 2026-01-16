/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * relop.c
 *
 * Code generation for function 'relop'
 *
 */

/* Include files */
#include "relop.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
boolean_T relop(const creal_T a, const creal_T b)
{
  boolean_T p;
  if (rtIsNaN(b.re) || rtIsNaN(b.im)) {
    p = false;
  } else if (rtIsNaN(a.re) || rtIsNaN(a.im)) {
    p = true;
  } else {
    double b_y;
    double x;
    double y;
    boolean_T SCALEB;
    y = fabs(a.re);
    if ((y > 8.9884656743115785E+307) ||
        (fabs(a.im) > 8.9884656743115785E+307)) {
      p = true;
    } else {
      p = false;
    }
    b_y = fabs(b.re);
    if ((b_y > 8.9884656743115785E+307) ||
        (fabs(b.im) > 8.9884656743115785E+307)) {
      SCALEB = true;
    } else {
      SCALEB = false;
    }
    if (p || SCALEB) {
      double b_b;
      y = fabs(a.re / 2.0);
      b_b = fabs(a.im / 2.0);
      if (y < b_b) {
        y /= b_b;
        x = b_b * sqrt(y * y + 1.0);
      } else if (y > b_b) {
        b_b /= y;
        x = y * sqrt(b_b * b_b + 1.0);
      } else {
        x = y * 1.4142135623730951;
      }
      b_b = fabs(b.re / 2.0);
      y = fabs(b.im / 2.0);
      if (b_b < y) {
        b_b /= y;
        y *= sqrt(b_b * b_b + 1.0);
      } else if (b_b > y) {
        y /= b_b;
        y = b_b * sqrt(y * y + 1.0);
      } else {
        y = b_b * 1.4142135623730951;
      }
    } else {
      double b_b;
      x = fabs(a.im);
      if (y < x) {
        b_b = y / x;
        x *= sqrt(b_b * b_b + 1.0);
      } else if (y > x) {
        x /= y;
        x = y * sqrt(x * x + 1.0);
      } else {
        x = y * 1.4142135623730951;
      }
      y = fabs(b.im);
      if (b_y < y) {
        b_b = b_y / y;
        y *= sqrt(b_b * b_b + 1.0);
      } else if (b_y > y) {
        y /= b_y;
        y = b_y * sqrt(y * y + 1.0);
      } else {
        y = b_y * 1.4142135623730951;
      }
    }
    if (x == y) {
      int i;
      int i1;
      if (rtIsInf(a.im) && rtIsInf(a.re)) {
        if (a.im > 0.0) {
          i = 1;
        } else {
          i = -1;
        }
        if (a.re > 0.0) {
          i1 = 1;
        } else {
          i1 = -1;
        }
        x = atan2(i, i1);
      } else if (a.re == 0.0) {
        if (a.im > 0.0) {
          x = RT_PI / 2.0;
        } else if (a.im < 0.0) {
          x = -(RT_PI / 2.0);
        } else {
          x = 0.0;
        }
      } else {
        x = atan2(a.im, a.re);
      }
      if (rtIsInf(b.im) && rtIsInf(b.re)) {
        if (b.im > 0.0) {
          i = 1;
        } else {
          i = -1;
        }
        if (b.re > 0.0) {
          i1 = 1;
        } else {
          i1 = -1;
        }
        y = atan2(i, i1);
      } else if (b.re == 0.0) {
        if (b.im > 0.0) {
          y = RT_PI / 2.0;
        } else if (b.im < 0.0) {
          y = -(RT_PI / 2.0);
        } else {
          y = 0.0;
        }
      } else {
        y = atan2(b.im, b.re);
      }
      if (x == y) {
        if (a.re != b.re) {
          if (x >= 0.0) {
            x = b.re;
            y = a.re;
          } else {
            x = a.re;
            y = b.re;
          }
        } else if (a.re < 0.0) {
          x = b.im;
          y = a.im;
        } else {
          x = a.im;
          y = b.im;
        }
        if (x == y) {
          x = 0.0;
          y = 0.0;
        }
      }
    }
    p = (x < y);
  }
  return p;
}

/* End of code generation (relop.c) */
