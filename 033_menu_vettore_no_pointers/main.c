

/* 
 * MENU VETTORE
 */

#include <stdio.h>
#include <stdbool.h>

#define MAXDIM 1000

void stampa(int v[], int riemp);
int inserisci(int v[], int riemp, int valore);
int elimina(int v[], int riemp, int valore_da_eliminare);
int ricerca(int v[], int riemp, int valore_da_cercare);

/*
 * 
 */
int main() {
    int scelta;

    // TIPO NOME_VAR;
    

    int vettore[MAXDIM] = {10, 12, 17, 3, 5, 17};

    int riemp = 6;
    int valore;
    int ris;
    do{
        printf("Scegli un'operazione fra le seguenti:\n");
        printf("1. stampa\n");
        printf("2. inserisci elemento\n");
        printf("3. elimina elemento\n");
        printf("4. ricerca elemento\n");
        printf("0. esci\n");
        
        scanf("%d", &scelta);
        
        switch(scelta){
            case 1:
                ///printf(vettore).> stampa l'indirizzo del primo elemento di vettore
                stampa(vettore, riemp);
                break;
                                    
            case 2: 

                printf("valore da inserire: \n");
                scanf("%d", &valore);
                ris = inserisci(vettore, riemp, valore);
                if (ris != -1)
                    riemp = ris; // AGGIORNO IL RIEMPIMENTO DOPO LA CHIAMATA a inserisci
                else
                    printf("Dimensione massima del vettore raggiunta\n");
                break;

            case 3: 

                printf("indica l'elemento da eliminare: \n");
                scanf("%d", &valore);
                ris = elimina(vettore, riemp, valore);
                if (ris != -1)
                    riemp = ris;
                else
                    printf("Elemento da eliminare non trovato!\n");
                break;

            case 4: 

                printf("valore da ricercare: \n");
                scanf("%d", &valore);
                printf("Prima occorrenza del valore ricercato è alla posizione %d\n", ricerca(vettore, riemp, valore));
                break;
            
            default:
                printf("Scelta non consentita!\n");
                    
                    
        }
        
    
    } while(scelta != 0);
    
    printf("Arrivederci!\n");
    return 0;
}

int elimina(int v[], int riemp, int valore_da_eliminare){
    
    int pos = ricerca(v, riemp, valore_da_eliminare);
    
    if (pos == -1)
        return -1;
    else{
        riemp--; // posso metterla dopo quest'istruzione??? che cambia?
        for (int i=pos; i < riemp; i++)
            v[i] = v[i+1];
        
    }
    return riemp;
}
    
void stampa(int v[], int riemp){
    
    printf("Nel vettore sono presenti i seguenti elementi: \n");
    for (int i=0; i<riemp; i++)
        printf("%d, ", v[i]);
    printf("\n\n");
}

int inserisci(int v[], int riemp, int valore){
    
    if(riemp < MAXDIM){
        v[riemp] = valore;
        riemp++;
        return riemp;
    }
    else 
        return -1;   
}

int ricerca(int v[], int riemp, int valore_da_cercare){
    
    bool trovato = false;
    int i = 0;
    
    while(i<riemp && trovato == false){
    
        if(v[i]==valore_da_cercare){
            trovato = true;
            //è possibile usare il break?
        }
        else
            i++;
    }
    if (trovato)
        return i;
    else
        return -1;   
}