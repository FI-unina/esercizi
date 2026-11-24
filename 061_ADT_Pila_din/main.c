#include <stdio.h>
#include <stdlib.h>

/*
    Codice che implementa la gestione di uno stack utilizzando una variabile globale
    per mantenere il puntatore della testa
*/

// Structure to create a node with data and the next pointer
struct node {
    int value;
    struct node *next;
} *sp, *new_node;

// *sp punta alla testa dello stack

void push(int);
int pop();
void display();


// Push() operation on a  stack
void push(int data) {
    
    if (sp == NULL)
    {
        sp =(struct node *)malloc(1*sizeof(struct node));
        sp->next = NULL;
        sp->value = data;
    }
    else
    {
        new_node =(struct node *)malloc(1*sizeof(struct node));
        new_node->next = sp;
        new_node->value = data;
        sp = new_node;
    }
    
    printf("Node is Inserted\n\n");
}

int pop() {

     new_node = sp;
 
    if (new_node == NULL)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    else
        new_node = new_node->next;
    int popped = sp->value;
    free(sp);
    sp = new_node;
    
    return popped;
}

void display() {
    // Display the elements of the stack
    new_node = sp;
 
    if (new_node == NULL)
    {
        printf("\nStack Underflow\n");
        return;
    }
    
    printf("The stack is \n");
    while (new_node != NULL)
    {
        printf("%d--->", new_node->value);
        new_node = new_node->next;
    }
    printf("NULL\n\n");

}

int main() {
    
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1:
            printf("\nEnter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("Popped element is :%d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
}