#include <stdio.h>

int main() {
    
    int x = 10;
    int y = 200;
    int *px = &x;
    int *py = &y;
    printf("indirizzo di x: %p\n", px);
    printf("indirizzo di y: %p\n", py);
    
    printf("sizeof int*: %lu\n", sizeof(px));
    
    printf("valore di x: %d\n", x);
    printf("valore di y: %d\n", y);
    printf("valore di x (letto attraverso il puntatore px): %d\n", *px);
    printf("valore di y (letto attraverso il puntatore py): %d\n", *py);
    
    // scambia valori sfruttando i puntatori...
    
    // conservo il valore di puntato da px in una variabile tmp
    int tmp = *px;  
    
    // assegno all'area puntata da px il valore contenuto nell'area puntata da px
    *px = *py;  
    
    // assegno all'area puntata da py il valore salvato in tmp
    *py = tmp;
    
    printf("\ndopo lo scambio...\n");
    
    printf("indirizzo di x: %p\n", px);
    printf("indirizzo di y: %p\n", py);
    
    printf("valore di x: %d\n", x);
    printf("valore di y: %d\n", y);
    printf("valore di x (letto attraverso il puntatore px): %d\n", *px);
    printf("valore di y (letto attraverso il puntatore py): %d\n", *py);

    return 0;
}

