#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHAR 30

struct dati_articolo {

    int anno;
    char giornale[MAX_CHAR];
    int numero_parole;

};

typedef struct dati_articolo articolo;

void inserimento_elementi(articolo* articoli, int dim);

void stampa_vettore(articolo* articoli, int dim);

int ricerca_minimo_parole(articolo* articoli, int dim);
articolo* inserimento_minimo(articolo* articoli, int* dim); 

float calcolo_media(articolo* articoli, int dim);
int conta_occorrenze_inferiore_media(articolo* articoli, int dim, float media);
articolo* generazione_array(articolo* articoli, int dim, int* dim_new_vet);

void flush(){
       int c;
       while((c = getchar()) != '\n' && c != EOF);
}

int main(){

    int dim = 0;

    // Chiedo all'utente il numero di elementi con cui inizializzare il vettore
    printf("Inserire il numero di elementi da caricare: ");
    scanf("%d", &dim);

    // Allocazione dinamica del vettore
    articolo* articoli = (articolo *) malloc(dim * sizeof(articolo));

    // Verifico l'esito dell'allocazione
    if (articoli == NULL){ // Allocazione non riuscita

        printf("Impossibile allocare il vettore\n");
        printf("Arrivederci!\n");

    }
    else{ // Allocazione riuscita

        inserimento_elementi(articoli, dim); // Richiedo l'inserimento degli elementi 

        stampa_vettore(articoli, dim); // Stampa del vettore

        // Stampa del menù
        int scelta;
        do{

            printf("Operazioni possibili:\n");
            printf("1. Inserimento nuovo articolo nella posizoine precedente a quello con il minimo numero di parole\n");
            printf("2. Generazione nuovo vettore con gli articoli con numero di parole inferiore o uguale alla media\n");
            printf("3. Esci\n\n");

            printf("Inserire la scelta: ");
            scanf("%d", &scelta);

            switch (scelta) {

                case 1: { // Inserimento nuovo articolo nella posizoine precedente a quello con il minimo numero di parole

                    
                    articolo* temp = inserimento_minimo(articoli, &dim);

                    if (temp != NULL)
                        articoli = temp;
                    else
                        printf("Operazione non riuscita!\n");

                    stampa_vettore(articoli, dim); 

                    break;

                }

                case 2: { // Generazione nuovo vettore con gli articoli con numero di parole inferiore o uguale alla media

                    printf("Genrazione vettore con gli articoli con numero di parole inferiore alla media\n");
                    int dim_new_vet; // Utilizzato per ricevere la dimensione del nuovo array
                    articolo* new_vet = generazione_array(articoli, dim, &dim_new_vet);

                    if (new_vet != NULL)
                        stampa_vettore(new_vet, dim_new_vet);
                    else
                        printf("Operazione non riuscita!\n");

                    break;

                }

                case 3: // Uscita
                    printf("Arrivederci\n");
                    free(articoli); //dealloco vettore di articoli
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
void inserimento_elementi (articolo *articoli, int dim) {

    printf("\nCaricamento di %d elementi\n", dim);

    for (int i=0; i<dim; i++) {
        printf("Inserire l'elemento di indice %d\n", i);
        
        printf("Anno: ");
        scanf("%d", &(articoli+i)->anno); // Accedo all'array utilizzando i puntatori invece della notazione [], ed ai campi della struct con l'operatore "->"" invede del "."

        //getchar(); // può essere usato per fare il flush dello \n precendente
        flush();
        printf("Titolo giornale: ");
        fgets((articoli+i)->giornale, MAX_CHAR, stdin);
        (articoli+i)->giornale[strcspn((articoli+i)->giornale, "\n")] = '\0';

        printf("Numero parole: ");
        scanf("%d", &(articoli+i)->numero_parole);

    }

}

// Procedura per la stampa degli elementi del vettore di struct
void stampa_vettore (articolo* articoli, int dim) {

    printf("\nStampa degli elementi del vettore\n");

    printf("Anno\tGiornale\tNumero parole\n");
    for (int i=0; i<dim; i++)
        printf("%d \t%s \t\t %d\n", (articoli+i)->anno, (articoli+i)->giornale, (articoli+i)->numero_parole); // Accedo all'array utilizzando i puntatori invece della notazione [], ed ai campi della struct con l'operatore "->"" invede del "."

    printf("\n");
}

// Funzione per la ricerca dell'elemento con il minimo numero di parole
// La funzione restituisce la posizione di tale elemento
int ricerca_minimo_parole(articolo* articoli, int dim){

    int minimo = INT_MAX;
    int posizione = -1;

    for (int i = 0; i < dim; i++)
        
        if ((articoli + i)->numero_parole < minimo){
            minimo = (articoli + i)->numero_parole;
            posizione = i;
        }
    

    return posizione;

}

// Funzione per l'inserimento di un elemento nella posizione precedente all'elemento con il minimo numero di parole
// La funzione restituisce il puntatore al nuovo array di articoli
articolo* inserimento_minimo(articolo* articoli, int* dim){

    // Allocazione del nuovo vettore con dimensione pari a dim + 1 
    int new_vet_dim = (*dim)+1;
    articolo * new_vet = (articolo *) malloc(new_vet_dim *sizeof(articolo));

    if (new_vet != NULL){ // Verifico che l'allocazione sia andata a buon fine

        // Chiedo all'utente il valore da aggiungere
        articolo* elemento  = (articolo *) malloc(sizeof(articolo));
        
        printf("Inserire i dati dell'articolo da aggiungere al vettore\n");
        printf("Anno: ");
        scanf("%d", &(elemento->anno)); // Accedo all'array utilizzando i puntatori invece della notazione [], ed ai campi della struct con l'operatore "->"" invede del "."

        //getchar();
        flush();
        printf("Titolo giornale: ");
        fgets(elemento->giornale, MAX_CHAR, stdin);
        elemento->giornale[strcspn(elemento->giornale, "\n")] = '\0';

        printf("Numero parole: ");
        scanf("%d", &(elemento->numero_parole));

        // Ricerco l'elmento dell'array con il numero minimo di parole
        int pos_min = ricerca_minimo_parole(articoli, *dim);

        printf("Posizione del minimo = %d\n\n", pos_min);        

        for(int i=0; i<pos_min; i++)    // Copio tutti gli elementi dal vettore precedente, fino alla posizione in cui voglio inserire il nuovo elemento, cioè pos
            *(new_vet+i) = *(articoli+i);

        //*(new_vet+pos_min) = *(elemento); // Copio l'elemento da inserire (*elemento) nella posizione ricercata
                                            //posso fare questa copia shallow perchè non ho aree dinamiche nella struct
        
        
        (new_vet+pos_min)->anno = elemento->anno;
        strcpy((new_vet+pos_min)->giornale, elemento->giornale);        
        (new_vet+pos_min)->numero_parole = elemento->numero_parole;
        //alternativa alla copia è impostare tutti i campi
        /*
            (new_vet+pos_min)->anno = elemento->anno
            strcpy(elemento->giornale, (new_vet+pos_min)->giornale);    
            
            (new_vet+pos_min)->numero_parole = elemento->numero_parole
        */

        for (int i=pos_min+1; i<new_vet_dim; i++) // Copio tutti gli elementi rimanenti del vettore di partenza, nelle rimanenti posizioni del nuovo vettore allocato 
            *(new_vet+i) = *(articoli+i-1);
        
        (*dim) = new_vet_dim; // Aggiorno il valore di dim del vecchio vettore alla dimensione del nuovo vettore

        free(articoli); // Dealloco il vecchio vettore
        free(elemento); // Dealloco la locazione temporanea utilizzata per memorizzare i dati del nuovo articolo

    }

    return new_vet; // Ritorno il puntatore al nuovo vettore (in caso di successo), oppure NULL in caso di problemi con la malloc

}


// Funzione per il calcolo della media del numero di parole
// La funzione restituisce la media ottenuta
float calcolo_media(articolo* articoli, int dim){

    float media;
    int somma_parziale = 0;

    for (int i = 0; i< dim; i++)
        somma_parziale = somma_parziale + (articoli+i)->numero_parole;

    media = ((float)somma_parziale)/dim;

    return media;

}

// Funzione per contare il numero di elementi con numero di parole inferiore alla media
// La funzione restituisce il numero di occorrenze trovate
int conta_occorrenze_inferiore_media(articolo* articoli, int dim, float media){

    int occorrenze = 0;

    for (int i = 0; i< dim; i++)
        if ((articoli+i)->numero_parole <= media)
            occorrenze++;

    return occorrenze;
}

// Funzione che genera un nuovo array contenete solo gli articoli con un numero di parole inferiore alla media
// dim_new_vet è un parametro di output utilizzato per fornire al chiamante la dimensione del nuono array
// Il puntatore al nuovo array viene fornito in ritorno
articolo* generazione_array(articolo* articoli, int dim, int* dim_new_vet){

    // Calcolo la media
    float media = calcolo_media(articoli, dim);
    printf("Media numero parole: %f\n", media);

    // Ricavo il numero di articoli con numero di parole inferiore o uguale alla media
    *dim_new_vet = conta_occorrenze_inferiore_media(articoli, dim, media);
    printf("Numero articoli con numero di parole minore o uguale alla media: %d\n", *dim_new_vet);

    // Alloco un nuovo vettore di arcoli con la dimensione pari al numero di arcoli con numero di parole inferiore o uguale alla media
    articolo* new_vet = (articolo*) malloc(*(dim_new_vet)*sizeof(articolo));

    struct dati_articolo new_vet_1[*dim_new_vet];

    if (new_vet != NULL){ // Verifico se l'allocazione è andata a buon fine

        // Cerco gli articolo con numero di parole inferiore o uguale alla media e li inserisco nel nuovo array
        int j = 0; 
        for (int i = 0; i < dim; i++)
            if ((articoli+i)->numero_parole <= media){
                *(new_vet+j) = *(articoli+i); //copia shallow
                j++;
            }
    }

    return new_vet; // Ritorno il nuovo vettore

}

