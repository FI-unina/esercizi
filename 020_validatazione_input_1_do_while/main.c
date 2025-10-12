/* 
 * Progettare e scrivere un programma che richieda all’utente l’inserimento 
 * di un intero fintantoché il valore inserito non rientra 
 * nell’intervallo [1, 12]
 */

#include <stdio.h>

int main() {
    int x;
    
    do{ 
        printf("Inserisci un valore tra 1 e 12: \n");
        scanf("%d", &x);

    }while(x>=1 && x<=12);
    
    printf("Il numero inserito è: %d\n", x);

    return 0;
}

