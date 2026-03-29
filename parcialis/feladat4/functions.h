//
// Created by palan on 3/29/2026.
//

#ifndef FELADAT4_FUNCTIONS_H
#define FELADAT4_FUNCTIONS_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define LE (x+1), y
#define FEL (x-1), y
#define BAL x, (y-1)
#define JOBB x, (y+1)
#define FAL 1
#define SZABAD 0
#define BOT 2

typedef struct {
    int x, y;
} Pont;

void masol(Pont utmin[], Pont ut[], int k, int *kmin, int bot, int *maxbot);
void backtracking_erdesz(int a[][50], int n, int m, Pont ut[], Pont utmin[], int *kmin, int xk, int yk, int x, int y, int k, int bot, int *maxbot);
void beolvas_erdo(int a[][50], int *n, int *m, const char *input);
void kiir_erdo(int a[][50], int n, int m);
void kiir_maxBotUt(Pont utmin[], int kmin, int maxbot);

#endif //FELADAT4_FUNCTIONS_H