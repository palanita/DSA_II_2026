//
// Created by palan on 4/2/2026.
//

#include "functions.h"


void beolvas(Szemely* szemelyek, int n, const char *input) {
     FILE *f = fopen(input, "r");
     if (f == NULL) {
         printf("Hiba: A fajl nem nyithato meg!\n");
         return;
     }
    if (fscanf(f, "%d", n)!=1) return;
    for (int i = 0; i < n; i++) {
        fscanf(f, "%s", szemelyek[i].name);
        fscanf(f, "%d %d %d", &szemelyek[i].age, &szemelyek[i].nem, &szemelyek[i].emelet);
    }
    fclose(f);
}

void kiir(Szemely *szemelyek, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", szemelyek[i].name);
        printf("%d, %d, %d\n", szemelyek[i].age, szemelyek[i].nem, szemelyek[i].age);
    }
}
