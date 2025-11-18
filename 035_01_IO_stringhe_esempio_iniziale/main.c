

/* 
 * Esempio di utilizzo di strcmp.
   Ricordare che strcmp considera il secondo parametro sempre come se fosse una stringa null-terminated!
   Per esempio, se str1 = "gigi\n" e str2 = "gigi\0"
    strcmp("gigi", str1) darà !=0
    strcmp("gigi", str2) darà 0

 */

#include <stdio.h>
#include <string.h>

#define MAXDIM 50

void flush(){
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}

/*
 * 
 */
int main() {

    char str1[MAXDIM], str2[MAXDIM];
    char target_str [] = "gigi";

    int val;
    printf("inserisci un numero\n");
    scanf("%d", &val);
    
    printf("Inserisci una stringa\n");
    flush(); //è necessario se c'è una scanf precedente dal momento che "aggiunge" uno '\n'...PROVARE A COMMENTARLA
    fgets(str1, MAXDIM, stdin);
    /* 
        NOTA: fgets include lo '\n' finale nella stringa. E' possibile rimpiazzare tale '\n' con il carattere
        tappo ('\0') utilizzando la funzione strcspn()
    */
    
    printf("la stringa inserita è %s\n", str1);
    
    printf("\n");
    //questo primo strcmp fallisce perchè str1 non è null-terminated
    printf("1. strcmp confrontando l'input da tastiera con gigi\\n....IL RISULTATO è un MATCH\n");
    //if (strcmp(str1, target_str) == 0)
    if (strcmp(str1, "gigi\n") == 0)
        printf("MATCH\n");
    else
        printf("NO MATCH\n");
    printf("\n");
    //questo primo strcmp fallisce perchè str1 non è null-terminated
    printf("2. strcmp confrontando l'input da tastiera con gigi (implicitamente nella strcmp uso stringhe null-terminated)....IL RISULTATO è un NO MATCH\n");
    //if (strcmp(str1, target_str) == 0)
    if (strcmp(str1, "gigi") == 0)
        printf("MATCH\n");
    else
        printf("NO Match\n");;
    printf("\n");
    int pos_di_slash_n = strcspn(str1, "\n");
    str1[pos_di_slash_n] = '\0';
    printf("Rimuovo lo \\n da str1...la stringa adesso è %s\n", str1);

    //questo primo strcmp fallisce perchè str1 non è null-terminated
    printf("3. strcmp confrontando l'input da tastiera con gigi....IL RISULTATO è un MATCH\n");
    //if (strcmp(str1, target_str) == 0)
    if (strcmp(str1, "gigi") == 0) //potrei usare come secondo parametro anche la var. target_str
        printf("MATCH\n");
    else
        printf("NO MATCH\n");;

        
    return 0;
}

