#pragma once
#include "NodoListCuent.h"
#include<string>

class ListCuentPalabras
{
public:
	NodoListCuent* Cabeza;
	std::string PrimeraPalabra;
	bool Ordenado;

	NodoListCuent* Buscar(std::string string);
	void AumentarPalabra(std::string string);
	NodoListCuent* MergeSort(NodoListCuent* merge);
	void Ordenar();

};

