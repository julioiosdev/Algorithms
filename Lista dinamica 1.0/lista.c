/* Implementacion tipo de datos LISTA dinamica de datos */

/*Caracteristicas generales:
                  -Lista dinamica simplemente enlazada con nodo cabecera
                  -Los punteros apuntan realmente al siguiente elemento que este referenciado
                  -Cuando se inserta un elemento, el actual se va desplazando.
                  -El ultimo elemento es NULL
                  -El tipo de la lista viene definido por el tipo de elemento que contiene, todas las funciones
                  son independientes del tipo de elemento excepto:
                      l_int_devuelve
                  -Es necesario declarar:
                      -stdlib.h (malloc, free)
                      -assert.h (assert) */
                      
#include <stdlib.h>
#include <assert.h>
#include "lista.h"

struct nodo{
       int elemento;
       struct nodo *psig;
       };
       
struct nodo* l_int_crear(void){
       struct nodo *paux; //crea el nodo cabecera
       
       if ((paux = malloc(sizeof(struct nodo))) != NULL ){
                 paux ->psig = NULL;
                 assert (paux != NULL);
                 }
                 
                 return (paux);
       }
       
       
struct nodo* l_int_insertar(struct nodo *l, struct nodo *pindice, int n){
       struct nodo *paux;
       assert(pindice !=NULL);
       paux = malloc(sizeof(struct nodo));
       if(paux !=NULL){
               paux->elemento = n;
               paux->psig = pindice->psig;
               pindice->psig = paux;
       }
       return (paux);
}

struct nodo* l_int_primero(struct nodo *l){
       assert(l !=NULL);
       return(l); //Devuelve un puntero al nodo cabecera
}

struct nodo* l_int_ultimo(struct nodo *l){
       struct nodo *paux; //El ulimo elemento de la lista es NULL
       paux=l;
       while(paux->psig != NULL)
             paux=paux->psig;
             
       assert(paux->psig == NULL);
       return(paux);
}

struct nodo* l_int_siguiente(struct nodo *l, struct nodo *pindice){
       assert(pindice->psig !=NULL);
       return(pindice->psig);
       }
       
struct nodo* l_int_anterior(struct nodo *l, struct nodo *pindice){
       struct nodo *paux;
       assert(pindice !=l);
       paux=l;
       while(paux->psig !=pindice)
       paux=paux->psig;
       assert(paux->psig == pindice);
       return(paux);
}

int l_int_longitud(struct nodo *l){
    int contador;
    struct nodo *paux;
    assert(l !=NULL);
    paux=l;
    contador=0;
    while(paux->psig != NULL){
                     contador++;
                     paux=paux->psig;
                     }
    return(contador);
}

struct nodo* l_int_localizar(struct nodo *l, const int posicion){
       struct nodo* paux;
       int c;
       
       assert(l->psig !=NULL); //La lista no tiene que estar vacia
       paux=l;
       c=posicion;
       while((c>0) && (paux->psig->psig!=NULL)){
                   paux=paux->psig;
                   c--;
                   }
       return(paux);
}

int l_int_elemento(struct nodo *l, struct nodo *pindice){
    assert(pindice->psig != NULL);
    return(pindice->psig->elemento);
}

void l_int_borrar(struct nodo *l,struct nodo *pindice){
     struct nodo *paux;
     assert (pindice->psig !=NULL);
     paux=pindice->psig;
     pindice->psig=pindice->psig->psig;
     assert(paux != NULL);
     free(paux);
}

void l_int_destruir (struct nodo *l){
     struct nodo *pborra;
     struct nodo *paux;
     
     paux=l;
     do{
            pborra=paux;
            paux=paux->psig;
            assert(pborra !=NULL);
            free(pborra);
            
            } while(paux!=NULL);
}

            
       
               
