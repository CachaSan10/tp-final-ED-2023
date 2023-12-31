
typedef struct tjugador
{
    tcad apellido;
    tcad nombre;
    tcad nickname;
    int puntaje;
    int cant_partida_ganadas;
};

typedef FILE *parchivo_jugador;


void menu_jugadores(int &op);
void agregar_jugador(parchivo_jugador jugador);
void cargar_jugador(tjugador &jugador);
void modificar_datos_jugador(tjugador &jugador);
void mostrar_jugadores(parchivo_jugador jugador);
void consultar_jugador(parchivo_jugador jugadores, tcad buscado);
void modificar_jugador(parchivo_jugador jugadores, tcad buscado);
void borrar_jugador(parchivo_jugador jugadores, tcad buscado);
bool existe_jugador(tcad buscado);
bool validar_cadena(tcad cadena);
bool validar_nickname(tcad cadena);
void menu_gestion_jugadores()
{
    int op;
    parchivo_jugador jugadores;
    tcad consulta,cadena;
    do
    {
        //system("cls");
        menu_jugadores(op);
        switch(op)
        {
        case 1:
            agregar_jugador(jugadores);
            //system("pause");
            break;
        case 2:
            fgets(cadena,30,stdin);
            strtok(cadena,"\n");
            cout<<"Ingrese Nickname de jugador a consultar: ";
            fgets(consulta,30,stdin);
            consultar_jugador(jugadores,consulta);
            //system("pause");
            break;
        case 3:
            fgets(cadena,30,stdin);
            strtok(cadena,"\n");
            cout<<"Ingrese Nickname de jugador a consultar: ";
            fgets(consulta,30,stdin);
            modificar_jugador(jugadores,consulta);
            //system("pause");
            break;
        case 4:
            mostrar_jugadores(jugadores);
            //system("pause");
            break;

        case 5:
            fgets(cadena,30,stdin);
            strtok(cadena,"\n");
            cout<<"Ingrese Nickname de jugador a consultar: ";
            fgets(consulta,30,stdin);
            borrar_jugador( jugadores, consulta);
            //system("pause");
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
    cout<<"\n----Menu de Gestion de Jugadores----"<<endl;
    cout<<"1- Agregar Jugador"<<endl;
    cout<<"2- Consultar Jugador"<<endl;
    cout<<"3- Modificar Jugador"<<endl;
    cout<<"4- Listar jugadores"<<endl;
    cout<<"5- Eliminar Jugador"<<endl;
    cout<<"6- Salir"<<endl;
    cout<<"Elegir Opcion"<<endl;
    cin>>op;

}

void cargar_jugador(tjugador &j)
{   bool nickname_valido=false;
    tcad cadena;
    j.puntaje=0;
    j.cant_partida_ganadas=0;
    fgets(cadena,30,stdin);
    strtok(cadena,"\n"); //Captura los saltos de lineas
    do
    {
        cout << "Ingrese apellido: ";
        fgets(j.apellido,30,stdin);
        fflush(stdin);
        if(validar_cadena(j.apellido))
            cout<<"Apellido valido"<<endl;
        else
            cout<<"Apellido vacio o no valido "<<endl;
    }while(validar_cadena(j.apellido)==false);
    do
    {
        cout << "Ingrese nombre: ";
        fgets(j.nombre,30,stdin);
        fflush(stdin);
        if(validar_cadena(j.nombre))
            cout<<"Nombre valido"<<endl;
        else
            cout<<"Nombre vacio o no valido "<<endl;
    }while(validar_cadena(j.nombre)==false);

     do
    {
       cout << "Ingrese nickname: ";
        fgets(j.nickname,30,stdin);
        fflush(stdin);
        if(existe_jugador(j.nickname)==false)
            {if(validar_nickname(j.nickname)){
                cout<<"Nickname valido"<<endl;
                nickname_valido=true;
            }else
                cout<<"Nombre vacio o no valido por que no posee al menos 3 numeros o no tiene por lo menos 6 caracteres el nickname"<<endl;
            }else
                cout<<"El nickname esta registrado"<<endl;
    }while(nickname_valido==false);

}

void agregar_jugador(parchivo_jugador jugadores)
{
    tjugador jugador;
    int cantidad;
    jugadores=fopen("archivo_binario/jugadores.txt","ab");//AKI
    cout << "Cuántos registros desea guardar: ";
    cin >> cantidad;
    while (cantidad>0)
    {

        cargar_jugador(jugador);
        fwrite(&jugador,sizeof(jugador),1,jugadores);
        cantidad--;
    }
    fclose(jugadores);
}

void mostrar_jugadores(parchivo_jugador jugadores)
{
    tjugador jugador;
    jugadores=fopen("archivo_binario/jugadores.txt","rb");
    if (jugadores==NULL)
        cout << "Archivo Inexistente" << endl;
    else
    {
        while (!feof(jugadores))
        {
            fread(&jugador,sizeof(jugador),1,jugadores);
            if (!feof(jugadores))
            {
                cout<<"\n---------------------------------";
                cout <<"\nApellido: "<< jugador.apellido;
                cout <<"\nNombre: "<< jugador.nombre;
                cout <<"\nNickname: "<< jugador.nickname;
                cout <<"\nPuntaje: "<< jugador.puntaje;
                cout <<"\nCantidad de Partida ganada: "<< jugador.cant_partida_ganadas;

            }
        }
    }
    fclose(jugadores);
}

void consultar_jugador(parchivo_jugador jugadores, tcad buscado)
{
    tjugador jugador;
    bool existe=false;
    jugadores=fopen("archivo_binario/jugadores.txt","rb");
    if (jugadores!=NULL)
        while (!feof(jugadores)&& existe==false)
        {
            fread(&jugador,sizeof(jugador),1,jugadores);
            if (strcmp(jugador.nickname,buscado)==0)
            {
                cout <<"\nApellido: "<< jugador.apellido << endl;
                cout <<"Nombre: "<< jugador.nombre << endl;
                cout <<"Puntaje: "<< jugador.puntaje << endl;
                cout <<"Cantidad de Partida ganada: "<< jugador.cant_partida_ganadas << endl;

                existe=true;
            }
        }

    if(existe==false)
        cout<<"El jugador no existe"<<endl;
    fclose(jugadores);
}

void modificar_datos_jugador(tjugador& j)
{
    tcad cadena;
    fgets(cadena,30,stdin);
    strtok(cadena,"\n"); //Captura los saltos de lineas
     do
    {
        cout << "Ingrese apellido: ";
        fgets(j.apellido,30,stdin);
        fflush(stdin);
        if(validar_cadena(j.apellido))
            cout<<"Apellido valido"<<endl;
        else
            cout<<"Apellido vacio o no valido "<<endl;
    }while(validar_cadena(j.apellido)==false);
    do
    {
        cout << "Ingrese nombre: ";
        fgets(j.nombre,30,stdin);
        fflush(stdin);
        if(validar_cadena(j.nombre))
            cout<<"Nombre valido"<<endl;
        else
            cout<<"Nombre vacio o no valido "<<endl;
    }while(validar_cadena(j.nombre)==false);
}

void modificar_jugador(parchivo_jugador jugadores, tcad buscado)
{
    tjugador j;
    bool band=false;
    jugadores=fopen("archivo_binario/jugadores.txt","rb+");
    if (jugadores==NULL)
        cout << "Archivo Inexistente" << endl;
    else
    {
        while (!feof(jugadores)&& band==false)
        {
            fread(&j,sizeof(j),1,jugadores);
            if (strcmp(j.nickname,buscado)==0)
                band=true;
        }
        if (band==true)
        {
            modificar_datos_jugador(j);

            fseek(jugadores,-sizeof(j),1);
            fwrite(&j,sizeof(j),1,jugadores);
        }
        else
            cout << "REGISTRO NO ENCONTRADO" << endl;
    }
    fclose(jugadores);
}

void borrar_jugador(parchivo_jugador jugadores, tcad buscado)
{
    tjugador j;
    parchivo_jugador aux;
    bool band=false;
    jugadores=fopen("archivo_binario/jugadores.txt","rb");
    aux=fopen("archivo_binario/jugadores_temporal.txt","w");
    if (jugadores!=NULL)
    {
        while (!feof(jugadores))
        {
            fread(&j,sizeof(j),1,jugadores);
            if (strcmp(j.nickname,buscado)!=0 && !feof(jugadores))
                fwrite(&j,sizeof(j),1,aux);
        }
        fclose(aux);
        fclose(jugadores);
        if (remove("archivo_binario/jugadores.txt")==0)
        {
            cout << "ELIMINADO EXITOSAMENTE" << endl;
            if (rename("archivo_binario/jugadores_temporal.txt","archivo_binario/jugadores.txt")==0)
                cout << "RENOMBRADO EXITOSAMENTE" << endl;
            else
                cout << "ERROR AL RENOMBRAR" << endl;
        }
        else
            cout << "ERROR AL ELIMINAR" << endl;
    }
}

bool existe_jugador(tcad buscado)
{
    parchivo_jugador jugadores;
    tjugador jugador;
    bool existe=false;
    jugadores=fopen("archivo_binario/jugadores.txt","rb");
    if (jugadores!=NULL)
        while (!feof(jugadores) && existe==false)
        {
            fread(&jugador,sizeof(jugador),1,jugadores);
            if (strcmp(jugador.nickname,buscado)==0)
            {
                existe=true;
            }
        }
    fclose(jugadores);
    return existe;
}

bool validar_cadena(tcad cadena)
{
    bool valido=true;
    int i;
    if(strlen(cadena)<3)
        valido = false;
    else
    {
        for(i=0; i < strlen(cadena)-1 && valido==true; i++)
        {
            cadena[i]= tolower(cadena[i]);
            if(!((cadena[i]>='a' && cadena[i]<='z') || cadena[i]==' '))
                valido=false;
        }
    }
    return valido;
}

bool validar_nickname(tcad cadena)
{
    int i,cant_num=0;
    bool valido=true;
    if(strlen(cadena)<6)
        valido = false;
    else
    {
        for(i=0; i < strlen(cadena)-1 && valido==true; i++)
        {
            cadena[i]= tolower(cadena[i]);
            if(cadena[i]>='0' && cadena[i]<='9')
                cant_num++;
        }
        if(cant_num<3)
            valido=false;
    }
    return valido;
}

void actualizar_puntaje_cant_ganados_jugador(parchivo_jugador jugadores, tcad nickname,int puntaje)
{
    tjugador j;
    bool band=false;
    jugadores=fopen("archivo_binario/jugadores.txt","rb+");
    if (jugadores==NULL)
        cout << "Archivo Inexistente" << endl;
    else
    {
        while (!feof(jugadores)&& band==false)
        {
            fread(&j,sizeof(j),1,jugadores);
            if (strcmp(j.nickname,nickname)==0)
                band=true;
        }
        if (band==true)
        {
            j.puntaje+=puntaje;
            j.cant_partida_ganadas++;
            fseek(jugadores,-sizeof(j),1);
            fwrite(&j,sizeof(j),1,jugadores);
        }
        else
            cout << "REGISTRO NO ENCONTRADO" << endl;
    }
    fclose(jugadores);
}
