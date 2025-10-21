/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * eml_fftshift.c
 *
 * Code generation for function 'eml_fftshift'
 *
 */

/* Include files */
#include "eml_fftshift.h"
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void eml_fftshift(emxArray_creal_T *x, int dim)
{
  creal_T *x_data;
  int b_k;
  int j;
  int k;
  int xtmp_re_tmp;
  x_data = x->data;
  xtmp_re_tmp = x->size[dim - 1];
  if (xtmp_re_tmp > 1) {
    int lowerDim;
    int midoffset;
    int npages;
    int vlend2;
    int vspread;
    int vstride;
    vlend2 = (int)((unsigned int)xtmp_re_tmp >> 1);
    vstride = 1;
    lowerDim = (unsigned char)(dim - 1);
    for (k = 0; k < lowerDim; k++) {
      vstride *= x->size[0];
    }
    npages = 1;
    lowerDim = dim + 1;
    for (k = lowerDim; k < 3; k++) {
      npages *= x->size[1];
    }
    vspread = (xtmp_re_tmp - 1) * vstride;
    midoffset = vlend2 * vstride - 1;
    if (vlend2 << 1 == xtmp_re_tmp) {
      int i2;
      i2 = 0;
      for (k = 0; k < npages; k++) {
        int i1;
        i1 = i2;
        i2 += vspread;
        for (j = 0; j < vstride; j++) {
          int ib;
          i1++;
          i2++;
          ib = i1 + midoffset;
          for (b_k = 0; b_k < vlend2; b_k++) {
            double xtmp_im;
            double xtmp_re;
            lowerDim = b_k * vstride;
            xtmp_re_tmp = (i1 + lowerDim) - 1;
            xtmp_re = x_data[xtmp_re_tmp].re;
            xtmp_im = x_data[xtmp_re_tmp].im;
            lowerDim += ib;
            x_data[xtmp_re_tmp] = x_data[lowerDim];
            x_data[lowerDim].re = xtmp_re;
            x_data[lowerDim].im = xtmp_im;
          }
        }
      }
    } else {
      int i2;
      i2 = 0;
      for (k = 0; k < npages; k++) {
        int i1;
        i1 = i2;
        i2 += vspread;
        for (j = 0; j < vstride; j++) {
          double xtmp_im;
          double xtmp_re;
          int ib;
          i1++;
          i2++;
          ib = i1 + midoffset;
          xtmp_re = x_data[ib].re;
          xtmp_im = x_data[ib].im;
          for (b_k = 0; b_k < vlend2; b_k++) {
            lowerDim = ib + vstride;
            xtmp_re_tmp = (i1 + b_k * vstride) - 1;
            x_data[ib] = x_data[xtmp_re_tmp];
            x_data[xtmp_re_tmp] = x_data[lowerDim];
            ib = lowerDim;
          }
          x_data[ib].re = xtmp_re;
          x_data[ib].im = xtmp_im;
        }
      }
    }
  }
}

/* End of code generation (eml_fftshift.c) */
