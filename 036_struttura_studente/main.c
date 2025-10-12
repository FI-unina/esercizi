#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define NVOTI 3

struct studente{
    char nome[31];
    char cognome[31];
    int eta;
    int lista_voti[NVOTI];
};

/* confronta_media() restituisce -1 se la media di s1 è maggiore
 *                      1 se la media di s2 è maggiore
 *                      0 se le due medie concidono 
 */
int confronta_media(struct studente s1, struct studente s2);
bool sono_omonimi(struct studente s1, struct studente s2);

void stampa_studente(struct studente s){

    printf("\n -----------\n");
    printf("NOME: %s\n", s.nome);
    printf("COGNOME: %s\n", s.cognome);
    printf("ETA': %d\n", s.eta);
    printf("Voti ultimi %d esami: ", NVOTI);
    
    for (int i=0; i<NVOTI; i++)
        printf("%d, ", s.lista_voti[i]);
    
    printf("\n");
    printf("-----------\n");
}

int main(int argc, char** argv) {
    
    struct studente s1, s2;
    
    // WARNING: cosa succede se inseriamo spazi nei nomi e cognomi usando la scanf?
    // fare versione utilizzando la gets
    
    printf("Inserisci nome primo studente: \n");
    scanf("%s", s1.nome); //perchè non metto la & in s1.nome?
    
    printf("Inserisci nome secondo studente: \n");
    scanf("%s", s2.nome); 
    
    printf("Inserisci cognome primo studente: \n");
    scanf("%s", s1.cognome); 
    
    printf("Inserisci cognome secondo studente: \n");
    scanf("%s", s2.cognome);

    printf("Inserisci età primo studente: \n");
    scanf("%d", &s1.eta);
    
    printf("Inserisci età secondo studente: \n");
    scanf("%d", &s2.eta);
    
    printf("Inserisci voti primo studente:\n");
    for(int i=0; i < NVOTI; i++){
        printf("voto %d:", i+1);
        scanf("%d", &s1.lista_voti[i]);
    }
    
    printf("Inserisci voti secondo studente:\n");
    for(int i=0; i<NVOTI; i++){
        printf("voto %d:", i+1);
        scanf("%d", &s2.lista_voti[i]);
    }

    stampa_studente(s1);
    stampa_studente(s2);
    
    bool esito_omonimi = sono_omonimi(s1, s2);
    if (esito_omonimi)
        printf("I due studenti sono omonimi!\n");
    else
        printf("I due studenti NON sono omonimi!\n");
    
    
    int esito_media = confronta_media(s1, s2);
    if (esito_media == 1){
        printf("Lo studente %s %s ha una media maggiore\n", s1.nome, s1.cognome); 
    }
    else if (esito_media == -1){
        printf("Lo studente %s %s ha una media maggiore\n", s2.nome, s2.cognome); 
    }
    else{ 
        printf("Gli studenti %s %s e %s %s hanno la stessa media\n", s1.nome, s1.cognome, s2.nome, s2.cognome);
    }
    
    
    return 0;
}

int confronta_media(struct studente s1, struct studente s2){
    
    int somma_voti1 = 0;
    int somma_voti2 = 0;
    
    float media1, media2;
    
    for (int i=0; i<NVOTI; i++)
        somma_voti1 += s1.lista_voti[i];
    media1 = (float) (somma_voti1)/NVOTI;
    
    for (int i=0; i<NVOTI; i++)
        somma_voti2 += s2.lista_voti[i];
    media2 = (float) (somma_voti2)/NVOTI;
    
    if (media1 > media2)
        return 1;
    else if (media1 == media2)
        return 0;
    else 
        return -1;
}

bool sono_omonimi(struct studente s1, struct studente s2){
    if(strcmp(s1.nome, s2.nome)==0)
        return true;
    else
        return false;
}