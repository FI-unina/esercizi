/* 
 * Progettare e scrivere un programma che prenda in ingresso 
 * un numero intero n e stampi la tabellina del numero inserito 
 * (da n*1 a n*10)
 */

#include <stdio.h>

int main() {

    int n;
    int i = 1;  // variabile di conteggio
    
    // input n
    printf("Inserisci un numero: \n");
    scanf("%d", &n);
    
    while(i<=10){
        
        printf("%d x %d = %d\n", n, i, n*i);
        //i = i+1;
        i++;
    
    }
    
    
    
    
    
    
    
    
    return 0;
}

