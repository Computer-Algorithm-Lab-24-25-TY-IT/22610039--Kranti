//22610026 Elizabeth Suresh Pawar
//Matrix Multiplication

#include <stdio.h>

#define MAX 10 // Define a maximum size for simplicity

void multiplyMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int rowFirst, int colFirst, int rowSecond, int colSecond) {
    // Check if multiplication is possible
    if (colFirst != rowSecond) {
        printf("Matrix multiplication not possible.\n");
        return;
    }

    // Initialize all elements of result matrix to 0
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < colSecond; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < colSecond; j++) {
            for (int k = 0; k < colFirst; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rowFirst, colFirst, rowSecond, colSecond;

    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &rowFirst, &colFirst);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &rowSecond, &colSecond);

    int first[MAX][MAX], second[MAX][MAX], result[MAX][MAX];

    // Input first matrix
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < colFirst; j++) {
            scanf("%d", &first[i][j]);
        }
    }

    // Input second matrix
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rowSecond; i++) {
        for (int j = 0; j < colSecond; j++) {
            scanf("%d", &second[i][j]);
        }
    }

    // Multiply matrices
    multiplyMatrices(first, second, result, rowFirst, colFirst, rowSecond, colSecond);

    // Print the result
    printf("Result matrix:\n");
    printMatrix(result, rowFirst, colSecond);

    return 0;
}

