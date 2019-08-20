#include "Dia.h"
#include <string>
#include "ListaActividades.h"
#include <iostream>

using namespace std;

Dia::Dia()
{
    this->actdia = new ListaActividades();
}

Dia::Dia(string dia)
{
    this->actdia = new ListaActividades();
    this->nombred = dia;

    if(dia.compare("lunes") == 0){
       this->id = 1;
    }else if(dia.compare("martes") == 0){
       this->id = 2;
    }else if(dia.compare("miercoles") == 0){
       this->id = 3;
    }else if(dia.compare("jueves") == 0){
       this->id = 4;
    }else if(dia.compare("viernes") == 0){
       this->id = 5;
    }else if(dia.compare("sabado") == 0){
       this->id = 6;
    }else if(dia.compare("domingo") == 0){
       this->id = 7;
    }
}

void Dia::imprimirDia()
{
    cout<<"Dia: "<<this->nombred<<"    ";
    this->actdia->imprimir();
    cout<<endl;
}

Dia::~Dia()
{
    //dtor
}
