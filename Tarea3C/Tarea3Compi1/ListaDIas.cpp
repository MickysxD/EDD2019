#include "ListaDIas.h"
#include "Dia.h"
#include "string.h"

using namespace std;

ListaDIas::ListaDIas()
{
    this->primero = NULL;
    this->contador = 0;
}

Dia ListaDIas::buscarDia(string nombred)
{
    Dia *temp = this->primero;
    while(temp != NULL){
        if(nombred.compare(temp->nombred))
        {
            return *temp;
        }
        temp = temp->siguiente;
    }
    return *temp;
}

Dia ListaDIas::agregarDia(string nombred)
{
    Dia *tem = this->primero;
    Dia *nuevo = new Dia(nombred);
    if(tem == NULL){
        this->primero = nuevo;
        return *nuevo;
    }else {
        Dia *ant = tem;
        while(tem != NULL){
            if(nuevo->id > tem->id){
                ant = tem;
                tem = tem->siguiente;
            }else if(tem->id > nuevo->id){
                nuevo->siguiente = tem;
                ant->siguiente = nuevo;
                return *nuevo;
            }
        }
    }
    return *nuevo;
}

void ListaDIas::agregarA(string nombred, string actividad){
    Dia *temp = this->primero;
    while(temp != NULL){
        if(nombred.compare(temp->nombred) == 0)
        {
            break;
        }
        temp = temp->siguiente;
    }


    if(temp == NULL){
        Dia *tem = this->primero;
        Dia *nuevo = new Dia(nombred);
        if(tem == NULL){
            this->primero = nuevo;

        }else {

            Dia *ant = tem;

            if(tem->id > nuevo->id && this->primero == tem){
                nuevo->siguiente = tem;
                this->primero = nuevo;
            }else{
                while(tem != NULL){
                    if(nuevo->id > tem->id){
                        ant = tem;
                        tem = tem->siguiente;
                        if(tem == NULL){
                            ant->siguiente = nuevo;
                        }
                    }else if(tem->id > nuevo->id){
                        nuevo->siguiente = tem;
                        ant->siguiente = nuevo;
                        tem = NULL;
                    }
                }
            }
        }
        nuevo->actdia->agregar(actividad);
    }else{
        temp->actdia->agregar(actividad);
    }
}

void ListaDIas::imprimir(){
    Dia *temp = this->primero;
    while(temp != NULL){
        temp->imprimirDia();
        temp = temp->siguiente;
    }
}

ListaDIas::~ListaDIas()
{
    //dtor
}
