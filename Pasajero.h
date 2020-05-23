#pragma once
#include <string>

class Pasajero
{
public:

	std::string Nombre;
	std::string Genero;
	int Edad;

	static int GetPrioridad(Pasajero& const pasajero);
};

