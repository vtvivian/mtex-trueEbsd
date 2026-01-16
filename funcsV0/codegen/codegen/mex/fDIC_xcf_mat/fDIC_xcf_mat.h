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
emlrtCTX emlrtGetRootTLSGlobal(void);

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

void fDIC_xcf_mat(const emlrtStack *sp, const emxArray_real_T *Image_ref,
                  const emxArray_real_T *Image_test, const struct0_T *ROI,
                  const real_T Filters_setting[4], real_T XCF_mesh,
                  const emxArray_real_T *hfilter,
                  const emxArray_real_T *FFTfilter, emxArray_real_T *Shift_X,
                  emxArray_real_T *Shift_Y, emxArray_real_T *CCmax);

/* End of code generation (fDIC_xcf_mat.h) */
