#include "PracticaAlgoritmia.h"


//inserta en la lista el alumno y devuelve el Id con el que fue insertado el alumno
int insertarLista(p_tipo_lista lista, int posicion, char nombre[], char dni[], int edad, int notaMedia)
{
   if (posicion > MAX_ELEMS|| posicion < 0)//comprobacion de que la posicion no es mayor que el maximo ni menor que el minimo
      printf("Error: posición fuera de lista\n");
   else 
   {
      if (lista->p_libre == MAX_ELEMS)  //comprobacion que el apuntador p_libre no esta al maximo que indicaria que la lista sta llena
         printf("Error: lista llena\n");
      else
      {
      
         if (!esVaciaPila(lista->pila))         //se comprueba la pila
            posicion=pop(lista->pila);
        else
        {
             for(int i=lista->p_libre; i>=posicion;i--)//desplazo todos los numeros 1 posicion a la derecha en el vector para meter mi numero
                 lista->alumno[i] = lista->alumno[i-1]; 
             lista->p_libre++; //incremento posción libre
        }         
             strcpy(lista->alumno[posicion].dni,dni);          //copio la cadena
             strcpy(lista->alumno[posicion].nombre,nombre);    //copio la cadena
             lista->alumno[posicion].edad=edad;                //copio la edad
             lista->alumno[posicion].notaMedia=notaMedia;      //copio la nota media  
             return posicion;                                  //retorna la posicion
       }
    }
}

//eliminar de la lista el alumno //borrado logico
void eliminarLista(p_tipo_lista  lista, int posicion)
{
 
    if (posicion > lista->p_libre-1 || posicion < 0)
        printf("Error: posición fuera de lista\n");
   else
   {
        for (int i=0;i<strlen(lista->alumno[posicion].dni);i++)
        lista->alumno[posicion].dni[i]='\0';//se pone '\0' por que las comprobaciones de eliminar se hacen por dni y como es un borrado logico
        push(lista->pila,posicion);
   }

}
//crea una lista de alumnos
p_tipo_lista  crear()
{
      p_tipo_lista lista= (p_tipo_lista)  malloc(sizeof (tipo_lista) ); //reserva memoria para un tipo_lista
      lista->p_libre=0;                                                 //inicio variables necesarias a 0
      lista->pila=crearPila();
      return lista;
}

int posicionAlumno(p_tipo_lista lista,char dni[])
{
     int i;
     for ( i=0 ; i < lista->p_libre && strcmp(lista->alumno[i].dni,dni );i++);
     if (i==lista->p_libre)
        return -1;
     else
         return i;
}

//visualiza la lista principal para comprobar
void visualizarLista(p_tipo_lista lista)
{
     for (int i=0; i < lista->p_libre;i++) //hasta que llegue a la ultima posicion p_libre muestra los elementos
    {
        cout <<"DNI: "<<lista->alumno[i].dni <<"\n";
        cout <<"nombre: "<<lista->alumno[i].nombre <<"\n";
        cout <<"edad: "<<lista->alumno[i].edad <<"\n";
        cout <<"nota MEdia: "<<lista->alumno[i].notaMedia<<"\n";    
        cout << "\n\n\n";
    }
}
