#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/* Egy tánccsoportban ki kivel tud párba állni úgy
 * hogy egy fiúhoz ne kerüljön nála magasabb lány?
 * Csak egy fiú és egy lány állhat párba.
 * Mindenkire irjuk ki, hogy kivel tud párba állni! (variáció)
 */
int main(void) {
    Tancos csoport[] = {
        "Bela", 182, fiu,
        "Peter", 145, fiu,
        "Anna", 167, lany,
        "Kata", 150, lany
    };
    int n=4; //ennyien vannak a tancccsoportban
    int v=2; //párba állnak
    int *x= (int*)calloc(n, sizeof(int));
    if (!x) {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    BT(x,n,0,v, csoport);
    free(x);
    return 0;
}