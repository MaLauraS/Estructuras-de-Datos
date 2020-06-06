#pragma once
#include<string>

class NodoListCuent
{
public:
	std::string Valor;
	int Cuenta;
	NodoListCuent* Siguiente;

	NodoListCuent();
	NodoListCuent(std::string valor);
};

