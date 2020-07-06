#pragma once
#include "NodoABB.h"

class ArbolBB
{
public:

	NodoABB* Raiz;

	static NodoABB* Insertar(NodoABB* nodo, int valorInsertar);
	static void Buscar(int x, NodoABB* nodo);
	static void Imprimir(NodoABB* nodo);
	static double ExperimentoABB(int n);
	static double RepetirExperimentoABB(int n);

};