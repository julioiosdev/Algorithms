#include "PracticaAlgoritmia.h"

//imprime el orden de edad recorriendo el arbol simetricamente
void imprimir_orden_edad(p_tipo_lista lista, p_nodo_arbol arbol)//orden de menor a mayor
 {
     if (arbol!=NULL)
     {
         if (arbol->izq != NULL)
           imprimir_orden_edad(lista,arbol->izq);
        cout << "\n\nEdad "<<arbol->valor<<"\n";
        imprimir(lista,arbol->list->valores,arbol->list->p_libre);
               
        if (arbol->der != NULL)
            imprimir_orden_edad(lista,arbol->der);
     }
     else
       cout<< -1;
}

//se envia una edad la busca en el arbol y imprime los alumnos con esa edad
void imprimir_edad_dada(p_tipo_lista lista, p_nodo_arbol arbol, int edad)
{
    p_nodo_arbol nodo=buscarNodo(arbol,edad);                     //devuelve el nodo buscado o null en caso de que no exista
    if (nodo != NULL)
    {
        cout<< "\n\nEdad "<<nodo->valor <<"\n";                                //se imprime su valor
        imprimir(lista,nodo->list->valores,nodo->list->p_libre);  //imprime los alumnos del nodo
     } 
     else
         cout<< -1;
        
}
