#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{


Tlista l=inicializar(l);



1 a y b
void insertar_examen(Tlista l, int i, int *error) {
     error = 0;
     // Si la lista está llena devuelve error = 1.
     if ((lista_llena(l))==true) { 
        error = 1;
        return;
     }
     // Si hay menos de 10 elementos se inserta al final.
     if (l->p_libre<10) {
        l->valores[l->p_libre]=i;
        l->p_libre++;
        return;
     }
     if (l->p_libre>=10) {
        // Si es menor que 50 inserta al principio.
        if (i<50) {
           int p_libre_aux=p_libre;
           // Mueve todos los elementos una posición hacia adelante.
           while (l->p_libre>0) {
               l->valores[l->p_libre]=l->valores[--l->p_libre];
               l->p_libre--;
           }
           // Coloca "i" en la primera posición
           l->valores[l->p_libre]=i;
           // Vuelve a colocar la posición libre como la que corresponde.
           p_libre=++p_libre_aux;
        }
        else {
           // Necesitamos dos variables auxiliares que apuntan a p_libre
           int p_libre_siguiente, p_libre_aux;
           p_libre_siguiente=p_libre_aux=l->p_libre;
           // Buscamos la posición donde se colocará el nuevo número.
           while (l->p_libre>0) {
               if ((l->valores[--l->p_libre])>i) {
                  l->p_libre--;
               }
           }
           // Una vez encontrada movemos todos los números una posición hacia adelante.
           while (p_libre_aux>l->p_libre) {
               l->valores[p_libre_aux]=l->valores[--p_libre_aux];
               p_libre_aux--;
           }
           // Por último insertamos el número en la posición correcta y actualizamos
           // la posición libre.
           l->valores[p_libre_aux]=i;
           l->p_libre=++p_libre_siguiente;
           return;
        }
     }     
   }







//este algoritmo no contempla que los mayores de 50 se inserten en orden
void insertar_examen (TLista l, int i, int *error)
{

int posicion=0;

	if (lista_llena(l)==true) //comprobamos si lista llena
		{
		printf("Lista llena \n");
		*error=1;
		return error;
		}


	if (l->p_libre<10) //si es menor que 10
		{
		posicion=l->p_libre; //posicion libre normal
		}
	else
		{
		if (i<50) { posicion=0; }
			else {posicion=l->p_libre; }
		}

	
 //si es entre 0 y 9 o >= de 50 no hace el for
	for (int i=lista->p_libre; i>=posicion; i--)
		lista->valores[i]=lista->valores[i-1];
		lista->valores[posicion]=numero; //insercion normal
		lista->p_libre++;  } //insercion normal

}




1 c
   int cantidad_ocurrencias(TLista l, int i) {
       if (esta_en(l)==false) { return 0; }
       int j;
       int contador=0;
       for (j=0;j<l->p_libre;j++) {
           if (l->valores[j]==i) { contador++; }
       }
       return contador;
   }



int cantidad_ocurrencias (TLista l, int i)
{
	int ocurrencias=0;
	int numero=i;
	if ((esta_en(l,i))==true)
	{
		for (i=0; i<l->p_libre; i++)
		{
			if (l->valores[i]==numero) {
			ocurrencias++;
			}
		}
	}
	return ocurrencias;

}








void insertar_examen (tipo_lista *lista, int i, int *error)
{

int posicion=0;
int numero=i;
int p_libre_aux=lista->p_libre;

/*	if (lista_llena(l)==true) //comprobamos si lista llena
		{
		printf("Lista llena \n");
		*error=1;
		return error;
		}

*/
	if (lista->p_libre<10) //si es menor que 10
		{
		posicion=lista->p_libre; //posicion libre normal
		lista->valores[posicion]=numero; 
		lista->p_libre++;   
		}
	else
		{
			if (numero<50) { //si es menor que 50 insercion al principio
				posicion=0;//con el for muevo todos los numeros a la derecha
					for (int i=lista->p_libre; i>posicion; i--)
						lista->valores[i]=lista->valores[i-1];
					lista->valores[posicion]=numero; //insercion normal
					lista->p_libre++;   
			}
			if (numero>=50) { //si es mayor o igual a 50
				 //busco la posicion donde va el num
				for (int j=lista->p_libre; j>0; j--)
				{
				if (lista->valores[j-1]>numero) { p_libre_aux--;  }
				} //muevo todos los valores a la derecha desde esa posicion
					for (int k=lista->p_libre; k>p_libre_aux; k--)
							lista->valores[k]=lista->valores[k-1];
					lista->valores[p_libre_aux]=numero;//inserto en posicion
					lista->p_libre++;
			}
		}



}
