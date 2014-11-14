#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define MAX_NODOS 100

void inicializar (int C[][MAX_NODOS], int *PnNodos){
  *PnNodos = 0;   
}


void mostrar (int C[][MAX_NODOS], int PnNodos, int eliminados[], int nEliminados){
     printf("Lista de elementos:\n\n");
     for (int x = 0;x<PnNodos;x++)
       for (int i = 0;i<PnNodos;i++){
          printf;
          if (C[x][i]>=0) printf(" %i ",C[x][i]);
          else printf("%i ",C[x][i]);
          if (PnNodos>1) if ((i%(PnNodos-1)==0) && i>0) printf("\n");;
      }
      printf("\n\n");
      
     printf("Lista de eliminados:\n\n");
     for (int x = 0;x<nEliminados;x++)
          printf("%i ",eliminados[x]);
     printf("\n\n");
}

void adicionar_nodo (int C[][MAX_NODOS], int *PnNodos){
  *PnNodos+=1;    
}

void adicionar_arco (int C[][MAX_NODOS], int *PnNodos, int nodoInicio, int nodoFin, int coste){
  if ((nodoInicio <= *PnNodos) && (nodoFin <= *PnNodos))  
      C[nodoInicio][nodoFin]=coste;
}

void eliminar_arco (int C[][MAX_NODOS], int *PnNodos, int nodoInicio, int nodoFin){
  C[nodoInicio][nodoFin]=0;
}

void eliminar_nodo (int C[][MAX_NODOS], int *PnNodos, int nodo, int eliminados[], int *nEliminados){
   for (int x = 0;x<*PnNodos;x++)
       for (int i = 0;i<*PnNodos;i++){
           if (i==nodo){
              C[x][nodo] = -1;
           }
            if (x==nodo){
              C[nodo][i] = -1;
           }
       }
   
    eliminados[*nEliminados] = nodo;
    *nEliminados+=1;
          
   /*for (int x = 0;x<*PnNodos;x++)
      for (int i = 0;i<*PnNodos;i++){
          if (C[x][i] == -1) {
             for (;x<*PnNodos-1;x++)
                 for (;i<*PnNodos-1;i++)
                    printf("C[%i][%i] =  C[%i][%i]",x,i,x+1,i+1);
          }  
       }
       
     *PnNodos-=1;  
    */
       
                       
}

void devolver_nodos_salientes(int C[][MAX_NODOS], int *PnNodos, int nodo){
  printf("Nodos salientes de %i: \n\n",nodo); 
  for (int x = 0;x<*PnNodos;x++)
       for (int i = 0;i<*PnNodos;i++)
         if (C[x][i] > 0) {} 
         
         
}

int main() {
      int C[MAX_NODOS][MAX_NODOS];
      int eliminados[MAX_NODOS];
      int PnNodos,nEliminados;
      
      inicializar(C,&PnNodos);
      
      adicionar_nodo(C,&PnNodos);
      adicionar_nodo(C,&PnNodos);
      adicionar_nodo(C,&PnNodos);
      adicionar_nodo(C,&PnNodos);
      
      adicionar_arco(C,&PnNodos,0,1,2); 
      
      devolver_nodos_salientes(C,&PnNodos,1);
      
      eliminar_nodo(C,&PnNodos,2,eliminados,&nEliminados); 
      
      mostrar(C,PnNodos,eliminados,nEliminados);
      
      system("PAUSE");
      return 0;
}
