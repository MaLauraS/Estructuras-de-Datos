#pragma once
#include "Pasajero.h"

class ColaPrioridad
{
	Pasajero Cola[100];
	int LenCola = 0;
	bool ColaVacia();
	Pasajero GetPrimero();
	void InsertarPrioridad(Pasajero& const pasajero);

};
