#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DIM 100


int ricerca_sequenziale(int v[], int riemp, int x, int *);
int ricerca_binaria(int v[], int riemp, int x, int *);

void insert_vett_ordinato(int [], int *);
void insert_vett_random(int [], int *);

int cum_sum(int [], int);

int main() {
    
    int vett_rand[MAX_DIM];
    //int vett_ord[MAX_DIM];
    int *vett_ord = malloc(MAX_DIM *sizeof(int));


    int riemp_rand = 0, riemp_ord = 0, valore_da_trovare;
    int confronti_seq_worst, confronti_seq_avg, confronti_seq_best, confronti_bin_worst, confronti_bin_avg, confronti_bin_best;

    // crea vett ordinato
    //printf("Generazione vettore ordinato...\n");
    for (int j=0; j<100; j++)
        insert_vett_ordinato(vett_ord, &riemp_ord);

    // ricerca di 100 valori generati

    srand(time(NULL));
    int num_el = riemp_ord-1;    
        
    
    int confronti_seq_worst_vet[num_el];
    int confronti_seq_avg_vet[num_el];
    int confronti_seq_best_vet[num_el];

    int pos_seq_avg, pos_seq_worst, pos_seq_best;
    int pos_bin_avg, pos_bin_worst, pos_bin_best;

    int confronti_bin_worst_vet[num_el];
    int confronti_bin_avg_vet[num_el];
    int confronti_bin_best_vet[num_el];
    
    
    for (int i=0; i<num_el; i++){
        
        valore_da_trovare = rand() % 100;
        confronti_seq_worst = 0;
        confronti_seq_avg = 0;
        confronti_seq_best = 0;
        confronti_bin_worst = 0;
        confronti_bin_avg = 0;
        confronti_bin_best = 0;

        riemp_rand = 0;
        for (int j=0; j<100; j++){
            //printf("#%d Generazione vettore random...\n", j);
            insert_vett_random(vett_rand, &riemp_rand);
        }

        // RICERCA SEQUENZIALE

        // Caso migliore per ricerca sequenziale (valore_da_trovare = vett_rand[0])
        pos_seq_best = ricerca_sequenziale(vett_rand, riemp_rand, vett_rand[0], &confronti_seq_best);

        // Caso medio per ricerca sequenziale (valore_da_trovare in posizione random)
        pos_seq_avg = ricerca_sequenziale(vett_rand, riemp_rand, valore_da_trovare, &confronti_seq_avg);

        // Caso peggiore per ricerca sequenziale (valore_da_trovare = vett_rand[riemp_rand-1])
        pos_seq_worst = ricerca_sequenziale(vett_rand, riemp_rand, vett_rand[riemp_rand-1], &confronti_seq_worst);

        if (pos_seq_worst != -1 && pos_seq_avg != -1 && pos_seq_best != -1){
            
            confronti_seq_worst_vet[i] = confronti_seq_worst;
            confronti_seq_avg_vet[i] = confronti_seq_avg;
            confronti_seq_best_vet[i] = confronti_seq_best;

        }
        else
            printf("Elemento non trovato\n");

        // RICERCA BINARIA
        // Caso peggiore per ricerca binaria (valore_da_trovare = vett_ord[riemp_ord-1])
        pos_bin_worst = ricerca_binaria(vett_ord, riemp_ord, vett_ord[riemp_ord-1], &confronti_bin_worst);

        // Caso medio per ricerca binaria (valore_da_trovare random)
        pos_bin_avg = ricerca_binaria(vett_ord, riemp_ord, valore_da_trovare, &confronti_bin_avg);
        
        // Caso migliore per ricerca binaria (valore_da_trovare = vett_rand[medio])
        int medio= (int)( (0+riemp_ord-1)/2);
        pos_bin_best = ricerca_binaria(vett_ord, riemp_ord, vett_ord[medio], &confronti_bin_best);

        if (pos_bin_worst != -1 && pos_bin_avg != -1 && pos_bin_best != -1){
         
            confronti_bin_worst_vet[i] = confronti_bin_worst;
            confronti_bin_avg_vet[i] = confronti_bin_avg;
            confronti_bin_best_vet[i] = confronti_bin_best;

        }
        else
            printf("Elemento non trovato\n");

    }

    // compute mean
    int cum_sum_confronti_seq_worst = 0, cum_sum_confronti_seq_avg = 0, cum_sum_confronti_seq_best = 0;
    int cum_sum_confronti_bin_worst = 0, cum_sum_confronti_bin_avg = 0, cum_sum_confronti_bin_best = 0;

    for (int i=0; i<num_el; i++){

        cum_sum_confronti_seq_worst += confronti_seq_worst_vet[i];
        cum_sum_confronti_seq_avg += confronti_seq_avg_vet[i];
        cum_sum_confronti_seq_best += confronti_seq_best_vet[i];

        cum_sum_confronti_bin_worst += confronti_bin_worst_vet[i];
        cum_sum_confronti_bin_avg += confronti_bin_avg_vet[i];
        cum_sum_confronti_bin_best += confronti_bin_best_vet[i];

    }

    printf("[CASO PEGGIORE]\tRicerca sequenziale. Sum: %d Media confronti: %.2f\n", cum_sum_confronti_seq_worst, (float)cum_sum_confronti_seq_worst/num_el);
    printf("[CASO MEDIO]\tRicerca sequenziale. Sum: %d Media confronti: %.2f\n", cum_sum_confronti_seq_avg, (float)cum_sum_confronti_seq_avg/num_el);
    printf("[CASO MIGLIORE]\tRicerca sequenziale. Sum: %d Media confronti: %.2f\n", cum_sum_confronti_seq_best, (float)cum_sum_confronti_seq_best/num_el);

    printf("\n\n");
    printf("[CASO PEGGIORE]\tRicerca binaria. Sum: %d Media confronti: %.2f\n", cum_sum_confronti_bin_worst, (float)cum_sum_confronti_bin_worst/num_el);
    printf("[CASO MEDIO]\tRicerca binaria. Sum: %d Media confronti: %.2f\n", cum_sum_confronti_bin_avg, (float)cum_sum_confronti_bin_avg/num_el);
    printf("[CASO MIGLIORE]\tRicerca binaria. Sum: %d Media confronti: %.2f\n", cum_sum_confronti_bin_best, (float)cum_sum_confronti_bin_best/num_el);

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
    //printf("Valore da cercare %d [confronti: %d]\n", x, *confronti);

    for (i=0; i<riemp; i++){

        //printf("CHECK #%d\n", i);
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
    
    /* 
    // VERSIONE con il WHILE e var booleana
    bool trovato=false;

    while (primo<=ultimo && !trovato) { 
	    
        medio = (int)(primo+ultimo)/2;
        printf("[ricerca] v[%d]: %d\n", medio, v[medio]);

	    if(v[medio] == x){
		    trovato = true;
            pos = medio;
        }
	    else if (x > v[medio]){
		    primo = medio + 1;
        }
	    else { 
		    ultimo = medio - 1;
        }
        (*confronti)++;
    }
    */
	return pos;
}

