/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * _coder_fDIC_xcf_mat_api.h
 *
 * Code generation for function 'fDIC_xcf_mat'
 *
 */

#ifndef _CODER_FDIC_XCF_MAT_API_H
#define _CODER_FDIC_XCF_MAT_API_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0
typedef struct {
  real_T f1[2];
} cell_wrap_0;
#endif /* typedef_cell_wrap_0 */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T size_pass_1;
  real_T position_X_pass_1[408];
  real_T position_Y_pass_1[408];
  real_T num_x_pass_1;
  real_T num_y_pass_1;
  cell_wrap_0 coordinator_pass_1[408];
  real_T num_pass_1;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void fDIC_xcf_mat(real_T Image_ref[120672], real_T Image_test[120672],
                  struct0_T *ROI, real_T Filters_setting[4], real_T XCF_mesh,
                  real_T hfilter[16384], real_T FFTfilter[16384],
                  real_T Shift_X[408], real_T Shift_Y[408],
                  emxArray_real_T *CCmax);

void fDIC_xcf_mat_api(const mxArray *const prhs[7], int32_T nlhs,
                      const mxArray *plhs[3]);

void fDIC_xcf_mat_atexit(void);

void fDIC_xcf_mat_initialize(void);

void fDIC_xcf_mat_terminate(void);

void fDIC_xcf_mat_xil_shutdown(void);

void fDIC_xcf_mat_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_fDIC_xcf_mat_api.h) */
