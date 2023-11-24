/**
el objetivo de esta libreria es almacenar los naipes que se le asignaron al jugador
se toma la estructura de una lista doble

*/
//#include "tdaCola.hpp"

typedef struct tlista_mano *plista_mano;
typedef struct tlista_mano
{
    tnaipe dato;
    plista_mano ant;
    plista_mano sig;
};
typedef struct tlistadoble
{
    plista_mano inicio;
    plista_mano final;
    int contador;
};

void iniciar_lista_m(tlistadoble &lis);
void crear_nodo(plista_mano &nuevo,tnaipe naipe);
void agregar_m(tlistadoble &lis,tnaipe naipe);
void agregar_fin(tlistadoble &lis,tnaipe naipe);
void mostrar_lista_m(tlistadoble lis);
plista_mano quitar_nodo_cartas(tlistadoble &lis,tnaipe naipe);
bool lista_mano_vacia(tlistadoble lis);
plista_mano extraer_inicio(tlistadoble &lista);
plista_mano extraer_fin(tlistadoble &lista);


void iniciar_lista_m(tlistadoble &lis)
{
    lis.inicio=NULL;
    lis.final=NULL;
    lis.contador=0;
}
void crear_nodo_m(plista_mano &nuevo,tnaipe naipe)
{
    nuevo=new tlista_mano;
    if (nuevo!=NULL)
    {
        nuevo->dato=naipe;
        nuevo->sig=NULL;
        nuevo->ant=NULL;
    }
}

void agregar_m(tlistadoble &lis,tnaipe naipe)
{
    plista_mano nuevo;
    plista_mano i;
    crear_nodo_m(nuevo,naipe);

    if (lis.contador==0)
    {
        lis.inicio=nuevo;
        lis.final=nuevo;
        lis.contador++;
    }
    else
    {
        if(nuevo->dato.valor<lis.inicio->dato.valor)
        {
            nuevo->sig=lis.inicio;
            lis.inicio->ant=nuevo;
            lis.inicio=nuevo;
            lis.contador++;
        }
        else
        {
            if(nuevo->dato.valor>=lis.final->dato.valor)
            {
                lis.final->sig=nuevo;
                nuevo->ant=lis.final;
                lis.final=nuevo;
                lis.contador++;
            }
            else
            {
                for(i=lis.inicio->sig; i!=lis.final && nuevo->dato.valor > i->dato.valor; i=i->sig);
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
{
    plista_mano i;
    if (lis.contador==0)
        cout << "Lista Vacia"<< endl;
    else
    {
        i=lis.inicio;
        while (i->sig!=NULL)
        {
            cout << i->dato.valor<<"--"<<i->dato.palo << endl;
            i=i->sig;
        }
        cout << i->dato.valor<<"--"<<i->dato.palo << endl;
    }
}

bool lista_mano_vacia(tlistadoble lis)
{
    return lis.inicio==NULL;
}
plista_mano quitar_nodo_cartas(tlistadoble &lis,tnaipe naipe)
{
    plista_mano i,extraido;
    if(lis.inicio==NULL)
        extraido=NULL;
    else
    {
        if(lis.inicio->dato.valor==naipe.valor && strcmp(lis.inicio->dato.palo,naipe.palo)==0)
        {
            if(lis.inicio==lis.final)
            {
                extraido=lis.inicio;
                lis.inicio=NULL;
                lis.final=NULL;
                lis.contador--;
            }
            else
            {
                extraido=lis.inicio;
                lis.inicio=lis.inicio->sig;
                lis.inicio->ant=NULL;
                extraido->sig=NULL;
                lis.contador--;
            }
        }
        else
        {
            if(lis.final->dato.valor==naipe.valor && strcmp(lis.final->dato.palo,naipe.palo)==0)
            {
                extraido=lis.final;
                lis.final=lis.final->ant;
                lis.final->sig=NULL;
                extraido->ant=NULL;
                lis.contador--;
            }
            else
            {

                for(i=lis.inicio->sig; i!=lis.final && (i->dato.valor!= naipe.valor && strcmp(i->dato.palo,naipe.palo)!=0) ; i=i->sig);
                if(i!=lis.final)
                {
                    extraido=i;
                    (i->ant)->sig=extraido->sig;
                    (i->sig)->ant=extraido->ant;
                    extraido->sig=NULL;
                    extraido->ant=NULL;
                    lis.contador--;
                }
                else
                    extraido=NULL;

            }

        }


    }
    return extraido;
}


void agregar_fin(tlistadoble &lis,tnaipe naipe)
{
    plista_mano nuevo;

    crear_nodo_m(nuevo,naipe);

    if(lis.inicio==NULL)
    {
        lis.inicio=nuevo;
        lis.final=nuevo;
    }
    else
    {
        lis.final->sig=nuevo;
        nuevo->ant=lis.final;
        lis.final=nuevo;
    }

}

plista_mano extraer_inicio(tlistadoble &lista)
{
    plista_mano borrado;

    if(lista.inicio==NULL)
        borrado=NULL;
    else
    {
        if(lista.inicio==lista.final)
        {
            borrado=lista.inicio;
            lista.inicio=NULL;
            lista.final=NULL;
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
plista_mano extraer_fin(tlistadoble &lista)
{
    plista_mano borrado;

    if(lista.inicio==NULL)
        borrado=NULL;
    else
    {
        if(lista.inicio==lista.final)
        {
            borrado=lista.inicio;
            lista.inicio=NULL;
            lista.final=NULL;
        }
        else
        {
            borrado=lista.final;
            lista.final=lista.final->ant;
            lista.final->sig=NULL;
            borrado->ant=NULL;

        }
    }
    return borrado;

}
