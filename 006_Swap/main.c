/* 
 * Sviluppare un programma per lo scambio (swap) di 2 variabili
 */

#include <stdio.h>


/*
 * 
 */
int main() {

    unsigned int a, b;
    
    printf("Inserire il valore di a:\n");
    scanf("%d", &a);
    printf("Inserire il valore di b:\n");
    scanf("%d", &b);
    
    printf("Prima dello scambio a vale: %d\n", a);
    printf("Prima dello scambio b vale: %d\n", b);
    
    // SCAMBIO il valore di a e b
    unsigned int tmp;
    tmp = a;
    a = b;
    b = tmp;
    
    printf("Dopo lo scambio a vale: %d\n", a);
    printf("Dopo lo scambio b vale: %d\n", b);
    
    return 0;
}














