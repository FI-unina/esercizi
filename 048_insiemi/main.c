#include <stdio.h>
#include "./insiemi.h"

/*
 * 
 */
int main() {

    int v[DIM];
    int r = 0;
    
    int w[DIM];
    int rr = 0;
    
    int vinter[DIM];
    int r_inter = 0;
    
    int vunione[2*DIM];
    int r_unione = 0;
    
    int vdiff[DIM];
    int r_diff = 0;
    
        printf("inserimento valori v\n");
    for (int i=0; i<5; i++){
        int numero;
        printf("valore da aggiungere all'insieme: \n");
        scanf("%d", &numero);
        aggiungi(v, &r, numero);}
    
    visualizza(v, r);
    
    
    printf("inserimento valori w\n");
    for (int i=0; i<5; i++){
        int numero;
        printf("valore da aggiungere all'insieme: \n");
        scanf("%d", &numero);
        aggiungi(w, &rr, numero);}
    
    printf("\nvettore v: \n"); 
    visualizza(v, r);
    
    printf("\nvettore w: \n");
    visualizza(w, rr);
    
    intersezione(v, r, w, rr, vinter, &r_inter);
    printf("\nvettore vinter: \n");
    visualizza(vinter, r_inter);
    
    unione(v, r, w, rr, vunione, &r_unione);
    printf("\nvettore vunione: \n");
    visualizza(vunione, r_unione);
    
    differenza(v, r, w, rr, vdiff, &r_diff);
    printf("\nvettore vdiff: \n");
    visualizza(vdiff, r_diff);
    
    return 0;
}

