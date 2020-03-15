#pragma once
#include <string>
#include "Alumno.h"
#include "Nodo.h"


class Pila
{
public:
	ListaEnlazada* ListaAlumnos;
	void Push(Alumno& const alumno);
	Alumno Peek();
	Alumno Pop();
	
};
