    #include "s21_matrix.h"


    /** * @brief Function for creating a matrix.
     * @param rows Rows of matrix 
     * @param columns Columns of matrix
     * @param result Matrix
     * @returns int OK if matrix was created successful, int INCORRECT_MATRIX in other cases.
     */
    int s21_create_matrix(int rows, int columns, matrix_t *result) {
        int flag = OK;
        if (rows == 0 || columns == 0 || result == NULL) {
            flag = INCORRECT_MATRIX;
        }
        if (flag == OK) {
            result->matrix = (double **)malloc(rows * sizeof(double *));
            if (!result->matrix) flag = INCORRECT_MATRIX;
        }

        if (flag == OK) {
        for (int i = 0; i < rows; i++) {
            result->matrix[i] = (double *)calloc(columns, sizeof(double));
            if (!result->matrix[i]) {
                flag = INCORRECT_MATRIX;
                for (int j = 0; j < i; j++) {
                    free(result->matrix[j]);
                }
                free(result->matrix);
                };
            }
        }
        if (flag == OK) {
            result->rows = rows;
            result->columns = columns;
        }
        return flag;
    }

