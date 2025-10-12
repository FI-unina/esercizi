#include <stdio.h>
#include <stdlib.h>

#define MAXDIM 100


/*
 * Progettare e scrivere un programma che legga una sequenza 
 * di interi da un file di testo e li inserisca in un vettore.
 * Il programma scrive gli interi letti in un altro file, 
 * riportando gli interi in sequenza inversa e sommando 1 a ciascun valore.
 */

int main() {

    // ESEMPI LETTURA-SCRITTURA FILE

    FILE *in_file;
    char ch;
    char str[MAXDIM];


    in_file = fopen("data.txt", "r");
    
    if (NULL == in_file) {
        printf("file can't be opened \n");
    }
    

    // LETTURA

    // Esempio fgetc

    printf("\nread with fgetc\n");  
    do {
        ch = fgetc(in_file);
        if (ch != EOF)
            printf("%c", ch);
 
        // Checking if character is not EOF.
        // If it is EOF stop reading.
    } while (ch != EOF);
    
    fclose(in_file);
    

    // Esempio fetgs

    in_file = fopen("data.txt", "r");
    printf("\n\nread with fgets\n");
    
    // fgets legge fino allo '\n', quindi è utile se si ha un file con dati separati dallo '\n'
    while (fgets(str, 50, in_file) != NULL) {
        printf("%s", str);
    }
    fclose(in_file);
    

    // Esempio fread

    in_file = fopen("data.txt", "r");
    printf("\n\nread with fread\n");
    // ritorna il numero di byte letti (massimo MAXDIM), ognuno di dimensione sizeof(char), dallo strem in_file
    int count = fread(&str, 1, MAXDIM, in_file);
    printf("READ value: %s\n", str);
    printf("count: %d\n", count);
    fclose(in_file);
    

    // SCRITTURA

    FILE *out_file_1;
    out_file_1 = fopen("out_1.txt", "w");
    
    if (NULL == out_file_1) {
        printf("file can't be opened \n");
    }

    FILE *out_file_2;
    out_file_2 = fopen("out_2.txt", "w");
    
    if (NULL == out_file_2) {
        printf("file can't be opened \n");
    }

    // fprintf
    printf("\n\nScrittura file con fprintf\n");
    fprintf(out_file_1, "This is testing for fprintf...\n");
    fclose(out_file_1);

    // fputs
    printf("\n\nScrittura file con fputs\n");
    fputs("This is testing for fputs...\n", out_file_2);
    fclose(out_file_2);


    // SVOLGIMENTO

    int v[MAXDIM];

    in_file = fopen("data.txt", "r");
    
    // lettura con fscanf
    count = 0;
    while (!feof(in_file)){
        fscanf(in_file, "%d", &v[count]);
        count++;
    }
        
    fclose(in_file);
    
    // scrittura con fprintf
    FILE *out_file_3;
    out_file_3 = fopen("out_3.txt", "w");
    
    if (NULL == out_file_3) {
        printf("file can't be opened \n");
    }
    
    printf("\n\nScrittura file con fprintf\n");
    for (int i=count-1; i>=0; i--)
        fprintf(out_file_3, "%d ", v[i]+1);

    fclose(out_file_3);
    
    return 0;
}

