//
// Created by anita on 2/19/26.
//
#include "function.h"

#include <stdio.h>

void readElementsRecursive(int *v, int n) {
    if (n>=0) {
        readElementsRecursive(v,n-1);
        printf("Kerek egy elemet:");
        scanf("%i", &v[n]);
    }
}

void printElementsRecursive(int *v, int n) {
    if (n>=0) {
        printf("%i ", v[n]);
        printElementsRecursive(v, n-1);
    }
}

int sumElementsRecursive(int *v, int n) {
    if (n>=0) {
        return v[n] + sumElementsRecursive(v, n-1);
    }
    return 0;
}

int minElementRecursive(int *v, int n) {
    if (n>=0) {
        int a = minElementRecursive(v, n-1);
        if (a<v[n]){
            return a;
        }else
            return v[n];
    }
    return 0;
}


int countPositiveElementsRecursive(int *v, int n) {
    if (n>=0) {
        if (v[n]>0) {
            return 1+countPositiveElementsRecursive(v, n-1);
        }
        return countPositiveElementsRecursive(v, n-1);
    }
    return 0;
}

void readMatrixRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol) {
    if (currentRow<rows) {
        if (currentCol<cols) {
            scanf("%i", &matrix[currentRow][currentCol]);
            readMatrixRecursive(matrix, rows, cols, currentRow,currentCol+1);
        }
        readMatrixRecursive(matrix,rows,cols, currentRow+1, 0);
    }
}






