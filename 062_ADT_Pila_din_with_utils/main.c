#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/*
    Codice che implementa la gestione di uno stack senza utilizzare una variabile globale
    per mantenere il puntatore della testa ma sfruttando i valori di ritorno delle funzioni
*/

// Structure to create a node with data and the next pointer
struct node {
    int value;
    struct node *next;
};

// *sp punta alla testa dello stack

struct node *push(struct node *sp, int data);
struct node *pop(struct node *sp, int *popped);
void display(struct node *sp);
bool full(struct node *sp);
bool empty(struct node *sp);


/*
    Push() operation on a  stack. La funzione push ritorna un puntatore
    alla testa della pila (sp). Devo avere necessariamente il ritorno perchè
    i puntatori sono passati per copia e non per riferimento (vedere esempio di pila
    con passaggio per riferimento del puntatore di testa)
*/ 
struct node *push(struct node *sp, int data) {
    
    // la pila è vuota, inserisco il primo elemento
    if (empty(sp)){
        sp =(struct node *)malloc(1*sizeof(struct node));
        sp->next = NULL;
        sp->value = data;
    }
    else
    // la pila non è vuota, inserisco l'elemento in testa
    {
        struct node *new_node =(struct node *)malloc(1*sizeof(struct node));
        new_node->next = sp;
        new_node->value = data;
        sp = new_node;
    }
    
    printf("Elemento %d inserito nello stack\n", sp->value);
    return sp;
}

struct node *pop(struct node *sp, int *popped) {

    /* 
        utilizzo un puntatore di supporto per aggiornare correttmente la testa,
        inizializzandolo alla testa dello stack
    */
    struct node *temp = sp;
 
    if (empty(temp))
    {
        printf("\nStack Underflow\n");
        return NULL;
    }
    // se lo stack non è vuoto otteniamo il puntatore all'elemento successivo a quello di testa
    else
        temp = temp->next;
    
    // mi salvo il valore dell'elemento di testa
    *popped = sp->value;

    /* 
        dealloco il puntatore di testa (posso farlo perchè in temp ho il puntatore all'elemento successivo
        alla testa)
    */
    free(sp);

    // aggiorno la testa
    sp = temp;
    
    return sp;
}


// Mostro a video tutti gli elementi dello stack a partire dalla testa (sp)

void display(struct node *sp) {

    struct node *temp = sp;
 
    if (empty(temp))
    {
        printf("\nStack Underflow\n");
        return;
    }
    
    printf("The stack is \n");

    /*
        mi fermo a stampare gli elementi finchè non arrivo all'ultimo elemento dello stack,
        ovvero quando l'elemento corrente ha come puntatore al successivo NULL
    */
    while (temp != NULL) {
        printf("%d--->", temp->value);
        temp = temp->next;        
    }
    
    printf("NULL\n\n");

}

bool full(struct node *sp){
    /*
        assumo di avere uno stack con dimensione inifita. Come modifico il codice per considerare 
        una dimensione finita dello stack?
    */
    return false;
}

bool empty(struct node *sp){

    return sp == NULL;
}

struct node *top(struct node *sp){
    
    return sp;
}


int main() {
    
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    
    struct node *sp = NULL;
    int popped;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Top\n5. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1:

            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            sp = push(sp, value);
            printf("sp value updated: %p\n", sp);
            break;

        case 2:

            popped = INT_MIN; // impostiamo l'elemento popped a INT_MIN in modo da capire se la funzione pop() ha e
                                // effettivamente aggiornato l'elemento
            sp = pop(sp, &popped);
            if (popped == INT_MIN)
                printf("Stack is empty, nothing to pop out\n");
            else
                printf("Popped element is :%d\n", popped);

            break;
        case 3:
            display(sp);
            break;
        case 4:{
            struct node *el_top = top(sp);
            if (el_top != NULL)
                printf("Elemento top: %d\n", el_top->value);
            else
                printf("Stack is empty\n");
            break;
        }
        case 5:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}