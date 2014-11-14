#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <stdbool.h>
#include "arbol.h"

struct nodo{ //usaremos la siguiente estructura
       int elemento;
       struct nodo *izq;
       struct nodo *der;
};

Arbol arbol_insertar(Arbol a,int n){ //devolvera un arbol y pedira un arbol y un numero para construir otro arbol
      
      struct nodo *aux; //usaremos una variable temporal
      
      if(a==NULL){ //si no hay arbol, esta es la condicionpara terminar de ejecutar la instruccioin
                      aux=malloc(sizeof(struct nodo)); //pedimos memoria para la estructura
                      aux->elemento=n; //guardamos el elemento
                      aux->izq = NULL;//Ponemos izquierda y derecha a NULL ya que no esta apuntando a nada
                      aux->der = NULL;
                      return aux;}//devolvemos el arbol que hemos creado
                      
                        
      if(a->elemento==n)//si el elemento que queremos insertar ya esta en el arbol, devolvemos el arbol sin insertar el elemento
            return a;
            
      if(a->elemento>n) //si el elemento de el nodo es mayor que el numero que nos ha metido el usuario
           a->izq=arbol_insertar(a->izq,n); //Apuntamos a la izquierda y volvemos a llamar a la funcion, llamara a la funcion hasta
           //que encuentre un NULL en ese momento creara una estructura y lo enlazara hay
              
      else
           a->der=arbol_insertar(a->der,n); //si es menor apunta a la derecha

      return a; //y devolvemos el arbol

}

Arbol arbol_encontrar(Arbol a,int n){//devuelve un puntero al nodo donde esta el numero
            
        if(a==NULL)
           return NULL;
         
         
         if(a->elemento==n)//Si el numero es igual al elemento de esa estructura
           return a;//devolvemos la estructura
           
           if(a->elemento>n)//Si el numero de la estructura es mayor que el numero que nos da el usuario, significa que el nodo esta
               return arbol_encontrar(a->izq, n);//mas a la izquierda, por eso devolvemos la funcion pero cde el nodo izquierdo
           else
               return arbol_encontrar(a->der, n);//de igual manera que en el anterior pero devolvemos el derecho
}  
            
bool arbol_pertenece(Arbol a,int n){//a traves de un booleano veremos si el numero esta en el arbol
     
      if(a==NULL){ //Si hemos llegado al final y no lo hemos encontrado devolvemos un false
        return false;
         }
         
         if(a->elemento==n) //si lo encontramos devolvemos un true
           return true;
         if(a->elemento>n) //recorreremos el arbol hasta intentar dar con el numero
           arbol_pertenece(a->izq, n);
         else
           arbol_pertenece(a->der, n);
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

Arbol arbol_padre_de(Arbol a,Arbol nodo){

         if(a==NULL)
           return NULL;
         
         if(a->izq==nodo || a->der==nodo)
               return a;
         else if(a->elemento>nodo->elemento)
             return arbol_padre_de(a->izq,nodo);
         else
              return arbol_padre_de(a->der,nodo);
     }



Arbol eliminar(Arbol a,int i){
      
    Arbol q,p; 
        
    if (a == NULL) 
        return a;
    if (a->elemento > i)//buscamos el nodo
        a-> izq = eliminar (a->izq, i); //recursividad por la izquierda para buscar el nodo
        
    else if (a->elemento < i)
         a-> der = eliminar (a->der, i);//recursividad por la derecha para buscar el nodo
         
        else{//si lo hemos encontrado
                //caso 1
                if ((a->der == NULL)&&(a->izq == NULL)) 
                    free(a);
                    return NULL;
                //Caso 2
                if (a->der == NULL){ 
                    q = a->izq;
                    free(a);
                    return q;
                }
                if (a->izq == NULL){
                    q = a->der;
                    free(a);
                    return q;
                    }
                //Caso 3
                for(p=a,q=a->izq; q->der != NULL; q = q->der)
                    p=q;
                if (p!=a)
                    p-> der = q->izq;
                else 
                    p->izq =q->izq;
                a->elemento =q->elemento;
                free(q);
                return NULL;
                }
                return a;
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
     
     
     

