#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main(int argc, char** argv){
    
    Pila p1, p2;
    int i;
    
    p1=crear();//creamos las pilas
    p2=crear();
    
    if(esta_vacia(p1) == true)//comprobamos que estabn vacias
    printf("La pila p1 esta vacia\n");
    
    if(esta_vacia(p2) == true)
    printf("La pila p2 esta vacia\n");
    
    for(i=0;i<20;i++){ //metemos numeros en la pila
                      if(i%2==0)
                      apilar(p1,i);
                      else
                      apilar(p2,i);
    }

printf("Los elementos de la pila p1 son: \n\t");
while(!esta_vacia(p1)) //mientras no este vacia
printf("%d ", desapilar(p1));//vamos sacando los numeros y mostandolos

puts("");
vaciar(p1);//la vaciamos

printf("Los elementos de la pila p2 son: \n \t");

while(!esta_vacia(p2))
printf("%d ",desapilar(p2));


destruir(p1);//eliminamos la pila
destruir(p2);

getche();
return (EXIT_SUCCESS);
}
