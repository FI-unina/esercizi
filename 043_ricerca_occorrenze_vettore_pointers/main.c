/* 
 * Scrivere una funzione che dato un vettore (di interi), 
 * il suo riempimento ed un numero, restituisca un valore booleano che 
 * indichi se il numero è presente nel vettore.
 * Modificare la funzione in modo che restituisca anche la posizione dell’elemento
 * due parametri di output.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAXDIM 50


bool ricerca1(int v[], int riemp, int valore_da_cercare);
void ricerca2(int v[], int riemp, int valore_da_cercare, bool *trovato, int *posizione);
void ricerca3(int *v, int riemp, int valore_da_cercare, bool *trovato, int *posizione);

int main() {
    
    int vettore[MAXDIM] = {10, 12, 17, 3, 5, 17};
    int riemp = 6;
    int valore; 
    printf("Inserisci un numero da cercare: \n");
    scanf("%d", &valore);
    
    // chiamata a ricerca1
    bool esito = ricerca1(vettore, riemp, valore);
    if (esito == true)
        printf("Il valore %d è presente nel vettore!\n", valore);
    else
        printf("Il valore %d NON è presente nel vettore!\n", valore);
    
    printf("Inserisci un numero da cercare: \n");
    scanf("%d", &valore);

    // chiamata a ricerca2
    int pos;
    ricerca2(vettore, riemp, valore, &esito, &pos);
    if (esito == true){
        printf("Il valore %d è presente nel vettore in posizione %d\n", valore, pos);
    }
    else
        printf("Il valore %d NON è presente nel vettore!\n", valore);


    printf("Inserisci un numero da cercare: \n");
    scanf("%d", &valore);
    
    // chiamata a ricerca3
    ricerca3(vettore, riemp, valore, &esito, &pos);
    if (esito == true){
        printf("Il valore %d è presente nel vettore in posizione %d\n", valore, pos);
    }
    else
        printf("Il valore %d NON è presente nel vettore!\n", valore);

    return 0;
}

bool ricerca1(int v[], int riemp, int valore_da_cercare){
    bool trovato = false;
    int i = 0;
    while(i<riemp && trovato==false){
        
        if(v[i]==valore_da_cercare)
            trovato = true;
        i++;
    }
    return trovato;
}

void ricerca2(int v[], int riemp, int valore_da_cercare, bool *trovato, int *posizione){

    *trovato = false;

    int i = 0;

    while(i<riemp && *trovato == false){
        
        if(v[i] == valore_da_cercare)
            *trovato = true;
        else
            i++;
    }
    if (*trovato)
        *posizione = i;
    else
        *posizione = -1;   
    return;
}

void ricerca3(int * v, int riemp, int valore_da_cercare, bool *trovato, int *posizione){

    *trovato = false;

    int i = 0;

    while(i<riemp && *trovato == false){
        
        if(*(v+i) == valore_da_cercare)
            *trovato = true;
        else
            i++;
    }
    if (*trovato)
        *posizione = i;
    else
        *posizione = -1;   
    return;
}