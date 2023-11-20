/**
el objetivo de esta libreria es almacenar los naipes que se le asignaron al jugador
se toma la estructura de una lista doble

*/
#include "tdaCola.hpp"

typedef struct tlista_mano *plista_mano;
typedef struct tlista_mano{
 tnaipe dato;
 plista_mano ant;
 plista_mano sig;
 };
typedef struct tlistadoble{
 plista_mano inicio;
 plista_mano final;
int contador;
 };

 void iniciar_lista(tlistadoble &lis);
 void crear_nodo(plista_mano &nuevo,tnaipe naipe);
 void agregar(tlistadoble &lis, plista_mano nuevo);
 plista_mano quitar_nodo(tlistadoble &lis);
 void mostrar_lista(tlistadoble lis);
pnodo quitar(tlistadoble &lis,tnaipe naipe);


 void iniciar_lista(tlistadoble &lis)
{
 lis.inicio=NULL;
 lis.final=NULL;
 lis.contador=0;
}
void crear_nodo(plista_mano &nuevo,tnaipe naipe){
    nuevo=new tlista_mano;
    if (nuevo!=NULL){
        nuevo->dato=naipe;
        nuevo->sig=NULL;
    }
}

void agregar(tlistadoble &lis, plista_mano nuevo)
{
plista_mano i;
if (lis.contador==0)
 { lis.inicio=nuevo;
   lis.final=nuevo;
 }
 else
 { if(nuevo->dato.valor<lis.inicio->dato.valor){
        nuevo->sig=lis.inicio;
        lis.inicio->ant=nuevo;
        lis.inicio=nuevo;
        lis.contador++;
    }else{
        if(nuevo->dato.valor>=lis.final->dato.valor){
            lis.final->sig=nuevo;
            nuevo->ant=lis.final;
            lis.final=nuevo;
        }else{
            for(i=lis.inicio->sig;i!=lis.final && nuevo->dato.valor > i->dato.valor;i=i->sig);
            nuevo->sig=i;
            nuevo->ant=i->ant;
            (i->ant)->sig=nuevo;
            i->ant=nuevo;
        }
    }
}

pnodo quitar(tlistadoble &lis,tnaipe naipe)
{ plista_mano i,extraido;
 if (lis.contador==0)
    aux=NULL;
 else
 {
    for(i=lis.inicio;i!=lis.final && i->dato.valor!= naipe.valor;i=i->sig);
    if(i!=lis.final){
        extraido=i;
        i->ant=extraido->sig;
        (i->sig)->ant=extraido->ant;
        extraido->sig=NULL;
        extraido->ant=NULL;
    }
 }
}

void mostrar_lista(tlistadoble lis)
{ pnodo i;
 if (lis.contador==0)
 cout << “Lista Vacia” << endl;
 else
 { i=lis.inicio;
 while (i->sig!=lis.inicio)
 { cout << i->dato << endl;
 i=i->sig; }
 cout << i->dato << endl;
 }
}
