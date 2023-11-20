#include<iostream>
#include<stdio.h>
using namespace std;


//#include "baraja.hpp"
//#include "TDA-Jugadores.hpp"
#include "tdaListaJugador.hpp"

void principal_juego();
void menu_juego(int &op);
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
            //repartir_cartas()//listas de jugadores cargada con los jugadores seleccionados,mazo
            break;
        case 3:
            //iniciar_juego()//envio la lista,mazo
            break;
        }

    }while(op!=4);

}

void menu_juego(int &op){
    cout<<"\n----Menu Principal----"<<endl;
    cout<<"1- elegir jugadores"<<endl;
    cout<<"2- repartir cartas"<<endl;
    cout<<"3- iniciar partida"<<endl;
    cout<<"4- Salir"<<endl;
    cout<<"Elegir Opcion"<<endl;
    cin>>op;
}

void seleccion_jugador(tlistaJ &lista_jugadores){
    //se inicia la lista en la que se almacenan los jugadores que van a participar de la partida
    iniciar_lista_jug(lista_jugadores);
    //archivo donde se almacenan los jugadores
    parchivo_jugador jugadores;
    //objeto auxiliar de tipo jugador
    tjugador player;
    //bandera logica cambia de estado de acuerdo a la existencia o no del registro buscado
    bool existe=false;
    //objetos auxiliares de tipo cadena
    tcad consulta,cadena;
    //variable que indica la cantidad de jugadores a seleccionar
    int cant;
    //realizo la apertura del archivo


    cout<<"indique la cantidad de jugadores a seleccionar: "<<endl;
    cin>>cant;
    //se repite la cantidad de veces que el usuario solicita seleccionar jugadores;
    for(int i=cant;i>0;i--){
            existe=false;
            //apertuda del archivo para solo lectura
            jugadores=fopen("archivo_binario/jugadores.txt","rb");
            fgets(cadena,30,stdin);
            strtok(cadena,"\n");
            //solicito el ingreso del nickname
            cout<<"Ingrese Nickname de jugador a selecionar: ";
            fgets(consulta,30,stdin);//guardo el dato a comparar
        //consulto si se logo la apertura del archivo
           if (jugadores!=NULL){
            //mientras que no me encuentre en el final del archivo y existe sea falso repito
            while (!feof(jugadores)&& existe==false)
            {
                fread(&player,sizeof(player),1,jugadores);
                //comparo el nikmame del recorrido con el buscado
                if (strcmp(player.nickname,consulta)==0)
                {   agregar_valor(lista_jugadores,player);
                    cout<<"jugador seleccionado"<<endl;
                    existe=true;
                }
            }
            fclose(jugadores);
            if(existe==false)
            cout<<"El jugador no existe"<<endl;
           }
    }
    cout<<"-- SELECCIONADOS PARA PARTIDA--"<<endl;
    mostrar_lis_jug(lista_jugadores.inicio);
}

