#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int valore;
    struct elemento* prossimo;
};

typedef struct elemento lista;

int main() {

    lista *l = (lista *) malloc(sizeof(lista));
    l->valore=4;
    
    l->prossimo = (struct elemento *) malloc(sizeof(lista));
    l->prossimo->valore = 5;
    
    l->prossimo->prossimo = (struct elemento *) malloc(sizeof(lista));
    l->prossimo->prossimo->valore = 7;
    
    l->prossimo->prossimo->prossimo = NULL;
    
    // stampa lista  
    printf("\nvalori nella lista:\n");
    lista *p = l; 
    while (p != NULL) { 
	    printf("%d\n", p->valore); 
	    p = p->prossimo; 
    }        
    
    // aggiunta del valore 6 dopo al valore 5
    p = l;
    while (p->valore != 5 && p->prossimo != NULL)
        p = p->prossimo;
    
    if (p->valore == 5){
        struct elemento *e = (struct elemento *) malloc(sizeof(lista));
        e->valore = 6;
        e->prossimo = p->prossimo;
        p->prossimo = e;
    }    
    
    printf("\nvalori nella lista:\n");
    p = l; 
    while (p != NULL) { 
	    printf("%d\n", p->valore); 
	    p = p->prossimo; 
    }      
    
    // TODO: delete pulita della lista
    printf("Start to deallocate list...\n");
    while(l->prossimo != NULL){
        
        lista *q = l; //uso un puntatore d'appoggio per impostarlo alla testa della lista in modo da deallocarlo
        printf("l: %p\n", l);
        l = l->prossimo; //la testa della lista diventa l'elemento successivo
        free(q); //dealloco l'area puntata dal puntatore d'appoggio
        
    }
    
    free(l); //l'ultimo elemento della lista viene deallocato assegnando un puntato nullo
    printf("List deallocated!\n");

    return 0;
}

