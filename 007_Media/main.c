/* 
 * Progettare e scrivere un programma che richieda in ingresso tre numeri
 * interi e ne restituisca la media aritmetica.
 * 
 */

#include <stdio.h>

int main() {
    
    int a, b, c;
    float media;  // perché float?
    printf("Inserisci il primo numero: \n");
    scanf("%d", &a);
    printf("Inserisci il secondo numero: \n");
    scanf("%d", &b);
    printf("Inserisci il terzo numero: \n");
    scanf("%d", &c);
    
    media = (float) (a+b+c)/3; // conversione da intero a float PRIMA della divisione
    /*
    1) n.b. è indispensabile l'uso delle parentesi 
       perché la divisione ha la precedenza sull'addizione
    2) cosa succede se non si effettua la conversione (casting) esplicitamente?
    // ad esempio: media = (a+b+c)/3;  
    */
    printf("La media dei 3 numeri inseriti è: %f\n", media);
    
    return 0;
}

