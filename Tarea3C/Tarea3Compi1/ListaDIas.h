#ifndef LISTADIAS_H
#define LISTADIAS_H
#include "Dia.h"

using namespace std;

class ListaDIas
{
    public:
        Dia *primero;
        int contador;

        ListaDIas();
        Dia buscarDia(string nombred);
        Dia agregarDia(string nombred);
        void agregarA(string nombred, string actividad);
        void imprimir();
        virtual ~ListaDIas();

    protected:

    private:
};

#endif // LISTADIAS_H
