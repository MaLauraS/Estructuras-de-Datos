#include "NodoAVL.h"

NodoAVL::NodoAVL(int valor)
{
	Valor = valor;

	altura = 1;
	izquierda = nullptr;
	derecha = nullptr;

}