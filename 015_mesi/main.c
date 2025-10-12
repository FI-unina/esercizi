
/* 
 * File:   main.cpp
 * Author: valer
 *
 * Created on 20 ottobre 2022, 15:50
 */

#include <stdio.h>


/*
 * 
 */
int main() {
    int n;
    printf("Inserisci un numero tra 1 e 12: \n");
    scanf("%d", &n);
    
    if (n==1)
        printf("Gennaio\n");
    else if (n==2)
        printf("Febbriaio\n");
    else if (n==3)
        printf("Marzo\n");
    else if (n==4)
        printf("Aprile\n");
    else if (n==5)
        printf("Maggio\n");
    else if (n==6)
        printf("Giugno\n");
    else if (n==7)
        printf("Luglio\n");
    else if (n==8)
        printf("Agosto\n");
    else if (n==9)
        printf("Settembre\n");
    else if (n==10)
        printf("Ottobre\n");
    else if (n==11)
        printf("Novembre\n");
    else if (n==12)
        printf("Dicembre\n");
    else
        printf("Valore non consentito! \n");
    
    return 0;
}

