//
// Created by palan on 5/10/2026.
//

#include "functions.h"

int postazas(int utca[], int n) {

    int adokKapok=0;
    int munka = 0;

    for (int i = 0; i < n; i++) {
        adokKapok += utca[i];
        munka += abs(adokKapok);
    }

    return munka;
}
