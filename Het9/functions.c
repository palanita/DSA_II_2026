#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
//
// Created by palan on 4/23/2026.
//
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) {
        return -8;
    }
    if (arr[left] == target) {
        return left;
    }
    if (arr[right] == target) {
        return right;
    }
    return binarySearchRecursive(arr, left + 1, right - 1, target);
}

bool valid(int **x, int n, int k, char **matrix) {
    //soronként haladunk
    int current_col = -1;
    // Megkeressük, hova tettük a csillagot az aktuális (k.) sorban
    for (int j = 0; j < n; j++) {
        if (matrix[k][j] == '*') {
            current_col = j;
            break;
        }
    }

    // Ellenőrizzük, hogy a korábbi sorokban (0-tól k-1-ig) van-e csillag ugyanabban az oszlopban
    for (int i = 0; i < k; i++) {
        if (matrix[i][current_col] == '*') {
            return false;
        }
    }
    return true;
}

void kiir(int **x, int n, int k, char **matrix) {
    static int count = 1;
    printf("%d. megoldas:\n", count++);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void backtrack(int **x, int n, int k, char **matrix) {
    // Ha k elérte n-t, minden sorba tettünk csillagot sikeresen
    if (k == n) {
        kiir(x, n, k, matrix);
        return;
    }

    // Végigpróbáljuk az összes oszlopot a k-adik sorban
    for (int j = 0; j < n; j++) {
        matrix[k][j] = '*'; // Beállítjuk a csillagot

        if (valid(x, n, k, matrix)) {
            backtrack(x, n, k + 1, matrix); // Rekurzió a következő sorra
        }

        matrix[k][j] = '+'; // Visszalépés (backtrack): visszaállítjuk '+' jelre
    }
}

int compare(const void *a, const void *b) {
    Interval *i1 = (Interval *) a;
    Interval *i2 = (Interval *) b;
    if (i1->start != i2->start)
        return i1->start - i2->start;
    return i2->end - i1->end; // Ha a kezdőpont azonos, a hosszabb legyen elöl
}

void solve() {
    FILE* f=fopen("bemenet.txt","r");
    if (f == NULL) {
        printf("Error opening file");
        return;
    }
    int n, m;
    if (fscanf(f, "%d %d", &n, &m) != 2) return;

    Interval intervals[n];
    for (int i = 0; i < n; i++) {
        fscanf(f,"%d %d", &intervals[i].start, &intervals[i].end);
    }
    fclose(f);
    // Rendezés kezdőpont szerint
    qsort(intervals, n, sizeof(Interval), compare);

    Interval result[n];
    int count = 0;
    int current_end = 0; // Eddig vagyunk lefedve
    int i = 0;
    int reachable = 0;

    // Mohó választás
    while (current_end < m) {
        int best_idx = -1;
        int max_reach = -1;

        // Megkeressük az összes olyan intervallumot, ami lefedi a jelenlegi végét,
        // és kiválasztjuk közülük azt, ami a legmesszebbre nyúlik.
        while (i < n && intervals[i].start <= current_end) {
            if (intervals[i].end > max_reach) {
                max_reach = intervals[i].end;
                best_idx = i;
            }
            i++;
        }

        // Ha nem találtunk olyan intervallumot, ami folytatná a lefedést
        if (best_idx == -1 || max_reach <= current_end) {
            printf("Nem fedhető le a teljes szakasz.\n");
            return;
        }

        // Kiválasztjuk a legjobbat
        result[count++] = intervals[best_idx];
        current_end = max_reach;

        if (current_end >= m) break;
    }

    // Kimenet kiírása
    printf("%d\n", count);
    for (int j = 0; j < count; j++) {
        printf("(%d,%d)%c", result[j].start, result[j].end, (j == count - 1 ? '\n' : ' '));
    }
}
