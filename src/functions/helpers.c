#include "s21_matrix.h"

int compare_matrix_sizes(matrix_t *A, matrix_t *B) {
    return A->rows == B->rows && A->columns == B->columns;
}

int create_submatrix(matrix_t *A, int row, int col, matrix_t *result) {
    if (!A || !A->matrix || row < 0 || col < 0 || row >= A->rows || col >= A->columns || !result) {
        return INCORRECT_MATRIX;
    }

    int new_rows = A->rows - 1;
    int new_columns = A->columns - 1;

    int flag = s21_create_matrix(new_rows, new_columns, result);

    if (flag == OK) {
        int res_i = 0;
        for (int i = 0; i < A->rows; i++) {
            if (res_i != row) {
                int res_j = 0;
                for (int j = 0; j < A->columns; j++) {
                    if (res_j != col) {
                        result->matrix[res_i][res_j] = A->matrix[i][j];
                        res_j++;
                    }
                }
                res_i++;
            }
        }
    }
    return flag;
}