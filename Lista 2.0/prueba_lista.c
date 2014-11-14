#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main( int argc, char** argv)
{
    
	Lista a;
	int i;
	int pos;

	a = l_int_crear();
	if (a== NULL) {
		perror("Error al crear la lista");
		exit (-1);
	}
	printf("Insertando los números del 0 al 19: ");
	printf("\n");
	for (i = 0; i < 20; i++) {
		printf("%d ", i);
		l_int_anadir(a, i);
	}
	printf("\n");
	printf("\n");
/*-------------------------------------------------------------------------------------*/
	printf("La lista contiene %d números \n", l_int_longitud(a));
/*-------------------------------------------------------------------------------------*/
printf("\n");
printf("Sacamos los numeros de la lista (en orden):");
printf("\n");
for(i=0; i<l_int_longitud(a); i++){
         printf("%d ",l_int_elemento(a,i));
         }
printf("\n");
printf("\n");
/*-------------------------------------------------------------------------------------*/
printf("\nSacamos los numeros de la lista (en orden inverso):");
printf("\n");
for(i=l_int_longitud(a) -2;i>=0;i--){
                        printf("%d ",l_int_elemento(a,i));
}
printf("\n");
/*-------------------------------------------------------------------------------------*/
printf("\nSacamos el numero de la posicion 1000 (no existe)");
printf("%d ",l_int_elemento(a,1000));
/*-------------------------------------------------------------------------------------*/
pos=l_int_encontrar(a,8);
printf("\n");
printf("\nEl numero 8 se encuentra en la posicion: %d\n",pos);
pos=l_int_encontrar(a,200);
if(pos==-1)
printf("\nNo se encuentra el numero 200\n");

/*-------------------------------------------------------------------------------------*/
printf("\nVamos a insertar un numero:");
l_int_insertar(a, 0, 87);
for(i=0; i<l_int_longitud(a); i++){
         printf("%d ",l_int_elemento(a,i));
         }
printf("\n");
/*-------------------------------------------------------------------------------------*/
printf("\nVamos a borrar de la lista la posicion 8, la lista queda:");

l_int_borrar(a, 8);
for(i=0; i<l_int_longitud(a); i++){
         printf("%d ",l_int_elemento(a,i));
         }
printf("\n");

/*-------------------------------------------------------------------------------------*/
printf("\n Borramos la lista siguiente \n ");
l_int_destruir(a);
printf("\nLista borrado ");
//¿Hay alguna forma de comprobar que hemos liberado la memoria?
//como ejercicio

getche();
return EXIT_SUCCESS;
         


	
}

