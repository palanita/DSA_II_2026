//
// Created by palan on 3/19/2026.
//

#ifndef LABOR_FUNCTIONS_H
#define LABOR_FUNCTIONS_H

typedef struct {
    char nev[15];
    float ar;
}Gy;
//Variacio
void BTV (int *x, int n, int k, int v);
bool validV(int *x, int n, int k, int v);
//Kombinacio
void BTK (int *x, int n, int k, int v);
bool validK(int *x, int n, int k, int v);
void kiir(int *x, int n, int k, int v);
//Kombinacio gyumolcsokkel
void charBTK (int *x, int n, int k, int v, char g[][15]);
void charKiir(int *x, int n, int k, int v, char g[][15]);
//Variacio structal
void vasarlasBTV (int *x, int n, int k, int v, Gy gyum [],float arStop);
bool valid3(int *x, int n, int k, int v, Gy gyum [], float arStop);
void vasarlasKiir(int *x, int n, int k, int v, Gy gyum []);
//reszhalmaz
void BTP (int *x, int n, int k, Gy gyum[]);
bool validP(int *x, int n, int k);
void kiirP(int *x, int n, int k, Gy gyum[]);







#endif //LABOR_FUNCTIONS_H