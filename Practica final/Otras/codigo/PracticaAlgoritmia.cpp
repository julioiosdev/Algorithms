#include "PracticaAlgoritmia.h"
#include "Arboles.c"
#include "ListaIntIdsArbol.c"
#include "ListaAlumnos.c"
#include "menu.c"
#include "OrdenacionPorEdad.c"
#include "OrdenacionPorLetra.c"
#include "pilaIds.c"
#include "PracticaAlgoritmia.h"



//inicia la lista principal y los arboles a NULL 
p_principal incializarIndice()
{
       p_principal principal= (p_principal) malloc (sizeof (principal));
       principal->lista=crear();
       principal->arbolEdad=principal->arbolAlfabetico=NULL;
       return principal; //devuelve la structura ya incializada 
}

//inserta alumno en la lista principal el alumno y los Ids en los arboles de manera ordenada o desordenada 
void insertar (p_principal principal, char nombre[], char dni[], int edad, int notaMedia, int orden )
{
     int id;
     if (principal->lista !=NULL) //por si la estructura no esta inciada
     {
        id= insertarLista( principal->lista, principal->lista->p_libre, nombre,  dni,  edad,  notaMedia) ;   //inserta en el Id p_libre 
        if (orden==DESORDENADO)
        {  
         
             principal->arbolAlfabetico=insertarArbol (principal->arbolAlfabetico,(int)nombre[0],id); //p_libre es el id de la lista principal
             principal->arbolEdad=insertarArbol (principal->arbolEdad, edad ,id);         
        }
        else
        {
            principal->arbolAlfabetico=insertarArbolOrdenado (principal->arbolAlfabetico,(int)nombre[0],id,principal->lista); //p_libre es el id de la lista principal
            principal->arbolEdad=insertarArbolOrdenado (principal->arbolEdad, edad ,id,principal->lista); 
        }    
    }
    else
        printf ("-1");
}

//elimina de los indices el alumno con el dni introducido "no tiene en cuenta que haya dnis duplicados"
int eliminar (p_principal principal, char dni[])
{
    int id;
    id=posicionAlumno(principal->lista,dni); //la poscion del alumno en la lista es el ID                                                                         
    if ( id != -1)
    {
        eliminarLista(  principal->lista, id);
        principal->arbolEdad=eliminarNodoArbol( principal->arbolEdad, principal->lista->alumno[id].edad, id);//le paso la edad y el id para que lo elimine de su listaInt
        principal->arbolAlfabetico=eliminarNodoArbol(principal->arbolAlfabetico,principal->lista->alumno[id].nombre[0],id); //le paso la letra del nombre y el id para que lo elimine de su lista ID
        
        printf ("Eliminado");
       return 0;  
     }
    else
    {
        printf ("no existe el dni");
        return -1;
    }
}

void imprimirOrdenMezcla(p_principal principal)
{
    if (principal->arbolEdad != NULL)
    {
          long inicio, final, final2;   
          inicio = GetTickCount(); //metodo que devuelve los milisegundos en que empieza
          ordenarArbolMezcla( principal, principal->arbolEdad); //ordena el arbol por edad y luego por orden alfabetico
          final= GetTickCount();  //metodo que devuelve los milisegundos en que empieza
          imprimir_orden_edad(principal->lista, principal->arbolEdad);
          final2 = GetTickCount(); //metodo que devuelve los milisegundos en que empieza
          printf ("\n\nTiempo en ordenar por mezcla: %d  milisegundos \n", final-inicio);                 //ordeno la copia por orden de la primera letra 
          printf ("\nTiempo en ordenar por mezcla y mostrar los resultados: %d  miliseundos\n",final2-inicio);
     }
     else cout <<-1;
}  


//metodo para imprimir los alumnos ordenados por la primera letra de una edad dada
void imprimirOrdenBurbuja(p_principal principal)
{   
    if (principal->arbolEdad != NULL)
    { 
        long inicio, final, final2;      //variables para el tiempo
        inicio = GetTickCount(); //metodo que devuelve los milisegundos en que empieza
        ordenarArbolBurbuja( principal,  principal->arbolEdad);//orden de menor a mayor
        final = GetTickCount();    //metodo que devuelve los milisegundos en que acaba
        imprimir_orden_edad(principal->lista, principal->arbolEdad);
        final2 = GetTickCount();
        printf ("\n\nTiempo en ordenar por burbuja: %d  milisegundos \n", final-inicio);                 //ordeno la copia por orden de la primera letra 
        printf ("\nTiempo en ordenar por burbuja y mostrar los resultados: %d  miliseundos\n",final2-inicio);
       }
     else
        cout<< -1; 
}



//Imprime los valores de la lista que se encuentren los Ids en el vector V
void imprimir (p_tipo_lista lista, int v[],int tamanio) 
{
     int identificador;
     for (int i=0; i < tamanio;i++)
    { 
       identificador=v[i];
        printf ("\nid lista: %d",identificador);
        cout <<"  nombre: "<<lista->alumno[identificador].nombre ;
        cout <<"    edad: "<<lista->alumno[identificador].edad ;
        cout <<"    DNI: "<<lista->alumno[identificador].dni ;
        cout <<"    nota MEdia: "<<lista->alumno[identificador].notaMedia<<"\n";  
    }   
}

//vacia los datos de los arboles y de la lista
void vaciarListas(p_principal principal)
{
     if (principal->lista!=NULL &&principal->arbolEdad!=NULL &&principal->arbolAlfabetico!=NULL )
    {  
     
          int vector[100]; //el arbol no deberia ser de mas de 100
        principal->lista->p_libre=0;
        vaciar(principal->lista->pila);
          
          int *contador, cont=0;
          contador=&cont;
          int j;
          
          simetrico(principal->arbolEdad,vector,contador); //recojo los valores de los nodos para despues eliminarlos 1 a  1
          for (j=0;j<(*contador);j++)
            principal->arbolEdad=eliminarArbol (principal->arbolEdad,vector[j]); //eliminos los nodo del arbolEdad
          cont=0;
          simetrico(principal->arbolAlfabetico,vector,contador);
          for (int j=0;j<(*contador);j++)
            principal->arbolAlfabetico=eliminarArbol (principal->arbolAlfabetico,vector[j]); //elimino nodos de arbolAlfabetico
          
         
         }  
}


int main(int argc, char *argv[])
{
    
    p_principal principal;
    principal=incializarIndice();
    menu( principal);
   
    system("PAUSE");
    return EXIT_SUCCESS;
}
















;
