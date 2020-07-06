#pragma once
#include <list>

class ThePowerfulList
{
public:
	static std::list<int> Insertar(int valorInsertar, std::list<int> lista);
	static void Buscar(int x, std::list<int> lista);
	static void Imprimir(std::list<int> lista);
	static double ExperimentoList(int n);
	static double RepetirExperimentoList(int n);
};

