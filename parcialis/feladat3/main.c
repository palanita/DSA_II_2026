#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/*
 * Milyen sorrendekben ülhetnek fel a fiatalok
 * és az idősök a buszra, úgy, hogy az idősök előbb száljanak fel,
 * mint bármelyik fiatal.
 */
int main(void) {
    Utas utasok[]={
        "Mari neni", 1,
        "Petike", 0,
        "Bela bacsi", 1,
        "Anna", 0,
        "Eszter", 0,
        "Anti bacsi", 1,
        "Erzsi neni",1
    };
    int n = sizeof(utasok)/sizeof(utasok[0]);
    int *x= (int*)calloc(n, sizeof(int));
    if (!x) {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    BTP(x,n,0, utasok);
    free(x);
    return 0;
}