#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

#include "TDA-Jugadores.hpp"

void menu(int&op);
int main()
{
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

            break;
        case 3:

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

