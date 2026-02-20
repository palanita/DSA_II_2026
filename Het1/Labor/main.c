#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(void) {
    int n;
    printf("Elemek szama: ");
    scanf("%i", &n);
    int *v = (int*)malloc(n*sizeof(int));
    if (!v) {
        printf("Memory allociation error");
    }
    readElementsRecursive(v,n-1);
    printf("A tomb elemei: ");
    printElementsRecursive(v,n-1);
    printf("\nSum: %i\n", sumElementsRecursive(v, n-1));
    printf("Pozitiv szamok szama: %i\n", countPositiveElementsRecursive(v, n-1));
    printf("Min szam: %i\n", minElementRecursive(v, n-1));
    free(v);
    return 0;
}
