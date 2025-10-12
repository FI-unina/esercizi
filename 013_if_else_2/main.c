#include <stdio.h>


/*
 Scrivere un programma che, inserito un numero intero da tastiera, 
 * dice se il numero è maggiore di 10, minore di 10 oppure uguale a 10
 */

int main() {
    int n;
    printf("Inserisci un numero: \n");
    scanf("%d", &n);
    
    
    if(n>10)
        printf("Il numero inserito è maggiore di 10\n"); 
    else{
        if (n==10)
            printf("Il numero inserito è uguale a 10\n");
        else
            printf("Il numero inserito è minore di 10\n");
    }
    
    return 0;
}

