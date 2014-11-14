#include <stdio.h>
#include <stdlib.h>
//declaro una estructura que está compuesta por dos cosas: la información a guardar y  un puntero que apunta al siguiente nodo, 
//así hago que la estructura sea dinámica. Si el puntero al siguiente nodo es null, quiere decir 
//que es el último elemento de la lista.
typedef struct pila{
        int valor;
        struct pila *siguiente;
        } nodo_pila,*tipo_pila;
//de esta estructura "pila" declaro dos variables: nodo_pila que lo voy a utilizar para saber el tamaño a reservar en memoria
// y el puntero a la primer nodo


//Declaro las funciones que voy a implementar
tipo_pila* push (tipo_pila *p, int numero); //inserta un valor en lo alto de la pila
tipo_pila* pop(tipo_pila *p); // suprime el ?ltimo que entra
int tope (tipo_pila *p); //devuelve el valor del ?ltimo elemento sin eliminarlo
tipo_pila* vaciar (tipo_pila *p);
tipo_pila* copiar (tipo_pila *p, tipo_pila *pilaDestino);

        
main(){
       //declaro--> aqui aun no guardo el espacio en memoria, solo la declaro
              tipo_pila* pila = NULL;
              
       // voy a meter 2 valores en la pila:
            pila=  push(pila,3);
             pila= push(pila,8);
             pila= push(pila,2);
             pila= push(pila,1);
         // voy a meter 2 valores en la pila:
             pila=  pop (pila)  ;    
      //mostrar el ultimo valor
      printf("El ultimo valor es %d", pila->valor);
      
      //vaciar la pila
      vaciar(pila);
       printf("\n Pila vacia");
       
       
        getchar();      
       };
       


//FUNCIONES
tipo_pila* push (tipo_pila *p, int numero){
     //primero reservo en memoria:
               tipo_pila paux = (tipo_pila )malloc (sizeof(nodo_pila));
     //le digo que el siguiente valor es p--> si p es null, quiere decir que es el ultimo valor
               paux-> siguiente = p;
     //ahora le digo que la estructura tiene como valor el numero
               paux->valor = numero;
     //devuelvo el puntero al ultimo nodo que acabo de crear, para que pila, que es la cima, apunte a este.
               return paux;
     }

tipo_pila* pop(tipo_pila *p){
          
          if (p == NULL) return NULL;
          else {
          tipo_pila* aux= p->siguiente;
          free(p);
          return aux;
          }
}

tipo_pila* vaciar (tipo_pila *p){
          while(p!=NULL){
              p=pop(p);               
          }
          //tipo_pila* paux,taux;
//          paux= p;
//          while (paux != NULL){
//                taux=paux;
//                paux=paux->siguiente;
//                free(taux);
//                }
//          return NULL;
         
          }

int tope (tipo_pila *p){
    
    if(p==NULL)
         return NULL;
    else
        return p->valor;
        
    }


tipo_pila* copiar (tipo_pila *p, tipo_pila *pilaDestino){
           
           tipo_pila *pilaAuxiliar=NULL;
           
           tipo_pila i; //  variable de control del bucle
           i=p; //i apunta a la ultima direccion de memoria de p --> a la cima de p
           while (i!=NULL){
              pilaAuxiliar=push(pilaAuxiliar,i->valor);
              i=i->siguiente;
           }
           while(pilaAuxiliar!=NULL){
              pilaDestino=push(pilaDestino,pilaAuxiliar->valor);
              pilaAuxiliar=pop(pilaAuxiliar);                          
           }
           return pilaDestino;
           
           
           
           
           }

