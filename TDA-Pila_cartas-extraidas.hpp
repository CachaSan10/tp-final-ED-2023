const int MAX=10;
typedef int contenedor[MAX];

typedef struct tcola{
    contenedor datos;
    int cont;
    int frente;
    int fin;
};

void iniciar_cola(tcola &q);
void agregar_cola(tcola &q, int nuevo);
int quitar_cola(tcola &q,int nuevo);
int siguiente(int indice);
bool cola_llena(tcola q);
bool cola_vacia(tcola q);
int consultar_frente(tcola q);
int consultar_final(tcola q);

void iniciar_cola(tcola &q){
q.frente=0; //frente
q.fin=0; //final
q.cont = 0; //contador
}

int siguiente(int indice){
    if(indice==MAX-1)
        return 0;
    else
        return (indice+1);
}

bool cola_llena(tcola q){
return (q.cont==MAX);
}

bool cola_vacia(tcola q){
return (q.cont==0);
}

void agregar_cola(tcola&q,int nuevo){
    if(cola_llena(q))
        cout<<"Cola Completa"<<endl;
    else{
        q.fin= siguiente(q.fin);
        q.datos[q.fin]=nuevo;
        q.cont++;
    }
}

int quitar_cola(tcola&q){
int aux;
        if(cola_vacia(q))
            aux=-9999;
        else{
        q.frente=siguiente(q.frente);
        q.cont--;
        aux=q.datos[q.frente];
        }
    return aux;
}

int consultar_frente(tcola q){
int consultado;
    if(cola_vacia(q))
        consultado=-999;
    else
        consultado=q.datos[siguiente(q.frente)];
    return consultado;
}

int consultar_final(tcola q){
int consultado;
    if(cola_vacia(q))
        consultado=-999;
    else
        consultado=q.datos[q.fin];
    return consultado;
}


