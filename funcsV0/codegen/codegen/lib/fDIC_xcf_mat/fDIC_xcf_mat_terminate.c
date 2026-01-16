/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * fDIC_xcf_mat_terminate.c
 *
 * Code generation for function 'fDIC_xcf_mat_terminate'
 *
 */

/* Include files */
#include "fDIC_xcf_mat_terminate.h"
#include "fDIC_xcf_mat_data.h"
#include "fDIC_xcf_mat_rtwutil.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Function Definitions */
void fDIC_xcf_mat_terminate(void)
{
  emlrtFreeThreadStackData();
  omp_destroy_nest_lock(&fDIC_xcf_mat_nestLockGlobal);
  isInitialized_fDIC_xcf_mat = false;
}

/* End of code generation (fDIC_xcf_mat_terminate.c) */
