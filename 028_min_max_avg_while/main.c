
#include <stdio.h>
#include <stdbool.h>

int main() {

    bool inserimenti_terminati = false;
    int voto_esame = -1;
    int n_voti = 0;
    float somma = 0;
    float media = 0.0;
    short int min = 30;
    short int max = 18;
    char scelta;
    while (!inserimenti_terminati){
    
        do{
            printf("Inserisci voto esame: \n");
            scanf("%d", &voto_esame);

            if(voto_esame>30 || voto_esame < 18)
                printf("Il voto deve essere compreso tra 18 e 30\n");

        }while(voto_esame>30 || voto_esame<18);
        
        // aggiorna somma
        somma = somma + voto_esame;
        
        // aggiorna min
        if (voto_esame<min)
            min = voto_esame;
        
        // aggiorna max
        if (voto_esame>max)
            max = voto_esame;
        
        // aggiorna n voti
        n_voti++;
        
        do{
            printf("Vuoi inserire altri voti? (y/n)\n");
            scanf(" %c", &scelta);

        }while(scelta!='y' && scelta!='n');


        if (scelta == 'n')
            inserimenti_terminati = true;
        
        //inserimenti_terminati = scelta =='n';
    }
    
    media = somma/n_voti;
    printf("Voto minimo: %d\n", min);
    printf("Voto massimo: %d\n", max);
    printf("Voto medio: %f\n", media);
    
    return 0;
}

