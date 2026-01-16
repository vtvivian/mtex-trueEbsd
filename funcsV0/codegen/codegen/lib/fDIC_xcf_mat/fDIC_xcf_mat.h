/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * fDIC_xcf_mat.h
 *
 * Code generation for function 'fDIC_xcf_mat'
 *
 */

#ifndef FDIC_XCF_MAT_H
#define FDIC_XCF_MAT_H

/* Include files */
#include "fDIC_xcf_mat_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void fDIC_xcf_mat(const double Image_ref[120672],
                         const double Image_test[120672], const struct0_T *ROI,
                         const double Filters_setting[4], double XCF_mesh,
                         const double hfilter[16384],
                         const double FFTfilter[16384], double Shift_X[408],
                         double Shift_Y[408], emxArray_real_T *CCmax);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (fDIC_xcf_mat.h) */
