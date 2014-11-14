#include <iostream.h>
#include <stdlib.h>


typedef struct lista{
        int valor;
        struct lista *anterior;
        struct lista *siguiente;
}NODO_LISTA,*P_NODO_LISTA;

P_NODO_LISTA crear_nodo(P_NODO_LISTA l){
     l = (P_NODO_LISTA)malloc(sizeof(NODO_LISTA));
     return l;
}

P_NODO_LISTA insertar (P_NODO_LISTA lst,int valor, int pos){
             P_NODO_LISTA laux, lsgte;
             printf("Insertando el %i en la posicion %i ...\n",valor,pos);
             int i;
             if ((pos == 0) || lst == NULL){       //Si la lista esta vacia o la posicion es la primera
                   laux = crear_nodo(lst);
                   laux->valor = valor;
                   laux->anterior = NULL;
                   laux->siguiente = lst;
                   if(lst != NULL) lst->anterior = laux;   //Si la lista no esta vacia y es la primera posicion
                   return laux;
             }
             
             for (i = 1, laux = lst; (i<pos)&&(laux != NULL);i++){
                    laux = laux->siguiente;
                    printf("  Antes estaba en esta posicion estaba el: %i\n",laux->siguiente->valor);
             }

             if (laux != NULL){
                lsgte = laux -> siguiente;
                laux->siguiente = crear_nodo(laux->siguiente);
                laux->siguiente->valor = valor;
                laux->siguiente->siguiente = lsgte;
                laux->siguiente->anterior = laux;
                if (lsgte != NULL)
                   lsgte->anterior = laux->siguiente;
             }
             return lst;
}

void mostrar(P_NODO_LISTA lst,int elementos){
     P_NODO_LISTA laux = lst;
     printf("\nValores: ");
     for (int i = 0;i<elementos;i++){
         printf("%i ",laux->valor);
         laux = laux->siguiente;
     }
     printf("\n\n");
}

P_NODO_LISTA borrar (P_NODO_LISTA lst, int pos){
             P_NODO_LISTA laux;
             int i;
             //Si la posición está fuera de rango o la lista es vacía no
             //se hace nada. Devolvemos la lista tal cual.
             if ((pos < 0) || (lst == NULL)) return lst;
             //Si es la primera posición, eliminamos el elemento y ponemos
             //como cabeza de la lista el segundo elemento.
             if (pos == 0){
                laux = lst->siguiente;
                free(lst);
                //En el caso de que no fuera el ultimo elemento se pone
                //el puntero a anterior apuntando a NULL
                if (laux != NULL)
                   laux->anterior = NULL;
                return laux;
             }
             //Lo primero que se debe hacer es encontrar la posición a borrar.
             for (i = 0,laux=lst; (i<pos)&&(laux->siguiente != NULL);i++)
                 laux = laux->siguiente;
             //Si no hemos llegado al último nodo, eliminamos y
             //actualizamos las referencias del nodo anterior y posterior del eliminado
             if (laux->siguiente != NULL){
                laux->anterior->siguiente = laux->siguiente;
                laux->siguiente->anterior = laux->anterior;
                free(laux);
             } else if (pos == i){
             //Si hemos llegado al final de lista y ese es el
             //elemento a eliminar sólo tenemos que actualizar el puntero a
             //siguiente.
                laux->anterior->siguiente = laux->siguiente;
                free(laux);
             }
             return lst;
}

int main()
{
      P_NODO_LISTA lst = (P_NODO_LISTA)malloc(sizeof(NODO_LISTA));
      //Insertar
      lst = insertar(lst,6,0);
      lst = insertar(lst,1,0);
      lst = insertar(lst,3,0);
 
      mostrar(lst,3);
      
      lst = insertar(lst,8,2);
      
      mostrar(lst,4);
      
      //Borrar
      
      lst = borrar(lst,2);
      
      mostrar(lst,3);
      system("PAUSE");
      return 0;
}
