#pragma once
#include <string>
#include <vector>
#include <limits>
#include <utility>
using namespace std;

class Grafo // No dirigido
{
public:

	int NumVertices;
	vector< vector<pair < int, int > > > Aristas;

	int ValorVacio();

	Grafo(int numVertices); // constructor que reciba como parámetro el número de vértices que tiene el grafo

	int GetArista(int i, int j); //Devuelva el peso de la arista entre el vértice i y el vértice j
	void SetArista(int i, int j, int peso); //Establezca el peso de la arista entre el vértice i y el vértice j

	string ToString(); //Imprimir grafo
};

