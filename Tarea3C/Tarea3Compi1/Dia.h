#ifndef DIA_H
#define DIA_H
#include "ListaActividades.h"
#include <string>

using namespace std;

class Dia
{
    public:
        string nombred;
        Dia *siguiente;
        int id;
        ListaActividades *actdia;

        Dia();
        Dia(string dia);
        void imprimirDia();
        virtual ~Dia();

    protected:

    private:
};

#endif // DIA_H
