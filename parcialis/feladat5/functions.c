//
// Created by palan on 4/1/2026.
//

#include "functions.h"


void masol(Pont utmin[], Pont ut[], int k, int *kmin) {
    for (int i = 0; i <= k; i++) {
        utmin[i] = ut[i];
    }
    *kmin = k;
}

void backtracking_ballon(int a[][50], int n, int m, Pont ut[],
                         Pont utmin[], int *kmin, int xv, int yv, int x, int y, int k) {
    if (k>15) return;
    ut[k].x = x;
    ut[k].y = y;
    if (x == xv && y == yv) {
        if (k < *kmin) {
            masol(utmin, ut, k, kmin);
        }
        return;
    }
    int alatta = a[x][y];

    a[x][y] = INT_MAX;
    //észak (fel)
    if (x - 1 >= 0 && a[x - 1][y] < k) {
        backtracking_ballon(a, n, m, ut, utmin, kmin, xv, yv, x - 1, y, k + 1);
    }
    //kelet (jobb)
    if (y + 1 < m && a[x][y + 1] < k) {
        backtracking_ballon(a, n, m, ut, utmin, kmin, xv, yv, x, y + 1, k + 1);
    }
    //dél (le)
    if (x + 1 < n && a[x + 1][y] < k) {
        backtracking_ballon(a, n, m, ut, utmin, kmin, xv, yv, x + 1, y, k + 1);
    }
    //nyugat (bal)
    if (y - 1 >= 0 && a[x][y - 1] < k) {
        backtracking_ballon(a, n, m, ut, utmin, kmin, xv, yv, x, y - 1, k + 1);
    }
    //várakozás
    backtracking_ballon(a, n, m, ut, utmin, kmin, xv, yv, x, y, k + 1);

    a[x][y] = alatta;
}

void beolvas_hegyseg(int a[][50], int *n, int *m, const char *input) {
    FILE *f = fopen(input, "r");
    if (f == NULL) {
        printf("Hiba: A fajl nem nyithato meg!\n");
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

void kiir_hegyseg(int a[][50], int n, int m) {
    printf("\nBeolvasott hegysegek (%dx%d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf ("%d ", a[i][j]) ;
        }
        printf("\n");
    }
    printf("\n");
}

void kiir_utmin(Pont utmin[], int kmin) {
    if (kmin == INT_MAX) {
        printf("Nincs megoldas!\n");
    } else {
        printf("Legrovidebb ut (%d lepes):\n", kmin);
        for (int i = 0; i <= kmin; i++) {
            printf("(%d,%d)%s", utmin[i].x, utmin[i].y, (i == kmin ? "" : " -> "));
        }
        printf("\n");
    }
}
