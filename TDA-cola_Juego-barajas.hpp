typedef struct tnodo *pnodo;

typedef struct tnodo
{
    char dato;
    pnodo sig;
};

typedef struct tcola
{
    pnodo inicio;
    pnodo fin;
};

void iniciar_cola(tcola &q)
{
    q.inicio=NULL;
    q.fin=NULL;
}

void crear_nodo(pnodo &nuevo,char valor)
{
    nuevo=new tnodo;
    if(nuevo != Null)
    {
        nuevo.dato=valor;
        nuevo->sig=NULL;
    }
}

bool cola_vacia(tcola q)
{
    q.inicio==NULL;
}

void agregar_cola(tcola &q,char valor)
{
    pnodo nuevo;
    crear_nodo(nuevo,valor);
    if(nuevo==NULL)
        cout<<"Cola LLena"<<endl;
    else
    {
        if(q.inicio==NULL)
        {
            q.inicio=nuevo;
            q.fin=nuevo;
        }
        else
        {
            q.fin->sig=nuevo;
            q.fin=nuevo;
        }
    }
}


char quitar_cola(tcola &q){
char aux;
pnodo eliminado;
    if(!cola_vacia(q))
    {
    eliminado=q.inicio;
    aux=eliminado->dato;
        if(q.inicio==q.fin){
            q.inicio=NULL;
            q.fin=NULL;
        }else{
            q.inicio=eliminado->sig;
            eliminado->sig=NULL;
        }
        delete(eliminado);
    }else
        q="?";
return aux;
}

char consultar_frente(tcola q){
char aux;
    if(!cola_vacia(q))
        aux=q.inicio->dato;
    else
        aux="?";
return aux;
}

char consultar_final(tcola q){
    char aux;
    if(!cola_vacia(q))
        aux=q.fin->dato;
    else
        aux="?";
return aux;
}

