#pragma once
#include "BiGrama.h"

class NodoBigrama
{
public:
	BiGrama Valor;
	NodoBigrama* Siguiente;

	NodoBigrama();
	NodoBigrama(BiGrama& valor);
};

