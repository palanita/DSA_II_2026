//
// Created by palan on 3/28/2026.
//

#include "functions.h"

void BTP (int *x, int n, int k, Hozzavalo *hozzavalok) {
    for (x[k] = 1; x[k] <= n; x[k]++) {
        if (valid(x,k,hozzavalok)) {
            if (k<n-1) {
                BTP(x,n,k+1, hozzavalok);
            }
            else  kiir(x,n, hozzavalok);
        }
    }
}

bool valid(int *x, int k, Hozzavalo *hozzavalok) {
    for (int i = 0; i < k; i++) {
        if (x[k] == x[i]) return false;
    }
    if (k>0) {
        if (hozzavalok[x[k-1]-1]==eleszto && hozzavalok[x[k]-1]==so) return false;
        if (hozzavalok[x[k-1]-1]==so && hozzavalok[x[k]-1]==eleszto) return false;
    }
    return true;
}

const char* hozzavalo_nevek[]={
    "liszt",
    "cukor",
    "eleszto",
    "so",
    "tej"
};

void kiir(int *x, int n, Hozzavalo *hozzavalok)
{
    for (int i = 0; i < n; i++) {
        printf("%s ", hozzavalo_nevek[hozzavalok[x[i]-1]]);
    }
    printf("\n");
}