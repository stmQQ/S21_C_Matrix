#include "s21_matrix.h"


int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int flag = OK;
    if (!A || !B || (A->columns != B->rows)) {
        flag = INCORRECT_MATRIX;
    }

    if (flag == OK) {
        flag = s21_create_matrix(A->rows, B->columns, result);
    }

    if (flag == OK) {
        for (int i = 0; i < result->rows; i++) {
            for (int j = 0; j < result->columns; j++) {
                double sum_ = 0;
                for (int k = 0; k < A->columns; k++) {
                    sum_ += A->matrix[i][k] * B->matrix[k][j];
                }
                result->matrix[i][j] = sum_;
            }
        }
    }

    return flag;
}