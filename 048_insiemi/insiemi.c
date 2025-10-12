#include <stdio.h>
#include "./insiemi.h"



void visualizza (int v[DIM], int riempv){
    for (int i=0; i<riempv; i++)
        printf("%d,", v[i]);
    printf("\n");
}

bool verifica_presenza(int v[DIM], int riempv, int valore){
    bool trovato = false;
    int i = 0;
    while(trovato==false && i < riempv)
        if (v[i] == valore)
            trovato = true;
        else
            i++;
    return trovato;   
}

void aggiungi(int v[DIM], int *riempv, int valore){

    if (verifica_presenza(v, *riempv, valore) == false && *riempv < DIM){
        v[*riempv] = valore;
        (*riempv)++;
    }
    return;
}

void intersezione(int v1[DIM], int riempv1, 
                  int v2[DIM], int riempv2, 
                  int v3[DIM], int *riempv3){

    for (int i=0; i<riempv1; i++){
        if (verifica_presenza(v2, riempv2, v1[i]))
            aggiungi(v3, riempv3, v1[i]);
    }

}


void unione(int v1[DIM], int riempv1, int v2[DIM], int riempv2, 
                  int v3[2*DIM], int *riempv3){

    for (int i=0; i<riempv1; i++)
        aggiungi(v3, riempv3, v1[i]);
    
    for (int i=0; i<riempv2; i++)
        aggiungi(v3, riempv3, v2[i]);
    
}

void differenza(int v1[DIM], int riempv1, int v2[DIM], int riempv2, int v3[DIM], int *riempv3){

    for (int i=0; i<riempv1; i++){
        
        if (verifica_presenza(v2, riempv2, v1[i])==false)
            aggiungi(v3, riempv3, v1[i]);
    }
    
    

}
