/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * fDIC_xcf_mat_initialize.c
 *
 * Code generation for function 'fDIC_xcf_mat_initialize'
 *
 */

/* Include files */
#include "fDIC_xcf_mat_initialize.h"
#include "_coder_fDIC_xcf_mat_mex.h"
#include "fDIC_xcf_mat_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void fDIC_xcf_mat_once(void);

/* Function Definitions */
static void fDIC_xcf_mat_once(void)
{
  mex_InitInfAndNan();
}

void fDIC_xcf_mat_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    fDIC_xcf_mat_once();
  }
}

/* End of code generation (fDIC_xcf_mat_initialize.c) */
