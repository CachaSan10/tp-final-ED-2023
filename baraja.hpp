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

//menu de opciones para generar la baraja
void menu_gestion_baraja(int &op){
    cout<<"\n----Menu Principal----"<<endl;
    cout<<"1- Generar Baraja"<<endl;//iniciar
    cout<<"2- Crear Mazo"<<endl;//aleatorio
    cout<<"3- Mostrar Mazo"<<endl;//recuperar del archivo las cartas
    cout<<"4- Salir"<<endl;
    cout<<"Elegir Opcion"<<endl;
    cin>>op;

}


//ejecuta las opciones precentadas en el menu
void principal_baraja(int op,parchivo archivo,tcola &mazo,bool & mazo_creado){

    bool inicio_baraja;
    tnaipe naipe;
    pmazo nuevo;
    do{
     menu_gestion_baraja(op);
    switch (op)
    {

    case 1:
            cout<<"-----------Generar Baraja------------"<<endl;
            iniciar_baraja(inicio_baraja,archivo,mazo);//inicio el archivo y la cola
            if(inicio_baraja==true)
                cout<<"se inicio correctamente la baraja"<<endl;
            else
                cout<<"no se pudo iniciar la baraja"<<endl;
        break;
    case 2:
            cout<<"-----------Crear Mazo Aleatorio------------"<<endl;
            if(inicio_baraja==true){
              generar_mazo(naipe,archivo,mazo);
               if(cola_vacia(mazo)==false){
                    cout<<"MAZO GENERADO CON EXITO"<<endl;
                    mazo_creado=true;
                }else{
                    cout<<"ERROR EN LA GENERACION DEL MAZO"<<endl;
                    mazo_creado=false;
                    }
            }else
                cout<<"debe iniciar la baraja opcion 1"<<endl;
        break;
    case 3:
            cout<<"-----------Mostrar Mazo Baraja------------"<<endl;
            listar_mazo(archivo);
        break;
    case 4:
            cout<<"finalizacion de generacion de baraja"<<endl;
            break;
    default:
            cout<<"error de ingreso"<<endl;
        break;
    }
    }while(op!=4);
}
void iniciar_baraja(bool &band,parchivo archivo,tcola &mazo){
    //archivo
    archivo=fopen("archivo_binario/BARAJA.SEC","wb+");
    iniciar_cola(mazo);
    if(archivo!=NULL && mazo.frente==NULL){
        band=true;
        fclose(archivo);
    }else
        band=false;
}

void generar_mazo(tnaipe &naipe,parchivo archivo,tcola &mazo){
    plista_mano extraido;
    tlistadoble lista;
    iniciar_lista_m(lista);
    int a;
    int i=0;
    //pmazo nuevo; //es el nodo de almacenamiento

    //falto inicializar la cola aux

   //tnaipe naipe;//es el registro con los datos del naipe
   archivo=fopen("archivo_binario/BARAJA.SEC","wb+");
   //listas de valores aleatorios del 1 al 12
   tlista aleatorio1,aleatorio2,aleatorio3,aleatorio4,palo;
   //genera del 1 al 12 en forma aleatorea
   generar_aleatorio(aleatorio1);
   generar_aleatorio(aleatorio2);
   generar_aleatorio(aleatorio3);
   generar_aleatorio(aleatorio4);
   generar_palo(palo);
    do{//verifica si esa lista no esta vacia
        a=rand()%8;
        if(aleatorio1.inicio!=NULL){
            generar_naipe(naipe,aleatorio1,palo);
            if(a==0||a==3||a==4||a==7){
                agregar_m(lista,naipe);
                i++;
            }else{
                agregar_fin(lista,naipe);
                i++;
            }
        }else{
            if(aleatorio2.inicio!=NULL){
                generar_naipe(naipe,aleatorio2,palo);
                if(a==1){
                    agregar_m(lista,naipe);
                    i++;
                }else{
                    agregar_fin(lista,naipe);
                    i++;
                }
            }else{
                if(aleatorio3.inicio!=NULL){
                    generar_naipe(naipe,aleatorio3,palo);
                    if(a==0){
                        agregar_m(lista,naipe);
                        i++;
                    }else{
                        agregar_fin(lista,naipe);
                        i++;
                    }
                }else{
                    if(aleatorio4.inicio!=NULL){
                    generar_naipe(naipe,aleatorio4,palo);
                    if(a==1){
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

        a=rand()%6;
        if(lista.inicio!=NULL){
            if(a==1||a==5){
                extraido=extraer_inicio(lista);
                naipe=extraido->dato;
                fwrite(&naipe,sizeof(naipe),1,archivo);
            }else{
                extraido=extraer_fin(lista);
                naipe=extraido->dato;
                fwrite(&naipe,sizeof(naipe),1,archivo);
                }
        }
    }while(lista_mano_vacia(lista)!=true);

     fclose(archivo);
    cargar_cola(archivo,mazo);
    }


void generar_naipe(tnaipe &naipe,tlista &aleatorio,tlista &palo){

    pnodo auxAl, auxPal;
    auxAl=quitar_inicio(aleatorio);
    auxPal=quitar_inicio(palo);
    naipe.valor=auxAl->dato;
    determinar_palo(naipe,auxPal->dato);
    naipe.punto=determinar_punto(auxAl->dato,auxPal->dato);
    naipe.comodin=determinar_comodin(auxAl->dato);
}

void generar_aleatorio(tlista &lis){

    iniciar_lista(lis);

    int aux=0,a;
    do{
        a=rand()%13;
       if(existe_valor(lis.inicio,a)==false && a!=0 && a>=1 &&a<=12){
            agregar_valor(lis,a);
            aux++;
        }
    }while(aux!=12);
}

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
 archivo=fopen("archivo_binario/BARAJA.SEC","rb");
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
 fclose(archivo);
}

void cargar_cola(parchivo archivo,tcola &q){
  tnaipe p;
  pmazo nuevo;
 archivo=fopen("archivo_binario/BARAJA.SEC","rb");
 if(archivo==NULL)
 cout << "El archivo no existe" << endl;
 else{
    while(!feof(archivo))
    { fread(&p,sizeof(p),1,archivo); // Leer un registro
        if (!feof(archivo)){
            nodo_mazo(nuevo,p);
            agregar_cola(q,nuevo);
             }
        }
 }
 fclose(archivo);
}


