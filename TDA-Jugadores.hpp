
void menu_jugadores(int &op);
void menu_gestion_jugadores()
{
    int op;
      do
    {
        menu_jugadores(op);
        switch(op)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            cout<<"Fin de gestion de jugadores"<<endl;
            break;
        default:
            cout<<"Error de opcion"<<endl;
        }
    }
    while(op!=6);
}

void menu_jugadores(int &op)
{
    cout<<"----Menu de Gestion de Jugadores----"<<endl;
    cout<<"1- Agregar Jugador"<<endl;
    cout<<"2- Consultar Jugador"<<endl;
    cout<<"3- Modificar Jugador"<<endl;
    cout<<"4- Listar jugadores"<<endl;
    cout<<"5- Eliminar Jugador"<<endl;
    cout<<"6- Salir"<<endl;
    cout<<"Elegir Opcion"<<endl;
    cin>>op;

}
