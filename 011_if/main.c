#include <stdio.h>

/*
 * Scrivere un programma che, inserito un numero intero da tastiera, 
 * stampa a video un messaggio se il numero è maggiore di 10
 */

int main() {
    int n;
    printf("Inserisci un numero: \n");
    scanf("%d", &n);
    
    if(n>10){
        printf("Il numero inserito è maggiore di 10\n");
        // poiché il blocco è costituito da una sola istruzione,
        // le parentesi graffe potevano essere omesse.
    }
    
    // cosa succede se il numero inserito è minore o uguale a 10?
    
    return 0;
}

