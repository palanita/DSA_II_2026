//
// Created by palan on 3/28/2026.
//

#include "functions.h"

void BT(int *x, int n, int k, int v, Tancos* csoport) {
    for (x[k] = 1; x[k] <= n; x[k]++) {
        if (valid(x,n,k,csoport)) {
            if (k<v-1) {
                BT(x,n,k+1,v,csoport);
            }
            else  kiir(x,n,v,csoport);
        }
    }
}

bool valid(int *x, int n, int k, Tancos *csoport) {
    for (int i = 0; i < k; i++) {
        if (x[k] == x[i]) return false;
        //csak fiú-lány pár feltétel
        if (csoport[x[k]-1].nem == csoport[x[i]-1].nem) return false;
        //magasság feltétel
        //if (csoport[x[k]-1].nem != csoport[x[i]-1].nem)
        //ha lány és nála kisebb
        if (csoport[x[k]-1].nem == lany &&
            csoport[x[k]-1].magassag > csoport[x[i]-1].magassag)
            return false;
            //ha fiú és nála magasabb
        if (csoport[x[k]-1].nem == fiu &&
            csoport[x[k]-1].magassag < csoport[x[i]-1].magassag)
            return false;
    }
    return true;
}


void kiir(int *x, int n, int v, Tancos* csoport) {
    for (int i = 0; i < v; i++) {
        printf("%s(%d) ", csoport[x[i]-1].nev, csoport[x[i]-1].magassag);
        if (i==0) printf("- ");
    }
    printf("\n");
}