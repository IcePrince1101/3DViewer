#ifndef _UNIT_TEST_ROUND_H_
#define _UNIT_TEST_ROUND_H_

#include "s21_test.h"

START_TEST(s21_eq_matrix_by_null) {
  // printf("---------------------------------------------\n");

  int code = s21_eq_matrix(NULL, NULL);

  // bool is_ok = code == FAILURE ? true : false;
  // printf("s21_eq_matrix_by_null: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, FAILURE);
}

START_TEST(s21_eq_matrix_by_uneq_rows) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};

  s21_create_matrix(3, 3, &matrixA);
  s21_create_matrix(12, 3, &matrixB);

  int code = s21_eq_matrix(&matrixA, &matrixB);

  // bool is_ok = code == FAILURE ? true : false;
  // printf("s21_eq_matrix_by_uneq_rows: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, FAILURE);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}

START_TEST(s21_eq_matrix_equal) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};

  s21_create_matrix(3, 3, &matrixA);
  s21_create_matrix(3, 3, &matrixB);

  double prompt[][3] = {{1, 2, 3}, {4, 5, 6.123452232}, {7, 8, NAN}};
  s21_copy_matrix(prompt, &matrixA);
  s21_copy_matrix(prompt, &matrixB);

  int code = s21_eq_matrix(&matrixA, &matrixB);

  // bool is_ok = code == SUCCESS ? true : false;
  // printf("s21_eq_matrix_equal: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, SUCCESS);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

START_TEST(s21_eq_matrix_unequal) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};

  s21_create_matrix(3, 3, &matrixA);
  s21_create_matrix(3, 3, &matrixB);

  double prompt1[][3] = {{1, 2, 3}, {4, 5, 6.123452232}, {7, 8, NAN}};
  double prompt2[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, NAN}};

  s21_copy_matrix(prompt1, &matrixA);
  s21_copy_matrix(prompt2, &matrixB);

  int code = s21_eq_matrix(&matrixA, &matrixB);

  // bool is_ok = code == FAILURE ? true : false;
  // printf("s21_eq_matrix_equal: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, FAILURE);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}
END_TEST

Suite *s21_eq_matrix_suite(void) {
  Suite *s = suite_create("eq_matrix\n");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_eq_matrix_by_null);
  tcase_add_test(tc_core, s21_eq_matrix_by_uneq_rows);
  tcase_add_test(tc_core, s21_eq_matrix_equal);
  tcase_add_test(tc_core, s21_eq_matrix_unequal);

  suite_add_tcase(s, tc_core);
  return s;
}
#endif  //_UNIT_TEST_ROUND_H_