
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXSTUDENTI 100


struct studente {
    char nome[51];
    char cognome[51];
    int eta;
    bool lavoratore;
    float media_voti;
};

/*
 * 
 */

int restituisci_eta(const struct studente info_studenti[MAXSTUDENTI], 
                    const int r, 
                    const char nome_da_cercare[51],
                    const char cognome_da_cercare[51]);


void stampa(struct studente s);

void stampa_da_nome_cognome(const struct studente info_studenti[MAXSTUDENTI], 
                            const int r, 
                            const char nome_da_cercare[51],
                            const char cognome_da_cercare[51]);


void inserisci_studente(struct studente info_studenti[], int *r);


int main() {
    struct studente info_studenti[MAXSTUDENTI] = {
        {"Mario", "Rossi", 24, true, 27.5},
        {"Paolo", "Rossi", 23, false, 26.4},
        {"Paolino", "Paperino", 28, false, 24.5},
        {"Luca", "Bianchi", 21, true, 28.5}
    };
    int r = 4;
     
    for (int i=0; i<r; i++)
        stampa(info_studenti[i]);
  
    
    printf("Inserisci il nome dello studente:\n");
    //scanf("%s", info_studenti[r].nome); //AAAAAA
    fgets(info_studenti[r].nome, 51, stdin);
    int pos_n = strcspn(info_studenti[r].nome, "\n");
    printf("pos_s %d", pos_n);
    info_studenti[r].nome[strcspn(info_studenti[r].nome, "\n")] = '\0';

    printf("Inserisci il cognome dello studente:\n");
    //scanf("%s", info_studenti[r].cognome); // AAAAA
    fgets(info_studenti[r].cognome, 51, stdin);
    info_studenti[r].cognome[strcspn(info_studenti[r].cognome, "\n")] = '\0';

    printf("Eta?\n");
    scanf("%d", &info_studenti[r].eta);
    printf("Lavoratore? (1=sì, 0=no)\n");
    scanf("%d", &info_studenti[r].lavoratore);
    printf("Media voti: \n");
    scanf("%f", &info_studenti[r].media_voti);
    
    r++;
    
    // Inserisci un nuovo studente con funzione
    inserisci_studente(info_studenti, &r);

    // stampa
    for (int i=0; i<r; i++){
        
        printf("NOME: %s\n", info_studenti[i].nome);
        printf("COGNOME: %s\n", info_studenti[i].cognome);
        printf("ETA': %d\n", info_studenti[i].eta);
        
        printf("MEDIA VOTI: %f\n", info_studenti[i].media_voti);
        
        printf("STUDENTE LAVORATORE: ");
        if (info_studenti[i].lavoratore)
            printf("Sì\n");
        else
            printf("No\n");    
        printf("----------------\n");
    }
    
    return 0;
}


int restituisci_eta(const struct studente info_studenti[MAXSTUDENTI], 
                    const int r, 
                    const char nome_da_cercare[51],
                    const char cognome_da_cercare[51]){

    int i = 0;
    int anni;
    bool trovato = false;
    
    while(!trovato && i<r){
    
        if(strcmp(info_studenti[i].nome, nome_da_cercare)==0 &&
           strcmp(info_studenti[i].cognome, cognome_da_cercare)==0)
        {
            anni = info_studenti[i].eta;
            trovato = true;}
        else i++; 
    }
    
    if (trovato)
        return anni;
    else 
        return -1;
    
}

void stampa(struct studente s){
    
    printf("NOME: %s\n", s.nome);
    printf("COGNOME: %s\n", s.cognome);
    printf("ETA': %d\n", s.eta);
    printf("MEDIA: %f\n", s.media_voti);
    
    printf("LAVORATORE: ");
    if (s.lavoratore == true)
        printf("Sì\n");
    else
        printf("No\n");
    
    return;
}

void inserisci_studente(struct studente info_studenti[], int *r){
    
    int cur_index = *r;

    fflush(stdin);
    printf("Inserisci il nome dello studente:\n");
    //scanf("%s", info_studenti[r].nome); //AAAAAA
    fgets(info_studenti[cur_index].nome, 51, stdin);
    info_studenti[cur_index].nome[strcspn(info_studenti[cur_index].nome, "\n")] = '\0';

    fflush(stdin);
    printf("Inserisci il cognome dello studente:\n");
    //scanf("%s", info_studenti[r].cognome); // AAAAA
    fgets(info_studenti[cur_index].cognome, 51, stdin);
    info_studenti[cur_index].cognome[strcspn(info_studenti[cur_index].cognome, "\n")] = '\0';

    printf("Eta?\n");
    scanf("%d", &info_studenti[cur_index].eta);
    printf("Lavoratore? (1=sì, 0=no)\n");
    scanf("%d", &info_studenti[cur_index].lavoratore);
    printf("Media voti: \n");
    scanf("%f", &info_studenti[cur_index].media_voti);

    (*r)++;
}