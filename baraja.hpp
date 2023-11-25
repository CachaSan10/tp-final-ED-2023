//#include <iostream>
//#include <stdio.h>

//#include<stdlib.h>
//#include <string.h>
using namespace std;

#include "lista_simple.hpp"



typedef FILE *parchivo;

void menu_gestion_baraja(int &opbaraja);
void principal_baraja(int op,parchivo archivo,tcola &mazo,bool & mazo_creado);
void crear_carta(pnodo nuevo,pmazo dato);
void generar_aleatorio(tlista &lis);
void iniciar_baraja(bool &band,parchivo archivo,tcola &mazo);
void generar_palo(tlista &lis);
int contar_elemento(tlista lis,int dato);
void generar_mazo(tnaipe &naipe,parchivo archivo,tcola &mazo);
void generar_naipe(tnaipe &naipe,tlista &aleatorio,tlista &palo);
void determinar_palo(tnaipe &naipe,int dato);
int determinar_punto(int dato,int palo);
bool determinar_comodin(int dato);
void nodo_mazo(pmazo &nuevo,tnaipe naipe);
void mostrar_naipe(tnaipe nodo);
void listar_mazo(parchivo archivo);
void cargar_cola(parchivo archivo,tcola &q);
bool existe_naipe(tcola aux,tnaipe naipe);
bool com_naipe(tnaipe a,tnaipe b);

/**
    SUBMENU DE OPERACIONES A RELIZAR CON LA BARAJA
*/
void menu_gestion_baraja(int &op){
    cout<<"\n----Menu Principal----"<<endl;
    cout<<"1- Generar Baraja"<<endl;//iniciar
    cout<<"2- Crear Mazo"<<endl;//aleatorio
    cout<<"3- Mostrar Mazo"<<endl;//recuperar del archivo las cartas
    cout<<"4- Salir"<<endl;
    cout<<"Elegir Opcion"<<endl;
    cin>>op;

}

/**
    EJECUTA LAS OPCIONES PRECENTADAS EN EL SUBMENU
*/
void principal_baraja(int op,parchivo archivo,tcola &mazo,bool & mazo_creado){
    //DECLARACION DE VARIABLES A UTILIZAR EN EL MODULO
    bool inicio_baraja;
    tnaipe naipe;
    pmazo nuevo;
    //FIN DE DECLARACION DE VARIABLES
    //EL SIGUIENTE BUCLE SE REPITE ASTA QUE EL USUARIO SOLICITA LA SALIDA DEL MISMO
    do{
     //system("cls");
    //INVOCACION DE MENU PROPIO DE LA LIBRERIA
    menu_gestion_baraja(op);
    switch (op)
    {

    case 1:
            cout<<"-----------Generar Baraja------------"<<endl;
            iniciar_baraja(inicio_baraja,archivo,mazo);//LLAMA A INICIALIZACION DEL ARCHIVO Y LA BARAJA
            if(inicio_baraja==true)//VERIFICA QUE LA INICIALIZACION SE EFECTUO CORRECTAMENTE
                cout<<"se inicio correctamente la baraja"<<endl;
            else
                cout<<"no se pudo iniciar la baraja"<<endl;
            //system("pause");
        break;
    case 2:
            cout<<"-----------Crear Mazo Aleatorio------------"<<endl;
            if(inicio_baraja==true){//EJECUTA LAS OPERACIONES SOLICITADAS POR EL USUSARIO SOLO SI SE INICIALIZO EL MAZO
              generar_mazo(naipe,archivo,mazo);//INVOCACION DE MODULO QUE GENERA EL MAZO DE CARTAS
               if(cola_vacia(mazo)==false){//VERIFICA QUE SE HAYA GENERADO EL MAZO CORRECTAMENTE
                    cout<<"MAZO GENERADO CON EXITO"<<endl;
                    mazo_creado=true;//CAMBIO EL ESTADO DE LA BANDERA ENVIADA EN LA INVOCACION DEL MODULO
                }else{
                    cout<<"ERROR EN LA GENERACION DEL MAZO"<<endl;
                    mazo_creado=false;
                    }
            }else
                cout<<"debe iniciar la baraja opcion 1"<<endl;

                //system("pause");
        break;
    case 3:
            cout<<"-----------Mostrar Mazo Baraja------------"<<endl;
            listar_mazo(archivo);//INVOCACION DE MODULO QUE LISTA LOS NAIPES DEL MAZO
            //system("pause");
        break;
    case 4:
            cout<<"finalizacion de generacion de baraja"<<endl;
            //system("pause");
            break;
    default:
            cout<<"error de ingreso"<<endl;
            //system("pause");
        break;
    }
    }while(op!=4);
}


/**
    EL MODULO EFECTUA LA CREACION DEL ARCHIVO DONDE SE ALMACENA LA BARAJA
    Y DEMAS REALIZA LA INICIALIZACION DE LA COLA DE CARTAS QUE SE UTILIZARAN EN EL JUEGO
*/
void iniciar_baraja(bool &band,parchivo archivo,tcola &mazo){
    archivo=fopen("archivo_binario/BARAJA.SEC","wb+");//APERTURA DEL ARCHIVO SI NO EXISTE LO CREA Y SI EXISTE LO SOBRESCRIBE
    iniciar_cola(mazo);
    if(archivo!=NULL && mazo.frente==NULL){//VERIFICO SI EL ARCHIVO EXISTE Y LA COLA SE INICIO CORRECTAMENTE
        band=true;
        fclose(archivo);//CIERE DEL ARCHIVO
    }else
        band=false;
}
/**
    MODULO ENCARGADO DE REALIZAR LA CARGA DEL ARCHIVO QUE ALMACENA LA BARAJA
    Y LA CARGA DEL CONTENIDO DEL MISMO ARCHIVO EN UNA COLA DE NAIPES
*/
void generar_mazo(tnaipe &naipe,parchivo archivo,tcola &mazo){
    //DECLARACION DE VARIABLES DEL MODULO
    plista_mano extraido;
    tlistadoble lista;
    iniciar_lista_m(lista);
    tlista aleatorio1,aleatorio2,aleatorio3,aleatorio4,palo;
    //FIN DE VARIABLES DEL MODULO
    int a;
    int i=0;

   //APERTURA DEL ARCHIVO DE ALMACENAMIENTO DE LOS NAIPES
   archivo=fopen("archivo_binario/BARAJA.SEC","wb+");

   //GENERACION DE 4 LISTAS QUE ALMACENAN VALORES DEL 1AL12 EN ORDEN ALEATORIO
   generar_aleatorio(aleatorio1);
   generar_aleatorio(aleatorio2);
   generar_aleatorio(aleatorio3);
   generar_aleatorio(aleatorio4);
   generar_palo(palo);
   //REPITE EL BUCLE ASTA QUE SE HAYAN GENERADO Y AGREGADO 48 NAIPES
    do{//verifica si esa lista no esta vacia
        //SE GENERA UN NUMERO ALEATOREO
        a=rand()%8;
        if(aleatorio1.inicio!=NULL){//VERIFICA SI SE RECORRIO TODOS LOS ELEMENTOS DE LA LISTA
            //INVOCACION AL MODILO ENCARGADO DE LA CARGA DE LOS DATOS CONTENIDOS EN NAIPE
            generar_naipe(naipe,aleatorio1,palo);
            //DE ACUERDO AL VALOR ALEATOREO ALMACENADO EN a SE REALIZA EL AGREGADO AL FINAL O AL INICIO DE LA COLA
            if(a==0||a==3||a==4||a==7){
                agregar_m(lista,naipe);
                i++;//INCREMENTO DE LA CANTIDAD DE NAIPES AGREGADOS
            }else{
                agregar_fin(lista,naipe);
                i++;
            }
        }else{
            if(aleatorio2.inicio!=NULL){//VERIFICA SI SE RECORRIO TODOS LOS ELEMENTOS DE LA LISTA
                generar_naipe(naipe,aleatorio2,palo);
                if(a==0||a==1||a==5){
                    agregar_m(lista,naipe);
                    i++;
                }else{
                    agregar_fin(lista,naipe);
                    i++;
                }
            }else{
                if(aleatorio3.inicio!=NULL){//VERIFICA SI SE RECORRIO TODOS LOS ELEMENTOS DE LA LISTA
                    generar_naipe(naipe,aleatorio3,palo);
                    if(a==2||a==6){
                        agregar_m(lista,naipe);
                        i++;
                    }else{
                        agregar_fin(lista,naipe);
                        i++;
                    }
                }else{
                    if(aleatorio4.inicio!=NULL){//VERIFICA SI SE RECORRIO TODOS LOS ELEMENTOS DE LA LISTA
                    generar_naipe(naipe,aleatorio4,palo);
                    if(a==4||a==5||a==7){
                        agregar_m(lista,naipe);
                        i++;
                    }else{
                        agregar_fin(lista,naipe);
                        i++;
                        }
                    }
                }

            }
        }

    }while(i!=48);

    do{
        //GENERO UN VALOR ALEATORIO PARA a
        a=rand()%6;
        if(lista.inicio!=NULL){//VERIFICO SI LA LISTA CONTIENE NAIPES
            if(a==1||a==5){//DE ACUERDO AL VALOR DE A SE EXTRAE DEL FRENTE O FINAL DE LA FILA
                //QUITO EL INICIO DE LA LISTA Y LO ASIGNO A EXTRAIDO
                extraido=extraer_inicio(lista);
                //EL CONTENIDO DE EXTRAIDO LO ALMACENO EN NAIPE
                naipe=extraido->dato;
                //REALIZO LA CARGA DEL NAIPE EN EL ARCHIVO CONTENEDOR DE LA BARAJA
                fwrite(&naipe,sizeof(naipe),1,archivo);
            }else{
                //QUITO EL FINAL DE LA LISTA Y LO ASIGNO A EXTRAIDO
                extraido=extraer_fin(lista);
                //EL CONTENIDO DE EXTRAIDO LO ALMACENO EN NAIPE
                naipe=extraido->dato;
                //REALIZO LA CARGA DEL NAIPE EN EL ARCHIVO CONTENEDOR DE LA BARAJA
                fwrite(&naipe,sizeof(naipe),1,archivo);
                }
        }
    }while(lista_mano_vacia(lista)!=true);
    //CIERRE DE ARCHIVO
     fclose(archivo);
     //REALIZO LA CARGA DE LA COLA
    cargar_cola(archivo,mazo);
    }

/**
    MODULO DE CARGA DE DATOS AL NAIPE
*/
void generar_naipe(tnaipe &naipe,tlista &aleatorio,tlista &palo){
    //DECLARACION DE VARIABLES
    pnodo auxAl, auxPal;
    //FIN DE DECLARACION
    auxAl=quitar_inicio(aleatorio);//ALMACENA EL INICIO DE LA LISTA ALEATOREA EN LA VARIABLE AUXILIAR
    auxPal=quitar_inicio(palo);//ALMACENA EL INICIO DE LA LISTA PALO EN LA VARIABLE AUXILIAR
    //CARGA DE VALORES A LOS ATRIBUTOS DE NAIPE
    naipe.valor=auxAl->dato;
    determinar_palo(naipe,auxPal->dato);
    naipe.punto=determinar_punto(auxAl->dato,auxPal->dato);
    naipe.comodin=determinar_comodin(auxAl->dato);//EL RETORNO DEL MODULO DETERMINAR COMODIN DEPENDE DEL VALOR QUE ADQUIERE LA CARTA
    //FIN DE LA CARGA
}

/**
    EL MODULO SE ENCARGA DE LA CARGA DE LA LISTA CON VALORES ALEATOREOS
    QUE NO SE REPITEN DEL 1 AL 12
*/
void generar_aleatorio(tlista &lis){

    iniciar_lista(lis);

    int aux=0,a;
    do{
        a=rand()%13;//ALMACENA EN A UN NUMERO ALEATOREO
       if(existe_valor(lis.inicio,a)==false && a!=0 && a>=1 &&a<=12){//VERIFICA LA EXISTENCIA DEL NUMERO EN LA LISTA
            agregar_valor(lis,a);//AGREGO EL VALOR A LA LISTA
            aux++;
        }
    }while(aux!=12);//SALE DEL BUCLE CUANDO EL CONTADOR ALCANZA EL VALOR DE 12
}
/**
    GENERA UNA LISTA CARGADA DE 48 ELEMENTOS
     CADA 12 ELEMNTOS CAMBIA EL VALOR
*/
void generar_palo(tlista &lis){
    iniciar_lista(lis);
    int a=0,b=0,c=0,d=0;
    //indicadores de cantidad de cada elemento
    int aux=0,x;
    do{
        if(a<12){
            x=1;
            agregar_valor(lis,x);
            a++;
            aux++;

        }else{
                if( b<12){
                    x=2;
                    agregar_valor(lis,x);
                    b++;
                    aux++;
               } else{
                    if(c<12){
                        x=3;
                        agregar_valor(lis,x);
                        c++;
                        aux++;
                    }else{
                        if( d<12){
                            x=4;
                            agregar_valor(lis,x);
                            d++;
                            aux++;
                        }
                    }
                }
            }



    }while(aux!=48);


}

int contar_elemento(tlista lis,int dato){
    int aux=0;
    pnodo a;
    for(a=lis.inicio;a!=NULL;a=a->sig){
        if(a->dato==dato)
            aux++;
        }
    return aux;
}


/**
    EL MODULO ALMACENA UN VALOR DE NAIPE DE ACUERDO AL NUMERO INGRESADO
*/
void determinar_palo(tnaipe &naipe,int dato){
    if(dato==1)
        strcpy(naipe.palo,"espada");
    if(dato==2)
        strcpy(naipe.palo,"oro");
    if(dato==3)
        strcpy(naipe.palo,"copa");
    if(dato==4)
        strcpy(naipe.palo,"basto");
}
int determinar_punto(int dato,int palo){
    int aux;
    switch(dato){
        case 1:
            aux=50;
        break;
        case 2:
            aux=25;
        break;
        case 3:
            aux=25;
        break;
        case 4:
            aux=5;
        break;
        case 5:
            aux=5;
        break;
        case 6:
            aux=5;
        break;
        case 7:
            if(palo==1||palo==2)
                aux=15;
            else
                aux=5;
        break;
        case 8:
            aux=5;
        break;
        case 9:
            aux=5;
        break;
        case 10:
            aux=10;
        break;
        case 11:
            aux=10;
        break;
        case 12:
            aux=5;
        break;
        default:
            return -9999;
    }
    return aux;
}

bool determinar_comodin(int dato){
return dato==1||dato==2||dato==3;
}
/**
    GENERA DA CARGA DEL NODO DE TIPO PMAZO
*/
void nodo_mazo(pmazo &nuevo,tnaipe naipe){
    nuevo=new tmazo;
    if(nuevo!=NULL){
        strcpy(nuevo->naipe.palo,naipe.palo);
        nuevo->naipe.comodin=naipe.comodin;
        nuevo->naipe.punto=naipe.punto;
        nuevo->naipe.valor=naipe.valor;
        nuevo->sig=NULL;
    }
}

void mostrar_naipe(tnaipe nodo){
    cout<<"-------------"<<endl;
    cout<<"valor: "<<nodo.valor<<endl;
    cout<<"palo: "<<nodo.palo<<endl;
    cout<<"puntos: "<<nodo.punto<<endl;
    cout<<"comodin "<<nodo.comodin<<endl;
    cout<<"--------------"<<endl;
}
//archivo


void listar_mazo(parchivo archivo)
{ tnaipe p;
  pmazo nuevo;
 archivo=fopen("archivo_binario/BARAJA.SEC","rb");//REALIZO LA APERTURA DEL ARCHIVO QUE CONTIENE LA BARAJA
 if(archivo==NULL)
 cout << "El archivo no existe" << endl;
 else{
 while(!feof(archivo))
 { fread(&p,sizeof(p),1,archivo); // Leer un registro
 if (!feof(archivo)){
    mostrar_naipe(p);
    }
 }
 }
 fclose(archivo);//CIERRE DEL ARCHIVO
}
/**
    REALIZA LA EXTRACCION DE LOS NAIPES CONTENIDOS EN EL ARCHIVO Y LOS ALMACENA EN LA COLA PASADA EN EL PARAMETRO
*/
void cargar_cola(parchivo archivo,tcola &q){
  // DECLARACION DE VARIABLES
  tnaipe p;
  pmazo nuevo;
  // FIN DE DECLARACION

  //ABRE EL ARCHIVO SOLO PARA LECTURA
 archivo=fopen("archivo_binario/BARAJA.SEC","rb");
 if(archivo==NULL)
 cout << "El archivo no existe" << endl;
 else{
    while(!feof(archivo))//VERIFICO NO HABER LLEGADO AL ULTIMO DE LOS ELEMENTOS DEL ARCHIVO
    { fread(&p,sizeof(p),1,archivo); //LEE EL REGISTRO
        if (!feof(archivo)){
            nodo_mazo(nuevo,p);
            agregar_cola(q,nuevo);
             }
        }
 }
 fclose(archivo);
}


