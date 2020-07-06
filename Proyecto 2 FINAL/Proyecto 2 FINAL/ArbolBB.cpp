#include "ArbolBB.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <functional>
#include <chrono>


NodoABB* ArbolBB::Insertar(NodoABB* nodo, int valorInsertar) {

	if (nodo == nullptr)
	{
		return new NodoABB(valorInsertar);
	}

	else if (nodo->Valor > valorInsertar)
	{
		nodo->Izq = Insertar(nodo->Izq, valorInsertar);
	}

	else if (nodo->Valor < valorInsertar)
	{
		nodo->Der = Insertar(nodo->Der, valorInsertar);
	}
}


void ArbolBB::Buscar(int x, NodoABB* nodo) {

	if (x == nodo->Valor) {
		return;
	}

	else if (x < nodo->Valor) {

		return Buscar(x, nodo->Izq);
	}

	else {

		return Buscar(x, nodo->Der);

	}

}


void ArbolBB::Imprimir(NodoABB* nodo) {

	if (nodo == nullptr) {
		return;
	}

	Imprimir(nodo->Izq);
	std::cout << nodo->Valor << " ";
	Imprimir(nodo->Der);
}


double ArbolBB::ExperimentoABB(int n) {

	std::vector<int> Num;

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, 1000000);

	auto generador = std::bind(distribution, generator);

	while (n--) {

		Num.push_back(generador());

	}

	NodoABB* arbol = nullptr;

	for (auto i : Num) {

		arbol = Insertar(arbol, i);

	}

	auto start = std::chrono::high_resolution_clock::now();

	for (auto i : Num) {

		Buscar(i, arbol);

	}

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	return ((double)duration.count()) / 1000000.0;
}


double ArbolBB::RepetirExperimentoABB(int n) {

	double tiempo = 0.0;
	for (int i = 0; i < 30; i++)
	{
		tiempo += ExperimentoABB(n);
	}

	return (tiempo / 30.0);
}
