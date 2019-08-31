#ifndef NODO_H
#define NODO_H
#include <string>

using namespace std;

class Nodo
{
    public:
        string dia;
		string hora;
		string actividad;
		int x;
		int y;

		Nodo *siguiente;
		Nodo *anterior;
		Nodo *arriba;
		Nodo *abajo;

		Nodo();
		void adia(string dia);
		void ahora(string hora);

        virtual ~Nodo();

    protected:

    private:
};

#endif // NODO_H
