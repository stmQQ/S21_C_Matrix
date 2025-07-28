#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int flag = OK;
    int i = 0, j = 0;
    matrix_t submatrix = {0};

    // Проверка входных данных
    if (!A || !A->matrix || A->rows < 1 || A->columns < 1 || A->rows != A->columns) {
        flag = INCORRECT_MATRIX;
    }

    // Создаем результирующую матрицу
    if (flag == OK) {
        flag = s21_create_matrix(A->rows, A->columns, result);
    }

    // Обработка матрицы 1x1
    if (flag == OK && A->rows == 1) {
        result->matrix[0][0] = A->matrix[0][0];
    }

    // Вычисление алгебраических дополнений
    if (flag == OK && A->rows > 1) {
        for (i = 0; flag == OK && i < A->rows; i++) {
            for (j = 0; flag == OK && j < A->columns; j++) {
                flag = create_submatrix(A, i, j, &submatrix);
                
                if (flag == OK) {
                    double minor = 0;
                    flag = s21_determinant(&submatrix, &minor);
                    s21_remove_matrix(&submatrix);
                    
                    if (flag == OK) {
                        result->matrix[i][j] = minor * ((i + j) % 2 ? -1 : 1);
                    }
                }
            }
        }
    }

    // Очистка в случае ошибки
    if (flag != OK) {
        s21_remove_matrix(result);
    }

    return flag;
}