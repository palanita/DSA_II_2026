#include <stdio.h>
#include <stdlib.h>

#include "function.h"

int main(void) {
    srand (time(NULL));
    int n;
    printf("Tagok szama: ");
    scanf("%d",&n);
    int *a= malloc(n * sizeof(int));

    koPapirOllo(a, n-1);
    kiir(a, n-1);
    printf("%d szamu tag nyert", bajnoksag(a, 0, n-1)+1);

    free(a);
    return 0;
}
