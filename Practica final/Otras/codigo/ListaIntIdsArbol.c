#include "PracticaAlgoritmia.h"

void insertarListaInt(p_tipo_lista_int lista, int posicion,int id)
{
     if (posicion > MAX_ELEMS|| posicion < 0) //comprobacion de que la posicion no es mayor que el maximo ni menor que el minimo
        printf("Error: posición fuera de lista\n");     
     else  
     {
        if (lista->p_libre == MAX_ELEMS)//comprobacion que el apuntador p_libre no esta al maximo que indicaria que la lista sta llena
           printf("Error: lista llena arbol\n");    
        else //inserto en la lista
        {
           for(int i=lista->p_libre; i>=posicion;i--)    //desplazo todos los numeros 1 posicion a la derecha en el vector para meter mi numero
              lista->valores[i] = lista->valores[i-1];
           lista->valores[posicion]=id;                  //inserto el ID    
           lista->p_libre++;                             //incremento posción libre
        }
     }
}

//elimina de la lista del arbol el id 

int eliminarIdLista(p_tipo_lista_int lista, int id)
{   
    int i;  //me va a indicar la posicion donde se encuentra el id
    int error=0;
    //busca el numero mientras haya numeros en la lista "dentro de su vector" y sea diferente al que buscamos si coinciden los numeros sale del for
    for (i=0;  lista->valores[i]!=id && i < lista->p_libre ; i++);
    if (i >= lista->p_libre || i < 0){
        printf("Error: posición fuera de lista\n");
        error=-1;
    }
    else
    {
        for(i=i ; i < lista->p_libre ; i++)//recorro todos los elementos una psocion hacia la izquierda hasta la posicion que me dicen
            lista->valores[i] = lista->valores[i+1];
        lista->p_libre--;
    }
    return error;
}

//crea la lista de los arboles, se crea cuando el nodo es NULL
p_tipo_lista_int crearListaInt()
{
    p_tipo_lista_int lista= (p_tipo_lista_int)  malloc(sizeof (listaInt) ); //reservo memoria para la lista
    lista->p_libre=0;                                                       //inicio p_libre a 0
    return lista;                                                           //devuelvo la lista
}

void copiarLista (p_tipo_lista_int inicial, p_tipo_lista_int copia)
{
    copia->p_libre = inicial->p_libre;
    for (int i=0; i< inicial->p_libre;i++)
         copia->valores[i]=inicial->valores[i];   
}

void mezclar (p_tipo_lista lista, int vector[], int inicio, int tamA, int tamB)
{
     int cmp;
     int  vectorAux[tamA+tamB];       //tamaño para el vector auxiliar
     int i=0,j=0,z=0;                  //inciio 3 contadores
     for (i=0 ;  i < tamA+tamB && z<tamB && j<tamA; i++)  
     {   

       cmp= strcmp(lista->alumno[vector[j+inicio]].nombre, lista->alumno[vector[z+inicio+tamA]].nombre); //comprar las 2 cadenas 
                                                                              //si son iguales da 0
                                                                              //si cad 1 mayor da un numero positivo
                                                                              //si cad 2 mayor da un numeor negativo
       if (cmp < 0 )      
            vectorAux[i]=vector[(j++)+inicio]; //OJO se incrementa j despues de hacer la operacion     
       else
            vectorAux[i]=vector[(z++)+inicio+tamA]; //OJO se incrmenta z despues de la operacion
      }      
  
      for (j; j<tamA; j++,i++)
          vectorAux[i]=vector[j+inicio];
      for (z; z<tamB; z++,i++)
          vectorAux[i]=vector[z+inicio+tamA];
    for (int i=0;i<tamB+tamA;i++) //copio el vector auxiliar a la posicion correspondiente del vector 
       vector[inicio+i]= vectorAux[i];
}
//metodo para ordenar por mezcla
void ordenMezcla(p_tipo_lista lista, int vector[], int inicio,int tamanio )
{
   int tamA;
   int tamB;
   if (tamanio > 1)
   {
      tamA = tamanio / 2;
      tamB = tamanio - tamA;
      ordenMezcla(lista,vector, inicio, tamA);
      ordenMezcla(lista,vector, inicio + tamA, tamB);
      mezclar(lista,vector, inicio, tamA, tamB);
   }  
}
//metodo para ordenar por burbuja
void burbuja(p_tipo_lista lista, int v[], int tamanio) 
{
    int i, j, interc;
    int cmp;
    for (i = 0; i < tamanio-1; i++)  //se recorre el vector de principio a fin
    {
      for(j = i+1; j < tamanio; j++) //se recorre el vector de i +1 hasta el final
      {
      cmp= strcmp(lista->alumno[v[j]].nombre, lista->alumno[v[i]].nombre);
         if (cmp<0)
         {   
            interc = v[j];                //variable auxsiliar
            v[j]=v[i];  //como la pos j es menor intercammbio con la pos de i
            v[i]=interc;                   //se pone en la posicion de i lo que valia la posicion dej
         }
       }
     }       
}  



void insertarListaIntOrdenado(p_tipo_lista listaPrincipal, p_tipo_lista_int lista, int posicion,int id)
{
     int cmp;
     bool aniadido=false;
     if (posicion > MAX_ELEMS|| posicion < 0) //comprobacion de que la posicion no es mayor que el maximo ni menor que el minimo
        printf("Error: posición fuera de lista\n");     
     else  
     {
        if (lista->p_libre == MAX_ELEMS)//comprobacion que el apuntador p_libre no esta al maximo que indicaria que la lista sta llena
           printf("Error: lista llena\n");
        else //inserto en la lista
        {
            for (int i=0;i<lista->p_libre;i++) 
            {    
				 cmp= strcmp(listaPrincipal->alumno[id].nombre, listaPrincipal->alumno[lista->valores[i]].nombre );
				 if (cmp <0 ) 
				 {
						 aniadido=true;
						for (int z= lista->p_libre ;z >= i; z--)
						{
							 lista->valores[z] = lista->valores[z-1];   
						}
						lista->valores[i]=id;
						break;
				 }
			 
             }
             
             if (aniadido==false)
                lista->valores[posicion]=id;
           lista->p_libre++;                             //incremento posción libre
        }
     }
}
/*void copiarLista (p_tipo_lista_int lista, p_tipo_lista_int listaCopia)
{
     for (int i=0_;i<lista->p_libre; i++)
         listaCopia->valores[i]=         listaCopia->valores[i];
         
}*/
