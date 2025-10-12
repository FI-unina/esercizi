#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_DIM 100


int ricerca_sequenziale(int v[], int riemp, int x, int *);
int ricerca_binaria(int v[], int riemp, int x, int *);

void insert_vett_ordinato(int [], int *);
void insert_vett_random(int [], int *);

int cum_sum(int [], int);

int main() {
    
    int vett_rand[MAX_DIM];
    int vett_ord[MAX_DIM];

    int riemp_rand = 0, riemp_ord = 0, valore, pos;
    int confronti_seq = 0, confronti_bin = 0;

    // crea vett ordinato
    int i;
    for (i=0; i<100; i++)
        insert_vett_ordinato(vett_ord, &riemp_ord);
    
    srand(time(NULL));
    for (i=0; i<100; i++)
        insert_vett_random(vett_rand, &riemp_rand);

    printf("somma array ordinato: %d\n", cum_sum(vett_ord, riemp_ord));
    printf("somma array ordinato: %d\n", cum_sum(vett_ord, riemp_ord));

    printf("Inserisci elemento da cercare (ricerca sequenziale)\n");
    scanf("%d", &valore);
    
    pos = ricerca_sequenziale(vett_rand, riemp_rand, valore, &confronti_seq);
    if (pos != -1)
        printf("Elemento %d trovato alla posizione %d tramite ricerca sequenziale (num. confronti: %d)\n", valore, pos, confronti_seq);
    else
        printf("Elemento non trovato\n");

    pos = ricerca_binaria(vett_ord, riemp_ord, valore, &confronti_bin);
    if (pos != -1)
        printf("Elemento %d trovato alla posizione %d tramite ricerca binaria (num. confronti: %d)\n", valore, pos, confronti_bin);
    else
        printf("Elemento non trovato\n");

    return 0;
}

int cum_sum(int v[], int n){
    int i, sum = 0;
    for (i=0; i<n; i++)
        sum = sum + v[i];
    return sum;
}

void insert_vett_random(int vett_ord[], int *riemp){

    int val, i;
    // genera un nuovo valore finchè non esiste nell'array
    
    
    if (*riemp == 0)
        val = rand() % 100;
    else {
        int ok_to_add = 1;
        while (ok_to_add){
            
            i = 0;
            val = rand() % 100; // genera un nuovo valore

            while(i<*riemp){ //cerca su tutti gli elementi dell'array
                //printf("check v[%d]: %d \n", i, vett_ord[i]);
                    
                if (val == vett_ord[i]) //non ho già inserito val nell'array, esci dal ciclo
                    break;
                else
                    i++;
            }
            if (i == *riemp) // se sono arrivato alla fine senza trovare un val già inserito esco dal ciclo esterno (ok=0)
                ok_to_add = 0;
        }
    }
    
    vett_ord[*riemp] = val;
    (*riemp)++;
    
}

void insert_vett_ordinato(int vett_ord[], int *riemp){

    vett_ord[*riemp] = *riemp;
    (*riemp)++;
}

int ricerca_sequenziale(int v[], int riemp, int x, int *confronti){

    int pos = -1, i;

    for (i=0; i<riemp; i++){

        if (v[i] == x){
            pos = i;
            break;
        }
        (*confronti)++;
    }
    return pos;

}


int ricerca_binaria(int v[], int riemp, int x, int *confronti){
	int primo=0, ultimo = riemp-1, medio, pos=-1;

	do { 
        
        medio= (int)( (primo+ultimo)/2);
        if (v[medio]==x){
			pos=medio;    
        }
        else if (v[medio]<x){
			primo=medio+1;    
        }
        else {
			ultimo=medio-1;
        }
        
        (*confronti)++;

	} while(primo<=ultimo && pos==-1);	

	return pos;
}

