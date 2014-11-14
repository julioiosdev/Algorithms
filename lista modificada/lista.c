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

//Esta totalmente comentada por David Prieto para facilitar la comprension  
//En este documento tenemos todas las funciones que llamaremos en el documento principal.                  
#include <stdlib.h>
#include <assert.h>
#include "lista.h"

struct nodo{ //declaramos nodo como una estructura la cual usaremos para todas las demas funciones
       int elemento;//declaramos un entero
       struct nodo *psig; //dentro declaramos un puntero ( *psig ) que tendra la estructura nodo.
       };
       
struct nodo* l_int_crear(void){ //creamos una funcion de tipo struct nodo que sera un puntero
       struct nodo *paux; //crea el nodo cabecera
       
       if ((paux = malloc(sizeof(struct nodo))) != NULL ){ //pedimos memoria del tamaño que necesite struct nodo
                 paux ->psig = NULL; //y paux apuntara a psig que sera igual a NULL. (hemos creado nuetsra cabecera)
                 assert (paux != NULL);
                 }
                 
                 return (paux); //devolvemos paux (el nodo cabecera) aunque no lo usaremos normalmente
       }
       
       
struct nodo* l_int_insertar(struct nodo *l, struct nodo *pindice, int n){ //pedira como entrada la lista, la posicion, y el numero a insertar
       struct nodo *paux; //declaramos un puntero de tipo struct nodo
       assert(pindice !=NULL);
       paux = malloc(sizeof(struct nodo));//pedimos memoria
       if(paux !=NULL){ //si tenemos memoria
               paux->elemento = n; //paux apuntara a elemento que tendra el valor del numero que se le da como entrada a la funcion
               paux->psig = pindice->psig;//paux que apuntara a psig tendra el valor de pindice que apuntara a psig
               pindice->psig = paux;//por ultimo pindice apuntara a psig y tendra el valor de paux
       }
       return (paux);//devolveremos paux, el valor del elemento insertado
}

struct nodo* l_int_primero(struct nodo *l){//pedimos la lista
       assert(l !=NULL);
       return(l); //Devuelve un puntero al nodo cabecera, esto es, el principio de la lista
}

struct nodo* l_int_ultimo(struct nodo *l){ //pedimos la lista
       struct nodo *paux; //El ulimo elemento de la lista es NULL
       paux=l; //paux es igual a la lista
       while(paux->psig != NULL)//mientras paux que apunta a psig sea distinto de null...
             paux=paux->psig; //paux sera paux que apuntara a psig, asi recorreremos toda la lista hasta el elemento final
             
       assert(paux->psig == NULL); 
       return(paux); //devolvemos paux que sera el valor del ultimo elemento
}

struct nodo* l_int_siguiente(struct nodo *l, struct nodo *pindice){//pediremos la lista y la posicion en la que estamos
       assert(pindice->psig !=NULL);
       return(pindice->psig); //simplemente devolvemos la posicion apuntando a psig, esto es, la posicion siguiente
       }
       
struct nodo* l_int_anterior(struct nodo *l, struct nodo *pindice){//pediremos la lista y la posicion
       struct nodo *paux; //declaramos un puntero auxiliar
       assert(pindice !=l);
       paux=l; //paux sera igual a la lista
       while(paux->psig !=pindice) //mientras paux que apunta a psig sea distinto de la posicion en la que nos encontramos
       paux=paux->psig; //paux es igual a paux apuntando a psig, avanzamos un puesto
       assert(paux->psig == pindice);
       return(paux);//devolvemos paux, esto es, el anterior
}

int l_int_longitud(struct nodo *l){
    int contador;
    struct nodo *paux;
    assert(l !=NULL);
    paux=l;
    contador=0;
    while(paux->psig != NULL){//recorreremos toda la lista hasta encontrar el NULL
                     contador++;//contador se ira incrementando tantas veces como avancemos puestos.
                     paux=paux->psig;
                     }
    return(contador);
}

struct nodo* l_int_localizar(struct nodo *l, const int posicion){//pdedimos la lista y la posicion, que sera constante
       struct nodo* paux;
       int c;
       
       assert(l->psig !=NULL); //La lista no tiene que estar vacia
       paux=l;
       c=posicion;
       while((c>0) && (paux->psig->psig!=NULL)){//mientras la posicion sea mayor que 0(que la posicion sea valida) y
       //paux que apunta a psig que apunta a psig sea distinto de NULL (que no lleguemos al final de la lista)
                   paux=paux->psig;
                   c--;
                   }
       return(paux);
}

int l_int_elemento(struct nodo *l, struct nodo *pindice){//pediremos la lista y la posicion
    assert(pindice->psig != NULL);
    return(pindice->psig->elemento); //devolveremos pindice apuntando a psig apuntando al elemento, debemos de hacer esto por el nodo cabecera
}

void l_int_borrar(struct nodo *l,struct nodo *pindice){//se hara de la misma forma que la funcion insertar
     struct nodo *paux;
     assert (pindice->psig !=NULL);
     paux=pindice->psig;
     pindice->psig=pindice->psig->psig;
     assert(paux != NULL);
     free(paux);
}

void l_int_destruir (struct nodo *l){//pediremos la lista
     struct nodo *pborra;
     struct nodo *paux;
     
     paux=l;
     do{
            pborra=paux;//iremos liberando la memoria pasando por todos los punteros
            paux=paux->psig;
            assert(pborra !=NULL);
            free(pborra);
            
            } while(paux!=NULL);//hasta encontrar el NULL
}

            
       
               
