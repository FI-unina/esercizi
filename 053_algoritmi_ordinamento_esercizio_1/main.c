#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_DIM 20
#define MAX_DIM 100

void selection_sort(int v[], int dimensione); // ricerca minimo...

void insertion_sort(int v[], int dimensione);
void insertion_sort_opt(int v[], int dimensione);

int ricerca_binaria(int v[], int n, int x);


// funzioni di utilità
int inserisci_numero(int min,int max);
int minimo(int v[], int inizio, int fine);
void scambia(int *a, int *b);
void stampa(int v[], int dimensione);
void genera_vettore(int v[], int riemp);



int main() {
    
    int a[MAX_DIM];
    int riemp = 0, x, pos;

    srand(time(NULL));

    riemp = inserisci_numero(MIN_DIM, MAX_DIM);
    
    genera_vettore(a, riemp);
    
    printf("Prima dell'ordinamento:\n");
    stampa(a, riemp);
    
    selection_sort(a, riemp);
    //insertion_sort(a, riemp);
    //insertion_sort_opt(a, riemp);
    printf("Dopo l'ordinamento:\n");
    stampa(a, riemp);

    do{
	
		printf("Inserisci un numero da cercare: ");
		scanf("%d", &x);
		
		if (x>=0){
			
            pos = ricerca_binaria(a, riemp, x);
		 
			if(pos!=-1)
				printf("Numero trovato in posizione: %d (infatti a[%d]= %d)\n", pos, pos, a[pos]);
			else 
				printf("Numero non trovato\n");	
		
			printf("\n\n");
		}
	
	}while(x>=0);
    
    return 0;
}

/*
 * restituisce l'indice dell'elemento minimo, considerando gli 
 * elementi in posizione da inzio a fine
 */
int minimo(int v[], int inizio, int fine){
    int min;
    int indice_min;
    for (int i=inizio; i<=fine; i++){
        if (v[i] < min || i==inizio){
            indice_min = i;
            min = v[i];
        }
    }
    return indice_min;        
}

/*
 * scambia il valore degli elementi a e b
 */
void scambia(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

/*
 * stampa gli elementi del vettore V fino all'indice dimensione.
 */
void stampa(int v[], int dimensione){
    
    for(int i=0; i<dimensione; i++)
        printf("%d ",v[i]);
    printf("\n");
}
    
void selection_sort(int v[], int dimensione){
    
    for (int i=0; i<dimensione-1; i++){
        int pos_min = minimo(v, i, dimensione-1);
        scambia(&v[i], &v[pos_min]);
        
        printf("vettore dopo l'iterazione %d\n", i);
        stampa(v, dimensione);
    }
}

void insertion_sort(int v[], int dimensione){

    // i: inizio semivettore non ordinato
    for (int i=1; i<dimensione; i++){
        int j = i;
        while(v[j] < v[j-1] && j>0){
            scambia(&v[j], &v[j-1]);
            j--;
        }
        printf("vettore dopo l'iterazione %d\n", i-1);
        stampa(v, dimensione);
    }
}

void insertion_sort_opt(int v[], int dimensione){
    //sostituisce gli scambi con assegnazioni
    // seguite da un'assegnazione finale.
    
    //i: inizio della porzione NON ordinata
    //j: fine della porzione ordinata
    // tmp: variabile d'appoggio
    int i, j, tmp;

    for (int i=1; i<dimensione; i++){
        int tmp = v[i];
        j=i-1;
        while(tmp < v[j] && j>=0){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = tmp;
    }
}

int inserisci_numero(int min, int max){
	int n;
	do{
		printf("Inserisci numero da %d a %d : ", min, max);
		scanf("%d", &n);	
	
	}while ( n < min || n > max);
	
	return n;	
}

void genera_vettore(int v[], int riemp){

	for(int i=0; i<riemp; i++)
		v[i] = rand() % 101; // modificare come si vuole
	
}

int ricerca_binaria(int v[], int n, int x){

	int primo=0, ultimo=n-1, medio, pos=-1;

	do { 
		medio= (int)((primo+ultimo)/2);
		
		if (v[medio]==x)  
			pos=medio;
		else if (v[medio]<x)
			primo=medio+1;
		else
			ultimo=medio-1;

	} while(primo<=ultimo && pos==-1);	

	return pos;
}

