/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * mtimes.c
 *
 * Code generation for function 'mtimes'
 *
 */

/* Include files */
#include "mtimes.h"
#include "eml_int_forloop_overflow_check.h"
#include "fDIC_xcf_mat_data.h"
#include "fDIC_xcf_mat_emxutil.h"
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo cd_emlrtRSI =
    {
        136,      /* lineNo */
        "mtimes", /* fcnName */
        "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pathName */
};

static emlrtRSInfo dd_emlrtRSI = {
    49,       /* lineNo */
    "mtimes", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/+refblas/"
    "mtimes.m" /* pathName */
};

static emlrtRSInfo ed_emlrtRSI = {
    327,            /* lineNo */
    "outerProduct", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/+refblas/"
    "mtimes.m" /* pathName */
};

static emlrtRSInfo fd_emlrtRSI = {
    328,            /* lineNo */
    "outerProduct", /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/+refblas/"
    "mtimes.m" /* pathName */
};

static emlrtRSInfo jd_emlrtRSI =
    {
        142,      /* lineNo */
        "mtimes", /* fcnName */
        "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pathName */
};

static emlrtRSInfo kd_emlrtRSI =
    {
        177,           /* lineNo */
        "mtimes_blas", /* fcnName */
        "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pathName */
};

static emlrtRTEInfo ic_emlrtRTEI = {
    279,      /* lineNo */
    20,       /* colNo */
    "mtimes", /* fName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/+refblas/"
    "mtimes.m" /* pName */
};

static emlrtRTEInfo jc_emlrtRTEI =
    {
        140,      /* lineNo */
        5,        /* colNo */
        "mtimes", /* fName */
        "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pName */
};

static emlrtRTEInfo kc_emlrtRTEI =
    {
        218,      /* lineNo */
        20,       /* colNo */
        "mtimes", /* fName */
        "/usr/local/MATLAB/R2025a/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pName */
};

/* Function Definitions */
void b_mtimes(const emlrtStack *sp, const emxArray_creal_T *A,
              const emxArray_real_T *B, emxArray_creal_T *C)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const creal_T *A_data;
  creal_T *C_data;
  const real_T *B_data;
  int32_T b_i;
  int32_T i;
  int32_T j;
  int32_T m;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  B_data = B->data;
  A_data = A->data;
  st.site = &cd_emlrtRSI;
  m = A->size[0];
  n = B->size[0];
  b_st.site = &dd_emlrtRSI;
  i = C->size[0] * C->size[1];
  C->size[0] = A->size[0];
  C->size[1] = B->size[0];
  emxEnsureCapacity_creal_T(&b_st, C, i, &ic_emlrtRTEI);
  C_data = C->data;
  c_st.site = &ed_emlrtRSI;
  if (B->size[0] > 2147483646) {
    d_st.site = &r_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (j = 0; j < n; j++) {
    c_st.site = &fd_emlrtRSI;
    if (m > 2147483646) {
      d_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (b_i = 0; b_i < m; b_i++) {
      C_data[b_i + C->size[0] * j].re = B_data[j] * A_data[b_i].re;
      C_data[b_i + C->size[0] * j].im = B_data[j] * A_data[b_i].im;
    }
  }
}

void c_mtimes(const emlrtStack *sp, const emxArray_creal_T *A,
              const emxArray_creal_T *B, emxArray_creal_T *C)
{
  static const creal_T alpha1 = {
      1.0, /* re */
      0.0  /* im */
  };
  static const creal_T beta1 = {
      0.0, /* re */
      0.0  /* im */
  };
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  const creal_T *A_data;
  const creal_T *B_data;
  creal_T *C_data;
  int32_T i;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  B_data = B->data;
  A_data = A->data;
  if ((A->size[0] == 0) || (A->size[1] == 0) || (B->size[0] == 0) ||
      (B->size[1] == 0)) {
    int32_T loop_ub;
    loop_ub = C->size[0] * C->size[1];
    C->size[0] = A->size[0];
    C->size[1] = B->size[1];
    emxEnsureCapacity_creal_T(sp, C, loop_ub, &jc_emlrtRTEI);
    C_data = C->data;
    loop_ub = A->size[0] * B->size[1];
    for (i = 0; i < loop_ub; i++) {
      C_data[i] = beta1;
    }
  } else {
    int32_T loop_ub;
    st.site = &jd_emlrtRSI;
    b_st.site = &kd_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    m_t = (ptrdiff_t)A->size[0];
    n_t = (ptrdiff_t)B->size[1];
    k_t = (ptrdiff_t)A->size[1];
    lda_t = (ptrdiff_t)A->size[0];
    ldb_t = (ptrdiff_t)B->size[0];
    ldc_t = (ptrdiff_t)A->size[0];
    loop_ub = C->size[0] * C->size[1];
    C->size[0] = A->size[0];
    C->size[1] = B->size[1];
    emxEnsureCapacity_creal_T(&b_st, C, loop_ub, &kc_emlrtRTEI);
    C_data = C->data;
    zgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, (real_T *)&alpha1,
          (real_T *)&A_data[0], &lda_t, (real_T *)&B_data[0], &ldb_t,
          (real_T *)&beta1, (real_T *)&C_data[0], &ldc_t);
  }
}

void mtimes(const emlrtStack *sp, const emxArray_creal_T *A,
            const emxArray_real_T *B, emxArray_creal_T *C)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const creal_T *A_data;
  creal_T *C_data;
  const real_T *B_data;
  int32_T b_i;
  int32_T i;
  int32_T j;
  int32_T m;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  B_data = B->data;
  A_data = A->data;
  st.site = &cd_emlrtRSI;
  m = A->size[0];
  n = B->size[1];
  b_st.site = &dd_emlrtRSI;
  i = C->size[0] * C->size[1];
  C->size[0] = A->size[0];
  C->size[1] = B->size[1];
  emxEnsureCapacity_creal_T(&b_st, C, i, &ic_emlrtRTEI);
  C_data = C->data;
  c_st.site = &ed_emlrtRSI;
  if (B->size[1] > 2147483646) {
    d_st.site = &r_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (j = 0; j < n; j++) {
    c_st.site = &fd_emlrtRSI;
    if (m > 2147483646) {
      d_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (b_i = 0; b_i < m; b_i++) {
      C_data[b_i + C->size[0] * j].re = B_data[j] * A_data[b_i].re;
      C_data[b_i + C->size[0] * j].im = B_data[j] * A_data[b_i].im;
    }
  }
}

/* End of code generation (mtimes.c) */
