#include <stdio.h>

int main() {
    
    const int N = 42;
    int n;
    printf("Inserisci un numero: \n");
    scanf("%d", &n);
    
    while(n != N){
        printf("Non hai indovinato!\n");
        printf("Inserisci un nuovo numero: \n");
        scanf("%d", &n);
    }
    
    printf("Complimenti hai indovinato!\n");
    
    return 0;
}

