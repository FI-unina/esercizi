/*
 * Obiettivo: contare quante volte è uscita una particolare estrazione
 * 1- Chiedi all’utente il numero di estrazioni da effettuare
 * 2- Estrai un intero a caso da 0 a 2
 * 3- Incrementa il contatore relativo al valore uscito
 * 4- Ripeti dal punto 2 per il numero di estrazioni richieste dall’utente
 * 5- Per ciascuno dei valori usciti stampa il valore, 
 *    il numero di estrazioni sul totale, 
 *    e la frequenza di quel valore sul totale delle estrazioni
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // inizializzazione random...
    int seed = time(NULL); 
    srand(seed);
    
    int n_estrazioni;
    printf("Quante estrazioni? \n");
    scanf("%d", &n_estrazioni);
    
    int cont0 = 0;
    int cont1 = 0;
    int cont2 = 0;

    printf("L'utente ha chiesto %d estrazioni.\n", n_estrazioni);
    printf("I valori estratti sono stati: \n");

    for (int i=1; i<=n_estrazioni; i++){
        
        int estratto = rand()%3;
        
        printf("%d, ", estratto);
        
        if (estratto == 0)
            cont0++;
        else if (estratto == 1)
            cont1++;
        else
            cont2++;
    }
    
    printf("\n");
    
    // calcolo frequenze:
    
    printf("valore 0 estratto %d volte su %d (%f)\n", cont0, n_estrazioni, (float)(cont0)/n_estrazioni);
    printf("valore 1 estratto %d volte su %d (%f)\n", cont1, n_estrazioni, (float)(cont1)/n_estrazioni);
    printf("valore 2 estratto %d volte su %d (%f)\n", cont2, n_estrazioni, (float)(cont2)/n_estrazioni);

    
    
    return 0;
}

