#include "DiccionarioCuentas.h"
#include <vector>

int DiccionarioCuentas::Hash(std::string palabra)
{
	//return palabra.size();

	// No puedo llamar .size in hacer el for auto, se paso con str y vector

	/*int res = 0;

	for (auto i : palabra) {

	}*/
	

}



int DiccionarioCuentas::ObtenerIndice(std::string palabra)
{
	int hash = Hash(palabra);
	int indice = hash % N;
	return indice;


}

DiccionarioCuentas::DiccionarioCuentas()
{
	N = 1000000;
	Arreglo = new ListCuentPalabras[N]();

}

DiccionarioCuentas::~DiccionarioCuentas()
{
	delete[] Arreglo;
}

DiccionarioCuentas::DiccionarioCuentas(int n)
{
	Arreglo = new ListCuentPalabras[n]();
	N = n;

}

void DiccionarioCuentas::Insertar(std::string palabra1, std::string palabra2)
{
	int indice = ObtenerIndice(palabra1);

	Arreglo[indice].AumentarPalabra(palabra2);

}

ListCuentPalabras* DiccionarioCuentas::Buscar(std::string palabra)
{
	int indice = ObtenerIndice(palabra);
	return  &(Arreglo[indice]);
}


