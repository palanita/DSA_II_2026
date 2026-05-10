//
// Created by palan on 5/6/2026.
//

#include "functions.h"

int hasonlit(const void *a, const void *b) {
    Film *f1 = (Film *)a;
    Film *f2 = (Film *)b;
    return (f1->end - f2->end);
}

void moziNezes(Film filmek[], int n) {
    // Rendezés a befejezési idő szerint
    qsort(filmek, n, sizeof(Film), hasonlit);

    printf("A kovetkezo filmeket tudod megnezni:\n");

    // Az első film (ami a leghamarabb véget ér) mindig benne van
    int i = 0;
    printf("%d. %s (Idotartam: %d - %d)\n", filmek[i].id, filmek[i].name, filmek[i].start, filmek[i].end);
    int db = 1;

    // A többi film ellenőrzése
    for (int j = 1; j < n; j++) {
        // Ha a következő film akkor kezdődik vagy később, mint ahogy az előző véget ért
        if (filmek[j].start >= filmek[i].end) {
            printf("%d. %s (Idotartam: %d - %d)\n", filmek[j].id, filmek[j].name, filmek[j].start, filmek[j].end);
            i = j; // utolsó megnézett film
            db++;
        }
    }
    printf("\nOsszesen megnezheto filmek szama: %d\n", db);
}