/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * mtimes.h
 *
 * Code generation for function 'mtimes'
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
void b_mtimes(const emlrtStack *sp, const emxArray_creal_T *A,
              const emxArray_real_T *B, emxArray_creal_T *C);

void c_mtimes(const emlrtStack *sp, const emxArray_creal_T *A,
              const emxArray_creal_T *B, emxArray_creal_T *C);

void mtimes(const emlrtStack *sp, const emxArray_creal_T *A,
            const emxArray_real_T *B, emxArray_creal_T *C);

/* End of code generation (mtimes.h) */
