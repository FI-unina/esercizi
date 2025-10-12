#include <stdio.h>


// definizione della funzione
float media(){

    int a, b, c;
    printf("Inserisci il primo valore: \n");
    scanf("%d", &a);
    
    printf("Inserisci il secondo valore: \n");
    scanf("%d", &b);
    
    printf("Inserisci il terzo valore: \n");
    scanf("%d", &c);
    
    int somma = a+b+c;
    float media = (float)(somma)/3;
    
    return media;
}

int main() {
    // in che ordine vengono mostrati i messaggi a video? 
    
    printf("sto per chiamare la funzione media\n");
    // chiamata della funzione
    float m1 = media();
    printf("la funzione media ha completato la sua esecuzione\n");
    
    printf("sto per chiamare la funzione media per la seconda volta\n");
    // chiamata della funzione
    float m2 = media();
    printf("la funzione media ha completato la sua esecuzione (2a volta)\n");
    
    printf("la media dei primi tre numeri è: %f\n", m1);
    printf("la media dei secondi tre numeri è: %f\n", m2);
    
    return 0;
}

