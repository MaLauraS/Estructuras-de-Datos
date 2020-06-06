#include "ListEnlazBigrama.h"
#include <sstream>

ListEnlazBigrama::ListEnlazBigrama()
{
	Cabeza = nullptr;
}

void ListEnlazBigrama::InsertarFinal(BiGrama& bigrama)
{
	NodoBigrama* nuevoNodo = new NodoBigrama(bigrama);
	if (ListaVacia()) {
		Cabeza = nuevoNodo;
		Ultimo = nuevoNodo;
	}

	else {

		Ultimo->Siguiente = nuevoNodo;
		Ultimo = nuevoNodo;
	}
}

BiGrama ListEnlazBigrama::RemoverPrimero()
{

	BiGrama resultado = Cabeza->Valor;
	NodoBigrama* temp = Cabeza->Siguiente;
	delete Cabeza;
	Cabeza = temp;

	return resultado;

}

bool ListEnlazBigrama::ListaVacia()
{
	return Cabeza == nullptr;
}

std::string ListEnlazBigrama::ToString()
{
	std::ostringstream print;
	print << "[";
	NodoBigrama* nodoActual = Cabeza;
	while (nodoActual != nullptr) {

		print << nodoActual->Valor.GetPalabra1(); 
		print << "--";
		print << nodoActual->Valor.GetPalabra2();
												/*Revisar, porque tira las dos palabras del bigrama.
											   1. Primera Palabra: Hola, Segunda Palabra: Mundo
											   2. Primera Palabra: Harry, Segunda Palabra: Potter
											   Debe devolver el siguiente string “[Hola--Mundo, Harry--Potter]”*/
		print << ", ";
		nodoActual = nodoActual->Siguiente;
	}
	print << "]";
	return print.str();

}

