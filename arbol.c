#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "arbol.h"

struct nodo{ //declaramos una estructura que va a tener dos punteros a dos estructuras de tipo nodo y un entero que sera el numero
       int elemento;
       struct nodo *izq;
       struct nodo *der;
};

Arbol arbol_inicializar(int i){ //simplemente creamos un arbol, poniendo los dos punteros a NULL
      struct nodo *arbol;
      
      arbol=malloc(sizeof(struct nodo));
      arbol->elemento=i;
      arbol->izq = NULL;
      arbol->der = NULL;
      
      assert(arbol != NULL);
      return arbol; 
}

Arbol arbol_construir(Arbol arbol, Arbol izq, Arbol der){ //pedimos un numero para central otro para el puntero izquierdo y otro para el derecho
      assert(arbol!=NULL);
      assert(arbol != izq &&arbol !=der);
      arbol->izq=izq; //ponemos al padre apuntando al nodo izquierda
      arbol->der=der;//y lo ponemos apuntando al derecho
      return arbol;
      
}
      
void arbol_recorrer_preorden(Arbol a){ //lo haremos mediante la recursividad
     if(a==NULL)//condicion para que salga de la funcion, saldra cuando el arbol sea NULL
         return;
     
     printf("%d ",a->elemento); //Como es preorden escrivimos primero el numero
     arbol_recorrer_preorden(a->izq);//Volvemos a llamar a la funcion dandole como entrada el nodo izquierdo(asi escriviremos la parte izquierda del arbol)
     //y escrivimos el elemento, esto lo hara mientras no llegue a NULL cuando llegue cerrara esa funcion
     arbol_recorrer_preorden(a->der);//tras recorrer la parte izquierda y escrivir los nodos ira a la derecha (lo mejor es dibujarlo para entenderlo)
}
     
void arbol_recorrer_simetrico(Arbol a){//el resto se hace igual, solo cambia el orden en el que escrive el elemento
     
       if(a==NULL)
         return;
     
    
     arbol_recorrer_simetrico(a->izq);//aqui primero recorremos la parte izquierda y luego escrivimos el numero
      printf("%d ",a->elemento);
     arbol_recorrer_simetrico(a->der);     
}

void arbol_recorrer_postorden(Arbol a){
     if(a==NULL)
         return;
     
     
     arbol_recorrer_postorden(a->izq);//primero llegamos al final de el arbol y despues escrivimos el numero
     arbol_recorrer_postorden(a->der);
     printf("%d ",a->elemento);
     
}

void arbol_destruir(Arbol a){
  struct nodo *paux;
  
  
  if(a==NULL)
  return;
  
    paux=a;
    if(a->der !=NULL)//mientras quede arbol lo recorrera destruyendolo, por la parte izquierda y luego la derecha
    arbol_destruir(a->der);//recorre el arbol como en postorder
    if(a->izq !=NULL)
    arbol_destruir(a->izq);
    free(paux);


     }
     
     
      
       
