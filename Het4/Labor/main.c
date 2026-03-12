#include <stdio.h>
#include <stdlib.h>

//n = hany tipusu adat pl. a kornyeken hany suli van
//k = aktualis szint pl. 14, szint (masodev)
void BTP (int *x, int n, int k);
bool valid(int *x, int n, int k);
void kiir(int *x, int n, int k);

int main(void) {
    int n;
    printf("n = ");
    scanf("%d", &n);
    int *x= (int*)calloc(n, sizeof(int));
    if (!x) {
        printf("Memory allocation failed\n");
        exit(-1);
    }
    BTP(x,n,0);
    free(x);
    return 0;
}

void BTP (int *x, int n, int k) {
    for (x[k] = 1; x[k] <= n; x[k]++) {
        if (valid(x,n,k)) {
            if (k<n-1) {
                BTP(x,n,k+1);
            }
            else  kiir(x,n,k);
        }
    }
}

bool valid(int *x, int n, int k) {
    for (int i = 0; i < k; i++) {
        if (x[k] == x[i]) return false;
    }
    return true;
}

void kiir(int *x, int n, int k)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

