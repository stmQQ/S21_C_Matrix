#include "s21_matrix.h"


int s21_determinant(matrix_t *A, double *result) {
    int flag = OK;
    *result = 0.0;

    if (!A || !A->matrix || A->rows != A->columns) {
        flag = INCORRECT_MATRIX;
    }

    if (flag == OK) {
        if (A->rows == 1) {
            *result = A->matrix[0][0];
        }

        if (A->rows == 2) {
            *result = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
        }

        if (A->rows > 2) {
            matrix_t submatrix;
            for (int col = 0; flag == OK && col < A->columns; col++) {
                flag = create_submatrix(A, 0, col, &submatrix);

                if (flag == OK) {
                    double minor = 0.0;
                    flag = s21_determinant(&submatrix, &minor);
                    s21_remove_matrix(&submatrix);

                    if (flag == OK) {
                        *result += (col % 2 ? -1 : 1) * A->matrix[0][col] * minor;
                    }
                }
            }
        }
    }

    return flag;
}