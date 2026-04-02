//
// Created by palan on 4/2/2026.
//

#ifndef LABOR_FUNCTIONS_H
#define LABOR_FUNCTIONS_H
#include <stdio.h>

typedef enum nem {
    FERFI=1,
    NO=2
}Nem;

typedef struct szemely {
    char* name;
    int age;
    Nem nem;
    int emelet;
}Szemely;
void beolvas(Szemely* szemelyek, int n, const char *input);
void kiir(Szemely* szemelyek, int n);


#endif //LABOR_FUNCTIONS_H