#ifndef _UNIT_TEST_ROUND_H_
#define _UNIT_TEST_ROUND_H_

#include "s21_test.h"

START_TEST(s21_mult_matrix_by_null) {
  // printf("---------------------------------------------\n");

  int code = s21_mult_matrix(NULL, NULL, NULL);

  // bool is_ok = code == INCORR ? true : false;
  // printf("s21_mult_matrix_by_null: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, INCORR);
}

START_TEST(s21_mult_matrix_by_uneq_rows) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};

  s21_create_matrix(3, 3, &matrixA);
  s21_create_matrix(12, 3, &matrixB);

  int code = s21_mult_matrix(&matrixA, &matrixB, &matrixA);

  // bool is_ok = code == CALC_ERR ? true : false;
  // printf("s21_mult_matrix_by_uneq_rows: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, CALC_ERR);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}

START_TEST(s21_mult_matrix_1x3) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};
  matrix_t result, key;

  s21_create_matrix(1, 3, &matrixA);
  s21_create_matrix(3, 1, &matrixB);
  s21_create_matrix(1, 1, &key);

  double prompt1[][3] = {{1, 2, 3}};
  double prompt2[][3] = {{1}, {2}, {3}};
  s21_copy_matrix(prompt1, &matrixA);
  s21_copy_matrix(prompt2, &matrixB);

  double prompt_key[][3] = {{14}};
  s21_copy_matrix(prompt_key, &key);

  int code = s21_mult_matrix(&matrixA, &matrixB, &result);

  // bool is_ok =
  // code == OK && s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_mult_matrix_1x3: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  // s21_print_matrix(result);

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_3x1) {
  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};
  matrix_t result, key;

  s21_create_matrix(3, 1, &matrixA);
  s21_create_matrix(1, 3, &matrixB);
  s21_create_matrix(3, 3, &key);

  double prompt1[][3] = {{2}, {4}, {7.5}};
  double prompt2[][3] = {{2, 4, 7.5}};
  s21_copy_matrix(prompt1, &matrixA);
  s21_copy_matrix(prompt2, &matrixB);

  double prompt_key[][3] = {{4, 8, 15}, {8, 16, 30}, {15, 30, 56.25}};
  s21_copy_matrix(prompt_key, &key);

  int code = s21_mult_matrix(&matrixA, &matrixB, &result);

  // bool is_ok =
  // code == OK && s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_mult_matrix_3x1: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_2x2) {
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

  double prompt_key[][3] = {{7, 10}, {15, 22}, {}};
  s21_copy_matrix(prompt_key, &key);

  int code = s21_mult_matrix(&matrixA, &matrixB, &result);

  // bool is_ok =
  // code == OK && s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_mult_matrix_2x2: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  // s21_print_matrix(result);

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_4x4) {
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

  double prompt_key[][4] = {{52, 86.5, 121.25, 156.125},
                            {2.1875, 3.9375, 5.71875, 7.515625},
                            {520, 865, 1212.5, 1561.25},
                            {118, 199.5, 281.75, 364.375}};
  s21_copy_matrix_4(prompt_key, &key);

  int code = s21_mult_matrix(&matrixA, &matrixB, &result);

  // bool is_ok =
  // code == OK && s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_mult_matrix_4x4: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_mult_matrix_suite(void) {
  Suite *s = suite_create("mult_matrix\n");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_mult_matrix_by_null);
  tcase_add_test(tc_core, s21_mult_matrix_by_uneq_rows);
  tcase_add_test(tc_core, s21_mult_matrix_1x3);
  tcase_add_test(tc_core, s21_mult_matrix_3x1);
  tcase_add_test(tc_core, s21_mult_matrix_2x2);
  tcase_add_test(tc_core, s21_mult_matrix_4x4);

  suite_add_tcase(s, tc_core);
  return s;
}
#endif  //_UNIT_TEST_ROUND_H_