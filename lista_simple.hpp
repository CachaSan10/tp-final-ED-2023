#include<iostream>
#include<stdio.h>
#include <cstdlib>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
    int dato;
    pnodo sig;
};

typedef struct tlista{
    pnodo inicio;
};


void iniciar_lista(tlista &lis);
void agregar_valor(tlista &lis,int a);
void crear_nodo(pnodo &nuevo,int dato);
bool existe_valor(pnodo lis,int valor);
void mostrar(tlista lis);
bool lista_vacia(tlista lis);
pnodo quitar_inicio(tlista &lis);
void agregar_fin_valor(tlista &lis,int a);


void iniciar_lista(tlista &lis){
    lis.inicio=NULL;
}
void agregar_valor(tlista &lis,int a){
    pnodo nuevo;
    crear_nodo(nuevo,a);
    if(lis.inicio==NULL)
        lis.inicio=nuevo;
    else{
        nuevo->sig=lis.inicio;
        lis.inicio=nuevo;
    }
}
void crear_nodo(pnodo &nuevo,int dato){
    nuevo=new tnodo;
    if (nuevo!=NULL){
        nuevo->dato=dato;
        nuevo->sig=NULL;
    }else{
        cout<<"sin espacio de memoria"<<endl;
    }
}
bool existe_valor(pnodo lis,int valor){
    pnodo i;
    bool encontrado= false;
    if(lis!=NULL){
        for(i=lis;i!=NULL&&encontrado==false;i=i->sig){
            if(i->dato==valor)
                encontrado=true;
        }
    }
    return encontrado;
}
void mostrar(pnodo a){
   pnodo i;
  if (a!=NULL)
  for(i=a;i!=NULL;i=i->sig)
  cout << "Nodo: " << i->dato << endl;
  else
  cout << "LISTA VACIA";
}
bool lista_vacia(tlista lis){
    return lis.inicio==NULL;
}

pnodo quitar_inicio(tlista &lis){
    pnodo extraido;
    if(lis.inicio==NULL)
        extraido=NULL;
    else{
        extraido=lis.inicio;
        lis.inicio=extraido->sig;
        extraido->sig=NULL;
    }
    return extraido;
}

void agregar_fin_valor(tlista &lis,int a){
    pnodo nuevo,i;
    crear_nodo(nuevo,a);
    if(lista_vacia(lis)==true)
        lis.inicio=nuevo;
    else{
        for(i=lis.inicio;i->sig!=NULL;i=i->sig);
        i->sig=nuevo;
    }
}
