#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_arbol{
        int valor;
        struct nodo_arbol *izquierda;
        struct nodo_arbol *derecha;
        } nodo, *P_nodo_arbol;


P_nodo_arbol insertar (P_nodo_arbol arbol, int i);
int pertence (P_nodo_arbol arbol, int i);
P_nodo_arbol encontrar (P_nodo_arbol arbol, int i);
P_nodo_arbol padre_de (P_nodo_arbol arbol, int i);
void imprimirArbol(P_nodo_arbol arbol, int profundidad);
//eliminar;

main(){
       P_nodo_arbol arbol = NULL;
       int i;
       for (i = 20; i> 0; i--){
           arbol = insertar (arbol,i);
           arbol = insertar (arbol,20+i);
       }
       imprimirArbol(arbol, 0);  
       getchar();  
}


P_nodo_arbol insertar(P_nodo_arbol arbol,int valor){
    if(arbol==NULL){
        arbol=(P_nodo_arbol)malloc(sizeof(nodo));
        arbol->valor=valor;
        arbol->izquierda=NULL;
        arbol->derecha=NULL;
        return arbol;
    }
    else{
        if(arbol->valor<valor){
           arbol->derecha=insertar(arbol->derecha,valor);
           return arbol;
        }
        else{
           if(arbol->valor>valor){
               arbol->izquierda=insertar(arbol->izquierda,valor);
               return arbol;
           }
           else{
               return arbol;
           }
        }
    }
}


void imprimirArbol(P_nodo_arbol arbol, int profundidad){
     if(arbol!=NULL){
                     
         int i;
         for(i=0;i<profundidad;i++){
           printf("-");
         }
         printf("%d\n", arbol->valor);
         printf("iz");
         imprimirArbol(arbol->izquierda,profundidad+1);
         printf("de");
         imprimirArbol(arbol->derecha,profundidad+1);
     }
     else{
          printf("\n");
     }
}
             

