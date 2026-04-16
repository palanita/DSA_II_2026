//
// Created by anita on 4/16/26.
//

#include "functions.h"

//Étterem feladat
int hasonlit(const void *a, const void *b) {
    Etel *e1 = (Etel *)a;
    Etel *e2 = (Etel *)b;
    return e1->ido - e2->ido;
}

double ossz_varakozas(Etel *etelek, int n, int i, double elozo_ido) {
    if (i == n) {
        return 0;
    }
    return elozo_ido + etelek[i].ido + ossz_varakozas(etelek, n, i + 1, elozo_ido + etelek[i].ido);
}

void kiir_sorrend(FILE *ki, Etel *etelek, int n, int i) {
    if (i == n) return;
    fprintf(ki, "%d ", etelek[i].id);

    kiir_sorrend(ki, etelek, n, i + 1);
}

void beolvas_etelek(FILE *be, Etel *etelek, int n, int i) {
    if (i == n) {
        return;
    }

    etelek[i].id = i + 1;
    if (fscanf(be, "%d", &etelek[i].ido) != 1) {
        return; // Hibakezelés, ha váratlanul véget ér a fájl
    }

    beolvas_etelek(be, etelek, n, i + 1);
}
//