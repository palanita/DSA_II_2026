#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/*
 * Egy erdész úton a faháza felé, botot akar szedni,
 * hogy a kuckojában tűzet tudjon rakni.
 * Melyik úton tud a legtöbb botot szedni?
 * A botot 2-essel jelöljük,
 * a kikerülendő fenyőfákat 1-essel,
 * az szabad utat 0-ávval.
 * A bot csak a szabad úton található.
 */

int main(void) {
    int n, m, kx, ky, startX, startY;
    const char *file = "erdo.txt";
    FILE *f = fopen(file, "r");
    if (!f) return -1;
    if (fscanf(f, "%d %d", &n, &m)!=2) {
        printf("Beolvasasi hiba");
        exit(-2);
    }

    int (*a)[50] = malloc(n * sizeof(*a));
    if (a == NULL) {
        printf("Unsuccessful memory allocation\n");
        exit(-2);
    }

    Pont ut[2500], maxbot[2500];
    int kmin = INT_MAX;
    int botokSzama= INT_MIN;

    beolvas_erdo(a, &n, &m, file);

    startX = 0;
    startY = 0;
    //kunyho koordinátái
    kx = n - 1;
    ky = m - 1;

    kiir_erdo(a, n, m);
    backtracking_erdesz(a, n, m, ut, maxbot, &kmin, kx, ky, startX, startY, 0, 0, &botokSzama);
    kiir_maxBotUt(maxbot, kmin, botokSzama);
    fclose(f);
    free(a);
    return 0;
}

