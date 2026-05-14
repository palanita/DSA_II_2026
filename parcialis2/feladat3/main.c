#include <stdio.h>
#include "functions.h"

//Torony

int main(void) {
    Beosztas beosztasok[]={{6,10},
    {1,7},
    {3,9},
    {8,13},
    {5,7},
    };

    int n=sizeof(beosztasok)/sizeof(beosztasok[0]);
    beosztasKirajozolasa(beosztasok, n);
    int minKatona=katonaIgenyles(beosztasok, n);
    printf("Minimum katonai igenyles: %d", minKatona);
    return 0;
}