#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/* Egy hőlégballon átszeretne menni a hegységeken,
 * hogy eljusson a kívánt tájra.
 * A hegységet felülnézetről látjuk,
 * a hegyek pedig a magasságukkal vannak jelölve. 1 = 100 m; 2 = 200m stb.
 * A hőlégballon minden lépésénél 100 méterrel fennebb repül így a k-val
 * számoljuk a magasságot.
 * A cél elérése érdekében, a hegyeket vagy kikerüli, vagy vár egyet, hogy
 * magasabbra repüljön.
 * Kérdés: melyik a legrövidebb út?
 */


int main(void) {
    int n, m, xv, yv, startX, startY;
    const char *file = "hegyseg.txt";
    FILE *f = fopen(file, "r");
    if (!f) return -1;
    fscanf(f, "%d %d", &n, &m);
    fclose(f);
    int (*a)[50] = malloc(n * sizeof(*a));
    if (a == NULL) {
        printf("Unsuccessful memory allocation\n");
        exit(-2);
    }
    Pont ut[2500], utmin[2500];
    int kmin = INT_MAX;
    beolvas_hegyseg(a, &n, &m, file);
    startX = 0;
    startY = 0;
    xv = n - 1;
    yv = m - 1;
    kiir_hegyseg(a, n, m);
    backtracking_ballon(a, n, m, ut, utmin, &kmin, xv, yv, startX, startY, 0);
    kiir_utmin(utmin, kmin);
    free(a);
    return 0;
}

