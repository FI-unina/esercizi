/* 
 * Progettare e scrivere un programma che prende in input 
 * un intero da 1 a 12 e stampa a video il nome del mese corrispondente, 
 * in inglese o in italiano in base alla scelta dell’utente che seleziona 
 * la lingua all’avvio del programma

 */

#include <stdio.h>


int main() {
    int n, lingua;
    
    printf("Lingua/Language (1=ITA, 2=ENG) \n");
    scanf("%d", &lingua);
   
    if (lingua == 1){
        
        printf("Inserisci un numero tra 1 e 12: \n");
        scanf("%d", &n);
    
        switch (n){
            case 1:
                printf("Gennaio\n");
                break;

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

            default:
                printf("Valore non consentito! \n");
        } // fine switch
  
    }else if(lingua == 2){
    
            printf("Insert a number between 1 and 12: \n");
            scanf("%d", &n);
        
            switch (n){
            case 1:
                printf("January\n");
                break;

            case 2:
                printf("February\n");
                break;

            case 3:
                printf("March\n");
                break;

            case 4:
                printf("April\n");
                break;

            case 5:
                printf("May\n");
                break;

            case 6:
                printf("June\n");
                break;            

            case 7:
                printf("July\n");
                break;         

            case 8:
                printf("August\n");
                break;            

            case 9:
                printf("September\n");
                break;

            case 10:
                printf("October\n");
                break;

            case 11:
                printf("November\n");
                break;            

            case 12:
                printf("December\n");
                break;

            default:
                printf("Value not allowed! \n");
        } // fine switch
    
    }else
        printf("Lingua non valida! / Language not allowed!\n");
    
    return 0;
}

