// Scope delle variabili

#include <stdio.h>

int globale = 99; // Questa è una variabile globale
int main()
{        
	float variabile = 2.5; 
	{ //INIZIO BLOCCO
		//VARIABILE LOCALE
		int variabile = 3; //NASCE CON LA DICHIARAZIONE
		printf("Variabile vale %d\n", variabile);
		variabile = 4;
		printf("Variabile vale %d\n", variabile);
		printf("Globale vale %d\n", globale);
	
	} //FINE BLOCCO
	printf("Variabile vale %f\n", variabile);
}