#include <iostream.h>
#include <stdlib.h>

typedef struct n_cola{
        int valor;
        struct n_cola *sig;
}NODO_COLA, *P_NODO_COLA;

typedef struct t_cola{
        P_NODO_COLA cabeza;
        P_NODO_COLA cola;
}*tipo_cola;

void push(P_NODO_COLA c, int i){
     tipo_cola t;
     if(c == NULL) t->cola = t->cabeza = c;
     else{
          q->cola->sig = p;
          q->cola = p;
     }
     c->sig = NULL;
     c->valor = i;
}
/*
int pop(tipo_cola *q){
    P_NODO_COLA p; 
    int v;
    if(es_vacia(q)){
      v = 0; 
      printf("Error: cola vacia \n");
    } else {
      v = q->cabeza->valor; p = q->cabeza;
      q->cabeza = q->cabeza->sig;
      free(p);
      }
    return v;
}
*/

int main()
{
      //Apilar

      P_NODO_COLA cola = (P_NODO_COLA)malloc(sizeof(NODO_COLA));
      tipo_cola t_cola;
      push(cola ,7);
      
      t_cola->cabeza = cola;
      printf("%i\n",cola->valor);
      printf("%d\n",(t_cola->cabeza)->valor);
      
      //Desapilar
      /*
      pop(cola);
      pop(cola);
      pop(cola);
      */
      system("PAUSE");
      return 0;
}
