#include <stdio.h>


int main() {
    
    struct elemento {
        int riga;
        int colonna;
        float valore;
    } e;
        
    struct elemento * ptr = &e;
    
    (*ptr).riga = 10;  // accesso tramite dereferenziazione puntatore ed accesso al campo (notazione . )
    
    ptr ->colonna = 2; // accesso tramite puntatore, equivalentemente: operatore freccia
    
    e.valore = 0.1; // accesso al campo valore tramite variabile struct

    printf("Valori della struttura stampati tramite operatore . e nome variabile struct\n");
    printf("\t e.riga: %d\n", e.riga);
    printf("\t e.colonna: %d\n", e.colonna);
    printf("\t e.valore: %f\n", e.valore);

    printf("\n\n");

    printf("Valori della struttura stampati tramite operatore . e deferenziazione puntatore alla struct\n");
    printf("\t (*ptr).riga: %d\n", (*ptr).riga);
    printf("\t (*ptr).colonna: %d\n", (*ptr).colonna);
    printf("\t (*ptr).valore: %f\n", (*ptr).valore);

    printf("\n\n");

    printf("Valori della struttura stampati tramite operatore -> applicato al puntatore alla struct\n");
    printf("\t ptr->riga: %d\n", ptr->riga);
    printf("\t ptr->colonna: %d\n", ptr->colonna);
    printf("\t ptr->valore: %f\n", ptr->valore);

    return 0;
}

