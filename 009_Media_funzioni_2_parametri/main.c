#include <stdio.h>

/* dichiarazione e definizione della funzione "media"
 * che ha 3 parametri di ingresso (interi)
 * ed un parametro di uscita (float)
 */
float media(int param1, int param2, int param3){  // firma della funzione, definisce l'interfaccia

    float media = (float)(param1+param2+param3)/3;
    return media;  //float, come previsto dalla firma della funzione
}

int main() {

    int a=2;
    int b=5;
    int c=10;
    
    // chiamata della funzione:
    // internamente, i parametri effettivi (a, b, c) vengono associati ai 
    // parametri formali (param1, param2, param3) in base alla loro posizione
    float m = media(a, b, c);  
    // dopo la chiamata, la variabile m conterrà il valore restituito dalla funzione
    printf("la media dei numeri %d, %d, %d è: \n", a, b, c);     
    printf("%f\n", m);
    
    return 0;
}

