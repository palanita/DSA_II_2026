//
// Created by palan on 3/28/2026.
//

#ifndef FELADAT2_FUNCTIONS_H
#define FELADAT2_FUNCTIONS_H

#include <stdio.h>

typedef enum {
    liszt,
    cukor,
    eleszto,
    so,
    tej
}Hozzavalo;

void BTP (int *x, int n, int k ,Hozzavalo *hozzavalok);
bool valid(int *x, int k, Hozzavalo *hozzavalok);
void kiir(int *x, int n, Hozzavalo *hozzavalok);

#endif //FELADAT2_FUNCTIONS_H