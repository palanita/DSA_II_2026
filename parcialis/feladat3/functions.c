//
// Created by palan on 3/29/2026.
//

#include "functions.h"

void BTP(int *x, int n, int k, Utas *utasok) {
    for (x[k] = 1; x[k] <= n; x[k]++) {
        if (valid(x, n, k, utasok)) {
            if (k < n - 1) {
                BTP(x, n, k + 1, utasok);
            } else kiir(x, n, k, utasok);
        }
    }
}

bool valid(int *x, int n, int k, Utas *utasok) {
    for (int i = 0; i < k; i++) {
        if (x[k] == x[i]) return false;
    }
    //ha fiatal
    if (!utasok[x[k] - 1].idos) {
        // ellenőrizzük, van-e a Teljes Utaslistában olyan idős,
        // aki még nincs benne az eddigi sorrendben
        for (int i = 1; i <= n; i++) {
            if (utasok[i - 1].idos) {
                bool mar_sorban_van = false;
                for (int j = 0; j < k; j++) {
                    if (x[j] == i) {
                        mar_sorban_van = true;
                        break;
                    }
                }
                // Ha találtunk olyan időst, aki még várakozik, a fiatal nem jöhet
                if (!mar_sorban_van) return false;
            }
        }
    }
    return true;
}

void kiir(int *x, int n, int k, Utas *utasok) {
    printf("busz ");
    for (int i = 0; i < n; i++) {
        printf("<-%s ", utasok[x[i] - 1].name);
    }
    printf("\n");
}
