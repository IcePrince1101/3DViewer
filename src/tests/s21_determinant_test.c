#ifndef _UNIT_TEST_ROUND_H_
#define _UNIT_TEST_ROUND_H_

#include "s21_test.h"

START_TEST(s21_determinant_by_null) {
  // printf("---------------------------------------------\n");

  int code = s21_determinant(NULL, NULL);

  // bool is_ok = code == INCORR ? true : false;
  // printf("s21_determinant_by_null: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, INCORR);
}
END_TEST

START_TEST(s21_determinant_incorr_index) {
  // printf("---------------------------------------------\n");

  matrix_t A = {0};
  double p = 0;
  s21_create_matrix(1, 3, &A);
  int code = s21_determinant(&A, &p);

  // bool is_ok = code == CALC_ERR ? true : false;
  // printf("s21_determinant_incorr_index: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, CALC_ERR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_2x2) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  double result, key;
  key = 2;

  s21_create_matrix(2, 2, &matrixA);

  double prompt[][3] = {{1, -2}, {3, -4}, {}};
  s21_copy_matrix(prompt, &matrixA);

  int code = s21_determinant(&matrixA, &result);

  // bool is_ok = code == OK && fabs(result - key) < ACCURACY ? true : false;
  // printf("s21_determinant_2x2: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");
  ck_assert_int_eq(code, OK);
  ck_assert_double_eq_tol(result, key, ACCURACY);

  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(s21_determinant_4x4) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  double result, key;
  key = 38;

  s21_create_matrix(4, 4, &matrixA);

  double prompt[][4] = {
      {0, 1, 2, 3}, {1, 4, 10, 20}, {2, 5, 9, 12}, {3, 10, 14, 16}};
  s21_copy_matrix_4(prompt, &matrixA);

  int code = s21_determinant(&matrixA, &result);

  // bool is_ok = code == OK && fabs(result - key) < ACCURACY ? true : false;
  // printf("s21_determinant_4x4: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");
  ck_assert_double_eq_tol(result, key, ACCURACY);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
}
END_TEST

Suite *s21_determinant_suite(void) {
  Suite *s = suite_create("determinant\n");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_determinant_by_null);
  tcase_add_test(tc_core, s21_determinant_incorr_index);
  tcase_add_test(tc_core, s21_determinant_2x2);
  tcase_add_test(tc_core, s21_determinant_4x4);

  suite_add_tcase(s, tc_core);
  return s;
}
#endif  //_UNIT_TEST_ROUND_H_