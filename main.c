#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
     int legajo;
     char nombre[20];
     int edad;
} persona;

typedef struct nodoArbol
{
    persona dato;
    struct nodoArbol* derec;
    struct nodoArbol* izq;
} nodoArbol;

typedef struct
{
    persona dato;
    struct nodoSimple* siguiente;
} nodoSimple;


nodoArbol* crearNodo(persona informacion);
nodoArbol* agregarAlArbolPorLegajo (nodoArbol* arbol, nodoArbol* nuevoNodo);
nodoArbol* cargarArbol (nodoArbol* arbol);
void mostrarArbolPersona(nodoArbol* arbol);
void mostrarUno(nodoArbol* arbol);

//simple
nodoSimple* pasarDatos(nodoArbol* arbol,nodoSimple* lista);
void mostrarListaSimple(nodoSimple* lista);
void mostrarUnoSimple(nodoSimple* lista);



///             Árbol Binario de Búsqueda (ABB)

int main()
{

    nodoArbol* arbol =NULL;
    arbol=cargarArbol(arbol);

    mostrarArbolPersona(arbol);

    printf("\nEJERCICIO PASAR DATOS:");

    nodoSimple* lista = NULL;
    lista=pasarDatos(arbol,lista);

    printf("%s", lista->dato.nombre);

    printf("\nLISTA:");
    mostrarListaSimple(lista);







    return 0;
}






/// A)

void mostrarMenorAMayor(nodoArbol* arbol)
{
    if(arbol!=NULL)
    {
        mostrarMenorAMayor(arbol->izq);
        printf("%d - ", arbol->dato);
        mostrarMenorAMayor(arbol->derec);
    }
}

/// B)

nodoArbol* crearNodo(persona informacion)
{

    nodoArbol* aux= (nodoArbol*)malloc(sizeof(nodoArbol));
    aux->dato= informacion;
    aux->derec=NULL;
    aux->izq=NULL;

return aux;
}

nodoArbol* agregarAlArbolPorLegajo (nodoArbol* arbol, nodoArbol* nuevoNodo)
{
    if(arbol==NULL)
    {
        arbol=nuevoNodo;

    }else if (nuevoNodo->dato.legajo <= arbol->dato.legajo)
    {
        arbol->izq= agregarAlArbolPorLegajo(arbol->izq, nuevoNodo);
    }else
    {
        arbol->derec= agregarAlArbolPorLegajo(arbol->derec, nuevoNodo);
    }
 return arbol;
}



nodoArbol* cargarArbol (nodoArbol* arbol)
{
    persona informacion;
    char op='s';

    while(op=='s')
    {
        printf("NOMBRE: ");
        fflush(stdin);
        gets(informacion.nombre);
        printf("\nEDAD:");
        scanf("%i", &informacion.edad);
        printf("\nLEGAJO:");
        scanf("%i", &informacion.legajo);

        nodoArbol* nuevo= crearNodo(informacion);
        arbol= agregarAlArbolPorLegajo(arbol, nuevo);

        printf("\nSEGUIR S/N:");
        fflush(stdin);
        scanf("%c",&op);


    }

return arbol;
}


void mostrarArbolPersona(nodoArbol* arbol)
{
    if(arbol!=NULL)
    {
        mostrarArbolPersona(arbol->izq);
        mostrarUno(arbol);
        mostrarArbolPersona(arbol->derec);
    }
}

void mostrarUno(nodoArbol* arbol)
{
        printf("NOMBRE: %s - ", arbol->dato.nombre);
        printf("EDAD:%i - ", arbol->dato.edad);
        printf("LEGAJO:%i - ", arbol->dato.legajo);
        printf("\n");
}

nodoSimple* crearNodoSimple(persona info)
{
    nodoSimple* aux = (nodoSimple*)malloc(sizeof(nodoSimple));
    aux->dato = info;
    aux->siguiente = NULL;
    return aux;
}

nodoSimple* agregarPpioSimple(nodoSimple* lista, nodoSimple* nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}

nodoSimple* pasarDatos(nodoArbol* arbol, nodoSimple* lista)
{
    if(arbol != NULL)
    {
        nodoSimple* nuevo = crearNodoSimple(arbol->dato);
        lista = agregarPpioSimple(lista, nuevo);

        lista = pasarDatos(arbol->izq,lista);
        lista = pasarDatos(arbol->derec,lista);
    }

    return lista;
}

void mostrarListaSimple(nodoSimple* lista)
{
    nodoSimple* aux = lista;
    while(aux)
    {
        mostrarUnoSimple(aux);
        aux = aux->siguiente;
    }
}


void mostrarUnoSimple(nodoSimple* lista)
{
    printf("\nNOMBRE: %s", lista->dato.nombre);
    printf("EDAD: %i", lista->dato.edad);
    printf("LEGAJO: %i", lista->dato.legajo);
}

