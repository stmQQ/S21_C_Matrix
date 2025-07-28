#include "s21_matrix.h"


int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int flag = OK;

    if (!A || !A->matrix || A->rows != A->columns) {
        flag = INCORRECT_MATRIX;
    }

    double det = 0.0;

    if (flag == OK) {
        flag = s21_determinant(A, &det);
        if (fabs(det) < 10e-7) {
            flag = CALCULATION_ERROR;
        }
    }
    matrix_t calculations_matrix;
    matrix_t transposed_calculations_matrix;
    if (flag == OK) {
        flag = s21_calc_complements(A, &calculations_matrix);
        flag = s21_transpose(&calculations_matrix, &transposed_calculations_matrix);
    }

    if (flag == OK) {
        flag = s21_mult_number(&transposed_calculations_matrix, 1 / det, result);
    }


    s21_remove_matrix(&calculations_matrix);
    s21_remove_matrix(&transposed_calculations_matrix);
    return flag;
}