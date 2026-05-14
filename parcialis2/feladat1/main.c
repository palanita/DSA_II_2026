#include <stdio.h>
#include "functions.h"

int main(void) {
    Film mozimuszor[] = {
        {1, "Batman", 10, 13},
        {2, "Eredet", 12, 15},
        {3, "Shrek", 13, 14},
        {4, "Gladiator", 15, 18},
        {5, "Matrix", 14, 17},
        {6, "Ponyvaregeny", 18, 21},
        {7, "Alien", 17, 19}
    };
    int n = sizeof(mozimuszor) / sizeof(mozimuszor[0]);

    moziNezes(mozimuszor, n);

    return 0;
}