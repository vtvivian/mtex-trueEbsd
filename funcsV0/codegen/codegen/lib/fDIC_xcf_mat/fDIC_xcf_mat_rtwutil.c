/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * fDIC_xcf_mat_rtwutil.c
 *
 * Code generation for function 'fDIC_xcf_mat_rtwutil'
 *
 */

/* Include files */
#include "fDIC_xcf_mat_rtwutil.h"
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Variable Definitions */
static fDIC_xcf_matTLS *fDIC_xcf_matTLSGlobal;
#pragma omp threadprivate(fDIC_xcf_matTLSGlobal)

/* Function Definitions */
void emlrtFreeThreadStackData(void)
{
  int b;
  int i;
  b = omp_get_max_threads();
#pragma omp parallel for schedule(static) num_threads(omp_get_max_threads())

  for (i = 1; i <= b; i++) {
    free(fDIC_xcf_matTLSGlobal);
  }
}

fDIC_xcf_matTLS *emlrtGetThreadStackData(void)
{
  return fDIC_xcf_matTLSGlobal;
}

void emlrtInitThreadStackData(void)
{
  int b;
  int i;
  b = omp_get_max_threads();
#pragma omp parallel for schedule(static) num_threads(omp_get_max_threads())

  for (i = 1; i <= b; i++) {
    fDIC_xcf_matTLSGlobal =
        (fDIC_xcf_matTLS *)malloc((size_t)1U * sizeof(fDIC_xcf_matTLS));
  }
}

/* End of code generation (fDIC_xcf_mat_rtwutil.c) */
