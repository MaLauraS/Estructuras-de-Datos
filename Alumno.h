#pragma once
#include <string>
#include "Pila.h"
#include "Nodo.h"


class Alumno
{
private:
	std::string Nombre;
	std::string Apellido;

public:
	std::string GetNombre();
	void SetNombre(std::string nombre);
	std::string GetApellido();
	void SetApellido(std::string apellido);

};
