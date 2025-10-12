/* 
 * Data una matrice con 4 righe e 3 colonne, 
 * calcolare la somma ed il massimo dei valori per ogni riga.
 */

#include <stdio.h>

#define NRIGHE 4
#define NCOLONNE 3

void stampa_matrice(float m[NRIGHE][NCOLONNE]);
void massimo(float m[NRIGHE][NCOLONNE], float max[NRIGHE]);
void somma(float m[NRIGHE][NCOLONNE], float sum[NRIGHE]);

int main() {

    float mat[NRIGHE][NCOLONNE];
    
    // inizializzazione matrice
    for (int i=0; i<NRIGHE; i++)
        for (int j=0; j<NCOLONNE; j++){
            printf("inserisci elemento di posizione (%d, %d)\n", i, j);
            scanf("%f", &mat[i][j]);
        }
    
    stampa_matrice(mat);
    
    // dichiaro array in cui la funzione passerà il risultato    
    float vet_massimi[NRIGHE];
    
    massimo(mat, vet_massimi);
    printf("MASSIMI RIGA:\n");
    for (int i=0; i<NRIGHE; i++)
        printf("%f\n", vet_massimi[i]);
  
    // dichiaro array in cui la funzione passerà il risultato
    float vet_somme[NRIGHE];  
    somma(mat, vet_somme);
    printf("SOMME RIGA:\n");
    for (int i=0; i<NRIGHE; i++)
        printf("%f\n", vet_somme[i]);
      
    return 0;
}


void stampa_matrice(float m[NRIGHE][NCOLONNE]){
    
    for (int i=0; i<NRIGHE; i++){
        
        for (int j=0; j<NCOLONNE; j++)
            printf("%f, ", m[i][j]);
        
        printf("\n");
    }

};

void massimo(float m[NRIGHE][NCOLONNE], float max[NRIGHE]){
    
    for (int i=0; i<NRIGHE; i++){
        float massimo_riga;
        for (int j=0; j<NCOLONNE; j++){
            if (m[i][j] > massimo_riga || j==0)
                massimo_riga = m[i][j];
        }
        max[i] = massimo_riga;
    }

}

void massimo2(float m[NRIGHE][NCOLONNE], float max[NRIGHE]){
    
    for (int i=0; i<NRIGHE; i++){
        float massimo_riga = m[i][0];
        for (int j=1; j<NCOLONNE; j++){
            if (m[i][j] > massimo_riga)
                massimo_riga = m[i][j];
        }
        max[i] = massimo_riga;
    }

}

void somma(float m[NRIGHE][NCOLONNE], float sum[NRIGHE]){

        for (int i=0; i<NRIGHE; i++){
            float somma_riga = 0;
            for (int j=0; j<NCOLONNE; j++)
                somma_riga += m[i][j];
            sum[i] = somma_riga;
    }
    
}