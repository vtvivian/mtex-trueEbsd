/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * FFTImplementationCallback.h
 *
 * Code generation for function 'FFTImplementationCallback'
 *
 */

#ifndef FFTIMPLEMENTATIONCALLBACK_H
#define FFTIMPLEMENTATIONCALLBACK_H

/* Include files */
#include "fDIC_xcf_mat_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void c_FFTImplementationCallback_dob(const emxArray_creal_T *x, int n2blue,
                                     int nfft, const emxArray_real_T *costab,
                                     const emxArray_real_T *sintab,
                                     const emxArray_real_T *sintabinv,
                                     emxArray_creal_T *y);

void c_FFTImplementationCallback_gen(int nRows, boolean_T useRadix2,
                                     emxArray_real_T *costab,
                                     emxArray_real_T *sintab,
                                     emxArray_real_T *sintabinv);

int c_FFTImplementationCallback_get(int nfft, boolean_T useRadix2, int *nRows);

void c_FFTImplementationCallback_r2b(const double x[16384], creal_T y[16384]);

void d_FFTImplementationCallback_r2b(const creal_T x[16384],
                                     const double costab[65],
                                     const double sintab[65], creal_T y[16384]);

void e_FFTImplementationCallback_r2b(const emxArray_creal_T *x, int n1_unsigned,
                                     const emxArray_real_T *costab,
                                     const emxArray_real_T *sintab,
                                     emxArray_creal_T *y);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (FFTImplementationCallback.h) */
