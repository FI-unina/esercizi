#include <stdio.h>

int main() {

    int v[3] = {25, 28, 34};
    int * pzero = &v[0];  // pzero punta all'elemento di indice 0
    int * puno = &v[1];   // puno punta all'elemento di indice 1
    int * pdue = &v[2];   // pdue punta all'elemento di indice 2
    int * pv = v;
    
    /* il nome dell'array senza parentesi quadre è un riferimento 
     * costante che coincide con il puntatore al primo elemento
     */ 
    printf("pv == pzero: %d\n", (pv == pzero)); // stampa 1, cioè true
    
    printf("valore dell'intero in indice 1: %d", *puno);
    
    // aritmetica dei puntatori.
    // pzero+i punta alla locazione di memoria che si trova i posizioni dopo pzero
    
    printf("valore dell'intero in indice 2: %d\n", *(pzero+2));
    
    return 0;
}

