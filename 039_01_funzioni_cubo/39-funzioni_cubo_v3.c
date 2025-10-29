/* programma che calcola e stampa il cubo dei primi n numeri interi */
#include <stdio.h>

double calcola (int x) {
    return x*x*x;
}

int main() {
    int i, n;
    printf("Dammi un numero e ti calcolo i cubi\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        printf("Il cubo di %d e' : %.0f\n", i, calcola(i));
}
