//
// Created by palan on 2/26/2026.
//

#include "function.h"


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
    if (i == j) {
        return 1;
    }else {
        int m1=bajnoksag(a,i,(i+j)/2);
        int m2=bajnoksag(a,(i+j)/2+1,j);

        if (a[m1]>a[m2] || (a[m1]==0 && a[m2]==2)) return m1;
        else return m2;
    }
}

