#include <stdio.h>
//
// Created by palan on 4/23/2026.
//
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left>right) {
        return -8;
    }
    if (arr[left] == target){
        return left;
    }
    if (arr[right] == target) {
        return right;
    }
    return binarySearchRecursive(arr, left+1, right-1, target);
}

int kiir(int** x, int n, char** matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", matrix[x[i][0]][x[0][j]]);
        }
        printf("\n");
    }
}


