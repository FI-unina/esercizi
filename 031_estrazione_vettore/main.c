/*
 * Sviluppare un programma che
 * - chiede all’utente quante estrazioni realizzare
 * - estrae per il numero di volte indicato dall’utente un numero da 1 a 90
 * - memorizza le estrazioni
 * - chiede all’utente di quale estrazione vuole visualizzare il risultato
 * - stampa il valore dell’estrazione corrispondente
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    
    // inizializzazione rand
    srand(time(NULL));
    
    int n_estrazioni;
        
    printf("Inserire il numero di estrazioni: \n");
    scanf("%d", &n_estrazioni);
    
    int v[n_estrazioni]; 
    
    // estrazione
    for(int i=0; i<n_estrazioni; i++){
        // memorizzo l'i-esima estrazione nella i-esima cella dell'array
        v[i] = 1+ rand()%90;  
    }

    for(int i=0; i<n_estrazioni; i++)
        // accedo all'i-esima cella dell'array
        printf("%d, ", v[i]);
    printf("\n");
    
    
    int x;
    printf("quale estrazione vuoi conoscere?\n");
    scanf("%d", &x);

    printf("Il valore dell'estrazione n. %d è: %d\n", x, v[x]);
    
    // come calcolare le frequenze?
    

    return 0;
}

