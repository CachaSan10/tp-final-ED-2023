#include<iostream>
#include<stdio.h>
using namespace std;


#include "baraja.hpp"
#include "TDA-Jugadores.hpp"
#include "tdaListaJugador.hpp"

void principal_juego();
void menu_juego();
void seleccion_jugador(tlistaJ &lista_jugadores);



void principal_juego(){
tlistaJ lista_jugadores;
int op;
    do{
        menu_juego(op);
        switch(op){
        case 1:
            seleccion_jugador(lista_jugadores);//lista de jugadores elegidos ,archivo jugador
            break;
        case 2:
            repartir_cartas()//listas de jugadores cargada con los jugadores seleccionados,mazo
            break;
        case 3:
            iniciar_juego()//envio la lista,mazo
            break;
        }

    }while(op!=4);

}

void menu_juego(int op){
    cout<<"\n----Menu Principal----"<<endl;
    cout<<"1- elegir jugadores"<<endl;
    cout<<"2- repartir cartas"<<endl;
    cout<<"3- iniciar partida"<<endl;
    cout<<"4- Salir"<<endl;
    cout<<"Elegir Opcion"<<endl;
    cin>>op;
}

void seleccion_jugador(tlistaJ &lista_jugadores){
    int cant;
    cout<<"indique la cantidad de jugadores a seleccionar"<<endl;

}
