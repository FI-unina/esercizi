#include <stdio.h>
#include <stdbool.h>

#define MAXDIM 8


void stampa(int v[], int riemp);
void stampa2(int *v, int riemp);
bool inserisci(int v[], int *riemp, int valore);
void inserisci2(int v[], int *riemp, int valore, bool *esito);
void inserisci3(int *v, int *riemp, int valore, bool *esito);

    int main() {
    
    int vettore[MAXDIM] = {10, 12, 17, 3, 5, 17};
    int riemp = 6;
    bool esito = false;

    // inserimento #1
    //esito = inserisci(vettore, &riemp, 44);
    //inserisci2(vettore, &riemp, 44, &esito);
    inserisci3(vettore, &riemp, 44, &esito);
    if (esito)
        printf("valore inserito con successo!\n");
    else
        printf("non è possibile inserire altri elementi!\n");
    //stampa(vettore, riemp);
    stampa2(vettore, riemp);
    
    // inserimento #2
    //esito = inserisci(vettore, &riemp, 55);
    //inserisci2(vettore, &riemp, 55, &esito);
    inserisci3(vettore, &riemp, 55, &esito);
    if (esito)
        printf("valore inserito con successo!\n");
    else
        printf("non è possibile inserire altri elementi!\n");
    //stampa(vettore, riemp);
    stampa2(vettore, riemp);
    
    // inserimento #3
    //esito = inserisci(vettore, &riemp, 66);
    //inserisci2(vettore, &riemp, 66, &esito);
    inserisci3(vettore, &riemp, 66, &esito);
    if (esito)
        printf("valore inserito con successo!\n");
    else
        printf("non è possibile inserire altri elementi!\n");
    //stampa(vettore, riemp);
    stampa2(vettore, riemp);

    // inserimento2 
    //esito = inserisci(vettore, &riemp, 77);
    //inserisci2(vettore, &riemp, 77, &esito);
    inserisci3(vettore, &riemp, 77, &esito);
    if (esito)
        printf("valore inserito con successo!\n");
    else
        printf("non è possibile inserire altri elementi!\n");
    //stampa(vettore, riemp);
    stampa2(vettore, riemp);

    return 0;
}

void stampa(int v[], int riemp){
    
    printf("nel vettore sono presenti i seguenti elementi: \n");
    for (int i=0; i<riemp; i++)
        printf("%d, ", v[i]);
    printf("\n\n");
}

void stampa2(int *v, int riemp){
    
    printf("nel vettore sono presenti i seguenti elementi: \n");
    for (int i=0; i<riemp; i++)
        printf("%d, ", *(v+i));
    printf("\n\n");
}

bool inserisci(int v[], int *riemp, int valore){
    
    if(*riemp < MAXDIM){
        v[*riemp] = valore;
        (*riemp)++;
        return true;
    }
    else 
        return false;   
}


void inserisci2(int v[], int *riemp, int valore, bool *esito){

    if(*riemp < MAXDIM){
        v[*riemp] = valore;
        (*riemp)++;

        *esito = true;
    }
    else 
        *esito = false;
}

void inserisci3(int * v, int *riemp, int valore, bool *esito){

    if(*riemp < MAXDIM){
        *(v+(*riemp)) = valore;
        (*riemp)++;

        *esito = true;
    }
    else 
        *esito = false;
}