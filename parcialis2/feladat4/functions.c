//
// Created by palan on 5/13/2026.
//

#include "functions.h"


long long _lepcso(int n, long long* memoria) {
    // ha mar kiszamoltam, akkor emlekszem ra
    if (memoria[n] != 0) return memoria[n];
    // kulonben kiszamolom
    memoria[n] = (
        _lepcso(n - 1, memoria) + 
        _lepcso(n - 2, memoria) + 
        _lepcso(n - 3, memoria)
    );
    return memoria[n];
}

long long lepcso(int n) {
    long long *memoria = calloc(n, sizeof(long long));
    memoria[1] = 1;
    memoria[2] = 2;
    memoria[3] = 4;

    int eredmeny = _lepcso(n, memoria);

    free(memoria);
    return eredmeny;
}