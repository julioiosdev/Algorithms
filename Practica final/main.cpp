//==============================================================================
// ALGORITMIA: TRABAJO FINAL  -  03/06/2012
//
// GRADO EN INGENIERÍA INFORMÁTICA       
// CURSO: 2011/2012
//==============================================================================
//
// REALIZADO POR:
//
// JOSE CLAUDIO CALDERÓN ARGÜESO    -  23058706X
// RUBEN GARCÍA DE LAS BAYONAS ROS  -  23056635D
// CARLOS BUTRÓN GÓMEZ              -  48351184D
//
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOMBRE 50
#define MAX_DNI 9
#define  Entero_A_Caracter(entero) entero+0x30

//==============================================================================
//                         ESTRUCTURAS DE DATOS
//==============================================================================

//================================//
//      LISTA DE DATOS (A)        //
//===============================//
// Estructura de la lista principal (A) con todos los datos.
typedef struct lista_Principal {
        unsigned int id;
        char nombre[MAX_NOMBRE];
        char dni[MAX_DNI];
        unsigned short edad;
        float nota_media;
        struct lista_Principal *anterior;
        struct lista_Principal *siguiente;
} tipo_lista_principal, *listaprincipal;
// Estructura de la celda de control para la lista principal (A).
typedef struct celdaControlPrincipal {
        unsigned int cantidad;
        struct lista_Principal *cabeza;
        struct lista_Principal *cola;
} tipo_celda_control_principal, *celdacontrolprincipal;


//=================================//
//      LISTA DE ÍNDICES INTERNA   //
//      A LOS ÁRBOLES ÍNDICE      //
//================================//
// Estructura de las listas internas a los índices que guardan la id
// de cada una de las personas que contiene.
typedef struct lista_Indices {
        struct lista_Principal *id;
        struct lista_Indices *anterior;
        struct lista_Indices *siguiente;
} tipo_lista_indices, *listaindices;
// Estructura de las celdas de control para las listas de índices.
typedef struct celda_Control {
        unsigned int cantidad;
        struct lista_Indices *cabeza;
        struct lista_Indices *cola;
} tipo_celda_control, *celdacontrollistaindices;



//================================//
//      ÍNDICE POR NOMBRE         //
//===============================//
// Árbol índice por nombre. Ordenados alfabéticamente por la primera letra.
typedef struct indice_Nombre {
        char primeraletra;
        struct celda_Control *indice; // Lista que contiene las ids de los alumnos
        struct indice_Nombre *izq;
        struct indice_Nombre *der;
} tipo_indice_nombre, *indicenombre;


//===============================//
//      ÍNDICE POR EDAD          //
//==============================//
// Árbol índice por edad. Menores a la izquerda, mayores a la derecha.
typedef struct indice_Edad {
        unsigned short edad;
        struct celda_Control *indice; // Lista que contiene las ids de los alumnos
        struct indice_Edad   *izq;
        struct indice_Edad   *der;
} tipo_indice_edad, *indiceedad;
//==============================================================================






//==============================================================================
//                      DECLARACIÓN DE FUNCIONES
//==============================================================================
//=============================//
//      INICIALIZACIÓN         //
//============================//
// Funciones de inicialización para la lista principal y los índices, así como
// de las listas internas a cada uno de los índices.
void inicializar(celdacontrolprincipal A, indicenombre B, indiceedad C); // Inicializa los valores de todos los atributos de las estructuras.
listaprincipal inicializarListaPrincipal(); // Lista principal con todos los datos de los alumnos.
celdacontrollistaindices inicializarCeldaControlListaIndices(); // Celda de control para las listas internas a los árboles.
listaindices inicializarListaIndices(); // Listas internas a los árboles que guardan punteros a los alumnos de la lista principal.


//=============================//
//      INSERCCIÓN             //
//============================//
// Insercción de un nuevo elemento en la lista principal y actualización de los
// índices, añadiendo la id del nuevo alumno en la lista del nodo correspondiente.
int insertarNuevoElemento(celdacontrolprincipal A, indicenombre B, indiceedad C, char nombre[MAX_NOMBRE], char dni[MAX_DNI], unsigned short edad, float nota_media, bool ordenado); // Inserta un nuevo alumno con los datos dados.
indicenombre insertarIndiceNombre(indicenombre B, char primeraletra, listaprincipal A, bool ordenado); // Inserta en el árbol índice por nombre o actualiza en caso de que ya existiera un nodo con esa letra.
indiceedad insertarIndiceEdad(indiceedad C, int edad, listaprincipal A, bool ordenado); // Inserta en el árbol índice por edad o actualiza en caso de que ya existiera un nodo con esa edad.
celdacontrollistaindices insertarListaIndices(celdacontrollistaindices ind, listaprincipal A, bool ordenado); // Inserta en la lista interna de cada árbol un nuevo elemento que apunta al nuevo alumno. Se puede elegir insercción "Ordenada o "Desordenada"


//=============================//
//      ELIMINACIÓN            //
//============================//
// Eliminación de un elemento existente en la lista principal y actualización de
// los índices, borrando la id del alumno eliminado de la lista del nodo correspondiente.
int eliminarElemento(celdacontrolprincipal A, indicenombre B, indiceedad C, char dni[MAX_DNI]); // Elimina un alumno. En caso de ser el único que queda, vuelve a inicializar listas y árboles.
listaprincipal encontrarElementoPorDNI(listaprincipal A, char dni[MAX_DNI]); // Busca un elemento en la lista principal por id. En caso de encontrarlo lo devuelve.
indicenombre actualizarIndiceNombre(indicenombre B, char primeraletra, unsigned int id); // Actualiza el árbol índice por nombre. En caso de no haber mas alumnos con la misma letra elimina el nodo.
indiceedad actualizarIndiceEdad(indiceedad C, unsigned short edad, unsigned int id); // Actualiza el árbol índice por edad. En caso de no haber mas alumnos con la misma edad elimina el nodo.
void actualizarListaIndices(celdacontrollistaindices control, unsigned int id); // Actualiza la lista interna a los árboles índice borrando el alumno con id igual al que se desea eliminar.
listaindices encontrarEnListaIndicesPorId(celdacontrollistaindices control, unsigned int id); // Encuentra en una lista interna a los árboles índice un alumno con la id que se le pase como parámetro.


//=============================//
//      IMPRESIÓN DE DATOS     //
//         POR PANTALLA        //
//============================//
void imprimirLetraDada(indicenombre B, char primeraletra); // Muestra todos los alumnos cuyo nombre empieza por la letra dada.
indicenombre encontrarNodoLetra(indicenombre B, char primeraletra); // Busca en el árbol índice por nombre (B) el nodo con la letra dada.
void imprimirOrdenAlfabetico(indicenombre B); // Muestra todos los alumnos ordenados alfabéticamente.
void imprimirEdadDada(indiceedad C, unsigned short edad); // Muestra todos los alumnos cuya edad sea la edad dada.
indiceedad encontrarNodoEdad(indiceedad C, unsigned short edad); // Busca en el árbol índice por edad (C) el nodo con la edad dada.
void imprimirOrdenEdad(indiceedad C); // Muestra todos los alumnos ordenados por edad.


//===================================//
//    IMPRESIÓN DE TODOS LOS         //
//    ELEMENTOSDE LISTA PDINCIPAL.   //
//===================================//
// Muestra por pantalla todos los elementos de la lista principal.
void mostrarElementosMatriz(celdacontrolprincipal A);


//==============================//
//    CANTIDAD DE ELEMENTOS     // 
//    EN LISTA PRINCIPAL       //
//=============================//
// Nos dice la cantidad de elementos que hay en la lista principal.
int cantidadElementos(celdacontrolprincipal A);


//=================================//
//     VACIAR (REINICIALIZAR)      //
//     LISTA PRINCIPAL E ÍNDICES   //
//     LIBERANDO MEMORIA          //
//===============================//
// Vacía la lista principal y libera todos los nodos para no dejar datos sin
// usar en la memoria.
int vaciarMatriz(celdacontrolprincipal A, indicenombre B, indiceedad C);
void vaciarIndiceNombre(indicenombre B);
void vaciarIndiceEdad(indiceedad C);


//==================================//
//          ESTADÍSTICA             //
//=================================//
int insertar500Alumnos(celdacontrolprincipal A, indicenombre B, indiceedad C, bool ordenado); // Inserta 500 alumnos nuevos, pudiendo elegir si queremos hacerlo de manera ordenada o desordenada.
void burbuja_mejorada (celdacontrollistaindices control, unsigned int cantidad); // Ordena con burbuja mejorada la lista de alumnos interna a los árboles índice.

//==============================================================================






//==============================================================================
//                       PROGRAMA PRINCIPAL (MAIN)
//==============================================================================
int main() {
    // Creamos la lista principal y los índices. Luego los inicializamos.
    tipo_celda_control_principal A;
    tipo_indice_nombre B;
    tipo_indice_edad C;
    /*
    celdacontrolprincipal A;
    indicenombre B;
    indiceedad C;
    */
    inicializar(&A, &B, &C);
    
    char nombre[MAX_NOMBRE]={0};
    char dni[MAX_DNI]={0};
    int edad=0;
    float nota_media=0;
    int comprobar=0;
    float inicio, fin;
    
    // Comienza el bucle del programa principal, que nos pregunta la acción
    // que deseamos realizar.
    int op=0; 
    do{
       system("CLS");
       fflush(stdout);
       printf(" -------------------\n");
       printf("|** TRABAJO FINAL **|\n");
       printf(" -------------------\n");
       printf("1.  Insertar nuevo alumno en la lista principal.       (Desordenado)\n");
       printf("2.  Insertar nuevo alumno en la lista principal.       (Ordenado)\n");
       printf("3.  Insertar 500 alumnos (nombre \"A\", edad 20).        (Ordenado/Desordenado)\n");       
       printf("4.  Eliminar alumno (lista principal e \xA1ndices).\n");
       printf("5.  Mostrar alumnos por la letra dada.                 (ID desordenada)\n");
       printf("6.  Mostrar todos los alumnos por orden alfab\x82tico.    (ID desordenada)\n");
       printf("7.  Mostrar alumnos por la edad dada.                  (ID desordenada)\n");
       printf("8.  Mostrar todos los alumnos por orden de edad.       (Ordena IDs con burbuja)\n");       
       printf("9.  Mostrar todos los alumnos de la lista principal.\n");
       printf("10. \xA8 Cuantos alumnos hay en la lista principal ?\n");
       printf("11. Vaciar lista principal e \xA1ndices.\n");
       printf("12. Salir.\n");
       printf("\n");  
       printf("Selecciona una opci\xA2n: ");
       scanf("%d",&op);
       switch(op){
                  case 1:
                       printf("\n"); 
                       printf("Introduzca nombre (max. %d caracteres): ",MAX_NOMBRE);
                       scanf(" %[^\n]",nombre);
                          
                       printf("Introduzca DNI (%d caracteres): ",MAX_DNI);                    
                       scanf("%s",dni); 
                                              
                       printf("Introduzca edad: ");
                       scanf("%d",&edad);                      
                       
                       printf("Introduzca nota media: ");
                       scanf("%f",&nota_media); 
                       
                       if ((comprobar=insertarNuevoElemento(&A, &B, &C, nombre, dni, edad, nota_media, 0))==-1) {
                          printf("\nFallo en la matriz de datos (Matriz inexistente o eliminada).\n");
                       }
                       else { printf("\nInserccion correcta.\n"); }
                       printf("\n");
                       system("PAUSE");
                  break;
                  
                  case 2:
                       printf("\n"); 
                       printf("Introduzca nombre (max. %d caracteres): ",MAX_NOMBRE);
                       scanf(" %[^\n]",nombre);
                          
                       printf("Introduzca DNI (%d caracteres): ",MAX_DNI);                    
                       scanf("%s",dni); 
                                              
                       printf("Introduzca edad: ");
                       scanf("%d",&edad);                      
                       
                       printf("Introduzca nota media: ");
                       scanf("%f",&nota_media); 
                       
                       inicio=clock();
                       if ((comprobar=insertarNuevoElemento(&A, &B, &C, nombre, dni, edad, nota_media, 1))==-1) {
                          printf("\nFallo en la matriz de datos (Matriz inexistente o eliminada).\n");
                       }
                       else {
                            fin=clock();
                            printf("Insercci\xA2n correcta.\nEl tiempo empleado fue: %f\n",(fin - inicio)); 
                       }
                       printf("\n");
                       system("PAUSE");
                  break;                  
                
                  case 3:
                       while (op!=1 && op!=0) {
                             printf("\n\xA8 Insertar Ordenado(1) o Desordenado(0) ? : ");
                             scanf("%d",&op);
                       }
                       inicio=clock();
                       if (insertar500Alumnos(&A, &B, &C, op)==-1) {
                          printf("\nFallo en la matriz de datos (Matriz inexistente o eliminada).\n");
                       }
                       else { 
                            fin=clock();
                            printf("Insercci\xA2n correcta.\nEl tiempo empleado fue: %f\n",(fin - inicio)); 
                       }
                       printf("\n");
                       system("PAUSE");      
                  break;
                  
                  case 4:
                       printf("Introduzca DNI (%d caracteres): ",MAX_DNI);                    
                       scanf("%s", dni);
                       fflush(stdin);
                       comprobar=eliminarElemento(&A, &B, &C, dni);
                     
                       if (comprobar==-1) {
                          printf("\nFallo en la matriz de datos (Matriz inexistente o eliminada).\n");
                       } 
                       else if (comprobar==0) {
                            printf("\nNo hay elementos en la matriz de datos.\n");
                       }
                       else if (comprobar==1) {
                            printf("\nNo se ha encontrado el elemento a eliminar.\n");
                       }
                       else {
                            printf("\nEliminado correctamente.\n");
                       }                                             
                       printf("\n");
                       system("PAUSE");
                  break;
                  
                  case 5:
                       printf("Introduzca una letra: ");
                       scanf("%s",nombre);
                       imprimirLetraDada(&B, toupper(nombre[0]));
                  break;

                  case 6:
                       imprimirOrdenAlfabetico(&B);
                  break;                  

                  case 7:
                       printf("Introduzca una edad: ");
                       scanf("%d",&edad);
                       imprimirEdadDada(&C, edad);
                  break;
                  
                  case 8:
                       inicio=clock();
                       imprimirOrdenEdad(&C);
                       fin=clock();
                       printf("Insercci\xA2n correcta.\nEl tiempo empleado fue: %f\n",(fin - inicio));                     
                  break;
                                    
                  case 9:
                       mostrarElementosMatriz(&A);
                  break;

                  case 10:
                       printf("\nLa lista principal tiene %d alumnos.",cantidadElementos(&A));
                       printf("\n");
                       system("PAUSE");
                  break;                                        
                                    
                  case 11:
                       comprobar=vaciarMatriz(&A, &B, &C);
                       if (comprobar==-1) {
                          printf("\nFallo en la matriz de datos (Matriz inexistente o eliminada).\n");
                       } 
                       else if (comprobar==0) {
                            printf("\nNo hay elementos en la matriz de datos.\n");
                       }
                       else {
                            printf("\nTodos los datos de la matriz principal han sido eliminados.\n");
                       }
                       printf("\n");
                       system("PAUSE");                                          
                  break;
       }
    } while(op!=12);
    return 0;
}
//==============================================================================






//==============================================================================
//                     IMPLEMENTACIÓN DE FUNCIONES
//==============================================================================

//==============================================================================
                //================================//
                //      INICIALIZACIÓN DE LISTAS  //
                //            E ÍNDICES           //
                //===============================//
// En esta función se inicializan la lista principal y los dos árboles índice.
void inicializar(celdacontrolprincipal A, indicenombre B, indiceedad C) { 
    //A=(celdacontrolprincipal)malloc(sizeof(tipo_celda_control_principal));
    A->cantidad=0;
    A->cabeza=A->cola=NULL;
    
    //B=(indicenombre)malloc(sizeof(tipo_indice_nombre));
    B->izq=B->der=NULL;
    B->primeraletra='0';
    B->indice=inicializarCeldaControlListaIndices();

    //C=(indiceedad)malloc(sizeof(tipo_indice_edad));
    C->izq=C->der=NULL;
    C->edad=0;
    C->indice=inicializarCeldaControlListaIndices();
}
/*// En esta función se inicializan la lista principal y los dos árboles índice.
void inicializar(celdacontrolprincipal *A, indicenombre *B, indiceedad *C) { 
    (*A)=(celdacontrolprincipal)malloc(sizeof(tipo_celda_control_principal));
    (*A)->cantidad=0;
    (*A)->cabeza=(*A)->cola=NULL;
    
    (*B)=(indicenombre)malloc(sizeof(tipo_indice_nombre));
    (*B)->izq=(*B)->der=NULL;
    (*B)->primeraletra='0';
    (*B)->indice=inicializarCeldaControlListaIndices();

    (*C)=(indiceedad)malloc(sizeof(tipo_indice_edad));
    (*C)->izq=(*C)->der=NULL;
    (*C)->edad=0;
    (*C)->indice=inicializarCeldaControlListaIndices();
}*/
// Al crear los árboles índice, para su campo "índice", que es una lista en la
// que se guardan las ids de los alumnos que se van insertando, se llama a esta
// función para que se inicialice también dicha lista.
listaprincipal inicializarListaPrincipal() {
    listaprincipal nueva; 
    nueva=(listaprincipal)malloc(sizeof(tipo_lista_principal));
    char nombre[MAX_NOMBRE]={0};
    strcpy(nueva->nombre, nombre);
    char dni[MAX_DNI]={0};
    strcpy(nueva->dni, dni);
    nueva->siguiente=nueva->anterior=NULL;
    
    return nueva;
}
// Al insertar un nuevo elemento en la lista principal es necesario crear un
// nuevo elemento de la misma. Para ello usamos esta función.
celdacontrollistaindices inicializarCeldaControlListaIndices() {
    celdacontrollistaindices control=(celdacontrollistaindices)malloc(sizeof(tipo_celda_control));
    control->cabeza=control->cola=NULL;
    control->cantidad=0;
       
    return control;
}
listaindices inicializarListaIndices() {
    listaindices nueva=(listaindices)malloc(sizeof(tipo_lista_indices));
    nueva->anterior=nueva->siguiente=NULL;
    nueva->id=NULL;
    
    return nueva;
}
//==============================================================================





//==============================================================================
                //================================//
                //      INSERCCIÓN DE UN NUEVO    //
                //      ELEMENTO EN LA LISTA      //
                //===============================//
//======================================
// INSERCCIÓN EN LA LISTA PRINCIPAL (A).
//======================================
int insertarNuevoElemento(celdacontrolprincipal A, indicenombre B, indiceedad C, char nombre[MAX_NOMBRE], char dni[MAX_DNI], unsigned short edad, float nota_media, bool ordenado) {
    if (A==NULL || B==NULL || C==NULL){ return -1; }
    // Crea un nuevo elemento de tipo lista principal y guarda en él los datos recogidos anteriormente.
    listaprincipal nueva=inicializarListaPrincipal(); 
    strcpy(nueva->nombre,nombre);
    strcpy(nueva->dni,dni);
    nueva->edad=edad;
    nueva->nota_media=nota_media;
    // Si la lista estaba vacía, le da la id 1 y además lo guarda en la celda de control como cabeza y cola.
    if (A->cantidad==0) {
       nueva->id=1;   
       A->cabeza=A->cola=nueva;
    }
    // Si la id del alumno correspondiente a la cola de la lista es igual a la cantidad de elementos en la lista
    // (por tanto se deduce que no hay huecos de por medio), entonces se le da la id que resulta de sumar uno
    // a la id del último alumno.
    else if (A->cantidad==A->cola->id) {
       nueva->id=A->cola->id+1;
       A->cola->siguiente=nueva;
       nueva->anterior=A->cola;
       A->cola=nueva;
    }
    // INSERCCIÓN ORDENADA EN LISTA PRINCIPAL
    // En caso de que falte alguna id en la lista debido a algun borrado se le da la id del primer hueco disponible.
    // Por ejemplo: 1,2,4,5,... <- Se le dará la id 3 que es la primera que falta.
    else {
         unsigned int i=1;
         listaprincipal aux=A->cabeza;
         do {
             if (aux->id!=i) {
                nueva->id=i;
                nueva->anterior=aux->anterior;
                nueva->siguiente=aux;
                if (aux->anterior!=NULL) { aux->anterior->siguiente=nueva; }
                aux->anterior=nueva;
                if (aux==A->cabeza) { A->cabeza=nueva; }
                break;
             }
             i++;
             aux=aux->siguiente;
         } while (true);   
    }
    // Añadimos uno a la cantidad de elementos y actualizamos/insertamos en los árboles índice B y C.
    B=insertarIndiceNombre(B, toupper(nueva->nombre[0]), nueva, ordenado);
    C=insertarIndiceEdad(C, nueva->edad, nueva, ordenado);
    A->cantidad++;
    return 1;
}
//======================================
// INSERCCIÓN EN EL ÁRBOL
// ÍNDICE DE NOMBRES (B).
//======================================
indicenombre insertarIndiceNombre(indicenombre B, char primeraletra, listaprincipal A, bool ordenado){
      // Si no existía ningún nodo con la letra del alumno insertado creamos uno nuevo.}
      if (B==NULL) {
         indicenombre aux;
         aux=(indicenombre)malloc(sizeof(tipo_indice_nombre));
         aux->indice=inicializarCeldaControlListaIndices();
         aux->primeraletra=primeraletra;
         aux->izq=aux->der=NULL;
         aux->indice=insertarListaIndices(aux->indice, A, ordenado); // Se inicializa su lista interna y se inserta el elemento con puntero al alumno creado.
         return aux;
      }
      // Si el árbol está recién inicializado guardamos la letra en el nodo existente y actualizamos su lista interna.
      else if (B->primeraletra=='0') {
          B->primeraletra=primeraletra;
          B->indice=insertarListaIndices(B->indice, A, ordenado);
          return B;
      }    
      // Si ya existía el nodo y la letra es la misma del nodo en el que nos encontramos solamente añadimos nuevo un elemento en su lista interna.
      if (B->primeraletra==primeraletra) { B->indice=insertarListaIndices(B->indice, A, ordenado); }
      // Si ya existía el nodo y la letra es menor que la del nodo en el que nos encontramos intentamos insertar un nodo nuevo por la derecha.
      if (B->primeraletra>primeraletra) { B->izq=insertarIndiceNombre(B->izq, primeraletra, A, ordenado); }    
      // Si ya existía el nodo y la letra es mayor que la del nodo en el que nos encontramos intentamos insertar un nodo nuevo por la izquierda.
      else if (B->primeraletra<primeraletra) { B->der=insertarIndiceNombre(B->der, primeraletra, A, ordenado); }

      return B;
}
//======================================
// INSERCCIÓN EN EL ÁRBOL 
// ÍNDICE DE EDADES (C).
//======================================
indiceedad insertarIndiceEdad(indiceedad C, int edad, listaprincipal A, bool ordenado) {
      // Si no existía ningún nodo con la edad del alumno insertado creamos uno nuevo.           
      if (C==NULL){
         indiceedad aux;
         aux=(indiceedad)malloc(sizeof(tipo_indice_edad));
         aux->indice=inicializarCeldaControlListaIndices();
         aux->edad=edad;
         aux->izq=aux->der=NULL;       
         aux->indice=insertarListaIndices(aux->indice, A, ordenado); // Se inicializa su lista interna y se inserta el elemento con puntero al alumno creado.
         return aux;
      }
      // Si el árbol está recién inicializado guardamos la edad en el nodo existente y actualizamos su lista interna.      
      else if (C->edad==0) {
          C->edad=edad;
          C->indice=insertarListaIndices(C->indice, A, ordenado);
          return C;              
      }
        
      // Si ya existía el nodo y la edad es la misma del nodo en el que nos encontramos solamente añadimos nuevo un elemento en su lista interna.                                       
      if (C->edad==edad) { C->indice=insertarListaIndices(C->indice, A, ordenado); }
      // Si ya existía el nodo y la edad es menor que la del nodo en el que nos encontramos intentamos insertar un nodo nuevo por la derecha.     
      if (C->edad>edad) { C->izq=insertarIndiceEdad(C->izq, edad, A, ordenado); }
      // Si ya existía el nodo y la edad es mayor que la del nodo en el que nos encontramos intentamos insertar un nodo nuevo por la izquierda.      
      else if (C->edad<edad) { C->der=insertarIndiceEdad(C->der, edad, A, ordenado);  }

      return C;
}
//======================================
// INSERCCIÓN EN LA LISTA INTERIOR 
// A LOS ÍNDICES.
//======================================
celdacontrollistaindices insertarListaIndices(celdacontrollistaindices control, listaprincipal A, bool ordenado) {
    // Creamos un nuevo elemento para la lista interna al árbol índice que apunte al nuevo alumno.
    listaindices nueva=inicializarListaIndices();
    nueva->id=A;
    // Si es el primero que se inserta en el nodo será la cabeza y la cola de la celda de control.
    if (control->cantidad==0) { control->cabeza=control->cola=nueva; }
    // Si no es el primero entonces lo insertamos el último de la lista (cola).
    else {
        // Según si hemos decidido la opción de insertar ordenado o desordenado se hará la insercción sobre la lista interior a los árboles índice.
        // En caso de haber seleccionado la opción "Desordenado" el nuevo alumno se inserta en la cabeza de la lista.        
        if (ordenado==0) {
            // Insercción en la cabeza de la lista.
            nueva->siguiente=control->cabeza;
            control->cabeza->anterior=nueva;
            control->cabeza=nueva;
            // Insercción en la cola de la lista.
            //nueva->anterior=control->cola;
            //control->cola->siguiente=nueva;
            //control->cola=nueva;
        }
        // En caso de haber seleccionado la opción "Ordenado" el nuevo alumno se inserta en la posición que le corresponde ordenado por su ID.
        else {
            listaindices aux=control->cabeza;
            do {
                // Comenzando por la cabeza de la lista se va comparando si la ID del nuevo alumno es menor que la del que estamos comprobando,
                // en caso de que así sea se sustituye y se actualizan los enlaces del nodo siguiente y el anterior (si procede).
                if (nueva->id->id<aux->id->id) {
                    nueva->anterior=aux->anterior;
                    nueva->siguiente=aux;
                    if (aux->anterior!=NULL) { aux->anterior->siguiente=nueva; }
                    aux->anterior=nueva;
                    if (aux==control->cabeza) { control->cabeza=nueva; }
                    break;
                }
                if (aux->siguiente==NULL) {
                   nueva->anterior=aux;
                   nueva->siguiente=NULL;
                   aux->siguiente=nueva;
                   control->cola=nueva;
                   break;
                }
                aux=aux->siguiente;
            } while (aux!=NULL);              
        }
    }
    // Sumamos uno a la cantidad de elementos de la lista.
    control->cantidad++;
    return control;
}
//==============================================================================





//==============================================================================
                //===============================//
                //      ELIMINACIÓN DE UN        //
                //      ELEMENTO EXISTENTE       //
                //===============================//
// Se elimina un alumno introduciendo como parámetro su DNI.
int eliminarElemento(celdacontrolprincipal A, indicenombre B, indiceedad C, char dni[MAX_DNI]) {
    if (A==NULL || B==NULL || C==NULL) { return -1; }
    if (A->cabeza==NULL) { return 0; }    
    listaprincipal encontrar=encontrarElementoPorDNI(A->cabeza, dni);
    if (encontrar==0) { return 1; }
    
    // Si es el ÚNICO alumno de la lista principal se vuelven a inicializar la lista principal y árboles índice.
    if (A->cantidad==1) {
       free(B->indice->cabeza);
       free(B->indice);
       free(C->indice->cabeza);
       free(C->indice);
       inicializar(A, B, C);
       return 2;
    }
    //======================================
    // Actualizamos la lista principal (A)
    // en todos sus casos posibles.
    //======================================
    // Si es el unico elemento de la lista, entonces colocamos cabeza y cola de la celda de control a NULL.
    if (encontrar==A->cabeza && encontrar==A->cola) { A->cabeza=A->cola=NULL; }
    // Si es el primer elemento y ademas no es el unico, actualizamos la cabeza al segundo elemento.
    else if (encontrar==A->cabeza && A->cabeza->siguiente!=NULL) {
            encontrar->siguiente->anterior=NULL;
            A->cabeza=encontrar->siguiente;
    }
    // Si es el ultimo elemento y ademas no es el unico, actualizamos la cola al penultimo elemento.
    else if (encontrar==A->cola && A->cola->anterior!=NULL) {
            encontrar->anterior->siguiente=NULL;
            A->cola=encontrar->anterior;
    }
    // Si se encuentra entre dos elementos, actualizamos las referencias del anterior y del siguiente
    // apuntando al nuevo elemento y sus enlaces anterior y siguiente a quien corresponda.
    else {
            encontrar->anterior->siguiente=encontrar->siguiente;
            encontrar->siguiente->anterior=encontrar->anterior;
    }

    //======================================
    // Actualizamos el Indice por Nombre (B).
    //======================================
    *B=*actualizarIndiceNombre(B, toupper(encontrar->nombre[0]), encontrar->id);

    //======================================
    // Actualizamos el Indice por Edad (C).
    //======================================
    *C=*actualizarIndiceEdad(C, encontrar->edad, encontrar->id);
            
    // Liberamos la memoria del elemento a borrar.
    free(encontrar);
    // Restamos uno a la cantidad de elementos total.
    A->cantidad--;
    return 2;
}
//======================================
// ELIMINACIÓN EN EL ÁRBOL
// ÍNDICE DE NOMBRES (B)
//======================================
indicenombre actualizarIndiceNombre(indicenombre B, char primeraletra, unsigned int id){  
    indicenombre q,p; 

    if (B->primeraletra>primeraletra) { // Buscamos el nodo.
        B->izq=actualizarIndiceNombre(B->izq, primeraletra, id); // Recursividad por la izquierda para buscar el nodo.
    }
    else if (B->primeraletra<primeraletra) {
        B->der=actualizarIndiceNombre(B->der, primeraletra,id); // Recursividad por la derecha para buscar el nodo.
    }
    else{ 
          // Si lo hemos encontrado...
        // Si es el único alumno del nodo se procede con la eliminación del mismo y actualización de los enlaces del árbol.
        if (B->indice->cantidad==1) { 
            free(B->indice->cabeza);
            B->indice->cabeza=B->indice->cola=NULL;
            free(B->indice);
            B->indice=NULL;
            // Caso 1:
            if ((B->der==NULL) && (B->izq==NULL)) { 
                free(B);
                return NULL;
            }
            // Caso 2:
            if (B->der==NULL) { 
                q=B->izq;
                free(B);
                return q;
            }
            if (B->izq==NULL) {
                q=B->der;
                free(B);
                return q;
            }
            // Caso 3:
            for(p=B, q=B->izq; q->der!=NULL; q=q->der) {
                p=q;
            }
            if (p!=B) { 
                p->der=q->izq; 
                q->der=B->der;
            }
            else {                 
                q->der=p->der;              
            }
            return q;         
        }
        // Si no es el único alumno del nodo entonces solamente actualizamos su lista interior eliminando el elemento que apunte al alumno a eliminar.
        else { actualizarListaIndices(B->indice, id); }
    }
    free(B);
    return B;
}
//======================================
// ELIMINACIÓN EN EL ÁRBOL
// ÍNDICE DE EDADES (C)
//======================================
indiceedad actualizarIndiceEdad(indiceedad C, unsigned short edad, unsigned int id){  
    indiceedad q,p; 

    if (C->edad>edad) { // Buscamos el nodo.
        C->izq=actualizarIndiceEdad(C->izq, edad, id); // Recursividad por la izquierda para buscar el nodo.
    }
    else if (C->edad<edad) {
        C->der=actualizarIndiceEdad(C->der, edad,id); // Recursividad por la derecha para buscar el nodo.
    }
    else{ // Si lo hemos encontrado...
        // Si es el único elemento del nodo se procede con la eliminación del mismo y actualización de los enlaces del árbol.    
        if (C->indice->cantidad==1) { 
            free(C->indice->cabeza);
            C->indice->cabeza=C->indice->cola=NULL;
            free(C->indice);
            C->indice=NULL;
            // Caso 1:
            if ((C->der==NULL) && (C->izq==NULL)) { 
                free(C);
                return NULL;
            }
            // Caso 2:
            if (C->der==NULL ) { 
                q=C->izq;
                free(&C);
                return q;
            }
            if (C->izq==NULL) {
                q=C->der;
                free(&C);
                return q;
            }
            // Caso 3:
            for(p=C, q=C->izq; q->der!=NULL; q=q->der) {
                p=q;
            }
            if (p!=C) {
                p->der=q->izq;
                q->der=C->der;
            }
            else {
                q->der=p->der;
            }
            return q;   
        }
        // Si no es el único alumno del nodo entonces solamente actualizamos su lista interior eliminando el elemento que apunte al alumno a eliminar.
        else { actualizarListaIndices(C->indice, id); }
    }
    free(&C);    
    return C;
}
//======================================
// ELIMINACIÓN EN LA LISTA INTERIOR 
// A LOS ÁRBOLES ÍNDICE.
//======================================
void actualizarListaIndices(celdacontrollistaindices control, unsigned int id) {
    // Buscamos el elemento que apunte al alumno a eliminar y lo guardamos en una variable auxiliar.
    listaindices aux=encontrarEnListaIndicesPorId(control, id);
    
    // Si es el primero de la lista actualizamos los enlaces y guardamos al segundo como nuevo primer elemento.
    if (aux==control->cabeza) {
        aux->siguiente->anterior=NULL;
        control->cabeza=aux->siguiente;
        free(aux);
        control->cantidad--;
        return;
    }
    // Si es el último de la lista actualizamos los enlaces y guardamos al penúltimo como nueva cola.
    if (aux==control->cola) {
        aux->anterior->siguiente=NULL;
        control->cola=aux->anterior;
        free(aux);
        control->cantidad--;
        return;
    }
    // Si es un elemento intermedio se actualizan los enlaces del anterior y el siguiente.
    if (aux!=control->cabeza && aux!=control->cola) {
        aux->anterior->siguiente=aux->siguiente;
        aux->siguiente->anterior=aux->anterior;
        free(aux);
        control->cantidad--;
        return;
    }
}
//======================================
// BÚSQUEDA DE UN ELEMENTO POR ID EN LA
// LISTA INTERIOR A LOS ÁRBOLES ÍNDICE.
//======================================
// Buscamos y devolvemos un elemento en una lista interna a un árbol índice por id.
listaindices encontrarEnListaIndicesPorId(celdacontrollistaindices control, unsigned int id) {
    listaindices aux;
    for (aux=control->cabeza; aux!=NULL; aux=aux->siguiente) {
        if (aux->id->id==id) { return aux; }
    }
    return NULL;
}
//======================================
// BUSCAR UN ELEMENTO POR SU DNI EN LA
// LISTA PRINCIPAL.
//======================================
listaprincipal encontrarElementoPorDNI(listaprincipal A, char dni[MAX_DNI]) {
    if (A==NULL){ return 0; }
    listaprincipal aux=A;
    do {
        if ((strcmp(aux->dni,dni))==0) { return aux; }
        aux=aux->siguiente; 
    } while (aux!=NULL);
    return 0;
}
//==============================================================================





//==============================================================================
                    //===============================//
                    //      IMPRESIÓN DE ELEMENTOS   //
                    //      POR PANTALLA             //
                    //===============================//
//======================================
// IMPRIMIR ALUMNOS CON PRIMERA LETRA
// DEL NOMBRE IGUAL A LA LETRA DADA.
//======================================                    
void imprimirLetraDada(indicenombre B, char primeraletra) {
    indicenombre nodo=encontrarNodoLetra(B, primeraletra);
    if (nodo==NULL) {
        printf("\nNo se ha encontrado ningun alumno cuyo nombre empiece por esa letra.");
        printf("\n");
        system("PAUSE");       
        return;
    }
    listaindices aux;
    unsigned int i;
    for (i=1, aux=nodo->indice->cabeza; i<=nodo->indice->cantidad; i++, aux=aux->siguiente) {
        printf("\n-------------------------\n");        
        printf("Elemento numero %d de %d.\n", i, nodo->indice->cantidad);
        printf("-------------------------\n");
        printf("Identificador: %d\n",aux->id->id);
        printf("Nombre:        %s\n",aux->id->nombre);
        printf("DNI:           %s\n",aux->id->dni);
        printf("Edad:          %d\n",aux->id->edad);
        printf("Nota Media:    %f\n",aux->id->nota_media);        
        printf("-------------------------\n");
        if (i%30==0) {
           printf("\n");
           system("PAUSE");
        }
    }
    printf("\n");
    system("PAUSE");
}
//======================================
// IMPRIMIR TODOS LOS ALUMNOS POR
// ORDEN ALFABÉTICO.
//====================================== 
void imprimirOrdenAlfabetico(indicenombre B) {   
    if (B==NULL) { return; }
    if (B->primeraletra=='0') {
        printf("\nNo hay ningun alumno en la lista principal.\n");
        printf("\n");
        system("PAUSE");
        return;
    }
    imprimirOrdenAlfabetico(B->izq);   
    listaindices aux;
    unsigned int i;
    for (i=1, aux=B->indice->cabeza; i<=B->indice->cantidad; i++, aux=aux->siguiente) {
        printf("\n-------------------------\n");
        printf("Letra %c. Elemento numero %d de %d.\n", B->primeraletra, i, B->indice->cantidad);
        printf("-------------------------\n");
        printf("Identificador: %d\n",aux->id->id);
        printf("Nombre:        %s\n",aux->id->nombre);
        printf("DNI:           %s\n",aux->id->dni);
        printf("Edad:          %d\n",aux->id->edad);
        printf("Nota Media:    %f\n",aux->id->nota_media);        
        printf("-------------------------\n");
        if (i%30==0) {
           printf("\n");
           system("PAUSE");
        }
    }
    printf("\n");
    system("PAUSE");
    imprimirOrdenAlfabetico(B->der);
}
//======================================
// ENCONTRAR NODO EN ÍNDICE ÁRBOL POR 
// NOMBRE CON LETRA IGUAL A LETRA DADA.
//====================================== 
indicenombre encontrarNodoLetra(indicenombre B, char primeraletra) {
    if(B==NULL) { return NULL; }
    //Si la letra es igual a la letra del nodo devolvemos dicho nodo.
    if(B->primeraletra==primeraletra) { return B; }
    //Si la letra del nodo es mayor que la letra que nos da el usuario habrá que buscar por la izquierda.
    if(B->primeraletra>primeraletra) { return encontrarNodoLetra(B->izq, primeraletra); }
    //Si la letra del nodo es menor que la letra que nos da el usuario habrá que buscar por la derecha.
    else { return encontrarNodoLetra(B->der, primeraletra); }
}
//======================================
// IMPRIMIR ALUMNOS CON EDAD IGUAL
// A LA EDAD DADA.
//====================================== 
void imprimirEdadDada(indiceedad C, unsigned short edad) {
    indiceedad nodo=encontrarNodoEdad(C, edad);
    if (nodo==NULL) {
        printf("\nNo se ha encontrado ningun alumno que tenga esa edad.");
        printf("\n");
        system("PAUSE");       
        return;
    }
    listaindices aux;
    unsigned int i;
    for (i=1, aux=nodo->indice->cabeza; i<=nodo->indice->cantidad; i++, aux=aux->siguiente) {
        printf("\n-------------------------\n");
        printf("Elemento numero %d de %d.\n", i, nodo->indice->cantidad);
        printf("-------------------------\n");
        printf("Identificador: %d\n",aux->id->id);
        printf("Nombre:        %s\n",aux->id->nombre);
        printf("DNI:           %s\n",aux->id->dni);
        printf("Edad:          %d\n",aux->id->edad);
        printf("Nota Media:    %f\n",aux->id->nota_media);        
        printf("-------------------------\n");
        if (i%30==0) {
           printf("\n");
           system("PAUSE");
        }
    }
    printf("\n");
    system("PAUSE");    
}
//======================================
// IMPRIMIR TODOS LOS ALUMNOS POR
// ORDEN DE EDAD.
//====================================== 
void imprimirOrdenEdad(indiceedad C) {   
    if (C==NULL) { return; }
    if (C->edad==0) {
        printf("\nNo hay ningun alumno en la lista principal.\n");
        printf("\n");
        system("PAUSE");
        return;
    }     
    imprimirOrdenEdad(C->izq);
    float inicio, fin;
    inicio=clock();
    burbuja_mejorada(C->indice, C->indice->cantidad);   
    fin=clock();
    printf("\nEl tiempo empleado para ordenarlo fue: %f\n",(fin - inicio));
    printf("\n");
    system("PAUSE");
    listaindices aux;
    unsigned int i;
    for (i=1, aux=C->indice->cabeza; i<=C->indice->cantidad; i++, aux=aux->siguiente) {
        printf("\n-------------------------\n");
        printf("Edad: %d. Elemento numero %d de %d.\n", C->edad, i, C->indice->cantidad);
        printf("-------------------------\n");
        printf("Identificador: %d\n",aux->id->id);
        printf("Nombre:        %s\n",aux->id->nombre);
        printf("DNI:           %s\n",aux->id->dni);
        printf("Edad:          %d\n",aux->id->edad);
        printf("Nota Media:    %f\n",aux->id->nota_media);        
        printf("-------------------------\n");
        if (i%30==0) {
           printf("\n");
           system("PAUSE");
        }
    }
    printf("\n");
    system("PAUSE");     
    imprimirOrdenEdad(C->der);
}
//======================================
// ENCONTRAR NODO EN ÍNDICE ÁRBOL POR 
// EDAD CON EDAD IGUAL A EDAD DADA.
//======================================  
indiceedad encontrarNodoEdad(indiceedad C, unsigned short edad) {
    if(C==NULL) { return NULL; }
    //Si la edad es igual a la edad del nodo devolvemos dicho nodo.
    if(C->edad==edad) { return C; }
    //Si la edad del nodo es mayor que la edad que nos da el usuario habrá que buscar por la izquierda.
    if(C->edad>edad) { return encontrarNodoEdad(C->izq, edad); }
    //Si la edad del nodo es menor que la edad que nos da el usuario habrá que buscar por la derecha.
    else { return encontrarNodoEdad(C->der, edad); }
}
//==============================================================================





//==============================================================================
                //====================================//
                //      MOSTRAR TODOS LOS ELEMENTOS   //
                //      DE LA LISTA PRINCIPAL         //
                //===================================//
void mostrarElementosMatriz(celdacontrolprincipal A) {
    if (A==NULL){ printf("\nFallo en la matriz de datos (Matriz inexistente o eliminada).\n"); system("PAUSE"); return; }
    if (A->cabeza==NULL) { printf("\nNo hay elementos en la matriz de datos.\n"); system("PAUSE"); return; }
    listaprincipal aux=A->cabeza;
    do {
        printf("------------------------\n");
        printf("Identificador: %d\n",aux->id);
        printf("Nombre:        %s\n",aux->nombre);
        printf("DNI:           %s\n",aux->dni);
        printf("Edad:          %d\n",aux->edad);
        printf("Nota Media:    %f\n",aux->nota_media);
        aux=aux->siguiente;
    } while (aux!=NULL);
    printf("------------------------\n");
    printf("\n");
    system("PAUSE");
}
//==============================================================================





//==============================================================================
                //=================================//
                //      CANTIDAD DE ELEMENTOS      //
                //      EN LA LISTA PRINCIPAL      //
                //================================//
// Devuelve la cantidad de elementos de la lista principal.
int cantidadElementos(celdacontrolprincipal A) {
    return A->cantidad;  
}
//==============================================================================





//==============================================================================
                //====================================//
                //      VACÍA LA LISTA PRINCIPAL      //
                //            E ÍNDICES               //
                //===================================//
//======================================
// VACIAR LISTA PRINCIPAL (A).
//======================================                
// Se vacía la lista principal. Se reinicia el contador "cantidad" y se libera
// la memoria utilizada.
int vaciarMatriz(celdacontrolprincipal A, indicenombre B, indiceedad C) {
    if (A==NULL){ return -1; } 
    if (A->cantidad==0) { return 0; }
    vaciarIndiceNombre(B);
    vaciarIndiceEdad(C);
    listaprincipal aux;
    do {
        aux=A->cabeza;
        A->cabeza=A->cabeza->siguiente;
        free(aux);
    } while (A->cabeza!=NULL);
    A->cantidad=0;
    inicializar(A, B, C);
    return 1;       
}
//======================================
// VACIAR ÁRBOL ÍNDICE POR NOMBRE (B).
//======================================
void vaciarIndiceNombre(indicenombre B) {
     if (B==NULL) { return; }
     if (B->primeraletra=='0') { return; }
     vaciarIndiceNombre(B->izq);
     vaciarIndiceNombre(B->der);
     listaindices aux;
     do {
        aux=B->indice->cabeza;
        B->indice->cabeza=B->indice->cabeza->siguiente;
        free(aux);
     } while (B->indice->cabeza!=NULL);
     free(B->indice);
     B->indice=NULL;
     free(B);
}
//======================================
// VACIAR ÁRBOL ÍNDICE POR EDAD (A).
//======================================
void vaciarIndiceEdad(indiceedad C) {
     if (C==NULL) { return; }
     if (C->edad==0) { return; }
     vaciarIndiceEdad(C->izq);
     vaciarIndiceEdad(C->der);
     listaindices aux;
     do {
        aux=C->indice->cabeza;
        C->indice->cabeza=C->indice->cabeza->siguiente;
        free(aux);
     } while (C->indice->cabeza!=NULL);
     free(C->indice);
     C->indice=NULL;
     free(&C);
}
//==============================================================================





//==============================================================================
                //====================================//
                //             ESTADÍSTIDA           //
                //===================================//
//======================================
// INSERTAR 500 ALUMNOS
//======================================                
// Inserta 500 alumnos nuevos, pudiendo elegir si queremos hacerlo de manera ordenada o desordenada.
int insertar500Alumnos(celdacontrolprincipal A, indicenombre B, indiceedad C, bool ordenado) {
    int i, comprobar;
    for (i=1; i<=500; i++) {
        comprobar=insertarNuevoElemento(A, B, C, "Aeiou", "DNI", 20, 7, ordenado);
    }
    return 1;   
}                
//======================================
// BURBUJA MEJORADA
//======================================                
// Organiza por ID los alumnos que se encuentran en una lista de índices dentro
// de un nodo de los árboles índice.
void burbuja_mejorada (celdacontrollistaindices control, unsigned int cantidad) {
    listaindices cola, aux;
    unsigned int i, j;
    bool seguir=true;
    for (i=1; seguir && i<cantidad; i++) {
        seguir=false;
        cola=control->cola;
        for (j=cantidad; j>i; j--) {
            if (cola->anterior->id->id>cola->id->id) {
               seguir=true;
               aux=cola->anterior;
               aux->siguiente=cola->siguiente;
               if (cola->siguiente!=NULL) { cola->siguiente->anterior=aux; }
               cola->siguiente=aux;
               cola->anterior=aux->anterior;
               if (aux->anterior!=NULL) { aux->anterior->siguiente=cola; }
               aux->anterior=cola;
               if (cola==control->cola) { control->cola=aux; }
               if (aux==control->cabeza) { control->cabeza=cola; }
            }
            else { cola=cola->anterior; }
        }
    }
}
//==============================================================================
