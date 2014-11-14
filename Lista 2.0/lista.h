#ifndef LISTA_H_
#define LISTA_H_

typedef struct cabeza *Lista; //de esta forma creamos un puntero de tipo cabeza, y hacemos que el usuariopueda usar lista
//para inicializar una variable

Lista l_int_crear(void);
int l_int_anadir(Lista l, int n);
int l_int_insertar(Lista l, int pos, int n);
int l_int_longitud(Lista l);
int l_int_encontrar(Lista l, int n);
int l_int_elemento(Lista l, int pos);
void l_int_borrar(Lista l, int pos);
void l_int_destruir(Lista l);

#endif /* LISTA_H_ */


