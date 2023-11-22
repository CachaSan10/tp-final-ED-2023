


typedef struct tnodo_arbol *parbol;
typedef struct tnodo_arbol
{
int dato;
parbol izq;
parbol der;
};

//Inicia el arbol
void iniciar_arbol(parbol &a){
a=NULL;
}

// Crear nodo del arbol
void crear_nodo_arbol(parbol &nuevo,int dato){
    nuevo=new tnodo_arbol;
    if (nuevo!=NULL){
        nuevo->dato=dato;
        nuevo->izq=NULL;
        nuevo->der=NULL;
    }else{
        cout<<"sin espacio de memoria"<<endl;
    }
}

/**Se pasa por parametro el valor mayor de la suma que se obtubo de las
barajas extraidas de los jugadores.
Se usa la lista para almacenar los valores de los puntajes ya sea 1
o mas de 1 en caso de que tenga el puntaje mayor e iguales
**/
void busqueda(parbol a,int buscarMayor,tlista& lista_usuario)
{
if (a!=NULL)
{
busqueda(a->izq,buscarMayor,lista_usuario);
 busqueda(a->der,buscarMayor,lista_usuario);
if (a->dato==buscarMayor)
 {
    agregar_valor(lista_usuario,a->dato);
 }


}
}

/**Procedimiento que se encarga de agregar los jugadores con el puntaje al arbol
el arbol agrega de acuerdo al puntaje que obtuvo el participante en el juego
*/
void insercion(parbol &a,parbol nuevo)
{
if (a==NULL)
a=nuevo;
else
if (nuevo->dato < a->dato)
insercion(a->izq,nuevo);
else
insercion(a->der,nuevo);
}

//Lista los valores en orden
void enorden(parbol a)
{ if (a!=NULL)
{ enorden(a->izq);
cout << a->dato;
enorden(a->der);
}
}
