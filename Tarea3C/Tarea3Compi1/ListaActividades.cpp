#include "ListaActividades.h"

ListaActividades::ListaActividades()
{
    this->primero = NULL;
    this->ultimo = NULL;
}

void ListaActividades::agregar(string act){
    Actividades *nuevo = new Actividades(act);
    Actividades *tem = this->ultimo;
    if(this->primero == NULL){
        this->primero = nuevo;
        this->ultimo = nuevo;
    }else{
        nuevo->anterior = tem;
        tem->siguiente = nuevo;
        this->ultimo = nuevo;
    }
}

void ListaActividades::imprimir(){
    Actividades *temp = this->primero;
    while(temp != NULL){
        temp->imprimirActividad();
        temp = temp->siguiente;
    }
}

ListaActividades::~ListaActividades()
{
    //dtor
}
