//
// Created by palan on 5/13/2026.
//

#ifndef FELADAT3_FUNCTIONS_H
#define FELADAT3_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>

    typedef struct {
        int start;  // Kezdési nap (pl. 5. naptól)
        int end;    // Befejezési nap
    } Beosztas;

int katonaIgenyles(Beosztas beosztasok[], int n);
void beosztasKirajozolasa(Beosztas beosztasok[], int n);
#endif //FELADAT3_FUNCTIONS_H