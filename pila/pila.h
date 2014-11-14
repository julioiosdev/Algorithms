#ifndef _PILA_H
#define _PILA_H

#include <stdbool.h>

typedef struct tipo_pila *Pila; // de esta forma el usuario puede usar pila para inicializar una variable, pila
//sera aun puntero de tipo_pila

Pila crear(void);
void destruir(Pila p);
void vaciar(Pila p);
bool esta_vacia(Pila p);
bool esta_llena(Pila p);
void apilar(Pila p,int n);
int desapilar(Pila p);

#endif /* _PILA_H */
