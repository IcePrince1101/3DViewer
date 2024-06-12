#ifndef _UNIT_TEST_ROUND_H_
#define _UNIT_TEST_ROUND_H_

#include "s21_test.h"

START_TEST(s21_sum_matrix_by_null) {
  // printf("---------------------------------------------\n");

  int code = s21_sum_matrix(NULL, NULL, NULL);

  // bool is_ok = code == INCORR ? true : false;
  // printf("s21_sum_matrix_by_null: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, INCORR);
}

START_TEST(s21_sum_matrix_by_uneq_rows) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};

  s21_create_matrix(3, 3, &matrixA);
  s21_create_matrix(12, 3, &matrixB);

  int code = s21_sum_matrix(&matrixA, &matrixB, &matrixA);

  // bool is_ok = code == CALC_ERR ? true : false;
  // printf("s21_sum_matrix_by_uneq_rows: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, CALC_ERR);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}

START_TEST(s21_sum_matrix_1x3) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};
  matrix_t result, key;

  s21_create_matrix(1, 3, &matrixA);
  s21_create_matrix(1, 3, &matrixB);
  s21_create_matrix(1, 3, &key);

  double prompt[][3] = {{1, 2, 3}};
  s21_copy_matrix(prompt, &matrixA);
  s21_copy_matrix(prompt, &matrixB);

  double prompt_key[][3] = {{2, 4, 6}};
  s21_copy_matrix(prompt_key, &key);

  int code = s21_sum_matrix(&matrixA, &matrixB, &result);

  // bool is_ok =
  // code == OK && s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_sum_matrix_1x3: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_3x1) {
  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};
  matrix_t result, key;

  s21_create_matrix(3, 1, &matrixA);
  s21_create_matrix(3, 1, &matrixB);
  s21_create_matrix(3, 1, &key);

  double prompt[][3] = {{2}, {4}, {6.5}};
  s21_copy_matrix(prompt, &matrixA);
  s21_copy_matrix(prompt, &matrixB);

  double prompt_key[][3] = {{4}, {8}, {13}};
  s21_copy_matrix(prompt_key, &key);

  int code = s21_sum_matrix(&matrixA, &matrixB, &result);

  // bool is_ok =
  // code == OK && s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_sum_matrix_3x1: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_2x2) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};
  matrix_t result, key;

  s21_create_matrix(2, 2, &matrixA);
  s21_create_matrix(2, 2, &matrixB);
  s21_create_matrix(2, 2, &key);

  double prompt[][3] = {{1, 2}, {3, 4}, {}};
  s21_copy_matrix(prompt, &matrixA);
  s21_copy_matrix(prompt, &matrixB);

  double prompt_key[][3] = {{2, 4}, {6, 8}, {}};
  s21_copy_matrix(prompt_key, &key);

  int code = s21_sum_matrix(&matrixA, &matrixB, &result);

  // bool is_ok =
  // code == OK && s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_sum_matrix_2x2: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_4x4) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};
  matrix_t result, key;

  s21_create_matrix(4, 4, &matrixA);
  s21_create_matrix(4, 4, &matrixB);
  s21_create_matrix(4, 4, &key);

  double prompt[][4] = {
      {1, 2, 3, 4}, {0.5, 0.25, 0.125, 0.0625}, {10, 20, 30, 40}, {5, 6, 7, 8}};
  s21_copy_matrix_4(prompt, &matrixA);
  s21_copy_matrix_4(prompt, &matrixB);

  double prompt_key[][4] = {
      {2, 4, 6, 8}, {1, 0.5, 0.25, 0.125}, {20, 40, 60, 80}, {10, 12, 14, 16}};
  s21_copy_matrix_4(prompt_key, &key);

  int code = s21_sum_matrix(&matrixA, &matrixB, &result);

  // bool is_ok =
  // code == OK && s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_sum_matrix_4x4: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_sum_matrix_suite(void) {
  Suite *s = suite_create("sum_matrix\n");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_sum_matrix_by_null);
  tcase_add_test(tc_core, s21_sum_matrix_by_uneq_rows);
  tcase_add_test(tc_core, s21_sum_matrix_1x3);
  tcase_add_test(tc_core, s21_sum_matrix_3x1);
  tcase_add_test(tc_core, s21_sum_matrix_2x2);
  tcase_add_test(tc_core, s21_sum_matrix_4x4);

  suite_add_tcase(s, tc_core);
  return s;
}
#endif  //_UNIT_TEST_ROUND_H_