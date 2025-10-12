/*
    Implementazione di una lista linkata e le relative funzioni per:
    - visualizzare la lista
    - inserire un elemento in testa
    - inserire un elemento in coda
    - inserire un elemento in una posizione stabilita
    - eliminare un elemento in testa
    - eliminare un elemento in coda
    - eliminare un elemento in una posizione stabilita
    - eliminare tutta la lista
	- ottenere la dimensione della lista
*/

#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void delete_list();
int size();

struct node* head = NULL;



struct node {
	int data;
	struct node* next;
};

int main() {

	int choice;
	while(1)
	{
	    printf("\n*****\n");
	    printf("0. Create\n");
	    printf("1. display\n");
	    printf("2. Insert Node at beginning\n");
	    printf("3. Insert Node in specific position\n");
	    printf("4. Insert Node at end of LinkedList\n");
	    printf("5. Delete Node at beginning\n");
	    printf("6. Delete Node at end\n");
	    printf("7. Delete Node at position\n");
        printf("8. Delete the list\n");
		printf("9. Get list size\n");
	    printf("10. ** To exit **");
	    
		printf("\n Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0: create();
					break;
			case 1: display();
					break;
			case 2: insert_begin();
					break;
			case 3: insert_pos();
					break;
			case 4: insert_end();
					break;
			case 5: delete_begin();
					break;
			case 6: delete_end();
					break;
			case 7: delete_pos();
					break;
            case 8: delete_list();
					break;
			case 9: printf("List size is %d\n", size());
					break;
			case 10: 
					delete_list(); 
					printf("Exiting...\n");
					exit(0);
			default:printf("\n Wrong Choice");
                    break;
		}
	}

}
//creates a node
void create()
{
	struct node* temp;
        //creating new node
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data); 
	temp->next = NULL;
	if(head==NULL)	{
		head = temp;
	}
	else{
		struct node* ptr = head;
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp; //inserting at end of List
	}
}

// prints the entire LinkedList
void display() {

	if(head==NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
        printf("LinkedList: ");
	struct node* ptr = head;
	while(ptr!=NULL) // start from first node
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
    printf("\n");
}

int size() {
	if(head == NULL)
	{
		printf("Linked List is Empty\n");
		return 0;
	}
    
	struct node* ptr = head;
	int i = 0;
	while(ptr!=NULL) // start from first node
	{
		ptr = ptr->next;
		i++;
	}
	return i;
}

void delete_list(){

    if(head==NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
	
    //NOTE: inizio dal puntatore di testa, ma nulla mi vieta di partire anche dall'ultimo elemento della lista
    
	while(head != NULL) // start from first node
	{ 
        struct node* ptr = head; // uso un puntatore d'appoggio per salvare la testa da cancellare
        head = head->next; //aggiorna la testa all'elemento successivo
		free(ptr); // dealloca l'area di memoria puntata dalla vecchia testa
	}
    printf("List DELETED!\n");

}

// to insert node at start of LinkedList
void insert_begin()
{
	struct node* temp;
        // creating a new node
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data);
	temp->next = NULL;
	if(head==NULL)
	{
		head = temp;
		return;
	}
	else
	{
		temp->next = head; //point it to old head node
		head = temp; //point head to new first node
	}
}
// to insert node at given position
void insert_pos()
{
	struct node* temp;
        // creating a new node
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data);
	temp->next = NULL;
	if(head==NULL) // if list empty we return
	{
		head = temp;
	    return;
	}
	else
	{
		struct node* prev_ptr;
		struct node* ptr = head;
		int pos;
		printf("Enter position: ");
		scanf("%d",&pos);
		for(int i=0;i<pos;i++)
		{
			prev_ptr = ptr;
			ptr = ptr->next;
		}
                //new node pointing to node in that pos
		temp->next = ptr;
                //prevptr pointing to new node
		prev_ptr->next = temp;
	}
}
// to insert node at end of LinkedList
void insert_end()
{
	struct node* temp;
        //creating new node
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data: ");
	scanf("%d",&temp->data); 
	temp->next = NULL;
	if(head==NULL)
	{
		head = temp; //if list is empty, we return
	        return;
	}
	else{
		struct node* ptr = head;  
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
               // tail node pointing to new node
		ptr->next = temp;
	}
}
// to delete first node of LinkedList
void delete_begin()
{ 
	if(head==NULL) //if List is empty we return
	{
		printf("Linked List is empty | Nothing to delete \n");
		return;
	}
	else
	{
		struct node* ptr = head; 
		head = head->next; // head node pointing to second node
		free(ptr); // deleting prev head node
		printf("Node Deleted \n");
	}
}
// to delete last node of LinkedList
void delete_end()
{
	if(head==NULL) //if List is empty we return
	{
		printf("Linked List is empty | Nothing to delete \n");
		return;
	}
	else if(head->next==NULL) 
	{
		struct node* ptr = head;
		head = ptr->next;
		free(ptr);
	}
	else
	{
		struct node* ptr = head;
		struct node* prev_ptr = NULL;
		while(ptr->next!=NULL)// traverse till last but one node
		{
			prev_ptr = ptr;
			ptr = ptr->next;
		}
		prev_ptr->next = NULL; // next field of last but one field is made as NULL
		free(ptr); // deleting last node
	}	
}
// to delete node at given position
void delete_pos()
{
	int pos;
	printf("Enter node position to delete: ");
	scanf("%d",&pos);     
	struct node* ptr=head;                                                                               
	if(head==NULL) //we return if List is empty
	{
		printf("Linked List is empty \n"); 
		return;
	}
	else if(pos == 0) 
	{
		ptr = head;
		head=ptr->next; // head pointing to second node
		free(ptr); // deleting old first node
	}
	else
	{
		struct node* prev_ptr;
		for(int i=0;i<pos;i++)
		{
			prev_ptr = ptr;
			ptr = ptr->next;
		}
		prev_ptr->next = ptr->next; //prev node pointing to pos+1 node
		free(ptr); //deleting node at pos
	}
}