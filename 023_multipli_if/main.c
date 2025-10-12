# include <stdio.h>

/*
 * Dati due numeri naturali in ingresso,
 * valutare se solo l'uno il multiplo dell'altro
*/

int main()
{

    // Dichiarazione delle variabili
    int x, y;
    // Caricamento valori
    printf("x = \n"); 
    scanf("%d", &x);
    printf("y = \n"); 
    scanf("%d", &y);
    
    // Verifica input
    if ((x < 0) || (y < 0)){
    	printf("Non sono entrambi numeri naturali\n");
    }
    else{
    	if ( ((x % y) == 0) || ((y % x) == 0))
            printf("I due numeri sono multipli l'uno dell'altro\n");
	    else
            printf("I due numeri non sono multipli l'uno dell'altro\n");
	}
 }