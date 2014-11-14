#ifndef _PracticaAlgoritmia_H_ //si no está definido (se pone siempre)
#define _PracticaAlgoritmia_H_//lo definimos

#include <cstdlib>
#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <sys/timeb.h> 
#include <math.h>


#define ORDENADO 0
#define DESORDENADO 1
#define ALEATORIO 1
#define NOALEATORIO 0


#define MAX_ELEMS 1000000

///cabeceras de los metoddos y structuras usados en la practica
using namespace std;

////////////////////////////////////////////////////////////////////////////////
////////////////estructuras de arbol y de lista/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//estructura para guardar los ids en el arbol
typedef struct listaInt{ 
        int p_libre; 
        int valores[MAX_ELEMS];   
}tipo_listaInt, *p_tipo_lista_int;

//estructura para el arbol
typedef struct nodo_arbol{ //estructura arbol
        int valor;
        p_tipo_lista_int list;
        struct nodo_arbol *izq;
        struct nodo_arbol *der;
        } *p_nodo_arbol; 


/////////////////////////////////////////////////////////////////////////////// 
///////////estructura para guardar los alumnos en la lista/////////////////////
///////////////////////////////////////////////////////////////////////////////
//estructura para guardar alumnos

typedef struct pila{
    int cima;
    int valores[MAX_ELEMS];
}*p_tipo_pila;


typedef struct Alumnos{ 
        char nombre[20];
        char dni[9];
        int edad;
        int notaMedia;
        }alum;
        
        
//lista principal que contiene los alumnos
typedef struct lista{ //estructura que contiene estructura con datos de alumnos
        int p_libre; 
        p_tipo_pila pila;
        Alumnos alumno[MAX_ELEMS];      
}tipo_lista, *p_tipo_lista;


typedef struct principal
{
        p_nodo_arbol arbolAlfabetico, arbolEdad;
        p_tipo_lista lista;      
}tipo_principal, *p_principal;

////////////////////////////////////////////////////////////////////////////////
///////////////////funciones usadas en la practica//////////////////////////////
////////////////////////////////////////////////////////////////////////////////

//arboles
p_nodo_arbol insertarArbol (p_nodo_arbol arbol, int i, int id);     //inserta un nodo en el arbol             
p_nodo_arbol insertarArbolOrdenado (p_nodo_arbol arbol, int i, int id, p_tipo_lista lista); //inserta los Ids ordenados en el arbol
p_nodo_arbol borraNodo(p_nodo_arbol nodo);                          //elimina un nodo del arbol
p_nodo_arbol eliminarNodoArbol (p_nodo_arbol arbol, int numero, int id);//borra un id del arbol si no hay Ids elimina el nodo
p_nodo_arbol buscarNodo(p_nodo_arbol arbol, int edad);               //busca y retorna el nodo     
void simetrico(p_nodo_arbol arbol, int vector[], int *i);//recorre el arbol de menor a mayor, sirve para borrar el arbol
p_nodo_arbol eliminarArbol (p_nodo_arbol arbol, int numero); //elimina los nodos con el valor paado del arbol sin importar los Ids que tenga
void ordenarArbolMezcla(p_principal principal, p_nodo_arbol arbol); //ordena el arbol por mezcla
void ordenarArbolBurbuja(p_principal principal, p_nodo_arbol arbol);//ordena el arbol por burbuja
     

//lista de enteros, lista que se encuentra en los nodos de los arboles para guardar los Ids de la lista principal
void insertarListaInt(p_tipo_lista_int lista, int posicion,int id); //inserta los IDs en la lista
void insertarListaIntOrdenado(p_tipo_lista listaPrincipal, p_tipo_lista_int lista, int posicion,int id); //inserta los Ids en la lista ordenados
int eliminarIdLista(p_tipo_lista_int lista, int id); //elimina id de la lista
p_tipo_lista_int crearListaInt(); //crea la lista
void burbuja(p_tipo_lista lista, int v[], int tamanio) ; //ordena por burbuja los Ids de la lista
void ordenMezcla(p_tipo_lista lista, int vector[], int inicio,int tamanio ); //ordena la lista Ids por mezcla recursiva tomando como referencia los nombre de la lista principal
void mezclar (p_tipo_lista lista, int vector[], int inicio, int tamA, int tamB);//mezcla "fusiona" de menor a mayor el vector con las posiciones pasadas
void copiarLista (p_tipo_lista_int lista, p_tipo_lista_int listaCopia);



//lista principal con los alumnos
p_tipo_lista crear();  //crea la lista alumnos
void visualizarLista(p_tipo_lista lista);  //metodo de prueba para visualizar la lista de alumnos
int insertarLista(p_tipo_lista lista, int posicion, char nombre[], char dni[], int edad, int notaMedia); //inserta un alumno en la lista devuelve la posicion donde lo inserto, esto es por si hay posiciones vacias lo inserta ahi
void eliminarLista(p_tipo_lista  lista, int posicion); //elimina un alumno de la lista "es un borrado logico", lo que hace es guardar la posicion en un vector de vacios e incrementar contador de vacios

//funciones de la pila para guardar las posiciones vacias de la lista alumnos
p_tipo_pila crearPila(); //crea una pila
int pop(p_tipo_pila pila); //devuelve el valor del ultimo elemento insertado en la pila
bool vaciar(p_tipo_pila pila); //vacia la pila "no se utiliza"
int push(p_tipo_pila pila, int numero); //inserta en la pila un valor
bool esVaciaPila(p_tipo_pila pila); //comprueba si la pila esta vacia


////////////////////////////////////////////////////////////////////////////////////
///////////////////////////funciones de la practica/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

//imprime en orden de edad odo el abol con sus correspondientes entradas en la tabla
void imprimir_orden_edad(p_tipo_lista  lista, p_nodo_arbol arbol);

//imprime en orden alfabetico todo el abol sus correspondientes entradas en la tabla
void imprimir_orden_alfabetico(p_tipo_lista lista, p_nodo_arbol Arbol);

//imprime los alumnos con una edad dada que se encuentren en la lista 
void imprimir_edad_dada(p_tipo_lista lista, p_nodo_arbol arbol, int edad);

//imprime los alumnos por el comienzo del nombre por una letra dada que se encuentren en la lista 
void imprimir_letra_dada(p_tipo_lista lista, p_nodo_arbol arbol, char letra);

//elimina de los arboles el alumno con el dni dado
int eliminar (p_principal principal, char dni[]);

//inicia los arboles y la lista
p_principal incializarIndice();

//inserta en la lista y los arboles un alumno
void insertar (p_principal principal, char nombre[], char dni[], int edad, int notaMedia, int orden );

//imprime los alumnos cuyos ids se encuentren en el vector v
void imprimir (p_tipo_lista lista, int v[],int tamanio) ; 

//meu con las diferentes opciones de la practica
void menu(p_principal principal);

//metodo para imprimir en orden burbuja muestra el tiempo, copia la lista y llama a burbuja
void imprimirOrdenBurbuja(p_principal principal);
//metodo para imprimir en orden de Mezcla muestra el tiempo, copia la lista y llama a ordenMezcla
void imprimirOrdenMezcla(p_principal principal);
//vacia las listas para hacer la estrategias 1 , 2 y 3
void vaciarListas(p_principal principal);

//inserta aleatoriamente alumnos con un orden establecido en orden (DESORDENADO/ORDENADO) y una edad aleatoria o fija y el numero de alumnos indicados 
void insertarMasivo(p_principal principal,int orden, int edad, int muestras);

//devuelve la posicion en la lista del alumno con el dni introducido o -1 si no existe, se usa para comprobaciones a la hora de insertar alumnos
int posicionAlumno(p_tipo_lista lista,char dni[]);


#endif
