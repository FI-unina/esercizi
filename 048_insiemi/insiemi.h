#ifndef INSIEMI_H
#define INSIEMI_H

#include <stdbool.h>
#define DIM 10
bool verifica_presenza(int v[DIM], int riempv, int valore);
void aggiungi(int v[DIM], int *riempv, int valore);
void visualizza (int v[], int riempv);

void intersezione(int v1[DIM], int riempv1, int v2[DIM], int riempv2, 
                  int v3[DIM], int *riempv3);
void unione(int v1[DIM], int riempv1, int v2[DIM], int riempv2, 
                  int v3[DIM], int *riempv3);

void differenza(int v1[DIM], int riempv1, int v2[DIM], int riempv2, 
                  int v3[DIM], int *riempv3);


#endif /* INSIEMI_H */

