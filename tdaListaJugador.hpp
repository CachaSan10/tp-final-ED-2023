/**
esta libreria se utiliza para almacenar a los jugadores seleccionados

*/
//#include "TDA-Jugadores.hpp"
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
    int cant;
};


void iniciar_lista_jug(tlistaJ &lis);
void agregar_valor(tlistaJ &lis,tjugador a);
void crear_nodo_jug(pnodojugador &nuevo,tjugador dato);
bool existe_valor(tlistaJ lis,tjugador valor);
void mostrar_lis_jug(pnodojugador a);
bool lista_vacia_j(tlistaJ lis);
pnodojugador quitar_inicio(tlistaJ &lis);



void iniciar_lista_jug(tlistaJ &lis){
    lis.inicio=NULL;
    lis.cant=0;
}
void agregar_valor(tlistaJ &lis,tjugador a){
    pnodojugador nuevo;
    crear_nodo_jug(nuevo,a);
    if(lis.inicio==NULL){
        lis.inicio=nuevo;
        lis.cant++;
    }else{
        nuevo->sig=lis.inicio;
        lis.inicio=nuevo;
        lis.cant++;
    }
}
void crear_nodo_jug(pnodojugador &nuevo,tjugador dato){
    nuevo=new t_nodojugador;
    if (nuevo!=NULL){
        nuevo->dato=dato;
        nuevo->sig=NULL;
    }else{
        cout<<"sin espacio de memoria"<<endl;
    }
}
bool existe_valor(pnodojugador lis,pnodojugador valor){
    pnodojugador i;
    bool encontrado= false;
    if(lis!=NULL){
        for(i=lis;i!=NULL&&encontrado==false;i=i->sig){
            if(i->dato.nickname==valor->dato.nickname)
                encontrado=true;
        }
    }
    return encontrado;
}
void mostrar_lis_jug(pnodojugador a){
   pnodojugador i;
  if (a!=NULL)
  { for(i=a;i!=NULL;i=i->sig)
        cout << "Nodo: " << i->dato.nickname << endl;
  }else
    cout << "LISTA VACIA";
}
bool lista_vacia_j(tlistaJ lis){
    return lis.inicio==NULL;
}

pnodojugador quitar_inicio(tlistaJ &lis){
    pnodojugador extraido;
    extraido=lis.inicio;
    lis.inicio=extraido->sig;
    lis.cant--;
    return extraido;
}


