#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMS 10
typedef struct cola{
int cabeza,cola;
int valores[MAX_ELEMS];
}tipo_cola;


//FUNCIONES
int suma_uno(int i){
    return ((i+1) % MAX_ELEMS);
}

void apilar(tipo_cola *c, int i){
    if (suma_uno(c->cola) == c->cabeza){
        printf("Error: cola llena \n");
    }else{
        c->valores[c->cola] = i;
        c->cola = suma_uno(c->cola);
    }
}

int pop(tipo_cola *c){
    int v = 0;
    if (es_vacia(c)){
        v=0; printf("Error: cola vacia\n");
    }else{
        v = c->valores[c->cabeza];
        c->cabeza = suma_uno(c->cabeza);
    }
    return v;
