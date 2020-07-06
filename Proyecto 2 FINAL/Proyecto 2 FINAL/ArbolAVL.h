#pragma once
#include "NodoAVL.h"

class ArbolAVL
{
public:

	static int Altura(NodoAVL* nodo);
	static int FactorEquilibrio(NodoAVL* nodo);

	static void Imprimir(NodoAVL* nodo);
	static void Buscar(NodoAVL* nodo, int n);

	static NodoAVL* Insertar(NodoAVL* arbol, int n);

	static double ExperimentoAVL(int n);
	static double RepetirExperimentoAVL(int n);

	static int DeterminarEscenario(NodoAVL* nodo);

	static NodoAVL* RotarIzquierda(NodoAVL* nodo);
	static NodoAVL* RotarDerecha(NodoAVL* nodo);
	static NodoAVL* RotarIzquierdaDerecha(NodoAVL* nodo);
	static NodoAVL* RotarDerechaIzquierda(NodoAVL* nodo);
};

enum Escenario { Izquierda, Derecha, IzquierdaDerecha, DerechaIzquierda, Nada };
