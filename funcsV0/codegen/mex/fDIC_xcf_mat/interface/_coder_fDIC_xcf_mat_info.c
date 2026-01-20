/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * _coder_fDIC_xcf_mat_info.c
 *
 * Code generation for function 'fDIC_xcf_mat'
 *
 */

/* Include files */
#include "_coder_fDIC_xcf_mat_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[5] = {
      "789ced944b4fc24010c7b7068d077c2426c62f013144a3786d113111096dd0680d2eedd4"
      "56bb5b6cb70ade3d78f2eb79f0c047b1584a1f49532204e3632fd3d9"
      "ffeefc7666b783b8da0987105a45fed8cafb7665e4af8fec028a8fa4ce25d671f1e56811"
      "e562fb02fd7564158b32e831dfa198c078a76a118362caa47e17900d",
      "8e653e80faa96886099241408c3af5a1470e23d2d8194ac36f5e07e54e7409b275273ca1"
      "1975c6f5b84ec93797518fe448d623b92ee075bfc80be2e7337881ae"
      "0935bedd53b436c12ccabf9e92bf94caf71587d9aec242de604ade532a2fae5f56ae8403"
      "b9697917af631be433cbbe931bb6750b0a73e4d27669b7cd7b4fd0b8",
      "710dd66f8b15fe549640d1a9a160537618a62a362d0a05dced164ac56d9978afb5e0e502"
      "958ea30e67bc39cda58ad3f26ca4b645e2f3b3eabb3661be491bae5f"
      "f6e3bfbc73f3e43df3f58d79f282f15dbc5e4abc49dfeb660a6f3da14b8620f46c4cf74a"
      "555dbd20f4582a435508cfd1c8e0649d03a5f8f38a3f48d9ffd7fefb",
      "49f3cd25fc305f5fd19a70334b5e561f572db76342c87b9b9267a7f2e2fa5cefd3abe96f"
      "efdfe565f1bf7fa3d9f76f91b4aafbecf47ce7b1d1d907bddebfdf6b"
      "558e7e7efffe004ec8da7d",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 3120U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *epFieldName[7] = {
      "QualifiedName",    "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "ResolvedFilePath", "TimeStamp",      "Visible"};
  const char_T *propFieldName[7] = {
      "Version",      "ResolvedFunctions", "Checksum", "EntryPoints",
      "CoverageInfo", "IsPolymorphic",     "AuxData"};
  uint8_T v[216] = {
      0U,   1U,   73U,  77U,  0U,   0U,   0U,   0U,   14U,  0U,   0U,   0U,
      200U, 0U,   0U,   0U,   6U,   0U,   0U,   0U,   8U,   0U,   0U,   0U,
      2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,   5U,   0U,   0U,   0U,
      8U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,
      1U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,   5U,   0U,   4U,   0U,
      17U,  0U,   0U,   0U,   1U,   0U,   0U,   0U,   17U,  0U,   0U,   0U,
      67U,  108U, 97U,  115U, 115U, 69U,  110U, 116U, 114U, 121U, 80U,  111U,
      105U, 110U, 116U, 115U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      14U,  0U,   0U,   0U,   112U, 0U,   0U,   0U,   6U,   0U,   0U,   0U,
      8U,   0U,   0U,   0U,   2U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      5U,   0U,   0U,   0U,   8U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,
      0U,   0U,   0U,   0U,   1U,   0U,   0U,   0U,   0U,   0U,   0U,   0U,
      5U,   0U,   4U,   0U,   14U,  0U,   0U,   0U,   1U,   0U,   0U,   0U,
      56U,  0U,   0U,   0U,   81U,  117U, 97U,  108U, 105U, 102U, 105U, 101U,
      100U, 78U,  97U,  109U, 101U, 0U,   77U,  101U, 116U, 104U, 111U, 100U,
      115U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   80U,  114U, 111U, 112U,
      101U, 114U, 116U, 105U, 101U, 115U, 0U,   0U,   0U,   0U,   72U,  97U,
      110U, 100U, 108U, 101U, 0U,   0U,   0U,   0U,   0U,   0U,   0U,   0U};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("fDIC_xcf_mat"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString("D:\\RockShare\\Work\\Projects\\2025_Contiguity_"
                          "SECO\\Technical\\standalone-app-2.0\\mtex-trueEbsd-"
                          "2.0.0\\funcsV0\\fDIC_xcf_mat.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(740001.68361111113));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("25.1.0.2973910 (R2025a) Update 1"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("Nx6aTHZFISRLQ66317sWbE"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  emlrtSetField(xResult, 0, "AuxData",
                emlrtMxCreateRowVectorUINT8((const uint8_T *)&v, 216U));
  return xResult;
}

/* End of code generation (_coder_fDIC_xcf_mat_info.c) */
