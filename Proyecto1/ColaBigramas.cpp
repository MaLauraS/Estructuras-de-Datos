#include "ColaBigramas.h"

ColaBigramas::ColaBigramas()
{
	ListaBigramas = new ListEnlazBigrama;
}

void ColaBigramas::Encolar(BiGrama bigrama)
{
	ListaBigramas->InsertarFinal(bigrama);
}

BiGrama ColaBigramas::Desencolar()
{
	return ListaBigramas->RemoverPrimero();
}

bool ColaBigramas::ColaVacia()
{
	return ListaBigramas->ListaVacia();
}

std::string ColaBigramas::ToString()
{
	return ListaBigramas->ToString();
}
