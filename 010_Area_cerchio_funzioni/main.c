#include <stdio.h>


#define pi 3.14
//const float pi = 3.14;  // in alternativa a define...

float calcola_area_cerchio(float raggio);  // dichiarazione funzione (non c'è corpo)

int main() {
    
    float r;
    
    printf("Questo programma effettua il calcolo dell'area del cerchio...\n");
    printf("Inserisci il raggio: \n");
    scanf("%f", &r);
    
    // chiamata alla funzione calcola_area_cerchio.
    // il risultato viene passato a cout per la stampa.
    printf("L'area del cerchio di raggio %f è pari a: %f\n", r, calcola_area_cerchio(r));
    
    printf("Inserisci un nuovo valore per il raggio: \n");
    scanf("%f", &r);
    // nuova chiamata alla funzione...
    printf("L'area del cerchio di raggio %f è pari a: %f\n", r, calcola_area_cerchio(r));
    
    return 0;
}

// definizione della funzione 
float calcola_area_cerchio(float raggio){
    return pi * raggio * raggio;
}