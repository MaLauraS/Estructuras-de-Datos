#include "Pasajero.h"

std::string Pasajero::GetGenero()
{
	return Genero;
}

void Pasajero::SetGenero(std::string GeneroNuevo)
{
	Genero = GeneroNuevo
}

int Pasajero::GetEdad()
{
	return Edad;
}


void Pasajero::SetEdad(int EdadNueva)
{
	Edad = EdadNueva
}

int Pasajero::GetPrioridad(Pasajero& const pasajero)
{
	return 0;
}
