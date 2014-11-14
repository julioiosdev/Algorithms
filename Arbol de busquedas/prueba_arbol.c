#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "arbol.h"
    
int main(int argc, char** argv){
    Arbol b;
    Arbol a;
    Arbol c;
    a=NULL; //A la hora de crear el arbol debemos de inicializar la viriable como NULL
    b=NULL;
    c=NULL;
    a=arbol_insertar(a,7);
    a=arbol_insertar(a,100);
    a=arbol_insertar(a,3);
    a=arbol_insertar(a,43);
    a=arbol_insertar(a,322);
    a=arbol_insertar(a,33);
    
    eliminar(a,322);
    
    printf("preorden: "); arbol_recorrer_preorden(a); printf("\n");
    printf("Simetrico: "); arbol_recorrer_simetrico(a); printf("\n");//recorremoa la funcion
    printf("Postorden: "); arbol_recorrer_postorden(a); printf("\n");
    
    c=arbol_encontrar(a, 43);
     printf("preorden: "); arbol_recorrer_preorden(c); printf("\n");
     
     
    if(arbol_pertenece(a,7))
    printf("Si que esta el %d");
    
    
    b=arbol_padre_de(a,c); printf("\n");
    
    printf("preorden: "); arbol_recorrer_preorden(b); printf("\n");
    
    getche();
    
    return EXIT_SUCCESS;
    
}   
    
