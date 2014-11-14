#ifndef _LISTA_H
#define _LISTA_H

typedef struct nodo *Lista;
typedef struct nodo *Posicion;

Lista l_int_crear(void);
Posicion l_int_insertar(Lista l,Posicion pos, int n);
Posicion l_int_primero(Lista l);
Posicion l_int_ultimo(Lista l);
Posicion l_int_siguiente(Lista l,Posicion pos);
Posicion l_int_anterior(Lista l,Posicion pos);
int l_int_longitud(Lista l);
Posicion l_int_localizar(Lista l, int posicion);
int l_int_elemento(Lista l,Posicion pos);
void l_int_borrar(Lista l, Posicion pos);
void l_int_destruir(Lista l);

#endif /* _LISTA_H*/
