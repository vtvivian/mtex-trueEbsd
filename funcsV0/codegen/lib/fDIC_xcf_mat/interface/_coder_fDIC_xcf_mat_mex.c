/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * _coder_fDIC_xcf_mat_mex.c
 *
 * Code generation for function 'fDIC_xcf_mat'
 *
 */

/* Include files */
#include "_coder_fDIC_xcf_mat_mex.h"
#include "_coder_fDIC_xcf_mat_api.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&fDIC_xcf_mat_atexit);
  fDIC_xcf_mat_initialize();
  unsafe_fDIC_xcf_mat_mexFunction(nlhs, plhs, nrhs, prhs);
  fDIC_xcf_mat_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

void unsafe_fDIC_xcf_mat_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                     int32_T nrhs, const mxArray *prhs[7])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *b_prhs[7];
  const mxArray *outputs[3];
  int32_T i;
  int32_T i1;
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
  for (i = 0; i < 7; i++) {
    b_prhs[i] = prhs[i];
  }
  fDIC_xcf_mat_api(b_prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    i1 = 1;
  } else {
    i1 = nlhs;
  }
  emlrtReturnArrays(i1, &plhs[0], &outputs[0]);
}

/* End of code generation (_coder_fDIC_xcf_mat_mex.c) */
