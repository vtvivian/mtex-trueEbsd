/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * fReg.h
 *
 * Code generation for function 'fReg'
 *
 */

#ifndef FREG_H
#define FREG_H

/* Include files */
#include "fDIC_xcf_mat_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double fReg(const emxArray_creal_T *buf1ft, const emxArray_creal_T *buf2ft,
            double XCF_roisize, double XCF_mesh,
            const emxArray_real_T *data_fill, double *row_shift, double *CCmax);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (fReg.h) */
