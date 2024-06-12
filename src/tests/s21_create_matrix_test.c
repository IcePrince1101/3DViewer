#ifndef _UNIT_TEST_ROUND_H_
#define _UNIT_TEST_ROUND_H_

#include "s21_test.h"

START_TEST(s21_create_matrix_by_zero) {
  // printf("---------------------------------------------\n");

  matrix_t matrix = {0, 0, 0};
  int code = s21_create_matrix(0, 1, &matrix);

  // bool is_ok = code == INCORR ? true : false;
  // printf("s21_create_matrix_by_zero: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, INCORR);

  s21_remove_matrix(&matrix);
}

START_TEST(s21_create_matrix_by_minus_num) {
  // printf("---------------------------------------------\n");

  matrix_t matrix = {0, 0, 0};
  int code = s21_create_matrix(1, -1, &matrix);

  // bool is_ok = code == INCORR ? true : false;
  // printf("s21_create_matrix_by_minus_num: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, INCORR);

  s21_remove_matrix(&matrix);
}

START_TEST(s21_create_matrix_by_one) {
  // printf("---------------------------------------------\n");

  matrix_t matrix = {0, 0, 0};
  int code = s21_create_matrix(1, 1, &matrix);

  // bool is_ok = code == OK && (matrix.rows == matrix.columns &&
  // (fabs(matrix.matrix[0][0]) < ACCURACY)) ? true: false;
  // printf("s21_create_matrix_by_one: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);
  ck_assert_int_eq(matrix.rows, matrix.columns);
  ck_assert_double_eq_tol(matrix.matrix[0][0], 0, ACCURACY);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_by_number) {
  // printf("---------------------------------------------\n");

  matrix_t matrix = {0, 0, 0};
  int code = s21_create_matrix(3, 4, &matrix);

  // bool is_ok =
  // code == OK && (matrix.rows == 3 && matrix.columns == 4 && matrix.matrix) ?
  // true : false; printf("s21_create_matrix_by_number: "); printf(is_ok ?
  // "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);
  ck_assert_int_eq(matrix.rows, 3);
  ck_assert_int_eq(matrix.columns, 4);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_by_null_result) {
  // printf("---------------------------------------------\n");

  int code = s21_create_matrix(3, 3, NULL);

  // bool is_ok = code == INCORR ? true : false;
  // printf("s21_create_matrix_by_null_result: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, INCORR);
}
END_TEST

Suite *s21_create_matrix_suite(void) {
  Suite *s = suite_create("create_matrix\n");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_create_matrix_by_zero);
  tcase_add_test(tc_core, s21_create_matrix_by_minus_num);
  tcase_add_test(tc_core, s21_create_matrix_by_one);
  tcase_add_test(tc_core, s21_create_matrix_by_number);
  tcase_add_test(tc_core, s21_create_matrix_by_null_result);

  suite_add_tcase(s, tc_core);
  return s;
}
#endif  //_UNIT_TEST_ROUND_H_