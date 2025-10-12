#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void inserisciDimensione(int *);
void inserisciElementi (int *, int);
void stampaVettore (int *, int);
int minimoVettore (int *, int, int);
int occorrenzeZeri(int*, int);
int* rimuovi(int *, int *, int , bool *);
int* aggiungi (int *, int *, int, int, bool *);
bool ricercaLineare(int *, int , int , int *);
void scambia(int * , int *);
void ordina(int *, int);

int main() {
    
    int *vettore;
    int riempimento;
    int posizione;
    char scelta;
    int minimo;
    int elemento;
    int occorrenze;
    bool esito;
    
    
    // Chiediamo prima quanti elementi contiene il vettore
    inserisciDimensione(&riempimento);

    // Ora possiamo allocare lo spazio necessario per memorizzare il vettore
    vettore = malloc(riempimento*sizeof(int));
    
    if (vettore){

        // Effettuo il caricamento di tutti gli elementi del vettore
        inserisciElementi (vettore, riempimento);

        // Stampo il vettore
        printf("\nIl vettore inserito è:\n");
        stampaVettore (vettore, riempimento);
        printf("\n");

        do {
            // Genero il menù con le operazioni possibili
            printf("\nOperazioni su vettore\n");
            printf("m: minimo\n");
            printf("z: occorrenze zeri\n");
            printf("c: cancellazione elemento\n");
            printf("i: inserimento\n");
            printf("r: ricerca\n");
            printf("o: ordinamento\n");
            printf("s: stampa\n");
            printf("e: exit\n\n");
            printf("Inserire l'operazione da realizzare: ");
            scanf(" %c", &scelta);

            switch (scelta) {

                case 'm': // Ricerca del minimo
                    minimo = minimoVettore(vettore, 0, riempimento);
                    printf("Il minimo elemento del vettore è: %d\n", *(vettore+minimo));
                    break;

                case 'z': // Numero di occorrenze degli zeri nel vettore
                    occorrenze = occorrenzeZeri(vettore, riempimento);
                    printf("Nel vettore ci sono %d valori nulli\n", occorrenze);
                    break;

                case 'c': // Cancellazione elemento
                    printf("Digitare la posizione dell'elemento da eliminare: ");
                    scanf("%d", &posizione);

                    vettore = rimuovi(vettore, &riempimento, posizione, &esito);
                    
                    if (esito) {
                        printf("Il nuovo vettore e':\n");
                        stampaVettore(vettore, riempimento);
                        printf("\n");
                    } else
                        printf("Errore!!! La posizione inserita supera la dimensione del vettore, oppure e' negativa\n");
                    
                    break;

                case 'i': // Inserimento elemento in una specifica posizione
                    printf("Digitare la posizione in cui inserire l'elemento ");
                    scanf("%d", &posizione);

                    printf("Digitare l'elemento da inserire: ");
                    scanf("%d", &elemento);
                    
                    vettore = aggiungi(vettore, &riempimento, posizione, elemento, &esito);
                    
                    if (esito) {
                        printf("Il nuovo vettore e':\n");
                        stampaVettore(vettore, riempimento);
                        printf("\n");
                    } else 
                        printf("Errore!!! la posizione inserita supera la dimensione del vettore, oppure e' negativa\n");
                    
                    break;

                case 'r': // Ricerca elemento nel vettore
                    printf("Digitare l'elemento da cercare: ");
                    scanf("%d", &elemento);

                    if(ricercaLineare(vettore, riempimento, elemento, &posizione))
                        printf("Prima occorrenza di %d trovata in posizione %d\n", elemento, posizione); 
                    else
                            printf("Elemento non trovato\n");
                        
                    printf("\n");
                    break;

                case 'o': // ordinamento del vettore
                    
                    printf("Ordinamento...\n");
                    ordina(vettore, riempimento);
                
                    printf("Il vettore ordinato in senso crescente è:\n");
                    stampaVettore(vettore, riempimento);
                    printf("\n");

                    break;

                case 's':

                    printf("Il vettore è:\n");
                    stampaVettore(vettore, riempimento);
                    printf("\n");

                    break;

                case 'e': // uscita
                    printf("Arrivederci\n");
                    break;

                default: 
                    printf("Scelta non consentita\n");
                    break;
            };
        } while (scelta != 'e');
    } else 
        printf("Impossibile allocare la memoria richiesta\n");
    
    printf("Programma terminato\n");
    return 0;
}

// Procedura per l'inserimento della dimensione del vettore
void inserisciDimensione(int *dim) {
    
    do {
        printf("Inserisci il numero di elementi del vettore: ");
        scanf("%d", dim);
    
        if (dim<=0)
            printf("Errore !!! Il vettore non puo' essere vuoto\n");
        
    } while (dim<=0);

}

// Procedura per l'inserimento degli elementi del vettore
void inserisciElementi (int *vet, int dim) {

    for (int i=0; i<dim; i++) {
        printf("Inserisci elemento di indice %d: ",i);
        scanf("%d", (vet+i));
    }
}

// Procedura per la stampa a video del vettore
void stampaVettore (int *vet, int dim) {
    
    for (int i=0; i<dim; i++) {
        printf("%d\t", *(vet+i));
    }
}

// Funzione che restituisce la posizione del minimo elemento in un sotto-vettore
int minimoVettore (int *vet, int inizio, int dim) {
    
    int minimo = *(vet+inizio);
    int pos_min = inizio;
    
    for (int i=inizio+1; i<dim; i++) 
        if (*(vet+i)<minimo){
            minimo = *(vet+i);
            pos_min = i;
        }
    
    return pos_min;
}

/*  Funzione che rimuove elemento in posizione pos. 
    La variabile boolena esito è false se si tenta di rimuovere un elemento di posizione
    negativa oppure maggiore della dimensione del vettore, true altrimenti.
    La funzione restituisce un puntatore a intero, ossia il puntatore al primo elemento del
    vettore in cui è stato cancellato l'elemento di posizione pos  */
int* rimuovi(int *vet, int *dim, int pos, bool *esito) {

    if(pos>=0 && pos<*dim){ // Verifico se la posizione dell'elemento da rimuovere è compresa tra [0, dim-1]
    
        int *nuovoVet;
        int new_vet_dim = (*dim)-1;
        
        nuovoVet = malloc(new_vet_dim * sizeof(int));  // Alloco dinamicamente il nuovo vettore che conterrà il vettore di partenza, a meno dell'elemento eliminato

        if (nuovoVet != NULL){
    
            for(int i=0; i<pos; i++)    // Copio tutti gli elementi dal vettore di partenza fino allìelemento da eliminare (cioè quello con posizione pos)
                *(nuovoVet+i) = *(vet+i);
        
            for (int i=pos+1; i<*dim; i++) // Copio la parte restante degli elementi dal vettore di partenza, saltando quello da eliminare
                *(nuovoVet+i-1) = *(vet+i);
            
            *dim = new_vet_dim;
            *esito = true;
            
            free(vet); // Dealloco il vettore di partenza
    
            return nuovoVet;
        } else {
            *esito = false;
            return vet; // Se non si è riusciti ad allocare il nuovo vettore, si ritorna il vettore di partenza 
        }
        
    } else {
        *esito = false;
        return vet; // Se la posizione inserita non ricade in [0, dim-1], si ritorna il vettore di partenza 
    }
}

/*  Funzione che aggiunge elemento elem in posizione pos, 
    La variabile boolena esito è false se si tenta di rimuovere un elemento di posizione
    negativa oppure maggiore della dimensione del vettore, true altrimenti.
    Nel caso in cui l'inserimento avvenga in maniera corretta
    allora la funzione restitruisce un esito pari a 0   */
int* aggiungi (int *vet, int *dim, int pos, int elem, bool *esito) {
   
    if(pos>=0 && pos<*dim+1){ // Verifico se la posizione dell'elemento da rimuovere è compresa tra [0, dim], dato che si vuole aggiungere un elemento
        
        int *nuovoVet;
        int new_vet_dim = (*dim)+1;

        nuovoVet = malloc(new_vet_dim * sizeof(int)); // Alloco dinamicamente il nuovo vettore che conterrà il vettore di partenza con l'aggiunta dell'ulteriore elemento da inserire

        if (nuovoVet != NULL){

            for(int i=0; i<pos; i++)    // Copio tutti gli elementi dal vettore precedente, fino alla posizione in cui voglio inserire il nuovo elemento, cioè pos
                *(nuovoVet+i) = *(vet+i);

            *(nuovoVet+pos)=elem; // Aggiungo l'elemento da inserire nella posizione richiesta    
        
            for (int i=pos+1; i<new_vet_dim; i++) // Copio tutti gli elementi rimanenti del vettore di partenza, nelle rimanenti posizioni del nuovo vettore allocato 
                *(nuovoVet+i) = *(vet+i-1);
            
            *dim = new_vet_dim;

            *esito = true;

            free(vet); // Dealloco il vettore di partenza

            return nuovoVet;
        } else {
            
            *esito = false;
            return vet; // Se non si è riusciti ad allocare il nuovo vettore, si ritorna il vettore di partenza 
        }

    } else {
        *esito = false;
        return vet; // Se la posizione inserita non ricade in [0, dim], si ritorna il vettore di partenza 
    }
}

// Funzione che svolge la ricerca lineare di un elemento elem in un vettore
bool ricercaLineare(int *vet, int dim, int elem, int *posizione){
    
    bool trovato=false;
    *posizione=0;
    
    while (!trovato && *posizione<dim)
        if(*(vet+(*posizione))==elem) 
            trovato=true;
        else 
            (*posizione)++;

    return trovato;
}

// Procedura che effettua lo scambio di due interi
void scambia(int* a, int* b){

    int temp = *a;
    *a = *b;
    *b = temp;

}

// Procedura per l'ordinamento in ordine crescente. Algoritmo del selection sort
void ordina(int *vet, int dim) {
    
    int temp, min, pos;
    
    for(int i=0; i<dim; i++) {

        pos = minimoVettore(vet, i, dim); // Cerco il minimo nel sotto-vettore corrente
    
        // Scambio, solo se la posizione del minimo è diversa da quella dell'elemento corrente
        if (i!=pos)
            scambia(vet+i, vet+pos);
        
    }
}

// Funzione che calcola l'occorrenza degli zeri nel vettore
int occorrenzeZeri(int *vet, int dim){

    int occorrenze=0;

    for(int i=0; i<dim; i++){
        if (*(vet+i)==0){
            occorrenze++;
        }
    }
    return occorrenze;
}