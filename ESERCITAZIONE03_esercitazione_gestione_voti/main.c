#include <stdio.h>
#include <stdbool.h>
#include <string.h>


struct esame{
    char matricola_studente[5];
    char nome_esame[51];
    int voto;
    bool lode;
};

const int MAX_ESAMI = 100;

void stampa_esame(struct esame e);
void stampa_storico(struct esame V[], int riemp);
bool valida_esame(struct esame e);
void inserisci_nuovo_esame(struct esame V[], int *riemp);
float calcola_media_studente(struct esame V[], int riemp, char matr[5]);
void stampa_voti_soglia(struct esame V[], int riemp, int soglia);

int ricerca_matricola(struct esame V[], int riemp, char matr[5]);
bool elimina_prima_occorrenza(struct esame V[], int *riemp, char matr[5]);
void elimina_tutte_occorrenze(struct esame V[], int *riemp, char matr[5]);

int main() {
    
    struct esame storico[MAX_ESAMI] = {
        { "1234", "Fondamenti di Informatica", 25, false},
        { "1235", "Fondamenti di Informatica", 28, false},
        { "1236", "Fondamenti di Informatica", 30, true},
        { "1234", "Analisi I", 18, false},
        { "1236", "Analisi I", 27, false},
        { "1235", "Fisica I", 28, false},
        { "1236", "Fisica I", 26, false}
    };
    
    int num_esami = 7;
    int scelta;
    char matricola[5];
    
    do{
        
        // stampare menu
        printf("\n1. Stampa storico\n");
        printf("2. Inserisci nuovo esame\n");
        printf("3. Calcola media\n");
        printf("4. Stampa voti sopra soglia\n");
        printf("5. Cancella voti studente\n");
        printf("0. Esci\n");
         
        // input scelta
        scanf("%d", &scelta);
        
        switch(scelta){
            case 1:
                //printf("stampa storico" <<  endl;
                stampa_storico(storico, num_esami);
                break;
            case 2:
                //printf("inserisci esame" <<  endl;
                inserisci_nuovo_esame(storico, &num_esami);
                break;
            case 3:
                //printf("calcola media\n");
                {
                char mat[5];
                printf("Inserisci matricola:\n");
                scanf ("%[^\n]%*c", mat);
                float media = calcola_media_studente(storico, num_esami, mat);
                printf("La media dello studente con matricola %s\n", mat);
                printf(" è: %f\n", media);
                break;
                }
            case 4:
                // stampa voti sopra soglia:
                {
                    int soglia;
                    printf("Scegli soglia:\n");
                    scanf("%d", &soglia);
                    stampa_voti_soglia(storico, num_esami, soglia);
                }
                break;
            case 5:
                
                printf("Inserisci matricola:\n");
                //scanf ("%[^\n]%*c", &matricola);
                elimina_tutte_occorrenze(storico, &num_esami, matricola);
                break;
            case 0:
                printf("Arrivederci!\n");
                break;
            default:
                printf("Scelta non consentita!\n");
        }
        
        
    }while(scelta != 0);
    
    

    return 0;
}

void stampa_esame(struct esame e){
    //Matricola: 1236 - Esame: Fondamenti di Informatica - Voto: 30 e lode.
    printf("Matricola: %s\n", e.matricola_studente);
    printf("Esame: %s - \n", e.nome_esame);
    printf("Voto: %d", e.voto);
    if(e.lode==true)
        printf(" e lode.");
    printf("\n");
    return;
}

void stampa_storico(struct esame V[], int riemp){
    printf("--------------------\n");
    printf("STORICO ESAMI\n");
    printf("--------------------\n");
    for (int i=0; i<riemp; i++){
        stampa_esame(V[i]);
    }
    printf("--------------------\n\n");
    
}

bool valida_esame(struct esame e){
    
    bool esito;
    bool c1 = e.voto >= 18 && e.voto <=30;
    bool c2 = !e.lode || (e.lode && e.voto==30);
    esito = c1 && c2;
    return esito;
}

void inserisci_nuovo_esame(struct esame V[], int *riemp){
    if(*riemp == MAX_ESAMI){
        printf("Spazio esaurito\n");
        return;
    }

    // acquisisci informazioni da tastiera
    struct esame esame_da_inserire;
    printf("Inserisci Matricola:\n");
    scanf ("%[^\n]%*c", &esame_da_inserire.matricola_studente);
    //cin >> esame_da_inserire.matricola_studente;
    
    printf("Inserisci nome esame:\n");
    //cin >> esame_da_inserire.nome_esame;
    //cin.ignore();
    //cin.getline(esame_da_inserire.nome_esame, 51);
    scanf ("%[^\n]%*c", &esame_da_inserire.nome_esame);

    printf("Inserisci voto:\n");
    //cin >> esame_da_inserire.voto;
    scanf ("%d", &esame_da_inserire.voto);

    /*
    // alternativa:
    char scelta_lode;
    printf("Lode? (s/n):";
    cin >> scelta_lode;
    if (scelta_lode == 's')
        esame_da_inserire.lode = true;
    else
        esame_da_inserire.lode = false;
    */
    
    do{
        printf("Lode: 0=no, 1=sì:\n");
        scanf ("%[^\n]%*c", &esame_da_inserire.lode);
    }while(esame_da_inserire.lode!=0 && esame_da_inserire.lode!=1);
    
    
    if (valida_esame(esame_da_inserire)== true){
        V[*riemp] = esame_da_inserire;
        (*riemp)++;
        printf("Inserimento avvenuto con successo\n\n");
    }
    else
        printf("Dati inseriti non validi!\n\n");
        
    return;

}

float calcola_media_studente(struct esame V[], int riemp, char matr[5]){
    
    int somma = 0;
    int conteggio = 0;
    for (int i=0; i<riemp; i++){
        if(strcmp(V[i].matricola_studente, matr)==0){
            somma = somma + V[i].voto;
            conteggio = conteggio + 1;
        }
    }
    return (float)(somma)/conteggio;
}

void stampa_voti_soglia(struct esame V[], int riemp, int soglia){
    
    for (int i=0; i<riemp; i++){
        if(V[i].voto >= soglia)
            stampa_esame(V[i]);
    }
    return;
}

// restituisce -1 se non trova matricola, altrimenti restituisce posizione
int ricerca_matricola(struct esame V[], int riemp, char matr[5]){
    int i = 0;
    bool trovato = false;
    int posizione = -1;
    while(!trovato && i < riemp){
        if(strcmp(matr, V[i].matricola_studente)==0){
            posizione = i;
            trovato = true;
        }
        else 
            i++;
    }
    return posizione;
}

bool elimina_prima_occorrenza(struct esame V[], int *riemp, char matr[5]){

    int pos = ricerca_matricola(V, *riemp, matr);
    if (pos == -1)
        return false; // non ha trovato elemento da eliminare
    else{
        (*riemp)--;
        for(int i=pos; i < *riemp; i++)
            V[i] = V[i+1];
    
        return true; // ha eliminato l'elemento
    }
}

void elimina_tutte_occorrenze(struct esame V[], int *riemp, char matr[5]){
    bool ho_eliminato_qualcosa;
    
    do ho_eliminato_qualcosa = elimina_prima_occorrenza(V, riemp, matr);
    while(ho_eliminato_qualcosa);
}