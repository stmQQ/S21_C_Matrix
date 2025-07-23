#include "s21_matrix.h"


int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int flag = OK;
    if (!compare_matrix_sizes(A, B)) {
        flag = INCORRECT_MATRIX;
    }
    
    if (flag == OK) {
        flag = s21_create_matrix(A->rows, A->columns, result);
    }

    if (flag == OK) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            }
        }
    }

    return flag;
}