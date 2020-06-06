#include "ListCuentPalabras.h"

NodoListCuent* ListCuentPalabras::Buscar(std::string string)
{

	NodoListCuent* nodoActual = Cabeza;
	while (nodoActual->Siguiente != nullptr && nodoActual->Valor != string) {
		nodoActual = nodoActual->Siguiente;
	}

	return nodoActual;
}

void ListCuentPalabras::AumentarPalabra(std::string string)
{
	auto res = Buscar(string);

	if (res != nullptr) {
		res->Cuenta++;
	}

	else {
		NodoListCuent* nuevoNodo = new NodoListCuent(string);
		nuevoNodo->Siguiente = Cabeza;
		Cabeza = nuevoNodo;
	}
	Ordenado = false;
}

NodoListCuent* ListCuentPalabras::MergeSort(NodoListCuent* Lista)
{
	NodoListCuent* nodoActual = Lista;
	int contador = 0;
	while (nodoActual->Siguiente != nullptr) {
		nodoActual = nodoActual->Siguiente;
		contador++;
	}

	if (contador == 0 || contador == 1) {
		return Lista;
	}

	int puntoMedio = contador / 2;
	int flag = 0;

	nodoActual = Lista;
	while (flag < puntoMedio) {
		nodoActual = nodoActual->Siguiente;
		flag++;
	}

	NodoListCuent* primeraParte = Lista;
	NodoListCuent* segundaParte = nodoActual->Siguiente;
	nodoActual = nullptr;

	primeraParte = MergeSort(primeraParte);
	segundaParte = MergeSort(segundaParte);

	NodoListCuent* res;

	if (primeraParte->Cuenta > segundaParte->Cuenta) {
		res = primeraParte;
		primeraParte = primeraParte->Siguiente;
	}
	else {
		res = segundaParte;
		segundaParte = segundaParte->Siguiente;
	}

	NodoListCuent* resultadoActual = res;

	while (primeraParte != nullptr && segundaParte != nullptr) {

		if (primeraParte->Cuenta > segundaParte->Cuenta) {
			resultadoActual->Siguiente = primeraParte;
			primeraParte = primeraParte->Siguiente;
			resultadoActual = resultadoActual->Siguiente;
		}
		else {
			resultadoActual->Siguiente = segundaParte;
			segundaParte = segundaParte->Siguiente;
			resultadoActual = resultadoActual->Siguiente;
		}
	}

	if (primeraParte != nullptr) {
		resultadoActual->Siguiente = primeraParte;
	}
	else {
		resultadoActual->Siguiente = segundaParte;
	}

	return res;

}



void ListCuentPalabras::Ordenar()
{
	Cabeza = MergeSort(Cabeza);
	Ordenado = true;
}
