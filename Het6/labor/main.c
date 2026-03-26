#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void) {
    //2. feladat
    // int n;
    // printf("halmaz elemeinek szama: ");
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &halmaz1[i]);
    // }
    int S;
    int n = 7;
    printf("\nCelosszeg: ");
    scanf("%d", &S);
    int* x= calloc(n, sizeof(int));
    int halmaz [] = {3, 4, 54, 6, 12, 1, 16};
    BT(x, n, 0, S, halmaz);
    free(x);
    return 0;
}