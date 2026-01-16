/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * blockedSummation.c
 *
 * Code generation for function 'blockedSummation'
 *
 */

/* Include files */
#include "blockedSummation.h"
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
double blockedSummation(const emxArray_real_T *x, int vlen)
{
  const double *x_data;
  double y;
  int b_k;
  int k;
  x_data = x->data;
  if ((x->size[0] == 0) || (vlen == 0)) {
    y = 0.0;
  } else {
    int firstBlockLength;
    int lastBlockLength;
    int nblocks;
    if (vlen <= 1024) {
      firstBlockLength = vlen;
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = (int)((unsigned int)vlen >> 10);
      lastBlockLength = vlen - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    y = x_data[0];
    for (k = 2; k <= firstBlockLength; k++) {
      y += x_data[k - 1];
    }
    for (k = 2; k <= nblocks; k++) {
      double bsum;
      int hi;
      firstBlockLength = (k - 1) << 10;
      bsum = x_data[firstBlockLength];
      if (k == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (b_k = 2; b_k <= hi; b_k++) {
        bsum += x_data[(firstBlockLength + b_k) - 1];
      }
      y += bsum;
    }
  }
  return y;
}

/* End of code generation (blockedSummation.c) */
