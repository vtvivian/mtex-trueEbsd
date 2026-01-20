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
#include "mwmathutil.h"

/* Function Definitions */
boolean_T relop(const creal_T a, const creal_T b)
{
  boolean_T p;
  if (muDoubleScalarIsNaN(b.re) || muDoubleScalarIsNaN(b.im)) {
    p = false;
  } else if (muDoubleScalarIsNaN(a.re) || muDoubleScalarIsNaN(a.im)) {
    p = true;
  } else {
    real_T x;
    real_T y;
    boolean_T SCALEB;
    if ((muDoubleScalarAbs(a.re) > 8.9884656743115785E+307) ||
        (muDoubleScalarAbs(a.im) > 8.9884656743115785E+307)) {
      p = true;
    } else {
      p = false;
    }
    if ((muDoubleScalarAbs(b.re) > 8.9884656743115785E+307) ||
        (muDoubleScalarAbs(b.im) > 8.9884656743115785E+307)) {
      SCALEB = true;
    } else {
      SCALEB = false;
    }
    if (p || SCALEB) {
      x = muDoubleScalarHypot(a.re / 2.0, a.im / 2.0);
      y = muDoubleScalarHypot(b.re / 2.0, b.im / 2.0);
    } else {
      x = muDoubleScalarHypot(a.re, a.im);
      y = muDoubleScalarHypot(b.re, b.im);
    }
    if (x == y) {
      x = muDoubleScalarAtan2(a.im, a.re);
      y = muDoubleScalarAtan2(b.im, b.re);
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
