/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * fDIC_xcf_mat.c
 *
 * Code generation for function 'fDIC_xcf_mat'
 *
 */

/* Include files */
#include "fDIC_xcf_mat.h"
#include "assertValidSizeArg.h"
#include "blockedSummation.h"
#include "fDIC_xcf_mat_data.h"
#include "fDIC_xcf_mat_emxutil.h"
#include "fDIC_xcf_mat_types.h"
#include "fReg.h"
#include "fft2.h"
#include "rt_nonfinite.h"
#include "std.h"
#include "mwmathutil.h"
#include "omp.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    13,             /* lineNo */
    "fDIC_xcf_mat", /* fcnName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    15,             /* lineNo */
    "fDIC_xcf_mat", /* fcnName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    16,             /* lineNo */
    "fDIC_xcf_mat", /* fcnName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    22,             /* lineNo */
    "fDIC_xcf_mat", /* fcnName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    24,             /* lineNo */
    "fDIC_xcf_mat", /* fcnName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    27,             /* lineNo */
    "fDIC_xcf_mat", /* fcnName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    29,             /* lineNo */
    "fDIC_xcf_mat", /* fcnName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    30,             /* lineNo */
    "fDIC_xcf_mat", /* fcnName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    112,    /* lineNo */
    "mean", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" /* pathName
                                                                         */
};

static emlrtRSInfo ib_emlrtRSI =
    {
        28,      /* lineNo */
        "colon", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pathName
                                                                          */
};

static emlrtRSInfo jb_emlrtRSI =
    {
        139,     /* lineNo */
        "colon", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pathName
                                                                          */
};

static emlrtRSInfo kb_emlrtRSI =
    {
        333,               /* lineNo */
        "eml_float_colon", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pathName
                                                                          */
};

static emlrtRSInfo ld_emlrtRSI = {
    41,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pathName */
};

static emlrtDCInfo emlrtDCI = {
    10,             /* lineNo */
    12,             /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    1            /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    10,             /* lineNo */
    10,             /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtDCInfo b_emlrtDCI = {
    11,             /* lineNo */
    32,             /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    11,             /* lineNo */
    32,             /* colNo */
    "Image_ref",    /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    11,             /* lineNo */
    90,             /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    11,             /* lineNo */
    90,             /* colNo */
    "Image_ref",    /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    11,             /* lineNo */
    150,            /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    11,             /* lineNo */
    150,            /* colNo */
    "Image_ref",    /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    11,             /* lineNo */
    208,            /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    11,             /* lineNo */
    208,            /* colNo */
    "Image_ref",    /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtECInfo emlrtECI = {
    1,              /* nDims */
    14,             /* lineNo */
    21,             /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    2,              /* nDims */
    14,             /* lineNo */
    21,             /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtDCInfo f_emlrtDCI = {
    20,             /* lineNo */
    34,             /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    20,             /* lineNo */
    34,             /* colNo */
    "Image_test",   /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    20,             /* lineNo */
    92,             /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    20,             /* lineNo */
    92,             /* colNo */
    "Image_test",   /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    20,             /* lineNo */
    152,            /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    20,             /* lineNo */
    152,            /* colNo */
    "Image_test",   /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    20,             /* lineNo */
    210,            /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    20,             /* lineNo */
    210,            /* colNo */
    "Image_test",   /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtECInfo c_emlrtECI = {
    1,              /* nDims */
    23,             /* lineNo */
    22,             /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtECInfo d_emlrtECI = {
    2,              /* nDims */
    23,             /* lineNo */
    22,             /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    11,                       /* lineNo */
    55,                       /* colNo */
    "ROI.coordinator_pass_1", /* aName */
    "fDIC_xcf_mat",           /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    11,                       /* lineNo */
    113,                      /* colNo */
    "ROI.coordinator_pass_1", /* aName */
    "fDIC_xcf_mat",           /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    11,                       /* lineNo */
    173,                      /* colNo */
    "ROI.coordinator_pass_1", /* aName */
    "fDIC_xcf_mat",           /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    11,                       /* lineNo */
    231,                      /* colNo */
    "ROI.coordinator_pass_1", /* aName */
    "fDIC_xcf_mat",           /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    20,                       /* lineNo */
    57,                       /* colNo */
    "ROI.coordinator_pass_1", /* aName */
    "fDIC_xcf_mat",           /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                       /* iFirst */
    -1,                       /* iLast */
    20,                       /* lineNo */
    175,                      /* colNo */
    "ROI.coordinator_pass_1", /* aName */
    "fDIC_xcf_mat",           /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    81,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    88,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI =
    {
        433,               /* lineNo */
        15,                /* colNo */
        "assert_pmaxsize", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pName
                                                                          */
};

static emlrtDCInfo j_emlrtDCI = {
    6,              /* lineNo */
    1,              /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    1            /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    6,              /* lineNo */
    1,              /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    4            /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    18,             /* lineNo */
    29,             /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    1            /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    18,             /* lineNo */
    29,             /* colNo */
    "FFTfilter",    /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    18,             /* lineNo */
    39,             /* colNo */
    "FFTfilter",    /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    18,             /* lineNo */
    61,             /* colNo */
    "ROI_ref_1",    /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    18,             /* lineNo */
    71,             /* colNo */
    "ROI_ref_1",    /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    25,             /* lineNo */
    30,             /* colNo */
    "FFTfilter",    /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    25,             /* lineNo */
    40,             /* colNo */
    "FFTfilter",    /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    25,             /* lineNo */
    63,             /* colNo */
    "ROI_test_1",   /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    25,             /* lineNo */
    73,             /* colNo */
    "ROI_test_1",   /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    27,             /* lineNo */
    23,             /* colNo */
    "Shift_X_temp", /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    27,             /* lineNo */
    39,             /* colNo */
    "Shift_Y_temp", /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    27,             /* lineNo */
    48,             /* colNo */
    "CCmax",        /* aName */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m", /* pName */
    0            /* checkKind */
};

static emlrtRTEInfo o_emlrtRTEI = {
    6,              /* lineNo */
    1,              /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    7,              /* lineNo */
    1,              /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    8,              /* lineNo */
    1,              /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    29,             /* lineNo */
    1,              /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    30,             /* lineNo */
    1,              /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = {
    11,             /* lineNo */
    9,              /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    13,             /* lineNo */
    9,              /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    16,             /* lineNo */
    9,              /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = {
    17,             /* lineNo */
    9,              /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI =
    {
        334,     /* lineNo */
        20,      /* colNo */
        "colon", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pName
                                                                          */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    18,             /* lineNo */
    9,              /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    20,             /* lineNo */
    9,              /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    22,             /* lineNo */
    9,              /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    25,             /* lineNo */
    9,              /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    16,             /* lineNo */
    21,             /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    16,             /* lineNo */
    63,             /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = {
    23,             /* lineNo */
    22,             /* colNo */
    "fDIC_xcf_mat", /* fName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pName */
};

static emlrtRSInfo md_emlrtRSI = {
    14,             /* lineNo */
    "fDIC_xcf_mat", /* fcnName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pathName */
};

static emlrtRSInfo nd_emlrtRSI = {
    23,             /* lineNo */
    "fDIC_xcf_mat", /* fcnName */
    "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
    "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0.0\\funcsV0\\fDIC_"
    "xcf_mat.m" /* pathName */
};

/* Function Declarations */
static void times(const emlrtStack *sp, emxArray_real_T *in1,
                  const emxArray_real_T *in2);

/* Function Definitions */
static void times(const emlrtStack *sp, emxArray_real_T *in1,
                  const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 2, &mc_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  stride_0_0 = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in2->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->size[1];
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, stride_0_0, &mc_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] *
          in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  stride_0_0 = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, stride_0_0, &mc_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

void fDIC_xcf_mat(const emlrtStack *sp, const emxArray_real_T *Image_ref,
                  const emxArray_real_T *Image_test, const struct0_T *ROI,
                  const real_T Filters_setting[4], real_T XCF_mesh,
                  const emxArray_real_T *hfilter,
                  const emxArray_real_T *FFTfilter, emxArray_real_T *Shift_X,
                  emxArray_real_T *Shift_Y, emxArray_real_T *CCmax)
{
  __m128d r;
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  emxArray_creal_T *ROI_ref;
  emxArray_creal_T *ROI_test;
  emxArray_creal_T *b_ROI_test_1;
  emxArray_real_T c_ROI_test_1;
  emxArray_real_T *ROI_test_1;
  emxArray_real_T *Shift_X_temp;
  emxArray_real_T *Shift_Y_temp;
  emxArray_real_T *b_data_fill;
  emxArray_real_T *b_y;
  emxArray_real_T *data_fill;
  emxArray_real_T *y;
  creal_T *ROI_ref_data;
  creal_T *ROI_test_data;
  real_T dv[2];
  real_T dv1[2];
  const real_T *FFTfilter_data;
  const real_T *Image_ref_data;
  const real_T *Image_test_data;
  const real_T *hfilter_data;
  real_T accumulatedData;
  real_T apnd;
  real_T cdiff;
  real_T d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T ndbl;
  real_T *CCmax_data;
  real_T *ROI_test_1_data;
  real_T *Shift_X_temp_data;
  real_T *Shift_Y_temp_data;
  real_T *b_y_data;
  real_T *data_fill_data;
  real_T *y_data;
  int32_T b_loop_ub;
  int32_T b_x_size_idx_0;
  int32_T c_loop_ub;
  int32_T c_x_size_idx_0;
  int32_T d_loop_ub;
  int32_T d_x_size_idx_0;
  int32_T fDIC_xcf_mat_numThreads;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T j;
  int32_T k;
  int32_T loop_ub;
  int32_T loop_ub_tmp_tmp;
  int32_T n;
  int32_T nm1d2;
  int32_T nx;
  int32_T vectorUB;
  int32_T x_size_idx_0;
  boolean_T emlrtHadParallelError = false;
  b_st.prev = sp;
  b_st.tls = sp->tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  FFTfilter_data = FFTfilter->data;
  hfilter_data = hfilter->data;
  Image_test_data = Image_test->data;
  Image_ref_data = Image_ref->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  cross correlation is performed and shift X, shift Y and peak height are */
  /*  determined. */
  /*  Image_size = size(Image_ref); */
  emxInit_real_T(sp, &Shift_X_temp, 1, &o_emlrtRTEI);
  if (!(ROI->num_pass_1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(ROI->num_pass_1, &k_emlrtDCI,
                                (emlrtConstCTX)sp);
  }
  if (ROI->num_pass_1 != (int32_T)muDoubleScalarFloor(ROI->num_pass_1)) {
    emlrtIntegerCheckR2012b(ROI->num_pass_1, &j_emlrtDCI, (emlrtConstCTX)sp);
  }
  nx = Shift_X_temp->size[0];
  Shift_X_temp->size[0] = (int32_T)ROI->num_pass_1;
  emxEnsureCapacity_real_T(sp, Shift_X_temp, nx, &o_emlrtRTEI);
  Shift_X_temp_data = Shift_X_temp->data;
  n = (int32_T)muDoubleScalarFloor(ROI->num_pass_1);
  if (ROI->num_pass_1 != n) {
    emlrtIntegerCheckR2012b(ROI->num_pass_1, &j_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub_tmp_tmp = (int32_T)ROI->num_pass_1;
  for (i = 0; i < loop_ub_tmp_tmp; i++) {
    Shift_X_temp_data[i] = 0.0;
  }
  emxInit_real_T(sp, &Shift_Y_temp, 1, &p_emlrtRTEI);
  nx = Shift_Y_temp->size[0];
  Shift_Y_temp->size[0] = loop_ub_tmp_tmp;
  emxEnsureCapacity_real_T(sp, Shift_Y_temp, nx, &p_emlrtRTEI);
  Shift_Y_temp_data = Shift_Y_temp->data;
  for (i = 0; i < loop_ub_tmp_tmp; i++) {
    Shift_Y_temp_data[i] = 0.0;
  }
  nx = CCmax->size[0];
  CCmax->size[0] = loop_ub_tmp_tmp;
  emxEnsureCapacity_real_T(sp, CCmax, nx, &q_emlrtRTEI);
  CCmax_data = CCmax->data;
  for (i = 0; i < loop_ub_tmp_tmp; i++) {
    CCmax_data[i] = 0.0;
  }
  if (loop_ub_tmp_tmp != n) {
    emlrtIntegerCheckR2012b(ROI->num_pass_1, &emlrtDCI, (emlrtConstCTX)sp);
  }
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, ROI->num_pass_1, mxDOUBLE_CLASS,
                                (int32_T)ROI->num_pass_1, &emlrtRTEI,
                                (emlrtConstCTX)sp);
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  fDIC_xcf_mat_numThreads = emlrtAllocRegionTLSs(
      sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(fDIC_xcf_mat_numThreads) private(             \
        ROI_test_1_data, ROI_test_data, data_fill_data, ROI_ref_data, y_data,  \
            b_y_data, y, b_y, data_fill, b_data_fill, ROI_ref, ROI_test_1,     \
            b_ROI_test_1, ROI_test, accumulatedData, ndbl, apnd,               \
            emlrtJBEnviron, g_st, i1, d, d1, i2, nm1d2, d2, d3, i3, vectorUB,  \
            b_loop_ub, c_loop_ub, k, i4, c_ROI_test_1, r, d_loop_ub, dv1,      \
            cdiff)                                                             \
    firstprivate(st, d_st, e_st, f_st, x_size_idx_0, b_x_size_idx_0,           \
                     c_x_size_idx_0, d_x_size_idx_0, emlrtHadParallelError)
  {
    if (setjmp(emlrtJBEnviron) == 0) {
      st.prev = sp;
      st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
      st.site = NULL;
      emlrtSetJmpBuf(&st, &emlrtJBEnviron);
      d_st.prev = &st;
      d_st.tls = st.tls;
      e_st.prev = &d_st;
      e_st.tls = d_st.tls;
      f_st.prev = &e_st;
      f_st.tls = e_st.tls;
      g_st.prev = &f_st;
      g_st.tls = f_st.tls;
      emxInit_real_T(&st, &y, 2, &fb_emlrtRTEI);
      b_y_data = y->data;
      emxInit_real_T(&st, &b_y, 2, &eb_emlrtRTEI);
      y_data = b_y->data;
      emxInit_real_T(&st, &data_fill, 2, &w_emlrtRTEI);
      emxInit_real_T(&st, &b_data_fill, 1, &w_emlrtRTEI);
      emxInit_creal_T(&st, &ROI_ref, 2, &ab_emlrtRTEI);
      emxInit_real_T(&st, &ROI_test_1, 2, &bb_emlrtRTEI);
      emxInit_creal_T(&st, &b_ROI_test_1, 2, &bb_emlrtRTEI);
      emxInit_creal_T(&st, &ROI_test, 2, &db_emlrtRTEI);
    } else {
      emlrtHadParallelError = true;
    }
#pragma omp for nowait
    for (j = 0; j < loop_ub_tmp_tmp; j++) {
      if (emlrtHadParallelError) {
        continue;
      }
      if (setjmp(emlrtJBEnviron) == 0) {
        accumulatedData = muDoubleScalarRound(ROI->size_pass_1 / 2.0);
        i1 =
            ROI->coordinator_pass_1->size[0] * ROI->coordinator_pass_1->size[1];
        if (j > i1 - 1) {
          emlrtDynamicBoundsCheckR2012b(j, 0, i1 - 1, &i_emlrtBCI, &st);
        }
        d = ROI->coordinator_pass_1->data[j].f1[1] - accumulatedData;
        if (j > i1 - 1) {
          emlrtDynamicBoundsCheckR2012b(j, 0, i1 - 1, &j_emlrtBCI, &st);
        }
        d1 = (ROI->coordinator_pass_1->data[j].f1[1] + accumulatedData) - 1.0;
        if (d > d1) {
          i2 = 0;
          nm1d2 = 0;
        } else {
          if (d != (int32_T)muDoubleScalarFloor(d)) {
            emlrtIntegerCheckR2012b(d, &b_emlrtDCI, &st);
          }
          if (((int32_T)d < 1) || ((int32_T)d > Image_ref->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, Image_ref->size[0],
                                          &emlrtBCI, &st);
          }
          i2 = (int32_T)d - 1;
          if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
            emlrtIntegerCheckR2012b(d1, &c_emlrtDCI, &st);
          }
          if (((int32_T)d1 < 1) || ((int32_T)d1 > Image_ref->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, Image_ref->size[0],
                                          &b_emlrtBCI, &st);
          }
          nm1d2 = (int32_T)d1;
        }
        if (j > i1 - 1) {
          emlrtDynamicBoundsCheckR2012b(j, 0, i1 - 1, &k_emlrtBCI, &st);
        }
        d2 = ROI->coordinator_pass_1->data[j].f1[0] - accumulatedData;
        if (j > i1 - 1) {
          emlrtDynamicBoundsCheckR2012b(j, 0, i1 - 1, &l_emlrtBCI, &st);
        }
        d3 = (ROI->coordinator_pass_1->data[j].f1[0] + accumulatedData) - 1.0;
        if (d2 > d3) {
          i3 = 0;
          vectorUB = 0;
        } else {
          if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
            emlrtIntegerCheckR2012b(d2, &d_emlrtDCI, &st);
          }
          if (((int32_T)d2 < 1) || ((int32_T)d2 > Image_ref->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d2, 1, Image_ref->size[1],
                                          &c_emlrtBCI, &st);
          }
          i3 = (int32_T)d2 - 1;
          if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
            emlrtIntegerCheckR2012b(d3, &e_emlrtDCI, &st);
          }
          if (((int32_T)d3 < 1) || ((int32_T)d3 > Image_ref->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d3, 1, Image_ref->size[1],
                                          &d_emlrtBCI, &st);
          }
          vectorUB = (int32_T)d3;
        }
        b_loop_ub = nm1d2 - i2;
        nm1d2 = ROI_test_1->size[0] * ROI_test_1->size[1];
        ROI_test_1->size[0] = b_loop_ub;
        c_loop_ub = vectorUB - i3;
        ROI_test_1->size[1] = c_loop_ub;
        emxEnsureCapacity_real_T(&st, ROI_test_1, nm1d2, &t_emlrtRTEI);
        ROI_test_1_data = ROI_test_1->data;
        for (k = 0; k < c_loop_ub; k++) {
          for (i4 = 0; i4 < b_loop_ub; i4++) {
            ROI_test_1_data[i4 + ROI_test_1->size[0] * k] =
                Image_ref_data[(i2 + i4) + Image_ref->size[0] * (i3 + k)];
          }
        }
        /*  zero mean and normalise standard deviation */
        d_st.site = &emlrtRSI;
        nm1d2 = b_loop_ub * c_loop_ub;
        e_st.site = &i_emlrtRSI;
        c_ROI_test_1 = *ROI_test_1;
        x_size_idx_0 = nm1d2;
        c_ROI_test_1.size = &x_size_idx_0;
        c_ROI_test_1.numDimensions = 1;
        f_st.site = &j_emlrtRSI;
        accumulatedData = blockedSummation(&f_st, &c_ROI_test_1, nm1d2);
        apnd = accumulatedData / (real_T)nm1d2;
        c_ROI_test_1 = *ROI_test_1;
        b_x_size_idx_0 = nm1d2;
        c_ROI_test_1.size = &b_x_size_idx_0;
        c_ROI_test_1.numDimensions = 1;
        d_st.site = &emlrtRSI;
        accumulatedData = b_std(&d_st, &c_ROI_test_1);
        nm1d2 = ROI_test_1->size[0] * ROI_test_1->size[1];
        ROI_test_1->size[0] = b_loop_ub;
        ROI_test_1->size[1] = c_loop_ub;
        emxEnsureCapacity_real_T(&st, ROI_test_1, nm1d2, &u_emlrtRTEI);
        ROI_test_1_data = ROI_test_1->data;
        for (k = 0; k < c_loop_ub; k++) {
          nm1d2 = (b_loop_ub / 2) << 1;
          vectorUB = nm1d2 - 2;
          for (i4 = 0; i4 <= vectorUB; i4 += 2) {
            _mm_storeu_pd(
                &ROI_test_1_data[i4 + ROI_test_1->size[0] * k],
                _mm_div_pd(
                    _mm_sub_pd(
                        _mm_loadu_pd(
                            &Image_ref_data[(i2 + i4) +
                                            Image_ref->size[0] * (i3 + k)]),
                        _mm_set1_pd(apnd)),
                    _mm_set1_pd(accumulatedData)));
          }
          for (i4 = nm1d2; i4 < b_loop_ub; i4++) {
            ROI_test_1_data[i4 + ROI_test_1->size[0] * k] =
                (Image_ref_data[(i2 + i4) + Image_ref->size[0] * (i3 + k)] -
                 apnd) /
                accumulatedData;
          }
        }
        if ((ROI_test_1->size[0] != hfilter->size[0]) &&
            ((ROI_test_1->size[0] != 1) && (hfilter->size[0] != 1))) {
          emlrtDimSizeImpxCheckR2021b(ROI_test_1->size[0], hfilter->size[0],
                                      &emlrtECI, &st);
        }
        if ((ROI_test_1->size[1] != hfilter->size[1]) &&
            ((ROI_test_1->size[1] != 1) && (hfilter->size[1] != 1))) {
          emlrtDimSizeImpxCheckR2021b(ROI_test_1->size[1], hfilter->size[1],
                                      &b_emlrtECI, &st);
        }
        if ((ROI_test_1->size[0] == hfilter->size[0]) &&
            (ROI_test_1->size[1] == hfilter->size[1])) {
          nm1d2 = ROI_test_1->size[0] * ROI_test_1->size[1];
          vectorUB = (nm1d2 / 2) << 1;
          c_loop_ub = vectorUB - 2;
          for (k = 0; k <= c_loop_ub; k += 2) {
            r = _mm_loadu_pd(&ROI_test_1_data[k]);
            _mm_storeu_pd(&ROI_test_1_data[k],
                          _mm_mul_pd(r, _mm_loadu_pd(&hfilter_data[k])));
          }
          for (k = vectorUB; k < nm1d2; k++) {
            ROI_test_1_data[k] *= hfilter_data[k];
          }
        } else {
          d_st.site = &md_emlrtRSI;
          times(&d_st, ROI_test_1, hfilter);
        }
        /*  han filtering */
        d_st.site = &b_emlrtRSI;
        fft2(&d_st, ROI_test_1, ROI_test);
        ROI_test_data = ROI_test->data;
        /*  2D fast fourier transform */
        ndbl = Filters_setting[2] + Filters_setting[3];
        if (muDoubleScalarIsNaN(ndbl)) {
          nm1d2 = b_y->size[0] * b_y->size[1];
          b_y->size[0] = 1;
          b_y->size[1] = 1;
          emxEnsureCapacity_real_T(&st, b_y, nm1d2, &v_emlrtRTEI);
          y_data = b_y->data;
          y_data[0] = rtNaN;
        } else if (ndbl < 1.0) {
          b_y->size[0] = 1;
          b_y->size[1] = 0;
        } else {
          nm1d2 = b_y->size[0] * b_y->size[1];
          b_y->size[0] = 1;
          b_y->size[1] = (int32_T)(ndbl - 1.0) + 1;
          emxEnsureCapacity_real_T(&st, b_y, nm1d2, &v_emlrtRTEI);
          y_data = b_y->data;
          nm1d2 = (int32_T)(ndbl - 1.0);
          vectorUB = (((int32_T)(ndbl - 1.0) + 1) / 2) << 1;
          c_loop_ub = vectorUB - 2;
          for (k = 0; k <= c_loop_ub; k += 2) {
            dv1[0] = k;
            dv1[1] = k + 1;
            r = _mm_loadu_pd(&dv1[0]);
            _mm_storeu_pd(&y_data[k], _mm_add_pd(_mm_set1_pd(1.0), r));
          }
          for (k = vectorUB; k <= nm1d2; k++) {
            y_data[k] = (real_T)k + 1.0;
          }
        }
        d_st.site = &c_emlrtRSI;
        accumulatedData = ROI->size_pass_1 - (ndbl - 1.0);
        e_st.site = &ib_emlrtRSI;
        if (muDoubleScalarIsNaN(accumulatedData) ||
            muDoubleScalarIsNaN(ROI->size_pass_1)) {
          nm1d2 = y->size[0] * y->size[1];
          y->size[0] = 1;
          y->size[1] = 1;
          emxEnsureCapacity_real_T(&e_st, y, nm1d2, &v_emlrtRTEI);
          b_y_data = y->data;
          b_y_data[0] = rtNaN;
        } else if (ROI->size_pass_1 < accumulatedData) {
          y->size[0] = 1;
          y->size[1] = 0;
        } else if ((muDoubleScalarIsInf(accumulatedData) ||
                    muDoubleScalarIsInf(ROI->size_pass_1)) &&
                   (accumulatedData == ROI->size_pass_1)) {
          nm1d2 = y->size[0] * y->size[1];
          y->size[0] = 1;
          y->size[1] = 1;
          emxEnsureCapacity_real_T(&e_st, y, nm1d2, &v_emlrtRTEI);
          b_y_data = y->data;
          b_y_data[0] = rtNaN;
        } else if (muDoubleScalarFloor(accumulatedData) == accumulatedData) {
          nm1d2 = y->size[0] * y->size[1];
          y->size[0] = 1;
          c_loop_ub = (int32_T)(ROI->size_pass_1 - accumulatedData);
          y->size[1] = c_loop_ub + 1;
          emxEnsureCapacity_real_T(&e_st, y, nm1d2, &v_emlrtRTEI);
          b_y_data = y->data;
          nm1d2 = ((c_loop_ub + 1) / 2) << 1;
          vectorUB = nm1d2 - 2;
          for (k = 0; k <= vectorUB; k += 2) {
            dv1[0] = k;
            dv1[1] = k + 1;
            r = _mm_loadu_pd(&dv1[0]);
            _mm_storeu_pd(&b_y_data[k],
                          _mm_add_pd(_mm_set1_pd(accumulatedData), r));
          }
          for (k = nm1d2; k <= c_loop_ub; k++) {
            b_y_data[k] = accumulatedData + (real_T)k;
          }
        } else {
          f_st.site = &jb_emlrtRSI;
          ndbl =
              muDoubleScalarFloor((ROI->size_pass_1 - accumulatedData) + 0.5);
          apnd = accumulatedData + ndbl;
          cdiff = apnd - ROI->size_pass_1;
          if (muDoubleScalarAbs(cdiff) <
              4.4408920985006262E-16 *
                  muDoubleScalarMax(muDoubleScalarAbs(accumulatedData),
                                    muDoubleScalarAbs(ROI->size_pass_1))) {
            ndbl++;
            apnd = ROI->size_pass_1;
          } else if (cdiff > 0.0) {
            apnd = accumulatedData + (ndbl - 1.0);
          } else {
            ndbl++;
          }
          if (ndbl >= 0.0) {
            vectorUB = (int32_T)ndbl;
          } else {
            vectorUB = 0;
          }
          g_st.site = &kb_emlrtRSI;
          if (ndbl > 2.147483647E+9) {
            emlrtErrorWithMessageIdR2018a(&g_st, &e_emlrtRTEI,
                                          "Coder:MATLAB:pmaxsize",
                                          "Coder:MATLAB:pmaxsize", 0);
          }
          nm1d2 = y->size[0] * y->size[1];
          y->size[0] = 1;
          y->size[1] = vectorUB;
          emxEnsureCapacity_real_T(&f_st, y, nm1d2, &y_emlrtRTEI);
          b_y_data = y->data;
          if (vectorUB > 0) {
            b_y_data[0] = accumulatedData;
            if (vectorUB > 1) {
              b_y_data[vectorUB - 1] = apnd;
              nm1d2 = (int32_T)((uint32_T)(vectorUB - 1) >> 1);
              for (k = 0; k <= nm1d2 - 2; k++) {
                b_y_data[k + 1] = accumulatedData + ((real_T)k + 1.0);
                b_y_data[(vectorUB - k) - 2] = apnd - ((real_T)k + 1.0);
              }
              if (nm1d2 << 1 == vectorUB - 1) {
                b_y_data[nm1d2] = (accumulatedData + apnd) / 2.0;
              } else {
                b_y_data[nm1d2] = accumulatedData + (real_T)nm1d2;
                b_y_data[nm1d2 + 1] = apnd - (real_T)nm1d2;
              }
            }
          }
        }
        nm1d2 = data_fill->size[0] * data_fill->size[1];
        data_fill->size[0] = 1;
        d_loop_ub = b_y->size[1] + y->size[1];
        data_fill->size[1] = d_loop_ub;
        emxEnsureCapacity_real_T(&st, data_fill, nm1d2, &w_emlrtRTEI);
        ROI_test_1_data = data_fill->data;
        nm1d2 = b_y->size[1];
        for (k = 0; k < nm1d2; k++) {
          ROI_test_1_data[k] = y_data[k];
        }
        nm1d2 = y->size[1];
        for (k = 0; k < nm1d2; k++) {
          ROI_test_1_data[k + b_y->size[1]] = b_y_data[k];
        }
        nm1d2 = b_data_fill->size[0];
        b_data_fill->size[0] = d_loop_ub;
        emxEnsureCapacity_real_T(&st, b_data_fill, nm1d2, &x_emlrtRTEI);
        data_fill_data = b_data_fill->data;
        for (k = 0; k < d_loop_ub; k++) {
          data_fill_data[k] = ROI_test_1_data[k];
        }
        for (k = 0; k < d_loop_ub; k++) {
          if (data_fill_data[k] !=
              (int32_T)muDoubleScalarFloor(data_fill_data[k])) {
            emlrtIntegerCheckR2012b(data_fill_data[k], &l_emlrtDCI, &st);
          }
          nm1d2 = (int32_T)data_fill_data[k];
          if ((nm1d2 < 1) || (nm1d2 > FFTfilter->size[0])) {
            emlrtDynamicBoundsCheckR2012b(nm1d2, 1, FFTfilter->size[0],
                                          &o_emlrtBCI, &st);
          }
        }
        for (k = 0; k < d_loop_ub; k++) {
          nm1d2 = (int32_T)data_fill_data[k];
          if ((nm1d2 < 1) || (nm1d2 > FFTfilter->size[1])) {
            emlrtDynamicBoundsCheckR2012b(nm1d2, 1, FFTfilter->size[1],
                                          &p_emlrtBCI, &st);
          }
        }
        for (k = 0; k < d_loop_ub; k++) {
          nm1d2 = (int32_T)data_fill_data[k];
          if ((nm1d2 < 1) || (nm1d2 > ROI_test->size[0])) {
            emlrtDynamicBoundsCheckR2012b(nm1d2, 1, ROI_test->size[0],
                                          &q_emlrtBCI, &st);
          }
        }
        for (k = 0; k < d_loop_ub; k++) {
          nm1d2 = (int32_T)data_fill_data[k];
          if ((nm1d2 < 1) || (nm1d2 > ROI_test->size[1])) {
            emlrtDynamicBoundsCheckR2012b(nm1d2, 1, ROI_test->size[1],
                                          &r_emlrtBCI, &st);
          }
        }
        nm1d2 = ROI_ref->size[0] * ROI_ref->size[1];
        ROI_ref->size[0] = d_loop_ub;
        ROI_ref->size[1] = d_loop_ub;
        emxEnsureCapacity_creal_T(&st, ROI_ref, nm1d2, &ab_emlrtRTEI);
        ROI_ref_data = ROI_ref->data;
        for (k = 0; k < d_loop_ub; k++) {
          for (i4 = 0; i4 < d_loop_ub; i4++) {
            nm1d2 = (int32_T)data_fill_data[i4] - 1;
            vectorUB = (int32_T)data_fill_data[k] - 1;
            apnd = FFTfilter_data[nm1d2 + FFTfilter->size[0] * vectorUB];
            ROI_ref_data[i4 + ROI_ref->size[0] * k].re =
                apnd * ROI_test_data[nm1d2 + ROI_test->size[0] * vectorUB].re;
            ROI_ref_data[i4 + ROI_ref->size[0] * k].im =
                apnd * ROI_test_data[nm1d2 + ROI_test->size[0] * vectorUB].im;
          }
        }
        /*  apply high and low frequence filter */
        if (j > i1 - 1) {
          emlrtDynamicBoundsCheckR2012b(j, 0, i1 - 1, &m_emlrtBCI, &st);
        }
        if (d > d1) {
          i3 = 0;
          nm1d2 = 0;
        } else {
          if (d != (int32_T)muDoubleScalarFloor(d)) {
            emlrtIntegerCheckR2012b(d, &f_emlrtDCI, &st);
          }
          if (((int32_T)d < 1) || ((int32_T)d > Image_test->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, Image_test->size[0],
                                          &e_emlrtBCI, &st);
          }
          i3 = (int32_T)d - 1;
          if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
            emlrtIntegerCheckR2012b(d1, &g_emlrtDCI, &st);
          }
          if (((int32_T)d1 < 1) || ((int32_T)d1 > Image_test->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, Image_test->size[0],
                                          &f_emlrtBCI, &st);
          }
          nm1d2 = (int32_T)d1;
        }
        if (j > i1 - 1) {
          emlrtDynamicBoundsCheckR2012b(j, 0, i1 - 1, &n_emlrtBCI, &st);
        }
        if (d2 > d3) {
          i2 = 0;
          vectorUB = 0;
        } else {
          if (d2 != (int32_T)muDoubleScalarFloor(d2)) {
            emlrtIntegerCheckR2012b(d2, &h_emlrtDCI, &st);
          }
          if (((int32_T)d2 < 1) || ((int32_T)d2 > Image_test->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d2, 1, Image_test->size[1],
                                          &g_emlrtBCI, &st);
          }
          i2 = (int32_T)d2 - 1;
          if (d3 != (int32_T)muDoubleScalarFloor(d3)) {
            emlrtIntegerCheckR2012b(d3, &i_emlrtDCI, &st);
          }
          if (((int32_T)d3 < 1) || ((int32_T)d3 > Image_test->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d3, 1, Image_test->size[1],
                                          &h_emlrtBCI, &st);
          }
          vectorUB = (int32_T)d3;
        }
        b_loop_ub = nm1d2 - i3;
        nm1d2 = ROI_test_1->size[0] * ROI_test_1->size[1];
        ROI_test_1->size[0] = b_loop_ub;
        vectorUB -= i2;
        ROI_test_1->size[1] = vectorUB;
        emxEnsureCapacity_real_T(&st, ROI_test_1, nm1d2, &bb_emlrtRTEI);
        ROI_test_1_data = ROI_test_1->data;
        for (k = 0; k < vectorUB; k++) {
          for (i4 = 0; i4 < b_loop_ub; i4++) {
            ROI_test_1_data[i4 + ROI_test_1->size[0] * k] =
                Image_test_data[(i3 + i4) + Image_test->size[0] * (i2 + k)];
          }
        }
        /*  zero mean and normalise standard deviation */
        d_st.site = &d_emlrtRSI;
        nm1d2 = b_loop_ub * vectorUB;
        e_st.site = &i_emlrtRSI;
        c_ROI_test_1 = *ROI_test_1;
        c_x_size_idx_0 = nm1d2;
        c_ROI_test_1.size = &c_x_size_idx_0;
        c_ROI_test_1.numDimensions = 1;
        f_st.site = &j_emlrtRSI;
        accumulatedData = blockedSummation(&f_st, &c_ROI_test_1, nm1d2);
        accumulatedData /= (real_T)nm1d2;
        c_ROI_test_1 = *ROI_test_1;
        d_x_size_idx_0 = nm1d2;
        c_ROI_test_1.size = &d_x_size_idx_0;
        c_ROI_test_1.numDimensions = 1;
        d_st.site = &d_emlrtRSI;
        ndbl = b_std(&d_st, &c_ROI_test_1);
        nm1d2 = ROI_test_1->size[0] * ROI_test_1->size[1];
        ROI_test_1->size[0] = b_loop_ub;
        ROI_test_1->size[1] = vectorUB;
        emxEnsureCapacity_real_T(&st, ROI_test_1, nm1d2, &cb_emlrtRTEI);
        ROI_test_1_data = ROI_test_1->data;
        for (k = 0; k < vectorUB; k++) {
          nm1d2 = (b_loop_ub / 2) << 1;
          c_loop_ub = nm1d2 - 2;
          for (i4 = 0; i4 <= c_loop_ub; i4 += 2) {
            _mm_storeu_pd(
                &ROI_test_1_data[i4 + ROI_test_1->size[0] * k],
                _mm_div_pd(
                    _mm_sub_pd(
                        _mm_loadu_pd(
                            &Image_test_data[(i3 + i4) +
                                             Image_test->size[0] * (i2 + k)]),
                        _mm_set1_pd(accumulatedData)),
                    _mm_set1_pd(ndbl)));
          }
          for (i4 = nm1d2; i4 < b_loop_ub; i4++) {
            ROI_test_1_data[i4 + ROI_test_1->size[0] * k] =
                (Image_test_data[(i3 + i4) + Image_test->size[0] * (i2 + k)] -
                 accumulatedData) /
                ndbl;
          }
        }
        if ((ROI_test_1->size[0] != hfilter->size[0]) &&
            ((ROI_test_1->size[0] != 1) && (hfilter->size[0] != 1))) {
          emlrtDimSizeImpxCheckR2021b(ROI_test_1->size[0], hfilter->size[0],
                                      &c_emlrtECI, &st);
        }
        if ((ROI_test_1->size[1] != hfilter->size[1]) &&
            ((ROI_test_1->size[1] != 1) && (hfilter->size[1] != 1))) {
          emlrtDimSizeImpxCheckR2021b(ROI_test_1->size[1], hfilter->size[1],
                                      &d_emlrtECI, &st);
        }
        if ((ROI_test_1->size[0] == hfilter->size[0]) &&
            (ROI_test_1->size[1] == hfilter->size[1])) {
          nm1d2 = ROI_test_1->size[0] * ROI_test_1->size[1];
          vectorUB = (nm1d2 / 2) << 1;
          c_loop_ub = vectorUB - 2;
          for (k = 0; k <= c_loop_ub; k += 2) {
            r = _mm_loadu_pd(&ROI_test_1_data[k]);
            _mm_storeu_pd(&ROI_test_1_data[k],
                          _mm_mul_pd(r, _mm_loadu_pd(&hfilter_data[k])));
          }
          for (k = vectorUB; k < nm1d2; k++) {
            ROI_test_1_data[k] *= hfilter_data[k];
          }
        } else {
          d_st.site = &nd_emlrtRSI;
          times(&d_st, ROI_test_1, hfilter);
        }
        /*  han filtering */
        d_st.site = &e_emlrtRSI;
        fft2(&d_st, ROI_test_1, b_ROI_test_1);
        ROI_ref_data = b_ROI_test_1->data;
        /*  2D fast fourier transform */
        for (k = 0; k < d_loop_ub; k++) {
          nm1d2 = (int32_T)data_fill_data[k];
          if ((nm1d2 < 1) || (nm1d2 > FFTfilter->size[0])) {
            emlrtDynamicBoundsCheckR2012b(nm1d2, 1, FFTfilter->size[0],
                                          &s_emlrtBCI, &st);
          }
        }
        for (k = 0; k < d_loop_ub; k++) {
          nm1d2 = (int32_T)data_fill_data[k];
          if ((nm1d2 < 1) || (nm1d2 > FFTfilter->size[1])) {
            emlrtDynamicBoundsCheckR2012b(nm1d2, 1, FFTfilter->size[1],
                                          &t_emlrtBCI, &st);
          }
        }
        for (k = 0; k < d_loop_ub; k++) {
          nm1d2 = (int32_T)data_fill_data[k];
          if ((nm1d2 < 1) || (nm1d2 > b_ROI_test_1->size[0])) {
            emlrtDynamicBoundsCheckR2012b(nm1d2, 1, b_ROI_test_1->size[0],
                                          &u_emlrtBCI, &st);
          }
        }
        for (k = 0; k < d_loop_ub; k++) {
          nm1d2 = (int32_T)data_fill_data[k];
          if ((nm1d2 < 1) || (nm1d2 > b_ROI_test_1->size[1])) {
            emlrtDynamicBoundsCheckR2012b(nm1d2, 1, b_ROI_test_1->size[1],
                                          &v_emlrtBCI, &st);
          }
        }
        nm1d2 = ROI_test->size[0] * ROI_test->size[1];
        ROI_test->size[0] = d_loop_ub;
        ROI_test->size[1] = d_loop_ub;
        emxEnsureCapacity_creal_T(&st, ROI_test, nm1d2, &db_emlrtRTEI);
        ROI_test_data = ROI_test->data;
        for (k = 0; k < d_loop_ub; k++) {
          for (i4 = 0; i4 < d_loop_ub; i4++) {
            nm1d2 = (int32_T)data_fill_data[i4] - 1;
            vectorUB = (int32_T)data_fill_data[k] - 1;
            accumulatedData =
                FFTfilter_data[nm1d2 + FFTfilter->size[0] * vectorUB];
            ROI_test_data[i4 + ROI_test->size[0] * k].re =
                accumulatedData *
                ROI_ref_data[nm1d2 + b_ROI_test_1->size[0] * vectorUB].re;
            ROI_test_data[i4 + ROI_test->size[0] * k].im =
                accumulatedData *
                ROI_ref_data[nm1d2 + b_ROI_test_1->size[0] * vectorUB].im;
          }
        }
        d_st.site = &f_emlrtRSI;
        apnd = fReg(&d_st, ROI_ref, ROI_test, ROI->size_pass_1, XCF_mesh,
                    b_data_fill, &ndbl, &accumulatedData);
        if ((int32_T)((uint32_T)j + 1U) > Shift_X_temp->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                        Shift_X_temp->size[0], &w_emlrtBCI,
                                        &st);
        }
        Shift_X_temp_data[j] = apnd;
        if ((int32_T)((uint32_T)j + 1U) > Shift_Y_temp->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                        Shift_Y_temp->size[0], &x_emlrtBCI,
                                        &st);
        }
        Shift_Y_temp_data[j] = ndbl;
        if ((int32_T)((uint32_T)j + 1U) > CCmax->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)j + 1U), 1,
                                        CCmax->size[0], &y_emlrtBCI, &st);
        }
        CCmax_data[j] = accumulatedData;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      } else {
        emlrtHadParallelError = true;
      }
    }
    if (!emlrtHadParallelError) {
      emlrtHeapReferenceStackLeaveScope(&st, 8);
      emxFree_creal_T(&st, &ROI_test);
      emxFree_creal_T(&st, &b_ROI_test_1);
      emxFree_real_T(&st, &ROI_test_1);
      emxFree_creal_T(&st, &ROI_ref);
      emxFree_real_T(&st, &b_data_fill);
      emxFree_real_T(&st, &data_fill);
      emxFree_real_T(&st, &b_y);
      emxFree_real_T(&st, &y);
    }
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  dv[0] = ROI->position_X_pass_1->size[0];
  dv[1] = ROI->position_X_pass_1->size[1];
  b_st.site = &g_emlrtRSI;
  nx = Shift_X_temp->size[0];
  c_st.site = &ld_emlrtRSI;
  assertValidSizeArg(&c_st, dv);
  n = Shift_X_temp->size[0];
  if (Shift_X_temp->size[0] < 1) {
    n = 1;
  }
  nx = muIntScalarMax_sint32(nx, n);
  if (ROI->position_X_pass_1->size[0] > nx) {
    emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (ROI->position_X_pass_1->size[1] > nx) {
    emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  loop_ub_tmp_tmp =
      ROI->position_X_pass_1->size[0] * ROI->position_X_pass_1->size[1];
  if (loop_ub_tmp_tmp != Shift_X_temp->size[0]) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &c_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  nx = Shift_X->size[0] * Shift_X->size[1];
  Shift_X->size[0] = ROI->position_X_pass_1->size[0];
  Shift_X->size[1] = ROI->position_X_pass_1->size[1];
  emxEnsureCapacity_real_T(sp, Shift_X, nx, &r_emlrtRTEI);
  CCmax_data = Shift_X->data;
  loop_ub = ROI->position_X_pass_1->size[0] * ROI->position_X_pass_1->size[1];
  for (i = 0; i < loop_ub; i++) {
    CCmax_data[i] = Shift_X_temp_data[i];
  }
  emxFree_real_T(sp, &Shift_X_temp);
  b_st.site = &h_emlrtRSI;
  nx = Shift_Y_temp->size[0];
  c_st.site = &ld_emlrtRSI;
  assertValidSizeArg(&c_st, dv);
  n = Shift_Y_temp->size[0];
  if (Shift_Y_temp->size[0] < 1) {
    n = 1;
  }
  nx = muIntScalarMax_sint32(nx, n);
  if (ROI->position_X_pass_1->size[0] > nx) {
    emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (ROI->position_X_pass_1->size[1] > nx) {
    emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (loop_ub_tmp_tmp != Shift_Y_temp->size[0]) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &c_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  nx = Shift_Y->size[0] * Shift_Y->size[1];
  Shift_Y->size[0] = ROI->position_X_pass_1->size[0];
  Shift_Y->size[1] = ROI->position_X_pass_1->size[1];
  emxEnsureCapacity_real_T(sp, Shift_Y, nx, &s_emlrtRTEI);
  CCmax_data = Shift_Y->data;
  for (i = 0; i < loop_ub; i++) {
    CCmax_data[i] = Shift_Y_temp_data[i];
  }
  emxFree_real_T(sp, &Shift_Y_temp);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (fDIC_xcf_mat.c) */
