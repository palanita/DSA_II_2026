//
// Created by palan on 3/26/2026.
//

#include "functions.h"


void BT(int *x, int n, int k, int S, int* halmaz) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += halmaz[x[i]];
    }
    if (sum == S) {
        kiir(x, n, k, halmaz);
        return;
    }
    if (sum > S) {
        return;
    }
    for (int i = (k == 0 ? 0 : x[k - 1] + 1); i < n; i++) {
        x[k] = i;
        BT(x, n, k + 1, S, halmaz);
    }
}


void kiir(int *x, int n, int k, int *halmaz) {
    for (int i = 0; i < k; i++) {
        printf("%d ", halmaz[x[i]]);
    }
    printf("\n");
}

