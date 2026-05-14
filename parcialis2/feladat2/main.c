#include <stdio.h>
#include "functions.h"

//Tokaj

int main(void) {
    int n = 6;
    int utca[] = {-2, 0, 0, 0, 0, 2};

    int munka = postazas(utca, n);

    printf("%d", munka);

    return 0;
}