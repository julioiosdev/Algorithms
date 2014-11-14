#include <stdio.h>
#include <stdlib.h>


typedef struct nodo_arbol{
int valor;
struct nodo_arbol *izq;
struct nodo_arbol *der;
} NODO_ARBOL, *P_NODO_ARBOL;


P_NODO_ARBOL insertar (P_NODO_ARBOL arbol, int i);
P_NODO_ARBOL encontrar (P_NODO_ARBOL arbol, int i);
P_NODO_ARBOL alojar_nodo_arbol();


int main(int argc, char** argv){
       
       P_NODO_ARBOL inser,encontrado, devuelto;
       
       inser = NULL;
      
       devuelto = insertar  (inser, 10);
       devuelto = insertar  (devuelto, 8);
       devuelto  = insertar  (devuelto, 3);
       devuelto  = insertar  (devuelto, 5);
       devuelto  = insertar  (devuelto, 30);
       
       
       encontrado= encontrar(devuelto,10);
       printf("\nEncontrado: %d\n", encontrado->valor);
       encontrado= encontrar(devuelto,3);
       printf("\nEncontrado: %d\n", encontrado->valor);
       encontrado= encontrar(devuelto,8);
       printf("\nEncontrado: %d\n", encontrado->valor);
       encontrado= encontrar(devuelto,5);
       printf("\nEncontrado: %d\n", encontrado->valor);
       encontrado= encontrar(devuelto,30);
       printf("\nEncontrado: %d\n", encontrado->valor);
       
       //encontrado= encontrar(buscado,8);
      
      system("PAUSE"); 
      return 0;
      
       
             }


P_NODO_ARBOL alojar_nodo_arbol(){
             
             P_NODO_ARBOL nodo =  (P_NODO_ARBOL) malloc (sizeof(NODO_ARBOL));
             return nodo;
             }



P_NODO_ARBOL insertar (P_NODO_ARBOL arbol, int i){
    P_NODO_ARBOL p;
    if (arbol == NULL){
              p = alojar_nodo_arbol();
              p->izq = p->der = NULL;
              p->valor = i;
              return p;
    }
    if (arbol->valor == i) return arbol;
    if (arbol->valor > i) 
           arbol->izq = insertar(arbol->izq, i);
    else
           arbol->der = insertar(arbol->der, i);
    return arbol;
}



int pertenece (P_NODO_ARBOL arbol, int i){
    if (arbol == NULL){
    return 0;
    }
    if (arbol->valor == i) return 1;
    if (arbol->valor > i) 
    return pertenece(arbol->izq, i);
    else 
    return pertenece(arbol->der, i);
}



P_NODO_ARBOL encontrar (P_NODO_ARBOL arbol, int i){
    if (arbol == NULL){
    return NULL;
    }
    if (arbol->valor == i){
                     printf ("\n == El esta aqui %d", arbol->valor);
    return arbol;}
    if (arbol->valor > i) {
                      printf ("\n Esta a la izquierda de %d", arbol->valor);
    return encontrar(arbol->izq, i);}
    else {
          printf ("\n Esta a la derecha de %d", arbol->valor);
    return encontrar(arbol->der, i);}
}



P_NODO_ARBOL padre_de (P_NODO_ARBOL arbol, P_NODO_ARBOL nodo){
    if (arbol == NULL){
    return NULL;
    }
    if (arbol->izq == nodo || arbol->der == nodo)
    return arbol;
    else if (arbol->valor > nodo->valor)
    return padre_de(arbol->izq, nodo);
    else
    return padre_de (arbol->der, nodo);
}
