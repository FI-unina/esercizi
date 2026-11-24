#include <stdio.h>


/*
 * Scrivere un programma che, inserito un numero intero da tastiera, 
 * dice se il numero è positivo, negativo o nullo pari o dispari
 */

int main() {
    int n;
    printf("Inserisci un numero: \n");
    scanf("%d", &n);
    
    if (n==0){
        printf("Il numero inserito è NULLO\n");
        printf("Il numero inserito è PARI\n");
        }
    else{
        if(n>0){
            printf("Il numero inserito è POSITIVO\n");
        }
        else{
            printf("Il numero inserito è NEGATIVO\n");
        }
        
        if (n%2==0){
            printf("Il numero inserito è PARI\n");
        }
        else{
            printf("Il numero inserito è DISPARI\n");
        }        
    }
    return 0;
}

