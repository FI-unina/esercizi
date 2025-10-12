/* 
 *
 * Scrivere un programma che richieda un numero intero all’utente e 
 * poi stampi a video il testo: 
 * "Il numero inserito è:” seguito dal numero inserito"
 * 
 */

#include <stdio.h>

int main() {
    
    // dichiarazione della variabile che ospiterà il numero intero
    int numero_input;
    
    // Richiedere di inserire un numero intero
    printf("Inserisci un numero intero: \n");
    
    // Inserire del numero intero
    scanf("%d", &numero_input);
    
    // Stampa
    printf("Il numero inserito e': %d\n", numero_input); 
    
    return 0;
}

