//
// Created by anita on 4/16/26.
//

#ifndef LABOR_FUNCTIONS_H
#define LABOR_FUNCTIONS_H
#include <stdio.h>

// Étterem feladat
typedef struct {
    int id;    // Sorszám
    int ido;   // Elkészítési idő
} Etel;

int hasonlit(const void *a, const void *b);
double ossz_varakozas(Etel *etelek, int n, int i, double elozo_ido);
void kiir_sorrend(FILE *ki, Etel *etelek, int n, int i);
void beolvas_etelek(FILE *be, Etel *etelek, int n, int i);
//


#endif //LABOR_FUNCTIONS_H