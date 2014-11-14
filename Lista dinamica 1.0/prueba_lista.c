#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int main (int argc,char** argv){
    Lista a;
    Posicion cl;
    int conta;
    
    a= l_int_crear();
    if (a==NULL){
                 perror("Error al crear la lista");
                 exit(-1);
    
     }
     cl=l_int_primero(a);
     printf("Insertando los numeros(del 0 al 10): ");
     for(conta=0;conta<=9;conta++){
                                    printf("%d ",conta);
                                    l_int_insertar(a,cl,conta);
                                    cl=l_int_siguiente(a,cl);
     }
     
     printf("\n");
   
     printf("Sacamos los numeros de la lista(en orden):");
     cl=l_int_primero(a);
     for(conta=0;conta<l_int_longitud(a);conta++){
                                                  printf("%d ",l_int_elemento(a,cl));
                                                  cl=l_int_siguiente(a,cl);
     }
     printf("\n");
   
      
     //------------------------------------------------------------------
     printf("\n Sacamos los numeros de la lista(al reves):");
     cl=l_int_ultimo(a);
     for(conta=0;conta<l_int_longitud(a);conta++){
                                                  cl=l_int_anterior(a,cl);//El ultimo elemento es NULL
                                                  printf("%d ",l_int_elemento(a,cl));
                                                  }
                                                  
    //-----------------------------------------------------------------
    printf("\n");
    printf("\n");
    printf("Vamos a eliminar el elemnto 5 de la lista queda:");
    cl=l_int_localizar(a,5);
    l_int_borrar(a,cl);
    cl=l_int_primero(a);
    for(conta=0;conta<l_int_longitud(a);conta++){
                                                 printf("%d ",l_int_elemento(a,cl));
                                                 cl=l_int_siguiente(a,cl);
}
printf("\n");
//----------------------------------------------------------------------------
printf("Borramos\n");
l_int_destruir(a);
getche();
return(EXIT_SUCCESS);
}
     
