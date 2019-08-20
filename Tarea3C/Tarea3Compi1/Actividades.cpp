#include "Actividades.h"
#include <string>

using namespace std;

Actividades::Actividades(string act)
{
    this->anterior = NULL;
    this->siguiente = NULL;
    this->actividad = act;
}

void Actividades::imprimirActividad(){
    cout<<"<-"<<this->actividad<<"->";
}

Actividades::~Actividades()
{
    //dtor
}
