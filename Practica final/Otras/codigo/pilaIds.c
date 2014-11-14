#include "PracticaAlgoritmia.h"
using namespace std;


p_tipo_pila crearPila(void)
{
     p_tipo_pila pila = (p_tipo_pila)malloc(sizeof(pila));
     pila->cima=0;
     return pila;
}
//Devuelve -1 si no hay elementos o el elemento si existe
int pop(p_tipo_pila pila){
    if (pila->cima > 0)
       return pila->valores[--pila->cima];     //se decrementa antes de hacer la operacion
    else
      return -1;
}

//simula pila "vacia" poniendo la cima "El apuntador "a 0
bool vaciar(p_tipo_pila pila){
    if (pila->cima!=0)
       pila->cima = 0;
    return true;
}

//posiciono 1 elemento en la pila devuelve -1 si ya esta llena
int push(p_tipo_pila pila, int numero){
    int error=0;
    if (pila->cima < MAX_ELEMS) 
       pila->valores[pila->cima++] = numero;   //hace la operacion y despues hace el ++ por eso vacia es = 0    
    else
        error=-1;
    return error;
}
bool esVaciaPila(p_tipo_pila pila)
{
     bool  vacia=true;
     if (pila->cima>0)
        vacia=false;
     return vacia;
     
}


