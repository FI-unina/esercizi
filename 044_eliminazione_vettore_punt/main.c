
#include <stdio.h>
#include <stdbool.h>

#define MAXDIM 50

void ricerca2(int v[], int riemp, int valore_da_cercare, bool *trovato, int *posizione);
bool elimina(int v[], int *riemp, int valore_da_eliminare);
bool elimina2(int * v, int *riemp, int valore_da_eliminare);
void stampa(int v[], int riemp);

int main() {
    
    int vettore[MAXDIM] = {10, 12, 17, 3, 5, 17};
    int riemp = 6;
    
    stampa(vettore, riemp);
    
    bool esito = elimina(vettore, &riemp, 44);
    if (esito)
        printf("valore eliminato!\n");
    else
        printf("valore non presente!\n");
    stampa(vettore, riemp);
   
    esito = elimina2(vettore, &riemp, 17);
    if (esito)
        printf("valore eliminato!\n");
    else
        printf("valore non presente!\n");
    stampa(vettore, riemp);
    
    return 0;
}

void ricerca2(int v[], int riemp, int valore_da_cercare, bool *trovato, int *posizione){
    *trovato = false;
    int i = 0;
    while(i<riemp && *trovato==false){
        
        if(v[i]==valore_da_cercare)
            *trovato = true;
        else
            i++;
    }
    if (*trovato)
        *posizione = i;
    else
        *posizione = -1;   
    return;
}

void stampa(int v[], int riemp){
    printf("nel vettore sono presenti i seguenti elementi: \n");
    for (int i=0; i<riemp; i++)
        printf("%d, ", v[i]);
    printf("\n\n");
}

bool elimina(int v[], int *riemp, int valore_da_eliminare){
    int pos;
    
    bool valore_presente;

    ricerca2(v, *riemp, valore_da_eliminare, &valore_presente, &pos);
    
    if (!valore_presente)
        return false;
    else{
        (*riemp)--;
        for (int i=pos; i < *riemp; i++)
            v[i] = v[i+1];
        return true;
    }

}

bool elimina2(int * v, int *riemp, int valore_da_eliminare){
    int pos;
    
    bool valore_presente;

    ricerca2(v, *riemp, valore_da_eliminare, &valore_presente, &pos);
    
    if (!valore_presente)
        return false;
    else{
        (*riemp)--;
        for (int i=pos; i < *riemp; i++)
            *(v+i) = *(v+i+1);
        return true;
    }

}