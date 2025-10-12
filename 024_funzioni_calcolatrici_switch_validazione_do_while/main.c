/* 
 * Progettare e scrivere un programma che
 * - Chiede all’utente di inserire due valori interi
 * - Chiede che operazione vuole svolgere (+, -, *, /, %)
 * - A seconda della risposta dell’utente, esegue il calcolo richiesto
 * - Stampa il risultato
 * 
 * Prevedere ed usare due funzioni:
 * - input_valida_operazione() che chiede all’utente di inserire un carattere 
 * fintantoché l’utente non inserisce un’operazione valida. 
 * La funzione restituisce l’operazione inserita dall’utente
 * - calcola(): prende in ingresso due operandi e l’operazione da eseguire e 
 * restituisce il risultato
*/

#include <stdio.h>

char input_valida_operazione();
int calcola(int a, int b, char op);

int main() {
    int numero1, numero2, r;
    
    char op = input_valida_operazione();  // chiamata della funzione
    
    // queste variabili possono essere inizializzate da stdin...
    numero1 = 10;  
    numero2 = 12;
    
    r = calcola(numero1, numero2, op);  // chiamata della funzione
    printf("Il risultato di %d %c %d è %d\n", numero1, op, numero2, r);
    
    return 0;
}

char input_valida_operazione(){
    char x;
    do{
        printf("Inserisci operazione (+,-,*,/,%%): \n");
        scanf("%c", &x);
        if(x!='+' && x!='-' && x!='*' && x!='/' && x!='%')
            printf("Operazione non valida!\n");
    }while(x!='+' && x!='-' && x!='*' && x!='/' && x!='%');

    return x;
}

int calcola(int a, int b, char op){
    int r;
    switch(op){
        case '+':
            r = a+b; 
        break;
        
        case '-':
            r = a-b;    
        break;
        
        case '*':
            r = a*b;
        break;
        
        case '/':
            r = a/b;
        break;
        
        case '%':
            r = a%b;
        break;
        
        default:
            printf("Operazione non valida!\n");
    }
    return r;
}