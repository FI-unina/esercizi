/* 
 * Progettare e scrivere un programma che prende 
 * in input un intero da 1 a 12 e stampa a video 
 * il nome del mese corrispondente (usare if-then-else)
 */

#include <stdio.h>


/*
 * 
 */
int main() {
    int n;
    printf("Inserisci un numero tra 1 e 12: \n");
    scanf("%d", &n);
    
    switch (n){
        default:
            printf("Valore non consentito! \n");
            break;
        case 1:
            {
            printf("Gennaio\n");
            break;
            }
        case 2:
            printf("Febbraio\n");
            break;
            
        case 3:
            printf("Marzo\n");
            break;
        
        case 4:
            printf("Aprile\n");
            break;

        case 5:
            printf("Maggio\n");
            break;

        case 6:
            printf("Giugno\n");
            break;            
            
        case 7:
            printf("Luglio\n");
            break;         
            
        case 8:
            printf("Agosto\n");
            break;            

        case 9:
            printf("Settembre\n");
            break;

        case 10:
            printf("Ottobre\n");
            break;
            
        case 11:
            printf("Novembre\n");
            break;            

        case 12:
            printf("Dicembre\n");
            break;
            
        
    }
    
    
    
    
    
    return 0;
}

