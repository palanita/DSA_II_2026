//
// Created by palan on 5/13/2026.
//

#include "functions.h"

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int megold(int n, int m, int M[][4]) {
    int eredmeny = -1;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (M[i-1][j-1] != 0 && //bal-fent
                M[i-1][j] != 0 &&  //fent
                M[i][j-1] != 0) {  //bal
                    M[i][j] = min(min(M[i-1][j-1],M[i-1][j]), M[i][j-1]) + 1; //min + 1
                    eredmeny = max(eredmeny, M[i][j]);
                }
        }
    }

    return eredmeny;
}