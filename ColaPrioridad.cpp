#include "Colaprioridad.h"
#include <algorithm> 
#define LEFT(i) (2*i+1)
#define RIGHT(i) (2*i+2)
#define EXISTS(i) (i < LenCola)
#define DAD(i) ((i-1)/2)


bool ColaPrioridad::ColaVacia()
{
	if (LenCola == 0)
		return true;
	return false;
}

Pasajero ColaPrioridad::GetPrimero()
{
	Pasajero resultado = Cola[0];
	LenCola--;
	Cola[0] = Cola[LenCola];
	int i = 0;
	while ((EXISTS(LEFT(i)) && Cola[LEFT(i)].Edad < Cola[i].Edad) || (EXISTS(RIGHT(i)) && Cola[RIGHT(i)].Edad < Cola[i].Edad)) {
		if (EXISTS(RIGHT(i))) {
			if (Cola[LEFT(i)].Edad > Cola[RIGHT(i)].Edad) {
				std::swap(Cola[i], Cola[RIGHT(i)]);
				i = RIGHT(i);
			}
			else {
				std::swap(Cola[i], Cola[LEFT(i)]);
				i = LEFT(i);
			}
		}
		else {
			std::swap(Cola[i], Cola[LEFT(i)]);
			i = LEFT(i);
		}
	}
	return resultado;
}		


void ColaPrioridad::InsertarPrioridad(Pasajero& const pasajero)
{
	Cola[LenCola] = pasajero;
	int i = LenCola;
	while (i > 0 && Cola[i].Edad < Cola[DAD(i)].Edad) {
		std::swap(Cola[i], Cola[DAD(i)]);
		i = DAD(i);
	}
}

