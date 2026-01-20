/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * fDIC_xcf_mat_data.c
 *
 * Code generation for function 'fDIC_xcf_mat_data'
 *
 */

/* Include files */
#include "fDIC_xcf_mat_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131674U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "fDIC_xcf_mat",                                       /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

emlrtRSInfo j_emlrtRSI = {
    86,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pathName */
};

emlrtRSInfo r_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" /* pathName */
};

emlrtRSInfo y_emlrtRSI =
    {
        42,    /* lineNo */
        "fft", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "fft\\fft.m" /* pathName */
};

emlrtRSInfo ab_emlrtRSI =
    {
        73,                /* lineNo */
        "executeCallback", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "fft\\fft.m" /* pathName */
};

emlrtRSInfo bb_emlrtRSI = {
    44,                        /* lineNo */
    "Custom1DFFTCallback/fft", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\Custom1DFFTCallback.m" /* pathName */
};

emlrtRSInfo cb_emlrtRSI = {
    56,                            /* lineNo */
    "Custom1DFFTCallback/fftLoop", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\Custom1DFFTCallback.m" /* pathName */
};

emlrtRSInfo db_emlrtRSI = {
    57,                            /* lineNo */
    "Custom1DFFTCallback/fftLoop", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\Custom1DFFTCallback.m" /* pathName */
};

emlrtRSInfo eb_emlrtRSI = {
    54,                            /* lineNo */
    "Custom1DFFTCallback/fftLoop", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\Custom1DFFTCallback.m" /* pathName */
};

emlrtRSInfo ac_emlrtRSI = {
    166,            /* lineNo */
    "eml_fftshift", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_"
    "fftshift.m" /* pathName */
};

emlrtRSInfo bc_emlrtRSI = {
    159,            /* lineNo */
    "eml_fftshift", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_"
    "fftshift.m" /* pathName */
};

emlrtRSInfo cc_emlrtRSI = {
    156,            /* lineNo */
    "eml_fftshift", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_"
    "fftshift.m" /* pathName */
};

emlrtRSInfo dc_emlrtRSI = {
    144,            /* lineNo */
    "eml_fftshift", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_"
    "fftshift.m" /* pathName */
};

emlrtRSInfo ec_emlrtRSI = {
    138,            /* lineNo */
    "eml_fftshift", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_"
    "fftshift.m" /* pathName */
};

emlrtRSInfo fc_emlrtRSI = {
    135,            /* lineNo */
    "eml_fftshift", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_"
    "fftshift.m" /* pathName */
};

emlrtRSInfo gc_emlrtRSI = {
    35,             /* lineNo */
    "eml_fftshift", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_"
    "fftshift.m" /* pathName */
};

emlrtRSInfo hc_emlrtRSI = {
    55,         /* lineNo */
    "prodsize", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\prodsize.m" /* pathName */
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t fDIC_xcf_mat_nestLockGlobal;

emlrtRTEInfo v_emlrtRTEI =
    {
        28,      /* lineNo */
        9,       /* colNo */
        "colon", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pName
                                                                          */
};

emlrtRTEInfo kb_emlrtRTEI = {
    32,                   /* lineNo */
    44,                   /* colNo */
    "MATLABFFTWCallback", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "fft\\MATLABFFTWCallback.m" /* pName */
};

emlrtRTEInfo lb_emlrtRTEI = {
    56,                    /* lineNo */
    17,                    /* colNo */
    "Custom1DFFTCallback", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\Custom1DFFTCallback.m" /* pName */
};

/* End of code generation (fDIC_xcf_mat_data.c) */
