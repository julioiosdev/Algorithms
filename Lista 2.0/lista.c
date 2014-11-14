/* Implementación tipo de datos LISTA dinámica de datos */

/* Características generales:
 	 	 - Lista dinámica simplemente enlazada SIN nodo cabecera.
 	 	 - Los punteros apuntan realmente al elemento que se está referenciando.
 	 	 - Cuando se inserta un elemento en una posición, el nuevo pasa a ocupar dicha posición.
 	 	 - El tipo de la lista viene definido por el tipo de elemento que contiene, todas las
 	 	 funciones son independientes del tipo de elemento excepto:
 	 	 	 	 	 l_int_elemento.
 	 	 - Las posiciones en la lista se numeran desde la posición 0.
 	 	 - Es necesario declarar:
 	 	 	 	 - stdlib.h (malloc, free)
 	 	 	 	 - assert.h (assert)			*/
/* Sin definir #define NDEBUG, versión DEPURACION */

#include <stdlib.h>
#include <assert.h>
#include "lista.h"

struct cabeza {
	int longitud;				// Almacena el número de elementos de la lista
	struct nodo *primero;		// Puntero al primer elemento de la lista
	struct nodo *ultimo;		// Puntero al último elemento de la lista
};

struct nodo {
	int elemento;
	struct nodo *psig;
};

struct cabeza* l_int_crear(void)
{
	struct cabeza *paux;		/* Creamos un puntero que sera como el nodo cabecera, esto es creamos el nodo cabecera */

	if ( (paux = malloc(sizeof(struct cabeza)) ) != NULL){ //pedimos memoria y nos aseguramos de que alla
		paux->longitud = 0; //al crear el nodo cabecera inicializamos longitud
		paux->primero = NULL;//inicializamos primero aciendo que el puntero primero apunte a NULL
		paux->ultimo = NULL;//igual pero con el puntero ultimo
	}
	else {
		return NULL;
	}
	assert (paux != NULL);
	return paux;//devolvemos el nodo cabecera
}

int l_int_anadir(Lista l, int n)
{
	struct nodo *paux; //creamos un puntero que tendra los campos de nodo

	assert (l != NULL);
	if ( (paux = malloc(sizeof (struct nodo)) ) != NULL) { //pedimos memoria asegurandonos de que alla
		paux->psig= NULL; //ponemos al puntero psig apuntando a NULL
		paux->elemento =n;//metemos el numero
		l->longitud++;//como hemos añadido un nodo incrementamos longitud
		if (l->ultimo == NULL) {	// Si la lista está vacía no hay que enlazar nodos...
			l->primero = paux; //ponemos al primero y al ultimo apuntando a la misma estructura.
			l->ultimo = paux;
		}
		else {						// si no, enlazamos el último nodo
			l->ultimo->psig = paux; //establecemos la relacion entre el ultimo elemento y el que acabamos de crear
			l->ultimo = paux; //ponemos a ultimo apuntando a paux que sera el nuevo ultimo elemento
		}
	}
	else
			return -1;

	return 0;
}

int l_int_insertar(Lista l, int pos, int n)
{
	struct nodo *pant;
	struct nodo *paux;
	int i;
	int creado;

	assert (l != NULL);
	if (pos >= l->longitud) { 	// En este caso estamos añadiendo a la lista ya que el usuario quiere insertarlo al final de la lista
		creado = l_int_anadir(l, n); //en ese caso llamamos a la funcion añaidir, para que lo haga esa funcion
		if (creado == -1)
			return -1;
	}
	else {
		pant = l->primero;
		for (i = 0; i < pos - 1; i++)	// Recuperamos el puntero a la anterior posición a insertar
			pant = pant->psig;
			
		if ( (paux = malloc(sizeof (struct nodo)) ) != NULL) {//pedimos memoria asegurandonos de que alla
			if (pos==0) {	// Estamos insertando al principio
			    paux->elemento = n;
				paux->psig = pant;//ponemos apuntando nuestra estructura a pant
				l->primero=paux;//ponemos a primero aountando a paux
                l->longitud++;}
			else{
            
            paux->elemento = n; //metemos el elemento
			paux->psig = pant->psig;//ponemos a paux apuntando donde apunta pant
			pant->psig = paux;//y ponemos a pant apuntando a paux, asi establecemos todas las conexiones
        	l->longitud++;}
		}
		else
			return -1;
	}
	return 0;
}

int l_int_longitud(Lista l)
{
	assert (l != NULL);
	return l->longitud ;//simplemente devolvemos longitud
}

int l_int_encontrar(Lista l, int n)
{
	struct nodo* paux;
	int i;
	int encontrado;

	assert (l != NULL);

	if (l->primero == NULL)		// La lista está vacía
		return -1;

	paux = l->primero;
	encontrado = 0;
	i = 0;

	while (paux != NULL) { //recorremos la lista completa
		if (paux->elemento == n) {
			encontrado = 1;
			break;
		}
		paux = paux->psig;
		i++; //esto nos marcara la posicion
	}
	if (encontrado)
		return i;//devolvemos la posicion
	else
		return -1;
}

int l_int_elemento(Lista l, int pos)
{
	struct nodo *paux;
	int i;

	assert (l != NULL);
	// Si la posicion es mayor que el número de elementos se devuelve el último
	if (pos >= l->longitud - 1)
		return l->ultimo->elemento;
	else {
		paux = l->primero;
		for (i = 0; i < pos; i++)//recorremoa la lista hasta la posicion poniendo un puntero en la posicion marcada
			paux = paux->psig;
	}
	return paux->elemento;//devolvemos el elemento que tenmemos en el puntero que hemos puesto
}

void l_int_borrar(Lista l, int pos)
{

    struct nodo *anterior;
    struct nodo *siguiente;
    struct nodo *central;
    int i;
    
    anterior = l->primero;
    
    
    if (pos<=0){ //si quiere eliminar la posicion 0
         l->primero=l->primero->psig; //la parte de l primero sera igual a la parte psig de primero de l, corremos primero un lugar
         free(anterior);//eliminamos anterior que lo teniamos apuntando donde estaba primero
         l->longitud--;}
       
    else if (pos>=l->longitud-1){
         
         while(anterior->psig !=NULL) //Mientras no lleguemos a NULL pasamos a la siguiente estructura
             anterior = anterior->psig;//y nos situamos en la penultima estructura
                                                          
         l->ultimo=anterior; //ultimo sera igual a anterior, asi lo colocamos en la penultimo posicion   
         anterior=anterior->psig; //ponemos en la ultima poscion anterior     
         free(anterior);        //eliminamos anterior      
         l->longitud--;                                
     }                                

             else {
   

   		        for (i = 0; i < pos-1; i++) //recorremos toda la lista hasta encontrar la posicion anteior al elemento a eliminar
   			        anterior = anterior->psig;

                central=anterior->psig;   //ponemos un puntero en el elemento a eliminar
   
                siguiente=anterior->psig->psig;//ponemos un puntero en el elemento siguiente al que hay que eliminar
                anterior->psig=siguiente; //decimos que la parte psig de anterior va a ser igual al puntero siguiente,
                // psig de anterior apuntara a siguiente
   
                free(central);
                l->longitud--;
             }
   
}
    
void l_int_destruir(Lista l)
{    
     struct nodo *pborra;
     struct nodo *paux;
     paux=l->primero;

     do{ //con esta funcion ponemos dos punteros que recorreran la lista uno detras del otro
            pborra=paux;//el de detras se ira eliminando mientras el de  delante sigue a la siguiente posicion
            paux=paux->psig;
            assert(pborra !=NULL);
            free(pborra);
            
            } while (paux!=NULL);//y lo haran mientras no tremine la lista
            free(l);
}

