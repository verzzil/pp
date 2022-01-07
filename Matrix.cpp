#include "FirstTasks.h"
#include <iostream>
#include "omp.h"
void parallel_vector_matrix();
void parallel_matrix_on_matrix();

void parallel_vector_matrix() {
    double vector[] = {1.0, 1.0};
    double matrix[][2] = {{3.0, 4.0}, {5.0, 6.0}};
    double result[] = {0.0, 0.0};
    int i, j;
#pragma omp parallel for private (i,j)
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
    for (int k = 0; k < 2; ++k) {
        std::cout << result[k] << std::endl;
    }
}


void parallel_matrix_on_matrix() {
    double matrix1[][2] = {{1.0, 1.0}, {2.0, 2.0}};
    double matrix[][2] = {{3.0, 4.0}, {5.0, 6.0}};
    double result[][2] = {{0.0, 0.0}, {0.0, 0.0}};
    int i, j, k;
#pragma omp parallel for shared(matrix1, matrix, result) private (i, j, k)
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            for (k = 0; k < 2; ++k)
                result[i][j] += matrix[i][k] * matrix1[k][j];
        }
    }
}