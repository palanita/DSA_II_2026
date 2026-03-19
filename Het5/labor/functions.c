//
// Created by palan on 3/19/2026.
//

#include "functions.h"
#include <stdio.h>


void BTV (int *x, int n, int k, int v) {
    for (x[k] = 1; x[k] <= n; x[k]++) {
        if (validV(x,n,k,v)) {
            if (k<v-1) {
                BTV(x,n,k+1,v);
            }
            else  kiir(x,n,k,v);
        }
    }
}

void BTK (int *x, int n, int k, int v) {
    for (x[k] = 1; x[k] <= n; x[k]++) {
        if (validK(x,n,k,v)) {
            if (k<v-1) {
                BTK(x,n,k+1,v);
            }
            else  kiir(x,n,k,v);
        }
    }
}
void charBTK (int *x, int n, int k, int v, char g[][15]) {
    for (x[k] = 1; x[k] <= n; x[k]++) {
        if (validK(x,n,k,v)) {
            if (k<v-1) {
                charBTK(x,n,k+1,v,g);
            }
            else  charKiir(x,n,k,v,g);
        }
    }
}

bool validK(int *x, int n, int k, int v) {
    for (int i = 0; i < k; i++) {
        if (x[k] <= x[i]) return false;
    }
    return true;
}

bool validV(int *x, int n, int k, int v) {
    for (int i = 0; i < k; i++) {
        if (x[k] == x[i]) return false;
    }
    return true;
}

void kiir(int *x, int n, int k, int v)
{
    for (int i = 0; i < v; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void charKiir(int *x, int n, int k, int v, char g[][15]) {
    for (int i = 0; i < v; i++) {
        printf("%s ", g[x[i]-1]);
    }
    printf("\n");
}

void vasarlasBTV(int *x, int n, int k, int v, Gy gyum [], float arStop) {
    for (x[k] = 1; x[k] <= n; x[k]++) {
        if (valid3(x,n,k,v,gyum,arStop)) {
            if (k<v-1) {
                vasarlasBTV(x,n,k+1,v, gyum , arStop);
            }
            else  vasarlasKiir(x,n,k,v, gyum);
        }
    }
}

bool valid3(int *x, int n, int k, int v, Gy gyum[], float arStop) {
    for (int i = 0; i < k; i++) {
        if (x[k] == x[i]) return false;
    }
    if (k==v) {
        float sum = 0;
        for (int i = 0; i < k; i++) {
            sum += gyum[x[i]-1].ar;
            if(sum >= arStop){
                return false;
            }
        }
    }
    return true;
}

void vasarlasKiir(int *x, int n, int k, int v, Gy gyum[]) {
    for (int i = 0; i < v; i++) {
        printf("  %s,  %f lej", gyum[x[i]-1].nev, gyum[x[i]-1].ar);
    }
    printf("\n");
}

void BTP(int *x, int n, int k, Gy gyum[]) {
    for (x[k] = 0; x[k] <= 1; x[k]++) {
        if (validP(x,n,k)) {
            if (k<k-1) {
                BTP(x,n,k+1, gyum);
            }
            else  kiirP(x,n,k, gyum);
        }
    }
}

bool validP(int *x, int n, int k) {
    return true;
}

void kiirP(int *x, int n, int k, Gy gyum[]) {
    for (int i = 0; i < n; i++) {
        if (x[i] != 0) {
            printf("%s ", gyum[i].nev);
        }
    }
    printf("\n");
}
