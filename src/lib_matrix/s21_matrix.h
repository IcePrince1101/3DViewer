/*!
 * @file    s21_matrix.h
 * @brief    This file contains functions for s21_matrix library. They describe
 * the mechanisms of creation, processing, and disposal of matrices
 */
#ifndef S21_MATRIX_H
#define S21_MATRIX_H
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define FAILURE 0

#define ACCURACY 1e-7

/*!
 * @brief This structure contains data about matrix
 * @param double **matrix - matrix
 * @param int rows - number of rows
 * @param int columns - number of columns
 */
typedef struct Matrix {
  double **matrix;
  int rows;
  int columns;
} matrix_t;
/*!
 * @brief This enum contains the list of errors
 */
typedef enum { OK = 0, INCORR = 1, CALC_ERR = 2 } errors;

/// This set of functions describes creation and disposal of matrices
/*!
 * @brief This function creates matrix
 * @param int rows - number of rows
 * @param int columns - number of columns
 * @param matrix_t *result - pointer to matrix
 * @return OK
 * @return INCORR
 */
int s21_create_matrix(int rows, int columns, matrix_t *result);

/*!
 * @brief This function removes matrix
 * @param matrix_t *A - pointer to matrix
 */
void s21_remove_matrix(matrix_t *A);

/// This set of functions describes matrix arithmetic and comparisons
/*!
 * @brief This function compares matrices
 * @param matrix_t *A - pointer to matrix
 * @param matrix_t *B - pointer to matrix
 * @return SUCCESS
 * @return FAILURE
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B);

/*!
 * @brief This function sums matrices
 * @param matrix_t *A - pointer to matrix
 * @param matrix_t *B - pointer to matrix
 * @param matrix_t *result - pointer to matrix
 * @return SUCCESS
 * @return FAILURE
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
/*!
 * @brief This function subtracts matrices
 * @param matrix_t *A - pointer to matrix
 * @param matrix_t *B - pointer to matrix
 * @param matrix_t *result - pointer to matrix
 * @return OK
 * @return INCORR
 * @return CALC_ERR
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
/*!
 * @brief This function multiplies matrix and number
 * @param matrix_t *A - pointer to matrix
 * @param double number - number
 * @param matrix_t *result - pointer to matrix
 * @return OK
 * @return INCORR
 * @return CALC_ERR
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
/*!
 * @brief This function multiplies matrices
 * @param matrix_t *A - pointer to matrix
 * @param matrix_t *B - pointer to matrix
 * @param matrix_t *result - pointer to matrix
 * @return OK
 * @return INCORR
 * @return CALC_ERR
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/// This set of functions describes matrix transformations
/*!
 * @brief This function transposes matrix
 * @param matrix_t *A - pointer to matrix
 * @param matrix_t *result - pointer to transposed matrix
 * @return OK
 * @return INCORR
 */
int s21_transpose(matrix_t *A, matrix_t *result);
/*!
 * @brief This function calculates algebraic complement matrix
 * @param matrix_t *A - pointer to matrix
 * @param matrix_t *result - pointer to result matrix
 * @return OK
 * @return INCORR
 * @return CALC_ERR
 */
int s21_calc_complements(matrix_t *A, matrix_t *result);
/*!
 * @brief This function calculates determinant
 * @param matrix_t *A - pointer to matrix
 * @param double *result - pointer to result
 * @return OK
 * @return INCORR
 * @return CALC_ERR
 */
int s21_determinant(matrix_t *A, double *result);
/*!
 * @brief This function calculates inverse matrix
 * @param matrix_t *A - pointer to matrix
 * @param matrix_t *result - pointer to result matrix
 * @return OK
 * @return INCORR
 * @return CALC_ERR
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

/// This set of functions describes auxiliary functions
/*!
 * @brief This function builds minor matrix
 * @param matrix_t A - matrix
 * @param int row - row
 * @param int column - column
 * @param matrix_t *result - pointer to result matrix
 */
void s21_build_minor_matrix(matrix_t A, int row, int column, matrix_t *result);
/*!
 * @brief This function checks if matrix exists
 * @param matrix_t *A - pointer to matrix
 * @return OK
 * @return INCORR
 */
int s21_is_matrix_exist(matrix_t *A);

#endif