#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
typedef char tcad[30];
#include "TDA-Jugadores.hpp"
#include "baraja.hpp"


void menu(int&op);

int main()
{
//declaracion de variables para la gestion de la baraja
parchivo archivo;
tcola mazo;
bool mazo_creado;
int opbaraja;
//--------------
    int op;
    do
    {

        menu(op);
        switch(op)
        {
        case 1:
                menu_gestion_jugadores();
            break;
        case 2:
                do{
                menu_gestion_baraja(opbaraja);
                principal_baraja(opbaraja,archivo,mazo);
                }while (opbaraja!=4);
                mazo_creado=true;

            break;
       case 3:
                if(mazo_creado==true){
                    principal_juego();
                }else
                    cout<<"debe iniciar el mazo"<<endl;
                break;
        case 4:
            break;
        case 5:
            cout<<"Fin del Juego"<<endl;
            break;
        default:
            cout<<"Error de opcion"<<endl;
        }
    }
    while(op!=5);
    return 0;
}

void menu(int&op)
{
    cout<<"\n----Menu Principal----"<<endl;
    cout<<"1- Gestion de Jugadores"<<endl;
    cout<<"2- Gestion de Barajas"<<endl;
    cout<<"3- Jugar"<<endl;
    cout<<"4- Mostrar ranking de jugadores"<<endl;
    cout<<"5- Salir"<<endl;
    cout<<"Elegir Opcion"<<endl;
    cin>>op;
}

