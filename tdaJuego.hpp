#include<iostream>
#include<stdio.h>
using namespace std;


//#include "baraja.hpp"
//#include "TDA-Jugadores.hpp"
#include "tdaListaJugador.hpp"

void principal_juego(tcola &mazo);
void menu_juego(int &op);
void seleccion_jugador(tlistaJ &lista_jugadores);
void repartir_cartas(tlistaJ &lis,tcola &mazo);
void iniciar_juego(tlistaJ &lista_jugadores,tcola &mazo);
void comparar_mod(tlistadoble &lista_cartas,pmazo extraido,tnaipe &naipe,bool band);

void principal_juego(tcola &mazo){
tlistaJ lista_jugadores;
//se inicia la lista en la que se almacenan los jugadores que van a participar de la partida
pnodojugador i;
iniciar_lista_jug(lista_jugadores);
bool ini_juego=false;
int op;
    do{
        menu_juego(op);
        switch(op){
        case 1:
        /**
        Procedimiento que se encarga de seleccionar los jugadores que se encuentra dentro del archivo binario
        para luego almacenarlo en una lista.
        **/
            seleccion_jugador(lista_jugadores);//lista de jugadores elegidos ,archivo jugador
            break;
        case 2:
        /**
        Funcion de la libreria tdaListaJugador.hhp que se encarga de verificar si la lista de jugadores esta vacia(true) o no(false).
        En caso de tener jugadores empieza a distribusion de las cartas a cada jugador.
        Una vez repartida las cartas cambia es estado de la variable en true para iniciar el juego.
        **/
            if(lista_vacia_j(lista_jugadores)==false){
                repartir_cartas(lista_jugadores,mazo);
                ini_juego=true;
           } else
                cout<<"debe seleccionar jugadores"<<endl;
            break;
        case 3:
            if(ini_juego==true)
                iniciar_juego(lista_jugadores,mazo);
            else
                cout<<"debe repartir las cartas"<<endl;
            break;
        case 4:
            cout<<"Fin del menu de Juego"<<endl;
            break;
        default:
            cout<<"Error de opcion"<<endl;
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

    do{
    cout<<"indique la cantidad de jugadores a seleccionar: "<<endl;
    cin>>cant;
    }while(cant==1);
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
            //mientras que no encuentre en el final del archivo y existe sea falso repito
            while (!feof(jugadores)&& existe==false)
            {
                fread(&player,sizeof(player),1,jugadores);
                //comparo el nikmame del recorrido con el buscado
                if (strcmp(player.nickname,consulta)==0)
                // Utiliza el procedimiento agregar_Valor de la libreria tdaListaJugador
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

//Procedimiento que se encarga de repartir las cartas a los jugadores
void repartir_cartas(tlistaJ &lis,tcola &mazo){
    pmazo extraido;
    int aux,cont;
    pnodojugador i;
    i=lis.inicio;
    aux=lis.cant;//cantidad de cartas que se asigna por jugador
    cout<<"PARTICIPANTES DE PARTIDA: "<<aux<<endl;
    for(aux;aux>0;aux--){
        iniciar_lista_m(i->lista_cartas);//inicio la lista de las cartas de cada jugador
        cont=0;
        while(cont<5){
            extraido=quitar_cola(mazo);
            agregar_m(i->lista_cartas,extraido->naipe);
            cont++;
            if(cont==5){
                count<<""<<endl;
                cout<<i->dato.nickname<<endl;//muestro el nombre del jugador
                mostrar_lista_m(i->lista_cartas);//muestro las cartas que obtuvo en la reparticion de cartas
                iniciar_pila(i->naipes_ganados);//iniciio la pila de naipes del jugador
                i=i->sig;
            }
        }
    }

}

void iniciar_juego(tlistaJ &lista_jugadores,tcola &mazo){
    bool scartas=false;
    pnodojugador i;
    pmazo extraido,aux;
    tnaipe naipe_ganador,naipe_reubicar;
    bool=band;
    i=lista_jugadores.inicio;
    int intentos=lista_jugadores.cant;//se utiliza esta variable para llevar un contador de las veces que se compara el mismo naipe
    do{
        band=false;
        cout<<"** JUEGA: "<<i->dato.nickname<<" **"<<endl;
        cout<<"**************************"<<endl;
        cout<<"CIMA DE BARAJA"<<endl;
        extraido=frente_cola(mazo);//CONSULTA frente de cola
        aux=frente_cola(mazo);//CONSULTA frente de cola
        naipe_reubicar=aux->naipe;
        mostrar_naipe(extraido->naipe);
        if(lista_mano_vacia(i->lista_cartas)!=true){//consulta si el jugador de turno tiene cartas para comparar
            cout<<"COMPARANDO CON MANO JUGADOR"<<endl;
            comparar_mod(i->lista_cartas,extraido,naipe_ganador,band);
            if(band==true){//si canbia band indica que en la mano tengo una carta que le gana  a la cima del mazo
                cout<<"EL JUGADOR OBTIENE LA CARTA"<<endl;
                cout<<"CARTA QUE GANO LA COMPARACION: "<<endl;
                /**
                Se utiliza de la libreria TDA-pilaCartas.hhp agregar_pila
                Se utiliza de la libreria tdaCola.hhp extraido
                Se utiliza de la libreria baraja.hhp mostrar_naipe
                **/
                mostrar_naipe(naipe_ganador);//muestro el naipe que le gano al frente del mazo
                extraido=quitar_cola(mazo);//quito el frente del mazo
                agregar_pila(i->naipes_ganados,extraido->naipe);//agrego el extraido a la pila del jugador
                intentos=lista_jugadores.cant;//reinicio intentos
            }else{
                cout<<"NO GANO LA COMPARACION"<<endl;
                intentos--;//decremento intentos
                if(comparar_naipe(naipe_reubicar,extraido->naipe)==true && intentos==0){//si los intentos de comparar son o y el naipe es el mismo
                    extraido=quitar_cola(mazo);//extraigo el naipe
                    agregar_cola(mazo,extraido->naipe);//lo reubico al final de la cola
                }
            }

        }else{
            cout<<"ya no tiene cartas en su mano"<<endl;
        }

        i=i->sig;//le paso el turno al siguiente jugador

        if(i==NULL)//si llega al final de la lista de los jugadores reinicio los turnos
            i=lista_jugadores.inicio;
        if(sin_cartas(lista_jugadores)==true)
            scartas=true;

    }while(scartas!=true);//si scartas cambia a verdadero finaliza el juego

}

/** Procedimiento que se encarga de comparar la lista de cartas que posee el jugador que le corresponde jugar
con la cima del mazo de carta para saber si el jugador puede o no retirar  la carta de la cima para despues extraerlo
y agregarlo a la pila de cartas que se va desaciendo el jugador.
*/
void comparar_mod(tlistadoble &lista_cartas,pmazo extraido,tnaipe &naipe,bool band){
    plista_mano i;
    //recorro los naipes que tiene en su mano el jugador
    for(i=lista_cartas.inicio;i!=NULL;i=i->sig){
        //si es comodin le gana a cualquier carta
        if(i->dato.comodin==true){
            naipe=i->dato;

        }
    }
}
