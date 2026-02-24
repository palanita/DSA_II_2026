//
// Created by palan on 2/24/2026.
//

#include "function.h"

void readMatrixRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol) {
    if (currentRow < rows) {
        if (currentCol < cols) {
            scanf("%i", &matrix[currentRow][currentCol]);
            readMatrixRecursive(matrix, rows, cols, currentRow, currentCol + 1);
        } else
            readMatrixRecursive(matrix, rows, cols, currentRow + 1, 0);
    }
}

void printMatrixRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol) {
    if (currentRow < rows) {
        if (currentCol < cols) {
            printf("%i ", matrix[currentRow][currentCol]);
            printMatrixRecursive(matrix, rows, cols, currentRow, currentCol + 1);
        } else {
            printf("\n");
            printMatrixRecursive(matrix, rows, cols, currentRow + 1, 0);
        }
    }
}

int isThreeDigitMirror(int x) {
    return x > 99 &&
           x < 1000 &&
           x / 100 == x % 10
               ? x
               : 0;
}

void printThreeDigitMirrorsByRowRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol) {
    if (currentRow < rows) {
        if (currentCol < cols) {
            if (isThreeDigitMirror(matrix[currentRow][currentCol]) != 0) {
                printf("%i ", matrix[currentRow][currentCol]);
            }
            printThreeDigitMirrorsByRowRecursive(matrix, rows, cols, currentRow, currentCol + 1);
        } else {
            printf("\n");
            printThreeDigitMirrorsByRowRecursive(matrix, rows, cols, currentRow + 1, 0);
        }
    }
}
