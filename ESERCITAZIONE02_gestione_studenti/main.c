#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHAR_MATR 9
#define MAX_CHAR_NOME 10
#define MAX_CHAR_COGNOME 30

struct dati_studente {

    char matricola [MAX_CHAR_MATR];
    char nome[MAX_CHAR_NOME];
    char cognome[MAX_CHAR_COGNOME];
    int numero_esami_sostenuti;

};

typedef struct dati_studente studente;

struct dati_studente_ridotto{

    char matricola [MAX_CHAR_MATR];
    bool maggiore_media;

};

typedef struct dati_studente_ridotto studente_ridotto;

void inserimento_studenti(studente* studenti, int dim);

void stampa_vettore(studente* studenti, int dim);

void scambia(studente* a, studente* b);
int ricerca_minimo_matricola(studente* studenti, int inizio, int dim);
void ordinamento_matricola(studente* studenti, int dim);
int ricerca_matricola(studente* studenti, int dim, char matricola[]);

float calcolo_media(studente* studenti, int dim);
int conta_occorrenze_superiore_media(studente* studenti, int dim, float media);
studente_ridotto* generazione_array(studente* studenti, int dim); // provare ad implementare la versione con doppio puntatore
void stampa_vettore_ridotto (studente_ridotto* studenti, int dim);


int main(){

    int dim = 0;

    // Chiedo all'utente il numero di studenti con cui inizializzare il vettore
    printf("Inserire il numero di studenti da caricare: ");
    scanf("%d", &dim);

    // Allocazione dinamica del vettore
    studente* studenti = (studente *) malloc(dim * sizeof(studente));

    // Verifico l'esito dell'allocazione
    if (studenti == NULL){ // Allocazione non riuscita

        printf("Impossibile allocare il vettore\n");
        printf("Arrivederci!\n");

    }
    else{ // Allocazione riuscita

        inserimento_studenti(studenti, dim); // Richiedo l'inserimento degli studenti 

        stampa_vettore(studenti, dim); // Stampa del vettore

        // Stampa del menù
        int scelta;
        do{

            printf("Operazioni possibili:\n");
            printf("1. Ricerca di uno studente per matricola attraverso la ricerca binaria\n");
            printf("2. Generazione nuovo vettore con indicazione degli studenti che hanno un numero di esami sostenuti maggiore della media.\n");
            printf("3. Esci\n\n");

            printf("Inserire la scelta: ");
            scanf("%d", &scelta);

            switch (scelta) {

                case 1: { // Ricerca studente per matricola con ricerca binaria

                    ordinamento_matricola(studenti, dim);

                    printf("Vettore ordinato per matricola\n");

                    stampa_vettore(studenti, dim); 

                    char matricola[MAX_CHAR_MATR];
                    printf("Inserire la matricola da cercare\n");
                    scanf("%s", matricola);

                    int posizione = ricerca_matricola(studenti, dim, matricola);

                    // Verifico se è stato trovato uno studente
                    if (posizione != -1){
                        
                        printf("Trovato studente:\n");
                        printf("Matricola: %s\n", (studenti+posizione)->matricola);
                        printf("Nome: %s\n", (studenti+posizione)->nome);
                        printf("Cognome: %s\n", (studenti+posizione)->cognome);
                        printf("Numero essami sostenuti: %d\n\n", (studenti+posizione)->numero_esami_sostenuti);

                    } else 
                        printf("Nessuno studente trovato con la matricola fornita\n\n");
                    

                    break;

                }

                case 2: { // Generazione nuovo vettore con indicazione degli studenti che hanno un numero di esami sostenuti maggiore della media

                    printf("Generazione nuovo vettore con indicazione degli studenti che hanno un numero di esami sostenuti maggiore della media\n");
                    
                    studente_ridotto* new_vet = generazione_array(studenti, dim);

                    if (new_vet != NULL)
                        stampa_vettore_ridotto(new_vet, dim);
                    else
                        printf("Operazione non riuscita!\n");

                    break;

                }

                case 3: // Uscita
                    printf("Arrivederci\n");
                    free(studenti); // dealloco vettore di studenti
                    break;

                default: 
                    printf("Scelta non consentita\n");
                    break;

            }

        } while(scelta != 3);


    }

    return 0;

}

// Procedura per l'inserimento degli elementi del vettore
void inserimento_studenti (studente *studenti, int dim) {

    printf("\nCaricamento di %d studenti\n", dim);

    for (int i=0; i<dim; i++) {
        printf("Inserire lo studente con indice %d\n", i);
        
        printf("Matricola: ");
        scanf("%s", (studenti+i)->matricola); // Accedo all'array utilizzando i puntatori invece della notazione [], ed ai campi della struct con l'operatore "->"" invede del "."

        printf("Nome: ");
        scanf("%s", (studenti+i)->nome); // Accedo all'array utilizzando i puntatori invece della notazione [], ed ai campi della struct con l'operatore "->"" invede del "."

        getchar(); // può essere usato per fare il flush dello \n precendente
        printf("Cognome: ");
        fgets((studenti+i)->cognome, MAX_CHAR_COGNOME, stdin);
        (studenti+i)->cognome[strcspn((studenti+i)->cognome, "\n")] = '\0';

        printf("Numero esami sostenuti: ");
        scanf("%d", &(studenti+i)->numero_esami_sostenuti);

    }

}

// Procedura per la stampa degli elementi del vettore di struct
void stampa_vettore (studente* studenti, int dim) {

    printf("\nStampa degli elementi del vettore\n");

    printf("Matricola \t Nome \t Cognome \t Numero esami sostenuti\n");
    for (int i=0; i<dim; i++)
        printf("%s \t %s \t %s \t %d\n", (studenti+i)->matricola, (studenti+i)->nome, (studenti+i)->cognome, (studenti+i)->numero_esami_sostenuti); // Accedo all'array utilizzando i puntatori invece della notazione [], ed ai campi della struct con l'operatore "->"" invede del "."

    printf("\n");
}

// Procedura per la stampa degli elementi del vettore di struct
void stampa_vettore_ridotto (studente_ridotto* studenti, int dim) {

    printf("\nStampa degli elementi del vettore\n");

    printf("Matricola \t Numero esami sostenuti maggiore della media (0 = No, 1 = Si)\n");
    for (int i=0; i<dim; i++)
        printf("%s \t %d \n", (studenti+i)->matricola, (studenti+i)->maggiore_media); // Accedo all'array utilizzando i puntatori invece della notazione [], ed ai campi della struct con l'operatore "->"" invede del "."

    printf("\n");
}

// Funzione per la ricerca dello studente con la matricola più piccola secondo l'ordinamento alfabetico
// La funzione restituisce la posizione di tale studente, o -1 se non è stato trovato alcuno studente con la matricola fornita
int ricerca_minimo_matricola(studente* studenti, int inizio, int dim){

    char minimo[MAX_CHAR_MATR];
    int posizione = -1;

    for (int i = inizio; i <= dim; i++)
        
        // i == inizio è usato per impostare la variabile minimo al primo elemento di indice inizio
        // altrimenti fallirebbe la strcmp
        if (i == inizio || strcmp((studenti + i)->matricola, minimo) < 0){
            strcpy(minimo, (studenti + i)->matricola);
            posizione = i;
        }
    

    return posizione;

}

// Procedura per lo scambia di struct
// Posso fare questo scambio diretto (con copia shallow) perchè non ho aree dinamiche nella struct
// L'alternativa è scambiare i singoli campi
void scambia(studente* a, studente* b){

    studente tmp = *a;
    *a = *b;
    *b = tmp;

}

// Procedura che implementa l'ordinamento degli elementii del vettore con selection sort
// Provare ad implementare la versione con insertion sort
void ordinamento_matricola(studente* studenti, int dim){
    
    for (int i=0; i<dim-1; i++){

        int pos_min = ricerca_minimo_matricola(studenti, i, dim-1);
        printf("pos_min: %d\n\n", pos_min);
        scambia(studenti+i, studenti+pos_min);
        
    }

}

// Funzione che ricerca uno studente per matricola, sfruttando la ricerca binaria
// Ritorna la posizione dello studente nell'array
int ricerca_matricola(studente* studenti, int dim, char matricola[]){

    int primo=0, ultimo=dim-1, medio, pos=-1;

	do { 
		medio= (int)((primo+ultimo)/2);
		
		if (strcmp((studenti+medio)->matricola, matricola) == 0)  
			pos=medio;
		else if (strcmp((studenti+medio)->matricola, matricola) < 0)
			primo=medio+1;
		else
			ultimo=medio-1;

	} while(primo<=ultimo && pos==-1);	

	return pos;

}

// Funzione per il calcolo della media degli esami sostenuti
// La funzione restituisce la media ottenuta
float calcolo_media(studente* studenti, int dim){

    float media;
    int somma_parziale = 0;

    for (int i = 0; i< dim; i++)
        somma_parziale = somma_parziale + (studenti+i)->numero_esami_sostenuti;

    media = ((float)somma_parziale)/dim;

    return media;

}

// Funzione per contare il numero di studenti con numero di esami sostenuti superiore alla media
// La funzione restituisce il numero di occorrenze trovate
int conta_occorrenze_superiore_media(studente* studenti, int dim, float media){

    int occorrenze = 0;

    for (int i = 0; i< dim; i++)
        if ((studenti+i)->numero_esami_sostenuti <= media)
            occorrenze++;

    return occorrenze;
}

// Funzione che genera un nuovo array contenete gli studenti  dell'array principale
// ma con la sola indicazione della matricola e di un valore booleano per indicare se lo studente ha sostenuto un numero di esami
// superiore (valore true) o inferiore (valore false) della media
// Il puntatore al nuovo array viene fornito in ritorno
studente_ridotto* generazione_array(studente* studenti, int dim){

    // Calcolo la media
    float media = calcolo_media(studenti, dim);
    printf("Media numero esami sostenuti: %f\n", media);

    // Alloco un nuovo vettore di arcoli con:
    // - dimensione pari a quella del vettore principale, dato che conterrà glis tessi studenti
    // - struttura differente, dato che deve contenere per ogni studente solo la matricola ed il campo booleano
    studente_ridotto* new_vet = (studente_ridotto*) malloc(dim*sizeof(studente_ridotto));

    if (new_vet != NULL){ // Verifico se l'allocazione è andata a buon fine

        // Inserisco le matricole degli studenti nel nuovo array, e metto il campo maggiore media a True per quello che hanno
        // un numero di esami sostenuti superiore alla media
        for (int i = 0; i < dim; i++){
            strcpy((new_vet+i)->matricola, (studenti+i)->matricola); // copio la matricola
            if ((studenti+i)->numero_esami_sostenuti > media)
                (new_vet+i)->maggiore_media = true; 
            else
                (new_vet+i)->maggiore_media = false; 

            
        }
    }

    return new_vet; // Ritorno il nuovo vettore

}
