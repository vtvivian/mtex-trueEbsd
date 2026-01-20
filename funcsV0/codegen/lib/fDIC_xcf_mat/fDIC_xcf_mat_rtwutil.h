/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * fDIC_xcf_mat_rtwutil.h
 *
 * Code generation for function 'fDIC_xcf_mat_rtwutil'
 *
 */

#ifndef FDIC_XCF_MAT_RTWUTIL_H
#define FDIC_XCF_MAT_RTWUTIL_H

/* Include files */
#include "fDIC_xcf_mat_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emlrtFreeThreadStackData(void);

extern fDIC_xcf_matTLS *emlrtGetThreadStackData(void);

extern void emlrtInitThreadStackData(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (fDIC_xcf_mat_rtwutil.h) */
