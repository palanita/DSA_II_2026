//
// Created by palan on 2/26/2026.
//

#include "function.h"

//0=ko
//1=papir
//2=ollo
int koPapirOllo(int *a, int n) {
    if (n>=0) {
        a[n] = rand()%3;
        koPapirOllo(a, n-1);
    }
}

void kiir(int *a, int n) {
    if (n>=0) {
        kiir(a,n-1);
        printf("[%d]: %d \n", n+1, a[n]);
    }
}

int bajnoksag(int *a, int i, int j) {
    int result;
    if (i == j) {
        return i;
    }else {

        int m1=bajnoksag(a,i,(i+j)/2);
        int m2=bajnoksag(a,(i+j)/2+1,j);

    /*
    *    1 nyer 0 ellen ||                 *
    *    2 nyer 1 ellen ||  0 nyer 2 ellen */
        if (a[m1]>a[m2] || (a[m1]==0 && a[m2]==2)) result=m1;
        else result = m2;

        //nyomon kovetes
        printf("Merkozes: [%d]: %d vs [%d]: %d \n Nyertes: [%d]\n", i+1,a[i], j+1,a[j], result+1);

        return result;
    }
}

