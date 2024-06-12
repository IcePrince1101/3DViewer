#ifndef _UNIT_TEST_ROUND_H_
#define _UNIT_TEST_ROUND_H_

#include "s21_test.h"

START_TEST(affineScale) {
    obj_data data_before, data_after;

    int code_parse_before = parseFile("tests/test_files/affineBefore.obj", &data_before);
    int code_parse_after = parseFile("tests/test_files/affineAfterScale.obj", &data_after);
    // * status check
    ck_assert_int_eq(code_parse_before, 0);
    ck_assert_int_eq(code_parse_after, 0);

    // * scale
    affine_scale(&data_before, 2);

    // * check vertexes
    int code = s21_eq_matrix(&data_before.matrix_3d, &data_after.matrix_3d) == SUCCESS ? 0 : 1;
    ck_assert_int_eq(code, 0);
    
    // * clear data_before
    for (unsigned int i = 1; i <= data_before.count_of_facets; i++) 
        free(data_before.polygons[i].vertexes);
    free(data_before.polygons);
    s21_remove_matrix(&data_before.matrix_3d);

    for (unsigned int i = 1; i <= data_after.count_of_facets; i++) 
        free(data_after.polygons[i].vertexes);
    free(data_after.polygons);
    s21_remove_matrix(&data_after.matrix_3d);
    
}
END_TEST

START_TEST(affineMoveX) {
    obj_data data_before, data_after;

    int code_parse_before = parseFile("tests/test_files/affineBefore.obj", &data_before);
    int code_parse_after = parseFile("tests/test_files/affineAfterMoveX.obj", &data_after);
    // * status check
    ck_assert_int_eq(code_parse_before, 0);
    ck_assert_int_eq(code_parse_after, 0);

    // * scale
    affine_moveX(&data_before, 2);

    // * check vertexes
    int code = s21_eq_matrix(&data_before.matrix_3d, &data_after.matrix_3d) == SUCCESS ? 0 : 1;
    ck_assert_int_eq(code, 0);
    
    // * clear data_before
    for (unsigned int i = 1; i <= data_before.count_of_facets; i++) 
        free(data_before.polygons[i].vertexes);
    free(data_before.polygons);
    s21_remove_matrix(&data_before.matrix_3d);

    for (unsigned int i = 1; i <= data_after.count_of_facets; i++) 
        free(data_after.polygons[i].vertexes);
    free(data_after.polygons);
    s21_remove_matrix(&data_after.matrix_3d);
    
}
END_TEST

START_TEST(affineMoveY) {
    obj_data data_before, data_after;

    int code_parse_before = parseFile("tests/test_files/affineBefore.obj", &data_before);
    int code_parse_after = parseFile("tests/test_files/affineAfterMoveY.obj", &data_after);
    // * status check
    ck_assert_int_eq(code_parse_before, 0);
    ck_assert_int_eq(code_parse_after, 0);

    // * scale
    affine_moveY(&data_before, 2);

    // * check vertexes
    int code = s21_eq_matrix(&data_before.matrix_3d, &data_after.matrix_3d) == SUCCESS ? 0 : 1;
    ck_assert_int_eq(code, 0);
    
    // * clear data_before
    for (unsigned int i = 1; i <= data_before.count_of_facets; i++) 
        free(data_before.polygons[i].vertexes);
    free(data_before.polygons);
    s21_remove_matrix(&data_before.matrix_3d);

    for (unsigned int i = 1; i <= data_after.count_of_facets; i++) 
        free(data_after.polygons[i].vertexes);
    free(data_after.polygons);
    s21_remove_matrix(&data_after.matrix_3d);
    
}
END_TEST

START_TEST(affineMoveZ) {
    obj_data data_before, data_after;

    int code_parse_before = parseFile("tests/test_files/affineBefore.obj", &data_before);
    int code_parse_after = parseFile("tests/test_files/affineAfterMoveZ.obj", &data_after);
    // * status check
    ck_assert_int_eq(code_parse_before, 0);
    ck_assert_int_eq(code_parse_after, 0);

    // * scale
    affine_moveZ(&data_before, 2);
    // * check vertexes
    int code = s21_eq_matrix(&data_before.matrix_3d, &data_after.matrix_3d) == SUCCESS ? 0 : 1;
    ck_assert_int_eq(code, 0);
    
    // * clear data_before
    for (unsigned int i = 1; i <= data_before.count_of_facets; i++) 
        free(data_before.polygons[i].vertexes);
    free(data_before.polygons);
    s21_remove_matrix(&data_before.matrix_3d);

    for (unsigned int i = 1; i <= data_after.count_of_facets; i++) 
        free(data_after.polygons[i].vertexes);
    free(data_after.polygons);
    s21_remove_matrix(&data_after.matrix_3d);
    
}
END_TEST

START_TEST(affineRotateX) {
    obj_data data_before, data_after;

    int code_parse_before = parseFile("tests/test_files/affineBefore.obj", &data_before);
    int code_parse_after = parseFile("tests/test_files/affineAfterRotateX.obj", &data_after);
    // * status check
    ck_assert_int_eq(code_parse_before, 0);
    ck_assert_int_eq(code_parse_after, 0);

    // * scale
    affine_rotateX(&data_before, 90);
    // * check vertexes
    int code = s21_eq_matrix(&data_before.matrix_3d, &data_after.matrix_3d) == SUCCESS ? 0 : 1;
    ck_assert_int_eq(code, 0);
    
    // * clear data_before
    for (unsigned int i = 1; i <= data_before.count_of_facets; i++) 
        free(data_before.polygons[i].vertexes);
    free(data_before.polygons);
    s21_remove_matrix(&data_before.matrix_3d);

    for (unsigned int i = 1; i <= data_after.count_of_facets; i++) 
        free(data_after.polygons[i].vertexes);
    free(data_after.polygons);
    s21_remove_matrix(&data_after.matrix_3d);
    
}
END_TEST

START_TEST(affineRotateY) {
    obj_data data_before, data_after;

    int code_parse_before = parseFile("tests/test_files/affineBefore.obj", &data_before);
    int code_parse_after = parseFile("tests/test_files/affineAfterRotateY.obj", &data_after);
    // * status check
    ck_assert_int_eq(code_parse_before, 0);
    ck_assert_int_eq(code_parse_after, 0);

    // * scale
    affine_rotateY(&data_before, 90);
    // * check vertexes
    int code = s21_eq_matrix(&data_before.matrix_3d, &data_after.matrix_3d) == SUCCESS ? 0 : 1;
    ck_assert_int_eq(code, 0);
    
    // * clear data_before
    for (unsigned int i = 1; i <= data_before.count_of_facets; i++) 
        free(data_before.polygons[i].vertexes);
    free(data_before.polygons);
    s21_remove_matrix(&data_before.matrix_3d);

    for (unsigned int i = 1; i <= data_after.count_of_facets; i++) 
        free(data_after.polygons[i].vertexes);
    free(data_after.polygons);
    s21_remove_matrix(&data_after.matrix_3d);
    
}
END_TEST

START_TEST(affineRotateZ) {
    obj_data data_before, data_after;

    int code_parse_before = parseFile("tests/test_files/affineBefore.obj", &data_before);
    int code_parse_after = parseFile("tests/test_files/affineAfterRotateZ.obj", &data_after);
    // * status check
    ck_assert_int_eq(code_parse_before, 0);
    ck_assert_int_eq(code_parse_after, 0);

    // * scale
    affine_rotateZ(&data_before, 90);
    // * check vertexes
    int code = s21_eq_matrix(&data_before.matrix_3d, &data_after.matrix_3d) == SUCCESS ? 0 : 1;
    ck_assert_int_eq(code, 0);
    
    // * clear data_before
    for (unsigned int i = 1; i <= data_before.count_of_facets; i++) 
        free(data_before.polygons[i].vertexes);
    free(data_before.polygons);
    s21_remove_matrix(&data_before.matrix_3d);

    for (unsigned int i = 1; i <= data_after.count_of_facets; i++) 
        free(data_after.polygons[i].vertexes);
    free(data_after.polygons);
    s21_remove_matrix(&data_after.matrix_3d);
    
}
END_TEST

Suite *testAffine(void) {
  Suite *s = suite_create("affine\n");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, affineScale);
  tcase_add_test(tc_core, affineMoveX);
  tcase_add_test(tc_core, affineMoveY);
  tcase_add_test(tc_core, affineMoveZ);
  tcase_add_test(tc_core, affineRotateX);
  tcase_add_test(tc_core, affineRotateY);
  tcase_add_test(tc_core, affineRotateZ);

  suite_add_tcase(s, tc_core);
  return s;
}

// void run_test(Suite *test) {
//   SRunner *sr = srunner_create(test);
//   printf("\n");
//   srunner_run_all(sr, CK_NORMAL);
//   srunner_free(sr);
// }

// int main() {
//   run_test(testObjParser());
// }

#endif  //_UNIT_TEST_ROUND_H_