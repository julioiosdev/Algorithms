#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "pila.h"

#define TAM 5000

struct tipo_pila{ //declaramos una estructura que tendra un array y un entero
       int elementos[TAM];
       int tope;
};

Pila crear(void){
     Pila p = malloc(sizeof(struct tipo_pila)); //pedimos memoria y creamos el primer elemento de la pila
     
     if(p != NULL){
          p->tope = 0; //metemos un 0 en tope
          }
          
          return p; //devolvemos la pila
     
     }
     
 void destruir(Pila p){
          assert(p != NULL);
          free(p); //liberamos la pila
          }
          
 void vaciar(Pila p){
      p->tope=0; //ponemos tope a 0
      }
 
 bool esta_vacia(Pila p){
      if(p->tope == 0) //comprobamos si esta vacia, si lo esta nos devolvera verdadero
      return true;
      
      else  //sino nos devolvera falso
      return false;
      }
      
 
 bool esta_llena(Pila p){ //hacemos una comprobacion, si tope es iguala al tamaño de la pila devolvemos verdadero, esto es esta llena
      if(p->tope == TAM)
      return true;
      else //sino esta llena devolvemos falso
      return false;
      }
      
  void apilar(Pila p,int n){//para apilar necesitamos la pila y el entero que queremos apilar
       assert(!esta_llena(p));
       p->elementos[p->tope]=n; //apuntamos al array de elementos en la posicion marcada por tope, ya que tope sera tan grande
       //como el numero de elementos, asi metemos el numero al final, y le metemos el numero (n)
       p->tope++; //mas uno a tope, ya que tenemos otro elemento
       }
       
      int desapilar(Pila p){//mostramos los elementos de la pila
          assert(!esta_vacia(p));
          p->tope--;//le restamos uno a tope ya que estamos sacando un elemento de la lista
          return p->elementos[p->tope];//devolvemos un puntero al array de elementos en la posicion marcada por tope
          //ya que le devolveremos el ultimo elemento de la pila, recuerda que el elemento lo sacamos de la lista
          }  
     
