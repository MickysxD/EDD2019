#ifndef MATRIZACTIVIDADES_H
#define MATRIZACTIVIDADES_H
#include "Nodo.h"
#include <string>

using namespace std;

class MatrizActividades
{
    public:
        Nodo *root;
        int contador;

        MatrizActividades();
        Nodo* buscarDia(string dia);
        Nodo* buscarHora(string hora);

        Nodo* agregarDia(Nodo *dia, Nodo *cabeza);
        Nodo* agregarHora(Nodo *hora, Nodo *cabeza);
        Nodo* crearDia(string dia);
        Nodo* crearHora(string hora);

        void agregarA(string dia, string hora, string actividad);

        void imprimir();
        void imprimird(string dia);

        virtual ~MatrizActividades();

    protected:

    private:
};

#endif // MATRIZACTIVIDADES_H
