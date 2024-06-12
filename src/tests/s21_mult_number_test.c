#ifndef _UNIT_TEST_ROUND_H_
#define _UNIT_TEST_ROUND_H_

#include "s21_test.h"

START_TEST(s21_mult_number_by_null) {
  // printf("---------------------------------------------\n");

  int code = s21_mult_number(NULL, 0, NULL);

  // bool is_ok = code == INCORR ? true : false;
  // printf("s21_mult_number_by_null: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, INCORR);
}

START_TEST(s21_mult_number_1x3) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t result, key;

  s21_create_matrix(1, 3, &matrixA);
  s21_create_matrix(1, 3, &key);

  double prompt[][3] = {{1, 2, 3}};
  s21_copy_matrix(prompt, &matrixA);

  double prompt_key[][3] = {{10, 20, 30}};
  s21_copy_matrix(prompt_key, &key);

  int code = s21_mult_number(&matrixA, 10, &result);

  // bool is_ok =
  // code == OK && s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_mult_number_1x3: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_3x1) {
  matrix_t matrixA = {0, 0, 0};
  matrix_t result, key;

  s21_create_matrix(3, 1, &matrixA);
  s21_create_matrix(3, 1, &key);

  double prompt[][3] = {{1}, {10}, {100}};
  s21_copy_matrix(prompt, &matrixA);

  double prompt_key[][3] = {{0.01}, {0.1}, {1}};
  s21_copy_matrix(prompt_key, &key);

  int code = s21_mult_number(&matrixA, 0.01, &result);

  // bool is_ok =
  // code == OK && s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_mult_number_3x1: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_4x4) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};
  matrix_t result, key;

  s21_create_matrix(4, 4, &matrixA);
  s21_create_matrix(4, 4, &key);

  double prompt[][4] = {
      {1, 2, 3, 4}, {0.5, 0.25, 0.125, 0.0625}, {10, 20, 30, 40}, {5, 6, 7, 8}};
  s21_copy_matrix_4(prompt, &matrixA);

  double prompt_key[][4] = {{0.1, 0.2, 0.3, 0.4},
                            {0.05, 0.025, 0.0125, 0.00625},
                            {1, 2, 3, 4},
                            {0.5, 0.6, 0.7, 0.8}};
  s21_copy_matrix_4(prompt_key, &key);

  int code = s21_mult_number(&matrixA, 0.1, &result);

  // bool is_ok =
  // code == OK && s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_mult_number_4x4: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_mult_number_suite(void) {
  Suite *s = suite_create("mult_number\n");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_mult_number_by_null);
  tcase_add_test(tc_core, s21_mult_number_1x3);
  tcase_add_test(tc_core, s21_mult_number_3x1);
  tcase_add_test(tc_core, s21_mult_number_4x4);

  suite_add_tcase(s, tc_core);
  return s;
}
#endif  //_UNIT_TEST_ROUND_H_