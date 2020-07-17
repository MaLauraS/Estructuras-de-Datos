#include "Grafo.h"
#include <sstream>
#include <iostream>


int Grafo::ValorVacio()
{
	return std::numeric_limits<int>::max();
}

Grafo::Grafo(int numVertices):Aristas(numVertices), NumVertices(numVertices)
{  
}


int Grafo::GetArista(int i, int j)
{
	for (auto k : Aristas[i]) {
		if (k.first == j) {
			return k.second;
		}
	}

	return ValorVacio();
}

void Grafo::SetArista(int i, int j, int peso)
{
	Aristas[i].push_back(pair<int,int>(j,peso));
}

std::string Grafo::ToString()
{
	std::stringstream ss;


	for (int i = 0; i < NumVertices; i++) {
		for (auto k : Aristas[i]) {

			int j = k.first;

			ss << i << " " << j << " " << k.second << "\n";
		}
	}
	return ss.str();
}

