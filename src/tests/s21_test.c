#ifndef _UNIT_TEST_ROUND_H_
#define _UNIT_TEST_ROUND_H_

#include "s21_test.h"

void s21_copy_matrix(double from[][3], matrix_t *A) {
  for (int i = 0; i < A->rows; ++i)
    for (int j = 0; j < A->columns; ++j) A->matrix[i][j] = from[i][j];
}

void s21_copy_matrix_4(double from[][4], matrix_t *A) {
  for (int i = 0; i < A->rows; ++i)
    for (int j = 0; j < A->columns; ++j) A->matrix[i][j] = from[i][j];
}

void s21_copy_matrix_6(double from[][7], matrix_t *A) {
  for (int i = 0; i < A->rows; ++i)
    for (int j = 0; j < A->columns; ++j) A->matrix[i][j] = from[i][j];
}

void run_test(Suite *test) {
  SRunner *sr = srunner_create(test);
  printf("\n");
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

int main() {
  run_test(s21_create_matrix_suite());
  run_test(s21_remove_matrix_suite());
  run_test(s21_eq_matrix_suite());
  run_test(s21_sum_matrix_suite());
  run_test(s21_sub_matrix_suite());
  run_test(s21_mult_number_suite());
  run_test(s21_mult_matrix_suite());
  run_test(s21_transpose_suite());
  run_test(s21_calc_complements_suite());
  run_test(s21_determinant_suite());
  run_test(s21_inverse_matrix_suite());
  run_test(testObjParser());
  run_test(testAffine());
}

#endif  //_UNIT_TEST_ROUND_H_