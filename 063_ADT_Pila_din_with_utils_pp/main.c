#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/*
    Codice che implementa la gestione di uno stack senza utilizzare una variabile globale
    per mantenere il puntatore della testa ma sfruttando il passaggio per riferimento
    di un puntatore passato come parametro alla funzioni
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

/*
    Nel caso di passaggio per riferimento di un puntatore dobbiamo usare l'operatore **
    **p sarà un puntatore al puntatore *p.
    
*/ 

// Push() operation on a  stack
void push (struct node **sp, int data){
    
    // la pila è vuota, inserisco il primo elemento
    if ( *sp == NULL){

        *sp =(struct node *)malloc(1*sizeof(struct node));
        (*sp)->next = NULL;
        (*sp)->value = data;
    }
    else
    // la pila non è vuota, inserisco l'elemento in testa
    {
        struct node *new_node =(struct node *)malloc(1*sizeof(struct node));
        new_node->next = *sp;
        new_node->value = data;
        *sp = new_node;
    }
}

int pop(struct node **sp) {

    struct node *temp = *sp;
    int popped;
 
    if (empty(temp))
    {
        printf("\nStack is empty\n");
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
        printf("\nStack is empty\n");
        return;
    }
    
    printf("The stack is \n");

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
		printf("Stack is empty\n");
		return;
	}
	
    //NOTE: inizio dal puntatore di testa, ma nulla mi vieta di partire anche dall'ultimo elemento dello stack
    
	while(*sp != NULL) // start from first node
	{ 
        struct node **ptr = sp; // uso un puntatore d'appoggio per salvare la testa da cancellare
        *sp = (*sp)->next; //aggiorna la testa all'elemento successivo
		free(*ptr); // dealloca l'area di memoria puntata dalla vecchia testa
	}
    printf("Stack DELETED!\n");

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
        printf("\n1. Push\n2. Pop\n3. Display\n4. Size\n5. Delete\n6. Top\n7. Exit\n");
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
                printf("Stack empty, nothing to pop out\n");
            else
                printf("Popped element is :%d\n", popped);

            break;
        case 3:
            display(sp);
            break;
        case 4:
            printf("Stack size is %d\n", size(sp));
            break;
        case 5:
            delete(&sp);
            break;
        case 6:{
            struct node *el_top = top(sp);
            if (el_top != NULL)
                printf("Elemento top: %d\n", el_top->value);
            else
                printf("Stack is empty\n");
            break;
        }
        case 7:
            delete(&sp);
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}