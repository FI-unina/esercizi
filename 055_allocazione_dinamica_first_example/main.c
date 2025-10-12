#include <AvailabilityVersions.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int *p_int;
    p_int = (int *) malloc(sizeof(int));

    int stack_distance = (unsigned long)&p_int - (unsigned long)p_int;
    printf("stack_distance: %#016x\n", stack_distance);

    printf("Prima di inizializzare il valore puntato da p_int => %d\n", *p_int);

    *p_int = 5;

    printf("Dopo aver inizializzare il valore puntato da p_int => %d\n", *p_int);
       
    int x, y;
    
    int* px = &x;
    int* py = &y;
    
    printf("\n");
    printf("La variabile px è sullo stack (&px: %p) e punta ad una area di memoria sullo STACK (px: %p)\n", &px, px);
    printf("La variabile py è sullo stack (&py: %p) e punta ad una area di memoria sullo STACK (py: %p)\n", &py, py);
    printf("La variabile p_int è sullo stack (&p_int: %p) e punta ad una area di memoria sullo HEAP (p_int: %p)\n", &p_int, p_int);
    printf("\n");
    
    int i= 0;
    
    free(p_int);
    
    printf("Dopo la free...\n");

    /* 
        Se uso un puntatore ad un area deallocato, il comportamento sarà undefined anche se 
     in un primo momento il programma potrebbe funzionare lo stesso se l'applicazione non riusa
     quel puntatore
    */
    
    // alloco un nuovo puntatore che potrebbe riusare il puntatore assegnato a p_int!!!!
    int *new_ptr = malloc(sizeof(int));
    *new_ptr = 100;
    
    // assegno all'area puntata da p_int il valore 10, ma avevo fatto la free di p_int!!!
    *p_int = 10; // non mi rendo conto che sto modificando il valore puntato da new_ptr!!

    printf("Dopo la free di p_int, new_ptr riusa lo stesso indirizzo\n");
    printf("p_int: %p\n", p_int);
    printf("new_ptr: %p\n", new_ptr);
    

    printf("p_int: %p\n", p_int);
    printf("p_int: %d\n", *p_int);
    printf("new_ptr: %d\n", *new_ptr);
    free(new_ptr);
    //free(p_int);
    
    
    
    
    return 0;
}

