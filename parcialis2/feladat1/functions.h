//
// Created by palan on 5/6/2026.
//

#ifndef FELADAT1_FUNCTIONS_H
#define FELADAT1_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>

    typedef struct {
        int id;     // Film sorszáma
        char* name; // Film címe
        int start;  // Kezdési idő (pl. 10 óra)
        int end;    // Befejezési idő (pl. 12 óra)
    } Film;

int hasonlit(const void *a, const void *b);
void moziNezes(Film filmek[], int n);
#endif //FELADAT1_FUNCTIONS_H