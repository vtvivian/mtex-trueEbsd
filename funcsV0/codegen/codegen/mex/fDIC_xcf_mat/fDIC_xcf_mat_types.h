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

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0
typedef struct {
  real_T f1[2];
} cell_wrap_0;
#endif /* typedef_cell_wrap_0 */

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

#ifndef typedef_emxArray_cell_wrap_0
#define typedef_emxArray_cell_wrap_0
typedef struct {
  cell_wrap_0 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_0;
#endif /* typedef_emxArray_cell_wrap_0 */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T size_pass_1;
  emxArray_real_T *position_X_pass_1;
  emxArray_real_T *position_Y_pass_1;
  real_T num_x_pass_1;
  real_T num_y_pass_1;
  emxArray_cell_wrap_0 *coordinator_pass_1;
  real_T num_pass_1;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T
typedef struct {
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;
#endif /* typedef_emxArray_creal_T */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int32_T */
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /* typedef_emxArray_int32_T */

/* End of code generation (fDIC_xcf_mat_types.h) */
