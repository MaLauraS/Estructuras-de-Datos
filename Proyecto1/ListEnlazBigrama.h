#pragma once
#include "NodoBigrama.h"

class ListEnlazBigrama
{
public:

	NodoBigrama* Cabeza;
	NodoBigrama* Ultimo;

	ListEnlazBigrama();
	void InsertarFinal(BiGrama& bigrama);
	BiGrama RemoverPrimero();
	bool ListaVacia();
	std::string ToString();
};

