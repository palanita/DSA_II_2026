#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(void) {
    //1.feladat
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

    //2.feladat

    return 0;
}
