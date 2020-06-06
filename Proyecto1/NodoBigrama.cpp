#include "NodoBigrama.h"

NodoBigrama::NodoBigrama()
{
	Siguiente = nullptr;
}

NodoBigrama::NodoBigrama(BiGrama& valor)
{
	Valor = valor;
}
