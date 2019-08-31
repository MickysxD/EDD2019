#include "MatrizActividades.h"
#include <string>
#include "Nodo.h"
#include <iostream>

using namespace std;

MatrizActividades::MatrizActividades()
{
	Nodo *rot = new Nodo();
	rot->adia("0");
	rot->ahora("0");
	rot->actividad = "Root";
	this->root = rot;
	this->contador = 0;
}

Nodo* MatrizActividades::buscarDia(string dia)
{
	Nodo *temp = this->root->siguiente;
	while (temp != NULL) {
		if (dia.compare(temp->dia) == 0)
		{
			return temp;
		}
		temp = temp->siguiente;
	}

	return temp;
}


Nodo* MatrizActividades::buscarHora(string hora)
{
	Nodo *temp = this->root->abajo;
	while (temp != NULL) {
		if (hora.compare(temp->hora) == 0)
		{
			return temp;
		}
		temp = temp->abajo;
	}

	return temp;
}


Nodo* MatrizActividades::agregarDia(Nodo *dia, Nodo *cabeza)
{
	Nodo *tem = cabeza;
	Nodo *nuevo = dia;
	bool bandera = false;
	bool entra = true;

	while (entra) {
		if (tem->x == nuevo->x) {
			tem->y = nuevo->y;
			tem->dia = nuevo->dia;
			return tem;
		}
		else if (tem->x > nuevo->x) {
			bandera = true;
			entra = false;
		}
		if (tem->siguiente != NULL) {
			tem = tem->siguiente;
		}
		else {
			entra = false;
		}
	}

	if (bandera) {
		nuevo->siguiente = tem;
		tem->anterior->siguiente = nuevo;
		nuevo->anterior = tem->anterior;
		tem->anterior = nuevo;
	}
	else {
		tem->siguiente = nuevo;
		nuevo->anterior = tem;
	}

	return nuevo;


	/*
	if(tem == NULL){
		this->root->siguiente = nuevo;
		return *nuevo;
	}else {
		Nodo *ant = tem;
		while(tem != NULL){
			if(nuevo->id > tem->id){
				ant = tem;
				tem = tem->siguiente;
			}else if(tem->id > nuevo->id){
				nuevo->siguiente = tem;
				ant->siguiente = nuevo;
				return *nuevo;
			}
		}
	}
	return *nuevo;
	*/

}


Nodo* MatrizActividades::agregarHora(Nodo *hora, Nodo *cabeza)
{
	Nodo *tem = cabeza;
	Nodo *nuevo = hora;
	bool bandera = false;
	bool entra = true;

	while (entra) {
		if (tem->y == nuevo->y) {
			tem->x = nuevo->x;
			tem->hora = nuevo->hora;
			return tem;
		}
		else if (tem->y > nuevo->y) {
			bandera = true;
			entra = false;
		}
		if (tem->abajo != NULL) {
			tem = tem->abajo;
		}
		else {
			entra = false;
		}
	}

	if (bandera) {
		nuevo->abajo = tem;
		tem->arriba->abajo = nuevo;
		nuevo->arriba = tem->arriba;
		tem->arriba = nuevo;
	}
	else {
		tem->abajo = nuevo;
		nuevo->arriba = tem;
	}

	return nuevo;


	/*
	if(tem == NULL){
		this->root->siguiente = nuevo;
		return *nuevo;
	}else {
		Nodo *ant = tem;
		while(tem != NULL){
			if(nuevo->id > tem->id){
				ant = tem;
				tem = tem->siguiente;
			}else if(tem->id > nuevo->id){
				nuevo->siguiente = tem;
				ant->siguiente = nuevo;
				return *nuevo;
			}
		}
	}
	return *nuevo;
	*/

}


Nodo* MatrizActividades::crearDia(string dia) {
	Nodo *adia = new Nodo();
	adia->adia(dia);
	Nodo *cabeza = this->root;
	return this->agregarDia(adia, cabeza);
}


Nodo* MatrizActividades::crearHora(string hora) {
	Nodo *ahora = new Nodo();
	ahora->ahora(hora);
	Nodo *cabeza = this->root;
	return this->agregarHora(ahora, cabeza);
}


void MatrizActividades::agregarA(string dia, string hora, string actividad)
{
	Nodo *nuevo = new Nodo();
	nuevo->actividad = actividad;
	nuevo->adia(dia);
	nuevo->ahora(hora);

	Nodo *diaa = this->buscarDia(dia);
	Nodo *horaa = this->buscarHora(hora);

	if (diaa == NULL && horaa == NULL) {
		diaa = this->crearDia(dia);
		horaa = this->crearHora(hora);
		nuevo = this->agregarDia(nuevo, horaa);
		nuevo = this->agregarHora(nuevo, diaa);

	}
	else if (diaa != NULL && horaa == NULL) {
		horaa = this->crearHora(hora);
		nuevo = this->agregarDia(nuevo, horaa);
		nuevo = this->agregarHora(nuevo, diaa);

	}
	else if (diaa == NULL && horaa != NULL) {
		diaa = this->crearDia(dia);
		nuevo = this->agregarDia(nuevo, horaa);
		nuevo = this->agregarHora(nuevo, diaa);

	}
	else if (diaa != NULL && horaa != NULL) {
		nuevo = this->agregarDia(nuevo, horaa);
		nuevo = this->agregarHora(nuevo, diaa);
	}

}

void MatrizActividades::imprimir()
{
	Nodo *dia = this->root->siguiente;
	while (dia != NULL) {
		Nodo *actividad = dia->abajo;
		cout << "Dia: " << actividad->dia <<endl;
		while (actividad != NULL) {
			cout << "	Hora: " << actividad->hora << "		Actividad: " << actividad->actividad << endl;
			actividad = actividad->abajo;
		}
		dia = dia->siguiente;
	}
}

void MatrizActividades::imprimird(string dia)
{
	Nodo *diat = this->root->siguiente;
	while (dia.compare(diat->dia) != 0) {

		diat = diat->siguiente;
	}

	Nodo *actividad = diat->abajo;
	cout << "Dia: " << actividad->dia << endl;
	while (actividad != NULL) {
		cout << "	Hora: " << actividad->hora << "		Actividad: " << actividad->actividad << endl;
		actividad = actividad->abajo;
	}

}


MatrizActividades::~MatrizActividades()
{
    //dtor
}
