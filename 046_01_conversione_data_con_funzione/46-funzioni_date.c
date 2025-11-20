#include <stdio.h>

int tempoInSecondi(int h, int m, int s) {
    int secondi = (h * 60 * 60) + (m * 60) + s;
    return secondi;
}

int main()
{
    int h1, m1, s1;
    int tempo1, tempo2;
    
    printf("inserisci la prima quantita' di tempo in ore minuti e secondi\n");
    scanf("%d", &h1);
    scanf("%d", &m1);
    scanf("%d", &s1);
    tempo1 = tempoInSecondi(h1, m1, s1);
    printf("il primo tempo, convertito in secondi e': %d\n", tempo1);
    
    printf("inserisci la seconda quantita' di tempo in ore minuti e secondi\n");
    scanf("%d", &h1);
    scanf("%d", &m1);
    scanf("%d", &s1);
    tempo2 = tempoInSecondi(h1, m1, s1);
    printf("il secondo tempo, convertito in secondi e': %d\n", tempo2);
    
    if (tempo1 > tempo2){
        printf("il primo tempo e' maggiore del secondo\n");;
    }
    else if (tempo2 > tempo1){
        printf("il secondo tempo e' maggiore del primo\n");
    }
    else {
        printf("le quantita' di tempo sono uguali\n");
    }
}