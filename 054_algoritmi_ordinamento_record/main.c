
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N_MAX 30

typedef struct{
	char Nome[N_MAX];
	char Cognome[N_MAX];
	int eta;	
} Studente;

typedef Studente tipo_v;


Studente leggi_studente();
void inserisci_studente(tipo_v v[],int* n,tipo_v s);

bool confronta_studente(Studente,Studente);

void ordina_classe_selection_sort(tipo_v v[],int n);
void ordina_classe_insertion_sort(tipo_v v[],int n);
void visualizza_classe(Studente v[],int n);

void ordina_classe_indici_selection_sort(tipo_v v[],int n, int index []);
void visualizza_classe_indici(Studente v[], int n, int index[]);

int main(){
	

	int n = 0;
	char scelta = 'y';
	Studente s, classe[N_MAX];

	
	
	while(n < N_MAX && scelta == 'y'){
		s = leggi_studente();
		inserisci_studente(classe, &n, s);
		printf("Inserisci nuovo studente? (y/n) ");
		scanf(" %c", &scelta);
	}
	
	printf("Classe disordinata: \n");
	visualizza_classe(classe, n);	
	
	int ord_scelto;
	
	printf("\nQuale ordinamento vuoi utilizzare?\n");
	printf("1. Selection sort (in place)\n");
	printf("2. Selection sort (con indici)\n");
	printf("3. Insertion sort \n");
	scanf("%d", &ord_scelto);
	
	printf("\nClasse ordinata: \n");
	switch (ord_scelto){
	
		case 1: ordina_classe_selection_sort(classe,n);
				visualizza_classe(classe,n);
				break;
		case 2:{
				int index[N_MAX];
				ordina_classe_indici_selection_sort(classe, n, index);
				visualizza_classe_indici(classe, n, index);
				break;
		}
		case 3:
				ordina_classe_insertion_sort(classe, n);
				visualizza_classe(classe,n);
				break;
	};

	printf("\n\n\n");
	
}

Studente leggi_studente(){
	Studente s;
	printf("Inserisci nome (senza spazi): ");
	scanf("%s", s.Nome);
	printf("Inserisci cognome (senza spazi): ");
	scanf("%s", s.Cognome);	
	printf("Inserisci eta': ");
	scanf("%d", &s.eta);

	return s;
}


void inserisci_studente(tipo_v v[], int* n, tipo_v s){
	
	strcpy(v[*n].Nome, s.Nome);
	strcpy(v[*n].Cognome, s.Cognome);
	v[*n].eta = s.eta;
	(*n)++;
}



void visualizza_classe(Studente v[],int n){
	for(int i=0;i<n;i++)
		printf("%d) %s - %s - %d\n", i, v[i].Cognome, v[i].Nome, v[i].eta);
}


void scambia(tipo_v v[],int i,int j){
	tipo_v temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	
}

bool confronta_studente(Studente v1,Studente v2){
	bool minore=false;
	int confronto;
	
	confronto = strcmp(v1.Cognome,v2.Cognome); // confrontiamo i cognomi

	if (confronto<0) //il cognome è alfabeticamente minore 
		minore = true;
	else if (confronto == 0){ // se i cognomi sono uguali confrontiamo i nomi
		confronto = strcmp(v1.Nome,v2.Nome); // confrontiamo i nomi
		if (confronto<0) //il nome è alfabeticamente minore 
			minore = true;
		else if (confronto == 0){ // se anche i nomi sono uguali confrontiamo le età
			minore = v1.eta < v2.eta; // confrontiamo le eta
		}
	}	
	
	return minore;
}

void ordina_classe_selection_sort(tipo_v v[],int n){
	
	int min,i,j;
	for(i=0; i<n-1; i++){
		// si trova l'elemento più piccolo dell'array e si scambia con l'elemento alla posizione i
		min=i;   
		for (j=i+1;j<n;j++){
			if ( confronta_studente(v[j],v[min]) )
				min=j;						
		}	
		scambia(v,i,min);
	}	
}

void ordina_classe_insertion_sort(tipo_v v[],int n){

    // i: inizio semivettore non ordinato
    for (int i=1; i<n; i++){
        int j = i;
        
		while(confronta_studente(v[j], v[j-1]) && j>0){
            scambia(v, j, j-1);
            j--;
        }
        
    }	
}


void scambia_indici(int index[], int i, int j){
	int temp;
	temp = index[i];
	index[i] = index[j];
	index[j] = temp;
	
}

void ordina_classe_indici_selection_sort(tipo_v v[], int n, int index_vector[]){
	
	int min,i,j;
	
	for (i=0; i<n; i++)
		index_vector[i] = i;
		
	for(i=0; i<n-1; i++){
		// si trova l'elemento più piccolo dell'array e si scambia con l'elemento alla posizione i
		min=i;   
		for (j=i+1;j<n;j++){
			if ( confronta_studente(v[index_vector[j]],v[index_vector[min]]) )
				min=j;						
		}	
		scambia_indici(index_vector,i,min);
		scambia(index_vector,i,min);
	}	
}

void visualizza_classe_indici(Studente v[], int n, int index[]){
	for(int i=0; i<n; i++)
		printf("%d) %s - %s - %d\n", i, v[index[i]].Cognome, v[index[i]].Nome, v[index[i]].eta);
}
