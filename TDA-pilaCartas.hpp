
#include "tdaCola.hpp"

typedef struct tpila *ppila;

typedef struct tpila{
    tnaipe dato;
    ppila sig;
 };

void iniciar_pila(ppila &p);
void crear_nodo(ppila &nuevo,tnaipe valor);
void agregar_pila(ppila &p,tnaipe nuevo);
tnaipe quitar_pila(ppila &p);
tnaipe tope_pila(ppila p);
bool pila_vacia(ppila p);

void iniciar_pila(ppila &p)
{
 p=NULL;
}

void crear_nodo(ppila &nuevo,tnaipe valor)
{
    nuevo=new tpila;
    if (nuevo!=NULL)
    { nuevo->dato=valor;
      nuevo->sig=NULL;
    }
}

void agregar_pila(ppila &p,tnaipe valor)
{   ppila nuevo;
    crear_nodo(nuevo,valor);
    if (nuevo==NULL)
        cout << "PILA LLENA" << endl;
    else
    {   nuevo->sig=p;
        p=nuevo;
    }
}

tnaipe quitar_pila(ppila &p)
{ tnaipe extraido;
    ppila nodo;
    if (pila_vacia(p)==true)
        extraido=NULL;
    else
    { extraido=p->dato;
      nodo=p;
      p=p->sig;
      nodo->sig=NULL;
    delete(nodo);
    }
 return extraido;
}
tnaipe tope_pila(ppila p)
{ tnaipe tope;
 if (pila_vacia(p)==true)
 tope=0;
 else
 tope=p->dato;
 return tope;
}
bool pila_vacia(ppila p)
{
 return p==NULL;
}

