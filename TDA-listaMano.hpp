/**
el objetivo de esta libreria es almacenar los naipes que se le asignaron al jugador
se toma la estructura de una lista doble

*/
//#include "tdaCola.hpp"

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

 void iniciar_lista_m(tlistadoble &lis);
 void crear_nodo(plista_mano &nuevo,tnaipe naipe);
 void agregar_m(tlistadoble &lis,tnaipe naipe);

 void mostrar_lista_m(tlistadoble lis);
plista_mano quitar_nodo_cartas(tlistadoble &lis,tnaipe naipe);
bool lista_mano_vacia(tlistadoble lis);

 void iniciar_lista_m(tlistadoble &lis)
{
 lis.inicio=NULL;
 lis.final=NULL;
 lis.contador=0;
}
void crear_nodo_m(plista_mano &nuevo,tnaipe naipe){
    nuevo=new tlista_mano;
    if (nuevo!=NULL){
        nuevo->dato=naipe;
        nuevo->sig=NULL;
    }
}

void agregar_m(tlistadoble &lis,tnaipe naipe)
{
plista_mano nuevo;
plista_mano i;
crear_nodo_m(nuevo,naipe);

if (lis.contador==0)
 { lis.inicio=nuevo;
   lis.final=nuevo;
   lis.contador++;
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
            lis.contador++;
        }else{
            for(i=lis.inicio->sig;i!=lis.final && nuevo->dato.valor > i->dato.valor;i=i->sig);
            nuevo->sig=i;
            nuevo->ant=i->ant;
            (i->ant)->sig=nuevo;
            i->ant=nuevo;
            lis.contador++;
        }
    }
}
}



void mostrar_lista_m(tlistadoble lis)
{ plista_mano i;
 if (lis.contador==0)
    cout << "Lista Vacia"<< endl;
 else
 { i=lis.inicio;
 while (i->sig!=NULL)
 { cout << i->dato.valor<<"--"<<i->dato.palo << endl;
   i=i->sig;
 }
 cout << i->dato.valor<<"--"<<i->dato.palo << endl;
 }
}

bool lista_mano_vacia(tlistadoble lis){
    return lis.contador==0;
}
plista_mano quitar_nodo_cartas(tlistadoble &lis,tnaipe naipe)
{ plista_mano i,extraido;
 if (lis.contador==0)
    extraido=NULL;
 else
 {  if(lis.final->dato.valor==i->dato.valor && strcmp(lis.final->dato.palo,naipe.palo)!=0){
        extraido=lis.final;
        lis.final=extraido->ant;
        lis.final->sig=extraido->sig;
        extraido->ant=NULL;
        extraido->sig=NULL;
        lis.contador--;
    }

    for(i=lis.inicio;i!=lis.final && i->dato.valor!= naipe.valor && strcmp(i->dato.palo,naipe.palo)!=0 ;i=i->sig);
    if(i!=lis.final){
        extraido=i;
        i->ant=extraido->sig;
        (i->sig)->ant=extraido->ant;
        extraido->sig=NULL;
        extraido->ant=NULL;
        lis.contador--;
    }
 }
 return extraido;
}
