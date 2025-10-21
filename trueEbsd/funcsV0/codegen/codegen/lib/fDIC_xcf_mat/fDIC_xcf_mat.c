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
#include "FFTImplementationCallback.h"
#include "blockedSummation.h"
#include "colon.h"
#include "fDIC_xcf_mat_data.h"
#include "fDIC_xcf_mat_emxutil.h"
#include "fDIC_xcf_mat_initialize.h"
#include "fDIC_xcf_mat_rtwutil.h"
#include "fDIC_xcf_mat_types.h"
#include "fReg.h"
#include "rt_nonfinite.h"
#include "std.h"
#include "omp.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Declarations */
static void times(double in1[16384], const emxArray_real_T *in2,
                  const double in3[16384]);

/* Function Definitions */
static void times(double in1[16384], const emxArray_real_T *in2,
                  const double in3[16384])
{
  const double *in2_data;
  int aux_0_1;
  int i;
  int i1;
  int stride_0_0;
  int stride_0_1;
  in2_data = in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  for (i = 0; i < 128; i++) {
    for (i1 = 0; i1 < 128; i1++) {
      int i2;
      i2 = i1 + (i << 7);
      in1[i2] = in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] * in3[i2];
    }
    aux_0_1 += stride_0_1;
  }
}

void fDIC_xcf_mat(const double Image_ref[120672],
                  const double Image_test[120672], const struct0_T *ROI,
                  const double Filters_setting[4], double XCF_mesh,
                  const double hfilter[16384], const double FFTfilter[16384],
                  double Shift_X[408], double Shift_Y[408],
                  emxArray_real_T *CCmax)
{
  static const double dv[65] = {1.0,
                                0.99879545620517241,
                                0.99518472667219693,
                                0.989176509964781,
                                0.98078528040323043,
                                0.970031253194544,
                                0.95694033573220882,
                                0.94154406518302081,
                                0.92387953251128674,
                                0.90398929312344334,
                                0.881921264348355,
                                0.85772861000027212,
                                0.83146961230254524,
                                0.80320753148064494,
                                0.773010453362737,
                                0.74095112535495922,
                                0.70710678118654757,
                                0.67155895484701833,
                                0.63439328416364549,
                                0.59569930449243336,
                                0.55557023301960218,
                                0.51410274419322166,
                                0.47139673682599764,
                                0.42755509343028208,
                                0.38268343236508978,
                                0.33688985339222005,
                                0.29028467725446233,
                                0.24298017990326387,
                                0.19509032201612825,
                                0.14673047445536175,
                                0.0980171403295606,
                                0.049067674327418015,
                                0.0,
                                -0.049067674327418015,
                                -0.0980171403295606,
                                -0.14673047445536175,
                                -0.19509032201612825,
                                -0.24298017990326387,
                                -0.29028467725446233,
                                -0.33688985339222005,
                                -0.38268343236508978,
                                -0.42755509343028208,
                                -0.47139673682599764,
                                -0.51410274419322166,
                                -0.55557023301960218,
                                -0.59569930449243336,
                                -0.63439328416364549,
                                -0.67155895484701833,
                                -0.70710678118654757,
                                -0.74095112535495922,
                                -0.773010453362737,
                                -0.80320753148064494,
                                -0.83146961230254524,
                                -0.85772861000027212,
                                -0.881921264348355,
                                -0.90398929312344334,
                                -0.92387953251128674,
                                -0.94154406518302081,
                                -0.95694033573220882,
                                -0.970031253194544,
                                -0.98078528040323043,
                                -0.989176509964781,
                                -0.99518472667219693,
                                -0.99879545620517241,
                                -1.0};
  static const double dv1[65] = {0.0,
                                 -0.049067674327418015,
                                 -0.0980171403295606,
                                 -0.14673047445536175,
                                 -0.19509032201612825,
                                 -0.24298017990326387,
                                 -0.29028467725446233,
                                 -0.33688985339222005,
                                 -0.38268343236508978,
                                 -0.42755509343028208,
                                 -0.47139673682599764,
                                 -0.51410274419322166,
                                 -0.55557023301960218,
                                 -0.59569930449243336,
                                 -0.63439328416364549,
                                 -0.67155895484701833,
                                 -0.70710678118654757,
                                 -0.74095112535495922,
                                 -0.773010453362737,
                                 -0.80320753148064494,
                                 -0.83146961230254524,
                                 -0.85772861000027212,
                                 -0.881921264348355,
                                 -0.90398929312344334,
                                 -0.92387953251128674,
                                 -0.94154406518302081,
                                 -0.95694033573220882,
                                 -0.970031253194544,
                                 -0.98078528040323043,
                                 -0.989176509964781,
                                 -0.99518472667219693,
                                 -0.99879545620517241,
                                 -1.0,
                                 -0.99879545620517241,
                                 -0.99518472667219693,
                                 -0.989176509964781,
                                 -0.98078528040323043,
                                 -0.970031253194544,
                                 -0.95694033573220882,
                                 -0.94154406518302081,
                                 -0.92387953251128674,
                                 -0.90398929312344334,
                                 -0.881921264348355,
                                 -0.85772861000027212,
                                 -0.83146961230254524,
                                 -0.80320753148064494,
                                 -0.773010453362737,
                                 -0.74095112535495922,
                                 -0.70710678118654757,
                                 -0.67155895484701833,
                                 -0.63439328416364549,
                                 -0.59569930449243336,
                                 -0.55557023301960218,
                                 -0.51410274419322166,
                                 -0.47139673682599764,
                                 -0.42755509343028208,
                                 -0.38268343236508978,
                                 -0.33688985339222005,
                                 -0.29028467725446233,
                                 -0.24298017990326387,
                                 -0.19509032201612825,
                                 -0.14673047445536175,
                                 -0.0980171403295606,
                                 -0.049067674327418015,
                                 -0.0};
  __m128d r2;
  emxArray_creal_T *ROI_ref;
  emxArray_creal_T *ROI_test;
  emxArray_int32_T *r1;
  emxArray_real_T c_ROI_test_1;
  emxArray_real_T *ROI_test_1;
  emxArray_real_T *Shift_X_temp;
  emxArray_real_T *Shift_Y_temp;
  emxArray_real_T *b_data_fill;
  emxArray_real_T *b_y;
  emxArray_real_T *data_fill;
  emxArray_real_T *y;
  fDIC_xcf_matTLS *fDIC_xcf_matTLSThread;
  creal_T *ROI_ref_data;
  double b_ROI_test_1[16384];
  double dv2[2];
  double a;
  double c_y;
  double d;
  double d1;
  double d2;
  double d3;
  double x;
  double *CCmax_data;
  double *ROI_test_1_data;
  double *Shift_X_temp_data;
  double *Shift_Y_temp_data;
  double *b_y_data;
  double *data_fill_data;
  double *y_data;
  int b_loop_ub;
  int b_y_tmp;
  int c_loop_ub;
  int c_y_tmp;
  int d_loop_ub;
  int d_y_tmp;
  int e_y_tmp;
  int f_y_tmp;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int j;
  int loop_ub;
  int ub_loop;
  int vectorUB;
  int y_tmp;
  int *r;
  if (!isInitialized_fDIC_xcf_mat) {
    fDIC_xcf_mat_initialize();
  }
  fDIC_xcf_matTLSThread = emlrtGetThreadStackData();
  /*  cross correlation is performed and shift X, shift Y and peak height are */
  /*  determined. */
  /*  Image_size = size(Image_ref); */
  emxInit_real_T(&Shift_X_temp, 1);
  loop_ub = (int)ROI->num_pass_1;
  ub_loop = Shift_X_temp->size[0];
  Shift_X_temp->size[0] = (int)ROI->num_pass_1;
  emxEnsureCapacity_real_T(Shift_X_temp, ub_loop);
  Shift_X_temp_data = Shift_X_temp->data;
  for (i = 0; i < loop_ub; i++) {
    Shift_X_temp_data[i] = 0.0;
  }
  emxInit_real_T(&Shift_Y_temp, 1);
  ub_loop = Shift_Y_temp->size[0];
  Shift_Y_temp->size[0] = (int)ROI->num_pass_1;
  emxEnsureCapacity_real_T(Shift_Y_temp, ub_loop);
  Shift_Y_temp_data = Shift_Y_temp->data;
  for (i = 0; i < loop_ub; i++) {
    Shift_Y_temp_data[i] = 0.0;
  }
  ub_loop = CCmax->size[0];
  CCmax->size[0] = (int)ROI->num_pass_1;
  emxEnsureCapacity_real_T(CCmax, ub_loop);
  CCmax_data = CCmax->data;
  for (i = 0; i < loop_ub; i++) {
    CCmax_data[i] = 0.0;
  }
  ub_loop = (int)ROI->num_pass_1;
#pragma omp parallel num_threads(omp_get_max_threads()) private(               \
        fDIC_xcf_matTLSThread, ROI_test_1_data, data_fill_data, ROI_ref_data,  \
            y_data, b_y_data, r, r1, y, b_y, data_fill, b_data_fill, ROI_ref,  \
            ROI_test_1, ROI_test, c_y, a, x, b_ROI_test_1, d, d1, i1, y_tmp,   \
            d2, d3, i2, b_y_tmp, b_loop_ub, c_loop_ub, i3, i4, c_ROI_test_1,   \
            vectorUB, r2, d_loop_ub, dv2)                                      \
    firstprivate(c_y_tmp, d_y_tmp, e_y_tmp, f_y_tmp)
  {
    fDIC_xcf_matTLSThread = emlrtGetThreadStackData();
    emxInit_int32_T(&r1, 1);
    emxInit_real_T(&y, 2);
    b_y_data = y->data;
    emxInit_real_T(&b_y, 2);
    y_data = b_y->data;
    emxInit_real_T(&data_fill, 2);
    emxInit_real_T(&b_data_fill, 1);
    emxInit_creal_T(&ROI_ref, 2);
    emxInit_real_T(&ROI_test_1, 2);
    emxInit_creal_T(&ROI_test, 2);
#pragma omp for nowait
    for (j = 0; j < ub_loop; j++) {
      x = ROI->size_pass_1 / 2.0;
      if (fabs(x) < 4.503599627370496E+15) {
        if (x >= 0.5) {
          x = floor(x + 0.5);
        } else if (x > -0.5) {
          x *= 0.0;
        } else {
          x = ceil(x - 0.5);
        }
      }
      c_y = ROI->coordinator_pass_1[j].f1[1];
      d = c_y - x;
      d1 = (c_y + x) - 1.0;
      if (d > d1) {
        i1 = 0;
        y_tmp = 0;
      } else {
        i1 = (int)d - 1;
        y_tmp = (int)d1;
      }
      c_y = ROI->coordinator_pass_1[j].f1[0];
      d2 = c_y - x;
      d3 = (c_y + x) - 1.0;
      if (d2 > d3) {
        i2 = 0;
        b_y_tmp = 0;
      } else {
        i2 = (int)d2 - 1;
        b_y_tmp = (int)d3;
      }
      b_loop_ub = y_tmp - i1;
      y_tmp = ROI_test_1->size[0] * ROI_test_1->size[1];
      ROI_test_1->size[0] = b_loop_ub;
      c_loop_ub = b_y_tmp - i2;
      ROI_test_1->size[1] = c_loop_ub;
      emxEnsureCapacity_real_T(ROI_test_1, y_tmp);
      ROI_test_1_data = ROI_test_1->data;
      for (i3 = 0; i3 < c_loop_ub; i3++) {
        for (i4 = 0; i4 < b_loop_ub; i4++) {
          ROI_test_1_data[i4 + ROI_test_1->size[0] * i3] =
              Image_ref[(i1 + i4) + 288 * (i2 + i3)];
        }
      }
      /*  zero mean and normalise standard deviation */
      y_tmp = b_loop_ub * c_loop_ub;
      c_ROI_test_1 = *ROI_test_1;
      c_y_tmp = y_tmp;
      c_ROI_test_1.size = &c_y_tmp;
      c_ROI_test_1.numDimensions = 1;
      c_y = blockedSummation(&c_ROI_test_1, y_tmp) / (double)y_tmp;
      c_ROI_test_1 = *ROI_test_1;
      d_y_tmp = y_tmp;
      c_ROI_test_1.size = &d_y_tmp;
      c_ROI_test_1.numDimensions = 1;
      a = b_std(&c_ROI_test_1);
      b_y_tmp = ROI_test_1->size[0] * ROI_test_1->size[1];
      ROI_test_1->size[0] = b_loop_ub;
      ROI_test_1->size[1] = c_loop_ub;
      emxEnsureCapacity_real_T(ROI_test_1, b_y_tmp);
      ROI_test_1_data = ROI_test_1->data;
      for (i3 = 0; i3 < c_loop_ub; i3++) {
        y_tmp = (b_loop_ub / 2) << 1;
        vectorUB = y_tmp - 2;
        for (i4 = 0; i4 <= vectorUB; i4 += 2) {
          _mm_storeu_pd(
              &ROI_test_1_data[i4 + ROI_test_1->size[0] * i3],
              _mm_div_pd(
                  _mm_sub_pd(
                      _mm_loadu_pd(&Image_ref[(i1 + i4) + 288 * (i2 + i3)]),
                      _mm_set1_pd(c_y)),
                  _mm_set1_pd(a)));
        }
        for (i4 = y_tmp; i4 < b_loop_ub; i4++) {
          ROI_test_1_data[i4 + ROI_test_1->size[0] * i3] =
              (Image_ref[(i1 + i4) + 288 * (i2 + i3)] - c_y) / a;
        }
      }
      if ((ROI_test_1->size[0] == 128) && (ROI_test_1->size[1] == 128)) {
        for (i3 = 0; i3 <= 16382; i3 += 2) {
          r2 = _mm_loadu_pd(&ROI_test_1_data[i3]);
          _mm_storeu_pd(&b_ROI_test_1[i3],
                        _mm_mul_pd(r2, _mm_loadu_pd(&hfilter[i3])));
        }
      } else {
        times(b_ROI_test_1, ROI_test_1, hfilter);
      }
      /*  han filtering */
      c_FFTImplementationCallback_r2b(b_ROI_test_1,
                                      fDIC_xcf_matTLSThread->f0.dcv);
      for (i3 = 0; i3 < 128; i3++) {
        for (i4 = 0; i4 < 128; i4++) {
          fDIC_xcf_matTLSThread->f0.ROI_test_1[i4 + (i3 << 7)] =
              fDIC_xcf_matTLSThread->f0.dcv[i3 + (i4 << 7)];
        }
      }
      d_FFTImplementationCallback_r2b(fDIC_xcf_matTLSThread->f0.ROI_test_1, dv,
                                      dv1, fDIC_xcf_matTLSThread->f0.dcv);
      for (i3 = 0; i3 < 128; i3++) {
        for (i4 = 0; i4 < 128; i4++) {
          fDIC_xcf_matTLSThread->f0.ROI_test_1[i4 + (i3 << 7)] =
              fDIC_xcf_matTLSThread->f0.dcv[i3 + (i4 << 7)];
        }
      }
      /*  2D fast fourier transform */
      c_y = Filters_setting[2] + Filters_setting[3];
      if (rtIsNaN(c_y)) {
        y_tmp = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = 1;
        emxEnsureCapacity_real_T(b_y, y_tmp);
        y_data = b_y->data;
        y_data[0] = rtNaN;
      } else if (c_y < 1.0) {
        b_y->size[0] = 1;
        b_y->size[1] = 0;
      } else {
        y_tmp = b_y->size[0] * b_y->size[1];
        b_y->size[0] = 1;
        b_y->size[1] = (int)(c_y - 1.0) + 1;
        emxEnsureCapacity_real_T(b_y, y_tmp);
        y_data = b_y->data;
        y_tmp = (int)(c_y - 1.0);
        b_y_tmp = (((int)(c_y - 1.0) + 1) / 2) << 1;
        vectorUB = b_y_tmp - 2;
        for (i3 = 0; i3 <= vectorUB; i3 += 2) {
          dv2[0] = i3;
          dv2[1] = i3 + 1;
          r2 = _mm_loadu_pd(&dv2[0]);
          _mm_storeu_pd(&y_data[i3], _mm_add_pd(_mm_set1_pd(1.0), r2));
        }
        for (i3 = b_y_tmp; i3 <= y_tmp; i3++) {
          y_data[i3] = (double)i3 + 1.0;
        }
      }
      a = ROI->size_pass_1 - (c_y - 1.0);
      if (rtIsNaN(a) || rtIsNaN(ROI->size_pass_1)) {
        y_tmp = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, y_tmp);
        b_y_data = y->data;
        b_y_data[0] = rtNaN;
      } else if (ROI->size_pass_1 < a) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((rtIsInf(a) || rtIsInf(ROI->size_pass_1)) &&
                 (a == ROI->size_pass_1)) {
        y_tmp = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, y_tmp);
        b_y_data = y->data;
        b_y_data[0] = rtNaN;
      } else if (floor(a) == a) {
        y_tmp = y->size[0] * y->size[1];
        y->size[0] = 1;
        vectorUB = (int)(ROI->size_pass_1 - a);
        y->size[1] = vectorUB + 1;
        emxEnsureCapacity_real_T(y, y_tmp);
        b_y_data = y->data;
        y_tmp = ((vectorUB + 1) / 2) << 1;
        b_y_tmp = y_tmp - 2;
        for (i3 = 0; i3 <= b_y_tmp; i3 += 2) {
          dv2[0] = i3;
          dv2[1] = i3 + 1;
          r2 = _mm_loadu_pd(&dv2[0]);
          _mm_storeu_pd(&b_y_data[i3], _mm_add_pd(_mm_set1_pd(a), r2));
        }
        for (i3 = y_tmp; i3 <= vectorUB; i3++) {
          b_y_data[i3] = a + (double)i3;
        }
      } else {
        eml_float_colon(a, ROI->size_pass_1, y);
        b_y_data = y->data;
      }
      y_tmp = data_fill->size[0] * data_fill->size[1];
      data_fill->size[0] = 1;
      d_loop_ub = b_y->size[1] + y->size[1];
      data_fill->size[1] = d_loop_ub;
      emxEnsureCapacity_real_T(data_fill, y_tmp);
      ROI_test_1_data = data_fill->data;
      y_tmp = b_y->size[1];
      for (i3 = 0; i3 < y_tmp; i3++) {
        ROI_test_1_data[i3] = y_data[i3];
      }
      y_tmp = y->size[1];
      for (i3 = 0; i3 < y_tmp; i3++) {
        ROI_test_1_data[i3 + b_y->size[1]] = b_y_data[i3];
      }
      y_tmp = b_data_fill->size[0];
      b_data_fill->size[0] = d_loop_ub;
      emxEnsureCapacity_real_T(b_data_fill, y_tmp);
      data_fill_data = b_data_fill->data;
      for (i3 = 0; i3 < d_loop_ub; i3++) {
        data_fill_data[i3] = ROI_test_1_data[i3];
      }
      y_tmp = r1->size[0];
      r1->size[0] = d_loop_ub;
      emxEnsureCapacity_int32_T(r1, y_tmp);
      r = r1->data;
      for (i3 = 0; i3 < d_loop_ub; i3++) {
        r[i3] = (int)data_fill_data[i3];
      }
      y_tmp = ROI_ref->size[0] * ROI_ref->size[1];
      ROI_ref->size[0] = d_loop_ub;
      ROI_ref->size[1] = d_loop_ub;
      emxEnsureCapacity_creal_T(ROI_ref, y_tmp);
      ROI_ref_data = ROI_ref->data;
      for (i3 = 0; i3 < d_loop_ub; i3++) {
        for (i4 = 0; i4 < d_loop_ub; i4++) {
          y_tmp = (r[i3] - 1) << 7;
          x = FFTfilter[((int)data_fill_data[i4] + y_tmp) - 1];
          y_tmp = (r[i4] + y_tmp) - 1;
          ROI_ref_data[i4 + ROI_ref->size[0] * i3].re =
              x * fDIC_xcf_matTLSThread->f0.ROI_test_1[y_tmp].re;
          ROI_ref_data[i4 + ROI_ref->size[0] * i3].im =
              x * fDIC_xcf_matTLSThread->f0.ROI_test_1[y_tmp].im;
        }
      }
      /*  apply high and low frequence filter */
      if (d > d1) {
        i1 = 0;
        b_y_tmp = 0;
      } else {
        i1 = (int)d - 1;
        b_y_tmp = (int)d1;
      }
      if (d2 > d3) {
        i2 = 0;
        y_tmp = 0;
      } else {
        i2 = (int)d2 - 1;
        y_tmp = (int)d3;
      }
      b_loop_ub = b_y_tmp - i1;
      vectorUB = ROI_test_1->size[0] * ROI_test_1->size[1];
      ROI_test_1->size[0] = b_loop_ub;
      c_loop_ub = y_tmp - i2;
      ROI_test_1->size[1] = c_loop_ub;
      emxEnsureCapacity_real_T(ROI_test_1, vectorUB);
      ROI_test_1_data = ROI_test_1->data;
      for (i3 = 0; i3 < c_loop_ub; i3++) {
        for (i4 = 0; i4 < b_loop_ub; i4++) {
          ROI_test_1_data[i4 + ROI_test_1->size[0] * i3] =
              Image_test[(i1 + i4) + 288 * (i2 + i3)];
        }
      }
      /*  zero mean and normalise standard deviation */
      b_y_tmp = b_loop_ub * c_loop_ub;
      c_ROI_test_1 = *ROI_test_1;
      e_y_tmp = b_y_tmp;
      c_ROI_test_1.size = &e_y_tmp;
      c_ROI_test_1.numDimensions = 1;
      c_y = blockedSummation(&c_ROI_test_1, b_y_tmp) / (double)b_y_tmp;
      c_ROI_test_1 = *ROI_test_1;
      f_y_tmp = b_y_tmp;
      c_ROI_test_1.size = &f_y_tmp;
      c_ROI_test_1.numDimensions = 1;
      a = b_std(&c_ROI_test_1);
      y_tmp = ROI_test_1->size[0] * ROI_test_1->size[1];
      ROI_test_1->size[0] = b_loop_ub;
      ROI_test_1->size[1] = c_loop_ub;
      emxEnsureCapacity_real_T(ROI_test_1, y_tmp);
      ROI_test_1_data = ROI_test_1->data;
      for (i3 = 0; i3 < c_loop_ub; i3++) {
        y_tmp = (b_loop_ub / 2) << 1;
        b_y_tmp = y_tmp - 2;
        for (i4 = 0; i4 <= b_y_tmp; i4 += 2) {
          _mm_storeu_pd(
              &ROI_test_1_data[i4 + ROI_test_1->size[0] * i3],
              _mm_div_pd(
                  _mm_sub_pd(
                      _mm_loadu_pd(&Image_test[(i1 + i4) + 288 * (i2 + i3)]),
                      _mm_set1_pd(c_y)),
                  _mm_set1_pd(a)));
        }
        for (i4 = y_tmp; i4 < b_loop_ub; i4++) {
          ROI_test_1_data[i4 + ROI_test_1->size[0] * i3] =
              (Image_test[(i1 + i4) + 288 * (i2 + i3)] - c_y) / a;
        }
      }
      if ((ROI_test_1->size[0] == 128) && (ROI_test_1->size[1] == 128)) {
        for (i3 = 0; i3 <= 16382; i3 += 2) {
          r2 = _mm_loadu_pd(&ROI_test_1_data[i3]);
          _mm_storeu_pd(&b_ROI_test_1[i3],
                        _mm_mul_pd(r2, _mm_loadu_pd(&hfilter[i3])));
        }
      } else {
        times(b_ROI_test_1, ROI_test_1, hfilter);
      }
      /*  han filtering */
      c_FFTImplementationCallback_r2b(b_ROI_test_1,
                                      fDIC_xcf_matTLSThread->f0.dcv);
      for (i3 = 0; i3 < 128; i3++) {
        for (i4 = 0; i4 < 128; i4++) {
          fDIC_xcf_matTLSThread->f0.ROI_test_1[i4 + (i3 << 7)] =
              fDIC_xcf_matTLSThread->f0.dcv[i3 + (i4 << 7)];
        }
      }
      d_FFTImplementationCallback_r2b(fDIC_xcf_matTLSThread->f0.ROI_test_1, dv,
                                      dv1, fDIC_xcf_matTLSThread->f0.dcv);
      for (i3 = 0; i3 < 128; i3++) {
        for (i4 = 0; i4 < 128; i4++) {
          fDIC_xcf_matTLSThread->f0.ROI_test_1[i4 + (i3 << 7)] =
              fDIC_xcf_matTLSThread->f0.dcv[i3 + (i4 << 7)];
        }
      }
      /*  2D fast fourier transform */
      y_tmp = ROI_test->size[0] * ROI_test->size[1];
      ROI_test->size[0] = d_loop_ub;
      ROI_test->size[1] = d_loop_ub;
      emxEnsureCapacity_creal_T(ROI_test, y_tmp);
      ROI_ref_data = ROI_test->data;
      for (i3 = 0; i3 < d_loop_ub; i3++) {
        for (i4 = 0; i4 < d_loop_ub; i4++) {
          y_tmp = (r[i4] + ((r[i3] - 1) << 7)) - 1;
          c_y = FFTfilter[y_tmp];
          ROI_ref_data[i4 + ROI_test->size[0] * i3].re =
              c_y * fDIC_xcf_matTLSThread->f0.ROI_test_1[y_tmp].re;
          ROI_ref_data[i4 + ROI_test->size[0] * i3].im =
              c_y * fDIC_xcf_matTLSThread->f0.ROI_test_1[y_tmp].im;
        }
      }
      x = fReg(ROI_ref, ROI_test, ROI->size_pass_1, XCF_mesh, b_data_fill, &a,
               &c_y);
      Shift_X_temp_data[j] = x;
      Shift_Y_temp_data[j] = a;
      CCmax_data[j] = c_y;
    }
    emxFree_creal_T(&ROI_test);
    emxFree_real_T(&ROI_test_1);
    emxFree_creal_T(&ROI_ref);
    emxFree_real_T(&b_data_fill);
    emxFree_real_T(&data_fill);
    emxFree_real_T(&b_y);
    emxFree_real_T(&y);
    emxFree_int32_T(&r1);
  }
  for (i = 0; i < 408; i++) {
    Shift_X[i] = Shift_X_temp_data[i];
    Shift_Y[i] = Shift_Y_temp_data[i];
  }
  emxFree_real_T(&Shift_Y_temp);
  emxFree_real_T(&Shift_X_temp);
}

/* End of code generation (fDIC_xcf_mat.c) */
