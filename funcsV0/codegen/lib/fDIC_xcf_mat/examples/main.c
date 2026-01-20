/*
 * Non-Degree Granting Education License -- for use at non-degree
 * granting, nonprofit, education, and research organizations only. Not
 * for commercial or industrial use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include files */
#include "main.h"
#include "fDIC_xcf_mat.h"
#include "fDIC_xcf_mat_emxAPI.h"
#include "fDIC_xcf_mat_initialize.h"
#include "fDIC_xcf_mat_terminate.h"
#include "fDIC_xcf_mat_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static void argInit_128x128_real_T(double result[16384]);

static void argInit_17x24_cell_wrap_0(cell_wrap_0 result[408]);

static void argInit_17x24_real_T(double result[408]);

static void argInit_1x2_real_T(double result[2]);

static void argInit_288x419_real_T(double result[120672]);

static void argInit_4x1_real_T(double result[4]);

static cell_wrap_0 argInit_cell_wrap_0(void);

static double argInit_real_T(void);

static void argInit_struct0_T(struct0_T *result);

/* Function Definitions */
static void argInit_128x128_real_T(double result[16384])
{
  int i;
  /* Loop over the array to initialize each element. */
  for (i = 0; i < 16384; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = argInit_real_T();
  }
}

static void argInit_17x24_cell_wrap_0(cell_wrap_0 result[408])
{
  int i;
  /* Loop over the array to initialize each element. */
  for (i = 0; i < 408; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = argInit_cell_wrap_0();
  }
}

static void argInit_17x24_real_T(double result[408])
{
  int i;
  /* Loop over the array to initialize each element. */
  for (i = 0; i < 408; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = argInit_real_T();
  }
}

static void argInit_1x2_real_T(double result[2])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static void argInit_288x419_real_T(double result[120672])
{
  int i;
  /* Loop over the array to initialize each element. */
  for (i = 0; i < 120672; i++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[i] = argInit_real_T();
  }
}

static void argInit_4x1_real_T(double result[4])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 4; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

static cell_wrap_0 argInit_cell_wrap_0(void)
{
  cell_wrap_0 result;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_1x2_real_T(result.f1);
  return result;
}

static double argInit_real_T(void)
{
  return 0.0;
}

static void argInit_struct0_T(struct0_T *result)
{
  double result_tmp;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_17x24_real_T(result->position_X_pass_1);
  result_tmp = argInit_real_T();
  result->size_pass_1 = result_tmp;
  result->num_x_pass_1 = result_tmp;
  result->num_y_pass_1 = result_tmp;
  argInit_17x24_cell_wrap_0(result->coordinator_pass_1);
  result->num_pass_1 = result_tmp;
  memcpy(&result->position_Y_pass_1[0], &result->position_X_pass_1[0],
         408U * sizeof(double));
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* Initialize the application.
You do not need to do this more than one time. */
  fDIC_xcf_mat_initialize();
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_fDIC_xcf_mat();
  /* Terminate the application.
You do not need to do this more than one time. */
  fDIC_xcf_mat_terminate();
  return 0;
}

void main_fDIC_xcf_mat(void)
{
  static double Image_ref_tmp[120672];
  static double hfilter_tmp[16384];
  emxArray_real_T *CCmax;
  struct0_T r;
  double Shift_X[408];
  double Shift_Y[408];
  double dv[4];
  /* Initialize function 'fDIC_xcf_mat' input arguments. */
  /* Initialize function input argument 'Image_ref'. */
  argInit_288x419_real_T(Image_ref_tmp);
  /* Initialize function input argument 'Image_test'. */
  /* Initialize function input argument 'ROI'. */
  /* Initialize function input argument 'Filters_setting'. */
  /* Initialize function input argument 'hfilter'. */
  argInit_128x128_real_T(hfilter_tmp);
  /* Initialize function input argument 'FFTfilter'. */
  /* Call the entry-point 'fDIC_xcf_mat'. */
  emxInitArray_real_T(&CCmax, 1);
  argInit_struct0_T(&r);
  argInit_4x1_real_T(dv);
  fDIC_xcf_mat(Image_ref_tmp, Image_ref_tmp, &r, dv, argInit_real_T(),
               hfilter_tmp, hfilter_tmp, Shift_X, Shift_Y, CCmax);
  emxDestroyArray_real_T(CCmax);
}

/* End of code generation (main.c) */
