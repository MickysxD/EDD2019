#ifndef ACTIVIDADES_H
#define ACTIVIDADES_H
#include <iostream>
#include <string>

using namespace std;

class Actividades
{
    public:
        Actividades *siguiente;
        Actividades *anterior;
        string actividad;

        Actividades(string act);
        void imprimirActividad();
        virtual ~Actividades();

    protected:

    private:
};

#endif // ACTIVIDADES_H
