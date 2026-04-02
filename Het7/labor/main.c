#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void) {
    int n;
    const char *file = "szemelyek.txt";
    FILE *f = fopen(file, "r");
    if (!f) return -1;
    fscanf(f, "%d", &n);
    fclose(f);
    printf("%d\n", n);
    Szemely *szemelyek= calloc(n, sizeof(Szemely));

    beolvas(szemelyek, n, file);
    kiir(szemelyek, n);

    free(szemelyek);

    return 0;
}
