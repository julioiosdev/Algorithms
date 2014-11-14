#include <iostream.h>
#include <stdlib.h>

#define MAX_ELEMS 10

typedef struct lista{
        int valores[MAX_ELEMS];
        int p_libre;
} tipo_lista;

void insertar(tipo_lista *l, int v, int p){
     int i;
     if (p-1 > l->p_libre || p < 1){
        printf("Error: posición fuera de lista\n");
        return;
     }
     
     if (l->p_libre == MAX_ELEMS){
        printf("Error: lista llena\n");
        return;
     }
    for(i=l->p_libre; i>=p;i--) {
          l->valores[i] = l->valores[i-1];
     }
     l->valores[p-1]=v;
     ++l->p_libre;
}

int extraer(tipo_lista *l, int p){
    int i,v;
    if (p > l->p_libre || p < 1){
        printf("Error: posición fuera de lista\n");
        return 0;
    }
    v = l->valores[p-1];
    for(i=p-1; i<l->p_libre-1; i++)
               l->valores[i] = l->valores[i+1];
    --l->p_libre;
    return v;
}

void inicializar(tipo_lista *l){
     l->p_libre = 0;
     }
     
int buscar(tipo_lista *l,int valor){
     int i = 0;
     for (;l->p_libre>=0;(l->p_libre)--){
         i++;
         if (l->valores[l->p_libre] == valor) return i;
     }
     return -1;
}     
int main()
{
       tipo_lista *lista = (tipo_lista*)malloc(sizeof(tipo_lista));  
       
       inicializar(lista);

      //Apilar
     insertar(lista,7,1);
     insertar(lista,2,2);
     insertar(lista,4,2);
     printf("%i ",lista->valores[0]);
     printf("%i ",lista->valores[1]);
     printf("%i \n",lista->valores[2]);
     
     //Buscar
     printf("Num. operaciones: %i \n",buscar(lista,2));
     
     
      //Desapilar
      /*
      extraer(lista,3);
      */
      system("PAUSE");
      return 0;
}
