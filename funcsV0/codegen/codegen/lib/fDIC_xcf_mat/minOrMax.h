/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * minOrMax.h
 *
 * Code generation for function 'minOrMax'
 *
 */

#ifndef MINORMAX_H
#define MINORMAX_H

/* Include files */
#include "fDIC_xcf_mat_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
int b_maximum(const emxArray_creal_T *x, creal_T *ex);

void binary_expand_op(const emxArray_creal_T *in1, const emxArray_creal_T *in2,
                      const emxArray_creal_T *in3, const emxArray_creal_T *in4,
                      emxArray_creal_T *in5, emxArray_int32_T *in6);

void maximum(const emxArray_creal_T *x, emxArray_creal_T *ex,
             emxArray_int32_T *idx);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (minOrMax.h) */
