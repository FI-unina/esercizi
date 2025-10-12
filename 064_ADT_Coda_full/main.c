#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/*
    Codice che implementa la gestione di una CODA senza utilizzare una variabile globale
    per mantenere il puntatore della coda ma sfruttando il passaggio per riferimento
    di un puntatore passato come parametro alle funzioni
*/


// Structure to create a node with data and the next pointer
struct node {
    int value;
    struct node *next;
};

void push (struct node **sp, int data);
int pop(struct node **sp);
void display(struct node *sp);
int size(struct node *sp);
bool full(struct node *sp);
bool empty(struct node *sp);
void delete (struct node **sp);
struct node *top(struct node *sp);
struct node *next(struct node *sp);

/*
    Nel caso di passaggio per riferimento di un puntatore dobbiamo usare l'operatore **
    **p sarà un puntatore al puntatore *p.
    
*/ 

// Push() operation on a queue
void push (struct node **sp, int data){
    
    // la coda è vuota, inserisco il primo elemento
    if ( *sp == NULL){
        
        *sp =(struct node *)malloc(1*sizeof(struct node));
        (*sp)->next = NULL;
        (*sp)->value = data;
    }
    else
    // la coda non è vuota, inserisco l'elemento in coda
    {
        
        struct node *new_node =(struct node *)malloc(1*sizeof(struct node));
        
        new_node->next = NULL;
        new_node->value = data;
        
        /* 
            devo partire dal puntatore di testa e attraversare la coda per arrivare all'ultimo elemento e aggiornare
            opportunamente il next
         */

        struct node *cur = *sp; // imposto il nodo corrente alla testa della coda
        while ( cur->next != NULL) //scorro al coda finchè non arrivo all'ultimo elemento
            cur = cur->next;
        // aggiorno il next dell'ultimo elemento con l'elemento che sto per inserire
        cur->next = new_node;
    
    }
}

int pop(struct node **sp) {

    struct node *temp = *sp;
    int popped;
 
    if (empty(temp))
    {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    else
        temp = temp->next;

    popped = (*sp)->value;
    free(*sp);
    *sp = temp;
    
    return popped;
}

void display(struct node *sp) {

    // Display the elements of the stack
    struct node *temp = sp;
 
    if (empty(temp))
    {
        printf("Queue is empty\n");
        return;
    }
    
    printf("The queue is \n");

    while (temp != NULL) {
        printf("%d--->", temp->value);
        temp = temp->next;        
    }
    
    printf("NULL\n\n");

}

bool full(struct node *sp){

    return false;
}

bool empty(struct node *sp){

    return sp == NULL;
}

int size(struct node *sp){

    struct node *temp = sp;
 
    if (empty(temp)){
        return 0;
    }

    int i = 0;
    while (temp != NULL) {
        temp = temp->next;        
        i++;
    }
    return i;
}

void delete(struct node **sp){

    if(*sp == NULL)
	{
		printf("Queue is empty\n");
		return;
	}
	
    //NOTE: inizio dal puntatore di testa, ma nulla mi vieta di partire anche dall'ultimo elemento della coda
    
	while(*sp != NULL) // start from first node
	{ 
        struct node **ptr = sp; // uso un puntatore d'appoggio per salvare la testa da cancellare
        *sp = (*sp)->next; //aggiorna la testa all'elemento successivo
		free(*ptr); // dealloca l'area di memoria puntata dalla vecchia testa
	}
    printf("Queue DELETED!\n");

}

struct node * next(struct node *sp){

    struct node *cur = sp; // imposto il nodo corrente alla testa della coda
    if (empty(cur))
        return NULL;

    while ( cur->next != NULL) //scorro al coda finchè non arrivo all'ultimo elemento, ovvero al primo elemento inserito
        cur = cur->next;
    
    return cur;
}

struct node *top(struct node *sp){
    
    return sp;
}


int main() {
    
    int choice, value;
    printf("\nImplementation of Queue using Linked List\n");
    
    struct node *sp = NULL;
    int popped;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Size\n5. Delete\n6. Next\n7. Top\n8. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1:

            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            
            push(&sp, value);
            
            break;

        case 2:
            
            popped = pop(&sp);

            if (popped == INT_MIN)
                printf("Queue is empty, nothing to pop out\n");
            else
                printf("Popped element is :%d\n", popped);

            break;
        case 3:
            display(sp);
            break;
        case 4:
            printf("Queue size is %d\n", size(sp));
            break;
        case 5:
            delete(&sp);
            break;
        case 6: {
            struct node *el_next;
            el_next = next(sp);
            if (el_next != NULL)
                printf("Elemento next: %d\n", el_next->value);
            else
                printf("Queue is empty\n");
            break;
        }
        case 7:{
            struct node *el_top = top(sp);
            if (el_top != NULL)
                printf("Elemento top: %d\n", el_top->value);
            else
                printf("Queue is empty\n");
            break;
        }
        case 8:
            delete(&sp);
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}