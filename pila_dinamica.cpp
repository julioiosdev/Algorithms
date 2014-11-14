#include <stdio.h>
#include <stdlib.h>

typedef struct pila{
        int valor;
        struct pila *sgte;
}nodo_pila, *tipo_pila;


//Apilar pila dinamica
tipo_pila push(tipo_pila p, int i){
          tipo_pila paux;
          paux = (tipo_pila)malloc(sizeof(nodo_pila));
          paux->sgte = p;
          paux->valor = i;
          return paux;
}

//Desapilar pila dinamica
tipo_pila pop(tipo_pila p, int *valor){
          tipo_pila paux;                             //Declara paux de tipo_pila
          if (p == NULL) return NULL;                 //Si p esta vacio sale
          *valor = p->valor;                          //Le asigna a *valor el valor del ultimo elemento (en este caso 4)
          paux = p->sgte;                             //La variable auxiliar para a apuntar a la posicion donde apuntaba el ultimo elemento (en este caso 2)
          free(p);                                    //Libera el espacio reservado por p
          return paux;                                //Devuelve la pila auxiliar
}

//Vaciar pila dinamica
tipo_pila vaciar(tipo_pila p){
          tipo_pila paux,taux;
          paux = p;
          while(paux != NULL){
                     taux = paux;
                     paux = paux->sgte;
                     free(taux);
          }
          return NULL;
}

int busqueda(tipo_pila p,int valor){
          tipo_pila paux;
          int i=0;
          if (p == NULL) return NULL;
          while (p->sgte != NULL && valor != p->valor) {
                      i++;
                      paux = p->sgte;
                      p = paux; 
          }
          return i;
}

int main()
{
    
    
    //Apilar
    tipo_pila pila = NULL;
    pila = push(pila,7);
    pila = push(pila,2);
    pila = push(pila,4);
    
    //Buscar
    printf("Num. operaciones: %i \n",busqueda(pila,2));
  
    //Desapilar  
 /*
    int i;
    pila = pop(pila, &i);
    pila = pop(pila, &i);
    pila = pop(pila, &i);
   
 */   
    //Vaciar
    //vaciar(pila);
    
    system("pause");
    return 0;
    
}
