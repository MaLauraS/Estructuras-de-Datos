#pragma once
#include "ListCuentPalabras.h"
#include<string>

class DiccionarioCuentas
{
public:
	ListCuentPalabras* Arreglo;
	int N;
	int Hash(std::string palabra);
	int ObtenerIndice(std::string palabra);

	DiccionarioCuentas();
	~DiccionarioCuentas();
	DiccionarioCuentas(int n);

	void Insertar(std::string palabra1, std::string palabra2);
	ListCuentPalabras* Buscar(std::string palabra);


};

