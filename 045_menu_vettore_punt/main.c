

/* 
 * MENU VETTORE
 */

#include <stdio.h>
#include <stdbool.h>

#define MAXDIM 50

void stampa(int v[], int riemp);
bool inserisci(int v[], int *riemp, int valore);
bool elimina(int v[], int *riemp, int valore_da_eliminare);
void ricerca2(int v[], int riemp, int valore_da_cercare, bool *trovato, int *posizione);
void ricerca_occorrenze2(int v[], int riemp, int valore_da_cercare, int *occorrenze);

/*
 * 
 */
int main() {
    int scelta;
    
    int a[MAXDIM] = {10, 12, 17, 3, 5, 17};
    int riemp = 6;
    int valore;

    do{
        printf("Scegli un'operazione fra le seguenti:\n");
        printf("1. stampa\n");
        printf("2. inserisci elemento\n");
        printf("3. elimina elemento\n");
        printf("4. ricerca elemento\n");
        printf("5. conta occorrenze\n");
        printf("0. esci\n");
        
        scanf("%d", &scelta);
        
        switch(scelta){
            case 1:
                stampa(a, riemp);
                break;
                    
                    
            case 2: 

                printf("valore da inserire: \n");
                scanf("%d", &valore);
                inserisci(a, &riemp, valore);
                break;

            case 3:
                printf("valore da eliminare: \n");
                scanf("%d", &valore);
                
                bool esito = elimina(a, &riemp, valore);
                
                if (esito)
                    printf("valore eliminato!\n");
                else
                    printf("valore non presente!\n");

                break;

            case 4: 
                printf("valore da cercare: \n");
                scanf("%d", &valore);
                int posizione;
                bool trovato = false;
                ricerca2(a, riemp, valore, &trovato, &posizione);
                if (trovato == true)
                    printf("Il valore %d è stato trovato in posiozione %d!\n", valore, posizione);
                else
                    printf("valore non trovato!\n");

                break;

            case 5:
                printf("valore da utilizzre per la ricerca delle occorrenze: \n");
                scanf("%d", &valore);
                int conteggio;
                ricerca_occorrenze2(a, riemp, valore, &conteggio);
                printf("Nel vettore il valore %d compare %d volta/e\n", valore, conteggio);

                break;

            case 0:
                printf("Arrivederci!\n");
                break;
            
            default:
                printf("Scelta non consentita!\n");
                    
                    
        }
        
    
    } while(scelta != 0);
    
    return 0;
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
    }
    return true;
}
    
void stampa(int v[], int riemp){
    
    printf("nel vettore sono presenti i seguenti elementi: \n");
    for (int i=0; i<riemp; i++)
        printf("%d, ", v[i]);
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

void ricerca2(int v[], int riemp, int valore_da_cercare, bool *trovato, int *posizione){
    
    *trovato = false;
    int i = 0;

    while(i<riemp && *trovato == false){
        
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

void ricerca_occorrenze2(int v[], int riemp, int valore_da_cercare, int *occorrenze){
    *occorrenze=0;
    for (int i=0; i<riemp; i++){
        if(v[i] == valore_da_cercare)
            (*occorrenze)++;
    }
    return;
}