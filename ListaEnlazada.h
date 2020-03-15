#pragma once
#include "Alumno.h"
class ListaEnlazada
{
public:
	Nodo* Cabeza;
	ListaEnlazada();
	bool ListaVacia();
	void InsertarInicio(Alumno& const alumno);
	Alumno QuitarPrimero();
	Alumno VerPrimero();

};

class ListaVaciaException {};
