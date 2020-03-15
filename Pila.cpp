#include "Pila.h"


void Pila::Push(Alumno& const alumno)
{
	ListaAlumnos -> InsertarInicio(alumno);
}

Alumno Pila::Peek()
{
	return ListaAlumnos -> VerPrimero();
}

Alumno Pila::Pop()
{
	return ListaAlumnos -> RemoverPrimero();
}






