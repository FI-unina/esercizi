/* 
 * Scrivere un programma che implementi le funzionalità di una calcolatrice.
 * Il programma:
 * - Chiede all’utente di inserire due valori inter
 * - Chiede che operazione vuole svolgere (+, -, *, /, %)
 * - A seconda della risposta dell’utente, esegue il calcolo richiesto
 * - Stampa il risultato
 */

#include <stdio.h>

int main() {
    int a, b, r;
    char op;
    
    printf("Inserisci primo operando: \n");
    scanf("%d", &a);
    printf("Inserisci secondo operando: \n");
    scanf("%d", &b);
    
    printf("Scegli operazione (+,-,*,/,%%): \n");
    scanf(" %c", &op); 

    /*
    NOTE: l'istruzione scanf("%c", &op); senza lo spazio non funzionerà perchè 
    la scanf("%d", &b); include un carattere \n che sarà letto dalla scanf successiva
    senza poter leggere il carattere richiesto. Per questo si antepone uno spazio vuoto
    nella scanf successiva. Per risolvere il problema è possibile usare anche sscanf
    */

    switch(op){
        case '+':
            r = a+b;
            printf("Il risultato di %d + %d è %d\n", a, b, r);
        break;
        
        case '-':
            r = a-b;
            printf("Il risultato di %d - %d è %d\n", a, b, r);
        break;
        
        case '*':
            r = a*b;
            printf("Il risultato di %d * %d è %d\n", a, b, r);
        break;
        
        case '/':
            r = a/b;
            printf("Il risultato di %d / %d è %d\n", a, b, r);
        break;
        
        case '%':
            r = a%b;
            printf("Il risultato di %d %% %d è %d\n", a, b, r);
        break;
        
        default:
            printf("Operazione non esistente!\n");
            
    }
   
    return 0;
}

