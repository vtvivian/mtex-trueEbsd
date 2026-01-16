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

#pragma once

/* Include files */
#include "fDIC_xcf_mat_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real_T fReg(const emlrtStack *sp, const emxArray_creal_T *buf1ft,
            const emxArray_creal_T *buf2ft, real_T XCF_roisize, real_T XCF_mesh,
            const emxArray_real_T *data_fill, real_T *row_shift, real_T *CCmax);

/* End of code generation (fReg.h) */
