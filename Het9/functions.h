//
// Created by palan on 4/23/2026.
//

#ifndef HET9_FUNCTIONS_H
#define HET9_FUNCTIONS_H
typedef struct {
    int start;
    int end;
} Interval;

//1. feladat
int binarySearchRecursive(int arr[], int left, int right, int target);

//2. feladat
void backtrack(int **x, int n, int k, char **matrix);

bool valid(int **x, int n, int k, char **matrix);

void kiir(int **x, int n, int k, char **matrix);

//3. feladat
int compare(const void *a, const void *b);

void solve();





#endif //HET9_FUNCTIONS_H
