#ifndef _UNIT_TEST_ROUND_H_
#define _UNIT_TEST_ROUND_H_

#include "s21_test.h"

START_TEST(parseCommonFile) {
    obj_data data;

    int code = parseFile("tests/test_files/parseCommonFile.obj", &data);
    printf("This is example how organized obj_data\n");
    printData(&data);
    
    // * status check
    ck_assert_int_eq(code, 0);

    // * check count of vertexes
    ck_assert_int_eq(data.count_of_vertexes, 6);
    // * check vertexes
    matrix_t vertex_key;
    s21_create_matrix(7, 3, &vertex_key);
    double vertex_key_k[][7] = {{0.0, 0.0, 0.0}, 
                       {1.0, 2.0, 3.0},
                       {2.0, 3.0, 4.0},
                       {4.0, 5.0, 6.0},
                       {5.0, 6.0, 7.0},
                       {7.0, 8.0, 9.0},
                       {1.0, 5.0, 9.0}};
    s21_copy_matrix_6(vertex_key_k, &vertex_key);
    int eq_code = s21_eq_matrix(&data.matrix_3d, &vertex_key) == SUCCESS ? 0 : 1;
    ck_assert_int_eq(eq_code, 0);

    // * check count of facets
    ck_assert_int_eq(data.count_of_facets, 2);
    // * check facets
    ck_assert_int_eq(data.polygons[1].vertexes[0], 1);
    ck_assert_int_eq(data.polygons[1].vertexes[1], 2);
    ck_assert_int_eq(data.polygons[1].vertexes[2], 3);
    ck_assert_int_eq(data.polygons[2].vertexes[0], 4);
    ck_assert_int_eq(data.polygons[2].vertexes[1], 5);
    ck_assert_int_eq(data.polygons[2].vertexes[2], 6);
    
    // * clear data
    if (code == 0) {
        for (unsigned int i = 1; i <= data.count_of_facets; i++) 
            free(data.polygons[i].vertexes);
        free(data.polygons);
        s21_remove_matrix(&data.matrix_3d);
    }
    // * remove matrix_key
    s21_remove_matrix(&vertex_key);
}
END_TEST

START_TEST(parseVertexInt) {
    // * create obj_data
    obj_data data;

    int code = parseFile("tests/test_files/parseVertexInt.obj", &data);

    // * status check
    ck_assert_int_eq(code, 0);

    // * check count of vertexes
    ck_assert_int_eq(data.count_of_vertexes, 3);
    // * check vertexes
    matrix_t vertex_key;
    s21_create_matrix(4, 3, &vertex_key);
    double vertex_key_k[][4] = {{0, 0, 0}, 
                                {1, 2, 3},
                                {1, 2, 4},
                                {4, 5, 6}};
    s21_copy_matrix_4(vertex_key_k, &vertex_key);
    int eq_code = s21_eq_matrix(&data.matrix_3d, &vertex_key) == SUCCESS ? 0 : 1;
    ck_assert_int_eq(eq_code, 0);

    // * check count of facets
    ck_assert_int_eq(data.count_of_facets, 0);

    // * free memory
    if (code == 0) {
        free(data.polygons);
        s21_remove_matrix(&data.matrix_3d);
    }
    s21_remove_matrix(&vertex_key);
}
END_TEST

START_TEST(parseVertexFloat) {
    // * create obj_data
    obj_data data;

    int code = parseFile("tests/test_files/parseVertexFloat.obj", &data);

    // * status check
    ck_assert_int_eq(code, 0);

    // * check count of vertexes
    ck_assert_int_eq(data.count_of_vertexes, 3);
    // * check vertexes
    matrix_t vertex_key;
    s21_create_matrix(4, 3, &vertex_key);
    double vertex_key_k[][4] = {{0.0, 0.0, 0.0}, 
                                {4.55656, 5.435456, 4.5},
                                {4.434, 2.3, -5.444},
                                {0.0, 4.001, 3.4}};
    s21_copy_matrix_4(vertex_key_k, &vertex_key);
    int eq_code = s21_eq_matrix(&data.matrix_3d, &vertex_key) == SUCCESS ? 0 : 1;
    ck_assert_int_eq(eq_code, 0);

    // * check count of facets
    ck_assert_int_eq(data.count_of_facets, 0);

    // * free memory
    if (code == 0) {
        free(data.polygons);
        s21_remove_matrix(&data.matrix_3d);
    }
    s21_remove_matrix(&vertex_key);
}
END_TEST

START_TEST(parseVertexError2Points) {
    // * create obj_data
    obj_data data;

    int code = parseFile("tests/test_files/parseVertexError2Points.obj", &data);

    // * status check
    ck_assert_int_eq(code, 1);

    // * free memory
    free(data.polygons);
    s21_remove_matrix(&data.matrix_3d);
}
END_TEST

START_TEST(parseVertexErrorToDouble) {
    // * create obj_data
    obj_data data;

    int code = parseFile("tests/test_files/parseVertexErrorToDouble.obj", &data);

    // * status check
    ck_assert_int_eq(code, 1);

    // * free memory
    free(data.polygons);
    s21_remove_matrix(&data.matrix_3d);
}
END_TEST

START_TEST(parseFacetsInt) {
    // * create obj_data
    obj_data data;

    int code = parseFile("tests/test_files/parseFacetsInt.obj", &data);

    // * status check
    ck_assert_int_eq(code, 0);

    // * check count of vertexes
    ck_assert_int_eq(data.count_of_vertexes, 3);
    // * check vertexes
    matrix_t vertex_key;
    s21_create_matrix(4, 3, &vertex_key);
    double vertex_key_k[][4] = {{0.0, 0.0, 0.0}, 
                                {1.0, 2.0, 3.0},
                                {2.0, 3.0, 4.0},
                                {4.0, 5.0, 6.0}};
    s21_copy_matrix_4(vertex_key_k, &vertex_key);
    int eq_code = s21_eq_matrix(&data.matrix_3d, &vertex_key) == SUCCESS ? 0 : 1;
    ck_assert_int_eq(eq_code, 0);

    // * check count of facets
    ck_assert_int_eq(data.count_of_facets, 2);
    ck_assert_int_eq(data.polygons[1].vertexes[0], 1);
    ck_assert_int_eq(data.polygons[1].vertexes[1], 2);
    ck_assert_int_eq(data.polygons[1].vertexes[2], 3);
    ck_assert_int_eq(data.polygons[2].vertexes[0], 2);
    ck_assert_int_eq(data.polygons[2].vertexes[1], 3);
    ck_assert_int_eq(data.polygons[2].vertexes[2], 4);

    // * free memory
    if (code == 0) {
        for (unsigned int i = 1; i <= data.count_of_facets; i++) 
            free(data.polygons[i].vertexes);
        free(data.polygons);
        s21_remove_matrix(&data.matrix_3d);
    }
    s21_remove_matrix(&vertex_key);
}
END_TEST

START_TEST(parseFacetsErrorLess3Points) {
    // * create obj_data
    obj_data data;

    int code = parseFile("tests/test_files/parseFacetsErrorLess3Points.obj", &data);
    // * status check
    ck_assert_int_eq(code, 1);

    // * free memory
    if (code == 0) {
        for (unsigned int i = 1; i <= data.count_of_facets; i++) {
            free(data.polygons[i].vertexes);
        }
        free(data.polygons);
        s21_remove_matrix(&data.matrix_3d);
    }
}
END_TEST

START_TEST(parseErrorFileNotExist) {
    // * create obj_data
    obj_data data;

    int code = parseFile("tests/test_files/parseErrorFileNotExist.obj", &data);

    // * status check
    ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(parseErrorNullFile) {
    // * create obj_data
    obj_data data;

    int code = parseFile(NULL, &data);

    // * status check
    ck_assert_int_eq(code, 1);
}
END_TEST

Suite *testObjParser(void) {
  Suite *s = suite_create("parseObjFile\n");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, parseCommonFile);
  tcase_add_test(tc_core, parseVertexInt);
  tcase_add_test(tc_core, parseVertexFloat);
  tcase_add_test(tc_core, parseVertexError2Points);
  tcase_add_test(tc_core, parseVertexErrorToDouble);
//   Facets
  tcase_add_test(tc_core, parseFacetsInt);
  tcase_add_test(tc_core, parseFacetsErrorLess3Points);
// File not exist
  tcase_add_test(tc_core, parseErrorFileNotExist);
//   Null file
  tcase_add_test(tc_core, parseErrorNullFile);

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