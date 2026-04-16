#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int main(void) {
    FILE *be = fopen("lap.in", "r");
    FILE *ki = fopen("lap.out", "w");
    if (be == NULL) return 1;
    int n;
    fscanf(be, "%d", &n);

    Etel *etelek = (Etel *)malloc(n * sizeof(Etel));

    beolvas_etelek(be,etelek,n,0);

    //Rendezés az elkészítési idő szerint
    qsort(etelek, n, sizeof(Etel), hasonlit);

    double atlag = ossz_varakozas(etelek, n, 0, 0.0) / n;

    // Kiírás a file-ba
    fprintf(ki, "%.2f\n", atlag);
    kiir_sorrend(ki,etelek,n,0);

    free(etelek);
    fclose(be);
    fclose(ki);

    return 0;
}