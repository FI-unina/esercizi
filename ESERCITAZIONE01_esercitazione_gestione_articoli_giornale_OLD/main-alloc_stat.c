#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHAR 30
#define MAX_DIM 100

struct dati_articolo {

    int anno;
    char giornale[MAX_CHAR];
    int numero_parole;

};

typedef struct dati_articolo articolo;

void inserimento_elementi(articolo articoli[], int riemp);

void stampa_vettore(articolo articoli[], int riemp);

int ricerca_minimo_parole(articolo articoli[], int riemp);
bool inserimento_minimo(articolo articoli[], int* riemp);

float calcolo_media(articolo articoli[], int riemp);
int conta_occorrenze_inferiore_media(articolo articoli[], int riemp, float media);
void generazione_array(articolo articoli[], int riemp, articolo new_vet[], int* riemp_new_vet); 


int main(){

    // Allocazione statica del vettore
    articolo articoli [MAX_DIM];
    
    int riemp = 0;

    do{
    
        // Chiedo all'utente il numero di elementi con cui inizializzare il vettore
        printf("Inserire il numero di elementi da caricare: ");
        scanf("%d", &riemp);

    } while (riemp <= 0 || riemp > MAX_DIM);
    

    

    inserimento_elementi(articoli, riemp); // Richiedo l'inserimento degli elementi 

    stampa_vettore(articoli, riemp); // Stampa del vettore

    // Stampa del menù
    int scelta;
    do{

        printf("Operazioni possibili:\n");
        printf("1. Inserimento nuovo articolo nella posizione precedente a quello con il minimo numero di parole\n");
        printf("2. Generazione nuovo vettore con gli articoli con numero di parole inferiore o uguale alla media\n");
        printf("3. Esci\n\n");

        printf("Inserire la scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {

            case 1: { // Inserimento nuovo articolo nella posizione precedente a quello con il minimo numero di parole

                bool esito = inserimento_minimo(articoli, &riemp);

                // Verifico l'esito dell'operazione
                if (!esito) 
                    printf("Operazione non riuscita! La dimensione dell'array non è sufficiente.\n");

                stampa_vettore(articoli, riemp); 

                break;

            }

            case 2: { // Generazione nuovo vettore con gli articoli con numero di parole inferiore o uguale alla media

                printf("Genrazione vettore con gli articoli con numero di parole inferiore alla media\n");
                
                int riemp_new_vet; // Utilizzato per ricevere il riempimento del nuovo array
                articolo new_vet[MAX_DIM];

                generazione_array(articoli, riemp, new_vet, &riemp_new_vet);

                stampa_vettore(new_vet, riemp_new_vet);

                break;

            }

            case 3: // Uscita
                printf("Arrivederci\n");
                break;

            default: 
                printf("Scelta non consentita\n");
                break;

        }

    } while(scelta != 3);

    return 0;

}

// Procedura per l'inserimento degli elementi del vettore
void inserimento_elementi (articolo articoli[], int riemp) {

    printf("\nCaricamento di %d elementi\n", riemp);

    for (int i=0; i<riemp; i++) {
        printf("Inserire l'elemento di indice %d\n", i);
        
        printf("Anno: ");
        scanf("%d", &articoli[i].anno);

        getchar(); // può essere usato per fare il flush dello \n precendente
        printf("Titolo giornale: ");
        fgets(articoli[i].giornale, MAX_CHAR, stdin);
        articoli[i].giornale[strcspn(articoli[i].giornale, "\n")] = '\0';

        printf("Numero parole: ");
        scanf("%d", &articoli[i].numero_parole);

    }

}

// Procedura per la stampa degli elementi del vettore di struct
void stampa_vettore (articolo articoli[], int riemp) {

    printf("\nStampa degli elementi del vettore\n");

    printf("Anno \t Gioranle \t Numero parole\n");
    for (int i=0; i<riemp; i++)
        printf("%d \t %s \t %d\n", articoli[i].anno, articoli[i].giornale, articoli[i].numero_parole); 

    printf("\n");
}

// Funzione per la ricerca dell'elemento con il minimo numero di parole
// La funzione restituisce la posizione di tale elemento
int ricerca_minimo_parole(articolo* articoli, int riemp){

    int minimo = INT_MAX;
    int posizione = -1;

    for (int i = 0; i < riemp; i++)
        
        if (articoli[i].numero_parole < minimo){
            minimo = articoli[i].numero_parole;
            posizione = i;
        }
    

    return posizione;

}

// Funzione per l'inserimento di un elemento nella posizione precedente all'elemento con il minimo numero di parole
// La funzione restituisce un boolean per indicare se l'operazione è andata a buon fine
bool inserimento_minimo(articolo articoli[], int* riemp){

    bool esito = false;

    if ((*(riemp) + 1) <= MAX_DIM){ // Verifico che l'allocazione sia andata a buon fine

        // Chiedo all'utente il valore da aggiungere
        articolo elemento;
        
        printf("Inserire i dati dell'articolo da aggiungere al vettore\n");
        printf("Anno: ");
        scanf("%d", &(elemento.anno)); 

        getchar();
        printf("Titolo giornale: ");
        fgets(elemento.giornale, MAX_CHAR, stdin);
        elemento.giornale[strcspn(elemento.giornale, "\n")] = '\0';

        printf("Numero parole: ");
        scanf("%d", &(elemento.numero_parole));

        // Ricerco l'elmento dell'array con il numero minimo di parole
        int pos_min = ricerca_minimo_parole(articoli, *riemp);

        printf("Posizione del minimo = %d\n\n", pos_min);        

        for (int i=pos_min; i<(*riemp)+1; i++) // A partire dalla posizione del minimo, sposto tutti gli elmenti di un aposizione verso destra
            articoli[i+1] = articoli[i];

        articoli[pos_min] = elemento; // Copio l'elemento da inserire elemento nella posizione ricercata
                                      // posso fare questa copia shallow perchè non ho aree dinamiche nella struct

        //alternativa alla copia è impostare tutti i campi
        /*

        articoli[pos_min].anno = elemento.anno;
        strcpy(articoli[pos_min].giornale, elemento.giornale);        
        articoli[pos_min].numero_parole = elemento.numero_parole;
        
        */
                                

        (*riemp)++; // Aggiorno il valore di riemp

        esito = true; 

        

    }

    return esito; // Ritorno l'esito dell'operazione

}


// Funzione per il calcolo della media del numero di parole
// La funzione restituisce la media ottenuta
float calcolo_media(articolo articoli[], int riemp){

    float media;
    int somma_parziale = 0;

    for (int i = 0; i< riemp; i++)
        somma_parziale = somma_parziale + articoli[i].numero_parole;

    media = ((float)somma_parziale)/riemp;

    return media;

}

// Funzione per contare il numero di elementi con numero di parole inferiore alla media
// La funzione restituisce il numero di occorrenze trovate
int conta_occorrenze_inferiore_media(articolo articoli[], int riemp, float media){

    int occorrenze = 0;

    for (int i = 0; i< riemp; i++)
        if (articoli[i].numero_parole <= media)
            occorrenze++;

    return occorrenze;
}

// Procedura che genera un nuovo array contenete solo gli articoli con un numero di parole inferiore alla media
// new_vet è un aparametro di output utilizzato per fornire al chiamante il nuovo array
// riemp_new_vet è un parametro di output utilizzato per fornire al chiamante il riempimento del nuono array
void generazione_array(articolo articoli[], int riemp, articolo new_vet[], int* riemp_new_vet){

    // Calcolo la media
    float media = calcolo_media(articoli, riemp);
    printf("Media numero parole: %f\n", media);

    // Ricavo il numero di articoli con numero di parole inferiore o uguale alla media
    *riemp_new_vet = conta_occorrenze_inferiore_media(articoli, riemp, media);
    printf("Numero articoli con numero di parole minore o uguale alla media: %d\n", *riemp_new_vet);

    // Cerco gli articolo con numero di parole inferiore o uguale alla media e li inserisco nel nuovo array
    int j = 0; 
    for (int i = 0; i < riemp; i++)
        if (articoli[i].numero_parole <= media){
            new_vet[j] = articoli[i]; //copia shallow
            j++;
        }

}
