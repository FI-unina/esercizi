/* 
 * 
 * Scrivere un programma che calcola l'area di un cerchio.
 * 
 */

#include <stdio.h>

/*
 * 
 */
int main() {
    
    const float pi = 3.1415;
    float raggio;
    
    printf("Calcolo dell'area del cerchio\n");
    
    printf("Inserisci il valore del raggio: \n");
    scanf("%f", &raggio);
    
    float area = pi * raggio * raggio;
    
    printf("area = %f\n", area);
    
    return 0;
}

