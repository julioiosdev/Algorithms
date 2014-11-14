#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMS 10

typedef struct pila {
        int cima;
        int valores[MAX_ELEMS];
} tipo_pila;

//Inicializar pila estatica
void inicializar(tipo_pila *p){
 p->cima=0;
}
 
//Apilar pila estatica    
void push(tipo_pila *p, int i, int *error){
    *error = 0;
    if (p->cima < MAX_ELEMS)
       p->valores[p->cima++] = i;
    else
    *error = -1;
}

//Desapilar pila estatica
void pop(tipo_pila *p, int * error){
    *error = 0;
    if (p->cima > 0)
        p->valores[--p->cima];
    else
        *error = -1;
}

//Busqueda en pila estatica

int busqueda(tipo_pila *p,int valor){
    int i=0;
    for(;p->cima>=0;p->valores[--p->cima]) {                                
         i++;
         if (p->valores[p->cima] == valor) return i;
    }
    return -1;  
}

int main()
{
    tipo_pila *pila = (tipo_pila*)malloc(sizeof(tipo_pila));
    int error;
    
    //Inicializar
    inicializar(pila);
       
    //Apilar
    push(pila,7,&error);
    push(pila,2,&error);
    push(pila,4,&error);
    
    //Buscar un valor
    printf("Num. operaciones: %i \n",busqueda(pila,2));
    
    //Desapilar     
    pop(pila,&error);
    pop(pila,&error);
    pop(pila,&error);
    
 
    system("pause");
    return 0;
}
