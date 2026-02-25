//
// Created by anita on 2/19/26.
//
#include "function.h"


void readElementsRecursive(int *v, int n) {
    if (n>=0) {
        readElementsRecursive(v,n-1);
        printf("Irj egy elemet:");
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
        }
        return v[n];
    }
    return v[0];
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

int prodDigitsNumber(int e) {
    if (e>=10) {
        return e%10*prodDigitsNumber(e/10);
    }
    return e;
}

int minDigitNumber(int e) {
    if (e>=10) {
        return e%10 < minDigitNumber(e/10) ? e%10 : minDigitNumber(e/10);
    }
    return e;
}

void readMatrixRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol) {
    if (currentRow<rows) {
        if (currentCol<cols) {
            scanf("%i", &matrix[currentRow][currentCol]);
            readMatrixRecursive(matrix, rows, cols, currentRow,currentCol+1);
        } else
        readMatrixRecursive(matrix,rows,cols, currentRow+1, 0);
    }
}

void printMatrixRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol) {
    if (currentRow<rows) {
        if (currentCol<cols) {
            printf("%i ", matrix[currentRow][currentCol]);
            printMatrixRecursive(matrix, rows, cols, currentRow,currentCol+1);
        } else{
			printf("\n");
        	printMatrixRecursive(matrix,rows,cols, currentRow+1, 0);
		}
    }
}






