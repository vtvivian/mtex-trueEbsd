/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * fDIC_xcf_mat_types.h
 *
 * Code generation for function 'fDIC_xcf_mat'
 *
 */

#ifndef FDIC_XCF_MAT_TYPES_H
#define FDIC_XCF_MAT_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0
typedef struct {
  double f1[2];
} cell_wrap_0;
#endif /* typedef_cell_wrap_0 */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  double size_pass_1;
  double position_X_pass_1[408];
  double position_Y_pass_1[408];
  double num_x_pass_1;
  double num_y_pass_1;
  cell_wrap_0 coordinator_pass_1[408];
  double num_pass_1;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T
typedef struct {
  creal_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;
#endif /* typedef_emxArray_creal_T */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int32_T */
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /* typedef_emxArray_int32_T */

#ifndef typedef_b_fDIC_xcf_mat
#define typedef_b_fDIC_xcf_mat
typedef struct {
  creal_T ROI_test_1[16384];
  creal_T dcv[16384];
} b_fDIC_xcf_mat;
#endif /* typedef_b_fDIC_xcf_mat */

#ifndef typedef_fDIC_xcf_matTLS
#define typedef_fDIC_xcf_matTLS
typedef struct {
  b_fDIC_xcf_mat f0;
} fDIC_xcf_matTLS;
#endif /* typedef_fDIC_xcf_matTLS */

#endif
/* End of code generation (fDIC_xcf_mat_types.h) */
