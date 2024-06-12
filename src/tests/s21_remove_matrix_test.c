#ifndef _UNIT_TEST_ROUND_H_
#define _UNIT_TEST_ROUND_H_

#include "s21_test.h"

START_TEST(s21_remove_matrix_non_null) {
  // printf("---------------------------------------------\n");

  matrix_t matrix = {0, 0, 0};
  s21_create_matrix(3, 4, &matrix);

  ck_assert_ptr_nonnull(matrix.matrix);
  // bool is_ok = matrix.matrix ? true : false;
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
  // is_ok = !matrix.matrix ? is_ok : false;
  // printf("s21_remove_matrix_non_null: ");
  // printf(is_ok ? "SUCCESS" : "FAIL");
  // printf("\n---------------------------------------------\n");
}
END_TEST

Suite *s21_remove_matrix_suite(void) {
  Suite *s = suite_create("remove_matrix\n");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_remove_matrix_non_null);
  // tcase_add_test(tc_core, s21_remove_matrix_null);

  suite_add_tcase(s, tc_core);
  return s;
}
#endif  //_UNIT_TEST_ROUND_H_