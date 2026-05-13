//
// Created by palan on 5/13/2026.
//

#include "functions.h"

int katonaIgenyles(Beosztas beosztasok[], int n) {
    if (beosztasok[0].start>beosztasok[0].end) return -1;
    int i = 0;
    for (int j = 1; j < n; j++) {
        //hiba ellenorzes
        if (beosztasok[j].start>beosztasok[j].end) return -1;
        if (beosztasok[i].end<beosztasok[j].end) i=j;
    }
    int napokSzama=beosztasok[i].end;

    int *osszegzes=calloc(napokSzama,sizeof(int));

    //beosztasok sorbavétele
    for (int i = 0; i < n; ++i) {
        //beosztasi idok egybeirasa
        for (int nap = beosztasok[i].start-1; nap <= beosztasok[i].end-1; ++nap) {
            osszegzes[nap]++;
        }
    }
    int max=0;

    for (int nap = 0; nap < napokSzama; nap++) {
        if (max<osszegzes[nap]) max=osszegzes[nap];
    }
    free(osszegzes);
    return max;
}

void beosztasKirajozolasa(Beosztas beosztasok[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < beosztasok[i].start-1; ++j) {
            printf(" ");
        }
        for (int nap = beosztasok[i].start-1; nap <= beosztasok[i].end-1; ++nap) {
            printf("-");
        }
        printf("\n");
    }
}

