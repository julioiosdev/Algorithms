#include <stdio.h>
#include <stdlib.h>
//declaro una estructura que está compuesta por dos cosas: la información a guardar y  un puntero que apunta al siguiente nodo, 
//así hago que la estructura sea dinámica. Si el puntero al siguiente nodo es null, quiere decir 
//que es el último elemento de la lista.
typedef struct nodo{
        int valor;
        struct nodo *siguiente;
        struct nodo *anterior;
        } nodo_cola;

typedef struct cola{
        nodo_cola *primero;
        nodo_cola *ultimo;
        } tipo_cola;


tipo_cola* crearCola(); //es el constructor

//funciones modificadoras
tipo_cola* encolar (tipo_cola *p, int numero); 
tipo_cola* desencolar(tipo_cola *p); 
tipo_cola* vaciar (tipo_cola *p);

//esta funcion es una especie de constructor..
tipo_cola* copiar (tipo_cola *p);

//funciones observadoras
int primero (tipo_cola *p); //devuelve el valor del ?ltimo elemento sin eliminarlo

//Funcion que imprime
void printcola(tipo_cola *p);

        
main(){
             
             tipo_cola* cola = NULL;
              
             cola= encolar(cola,3);
             printcola(cola);
             cola= encolar(cola,8);
	     printcola(cola);
             cola= encolar(cola,2);
	     printcola(cola);
             cola= encolar(cola,1);
             printcola(cola);
             cola= desencolar (cola)  ;    
             printcola(cola);
             printf("El ultimo valor es %i \n", primero(cola));
      
             cola=vaciar(cola);
             printcola(cola);
             printf("\n cola vacia");
       
       
             getchar();      
       };
tipo_cola* crearCola(){
           tipo_cola *i;
           i=(tipo_cola*)malloc(sizeof(cola));
           i->siguiente = NULL;
           i->anterior= NULL;
           return i;           
}
           


//FUNCIONES
tipo_cola* encolar (tipo_cola *p, int numero){
           nodo_cola* nodo_nuevo =  (nodo_cola*)malloc (sizeof(nodo));
                     
           nodo_nuevo->siguiente=p->ultimo;
           nodo_nuevo->anterior=NULL;
           nodo_nuevo->valor=numero;
           
           p->ultimo->anterior=nodo_nuevo;
           p->ultimo=nodo_nuevo;
           return p;
         }

tipo_cola* desencolar(tipo_cola *p){
          
          if (p->primero == NULL){
             return p;
          }
          else {
               nodo_cola *aux=p->primero;
               p->primero=aux->anterior;
               p->primero->siguiente=NULL;
               free(aux);
          }
          return p;
}

tipo_cola* vaciar (tipo_cola *p){
          while(p->primero!=NULL){  //llama a la funcion desencolar hasta que el puntero no est� a null
              p=desencolar(p);               
          }
          return p;
}

int primero (tipo_cola *p){
    return p->primero->valor;        //recibe la direccion de la cima de la cola. y devuelve el valor
}


tipo_cola* copiar(tipo_cola *p){
           
}

void printcola(tipo_cola *p){
	tipo_cola *i;
        i=p;
        while(i!=NULL){
		printf("%i -> ",i->valor);
		i=i->siguiente;
	}
        printf("\n");
}


