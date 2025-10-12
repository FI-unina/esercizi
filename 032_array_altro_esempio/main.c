/*
 * Sviluppare un programma in C/C++ che:
 * -dichiara ed inizializza due vettori di 5 interi A e B;
 * -dichiara un vettore di 5 interi C;
 * -somma gli elementi omologhi di A e B e li deposita nel vettore C;
 * -stampa a video il vettore A, il vettore B ed il vettore C.
 */

#include <stdio.h>
#include <stdbool.h>

int main() {

    int A[5] = {1, 2, 3, 4, 5};
    int B[5];
    int C[5];

    // inizializza B:
    for (int i=0; i<5; i++){
        printf("inserisci l'elemento di posizione %d\n", i);
        scanf("%d", &B[i]);
    }
    
    printf("Il terzo elemento del vettore A è: %d\n", A[2]);
    
    printf("Vettore A\n");
    for (int i=0; i<5; i++)
        printf("%d ", A[i]);
    printf("\n");
    
    printf("Vettore B\n");
    for (int i=0; i<5; i++)
        printf("%d ", B[i]);
    printf("\n");
    
    for (int i=0; i<5; i++)
        C[i] = A[i] + B[i];
    
    printf("Vettore C\n");
    for (int i=0; i<5; i++)
        printf("%d ", C[i]);
    printf("\n");
    
    return 0;
}

