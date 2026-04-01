#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

/* Milyen sorrendben tehetjük össze a süti hozzávalókat,
 * hogy a közvetlenül az élesztő előtt és után ne
 * adjunk hozzá a sót? (permutáció)
 */
int main(void) {
    Hozzavalo hozzavalok[]={cukor, liszt, eleszto, so, tej};
    int n=sizeof(hozzavalok)/sizeof(hozzavalok[0]);
    int *x= (int*)calloc(n, sizeof(int));
    if (!x) {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    BTP(x,n,0, hozzavalok);
    free(x);    return 0;
}