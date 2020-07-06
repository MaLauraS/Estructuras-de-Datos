#include "ThePowerfulList.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <functional>
#include <chrono>
#include <list>


std::list<int> ThePowerfulList::Insertar(int valorInsertar, std::list<int> lista) {

	if (lista.empty())
	{
		std::list<int> nLista (valorInsertar);
		return nLista;
	}

	else
	{
		lista.push_back(valorInsertar);
	}
}


void ThePowerfulList::Buscar(int x, std::list<int> lista) {

	for (auto i: lista)
	{
		if (i == x) return;
	}

}


void ThePowerfulList::Imprimir(std::list<int> lista) {

	for (auto i : lista)
	{
		std::cout << i << "\n";
	}
}


double ThePowerfulList::ExperimentoList(int n) {

	std::vector<int> Num;

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, 1000000);

	auto generador = std::bind(distribution, generator);

	while (n--) {

		Num.push_back(generador());

	}

	std::list<int> lista;

	for (auto i : Num) {

		lista = Insertar(i, lista);

	}

	auto start = std::chrono::high_resolution_clock::now();

	for (auto i : Num) {

		Buscar(i, lista);

	}

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	return ((double)duration.count()) / 1000000.0;
}


double ThePowerfulList::RepetirExperimentoList(int n) {

	double tiempo = 0.0;
	for (int i = 0; i < 30; i++)
	{
		tiempo += ExperimentoList(n);
	}

	return (tiempo / 30.0);
}