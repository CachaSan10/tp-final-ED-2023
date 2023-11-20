/**
esta libreria se utiliza para almacenar a los jugadores seleccionados

*/
#include "TDA-Jugadores.hpp"
#include "TDA-pilaCartas.hpp"
#include "TDA-listaMano.hpp"

typedef struct t_nodojugador *pnodojugador;
typedef struct t_nodojugador{
    tjugador dato;
    tpila naipes_ganados;//naipes que gana el jugador
    tlistadoble lista_cartas;
    pnodojugador sig;
};

typedef struct tlistaJ{
    pnodojugador inicio;
};


void iniciar_lista(tlistaJ &lis);
void agregar_valor(tlistaJ &lis,int a);
void crear_nodo(pnodo &nuevo,int dato);
bool existe_valor(pnodo lis,int valor);
void mostrar(tlistaJ lis);
bool lista_vacia(tlistaJ lis);
pnodo quitar_inicio(tlistaJ &lis);



void iniciar_lista(tlistaJ &lis){
    lis.inicio=NULL;
}
void agregar_valor(tlistaJ &lis,int a){
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
bool lista_vacia(tlistaJ lis){
    return lis.inicio==NULL;
}

pnodo quitar_inicio(tlistaJ &lis){
    pnodo extraido;
    extraido=lis.inicio;
    lis.inicio=extraido->sig;
    return extraido;
}


