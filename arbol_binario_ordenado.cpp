#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>

int num_elementos=0,indice=0;

typedef struct nodo_arbol{
        int valor;
        struct nodo_arbol *izq;
        struct nodo_arbol *der;
} NODO_ARBOL, *P_NODO_ARBOL;


P_NODO_ARBOL alojar_nodo_arbol(){
      P_NODO_ARBOL p;
      p = (P_NODO_ARBOL)malloc(sizeof(NODO_ARBOL));
      return p;              
}

P_NODO_ARBOL insertar (P_NODO_ARBOL arbol, int i){
             P_NODO_ARBOL p;
             if (arbol == NULL){
                p = alojar_nodo_arbol();
                p->izq = p->der = NULL;
                p->valor = i;
                num_elementos++;
                return p;
             }
             
             if (arbol->valor == i) return arbol;
             if (arbol->valor > i)
                arbol->izq = insertar(arbol->izq, i);
             else
                arbol->der = insertar(arbol->der, i);
             return arbol;
             
}


P_NODO_ARBOL encontrar(P_NODO_ARBOL arbol, int i){
             if (arbol == NULL){
                return NULL;
             }
             if (arbol->valor == i) return arbol;
             if (arbol->valor > i)
                return encontrar(arbol->izq, i);
             else
                return encontrar(arbol->der, i);
}


P_NODO_ARBOL padre_de(P_NODO_ARBOL arbol, P_NODO_ARBOL nodo){
             if (arbol == NULL){
                return NULL;
             }
             if (arbol->izq == nodo || arbol->der == nodo)
                return arbol;
             else if (arbol->valor > nodo->valor)
                return padre_de(arbol->izq, nodo);
             else
                return padre_de(arbol->der, nodo);    
}


void borraNodo(P_NODO_ARBOL arbol,P_NODO_ARBOL nodo,int caso){
     if (caso == 1){
          //  CASO 1
        if (padre_de(arbol,nodo)->valor > nodo->valor)
           padre_de(arbol,nodo)->izq = NULL;
        else
           padre_de(arbol,nodo)->der = NULL;
     } 
     else if (caso == 2) {
          //  CASO 2
     P_NODO_ARBOL q;
        if (nodo->izq == NULL)
           q = nodo->der;
        else
           q = nodo->izq;
           
        if (padre_de(arbol,nodo)->valor > nodo->valor)
           padre_de(arbol,nodo)->izq = q;
        else
           padre_de(arbol,nodo)->der = q;
     } else
     {   //  CASO 3
       P_NODO_ARBOL q,p;
       //Busca el hijo menor dentro del nodo
       for(p=nodo,q=nodo->izq;q->der != NULL; q = q->der)
           p=q;
           
       if (p!=nodo)
          p->der=q->izq;
       else
          p->izq=q->izq;
       
        if (padre_de(arbol,nodo)->valor > nodo->valor)
           padre_de(arbol,nodo)->izq = q;
        else
           padre_de(arbol,nodo)->der = q;
           
     /* Otra forma:
     x = elemento mayor(q->izq) devuelve el elemento mayor de ese nodo
     padre = padre_de (x)
     padre->der = null
     valor = x->valor
     free(valor)
     p->valor=valor
     */
     }
     free(nodo);
          
}

P_NODO_ARBOL eliminar (P_NODO_ARBOL a, int i){
             P_NODO_ARBOL n;
             n = encontrar(a,i);
             P_NODO_ARBOL q,p;
             if (n == NULL) return n;
             if ((n->der == NULL) && (n->izq == NULL)){
                  //  CASO 1
                     printf("Caso 1, elimina el valor: %d\n",n->valor); 
                     borraNodo(a,n,1);
                     return n;
             } 
             else if ((n->der == NULL) || (n->izq == NULL)){
                  //  CASO 2
                     printf("Caso 2, elimina el valor: %d\n",n->valor);
                     borraNodo (a,n,2);
                     return n;
             }else {
                  //  CASO 3
                     printf("Caso 3, elimina el valor: %d\n",n->valor);
                     borraNodo(a,n,3);
                     return n;
             }
             
             return n;
}

void recorridoSimetrico(P_NODO_ARBOL arbol, int recorrido[]){
  if (arbol != NULL) {
    recorridoSimetrico(arbol->izq,recorrido);
    recorrido[indice]=arbol->valor;
    indice++;
    recorridoSimetrico(arbol->der,recorrido);
  }
} 

void recorridoAnterior(P_NODO_ARBOL arbol, int recorrido[]){
  if (arbol != NULL) {
    recorrido[indice]=arbol->valor;
    indice++;
    recorridoSimetrico(arbol->izq,recorrido);
    recorridoSimetrico(arbol->der,recorrido);
  }
} 

void recorridoPosterior(P_NODO_ARBOL arbol, int recorrido[]){
  if (arbol != NULL) {
    recorridoSimetrico(arbol->izq,recorrido);
    recorridoSimetrico(arbol->der,recorrido);
    recorrido[indice]=arbol->valor;
    indice++;
  }
}  

void mayoresQue(P_NODO_ARBOL arbol,int recorrido[],int i){
  int valor = i;
  if (arbol != NULL) {
    if(arbol->valor>i){
        recorrido[indice]=arbol->valor;
        indice++;
    }   
    mayoresQue(arbol->izq,recorrido,valor);
    mayoresQue(arbol->der,recorrido,valor);
  }    
}

int main(){
    P_NODO_ARBOL arbol = NULL;
    
    //Insertar valores
    arbol = insertar(arbol,10);
    arbol = insertar(arbol,5);
    arbol = insertar(arbol,15);
    arbol = insertar(arbol,3);
    arbol = insertar(arbol,7);
    arbol = insertar(arbol,20);
    printf("valor: %i izquierda: %i derecha: %i \n",arbol->valor,(arbol->izq)->valor,(arbol->der)->valor);
    
    //Buscar posicion de valor
    printf("Posicion del 5: %i\n",encontrar(arbol,5));
    
    //Buscar padre de nodo
    printf("Padre del 3: %i\n",padre_de(arbol,encontrar(arbol,3))->valor);
   
    //Eliminar valor de un arbol
    
    //  CASO 1
    /*
    eliminar(arbol,3);
    printf("Posicion del valor 3: %i\n",encontrar(arbol,3));
    */
    
    //  CASO 2
    /*
    eliminar(arbol,15);
    printf("Posicion del valor 15: %d, valor del hijo: %d\n",encontrar(arbol,15),encontrar(arbol,20)->valor);
    */
    
    //  CASO 3
    /*
    eliminar(arbol,5);
    printf("Posicion del valor 5: %d, valor del hijo: %d\n",encontrar(arbol,5),encontrar(arbol,3)->valor);
    */
    
    //  Recorridos
    int recorrido[num_elementos];
    
    //---- Recorrido simetrico
    recorridoSimetrico(arbol,recorrido);
    printf("RECORRIDO SIMETRICO: ");
    for (int x=0;x<num_elementos;x++)
      printf("%i ",recorrido[x]);
    indice = 0;
    //----  
     
    //---- Recorrido anterior
    recorridoAnterior(arbol,recorrido);
    printf("\nRECORRIDO ANTERIOR: ");
    for (int x=0;x<num_elementos;x++)
      printf("%i ",recorrido[x]); 
    indice = 0;
    //----     
    
    //---- Recorrido posterior
    recorridoPosterior(arbol,recorrido);
    printf("\nRECORRIDO POSTERIOR: ");
    for (int x=0;x<num_elementos;x++)
      printf("%i ",recorrido[x]); 
    indice = 0;
    //----     
    
    //---- MAYORES QUE
    mayoresQue(arbol,recorrido,10);
    printf("\nMayores que 10: ");
    for (int x=0;x<indice;x++)
      printf("%i ",recorrido[x]); 
    indice = 0;
    //----    
     
    printf("\n");   
    system("PAUSE");
    return 0;
}   
