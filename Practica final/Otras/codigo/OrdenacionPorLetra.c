#include "PracticaAlgoritmia.h"
//imprime el orden alfabetico recorriendo el arbol simetricamente
void imprimir_orden_alfabetico(p_tipo_lista lista, p_nodo_arbol arbol)//orden de menor a mayor
 {
    if (arbol!=NULL)
    {
      if (arbol->izq != NULL)
         imprimir_orden_alfabetico(lista,arbol->izq);
     
      cout << "\n\nLetra "<<(char)arbol->valor<<"\n";
      imprimir(lista,arbol->list->valores,arbol->list->p_libre) ;
        
      if (arbol->der != NULL)
         imprimir_orden_alfabetico(lista,arbol->der);
    }
    else
        cout<< -1;
}


//se envia una letra la busca en el arbol y imprime los alumnos con esa letra
void imprimir_letra_dada(p_tipo_lista lista, p_nodo_arbol arbol, char letra)
{
    p_nodo_arbol nodo=buscarNodo(arbol,letra);    //devuelve el nodo buscado o null en caso de que no exista
    if (nodo != NULL)
    {
       cout << "\n\nLetra "<<(char)nodo->valor<<"\n";         //imprime su valor como char
       imprimir(lista, nodo->list->valores , nodo->list->p_libre); //visualiza los alumnos
    }
    else
       cout<< -1;
}
