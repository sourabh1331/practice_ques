#include <stdio.h>
#include <stdlib.h>

void spiralTraversal(int **matrix, int rows, int cols) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        for (int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }
    printf("\n");
}

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    spiralTraversal(matrix, rows, cols);

    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}