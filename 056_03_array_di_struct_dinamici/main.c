#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct{
	int campo1;
	int campo2;
} strutturaGenerica;


void inserisciDimensione(int *);
void inserisciElementi (strutturaGenerica *, int);
void stampaVettore (strutturaGenerica *, int);
strutturaGenerica massimo(strutturaGenerica *, int );
int occorrenzeZeri(strutturaGenerica *, int );
strutturaGenerica* rimuovi(strutturaGenerica *, int *, int , bool *);
strutturaGenerica* aggiungi (strutturaGenerica *, int *, int , strutturaGenerica , bool *);
bool ricercaLineare(strutturaGenerica *, int, int, int*);
void ordina(strutturaGenerica *, int);

int main() {
    strutturaGenerica *vettore;
    int riempimento;
    strutturaGenerica maxElem;
    int posizione;
    bool esito;
    strutturaGenerica elementoDaInserire;
    int elementoDaCercareInCampo1;
    int posizioneElemento;
    char scelta;
    //Chiediamo prima quanti elementi contiene il vettore
    inserisciDimensione(&riempimento);
    //ora possiamo allocare lo spazio necessario per memorizzare il vettore
    vettore = malloc(riempimento*sizeof(strutturaGenerica));
    if (vettore){
        inserisciElementi (vettore, riempimento);
        printf("Il vettore inserito è:\n");
        stampaVettore (vettore, riempimento);
        printf("\n");
        printf("Operazioni su vettore\n");
        printf("m: massimo, z: occorrenze zeri, c: cancellazione elemento, i: inserimento, r: ricerca, o: ordinamento\n");
        scanf(" %c", &scelta);
        switch (scelta) {
        case 'm':
            maxElem = massimo(vettore, riempimento);
            printf("L'elemento con massimo prodotto tra i campi è:\n");
            printf("%d\t",maxElem.campo1);
            printf("%d\n",maxElem.campo2);
            break;
        case 'z':
            printf("Nel vettore ci sono %d record con \"campo 2\" nullo\n", occorrenzeZeri(vettore, riempimento));
            break;
        case 'c':
            printf("Digitare la posizione dell'elemento da eliminare: ");
            scanf("%d", &posizione);
            vettore = rimuovi(vettore, &riempimento, posizione, &esito);
            if (esito) {
                printf("Il nuovo vettore e':\n");
                stampaVettore(vettore, riempimento);
                printf("\n");
            } else {
                printf("Errore!!! la posizione inserita supera la dimensione del vettore, oppure e' negativa\n");
            }
            break;
        case 'i':
            printf("Immettere la posizione in cui inserire l'elemento ");
            scanf("%d", &posizione);
            printf("Digitare il campo 1 dell'elemento da inserire: ");
            scanf("%d", &elementoDaInserire.campo1);
            printf("Digitare il campo 2 dell'elemento da inserire: ");
            scanf("%d", &elementoDaInserire.campo2);
            
            vettore = aggiungi(vettore, &riempimento, posizione, elementoDaInserire, &esito);
            if (esito) {
                printf("Il nuovo vettore e':\n");
                stampaVettore(vettore, riempimento);
                printf("\n");
            } else {
                printf("Errore!!! la posizione inserita supera la dimensione del vettore, oppure e' negativa\n");
            }
            break;
        case 'r':
            printf("Inserire l'elemento da cercare nel campo 1 degli elementi del vettore ");
            scanf("%d", &elementoDaCercareInCampo1);
            if(ricercaLineare(vettore, riempimento, elementoDaCercareInCampo1, &posizione)){
                    printf("Primo elemento trovato in posizione %d: \n",posizione);
                }
            else{
                    printf("Elemento non trovato\n");
                } 
            printf("\n");
            break;
        case 'o':
            ordina(vettore, riempimento);
            printf("Ordinamento...\n");
            printf("Il vettore ordinato in senso crescente è:\n");
            stampaVettore(vettore, riempimento);
            printf("\n");
        default: 
            printf("Scelta non consentita\n");
            break;
        }
    } else {
        printf("Impossibile allocare la memoria richiesta\n");
    }
    printf("Programma terminato\n");
    return 0;
}

//procedura per l'inserimento della dimensione del vettore
void inserisciDimensione(int *dim) {
    do {
        printf("Inserisci il numero di elementi del vettore: ");
        scanf("%d", dim);
        if (dim<=0){
            printf("Errore !!! Il vettore non puo' essere vuoto\n");
        }
    } while (dim<=0);
}

//procedura per l'inserimento degli elementi del vettore
void inserisciElementi (strutturaGenerica *vet, int dim) {
    for (int i=0; i<dim; i++) {
        printf("Inserisci il campo 1 dell'elemento di posizione %d: ",i);
        scanf("%d", &(vet+i)->campo1);
        printf("Inserisci il campo 2 dell'elemento di posizione %d: ",i);
        scanf("%d", &(vet+i)->campo2);
    }
}

//procedura per la stampa a video del vettore
void stampaVettore (strutturaGenerica *vet, int dim) {
    
    for(int i=0;i<dim;i++) {
        printf("%d\t",(vet+i)->campo1);
        printf("%d\n",(vet+i)->campo2);
    }
}

/*funzione che restituisce l'elemento del vettore che ha il massimo 
valore del prodotto tra campo1 e campo2*/

strutturaGenerica massimo(strutturaGenerica *vet, int dim) {
    strutturaGenerica maxElemento = *vet;
    int max=vet->campo1*vet->campo2;
    for(int i=1;i<dim;i++) {
        if (((vet+i)->campo1)*((vet+i)->campo2)>max){
            maxElemento=*(vet+i);
            max=((vet+i)->campo1)*((vet+i)->campo2);
        }		
    }
    return maxElemento;
}

/*Funzione che rimuove elemento in posizione pos. 
La variabile boolena esito è false se si tenta di rimuovere un elemento di posizione
negativa oppure maggiore della dimensione del vettore, true altrimenti.
La funzione restituisce un puntatore a strutturaGenerica, ossia il puntatore al primo elemento del
vettore  in cui è stato cancellato l'elemento di posizione pos*/

strutturaGenerica* rimuovi(strutturaGenerica *vet, int *dim, int pos, bool *esito) {
    if(pos>=0 && pos<*dim){
        //possibile eliminare
        strutturaGenerica *nuovoVet;
        int new_vet_dim = (*dim)-1;

        nuovoVet = malloc(new_vet_dim * sizeof(strutturaGenerica));

        for(int i=0; i<pos; i++) {
               *(nuovoVet+i) = *(vet+i);
            }   
        for (int i=pos+1; i<*dim; i++) {
            *(nuovoVet+i-1) = *(vet+i);
        }
        
        *dim = new_vet_dim;

        *esito = true;
        free(vet);

        return nuovoVet;
    } else {
        *esito = false;
        return vet;
    }
}

/*funzione che aggiunge elemento elem in posizione pos, 
La variabile boolena esito è false se si tenta di rimuovere un elemento di posizione
negativa oppure maggiore della dimensione del vettore, true altrimenti.
Nel caso in cui l'inserimento avvenga in maniera corretta
allora la funzione restitruisce un esito pari a 0*/
strutturaGenerica* aggiungi (strutturaGenerica *vet, int *dim, int pos, strutturaGenerica elem, bool *esito) {
    
    if(pos>=0 && pos<*dim+1){
        //possibile inserire
            
        strutturaGenerica *nuovoVet;
        int new_vet_dim = (*dim)+1;
        nuovoVet = malloc(new_vet_dim * sizeof(strutturaGenerica));

        for(int i=0; i<pos; i++) {
            *(nuovoVet+i) = *(vet+i);
        }   

        *(nuovoVet+pos)=elem;

        for (int i=pos+1; i<new_vet_dim; i++) {
            *(nuovoVet+i) = *(vet+i-1);
        }

        *dim = new_vet_dim; //aggiorno la dimensione corrente alla nuova dimensione nuova

        *esito = true;
        free(vet);
        return nuovoVet;

    } else {
        *esito = false;
        return vet;
    }
}

/*funzione che svolge la ricerca lineare di un elemento elem in un vettore
In questo caso la funzione cerca la posizione del primo elemento il cui campo 1 è
uguale all'elemento cercato
*/
bool ricercaLineare(strutturaGenerica *vet, int dim, int elem, int *posizione){
    bool trovato=false;
    *posizione=0;
    while (!trovato && *posizione<dim) {
        if((vet+*posizione)->campo1==elem) {
            trovato=true;
        } else {
            (*posizione)++;
        }
    }
    return trovato;
}

/*ordinamento per l'ordinamento in ordina crescente. Algoritmo del selection sort.
In questo caso la procedura ordina in senso crescente in base alla somma dei campi 
degli elementi del vettore 
*/
void ordina(strutturaGenerica *vet, int dim) {
    strutturaGenerica *temp;
    temp=malloc(sizeof(strutturaGenerica));
    int min, pos;
    for(int i=0; i<dim-1; i++) {
        min=(vet+i)->campo1+(vet+i)->campo2;
        pos=i;
        for (int j=i+1;j<dim;j++){
            if ((vet+j)->campo1+(vet+j)->campo2<min) {
                min=(vet+j)->campo1+(vet+j)->campo2;
                pos=j;
            }
        }
        if (i!=pos){
            //algoritmo di scambio
            *temp=*(vet+i); 
            *(vet+i)=*(vet+pos); 
            *(vet+pos)=*temp;
        }
    }
}

//funzione per il calcolo delle occorrenze dei valori nulli del campo 2 delle strutture inserite
int occorrenzeZeri(strutturaGenerica* vet, int dim){
    int occorrenze=0;
    for (int i=0; i<dim; i++){
        if ((vet+i)->campo2==0){
            occorrenze++;
        }
    }
    return occorrenze;
}