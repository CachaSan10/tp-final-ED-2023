#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo
{
    int dato;
    pnodo sig;
    pnodo ant;
};

typedef struct tlista
{
    pnodo inicio;
    pnodo fin;
};

void menu(int &op);
void iniciar_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void agregar_inicio(tlista &lista,pnodo nuevo);
void agregar_fin(tlista &lista,pnodo nuevo);
void agregar_orden(tlista &lista,pnodo nuevo);
pnodo extraer_inicio(tlista &lista);
pnodo extraer_fin(tlista &lista);
pnodo extraer_especifico(tlista &lista, int valor);
bool buscar_nodo(tlista lista,int valor);
void mostrar_contenido(tlista lista);

int main()
{
    tlista lista;
    pnodo nuevo,borrado;
    int opcion,valor;
    iniciar_lista(lista);
    do
    {
        menu(opcion);
        switch(opcion)
        {
        case 1:
            crear_nodo(nuevo);
            agregar_inicio(lista,nuevo);
            break;
        case 2:
            crear_nodo(nuevo);
            agregar_fin(lista,nuevo);
            break;
        case 3:
            crear_nodo(nuevo);
            agregar_orden(lista,nuevo);
            break;
        case 4:
            borrado=extraer_inicio(lista);
            if(borrado!=NULL)
            {
                cout<<"\n Valor eliminado: "<<borrado->dato<<endl;
                delete(borrado);
            }
            else
                cout<<"Lista Vacia"<<endl;
            break;
        case 5:
            borrado=extraer_fin(lista);
            if(borrado!=NULL)
            {
                cout<<"\n Valor eliminado: "<<borrado->dato<<endl;
                delete(borrado);
            }
            else
                cout<<"Lista Vacia"<<endl;
            break;
        case 6:
            cout<<"Ingrese Valor eliminar: ";
            cin>>valor;
            borrado=extraer_especifico(lista,valor);
            if(borrado!=NULL)
            {
                cout<<"\n Valor eliminado: "<<borrado->dato<<endl;
                delete(borrado);
            }
            else
                cout<<"Lista Vacia"<<endl;
            break;
        case 7:
            cout<<"Ingrese Valor Buscar: ";
            cin>>valor;
            if(buscar_nodo(lista,valor))
                cout<<"Valor Encontrado"<<endl;
            else
                cout<<"Valor no encontrado"<<endl;
            break;
        case 8:
            mostrar_contenido(lista);
            break;
        case 9:
            cout<<"Fin del Programa"<<endl;
            break;
        default:
            cout<<"Opcion Incorrecta"<<endl;
            break;
        }
    }
    while(opcion!=9);
    return 0;
}


void menu(int &op)
{
    cout<<"\n 1) Agregar Inicio"<<endl;
    cout<<"2) Agregar Final"<<endl;
    cout<<"3) Agregar ordenado"<<endl;
    cout<<"4) Extraer Inicio"<<endl;
    cout<<"5) Extraer Fin"<<endl;
    cout<<"6) Extraer Nodo especifico"<<endl;
    cout<<"7) Buscar Valor"<<endl;
    cout<<"8) Mostrar Lista"<<endl;
    cout<<"9) Salir"<<endl;
    cout<<"Seleccione Opcion: ";
    cin>>op;
}



void iniciar_lista(tlista &lista)
{
    lista.inicio=NULL;
    lista.fin=NULL;

}

void crear_nodo(pnodo &nuevo)
{
    nuevo = new tnodo;
    if(nuevo!=NULL)
    {
        cout<<"Ingrese Valor: ";
        cin>>nuevo->dato;
        nuevo->ant=NULL;
        nuevo->sig=NULL;
    }
    else
        cout<<"Memoria LLena"<<endl;
}

void agregar_inicio(tlista &lista,pnodo nuevo)
{
    if(lista.inicio==NULL)
    {
        lista.inicio=nuevo;
        lista.fin=nuevo;
    }
    else
    {
        nuevo->sig=lista.inicio;
        lista.inicio->ant=nuevo;
        lista.inicio=nuevo;
    }
}

void agregar_fin(tlista &lista,pnodo nuevo)
{
    if(lista.inicio==NULL)
    {
        lista.inicio=nuevo;
        lista.fin=nuevo;
    }
    else
    {
        lista.fin->sig=nuevo;
        nuevo->ant=lista.fin;
        lista.fin=nuevo;
    }
}


void agregar_orden(tlista &lista,pnodo nuevo)
{
    {
        pnodo i;
        if (lista.inicio==NULL)
        {
            lista.inicio=nuevo;
            lista.fin=nuevo;

        }
        else
        {
            if (nuevo->dato < lista.inicio->dato)
            {
                nuevo->sig=lista.inicio;
                lista.inicio->ant=nuevo;
                lista.inicio=nuevo;
            }
            else if (nuevo->dato > lista.fin->dato)
            {
                lista.fin->sig=nuevo;
                nuevo->ant=lista.fin;
                lista.fin=nuevo;
            }
            else
            {
                for(i=lista.inicio->sig; i!=lista.fin && nuevo->dato > i->dato; i=i->sig);
                nuevo->sig=i;
                nuevo->ant=i->ant;
                (i->ant)->sig=nuevo;
                i->ant=nuevo;
            }
        }
    }

}


pnodo extraer_inicio(tlista &lista)
{
    pnodo borrado;

    if(lista.inicio==NULL)
        borrado=NULL;
    else
    {
        if(lista.inicio==lista.fin)
        {
            borrado=lista.inicio;
            lista.inicio=NULL;
            lista.fin=NULL;
        }
        else
        {
            borrado=lista.inicio;
            lista.inicio=lista.inicio->sig;
            lista.inicio->ant=NULL;
            borrado->sig=NULL;
        }
    }
    return borrado;
}



pnodo extraer_fin(tlista &lista)
{
    pnodo borrado;

    if(lista.inicio==NULL)
        borrado=NULL;
    else
    {
        if(lista.inicio==lista.fin)
        {
            borrado=lista.inicio;
            lista.inicio=NULL;
            lista.fin=NULL;
        }
        else
        {
            borrado=lista.fin;
            lista.fin=lista.fin->ant;
            lista.fin->sig=NULL;
            borrado->ant=NULL;

        }
    }
    return borrado;

}

pnodo extraer_especifico(tlista &lista, int valor)
{
    pnodo extraido,i;
    if(lista.inicio==NULL)
        extraido=NULL;
    else
    {
        if(lista.inicio->dato==valor)
        {
            if(lista.inicio==lista.fin)
            {
                extraido=lista.inicio;
                lista.inicio=NULL;
                lista.fin=NULL;
            }
            else
            {
                extraido=lista.inicio;
                lista.inicio=lista.inicio->sig;
                lista.inicio->ant=NULL;
                extraido->sig=NULL;
            }
        }
        else
        {

            if(lista.fin->dato == valor)
            {
                extraido=lista.fin;
                lista.fin=lista.fin->ant;
                lista.fin->sig=NULL;
                extraido->ant=NULL;
            }

            for(i=lista.inicio->sig; i!=lista.fin && i->dato!=valor; i=i->sig);
            if(i!=lista.fin)
            {
                extraido=i->sig;
                (i->ant)->sig=extraido->sig;
                (i->sig)->ant=extraido->ant;
                extraido->sig=NULL;
                extraido->ant=NULL;
            }
            else
                extraido=NULL;

        }
    }

    return extraido;
}

bool buscar_nodo(tlista lista,int valor)
{
    pnodo i=NULL;
    for(i=lista.inicio; i!=NULL && i->dato!=valor; i=i->sig);

    return i!=NULL;
}

void mostrar_contenido(tlista lista)
{
    pnodo i;
    if(lista.inicio!=NULL)
    {
        for(i=lista.inicio; i!=NULL; i=i->sig)
        {
            cout<<i->dato<<endl;
        }
    }
    else
        cout<<"Memoria Vacia"<<endl;
}
