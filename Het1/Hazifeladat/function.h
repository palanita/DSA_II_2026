//
// Created by palan on 2/24/2026.
//

#ifndef LABOR_FUNCTION_H
#define LABOR_FUNCTION_H
#include <stdio.h>
#include <stdlib.h>

void readMatrixRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol);
void printMatrixRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol);
int isThreeDigitMirror(int x);
void printThreeDigitMirrorsByRowRecursive(int **matrix, int rows, int cols, int currentRow, int currentCol);
#endif //LABOR_FUNCTION_H