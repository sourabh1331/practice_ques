#include <stdio.h>
#include <stdlib.h>

void reverseMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows / 2; i++) {
        int *temp = matrix[i];
        matrix[i] = matrix[rows - i - 1];
        matrix[rows - i - 1] = temp;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][cols - j - 1];
            matrix[i][cols - j - 1] = temp;
        }
    }
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
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

    reverseMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}