

typedef struct tnodo_arbol *parbol;
typedef struct tnodo_arbol
{
    tjugador jugador;
    parbol izq;
    parbol der;
};

void mostrar_ranking();

void mostrar_jugador_arbol(tjugador j);
void insercion(parbol &a,parbol nuevo);

void enorden(parbol a);
//Inicia el arbol
void iniciar_arbol(parbol &a)
{
    a=NULL;
}

// Crear nodo del arbol
void crear_nodo_arbol(parbol &nuevo,tjugador dato)
{
    nuevo=new tnodo_arbol;
    if (nuevo!=NULL)
    {
        strcpy(nuevo->jugador.apellido,dato.apellido);
        strcpy(nuevo->jugador.nombre,dato.nombre);
        strcpy(nuevo->jugador.nickname,dato.nickname);
        nuevo->jugador.cant_partida_ganadas=dato.cant_partida_ganadas;
        nuevo->jugador.puntaje=dato.puntaje;
        nuevo->izq=NULL;
        nuevo->der=NULL;
    }
    else
    {
        cout<<"sin espacio de memoria"<<endl;
    }
}


void mostrar_ranking()
{
    parchivo_jugador jugadores;
    tjugador jugador;
    parbol nuevo, arbol;
    iniciar_arbol(arbol);

    jugadores=fopen("archivo_binario/jugadores.txt","rb");
    if (jugadores!=NULL)
        while (!feof(jugadores) )
        {
            fread(&jugador,sizeof(jugador),1,jugadores);
            if (jugador.cant_partida_ganadas>=1)
            {
                crear_nodo_arbol(nuevo,jugador);
                insercion(arbol,nuevo);
            }
        }
    fclose(jugadores);
    if(arbol!=NULL){
    cout<<"Ranking de jugadores"<<endl;
    enorden(arbol);
    }else
        cout<<"No hay jugadores que hayan ganado"<<endl;
    arbol=NULL;
}

/**Procedimiento que se encarga de agregar los jugadores con el puntaje al arbol
el arbol agrega de acuerdo al puntaje que obtuvo el participante en el juego
*/
void insercion(parbol &a,parbol nuevo)
{
    if (a==NULL)
        a=nuevo;
    else if (nuevo->jugador.puntaje < a->jugador.puntaje)
        insercion(a->izq,nuevo);
    else
        insercion(a->der,nuevo);
}

void mostrar_jugador_arbol(tjugador jugador)
{
    cout<<"\n---------------------------------";
    cout <<"\nNickname: "<< jugador.nickname;
    cout <<"\nApellido: "<< jugador.apellido;
    cout <<"\nNombre: "<< jugador.nombre;
    cout <<"\nNickname: "<< jugador.nickname;
    cout <<"\nPuntaje: "<< jugador.puntaje;
    cout <<"\nCantidad de Partida ganada: "<< jugador.cant_partida_ganadas;
}


//Lista los valores en orden
void enorden(parbol a)
{
    if (a!=NULL)
    {
       enorden(a->der);
        mostrar_jugador_arbol(a->jugador);
         enorden(a->izq);
    }
}
