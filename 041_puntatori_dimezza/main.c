#include <stdlib.h>
#include <stdio.h>

void dimezza_ptr(float* a);

int main() {

    float numero = 3;
    
    dimezza_ptr(&numero);
    
    printf("numero: %f\n", numero);
    return 0;
}

// parametro passato per puntatore 
// (tecnicamente, si sta passando un indirizzo per valore)
void dimezza_ptr(float* a){
    *a = *a/2;
}