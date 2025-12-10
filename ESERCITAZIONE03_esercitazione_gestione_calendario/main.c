#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NOM 50
#define MAX_LUO 50

struct dati_calendario{
  
  char nome[MAX_NOM];
  int data;
  char ora[20];
  char luogo[MAX_LUO];
  int durata;
  int id;
    
};

typedef struct dati_calendario tipo_calendario;

void inserisci_attivita(tipo_calendario* calendario, int dimensione);
void stampa_attivita(tipo_calendario* calendario, int dimensione);
tipo_calendario* cancella_attivita_per_data_luogo(tipo_calendario* calendario, int* dimensione, int data, const char* luogo);
tipo_calendario* ricerca_e_ordina_per_denominazione_luogo(tipo_calendario* calendario, int dimensione, const char* denominazione, const char* luogo, int* num_risultati);
void scambia(tipo_calendario* a, tipo_calendario* b);
void ordina_per_data(tipo_calendario* calendario, int dimensione);

int main(){
    
    int dimensione;
    
    printf("Inserire il numero di attivita da caricare nel calendario: ");
    scanf("%d", &dimensione);
    
    tipo_calendario* calendario = (tipo_calendario*) malloc(dimensione*sizeof(tipo_calendario));
    
    if(calendario == NULL){
        
        printf("Allocazione fallita.");
        
    }else{
        
        inserisci_attivita(calendario, dimensione);
        stampa_attivita(calendario, dimensione);
        
        int scelta;
        
        do{
            
            printf("\nOPERAZIONI POSSIBILI\n");
            printf("1 =  Cancellazione attivita' dato la data e il luogo\n");
            printf("2 =  Ricerca attività per denominazione e luogo, e ordinamento per data\n");
            printf("3 =  Ordina il calendario per data\n");
            printf("4 = ESCI\n");
            scanf("%d", &scelta);
            
            switch(scelta)
            {
                case 1:{
                int data;
                char luogo[MAX_LUO];
                printf("Inserisci la data (AAAAMMGG): ");
                scanf("%d", &data);
                getchar(); 
                printf("Inserisci il luogo: ");
                fgets(luogo, MAX_LUO, stdin);
                luogo[strcspn(luogo, "\n")] = '\0';

                calendario = cancella_attivita_per_data_luogo(calendario, &dimensione, data, luogo);
                printf("Attività cancellate. Nuovo elenco:\n");
                stampa_attivita(calendario, dimensione);
                break;
                }
                case 2:{
                 char denominazione[MAX_NOM], luogo[MAX_LUO];
                int num_risultati;
                printf("Inserisci la denominazione: ");
                getchar();
                fgets(denominazione, MAX_NOM, stdin);
                denominazione[strcspn(denominazione, "\n")] = '\0';
                printf("Inserisci il luogo: ");
                fgets(luogo, MAX_LUO, stdin);
                luogo[strcspn(luogo, "\n")] = '\0';

                tipo_calendario* risultati = ricerca_e_ordina_per_denominazione_luogo(calendario, dimensione, denominazione, luogo, &num_risultati);
                if (num_risultati > 0) {
                    printf("Risultati trovati (%d):\n", num_risultati);
                    stampa_attivita(risultati, num_risultati);
                    free(risultati);
                } else {
                    printf("Nessuna attività trovata.\n");
                }
                break;
                }
                case 3:{
                    
                    ordina_per_data(calendario, dimensione);
                    printf("DOPO ORDINAMENTO\n");
                    stampa_attivita(calendario, dimensione);
                    
                    break;
                }
                case 4:{
                    printf("Arrivederci.");
                    free(calendario);
                    break;
                default:
                printf("Operazione non valida.\n");
                break;
                }
            }
        }while(scelta != 4);
    }
    
    return 0;
}

void inserisci_attivita(tipo_calendario* calendario, int dimensione){
    
    
    for(int i=0; i<dimensione; i++){
        printf("Inserimento attivita in posizione %d\n", i);
        
        printf("Inserire denominazione attivita: ");
        getchar();
        fgets((calendario+i)->nome, MAX_NOM, stdin);
        (calendario+i)->nome[strcspn((calendario+i)->nome, "\n")] = '\0';
        
        printf("Inserire data (formato AAAAMMGG): ");
        scanf("%d", &(calendario+i)->data);
        
        printf("Inserire ora (formato hh:mm): ");
        scanf("%s", (calendario+i)->ora);
        
        printf("Inserire luogo: ");
        getchar();
        fgets((calendario+i)->luogo, MAX_LUO, stdin);
        (calendario+i)->luogo[strcspn((calendario+i)->luogo, "\n")] = '\0';
        
        do{
            printf("Inserire durata (valori possibili: 15, 30, 60): ");
            scanf("%d", &(calendario+i)->durata);
            
            if((calendario+i)->durata != 15 && (calendario+i)->durata != 30 && (calendario+i)->durata != 60){
                
                printf("Durata non valida, riprovare\n");
            }
        }while((calendario+i)->durata != 15 && (calendario+i)->durata != 30 && (calendario+i)->durata != 60);
        
        (calendario+i)->id = i + 1;
    
    }
}

void stampa_attivita(tipo_calendario* calendario, int dimensione){
    
    printf("\nRIEPILOGO\n");
    printf("ID\tDENOMINAZIONE\tDATA\tORA\tLUOGO\tDURATA\n");
    for(int i = 0; i<dimensione; i++){
        
        printf("%03d\t%s\t%d\t%s\t%s\t%d\n", (calendario+i)->id, (calendario+i)->nome, (calendario+i)->data, (calendario+i)->ora, (calendario+i)->luogo, (calendario+i)->durata);
        
    }
}

tipo_calendario* cancella_attivita_per_data_luogo(tipo_calendario* calendario, int* dimensione, int data, const char* luogo) {
    int new_size = 0;
    for (int i = 0; i < *dimensione; i++) {
        if (!(calendario[i].data == data && strcmp(calendario[i].luogo, luogo) == 0)) {
            new_size++;
        }
    }

    tipo_calendario* new_calendario = malloc(new_size * sizeof(tipo_calendario));
    if (new_calendario == NULL) {
        return calendario;
    }

    int j = 0;
    for (int i = 0; i < *dimensione; i++) {
        if (!(calendario[i].data == data && strcmp(calendario[i].luogo, luogo) == 0)) {
            new_calendario[j++] = calendario[i];
        }
    }

    free(calendario);
    *dimensione = new_size;
    return new_calendario;
}

tipo_calendario* ricerca_e_ordina_per_denominazione_luogo(tipo_calendario* calendario, int dimensione, const char* denominazione, const char* luogo, int* num_risultati) {
    tipo_calendario* risultati = malloc(dimensione * sizeof(tipo_calendario));
    if (risultati == NULL) {
        *num_risultati = 0;
        return NULL;
    }

    *num_risultati = 0;
    for (int i = 0; i < dimensione; i++) {
        if (strcmp(calendario[i].nome, denominazione) == 0 && strcmp(calendario[i].luogo, luogo) == 0) {
            risultati[(*num_risultati)++] = calendario[i];
        }
    }

    ordina_per_data(risultati, *num_risultati);
    
    return risultati;
}

void scambia(tipo_calendario* a, tipo_calendario* b) {
    tipo_calendario temp = *a;
    *a = *b;
    *b = temp;
}

void ordina_per_data(tipo_calendario* calendario, int dimensione) {
    for (int i = 0; i < dimensione - 1; i++) {
        int min = i;
        for (int j = i + 1; j < dimensione; j++) {
            if (calendario[j].data < calendario[min].data) {
                min = j;   
            }
        }
        scambia(&calendario[i], &calendario[min]);
    }
}