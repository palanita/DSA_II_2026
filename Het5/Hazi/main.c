#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BTP (int *x, int n, int k, char* word);
bool valid(int *x, int n, int k);
void kiir(int *x, int n, int k, char* word);

int main(void) {
    char* word = calloc(15, sizeof(char));
    printf("Kerek egy szot: ");
    scanf("%s", word);
    int n = strlen(word);

    int *x= (int*)calloc(n, sizeof(int));
    if (!x) {
        printf("Memory allocation failed\n");
        exit(-1);
    }

    BTP(x,n,0, word);
    free(word);
    free(x);
    return 0;
}

void BTP (int *x, int n, int k, char* word) {
    for (x[k] = 1; x[k] <= n; x[k]++) {
        if (valid(x,n,k)) {
            if (k<n-1) {
                BTP(x,n,k+1, word);
            }
            else  kiir(x,n,k, word);
        }
    }
}

bool valid(int *x, int n, int k) {
    for (int i = 0; i < k; i++) {
        if (x[k] == x[i]) return false;
    }
    return true;
}

void kiir(int *x, int n, int k, char* word)
{
    for (int i = 0; i < n; i++) {
        printf("%c ", word[x[i]-1]);
    }
    printf("\n");
}

