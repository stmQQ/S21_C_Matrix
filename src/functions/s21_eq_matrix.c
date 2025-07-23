#include "s21_matrix.h"

#define SUCCESS 1
#define FAILURE 0

#define EPSILON 1e-7

/** * @brief Function for comparing two matrixes up to 7 decimal places.
 * @param A First matrix
 * @param B Second matrix
 * @returns int SUCCESS if A equals B, else returns FAILURE
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int flag = SUCCESS;
    if (!compare_matrix_sizes(A, B)) {
        flag = FAILURE;
    }
    if (flag == SUCCESS) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) 
                    flag = FAILURE;
            }
        }
    }

    return flag;
}