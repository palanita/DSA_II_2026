//
// Created by palan on 4/1/2026.
//

#ifndef FELADAT5_FUNCTIONS_H
#define FELADAT5_FUNCTIONS_H
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int x, y;
} Pont;

void masol(Pont utmin[], Pont ut[], int k, int *kmin);
void backtracking_ballon(int a[][50], int n, int m, Pont ut[],
    Pont utmin[], int *kmin, int xv, int yv, int x, int y, int k);
void beolvas_hegyseg(int a[][50], int *n, int *m, const char *input);
void kiir_hegyseg(int a[][50], int n, int m);
void kiir_utmin(Pont utmin[], int kmin);

#endif //FELADAT5_FUNCTIONS_H