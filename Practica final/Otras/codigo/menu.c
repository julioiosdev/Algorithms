#include "PracticaAlgoritmia.h"


void menu(p_principal principal)
{
     char nombreIn[10];
     char dniIn[10];
     int notaIn,  edadIn; 
     char letra;
     int iteracion[10][4]; //se genera siempre las muestas divididas entre 10
     int numero;
     do
     {
       do
       {

            printf ("\n-------------------------------------------------------------");
              printf ("\n|\t1 Anadir rango de alumnos a la lista\n");
              printf ("\n|\t2 Anadir alumno a la lista\n");
              printf ("\n|\t3 Eliminar alumno a la lista\n");
              printf ("\n|\t4 Imprimir letra dada lista\n");
              printf ("\n|\t5 Imprimir edad dada de la lista\n");
              printf ("\n|\t6 Imprimir orden alfabeticamente\n");
              printf ("\n|\t7 Imprimir orden edad\n");
              printf ("\n|\t8 Imprimir lista\n");
              printf ("\n|\t9 Imprimir lista POR EDAD ordenado burbuja\n");
              printf ("\n|\t10 Imprimir lista POR EDAD ordenado mezcla\n");
              printf ("\n|\t11 Comprobacion eficiencia entre estrategia1, estrategia2, estrategia3\n");
              printf ("\n|\t0 salir\n");
              printf ("--------------------------------------------------------------");
              scanf("%d",&numero);
              fflush(stdin);
       }while(numero >11 || numero <0);
        switch (numero)
        {
              case 0: break;
              case 1:     
                   {    
                      int numAlu;
                      do{
                      printf("\nEscriba el numero para añadir");
                      scanf ("%d", &numAlu);
                      }while (numAlu>MAX_ELEMS || numAlu<1);
                      insertarMasivo( principal, DESORDENADO,ALEATORIO,numAlu);                 
                      break;
                   } 
              case 2:
                   {
                    
                     edadIn=-1;//para controlar fallos
                     notaIn=-1;
                     printf ("\nEscriba nombre: ");
                     scanf("%s",&nombreIn);
                     fflush(stdin);
                     do{   
                         printf ("\nEscriba DNI, si existe en la lista se le volvera a pedir: ");
                         scanf("%s",&dniIn);
                         fflush(stdin);
                     } while(posicionAlumno(principal->lista, dniIn)!=-1);
                     do{
                         printf("\nEscriba edad, un valor entre 0 y 100: ");
                         scanf ("%d", &edadIn);
                         fflush(stdin);
                     }while (edadIn<0 || edadIn>100);
                      do{
                         printf ("\nEscriba la nota, tiene que ser un valor entre 0 y 10: ");
                         scanf ("%d", &notaIn);
                         fflush(stdin);
                     }while (notaIn<0 || notaIn>10);
                     insertar ( principal, nombreIn, dniIn,  edadIn, notaIn ,DESORDENADO);
                     printf ("\nAlumno insertado");
                     break;
                   }
              case 3:
                   {                     
                       printf ("\nIntroduzca el dni a eliminar: ");
                       scanf("%s",&dniIn);
                       fflush(stdin);
                       eliminar (principal ,  dniIn);
                       break;
                   }
              case 4: 
                   {
                       printf ("\nEscriba la letra: ");
                       scanf ("%c", &letra);
                       fflush(stdin);
                       cout <<"Edad buscada\n";
                       imprimir_letra_dada(principal->lista,  principal->arbolAlfabetico, letra);
                       break;
                   }
              case 5:
                   {
                       printf ("\nEscriba el numero: ");
                       scanf ("%d", &numero);
                       fflush(stdin);
                       cout <<"Numero buscado\n";
                       imprimir_edad_dada(principal->lista,  principal->arbolEdad, numero);
                       break;
                   }
              case 6:
                   { 
                       cout <<"\n\tPor orden alfabetico\n";
                       imprimir_orden_alfabetico(principal->lista,principal->arbolAlfabetico);
                       break;
                   }
              case 7:
                   {
                       cout <<"\n\tPor edad\n";
                       imprimir_orden_edad(principal->lista, principal->arbolEdad); 
                       break;
                   }
              case 8:
                   {
                    
                     visualizarLista(principal->lista);
                     break;
                   }
              case 9:
                   {
                      imprimirOrdenBurbuja(principal);
                      break;
                   }
              case 10:
                   {
                      imprimirOrdenMezcla(principal);
                      break;
                   }
              case 11:
                   {
                      int  muestras, incremento;
                      do 
                      {
                           cout <<"\nEscriba el numero de muestras aproximado como minimo 10 y maximo "<< MAX_ELEMS<<"\n";
                           scanf ("%d", &muestras);  //el valor es aproziamdo
                      }while(muestras <10 || muestras>MAX_ELEMS+10);
                      incremento=(int)muestras/10; //se divide entre 10 
                      muestras=incremento*10; //y se le multiplica por 10 para sacar las muestras de nuevo
         
                      long inicio, final, final2;      //variables para el tiempo
                      int itera=0;
                      for (int t=incremento ;t<=muestras;t+=incremento)
                      {
                           inicio = GetTickCount();
                               vaciarListas(principal);  
                               insertarMasivo( principal, ORDENADO,ALEATORIO,t); 
                               //  imprimir_orden_edad(principal->lista, principal->arbolEdad); 
                               // printf ("\n\n\n\n");
                           final= GetTickCount();
                           iteracion[itera][0]=final-inicio;
                         
                           inicio = GetTickCount();
                               vaciarListas(principal);
                               insertarMasivo(principal, DESORDENADO,ALEATORIO,t);
                               ordenarArbolBurbuja( principal, principal->arbolEdad);
                               //imprimir_orden_edad(principal->lista, principal->arbolEdad); 
                               // printf ("\n\n\n\n");           
                            final= GetTickCount();
                            iteracion[itera][1]=final-inicio;
                         
                            inicio = GetTickCount();
                                vaciarListas(principal);
                                insertarMasivo(principal, DESORDENADO,ALEATORIO,t); 
                                ordenarArbolMezcla( principal, principal->arbolEdad);
                               // imprimir_orden_edad(principal->lista, principal->arbolEdad);
                               //  printf ("\n\n\n\n");
                                 
                             final= GetTickCount();
                             iteracion[itera][2]=final-inicio;
                             iteracion[itera][3]=t;
                             itera++;
                        }
                        printf ("\nOrdenado\tBurbuja\tMezcla\tmuestras\n\n");
                        for (int i=0;i<itera;i++)
                        {    for (int j=0;j<4;j++)
                                printf ("%d\t", iteracion[i][j]);
                             printf ("\n");
                        }   
                         break;
                       }
                     
                default :printf ("error opcion no valida");   break;       
        }
       }while(numero!=0);    
}

void insertarMasivo(p_principal principal,int orden, int edad, int muestras)
{
     int maximoNombre;
     char dni[10];
     int edadAlumno;
     int nota;
     for (int i=0; i<muestras;i++) 
     {
         if (edad==ALEATORIO)
            edadAlumno=((rand()%60)+20); //edad aleatoria entre 20 y 80
         else
             edadAlumno=20;
         for (int i=0; i<9;i++)         //numeros aleatorios para el dni
             dni[i]=((rand()%10)+48);
         dni[9]='\0';
         nota=((rand()%11));    //numero aleatorio para la nota
         
         maximoNombre=((rand()%5)+2);    //numero aleatorio apra la cadena nombre
         char nombre[maximoNombre];
         
         for (int i=0; i < maximoNombre;i++)      //caracteres aleatoriros para la cadena nombre
              nombre[i]=((rand() % 26)+97);       //se genera una cadena de carcteres aleatorios +97 codigo ascii
          nombre[maximoNombre]='\0';    
          if (orden==ORDENADO)
             insertar ( principal,  nombre,  dni,   edadAlumno,  nota,ORDENADO ); //inserto en la lista
          else
              insertar ( principal,  nombre,  dni,   edadAlumno,  nota,DESORDENADO ); //inserto en la lista
     }
}
