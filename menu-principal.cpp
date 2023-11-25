#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
using namespace std;
typedef char tcad[30];
#include "tdaCola.hpp"
#include "TDA-listaMano.hpp"
#include "TDA-Jugadores.hpp"
#include "baraja.hpp"
#include "TDA-pilaCartas.hpp"
#include "tdaListaJugador.hpp"
#include "tdaJuego.hpp"
#include "arbol_ranking.hpp"


void menu(int&op);

int main()
{
srand(time(NULL));
//declaracion de variables para la gestion de la baraja
parchivo archivo;
tcola mazo;
bool mazo_creado;
int opbaraja;
//--------------
    int op;
    do
    {
        //system("cls");
        menu(op);
        switch(op)
        {
        case 1:
                menu_gestion_jugadores();
          //      system("pause");
            break;
        case 2:
                principal_baraja(opbaraja,archivo,mazo,mazo_creado);
          //      system("pause");

            break;
       case 3:
                if(mazo_creado==true){
                    principal_juego(mazo,mazo_creado);
            //        system("pause");
                }else
                    cout<<"debe iniciar el mazo"<<endl;
            //        system("pause");
                break;
        case 4:
            mostrar_ranking();
         //   system("pause");
            break;
        case 5:
            cout<<"Fin del Juego"<<endl;
            break;
        default:
            cout<<"Error de opcion"<<endl;
        }
    }while(op!=5);
    return 0;
}

void menu(int&op)
{
    cout<<"\n**EL CORAZON DE LA REINA**"<<endl;
    cout<<"\n----Menu Principal----"<<endl;
    cout<<"1- Gestion de Jugadores"<<endl;
    cout<<"2- Gestion de Barajas"<<endl;
    cout<<"3- Jugar"<<endl;
    cout<<"4- Mostrar ranking de jugadores"<<endl;
    cout<<"5- Salir"<<endl;
    cout<<"Elegir Opcion"<<endl;
    cin>>op;
}

