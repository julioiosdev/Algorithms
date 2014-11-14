#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>


int busqueda_binaria_1(int v[], int nelem, int valor){
    int superior, inferior, medio;
    superior = nelem - 1;
    inferior = 0;
    printf("\n     ---- Busqueda binaria 1 valor: %i ---- \n",valor);
    while (inferior < superior){
    
          medio = (inferior + superior) / 2;
          printf("      Inferior: %i, medio: %i, superior: %i\n",inferior,medio,superior);
          
          if (valor > v[medio])
             inferior = medio + 1;
          else
             superior = medio;
    }
    printf("     ------------------------------------\n");
    return ((v[superior]==valor)?superior:-1);
}

int busqueda_binaria_2(int v[], int nelem,int valor){
    int superior, inferior, medio;
    superior = nelem - 1;
    inferior = 0;
    printf("\n     ---- Busqueda binaria 2 valor: %i ---- \n",valor);
    while (inferior <= superior){
    
          medio = (inferior + superior)/2;
          printf("      Inferior: %i, medio: %i, superior: %i\n",inferior,medio,superior);
          
          if (valor < v[medio])
             superior = medio - 1;
          else if (valor > v[medio])
             inferior = medio + 1;
          else {
             printf("     ------------------------------------\n");
             return medio;
          }
    }
    printf("     ------------------------------------\n");
    return -1;
}

int busqueda_a_tres_1(int v[], int nelem,int valor){
    int superior, inferior, m1, m2;
    superior = nelem - 1;
    inferior = 0;
    printf("\n     ---- Busqueda a tres 1 valor: %i ---- \n",valor);  
    while (inferior < superior){
    
          m1 = ((inferior + superior)/3);   
          m2 = ((inferior + superior * 2)/3);
          printf("      Inferior: %i, m1: %i, m2: %i, superior: %i\n",inferior,m1,m2,superior);
          
          if (v[m1] > valor)
             superior = m1-1;
          else if (v[m2] < valor)
             inferior = m2+1;
          else {
             inferior = m1;
             superior = m2;
           }
    }
    printf("     ------------------------------------\n");
    return ((v[superior]==valor)?superior:-1); //Si v[superior] = valor entonces devuelve superior
                                               // si no devuelve -1       
}

int busqueda_a_tres_2(int v[], int nelem,int valor){
    int superior, inferior, m1, m2;
    superior = nelem - 1;
    inferior = 0;
    printf("\n     ---- Busqueda a tres 2 valor: %i ---- \n",valor);  
    while (inferior <= superior){
    
          m1 = ((inferior + superior)/3);   
          m2 = ((inferior + superior * 2)/3);
          printf("      Inferior: %i, m1: %i, m2: %i, superior: %i\n",inferior,m1,m2,superior);
          
          if (v[m1] == valor) {
             printf("     -----------------------------------\n");
             return m1;
          }
          else if (v[m2] == valor) {
             printf("     ------------------------------------\n");
             return m2;
          }

          if (v[m1] > valor)
             superior = m1-1;
          else if (v[m2] < valor)
             inferior = m2+1;
          else {
             inferior = m1;
             superior = m2;
           }
    }
    printf("     ------------------------------------\n");
    return -1;
    
}
    
int main()
{
    int v[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int nelem = 15;

    //Busqueda 1
    printf("\nBusqueda con busqueda_binaria_1. Posicion: %i\n",busqueda_binaria_1(v,nelem,4));
       
    //Busqueda 2
    printf("\nBusqueda con busqueda_binaria_2. Posicion: %i\n",busqueda_binaria_2(v,nelem,4));
    
    //Busqueda 3
    printf("\nBusqueda con busqueda_a_tres_1. Posicion: %i\n",busqueda_a_tres_1(v,nelem,4));
    
    //Busqueda 4
    printf("\nBusqueda con busqueda_a_tres_2. Posicion: %i\n",busqueda_a_tres_2(v,nelem,4));
    
    printf("\n");

    system("PAUSE");
    return 0;
}
