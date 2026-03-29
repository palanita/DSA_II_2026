//
// Created by palan on 3/29/2026.
//

#ifndef FELADAT3_FUNCTIONS_H
#define FELADAT3_FUNCTIONS_H
#include <stdlib.h>
#include <stdio.h>

typedef struct utas {
    char* name;
    bool idos;
}Utas;

void BTP (int *x, int n, int k, Utas *utasok);
bool valid(int *x, int n, int k, Utas *utasok);
void kiir(int *x, int n, int k, Utas *utasok);
#endif //FELADAT3_FUNCTIONS_H