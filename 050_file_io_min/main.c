/*
 * Progettare e scrivere un programma che legga una sequenza 
 * di interi da un file di testo, ne individui il minimo e lo stampi a video.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_DIM_FILE 1000

int main() {
    
    FILE *mio_file_input;
    char str[100];

    mio_file_input = fopen("dati_input.txt", "r");
    
    if(!mio_file_input){
        printf("File non trovato!\n");
        return 1;
    }
    else
        printf("Apertura file avvenuta con successo!\n");
    
    int numero;
    int minimo = INT_MAX;  // assumendo che tutti i valori sono strettamente minori di 1000

    while (fgets(str, MAX_DIM_FILE, mio_file_input) != NULL) {
        numero = atoi(str);
        if (numero < minimo)
            minimo = numero;
    }
    fclose(mio_file_input);
        
    printf("Il minimo è %d\n", minimo);

    return 0;
}

