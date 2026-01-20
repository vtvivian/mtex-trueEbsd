/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * fReg.c
 *
 * Code generation for function 'fReg'
 *
 */

/* Include files */
#include "fReg.h"
#include "eml_fftshift.h"
#include "eml_int_forloop_overflow_check.h"
#include "exp.h"
#include "fDIC_xcf_mat_data.h"
#include "fDIC_xcf_mat_emxutil.h"
#include "fDIC_xcf_mat_types.h"
#include "ifft2.h"
#include "ifftshift.h"
#include "indexShapeCheck.h"
#include "mtimes.h"
#include "relop.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "omp.h"
#include <emmintrin.h>
#include <math.h>

/* Variable Definitions */
static emlrtRSInfo mb_emlrtRSI =
    {
        18,     /* lineNo */
        "fReg", /* fcnName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pathName */
};

static emlrtRSInfo nb_emlrtRSI =
    {
        21,     /* lineNo */
        "fReg", /* fcnName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI =
    {
        22,     /* lineNo */
        "fReg", /* fcnName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI =
    {
        23,     /* lineNo */
        "fReg", /* fcnName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI =
    {
        56,     /* lineNo */
        "fReg", /* fcnName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI =
    {
        59,     /* lineNo */
        "fReg", /* fcnName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI =
    {
        60,     /* lineNo */
        "fReg", /* fcnName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI =
    {
        62,     /* lineNo */
        "fReg", /* fcnName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI =
    {
        63,     /* lineNo */
        "fReg", /* fcnName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI =
    {
        65,     /* lineNo */
        "fReg", /* fcnName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pathName */
};

static emlrtRSInfo wb_emlrtRSI =
    {
        68,     /* lineNo */
        "fReg", /* fcnName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pathName */
};

static emlrtRSInfo xb_emlrtRSI =
    {
        69,     /* lineNo */
        "fReg", /* fcnName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pathName */
};

static emlrtRSInfo
    yb_emlrtRSI =
        {
            12,         /* lineNo */
            "fftshift", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\fftshif"
            "t.m" /* pathName */
};

static emlrtRSInfo pc_emlrtRSI = {
    17,    /* lineNo */
    "max", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" /* pathName
                                                                        */
};

static emlrtRSInfo qc_emlrtRSI =
    {
        67,         /* lineNo */
        "minOrMax", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI =
    {
        106,       /* lineNo */
        "maximum", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    288,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    381,                     /* lineNo */
    "unaryMinOrMaxDispatch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    449,          /* lineNo */
    "minOrMax2D", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo vc_emlrtRSI = {
    533,                         /* lineNo */
    "minOrMax2DColumnMajorDim1", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo wc_emlrtRSI = {
    531,                         /* lineNo */
    "minOrMax2DColumnMajorDim1", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo xc_emlrtRSI = {
    371,                     /* lineNo */
    "unaryMinOrMaxDispatch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo yc_emlrtRSI = {
    418,          /* lineNo */
    "minOrMax1D", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo bd_emlrtRSI =
    {
        94,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pathName */
};

static emlrtRSInfo id_emlrtRSI =
    {
        69,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pathName */
};

static emlrtDCInfo m_emlrtDCI =
    {
        13,     /* lineNo */
        22,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m", /* pName */
        4                     /* checkKind */
};

static emlrtDCInfo n_emlrtDCI =
    {
        13,     /* lineNo */
        22,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m", /* pName */
        1                     /* checkKind */
};

static emlrtECInfo e_emlrtECI =
    {
        1,      /* nDims */
        18,     /* lineNo */
        18,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtECInfo f_emlrtECI =
    {
        2,      /* nDims */
        18,     /* lineNo */
        18,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtDCInfo o_emlrtDCI =
    {
        17,     /* lineNo */
        8,      /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m", /* pName */
        1                     /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI =
    {
        -1,     /* iFirst */
        -1,     /* iLast */
        17,     /* lineNo */
        8,      /* colNo */
        "CC",   /* aName */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m", /* pName */
        0                     /* checkKind */
};

static emlrtDCInfo p_emlrtDCI =
    {
        17,     /* lineNo */
        41,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m", /* pName */
        1                     /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI =
    {
        -1,     /* iFirst */
        -1,     /* iLast */
        17,     /* lineNo */
        41,     /* colNo */
        "CC",   /* aName */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m", /* pName */
        0                     /* checkKind */
};

static emlrtDCInfo q_emlrtDCI =
    {
        17,     /* lineNo */
        78,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m", /* pName */
        1                     /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI =
    {
        -1,     /* iFirst */
        -1,     /* iLast */
        17,     /* lineNo */
        78,     /* colNo */
        "CC",   /* aName */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m", /* pName */
        0                     /* checkKind */
};

static emlrtDCInfo r_emlrtDCI =
    {
        17,     /* lineNo */
        111,    /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m", /* pName */
        1                     /* checkKind */
};

static emlrtBCInfo db_emlrtBCI =
    {
        -1,     /* iFirst */
        -1,     /* iLast */
        17,     /* lineNo */
        111,    /* colNo */
        "CC",   /* aName */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m", /* pName */
        0                     /* checkKind */
};

static emlrtECInfo g_emlrtECI =
    {
        -1,     /* nDims */
        17,     /* lineNo */
        5,      /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtBCInfo eb_emlrtBCI =
    {
        -1,     /* iFirst */
        -1,     /* iLast */
        24,     /* lineNo */
        15,     /* colNo */
        "loc1", /* aName */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m", /* pName */
        0                     /* checkKind */
};

static emlrtECInfo h_emlrtECI =
    {
        1,      /* nDims */
        64,     /* lineNo */
        10,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtECInfo i_emlrtECI =
    {
        2,      /* nDims */
        64,     /* lineNo */
        10,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtBCInfo fb_emlrtBCI =
    {
        -1,     /* iFirst */
        -1,     /* iLast */
        72,     /* lineNo */
        17,     /* colNo */
        "loc1", /* aName */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m", /* pName */
        0                     /* checkKind */
};

static emlrtRTEInfo g_emlrtRTEI = {
    90,              /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    198,             /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI =
    {
        138,                   /* lineNo */
        23,                    /* colNo */
        "dynamic_size_checks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI =
    {
        133,                   /* lineNo */
        23,                    /* colNo */
        "dynamic_size_checks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pName */
};

static emlrtBCInfo gb_emlrtBCI =
    {
        -1,     /* iFirst */
        -1,     /* iLast */
        57,     /* lineNo */
        13,     /* colNo */
        "c_i",  /* aName */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m", /* pName */
        0                     /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI =
    {
        -1,     /* iFirst */
        -1,     /* iLast */
        60,     /* lineNo */
        13,     /* colNo */
        "r_i",  /* aName */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m", /* pName */
        0                     /* checkKind */
};

static emlrtRTEInfo mb_emlrtRTEI =
    {
        13,     /* lineNo */
        5,      /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRTEInfo nb_emlrtRTEI =
    {
        18,     /* lineNo */
        28,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI =
    {
        18,     /* lineNo */
        18,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI =
    {
        21,     /* lineNo */
        16,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    523,             /* lineNo */
    21,              /* colNo */
    "unaryMinOrMax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    525,             /* lineNo */
    5,               /* colNo */
    "unaryMinOrMax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    18,    /* lineNo */
    5,     /* colNo */
    "max", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" /* pName
                                                                        */
};

static emlrtRTEInfo tb_emlrtRTEI =
    {
        56,     /* lineNo */
        5,      /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRTEInfo ub_emlrtRTEI =
    {
        57,     /* lineNo */
        9,      /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRTEInfo vb_emlrtRTEI =
    {
        57,     /* lineNo */
        5,      /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRTEInfo wb_emlrtRTEI =
    {
        59,     /* lineNo */
        5,      /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRTEInfo xb_emlrtRTEI =
    {
        76,                  /* lineNo */
        13,                  /* colNo */
        "eml_mtimes_helper", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pName */
};

static emlrtRTEInfo yb_emlrtRTEI =
    {
        62,     /* lineNo */
        32,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRTEInfo ac_emlrtRTEI =
    {
        60,     /* lineNo */
        9,      /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRTEInfo bc_emlrtRTEI =
    {
        64,     /* lineNo */
        18,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRTEInfo cc_emlrtRTEI =
    {
        64,     /* lineNo */
        5,      /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRTEInfo dc_emlrtRTEI =
    {
        62,     /* lineNo */
        5,      /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRTEInfo ec_emlrtRTEI =
    {
        56,     /* lineNo */
        19,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRTEInfo fc_emlrtRTEI =
    {
        65,     /* lineNo */
        14,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRTEInfo gc_emlrtRTEI =
    {
        1,      /* lineNo */
        40,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRTEInfo nc_emlrtRTEI =
    {
        64,     /* lineNo */
        10,     /* colNo */
        "fReg", /* fName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pName */
};

static emlrtRSInfo od_emlrtRSI =
    {
        64,     /* lineNo */
        "fReg", /* fcnName */
        "D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
        "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-2.0."
        "0\\funcsV0\\fReg.m" /* pathName */
};

/* Function Declarations */
static void b_times(const emlrtStack *sp, emxArray_creal_T *in1,
                    const emxArray_creal_T *in2);

/* Function Definitions */
static void b_times(const emlrtStack *sp, emxArray_creal_T *in1,
                    const emxArray_creal_T *in2)
{
  emxArray_creal_T *b_in2;
  const creal_T *in2_data;
  creal_T *b_in2_data;
  creal_T *in1_data;
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
  emxInit_creal_T(sp, &b_in2, 2, &nc_emlrtRTEI);
  if (in1->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in1->size[0];
  }
  stride_0_0 = b_in2->size[0] * b_in2->size[1];
  b_in2->size[0] = loop_ub;
  if (in1->size[1] == 1) {
    b_loop_ub = in2->size[1];
  } else {
    b_loop_ub = in1->size[1];
  }
  b_in2->size[1] = b_loop_ub;
  emxEnsureCapacity_creal_T(sp, b_in2, stride_0_0, &nc_emlrtRTEI);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in1->size[0] != 1);
  stride_1_1 = (in1->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      real_T d;
      real_T d1;
      real_T d2;
      real_T d3;
      int32_T i2;
      int32_T i3;
      i2 = i1 * stride_0_0;
      i3 = i1 * stride_1_0;
      d = in2_data[i2 + in2->size[0] * aux_0_1].re;
      d1 = in1_data[i3 + in1->size[0] * aux_1_1].im;
      d2 = in2_data[i2 + in2->size[0] * aux_0_1].im;
      d3 = in1_data[i3 + in1->size[0] * aux_1_1].re;
      b_in2_data[i1 + b_in2->size[0] * i].re = d * d3 - d2 * d1;
      b_in2_data[i1 + b_in2->size[0] * i].im = d * d1 + d2 * d3;
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  stride_0_0 = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_creal_T(sp, in1, stride_0_0, &nc_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in2_data[i1 + b_in2->size[0] * i];
    }
  }
  emxFree_creal_T(sp, &b_in2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

real_T fReg(const emlrtStack *sp, const emxArray_creal_T *buf1ft,
            const emxArray_creal_T *buf2ft, real_T XCF_roisize, real_T XCF_mesh,
            const emxArray_real_T *data_fill, real_T *row_shift, real_T *CCmax)
{
  __m128d r;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_creal_T *CC;
  emxArray_creal_T *b_prefac;
  emxArray_creal_T *ex;
  emxArray_creal_T *kern;
  emxArray_creal_T *kernc;
  emxArray_creal_T *y;
  emxArray_int32_T *idx;
  emxArray_real_T *b_c_i;
  emxArray_real_T *b_loc1;
  emxArray_real_T *c_i;
  emxArray_real_T *loc1;
  emxArray_real_T *r_i;
  const creal_T *buf1ft_data;
  const creal_T *buf2ft_data;
  creal_T b_CC;
  creal_T prefac;
  creal_T *CC_data;
  creal_T *kern_data;
  const real_T *data_fill_data;
  real_T b_re_tmp;
  real_T c_re_tmp;
  real_T coff;
  real_T col_shift;
  real_T d;
  real_T d_re_tmp;
  real_T dftshift;
  real_T e_re_tmp;
  real_T f_re_tmp;
  real_T g_re_tmp;
  real_T h_re_tmp;
  real_T i_re_tmp;
  real_T j_re_tmp;
  real_T re_tmp;
  real_T roff;
  real_T *b_c_i_data;
  real_T *c_i_data;
  real_T *loc1_data;
  real_T *r_i_data;
  int32_T iv[2];
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T d_loop_ub;
  int32_T e_loop_ub;
  int32_T fReg_numThreads;
  int32_T i;
  int32_T i1;
  int32_T i10;
  int32_T i11;
  int32_T i12;
  int32_T i13;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  int32_T i8;
  int32_T i9;
  int32_T j;
  int32_T loop_ub;
  int32_T m;
  int32_T n;
  int32_T *idx_data;
  boolean_T b;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  data_fill_data = data_fill->data;
  buf2ft_data = buf2ft->data;
  buf1ft_data = buf1ft->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /* FREG Register two FFTs to subpixel accuracy */
  /* a reduced form of the code submitted to the matlab file exchange */
  /* http://www.mathworks.co.uk/matlabcentral/fileexchange/18401-efficient-subpixel-image-registration-by-cross-correlation
   */
  /*  */
  /* reported in the literature: */
  /* Manuel Guizar-Sicairos, Samuel T. Thurman, and James R. Fienup */
  /* "Efficient subpixel image registration algorithms," Opt. Lett. 33, 156-158
   * (2008). */
  /*  */
  /* also modded to handle the filtered FFT sizes */
  /* TBB 2012 */
  col_shift = XCF_roisize * 2.0;
  if (!(col_shift >= 0.0)) {
    emlrtNonNegativeCheckR2012b(col_shift, &m_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (col_shift != (int32_T)muDoubleScalarFloor(col_shift)) {
    emlrtIntegerCheckR2012b(col_shift, &n_emlrtDCI, (emlrtConstCTX)sp);
  }
  emxInit_creal_T(sp, &CC, 2, &mb_emlrtRTEI);
  i = (int32_T)col_shift;
  loop_ub = CC->size[0] * CC->size[1];
  CC->size[0] = (int32_T)col_shift;
  CC->size[1] = (int32_T)col_shift;
  emxEnsureCapacity_creal_T(sp, CC, loop_ub, &mb_emlrtRTEI);
  CC_data = CC->data;
  b_loop_ub = (int32_T)col_shift * (int32_T)col_shift;
  for (b_i = 0; b_i < b_loop_ub; b_i++) {
    CC_data[b_i].re = 0.0;
    CC_data[b_i].im = 0.0;
  }
  emxInit_creal_T(sp, &kern, 2, &cc_emlrtRTEI);
  i1 = buf2ft->size[0];
  loop_ub = kern->size[0] * kern->size[1];
  kern->size[0] = buf2ft->size[0];
  i2 = buf2ft->size[1];
  kern->size[1] = buf2ft->size[1];
  emxEnsureCapacity_creal_T(sp, kern, loop_ub, &nb_emlrtRTEI);
  kern_data = kern->data;
  c_loop_ub = buf2ft->size[0] * buf2ft->size[1];
  i3 = (c_loop_ub < 1600);
  if (i3) {
    for (i4 = 0; i4 < c_loop_ub; i4++) {
      kern_data[i4].re = buf2ft_data[i4].re;
      kern_data[i4].im = -buf2ft_data[i4].im;
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
    emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    fReg_numThreads = emlrtAllocRegionTLSs(
        sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(fReg_numThreads)

    for (i4 = 0; i4 < c_loop_ub; i4++) {
      kern_data[i4].re = buf2ft_data[i4].re;
      kern_data[i4].im = -buf2ft_data[i4].im;
    }
    emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  }
  i5 = buf1ft->size[0];
  if ((buf1ft->size[0] != i1) && ((buf1ft->size[0] != 1) && (i1 != 1))) {
    emlrtDimSizeImpxCheckR2021b(buf1ft->size[0], i1, &e_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  i6 = buf1ft->size[1];
  if ((buf1ft->size[1] != i2) && ((buf1ft->size[1] != 1) && (i2 != 1))) {
    emlrtDimSizeImpxCheckR2021b(buf1ft->size[1], i2, &f_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  re_tmp = (XCF_roisize + 1.0) - trunc((real_T)data_fill->size[0] / 2.0);
  coff = (XCF_roisize + 1.0) + trunc(((real_T)data_fill->size[0] - 1.0) / 2.0);
  if (re_tmp > coff) {
    d_loop_ub = 0;
    n = 0;
    i7 = 0;
    e_loop_ub = 0;
  } else {
    b_re_tmp = (int32_T)muDoubleScalarFloor(re_tmp);
    if (re_tmp != b_re_tmp) {
      emlrtIntegerCheckR2012b(re_tmp, &o_emlrtDCI, (emlrtConstCTX)sp);
    }
    overflow = (((int32_T)re_tmp < 1) || ((int32_T)re_tmp > i));
    if (overflow) {
      emlrtDynamicBoundsCheckR2012b((int32_T)re_tmp, 1, i, &ab_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    d_loop_ub = (int32_T)re_tmp - 1;
    roff = (int32_T)muDoubleScalarFloor(coff);
    if (coff != roff) {
      emlrtIntegerCheckR2012b(coff, &p_emlrtDCI, (emlrtConstCTX)sp);
    }
    b = (((int32_T)coff < 1) || ((int32_T)coff > i));
    if (b) {
      emlrtDynamicBoundsCheckR2012b((int32_T)coff, 1, i, &bb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    n = (int32_T)coff;
    if (re_tmp != b_re_tmp) {
      emlrtIntegerCheckR2012b(re_tmp, &q_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (overflow) {
      emlrtDynamicBoundsCheckR2012b((int32_T)re_tmp, 1, i, &cb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i7 = (int32_T)re_tmp - 1;
    if (coff != roff) {
      emlrtIntegerCheckR2012b(coff, &r_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (b) {
      emlrtDynamicBoundsCheckR2012b((int32_T)coff, 1, i, &db_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    e_loop_ub = (int32_T)coff;
  }
  st.site = &mb_emlrtRSI;
  b = ((buf1ft->size[0] == kern->size[0]) &&
       (buf1ft->size[1] == kern->size[1]));
  if (b) {
    m = buf1ft->size[0] * buf1ft->size[1];
    loop_ub = kern->size[0] * kern->size[1];
    kern->size[0] = buf1ft->size[0];
    kern->size[1] = buf1ft->size[1];
    emxEnsureCapacity_creal_T(&st, kern, loop_ub, &ob_emlrtRTEI);
    kern_data = kern->data;
    if (m < 1600) {
      for (i8 = 0; i8 < m; i8++) {
        re_tmp = buf1ft_data[i8].re;
        coff = kern_data[i8].im;
        b_re_tmp = buf1ft_data[i8].im;
        roff = kern_data[i8].re;
        kern_data[i8].re = re_tmp * roff - b_re_tmp * coff;
        kern_data[i8].im = re_tmp * coff + b_re_tmp * roff;
      }
    } else {
      emlrtEnterParallelRegion(&st, omp_in_parallel());
      emlrtPushJmpBuf(&st, &emlrtJBStack);
      fReg_numThreads =
          emlrtAllocRegionTLSs(st.tls, omp_in_parallel(), omp_get_max_threads(),
                               omp_get_num_procs());
#pragma omp parallel for num_threads(fReg_numThreads) private(                 \
        c_re_tmp, d_re_tmp, e_re_tmp, f_re_tmp)

      for (i8 = 0; i8 < m; i8++) {
        c_re_tmp = buf1ft_data[i8].re;
        d_re_tmp = kern_data[i8].im;
        e_re_tmp = buf1ft_data[i8].im;
        f_re_tmp = kern_data[i8].re;
        kern_data[i8].re = c_re_tmp * f_re_tmp - e_re_tmp * d_re_tmp;
        kern_data[i8].im = c_re_tmp * d_re_tmp + e_re_tmp * f_re_tmp;
      }
      emlrtPopJmpBuf(&st, &emlrtJBStack);
      emlrtExitParallelRegion(&st, omp_in_parallel());
    }
  } else {
    b_st.site = &mb_emlrtRSI;
    b_times(&b_st, kern, buf1ft);
  }
  b_st.site = &yb_emlrtRSI;
  eml_fftshift(&b_st, kern, 1);
  b_st.site = &yb_emlrtRSI;
  eml_fftshift(&b_st, kern, 2);
  kern_data = kern->data;
  n -= d_loop_ub;
  iv[0] = n;
  loop_ub = e_loop_ub - i7;
  iv[1] = loop_ub;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &kern->size[0], 2, &g_emlrtECI,
                                (emlrtCTX)sp);
  for (j = 0; j < loop_ub; j++) {
    for (b_i = 0; b_i < n; b_i++) {
      CC_data[(d_loop_ub + b_i) + CC->size[0] * (i7 + j)] =
          kern_data[b_i + n * j];
    }
  }
  /*  Compute crosscorrelation and locate the peak  */
  loop_ub = kern->size[0] * kern->size[1];
  kern->size[0] = i;
  kern->size[1] = i;
  emxEnsureCapacity_creal_T(sp, kern, loop_ub, &pb_emlrtRTEI);
  kern_data = kern->data;
  for (b_i = 0; b_i < b_loop_ub; b_i++) {
    kern_data[b_i] = CC_data[b_i];
  }
  st.site = &nb_emlrtRSI;
  ifftshift(&st, kern);
  st.site = &nb_emlrtRSI;
  ifft2(&st, kern, CC);
  CC_data = CC->data;
  /*  Calculate cross-correlation */
  st.site = &ob_emlrtRSI;
  b_st.site = &pc_emlrtRSI;
  c_st.site = &qc_emlrtRSI;
  d_st.site = &rc_emlrtRSI;
  if (((CC->size[0] != 1) || (CC->size[1] != 1)) && (CC->size[0] == 1)) {
    emlrtErrorWithMessageIdR2018a(&d_st, &g_emlrtRTEI,
                                  "Coder:toolbox:autoDimIncompatibility",
                                  "Coder:toolbox:autoDimIncompatibility", 0);
  }
  if (CC->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &h_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &sc_emlrtRSI;
  f_st.site = &tc_emlrtRSI;
  g_st.site = &uc_emlrtRSI;
  m = CC->size[0];
  n = CC->size[1];
  emxInit_creal_T(&g_st, &ex, 2, &gc_emlrtRTEI);
  loop_ub = ex->size[0] * ex->size[1];
  ex->size[0] = 1;
  ex->size[1] = CC->size[1];
  emxEnsureCapacity_creal_T(&g_st, ex, loop_ub, &qb_emlrtRTEI);
  kern_data = ex->data;
  emxInit_int32_T(&g_st, &idx, &gc_emlrtRTEI);
  loop_ub = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = CC->size[1];
  emxEnsureCapacity_int32_T(&g_st, idx, loop_ub, &rb_emlrtRTEI);
  idx_data = idx->data;
  for (b_i = 0; b_i < n; b_i++) {
    idx_data[b_i] = 1;
  }
  if (CC->size[1] >= 1) {
    h_st.site = &wc_emlrtRSI;
    if (CC->size[1] > 2147483646) {
      i_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&i_st);
    }
    overflow = (CC->size[0] > 2147483646);
    for (j = 0; j < n; j++) {
      kern_data[j] = CC_data[CC->size[0] * j];
      h_st.site = &vc_emlrtRSI;
      if (overflow) {
        i_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (b_i = 2; b_i <= m; b_i++) {
        b_CC = CC_data[(b_i + CC->size[0] * j) - 1];
        if (relop(kern_data[j], b_CC)) {
          kern_data[j] = b_CC;
          idx_data[j] = b_i;
        }
      }
    }
  }
  emxInit_real_T(&st, &loc1, 2, &ec_emlrtRTEI);
  loop_ub = loc1->size[0] * loc1->size[1];
  loc1->size[0] = 1;
  loc1->size[1] = CC->size[1];
  emxEnsureCapacity_real_T(&st, loc1, loop_ub, &sb_emlrtRTEI);
  loc1_data = loc1->data;
  for (b_i = 0; b_i < n; b_i++) {
    loc1_data[b_i] = idx_data[b_i];
  }
  st.site = &pb_emlrtRSI;
  b_st.site = &pc_emlrtRSI;
  c_st.site = &qc_emlrtRSI;
  d_st.site = &rc_emlrtRSI;
  if (ex->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &h_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &sc_emlrtRSI;
  f_st.site = &xc_emlrtRSI;
  loop_ub = 1;
  prefac = kern_data[0];
  g_st.site = &yc_emlrtRSI;
  if (ex->size[1] > 2147483646) {
    h_st.site = &r_emlrtRSI;
    check_forloop_overflow_error(&h_st);
  }
  for (b_i = 2; b_i <= n; b_i++) {
    b_CC = kern_data[b_i - 1];
    if (relop(prefac, b_CC)) {
      prefac = b_CC;
      loop_ub = b_i;
    }
  }
  if (loop_ub > CC->size[1]) {
    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, CC->size[1], &eb_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  /*  Obtain shift in original pixel grid from the position of the
   * crosscorrelation peak  */
  /* %% DFT computation %%% */
  /*  Initial shift estimate in upsampled grid */
  re_tmp = loc1_data[loop_ub - 1];
  if (re_tmp > XCF_roisize) {
    re_tmp = (re_tmp - col_shift) - 1.0;
  } else {
    re_tmp--;
  }
  *row_shift = muDoubleScalarRound(re_tmp / 2.0 * XCF_mesh) / XCF_mesh;
  if (loop_ub > XCF_roisize) {
    re_tmp = ((real_T)loop_ub - col_shift) - 1.0;
  } else {
    re_tmp = (real_T)loop_ub - 1.0;
  }
  col_shift = muDoubleScalarRound(re_tmp / 2.0 * XCF_mesh) / XCF_mesh;
  re_tmp = muDoubleScalarCeil(XCF_mesh * 1.5);
  dftshift = trunc(re_tmp / 2.0);
  /*  Center of output array at dftshift+1 */
  /*  Matrix multiply DFT around the current shift estimate */
  roff = dftshift - *row_shift * XCF_mesh;
  coff = dftshift - col_shift * XCF_mesh;
  /*  Compute kernels and obtain DFT by matrix products */
  prefac.im = -6.2831853071795862 / (XCF_roisize * XCF_mesh);
  /* speed up kernel generation for reduced filtered FFT */
  b_re_tmp = muDoubleScalarFloor(XCF_roisize / 2.0);
  overflow = muDoubleScalarIsNaN(XCF_roisize - 1.0);
  if (overflow) {
    loop_ub = loc1->size[0] * loc1->size[1];
    loc1->size[0] = 1;
    loc1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, loc1, loop_ub, &v_emlrtRTEI);
    loc1_data = loc1->data;
    loc1_data[0] = rtNaN;
  } else if (XCF_roisize - 1.0 < 0.0) {
    loc1->size[0] = 1;
    loc1->size[1] = 0;
  } else {
    loop_ub = loc1->size[0] * loc1->size[1];
    loc1->size[0] = 1;
    loc1->size[1] = (int32_T)(XCF_roisize - 1.0) + 1;
    emxEnsureCapacity_real_T(sp, loc1, loop_ub, &v_emlrtRTEI);
    loc1_data = loc1->data;
    loop_ub = (int32_T)(XCF_roisize - 1.0);
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      loc1_data[b_i] = b_i;
    }
  }
  st.site = &qb_emlrtRSI;
  b_ifftshift(&st, loc1);
  loc1_data = loc1->data;
  emxInit_real_T(sp, &c_i, 1, &tb_emlrtRTEI);
  n = loc1->size[1];
  loop_ub = c_i->size[0];
  c_i->size[0] = loc1->size[1];
  emxEnsureCapacity_real_T(sp, c_i, loop_ub, &tb_emlrtRTEI);
  c_i_data = c_i->data;
  loop_ub = (loc1->size[1] / 2) << 1;
  m = loop_ub - 2;
  for (j = 0; j <= m; j += 2) {
    r = _mm_loadu_pd(&loc1_data[j]);
    _mm_storeu_pd(&c_i_data[j], _mm_sub_pd(r, _mm_set1_pd(b_re_tmp)));
  }
  for (j = loop_ub; j < n; j++) {
    c_i_data[j] = loc1_data[j] - b_re_tmp;
  }
  emxInit_real_T(sp, &b_c_i, 1, &ub_emlrtRTEI);
  d_loop_ub = data_fill->size[0];
  loop_ub = b_c_i->size[0];
  b_c_i->size[0] = data_fill->size[0];
  emxEnsureCapacity_real_T(sp, b_c_i, loop_ub, &ub_emlrtRTEI);
  b_c_i_data = b_c_i->data;
  for (j = 0; j < d_loop_ub; j++) {
    loop_ub = (int32_T)data_fill_data[j];
    if ((loop_ub < 1) || (loop_ub > c_i->size[0])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, c_i->size[0], &gb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    b_c_i_data[j] = c_i_data[loop_ub - 1];
  }
  e_loop_ub = b_c_i->size[0];
  loop_ub = c_i->size[0];
  c_i->size[0] = b_c_i->size[0];
  emxEnsureCapacity_real_T(sp, c_i, loop_ub, &vb_emlrtRTEI);
  c_i_data = c_i->data;
  for (j = 0; j < e_loop_ub; j++) {
    c_i_data[j] = b_c_i_data[j];
  }
  emxInit_real_T(sp, &r_i, 2, &wb_emlrtRTEI);
  if (overflow) {
    loop_ub = r_i->size[0] * r_i->size[1];
    r_i->size[0] = 1;
    r_i->size[1] = 1;
    emxEnsureCapacity_real_T(sp, r_i, loop_ub, &v_emlrtRTEI);
    r_i_data = r_i->data;
    r_i_data[0] = rtNaN;
  } else if (XCF_roisize - 1.0 < 0.0) {
    r_i->size[0] = 1;
    r_i->size[1] = 0;
  } else {
    loop_ub = r_i->size[0] * r_i->size[1];
    r_i->size[0] = 1;
    r_i->size[1] = (int32_T)(XCF_roisize - 1.0) + 1;
    emxEnsureCapacity_real_T(sp, r_i, loop_ub, &v_emlrtRTEI);
    r_i_data = r_i->data;
    loop_ub = (int32_T)(XCF_roisize - 1.0);
    for (j = 0; j <= loop_ub; j++) {
      r_i_data[j] = j;
    }
  }
  st.site = &rb_emlrtRSI;
  b_ifftshift(&st, r_i);
  loop_ub = r_i->size[0] * r_i->size[1];
  r_i->size[0] = 1;
  emxEnsureCapacity_real_T(sp, r_i, loop_ub, &wb_emlrtRTEI);
  r_i_data = r_i->data;
  loop_ub = r_i->size[1] - 1;
  m = (r_i->size[1] / 2) << 1;
  n = m - 2;
  for (j = 0; j <= n; j += 2) {
    r = _mm_loadu_pd(&r_i_data[j]);
    _mm_storeu_pd(&r_i_data[j], _mm_sub_pd(r, _mm_set1_pd(b_re_tmp)));
  }
  for (j = m; j <= loop_ub; j++) {
    r_i_data[j] -= b_re_tmp;
  }
  st.site = &sb_emlrtRSI;
  indexShapeCheck(&st, r_i->size, data_fill->size[0]);
  for (j = 0; j < d_loop_ub; j++) {
    loop_ub = (int32_T)data_fill_data[j];
    if ((loop_ub < 1) || (loop_ub > r_i->size[1])) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, r_i->size[1], &hb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
  }
  overflow = muDoubleScalarIsNaN(re_tmp - 1.0);
  if (overflow) {
    loop_ub = loc1->size[0] * loc1->size[1];
    loc1->size[0] = 1;
    loc1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, loc1, loop_ub, &v_emlrtRTEI);
    loc1_data = loc1->data;
    loc1_data[0] = rtNaN;
  } else if (re_tmp - 1.0 < 0.0) {
    loc1->size[0] = 1;
    loc1->size[1] = 0;
  } else {
    loop_ub = loc1->size[0] * loc1->size[1];
    loc1->size[0] = 1;
    loc1->size[1] = (int32_T)(re_tmp - 1.0) + 1;
    emxEnsureCapacity_real_T(sp, loc1, loop_ub, &v_emlrtRTEI);
    loc1_data = loc1->data;
    loop_ub = (int32_T)(re_tmp - 1.0);
    for (j = 0; j <= loop_ub; j++) {
      loc1_data[j] = j;
    }
  }
  emxInit_creal_T(sp, &kernc, 2, &dc_emlrtRTEI);
  st.site = &tb_emlrtRSI;
  emxInit_creal_T(&st, &b_prefac, 1, &xb_emlrtRTEI);
  loop_ub = b_prefac->size[0];
  b_prefac->size[0] = b_c_i->size[0];
  emxEnsureCapacity_creal_T(&st, b_prefac, loop_ub, &xb_emlrtRTEI);
  kern_data = b_prefac->data;
  loop_ub = b_c_i->size[0];
  emxFree_real_T(&st, &b_c_i);
  if (c_i->size[0] < 1600) {
    for (i9 = 0; i9 < e_loop_ub; i9++) {
      kern_data[i9].re = c_i_data[i9] * 0.0;
      kern_data[i9].im = c_i_data[i9] * prefac.im;
    }
  } else {
    emlrtEnterParallelRegion(&st, omp_in_parallel());
    emlrtPushJmpBuf(&st, &emlrtJBStack);
    fReg_numThreads = emlrtAllocRegionTLSs(
        st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(fReg_numThreads)

    for (i9 = 0; i9 < loop_ub; i9++) {
      kern_data[i9].re = c_i_data[i9] * 0.0;
      kern_data[i9].im = c_i_data[i9] * prefac.im;
    }
    emlrtPopJmpBuf(&st, &emlrtJBStack);
    emlrtExitParallelRegion(&st, omp_in_parallel());
  }
  emxInit_real_T(&st, &b_loc1, 2, &yb_emlrtRTEI);
  loop_ub = b_loc1->size[0] * b_loc1->size[1];
  b_loc1->size[0] = 1;
  n = loc1->size[1];
  b_loc1->size[1] = loc1->size[1];
  emxEnsureCapacity_real_T(&st, b_loc1, loop_ub, &yb_emlrtRTEI);
  b_c_i_data = b_loc1->data;
  loop_ub = (loc1->size[1] / 2) << 1;
  m = loop_ub - 2;
  for (j = 0; j <= m; j += 2) {
    r = _mm_loadu_pd(&loc1_data[j]);
    _mm_storeu_pd(&b_c_i_data[j], _mm_sub_pd(r, _mm_set1_pd(coff)));
  }
  for (j = loop_ub; j < n; j++) {
    b_c_i_data[j] = loc1_data[j] - coff;
  }
  b_st.site = &bd_emlrtRSI;
  mtimes(&b_st, b_prefac, b_loc1, kernc);
  emxFree_real_T(&st, &b_loc1);
  st.site = &tb_emlrtRSI;
  b_exp(&st, kernc);
  if (overflow) {
    loop_ub = loc1->size[0] * loc1->size[1];
    loc1->size[0] = 1;
    loc1->size[1] = 1;
    emxEnsureCapacity_real_T(sp, loc1, loop_ub, &v_emlrtRTEI);
    loc1_data = loc1->data;
    loc1_data[0] = rtNaN;
  } else if (re_tmp - 1.0 < 0.0) {
    loc1->size[0] = 1;
    loc1->size[1] = 0;
  } else {
    loop_ub = loc1->size[0] * loc1->size[1];
    loc1->size[0] = 1;
    loc1->size[1] = (int32_T)(re_tmp - 1.0) + 1;
    emxEnsureCapacity_real_T(sp, loc1, loop_ub, &v_emlrtRTEI);
    loc1_data = loc1->data;
    loop_ub = (int32_T)(re_tmp - 1.0);
    for (j = 0; j <= loop_ub; j++) {
      loc1_data[j] = j;
    }
  }
  st.site = &ub_emlrtRSI;
  m = loc1->size[1];
  loop_ub = b_prefac->size[0];
  b_prefac->size[0] = loc1->size[1];
  emxEnsureCapacity_creal_T(&st, b_prefac, loop_ub, &xb_emlrtRTEI);
  kern_data = b_prefac->data;
  loop_ub = loc1->size[1];
  if (loc1->size[1] < 1600) {
    for (i10 = 0; i10 < m; i10++) {
      re_tmp = loc1_data[i10] - roff;
      kern_data[i10].re = re_tmp * 0.0;
      kern_data[i10].im = re_tmp * prefac.im;
    }
  } else {
    emlrtEnterParallelRegion(&st, omp_in_parallel());
    emlrtPushJmpBuf(&st, &emlrtJBStack);
    fReg_numThreads = emlrtAllocRegionTLSs(
        st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(fReg_numThreads) private(d)

    for (i10 = 0; i10 < loop_ub; i10++) {
      d = loc1_data[i10] - roff;
      kern_data[i10].re = d * 0.0;
      kern_data[i10].im = d * prefac.im;
    }
    emlrtPopJmpBuf(&st, &emlrtJBStack);
    emlrtExitParallelRegion(&st, omp_in_parallel());
  }
  loop_ub = c_i->size[0];
  c_i->size[0] = d_loop_ub;
  emxEnsureCapacity_real_T(&st, c_i, loop_ub, &ac_emlrtRTEI);
  c_i_data = c_i->data;
  for (b_i = 0; b_i < d_loop_ub; b_i++) {
    c_i_data[b_i] = r_i_data[(int32_T)data_fill_data[b_i] - 1];
  }
  emxFree_real_T(&st, &r_i);
  b_st.site = &bd_emlrtRSI;
  b_mtimes(&b_st, b_prefac, c_i, CC);
  emxFree_creal_T(&st, &b_prefac);
  emxFree_real_T(&st, &c_i);
  st.site = &ub_emlrtRSI;
  b_exp(&st, CC);
  loop_ub = kern->size[0] * kern->size[1];
  kern->size[0] = i5;
  kern->size[1] = i6;
  emxEnsureCapacity_creal_T(sp, kern, loop_ub, &bc_emlrtRTEI);
  kern_data = kern->data;
  loop_ub = buf1ft->size[0] * buf1ft->size[1];
  if (loop_ub < 1600) {
    for (i11 = 0; i11 < loop_ub; i11++) {
      kern_data[i11].re = buf1ft_data[i11].re;
      kern_data[i11].im = -buf1ft_data[i11].im;
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
    emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    fReg_numThreads = emlrtAllocRegionTLSs(
        sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(fReg_numThreads)

    for (i11 = 0; i11 < loop_ub; i11++) {
      kern_data[i11].re = buf1ft_data[i11].re;
      kern_data[i11].im = -buf1ft_data[i11].im;
    }
    emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  }
  if ((i1 != i5) && ((i1 != 1) && (i5 != 1))) {
    emlrtDimSizeImpxCheckR2021b(i1, i5, &h_emlrtECI, (emlrtConstCTX)sp);
  }
  if ((i2 != i6) && ((i2 != 1) && (i6 != 1))) {
    emlrtDimSizeImpxCheckR2021b(i2, i6, &i_emlrtECI, (emlrtConstCTX)sp);
  }
  if (b) {
    loop_ub = kern->size[0] * kern->size[1];
    kern->size[0] = i1;
    kern->size[1] = i2;
    emxEnsureCapacity_creal_T(sp, kern, loop_ub, &cc_emlrtRTEI);
    kern_data = kern->data;
    if (i3) {
      for (i12 = 0; i12 < c_loop_ub; i12++) {
        re_tmp = buf2ft_data[i12].re;
        b_re_tmp = kern_data[i12].im;
        roff = buf2ft_data[i12].im;
        coff = kern_data[i12].re;
        kern_data[i12].re = re_tmp * coff - roff * b_re_tmp;
        kern_data[i12].im = re_tmp * b_re_tmp + roff * coff;
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
      emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
      fReg_numThreads =
          emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(),
                               omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(fReg_numThreads) private(                 \
        g_re_tmp, h_re_tmp, i_re_tmp, j_re_tmp)

      for (i12 = 0; i12 < c_loop_ub; i12++) {
        g_re_tmp = buf2ft_data[i12].re;
        h_re_tmp = kern_data[i12].im;
        i_re_tmp = buf2ft_data[i12].im;
        j_re_tmp = kern_data[i12].re;
        kern_data[i12].re = g_re_tmp * j_re_tmp - i_re_tmp * h_re_tmp;
        kern_data[i12].im = g_re_tmp * h_re_tmp + i_re_tmp * j_re_tmp;
      }
      emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
      emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
    }
  } else {
    st.site = &od_emlrtRSI;
    b_times(&st, kern, buf2ft);
  }
  emxInit_creal_T(sp, &y, 2, &fc_emlrtRTEI);
  st.site = &vb_emlrtRSI;
  b_st.site = &id_emlrtRSI;
  if (kern->size[0] != CC->size[1]) {
    if (((CC->size[0] == 1) && (CC->size[1] == 1)) ||
        ((kern->size[0] == 1) && (kern->size[1] == 1))) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &j_emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI, "MATLAB:innerdim",
                                    "MATLAB:innerdim", 0);
    }
  }
  b_st.site = &bd_emlrtRSI;
  c_mtimes(&b_st, CC, kern, y);
  emxFree_creal_T(&st, &kern);
  st.site = &vb_emlrtRSI;
  b_st.site = &id_emlrtRSI;
  if (kernc->size[0] != y->size[1]) {
    if (((y->size[0] == 1) && (y->size[1] == 1)) ||
        ((kernc->size[0] == 1) && (kernc->size[1] == 1))) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &j_emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI, "MATLAB:innerdim",
                                    "MATLAB:innerdim", 0);
    }
  }
  b_st.site = &bd_emlrtRSI;
  c_mtimes(&b_st, y, kernc, CC);
  CC_data = CC->data;
  emxFree_creal_T(&st, &y);
  emxFree_creal_T(&st, &kernc);
  loop_ub = CC->size[0] * CC->size[1];
  m = CC->size[0];
  n = CC->size[1];
  if (loop_ub < 1600) {
    for (i13 = 0; i13 < loop_ub; i13++) {
      CC_data[i13].im = -CC_data[i13].im;
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
    emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    fReg_numThreads = emlrtAllocRegionTLSs(
        sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(fReg_numThreads)

    for (i13 = 0; i13 < loop_ub; i13++) {
      CC_data[i13].im = -CC_data[i13].im;
    }
    emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  }
  /*  Locate maximum and map back to original pixel grid */
  st.site = &wb_emlrtRSI;
  b_st.site = &pc_emlrtRSI;
  c_st.site = &qc_emlrtRSI;
  d_st.site = &rc_emlrtRSI;
  if (((CC->size[0] != 1) || (CC->size[1] != 1)) && (CC->size[0] == 1)) {
    emlrtErrorWithMessageIdR2018a(&d_st, &g_emlrtRTEI,
                                  "Coder:toolbox:autoDimIncompatibility",
                                  "Coder:toolbox:autoDimIncompatibility", 0);
  }
  if (CC->size[0] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &h_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &sc_emlrtRSI;
  f_st.site = &tc_emlrtRSI;
  g_st.site = &uc_emlrtRSI;
  loop_ub = ex->size[0] * ex->size[1];
  ex->size[0] = 1;
  ex->size[1] = n;
  emxEnsureCapacity_creal_T(&g_st, ex, loop_ub, &qb_emlrtRTEI);
  kern_data = ex->data;
  loop_ub = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = n;
  emxEnsureCapacity_int32_T(&g_st, idx, loop_ub, &rb_emlrtRTEI);
  idx_data = idx->data;
  for (b_i = 0; b_i < n; b_i++) {
    idx_data[b_i] = 1;
  }
  if (CC->size[1] >= 1) {
    h_st.site = &wc_emlrtRSI;
    if (CC->size[1] > 2147483646) {
      i_st.site = &r_emlrtRSI;
      check_forloop_overflow_error(&i_st);
    }
    overflow = (CC->size[0] > 2147483646);
    for (b_i = 0; b_i < n; b_i++) {
      kern_data[b_i] = CC_data[CC->size[0] * b_i];
      h_st.site = &vc_emlrtRSI;
      if (overflow) {
        i_st.site = &r_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (j = 2; j <= m; j++) {
        b_CC = CC_data[(j + CC->size[0] * b_i) - 1];
        if (relop(kern_data[b_i], b_CC)) {
          kern_data[b_i] = b_CC;
          idx_data[b_i] = j;
        }
      }
    }
  }
  emxFree_creal_T(&g_st, &CC);
  loop_ub = loc1->size[0] * loc1->size[1];
  loc1->size[0] = 1;
  loc1->size[1] = n;
  emxEnsureCapacity_real_T(&st, loc1, loop_ub, &sb_emlrtRTEI);
  loc1_data = loc1->data;
  for (b_i = 0; b_i < n; b_i++) {
    loc1_data[b_i] = idx_data[b_i];
  }
  emxFree_int32_T(&st, &idx);
  st.site = &xb_emlrtRSI;
  b_st.site = &pc_emlrtRSI;
  c_st.site = &qc_emlrtRSI;
  d_st.site = &rc_emlrtRSI;
  if (ex->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &h_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &sc_emlrtRSI;
  f_st.site = &xc_emlrtRSI;
  loop_ub = 1;
  prefac = kern_data[0];
  g_st.site = &yc_emlrtRSI;
  if (ex->size[1] > 2147483646) {
    h_st.site = &r_emlrtRSI;
    check_forloop_overflow_error(&h_st);
  }
  for (b_i = 2; b_i <= n; b_i++) {
    b_CC = kern_data[b_i - 1];
    if (relop(prefac, b_CC)) {
      prefac = b_CC;
      loop_ub = b_i;
    }
  }
  emxFree_creal_T(&f_st, &ex);
  *CCmax = muDoubleScalarHypot(prefac.re, prefac.im);
  if (loop_ub > n) {
    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, n, &fb_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  /*      CCmax = CC(rloc,cloc); */
  *row_shift += ((loc1_data[loop_ub - 1] - dftshift) - 1.0) / XCF_mesh;
  emxFree_real_T(sp, &loc1);
  col_shift += (((real_T)loop_ub - dftshift) - 1.0) / XCF_mesh;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return col_shift;
}

/* End of code generation (fReg.c) */
