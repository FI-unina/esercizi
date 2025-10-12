#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef int element;

struct pila {
    element e[MAX];
    int sp;  // stack pointer
};

typedef struct pila* ppila;

ppila newStack();
void showStack(ppila p);
bool push(ppila p, element e);
bool pop(ppila p, element *e);
bool isFullStack(ppila p);
bool isEmptyStack(ppila p);

int main() {

    ppila P = newStack();
    
    if (push(P, 45) == false)
        printf("inserimento fallito!\n");
    else
        printf("Inserimento effettuato!\n");
    
    if (push(P, 23) == false)
        printf("inserimento fallito!\n");
    else
        printf("Inserimento effettuato!\n");
    
    if (push(P, 72) == false)
        printf("inserimento fallito!\n");
    else
        printf("Inserimento effettuato!\n");
    
    showStack(P);
    
    // Facciamo 3 pop consecutivi
    element y; 
    
    if (pop(P, &y)){
        printf("popped element y: %d\n", y);
        showStack(P);
    }

    if (pop(P, &y)){
        printf("popped element y: %d\n", y);
        showStack(P);
    }

    if (pop(P, &y)){
        printf("popped element y: %d\n", y);
        showStack(P);
    }
    
    return 0;
}

/* 
 * Alloca una nuova "pila" (record con vettore e sp) in area heap.
 * La pila creata è vuota (sp = 0)
 * Resituisce il puntatore al record.
 */
ppila newStack(){
    ppila p = malloc (sizeof(struct pila));
    p->sp = 0;
    return p;
}

void showStack(ppila p){

    if (p->sp == 0)
        printf("la pila è vuota\n");
    else{
        for(int i=0; i<p->sp; i++)
            printf("%d, ", p->e[i]);
        printf("\n");
    }
}

/* 
 * Inserisce un elemento sulla pila.
 * Restituisce true se l'operazione va a buon fine, false altrimenti.
 */
bool push(ppila p, element e){
    if (isFullStack(p)){  // se è piena non è possibile inserire un nuovo elemento.
        return false;
    }
    else {
        p->e[p->sp] = e;
        p->sp++;
        return true;
    }
}

bool pop(ppila p, element *x){
    if (!isEmptyStack(p)){  // se non è vuota si effettua il prelievo.
        p->sp--;
        *x = p->e[p->sp];
        return true;
    }
    else 
        return false;
}

/*
 * Restituisce true se la pila è piena, false altrimenti.
 */
bool isFullStack(ppila p){
    return (p->sp == MAX);
}

/*
 * Restituisce true se la pila è vuota, false altrimenti.
 */
bool isEmptyStack(ppila p){
    return (p->sp == 0);
}
