/* 
 * Progettare e scrivere un programma che richieda all’utente 
 * l’inserimento di un carattere fintantoché il carattere inserito non 
 * è uguale ad uno tra: '+', '-', '*', '/', '%'
 */

#include <stdio.h>


int main() {
    char x;
    
    do{ 
        printf("Scegli tra: +, -, *, /\n");
        scanf(" %c", &x); //aggiungo un spazio prima del %c in modo da fare l'escape del carattere \n dovuto alla pressione dell'INVIO

        if (x!='+' && x!='-' && x!='*' && x!='/' && x!='%')
            printf("Il carattere inserito non è valido!!!\n");
        
    } while(x!='+' && x!='-' && x!='*' && x!='/' && x!='%');
    
    printf("\nIl carattere inserito è: %d\n", x);

    // while(!(x=='+' || x=='-' || x=='*' || x=='/' || x=='%'))
    
    return 0;
}

