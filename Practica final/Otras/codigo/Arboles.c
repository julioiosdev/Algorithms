#include "PracticaAlgoritmia.h"

//FUNCIONES DEFINIDAS EN LA CABECERA

////////////////////Inserta un nodo en el arbol si no existe el arbol lo crea
p_nodo_arbol insertarArbol (p_nodo_arbol arbol, int i, int id)
{  // INICIO metodo insertar
    p_nodo_arbol p;
    if (arbol == NULL)
    {    
       p=(p_nodo_arbol) malloc (sizeof(nodo_arbol)); // guardo un puntero en p que donde apunte reservara memoria de la estrucura nodo arbol
       p->izq = p->der = NULL;                       //inicializo tanto la derecha como la izquierda a NULL
       p->valor = i;                                 // en valor se va a guardar el entero que le paso por parámetro a la función 
       p->list=crearListaInt();                      //creamos una nueva lista para almacenar los IDs
       insertarListaInt(p->list,p->list->p_libre,id);//insertamos en la posicon plibre "0" de la lista el id
       return p;                                     // retorna el nodo
    }
    if (arbol->valor == i)                            //cuando el valor es = se inserta a la lista
    {
       insertarListaInt(arbol->list,arbol->list->p_libre,id); //si ya esiste el nodo agrego el id a la lista del nodo en la posicion libre
        return arbol; 
    }                                    
    if (arbol->valor > i)                              // si el valor, que ya tengo en la esctructura, es decir, he tomado en cuanta que ya he hecho un insert,...es mayor que 
                                                       // el nuevo valor que le paso por parametro, guardare en izq, la funcion insertar??¿¿¿, (se que le paso un null y un nº2 x ejem)
         arbol->izq = insertarArbol(arbol->izq, i,id);
    else 
         arbol->der = insertarArbol(arbol->der, i,id);  // guardare en der, la funcion insertar??¿¿¿, (se que le paso un null y un nº9 x eje)              
    return arbol;
    
} 
    
//borra el nodo enviado
p_nodo_arbol borraNodo(p_nodo_arbol nodo)
{
     free (nodo->list);             //para eliminar las listas tb
     free (nodo);                   //elimino el nodo
     return NULL;                   //devuelvo null para que se ponga el puntero del padre a null
                                      
}
//elmina el id de un nodo existente o el nodo entero cuando se queda sin Ids
p_nodo_arbol eliminarNodoArbol (p_nodo_arbol arbol, int numero, int id){
    
      p_nodo_arbol q,pNodo;
      if (arbol == NULL)
          return arbol;
      if (arbol->valor > numero) 
         arbol->izq = eliminarNodoArbol (arbol->izq, numero,id);     
      else if (arbol->valor < numero)
         arbol->der = eliminarNodoArbol (arbol->der, numero,id);
           
           //esto quiere decir qe valor es = al numero del nodo-valor 
      else{
          if (arbol->list->p_libre>1)             //si tiene mas de un id borro el id si tiene 1 elemento borro el nodo puesto que ya no me interesa
          {
             printf ("entro a borrar de la lista");
                eliminarIdLista(arbol->list,id) ;   
                return arbol;
          }
          if ((arbol->der == NULL)&&(arbol->izq == NULL)) //caso 1
               return borraNodo(arbol);
             //Caso 2
          if (arbol->der == NULL){ 
              q = arbol->izq;//q nodo secundario
              return q;
              borraNodo (arbol);    
          }
          if (arbol->izq == NULL){
             
             q=arbol->der;
             return q;
             borraNodo (arbol);
          } 
          //Caso 3
          for( pNodo=arbol ,q=arbol->izq ; q->der != NULL ; q = q->der)// busco el ultimo de la rama izq                  
                pNodo=q;  
          if (pNodo!=arbol)
              pNodo->der = q->izq;
           else
              pNodo->izq =q->izq;     
           
            arbol->valor = q->valor;     //copio el valor
            copiarLista (q->list,arbol->list); //copiamos la lista
            borraNodo (q);
                
        }
         return arbol;

}
//devuelve un nodo buscado por edad o por caracter
p_nodo_arbol buscarNodo(p_nodo_arbol arbol, int num)
{
     if (arbol !=NULL)
     {
        if (arbol->valor==num)                             //si el nodo->valor == a num  devuelve el nodo
           return arbol;
        else if (arbol->izq != NULL && arbol->valor > num)  //si no se llama a si misma por la izquierda
                return buscarNodo(arbol->izq, num);
        else if (arbol->der != NULL && arbol->valor < num)  //si no se llama a si misma por la derecha
                return buscarNodo(arbol->der, num);
         else
             return NULL; //si no encuentra el nodo devuelve NULL
     } 
     else
         return NULL;     //si le han enviado un nodo nullo devuelve NULL
         
}

p_nodo_arbol insertarArbolOrdenado (p_nodo_arbol arbol, int i, int id, p_tipo_lista lista)
{  // INICIO metodo insertar
    p_nodo_arbol p;
    if (arbol == NULL)
    {    
       p=(p_nodo_arbol) malloc (sizeof(nodo_arbol)); // guardo un puntero en p que donde apunte reservara memoria de la estrucura nodo arbol
       p->izq = p->der = NULL;                       //inicializo tanto la derecha como la izquierda a NULL
       p->valor = i;                                 // en valor se va a guardar el entero que le paso por parámetro a la función 
       p->list=crearListaInt();                      //creamos una nueva lista para almacenar los IDs
       insertarListaInt(p->list,p->list->p_libre,id);//insertamos en la posicon plibre "0" de la lista el id
       return p;                                     // retorna el nodo
    }
    if (arbol->valor == i)                            //cuando el valor es = se inserta a la lista
    {
       insertarListaIntOrdenado(lista,arbol->list,arbol->list->p_libre,id); //si ya esiste el nodo agrego el id a la lista del nodo en la posicion libre
        return arbol; 
    }                                    
    if (arbol->valor > i)                              // si el valor, que ya tengo en la esctructura, es decir, he tomado en cuanta que ya he hecho un insert,...es mayor que 
                                                       // el nuevo valor que le paso por parametro, guardare en izq, la funcion insertar??¿¿¿, (se que le paso un null y un nº2 x ejem)
         arbol->izq = insertarArbol(arbol->izq, i,id);
    else 
         arbol->der = insertarArbol(arbol->der, i,id);  // guardare en der, la funcion insertar??¿¿¿, (se que le paso un null y un nº9 x eje)              
    return arbol;
    
} 


void simetrico(p_nodo_arbol arbol, int vector[], int *i)//orden de menor a mayor se utiliza para saber los nodos a borrar
 {
    if (arbol->izq != NULL)
    simetrico(arbol->izq , vector, i);      
    vector[*i]=arbol->valor;
       (*i)++;
    if (arbol->der != NULL)
        simetrico(arbol->der, vector, i);
}

p_nodo_arbol eliminarArbol (p_nodo_arbol arbol, int numero){
      p_nodo_arbol q,pNodo;
      if (arbol == NULL)
          return arbol;
      if (arbol->valor > numero) 
         arbol->izq = eliminarArbol (arbol->izq, numero);
      
           else if (arbol->valor < numero)
            arbol->der = eliminarArbol (arbol->der, numero);
           
           //esto quiere decir qe valor es = al numero del nodo-valor 
           else{
              
                if ((arbol->der == NULL)&&(arbol->izq == NULL)) //caso 1
                   return borraNodo(arbol);
                   //Caso 2
                if (arbol->der == NULL){
                   //q nodo secundario
                   q = arbol->izq;
                   borraNodo (arbol);
                   return q;
                }
                if (arbol->izq == NULL){
                   q = arbol->der;
                   borraNodo (arbol);
                   return q;
                }
                //Caso 3
                for( pNodo=arbol ,q=arbol->izq ; q->der != NULL ; q = q->der)// busco el ultimo de la rama izq                  
                      pNodo=q;  
                if (pNodo!=arbol)
                    pNodo->der = q->izq;
                 else
                    pNodo->izq =q->izq;     
                 arbol->valor = q->valor;     
                  borraNodo(q);
                       
      }
      return arbol;
}
//ordena todo el arbol de indices usando burbuja
void ordenarArbolBurbuja(p_principal principal, p_nodo_arbol arbol)//orden de menor a mayor
{
    if (arbol->izq != NULL)
        ordenarArbolBurbuja(principal,arbol->izq);      
     burbuja(principal->lista,arbol->list->valores,arbol->list->p_libre);  
    if (arbol->der != NULL)
        ordenarArbolBurbuja(principal,arbol->der);
}
//ordena todo el arbol de indices usando mezcla
void ordenarArbolMezcla(p_principal principal, p_nodo_arbol arbol)//orden de menor a mayor
{
    if (arbol->izq != NULL)
      ordenarArbolMezcla(principal,arbol->izq);       
    ordenMezcla(principal->lista,arbol->list->valores,0,arbol->list->p_libre);  
    if (arbol->der != NULL)
        ordenarArbolMezcla(principal,arbol->der);
}
  
