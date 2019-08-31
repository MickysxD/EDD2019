#include <iostream>
#include "MatrizActividades.h"
#include "conio.h"
#include "string.h"
#include <string>
#include <algorithm>

using namespace std;

MatrizActividades *nueva = new MatrizActividades();

string dia, actividad, hora;
int numero;
bool si = true;

int main()
{
    while (si) {
		cout << "1. Agregar actividad" << endl;
		cout << "2. Ver actividades por dia" << endl;
		cout << "3. Ver todas las actividades" << endl;
		cout << "4. Salir" << endl  << endl;
		cout << "	Ingrese el numero de la opcion a elegir: ";
		cin >> numero;
		cout << endl << endl;
		switch (numero)
		{
			case 1:
				cout << "         Ingrese un dia: ";
				cin >> dia;
				transform(dia.begin(), dia.end(), dia.begin(), ::tolower);
				cout << "         Ingrese una hora: ";
				cin >> hora;
				cout << "         Ingrese una actividad: ";
				cin >> actividad;
				cout << endl;

				nueva->agregarA(dia, hora, actividad);
				cout << endl;
				break;

			case 3:
				nueva->imprimir();
				cout << endl;
				cout << endl;
				break;

			case 2:
				cout << "         Ingrese un dia: ";
				cin >> dia;
				cout << endl;

				nueva->imprimird(dia);
				cout << endl;
				cout << endl;
				break;

			case 4:
				si = false;
				break;

			default:
				break;
		}

	}

	getch();
	return 0;
}
