#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

//n =
//k = 0 hany szint


int main(void) {
    Gy gyumolcsok2[] = {"alma", 2,"banan",3, "barack",12, "dinnye", 20 };
    int n;
    char gyumolcsok[][15]={"alma","banan", "barack", "dinnye"};
    printf("n = ");
    scanf("%d", &n);
    int v;
    printf("v = ");
    scanf("%d", &v);
    int *x= (int*)calloc(n, sizeof(int));
    if (!x) {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    BTP(x,n,0, gyumolcsok2);
    free(x);
    return 0;
}

