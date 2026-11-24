/* 
 * 
 * 1. Estrai un intero a caso da 1 a 5
 * 2. Chiedi all’utente di indovinare il numero
 * 3. Se non ha indovinato: ripeti dal passo 1
 * 4. Altrimenti stampa "Complimenti, hai indovinato!" e termina il programma
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXNUM 5


int main() {

    int seed = time(NULL); 
    srand(seed);
    int numeroGrande = rand();
    int numero = 1 + (numeroGrande % MAXNUM);

    int tentativo;
    
    do{
        printf("Indovina il numero (a 1 a %d)!\n", MAXNUM);
        scanf("%d", &tentativo);
        
        if (tentativo != numero)
            printf("Sbagliato! Ritenta...\n");
        
    }while(tentativo != numero);

    printf("Complimenti, hai indovinato\n");
        
    return 0;
}

