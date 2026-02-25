#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(void) {
    int n;
    printf("Elemek szama: ");
    scanf("%i", &n);
    int *v = (int*)malloc(n*sizeof(int));
    if (!v) {
        printf("Memory allociation error");
    }
    //1.
    readElementsRecursive(v,n-1);
    //2.
    printf("A tomb elemei: ");
    printElementsRecursive(v,n-1);
    //3.
    printf("\nSum: %i\n", sumElementsRecursive(v, n-1));
    //5.
    printf("Pozitiv szamok szama: %i\n", countPositiveElementsRecursive(v, n-1));
    //4.
    printf("Min szam: %i\n", minElementRecursive(v, n-1));

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
    printf("Matrix elemei: ");
    readMatrixRecursive(matrix,rows,cols,0,0);
    printMatrixRecursive(matrix,rows,cols,0,0);

    free(v);
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
