// Tarea4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "conio.h"
#include "MatrizActividades.h"
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

	//getch();
	return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
