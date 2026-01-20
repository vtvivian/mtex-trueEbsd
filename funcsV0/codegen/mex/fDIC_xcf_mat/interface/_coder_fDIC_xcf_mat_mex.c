/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * _coder_fDIC_xcf_mat_mex.c
 *
 * Code generation for function '_coder_fDIC_xcf_mat_mex'
 *
 */

/* Include files */
#include "_coder_fDIC_xcf_mat_mex.h"
#include "_coder_fDIC_xcf_mat_api.h"
#include "fDIC_xcf_mat.h"
#include "fDIC_xcf_mat_data.h"
#include "fDIC_xcf_mat_initialize.h"
#include "fDIC_xcf_mat_terminate.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Function Definitions */
void fDIC_xcf_mat_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                              const mxArray *prhs[7])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[3];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        12, "fDIC_xcf_mat");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "fDIC_xcf_mat");
  }
  /* Call the function. */
  fDIC_xcf_mat_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  static jmp_buf emlrtJBEnviron;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexAtExit(&fDIC_xcf_mat_atexit);
  emlrtLoadLibrary("C:\\ProgramData\\MATLAB\\SupportPackages\\R2025a\\3P."
                   "instrset\\mingw_w64.instrset\\bin\\libgomp-1.dll");
  /* Initialize the memory manager. */
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&fDIC_xcf_mat_nestLockGlobal);
  fDIC_xcf_mat_initialize();
  st.tls = emlrtRootTLSGlobal;
  emlrtSetJmpBuf(&st, &emlrtJBEnviron);
  if (setjmp(emlrtJBEnviron) == 0) {
    fDIC_xcf_mat_mexFunction(nlhs, plhs, nrhs, prhs);
    fDIC_xcf_mat_terminate();
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&fDIC_xcf_mat_nestLockGlobal);
  } else {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&fDIC_xcf_mat_nestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
  }
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                           &emlrtLockerFunction, omp_get_num_procs(), NULL,
                           "GBK", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_fDIC_xcf_mat_mex.c) */
