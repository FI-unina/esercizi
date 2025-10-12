/*
 * Progettare ed implementare un programma che gestisce l’inventario 
 * di una biblioteca.
 * Per ciascun libro vengano memorizzate le seguenti informazioni:
 * autore, titolo, anno pubblicazione, numero di copie.
 * Per semplicità, si assuma che la biblioteca possa inventariare al più 200 libri.
 * 
 * Inizializzare la struttura dati con le seguenti informazioni (4 libri):
 * Virgilio, Eneide, 19 a.C., 5 copie,
 * Andrea Camilleri, La forma dell'acqua, 1994, 2 copie,
 * Frank Herbert, Dune, 1965, 1 copia,
 * Italo Svevo, La coscienza di Zeno, 1923, 10 copie
 * 
 * Attraverso un menù interattivo, il programma metta a disposizione 
 * le seguenti funzionalità:
 * 1. stampa inventario completo nel seguente formato:
 * --------------
 * Eneide - Virgilio (19 a.C.)
 * N. Copie: 5
 * --------------
 * 
 * 2. inserimento nuovo libro
 * 3. cancellazione libro
 * 4. conteggio numero di copie complessive

 * Implementare le seguenti funzioni di utilità:
 * - ricerca_per_titolo
 * - stampa_libro
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIBRI 200


struct libro{
    char autore[51];
    char titolo[71];
    int anno_pub;
    int copie;
};

/*
 * stampa le info di un libro nel formato richiesto.
 */
void stampa_libro(struct libro l);
void stampa_tutto(struct libro b[], int riemp);
bool inserisci(struct libro b[], int *riemp);
int conteggio_copie(struct libro b[], int riemp);
int ricerca_per_titolo(struct libro b[], int riemp, char titolo[]);
bool cancellazione(struct libro b[], int *riemp);

int main() {
    // dichiarazione ed inizializzazione array di struct libro
    struct libro biblioteca[MAX_LIBRI] = {
        {"Virgilio", "Eneide", -19, 5},
        {"Andrea Camilleri", "La forma dell'acqua", 1994, 2},
        {"Frank Herbert", "Dune", 1965, 1},
        {"Italo Svevo", "La coscienza di Zeno", 1923, 10},
    };
    
    // in alternativa, per ogni libro...
    /*
    strcpy(biblioteca[0].autore, "Virgilio");
    strcpy(biblioteca[0].titolo, "Eneide");
    biblioteca[0].anno_pub = -19;
    biblioteca[0].copie = 5;
    */
    
    // stampa di prova
    //stampa_libro(biblioteca[2]);
    //stampa_libro(biblioteca[0]);
    
    
    int r = 4;
    int sel;
    do{
    printf("1. Stampa inventario\n");
    printf("2. Inserisci libro\n");
    printf("3. Cancella libro\n");
    printf("4. Esci\n");
    scanf("%d", &sel);

    bool esito_c, esito_i;
    
    switch(sel){
        case 1:
            stampa_tutto(biblioteca, r);
            break;
        case 2:
            esito_i = inserisci(biblioteca, &r);
            if(esito_i)
                printf("Libro aggiunto all'inventario\n");
            else
                printf("Spazio non disponibile\n");
            break;
        case 3:
             esito_c = cancellazione(biblioteca, &r);
            if (esito_c)
                printf("Il libro è stato eliminato dall'inventario\n");
            else
                printf("Non è possibile cancellare il libro indicato\n");
            break;
        case 4:
            printf("Arrivederci!\n");
            break;
        default:
            printf("Scelta non consentita!\n");
    }
    
    }while(sel!=4);
    
    return 0;
}


/* 
 * FORMATO:
 * 
 --------------
 Eneide - Virgilio (19 a.C.)
 N. Copie: 5
*/
void stampa_libro(struct libro l){

    printf("\n--------------\n");
    printf("%s - %s ", l.titolo, l.autore);
    
    if (l.anno_pub <0)
        printf(" (%d  a.C.)\n", -l.anno_pub);
    else
        printf(" (%d )\n", l.anno_pub);
    
    printf("N. Copie: %d", l.copie);
    
    printf("\n--------------\n");

    return;
}


void stampa_tutto(struct libro b[], int riemp){
    
    for (int i=0; i<riemp; i++)
        stampa_libro(b[i]);
    printf("\n");
    return;
}

/*
        NOTA sull'input da tastiera:

        1. Posso utilizzare fgets per prendere una stringa in input (inclusa degli spazi) ma devo anche utilizzare
        anche strcspn per sostituire lo '\n' (include dall'input da tastiera) con lo '\0'. Devo anche ricordarmi di
        utilizzare fflush(stdin) come prima istruzione prima della prima fgets per "azzerare" il buffer dello stdin
        dei precedenti inserimenti (per esempio quando inserisco la scelta da tastiera in accordo al menu contestuale)

        2. Al posto di usare fgets + strcspn posso utilizza lo stesso la scanf considerando come primo 
        parametro: %[^\n]%*c
        
        Questo specifica che:
        -   Il [] è il carattere di scansione. [^\n] indica che se l'input non è una newline ('\n') 
            prende l'input. 
        -   Con %*c, legge il carattere newline dal buffer di input (che non viene effettivamente letto) 
            e * indica che questo input letto viene scartato (soppressione dell'assegnazione).
            Infatti non è necessario immagazzinare lo \n e questo newline nel buffer non crea alcun 
            problema per i prossimi input che si potrebbero prendere, quindi potremmo evitare il fflush (stdin);
        In definitiva posso usare:
            
            scanf ("%[^\n]%*c", titolo);
    */

bool inserisci(struct libro b[], int *riemp) {
    /*
    * NOTA – 
    */

    if (*riemp < MAX_LIBRI){
        //cin.ignore(); //C++
        fflush (stdin); //è necessario questo perchè la scelta inserita da tastiera, in base al menu contestuale, aggiunge uno \n
        printf("titolo: \n");
        //cin >> biblioteca[r].titolo; //C++
        fgets(b[*riemp].titolo, 71, stdin);

        /* 
            strcspn() È una funzione della libreria C che calcola la lunghezza, in termini di numero di caratteri 
            letti dalla stringa come primo parametro rispetto alla stringa presente nel secondo parametro.
            Nel nostro caso dobbiamo sostituire lo '\n' introdotto dall'input da tastiera con '\0' che è
            il carattere "tappo" per la stringa inserita
        */  

        b[*riemp].titolo[strcspn(b[*riemp].titolo, "\n")] = '\0';
        //cin.getline(b[riemp].titolo, 71);

        printf("autore: \n");
        //cin >> biblioteca[r].autore;
        //cin.getline(b[riemp].autore, 51);
        fgets(b[*riemp].autore, 51, stdin);
        b[*riemp].autore[strcspn(b[*riemp].autore, "\n")] = '\0';

        printf("anno: \n");
        //cin >> b[riemp].anno_pub;
        scanf("%d", &b[*riemp].anno_pub);

        printf("copie: \n");
        scanf("%d", &b[*riemp].copie);
        
        (*riemp)++;
        
        return true;
    
    }
    else{
        printf("Non è possibile inserire altri libri!\n");
        return false;
    }
}

int conteggio_copie(struct libro b[], int riemp){
    int conteggio = 0;
    for (int i=0; i<riemp; i++)
        conteggio = conteggio + b[i].copie; 
    return conteggio;
}

/*
 * restituisce la posizione nell'array del libro con il titolo specificato
 * se presente nell'array, -1 altrimenti.
 */
int ricerca_per_titolo(struct libro b[], int riemp, char titolo[]){
    int posizione = -1;
    int i=0;
    bool trovato = false;
    while(i<riemp && !trovato){
        if(strcmp(b[i].titolo, titolo)==0){
            trovato = true;
            posizione = i;
        }
        else
            i++;
    }
    return posizione;
}

bool cancellazione(struct libro b[], int *riemp){
    
    char titolo[71];
    printf("Inserire il titolo esatto del libro da eliminare: \n");
    //cin.ignore();
    //cin.getline(titolo, 71);
    fflush (stdin);
    
    
    fgets(titolo, 71, stdin);
    titolo[strcspn(titolo, "\n")] = '\0';
    
    

    printf("TITOLO da cancellare: %s\n", titolo);

    int pos = ricerca_per_titolo(b, *riemp, titolo);
    if (pos==-1)
        return false;
    else{
        (*riemp)--;
        for (int i=pos; i < *riemp; i++){
            
            b[i] = b[i+1];         
            /*   
            strcpy(b[i].titolo, b[i+1].titolo);
            strcpy(b[i].autore, b[i+1].autore);
            b[i].anno_pub = b[i+1].anno_pub;
            b[i].copie = b[i+1].copie;
            */
        }
            
        return true;
    }
}