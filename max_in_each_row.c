#include <stdio.h>
#include <stdlib.h>

void findMaxInEachRow(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int max = matrix[i][0];
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        printf("Row %d: %d\n", i, max);
    }
}

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    findMaxInEachRow(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}