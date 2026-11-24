#include <stdio.h>
#include <limits.h>

/*
 * 
 */
int main() {
    
    int x = 1;  // inizializzazione dell'intero x a 1
    
    // sizeof restituisce la dimensione della variabile (in byte)
    printf("Size of x: %lu bytes.\n", sizeof(x));  
    
    
    // costanti definite nella libreria climits
    printf("Min: %d\n", INT_MIN);  
    printf("Max: %d\n", INT_MAX);
    
    x =  2147483647;  // x = INT_MAX
    printf("%d\n", x);  
    x = x + 1;  // l'operazione di addizione genera OVERFLOW! (wraparound)
    printf("x = %d\n", x);  
    
    int z = INT_MIN; 
    printf("z = %d\n", z);  
    z = z - 1;  // l'operazione di sottrazione genera OVERFLOW! (wraparound)
    printf("z = %d\n", z);
    
    unsigned int y = -1;  // non è un valore codificabile (intero senza segno)
    printf("y = %d\n", y);  // cosa viene stampato a video?
    
    //... valore massimo rappresentabile con un unsigned int
    printf("UINT_MAX: %d\n", UINT_MAX); // stampo un int
    printf("UINT_MAX: %u\n", UINT_MAX); // stampo un unsigned int
    printf("UINT_MAX: %x\n", UINT_MAX); // stampo un unsigned hex
   
    return 0;
}

