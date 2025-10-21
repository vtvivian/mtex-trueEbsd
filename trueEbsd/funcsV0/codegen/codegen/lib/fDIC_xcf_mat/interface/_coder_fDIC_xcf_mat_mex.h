/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * _coder_fDIC_xcf_mat_mex.h
 *
 * Code generation for function 'fDIC_xcf_mat'
 *
 */

#ifndef _CODER_FDIC_XCF_MAT_MEX_H
#define _CODER_FDIC_XCF_MAT_MEX_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void unsafe_fDIC_xcf_mat_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                     int32_T nrhs, const mxArray *prhs[7]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_fDIC_xcf_mat_mex.h) */
