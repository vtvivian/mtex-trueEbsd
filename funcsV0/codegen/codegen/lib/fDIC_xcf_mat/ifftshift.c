/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * ifftshift.c
 *
 * Code generation for function 'ifftshift'
 *
 */

/* Include files */
#include "ifftshift.h"
#include "eml_fftshift.h"
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void b_ifftshift(emxArray_real_T *x)
{
  double *x_data;
  int b_k;
  int dim;
  int k;
  x_data = x->data;
  for (dim = 0; dim < 2; dim++) {
    int a;
    a = x->size[dim];
    if (a > 1) {
      int lowerDim;
      int vlend2;
      vlend2 = (int)((unsigned int)a >> 1) - 1;
      lowerDim = (vlend2 + 1) << 1;
      if (lowerDim == a) {
        int b_lowerDim;
        int npages;
        npages = 1;
        b_lowerDim = dim + 2;
        for (k = b_lowerDim; k < 3; k++) {
          npages *= x->size[1];
        }
        if (lowerDim == a) {
          int i2;
          i2 = 1;
          for (k = 0; k < npages; k++) {
            int i1;
            int ib;
            i1 = i2;
            i2 += a;
            ib = i1 + vlend2;
            for (b_k = 0; b_k <= vlend2; b_k++) {
              double tmp;
              lowerDim = (i1 + b_k) - 1;
              tmp = x_data[lowerDim];
              b_lowerDim = ib + b_k;
              x_data[lowerDim] = x_data[b_lowerDim];
              x_data[b_lowerDim] = tmp;
            }
          }
        } else {
          int i2;
          i2 = 1;
          for (k = 0; k < npages; k++) {
            double tmp;
            int i1;
            int ib;
            i1 = i2;
            i2 += a;
            ib = i1 + vlend2;
            tmp = x_data[ib];
            for (b_k = 0; b_k <= vlend2; b_k++) {
              lowerDim = ib + b_k;
              b_lowerDim = (i1 + b_k) - 1;
              x_data[lowerDim] = x_data[b_lowerDim];
              x_data[b_lowerDim] = x_data[lowerDim + 1];
            }
            ib = (ib + vlend2) + 1;
            x_data[ib] = tmp;
          }
        }
      } else {
        int i1;
        int ib;
        ib = 1;
        lowerDim = dim + 2;
        for (k = lowerDim; k < 3; k++) {
          ib *= x->size[1];
        }
        i1 = -1;
        for (b_k = 0; b_k < ib; b_k++) {
          double tmp;
          lowerDim = i1;
          i1 += a;
          lowerDim = (lowerDim + vlend2) + 2;
          tmp = x_data[i1];
          for (k = 0; k <= vlend2; k++) {
            int b_lowerDim;
            int i2;
            b_lowerDim = i1 - k;
            i2 = (lowerDim - k) - 1;
            x_data[b_lowerDim] = x_data[i2];
            x_data[i2] = x_data[b_lowerDim - 1];
          }
          x_data[(i1 - vlend2) - 1] = tmp;
        }
      }
    }
  }
}

void ifftshift(emxArray_creal_T *x)
{
  creal_T *x_data;
  int b_k;
  int dim;
  int j;
  int k;
  x_data = x->data;
  for (dim = 0; dim < 2; dim++) {
    int midoffset;
    midoffset = x->size[dim];
    if (midoffset > 1) {
      int vlend2;
      vlend2 = (int)((unsigned int)midoffset >> 1);
      if (vlend2 << 1 == midoffset) {
        eml_fftshift(x, dim + 1);
        x_data = x->data;
      } else {
        int i2;
        int lowerDim;
        int npages;
        int vstride;
        vstride = 1;
        for (k = 0; k < dim; k++) {
          vstride *= x->size[0];
        }
        npages = 1;
        lowerDim = dim + 2;
        for (k = lowerDim; k < 3; k++) {
          npages *= x->size[1];
        }
        lowerDim = (midoffset - 1) * vstride;
        midoffset = vlend2 * vstride - 1;
        i2 = -1;
        for (k = 0; k < npages; k++) {
          int i1;
          i1 = i2 + 1;
          i2 += lowerDim;
          for (j = 0; j < vstride; j++) {
            double xtmp_im;
            double xtmp_re;
            int ia;
            int ib;
            i1++;
            ia = i1 + midoffset;
            ib = (i2 + j) + 1;
            xtmp_re = x_data[ib].re;
            xtmp_im = x_data[ib].im;
            for (b_k = 0; b_k < vlend2; b_k++) {
              int b_i1;
              int i;
              i = (b_k + 1) * -vstride;
              b_i1 = ia + i;
              x_data[ib + b_k * -vstride] = x_data[b_i1];
              x_data[b_i1] = x_data[ib + i];
            }
            ib += vlend2 * -vstride;
            x_data[ib].re = xtmp_re;
            x_data[ib].im = xtmp_im;
          }
          if (vstride - 1 >= 0) {
            i2 += vstride;
          }
        }
      }
    }
  }
}

/* End of code generation (ifftshift.c) */
