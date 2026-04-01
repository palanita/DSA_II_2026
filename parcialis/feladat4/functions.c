//
// Created by palan on 3/29/2026.
//

#include "functions.h"

void masol(Pont utmin[], Pont ut[], int k, int *kmin,int bot, int *maxbot) {
    for (int i = 0; i <= k; i++) {
        utmin[i] = ut[i];
    }
    *kmin = k;
    *maxbot = bot;
}

void backtracking_erdesz(int a[][50], int n, int m, Pont ut[], Pont utmin[],
    int *kmin, int xk, int yk, int x, int y, int k, int bot ,int *maxbot) {
    ut[k].x = x;
    ut[k].y = y;
    if (x == xk && y == yk) {
        if (bot >= *maxbot && k < *kmin ) {
            masol(utmin, ut, k, kmin,bot, maxbot);
        }
        return;
    }
    int alatta = a[x][y];
    a[x][y] = FAL;
    if (x - 1 >= 0 && a[x - 1][y] == BOT) {
        backtracking_erdesz(a, n, m, ut, utmin, kmin, xk, yk,FEL, k + 1, bot+1, maxbot);
    }
    if(x - 1 >= 0 && a[x - 1][y] == SZABAD) {
        backtracking_erdesz(a, n, m, ut, utmin, kmin, xk, yk,FEL, k + 1, bot, maxbot);
    }
    if (x + 1 < n && a[x + 1][y] == BOT) {
        backtracking_erdesz(a, n, m, ut, utmin, kmin, xk, yk, LE, k + 1, bot+1, maxbot);
    }
    if (x + 1 < n && a[x + 1][y] == SZABAD) {
        backtracking_erdesz(a, n, m, ut, utmin, kmin, xk, yk, LE, k + 1, bot, maxbot);
    }

    if (y - 1 >= 0 && a[x][y - 1] == BOT) {
        backtracking_erdesz(a, n, m, ut, utmin, kmin, xk, yk, BAL, k + 1, bot+1, maxbot);
    }
    if (y - 1 >= 0 && a[x][y - 1] == SZABAD) {
        backtracking_erdesz(a, n, m, ut, utmin, kmin, xk, yk, BAL, k + 1, bot, maxbot);
    }
    if (y + 1 < m && a[x][y + 1] == BOT) {
        backtracking_erdesz(a, n, m, ut, utmin, kmin, xk, yk, JOBB, k + 1, bot+1, maxbot);
    }
    if (y + 1 < m && a[x][y + 1] == SZABAD) {
        backtracking_erdesz(a, n, m, ut, utmin, kmin, xk, yk, JOBB, k + 1, bot, maxbot);
    }
    a[x][y] = alatta;
}

void beolvas_erdo(int a[][50], int *n, int *m, const char *input){
    FILE *f = fopen(input, "r");
    if (f == NULL) {
        printf("A fajl nem nyithato meg!\n");
        return;
    }
    if (fscanf(f, "%d %d", n, m) != 2) {
        printf("Hiba a meretek beolvasasakor!\n");
    }
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            fscanf(f, "%d", &a[i][j]);
        }
    }
    fclose(f);
}

void kiir_erdo(int a[][50], int n, int m) {
    printf("\nBeolvasott erdo (%dx%d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void kiir_maxBotUt(Pont utmin[], int kmin, int maxbot) {
    if (kmin == INT_MAX) {
        printf("Nincs megoldas!\n");
    } else {
        printf("Botok szama: %d\n", maxbot);
        printf("Legtobb botot tartalmazo ut (%d lepes):\n", kmin);
        for (int i = 0; i <= kmin; i++) {
            printf("(%d,%d)%s", utmin[i].x, utmin[i].y, (i == kmin ? "" : " -> "));
        }
        printf("\n");
    }
}