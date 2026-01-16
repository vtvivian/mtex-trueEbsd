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
#include "fDIC_xcf_mat_data.h"
#include "fDIC_xcf_mat_rtwutil.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Function Definitions */
void fDIC_xcf_mat_initialize(void)
{
  omp_init_nest_lock(&fDIC_xcf_mat_nestLockGlobal);
  emlrtInitThreadStackData();
  isInitialized_fDIC_xcf_mat = true;
}

/* End of code generation (fDIC_xcf_mat_initialize.c) */
