#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_ELEMS 10
typedef struct cola {
        int cabeza,cola;
        int valores[MAX_ELEMS];
} tipo_cola;

int suma_uno(int i){
    return ((i+1) % MAX_ELEMS);
}

void apilar(tipo_cola *c, int i){
     if (suma_uno((c->cola)) == c->cabeza) {
        printf("Error: Cola llena \n");
     } else {
       c->valores[c->cola] = i;
       c->cola = suma_uno((c->cola));
     }
}

int pop(tipo_cola *c){
      int v = 0;
      if (c == NULL){
         v=0;
         printf("Error: Cola vacia\n");
      } else {
         v = c->valores[c->cabeza];
         c->cabeza = suma_uno((c->cabeza));
         return v;
      }
}

int buscar(tipo_cola *c, int valor) {
    int i = 0;
     for (;c->cabeza <= c->cola;(c->cabeza)++){
         i++;
        if(valor == c->valores[c->cabeza]) return i;
     }
     return -1;
       
}

void inicializar(tipo_cola *c){
     c->cabeza = 0;
     c->cola = 0;     
}

int main()
{
      tipo_cola *cola = (tipo_cola*)malloc(sizeof(tipo_cola));;

      inicializar(cola);
         
      //Apilar  
      apilar(cola,7);
      printf("cola: %i cabeza: %i valor: %i \n",cola->cola,cola->cabeza,cola->valores[0]);
      apilar(cola,4);
      printf("cola: %i cabeza: %i valor: %i \n",cola->cola,cola->cabeza,cola->valores[1]);
      apilar(cola,2);
      printf("cola: %i cabeza: %i valor: %i \n",cola->cola,cola->cabeza,cola->valores[2]);
      
      
      //Buscar un valor
      printf("Num. operaciones: %i \n",buscar(cola,2));
      
      //Desapilar
      /*
      printf("%d ", pop(cola));
      printf("%d ", pop(cola));
      printf("%d ", pop(cola));
      */
      
      system("PAUSE");
      return 0;
}
