/* Creare un programma che riempia una lista collegata con valori interi 
 * forniti dall’utente tramite tastiera.
 * Al termine dell'inserimento, il programma mette a disposizione un menù,
 * tramite il quale l'utente può scegliere di inserire nuovi valori, 
 * individuare il massimo dei valori inseriti fino a quel momento, 
 * o visualizzare gli elementi della lista.
 */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node* lista;

void aggiungi(lista *l, int valore);
void stampa_menu();
void visualizza(lista l);
int trova_max(lista l);

int main() {
    
    lista L = NULL; // la lista è vuota
    char scelta;
    do{
        
        int valore_da_agg;
        printf("Inserisci un nuovo valore: \n");
        scanf("%d", &valore_da_agg);
        
        aggiungi(&L, valore_da_agg);
        
        printf("Vuoi aggiungere un altro elemento? (s/n)\n");
        scanf(" %c", &scelta);

    }while(scelta != 'n');
    
    
    // menu
    int scelta_menu;
    do{
        stampa_menu();
        scanf("%d", &scelta_menu);
        
        switch(scelta_menu){
            case 1:
                {
                    visualizza(L);
                    break;
                }
            case 2:
                {
                    int m = trova_max(L);
                    printf("max = %d\n", m);
                    break;
                }
            case 3:
                {
                    int val;
                    printf("Inserisci valore: \n");
                    scanf("%d", &val);
                    aggiungi(&L, val);
                    break;
                }
            case 0:
                {
                    printf("Arrivederci!\n");
                    free(L);
                    break;
                }
            default:
                printf("Scelta non consentita\n");        
        }
        

    }while(scelta_menu != 0);
    
    
    return 0;
}

void aggiungi(lista *l, int val){
    
    struct node* cur_node = malloc (sizeof(struct node));
    cur_node->value = val;
    cur_node->next = NULL;

    if (*l == NULL)  // se la lista è vuota
        *l = cur_node;
    
    else{  // se è già presente qualche elemento
        lista tmp = *l;
        while(tmp->next != NULL)
            tmp = tmp->next;
        
        tmp->next = cur_node;
    }   
}

void visualizza(lista l){

    lista tmp = l;
    if (tmp == NULL)
        printf("La lista è vuota\n");
    else{
        while(tmp != NULL){
            printf("%d,", tmp->value);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void stampa_menu(){
    printf("1. visualizza lista\n");
    printf("2. trova massimo\n");
    printf("3. inserisci un altro valore\n");
    printf("0. esci\n");
}

int trova_max(lista l){
    lista tmp = l;
    int max = tmp->value;
    while(tmp != NULL){
        if (tmp->value > max)
            max = tmp->value;
        tmp = tmp->next;
    }
    return max;

}