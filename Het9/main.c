#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void) {
    //1.feladat
    printf("\n1. feladat\n");
    FILE* input=fopen("tomb.txt","r");
    if (input == NULL) {
        printf("Error opening file");
    }
    int n;
    fscanf(input,"%d",&n);
    int *arr= calloc(n,sizeof(int));
    for(int i=0;i<n;i++) {
        fscanf(input,"%d",&arr[i]);
        printf("%d ",arr[i]);
    }
    printf("\nKeresett elem indexe: %d",binarySearchRecursive(arr,0,n,6));
    fclose(input);
    free(arr);

    //2.feladat
    printf("\n2. feladat\n");
    printf("\nn = ");
    scanf("%d", &n);

    // Dinamikus memóriafoglalás a mátrixnak
    char **matrix = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (char *)malloc(n * sizeof(char));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = '+'; // Alapértelmezésben minden elem '+'
        }
    }

    int **x = (int **)malloc(n * sizeof(int *));

    backtrack(x, n, 0, matrix);

    // Memória felszabadítása
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(x);

    //3.feladat
    printf("\n3. feladat\n");
    solve();
    return 0;
}
