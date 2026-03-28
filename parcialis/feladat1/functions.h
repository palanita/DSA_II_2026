//
// Created by palan on 3/28/2026.
//

#ifndef FELADAT1_FUNCTIONS_H
#define FELADAT1_FUNCTIONS_H
#include <stdio.h>

typedef enum {
    fiu,
    lany,
}Nem;

typedef struct {
    char* nev;
    int magassag;
    Nem nem;
}Tancos;

void BT (int *x, int n, int k,int v, Tancos* csoport);
bool valid(int *x, int n, int k, Tancos* csoport);
void kiir(int *x, int n, int v, Tancos* csoport);


#endif //FELADAT1_FUNCTIONS_H