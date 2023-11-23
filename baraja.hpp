#include <iostream>
#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include <string.h>
using namespace std;
#include "tdaCola.hpp"
#include "lista_simple.hpp"


typedef FILE *parchivo;

void menu_gestion_baraja(int &opbaraja);
void principal_baraja(int op,parchivo archivo,tcola &mazo);
void crear_carta(pnodo nuevo,pmazo dato);
void generar_aleatorio(tlista &lis);
void iniciar_baraja(bool &band,parchivo archivo,tcola &mazo);
void aleatoreo_palo(tlista &lis);
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

void menu_gestion_baraja(int &op){
    cout<<"\n----Menu Principal----"<<endl;
    cout<<"1- Generar Baraja"<<endl;//iniciar
    cout<<"2- Crear Mazo"<<endl;//aleatorio
    cout<<"3- Mostrar Mazo"<<endl;//recuperar del archivo las cartas
    cout<<"4- Salir"<<endl;
    cout<<"Elegir Opcion"<<endl;
    cin>>op;

}
void principal_baraja(int op,parchivo archivo,tcola &mazo){

    bool inicio_baraja;
    tnaipe naipe;
    pmazo nuevo;
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
               if(cola_vacia(mazo)==false)
                    cout<<"MAZO GENERADO CON EXITO"<<endl;
                else
                    cout<<"ERROR EN LA GENERACION DEL MAZO"<<endl;
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
}
void iniciar_baraja(bool &band,parchivo archivo,tcola &mazo){
    //archivo
    archivo=fopen("BARAJA.SEC","wb+");
    iniciar_cola(mazo);
    if(archivo!=NULL && mazo.frente==NULL){
        band=true;
        fclose(archivo);
    }else
        band=false;
}

void generar_mazo(tnaipe &naipe,parchivo archivo,tcola &mazo){
    int i=0;
    pmazo nuevo; //es el nodo de almacenamiento
    tcola aux;
   //tnaipe naipe;//es el registro con los datos del naipe
   archivo=fopen("BARAJA.SEC","wb+");
   tlista aleatorio1,aleatorio2,aleatorio3,aleatorio4,palo;
  // srand(time(NULL));
   //genera del 1 al 12 en forma aleatorea
   generar_aleatorio(aleatorio1);
   //mostrar(aleatorio1.inicio);
   generar_aleatorio(aleatorio2);
   //
  // mostrar(aleatorio2.inicio);
   generar_aleatorio(aleatorio3);
   //
  // mostrar(aleatorio3.inicio);
   generar_aleatorio(aleatorio4);

   //mostrar(aleatorio4.inicio);
   genero los aleatorios en los palos
   //
   aleatoreo_palo(palo);
   //
    do{//verifica si esa lista no esta vacia
        if(aleatorio1.inicio!=NULL){
            //
            generar_naipe(naipe,aleatorio1,palo);
            //controla que el naipe no exista
            //controlo con una cola auxiliar
            if(existe_naipe(aux,naipe)==false){
                //creo el nodo para agregar en el auxiliar
                nodo_mazo(nuevo,naipe);
                //agregoa a auxiliar
                agregar_cola(aux,nuevo);
                fwrite(&naipe,sizeof(naipe),1,archivo);
                i++;
            }
        }else{
            if(aleatorio2.inicio!=NULL){
                generar_naipe(naipe,aleatorio2,palo);
                if(existe_naipe(aux,naipe)==false){
                    nodo_mazo(nuevo,naipe);
                    agregar_cola(aux,nuevo);
                    fwrite(&naipe,sizeof(naipe),1,archivo);
                    i++;
                }
            }else{
                if(aleatorio3.inicio!=NULL){
                    generar_naipe(naipe,aleatorio3,palo);
                    if(existe_naipe(aux,naipe)==false){
                        nodo_mazo(nuevo,naipe);
                        agregar_cola(aux,nuevo);
                        fwrite(&naipe,sizeof(naipe),1,archivo);
                        i++;
                    }
                }else{
                    if(aleatorio4.inicio!=NULL){
                        generar_naipe(naipe,aleatorio4,palo);
                        if(existe_naipe(aux,naipe)==false){
                            nodo_mazo(nuevo,naipe);
                            agregar_cola(aux,nuevo);
                            fwrite(&naipe,sizeof(naipe),1,archivo);
                            i++;
                            }
                    }
                }
            }
        }
    }while(i!=48);
     fclose(archivo);
    cargar_cola(archivo,mazo);

}

void generar_naipe(tnaipe &naipe,tlista &aleatorio,tlista &palo){
    srand(time(NULL));
    pnodo auxAl, auxPal;
    auxAl=quitar_inicio(aleatorio);
    auxPal=quitar_inicio(palo);
    naipe.valor=auxAl->dato;
    determinar_palo(naipe,auxPal->dato);
    naipe.punto=determinar_punto(auxAl->dato,auxPal->dato);
    naipe.comodin=determinar_comodin(auxAl->dato);
}

void generar_aleatorio(tlista &lis){
    srand(time(NULL));
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

void aleatoreo_palo(tlista &lis){
   srand(time(NULL));
    iniciar_lista(lis);
    //indicadores de cantidad de cada elemento
    int a=0,b=0,c=0,d=0;
    int aux=0,x;
    do{
        x=rand()%5;
       if(x!=0){
            if(x==1 && a<12){
                agregar_valor(lis,x);
                a++;
                aux++;

            }else{
                if(x==2 && b<12){
                    agregar_valor(lis,x);
                    b++;
                    aux++;
               } else{
                    if(x==3 && c<12){
                        agregar_valor(lis,x);
                        c++;
                        aux++;
                    }else{
                        if(x==4 && d<12){
                            agregar_valor(lis,x);
                            d++;
                            aux++;
                        }
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
        nuevo->naipe=naipe;
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
 archivo=fopen("BARAJA.SEC","rb");
 if(archivo==NULL)
 cout << "El archivo no existe" << endl;
 else
 while(!feof(archivo))
 { fread(&p,sizeof(p),1,archivo); // Leer un registro
 if (!feof(archivo)){
    mostrar_naipe(p);
    }
 }
 fclose(archivo);
}

void cargar_cola(parchivo archivo,tcola &q){
  tnaipe p;
  pmazo nuevo;
 archivo=fopen("BARAJA.SEC","rb");
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


bool existe_naipe(tcola aux,tnaipe naipe){
    pmazo q;
    bool band=false;
    do{
        q = quitar_cola(aux);
        if(com_naipe(q->naipe,naipe)==true)
            band=true;
    }while(cola_vacia(aux)!=true && band!=true);
    return band;
}

bool com_naipe(tnaipe a,tnaipe b){
    if(a.valor==b.valor)
        if(strcmp(a.palo,b.palo)==0)
            return true;
    return false;
}
