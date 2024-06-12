#ifndef _UNIT_TEST_ROUND_H_
#define _UNIT_TEST_ROUND_H_

#include "s21_test.h"

START_TEST(s21_sub_matrix_by_null) {
  // printf("---------------------------------------------\n");

  int code = s21_sub_matrix(NULL, NULL, NULL);

  // bool is_ok = code == INCORR ? true : false;
  // printf("s21_sub_matrix_by_null: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, INCORR);
}

START_TEST(s21_sub_matrix_by_uneq_rows) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};

  s21_create_matrix(3, 3, &matrixA);
  s21_create_matrix(12, 3, &matrixB);

  int code = s21_sub_matrix(&matrixA, &matrixB, &matrixA);

  // bool is_ok = code == CALC_ERR ? true : false;
  // printf("s21_sub_matrix_by_uneq_rows: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, CALC_ERR);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
}

START_TEST(s21_sub_matrix_1x3) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};
  matrix_t result, key;

  s21_create_matrix(1, 3, &matrixA);
  s21_create_matrix(1, 3, &matrixB);
  s21_create_matrix(1, 3, &key);

  double prompt1[][3] = {{0, -0.5, 3.5}};
  double prompt2[][3] = {{1, 2, 3}};
  s21_copy_matrix(prompt1, &matrixA);
  s21_copy_matrix(prompt2, &matrixB);

  double prompt_key[][3] = {{-1, -2.5, 0.5}};
  s21_copy_matrix(prompt_key, &key);

  int code = s21_sub_matrix(&matrixA, &matrixB, &result);

  // bool is_ok =
  //     code == OK && s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_sub_matrix_1x3: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_3x1) {
  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};
  matrix_t result, key;

  s21_create_matrix(3, 1, &matrixA);
  s21_create_matrix(3, 1, &matrixB);
  s21_create_matrix(3, 1, &key);

  double prompt1[][3] = {{2}, {4}, {6.5}};
  double prompt2[][3] = {{1}, {2}, {3}};
  s21_copy_matrix(prompt1, &matrixA);
  s21_copy_matrix(prompt2, &matrixB);

  double prompt_key[][3] = {{1}, {2}, {3.5}};
  s21_copy_matrix(prompt_key, &key);

  int code = s21_sub_matrix(&matrixA, &matrixB, &result);

  // bool is_ok =
  //     code == OK && s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_sub_matrix_3x1: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_2x2) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};
  matrix_t result, key;

  s21_create_matrix(2, 2, &matrixA);
  s21_create_matrix(2, 2, &matrixB);
  s21_create_matrix(2, 2, &key);

  double prompt1[][3] = {{1, 2}, {3, 4}, {}};
  double prompt2[][3] = {{10, 20}, {30, 40}, {}};

  s21_copy_matrix(prompt1, &matrixA);
  s21_copy_matrix(prompt2, &matrixB);

  double prompt_key[][3] = {{-9, -18}, {-27, -36}, {}};
  s21_copy_matrix(prompt_key, &key);

  int code = s21_sub_matrix(&matrixA, &matrixB, &result);

  // bool is_ok =
  //     code == OK && s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_sub_matrix_2x2: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_4x4) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t matrixB = {0, 0, 0};
  matrix_t result, key;

  s21_create_matrix(4, 4, &matrixA);
  s21_create_matrix(4, 4, &matrixB);
  s21_create_matrix(4, 4, &key);

  double prompt1[][4] = {
      {1, 2, 3, 4}, {0.5, 0.25, 0.125, 0.0625}, {10, 20, 30, 40}, {5, 6, 7, 8}};
  double prompt2[][4] = {{0.5, 1, 1.5, 2},
                         {0.25, 0.125, 0.0625, 0},
                         {5, 10, 15, 20},
                         {1, 2, 3, 4}};
  s21_copy_matrix_4(prompt1, &matrixA);
  s21_copy_matrix_4(prompt2, &matrixB);

  double prompt_key[][4] = {{0.5, 1, 1.5, 2},
                            {0.25, 0.125, 0.0625, 0.0625},
                            {5, 10, 15, 20},
                            {4, 4, 4, 4}};
  s21_copy_matrix_4(prompt_key, &key);

  int code = s21_sub_matrix(&matrixA, &matrixB, &result);

  // bool is_ok =
  //     code == OK && s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_sub_matrix_4x4: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&matrixB);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_sub_matrix_suite(void) {
  Suite *s = suite_create("sub_matrix\n");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_sub_matrix_by_null);
  tcase_add_test(tc_core, s21_sub_matrix_by_uneq_rows);
  tcase_add_test(tc_core, s21_sub_matrix_1x3);
  tcase_add_test(tc_core, s21_sub_matrix_3x1);
  tcase_add_test(tc_core, s21_sub_matrix_2x2);
  tcase_add_test(tc_core, s21_sub_matrix_4x4);

  suite_add_tcase(s, tc_core);
  return s;
}
#endif  //_UNIT_TEST_ROUND_H_