#include <stdio.h>

int main() {

    int x = 100;
    int y;

    int *px; 
    px = &x;
    
    y = *px;
    
    int **py;
    py = &px;

    printf("x => \t[%p] -> %d\n", &x, x);
    printf("y => \t[%p] -> %d\n", &y, y);
    printf("px => \t[%p] -> %p\n", &px, px);
    printf("py => \t[%p] -> %p\n", &py, py);
    
    printf("\n\nDeferenziazioni...\n\n");
    printf("*px %d\n", *px);
    printf("*py: %p **py: %d\n", *py, **py);

    
    return 0;
}

