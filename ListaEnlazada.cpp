#include "ListaEnlazada.h"

bool ListaEnlazada::ListaVacia()
{
if (Cabeza == nullptr)
	return true;
return false;
}

void ListaEnlazada::InsertarInicio(Alumno& const alumno)
{
Nodo* inicio = new Nodo(alumno);
if (ListaVacia())
	Cabeza = inicio;
else {
	inicio->Siguiente = Cabeza;
	Cabeza = inicio;
	}
}

Alumno ListaEnlazada::QuitarPrimero()
{
	if (ListaVacia())
		throw ListaVaciaException{};
	Alumno resultado = Cabeza -> Valor;
	Cabeza = Cabeza -> Siguiente;
		return resultado;

}

Alumno ListaEnlazada::VerPrimero()
{
if (ListaVacia())
	throw ListaVaciaException{};
return Cabeza -> Valor;

}

ListaEnlazada::ListaEnlazada() :
	Cabeza(nullptr) {
}
