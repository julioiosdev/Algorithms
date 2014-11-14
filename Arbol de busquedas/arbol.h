#ifndef ARBOL_H_
#define ARBOL_H_

#include <stdbool.h>

typedef struct nodo *Arbol;

Arbol arbol_insertar(Arbol a,int n);
bool arbol_pertenece(Arbol a,int n); // si esta el numero devuelve verdadero sino falso
Arbol arbol_encontrar(Arbol a,int n);//devuelve un puntero al nodo donde esta el arbol
Arbol arbol_padre_de(Arbol a,Arbol nodo);
Arbol arbol_eliminar(Arbol a,int i);
void arbol_recorrer_preorden(Arbol a);
void arbol_recorrer_simetrico(Arbol a);
void arbol_recorrer_postorden(Arbol a);
void arbol_destruir(Arbol a);

#endif /*ARBOL_H_*/
