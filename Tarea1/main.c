#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
typedef struct nodo {

    int dato;
    struct nodo *siguiente, *anterior;
}nodo;

nodo *cabeza = NULL;
nodo *ultimo = NULL;

void Insertar();
void Mostrar();
void Eliminar();

int main()
{
    char opcion;

    do {

         menu();
         opcion = getch();

            switch(opcion){

        case '1':

                Insertar();

            break;

            case '2':

               Eliminar();
            break;

            case '3':


                Mostrar();

            break;

            case '4':

                exit(1);
        break;
            default:

                    printf("Opcion Incorrecta \n");
                break;

            }

    }while (opcion != '4');


    return 0;
}

void Insertar(){

    nodo *nuevo = (nodo*)malloc(sizeof(nodo));
    printf(" Ingrese un valor ");
    scanf("%d", &nuevo->dato);

    if (cabeza == NULL){

        cabeza = nuevo;
        cabeza->siguiente = NULL;
        cabeza->anterior = NULL;
        ultimo = cabeza;


    }else {

        ultimo->siguiente = nuevo;
        nuevo->siguiente = NULL;
        nuevo->anterior = ultimo;
        ultimo = nuevo;
    }

        printf("\nValor ingresado\n");
};

void Mostrar(){

    nodo *actual = (nodo*)malloc(sizeof(nodo));
    actual = cabeza;
    printf("\nValores: ");
    if (cabeza != NULL){

        while(actual != NULL){
            printf("%d ", actual->dato);
            actual = actual->siguiente;
        }
    }else {

        printf("\nLa lista esta vacia");
    }

};

void Eliminar(){

    nodo *actual = (nodo *)malloc(sizeof(nodo));
    actual = cabeza;
    nodo *aux = (nodo *)malloc(sizeof(nodo));
    aux = NULL;

    int buscar = 0;
    int encontrado = 0;

    printf( "Ingrese valor a eliminar: ") ;
    scanf("%d", &buscar);

    if (cabeza != NULL){

        while (actual != NULL && encontrado != 1){

            if (actual->dato == buscar){

               printf( "\nValor : " , buscar , " encontrado");

                if (actual == cabeza){

                    cabeza = cabeza->siguiente;
                    cabeza->anterior = NULL;


                }else if (actual == ultimo){

                aux->siguiente = NULL;
                ultimo = aux;

                }else {

                    aux->siguiente = actual->siguiente;
                    actual->siguiente->anterior = aux;

                }

                printf("Valor Eliminado");

                encontrado = 1;
            }
            aux = actual;
            actual = actual->siguiente;
        }

        if (!encontrado){

           printf( "\n Valor no encontrado");
        }
    }else {

        printf("Lista Vacia");
    }
};

void menu (){

    printf("\n\n          Menu: \n         ======\n\n");
    printf("1.- Insertar Elemento\n");
    printf("2.- Borrar Elemento\n");
    printf("3.- Mostrar Lista\n");
    printf("4.- Salir\n\n");
    printf("Elegir Opcion: "); fflush(stdout);
}
