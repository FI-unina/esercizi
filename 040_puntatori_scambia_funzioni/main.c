/*
    Applicazione che implementa lo swap di 2 variabili utilizzando 2 funzioni
    che utilizzano i puntatori. 
    - swap_ref utilizza il passaggio per riferimento di puntatori a interi (puntatori a puntatori) 
    - swap_ptr utilizza il passaggio per riferimento di variabili intere (singolo puntatore)
*/

#include <stdio.h>

void swap_ref(int **a, int **b);  // scambio attraverso puntatori a puntatori
void swap_ptr(int *a, int *b);  // scambio attraverso puntatori

int main() {
    
    int q = 1;
    int w = 2;
    
    printf("\n\nScambio utilzzando puntatori\n\n");
    printf("PRIMA DELLO SWAP\n");
    printf("[%p] -> %d\n", &q, q);
    printf("[%p] -> %d\n", &w, w);

    swap_ptr(&q, &w);

    printf("DOPO LO SWAP\n");
    printf("[%p] %d\n", &q, q);
    printf("[%p] %d\n", &w, w);
    
    int *px, *py;
    int x = 1;
    int y = 2;
    px = &x;
    py = &y;

    printf("\nSWAP con doppio puntatore\n");
    printf("PRIMA DELLO SWAP\n");
    printf("[%p] -> %d\n", px, x);
    printf("[%p] -> %d\n", py, y);

    printf("\n\nScambio utilzzando puntatori a puntatori\n\n");
    //printf("PRIMA DELLO SWAP -> x: %d y: %d\n", *px, *py);
    swap_ref(&px, &py);
    printf("DOPO LO SWAP -> x: %d y: %d\n", *px, *py);

    printf("[%p] -> %d\n", px, x);
    printf("[%p] -> %d\n", py, y);

    return 0;
}

// versione di swap con l'uso di puntatori a puntatori
void swap_ref(int **a, int **b){
    printf("[swap_ref] a: %p b: %p\n", a, b);
    printf("[swap_ref] *a: %p *b: %p\n", *a, *b);
    int *tmp = *a;
    *a = *b;
    *b = tmp;
    printf("\n");
    printf("[swap_ref] *a: %p *b: %p\n", *a, *b);
    return;
}

// versione di swap con l'uso di puntatori
void swap_ptr(int* a, int* b){
    printf("[swap_ptr] a: %p b: %p\n", a, b);
    int tmp = *a;
    printf("[swap_ptr] tmp: %d\n", tmp);
    *a = *b;
    printf("[swap_ptr] *a: %d\n", *a);
    *b = tmp;
    printf("[swap_ptr] *b: %d\n", *b);
    return;
}