/**
variante en la que se prioriza la velocidad
*/
#include<iostream>
#include<stdio.h>
using namespace std;


//#include "TDA-Jugadores.hpp"




typedef struct tmazo *pmazo;//nodo

//dato a registrar por nodo
typedef struct tnaipe{
    int valor;
    tcad palo;
    int punto;
    bool comodin;
};
//definicicion de puntero
typedef struct tmazo{
    tnaipe naipe;
    pmazo sig;
};
//definicion de cola
typedef struct tcola{
    pmazo frente;
    pmazo final;
};
//declaraciones de metodos
void iniciar_cola(tcola &q);
void agregar_cola(tcola &q,pmazo nuevo);
bool cola_vacia(tcola q);
pmazo  frente_cola(tcola q);
pmazo final_cola(tcola q);
pmazo quitar_cola(tcola &q);


void iniciar_cola(tcola &q){
    q.frente=NULL;
    q.final=NULL;
}
void agregar_cola(tcola &q,pmazo nuevo){
        if(q.frente==NULL){
            q.frente=nuevo;
            q.final=nuevo;
        }else {
            q.final->sig=nuevo;//el nuevo dato lo agrego al final de la lista
            q.final=nuevo;
        }

}

bool cola_vacia(tcola q){
    return q.frente==NULL;
}

//consulto el frente de la cola
pmazo frente_cola(tcola q){
    return q.frente;
}
//consulto el frente de la cola
pmazo final_cola(tcola q){
    return q.final;
}


pmazo quitar_cola(tcola &q){
    pmazo aux;
    if(cola_vacia(q)==true)
        aux=NULL;
    else{
        if(q.frente==q.final){//contiene un solo elemento
            aux=q.frente;
            q.frente=NULL;
            q.final=NULL;
        }else{
            aux=q.frente;
            q.frente=aux->sig;
            aux->sig=NULL;
        }
    }
    return aux;
}


