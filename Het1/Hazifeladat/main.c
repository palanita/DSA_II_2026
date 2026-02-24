#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(void) {
    int cols, rows;
    printf("\nsorok szama: ");
    scanf("%i", &rows);
    printf("\noszlopok szama: ");
    scanf("%i", &cols);
    int **matrix = (int**)malloc(rows*sizeof(int*));
    for (int i = 0; i < rows; i++) {
        if (!matrix) {
            printf("Memory allociation error");
        }
        matrix[i] = (int*)malloc(cols*sizeof(int));
    }

    readMatrixRecursive(matrix, rows, cols, 0,0);
    printf("A beolvasott matrix: \n");
    printMatrixRecursive(matrix, rows, cols, 0,0);
    printf("Azon elemek, amik harom szamjegyes tukorszamok:\n");
    printThreeDigitMirrorsByRowRecursive(matrix, rows, cols, 0,0);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
