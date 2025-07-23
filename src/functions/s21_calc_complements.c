#include "s21_matrix.h"


int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int flag = OK;
    if (!A || A->rows != A->columns) {
        flag = INCORRECT_MATRIX;
    }

    if (flag == OK) {
        flag = s21_create_matrix(A->rows, A->columns, result);
    }

    if (flag == OK) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = calculate_minor(i, j, A);
            }
        }
    }
}
