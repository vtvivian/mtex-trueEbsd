/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * _coder_fDIC_xcf_mat_api.c
 *
 * Code generation for function '_coder_fDIC_xcf_mat_api'
 *
 */

/* Include files */
#include "_coder_fDIC_xcf_mat_api.h"
#include "fDIC_xcf_mat.h"
#include "fDIC_xcf_mat_data.h"
#include "fDIC_xcf_mat_emxutil.h"
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo lc_emlrtRTEI = {
    1,                         /* lineNo */
    1,                         /* colNo */
    "_coder_fDIC_xcf_mat_api", /* fName */
    ""                         /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static const mxArray *b_emlrt_marshallOut(emxArray_real_T *u);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct0_T *y);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               struct0_T *y);

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                             const char_T *identifier, emxArray_real_T *y);

static const mxArray *emlrt_marshallOut(emxArray_real_T *u);

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_0 *y);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2]);

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[4];

static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4];

static real_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier);

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2]);

static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4];

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(emxArray_real_T *u)
{
  static const int32_T i = 0;
  const mxArray *m;
  const mxArray *y;
  real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 1);
  u->canFreeData = false;
  emlrtAssign(&y, m);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                               const char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[7] = {
      "size_pass_1",  "position_X_pass_1",  "position_Y_pass_1", "num_x_pass_1",
      "num_y_pass_1", "coordinator_pass_1", "num_pass_1"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)sp, parentId, u, 7,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "size_pass_1";
  y->size_pass_1 =
      e_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        0, "size_pass_1")),
                         &thisId);
  thisId.fIdentifier = "position_X_pass_1";
  f_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 1,
                                                    "position_X_pass_1")),
                     &thisId, y->position_X_pass_1);
  thisId.fIdentifier = "position_Y_pass_1";
  f_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 2,
                                                    "position_Y_pass_1")),
                     &thisId, y->position_Y_pass_1);
  thisId.fIdentifier = "num_x_pass_1";
  y->num_x_pass_1 =
      e_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        3, "num_x_pass_1")),
                         &thisId);
  thisId.fIdentifier = "num_y_pass_1";
  y->num_y_pass_1 =
      e_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0,
                                                        4, "num_y_pass_1")),
                         &thisId);
  thisId.fIdentifier = "coordinator_pass_1";
  g_emlrt_marshallIn(sp,
                     emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 5,
                                                    "coordinator_pass_1")),
                     &thisId, y->coordinator_pass_1);
  thisId.fIdentifier = "num_pass_1";
  y->num_pass_1 = e_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)sp, u, 0, 6, "num_pass_1")),
      &thisId);
  emlrtDestroyArray(&u);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                             const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId, y);
  emlrtDestroyArray(&nullptr);
}

static const mxArray *emlrt_marshallOut(emxArray_real_T *u)
{
  static const int32_T iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 2);
  u->canFreeData = false;
  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_cell_wrap_0 *y)
{
  cell_wrap_0 *y_data;
  emlrtMsgIdentifier thisId;
  int32_T iv[2];
  int32_T sizes[2];
  int32_T i;
  int32_T n;
  char_T str[11];
  boolean_T bv[2];
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  bv[0] = true;
  iv[0] = -1;
  bv[1] = true;
  iv[1] = -1;
  emlrtCheckVsCell((emlrtCTX)sp, parentId, u, 2U, &iv[0], &bv[0], &sizes[0]);
  n = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_cell_wrap_0(sp, y, n, (emlrtRTEInfo *)NULL);
  y_data = y->data;
  n = sizes[0] * sizes[1];
  for (i = 0; i < n; i++) {
    emlrtMexSnprintf(&str[0], (size_t)11U, "%d", i + 1);
    thisId.fIdentifier = &str[0];
    h_emlrt_marshallIn(sp,
                       emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, i)),
                       &thisId, y_data[i].f1);
  }
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2])
{
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[4]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[4];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static real_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[4]
{
  real_T(*y)[4];
  y = p_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = e_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {-1, -1};
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {-1, -1};
  real_T *ret_data;
  int32_T iv[2];
  int32_T i;
  boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtConstCTX)sp, src, &ret_data[0], 8, false);
  emlrtDestroyArray(&src);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2] = {1, 2};
  real_T(*r)[2];
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                          (const void *)&dims[0]);
  r = (real_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[4]
{
  static const int32_T dims = 4;
  real_T(*ret)[4];
  int32_T i;
  boolean_T b = false;
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret = (real_T(*)[4])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void fDIC_xcf_mat_api(const mxArray *const prhs[7], int32_T nlhs,
                      const mxArray *plhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *CCmax;
  emxArray_real_T *FFTfilter;
  emxArray_real_T *Image_ref;
  emxArray_real_T *Image_test;
  emxArray_real_T *Shift_X;
  emxArray_real_T *Shift_Y;
  emxArray_real_T *hfilter;
  struct0_T ROI;
  real_T(*Filters_setting)[4];
  real_T XCF_mesh;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  emxInit_real_T(&st, &Image_ref, 2, &lc_emlrtRTEI);
  Image_ref->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Image_ref", Image_ref);
  emxInit_real_T(&st, &Image_test, 2, &lc_emlrtRTEI);
  Image_test->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "Image_test", Image_test);
  emxInitStruct_struct0_T(&st, &ROI, &lc_emlrtRTEI);
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "ROI", &ROI);
  Filters_setting =
      i_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "Filters_setting");
  XCF_mesh = k_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "XCF_mesh");
  emxInit_real_T(&st, &hfilter, 2, &lc_emlrtRTEI);
  hfilter->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[5]), "hfilter", hfilter);
  emxInit_real_T(&st, &FFTfilter, 2, &lc_emlrtRTEI);
  FFTfilter->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "FFTfilter", FFTfilter);
  /* Invoke the target function */
  emxInit_real_T(&st, &Shift_X, 2, &lc_emlrtRTEI);
  emxInit_real_T(&st, &Shift_Y, 2, &lc_emlrtRTEI);
  emxInit_real_T(&st, &CCmax, 1, &lc_emlrtRTEI);
  fDIC_xcf_mat(&st, Image_ref, Image_test, &ROI, *Filters_setting, XCF_mesh,
               hfilter, FFTfilter, Shift_X, Shift_Y, CCmax);
  emxFree_real_T(&st, &FFTfilter);
  emxFree_real_T(&st, &hfilter);
  emxFreeStruct_struct0_T(&st, &ROI);
  emxFree_real_T(&st, &Image_test);
  emxFree_real_T(&st, &Image_ref);
  /* Marshall function outputs */
  Shift_X->canFreeData = false;
  plhs[0] = emlrt_marshallOut(Shift_X);
  emxFree_real_T(&st, &Shift_X);
  if (nlhs > 1) {
    Shift_Y->canFreeData = false;
    plhs[1] = emlrt_marshallOut(Shift_Y);
  }
  emxFree_real_T(&st, &Shift_Y);
  if (nlhs > 2) {
    CCmax->canFreeData = false;
    plhs[2] = b_emlrt_marshallOut(CCmax);
  }
  emxFree_real_T(&st, &CCmax);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_fDIC_xcf_mat_api.c) */
