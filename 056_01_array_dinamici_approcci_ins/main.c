#include <stdio.h>
#include <stdlib.h>

int* inserisci(int* vector, int* dim, int x);
void inserisci_ptr2(int ** vector, int* dim, int x);

int* inserisci_realloc(int * vector, int* dim, int x);
void inserisci_realloc_ptr2(int ** vector, int* dim, int x);

int* rimuovi(int* vector, int* dim, int posizione);
int* rimuovi_with_realloc(int* vector, int* dim, int posizione);

void stampa(int * vector, int* dim);


int main(){

    int * vector = (int *)malloc(sizeof(int));  
    int dim = 0;
    int pos = 3;

    vector = inserisci(vector, &dim, 10);
    vector = inserisci_realloc(vector, &dim, 100);
    
    inserisci_ptr2(&vector, &dim, 1000);
    inserisci_realloc_ptr2(&vector, &dim, 10000);

    printf("Vettore prima della rimozione:\n");
    stampa(vector, &dim);

    printf("\nRimuovo l'elemento di posto %d\n", pos);
    vector = rimuovi(vector, &dim, pos);

    printf("\nVettore dopo la rimozione:\n");
    stampa(vector, &dim);

    return 0;


}


// Inserimento utilizzando la malloc per allocare il nuovo vettore, contentente il vettore di partenza più l'elemento da inserire
// La funzione ritorna il puntatore al nuovo vettore se l'allocazione riesce, altrimenti ritorna il puntatore al vettore di partenza
int* inserisci(int* old_vector, int* dim, int x){
    
    int* new_vector = (int *) malloc(((*dim)+1) * sizeof(int));

    if (new_vector != NULL){

        // copia tutti i vecchi valori del vettore puntato da *vector nel nuovo vettore puntato da *temp
        for(int i = 0; i < *dim; i++){
            //temp[i] = vector[i];
            *(new_vector+i) = *(old_vector+i);
        }

        new_vector[(*dim)] = x;

        (*dim)++;
        
        free(old_vector);

    } else { 
        printf("Allocazione non riuscita\n");
        new_vector = old_vector;
    }

    return new_vector;

}

// Inserimento utilizzando la realloc per aumentare la dimensione del vettore di partenza
// La funzione ritorna il puntatore al nuovo vettore se l'allocazione riesce, altrimenti ritorna il puntatore al vettore di partenza
int* inserisci_realloc(int* old_vector, int* dim, int x){

    int* new_vector = (int *)realloc(old_vector, ((*dim)+1)*sizeof(int));

    if (new_vector != NULL){
        new_vector[*dim] = x;
        (*dim)++;   
    } else {
        printf("Allocazione non riuscita\n");
        new_vector = old_vector;
    }

    return new_vector;

}

// Inserimento utilizzando la malloc per allocare il nuovo vettore, contentente il vettore di partenza più l'elemento da inserire
// Il vettore di partenza è passatto come puntatore di puntatore, così da evitare il parametro di ritorno di tipo int * per puntare al nuovo vettore allocato
void inserisci_ptr2(int ** old_vector, int* dim, int x){

    int* new_vector = (int *) malloc(((*dim)+1) * sizeof(int));

    if (new_vector != NULL){

        for(int i = 0; i < *dim; i++){
            new_vector[i] = (*old_vector)[i];
            //*(temp+i) = *(*vector+i);
        }

        new_vector[(*dim)] = x;

        (*dim)++;

        *old_vector = new_vector;

    } else
        printf("Allocazione non riuscita\n");
    
}

// Inserimento utilizzando la realloc per aumentare la dimensione del vettore di partenza
// Il vettore di partenza è passatto come puntatore di puntatore, così da evitare il parametro di ritorno di tipo int * per puntare al nuovo vettore allocato
void inserisci_realloc_ptr2(int** old_vector, int* dim, int x){

    int * new_vector = (int *)realloc(*old_vector, ((*dim)+1)*sizeof(int));

    if (new_vector != NULL){
        new_vector[*dim] = x;
        (*dim)++;
        *old_vector = new_vector;
    } else 
        printf("Allocazione non riuscita\n");

}

// Rimozione di un elemento utilizzando la malloc per allocare il nuovo vettore, contentente il vettore di partenza a meno dell'elemento da eliminare
// La funzione ritorna il puntatore al nuovo vettore se l'allocazione riesce, altrimenti ritorna il puntatore al vettore di partenza
int* rimuovi(int* old_vector, int* dim, int posizione){

    int * new_vector = malloc(((*dim)-1) * sizeof(int));

    if (new_vector != NULL){
        for (int i = 0; i<posizione; i++)
            new_vector[i] = old_vector[i];
    
        for (int i = posizione; i<*dim; i++)
            new_vector[i] = old_vector[i+1];

        (*dim)--;
    } else {
        printf("Allocazione non riuscita");
        new_vector = old_vector;
    }

    return new_vector;
}


void stampa(int * vector, int * dim){

    for (int i = 0; i < (*dim); i++)
        printf("vector[%d] = %d\n", i, *(vector + i));

}