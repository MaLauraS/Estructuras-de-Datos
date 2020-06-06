#pragma once
#include "BiGrama.h"
#include "ListEnlazBigrama.h"


class ColaBigramas
{
public:
	ListEnlazBigrama* ListaBigramas;

	ColaBigramas();
	void Encolar(BiGrama bigrama);
	BiGrama Desencolar();
	bool ColaVacia();
	std::string ToString();

};

