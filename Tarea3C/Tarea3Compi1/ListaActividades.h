#ifndef LISTAACTIVIDADES_H
#define LISTAACTIVIDADES_H
#include <iostream>
#include "Actividades.h"

using namespace std;

class ListaActividades
{
    public:
        Actividades *primero;
        Actividades *ultimo;

        void agregar(string act);
        ListaActividades();
        void imprimir();
        virtual ~ListaActividades();

    protected:

    private:
};

#endif // LISTAACTIVIDADES_H
