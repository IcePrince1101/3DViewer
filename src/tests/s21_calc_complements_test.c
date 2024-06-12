#ifndef _UNIT_TEST_ROUND_H_
#define _UNIT_TEST_ROUND_H_

#include "s21_test.h"

START_TEST(s21_calc_complements_by_null) {
  // printf("---------------------------------------------\n");

  int code = s21_calc_complements(NULL, NULL);

  // bool is_ok = code == INCORR ? true : false;
  // printf("s21_calc_complements_by_null: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, INCORR);
}
END_TEST

START_TEST(s21_calc_complements_incorr_index) {
  // printf("---------------------------------------------\n");

  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  int code = s21_calc_complements(&A, NULL);

  // bool is_ok = code == INCORR ? true : false;
  // printf("s21_calc_complements_incorr_index: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, INCORR);

  s21_remove_matrix(&A);
}

START_TEST(s21_calc_complements_1x3) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t result;

  s21_create_matrix(1, 3, &matrixA);

  double prompt[][3] = {{1, 2, 3}};
  s21_copy_matrix(prompt, &matrixA);

  int code = s21_calc_complements(&matrixA, &result);

  // bool is_ok = code == CALC_ERR ? true : false;
  // printf("s21_calc_complements_1x3: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, CALC_ERR);

  s21_remove_matrix(&matrixA);
}
END_TEST

START_TEST(s21_calc_complements_2x2) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t result, key;

  s21_create_matrix(2, 2, &matrixA);
  s21_create_matrix(2, 2, &key);

  double prompt[][3] = {{1, -2}, {3, -4}, {}};
  s21_copy_matrix(prompt, &matrixA);

  double prompt_key[][3] = {{-4, -3}, {2, 1}, {}};
  s21_copy_matrix(prompt_key, &key);

  int code = s21_calc_complements(&matrixA, &result);

  // bool is_ok =
  // code == OK &&s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_calc_complements_2x2: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_4x4) {
  // printf("---------------------------------------------\n");

  matrix_t matrixA = {0, 0, 0};
  matrix_t result, key;

  s21_create_matrix(4, 4, &matrixA);
  s21_create_matrix(4, 4, &key);

  double prompt[][4] = {
      {0, 1, 2, 3}, {1, 4, 10, 20}, {2, 5, 9, 12}, {3, 10, 14, 16}};
  s21_copy_matrix_4(prompt, &matrixA);

  double prompt_key[][4] = {{-96, -36, 76, -26},
                            {4, 11, -19, 9},
                            {20, -40, 38, -12},
                            {-2, 23, -19, 5}};
  s21_copy_matrix_4(prompt_key, &key);

  int code = s21_calc_complements(&matrixA, &result);

  // bool is_ok =
  // code == OK &&s21_eq_matrix(&result, &key) == SUCCESS ? true : false;
  // printf("s21_calc_complements_4x4: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");

  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&matrixA);
  s21_remove_matrix(&key);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_calc_complements_suite(void) {
  Suite *s = suite_create("calc_complements\n");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_calc_complements_by_null);
  tcase_add_test(tc_core, s21_calc_complements_incorr_index);
  tcase_add_test(tc_core, s21_calc_complements_1x3);
  tcase_add_test(tc_core, s21_calc_complements_2x2);
  tcase_add_test(tc_core, s21_calc_complements_4x4);

  suite_add_tcase(s, tc_core);
  return s;
}
#endif  //_UNIT_TEST_ROUND_H_