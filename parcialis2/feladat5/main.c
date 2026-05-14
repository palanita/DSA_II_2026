#include <stdio.h>
#include "functions.h"

/*
Adott egy 𝑛 soros és 𝑚 oszlopos bitmátrix. Határozzuk meg a legnagyobb
olyan négyzet oldalhosszát, amely a mátrixban található és csak 1-eseket tartalmaz!
*/
int main(void) {
    int n = 3, m = 4;
    int M[3][4] = {
        {0, 1, 1, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1}
    };
    
    printf("%d", megold(n, m, M));
    return 0;
}